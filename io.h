/**
 * IO - Console input/output library.
 * @author  PUC-Minas - ICEI
 * @version 0.1 - 2023-2
 *
 * IO - v2023-2_0.1 - 09 / 08 / 2023
 * Author: Manoella Santos Diniz

 */
// ---------------------- lista de dependencias

#include <stdio.h>   // para entradas e saidas
#include <stddef.h>  // para definicoes basicas
#include <stdlib.h>  // para a biblioteca padrao
#include <string.h>  // para cadeias de caracteres
#include <stdarg.h>  // para tratar argumentos
#include <stdbool.h> // para definicoes logicas
#include <ctype.h>   // para tipos padroes
#include <math.h>    // para definicoes matematicas
#include <time.h>    // para medir tempo
#include <wchar.h>   // para 16-bit characters

// ---------------------- redefinicoes para apontamentos

#ifndef __IO_REFS__
#define __IO_REFS__

#define nullptr NULL // para compatibilizar com C++
#define null NULL    // para generalizar

#define addr(p) (&(p))  // para obter endereco
#define deref(p) (*(p)) // para obter conteudo de endereco
#define val(p) (*(p))   // para obter conteudo apontado

#define ref * // para passar parametro por referencia
              // (na assinatura)
#define var & // para passar parametro por referencia
              // (na chamada)

#endif

// ---------------------- redefinicoes uteis

#ifndef _IO_H_
#define _IO_H_
// alternativas mais seguras
#define IO_printf printf   // melhor: printf_s
#define IO_scanf scanf     // melhor: scanf_s
#define IO_fprintf fprintf // melhor: fprintf_s
#define IO_fscanf fscanf   // melhor: fscanf_s

#define AND &&
#define OR ||
#define NOT !
#define XOR ^

// ---------------------- definicoes de constantes

const bool FALSE = false; // definir constante
const bool TRUE = true;   // definir constante

const char EOS = '\0';    // definir fim de cadeia de caracteres
const char EOL = '\n';    // definir mudanca de linha
const char ENDL[] = "\n"; // definir mudanca de linha

const char STR_EMPTY[] = ""; // definir cadeia de caracteres vazia
const int STR_SIZE = 80;     // definir tamanho padrao para caracteres

// ---------------------- definicoes de tipos

typedef char *chars;     // definir cadeia  de caracteres
typedef int *ints;       // definir arranjo de inteiros
typedef double *doubles; // definir arranjo de reais
typedef bool *bools;     // definir arranjo de logicos

// ---------------------- definicoes de variaveis globais

int IO_error = 0;     // inicialmente sem erros
bool IO_trace = true; // inicialmente habilitado

// ---------------------- para tratamento de erros

void IO_debugOFF()
{
    IO_trace = false;
} // end IO_debug_OFF ( )

void IO_debugON()
{
    IO_trace = true;
} // end IO_debug_ON  ( )

void IO_debug(bool condition, const char *const text)
{
    if (IO_trace && condition)
    {
        IO_printf("\nDBG> %s\n", text);
        getchar();
    } // end if
} // end IO_debug ( )

// ---------------------- para entradas e saidas

/**
 * Metodo para limpar a saida de dados padrao.
 */
void IO_clrscr()
{
    if (IO_trace)
    {
#if defined(_WIN32) || defined(_WIN64) || defined(__WINDOWS__)
        system("cls"); // para Windows - OBS: NAO RECOMENDADO !
#elif defined(__linux__)
        system("clear"); // para Linux   - OBS: NAO RECOMENDADO !
#elif defined(__APPLE__) && defined(__MACH__)
        system("clear"); // para Linux   - OBS: NAO RECOMENDADO !
#elif defined(unix) || defined(__unix__) || defined(__unix)
        system("clear"); // para Linux   - OBS: NAO RECOMENDADO !
#else
#error Unknown_OS
#endif
    } // end if
} // end IO_flush ( )

/**
    Metodo para limpar a entrada de dados padrao.
 */
void IO_flush()
{
    //  fflush ( stdin );   // para Windows - OBS: NAO RECOMENDADO !
    // para Linux   - OBS: NAO FUNCIONA    !
    int x = 0; // compat�vel com o retorno de getchar()
    do
    {
        x = getchar();
    } while (x != EOF && x != '\n');
    clearerr(stdin); // reiniciar o estado de EOF

} // end IO_flush ( )

/**
    Funcao para informar a versao dessa biblioteca.
    @return versao atual
 */
chars IO_version()
{
    chars x = strdup("v.2022-2");
    return (x);
} // end IO_version ( )

/**
    Metodo para identificar o programa e a autoria.
    @param text - mensagem a ser exibida
 */
void IO_id(const char *const text)
{
    IO_printf("%s\n", text);
    IO_printf("%s\n", "Autor: Manoella Santos Diniz");
    IO_printf("\n"); // mudar de linha
} // fim IO_id ( )

/**
    Funcao para ler valor inteiro do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
int IO_readint(const char *const text)
{
    int x = 0;
    if (IO_trace)
        IO_printf("%s", text);
    IO_scanf("%d", &x);
    IO_flush();
    return (x);
} // end IO_readint ( )

/**
    Funcao para ler valor positivo do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
int IO_readpositive(const char *const text)
{
    int x = 0;
    bool ERRO = false;
    do
    {
        if (IO_trace)
            IO_printf("%s", text);
        IO_scanf("%d", &x);
        IO_flush();
        ERRO = x < 0;
        if (ERRO)
            IO_printf("\aERRO: Quantidade menor que 0.\n");
    } while (ERRO);
    return (x);
} // end IO_readpositive ( )

/**
    Funcao para ler valor real de precisao dupla do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
double IO_readdouble(const char *const text)
{
    double x = 0.0;
    if (IO_trace)
        IO_printf("%s", text);
    IO_scanf("%lf", &x);
    IO_flush();
    return (x);
} // end IO_readdouble ( )

/**
    Funcao para ler valor real de precisao simples do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
float IO_readfloat(const char *const text)
{
    float x = 0.0;
    if (IO_trace)
        IO_printf("%s", text);
    IO_scanf("%f", &x);
    IO_flush();
    return (x);
} // end IO_readfloat ( )

/**
    Funcao para ler valor logico do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
    OBS.:   Usar zero (0) para falso e
            diferente de zero para verdadeiro
 */
bool IO_readbool(const char *const text)
{
    int x = 0;
    if (IO_trace)
        IO_printf("%s", text);
    IO_scanf("%d", &x);
    IO_flush();
    return (x != 0);
} // end IO_readbool ( )

/**
    Funcao para ler caractere do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
char IO_readchar(const char *const text)
{
    char x = '0';
    if (IO_trace)
        IO_printf("%s", text);
    do
    {
        x = getchar();
    } while ('\n' == x);
    IO_flush();
    //  getchar ( );
    return (x);
} // end IO_readchar ( )

/**
    Funcao para ler caractere do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
void IO_pause(const char *const text)
{
    char x = '0';
    if (IO_trace)
    {
        IO_printf("\n%s\n", text);
        do
        {
            x = getchar();
        } while ('\n' != x);
    } // end if
} // end IO_pause ( )

/**
    Funcao para reservar espaco para guardar cadeia de caracteres.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
chars IO_new_chars(int size)
{
    return ((chars)malloc((size + 1) * sizeof(char)));
} // fim IO_new_chars ( )

/**
    Funcao para reservar espaco para guardar inteiros.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
ints IO_new_ints(int size)
{
    return ((ints)malloc((size) * sizeof(int)));
} // fim IO_new_ints ( )

/**
    Funcao para reservar espaco para guardar reais.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
doubles IO_new_doubles(int size)
{
    return ((doubles)malloc((size) * sizeof(double)));
} // fim IO_new_doubles ( )

/**
    Funcao para reservar espaco para guardar logicos.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
bools IO_new_bools(int size)
{
    return ((bools)malloc((size) * sizeof(bool)));
} // fim IO_new_bools ( )

/**
    Funcao para concatenar cadeias de caracteres.
    @return cadeia com o resultado
    @param text1 - primeira cadeia
    @param text2 - segunda  cadeia
 */
chars IO_concat(const char *const text1, const char *const text2)
{ // reservar area
    chars buffer = IO_new_chars(strlen(text1) + strlen(text2) + 1);
    strcpy(buffer, text1);
    strcat(buffer, text2);
    return (buffer);
} // fim IO_concat ( )

/**
    Funcao para converter valor logico para caracteres.
    @return cadeia com o resultado
    @param x     - valor logico
 */
chars IO_toString_b(bool x)
{ // reservar area
    chars buffer = IO_new_chars(STR_SIZE + 1);
    sprintf(buffer, "%d", x); // variante do printf( )
    return (buffer);
} // fim IO_toString_b ( )

/**
    Funcao para converter caractere para caracteres.
    @return cadeia com o resultado
    @param x     - caractere
 */
chars IO_toString_c(char x)
{
    chars buffer = IO_new_chars(STR_SIZE + 1);
    sprintf(buffer, "%c", x); // variante do printf( )
    return (buffer);
} // fim IO_toString_c ( )

