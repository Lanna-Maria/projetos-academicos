# 🧮 Compilador de Expressões Aritméticas com Interface Gráfica

Este projeto foi desenvolvido por **Lanna** para a disciplina de **Compiladores**, do curso de **Bacharelado em Ciência da Computação**.

Ele simula um compilador simples capaz de realizar a **análise léxica**, **análise sintática** e a **avaliação de expressões aritméticas**, utilizando **Python** com interface gráfica em **Tkinter**.

## ✨ Funcionalidades

- Leitura de expressões aritméticas a partir de um arquivo `.txt`
- Tokenização de números, operadores e parênteses
- Construção de uma Árvore Sintática (AST)
- Avaliação da expressão com base na árvore
- Interface gráfica amigável com exibição da tabela de tokens e resultado final

## 📂 Estrutura esperada

O programa lê expressões do arquivo `teste.txt`. Exemplo de conteúdo:

```
(8 + 2) * 5 - 3 / 1
```

## 🖥️ Interface

A interface gráfica apresenta:

- Um botão **"Compilar"** que processa a expressão
- Uma **tabela** com os tokens e seus respectivos tipos
- Um **rótulo** exibindo o resultado da expressão

## ▶️ Como executar

1. Certifique-se de ter o **Python 3** instalado.

2. Clone o repositório:

```bash
gh repo clone Lanna-Maria/compilador-expressao-aritmetica-tkinter
cd compilador-expressao-aritmetica-tkinter
```

3. (Opcional) Crie um ambiente virtual:

```bash
python -m venv venv
source venv/bin/activate  # Linux/macOS
venv\Scripts\activate   # Windows
```

4. Instale a biblioteca Tkinter, se necessário (já incluída por padrão em muitas instalações do Python):

```bash
pip install tk
```

5. Crie um arquivo chamado `teste.txt` com a expressão que deseja compilar.

6. Execute o programa:

```bash
python quest2.py
```

> Uma interface será aberta exibindo os tokens e o resultado.

## 🛠 Tecnologias utilizadas

- Python 3
- Tkinter (GUI)
- Expressões regulares (`re`)

## 📌 Observações

- Certifique-se de que o arquivo `teste.txt` esteja na **mesma pasta** que o código.
- O analisador léxico lança erro ao encontrar caracteres inválidos.
- O parser requer parênteses corretamente balanceados e expressões válidas.

## 📄 Licença

Este projeto está sob a licença MIT. Sinta-se à vontade para usar, modificar e distribuir.

---

🎓 Desenvolvido com fins acadêmicos por **Lanna**.
