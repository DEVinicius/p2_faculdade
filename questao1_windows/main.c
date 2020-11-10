/*
    Questoes realizadas pelos alunos
    * Lucas Lupoli Barbosa Ayoub - RA: 21443977
    * Willian dos Santos Silva - RA:21427800
    * Vinícius Pereira de Oliveira - RA: 21504714
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcoes.c"

typedef struct func
{
	/*
        Declaração das variaveis, onde é declarado o vetor nome, utilizado para calcular o tamanho da string nome. Que
        por sua vez, possui um número máximo de 50 caracteres.

        A declaração da variavel id serve para numerar os usuarios cadastrados na lista.
        Por último o contador_letras, que é um vetor de 26 espaços que vai contabilizar a quantidade de vezes que cada caracter, seja ele maiusculo ou minusculo aparece.
    */
 
 char nome[50];
 int id;
 char cpf [20];
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
	/*
        FEATURE OBRIGATÓRIA

        Essa feature vai criar um menu onde o usuario vai poder escolher uma das 3 opcoes disponiveis "inserir funcionarios" "exibir funcionarios" ou "sair do programa".
        Caso o usuario nao escolha uma das opcoes disponiveis, o menu entrara em loop até que o usuario escolha uma das opcoes correta.
    */
	while(situacao_menu == 1){
 	printf("\ndigite: \n1 - inserir funcionarios \n2 - exibir funcionarios \n3 - sair do programa \nescolha uma opcao: ");
 	scanf("%d", &escolha_menu);
 	switch(escolha_menu){
 		case 1:
 			if(indice_vetor < 5){
 				dados[indice_vetor].id = indice_vetor +1;
				
				/*
        		FEATURE OBRIGATÓRIA
        		
				Essa feature vai analisar se o nome do funcionário inserido contém somente letras maiúsculas ou
				minúsculas e tambem sem acentuação gráfica, caracteres especial e espaço em branco.
				E se os nomes digitados sao maiores do que 49 caracteres
    			*/
				do
				{
					printf("Digite o nome do funcionario: ");
					fflush(stdin); 
					fgets(dados[indice_vetor].nome, 49, stdin);
					
					if(maiusculo(dados[indice_vetor].nome))
					{
						printf("\nTodas as letras sao maiusculas\n\n");
						situacao_nome = 0;
					}
					else if(minusculo(dados[indice_vetor].nome))
					{
						printf("\nTodas as letras sao minusculas\n\n");
						situacao_nome = 0;
					}
					else
					{
						printf("\nDigite o nome so com letras maiusculas ou minusculas\n\n");
					}
					
					
				}while (situacao_nome == 1);
				
				/*FEATURE NÃO OBRIGATÓRIA

                Essa feature faz a verificacao se o dado .dd tem um valor maior quem 100 ou ou menor que 0. 
				Ja na parte dos numeros de telefone ele verifica se o dado .tel digitado
				tem um valor menor que 900000000 ou maior 999999999.
				Caso o usuario nao coloque um dado valido ira aparecer uma mensagem, "DD invalido / tel. invalido".
				O sistema entrara em loop ate q o usuario digite um numero que esteja dentro dos parametros.
				 
				 */
                
				do{
				 
				printf("\nDigite seu telefone celular com DD: ");
				scanf("%02d%09d", &dados[indice_vetor].dd, &dados[indice_vetor].tel);
				fflush(stdin);

					if (dados[indice_vetor].dd > 100 || dados[indice_vetor].dd < 0 || dados[indice_vetor].tel < 900000000 || dados[indice_vetor].tel > 999999999)
					{
						printf("DD invalido / tel. invalido.\n");
						printf("%d\n", dados[indice_vetor].dd);
						printf("%d", dados[indice_vetor].tel);
					}
				  }
				        while(dados[indice_vetor].dd > 100 || dados[indice_vetor].dd < 0 || dados[indice_vetor].tel < 900000000 || dados[indice_vetor].tel > 999999999);
				 				 

				do{
					printf("\nDigite o CPF: ");
					scanf("%s", dados[indice_vetor].cpf);

					if(verificaCpf(dados[indice_vetor].cpf ) == false){
						printf("CPF Invalido.\nSo aceitamos numeros\nDigite novamente\n\n ");
					}
					else
					{
						printf("CPF Aceito\n\n\n");
					}
					
				}while(verificaCpf(dados[indice_vetor].cpf) == false);
				
				/*FEATURE NÃO OBRIGATÓRIA

                Essa feature verifica se a data de nascimento que o usuario digitou esteja correta.
				Para isso o dado .ano tem que estar entre ou igual 1950 a 2020 assim validando o ano.
				Tambem verifica se dado .mes esteja entre ou igual a 1 a 12 assim validando o mes.  
                A feature tambem analisa se o mes que o usuario digitou tem 30 ou 31 dias, e se é ano bissexto com o mes 2 contendo 28 ou 29 dias.
				*/
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
		/*FEATURE DE EXIBIÇÃO
			Seção que realizará todas as ex
		*/
			if(indice_vetor == 0){
				printf("nao ha funcionarios cadastrados");
			}
			else{
				for(contador = 0; contador < indice_vetor; contador ++){
						 printf("\nId\t\t\tNome\t\t\tTel.\t\t\tCPF\t\tData de nascimento\n");
						 printf("\n%d\t\t%s\t\t(%d) %d\t\t %s\t\t\t %i/%i/%i\n", dados[contador].id, dados[contador].nome, dados[contador].dd, dados[contador].tel, dados[contador].cpf, dados[contador].dia, dados[contador].mes, dados[contador].ano);
						 
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
