#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include "parsexec.h"
#include "tutorial.h"
#include "survive.h"

static char comando[100] = "tutorial";

static bool pegar_comando(void){
    printf("\n--> ");
    return fgets(comando, sizeof(comando), stdin) != NULL;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    // Adicionei uma checagem para saber se o personagem est� vivo
    while(comparaeExecuta(comando) && checkStatus() && pegar_comando())
        loseSanidade(2); // Cada comando faz voc� perder sanidade (Pois s� o fato de estar nesse local faz vc perder sanidade)
        update_status();
    printf("Tchau tchau!\n");
    return 0;
}
