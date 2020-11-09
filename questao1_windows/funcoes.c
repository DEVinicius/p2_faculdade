#include "funcoes.h"

/*
    Função que devolve verdadeiro caso todos os caracteres
    alfabéticos da string s sejam maiusculos
*/

bool maiusculo(char * palavra)
{
    bool resposta = true;
    // tamanho da string
    int tamanho_palavra = strlen(palavra) - 1;
    int contador = 0;
    if (tamanho_palavra == 0 ){
    	return false;
	}
    for(contador = 0; contador < tamanho_palavra; contador++)
    {
        /*
            PROCESSO DE VALIDAÇÃO

            Essa parte vai verificar se as letras são todas maiusculas 
            ou se possui algum espaço
        */
        if(!isupper(palavra[contador]))
        {
            if(palavra[contador] != ' ')
            {
                return false;
            }
        }
    }
    return true;
}



/*
    Função que devolve verdadeiro caso todos os caracteres
    alfabéticos da string s sejam minusculos
*/
bool minusculo(char * palavra)
{
    bool resposta = true;
    // tamanho da string
    int tamanho_palavra = strlen(palavra) - 1;
    int contador = 0;
	if (tamanho_palavra == 0 ){
    	return false;
    }
    for(contador = 0; contador < tamanho_palavra; contador++)
    {
        /*
            PROCESSO DE VALIDAÇÃO

            Essa parte vai verificar se as letras são todas minusculas 
            ou se possui algum espaço
        */
        if(!islower(palavra[contador]))
        {
            if(palavra[contador] != ' ')
            {
                return false;
            }
        }
    }
    return true;
}
