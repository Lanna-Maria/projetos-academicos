import pandas as pd

# Carregar o arquivo com os clusters
df_kmeans_pca = pd.read_csv('dados_com_clusters_kmeans_com_pca.csv')

# Calcular as médias de vitórias, controle de objetivos e ouro para cada cluster
cluster_means = df_kmeans_pca.groupby('Cluster_KMeans').agg({
    'blue_win': 'mean',  # Média de vitórias dos times
    'blueGold': 'mean',  # Média de ouro dos times
    'blueHeraldKills': 'mean',  # Média de HeraldKills (controle de objetivos)
    'blueDragonKills': 'mean',  # Média de DragonKills (controle de objetivos)
    'blueTowersDestroyed': 'mean',  # Média de Torres Destruídas
    'redGold': 'mean',  # Média de ouro dos times
    'redHeraldKills': 'mean',  # Média de HeraldKills (controle de objetivos)
    'redDragonKills': 'mean',  # Média de DragonKills (controle de objetivos)
    'redTowersDestroyed': 'mean',  # Média de Torres Destruídas
})

# Defina as regras para classificação de desempenho
def classificar_desempenho(row):
    if row['blue_win'] > 0.6 and row['blueGold'] > 30000 and row['blueDragonKills'] > 3 and row['blueHeraldKills'] > 1:
        return 'Alto Desempenho'
    elif 0.4 < row['blue_win'] <= 0.6:
        return 'Médio Desempenho'
    else:
        return 'Baixo Desempenho'

# Aplicar a classificação de desempenho aos clusters
cluster_means['Desempenho'] = cluster_means.apply(classificar_desempenho, axis=1)

# Exibir as classificações
print(cluster_means[['blue_win', 'blueGold', 'blueDragonKills', 'Desempenho']])
