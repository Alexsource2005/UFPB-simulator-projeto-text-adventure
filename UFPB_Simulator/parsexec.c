#include <ctype.h> //usaremos a função "isspace()" para fazer um teste mais apurado. isspace() retorna 0 se o caractere passado NÃO FOR um espaço vazio
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

} tComando; // vai servir pra ligar um padrão de comando com uma função de execução especifica

static bool exec_sair(void){
    return false;
}

static bool exec_sem_padrao(void){
    const char *source = *parametros; // "parametros" vai ser uma variavel global
    int len;

    for(len = 0; source[len] != '\0' && !isspace(source[len]); len++); //calcula o tamanho da primeira palavra escrita pelo jogador (verbo)
    if(len > 0)
        printf("Eu não sei como %.*s.", len, source); //%.*s permite que antes do parametro de string coloquemos um número inteiro que limite o número máxximo de caracteres
    return true;
}

bool comparaeExecuta(char *comando){
    static const tComando lista_comando[] = //lista de padrões, para adicionar sinonimos, só adicionar e ligar a mesma função já existente
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
