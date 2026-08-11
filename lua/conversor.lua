local function paraBinario(numero)
    if numero == 0 then return "0" end
    local binario = ""
    while numero > 0 do
        binario = tostring(numero % 2) .. binario
        numero = numero // 2
    end
    return binario
end

local function paraOctal(numero)
    if numero == 0 then return "0" end
    local octal = ""
    while numero > 0 do
        octal = tostring(numero % 8) .. octal
        numero = numero // 8
    end
    return octal
end

local function main(arg)
    if #arg ~= 1 then
        print("Uso: lua5.4 conversor.lua <hexadecimal>")
        os.exit(1)
    end

    local entrada = arg[1]
    local valorHex = entrada:gsub("^0[xX]", "")

    local numeroDecimal = tonumber(valorHex, 16)

    if not numeroDecimal then
        print("Erro: '" .. entrada .. "' não é um hexadecimal válido.")
        os.exit(1)
    end

    print("Hexadecimal: " .. entrada:upper())
    print("Decimal:     " .. numeroDecimal)
    print("Binário:     " .. paraBinario(numeroDecimal))
    print("Octal:       " .. paraOctal(numeroDecimal))
end

main(arg)
