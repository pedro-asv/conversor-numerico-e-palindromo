using System;

class Conversor
{
    static string ParaBinario(long numero)
    {
        if (numero == 0) return "0";
        return Convert.ToString(numero, 2);
    }

    static string ParaOctal(long numero)
    {
        if (numero == 0) return "0";
        return Convert.ToString(numero, 8);
    }

    static void Main(string[] args)
    {
        Console.OutputEncoding = new System.Text.UTF8Encoding(false);

        if (args.Length != 1)
        {
            Console.WriteLine("Uso: Conversor.exe <hexadecimal>");
            Environment.Exit(1);
        }

        string entrada = args[0];
        string valorHex = entrada.Trim();
        if (valorHex.StartsWith("0x", StringComparison.OrdinalIgnoreCase))
        {
            valorHex = valorHex.Substring(2);
        }

        long numeroDecimal;
        try
        {
            numeroDecimal = Convert.ToInt64(valorHex, 16);
        }
        catch (FormatException)
        {
            Console.WriteLine($"Erro: '{entrada}' não é um hexadecimal válido.");
            Environment.Exit(1);
            return;
        }

        Console.WriteLine($"Hexadecimal: {entrada.ToUpper()}");
        Console.WriteLine($"Decimal:     {numeroDecimal}");
        Console.WriteLine($"Binário:     {ParaBinario(numeroDecimal)}");
        Console.WriteLine($"Octal:       {ParaOctal(numeroDecimal)}");
    }
}
