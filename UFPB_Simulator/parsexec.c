#include <ctype.h> //usaremos a função "isspace()" para fazer um teste mais apurado. isspace() retorna 0 se o caractere passado NÃO FOR um espaço vazio
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

} tComando; // vai servir pra ligar um padrão de comando com uma função de execução especifica

static bool exec_sair(void){
    return false;
}

static bool exec_sem_padrao(void){ // só executa se o verbo inserido pelo jogador não estiver pré-definido nos padrões
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
        {"ir ao A", exec_ir},
        {"ir a A", exec_ir},
        {"ir A", exec_ir},
        {"pegar A de B", exec_pegarDE},
        {"pegar A do B", exec_pegarDE},
        {"pegar A da B", exec_pegarDE},
        {"pegar A", exec_pegar},
        {"jogar A em B", exec_jogarNO},
        {"jogar A no chão", exec_jogarNO},
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
        {"comer", exec_eat}, // Adicionei a função de comer só falta colocar
        {"dormir", exec_sleep}, // Adicionei a função de dormir
        {"aliviar", exec_banheiro}, // Função para quando chegar ao banheiro
        {"A", exec_sem_padrao}
    };

    const tComando *cmd;
    for(cmd = lista_comando; !compara_comando(comando, cmd->padrao); cmd++);
    return(*cmd->funcao)();
}
