/**
 * palindromo.js — Verifica se uma frase ou palavra é um palíndromo.
 *
 * Ignora maiúsculas/minúsculas, espaços e pontuação.
 *
 * Uso:
 *   node palindromo.js "Arara"
 *   node palindromo.js "A base do teto desaba"
 */

function normalizar(texto) {
    return texto.toLowerCase().replace(/[^a-z0-9]/g, "");
}

function ehPalindromo(texto) {
    const normalizado = normalizar(texto);
    // JavaScript não tem um jeito nativo de inverter string —
    // por isso o split/reverse/join, diferente do [::-1] do Python
    const invertido = normalizado.split("").reverse().join("");
    return normalizado === invertido;
}

function main() {
    const texto = process.argv[2];

    if (!texto) {
        console.log('Uso: node palindromo.js "texto a verificar"');
        process.exit(1);
    }

    const resultado = ehPalindromo(texto);

    console.log(`Texto original:  ${texto}`);
    console.log(`Texto comparado: ${normalizar(texto)}`);
    console.log(resultado ? "É palíndromo!" : "Não é palíndromo.");

    process.exit(resultado ? 0 : 1);
}

main();
