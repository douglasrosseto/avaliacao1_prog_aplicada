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

    //só faz algo na string se tiver números
    if (contarNums > 0) {
        //criar variável com o tamanho da string + o número de Z
        char * novaString = malloc(tamanhoString + contarNums + 1);

        //copia string antiga com a nova string com os Zs 
        int temp = 0;
        for (int i = 0; i < tamanhoString; i++) {

            novaString[temp++] = str[i];

            if (str[i] == '0') {
                novaString[temp-1] = 'Z';
                novaString[temp++] = 'A';
            }
            if (str[i] == '1') {
                novaString[temp-1] = 'Z';
                novaString[temp++] = 'B';
            }
            if (str[i] == '2') {
                novaString[temp-1] = 'Z';
                novaString[temp++] = 'C';
            }
            if (str[i] == '3') {
                novaString[temp-1] = 'Z';
                novaString[temp++] = 'D';
            }
            if (str[i] == '4') {
                novaString[temp-1] = 'Z';
                novaString[temp++] = 'E';
            }
            if (str[i] == '5') {
                novaString[temp-1] = 'Z';
                novaString[temp++] = 'F';
            }
            if (str[i] == '6') {
                novaString[temp-1] = 'Z';
                novaString[temp++] = 'G';
            }
            if (str[i] == '7') {
                novaString[temp-1] = 'Z';
                novaString[temp++] = 'H';
            }
            if (str[i] == '8') {
                novaString[temp-1] = 'Z';
                novaString[temp++] = 'I';
            }
            if (str[i] == '9') {
                novaString[temp-1] = 'Z';
                novaString[temp++] = 'J';
            }
        }
        novaString[temp] = 0;
        return novaString;
    }

    if (contarNums == 0) {
        return str;
    }
}

//função para contar quantas vezes o caractere se repete
int tamanho_max = 128;
char * contarRepeticao(char * str) {
    char caracter, contador = 1, i = 0, *saida = malloc(tamanho_max);
    while ((caracter = * str++) != '\0') {
        if (caracter != * str) {
            if (contador > 1)
                i += sprintf(saida + i, "%d", contador);
            *(saida + i++) = caracter;
            contador = 0;
        }
        contador++;
    }
    *(saida + i) = '\0';
    return saida;
}

//funcão para decodificar a string começando pela repetição de caracteres
char * decodificarRepeticao(char * str){
    char caracter, contador = 0, i = 0, *saida = malloc(tamanho_max);
    while ((caracter = * str++) != '\0') {
        if ('0' <= caracter && caracter <= '9') {
            contador = contador * 10 + (caracter - '0');
            continue;
        }
        if (contador == 0)
            contador = 1;
        do
            *(saida + i++) = caracter;
        while (--contador);
    }
    *(saida + i) = '\0';
    return saida;
}

int main(){

    //pede opção para o usuário, codificar ou decodificar
    printf("\nDigite C para fazer o encode ou D para fazer o decode: \n");
    char opcao;
    scanf("%c", &opcao);
    
    //confere se o usuário digitou C ou D para fazer o encode ou decode
    if(opcao == 'C'){
        //lê o input do usuário
        printf("\nDigite o texto a ser codificado: \n");
        char texto[1000];
        scanf("%s", texto); 

        //chama as funções para codificar
        char * codificado = contarQntZs(texto);
        char * codificado2 = checarSeTemNumeros(codificado);
        char * codificado3 = contarRepeticao(codificado2);
        //printa o output da codificação
        printf("\nTexto codificado:\n%s", codificado3);
    }

    if(opcao == 'D'){
        //lê o input do usuário
        printf("\nDigite o texto a ser decodificado: \n");
        char texto[1000];
        scanf("%s", texto); 

        //chama as funções para decodificar
        char * decodificado = decodificarRepeticao(texto);
        //printa o output da decodificação
        printf("\nTexto decodificado:\n%s", decodificado);
    }

    //em caso de nenhuma das opções acima, o usuário é avisado que o caractere digitado é inválido
    if (opcao != 'C' && opcao != 'D'){
        printf("Opção inválida");
    }

}