/**
    Funcao para converter inteiro para caracteres.
    @return cadeia com o resultado
    @param x     - valor inteiro
 */
chars IO_toString_d(int x)
{
    chars buffer = IO_new_chars(STR_SIZE + 1);
    sprintf(buffer, "%d", x); // variante do printf( )
    return (buffer);
} // fim IO_toString_d ( )

/**
    Funcaoo para converter real para caracteres.
    @return cadeia com o resultado
    @param x     - valor real
 */
chars IO_toString_f(double x)
{ // variante do printf( )
    chars buffer = IO_new_chars(STR_SIZE + 1);
    sprintf(buffer, "%lf", x);
    return (buffer);
} // fim IO_toString_f ( )

/**
 * Funcao para concatenar 'a cadeia de caracteres mais um digito.
 * @return cadeia de caracteres acrescida de mais um digito
 * @param digits - cadeia de caracteres
 * @param digit - simbolo a ser acrescentado 'a cadeia de caracteres
 */
chars concatADigit(chars string, char digit)
{
    return (IO_concat(string, IO_toString_c(digit)));
} // fim concatADigit()

/**
    Metodo para mostrar uma linha com certo texto.
    @param text - texto a ser exibido
 */
void IO_print(const char *const text)
{
    IO_printf("%s", text);
    //      puts ( text );
} // fim IO_print ( )

/**
    Metodo para mostrar uma linha com certo texto
    e mudar de linha.
    @param text - texto a ser exibido
 */
void IO_println(const char *const text)
{
    IO_printf("%s\n", text);
    //  puts ( text ); putchar ( '\n' );
} // fim IO_println ( )

/**
    Metodo para gravar uma linha em arquivo texto.
    @param filePtr - referencia para arquivo aberto
    @param text    - cadeia de caracteres a ser gravada
 */
void IO_fprint(FILE *filePtr, const char *const text)
{
    IO_fprintf(filePtr, "%s", text);
} // fim IO_fprint ( )

/**
    Metodo para gravar uma linha em arquivo texto
    e mudar de linha.
    @param filePtr - referencia para arquivo aberto
    @param text    - cadeia de caracteres a ser gravada
 */
void IO_fprintln(FILE *filePtr, const char *const text)
{
    IO_fprintf(filePtr, "%s\n", text);
} // fim IO_fprintln ( )

/**
    Funcao para ler uma cadeia de caracteres de arquivo.
    @return palavra lida
    @param arquivo - referencia para arquivo aberto
 */
chars IO_fread(FILE *filePtr)
{
    chars buffer = IO_new_chars(STR_SIZE + 1);

    IO_fscanf(filePtr, "%s", buffer); // ler uma cadeia
    return (buffer);
} // fim IO_fread ( )

/**
    Funcao para ler uma linha inteira.
    @return linha lida
    @param filePtr - referencia para arquivo aberto
 */
chars IO_freadln(FILE *filePtr)
{
    chars buffer = IO_new_chars(STR_SIZE + 1);

    fgets(buffer, STR_SIZE, filePtr); // ler uma linha
    buffer[strlen(buffer) - 1] = EOS; // reposicionar o fim de linha
    return (buffer);
} // fim IO_freadln ( )

/**
    Funcao para ler cadeia de caracteres.
    @return cadeia de caracteres
    @param text - mensagem a ser exibida antes da leitura
 */
chars IO_readstring(const char *const text)
{
    chars buffer = IO_new_chars(STR_SIZE + 1);
    if (IO_trace)
        IO_printf("%s", text);
    IO_scanf("%80s", buffer); // ler cadeia de caracteres
                              // com limitacao de 80 posicoes
    IO_flush();
    return (buffer);
} // fim IO_readString ( )

/**
    Funcao para ler uma linha inteira.
    @return linha lida
    @param text - mensagem a ser exibida antes da leitura
 */
chars IO_readln(const char *const text)
{
    if (IO_trace)
        IO_printf("%s", text);
    return (IO_freadln(stdin));
} // fim IO_readln ( )

/**
    Funcao para converter valor logico para cadeia de caracteres.
    @return "true", se verdadeiro; "false", caso contrario
    @param  value - valor a ser convertido
 */
chars IO_boolalpha(bool value)
{
    if (value)
        return (strdup("true"));
    else
        return (strdup("false"));
} // fim IO_boolalpha ( )

/**
    Funcao para comparar conteudos em memoria.
    @return true, se iguais; false, caso contrario
    @param  p1   - endereco do primeiro valor
    @param  p2   - endereco do segundo  valor
    @param  size - tamanho em bytes a ser comparado
 */
bool IO_check(void *p1, void *p2, int size)
{
    return (p1 && p2 && (0 == memcmp(p1, p2, size)));
} // fim IO_check ( )

/**
    Funcao para retornar o tamanho de cadeia de caracteres.
    @return tamanho, se existir; 0, caso contrario
    @param  text  - cadeia de caracteres
 */
int IO_length(char *text)
{
    int x = 0;
    if (text)
    {
        x = strlen(text);
    }
    return (x);
} // fim IO_length ( )

/**
    Funcao para obter simbolo de certa posicao
    em cadeia de caracteres.
    @return simbolo, se existir; '\0', caso contrario
    @param  text  - cadeia de caracteres
    @param  index - posicao desejada
 */
char IO_charAt(char *text, unsigned int index)
{
    char x = '\0';
    if (text && index < strlen(text))
    {
        x = text[index];
    }
    return (x);
} // fim IO_charAt ( )

/**
    Funcao para copiar parte de uma cadeia de caracteres.
    @return parte de cadeia de caracteres ou
            NULL, caso houver parametros invalidos
    @param  text  - cadeia de caracteres
    @param  start - onde comecar
    @param  size  - quantos caracteres copiar
 */
char *IO_substring(char *text, int start, int size)
{
    chars buffer = NULL;
    if (start >= 0 && size > 0 && (start + size) < (int)strlen(text))
    {
        buffer = IO_new_chars(size + 1);
        memcpy(buffer, text + start, size);
        buffer[size] = '\0';
    }
    return (buffer);
} // fim IO_substring ( )

/**
    Funcao para copiar parte de uma cadeia de caracteres.
    @return parte de cadeia de caracteres ou
            NULL, caso houver parametros invalidos
    @param  text   - cadeia de caracteres
    @param  symbol - caractere a ser acrescentado
 */
char *IO_strapp(char *text, char symbol)
{
    chars buffer = NULL;
    int size = 0;
    if (text)
    {
        size = strlen(text);
        buffer = IO_new_chars(size + 1);
        memcpy(buffer, text, size);
        buffer[size] = symbol;
        buffer[size + 1] = '\0';
    }
    return (buffer);
} // fim IO_strapp ( )

// ---------------------- definicoes de funcoes e procedimentos

/**
 * Funcao para calcular area de quadrado
 * @return area
 * @param l - lado
 */
double areaQuadrado(double l)
{
    // definir dado local
    double A = 0.0;

    // calcular
    A = l * l;

    return (A);
} // fim areaQuadrado()

/**
 * Funcao para calcular perimetro de quadrado
 * @return perimetro
 * @param l - lado
 */
double perimetroQuadrado(double l)
{
    // definir dado local
    double P = 0.0;

    // calcular
    P = 4.0 * l;

    return (P);
} // fim perimetroQuadrado()

/**
 * Funcao para calcular area de retangulo
 * @return area
 * @param b - base
 * @param h - altura
 */
double areaRetangulo(double b, double h)
{
    // definir dado local
    double A = 0.0;

    // calcular
    A = b * h;

    return (A);
} // fim areaRetangulo()

/**
 * Funcao para calcular perimetro de retangulo
 * @return perimetro
 * @param b - base
 * @param h - altura
 */
double perimetroRetangulo(double b, double h)
{
    // definir dado local
    double P = 0.0;

    // calcular
    P = (2.0 * b) + (2.0 * h);

    return (P);
} // fim perimetroRetangulo()

/**
 * Funcao para calcular area de triangulo
 * @return area
 * @param b - base
 * @param h - altura
 */
double areaTriangulo(double b, double h)
{
    // definir dado local
    double A = 0.0;

    // calcular
    A = (b * h) / 2.0;

    return (A);
} // fim areaTriangulo()

/**
 * Funcao para calcular perimetro de triangulo equilatero
 * @return perimetro
 * @param l - lado
 */
double perimetroTriangulo(double l)
{
    // definir dado
    double P = 0.0;

    // calcular
    P = 3.0 * l;

    return (P);
} // fim perimetroTriangulo()

/**
 * Funcao para calcular altura de triangulo equilatero
 * @return altura
 * @param l - lado
 */
double alturaTriangulo_E(double l)
{
    // definir dado local
    double h = 0.0;

    // calcular
    h = (sqrt(3) * l) / 2.0;

    return (h);
} // fim alturaTriangulo_E()

