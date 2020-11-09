/*
    Questoes realizadas pelos alunos
    * Lucas Lupoli Barbosa Ayoub - RA: 21443977
    * Willian dos Santos Silva - RA:21427800
    * Vinícius Pereira de Oliveira - RA: 21504714
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    /*
        Declaração das variaveis, onde é declarado o vetor indice, utilizado para calcular o tamanho da string frase. A 
        string frase, por sua vez, possui um número máximo de 250 caracteres.

        A declaração da variavel i serve para percorrer o vetor frase de acordo com o seu tamanho (variavel indice).
        Por último o contador_letras, que é um vetor de 26 espaços que vai contabilizar a quantidade de vezes que cada caracter, seja ele maiusculo ou minusculo aparece.
    */
    int indice = 0;
    char frase[250];
    int i = 0;
    int contador_letras[27] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


    /*
        FEATURE OBRIGATÓRIA

        Essa feature vai pedir dados em forma de texto para o usuário até ele digitar o comando "~"
        Enquanto o usuário for adicionando caracteres, automaticamente o valor da variavel indice aumenta
    */
    printf("Escreva seu texto (Digite ~ para finalizar): \n");

    while((frase[indice] = fgetc(stdin)) != '~')
    {
        indice++;
    }

    /*
        FEATURE NÃO OBRIGATÓRIA

        Caso a frase / texto tenha mais de 200 caracteres, automaticamente o sistema da o aviso ao usuário,
        informando que o devido conteudo inserido possui caracteres que o suportado
    */

    if((strlen(frase) - 1) > 200)
    {
        printf("Frase com mais de 200 caracteres");
        
        return 0;
    }
    else
    {
        /*
            FEATURE OBRIGATÓRIA

            Feature que analisa cada caracter, seja ele maiusculo ou minusculo 
            e vai incrementando no vetor contador_letras de acordo com o seu 
            respectivo espaço
        */
        frase[indice++] = '\0';
        for(i = 0; i < indice - 1; i++)
        {
            if(frase[i] == 'a' || frase[i] == 'A')
            {
                contador_letras[0] ++;
            }

            if(frase[i] == 'b' || frase[i] == 'B')
            {
                contador_letras[1] ++;
            }

            if(frase[i] == 'c' || frase[i] == 'C')
            {
                contador_letras[2] ++;
            }

            if(frase[i] == 'd' || frase[i] == 'D')
            {
                contador_letras[3] ++;
            }

            if(frase[i] == 'e' || frase[i] == 'E')
            {
                contador_letras[4] ++;
            }

            if(frase[i] == 'f' || frase[i] == 'F')
            {
                contador_letras[5] ++;
            }

            if(frase[i] == 'g' || frase[i] == 'G')
            {
                contador_letras[6] ++;
            }

            if(frase[i] == 'h' || frase[i] == 'H')
            {
                contador_letras[7] ++;
            }

            if(frase[i] == 'i' || frase[i] == 'I')
            {
                contador_letras[8] ++;
            }

            if(frase[i] == 'j' || frase[i] == 'J')
            {
                contador_letras[9] ++;
            }

            if(frase[i] == 'k' || frase[i] == 'K')
            {
                contador_letras[10] ++;
            }

            if(frase[i] == 'l' || frase[i] == 'L')
            {
                contador_letras[11] ++;
            }

            if(frase[i] == 'm' || frase[i] == 'M')
            {
                contador_letras[12] ++;
            }

            if(frase[i] == 'n' || frase[i] == 'N')
            {
                contador_letras[13] ++;
            }

            if(frase[i] == 'o' || frase[i] == 'O')
            {
                contador_letras[14] ++;
            }

            if(frase[i] == 'p' || frase[i] == 'P')
            {
                contador_letras[15] ++;
            }

            if(frase[i] == 'q' || frase[i] == 'Q')
            {
                contador_letras[16] ++;
            }

            if(frase[i] == 'r' || frase[i] == 'R')
            {
                contador_letras[17] ++;
            }

            if(frase[i] == 's' || frase[i] == 'S')
            {
                contador_letras[18] ++;
            }

            if(frase[i] == 't' || frase[i] == 'T')
            {
                contador_letras[19] ++;
            }

            if(frase[i] == 'u' || frase[i] == 'U')
            {
                contador_letras[20] ++;
            }

            if(frase[i] == 'v' || frase[i] == 'V')
            {
                contador_letras[21] ++;
            }
            
            if(frase[i] == 'w' || frase[i] == 'W')
            {
                contador_letras[22] ++;
            }

            if(frase[i] == 'x' || frase[i] == 'X')
            {
                contador_letras[23] ++;
            }

            if(frase[i] == 'y' || frase[i] == 'Y')
            {
                contador_letras[24] ++;
            }

            if(frase[i] == 'z' || frase[i] == 'Z')
            {
                contador_letras[25] ++;
            }


            /*
                FEATURE NÃO OBRIGATÓRIA

                Faz a verificacao se algum numero foi digitado,
                A verificacao é feita de acordo com a tabela ASCII,
                Os valores dos numeros e caracteres especiais em caracter vao da sequencia 33 até 64 e da 91 até a 96.
            */
            if(frase[i] >= 33 && frase[i] <= 64 || frase[i] >= 91 && frase[i] <= 96)
            {
                contador_letras[26] ++;
            }
        }


        /*
            EXIBIÇÃO DA CONTAGEM POR LETRA E NUMERO

            Nessa seçao é exibido todos os resultados de todas as contagens feitas
            Os resultados estão dispostos em ordem alfabética com a quantidade de numeros e caracteres especiais no final
        */
        printf("Letra\tQuantidade\n");
        printf("A\t%d\n",contador_letras[0]);
        printf("B\t%d\n",contador_letras[1]);
        printf("C\t%d\n",contador_letras[2]);
        printf("D\t%d\n",contador_letras[3]);
        printf("E\t%d\n",contador_letras[4]);
        printf("F\t%d\n",contador_letras[5]);
        printf("G\t%d\n",contador_letras[6]);
        printf("H\t%d\n",contador_letras[7]);
        printf("I\t%d\n",contador_letras[8]);
        printf("J\t%d\n",contador_letras[9]);
        printf("K\t%d\n",contador_letras[10]);
        printf("L\t%d\n",contador_letras[11]);
        printf("M\t%d\n",contador_letras[12]);
        printf("N\t%d\n",contador_letras[13]);
        printf("O\t%d\n",contador_letras[14]);
        printf("P\t%d\n",contador_letras[15]);
        printf("Q\t%d\n",contador_letras[16]);
        printf("R\t%d\n",contador_letras[17]);
        printf("S\t%d\n",contador_letras[18]);
        printf("T\t%d\n",contador_letras[19]);
        printf("U\t%d\n",contador_letras[20]);
        printf("V\t%d\n",contador_letras[21]);
        printf("W\t%d\n",contador_letras[22]);
        printf("X\t%d\n",contador_letras[23]);
        printf("Y\t%d\n",contador_letras[24]);
        printf("Z\t%d\n\n\n",contador_letras[25]);
        printf("caracteres especiais\t%d\n",contador_letras[26]);
    }
    
}