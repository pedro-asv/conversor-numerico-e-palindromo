import java.io.PrintStream;
import java.nio.charset.StandardCharsets;

public class Palindromo {

    static String normalizar(String texto) {
        StringBuilder resultado = new StringBuilder();
        for (char c : texto.toLowerCase().toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                resultado.append(c);
            }
        }
        return resultado.toString();
    }

    static boolean ehPalindromo(String texto) {
        String normalizado = normalizar(texto);
        String invertido = new StringBuilder(normalizado).reverse().toString();
        return normalizado.equals(invertido);
    }

    public static void main(String[] args) {
        System.setOut(new PrintStream(System.out, true, StandardCharsets.UTF_8));

        if (args.length != 1) {
            System.out.println("Uso: java Palindromo \"texto a verificar\"");
            System.exit(1);
        }

        String texto = args[0];
        boolean resultado = ehPalindromo(texto);

        System.out.println("Texto original:  " + texto);
        System.out.println("Texto comparado: " + normalizar(texto));
        System.out.println(resultado ? "É palíndromo!" : "Não é palíndromo.");

        System.exit(resultado ? 0 : 1);
    }
}
