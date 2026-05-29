# Discente: Lanna Maria Ibiapina da Silva Mesquita

import re
import tkinter as tk
from tkinter import ttk, messagebox

# Lexer (Analisador Léxico)
def lexer(expressao):
    """
    Função que transforma a expressão em uma lista de tokens.
    Tokens podem ser números, operadores (+, -, *, /) ou parênteses.
    """
    tokens = []
    especificacao_tokens = [
        ('NUMERO',   r'\d+(\.\d*)?'),
        ('OPERADOR', r'[+\-*/]'),
        ('PARENTESE', r'[()]'),
        ('IGNORAR',  r'[ \t]'),
        ('ERRO',     r'.'),
    ]
    regex_tokens = '|'.join(f'(?P<{nome}>{padrao})' for nome, padrao in especificacao_tokens)
    
    for correspondencia in re.finditer(regex_tokens, expressao):
        tipo = correspondencia.lastgroup
        valor = correspondencia.group()
        if tipo == 'NUMERO':
            valor = float(valor) if '.' in valor else int(valor)
        elif tipo == 'IGNORAR':
            continue
        elif tipo == 'ERRO':
            raise RuntimeError(f'Caractere inesperado: {valor}')
        tokens.append((tipo, valor))
    return tokens

# Função para exibir a tabela de tokens
def exibir_tabela_tokens(tokens, treeview):
    """
    Exibe a tabela de tokens no Treeview, formatando os operadores e parênteses.
    """
    # Limpa os dados antigos na tabela
    for row in treeview.get_children():
        treeview.delete(row)

    # Mapeamento de operadores para exibição
    operadores_extensos = {
        '+': 'SOMA',
        '-': 'SUBTRAÇÃO',
        '*': 'MULTIPLICAÇÃO',
        '/': 'DIVISÃO'
    }

    # Insere os tokens formatados na tabela
    for token in tokens:
        tipo, valor = token

        if tipo == 'OPERADOR':
            tipo_exibicao = 'OPERADOR'
            valor_exibicao = operadores_extensos.get(valor, valor)  # Converte para o nome extenso

        elif tipo == 'PARENTESE':
            if valor == '(':
                tipo_exibicao = "PARENTESE ABERTO"
            elif valor == ')':
                tipo_exibicao = "PARENTESE FECHADO"
            valor_exibicao = valor  

        else:
            tipo_exibicao = "NÚMERO" if tipo == 'NUMERO' else tipo
            valor_exibicao = valor

        # Adiciona ao Treeview
        treeview.insert("", "end", values=(valor, tipo_exibicao, valor_exibicao))


# Parser (Analisador Sintático)
def parser(tokens):
    """
    Converte a lista de tokens em uma árvore sintática (AST).
    """
    def parse_expressao(indice):
        no, indice = parse_termo(indice)
        while indice < len(tokens) and tokens[indice][1] in ('+', '-'):
            operador = tokens[indice][1]
            no_direita, indice = parse_termo(indice + 1)
            no = (operador, no, no_direita)
        return no, indice

    def parse_termo(indice):
        no, indice = parse_fator(indice)
        while indice < len(tokens) and tokens[indice][1] in ('*', '/'):
            operador = tokens[indice][1]
            no_direita, indice = parse_fator(indice + 1)
            no = (operador, no, no_direita)
        return no, indice

    def parse_fator(indice):
        token = tokens[indice]
        if token[0] == 'NUMERO':
            return token[1], indice + 1
        elif token[1] == '(':
            no, indice = parse_expressao(indice + 1)
            if tokens[indice][1] != ')':
                raise RuntimeError('Esperado parêntese de fechamento')
            return no, indice + 1
        else:
            raise RuntimeError(f'Token inesperado: {token[1]}')

    ast, _ = parse_expressao(0)
    return ast

# Avaliação da Expressão
def avaliar(ast):
    """
    Avalia a árvore sintática (AST) e retorna o resultado da expressão.
    """
    if isinstance(ast, (int, float)):
        return ast
    operador, esquerda, direita = ast
    if operador == '+':
        return avaliar(esquerda) + avaliar(direita)
    elif operador == '-':
        return avaliar(esquerda) - avaliar(direita)
    elif operador == '*':
        return avaliar(esquerda) * avaliar(direita)
    elif operador == '/':
        return avaliar(esquerda) / avaliar(direita)

# Função para ler a expressão de um arquivo TXT
def ler_expressao_arquivo(nome_arquivo):
    """
    Lê a expressão de um arquivo TXT.
    """
    try:
        with open(nome_arquivo, 'r') as arquivo:
            return arquivo.read().strip()
    except FileNotFoundError:
        raise RuntimeError(f"Arquivo '{nome_arquivo}' não encontrado.")
    except Exception as e:
        raise RuntimeError(f"Erro ao ler o arquivo: {e}")

# Função principal para compilar a expressão
def compilar_expressao(treeview, label_resultado):
    """
    Coordena o processo de compilação:
    1. Lê a expressão do arquivo TXT.
    2. Análise léxica.
    3. Análise sintática.
    4. Avaliação da expressão.
    """
    try:
        expressao = ler_expressao_arquivo("teste.txt")
        tokens = lexer(expressao)
        exibir_tabela_tokens(tokens, treeview)
        ast = parser(tokens)
        resultado = avaliar(ast)
        label_resultado.config(text=f'Resultado: {resultado}')
    except Exception as e:
        messagebox.showerror("Erro", str(e))

# Interface Gráfica
def criar_interface():
    """
    Cria a interface gráfica usando Tkinter.
    """
    janela = tk.Tk()
    janela.title("Compilador de Expressões Aritméticas")
    janela.geometry("500x400")

    botao_compilar = tk.Button(janela, text="Compilar", command=lambda: compilar_expressao(
        treeview_tokens, label_resultado
    ))
    botao_compilar.pack(pady=10)

    colunas = ("TOKEN", "TIPO", "VALOR")
    treeview_tokens = ttk.Treeview(janela, columns=colunas, show="headings")
    for coluna in colunas:
        treeview_tokens.heading(coluna, text=coluna)
    treeview_tokens.pack(pady=10)

    label_resultado = tk.Label(janela, text="Resultado: ")
    label_resultado.pack(pady=10)

    janela.mainloop()

# Inicia a interface gráfica
if __name__ == "__main__":
    criar_interface()
