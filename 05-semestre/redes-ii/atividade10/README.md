# Atividade 10

## Objetivo

O objetivo desta atividade é criar uma arquitetura de microsserviços escalável utilizando Docker e Docker Compose. A arquitetura inclui três serviços Node.js (`users-service`, `products-service`, e `orders-service`), que se comunicam de forma assíncrona através do RabbitMQ. O Consul é utilizado para registro e descoberta de serviços, e o Prometheus para monitoramento das métricas de cada serviço.

## Link para o Vídeo de Demonstração

[Link para o Vídeo de Demonstração](https://youtu.be/V6xblqKct6w)

[Link para o Diretório do Projeto no GitHub](https://github.com/johncobain/ads-ifba/tree/7f6ad75ebdc18a4a1fe69cf2b24c9d6801a41b2c/05-semestre/redes-ii/atividade10/escalabilidade)

## Estrutura do Projeto

O projeto é composto pelos seguintes serviços e componentes, orquestrados pelo Docker Compose:

- **`orders-service`**: Serviço responsável por criar pedidos e publicá-los em uma fila do RabbitMQ.
- **`products-service`**: Serviço que consome eventos da fila de pedidos.
- **`users-service`**: Outro serviço que também consome eventos da fila de pedidos.
- **`rabbitmq`**: Broker de mensageria para comunicação assíncrona entre os serviços.
- **`consul`**: Ferramenta para descoberta e registro de serviços.
- **`prometheus`**: Sistema de monitoramento que coleta métricas dos serviços.

## Executando a Aplicação

Para executar a aplicação, certifique-se de ter o Docker e o Docker Compose instalados. Em seguida, no diretório `atividade10/escalabilidade`, execute o seguinte comando:

```bash
docker compose up --build
```

Este comando irá construir as imagens dos serviços e iniciar todos os contêineres definidos no arquivo `docker-compose.yml`.

## Testando a Aplicação

Após a inicialização de todos os serviços, você pode interagir com a aplicação:

- **Criar um pedido**: Acesse `http://localhost:3003/create-order` em seu navegador ou utilize o `curl`. Isso enviará uma mensagem para a fila `order_created` no RabbitMQ.

    ```bash
    curl http://localhost:3003/create-order
    ```

- **Verificar Logs**: Nos logs do terminal onde o `docker compose` está rodando, você verá as mensagens de "Evento recebido no serviço:" nos logs dos serviços `users-service` e `products-service`, confirmando que eles consumiram o evento.

- **Painel do RabbitMQ**: Acesse `http://localhost:15672` para visualizar o painel de gerenciamento do RabbitMQ (login: `guest`, senha: `guest`).

- **Painel do Consul**: Acesse `http://localhost:8500` para ver os serviços registrados no Consul.

- **Painel do Prometheus**: Acesse `http://localhost:9090` para visualizar as métricas coletadas dos serviços. Você pode ir na aba "Status" -> "Targets" para ver se o Prometheus está conseguindo acessar os serviços.
