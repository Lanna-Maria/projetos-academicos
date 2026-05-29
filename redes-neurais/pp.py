# 1. Importar bibliotecas
import pandas as pd
# pandas é uma biblioteca para manipulação e análise de dados.
# Facilita o trabalho com tabelas, chamadas DataFrames, que são estruturas
# semelhantes a planilhas do Excel. Muito usada para carregar arquivos CSV,
# limpar dados e fazer operações como filtrar, agrupar e transformar dados.

from sklearn.model_selection import train_test_split
# sklearn (scikit-learn) é uma biblioteca de machine learning.
# O módulo train_test_split serve para dividir os dados em conjuntos de treino
# e teste de forma aleatória e prática, essencial para avaliar modelos
# corretamente e evitar "vazamento" de dados entre treino e teste.

from sklearn.feature_extraction.text import TfidfVectorizer
# Também do scikit-learn, o TfidfVectorizer transforma textos em vetores numéricos
# baseados na frequência de termos. TF-IDF significa Term Frequency-Inverse Document Frequency,
# que ajuda a dar mais peso a palavras importantes e menos peso a palavras comuns
# (como "de", "a", "o").

import numpy as np
# NumPy é a principal biblioteca para computação numérica em Python.
# Facilita operações matemáticas e manipulação de arrays/matrizes de forma rápida e eficiente,
# essencial para o cálculo dentro dos modelos de machine learning e deep learning.


# 2. Carregar o dataset
df = pd.read_csv('spam.csv', encoding='latin-1')[['Category', 'Message']]
# Lê o arquivo CSV chamado 'spam.csv', usando a codificação 'latin-1' para evitar problemas com caracteres.
# Seleciona só as colunas 'Category' (rótulo da mensagem) e 'Message' (texto da mensagem).

# 3. Normalização dos rótulos
df['Category'] = df['Category'].map({'ham': 0, 'spam': 1})
# Converte os rótulos de texto ('ham' = mensagem normal, 'spam' = mensagem indesejada)
# em valores numéricos binários 0 e 1 para facilitar o treinamento do modelo.

# 4. Remover mensagens vazias
df = df[df['Message'].str.strip().astype(bool)]
# Remove linhas onde a mensagem está vazia ou contém só espaços.
# str.strip() tira espaços antes e depois, e astype(bool) converte em True/False para filtragem.

# 5. Verificar e mostrar dados faltantes
print("Dados faltantes:\n", df.isnull().sum())
# Checa se há valores faltantes (NaN) nas colunas do DataFrame e imprime a contagem.
# Isso ajuda a garantir que o dataset está limpo.

# 6. Separar variáveis independentes e alvo
X = df['Message']   # Texto das mensagens, que serão as variáveis de entrada (features)
y = df['Category']  # Rótulo binário 0/1, que é o alvo (target) a ser previsto

# 7. Divisão treino/teste
X_text_train, X_text_test, y_train, y_test = train_test_split(
    X,
    y,
    test_size=0.2,    # Usa 20% dos dados para teste, 80% para treino
    random_state=42,  # Define uma semente para garantir que a divisão seja sempre a mesma (reprodutível)
    stratify=y        # Mantém a proporção dos rótulos igual em treino e teste (balanceamento)
)

# 8. Vetorização com TF-IDF
vectorizer = TfidfVectorizer()
X_train = vectorizer.fit_transform(X_text_train).toarray()
# Ajusta o vetor TF-IDF aos textos de treino (aprende o vocabulário e pesos)
# e transforma as mensagens em vetores numéricos, que são convertidos para array.

X_test = vectorizer.transform(X_text_test).toarray()
# Transforma os textos de teste em vetores numéricos usando o vocabulário já aprendido,
# sem ajustar novamente para evitar vazamento de dados.

# 9. Salvar os conjuntos separados
pd.DataFrame(X_train).to_csv("X_train.csv", index=False)
pd.DataFrame(X_test).to_csv("X_test.csv", index=False)
pd.DataFrame(y_train).to_csv("y_train.csv", index=False)
pd.DataFrame(y_test).to_csv("y_test.csv", index=False)
# Salva os vetores numéricos e os rótulos para treino e teste em arquivos CSV separados,
# facilitando a reutilização posterior sem precisar repetir o pré-processamento.

print("📁 Conjuntos vetorizados salvos: X_train.csv, X_test.csv, y_train.csv, y_test.csv")

# 10. (Opcional) Salvar o dataset completo também, se quiser manter
df.to_csv("spam_pre_processado.csv", index=False)
# Salva o dataset já limpo e com rótulos numéricos em um CSV para referência futura.

print("📁 Dataset completo também salvo como 'spam_pre_processado.csv'")
