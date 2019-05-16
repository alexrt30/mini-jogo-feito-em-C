#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <gconio.h>
 typedef struct Pessoa{
	 int num1, num2, res, pontos;
	 char nome[100];
	 }Pessoa;

int Menu(){
	int op=0;
	printf("\nSeja bem vindo ao Desafio dos Números!\n\n");
	printf("Tente alcançar a pontuação mais alta!\n\n");
	printf("\n  ------MENU------\n");
	printf("_____________________\n");
	printf("[1] PLAY GAMER\n");
	printf("_____________________\n");
	printf("[2] RANKING\n");
	printf("_____________________\n");
	printf("[3] CONFIGURAÇÃO\n");
	printf("_____________________\n");
	printf("[4] SOBRE\n");
	printf("_____________________\n");
	scanf(" %d", &op);
	system("clear");
	return op;
	}

void Multiplicacao(FILE* arq, FILE* rank){
    Pessoa aux;
    int r, c=3, pont=0;
    
    printf("Voce tem %d chances/n", c);
    printf("\nBORA JOGAR :)/n/n");
    
    fseek(arq,0,SEEK_SET);
    while(fread(&aux,sizeof(Pessoa),1,arq)){
        printf("\n\nQUANTO É: %dX%d=",aux.num2, aux.num1);
        scanf(" %d", &r);
        if(r==aux.res){
			printf("___________________________ \n");
			printf("Uau!!! Parabens voce acertou\n");
			printf("___________________________ \n");
			pont=pont+4;
			}else{
				c--;
				printf("___________________________ \n");
				printf("Que triste :(  Voce errou\n");
				printf("RESPOSTA CORRETA ERA: %d \n",aux.res);
				printf("___________________________ \n");
				if(c!=0){
					printf("Voce ainda tem %d chances/n", c);
					printf("\n___________________________ \n");
					}
				
				}
	setbuf(stdin,NULL);
	getchar();
	system("clear");
	if(c!=0)
	printf("PONTOS: %d\nCHANCES: %d\n", pont, c);
	
	if(c==0){
	system("clear");
	printf("INFELIMENTE, Voce perdeu\n");
	printf("SUA PONTUAÇÃO: %d\n\n",pont);
	Pessoa aux;
	    printf("Digite seu nome\n");
	    scanf(" %[^\n]s",aux.nome);
	    aux.pontos=pont;
        fseek(rank,0,SEEK_END);
        fwrite(&aux,sizeof(Pessoa),1,rank);
		getchar();
		system("clear");
		break;
		}
    }
}	

		

void Subtracao(FILE* arq, FILE* rank){
    Pessoa aux;
    int x=0, r, c=3, pont=0;
    
    printf("Voce tem %d chances/n", c);
    printf("\nBORA JOGAR :)/n/n");
    
    fseek(arq,0,SEEK_SET);
    while(fread(&aux,sizeof(Pessoa),1,arq)){
		x++;
		if(x==100)
		break;
        printf("\n\nQUANTO É: %d-%d=",aux.num2, aux.num1);
        scanf(" %d", &r);
        if(r==aux.res){
			printf("___________________________ \n");
			printf("Uau!!! Parabens voce acertou\n");
			printf("___________________________ \n");
			pont=pont+4;
			}else{
				c--;
				printf("___________________________ \n");
				printf("Que triste :(  Voce errou\n");
				printf("RESPOSTA CORRETA ERA: %d \n",aux.res);
				printf("___________________________ \n");
				if(c!=0){
					printf("Voce ainda tem %d chances/n", c);
					printf("\n___________________________ \n");
					}
				
				}
	setbuf(stdin,NULL);
	getchar();
	system("clear");
	if(c!=0)
	printf("PONTOS: %d\nCHANCES: %d\n", pont, c);
	
	if(c==0){
		system("clear");
		printf("INFELIMENTE, Voce perdeu\n");
		printf("SUA PONTUAÇÃO: %d\n\n",pont);
		Pessoa aux;
	    printf("Digite seu nome\n");
	    scanf(" %[^\n]s",aux.nome);
	    aux.pontos=pont;
        fseek(rank,0,SEEK_END);
        fwrite(&aux,sizeof(Pessoa),1,rank);
		getchar();
		system("clear");
		break;
		}
    }
}	


void Adicao(FILE* arq, FILE* rank){
    Pessoa aux;
    int x=0, r, c=3, pont=0;
    system("clear");
    printf("Voce tem %d chances\n", c);
    printf("\nBORA JOGAR :)\n");
    
    fseek(arq,0,SEEK_SET);
    while(fread(&aux,sizeof(Pessoa),1,arq)){
		x++;
		if(x==100)
		break;
        printf("\n\nQUANTO É: %d+%d=",aux.num1, aux.num2);
        scanf(" %d", &r);
        if(r==aux.res){
			printf("___________________________ \n");
			printf("Uau!!! Parabens voce acertou\n");
			printf("___________________________ \n");
			pont=pont+4;
			}else{
				c--;
				printf("___________________________ \n");
				printf("Que triste :(  Voce errou\n");
				printf("RESPOSTA CORRETA ERA: %d \n",aux.res);
				printf("___________________________ \n");
				if(c!=0){
					printf("Voce ainda tem %d chances/n", c);
					printf("\n___________________________ \n");
					}
				
				}
	setbuf(stdin,NULL);
	getchar();
	system("clear");
	if(c!=0)
	printf("PONTOS: %d\nCHANCES: %d\n", pont, c);
	
	if(c==0){
		system("clear");
		printf("INFELIMENTE, Voce perdeu\n");
		printf("SUA PONTUAÇÃO: %d\n\n",pont);
		Pessoa aux;
	    printf("Digite seu nome\n");
	    scanf(" %[^\n]s",aux.nome);
	    aux.pontos=pont;
        fseek(rank,0,SEEK_END);
        fwrite(&aux,sizeof(Pessoa),1,rank);
		getchar();
		system("clear");
		break;
		}
    }
}	



