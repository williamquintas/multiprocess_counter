# Contando letras A usando multiprocessos

Esta tarefa consiste em receber um texto na entrada e contar quantas letras `a`
ou `A` (o sistema é case-insensitive!) existem nessa entrada. Porém, trata-se de
um exercício de programação, e não somente de uma solução com algoritmo.

**O objetivo desta tarefa é fazer o sistema operar como multi-processos,
usando a instrução `fork()`.**

As soluções deverão ser estruturadas de forma que:

1. cada linha seja analisada por
um processo independente.
1. Os processo deverão (ao menos potencialmente) poder
executar em paralelo.
1. O programa deverá assumir um **número máximo de processos paralelos** igual a
`4`.
1. Todos os processos devem encerrar *antes* do fim do programa principal

Soluções que não contemplem esses três requisitos não serão aceitas. Eles serão
verificados manualmente, caso a caso.

## Exemplos

Entrada | Saida
------- | -----
`Teste\n` | `0\n`
`a\n` | `1\n`
`a\nA\n` | `2\n` (operando em dois processos)
`a\nA\nTeste\n` | `2\n` (operando em três processos)


## Instruções adicionais

1. Vá diretamente ao conjunto de testes para verificar como tratar casos
   limítrofes ou mal-definidos.
1. Lembre-se de seguir as [instruções de submissão](docs/instrucoes.md).
1. Se desejar, proponha novos casos de teste.
