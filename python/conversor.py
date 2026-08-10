"""
conversor.py — Converte um número hexadecimal para decimal, binário e octal.

Uso:
    python3 conversor.py <hexadecimal>
    python3 conversor.py 1A3F
    python3 conversor.py 0x1A3F
"""

import sys


def converter_hex(valor_hex: str) -> dict:
    """Recebe uma string hexadecimal (com ou sem prefixo 0x) e retorna
    um dicionário com as representações em decimal, binário e octal."""
    valor_hex = valor_hex.strip().lower().removeprefix("0x")

    # int(x, 16) faz o Python interpretar a string como base 16 —
    # lança ValueError automaticamente se algum caractere não for hexadecimal válido
    numero_decimal = int(valor_hex, 16)

    return {
        "decimal": numero_decimal,
        "binario": bin(numero_decimal)[2:],   # remove o prefixo "0b"
        "octal": oct(numero_decimal)[2:],     # remove o prefixo "0o"
    }


def main():
    if len(sys.argv) != 2:
        print("Uso: python3 conversor.py <hexadecimal>")
        sys.exit(1)

    try:
        resultado = converter_hex(sys.argv[1])
    except ValueError:
        print(f"Erro: '{sys.argv[1]}' não é um hexadecimal válido.")
        sys.exit(1)

    print(f"Hexadecimal: {sys.argv[1].upper()}")
    print(f"Decimal:     {resultado['decimal']}")
    print(f"Binário:     {resultado['binario']}")
    print(f"Octal:       {resultado['octal']}")


if __name__ == "__main__":
    main()