/**
 * Funcao para calcular volume de cubo
 * @return volume
 * @param l - lado
 */
double volumeCubo(double l)
{
    // definir dado local
    double V = 0.0;

    // calcular
    V = pow(l, 3.0);

    return (V);
} // fim volumeCubo()

/**
 * Funcao para calcular volume de paralelepipedo
 * @return volume
 * @param l - lado
 * @param w - comprimento
 * @param h - altura
 */
double volumeParalelepipedo(double l, double w, double h)
{
    // definir dado local
    double V = 0.0;

    // calcular
    V = l * w * h;

    return (V);
} // fim volumeParalelepipedo()

/**
 * Funcao para calcular area de circulo
 * @return area
 * @param r - raio
 */
double areaCirculo(double r)
{
    // definir dado local
    double A = 0.0;

    // calcular
    A = M_PI * pow(r, 2.0);

    return (A);
} // fim areaCirculo()

/**
 * Funcao para calcular raio de circulo
 * @return raio
 * @param A - area
 */
double raioCirculo(double A)
{
    // definir dado local
    double r = 0.0;

    // calcular
    r = sqrt(A / M_PI);

    return (r);
} // fim raioCirculo()

/**
 * Funcao para calcular volume de esfera
 * @return volume
 * @param r - raio
 */
double volumeEsfera(double r)
{
    // definir dado local
    double V = 0.0;

    // calcular
    V = (4.0 * M_PI * pow(r, 3.0)) / 3.0;

    return (V);
} // fim volumeEsfera()

/**
 * Funcao para calcular volume de esfera
 * @return raio
 * @param V - volume
 */
double raioEsfera(double V)
{
    // definir dado local
    double r = 0.0;

    // calcular
    r = cbrt((3.0 * V) / (4.0 * M_PI));

    return (r);
} // fim raioEsfera()

/**
 * Funcao para calcular area de esfera
 * @return area
 * @param r - raio
 */
double areaEsfera(double r)
{
    // definir dado local
    double A = 0.0;

    // calcular
    A = 4.0 * M_PI * pow(r, 2.0);

    return (A);
} // fim areaEsfera()

/**
 * Funcao para calcular valor maior entre dois valores inteiros
 * @return maior
 * @param x
 * @param y - valores a serem testados
 */
int maior_i(int x, int y)
{
    // definir dado local
    int maior = 0;

    // testar se primeiro e' maior que segundo
    if (x > y)
    {
        maior = x;
    }
    else
    {
        maior = y;
    } // fim else

    return (maior);
} // fim maior_i()

/**
 * Funcao para calcular valor menor entre dois valores inteiros
 * @return menor
 * @param x
 * @param y - valores a serem testados
 */
bool menor_i(int x, int y)
{
    // definir dado local
    bool menor = false;

    // testar se primeiro e' maior que segundo
    if (x < y)
    {
        menor = true;
    } // fim if

    return (menor);
} // fim maior_i()

/**
 * Funcao para calcular valor maior entre dois valores reais
 * @return maior
 * @param x
 * @param y - valores a serem testados
 */
double maior_d(double x, double y)
{
    // definir dado local
    double maior = 0.0;

    // testar se primeiro e' maior que segundo
    if (x > y)
    {
        maior = x;
    }
    else
    {
        maior = y;
    } // fim else

    return (maior);
} // fim maior_d()

/**
 * Funcao para determinar se valor inteiro e' par
 * @return true, se par; false, se impar
 * @param x - valor a ser testado
 */
bool par(int x)
{
    // definir dado local e comparar
    bool par = x % 2 == 0;

    return (par);
} // fim par()

/**
 * Funcao para determinar se caractere e' letra maiuscula
 * @return true, se maiuscula; false, se minuscula
 * @param c - caractere a ser testado
 */
bool isUpperCase(char c)
{
    // definir dado local
    bool maiuscula = false;

    // testar se caractere esta' entre A e Z
    if (c >= 'A' && c <= 'Z')
    {
        maiuscula = true;
    } // fim if

    return (maiuscula);
} // fim isUpperCase()

/**
 * Funcao para determinar se caractere e' letra minuscula.
 * @return true, se par; false, caso contrario
 * @param x - valor a ser testado
 */
bool isLowerCase(char x)
{
    // definir dado local
    bool result = false;
    // testar a condicao
    if ('a' <= x && x <= 'z')
    {
        result = true;
    } // fim se
    return (result);
} // fim isLowerCase()

/**
 * Funcao para determinar se caractere e' letra
 * @return true, se letra; false, se outro simbolo
 * @param c - caractere a ser testado
 */
bool isLetter(char c)
{
    // definir dado local
    bool letra = false;

    // testar se caractere esta' entre A e Z ou entre a e z
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        letra = true;
    } // fim if

    return (letra);
} // fim isLetter()

/**
 * Funcao para determinar se caractere e' digito
 * @return true, se digito; false, se outro simbolo
 * @param c - caractere a ser testado
 */
bool isDigit(char c)
{
    // definir dado local
    bool digito = false;

    // testar se caractere esta' entre 0 e 9
    if ((c >= '0' && c <= '9'))
    {
        digito = true;
    } // fim if

    return (digito);
} // fim isDigit()

/**
 * Funcao para determinar se inteiro e' multiplo de 3
 * @return true, se multiplo; false, se nao
 * @param x - valor a ser testado
 */
bool multipleThree(int x)
{
    // definir dado local e comparar
    bool multiplo = x % 3 == 0;

    return (multiplo);
} // fim multipleThree()

/**
 * Funcao para determinar se inteiro e' multiplo de 5
 * @return true, se multiplo; false, se nao
 * @param x - valor a ser testado
 */
bool multipleFive(int x)
{
    // definir dado local e comparar
    bool multiplo = x % 5 == 0;

    return (multiplo);
} // fim multipleFive()

/**
 * Funcao para determinar se valor inteiro e' positivo.
 * @return true, se positivo; false, caso contrario
 * @param x - valor a ser testado
 */
bool positive(int x)
{
    // definir dado local
    bool result = false;

    // testar a condicao
    if (x > 0)
    {
        result = true;
    } // fim se

    return (result);
} // fim positive()

/**
 * Funcao para determinar se valor inteiro pertence a intervalo aberto.
 * @return true, se pertencer; false, caso contrario
 * @param x - valor a ser testado
 */
bool belongsTo(int x, int inferior, int superior)
{
    // definir dado local
    bool result = false;

    // testar a condicao
    if (inferior < x && x < superior)
    {
        result = true;
    } // fim se

    return (result);
} // fim belongsTo()

/**
 * Funcao para determinar se valor inteiro pertence a intervalo fechado.
 * @return true, se pertencer; false, caso contrario
 * @param x - valor a ser testado
 */
bool belongsIn(int x, int inferior, int superior)
{
    // definir dado local
    bool result = false;

    // testar a condicao
    if (inferior <= x && x <= superior)
    {
        result = true;
    } // fim se

    return (result);
} // fim belongsIn()

/**
 * Funcao para determinar se valor real pertence a intervalo aberto.
 * @return true, se pertencer; false, caso contrario
 * @param x - valor a ser testado
 */
bool belongsTo_d(double x, double inferior, double superior)
{
    // definir dado local
    bool result = false;

    // testar a condicao
    if (inferior < x && x < superior)
    {
        result = true;
    } // fim se

    return (result);
} // fim belongsTo_d()

/**
 * Funcao para determinar se valor real pertence a intervalo fechado.
 * @return true, se pertencer; false, caso contrario
 * @param x - valor a ser testado
 */
bool belongsIn_d(double x, double inferior, double superior)
{
    // definir dado local
    bool result = false;

    // testar a condicao
    if (inferior <= x && x <= superior)
    {
        result = true;
    } // fim se

    return (result);
} // fim belongsIn_d()

/**
 * Funcao para determinar se caractere pertence a intervalo aberto.
 * @return true, se pertencer; false, caso contrario
 * @param x - valor a ser testado
 */
bool belongsTo_c(char x, char y, char z)
{
    bool entre = false;

    // testar
    if ((x > y && x < z) || (x > z && x < y))
    {
        entre = true;
    } // fim if

    return (entre);
} // fim belongTo_c()

/**
 * Funcao para determinar se caractere pertence a intervalo fechado.
 * @return true, se pertencer; false, caso contrario
 * @param x - valor a ser testado
 */
bool belongsIn_c(char x, char y, char z)
{
    bool entre = false;

    // testar
    if ((x >= y && x <= z) || (x >= z && x <= y))
    {
        entre = true;
    }

    return (entre);
} // fim belongIn_c()

/**
 * contarMinusculas - Contador de letras minusculas.
 * @return quantidade de letras minusculas
 * @param x - cadeia de caracteres a ser avaliada
 */
