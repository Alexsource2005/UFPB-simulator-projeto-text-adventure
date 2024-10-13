#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "objetos.h"
#include "misc.h"
#include "comparar.h"

const char *parametros[MAX_PARAMS]; //Declara um array que armazenar� par�metros correspondentes aos comandos.

static const char *pula_espacos(const char *source) { //Essa fun��o avan�a o ponteiro src at� o pr�ximo caractere n�o-espa�o, ignorando espa�os em branco no in�cio.
    while(isspace(*source))
        source++;
    return source;
}

static const char *compara_espacos(const char *source){ //Verifica se o caractere atual � um espa�o ou se chegou ao fim da string. Se for um espa�o ou fim, chama skipSpaces para continuar.
    return *source == '\0' || isspace(*source) ? pula_espacos(source) : NULL;
}

static const char *compara_terminal(const char *source, char terminal){ //Compara o caractere atual de src com um caractere terminal (terminal).
                                                                        //Se for um espa�o, usa matchSpaces. Caso contr�rio, compara os caracteres de forma case-insensitive
    return terminal == ' ' ? compara_espacos(source) :
        tolower(*source) == tolower(terminal) ? source + 1 : NULL;
 }

static const char *compara_rotulo(const char *source, const char *rotulo, bool no_final) {  //Compara uma sequ�ncia de caracteres (tag) com a string src. Avan�a src enquanto os caracteres coincidirem. Se chegar ao fim da tag e ainda houver caracteres n�o tratados em src (dependendo do par�metro atEnd), retorna NULL.
    while(source != NULL && *rotulo != '\0'){
        source = compara_terminal(source, *rotulo++);
    }
    return no_final && source != NULL && *pula_espacos(source) != '\0' ? NULL : source;
}

static const char *compara_parametro(const char *source, const char **param, bool solto) { //Esta fun��o verifica os par�metros de entrada contra uma lista de objetos (que podem ser comandos ou elementos). Ela itera pelos objetos e suas tags, procurando por correspond�ncias. Se encontrar uma tag que corresponda a src, atualiza o par�metro correspondente.
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

bool compara_comando(const char *source, const char *padrao) { //compara um comando (src) com um padr�o (pattern).
    const char **param;
    for(param = parametros; param < parametros + MAX_PARAMS; param++) //Inicializa todos os par�metros em params como strings vazias
        *param = "";

    for(source = pula_espacos(source); source != NULL && *padrao != '\0'; padrao++){ //Ignora espa�os iniciais em src e ent�o itera sobre cada caractere em pattern
        source = isupper(*padrao) ? compara_parametro(source, parametro_por_letra(*padrao), padrao[1]=='\0') : compara_terminal(source, *padrao); //Se o caractere em pattern for uma letra mai�scula, chama matchParam para verificar se h� um par�metro correspondente; caso contr�rio, chama matchTerminal para comparar diretamente.
    }
    return source != NULL && *pula_espacos(source) == '\0'; //No final, verifica se n�o restaram caracteres n�o processados em src, retornando true se todos os espa�os foram tratados corretamente e se o comando foi reconhecido.
}
