#include <stdbool.h>
#include <stdio.h>
#include "objetos.h"
#include "comparar.h"
#include "movimento.h"
#include "alcance.h"
#include "substantivo.h"

bool exec_darPARA(void)
{
    tObjetos *obj = pega_possesao(player, "dar", parametros[0]);

    if(obj != NULL)
    {
        tObjetos *destino = objeto_no_alcance("para quem dar isto", parametros[1]);
        if(destino != NULL)
        {
            if(destino->vida > 0)
            {
                mover_objeto(obj, destino);
            }
            else
            {
                printf("Você não pode dar um item para um objeto inanimado.\n");
            }
        }

    }
    return true;

}

bool exec_pegarDE(void)
{
    tObjetos *origem = objeto_no_alcance("de onde você quer pegar isso", parametros[1]);

    if(origem != NULL && visivel_existe("oque você quer pegar", parametros[0]) != NULL)
    {
        if(origem->vida > 0)
        {
            printf("Você deveria pedir ao %s antes de pegar algo que não lhe pertence.\n", origem->descricao);

        }
        else
        {
            mover_objeto(pega_possesao(origem, "pegar", parametros[0]), player);
        }
    }
    return true;
}

bool exec_jogarNO(void)
{
    tObjetos *obj = pega_possesao(player, "jogar", parametros[0]);

    if(obj != NULL)
    {
        tObjetos *destino = objeto_no_alcance("onde você quer jogar isso", parametros[1]);
        if(destino != NULL)
        {
            if(destino->vida > 0)
            {
                printf("Você não pode agredir uma pessoa inocente. é crime.\n");

            }
            else
            {
                mover_objeto(obj, destino);
            }

        }
    }
    return true;
}

bool exec_pedirPARA(void)
{
    tObjetos *pessoa_origem = objeto_no_alcance("para quem pedir por isso.", parametros[1]);
    if(pessoa_origem != NULL)
    {
        if(pessoa_origem->vida > 0)
        {
            if(visivel_existe("oque você quer pedir para esta pessoa.", parametros[0]) != NULL)
            {
                mover_objeto(pega_possesao(pessoa_origem, "pedir", parametros[0]), player);
            }
        }
        else
        {
            printf("Objetos inanimados não falam. Você tomou seus remédios hoje.\n");
        }
    }
    return true;
}

bool exec_colocarEM(void)
{
        tObjetos *obj = pega_possesao(player, "colocar", parametros[0]);
        if(obj != NULL)
        {
            tObjetos *destino = objeto_no_alcance("onde voce quer colocar isso.", parametros[1]);
            if(destino != NULL)
            {
                if(destino->vida > 0)
                {
                    printf("Você deveria oferecer isso para %s educadamente.", destino->descricao);
                }
                else
                {
                    mover_objeto(obj, destino);
                }
            }

        }
}

bool exec_programar_arduino(void) {
    tObjetos *arduino_obj = visivel_existe("O que você quer programar", "arduino");
    tObjetos *notebook_obj = visivel_existe("Com o que você quer programar", "notebook");

    if (arduino_obj == NULL || notebook_obj == NULL) {
        printf("Você não tem o arduino ou o notebook para programar.\n");
        return true;
    }

    if (arduino_obj->local != player || player->local != CI) {
        printf("Você precisa ter o arduino e o notebook em mãos para programar.\n");
        return true;
    }

    printf("Você começa a programar o arduino com o notebook...\n");
    printf("Depois de alguns minutos, você termina de programar o arduino.\n");
    printf("Você recebe um arduino pronto para ser usado.\n");

    // Remover o arduino antigo
    arduino_obj->local = NULL;

    // Adicionar o arduino pronto ao jogador
    arduino_pronto->local = player;

    return true;
}

bool exec_construir_chassi(void) {
    tObjetos *cano_obj = visivel_existe("O que você quer usar para construir", "cano");

    if (cano_obj == NULL || cano_obj->local != player) {
        printf("Você precisa ter o cano em mãos para construir o chassi.\n");
        return true;
    }

    printf("Você usa o cano para construir um chassi robusto...\n");
    printf("Após algum tempo de trabalho, você termina de construir o chassi!\n");

    // Remover o cano
    cano_obj->local = NULL;

    // Adicionar o chassi ao jogador
    chassi->local = player;

    return true;
}

bool exec_construir_carro_combate(void) {
    tObjetos *chassi_obj = visivel_existe("O que você quer usar para construir", "chassi");
    tObjetos *arduino_pronto_obj = visivel_existe("O que mais você quer usar", "arduino pronto");

    if (chassi_obj == NULL || chassi_obj->local != player ||
        arduino_pronto_obj == NULL || arduino_pronto_obj->local != player) {
        printf("Você precisa ter o chassi e o arduino pronto em mãos para construir o carro de combate.\n");
        return true;
    }

    printf("Você combina o chassi com o arduino pronto...\n");
    printf("Após um trabalho meticuloso, você finaliza a construção do carro de combate!\n");

    // Remover o chassi e o arduino pronto
    chassi_obj->local = NULL;
    arduino_pronto_obj->local = NULL;

    // Adicionar o carro de combate ao jogador
    carro_de_combate->local = player;

    // Condição de vitória
    printf("Parabéns! Você construiu o carro de combate e venceu o jogo!\n");
    return false;  // Retorna false para encerrar o jogo
}
