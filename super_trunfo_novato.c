#include <stdio.h>

// Definindo um tipo enumerado para o atributo que sera comparado
typedef enum {
    POPULACAO,
    AREA,
    PIB,
    DENSIDADE_POPULACIONAL,
    PIB_PER_CAPITA
} AtributoComparacao;

// Estrutura da carta
struct Carta {
    char estado[3];           // Ex: "SP"
    char codigo[4];           // Ex: "A01"
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;                // em bilhoes
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

int main() {
    // Escolha do atributo a comparar
    // Para testar, altere aqui: POPULACAO, AREA, PIB, DENSIDADE_POPULACIONAL ou PIB_PER_CAPITA
    AtributoComparacao atributoEscolhido = POPULACAO;

    struct Carta carta1, carta2;

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Estado (ex: SP): ");
    scanf("%2s", carta1.estado);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%3s", carta1.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);

    printf("Populacao: ");
    scanf("%d", &carta1.populacao);

    printf("Area (km2): ");
    scanf("%f", &carta1.area);

    printf("PIB (bilhoes): ");
    scanf("%f", &carta1.pib);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    //Cadastro da Carta 2 
    printf("\nCadastro da Carta 2:\n");
    printf("Estado (ex: RJ): ");
    scanf("%2s", carta2.estado);

    printf("Codigo da Carta (ex: B02): ");
    scanf("%3s", carta2.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);

    printf("Populacao: ");
    scanf("%d", &carta2.populacao);

    printf("Area (km2): ");
    scanf("%f", &carta2.area);

    printf("PIB (bilhoes): ");
    scanf("%f", &carta2.pib);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    //Calcula densidade e PIB per capita
    carta1.densidadePopulacional = (float)carta1.populacao / carta1.area;
    carta1.pibPerCapita        = (carta1.pib * 1000000000.0f) / carta1.populacao;

    carta2.densidadePopulacional = (float)carta2.populacao / carta2.area;
    carta2.pibPerCapita        = (carta2.pib * 1000000000.0f) / carta2.populacao;

    // Preparar valores para comparacao
    float valor1 = 0.0f, valor2 = 0.0f;
    int carta1Vence = 0;

    // Seleciona o atributo e faz a comparacao
    if (atributoEscolhido == POPULACAO) {
        valor1 = (float)carta1.populacao;
        valor2 = (float)carta2.populacao;
        printf("\nComparacao de cartas (Atributo: Populacao):\n");
        carta1Vence = (valor1 > valor2);
    }
    else if (atributoEscolhido == AREA) {
        valor1 = carta1.area;
        valor2 = carta2.area;
        printf("\nComparacao de cartas (Atributo: Area):\n");
        carta1Vence = (valor1 > valor2);
    }
    else if (atributoEscolhido == PIB) {
        valor1 = carta1.pib;
        valor2 = carta2.pib;
        printf("\nComparacao de cartas (Atributo: PIB):\n");
        carta1Vence = (valor1 > valor2);
    }
    else if (atributoEscolhido == DENSIDADE_POPULACIONAL) {
        valor1 = carta1.densidadePopulacional;
        valor2 = carta2.densidadePopulacional;
        printf("\nComparacao de cartas (Atributo: Densidade Populacional):\n");
        // para densidade, menor vence
        carta1Vence = (valor1 < valor2);
    }
    else if (atributoEscolhido == PIB_PER_CAPITA) {
        valor1 = carta1.pibPerCapita;
        valor2 = carta2.pibPerCapita;
        printf("\nComparacao de cartas (Atributo: PIB per Capita):\n");
        carta1Vence = (valor1 > valor2);
    }
    else {
        printf("Atributo invalido!\n");
        return 1;
    }

    //Exibe resultados
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, valor2);

    if (carta1Vence)
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    else
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);

    return 0;
}
