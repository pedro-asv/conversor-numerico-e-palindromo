<?php
function normalizar(string $texto): string
{
    return preg_replace('/[^a-z0-9]/', '', strtolower($texto));
}

function ehPalindromo(string $texto): bool
{
    $normalizado = normalizar($texto);
    return $normalizado === strrev($normalizado);
}

function main(array $argv): void
{
    if (count($argv) !== 2) {
        echo 'Uso: php palindromo.php "texto a verificar"' . PHP_EOL;
        exit(1);
    }

    $texto = $argv[1];
    $resultado = ehPalindromo($texto);

    echo "Texto original:  " . $texto . PHP_EOL;
    echo "Texto comparado: " . normalizar($texto) . PHP_EOL;
    echo ($resultado ? "É palíndromo!" : "Não é palíndromo.") . PHP_EOL;

    exit($resultado ? 0 : 1);
}

main($argv);
