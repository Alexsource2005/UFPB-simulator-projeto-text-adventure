#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "locais.h"
#include "inventory.h"


bool comparaeExecuta(char *comando) {
    if (comando == NULL || strlen(comando) == 0) {
        printf("Comando vazio.\n");
        return true; // Continue o loop
    }

    setlocale(LC_ALL, " "); // Mantenha isso no início da função ou no main

    char *verbo = strtok(comando, " \n"); // Obtém o verbo
    char *substantivo = strtok(NULL, "\n"); // Obtém o substantivo

    if (verbo != NULL) {
        if (strcasecmp(verbo, "sair") == 0) {
            return false; // Sair do jogo

        } else if (strcasecmp(verbo, "olhar") == 0) {
            exec_olhar(substantivo);

        } else if (strcasecmp(verbo, "ir") == 0) {
            if (substantivo != NULL) {
                exec_ir(substantivo);
            } else {
                printf("Para onde você quer ir?\n");
            }


        } else if (strcasecmp(verbo, "pegar") == 0) {
            if (substantivo != NULL) {
                exec_pegar(substantivo);
            } else {
                printf("O que você quer pegar?\n");
            }


        } else if (strcasecmp(verbo, "jogar") == 0) {
            if (substantivo != NULL) {
                exec_jogar(substantivo);
            } else {
                printf("O que você quer jogar?\n");
            }


        } else if (strcasecmp(verbo, "dar") == 0) {
            if (substantivo != NULL) {
                exec_dar(substantivo);
            } else {
                printf("O que você quer dar?\n");
            }


        } else if (strcasecmp(verbo, "pedir") == 0) {
            if (substantivo != NULL) {
                exec_pedir(substantivo);
            } else {
                printf("O que você quer pedir?\n");
            }


        } else if (strcasecmp(verbo, "checar") == 0) {
            if (substantivo != NULL) {
                exec_checar(substantivo);
            } else {
                printf("O que você quer checar?\n");
            }


        } else {
            printf("Eu não sei '%s'.\n", verbo);
        }
    }

    return true; // Continua o loop do jogo
}
