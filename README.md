# Sistema de Criptografia

Projeto feito para a disciplina de **Algoritmo e Pensamento Computacional**, com o objetivo de juntar os conteúdos que foram estudados durante as aulas em um único programa.

A ideia do projeto é criar um sistema de **criptografia simples**, usando Cifra de César, ASCII e algumas sequências matemáticas para fazer um segundo deslocamento nas letras.

## Como funciona

O programa funciona em duas camadas.

Na primeira camada, é usada a **Cifra de César**, onde o usuário escolhe um valor de SHIFT. Por exemplo, com SHIFT 3:

```text
A → D
B → E
C → F
```

Na segunda camada, o programa usa uma sequência matemática escolhida pelo usuário. O valor dessa sequência muda de acordo com a posição de cada letra.

A lógica usada é:

```text
Deslocamento = SHIFT + valor da sequência na posição
```

Então a palavra passa por uma transformação inicial e depois por outra usando os valores da sequência escolhida.

## O que o usuário pode escolher

Primeiro o usuário informa a palavra que deseja criptografar. A palavra pode ter no máximo 15 letras e não pode possuir acentos, números ou caracteres especiais.

Depois ele escolhe o valor do SHIFT, entre 1 e 25.

Por último, escolhe qual sequência deseja utilizar na segunda camada:

```text
1 - Progressão Aritmética (PA)
2 - Progressão Geométrica (PG)
3 - Números Primos
4 - Fibonacci
5 - Incremento em Progressão
```

Também existe a opção de voltar para o menu antes de continuar.

## Sequências utilizadas

### Progressão Aritmética (PA)

Na PA, cada termo é obtido somando uma razão ao termo anterior.

Por exemplo, usando razão 2:

```text
1, 3, 5, 7, 9, 11, 13...
```

A razão pode ser escolhida pelo usuário.

### Progressão Geométrica (PG)

Na PG, cada termo é obtido multiplicando o anterior por uma razão.

Por exemplo, usando razão 2:

```text
1, 2, 4, 8, 16, 32, 64...
```

A razão também pode ser escolhida pelo usuário.

### Números Primos

O programa procura os números primos e vai montando uma sequência com a quantidade necessária para a palavra.

Exemplo:

```text
2, 3, 5, 7, 11, 13, 17...
```

### Fibonacci

A sequência usada no projeto começa em:

```text
1, 1, 2, 3, 5, 8, 13...
```

Cada número é formado pela soma dos dois anteriores.

### Incremento em Progressão

Nessa opção, o incremento vai aumentando conforme a sequência avança.

Por exemplo, começando com incremento 1:

```text
1, 2, 4, 7, 11, 16...
```

Nesse caso, os incrementos utilizados vão sendo:

```text
+1, +2, +3, +4, +5...
```

## ASCII

Uma das partes utilizadas na criptografia é o ASCII.

As letras possuem valores numéricos e isso permite fazer os cálculos do deslocamento.

Por exemplo:

```text
A = 65
B = 66
C = 67
```

O programa usa esses valores para transformar as letras, aplicar o SHIFT e depois voltar para o caractere correspondente.

Também é feito o controle para que o deslocamento continue dentro do alfabeto. Assim, por exemplo:

```text
Z + 1 = A
z + 1 = a
```

## Arquivos

Depois que a palavra é criptografada, o programa salva o resultado em um arquivo chamado:

```text
resultado_criptografia.txt
```

Nele ficam informações como a palavra codificada, o SHIFT usado, o tipo de sequência e a quantidade de letras.

Além disso, o programa possui um arquivo de log:

```text
log_criptografia.txt
```

Nesse arquivo ficam registradas as execuções feitas pelo programa, como a palavra original, o SHIFT, o tipo de sequência e o resultado.

## Exemplo

Um exemplo de entrada seria:

```text
Palavra: Nicolas
SHIFT: 3
Sequência: Fibonacci
```

A palavra passa primeiro pela Cifra de César e depois recebe os deslocamentos da sequência escolhida.

No final, o programa mostra a palavra criptografada e salva as informações nos arquivos.

## O que foi usado no projeto

Durante a construção do projeto foram utilizados conteúdos como:

- linguagem C;
- ASCII;
- Cifra de César;
- `if`, `else` e estruturas de repetição;
- arrays;
- menus;
- manipulação de arquivos;
- Progressão Aritmética;
- Progressão Geométrica;
- números primos;
- Fibonacci;
- incremento em progressão.

Antes de fazer a versão em C, a lógica também foi testada em Python, principalmente para entender melhor o funcionamento das sequências e da criptografia.

## Objetivo do projeto

A ideia principal foi pegar conteúdos que parecem separados, como matemática, algoritmos e programação, e colocar tudo funcionando junto em um único sistema.

Além de fazer a criptografia funcionar, o projeto também permite escolher diferentes sequências e observar como cada uma delas altera o resultado final.

**Disciplina:** Algoritmo e Pensamento Computacional  
**Professor:** Francisco de Assis Cavallaro  
**Atividade:** Avaliativa – 02
