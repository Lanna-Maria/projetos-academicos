import pandas as pd
import numpy as np
from scipy.stats import zscore
from sklearn.preprocessing import MinMaxScaler

# Carregar o dataset
df = pd.read_csv('Lol.csv')

# =======================================================
# 1. Preencher valores ausentes com a média
# =======================================================
# Identificar colunas numéricas
cols_numericas = df.select_dtypes(include=[np.number]).columns

# Preencher valores ausentes com a média da respectiva coluna
df[cols_numericas] = df[cols_numericas].apply(lambda x: x.fillna(x.mean()))

# Verificar se ainda há valores ausentes
print("\nValores ausentes após preenchimento:")
print(df.isnull().sum())

# =======================================================
# 2. Remover Outliers utilizando Z-Score
# =======================================================
# Calcular Z-Score
z_scores = np.abs(zscore(df[cols_numericas]))  # Considera apenas colunas numéricas
outliers = (z_scores > 3)  # Z-Score maior que 3

# Remover linhas com outliers
df_sem_outliers = df[~outliers.any(axis=1)]

# Verificar as primeiras linhas do novo DataFrame sem outliers
print("\nPrimeiras linhas após remoção de outliers:")
print(df_sem_outliers.head())

# Estatísticas descritivas do DataFrame sem outliers
print("\nEstatísticas descritivas (sem outliers):")
print(df_sem_outliers.describe())

# =======================================================
# 3. Normalização (Min-Max Scaling)
# =======================================================
# Inicializar o MinMaxScaler
scaler = MinMaxScaler()

# Aplicar normalização
df_normalizado = df_sem_outliers.copy()
df_normalizado[cols_numericas] = scaler.fit_transform(df_sem_outliers[cols_numericas])

# Salvar o dataframe normalizado
df_normalizado.to_csv('dados_normalizados.csv', index=False)

# Verificar as primeiras linhas do novo DataFrame normalizado
print("\nPrimeiras linhas após normalização:")
print(df_normalizado.head())

# Estatísticas descritivas do DataFrame normalizado
print("\nEstatísticas descritivas (normalização):")
print(df_normalizado.describe())

# =======================================================
# 4. Verificação dos Resultados
# =======================================================
# Estatísticas descritivas do DataFrame original
print("\nEstatísticas descritivas (original):")
print(df.describe())

# Estatísticas descritivas do DataFrame normalizado
print("\nEstatísticas descritivas (normalizado):")
print(df_normalizado.describe())
