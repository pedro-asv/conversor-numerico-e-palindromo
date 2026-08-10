"""
palindromo.py — Verifica se uma frase ou palavra é um palíndromo.

Ignora maiúsculas/minúsculas, espaços e pontuação, então também
reconhece frases como "A base do teto desaba".

Uso:
    python3 palindromo.py "Arara"
    python3 palindromo.py "A base do teto desaba"
"""

import sys
import re


def normalizar(texto: str) -> str:
    """Remove tudo que não é letra/número e deixa em minúsculas."""
    return re.sub(r"[^a-z0-9]", "", texto.lower())


def eh_palindromo(texto: str) -> bool:
    normalizado = normalizar(texto)
    return normalizado == normalizado[::-1]  # [::-1] inverte a string


def main():
    if len(sys.argv) != 2:
        print('Uso: python3 palindromo.py "texto a verificar"')
        sys.exit(1)

    texto = sys.argv[1]
    resultado = eh_palindromo(texto)

    print(f"Texto original:  {texto}")
    print(f"Texto comparado: {normalizar(texto)}")
    print("É palíndromo!" if resultado else "Não é palíndromo.")

    sys.exit(0 if resultado else 1)


if __name__ == "__main__":
    main()
