#include <ctype.h> //usaremos a fun��o "isspace()" para fazer um teste mais apurado. isspace() retorna 0 se o caractere passado N�O FOR um espa�o vazio
#include <stdio.h>
#include <stdbool.h>
#include "objetos.h"
#include "misc.h"
#include "comparar.h" //implementar
#include "locais.h"
#include "inventory.h"
#include "abrir_fechar.h"

typedef struct {
    const char *padrao;
    bool (*funcao)(void);

} tComando; // vai servir pra ligar um padr�o de comando com uma fun��o de execu��o especifica

static bool exec_sair(void){
    return false;
}

static bool exec_sem_padrao(void){
    const char *source = *parametros; // "parametros" vai ser uma variavel global
    int len;

    for(len = 0; source[len] != '\0' && !isspace(source[len]); len++); //calcula o tamanho da primeira palavra escrita pelo jogador (verbo)
    if(len > 0)
        printf("Eu n�o sei como %.*s.", len, source); //%.*s permite que antes do parametro de string coloquemos um n�mero inteiro que limite o n�mero m�xximo de caracteres
    return true;
}

bool comparaeExecuta(char *comando){
    static const tComando lista_comando[] = //lista de padr�es, para adicionar sinonimos, s� adicionar e ligar a mesma fun��o j� existente
    {
        {"sair", exec_sair},
        {"olhar", exec_olhar_aoredor},
        {"olhar ao redor", exec_olhar_aoredor},
        {"olhar para A", exec_olhar},
        {"olhar A", exec_olhar},
        {"examinar A", exec_olhar},
        {"ir para A", exec_ir},
        {"ir A", exec_ir},
        {"jogar A", exec_jogar},
        {"pedir A", exec_pedir},
        {"dar A", exec_dar},
        {"checar inventario", exec_inventario},
        {"inventario", exec_inventario},
        {"abrir A", exec_abrir},
        {"fechar A", exec_fechar},
        {"A", exec_sem_padrao}
    };

    const tComando *cmd;
    for(cmd = lista_comando; !compara_comando(comando, cmd->padrao); cmd++);
    return(*cmd->funcao)();
}
