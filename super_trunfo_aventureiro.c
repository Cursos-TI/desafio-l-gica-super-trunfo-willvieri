#include <stdio.h>

// Estrutura para representar uma carta
struct Carta {
    char estado[3];
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;  // bilhões
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para calcular densidade e pib per capita
void calcularAtributos(struct Carta *c) {
    c->densidadePopulacional = (float)c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1000000000.0f) / c->populacao;
}

int main() {
    // Cartas já cadastradas (pode modificar ou deixar hardcoded)
    struct Carta carta1 = {
        "SP", "A01", "Sao Paulo", 12325000, 1521.11f, 699.28f, 50, 0, 0
    };
    struct Carta carta2 = {
        "RJ", "B02", "Rio de Janeiro", 6748000, 1200.25f, 300.50f, 30, 0, 0
    };

    // Calcula atributos derivados
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    int opcao;

    // Menu interativo
    printf("Escolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("6 - PIB per Capita\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    float val1 = 0.0f, val2 = 0.0f;
    char nomeAtributo[30];
    int vencedor = 0; // 0 = empate, 1 = carta1 vence, 2 = carta2 vence

    switch (opcao) {
        case 1:
            val1 = (float)carta1.populacao;
            val2 = (float)carta2.populacao;
            snprintf(nomeAtributo, sizeof(nomeAtributo), "Populacao");
            if (val1 > val2) vencedor = 1;
            else if (val2 > val1) vencedor = 2;
            break;
        case 2:
            val1 = carta1.area;
            val2 = carta2.area;
            snprintf(nomeAtributo, sizeof(nomeAtributo), "Area");
            if (val1 > val2) vencedor = 1;
            else if (val2 > val1) vencedor = 2;
            break;
        case 3:
            val1 = carta1.pib;
            val2 = carta2.pib;
            snprintf(nomeAtributo, sizeof(nomeAtributo), "PIB");
            if (val1 > val2) vencedor = 1;
            else if (val2 > val1) vencedor = 2;
            break;
        case 4:
            val1 = (float)carta1.pontosTuristicos;
            val2 = (float)carta2.pontosTuristicos;
            snprintf(nomeAtributo, sizeof(nomeAtributo), "Numero de Pontos Turisticos");
            if (val1 > val2) vencedor = 1;
            else if (val2 > val1) vencedor = 2;
            break;
        case 5:
            val1 = carta1.densidadePopulacional;
            val2 = carta2.densidadePopulacional;
            snprintf(nomeAtributo, sizeof(nomeAtributo), "Densidade Demografica");
            // menor vence para densidade
            if (val1 < val2) vencedor = 1;
            else if (val2 < val1) vencedor = 2;
            break;
        case 6:
            val1 = carta1.pibPerCapita;
            val2 = carta2.pibPerCapita;
            snprintf(nomeAtributo, sizeof(nomeAtributo), "PIB per Capita");
            if (val1 > val2) vencedor = 1;
            else if (val2 > val1) vencedor = 2;
            break;
        default:
            printf("Opcao invalida!\n");
            return 1;
    }

    // Exibir resultado
    printf("\nComparacao de cartas (Atributo: %s):\n", nomeAtributo);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, val1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, val2);

    if (vencedor == 0) {
        printf("Resultado: Empate!\n");
    } else if (vencedor == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    }

    return 0;
}
