📚 Implementação da Estrutura de Dados: Sequence (Sequência)
Sobre o Projeto

Este repositório contém a implementação da estrutura de dados Sequência em C++. A classe Sequence armazena elementos do tipo std::string e permite inserir e remover elementos em qualquer posição da lista. A implementação utiliza listas ligadas (linked list) simples.

O projeto é modularizado, separando a declaração da classe (Sequence.h) da implementação (Listsequence.cpp) e mantendo os testes (TestSequence.cpp) em um arquivo separado.

Tecnologias Utilizadas

Linguagem: C++

Contêiner: Lista Ligada (Node com ponteiros)

Compilador: g++ (GNU Compiler Collection)

🚀 Funcionalidades

A classe Sequence implementa operações básicas de uma sequência:

Método	Descrição
Sequence()	Construtor. Inicializa a sequência vazia.
insertBegin(string)	Insere um elemento no início da sequência.
insertEnd(string)	Insere um elemento no final da sequência.
insert(int i, string)	Insere um elemento na posição i da sequência.
removeBegin()	Remove o primeiro elemento e retorna seu valor.
removeEnd()	Remove o último elemento e retorna seu valor.
remove(int i)	Remove o elemento na posição i e retorna seu valor.
get(int i)	Retorna o elemento da posição i.
isEmpty()	Retorna true se a sequência estiver vazia.
getQuantity()	Retorna a quantidade de elementos na sequência.
print()	Mostra todos os elementos da sequência no terminal.
🛠️ Como Compilar e Executar

Para rodar este projeto, você precisa de um compilador C++ como o g++.

No terminal (PowerShell, CMD ou Bash), vá até a pasta do projeto e rode:

g++ Listsequence.cpp TestSequence.cpp -o test


Para executar o programa:

.\test.exe

Pré-requisitos

Compilador C++ (g++ ou equivalente)

Biblioteca C++ padrão (iostream, string, cassert)

Estrutura de Arquivos

O projeto é composto por quatro arquivos principais:

├── Node.h           # Declaração da classe Node
├── Sequence.h       # Declaração da classe Sequence
├── Listsequence.cpp # Implementação dos métodos da Sequence
└── TestSequence.cpp # Contém a função main() e os testes

1. Compilação (Build)

É necessário compilar e ligar todos os arquivos .cpp juntos para criar o executável:

g++ Listsequence.cpp TestSequence.cpp -o test


O comando cria um arquivo executável chamado test.exe.

2. Execução dos Testes

O executável roda todos os testes do professor, verificando se as operações de inserção e remoção funcionam corretamente.

.\test.exe


Saída Esperada:
Se todos os testes passarem, você verá algo como:

TestInsertBegin OK
TestInsertEnd OK
TestRemoveBegin OK
TestRemoveEnd OK
TestInsert OK
TestRemove OK
TestAll OK


Isso significa que a sequência está funcionando como esperado.



👥

Rafael Moura
Herick Bruno
Murillo Valdeger

