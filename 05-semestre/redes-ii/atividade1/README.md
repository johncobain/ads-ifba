# Atividade 1

## Objetivo

Simular uma rede utilizando máquinas virtuais, onde uma máquina irá atuar como roteador e as outras duas como computadores. O roteador irá interligar as duas redes internas e permitir a comunicação entre elas, além de fornecer acesso à internet para os computadores.

A primeira máquina (roteador) terá duas interfaces de rede conectadas a redes internas diferentes (10.10.1.1/24 e 10.10.0.1/24).

As outras duas máquinas terão uma interface de rede conectada apenas a rede interna correspondente (10.10.1.2/24 e 10.10.0.2/24).

## Link para o Vídeo de Demonstração

[Link para o Vídeo de Demonstração]()//todo

## Link para Download das VMs

[Link para Download das VMs](https://drive.google.com/drive/folders/1nGR5_DV5u7J-jm3upk0B82C3EsvlfjlT?usp=drive_link)

## Acesso ao Roteador por SSH

Login: root
Pass: thoughtpolice

ssh: ssh -p 3022 root@localhost

## maq 1

### VirtualBox 1

papel: roteador
networks:

- adapter1: internal network (lab_a)
- adapter2: internal network (lab_b)
- adapter3: NAT:
  - ip_fowarding:
    - name: ssh
    - host port: 3022
    - guest port: 22

### Terminal 1 (configurar rotas)

```bash
nano /etc/network/interfaces
```

``` bash
# This file describes the network interfaces available on your system  
# and how to activate them. For more information, see interfaces(5).  
  
source /etc/network/interfaces.d/*  
  
# The loopback network interface  
auto lo  
iface lo inet loopback  
  
#interface 1  
auto enp0s3  
iface enp0s3 inet static  
       address 10.10.1.1  
       netmask 255.255.255.0  
  
#interface 2  
auto enp0s8  
iface enp0s8 inet static  
       address 10.10.0.1  
       netmask 255.255.255.0  
  
#interface 3 (ssh)  
auto enp0s9  
iface enp0s9 inet dhcp
```

Forma temporária

```bash
ifconfig enp0s3 10.10.1.1 netmask 255.255.255.0 up 
ifconfig enp0s8 10.10.0.1 netmask 255.255.255.0 up
```

### Terminal 1 (habilitar ip_foward)

```bash
echo 1 > /proc/sys/net/ipv4/ip_forward
```

### Terminal 1 (habilitar acesso ssh por root)

```bash
nano /etc/ssh/sshd_config
```

- Procure por: `#PermitRootLogin prohibit-password`
- Mude para: `PermitRootLogin yes`

## maq 2

### VirtualBox 2

papel: computador
networks:

- adapter1: internal network (lab_a)

### Terminal 2 (configurar rotas)

```bash
nano /etc/network/interfaces
```

```bash
# This file describes the network interfaces available on your system  
# and how to activate them. For more information, see interfaces(5).  
  
source /etc/network/interfaces.d/*  
  
# The loopback network interface  
auto lo  
iface lo inet loopback  
 
auto enp0s3  
iface enp0s3 inet static  
       address 10.10.1.2  
       netmask 255.255.255.0
       gateway 10.10.1.1  
```

Forma temporária

```bash
ifconfig enp0s3 10.10.1.2 netmask 255.255.255.0 up
route add default gw 10.10.1.1
```

## maq 3

### VirtualBox 3

papel: computador
networks:

- adapter1: internal network (lab_b)

### Terminal 3 (nano /etc/network/interfaces)

```bash
# This file describes the network interfaces available on your system  
# and how to activate them. For more information, see interfaces(5).  
  
source /etc/network/interfaces.d/*  
  
# The loopback network interface  
auto lo  
iface lo inet loopback  
 
auto enp0s3  
iface enp0s3 inet static  
       address 10.10.0.2  
       netmask 255.255.255.0
       gateway 10.10.0.1  
```

Forma temporária

```bash
ifconfig enp0s3 10.10.0.2 netmask 255.255.255.0 up 
route add default gw 10.10.0.1
```

## Teste de Comunicação Entre as Máquinas

### maq 2 -> maq 1

- ping 10.10.1.1

### maq 2 -> maq 3

- ping 10.10.0.2

### maq 3 -> maq 1

- ping 10.10.0.1

### maq 3 -> maq 2

- ping 10.10.1.2
