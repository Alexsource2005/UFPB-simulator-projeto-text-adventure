#include <ctype.h> //usaremos a fun��o "isspace()" para fazer um teste mais apurado. isspace() retorna 0 se o caractere passado N�O FOR um espa�o vazio
#include <stdio.h>
#include <stdbool.h>
#include "objetos.h"
#include "misc.h"
#include "comparar.h"
#include "locais.h"
#include "inventory.h"
#include "inventory2.h"
#include "abrir_fechar.h"
#include "tutorial.h"
#include "survive.h"

typedef struct {
    const char *padrao;
    bool (*funcao)(void);

} tComando; // vai servir pra ligar um padr�o de comando com uma fun��o de execu��o especifica

static bool exec_sair(void){
    return false;
}

static bool exec_sem_padrao(void){ // s� executa se o verbo inserido pelo jogador n�o estiver pr�-definido nos padr�es
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
        {"ir ao A", exec_ir},
        {"ir a A", exec_ir},
        {"ir A", exec_ir},
        {"pegar A de B", exec_pegarDE},
        {"pegar A do B", exec_pegarDE},
        {"pegar A da B", exec_pegarDE},
        {"pegar A", exec_pegar},
        {"jogar A em B", exec_jogarNO},
        {"jogar A no ch�o", exec_jogarNO},
        {"jogar A", exec_jogar},
        {"pedir A para B", exec_pedirPARA},
        {"pedir A ao B", exec_pedirPARA},
        {"pedir A a B", exec_pedirPARA},
        {"pedir A", exec_pedir},
        {"dar A para B", exec_darPARA},
        {"dar A ao B", exec_darPARA},
        {"dar A a B", exec_darPARA},
        {"dar A", exec_dar},
        {"colocar A em B", exec_colocarEM},
        {"checar o inventario", exec_inventario},
        {"checar inventario", exec_inventario},
        {"inventario", exec_inventario},
        {"abrir A", exec_abrir},
        {"fechar A", exec_fechar},
        {"programar arduino", exec_programar_arduino},
        {"construir chassi", exec_construir_chassi},
        {"construir carro de combate", exec_construir_carro_combate},
        {"tuto", exec_tutorial},
        {"tutorial", exec_tutorial},
        {"comer", exec_eat}, // Adicionei a fun��o de comer s� falta colocar
        {"dormir", exec_sleep}, // Adicionei a fun��o de dormir
        {"aliviar", exec_banheiro}, // Fun��o para quando chegar ao banheiro
        {"A", exec_sem_padrao}
    };

    const tComando *cmd;
    for(cmd = lista_comando; !compara_comando(comando, cmd->padrao); cmd++);
    return(*cmd->funcao)();
}
