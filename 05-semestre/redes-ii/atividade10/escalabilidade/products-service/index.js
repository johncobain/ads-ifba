
const express = require('express');
const amqp = require('amqplib');
const client = require('prom-client');
const axios = require('axios');
const app = express();

const SERVICE_NAME = process.env.SERVICE_NAME || 'products-service';
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

// RabbitMQ consumer
async function initRabbit() {
  try {
    const conn = await amqp.connect('amqp://rabbitmq');
    const ch = await conn.createChannel();
    await ch.assertQueue('order_created');
    ch.consume('order_created', (msg) => {
      console.log(" [!] Evento recebido no serviço:", msg.content.toString());
      ch.ack(msg);
    });
  } catch (e) {
    console.log("Aguardando RabbitMQ...");
    setTimeout(initRabbit, 5000);
  }
}

app.get('/', (req, res) => res.send("Serviço Ativo"));

app.listen(SERVICE_PORT, () => {
  console.log(`Rodando na porta ${SERVICE_PORT}`);
  initRabbit();
  registerConsul();
});

