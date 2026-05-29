💎 Gerador de Losango em C

Este programa em C desenha um losango (*) no terminal com base em um tamanho informado pelo usuário. Ele utiliza laços de repetição para construir as metades superior e inferior da figura, de forma simétrica e centralizada.

---

🧠 Descrição do Programa

O programa solicita ao usuário o tamanho do losango (um número inteiro positivo) e, em seguida, imprime o losango correspondente utilizando asteriscos *.

A função principal é losango(int l), que recebe como parâmetro o tamanho desejado e é responsável por:

Gerar a metade superior do losango (do topo até o meio).

Gerar a metade inferior (do meio até a base).

Alinhar corretamente os espaços e os asteriscos para formar a figura centralizada.

---

⚙️ Estrutura do Código
Funções
void losango(int l)

Responsável por desenhar o losango.
Utiliza três variáveis de controle:

i → controla as linhas;

j → imprime os espaços em branco antes dos asteriscos;

k → imprime os asteriscos.

A lógica é dividida em duas partes:

Metade superior: cresce de 1 até l linhas.

Metade inferior: decresce de l-1 até 1 linha.

int main()

Define a localidade para português com setlocale(LC_ALL, "Portuguese");

Solicita ao usuário o tamanho do losango.

Chama a função losango(res) para desenhar a figura.

---

💻 Exemplo de Execução

```bash
Digite o tamanho do losango: 4

   *
  ***
 *****
*******
 *****
  ***
   *

```

---

🧩 Como Compilar e Executar
No Linux ou macOS:

```bash
gcc losango.c -o losango
./losango

```

---

No Windows (com MinGW):

```bash
gcc losango.c -o losango.exe
losango.exe
```

---

📄 Requisitos

Compilador C (como GCC ou Clang)

Console/terminal compatível com saída de texto padrão

---

✨ Autora

Desenvolvido por Lanna Maria
📘 Projeto Acadêmico em linguagem C para a disciplina da computação gráfica — Estruturas de repetição e formatação de saída.


