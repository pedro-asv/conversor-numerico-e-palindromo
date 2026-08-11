using System;
using System.Linq;

class Palindromo
{
    static string Normalizar(string texto)
    {
        return new string(texto.ToLower().Where(char.IsLetterOrDigit).ToArray());
    }

    static bool EhPalindromo(string texto)
    {
        string normalizado = Normalizar(texto);
        char[] invertidoArray = normalizado.ToCharArray();
        Array.Reverse(invertidoArray);
        string invertido = new string(invertidoArray);
        return normalizado == invertido;
    }

    static void Main(string[] args)
    {
        Console.OutputEncoding = new System.Text.UTF8Encoding(false);

        if (args.Length != 1)
        {
            Console.WriteLine("Uso: Palindromo.exe \"texto a verificar\"");
            Environment.Exit(1);
        }

        string texto = args[0];
        bool resultado = EhPalindromo(texto);

        Console.WriteLine($"Texto original:  {texto}");
        Console.WriteLine($"Texto comparado: {Normalizar(texto)}");
        Console.WriteLine(resultado ? "É palíndromo!" : "Não é palíndromo.");

        Environment.Exit(resultado ? 0 : 1);
    }
}
