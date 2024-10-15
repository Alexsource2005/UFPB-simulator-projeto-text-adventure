#include <stdio.h>
#include <stdbool.h>
#include "objetos.h"
#include "tutorial.h"

bool exec_tutorial(void) {
    printf("\n=== TUTORIAL ===\n");
    printf("Bem-vindo ao simulador da UFPB! Aqui est� um guia r�pido para jogar:\n\n");

    printf("OBJETIVO DO JOGO:\n");
    printf("Seu objetivo � construir um carro de combate. Para isso, voc� precisa:\n");
    printf("1. Encontrar um cano PVC\n");
    printf("2. Construir um chassi usando o cano\n");
    printf("3. Encontrar um arduino\n");
    printf("4. Programar o arduino usando um notebook\n");
    printf("5. Combinar o chassi e o arduino programado para criar o carro de combate\n\n");

    printf("COMANDOS DISPON�VEIS:\n");
    printf("- olhar: Examinar o ambiente ao seu redor\n");
    printf("- olhar [objeto]: Examinar um objeto espec�fico\n");
    printf("- ir para [lugar]: Mover-se para um novo local\n");
    printf("- pegar [objeto]: Pegar um objeto\n");
    printf("- inventario: Ver os itens que voc� est� carregando\n");
    printf("- construir chassi: Construir um chassi usando o cano PVC\n");
    printf("- construir carro de combate: Construir o carro de combate final\n");
    printf("- tuto: Exibir este tutorial novamente\n");
    printf("- sair: Encerrar o jogo\n\n");

    printf("Boa sorte e divirta-se explorando o campus!\n");
    printf("================\n");

    return true;
}
