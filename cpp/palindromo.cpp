#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string normalizar(const std::string &texto)
{
    std::string resultado;
    for (unsigned char c : texto)
    {
        if (std::isalnum(c))
        {
            resultado += std::tolower(c);
        }
    }
    return resultado;
}

bool ehPalindromo(const std::string &texto)
{
    std::string normalizado = normalizar(texto);
    std::string invertido = normalizado;
    std::reverse(invertido.begin(), invertido.end());
    return normalizado == invertido;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Uso: ./palindromo \"texto a verificar\"" << std::endl;
        return 1;
    }

    std::string texto = argv[1];
    bool resultado = ehPalindromo(texto);

    std::cout << "Texto original:  " << texto << std::endl;
    std::cout << "Texto comparado: " << normalizar(texto) << std::endl;
    std::cout << (resultado ? "É palíndromo!" : "Não é palíndromo.") << std::endl;

    return resultado ? 0 : 1;
}