int contarMinusculas(chars cadeia, int x)
{
    // definir dado
    int resposta = 0;

    // testar se contador valido
    if (0 <= x && x < strlen(cadeia))
    {
        // testar se letra minuscula
        if (cadeia[x] >= 'a' &&
            cadeia[x] <= 'z')
        {
            // fazer de novo com valor absoluto
            resposta = 1;
        } // fim se
        resposta = resposta + contarMinusculas(cadeia, x + 1);
    } // fim se

    // retornar resposta
    return (resposta);
} // fim contarMinusculas()

/**
 * contarMinusculas - Contador de letras minusculas.
 * @return quantidade de letras minusculas
 * @param x - cadeia de caracteres a ser avaliada
 */
int contarMaiusculasb(chars cadeia, int posicao)
{
    // definir dado
    int contador = 0;
    int tamanho = 0;

    tamanho = strlen(cadeia);

    // testar se contador valido
    if (0 <= posicao && posicao < tamanho)
    {
        // testar se letra minuscula
        if (cadeia[posicao] >= 'A' && cadeia[posicao] <= 'Z')
        {
            // fazer de novo com valor absoluto
            contador = 1;
        } // fim se
        contador = contador + contarMaiusculasb(cadeia, posicao + 1);
    } // fim se

    // retornar resposta
    return (contador);
} // fim contarMaiusculasb()

int contarMaiusculas(chars palavra)
{
    return (contarMaiusculasb(palavra, 0));
}

/**
 * Funcao para contar maiusculas menores que K em uma cadeia de caracteres.
 * @return quantidade
 * @param palavra - cadeia a ser analisada
 * @param tamanho - tamanho da cadeia
 * @param posicao - posicao do caractere
 * @param simbolo - caractere a ser testado
 */
int contarMaiusculas_K(chars palavra)
{
    // definir dados locais
    int tamanho = 0;
    int contador = 0;
    int posicao = 0;
    char simbolo = '_';

    // definir tamanho da cadeia
    tamanho = strlen(palavra);

    // contar maiusculas menores que K
    for (posicao = 0; posicao < tamanho; posicao++)
    {
        simbolo = palavra[posicao];

        // testar
        if (isUpperCase(simbolo) && simbolo < 'K')
        {
            contador++;
        }
    } // fim for

    return (contador);
} // fim contarMaiusculas_K()

/**
 * Funcao para contar maiusculas menores que K e k em uma cadeia de caracteres.
 * @return quantidade
 * @param palavra - cadeia a ser analisada
 * @param tamanho - tamanho da cadeia
 * @param posicao - posicao do caractere
 * @param simbolo - caractere a ser testado
 */
int contarLetras_Kk(chars palavra)
{
    // definir dados locais
    int tamanho = 0;
    int contador = 0;
    int posicao = 0;
    char simbolo = '_';

    // definir tamanho da cadeia
    tamanho = strlen(palavra);

    // contar letras menores que K
    for (posicao = 0; posicao < tamanho; posicao++)
    {
        simbolo = palavra[posicao];

        // testar
        if ((isUpperCase(simbolo) && simbolo < 'K') || (isLowerCase(simbolo) && simbolo < 'k'))
        {
            contador++;
        }
    } // fim for

    return (contador);
} // fim contarLetras_Kk()

/**
 * Funcao para contar digitos em uma cadeia de caracteres.
 * @return quantidade
 * @param palavra - cadeia a ser analisada
 * @param tamanho - tamanho da cadeia
 * @param posicao - posicao do caractere
 * @param simbolo - caractere a ser testado
 */
int contarDigitos(chars palavra)
{
    // definir dados locais
    int tamanho = 0;
    int contador = 0;
    int posicao = 0;
    char simbolo = '_';

    // definir tamanho da cadeia
    tamanho = strlen(palavra);

    // contar digitos impares
    for (posicao = 0; posicao < tamanho; posicao++)
    {
        simbolo = palavra[posicao];

        // testar
        if (isDigit(simbolo))
        {
            contador++;
        }
    } // fim for

    return (contador);
} // fim contarDigitos()

/**
 * contarDigitosb - Contar digitos recursivamente.
 * @return quantidade de digitos
 * @param x - numero cuja quantidade de digitos sera' calculada
 */
int contarDigitosb(int x)
{
    // definir dado
    int resposta = 1; // base

    // testar se contador valido
    if (x >= 10)
    {
        // tentar fazer de novo com valor menor
        resposta = 1 + contarDigitosb(x / 10); // motor 1
    }
    else
    {
        if (x < 0)
        {
            // fazer de novo com valor absoluto
            resposta = contarDigitosb(-x); // motor 2
        }                                  // fim se
    }                                      // fim se

    // retornar resposta
    return (resposta);
} // fim contarDigitosb()

int contarDigitos2b_I(chars palavra, int posicao)
{
    // definir dados locais
    int tamanho = 0;
    int contador = 0;
    int digito = 0;
    char simbolo = '_';

    tamanho = strlen(palavra);

    // contar digitos impares
    if (posicao >= 0 && posicao < tamanho)
    {
        simbolo = palavra[posicao];

        // resgatar valor decimal da tabela ASCII
        if (isDigit(simbolo))
        {
            digito = (int)simbolo - 48;

            if (!par(digito))
            {
                contador = 1 + contarDigitos2b_I(palavra, posicao + 1);
            }
            else
            {
                contador = contarDigitos2b_I(palavra, posicao + 1);
            }
        }
        else
        {
            contador = contarDigitos2b_I(palavra, posicao + 1);
        }
    }

    return (contador);
}

int contarDigitosb_I(chars palavra)
{
    return (contarDigitos2b_I(palavra, 0));
}

/**
 * Funcao para contar digitos impares em uma cadeia de caracteres.
 * @return quantidade
 * @param palavra - cadeia a ser analisada
 * @param tamanho - tamanho da cadeia
 * @param posicao - posicao do caractere
 * @param simbolo - caractere a ser testado
 */
int contarDigitos_I(chars palavra)
{
    // definir dados locais
    int tamanho = 0;
    int contador = 0;
    int posicao = 0;
    int digito = 0;
    char simbolo = '_';

    // definir tamanho da cadeia
    tamanho = strlen(palavra);

    // contar digitos impares
    for (posicao = 0; posicao < tamanho; posicao++)
    {
        simbolo = palavra[posicao];

        // resgatar valor decimal da tabela ASCII
        digito = (int)simbolo - 48;

        // testar
        if (isDigit(simbolo) && !par(digito))
        {
            contador++;
        }
    } // fim for

    return (contador);
} // fim contarDigitos_I()

/**
 * Funcao para contar alfanumericos em uma cadeia de caracteres.
 * @return quantidade
 * @param palavra - cadeia a ser analisada
 * @param tamanho - tamanho da cadeia
 * @param posicao - posicao do caractere
 * @param simbolo - caractere a ser testado
 */
int contarAlfanum(chars palavra)
{
    // definir dados locais
    int tamanho = 0;
    int contador = 0;
    int posicao = 0;
    char simbolo = '_';

    // definir tamanho da cadeia
    tamanho = strlen(palavra);

    // contar digitos impares
    for (posicao = 0; posicao < tamanho; posicao++)
    {
        simbolo = palavra[posicao];

        // testar
        if (isDigit(simbolo) || isLetter(simbolo))
        {
            contador++;
        }
    } // fim for

    return (contador);
} // fim contarAlfanum()

/**
 * Funcao para separar maiusculas menores que K.
 * @return maiusculas
 * @param palavra - cadeia a ser analisada
 * @param tamanho - tamanho da cadeia
 * @param posicao - posicao do caractere
 * @param simbolo - caractere a ser testado
 * @param maiusculas - cadeia de maiusculas
 */
chars separarMaiusculas_K(chars palavra)
{
    // definir dados locais
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '_';
    chars maiusculas = IO_new_chars(STR_SIZE);

    strcpy(maiusculas, STR_EMPTY); // vazio

    // determinar a quantidade de simbolos na palavra
    tamanho = strlen(palavra);

    // repetir para a quantidade de vezes informada
    for (posicao = 0; posicao < tamanho; posicao = posicao + 1)
    {
        // isolar um simbolo por vez
        simbolo = palavra[posicao];

        // testar e contar as letras maiusculas de uma palavra
        if (isUpperCase(simbolo) && simbolo < 'K')
        {
            // concatenar simbolo encontrado
            maiusculas = IO_concat(maiusculas, IO_toString_c(simbolo));
        }
    }

    return (maiusculas);
} // fim separarMaiusculas_K()

/**
 * Funcao para separar letras menores que K e k.
 * @return maiusculas
 * @param palavra - cadeia a ser analisada
 * @param tamanho - tamanho da cadeia
 * @param posicao - posicao do caractere
 * @param simbolo - caractere a ser testado
 * @param maiusculas - cadeia de maiusculas
 */
