/**
 * UNIDADE 0
 * @author  - Manoella Santos Diniz [769058]
 * @version - v0.1
 * @date - 09 / 08 / 2023
 */

// dependencias
#include "io.h" // para as entradas e saidas

/**
 * Method00 - nao faz nada.
 */
void method00()
{
    // nao faz nada
} // fim do method00()

bool estaContido(int array[], int tamanho, int x)
{
    bool contido = false;
    int controle = 0;

    for (controle = 0; controle < tamanho; controle++)
    {
        if (array[controle] == x)
            contido = true;
    }

    return contido;
}

/**
 * Method01 - Elemento esta' contido ou nao
 */
void method01()
{
    // definir valores
    int n = 0;
    int x = 0;
    int controle = 0;

    // identificar
    IO_id("Unidade00b");

    n = IO_readpositive("Entrar com tamanho do array: ");

    int array[n];

    for (controle = 0; controle < n; controle++)
    {
        array[controle] = IO_readint("Entrar com valor: ");
    }

    x = IO_readint("Entrar com valor para checar: ");

    if (estaContido(array, n, x))
        IO_printf("\nO elemento esta' no array.");
    else
        IO_printf("\nO elemento nao esta' no array.");

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim do method01()

bool estaContidoB(int array[], int tamanho, int x)
{
    bool contido = false;
    int i = 0;
    int j = 0;

    for (i = tamanho / 2; i < tamanho; i++)
    {
        for (j = tamanho / 2; j >= 0; j--)
        {
            if (array[j] == x || array[i] == x)
                contido = true;
        }
    }

    return contido;
}

/**
 * Method02 - Elemento esta' contido ou nao (alternativo)
 */
void method02()
{
    // definir valores
    int n = 0;
    int x = 0;
    int controle = 0;

    // identificar
    IO_id("Unidade00b");

    n = IO_readpositive("Entrar com tamanho do array: ");

    int array[n];

    for (controle = 0; controle < n; controle++)
    {
        array[controle] = IO_readint("Entrar com valor: ");
    }

    x = IO_readint("Entrar com valor para checar: ");

    if (estaContidoB(array, n, x))
        IO_printf("\nO elemento esta' no array.");
    else
        IO_printf("\nO elemento nao esta' no array.");

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim do method02()

void menorMaior(int array[], int tamanho)
{
    int maior = 0;
    int menor = 0;
    int controle = 0;

    for (controle = 0; controle < tamanho; controle++)
    {
        if (controle == 0)
        {
            maior = array[controle];
            menor = array[controle];
        }
        if (array[controle] > maior)
        {
            maior = array[controle];
        }
        else if (array[controle] < menor)
        {
            menor = array[controle];
        }
    }

    IO_printf("\nMAIOR: %d", maior);
    IO_printf("\nMENOR: %d", menor);
}

/**
 * Method03 - Maior e menor elementos
 */
void method03()
{
    // definir valores
    int n = 0;
    int controle = 0;

    // identificar
    IO_id("Unidade00b");

    n = IO_readpositive("Entrar com tamanho: ");

    int array[n];

    for (controle = 0; controle < n; controle++)
    {
        array[controle] = IO_readint("Entrar com valor: ");
    }

    menorMaior(array, n);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim do method03()

void menorMaiorB(int array[], int tamanho)
{
    int maior = 0;
    int menor = 0;
    int controle = 0;

    for (controle = 0; controle < tamanho; controle++)
    {
        if (controle == 0)
        {
            maior = array[controle];
            menor = array[controle];
        }
        if (array[controle] > maior)
        {
            maior = array[controle];
        }
        else if (array[controle] < menor)
        {
            menor = array[controle];
        }
    }

    IO_printf("\nMAIOR: %d", maior);
    IO_printf("\nMENOR: %d", menor);
}

/**
 * Method04 - Maior e menor elementos (alternativo)
 */
void method04()
{
    // definir valores
    int n = 0;
    int controle = 0;

    // identificar
    IO_id("Unidade00b");

    n = IO_readpositive("Entrar com tamanho: ");

    int array[n];

    for (controle = 0; controle < n; controle++)
    {
        array[controle] = IO_readint("Entrar com valor: ");
    }

    menorMaior(array, n);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim do method04()

/*
 * Funcao principal.
 * @return codigo de encerramento
 * @param argc - quantidade de parametros na linha de comandos
 * @param argv - arranjo com o grupo de parametros na linha de comandos
 */
int main(int argc, char *argv[])
{
    // definir dado
    int x = 0; // definir variavel com valor inicial

    // repetir até desejar parar
    do
    {
        // identificar
        IO_id("Unidade00b");

        // ler do teclado
        IO_println("Opcoes");
        IO_println(" 0 - parar");
        IO_println(" 1 - Method01");
        IO_println(" 2 - Method02");
        IO_println(" 3 - Method03");
        IO_println(" 4 - Method04");
        IO_println("");
        x = IO_readint("Entrar com uma opcao: ");

        // testar valor
        switch (x)
        {
        case 0:
            method00();
            break;
        case 1:
            method01();
            break;
        case 2:
            method02();
            break;
        case 3:
            method03();
            break;
        case 4:
            method04();
            break;
        default:
            IO_pause("ERRO: Valor invalido.");
        } // fim escolher
    } while (x != 0);

    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}
