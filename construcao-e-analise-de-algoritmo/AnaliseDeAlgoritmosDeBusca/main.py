import random # Gerar números aleatórios
import time # Medir o tempo de execução
import matplotlib.pyplot as plt # Plotar gráficos

# Essa função implementa o algoritmo de busca linear convencional
# Ela vai percorrer cada elemento da lista sequencialmente e comparar com a chave de busca.
def busca_linear_convencional(lista, chave):
    for i in range(len(lista)):
        if lista[i] == chave:
            return i
    return -1

#Essa função implementa o algoritmo de busca linear com sentinela.
# Ela adiciona um sentinela (o valor da chave de busca) ao final da lista, substituindo o último elemento temporariamente.
# Em seguida, irá realizar a busca linear normalmente.
def busca_linear_sentinela(lista, chave):
    ultimo_elemento = lista[-1]
    lista[-1] = chave
    i = 0
    while lista[i] != chave:
        i += 1
    lista[-1] = ultimo_elemento
    if i < len(lista)-1 or lista[-1] == chave:
        return i
    return -1

# Essa função implementa o algoritmo de busca binária convencional.
# Ela assume que a lista está ordenada em ordem crescente.
# Inicialmente, define os índices de início e fim do intervalo de busca.
# Em cada iteração, calcula o índice do meio do intervalo, compara o elemento do meio com a chave e atualiza os índices de início e fim de acordo com a comparação.
def busca_binaria_convencional(lista, chave):
    inicio = 0
    fim = len(lista) - 1
    while inicio <= fim:
        meio = (inicio + fim) // 2
        if lista[meio] == chave:
            return meio
        elif lista[meio] < chave:
            inicio = meio + 1
        else:
            fim = meio - 1
    return -1

#Essa função implementa o mesmo algoritmo de busca binária convencional.
# A diferença é que a operação de divisão inteira (inicio + fim) // 2 é usada para calcular o índice do elemento do meio.
def busca_binaria_rapida(lista, chave):
    inicio = 0
    fim = len(lista) - 1
    while inicio <= fim:
        meio = (inicio + fim) // 2
        if lista[meio] == chave:
            return meio
        elif lista[meio] < chave:
            inicio = meio + 1
        else:
            fim = meio - 1
    return -1


# Geração dos vetores de tamanhos específicos
# Essas linhas definem uma lista tamanhos_vetores com os tamanhos dos vetores que serão utilizados.
tamanhos_vetores = [1000, 3000, 6000, 9000, 12000, 15000, 18000, 21000, 24000]
vetores = [] #  Em seguida, é criada uma lista vazia vetores.
#Loop para percorrer os tamanhos dos vetores e para cada tamanho, gera um novo vetor com elementos inteiros aleatórios no intervalo de 0 a 100000.
for tamanho in tamanhos_vetores:
    vetor = [random.randint(0, 100000) for _ in range(tamanho)]
    vetores.append(vetor)

# Definição da chave de busca (gerada aleatoriamente neste exemplo)
# Essas linhas criam listas vazias para armazenar os tempos de execução dos algoritmos de busca.
chave = random.randint(0, 100000)

tempos_linear_convencional = []
tempos_linear_sentinela = []
tempos_binaria_convencional = []
tempos_binaria_rapida = []

# Essas linhas realizam a comparação dos algoritmos de busca para cada vetor gerado. O loop for percorre cada vetor na lista vetores
#  Para cada vetor, irá medir o tempo de execução  e armazenar na lista.
for vetor in vetores:
    # Busca linear convencional
    inicio = time.time()
    busca_linear_convencional(vetor, chave)
    fim = time.time()
    tempos_linear_convencional.append(fim - inicio)

    # Busca linear com sentinela
    inicio = time.time()
    busca_linear_sentinela(vetor, chave)
    fim = time.time()
    tempos_linear_sentinela.append(fim - inicio)

    # Ordenação linear
    vetor.sort()

    # Busca binária convencional
    inicio = time.time()
    busca_binaria_convencional(vetor, chave)
    fim = time.time()
    tempos_binaria_convencional.append(fim - inicio)

    # Busca binária rápida
    inicio = time.time()
    busca_binaria_rapida(vetor, chave)
    fim = time.time()
    tempos_binaria_rapida.append(fim - inicio)

# Plotando o gráfico comparativo
# Essas linhas plotam um gráfico comparando os tempos de execução dos algoritmos de busca.
# Onde cada algoritmo vai ser representado por uma curva no gráfico
plt.plot(tamanhos_vetores, tempos_linear_convencional, label='Linear Convencional')
plt.plot(tamanhos_vetores, tempos_linear_sentinela, label='Linear com Sentinela')
plt.plot(tamanhos_vetores, tempos_binaria_convencional, label='Binária Convencional')
plt.plot(tamanhos_vetores, tempos_binaria_rapida, label='Binária Rápida')

# Os eixos X e Y do gráfico está sendo rotulados adequadamente.
plt.xlabel('Tamanho do vetor')
plt.ylabel('Tempo de execução (segundos)')
plt.title('Comparação de algoritmos de busca') # O título do gráfico está definido como: "Comparação de algoritmos de busca".
plt.legend() #A legenda será adicionada para identificar cada curva no gráfico.

plt.show() #Exibição do gráfico.