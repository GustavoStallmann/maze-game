![Group 1](https://github.com/user-attachments/assets/f8a00b0c-8878-4786-ac7d-7ed08d333baa)
# Maze Game Auto Solving

Este projeto foi desenvolvido por mim durante a disciplina de **Estrutura de Dados 1**. O objetivo era implementar um algoritmo que pudesse ler a planta de um labirinto a partir de uma entrada e encontrar sua solução de forma autônoma.

## Descrição

Este projeto foi implementado com suporte gráfico utilizando a biblioteca [Raylib](https://www.raylib.com/), permitindo que o labirinto e sua solução sejam exibidos de maneira interativa.

## Tecnologias Utilizadas

* **C**: Linguagem principal do projeto.
* **Raylib**: Biblioteca utilizada para a renderização gráfica do labirinto.
* **Makefile**: Para gerenciamento de build e execução do projeto.

## Como Rodar

Certifique-se de ter o Raylib instalado no seu sistema. Consulte a [documentação oficial do Raylib](https://www.raylib.com/).

Clone o repositório ou baixe os arquivos do projeto:
```bash
git clone <URL_DO_REPOSITORIO>
cd <PASTA_DO_PROJETO>
```

Compile o projeto com:
```bash
make
```
Execute o programa com:
```bash
make run < labirinto.txt
```

O programa irá carregar o labirinto da entrada fornecida e exibir a solução graficamente.

## Recursos Adicionais
* **Visualização Gráfica**: O algoritmo mostra, em tempo real, o caminho sendo traçado para a solução do labirinto.
* **Customização de Labirintos**: Você pode fornecer diferentes configurações de labirinto editando o arquivo de entrada.
