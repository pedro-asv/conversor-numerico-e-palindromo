import sys


def converter_hex(valor_hex: str) -> dict:
    valor_hex = valor_hex.strip().lower().removeprefix("0x")

    numero_decimal = int(valor_hex, 16)

    return {
        "decimal": numero_decimal,
        "binario": bin(numero_decimal)[2:],
        "octal": oct(numero_decimal)[2:],
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