void Rank(FILE* rank){
	
	Pessoa vet[100]; 
	int x=0, aux2;
	char aux3[100];
	
    fseek(rank,0,SEEK_SET);
    while(fread(&vet[x++],sizeof(Pessoa),1,rank));
	x--;
	
	
 	for(int i=0; i<x; i++){
		for(int j=i; j<x; j++){
			if(vet[i].pontos<vet[j].pontos){
			  aux2=vet[i].pontos;
			  vet[i].pontos=vet[j].pontos;
			  vet[j].pontos=aux2;
			  
			  strcpy(aux3,vet[i].nome);
			  strcpy(vet[i].nome,vet[j].nome);
			  strcpy(vet[j].nome,aux3);
					  }
				}
				}   
    
    system("clear");
    if(x!=0)
    printf("RANK DOS MELHORES DOS JOGADORES\n\n");
    for(int i=0; i<x; i++){
		printf("Nome: %s Pontuação: %d\n",vet[i].nome, vet[i].pontos);
		}
	if(x==0)
		printf("\n\n\n\n\n\n\n\n###Vazio, Seu nome pode esta aqui basta jogar :)###\n\n ");
	sleep(3);
	system("clear");
	}
	
	
void MenuJogo(FILE* arq, FILE* sub, FILE* mult, FILE* rank){
	int op;
	printf("ESCOLHA SUA OPÇÃO\n\n");
	printf("[1]ADIÇÃO\n");
	printf("[2]SUBTRAÇÃO\n");
	printf("[3]MULTIPLICAÇÃO\n");
	scanf(" %d", &op);
	switch(op){
		case 1:
		Adicao(arq, rank);
		break;
		
		case 2:
		Subtracao(sub, rank);
		break;
		
		case 3:
		Multiplicacao(mult, rank);
		break;
		}
	
	}

void Att(FILE* arq, FILE* sub, FILE* mult){
	int op;
	printf("___________________________ \n");
	printf("BEM-VINDO AS CONFIGURAÇÃO\n\n");
	printf("___________________________ \n");
	printf("[1]Atualizar dados\n");
	printf("___________________________ \n");
	printf("[2]Menu principal\n");
	printf("___________________________ \n");
	scanf(" %d", &op);
	switch(op){
		case 1:
		remove("soma.txt");
		remove("sub.txt");
		remove("mult.txt");
		system("clear");
		break;
		
		case 2:
		system("clear");
		Menu();
		break;
		
		}
	
	}
	
	

void Gravar(FILE* arq, FILE* sub, FILE* mult){
	Pessoa aux;
	int i=0;
	do{
		aux.num1=rand()%9;
		aux.num2=rand()%9;
		aux.res=aux.num2+aux.num1;
		fseek(arq,0,SEEK_END);
		fwrite(&aux,sizeof(Pessoa),1,arq);
		i++;
		}while(i!=100);
		
	i=0;	
	do{
		aux.num1=rand()%9;
		aux.num2=rand()%3;
		aux.res=aux.num2*aux.num1;
		fseek(mult,0,SEEK_END);
		fwrite(&aux,sizeof(Pessoa),1,mult);
		i++;
		}while(i!=100);
		
	i=0;	
	do{
		aux.num1=rand()%9;
		aux.num2=rand()%9;
		aux.res=aux.num2-aux.num1;
		fseek(sub,0,SEEK_END);
		fwrite(&aux,sizeof(Pessoa),1,sub);
		i++;
		}while(i!=100);	
	

	}
	
void Sobre(){
	printf("-------------------------------\n");
	printf(" Criadores: Alex, Emanuel\n");
	printf("\n Proposta do jogo\n Usa como ferramenta nas aulas de Matemática,\n o jogo ajudam a criar contextos de aprendizagem\n significativos. Mas é preciso acertar\n na escolha e compreender.\n");
	printf(" O jogo contem contas simples de Adição,\n Subtração, Multiplicação e Divisão\n");
	printf("\n\n Caro professor esse codigo deu muito trabalho,\n Merecemos 5 pontos só pelas as raivas que passamos.\n");
	printf(" OBRIGADO\n");
	printf("\n\nCopyright © 2016-2018\n");

	printf("-------------------------------\n");
	setbuf(stdin,NULL);
	getchar();
	system("clear");
	}

	
int main(void){
  srand(time(NULL));
  FILE* soma; 
  FILE* sub;
  FILE* mult; 
  FILE* rank;  
	soma = fopen("soma.txt","rb+");
	sub = fopen("sub.txt","rb+");
	mult = fopen("mult.txt","rb+");
	rank = fopen("rank.txt","rb+");
    if(!soma){
		soma = fopen("soma.txt","wb+");
		sub = fopen("sub.txt","wb+");
		sub = fopen("mult.txt","wb+");
		}
		
   Gravar(soma, sub, mult);
  
  int op;
  do{
	  
	  switch(op=Menu()){
		  case 1:
		  MenuJogo(soma, sub, mult, rank);
		  break;
		  case 2:
		  Rank(rank);
		  break;
		  case 3:
		  Att(soma, sub, mult);
		  break;
		  case 4:
		  Sobre();
		  break;
		  }
	  }while(op!=0);
  fclose(soma);
  fclose(sub);
  fclose(mult);
   fclose(rank);
  printf("Arquivo Fechado");
  return(0);
}
