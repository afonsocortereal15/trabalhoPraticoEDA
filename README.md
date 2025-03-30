# Trabalho Prático - Estruturas de Dados Avançadas

Este projeto implementa um sistema de matriz esparsa que representa dados como caracteres numa grelha 2D. O sistema armazena de forma eficiente apenas as células não vazias numa estrutura de lista ligada.

## Funcionalidades

- **Implementação de Matriz Esparsa**: Utiliza listas ligadas para armazenar eficientemente células não vazias da matriz
- **Inserção de Caracteres**: Adiciona caracteres em coordenadas específicas na matriz
- **Remoção de Caracteres**: Substitui caracteres por "." em posições específicas ou em todas as ocorrências
- **Cálculo de Interferência**: Calcula pontos de interferência entre pares do mesmo caractere
- **Entrada por Ficheiro**: Carrega dados da matriz a partir de ficheiros de entrada

## Estrutura

O projeto está organizado em vários módulos:

- `input.c/h`: Gere a criação da matriz, gestão de nós e carregamento de ficheiros
- `insert.c/h`: Funções para inserir caracteres em posições específicas
- `remove.c/h`: Funções para substituir caracteres por "."
- `calculate.c/h`: Implementa o algoritmo de cálculo das coordenadas de interferência
- `matrix.h`: Define funções para exibição e processamento da matriz
- `main.c`: Demonstração da funcionalidade do sistema

## Utilização

1. Crie um ficheiro de entrada com os dados da matriz (ver `input.txt` para o formato)
2. Compile o projeto: `gcc -o main *.c`
3. Execute o programa: `./main`

Ou execute o comando: `gcc -o build/main src/calculate.c src/input.c src/insert.c src/remove.c main.c -I include/ && ./build/main`

## Exemplo

O programa lê uma matriz a partir de `input.txt`, onde cada caractere representa dados em coordenadas específicas. Em seguida, processa pares do mesmo caractere para calcular pontos de interferência, que são marcados com caracteres `#`. O programa também pode remover caracteres e adicionar novos em posições específicas.

## Autor

Afonso Corte-Real (<a31500@alunos.ipca.pt>)
