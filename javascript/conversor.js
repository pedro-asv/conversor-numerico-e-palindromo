function converterHex(valorHex) {
    valorHex = valorHex.trim().toLowerCase().replace(/^0x/, "");

    const numeroDecimal = parseInt(valorHex, 16);

    if (Number.isNaN(numeroDecimal)) {
        throw new Error(`'${valorHex}' não é um hexadecimal válido.`);
    }

    return {
        decimal: numeroDecimal,
        binario: numeroDecimal.toString(2),
        octal: numeroDecimal.toString(8),
    };
}

function main() {
    const argumento = process.argv[2];

    if (!argumento) {
        console.log("Uso: node conversor.js <hexadecimal>");
        process.exit(1);
    }

    try {
        const resultado = converterHex(argumento);
        console.log(`Hexadecimal: ${argumento.toUpperCase()}`);
        console.log(`Decimal:     ${resultado.decimal}`);
        console.log(`Binário:     ${resultado.binario}`);
        console.log(`Octal:       ${resultado.octal}`);
    } catch (erro) {
        console.log(`Erro: ${erro.message}`);
        process.exit(1);
    }
}

main();
