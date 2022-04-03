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

//função de checar se a string tem números
char * checarSeTemNumeros(char * str) {
    int tamanhoString = strlen(str);

    //contar quantas vezes o Z aparece na string
    int contarNums = 0;
    for (int i = 0; i < tamanhoString; i++) {

        if (str[i] >= '0' && str[i] <= '9') {
            contarNums++;
        }
    }

    //criar variável com o tamanho da string + o número de Z
    char * novaString = malloc(tamanhoString + contarNums + 1);

    //copia string antiga com a nova string com os Zs 
    int temp = 0;
    for (int i = 0; i < tamanhoString; i++) {

        novaString[temp++] = 'Z';

        if (str[i] == '0') {
            novaString[temp++] = 'A';
        }
        if (str[i] == '1') {
            novaString[temp++] = 'B';
        }
        if (str[i] == '2') {
            novaString[temp++] = 'C';
        }
        if (str[i] == '3') {
            novaString[temp++] = 'D';
        }
        if (str[i] == '4') {
            novaString[temp++] = 'E';
        }
        if (str[i] == '5') {
            novaString[temp++] = 'F';
        }
        if (str[i] == '6') {
            novaString[temp++] = 'G';
        }
        if (str[i] == '7') {
            novaString[temp++] = 'H';
        }
        if (str[i] == '8') {
            novaString[temp++] = 'I';
        }
        if (str[i] == '9') {
            novaString[temp++] = 'J';
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
        char * codificado2 = checarSeTemNumeros(codificado);
        printf("\nTexto codificado:\n%s", codificado2);
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