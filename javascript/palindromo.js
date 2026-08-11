function normalizar(texto) {
    return texto.toLowerCase().replace(/[^a-z0-9]/g, "");
}

function ehPalindromo(texto) {
    const normalizado = normalizar(texto);
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
