#include <stdio.h> //bilioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca  de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string

int registro()
{
	//inicio criacao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criacao de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar as valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definido a linguagem
	
	char cpf[40];
	char conteudo[200];
	
 	printf("Digite o CPF a ser consultado: ");
 	scanf("%s",cpf);
 	
 	FILE *file;
 	file = fopen(cpf,"r");
 	
 	if(file == NULL)
 	{
 		printf("Nao foi possivel abrir o arquivo, nao localizado!.\n");
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL)
	 {
	 	printf("\nEssas sao as informacoes do usuario: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 }
	 
	 system("pause");
 	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf(" O usuaio nao se encontra no sistema!.\n");
		system("pause");
	}
	
}



int main()
{
	 int opcao=0; //Definido variaves
	 int laco=1;
	 
	 for(laco=1;laco=1;)
	 {
	 
	 system("cls");
	 
	 setlocale(LC_ALL, "portuguese"); //Definido a linguagem
	
	 printf("### Cartorio da EBAC ###\n\n"); //inicio do menu
 	 printf("Escolha a opcao desejada do menu\n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n\n");
	 printf("\t4 - sair do sistema\n\n");
	 printf("opcao: ");//fim do menu
	
	 scanf("%d", &opcao); //armazenando a escolha do usuario
	
	 system("cls");
	
	 switch(opcao)
	 {
	 	case 1:
	 	registro(); //chama de funcoes
	 	break;
	 	
	 	case 2:
	 	consulta();
	   	break;
	   	
	   	case 3:
	   	deletar();
	 	break;
	 	
	 	case 4:
	 	printf(" Obrigado por utilizar o sistema!\n");
	 	return 0;
	 	break;
	 	
	 	
	 	default:
	 	printf("Essa opcao nao esta disponivel!\n");
	 	system("pause");
	 	break;
	 	
	 } 
 
  } 
}
