#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "locais.h"

bool comparaeExecuta(char *comando)
{
    setlocale(LC_ALL, " ");
    // separar o verbo do substantivo do comando. Exemplo: "ir norte"
   char *verbo = strtok(comando, " \n"); // "ir"

if (verbo != NULL)
    {
        if (strcasecmp(verbo, "sair") == 0) // strcasecmp para lidar com maiusculas-minusculas
        {
            return false;
        }
        else if (strcasecmp(verbo, "olhar") == 0)
        {
            exec_olhar(strtok(NULL, "\n")); // Captura tudo após "olhar"
        }
        else if (strcasecmp(verbo, "ir") == 0)
        {
            char *substantivo = strtok(NULL, "\n"); // Captura o restante da linha
            if (substantivo != NULL)
            {
                exec_ir(substantivo); // Executa o comando com o substantivo completo
            }
            else
            {
                printf("Para onde você quer ir?\n");
            }
        }
        else
        {
            printf("Eu não sei '%s'.\n", verbo);
        }
    }
    return true;
}
