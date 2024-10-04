#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include "parsexec.h"

static char comando[100] = "olhar ao redor";

static bool pegar_comando(void){
    printf("\n--> ");
    return fgets(comando, sizeof(comando), stdin) != NULL;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    printf("Bem-vindo ao nosso exemplo na UFPB!\n");
    while(comparaeExecuta(comando) && pegar_comando());
    printf("Tchau tchau!\n");
    return 0;
}
