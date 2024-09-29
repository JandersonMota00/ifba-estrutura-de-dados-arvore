# IFBA - Estrutura de Dados

- **Instituição:** IFBA - Instituto Federal da Bahia
- **Curso:** Análise e Desenvolvimento de Sistemas (ADS)
- **Disciplina:** Estrutura de Dados
- **Projeto:** Implementar a estrutura de dados da árvore binária.
- **Professor:** Felipe Gustavo de Souza Gomes
- **Semestre:** 3
- **Ano:** 2024.1

## Integrantes do Projeto

<table>
  <tr>
    <td align="center">
      <img src="https://avatars.githubusercontent.com/u/165097289?v=4" width="100px;" alt="Foto do Integrante Igor"/><br />
      <sub><b><a href="https://github.com/IgorCauanAl">Igor Cauan</a></b></sub>
    </td>
    <td align="center">
      <img src="https://avatars.githubusercontent.com/u/80362674?v=4" width="100px;" alt="Foto do Integrante Janderson"/><br />
      <sub><b><a href="https://github.com/JandersonMota">Janderson Mota</a></b></sub>
    </td>
    <td align="center">
      <img src="https://avatars.githubusercontent.com/u/157417082?v=4" width="100px;" alt="Foto do Integrante Saulo"/><br />
      <sub><b><a href="https://github.com/SaulinhoDevs">Saulo Melo</a></b></sub>
    </td>
  </tr>
</table>

## Descrição

Nesse trabalho vocês deverão implementar a estrutura de dados da árvore binária. Suponha que os nós da sua árvore seguem a seguinte estrutura:

```c
// Definição da estrutura do nó da árvore binária
typedef struct Node {
    float num;
    struct Node* left;
    struct Node* right;
} Node;
```

Não é obrigatório implementar o balanceamento da árvore. Quem tiver interesse em implementar o balanceamento pode dar uma olhada em árvores AVL ou árvores red-black (ou rubro-negra).

## Funcionalidades Implementadas

### 1. Inserção de nós na árvore
Nessa operação deverá ser lido um número e logo em seguida o valor deverá ser alocado na árvore. Caso o número já exista na árvore não inseri-lo novamente.
### 2. Remoção de nós na árvore
Nessa operação deverá ser lido um número a ser apagado da árvore.
### 3. Ver altura da árvore
Nessa função deverá ser mostrado um número que representa a altura da árvore.
### 4. Mostrar os elementos de um nível
Nessa operação deverá ser lido um número referente ao nível da árvore e logo em seguida deverá ser apresentado todos os elementos daquele nível da árvore.
### 5. Checar se árvore está balanceada ou não
Nessa função você deverá calcular a diferença absoluta da altura das subárvores da esquerda e da direita da árvore, caso a diferença seja 0 ou 1 retornar a mensagem “Árvore balanceada”, caso contrário retornar a mensagem “Árvore desbalanceada”.
### 6. Mostrar estatística da árvore
Nessa função deverão ser apresentados 3 valores como resultado: o maior valor da árvore, o menor valor da árvore e a média dos valores da árvore. O formato deverá ser o seguinte: `Maior: %.2f Menor: %.2f Média: %.2f`.
