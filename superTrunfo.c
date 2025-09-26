#include <stdio.h>

//Estrutura para criação das cartas~
struct CartaSuperTrunfo {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    unsigned int pontosTuristicos;
    float densidadePopulacao, pibPerCapita, superPoder;
};

struct CartaSuperTrunfo carta1, carta2;  // Definição da quantidade de cartas

// Função para preencher as cartas evitando repetições
void preencherCarta(struct CartaSuperTrunfo *carta, const char *nomeCarta) {
    printf("\n===== Preenchendo %s =====\n", nomeCarta);

    char entrada[10];
    printf("Escolha uma letra entre 'A' e 'H' para representar um dos estados: ");
    scanf(" %c", entrada);
    carta->estado = entrada[0];
    while ((getchar()) != '\n');

    printf("Escolha um número de 1 a 4 para o código da carta: ");
    int numeroCodigo;
    scanf(" %d", &numeroCodigo);
    sprintf(carta->codigo, "%c%02d", carta->estado, numeroCodigo);

    while ((getchar()) != '\n' && getchar() != EOF);  // Limpa o buffer completamente antes de ler a próxima string
    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("Digite a População: ");
    scanf("%d", &carta->populacao);

    printf("Digite a Área da Cidade (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite a Quantidade de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    carta->densidadePopulacao = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1e9) / carta->populacao;
    carta->superPoder = carta->populacao + carta->area + carta->pib + carta->pontosTuristicos + carta->pibPerCapita;

    printf(" %s registrada com sucesso!\n", nomeCarta);
}

void compararCartas(int atributo) {
    
    printf("\n Comparação de cartas: \n\n");
    float valor1, valor2;
    const char *nomeAtributo;

    switch (atributo) {
        case 1: valor1 = carta1.populacao; valor2 = carta2.populacao; nomeAtributo = "População"; break;
        case 2: valor1 = carta1.area; valor2 = carta2.area; nomeAtributo = "Área"; break;
        case 3: valor1 = carta1.pib; valor2 = carta2.pib; nomeAtributo = "PIB"; break;
        case 4: valor1 = carta1.pontosTuristicos; valor2 = carta2.pontosTuristicos; nomeAtributo = "Pontos Turísticos"; break;
        case 5: valor1 = carta1.densidadePopulacao; valor2 = carta2.densidadePopulacao; nomeAtributo = "Densidade Populacional"; break;
        case 6: valor1 = carta1.pibPerCapita; valor2 = carta2.pibPerCapita; nomeAtributo = "PIB per Capita"; break;
        case 7: valor1 = carta1.superPoder; valor2 = carta2.superPoder; nomeAtributo = "Superpoder"; break;
        default: printf(" Opção inválida\n"); return;
    }
    
    if (valor1 > valor2) {
        printf(" A carta 1 - %s venceu na disputa de %s!\n", carta1.nomeCidade, nomeAtributo);
    } else if (valor2 > valor1) {
        printf(" A carta 2 - %s venceu na disputa de %s!\n", carta2.nomeCidade, nomeAtributo);
    } else {
        printf(" Empate! Ambas as cidades têm o mesmo valor de %s.\n", nomeAtributo);
    }
}

int main(void) {
    // Mensagem de boas-vindas
    printf("****  Bem-vindo ao Super Trunfo - Cidades!  ****\n");
    printf("** Nesta versão, jogaremos com duas cartas. **\n");
    printf("** Escolha um atributo para comparar e veja quem vence! **\n\n");

    // Preenchendo as cartas
    preencherCarta(&carta1, "Carta 1");
    preencherCarta(&carta2, "Carta 2");

    // Menu interativo
    int escolha;
    do {
        printf("\n Escolha um atributo para comparar:\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\n7 - Superpoder\n8 - Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &escolha);

        if (escolha != 8) {
            compararCartas(escolha);
        }
    } while (escolha != 8);

    printf(" Obrigado por jogar! Até a próxima.\n");

    return 0;
}