chars separarLetras_Kk(chars palavra)
{
    // definir dados locais
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '_';
    chars letras = IO_new_chars(STR_SIZE);

    strcpy(letras, STR_EMPTY); // vazio

    // determinar a quantidade de simbolos na palavra
    tamanho = strlen(palavra);

    // repetir para a quantidade de vezes informada
    for (posicao = 0; posicao < tamanho; posicao = posicao + 1)
    {
        // isolar um simbolo por vez
        simbolo = palavra[posicao];

        // testar e contar as letras de uma palavra
        if ((isUpperCase(simbolo) && simbolo < 'K') || (isLowerCase(simbolo) && simbolo < 'k'))
        {
            // concatenar simbolo encontrado
            letras = IO_concat(letras, IO_toString_c(simbolo));
        }
    }

    return (letras);
} // fim separarLetras_Kk()

/**
 * Funcao para separar simbolos.
 * @return maiusculas
 * @param palavra - cadeia a ser analisada
 * @param tamanho - tamanho da cadeia
 * @param posicao - posicao do caractere
 * @param simbolo - caractere a ser testado
 * @param simbolos - cadeia de simbolos
 */
chars separarSimbolos(chars palavra)
{
    // definir dados locais
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '_';
    chars simbolos = IO_new_chars(STR_SIZE);

    strcpy(simbolos, STR_EMPTY); // vazio

    // determinar a quantidade de simbolos na palavra
    tamanho = strlen(palavra);

    // repetir para a quantidade de vezes informada
    for (posicao = 0; posicao < tamanho; posicao = posicao + 1)
    {
        // isolar um simbolo por vez
        simbolo = palavra[posicao];

        // testar e contar as letras maiusculas de uma palavra
        if (!isLetter(simbolo) && !isDigit(simbolo))
        {
            // concatenar simbolo encontrado
            simbolos = IO_concat(simbolos, IO_toString_c(simbolo));
        }
    }

    return (simbolos);
} // fim separarSimbolos()

/**
 * Funcao para separar alfanumericos.
 * @return maiusculas
 * @param palavra - cadeia a ser analisada
 * @param tamanho - tamanho da cadeia
 * @param posicao - posicao do caractere
 * @param simbolo - caractere a ser testado
 * @param alfanum - cadeia de alfanumericos
 */
chars separarAlfanum(chars palavra)
{
    // definir dados locais
    int tamanho = 0;
    int posicao = 0;
    char simbolo = '_';
    chars alfanum = IO_new_chars(STR_SIZE);

    strcpy(alfanum, STR_EMPTY); // vazio

    // determinar a quantidade de alfanumericos na palavra
    tamanho = strlen(palavra);

    // repetir para a quantidade de vezes informada
    for (posicao = 0; posicao < tamanho; posicao = posicao + 1)
    {
        // isolar um simbolo por vez
        simbolo = palavra[posicao];

        // testar e contar as letras maiusculas de uma palavra
        if (isLetter(simbolo) || isDigit(simbolo))
        {
            // concatenar simbolo encontrado
            alfanum = IO_concat(alfanum, IO_toString_c(simbolo));
        }
    }

    return (alfanum);
} // fim separarAlfanum()

/**
 * Funcao para determinar qual cadeia possui menos digitos.
 * @return true, se primeira cadeia tiver mais digitos; false, caso contrario
 * @param menos - guarda o resultado da comparacao entre as duas cadeias
 */
bool menosDigitos(chars palavra_A, chars palavra_B)
{
    // definir dado local
    bool menos = false;

    // comparar
    menos = menor_i(contarDigitos(palavra_A), contarDigitos(palavra_B));

    return (menos);
} // fim menosDigitos()

/**
 * Method01a - Mostrar certa quantidade de valores.
 * @param x - quantidade de valores a serem mostrados
 */
void method01a(int x)
{
    // definir dado local
    int y = 1; // controle

    // repetir enquanto controle menor que a quantidade desejada
    while (y <= x)
    {
        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", y);

        // passar ao proximo
        y = y + 1;
    } // fim se
} // fim method01a()

/**
 * Method01b - Mostrar certa quantidade de valores recursivamente.
 * @param x - quantidade de valores a serem mostrados
 */
void method01b(int x)
{
    // repetir enquanto valor maior que zero
    if (x > 0)
    {
        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", x);

        // passar ao proximo
        method01b(x - 1); // motor da recursividade
    }                     // fim se
} // fim method01b()

/**
 * Method02a - Mostrar certa quantidade de valores pares.
 * @param x - quantidade de valores a serem mostrados
 */
void method02a(int x)
{
    // definir dado local
    int y = 1; // controle
    int z = 2;

    // repetir enquanto controle menor que a quantidade desejada
    while (y <= x)
    {
        // mostrar valor
        IO_printf("%d: %d\n", y, z);

        // passar ao proximo par
        z = z + 2;

        // passar ao proximo valor controlado
        y = y + 1;
    } // fim se
} // fim method02a()

/**
 * Method02b - Mostrar certa quantidade de valores recursivamente.
 * @param x - quantidade de valores a serem mostrados
 */
void method02b(int x)
{
    // repetir enquanto valor maior que zero
    if (x > 0)
    {
        // passar ao proximo
        method02b(x - 1); // motor da recursividade

        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", x);
    } // fim se
} // fim method02b()

/**
 * Method03a - Mostrar certa quantidade de valores pares.
 * @param x - quantidade de valores a serem mostrados
 */
void method03a(int x)
{
    // definir dado local
    int y = 1; // controle
    int z = 0;

    // repetir enquanto controle menor que a quantidade desejada
    while (y <= x)
    {
        // vincular o valor a ser mostrado ao controle
        z = 2 * y;

        // mostrar valor
        IO_printf("%d: %d\n", y, z);

        // passar ao proximo valor controlado
        y = y + 1;
    } // fim se
} // fim method03a()

/**
 * Method03b - Mostrar certa quantidade de valores recursivamente.
 * @param x - quantidade de valores a serem mostrados
 */
void method03b(int x)
{
    // repetir enquanto valor maior que zero
    if (x > 1)
    {
        // passar ao proximo
        method03b(x - 1); // motor da recursividade

        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", x);
    }
    else
    { // base da recursividade
        // mostrar o ultimo
        IO_printf("%s\n", "Valor = 1");
    } // fim se
} // fim method03b()

/**
 * Method04a - Mostrar certa quantidade de valores pares.
 * @param x - quantidade de valores a serem mostrados
 */
void method04a(int x)
{
    // definir dado local
    int y = x; // controle
    int z = 0;

    // repetir enquanto controle menor que a quantidade desejada
    while (y > 0)
    {
        // vincular o valor a ser mostrado ao controle
        z = 2 * y;

        // mostrar valor
        IO_printf("%d: %d\n", y, z);

        // passar ao proximo valor controlado
        y = y - 1;
    } // fim se
} // fim method04a()

/**
 * Method04b - Mostrar certa quantidade de valores recursivamente.
 * @param x - quantidade de valores a serem mostrados
 */
void method04b(int x)
{
    // repetir enquanto valor maior que zero
    if (x > 1)
    {
        // passar ao proximo
        method04b(x - 1); // motor da recursividade

        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", 2 * (x - 1));
    }
    else
    { // base da recursividade
        // mostrar o ultimo
        IO_printf("%s\n", "Valor = 1");
    } // fim se
} // fim method04b()

/**
 Method05a - Mostrar certa quantidade de valores pares.
 @param x - quantidade de valores a serem mostrados
*/
void method05a(int x)
{
    // definir dado local
    int y = 0; // controle

    // repetir enquanto controle menor que a quantidade desejada
    for (y = x; y > 0; y = y - 1)
    {
        // mostrar valor
        IO_printf("%d: %d\n", y, (2 * y));
    } // fim se
} // fim method05a()

/**
 * Method05b - Mostrar certa quantidade de valores recursivamente.
 * @param x - quantidade de valores a serem mostrados
 */
void method05b(int x)
{
    // repetir enquanto valor maior que zero
    if (x > 1)
    {
        // passar ao proximo
        method05b(x - 1); // motor da recursividade

        // mostrar valor
        IO_printf("%d: %d/%d\n", x, (2 * (x - 1)), (2 * (x - 1) + 1));
    }
    else
    { // base da recursividade
        // mostrar o ultimo
        IO_printf("%d: %d\n", x, 1);
    } // fim se
} // fim method05b()

/**
 * somarValores - funcao para somar certa quantidade de pares.
 * @return soma dos valores
 * @param x - quantidade de valores a serem mostrados
 */
int somarValores(int x)
{
    // definir dados locais
    int soma = 1;
    int y = 0; // controle

    // repetir enquanto controle menor que a quantidade desejada
    for (y = x - 1; y > 0; y = y - 1)
    {
        // mostrar valor
        IO_printf("%d: %d\n", y, (2 * y));

        // somar valor
        soma = soma + (2 * y);
    } // fim se

    // retornar resultado
    return (soma);
} // fim somarValores()

/**
 * somarFracao1 - funcao para somar certa quantidade de fracoes.
 * @return soma dos valores
 * @param x - quantidade de valores a serem mostrados
 */
