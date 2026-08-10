/**
 * conversor.cpp — Converte um número hexadecimal para decimal, binário e octal.
 *
 * Compilar: g++ -o conversor conversor.cpp
 * Uso:      ./conversor <hexadecimal>
 *           ./conversor 1A3F
 *           ./conversor 0x1A3F
 */

#include <iostream>
#include <string>
#include <bitset>
#include <cctype>
#include <stdexcept>

std::string removerPrefixo(std::string valor)
{
    if (valor.size() >= 2 && valor[0] == '0' && (valor[1] == 'x' || valor[1] == 'X'))
    {
        valor = valor.substr(2);
    }
    return valor;
}

bool ehHexValido(const std::string &valor)
{
    if (valor.empty())
        return false;
    for (char c : valor)
    {
        if (!std::isxdigit(static_cast<unsigned char>(c)))
            return false;
    }
    return true;
}

// Converte manualmente pra binário, dígito a dígito — diferente das outras
// linguagens, que têm função pronta pra isso. Em C++, o jeito mais didático
// costuma ser via bitset (usado abaixo) já que não existe um "toString(base)" nativo.
std::string paraBinario(unsigned long numero)
{
    if (numero == 0)
        return "0";
    std::string binario = std::bitset<32>(numero).to_string();
    // remove os zeros à esquerda que sobram do bitset de 32 bits
    size_t primeiroUm = binario.find('1');
    return binario.substr(primeiroUm);
}

std::string paraOctal(unsigned long numero)
{
    if (numero == 0)
        return "0";
    std::string octal;
    while (numero > 0)
    {
        octal = std::to_string(numero % 8) + octal;
        numero /= 8;
    }
    return octal;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Uso: ./conversor <hexadecimal>" << std::endl;
        return 1;
    }

    std::string entradaOriginal = argv[1];
    std::string valorHex = removerPrefixo(entradaOriginal);

    if (!ehHexValido(valorHex))
    {
        std::cout << "Erro: '" << entradaOriginal << "' não é um hexadecimal válido." << std::endl;
        return 1;
    }

    unsigned long numeroDecimal = std::stoul(valorHex, nullptr, 16);

    for (auto &c : entradaOriginal)
        c = std::toupper(static_cast<unsigned char>(c));

    std::cout << "Hexadecimal: " << entradaOriginal << std::endl;
    std::cout << "Decimal:     " << numeroDecimal << std::endl;
    std::cout << "Binário:     " << paraBinario(numeroDecimal) << std::endl;
    std::cout << "Octal:       " << paraOctal(numeroDecimal) << std::endl;

    return 0;
}
