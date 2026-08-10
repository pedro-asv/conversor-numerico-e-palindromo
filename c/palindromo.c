/**
 * palindromo.c — Verifica se uma frase ou palavra é um palíndromo.
 *
 * Compilar: gcc -o palindromo palindromo.c
 * Uso:      ./palindromo "Arara"
 *           ./palindromo "A base do teto desaba"
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO_BUFFER 256

/* Recebe o texto original e escreve a versão normalizada (só letras/números,
 * minúsculo) em 'saida'. Em C precisamos passar o buffer de destino como
 * parâmetro, porque a função não pode simplesmente "retornar uma string nova"
 * do jeito fácil que Python/JS fazem. */
void normalizar(const char *texto, char *saida)
{
    int j = 0;
    for (int i = 0; texto[i] != '\0'; i++)
    {
        unsigned char c = (unsigned char)texto[i];
        if (isalnum(c))
        {
            saida[j++] = tolower(c);
        }
    }
    saida[j] = '\0';
}

int eh_palindromo(const char *normalizado)
{
    int tamanho = strlen(normalizado);
    for (int i = 0; i < tamanho / 2; i++)
    {
        if (normalizado[i] != normalizado[tamanho - 1 - i])
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Uso: ./palindromo \"texto a verificar\"\n");
        return 1;
    }

    char normalizado[TAMANHO_BUFFER];
    normalizar(argv[1], normalizado);

    int resultado = eh_palindromo(normalizado);

    printf("Texto original:  %s\n", argv[1]);
    printf("Texto comparado: %s\n", normalizado);
    printf("%s\n", resultado ? "É palíndromo!" : "Não é palíndromo.");

    return resultado ? 0 : 1;
}
