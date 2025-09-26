#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===============================
// Estrutura que representa uma carta do jogo Super Trunfo
// ===============================
struct CartaSuperTrunfo {
    char estado;                // Letra de 'A' até 'H' representando o estado
    char codigo[4];             // Código da carta (Ex: A01, B03...)
    char nomeCidade[50];        // Nome da cidade
    int populacao;              // População da cidade
    float area;                 // Área da cidade em km²
    float pib;                  // PIB da cidade em bilhões
    unsigned int pontosTuristicos; // Número de pontos turísticos

    // Atributos derivados (calculados automaticamente)
    float densidadePopulacao;   
    float pibPerCapita;         
    float superPoder;           
};

// ===============================
// Variáveis globais - teremos apenas duas cartas
// ===============================
struct CartaSuperTrunfo carta1, carta2;

// ===============================
// Função utilitária: limpa buffer do teclado
// ===============================
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// ===============================
// Função para calcular atributos derivados de uma carta
// ===============================
void calcularAtributos(struct CartaSuperTrunfo *carta) {
    carta->densidadePopulacao = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1e9) / carta->populacao; // PIB convertido para reais
    carta->superPoder = carta->populacao + carta->area + carta->pib +
                        carta->pontosTuristicos + carta->pibPerCapita;
}

// ===============================
// Função para preencher uma carta com dados do usuário
// ===============================
void preencherCarta(struct CartaSuperTrunfo *carta, const char *nomeCarta) {
    printf("\n===== Preenchendo %s =====\n", nomeCarta);

    // Estado (A até H)
    printf("Escolha uma letra entre 'A' e 'H' para representar o estado: ");
    scanf(" %c", &carta->estado);
    limparBuffer();

    // Código da carta
    int numeroCodigo;
    printf("Escolha um número de 1 a 4 para o código da carta: ");
    scanf("%d", &numeroCodigo);
    limparBuffer();

    sprintf(carta->codigo, "%c%02d", carta->estado, numeroCodigo);

    // Nome da cidade
    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);
    limparBuffer();

    // População
    printf("Digite a População: ");
    scanf("%d", &carta->populacao);

    // Área
    printf("Digite a Área da Cidade (em km²): ");
    scanf("%f", &carta->area);

    // PIB
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    // Pontos turísticos
    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%u", &carta->pontosTuristicos);

    // Calculando atributos derivados
    calcularAtributos(carta);

    printf("\n✅ %s registrada com sucesso!\n", nomeCarta);
}

// ===============================
// Função para exibir os detalhes de uma carta
// ===============================
void exibirCarta(const struct CartaSuperTrunfo *carta) {
    printf("\n--- Detalhes da Carta %s ---\n", carta->codigo);
    printf("Cidade: %s\n", carta->nomeCidade);
    printf("População: %d habitantes\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões\n", carta->pib);
    printf("Pontos turísticos: %u\n", carta->pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidadePopulacao);
    printf("PIB per Capita: %.2f reais\n", carta->pibPerCapita);
    printf("Superpoder: %.2f\n", carta->superPoder);
}

// ===============================
// Função para comparar dois atributos escolhidos
// ===============================
void compararCartas(int atributo) {
    float valor1, valor2;
    const char *nomeAtributo;

    // Seleciona o atributo baseado na escolha
    switch (atributo) {
        case 1: valor1 = carta1.populacao; valor2 = carta2.populacao; nomeAtributo = "População"; break;
        case 2: valor1 = carta1.area; valor2 = carta2.area; nomeAtributo = "Área"; break;
        case 3: valor1 = carta1.pib; valor2 = carta2.pib; nomeAtributo = "PIB"; break;
        case 4: valor1 = carta1.pontosTuristicos; valor2 = carta2.pontosTuristicos; nomeAtributo = "Pontos Turísticos"; break;
        case 5: valor1 = carta1.densidadePopulacao; valor2 = carta2.densidadePopulacao; nomeAtributo = "Densidade Populacional"; break;
        case 6: valor1 = carta1.pibPerCapita; valor2 = carta2.pibPerCapita; nomeAtributo = "PIB per Capita"; break;
        case 7: valor1 = carta1.superPoder; valor2 = carta2.superPoder; nomeAtributo = "Superpoder"; break;
        default: printf("⚠️ Opção inválida!\n"); return;
    }

    // Exibe resultado da comparação
    printf("\n🔎 Comparação de %s:\n", nomeAtributo);
    printf("Carta 1 (%s - %s): %.2f\n", carta1.codigo, carta1.nomeCidade, valor1);
    printf("Carta 2 (%s - %s): %.2f\n", carta2.codigo, carta2.nomeCidade, valor2);

    if (valor1 > valor2) {
        printf("🏆 Carta 1 (%s) venceu na disputa de %s!\n", carta1.nomeCidade, nomeAtributo);
    } else if (valor2 > valor1) {
        printf("🏆 Carta 2 (%s) venceu na disputa de %s!\n", carta2.nomeCidade, nomeAtributo);
    } else {
        printf("🤝 Empate! Ambas as cartas têm o mesmo valor de %s.\n", nomeAtributo);
    }
}

// ===============================
// Função principal
// ===============================
int main(void) {
    printf("****  Bem-vindo ao Super Trunfo - Cidades!  ****\n");
    printf("** Nesta versão, jogaremos com duas cartas. **\n");
    printf("** Escolha um atributo para comparar e veja quem vence! **\n\n");

    // Preenchendo as cartas
    preencherCarta(&carta1, "Carta 1");
    preencherCarta(&carta2, "Carta 2");

    // Exibindo as cartas cadastradas
    exibirCarta(&carta1);
    exibirCarta(&carta2);

    // Menu interativo
    int escolha;
    do {
        printf("\n===== MENU =====\n");
        printf("1 - Comparar População\n");
        printf("2 - Comparar Área\n");
        printf("3 - Comparar PIB\n");
        printf("4 - Comparar Pontos Turísticos\n");
        printf("5 - Comparar Densidade Populacional\n");
        printf("6 - Comparar PIB per Capita\n");
        printf("7 - Comparar Superpoder\n");
        printf("8 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        if (escolha >= 1 && escolha <= 7) {
            compararCartas(escolha);
        }
    } while (escolha != 8);

    printf("\n🎮 Obrigado por jogar! Até a próxima.\n");
    return 0;
}
