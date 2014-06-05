avl-tree
========

This is a simple example of avl tree

Project description
===================

- Atividade: Desenvolva um software que implementa um diário de classes, utilizando uma Árvore AVL como estrutura de dados para guardar os dados da aplicação. A solução deve obedecer os seguintes requisitos:

Implemente, em uma biblioteca chamada AVL, o tipo abstrato de dados Árvore AVL, com alocação dinâmica de memória. Cada nó deve armazenar os dados de um aluno (Matrícula, Nome, 03 Notas de Prova). A biblioteca deve conter, além da estrutura de dados do TAD, as seguintes operações:
- Criar uma árvore AVL vazia
- Verificar se uma árvore está vazia ou não
- Inserir um novo elemento (a ordem de classificação dos nós é pelo número de matrícula do aluno)
- Remover um elemento, dado o seu valor
- Verificar se a uma árvore contém os dados de um aluno (i.e. busca pela matrícula), retornando o endereço do nó, caso encontrado, ou NULL, caso contrário.
- Exibir todos os valores de uma árvore em pré-ordem, em-ordem e pós-ordem.
- Esvaziar uma árvore

- O programa principal deve utilizar a biblioteca AVL criada no item 1 e fornecer as seguintes funcionalidades:
- Crie uma árvore AVL T.
- Exiba o seguinte menu de opções: 
EDITOR DO DIÁRIO DE CLASSES:
1 – INSERIR
2 – REMOVER
3 – PESQUISAR
4 – EXIBIR A ÁRVORE
5 – ESVAZIAR A ÁRVORE
6 – SAIR
DIGITE SUA OPÇÃO:
- Leia a opção do usuário.
- Execute a opção escolhida pelo usuário.
- Após a execução de cada opção, o programa deve retornar ao menu para nova opção do usuário ou o encerramento do programa.

Observações:

- Para impressão da árvore:
Cada nó deve ser impresso em uma linha separada, seguindo o formato "No = %d\tFB = %d\tPai = %d\tEsquerdo = %d\tDireito = %d\n". O "%d" indica o número de matrícula armazenado no respectivo nó e/ou o fator de balanceamento do nó.
Na opção exibir a árvore, deve-se perguntar qual é o percurso desejado, ou seja, pré-ordem, em-ordem e pós-ordem.
Esvaziar a árvore significa liberar toda a memória alocada para os nós da árvore.
Na busca, todos os dados do aluno devem ser impressos na tela.
Desenvolvimento: O exercício deverá ser desenvolvido em duplas. Como sugestão, façam duplas que misturem alunos do BSI com alunos dos outros cursos. O programa deve ser implementado usando a linguagem C e usar alocação dinâmica de memória para manipular a estrutura de dados. 
