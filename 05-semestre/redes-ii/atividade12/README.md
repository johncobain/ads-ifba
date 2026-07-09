# Atividade 12

## Objetivo

Configurar um servidor Streaming para transmissao em tempo real de um arquivo de vídeo.
Para a realização dessa atividade, é necessário que a máquina host possua o VLC. O módulo FFplay do FFmpeg serve como alternativa. Também será necessário que a máquina host possua o Wireshark para capturar os pacotes de rede.

Além disso, será utilizada uma máquina virtual diferente, utilizando Ubuntu 20.4 e configurada em modo Bridge.

[Link da máquina virtual](https://www.dropbox.com/scl/fi/pltkqimkjzgd8d6f0p8nj/maq4.ova?rlkey=3kojkxn3cs0lbt1xxq4aeiik3&st=a7woev1g&e=1&dl=0)

## Link para o Vídeo de Demonstração

[Vídeo de Demonstração](https://youtu.be/xlZke2Bs6pQ)

## Acesso remoto por SSH

Login: osboxes

Pass: osboxes.org

ssh: ssh osboxes@< ip da maq >

## Configuração da VM

Para acessar a máquina virtual, é necessário instalar o SSH e liberar a porta 22 no firewall:

```bash
sudo -i // para entrar no root
apt update
apt install ssh
ufw allow 22
```

Após isso, instale as dependências:

```bash
apt-get update
apt install nginx libnginx-mod-rtmp ffmpeg yt-dlp python3-brotli
```

Verifique se o Nginx está rodando:

```bash
systemctl status nginx
ls /usr/lib/nginx/modules/ | grep rtmp
```

Adicione o seguinte bloco no final do arquivo /etc/nginx/nginx.conf:

```bash
rtmp {
    server {
        listen 1935;
        chunk_size 4096;
        allow publish 127.0.0.1;
        deny publish all;

        application live {
            live on;
            record off;
        }
    }
}
```

Reinicie o Nginx:

```bash
systemctl restart nginx
```

## Download do arquivo de vídeo e configuração do streaming

Baixe o arquivo de vídeo desejado, por exemplo, utilizando o comando:

```bash
yt-dlp "https://filesamples.com/samples/video/mp4/sample_1280x720_surfing_with_audio.mp4" -o video.mp4
```

Utilize o ffmpeg para transmitir o vídeo para o servidor Nginx:

```bash
ffmpeg -re -i video.mp4 -c:v copy -c:a aac -ar 44100 -f flv rtmp://localhost/live/stream
```

## Consumindo o streaming na máquina host

Abra o VLC na máquina host e vá em Mídia > Abrir Fluxo de Rede. Insira o seguinte endereço:

```bash
rtmp://<ip da máquina virtual>/live/stream
```

## Captura de pacotes de rede

Utilize o Wireshark para capturar os pacotes de rede:

```bash
sudo apt install wireshark
sudo wireshark
```
