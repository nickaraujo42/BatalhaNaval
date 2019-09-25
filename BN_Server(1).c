/************* UDP CLIENT CODE ******************/
//////////////////////////////////////////////////
///////////////Por COXINHA ESTUDIOS///////////////
//Felipe Pinheiro Rocha 	RA:1680961913016//
//Nicolas Araujo Bonfim		RA:1680961913039//
//Julio de Medeiros		RA:1680961913006//
//Caique de Albuquerque Nadal 	RA:1680961913038//
//Gabriel Anea			RA:1680961913044//
//////////////////////////////////////////////////

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define linha 10
#define coluna 10

//TABULEIRO DO JOGADOR
char myTable[coluna][linha];

//TABULEIRO INIMIGO
char enemyTable[coluna][linha];

void ZerarMapa(char Mapa[coluna][linha]) {
  int x, y;
  for (y = 0; y < linha; y++) {
    for (x = 0; x < coluna; x++) {
      Mapa[x][y] = ' ';
    }
  }
}

void Submarino(char Mapa[coluna][linha]) {
	//Esse código impede barcos aparecerem perto demais
	//Representado pelo numero 1
	
	int i, c, d, rx, ry;
	int valido = 1;
	for(i = 0; i <4 ;i ++) {
  		rx = rand()%10; ry = rand()%10;
		for (d = 0; d < 3; d++) {
			for (c = 0; c < 3; c++) {
				if(rx == 0 && c == 0) c = c + 1;
				if(ry == 0 && d == 0) d = d + 1;  
				if(Mapa[rx + (- 1 + c)][ry + (- 1 + d)] != ' ')
					valido = 0;
			}
		}
		
		if(valido == 1)
			Mapa[rx][ry] = '#';
		else 
			i--; valido = 1;
	}
}


void Encouracado(char Mapa[coluna][linha]) {
	
	//Esse código impede barcos aparecerem perto demais
	//Representado pelo numero 2
	
	int i, c, d, rx, ry, dir;
	int valido = 1;
	for(i = 0; i <3 ;i ++) {
  		rx = rand()%10; ry = rand()%10; 
		for (d = 0; d < 5; d++) {
			for (c = 0; c < 5; c++) {
				if((rx == 0 && c <= 1) || (rx == 1 && c == 0)) c = c + 1;
				if((ry == 0 && d <= 1) || (ry == 1 && d == 0)) d = d + 1;  
				if(Mapa[rx + (- 2 + c)][ry + (- 2 + d)] != ' ')
					valido = 0;
			}
		}
		
		if(valido) {
			
			Mapa[rx][ry] = '#';
			
			
			dir = rand()%2;
			if(dir == 0 && rx != 0) { Mapa[rx - 1][ry] = '#';}
			else if(dir == 0) Mapa[rx + 1][ry] = '#';
			if(dir == 1 && ry != 0) { Mapa[rx][ry - 1] = '#';}
			else if(dir == 1) Mapa[rx][ry + 1] = '#';
			
		}
		
		else 
			i--; valido = 1;
		
	}

}

void Cruzador(char Mapa[coluna][linha]) {
	
	//Esse código impede barcos aparecerem perto demais
	//Representado pelo numero 3
	
	int i, c, d, t, rx, ry, dir;
	int valido = 1;
	for(i = 0; i < 3; i++) {
		rx = rand()%10; ry = rand()%10;
		dir = rand()%2;
		
		if(dir == 0 && rx >= 3){
			
			for (d = 0; d < 3; d++) {
				for (c = 0; c < 5; c++) {
					if(ry == 0 && d == 0) d++;
					if(Mapa[rx + (- 3 + c)][ry + (- 1 + d)] != ' ')
						valido = 0; 
					if(rx == 9 && c >= 3) c++;
					if(ry == 9 && c >= 4 && d >= 1) d++;
				}
			}
			if(valido ==1) {
				for (t = 0; t < 3; t++) 
					Mapa[rx - t][ry] = '#';
			}
			
		}
		else if(dir == 0) {
			
			for (d = 0; d < 3; d++) {
				for (c = 0; c < 5; c++) {
					if(ry == 0 && d == 0) d++; 
					if(Mapa[rx +(- 1 + c)][ry + (- 1 + d)] != ' ')
						valido = 0; 
					if(rx == 9 && c >= 3) c++;
					if(ry == 9 && c >= 4 && d >= 1) d++;
				}
			}
			if(valido == 1) {
				for (t = 0; t < 3; t++) 
					Mapa[rx + t][ry] = '#';
			}
			
		}
		if(dir == 1 && ry >= 3){
			
			for (d = 0; d < 5; d++) {
				for (c = 0; c < 3; c++) {
					if(rx == 0 && c == 0) c++;
					if(Mapa[rx + (- 1 + c)][ry + (- 3 + d)] != ' ')
						valido = 0; 
					if(rx == 9 && c == 1) c++;
					if(ry == 9 && c >= 2 && d == 3 ) d++;
					
				}
			}
			if(valido ==1) {
				for (t = 0; t < 3; t++) 
					Mapa[rx][ry - t] = '#';
			}
			
		}
		else if(dir == 1){
			
			for (d = 0; d < 5; d++) {
				for (c = 0; c < 3; c++) {
					if(rx == 0 && c == 0) c++;
					if(Mapa[rx + (- 1 + c)][ry + (- 1 + d)] != ' ')
						valido = 0; 
					if(rx == 9 && c == 1) c++;
					if(ry == 9 && c >= 2 && d == 3 ) d++;
					
				}
			}
			if(valido ==1) {
				for (t = 0; t < 3; t++) 
					Mapa[rx][ry + t] = '#';
			}
			
		}
		
		if (valido == 0){
				i--; valido = 1;	
		}
		
	}	
}


