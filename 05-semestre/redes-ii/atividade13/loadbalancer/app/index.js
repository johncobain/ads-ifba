const express = require('express');
const redis = require('redis');
const app = express();
const port = 3000;
const APP_NAME = process.env.APP_NAME || "instancia-desconhecida";

// Configuração do Cliente Redis
const client = redis.createClient({ url: 'redis://cache:6379' });
client.on('error', err => console.log('Redis Error', err));
client.connect();

app.get('/api/dados', async (req, res) => {
    // 1. Verificar Cache
    const cache = await client.get('meus_dados');
    if (cache) {
        return res.json({
            origem: "CACHE (Redis)",
            instancia: APP_NAME,
            dados: JSON.parse(cache),
            timestamp: new Date()
        });
    }
    // 2. Se não existir, "gerar" o dado (simulando um processo lento)
    const novosDados = { mensagem: "Dados valiosos gerados agora!", id: Math.random() };
    // 3. Salvar no Redis com TTL de 30 segundos
    await client.setEx('meus_dados', 30, JSON.stringify(novosDados));
    res.json({
        origem: "GERADO AGORA (DB)",
        instancia: APP_NAME,
        dados: novosDados,
        timestamp: new Date()
    });
});

app.listen(port, () => console.log(`${APP_NAME} rodando na porta ${port}`));