double somarFracao1(int x)
{
    // definir dados locais
    double soma = 1.0;
    double numerador = 0.0;
    double denominador = 0.0;
    int y = 0; // controle

    // repetir enquanto controle menor que a quantidade desejada
    for (y = x - 1; y > 0; y = y - 1)
    {
        // calcular numerador
        numerador = 1.0;

        // calcular denominador
        denominador = 2.0 * y;

        // mostrar valor
        IO_printf("%d: %7.4lf/%7.4lf = %lf\n",
                  y, numerador, denominador, (numerador / denominador));

        // somar valor
        soma = soma + (1.0) / (2.0 * y);
    } // fim se

    // retornar resultado
    return (soma);
} // fim somarFracao1()

/**
 * somarFracao2 - funcao para somar certa quantidade de fracoes.
 * @return soma dos valores
 * @param x - quantidade de valores a serem mostrados
 */
double somarFracao2(int x)
{
    // definir dados locais
    double soma = 1.0;
    double numerador = 0.0;
    double denominador = 0.0;
    int y = 0; // controle

    // mostrar primeiro valor
    IO_printf("%d: %7.4lf/%7.4lf\n", 1, 1.0, soma);

    // repetir enquanto controle menor que a quantidade desejada
    for (y = 1; y <= (x - 1); y = y + 1)
    {
        // calcular numerador
        numerador = 2.0 * y - 1;

        // calcular denominador
        denominador = 2.0 * y;

        // mostrar valor
        IO_printf("%d: %7.4lf/%7.4lf = %lf\n",
                  y + 1, numerador, denominador, (numerador / denominador));

        // somar valor
        soma = soma + (2.0 * y - 1) / (2.0 * y);
    } // fim se

    // retornar resultado
    return (soma);
} // fim somarFracao2()

/**
 * somarFracao3 - funcao para somar certa quantidade de fracoes.
 * @return soma dos valores
 * @param x - quantidade de valores a serem mostrados
 */
double somarFracao3(int x)
{
    // definir dados locais
    double soma = 1.0;
    int y = 0; // controle

    // mostrar primeiro valor
    IO_printf("%d: %7.4lf/%7.4lf\n", 1, 1.0, soma);

    // repetir enquanto controle menor que a quantidade desejada
    for (y = 1; y <= (x - 1); y = y + 1)
    {
        // mostrar valor
        IO_printf("%d: %7.4lf/%7.4lf = %7.4lf\n",
                  y + 1, (2.0 * y), (2.0 * y + 1), ((2.0 * y) / (2.0 * y + 1)));

        // somar valor
        soma = soma + (2.0 * y) / (2.0 * y + 1);
    } // fim se

    // retornar resultado
    return (soma);
} // fim somarFracao3()

/**
 * somarFracoes - Somar certa quantidade de fracoes recursivamente.
 * @return soma de valores
 * @param x - quantidade de valores a serem mostrados
 */
double somarFracoes(int x)
{
    // definir dado local
    double soma = 0.0;

    // repetir enquanto valor maior que zero
    if (x > 1)
    {
        // separar um valor e passar ao proximo (motor da recursividade)
        soma = (2.0 * (x - 1)) / (2.0 * (x - 1) + 1) + somarFracoes(x - 1);

        // mostrar valor
        IO_printf("%d: %lf/%lf\n", x, (2.0 * (x - 1)), (2.0 * (x - 1) + 1));
    }
    else
    {
        // base da recursividade
        soma = 1.0;
        // mostrar o ultimo
        IO_printf("%d: %lf\n", x, 1.0);
    } // fim se

    // retornar resultado
    return (soma);
} // fim somarFracoes()

/**
 * somarFracoesb - Somar certa quantidade de fracoes recursivamente.
 * @return soma de valores
 * @param n - quantidade de valores a serem mostrados
 */
double somarFracoesb(int n)
{
    // definir dado local
    double soma = 0.0;

    // repetir enquanto valor maior que zero
    if (n > 1)
    {
        // separar um valor e passar ao proximo (motor da recursividade)
        soma = 1.0 / (6.0 * n) + somarFracoesb(n - 1);

        // mostrar valor
        IO_printf("1/%d = %lf\n", 6 * n, 1.0 / (6.0 * n));
    }
    else
    {
        // caso base
        soma = 1.0 / 6.0;

        // mostrar o ultimo
        IO_printf("1/%d = %lf\n", 6 * n, 1.0 / (6.0 * n));
    } // fim se

    // retornar resultado
    return (soma);
} // fim somarFracoesb()

/**
 * somarFracoes2b - Somar certa quantidade de fracoes recursivamente.
 * @return soma de valores
 * @param x - quantidade de valores a serem mostrados (controle)
 * @param soma - valor atual da soma (historia = memoria)
 * @param numerador - numerador da parcela a ser somada
 * @param denominador - denominador da parcela a ser somada
 */
double somarFracoes2b(int x, double soma, double numerador, double denominador)
{
    // repetir enquanto valor maior que zero
    if (x > 0)
    {
        // mostrar valores atuais
        IO_printf("%d: %lf/%lf\n", x, numerador, denominador);

        // somar o termo atual e passar ao proximo (motor da recursividade)
        soma = somarFracoes2b(x - 1,                                    // proximo
                              soma + ((1.0 * numerador) / denominador), // atualizar
                              numerador + 2.0,                          // proximo
                              denominador + 2.0);                       // proximo
    }

    // retornar resultado
    return (soma);
} // fim somarFracoes2b()

/**
 * somarFracoes2a - Somar certa quantidade de fracoes.
 * Funcao de servico para preparar e
 * disparar o mecanismo recursivo.
 * @return soma de valores
 * @param x - quantidade de valores a serem mostrados
 */
double somarFracoes2a(int x)
{
    // definir dado local
    double soma = 0.0;

    // repetir enquanto valor maior que zero
    if (x > 0)
    {
        // mostrar o ultimo
        IO_printf("%d: %lf\n", x, 1.0);

        // preparar a soma do valor atual e o proximo
        soma = somarFracoes2b(x - 1, 1.0, 2.0, 3.0);
    } // fim se

    // retornar resultado
    return (soma);
} // fim somarFracoes2a()

/**
 * multiplicarValores - funcao para multiplicar certa quantidade de valores impares.
 * @return produto de valores
 * @param x - quantidade de valores
 */
int multiplicarValores(int x)
{
    // definir dados locais
    int produto = 1;
    int y = 0; // controle

    // repetir enquanto controle menor que a quantidade desejada
    for (y = 1; y <= x; y = y + 1)
    {
        // mostrar valor
        IO_printf("%d: %d\n", y, (2 * y - 1));

        // somar valor
        produto = produto * (2 * y - 1);
    } // fim se

    // retornar resultado
    return (produto);
} // fim multiplicarValores()

/**
 * Method11a - Mostrar certa quantidade de valores multiplos de 6.
 * @param n - quantidade de valores a serem mostrados
 */
void method11a(int n)
{
    // definir dado local
    int x = 1; // controle
    int y = 0;

    // repetir enquanto controle menor que a quantidade desejada
    while (x <= n)
    {
        // vincular o valor a ser mostrado ao controle
        y = 6 * x;

        // mostrar valor
        IO_printf("%d: %d\n", x, y);

        // passar ao proximo valor controlado
        x = x + 1;
    } // fim se
} // fim method11a()

/**
 * Method11b - Mostrar certa quantidade de multiplos de 6 recursivamente.
 * @param n - quantidade de valores a serem mostrados
 */
void method11b(int n)
{
    // repetir enquanto valor maior que zero
    if (n > 1)
    {
        // passar ao proximo
        method11b(n - 1); // motor da recursividade

        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", 6 * n);
    }
    else
    { // base da recursividade
        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", 6 * n);
    } // fim se
} // fim method11b()

/**
 * Method12a - Mostrar certa quantidade de valores multiplos de 12.
 * @param n - quantidade de valores a serem mostrados
 */
void method12a(int n)
{
    // definir dado local
    int x = 1; // controle
    int y = 0;

    // repetir enquanto controle menor que a quantidade desejada
    while (x <= n)
    {
        // vincular o valor a ser mostrado ao controle
        y = 12 * x;

        // mostrar valor
        IO_printf("%d: %d\n", x, y);

        // passar ao proximo valor controlado
        x = x + 1;
    } // fim se
} // fim method12a()

/**
 * Method12b - Mostrar certa quantidade de multiplos de 6 recursivamente.
 * @param n - quantidade de valores a serem mostrados
 */
void method12b(int n)
{
    // repetir enquanto valor maior que zero
    if (n > 1)
    {
        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", 6 * n);

        // passar ao proximo
        method12b(n - 1); // motor da recursividade
    }
    else
    { // base da recursividade
        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", 6 * n);
    } // fim se
} // fim method12b()

/**
 * Method13a - Mostrar certa quantidade de valores multiplos de 9 impares.
 * @param n - quantidade de valores a serem mostrados
 */
void method13a(int n)
{
    // definir dado local
    int x = 0;

    // repetir enquanto controle menor que a quantidade desejada
    while (n > 0)
    {
        // vincular o valor a ser mostrado ao controle
        x = (2 * n - 1) * 9;

        // mostrar valor
        IO_printf("%d: %d\n", n, x);

        // passar ao proximo valor controlado
        n = n - 1;
    } // fim se
} // fim method13a()

