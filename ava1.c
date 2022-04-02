#include "stdio.h"

//função de codificação
char * codificar (char * str){
    return str;
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

        char * codificado = codificar(texto);
        printf("\nTexto decodificado:\n%s", codificado);
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