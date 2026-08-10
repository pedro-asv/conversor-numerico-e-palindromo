/**
 * conversor.c — Converte um número hexadecimal para decimal, binário e octal.
 *
 * Compilar: gcc -o conversor conversor.c
 * Uso:      ./conversor <hexadecimal>
 *           ./conversor 1A3F
 *           ./conversor 0x1A3F
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Diferente de C++, aqui não existe std::string — trabalhamos com
 * arrays de char de tamanho fixo, e precisamos garantir manualmente
 * que cabe no buffer (esse é o tipo de cuidado que o C++/Python
 * escondem da gente com tipos de string dinâmicos). */
#define TAMANHO_BUFFER 64

void para_binario(unsigned long numero, char *saida)
{
    if (numero == 0)
    {
        strcpy(saida, "0");
        return;
    }

    char temporario[TAMANHO_BUFFER];
    int i = 0;

    while (numero > 0)
    {
        temporario[i++] = (numero % 2) + '0';
        numero /= 2;
    }

    /* construímos de trás pra frente, então precisamos inverter na hora de copiar */
    int j;
    for (j = 0; j < i; j++)
    {
        saida[j] = temporario[i - 1 - j];
    }
    saida[j] = '\0'; /* toda string em C precisa terminar com '\0' manualmente */
}

void para_octal(unsigned long numero, char *saida)
{
    if (numero == 0)
    {
        strcpy(saida, "0");
        return;
    }

    char temporario[TAMANHO_BUFFER];
    int i = 0;

    while (numero > 0)
    {
        temporario[i++] = (numero % 8) + '0';
        numero /= 8;
    }

    int j;
    for (j = 0; j < i; j++)
    {
        saida[j] = temporario[i - 1 - j];
    }
    saida[j] = '\0';
}

int eh_hex_valido(const char *valor)
{
    if (strlen(valor) == 0)
        return 0;

    for (size_t i = 0; i < strlen(valor); i++)
    {
        if (!isxdigit((unsigned char)valor[i]))
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Uso: ./conversor <hexadecimal>\n");
        return 1;
    }

    char entrada_original[TAMANHO_BUFFER];
    strncpy(entrada_original, argv[1], TAMANHO_BUFFER - 1);
    entrada_original[TAMANHO_BUFFER - 1] = '\0';

    char *valor_hex = entrada_original;
    if (strncasecmp(valor_hex, "0x", 2) == 0)
    {
        valor_hex += 2; /* "pula" os 2 primeiros caracteres, sem copiar string nova */
    }

    if (!eh_hex_valido(valor_hex))
    {
        printf("Erro: '%s' não é um hexadecimal válido.\n", entrada_original);
        return 1;
    }

    /* strtoul (string to unsigned long) é o equivalente em C do
     * std::stoul do C++ / int(x, 16) do Python */
    unsigned long numero_decimal = strtoul(valor_hex, NULL, 16);

    char binario[TAMANHO_BUFFER];
    char octal[TAMANHO_BUFFER];
    para_binario(numero_decimal, binario);
    para_octal(numero_decimal, octal);

    for (char *p = entrada_original; *p; p++)
    {
        *p = toupper((unsigned char)*p);
    }

    printf("Hexadecimal: %s\n", entrada_original);
    printf("Decimal:     %lu\n", numero_decimal);
    printf("Binário:     %s\n", binario);
    printf("Octal:       %s\n", octal);

    return 0;
}