/**
 * Method13b - Mostrar certa quantidade de multiplos de 6 recursivamente.
 * @param n - quantidade de valores a serem mostrados
 */
void method13b(int n)
{
    // repetir enquanto valor maior que zero
    if (n > 1)
    {
        // passar ao proximo
        method13b(n - 1); // motor da recursividade

        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", 6 * (n - 1));
    }
    else
    { // base da recursividade
        // mostrar valor
        IO_printf("%s\n", "Valor = 1");
    } // fim se
} // fim method13b()

/**
 * Method14a - Mostrar certa quantidade de valores inversos de 6.
 * @param n - quantidade de valores a serem mostrados
 */
void method14a(int n)
{
    // definir dado local
    int x = 1; // controle
    int y = 0;
    double z = 0;

    // repetir enquanto controle menor que a quantidade desejada
    while (x <= n)
    {
        // vincular o valor a ser mostrado ao controle
        y = 6 * x;
        z = 1.0 / y;

        // mostrar valor
        IO_printf("%d: 1/%d = %lf\n", x, y, z);

        // passar ao proximo valor controlado
        x = x + 1;
    } // fim se
} // fim method14a()

/**
 * Method14b - Mostrar certa quantidade de multiplos de 6 recursivamente.
 * @param n - quantidade de valores a serem mostrados
 */
void method14b(int n)
{
    // repetir enquanto valor maior que zero
    if (n > 1)
    {
        // mostrar valor
        IO_printf("1/%d = %lf\n", 6 * (n - 1), 1.0 / (6 * (n - 1)));

        // passar ao proximo
        method14b(n - 1); // motor da recursividade
    }
    else
    { // base da recursividade
        // mostrar valor
        IO_printf("%s\n", "1/1 = 1");
    } // fim se
} // fim method14b()

void method15a(double y, int n)
{
    // definir dado local
    int x = 0; // controle
    double z = 0;

    // repetir enquanto controle menor que a quantidade desejada
    while (x < n)
    {
        // vincular o valor a ser mostrado ao controle
        z = 1.0 / pow(y, x);

        // mostrar valor
        IO_printf("%d: 1/%lf**%d = %lf\n", x + 1, y, x, z);

        // passar ao proximo valor controlado
        x = x + 1;
    } // fim se
}

void method17b(chars palavra, int i)
{
    if (i >= 0)
    {
        method17b(palavra, i - 1);

        // mostrar caracteres
        printf("%c\n", palavra[i]);
    }
}

void method17a(chars palavra)
{
    int tamanho = 0;

    tamanho = strlen(palavra);

    method17b(palavra, tamanho - 1);
}

/**
 * somarValores2 - funcao para somar certa quantidade de pares nao multiplos de 5 comecando no 6.
 * @return soma dos valores
 * @param n - quantidade de valores a serem mostrados
 */
int somarValores2(int n)
{
    // definir dados locais
    int x = 1; // controle
    int y = 0;
    int soma = 0;

    // repetir enquanto controle menor que a quantidade desejada
    for (x = 1; x <= n; x = x + 1)
    {
        if (!multipleFive(x))
        {
            y = 6 * x;
        }
        else
        {
            y = 6 * x + 6;
        }

        // mostrar valor
        IO_printf("%d: %d\n", x, y);

        // somar valor
        soma = soma + y;
    } // fim se

    // retornar resultado
    return (soma);
} // fim somarValores2()

double somarValores3(int n)
{
    // definir dados locais
    int x = 1; // controle
    int y = 0;
    double z = 0.0;
    double soma = 0.0;

    // repetir enquanto controle menor que a quantidade desejada
    for (x = 1; x <= n; x = x + 1)
    {
        if (!multipleFive(x))
        {
            y = 6 * x;
            z = 1.0 / y;
        }
        else
        {
            y = 6 * x + 6;
            z = 1.0 / y;
        }

        // mostrar valor
        IO_printf("%d: 1/%d = %lf\n", x, y, z);

        // somar valor
        soma = soma + z;
    } // fim se

    // retornar resultado
    return (soma);
}

int somarValores4(int n)
{
    // definir dados locais
    int x = 1; // controle
    int resultado = 0;
    int soma = 0;

    resultado = 6;

    // repetir enquanto controle menor que a quantidade desejada
    for (x = 0; x < n; x = x + 1)
    {
        resultado = resultado + x;

        // mostrar valor
        IO_printf("%d: %d\n", x + 1, resultado);

        // somar valor
        soma = soma + resultado;
    } // fim se

    // retornar resultado
    return (soma);
}

int somarValores5(int n)
{
    // definir dados locais
    int x = 1; // controle
    int resultado = 0;
    int potencia = 0;
    int soma = 0;

    resultado = 6;

    // repetir enquanto controle menor que a quantidade desejada
    for (x = 0; x < n; x = x + 1)
    {
        resultado = resultado + x;
        potencia = resultado * resultado;

        // mostrar valor
        IO_printf("%d: %d\n", x + 1, potencia);

        // somar valor
        soma = soma + potencia;
    } // fim se

    // retornar resultado
    return (soma);
}

double somarValores6(int n)
{
    // definir dados locais
    int x = 1; // controle
    int denominador = 0;
    double resultado = 0.0;
    double soma = 0.0;

    denominador = 6.0;

    // repetir enquanto controle menor que a quantidade desejada
    for (x = 0; x < n; x = x + 1)
    {
        denominador = denominador + x;
        resultado = 1.0 / denominador;

        // mostrar valor
        IO_printf("%d: 1/%d = %lf\n", x + 1, denominador, resultado);

        // somar valor
        soma = soma + resultado;
    } // fim se

    // retornar resultado
    return (soma);
}

int somarValores7(int x, int n)
{
    int soma = 0;
    int par = 2 * n;
    int potencia = (int)pow(x, par);

    // repetir enquanto valor maior que zero
    if (n > 0)
    {
        // separar um valor e passar ao proximo (motor da recursividade)
        soma = potencia + somarValores7(x, n - 1);

        // mostrar valor
        IO_printf("%d**%d = %d\n", x, par, potencia);
    }
    else
    {
        // base da recursividade
        soma = potencia;

        // mostrar o ultimo
        IO_printf("%d**%d = %d\n", x, par, potencia);
    } // fim se

    return (soma);
}

/**
 * somarValoresR - Somar certa quantidade de fracoes recursivamente.
 * @return soma de valores
 * @param n - quantidade de valores a serem mostrados
 */
int somarValoresR(int n)
{
    // definir dado local
    int soma = 0;

    // repetir enquanto valor maior que zero
    if (n > 1)
    {
        // separar um valor e passar ao proximo (motor da recursividade)
        soma = (6 * n) + somarValoresR(n - 1);

        // mostrar valor
        IO_printf("%d: %d\n", n, 6 * n);
    }
    else
    {
        // base da recursividade
        soma = 6;
        // mostrar o ultimo
        IO_printf("%d: %d\n", n, 6 * n);
    } // fim se

    // retornar resultado
    return (soma);
} // fim somarValoresR()

int fatorial(int n)
{
    int x = 0; // controle

    for (x = 1; n > 1; n = n - 1)
    {
        x = x * n;
    }

    return (x);
}

/**
 * fibonacci - Gerador de numero de Fibonacci.
 * @return numero de Fibonacci
 * @param x - numero de ordem cujo valor sera' calculado
 */
int fibonacci(int x)
{
    // definir dado
    int resposta = 0;

    // testar se contador valido
    if (x == 1 || x == 2)
    {
        // primeiros dois valores iguais a 1
        resposta = 1; // bases
    }
    else
    {
        if (x > 1)
        {
            // fazer de novo com valor absoluto
            resposta = fibonacci(x - 1) + fibonacci(x - 2);
        } // fim se
    }     // fim se

    // retornar resposta
    return (resposta);
} // fim fibonacci()

int fibonaccib_P(int x)
{
    // definir dado
    int resposta = 0;

    // testar se contador valido
    if (x == 1)
    {
        // primeiros dois valores iguais a 1
        resposta = 2; // bases
    }
    else if (x < 1)
    {
        // fazer de novo com valor absoluto
        resposta = x;
    }
    else
    {
        // valores pares fibonacci
        resposta = 4 * fibonaccib_P(x - 1) + fibonaccib_P(x - 2);
    }

    // retornar resposta
    return (resposta);
}

int fibonacci_P(int n)
{
    int contador = 0;
    int soma = 0;

    for (contador = 0; contador <= n; contador++)
    {
        soma = soma + fibonaccib_P(contador);
    }

    return (soma);
}

