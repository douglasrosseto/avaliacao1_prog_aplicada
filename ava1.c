#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//função de contar quantos Z tem na string
char * contarQntZs(char * str) {
    int tamanhoString = strlen(str);

    //contar quantas vezes o Z aparece na string
    int contarZ = 0;
    for (int i = 0; i < tamanhoString; i++) {

        if (str[i] == 'Z'){ 
            contarZ++;
        }
    }

    //criar variável com o tamanho da string + o número de Z
    char * novaString = malloc(tamanhoString + contarZ + 1);

    //copia string antiga com a nova string com os Zs 
    int temp = 0;
    for (int i = 0; i < tamanhoString; i++) {

        novaString[temp++] = str[i];

        if (str[i] == 'Z'){ 
            novaString[temp++] = 'Z';
        }
    }

    novaString[temp] = 0;
    return novaString;
}

//função de decodificação
char * decodificar (char * str){
    return str;
}

int main(){

    //pede opção para o usuário, codificar ou decodificar
    printf("\nDigite C para fazer o encode ou D para fazer o decode: \n");
    char opcao;
    scanf("%c", &opcao);
    
    //confere se o usuário digitou C ou D para fazer o encode ou decode
    if(opcao == 'C'){
        printf("\nDigite o texto a ser codificado: \n");
        char texto[1000];
        scanf("%s", texto); 

        char * codificado = contarQntZs(texto);
        printf("\nTexto codificado:\n%s", codificado);
    }

    if(opcao == 'D'){
        printf("\nDigite o texto a ser decodificado: \n");
        char texto[1000];
        scanf("%s", texto); 

        char * decodificado = decodificar(texto);
        printf("\nTexto decodificado:\n%s", decodificado);
    }

    //em caso de nenhuma das opções acima, o usuário é avisado que o caractere digitado é inválido
    if (opcao != 'C' && opcao != 'D'){
        printf("Opcao invalida");
    }

}