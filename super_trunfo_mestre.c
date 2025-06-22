#include <stdio.h>
#include <string.h>

// Estrutura da carta
struct Carta {
    char estado[3];
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;  // em bilhões
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para calcular densidade e PIB per capita
void calcularAtributos(struct Carta *c) {
    c->densidadePopulacional = (float)c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1000000000.0f) / c->populacao;
}

// Função para imprimir o menu de atributos, pulando o atributo ja escolhido na primeira opcao
void imprimirMenu(int ignorar) {
    // ignorar é o indice do atributo que não deve aparecer
    // Atributos indexados de 1 a 6 para o usuário
    if (ignorar != 1) printf("1 - Populacao\n");
    if (ignorar != 2) printf("2 - Area\n");
    if (ignorar != 3) printf("3 - PIB\n");
    if (ignorar != 4) printf("4 - Numero de Pontos Turisticos\n");
    if (ignorar != 5) printf("5 - Densidade Demografica\n");
    if (ignorar != 6) printf("6 - PIB per Capita\n");
}

// Função para obter o nome do atributo
const char* nomeDoAtributo(int op) {
    switch (op) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Numero de Pontos Turisticos";
        case 5: return "Densidade Demografica";
        case 6: return "PIB per Capita";
        default: return "Atributo desconhecido";
    }
}

// Função para pegar o valor do atributo da carta, para comparação e soma
float valorAtributo(struct Carta c, int op) {
    switch (op) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidadePopulacional;
        case 6: return c.pibPerCapita;
        default: return 0.0f;
    }
}

// Função para decidir quem vence no atributo
// retorna 0 = empate, 1 = carta1 vence, 2 = carta2 vence
// regra: maior vence, exceto densidade (5) menor vence
int compararAtributo(struct Carta c1, struct Carta c2, int op) {
    float v1 = valorAtributo(c1, op);
    float v2 = valorAtributo(c2, op);

    if (op == 5) { // densidade demográfica menor vence
        if (v1 < v2) return 1;
        else if (v2 < v1) return 2;
        else return 0;
    } else {
        if (v1 > v2) return 1;
        else if (v2 > v1) return 2;
        else return 0;
    }
}

int main() {
    struct Carta carta1 = {"SP", "A01", "Sao Paulo", 12325000, 1521.11f, 699.28f, 50, 0, 0};
    struct Carta carta2 = {"RJ", "B02", "Rio de Janeiro", 6748000, 1200.25f, 300.50f, 30, 0, 0};

    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    int op1 = 0, op2 = 0;

    // Menu escolha 1
    printf("Escolha o primeiro atributo para comparar:\n");
    imprimirMenu(0);
    printf("Opcao: ");
    scanf("%d", &op1);

    // Validar escolha 1
    if (op1 < 1 || op1 > 6) {
        printf("Opcao invalida!\n");
        return 1;
    }

    // Menu escolha 2
    printf("\nEscolha o segundo atributo para comparar (diferente do primeiro):\n");
    imprimirMenu(op1);
    printf("Opcao: ");
    scanf("%d", &op2);

    // Validar escolha 2
    if (op2 < 1 || op2 > 6 || op2 == op1) {
        printf("Opcao invalida ou igual ao primeiro atributo!\n");
        return 1;
    }

    // Comparar atributos individualmente
    int vencedor1 = compararAtributo(carta1, carta2, op1);
    int vencedor2 = compararAtributo(carta1, carta2, op2);

    // Valores dos atributos
    float val1_op1 = valorAtributo(carta1, op1);
    float val2_op1 = valorAtributo(carta2, op1);
    float val1_op2 = valorAtributo(carta1, op2);
    float val2_op2 = valorAtributo(carta2, op2);

    // Somar os valores para determinar o vencedor final
    float soma1 = val1_op1 + val1_op2;
    float soma2 = val2_op1 + val2_op2;

    int vencedorFinal;
    if (soma1 > soma2) vencedorFinal = 1;
    else if (soma2 > soma1) vencedorFinal = 2;
    else vencedorFinal = 0; // empate

    // Exibir resultado claro
    printf("\nComparacao de cartas com dois atributos:\n\n");
    printf("Carta 1 - %s (%s)\n", carta1.nomeCidade, carta1.estado);
    printf("  %s: %.2f\n", nomeDoAtributo(op1), val1_op1);
    printf("  %s: %.2f\n", nomeDoAtributo(op2), val1_op2);
    printf("  Soma: %.2f\n\n", soma1);

    printf("Carta 2 - %s (%s)\n", carta2.nomeCidade, carta2.estado);
    printf("  %s: %.2f\n", nomeDoAtributo(op1), val2_op1);
    printf("  %s: %.2f\n", nomeDoAtributo(op2), val2_op2);
    printf("  Soma: %.2f\n\n", soma2);

    if (vencedorFinal == 1) {
        printf("Resultado final: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (vencedorFinal == 2) {
        printf("Resultado final: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado final: Empate!\n");
    }

    return 0;
}
