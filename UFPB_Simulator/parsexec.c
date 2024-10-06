#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "locais.h"
#include "inventory.h"

char *apenas_um_substantivo(char *substantivo, char *ultima_palavra){
    char *token = strtok(substantivo, " "); // Divide o restante em palavras

    while (token != NULL) {
        ultima_palavra = token; // Armazena o último token
        token = strtok(NULL, " "); // Continua pegando os tokens
    }

    return ultima_palavra;
}

bool comparaeExecuta(char *comando) {
    if (comando == NULL || strlen(comando) == 0) {
        printf("Comando vazio.\n");
        return true; // Continue o loop
    }

    setlocale(LC_ALL, " "); // Mantenha isso no início da função ou no main

    char *verbo = strtok(comando, " \n"); // Obtém o verbo
    char *substantivo = strtok(NULL, "\n"); // Obtém o substantivo

    char *ultima_palavra = NULL;


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
           ultima_palavra = apenas_um_substantivo(substantivo, ultima_palavra);

            if (ultima_palavra != NULL) {
                exec_pegar(ultima_palavra);
            } else {
                printf("O que você quer pegar?\n");
            }


        } else if (strcasecmp(verbo, "jogar") == 0) {
            ultima_palavra = apenas_um_substantivo(substantivo, ultima_palavra);
            if (ultima_palavra != NULL) {
                exec_jogar(ultima_palavra);
            } else {
                printf("O que você quer jogar?\n");
            }


        } else if (strcasecmp(verbo, "dar") == 0) {
            ultima_palavra = apenas_um_substantivo(substantivo, ultima_palavra);
            if (ultima_palavra != NULL) {
                exec_dar(ultima_palavra);
            } else {
                printf("O que você quer dar?\n");
            }


        } else if (strcasecmp(verbo, "pedir") == 0) {
            ultima_palavra = apenas_um_substantivo(substantivo, ultima_palavra);
            if (ultima_palavra != NULL) {
                exec_pedir(ultima_palavra);
            } else {
                printf("O que você quer pedir?\n");
            }


        } else if (strcasecmp(verbo, "checar") == 0) {
            ultima_palavra = apenas_um_substantivo(substantivo, ultima_palavra);
            if (ultima_palavra != NULL) {
                exec_checar(ultima_palavra);
            } else {
                printf("O que você quer checar?\n");
            }


        } else {
            printf("Eu não sei '%s'.\n", verbo);
        }
    }

    return true; // Continua o loop do jogo
}
