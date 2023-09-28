#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct
{
    int dificuldade;
    int valor1;
    int valor2;
    int operacao;
    int resultado;
} Calcular;

void jogar();
void mostrarInfo(Calcular calc);
int somar(int resposta, Calcular calc);
int diminuir(int resposta, Calcular calc);
int multiplicar(int resposta, Calcular calc);

int pontos = 0;

int main()
{
    //Gerar numero alatorio.
    srand(time(NULL));
    jogar();
    return (0);
}

void jogar()
{
    Calcular calc;
    int dificuldade;
    int resposta;
    int continuar;

    printf("Insira o nivel de dificuldade desejado [1, 2, 3 ou 4]:\n");
    scanf("%d", &dificuldade);

    calc.dificuldade = dificuldade;

    // gerar numero aleatorio entre 0 e 2
    // 0 == somar, 1 == diminuir, 2 == multiplicar.
    calc.operacao = rand() % 3;

    if (calc.dificuldade == 1)
    {
        calc.valor1 = rand() % 11;
        calc.valor2 = rand() % 11;
    }
    else if (calc.dificuldade == 2)
    {
        calc.valor1 = rand() % 101;
        calc.valor2 = rand() % 101;
    }
    else if (calc.dificuldade == 3)
    {
        calc.valor1 = rand() % 1001;
        calc.valor2 = rand() % 1001;
    }
    else if (calc.dificuldade == 4)
    {
        calc.valor1 = rand() % 10001;
        calc.valor2 = rand() % 10001;
    }
    else
    {
        calc.valor1 = rand() % 100001;
        calc.valor2 = rand() % 100001;
    }
    printf("Informe o resultado da seguinte operacao:\n");

    if (calc.operacao == 0)
    {
        printf("%d + %d\n", calc.valor1, calc.valor2);
        printf("Resposta: ");
        scanf("%d", &resposta);

        if (somar(resposta, calc))
        {
            pontos += 1;
            printf("Voce tem %d pontos!\n", pontos);
        }
    }
    else if (calc.operacao == 1)
    {
        printf("%d - %d\n", calc.valor1, calc.valor2);
        printf("Resposta: ");
        scanf("%d", &resposta);

        if (diminuir(resposta, calc))
        {
            pontos += 1;
            printf("Voce tem %d pontos!\n", pontos);
        }

    }
    else if (calc.operacao == 2)
    {
        printf("%d * %d\n", calc.valor1, calc.valor2);
        printf("Resposta: ");
        scanf("%d", &resposta);

        if (multiplicar(resposta, calc))
        {
            pontos += 1;
            printf("Voce tem %d pontos!\n", pontos);
        }
    }
    // recomeçar o jogo ?
    printf("Deseja continuar ? [1 = Sim , 0= Nao]");
    scanf("%d", &continuar);

    if (continuar == 1)
    {
        jogar();
    }
    else
    {
        printf("Voce finalizou com %d pontos.\n", pontos);
        printf("Ate a proxima!");
        exit(0);
    }
}

void mostrarInfo(Calcular calc)
{
    char op[25];

    if(calc.operacao == 0) // opção = soma.
    {
        sprintf(op, "Somar"); // trasferir valor para a variavel.
    }
    else if(calc.operacao == 1)
    {
        sprintf(op, "Diminuir");
    }
    else if(calc.operacao == 2)
    {
        sprintf(op, "Multiplicar");
    }
    else
    {
        sprintf(op, "Operacao desconhecida");
    }
    printf("Valor 1: %d\nValor 2: %d\nDificuldade: %d\nOperacao: %s", calc.valor1, calc.valor2, calc.dificuldade, op);
}

int somar(int resposta, Calcular calc)
{
    int resultado = calc.valor1 + calc.valor2;
    calc.resultado = resultado;
    int certo = 0; // 0 == errou, 1 == acertou.

    if (resposta == calc.resultado)
    {
        printf("Resposta correta!\n");
        certo = 1;
    }
    else
    {
        printf("Resposta errada!\n");
    }
    printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return (certo);
}

int diminuir(int resposta, Calcular calc)
{
    int resultado = calc.valor1 - calc.valor2;
    calc.resultado = resultado;
    int certo = 0; // 0 == errou, 1 == acertou.

    if (resposta == calc.resultado)
    {
        printf("Resposta correta!\n");
        certo = 1;
    }
    else
    {
        printf("Resposta errada!\n");
    }
    printf("%d - %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return (certo);
}

int multiplicar(int resposta, Calcular calc)
{
    int resultado = calc.valor1 * calc.valor2;
    calc.resultado = resultado;
    int certo = 0; // 0 == errou, 1 == acertou.

    if (resposta == calc.resultado)
    {
        printf("Resposta correta!\n");
        certo = 1;
    }
    else
    {
        printf("Resposta errada!\n");
    }
    printf("%d * %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return (certo);
}