void PortaAviao(char Mapa[coluna][linha]) {
	
	//Esse é o primeiro barco a ser inserido, não precisa verificar
	//Representado pelo numero 4
	
	int i, c, d, t, rx, ry, dir;
	int valido = 1;
	for(i = 0; i <1 ;i ++) {
  		rx = rand()%10; ry = rand()%10; 
			
		Mapa[rx][ry] = '#';
		//if (rx > 3 && rx < 7) valido = 0;
		//if (ry > 3 && ry < 7) valido = 0;
			
		if(valido = 1) {
			
			dir = rand()%2;
			if(dir == 0 && rx >= 4) {
				
				for (t = 1; t < 4; t++) 
					Mapa[rx - t][ry] = '#';
				
			}
			else if(dir == 0) {
			
				for (t = 1; t < 4; t++) 
					Mapa[rx + t][ry] = '#';
			}
			if(dir == 1 && ry >= 4) {
			
				for (t = 1; t < 4; t++) 
					Mapa[rx][ry - t] = '#';
			}
			else if(dir == 1){
			
				for (t = 1; t < 4; t++) 
					Mapa[rx][ry + t] = '#';
			}
	
		}
		else 
			i--; valido = 1;
	
	}
}

int ganhou = 0;//VARIAVEL PARA TESTAR SE A CONDIÃ‡AO DE VITORIA OU DERROTA FOI ALCANÃ‡ADA

