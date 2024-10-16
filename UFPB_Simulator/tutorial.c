#include <stdio.h>
#include <stdbool.h>
#include "objetos.h"
#include "tutorial.h"

bool exec_tutorial(void) {
    printf("\n=== TUTORIAL ===\n");
    printf("Bem-vindo ao simulador da UFPB! Aqui está um guia rápido para jogar:\n\n");

    printf("OBJETIVO DO JOGO:\n");
    printf("Seu objetivo é construir um carro de combate. Para isso, você precisa:\n");
    printf("1. Encontrar um cano PVC\n");
    printf("2. Construir um chassi usando o cano\n");
    printf("3. Encontrar um arduino\n");
    printf("4. Programar o arduino usando um notebook\n");
    printf("5. Combinar o chassi e o arduino programado para criar o carro de combate\n\n");

    printf("MECÂNICAS DE SOBREVIVÊNCIA:\n");
    printf("- Fome: Você precisa comer regularmente para não morrer de fome.\n");
    printf("- Energia: Mover-se e realizar ações gasta energia. Descanse quando necessário.\n");
    printf("- Sanidade: Suas experiências afetam sua sanidade. Cuide de sua saúde mental.\n");
    printf("- Necessidades fisiológicas: Use o banheiro quando necessário.\n\n");

    printf("COMANDOS DISPONÍVEIS:\n");
    printf("- olhar: Examinar o ambiente ao seu redor\n");
    printf("- olhar [objeto]: Examinar um objeto específico\n");
    printf("- ir para [lugar]: Mover-se para um novo local\n");
    printf("- pegar [objeto]: Pegar um objeto\n");
    printf("- inventario: Ver os itens que você está carregando\n");
    printf("- construir chassi: Construir um chassi usando o cano PVC\n");
    printf("- construir carro de combate: Construir o carro de combate final\n");
    printf("- comer: Satisfazer sua fome\n");
    printf("- dormir: Recuperar energia\n");
    printf("- aliviar: Usar o banheiro (apenas quando estiver em um)\n");
    printf("- tuto: Exibir este tutorial novamente\n");
    printf("- sair: Encerrar o jogo\n\n");

    printf("DICAS:\n");
    printf("- Gerencie bem seus recursos (fome, energia, sanidade).\n");
    printf("- Explore o campus para encontrar os itens necessários.\n");
    printf("- Use o banheiro regularmente para evitar acidentes.\n");
    printf("- Se estiver muito cansado para se mover, considere tirar um cochilo.\n");
    printf("- Preste atenção às mensagens do jogo para dicas e informações importantes.\n\n");

    printf("Boa sorte e divirta-se explorando o campus!\n");
    printf("================\n");

    return true;
}
