/**
 * Conversor.java — Converte um número hexadecimal para decimal, binário e octal.
 *
 * Compilar: javac Conversor.java
 * Uso:      java Conversor <hexadecimal>
 *           java Conversor 1A3F
 */

import java.io.PrintStream;
import java.nio.charset.StandardCharsets;

public class Conversor {

    static long converterParaDecimal(String valorHex) {
        // Long.parseLong com base 16 lança NumberFormatException se
        // algum caractere não for hexadecimal válido
        return Long.parseLong(valorHex, 16);
    }

    public static void main(String[] args) {
        // Força saída em UTF-8 — sem isso, acentos aparecem corrompidos em
        // terminais/sistemas que não usam UTF-8 por padrão (comum no Windows)
        System.setOut(new PrintStream(System.out, true, StandardCharsets.UTF_8));

        if (args.length != 1) {
            System.out.println("Uso: java Conversor <hexadecimal>");
            System.exit(1);
        }

        String entrada = args[0];
        String valorHex = entrada.trim();
        if (valorHex.toLowerCase().startsWith("0x")) {
            valorHex = valorHex.substring(2);
        }

        long numeroDecimal;
        try {
            numeroDecimal = converterParaDecimal(valorHex);
        } catch (NumberFormatException e) {
            System.out.println("Erro: '" + entrada + "' não é um hexadecimal válido.");
            System.exit(1);
            return;
        }

        System.out.println("Hexadecimal: " + entrada.toUpperCase());
        System.out.println("Decimal:     " + numeroDecimal);
        System.out.println("Binário:     " + Long.toBinaryString(numeroDecimal));
        System.out.println("Octal:       " + Long.toOctalString(numeroDecimal));
    }
}
