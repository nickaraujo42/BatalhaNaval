# Batalha Naval

O projeto Batalha Naval é um jogo construído na linguagem C e que foi implementado em redes, usando o protocolo UDP.

A ideia original do projeto é estudar o desenvolvimento de jogos em redes. 
Produzido por alunos da Fatec de Sao Caetano do Sul, cursando Jogos Digitais.

Para inicializar usamos o Software GNS3, 
ele permite a combinação de dispositivos virtuais e reais, usados ​​para simular redes complexas, necessario tambem a ultilizaçao 
do Oracle VM VirtualBox, para criar ambientes para instalação de sistemas, com os sistemas nas duas maquinas Linux Ubuntu 18.04.

## Configurando as VMs, Oracle VM VirtualBox

As duas maquinas tanto o cliente e o servidor seguem as mesmas configuraçoes.

Configuraçao do Sistema
![alt text](https://i.imgur.com/VH6wAHc.png)

Configuraçao da Rede
![alt text](https://i.imgur.com/elvrkW7.png)

## GNS3

Iniciar um novo projeto.

File -> New blank project

Adicinando as Maquinas Vituais

Edit -> Preferences -> VitualBox VMs -> New

![alt text](https://i.imgur.com/J5PamqK.png)

Depois de salvar as configuraçoes

Abrir Browse Switches -> ATM Switch

![alt text](https://i.imgur.com/DjOARvw.png)

Abrir Browse End Devices -> Adicionar as duas Vms ao projeto

![alt text](https://i.imgur.com/fvZsQS7.png)

Conectar as maquinas ao Switch usando a opçao Add Link 

![alt text](https://i.imgur.com/DHM1XD6.png)

Para finalizar e iniciar as maquinas conectadas
Ultilize o Start (Em verde na imagem)

![alt text](https://i.imgur.com/eDMU1Ts.png)

Após as estarão maquinas ligadas e conectadas.
