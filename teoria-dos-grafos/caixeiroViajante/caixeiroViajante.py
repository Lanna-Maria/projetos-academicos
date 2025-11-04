import argparse
import random
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import os
import time  # Importando o módulo time para medir o tempo de execução


# matriz de distâncias para representar o grafo
def read(instancia):
    arquivo = f"{instancia}"  
    if not os.path.isfile(arquivo):
        raise FileNotFoundError(f"Arquivo {arquivo} não encontrado!")
    
    with open(arquivo, 'r') as f:
        linhas = f.readlines()
    
    n = int(linhas[0].strip())  # Número de cidades
    matriz = np.zeros((n, n))

    # Ajustando para carregar todas as distâncias corretamente
    for i in range(1, len(linhas)):
        dados = list(map(float, linhas[i].strip().split()))
        cidade1 = int(dados[0]) - 1
        cidade2 = int(dados[1]) - 1
        distancia = dados[2]
        matriz[cidade1][cidade2] = distancia
        matriz[cidade2][cidade1] = distancia  
    
    return matriz

# Função de fitness: calcula a distância total do caminho
def fitness(caminho, matriz):
    return sum(matriz[caminho[i], caminho[i + 1]] for i in range(len(caminho) - 1)) + matriz[caminho[-1], caminho[0]]

# Função para mostrar o melhor caminho encontrado eo custo
def show(caminho, distancia):
    print("Melhor caminho encontrado:")
    print(" -> ".join(map(str, [cidade + 1 for cidade in caminho])))
    print(f"Custo do caminho: {distancia}")

# Algoritmo Genético para resolver o problema do Caixeiro Viajante
def resolver_caixeiro_viajante(matriz, geracoes=500, tamanho_populacao=100, taxa_mutacao=0.05):
    num_cidades = matriz.shape[0]

    populacao = [random.sample(range(num_cidades), num_cidades) for _ in range(tamanho_populacao)]

    for geracao in range(geracoes):
        aptidoes = [fitness(individuo, matriz) for individuo in populacao]

        selecionados = []
        for _ in range(tamanho_populacao):
            i, j = random.sample(range(tamanho_populacao), 2)
            selecionados.append(populacao[i] if aptidoes[i] < aptidoes[j] else populacao[j])

        nova_populacao = []
        for _ in range(tamanho_populacao // 2):
            pai1, pai2 = random.sample(selecionados, 2)
            ponto1, ponto2 = sorted(random.sample(range(num_cidades), 2))
            filho1 = pai1[ponto1:ponto2] + [gene for gene in pai2 if gene not in pai1[ponto1:ponto2]]
            filho2 = pai2[ponto1:ponto2] + [gene for gene in pai1 if gene not in pai2[ponto1:ponto2]]
            nova_populacao.extend([filho1, filho2])

        for individuo in nova_populacao:
            if random.random() < taxa_mutacao:
                i, j = random.sample(range(num_cidades), 2)
                individuo[i], individuo[j] = individuo[j], individuo[i]

        populacao = nova_populacao

    melhor_caminho = min(populacao, key=lambda caminho: fitness(caminho, matriz))
    melhor_distancia = fitness(melhor_caminho, matriz)

    return melhor_caminho, melhor_distancia

# Função para animação do caminho
def animate_path(i, linha, coordenadas, ax):
    ax.clear()  # Limpa o gráfico a cada frame
    ax.set_title('Caminho Ótimo Encontrado pelo Algoritmo Genético')
    ax.set_xlabel('Coordenada X')
    ax.set_ylabel('Coordenada Y')

    # Plotando as cidades como pontos azuis
    ax.scatter(coordenadas[:, 0], coordenadas[:, 1], color='blue', s=100)

    # Plotando as arestas até o passo atual da animação
    for j in range(i+1):
        x_vals = [p[0] for p in linha[j]]
        y_vals = [p[1] for p in linha[j]]
        ax.plot(x_vals, y_vals, 'ro-', markersize=5)  # Desenhando as arestas com círculos vermelhos

    # Adicionando o número das cidades
    for k, cidade in enumerate(coordenadas):
        ax.text(cidade[0], cidade[1], str(k+1), fontsize=12, ha='right')

# Função para visualização animada do caminho
def visualize_animation(caminho, matriz):
    num_cidades = len(caminho)
    coordenadas = np.random.rand(num_cidades, 2)  # Coordenadas aleatórias para as cidades

    # Lista de arestas
    linha = []
    for i in range(len(caminho) - 1):
        linha.append([coordenadas[caminho[i]], coordenadas[caminho[i + 1]]])
    linha.append([coordenadas[caminho[-1]], coordenadas[caminho[0]]])  # Fechando o ciclo

    # Criando o gráfico
    fig, ax = plt.subplots(figsize=(10, 6))
    ani = animation.FuncAnimation(fig, animate_path, frames=len(linha), fargs=(linha, coordenadas, ax), interval=500, repeat=False)

    plt.show()

# Função principal
def main():
    parser = argparse.ArgumentParser(description="Problema do Caixeiro Viajante com Algoritmo Genético")
    
    subparsers = parser.add_subparsers(dest="comando", help="Comandos para executar o programa")
    
    # Subcomando para ler a matriz
    parser_read = subparsers.add_parser("read", help="Ler a matriz de distâncias")
    parser_read.add_argument("instancia", help="Instância do problema (arquivo de distâncias)")
    
    # Subcomando para mostrar o melhor caminho
    parser_show = subparsers.add_parser("show", help="Mostrar o melhor caminho encontrado")
    parser_show.add_argument("instancia", help="Instância do problema (arquivo de distâncias)")
    
    # Subcomando para visualizar o caminho
    parser_visualize = subparsers.add_parser("visualize", help="Visualizar o caminho encontrado")
    parser_visualize.add_argument("instancia", help="Instância do problema (arquivo de distâncias)")
    
    args = parser.parse_args()

    try:
        if args.comando == "read":
            matriz = read(args.instancia)
            print("Instância carregada com sucesso!")
        
        if args.comando == "show" or args.comando == "visualize":
            matriz = read(args.instancia)
            
            # Medindo o tempo de execução do algoritmo genético
            start_time = time.time()  # Tempo inicial
            caminho, distancia = resolver_caixeiro_viajante(matriz)
            end_time = time.time()  # Tempo final
            
            # Calculando o tempo de execução
            tempo_execucao = end_time - start_time
            print(f"Tempo de execução: {tempo_execucao:.4f} segundos")
            
            if args.comando == "show":
                show(caminho, distancia)
            elif args.comando == "visualize":
                visualize_animation(caminho, matriz)
    
    except Exception as e:
        print(f"Erro: {e}")

if __name__ == "__main__":
    main()
