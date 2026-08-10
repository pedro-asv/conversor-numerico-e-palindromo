-- palindromo.lua — Verifica se uma frase ou palavra é um palíndromo.
--
-- Uso:
--   lua5.4 palindromo.lua "Arara"
--   lua5.4 palindromo.lua "A base do teto desaba"

local function normalizar(texto)
    texto = texto:lower()
    -- gsub com o padrão "%a%d" mantém só letras e números (sintaxe de
    -- padrão do Lua, parecida com regex mas com sintaxe própria)
    local normalizado = texto:gsub("[^%a%d]", "")
    return normalizado
end

local function inverter(texto)
    return texto:reverse()
end

local function ehPalindromo(texto)
    local normalizado = normalizar(texto)
    return normalizado == inverter(normalizado)
end

local function main(arg)
    if #arg ~= 1 then
        print('Uso: lua5.4 palindromo.lua "texto a verificar"')
        os.exit(1)
    end

    local texto = arg[1]
    local resultado = ehPalindromo(texto)

    print("Texto original:  " .. texto)
    print("Texto comparado: " .. normalizar(texto))
    print(resultado and "É palíndromo!" or "Não é palíndromo.")

    os.exit(resultado and 0 or 1)
end

main(arg)
