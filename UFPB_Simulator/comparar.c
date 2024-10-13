#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "objetos.h"
#include "misc.h"
#include "comparar.h"

const char *parametros[MAX_PARAMS]; //Declara um array que armazenará parâmetros correspondentes aos comandos.

static const char *pula_espacos(const char *source) { //Essa função avança o ponteiro src até o próximo caractere não-espaço, ignorando espaços em branco no início.
    while(isspace(*source))
        source++;
    return source;
}

static const char *compara_espacos(const char *source){ //Verifica se o caractere atual é um espaço ou se chegou ao fim da string. Se for um espaço ou fim, chama skipSpaces para continuar.
    return *source == '\0' || isspace(*source) ? pula_espacos(source) : NULL;
}

static const char *compara_terminal(const char *source, char terminal){ //Compara o caractere atual de src com um caractere terminal (terminal).
                                                                        //Se for um espaço, usa matchSpaces. Caso contrário, compara os caracteres de forma case-insensitive
    return terminal == ' ' ? compara_espacos(source) :
        tolower(*source) == tolower(terminal) ? source + 1 : NULL;
 }

static const char *compara_rotulo(const char *source, const char *rotulo, bool no_final) {  //Compara uma sequência de caracteres (tag) com a string src. Avança src enquanto os caracteres coincidirem. Se chegar ao fim da tag e ainda houver caracteres não tratados em src (dependendo do parâmetro atEnd), retorna NULL.
    while(source != NULL && *rotulo != '\0'){
        source = compara_terminal(source, *rotulo++);
    }
    return no_final && source != NULL && *pula_espacos(source) != '\0' ? NULL : source;
}

static const char *compara_parametro(const char *source, const char **param, bool solto) { //Esta função verifica os parâmetros de entrada contra uma lista de objetos (que podem ser comandos ou elementos). Ela itera pelos objetos e suas tags, procurando por correspondências. Se encontrar uma tag que corresponda a src, atualiza o parâmetro correspondente.
    const char *fim_de_source = solto ? source + strlen(source) : NULL;
    tObjetos *obj;

    for(obj = lista_objetos; obj < fim_lista; obj++) {
        const char **rotulo;
        for(rotulo = obj->rotulos; *rotulo != NULL; rotulo++){
            const char *behindmatch = compara_rotulo(source, *rotulo, solto);
            if(behindmatch != NULL && strlen(*rotulo) > strlen(*param)) {
                *param = *rotulo;
                fim_de_source = behindmatch;

            }
        }
    }
    if(**param == '\0')
        *param = source;
    return fim_de_source;
}

bool compara_comando(const char *source, const char *padrao) { //compara um comando (src) com um padrão (pattern).
    const char **param;
    for(param = parametros; param < parametros + MAX_PARAMS; param++) //Inicializa todos os parâmetros em params como strings vazias
        *param = "";

    for(source = pula_espacos(source); source != NULL && *padrao != '\0'; padrao++){ //Ignora espaços iniciais em src e então itera sobre cada caractere em pattern
        source = isupper(*padrao) ? compara_parametro(source, parametro_por_letra(*padrao), padrao[1]=='\0') : compara_terminal(source, *padrao); //Se o caractere em pattern for uma letra maiúscula, chama matchParam para verificar se há um parâmetro correspondente; caso contrário, chama matchTerminal para comparar diretamente.
    }
    return source != NULL && *pula_espacos(source) == '\0'; //No final, verifica se não restaram caracteres não processados em src, retornando true se todos os espaços foram tratados corretamente e se o comando foi reconhecido.
}
