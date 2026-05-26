const express = require('express');
const amqp = require('amqplib');
const client = require('prom-client');
const axios = require('axios');
const app = express();

const SERVICE_NAME = process.env.SERVICE_NAME || 'orders-service';
const SERVICE_ID = SERVICE_NAME + '-1';
const CONSUL_HOST = process.env.CONSUL_HOST || 'consul';
const CONSUL_PORT = process.env.CONSUL_PORT || 8500;
const SERVICE_PORT = 3000;

// Prometheus metrics
client.collectDefaultMetrics();
app.get('/metrics', async (req, res) => {
  res.set('Content-Type', client.register.contentType);
  res.end(await client.register.metrics());
});

// Consul registration
async function registerConsul() {
  try {
    await axios.put(`http://${CONSUL_HOST}:${CONSUL_PORT}/v1/agent/service/register`, {
      Name: SERVICE_NAME,
      ID: SERVICE_ID,
      Address: SERVICE_NAME,
      Port: SERVICE_PORT,
      Check: {
        HTTP: `http://${SERVICE_NAME}:${SERVICE_PORT}/metrics`,
        Interval: '10s'
      }
    });
    console.log(`[CONSUL] Serviço registrado: ${SERVICE_NAME}`);
  } catch (err) {
    console.log('[CONSUL] Falha ao registrar, tentando novamente em 5s...');
    setTimeout(registerConsul, 5000);
  }
}

app.get('/create-order', async (req, res) => {
  try {
    const conn = await amqp.connect('amqp://rabbitmq');
    const ch = await conn.createChannel();
    const msg = JSON.stringify({ id: Math.random(), item: 'Teclado', status: 'Criado' });
    ch.sendToQueue('order_created', Buffer.from(msg));
    res.send("Pedido enviado para a fila!");
  } catch (e) {
    res.status(500).send("Erro no RabbitMQ");
  }
});

app.listen(SERVICE_PORT, () => {
  console.log(`Order Service na porta ${SERVICE_PORT}`);
  registerConsul();
});