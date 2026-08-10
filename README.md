# 🔢 Conversor Numérico e Verificador de Palíndromo — Multilinguagem

Dois exercícios clássicos (conversão de base numérica e checagem de
palíndromo), implementados em **8 linguagens diferentes**, com o mesmo
comportamento e contrato de entrada/saída em todas elas — pra comparar,
na prática, como cada linguagem resolve o mesmo problema.

## Linguagens

| Linguagem | Pasta | Como rodar |
|---|---|---|
| C | `c/` | `gcc -o conversor conversor.c && ./conversor 1A3F` |
| C++ | `cpp/` | `g++ -o conversor conversor.cpp && ./conversor 1A3F` |
| C# | `csharp/` | `mcs Conversor.cs -out:Conversor.exe && mono Conversor.exe 1A3F` |
| Java | `java/` | `javac -encoding UTF-8 Conversor.java && java Conversor 1A3F` |
| Python | `python/` | `python3 conversor.py 1A3F` |
| JavaScript (Node) | `javascript/` | `node conversor.js 1A3F` |
| PHP | `php/` | `php conversor.php 1A3F` |
| Lua | `lua/` | `lua5.4 conversor.lua 1A3F` |

(troque `Conversor`/`conversor` por `Palindromo`/`palindromo` pro segundo programa)

## O que cada programa faz

**Conversor** — recebe um número em hexadecimal (com ou sem prefixo `0x`)
e mostra o mesmo valor em decimal, binário e octal.

**Palíndromo** — recebe uma palavra ou frase e verifica se ela é um
palíndromo, ignorando maiúsculas/minúsculas, espaços e pontuação (então
reconhece frases como *"A base do teto desaba"*, não só palavras soltas).

Todos os 7 programas seguem o mesmo padrão: recebem entrada via linha de
comando (não interativa), e retornam um **exit code** (0 = sucesso,
1 = erro ou "não é palíndromo") — o que permite usá-los dentro de scripts
maiores, não só rodar e ler a tela.

## O que reparei comparando as linguagens

- **Tratamento de entrada inválida** muda bastante entre elas: Python
  (`int(x, 16)`) e Java/C# lançam exceção automaticamente se a string não
  for um hexadecimal válido. JavaScript (`parseInt`) não lança nada — ele
  silenciosamente retorna `NaN`, e é preciso checar isso manualmente. Lua
  segue o mesmo caminho: `tonumber` retorna `nil` em vez de erro.
- **Inverter uma string** é trivial em Python (`texto[::-1]`) e Lua
  (`texto:reverse()`), mas em JavaScript exige
  `split("").reverse().join("")`, e em C++/Java não existe um método
  pronto — usei `std::reverse` (C++) e `StringBuilder.reverse()` (Java).
- **C não tem `std::string`.** É a diferença mais marcante em relação ao
  C++: em C, toda string é um array de `char` de tamanho fixo, e é
  responsabilidade minha garantir que o buffer é grande o suficiente e
  terminar a string manualmente com `'\0'`. Em C++, `std::string`
  cresce sozinha e cuida disso por trás dos panos — é o tipo de detalhe
  que fica invisível até você programar sem essa camada de segurança.
- **C++ não tem conversão nativa pra binário/octal como string** — as
  outras linguagens têm função pronta (`bin()`, `toString(2)`,
  `decbin()`, etc.); em C++ tive que implementar a conversão dígito a
  dígito manualmente. Em C, o mesmo problema existe, só que sem sequer
  o `std::bitset` do C++ pra ajudar — tudo é feito na mão, dígito a dígito.
- **Encoding de acentos foi o bug mais chato de todos.** Rodando os
  programas de C# e Java, os acentos ("Binário", "É palíndromo") saíam
  corrompidos no terminal — não por erro de lógica, mas porque essas duas
  linguagens/runtimes dependem da configuração de encoding do sistema
  operacional pra saída de console, enquanto Python/JS/PHP/Lua escrevem
  UTF-8 direto, sem depender disso. Corrigi forçando `UTF-8` explicitamente
  no código (`Console.OutputEncoding` em C#, `System.setOut(...)` em Java)
  em vez de confiar na configuração de quem for rodar — é um problema real
  que aparece bastante em máquina Windows com Java/C#.

## Testes

Todos os 7 programas foram testados com a mesma entrada (`1A3F` → decimal
`6719`, binário `1101000111111`, octal `15077`; e a frase
`"A base do teto desaba"` como palíndromo válido) e produziram
exatamente o mesmo resultado, incluindo os exit codes.

## Autor

**Pedro Augusto** — Desenvolvedor Full-Stack Júnior
[LinkedIn](https://linkedin.com/in/pedro-augusto-4103b6258) · [GitHub](https://github.com/pedro-asv)
