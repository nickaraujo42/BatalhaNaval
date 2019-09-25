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

Abrir Browse Switches -> Ethernet Switch

![alt text](https://i.imgur.com/1ZPkdrl.png)

Abrir Browse End Devices -> Adicionar as duas Vms ao projeto

![alt text](https://i.imgur.com/lilJEKN.png)

Conectar as maquinas ao Switch usando a opçao Add Link 

![alt text](https://i.imgur.com/mpTnWIR.png)
![alt text](https://i.imgur.com/gltGGrh.png)

Para finalizar e iniciar as maquinas conectadas
Ultilize o Start (Em verde na imagem)

![alt text](https://i.imgur.com/eDMU1Ts.png)

Após as maquinas estarão maquinas ligadas e conectadas.

## Oracle VM VirtualBox

## CLIENTE

Em configuraçoes de rede cabeada

![alt text](https://i.imgur.com/Gbxu4JD.png)

Aplicar o metodo IPv4 no manual
Com o seguinte endereço e a mascara de rede igual segue na imagem

![alt text](https://i.imgur.com/aXVl1f9.png)

## SERVIDOR 

![alt text](https://i.imgur.com/Gbxu4JD.png)

Aplicar o metodo IPv4 no manual
Com o seguinte endereço e a mascara de rede igual segue na imagem

![alt text](https://i.imgur.com/aw05Kon.png)

Caso necessario desligar e ligar a rede novamente.

Passar o codigo com um pen drive para as maquinas vituais Cliente no respectivo e Servidor do mesmo modo.

## HOW TO

Para compilar um código c no Linux (ubuntu) basta:

prompt: gcc codigo_fonte.c -o nome_do_executavel

Caso queira ver o processo de compilação digite: 

prompt: gcc codigo_fonte.c -o nome_do_executavel --verbose

Para executar o programa basta digitar:

prompt: ./nome_do_executavel

Caso o arquivo não execute pode ser devido a questão de permissão....

Como resolver? digite chmod +x nome_arquivo

como segue o exemplo da imagem:

![alt text](https://i.imgur.com/d7nAT0y.png)

Só se divertir com o jogo :)
