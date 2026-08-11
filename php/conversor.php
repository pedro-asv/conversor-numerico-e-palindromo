<?php
function converterHex(string $valorHex): array
{
    $valorHex = preg_replace('/^0x/i', '', trim($valorHex));

    if (!ctype_xdigit($valorHex) || $valorHex === '') {
        throw new InvalidArgumentException("'{$valorHex}' não é um hexadecimal válido.");
    }

    $numeroDecimal = hexdec($valorHex);

    return [
        'decimal' => $numeroDecimal,
        'binario' => decbin($numeroDecimal),
        'octal'   => decoct($numeroDecimal),
    ];
}

function main(array $argv): void
{
    if (count($argv) !== 2) {
        echo "Uso: php conversor.php <hexadecimal>" . PHP_EOL;
        exit(1);
    }

    try {
        $resultado = converterHex($argv[1]);
    } catch (InvalidArgumentException $e) {
        echo "Erro: " . $e->getMessage() . PHP_EOL;
        exit(1);
    }

    echo "Hexadecimal: " . strtoupper($argv[1]) . PHP_EOL;
    echo "Decimal:     " . $resultado['decimal'] . PHP_EOL;
    echo "Binário:     " . $resultado['binario'] . PHP_EOL;
    echo "Octal:       " . $resultado['octal'] . PHP_EOL;
}

main($argv);
