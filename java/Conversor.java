import java.io.PrintStream;
import java.nio.charset.StandardCharsets;

public class Conversor {

    static long converterParaDecimal(String valorHex) {
        return Long.parseLong(valorHex, 16);
    }

    public static void main(String[] args) {
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
