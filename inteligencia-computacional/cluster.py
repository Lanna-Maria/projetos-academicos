import os
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import MiniBatchKMeans
from sklearn.decomposition import PCA
from sklearn.metrics import silhouette_score, silhouette_samples
from sklearn.manifold import TSNE  # Importar o t-SNE para redução de dimensionalidade

# 📂 Carregar o dataset pré-processado
file_path = "dados_normalizados.csv"  # Substitua pelo caminho correto

if not os.path.exists(file_path):
    raise FileNotFoundError(f"Arquivo não encontrado: {file_path}")

df = pd.read_csv(file_path)

# 🔍 Selecionar colunas numéricas (já normalizadas)
colunas_numericas = [
    'blueGold', 'blueMinionsKilled', 'blueJungleMinionsKilled', 'blueAvgLevel',
    'redGold', 'redMinionsKilled', 'redJungleMinionsKilled', 'redAvgLevel',
    'blueChampKills', 'blueHeraldKills', 'blueDragonKills', 'blueTowersDestroyed',
    'redChampKills', 'redHeraldKills', 'redDragonKills', 'redTowersDestroyed'
]
X = df[colunas_numericas]

# 🔍 Método do cotovelo para encontrar o número ideal de clusters (somente para K-Means)
inertia = []
K_range = range(2, 11)  # Testar de 2 a 10 clusters (k=1 não faz sentido para Silhouette)

for k in K_range:
    kmeans = MiniBatchKMeans(n_clusters=k, random_state=42, batch_size=1024)
    kmeans.fit(X)  # Treinando nos dados completos
    inertia.append(kmeans.inertia_)

# 📉 Plotar o método do cotovelo
plt.figure(figsize=(8, 5))
plt.plot(K_range, inertia, 'bo-', markerfacecolor='red')
plt.xlabel('Número de Clusters (k)')
plt.ylabel('Inércia')
plt.title('Método do Cotovelo para Escolha de k (K-Means)')
plt.grid(True)
plt.show()

# 🔍 Escolher o número de clusters com base no gráfico (por exemplo, k=3)
k = 3
kmeans = MiniBatchKMeans(n_clusters=k, random_state=42, batch_size=1024)
df['Cluster_KMeans'] = kmeans.fit_predict(X)  # Treinando nos dados completos

# 🔍 Calcular o Silhouette Score para K-Means
silhouette_avg = silhouette_score(X, df['Cluster_KMeans'])  # Calculando nos dados completos
print(f"Silhouette Score para K-Means (k={k}): {silhouette_avg:.2f}")

# 🔍 Gráfico da Silhueta para K-Means
silhouette_values = silhouette_samples(X, df['Cluster_KMeans'])  # Coeficientes de silhueta para os dados completos

plt.figure(figsize=(8, 6))
y_lower = 10  # Espaço entre os clusters no gráfico

for i in range(k):
    # Agrupar os coeficientes de silhueta para o cluster i e ordená-los
    cluster_silhouette_values = silhouette_values[df['Cluster_KMeans'] == i]
    cluster_silhouette_values.sort()

    size_cluster_i = cluster_silhouette_values.shape[0]
    y_upper = y_lower + size_cluster_i

    plt.fill_betweenx(np.arange(y_lower, y_upper),
                      0, cluster_silhouette_values,
                      alpha=0.7, label=f'Cluster {i}')

    y_lower = y_upper + 10  # Espaço entre os clusters

plt.axvline(x=silhouette_avg, color="red", linestyle="--", label=f'Média: {silhouette_avg:.2f}')
plt.xlabel('Coeficiente de Silhueta')
plt.ylabel('Cluster')
plt.title(f'Gráfico da Silhueta para K-Means (k={k})')
plt.yticks([])  # Remover ticks do eixo y
plt.legend()
plt.grid(True)
plt.show()

# 🔍 Redução de dimensionalidade com PCA para visualização
pca = PCA(n_components=2)
X_pca = pca.fit_transform(X)

# Adicionar as componentes principais ao DataFrame
df['PCA1'] = X_pca[:, 0]
df['PCA2'] = X_pca[:, 1]

# 🔍 Visualizar os clusters com PCA para K-Means
plt.figure(figsize=(8, 6))
plt.scatter(df['PCA1'], df['PCA2'], c=df['Cluster_KMeans'], cmap='viridis', s=50, alpha=0.6)
plt.xlabel('Componente Principal 1')
plt.ylabel('Componente Principal 2')
plt.title(f'Agrupamento de Times em {k} Clusters (PCA - K-Means)')
plt.colorbar(label='Cluster')
plt.grid(True)
plt.show()

# 🔍 Redução de dimensionalidade com t-SNE para visualização
tsne = TSNE(n_components=2, random_state=42)
X_tsne = tsne.fit_transform(X)

# Adicionar os resultados do t-SNE ao DataFrame
df['tSNE1'] = X_tsne[:, 0]
df['tSNE2'] = X_tsne[:, 1]

# 🔍 Visualizar os clusters com t-SNE para K-Means
plt.figure(figsize=(8, 6))
plt.scatter(df['tSNE1'], df['tSNE2'], c=df['Cluster_KMeans'], cmap='viridis', s=50, alpha=0.6)
plt.xlabel('Componente t-SNE 1')
plt.ylabel('Componente t-SNE 2')
plt.title(f'Agrupamento de Times em {k} Clusters (t-SNE - K-Means)')
plt.colorbar(label='Cluster')
plt.grid(True)
plt.show()

# 🔍 Exibir as primeiras linhas do DataFrame com os resultados de PCA e t-SNE
print("✅ Primeiras linhas do DataFrame com clusters, PCA e t-SNE para K-Means:")
print(df[['Cluster_KMeans', 'PCA1', 'PCA2', 'tSNE1', 'tSNE2']].head())

# 💾 Salvar o dataset com os clusters, PCA e t-SNE
output_file_kmeans_tsne = "dados_com_clusters_kmeans_com_pca_tsne.csv"
df.to_csv(output_file_kmeans_tsne, index=False)
print(f"📁 Resultados salvos em '{output_file_kmeans_tsne}'")