int contarNavios()
/*ESSE METODO SERVE PARA CONFERIR SE AINDA EXISTE ALGUM NAVIO DO JOGADOR OU DO INIMIGO*/
{
	int i,j;
	ganhou = 1;

	for(i = 0;i<10;i++)
	{
		for(j = 0;j<10;j++)
		{
			if(enemyTable[i][j] == '#')
			{
				ganhou = 0;
				break;
			}
		}
	}

	if(ganhou == 1)
	/*SE TODOS OS NAVIOS INIMIGOS FORAM DESTRUIDOS, ESSE JOGADOR VENCEU*/
	{
		printf("\n __     __                                     ");
		printf("\n|  \\   |  \\                                  ");
		printf("\n| $$   | $$  ______    _______   ______        ");
		printf("\n| $$   | $$ /      \\  /       \\ /      \\    ");
		printf("\n \\$$\\ /  $$|  $$$$$$\\|  $$$$$$$|  $$$$$$\\  ");
		printf("\n  \\$$\\  $$ | $$  | $$| $$      | $$    $$    ");
		printf("\n   \\$$ $$  | $$__/ $$| $$_____ | $$$$$$$$     ");
		printf("\n    \\$$$    \\$$    $$ \\$$     \\ \\$$     \\");
		printf("\n     \\$      \\$$$$$$   \\$$$$$$$  \\$$$$$$$  ");
		printf("\n		                                                                 __ ");
		printf("\n		                                                                |  \\");
		printf("\n		    __     __   ______   _______    _______   ______   __    __ | $$");
		printf("\n		   |  \\   /  \\ /      \\ |       \\  /       \\ /      \\ |  \\  |  \\| $$");
		printf("\n		    \\$$\\ /  $$|  $$$$$$\\| $$$$$$$\\|  $$$$$$$|  $$$$$$\\| $$  | $$| $$");
		printf("\n		     \\$$\\  $$ | $$    $$| $$  | $$| $$      | $$    $$| $$  | $$ \\$$");
		printf("\n		      \\$$ $$  | $$$$$$$$| $$  | $$| $$_____ | $$$$$$$$| $$__/ $$ __ ");
		printf("\n		       \\$$$    \\$$     \\| $$  | $$ \\$$     \\ \\$$     \\ \\$$    $$|  \\");
		printf("\n		        \\$      \\$$$$$$$ \\$$   \\$$  \\$$$$$$$  \\$$$$$$$  \\$$$$$$  \\$$\n");
		return 0;
	}
	/*CASO ISSO NAO OCORRA.. SEGUE O CODIGO ABAIXO*/
	for(i = 0;i<10;i++)
		{
			for(j = 0;j<10;j++)
			{
				if(myTable[i][j] == '#')
				{
					ganhou = 0;
					break;
				}
			}
		}
	if(ganhou == 1)
	/*APOS CONFERIR SE O JOGADOR VENCEU, CONFERE SE ELE PERDEU OU SEJA
	SE ELE AINDA POSSUI ALGUM NAVIO*/
	{
		printf("\n __     __                                     ");
		printf("\n|  \\   |  \\                                  ");
		printf("\n| $$   | $$  ______    _______   ______        ");
		printf("\n| $$   | $$ /      \\  /       \\ /      \\    ");
		printf("\n \\$$\\ /  $$|  $$$$$$\\|  $$$$$$$|  $$$$$$\\  ");
		printf("\n  \\$$\\  $$ | $$  | $$| $$      | $$    $$    ");
		printf("\n   \\$$ $$  | $$__/ $$| $$_____ | $$$$$$$$     ");
		printf("\n    \\$$$    \\$$    $$ \\$$     \\ \\$$     \\");
		printf("\n     \\$      \\$$$$$$   \\$$$$$$$  \\$$$$$$$  ");
		printf("\n			 _______                             __                      __ ");
		printf("\n			|       \\                           |  \\                    |  \\");
		printf("\n			| $$$$$$$\\  ______    ______    ____| $$  ______   __    __ | $$");
		printf("\n			| $$__/ $$ /      \\  /      \\  /      $$ /      \\ |  \\  |  \\| $$");
		printf("\n			| $$    $$|  $$$$$$\\|  $$$$$$\\|  $$$$$$$|  $$$$$$\\| $$  | $$| $$");
		printf("\n			| $$$$$$$ | $$    $$| $$   \\$$| $$  | $$| $$    $$| $$  | $$ \\$$");
		printf("\n			| $$      | $$$$$$$$| $$      | $$__| $$| $$$$$$$$| $$__/ $$ __ ");
		printf("\n			| $$       \\$$     \\| $$       \\$$    $$ \\$$     \\ \\$$    $$|  \\");
		printf("\n			 \\$$        \\$$$$$$$ \\$$        \\$$$$$$$  \\$$$$$$$  \\$$$$$$  \\$$\n");			
		return 0;
	}
}

int Attack(char charx, int y)
/*ESSE METODO SERVE PARA ATACAR O TABULEIRO IMIMIGO COM AS COORDENADAS DIGITADAS*/
{
	int x = charx;
	printf("attacado em: %c %d\n",charx,y);
	
	switch(charx)
	// Troca a letra pelo seu numero correspondente
	{
		case'A':
		{
			x = 0;
			break;
		}
		case'B':
		{
			x = 1;
			break;
		}
		case'C':
		{
			x = 2;
			break;
		}
		case'D':
		{
			x = 3;
			break;
		}
		case'E':
		{
			x = 4;
			break;
		}
		case'F':
		{
			x = 5;
			break;
		}
		case'G':
		{
			x = 6;
			break;
		}
		case'H':
		{
			x = 7;
			break;
		}
		case'I':
		{
			x = 8;
			break;
		}
		case'J':
		{
			x = 9;
			break;
		}
	}
	
	switch(enemyTable[y][x])
	{
		case' ':
		/*CASO A CASA ATACADA FOR VAZIA PREENCHE COM UM SIMBOLO QUE SIGNIFICA QUE O TIRO
		 * FOI ERRADO OU SEJA (O);
		 */
		{
			enemyTable[y][x] = '-';
			break;
		}
		case'#':
		/*CASO A CASA ATACADA POSSUIR UM NAVIO PREENCHE COM UM SIMBOLO QUE SIGNIFICA QUE O
		* TIRO FOI CERTEIRO OU SEJA (X);
		*/
		{
			enemyTable[y][x] = 'X';
			break;
		}
		case'X':
		/*CASO A CASA ATACADA JA ESTIVER SIDO ATACADA, PROBLEMA DO JOGADOR, NADA Ã‰ ACERTADO
		 * E A CASA CONTINUA COM O SIMBOLO DE ACERTO (X)
		 */
		{
			enemyTable[y][x] = 'X';
			break;
		}
		case'-':
		/*CASO A CASA ATACADA JA ESTIVER SIDO ATACADA E ERRRADA, PROBLEMA DO JOGADOR,
		* NADA Ã‰ ACERTADO E A CASA CONTINUA COM O SIMBOLO DE ACERTO (O)
		*/
		{
			enemyTable[y][x] = '-';
			break;
		}
	}
	
	printf("attacado em: %c\n",enemyTable[y][x]);
	return 0;
}