/**
 writeInts - Gravar em arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void writeInts(chars fileName, int x)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "wt");
    int y = 0;

    // repetir para a quantidade de dados
    for (y = 1; y <= x; y = y + 1)
    {
        // gravar valor
        fprintf(arquivo, "%d\n", y);
    } // fim repetir

    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
} // fim writeInts ( )

/**
 readInts - Ler de arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void readInts(chars fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "rt");
    int x = 0;

    // tentar ler o primeiro
    fscanf(arquivo, "%d", &x);
    // repetir enquanto houver dados
    while (!feof(arquivo))
    {
        // mostrar valor
        printf("%d\n", x);

        // tentar ler o proximo
        fscanf(arquivo, "%d", &x);
    } // fim repetir

    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose(arquivo);
} // fim readInts ( )

/**
 writeDoubles - Gravar em arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void writeDoubles(chars fileName, int x)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "wt");
    int y = 0;

    // gravar quantidade de valores
    IO_fprintf(arquivo, "%d\n", x);

    // repetir para a quantidade de dados
    for (y = 1; y <= x; y = y + 1)
    {
        // gravar valor
        IO_fprintf(arquivo, "%lf\n", (0.1 * y));
    } // fim repetir

    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
} // fim writeDoubles ( )

/**
 readDoubles - Ler de arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void readDoubles(chars fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "rt");
    int x = 0;
    int y = 1;
    double z = 0.0;

    // tentar ler a quantidade de dados
    fscanf(arquivo, "%d", &x);

    // repetir enquanto houver dados e
    // quantidade nao tiver sido alcancada
    while (!feof(arquivo) && y <= x)
    {
        // tentar ler
        fscanf(arquivo, "%lf", &z);

        // mostrar valor
        printf("%2d: %lf\n", y, z);

        // passar ao proximo
        y = y + 1;
    } // fim repetir

    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose(arquivo);
} // fim readDoubles ( )

/**
 writeText - Gravar em arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void writeText(chars fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "wt");
    chars linha = IO_new_chars(STR_SIZE);

    // repetir ate' desejar parar
    IO_println("Gravar linhas (para terminar, entrar com \"PARAR\"):\n");
    do
    {
        // ler do teclado
        strcpy(linha, IO_readln(""));

        // gravar valor
        IO_fprintf(arquivo, "%s\n", linha);
    } while (strcmp("PARAR", linha) != 0);

    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
} // fim writeText ( )

/**
 readText - Ler de arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
*/
void readText(chars fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "rt");
    chars linha = IO_new_chars(STR_SIZE);

    // tentar ler o primeiro
    strcpy(linha, IO_freadln(arquivo));

    // repetir enquanto houver dados
    while (!feof(arquivo) &&
           strcmp("PARAR", linha) != 0)
    {
        // mostrar valor
        printf("%s\n", linha);

        // tentar ler o proximo
        strcpy(linha, IO_freadln(arquivo));
    } // fim repetir

    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose(arquivo);
} // fim readText ( )

/**
 copyText - Copiar arquivo texto.
 @param fileOut - nome do arquivo de saida (destino)
 @param fileIn - nome do arquivo de entrada (origem )
*/
void copyText(chars fileOut, chars fileIn)
{
    // definir dados
    FILE *saida = fopen(fileOut, "wt");
    FILE *entrada = fopen(fileIn, "rt");
    chars linha = IO_new_chars(STR_SIZE);
    int contador = 0;

    // ler da origem
    strcpy(linha, IO_freadln(entrada));

    // repetir enquanto houver dados
    while (!feof(entrada))
    {
        // contar linha lida
        contador = contador + 1;

        // gravar no destino,
        // EXCEPCIONALMENTE sem a ultima linha, nesse caso
        if (strcmp("PARAR", linha) != 0)
        {
            IO_fprintln(saida, linha);
        } // fim se

        // ler da origem
        strcpy(linha, IO_freadln(entrada));
    } // fim repetir

    // informar total de linhas copiadas
    IO_printf("Lines read = %d\n", contador);

    // fechar arquivos
    fclose(saida);
    fclose(entrada);
} // fim copyText ( )

/**
 appendText - Gravar em arquivo texto certa quantidade de valores.
 @param fileName - nome do arquivo
 @param x - quantidade de valores
*/
void appendText(chars fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "at");
    chars linha = IO_new_chars(STR_SIZE);

    // repetir ate' desejar parar
    IO_println("Gravar linhas (para terminar, entrar com \"PARAR\"):\n");
    do
    {
        // ler do teclado
        strcpy(linha, IO_readln(""));

        // gravar valor
        IO_fprintln(arquivo, linha);
    } while (strcmp("PARAR", linha) != 0);

    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
} // fim appendText ( )

/**
 readWords - Ler palavras de arquivo.
 @param fileName - nome do arquivo
*/
void readWords(chars fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "rt");
    chars linha = IO_new_chars(STR_SIZE);

    // tentar ler a primeira
    strcpy(linha, IO_fread(arquivo));

    // repetir enquanto houver dados
    while (!feof(arquivo) &&
           strcmp("PARAR", linha) != 0)
    {
        // mostrar valor
        printf("%s\n", linha);

        // tentar ler o proximo
        strcpy(linha, IO_fread(arquivo));
    } // fim repetir

    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose(arquivo);
} // fim readWords ( )

/**
 searchWord - Procurar palavra em arquivo.
 @return true, se encontrar; false, caso contrario
 @param fileName - nome do arquivo
 @param word - palavra a procurar
*/
bool searchWord(chars fileName, chars word)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "rt");
    chars linha = IO_new_chars(STR_SIZE);

    // tentar ler a primeira
    strcpy(linha, IO_fread(arquivo));

    // repetir enquanto houver dados
    while (!feof(arquivo) &&
           strcmp(word, linha) != 0)
    {
        // tentar ler o proximo
        strcpy(linha, IO_fread(arquivo));
    } // fim repetir

    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose(arquivo);

    // retornar resultado
    return (strcmp(word, linha) == 0);
} // fim searchdWord ( )

void writeMultiples_6(chars fileName, int n)
{
    FILE *arquivo = fopen(fileName, "wt");
    int array[n];
    int x = 0;
    int controle = 0;

    for (controle = 0; controle < n; controle = controle + 1)
    {
        x = x + 6;
        array[controle] = x;
        IO_fprintf(arquivo, "%d\n", array[controle]);
    }

    fclose(arquivo);
}

void writeMultiples_5(chars fileName, int n)
{
    FILE *arquivo = fopen(fileName, "wt");
    int array[n];
    int x = 5;
    int controle = 0;

    for (controle = 0; controle < n; controle = controle + 1)
    {
        x = x + 10;
        array[controle] = x;
    }

    for (controle = n - 1; controle >= 0; controle = controle - 1)
    {
        IO_fprintf(arquivo, "%d\n", array[controle]);
    }

    fclose(arquivo);
}

void writePowers_6(chars fileName, int n)
{
    FILE *arquivo = fopen(fileName, "wt");
    int array[n];
    int x = 1;
    int controle = 0;

    IO_fprintf(arquivo, "1\n");

    for (controle = 1; controle < n; controle = controle + 1)
    {
        x = x * 6;
        array[controle] = x;
        IO_fprintf(arquivo, "%d\n", array[controle]);
    }

    fclose(arquivo);
}

void writeInverses_6(chars fileName, int n)
{
    FILE *arquivo = fopen(fileName, "wt");
    double array[n];
    double x = 1.0;
    double y = 1.0;
    int controle = 0;

    IO_fprintf(arquivo, "1/1 = 1\n");

    for (controle = 1; controle < n; controle = controle + 1)
    {
        x = x * 6;
        y = 1.0 / x;
        array[controle] = y;
        IO_fprintf(arquivo, "1/%.0lf = %lf\n", x, array[controle]);
    }

    fclose(arquivo);
}

void writeInverses_P(chars fileName, int n, double x)
{
    FILE *arquivo = fopen(fileName, "wt");
    double array[n];
    int y = 0;
    double z = 1.0;
    int controle = 0;

    IO_fprintf(arquivo, "%lf\n", z);

    for (controle = 1; controle < n; controle = controle + 1)
    {
        y = y + 2;
        z = 1.0 / pow(x, y);
        array[controle] = z;
        IO_fprintf(arquivo, "%lf\n", array[controle]);
    }

    fclose(arquivo);
}

void writeSums(chars fileName, int n)
{
    FILE *arquivoA = fopen("DADOS15.TXT", "rt");
    FILE *arquivoB = fopen(fileName, "wt");
    int contador = 0;
    double soma = 0;
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    if (arquivoA == NULL)
    {
        IO_printf("\aERRO: Arquivo nao encontrado.\n");
        fclose(arquivoB);
    }

    while (fscanf(arquivoA, "%lf", &x) == 1)
    {
        if (contador == 0)
        {
            y = x;
        }
        else if (contador <= n)
        {
            z = 2 * (contador - 1);
            soma = soma + 1.0 / pow(y, z);
        }

        contador = contador + 1;
    }

    fclose(arquivoA);

    IO_fprintf(arquivoB, "Quantidade = %d\n", n);
    IO_fprintf(arquivoB, "Resultado = %lf", soma);

    fclose(arquivoB);
}



#endif
