#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "funcoes.c"

typedef struct func
{
 int id;
 char nome[50];
 long cpf;
 int dia;
 int mes;
 int ano;
 int dd;
 int tel;
} tFuncionario;

void flush_in()
{
   int ch;

   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

int main(){
 tFuncionario dados[5];
 int escolha_menu = 0, situacao_menu = 1, indice_vetor = 0, contador = 0, situacao_data = 1, situacao_nome = 1;
 //Leitura dos dados
 while(situacao_menu == 1){
 	printf("\ndigite: \n1 - inserir funcionarios \n2 - exibir funcionarios \n3 - sair do programa \nescolha uma opcao: ");
 	scanf("%d", &escolha_menu);
 	switch(escolha_menu){
 		case 1:
 			if(indice_vetor < 5){
 				dados[indice_vetor].id = indice_vetor +1;
				
				do
				{
					printf("Digite o nome do funcionario: ");
					flush_in(); 
					fgets(dados[indice_vetor].nome, 49, stdin);
					
					if(maiusculo(dados[indice_vetor].nome))
					{
						printf("\nTodas as letras sao maiusculas");
						situacao_nome = 0;
					}
					else if(minusculo(dados[indice_vetor].nome))
					{
						printf("\nTodas as letras sao minusculas");
						situacao_nome = 0;
					}
					else
					{
						printf("\nDigite o nome so com letras maiusculas ou minusculas\n");
					}
					
					
				}while (situacao_nome == 1);

				do{
				 
					printf("\nDigite seu telefone celular com DD: ");
					scanf("%02d%09d", &dados[indice_vetor].dd, &dados[indice_vetor].tel);
					//fflush(stdin);
					flush_in(); 

					if (dados[indice_vetor].dd > 100 || dados[indice_vetor].dd < 0 || dados[indice_vetor].tel < 900000000 || dados[indice_vetor].tel > 999999999)
					{
						printf("DD invalido / tel. invalido.\n");
						printf("%d\n", dados[indice_vetor].dd);
						printf("%d", dados[indice_vetor].tel);
					}
				 }
				 
				 while(dados[indice_vetor].dd > 100 || dados[indice_vetor].dd < 0 || dados[indice_vetor].tel < 900000000 || dados[indice_vetor].tel > 999999999);
				 				 
				 printf("\nDigite o CPF: ");
				 scanf("%li", &dados[indice_vetor].cpf);
				 do{ 
			 		 printf("\nDigite a data de nascimento: ");
					 scanf("%02d%02d%04d", &dados[indice_vetor].dia, &dados[indice_vetor].mes, &dados[indice_vetor].ano);
					 if(dados[indice_vetor].ano <= 2020 && dados[indice_vetor].ano >= 1950){
						 	 if(dados[indice_vetor].mes > 0 && dados[indice_vetor].mes <= 12){
								if(dados[indice_vetor].mes == 1 || dados[indice_vetor].mes == 3 || dados[indice_vetor].mes == 5 || dados[indice_vetor].mes == 7 || dados[indice_vetor].mes == 10 || dados[indice_vetor].mes == 12){
									if(dados[indice_vetor].dia > 0 && dados[indice_vetor].dia <= 31){
										situacao_data = 0;
									}
									else{
										printf("dia invalido");
									}
								}
								else if(dados[indice_vetor].mes == 2){
									if(dados[indice_vetor].ano % 4 == 0){
										if(dados[indice_vetor].dia > 0 && dados[indice_vetor].dia <= 29){
											situacao_data = 0;
										}
										else{
											printf("dia do mes de fevereiro bissexto invalido");
										}
									}
									else{
												if(dados[indice_vetor].dia > 0 && dados[indice_vetor].dia <= 28){
											situacao_data = 0;
										}
										else{
											printf("dia do mes de fevereiro invalido");
										}
									}
								}
								else{
									if(dados[indice_vetor].dia > 0 && dados[indice_vetor].dia <= 30){
										situacao_data = 0;
									}
									else{
										printf("dia do mes invalido");
									}
								}
						 	}
							 else
							 {
								 printf("Mes invalido");
							 }
							 
					 	}
					 else{
					 	printf("ano invalido");
					 }
				 } while(situacao_data == 1);
			
				 indice_vetor ++;
			 }
			 else{
			 	printf("numero de usuarios excedidos");
			 }

 			
			break;
		case 2:
			if(indice_vetor == 0){
				printf("nao ha funcionarios cadastrados");
			}
			else{
				for(contador = 0; contador < indice_vetor; contador ++){
						 printf("\nID: %d\n", dados[contador].id);
						 printf("\nNome: %s\n", dados[contador].nome);
						 printf("\nTel. (%d) %d\n", dados[contador].dd, dados[contador].tel);
						 printf("\nCPF: %li\n", dados[contador].cpf);
						 printf("\nData de nascimento : %i/%i/%i\n\n\n\n", dados[contador].dia, dados[contador].mes, dados[contador].ano);
				}
				
			}
			break;
		case 3:
			exit(0);
			break;
	 }
 }
 
 return 0;
}//Fim da main()