int PrintTable()
/*ESSE METODO IMPRIMI O TABULEIRO DO JOGADOR E DO INIMIGO NA TELA*/
{
	int i,j;
	printf("  | A | B | C | D | E | F | G | H | I | J |=|=| A | B | C | D | E | F | G | H | I | J |\n\n");

	for(i = 0;i<10;i++)	//linha
	{
		printf("%d |",i);
		for(j = 0;j<10;j++)	//coluna
		{
			printf(" %c |",myTable[i][j]);
		}
		
		printf("=|=|");	
		
		for(j = 0;j<10;j++)	//coluna
			{
				char temp = enemyTable[i][j];
				if (temp == '#')
				/*POR SE TRATAR DO TABULEIRO INIMIGO, NÃƒO SE PODE MOSTRAR AS CASAS QUE
				 * POSSUEM NAVIO, LOGO O SIMBOLO DO NAVIO Ã‰ MASCARADO POR UM VAZIO
				 */
				{
					temp = ' ';
				}
				printf(" %c |",temp);
			}
		printf(" %d",i);
		printf("\n\n");
	}
	
		printf("  | A | B | C | D | E | F | G | H | I | J |=|=| A | B | C | D | E | F | G | H | I | J |\n\n");
		printf("------------\n");
	return 0;
}

int main(){
  int udpSocket, nBytes;
  char buffer[1024];
  struct sockaddr_in serverAddr, clientAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size, client_addr_size;
  int i;

  /*Create UDP socket*/
  udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

  /*Configure settings in address struct*/
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("192.168.0.10");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  /*Bind socket with address struct*/
  bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  /*Initialize size variable to be used later on*/
  addr_size = sizeof serverStorage;
  
  ZerarMapa(myTable);
  PortaAviao(myTable);
  Encouracado(myTable);
  Cruzador(myTable);
  Submarino(myTable);
  
  ZerarMapa(enemyTable);
  PortaAviao(enemyTable);
  Encouracado(enemyTable);
  Cruzador(enemyTable);
  Submarino(enemyTable);
  
  printf("Voce ira jofar depois\n");
  PrintTable();

  while(1){

	  printf("\nAGUARGANDO ADVERSARIO...\n");
	  recvfrom(udpSocket,myTable,sizeof(myTable),0,(struct sockaddr *)&serverStorage, &addr_size);
	  printf("\n\n				TURNO INIMIGO:\n");
	  PrintTable();

	  contarNavios();
	  /*CHECA SE ESSE JOGADOR PERDEU ANTES DE PERMITIR QUE ELE JOGUE
	   *
	   */
	  if(ganhou == 1)
	  {
		  break;
	  }

	  int x, y;
	  char charx;

	  printf("seu turno:\n");
	  printf("digite uma letra:\n");
	  scanf("%c",&charx);
	  printf("digite um numero:\n");
	  scanf("%d",&y);
	  getchar();//Limpa os caractéres escritos

	  printf("\n\n				SEU TURNO:\n");
	  Attack(x,y);
	  PrintTable();
	  sendto(udpSocket,enemyTable,sizeof(enemyTable),0,(struct sockaddr *)&serverStorage,addr_size);

	  contarNavios();
	  /*CHECA SE ESSE JOGADOR VENCEU ANTES DE PERMITIR O MOVIMENTO ADVERSARIO
	  *
	  */
	  if(ganhou == 1)
	  {
		  break;
	  }
  }

  return 0;
}
