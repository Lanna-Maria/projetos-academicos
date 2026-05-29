import numpy as np
# Biblioteca fundamental para computação numérica em Python.
# Facilita criação e manipulação de arrays/matrizes, operações matemáticas
# vetorizadas, álgebra linear, geração de números aleatórios, entre outros.
# Muito usada para cálculos internos em algoritmos de machine learning.

import pandas as pd
# Biblioteca para manipulação e análise de dados estruturados.
# Permite trabalhar com DataFrames, que são tabelas similares a planilhas,
# facilitando a leitura, limpeza, transformação e exportação de dados.

from sklearn.metrics import accuracy_score, mean_squared_error
# Módulo do scikit-learn que oferece funções para avaliação de modelos.
# accuracy_score calcula a acurácia (percentual de acertos) em classificações.
# mean_squared_error calcula o erro quadrático médio (MSE), que mede o quanto
# as previsões estão distantes dos valores reais, usado em regressão e outros.

# 1. Carregar os dados pré processados de treino e teste com os conjuntos vetorizados
X_train = pd.read_csv("X_train.csv").values   # Lê os dados vetorizados de treino e converte para array NumPy
X_test = pd.read_csv("X_test.csv").values     # Lê os dados vetorizados de teste e converte para array NumPy
y_train = pd.read_csv("y_train.csv").values.reshape(-1, 1)  # Lê os rótulos de treino e transforma em vetor coluna
y_test = pd.read_csv("y_test.csv").values.reshape(-1, 1)    # Lê os rótulos de teste e transforma em vetor coluna

# 2. Implementação da MLP com forward, backpropagation e momentum
class MLP:
    def __init__(self, input_size, hidden_size, output_size, lr=0.01, momentum=0.9):
        self.lr = lr                  # Taxa de aprendizado para atualizar pesos
        self.momentum = momentum      # Coeficiente de momentum para suavizar atualizações

        # Inicialização dos pesos das camadas com valores pequenos aleatórios
        self.W1 = np.random.randn(input_size, hidden_size) * 0.01  # Pesos da camada de entrada para escondida
        self.b1 = np.zeros((1, hidden_size))                       # Viés da camada escondida (inicial zero)
        self.W2 = np.random.randn(hidden_size, output_size) * 0.01 # Pesos da camada escondida para saída
        self.b2 = np.zeros((1, output_size))                       # Viés da camada de saída (inicial zero)

        # Inicialização dos termos do momentum para cada parâmetro (inicial zero)
        self.vW1 = np.zeros_like(self.W1)  
        self.vb1 = np.zeros_like(self.b1)
        self.vW2 = np.zeros_like(self.W2)
        self.vb2 = np.zeros_like(self.b2)

    def relu(self, z):
        # Função de ativação ReLU: ativa apenas valores positivos (z)
        return np.maximum(0, z)

    def relu_deriv(self, z):
        # Derivada da ReLU para backpropagation: 1 se z > 0, 0 caso contrário
        return (z > 0).astype(float)

    def sigmoid(self, z):
        # Função sigmoide para ativação da saída: transforma valores para (0,1)
        return 1 / (1 + np.exp(-z))

    def sigmoid_deriv(self, z):
        # Derivada da sigmoide, útil para backpropagation
        s = self.sigmoid(z)
        return s * (1 - s)

    def forward(self, X):
        # Propagação direta (forward pass)
        self.z1 = np.dot(X, self.W1) + self.b1  # Produto da entrada pelos pesos + viés na camada escondida
        self.a1 = self.relu(self.z1)             # Aplicação da ativação ReLU na camada escondida
        self.z2 = np.dot(self.a1, self.W2) + self.b2  # Produto da ativação escondida pelos pesos + viés na saída
        self.a2 = self.sigmoid(self.z2)          # Ativação sigmoide na saída (probabilidade)
        return self.a2                           # Saída final da rede

    def backward(self, X, y, output):
        m = y.shape[0]  # Número de amostras (batch size)
        
        # Cálculo do gradiente do erro na camada de saída (usando derivada da sigmoide)
        dz2 = (output - y) * self.sigmoid_deriv(self.z2)
        dW2 = np.dot(self.a1.T, dz2) / m       # Gradiente dos pesos da camada saída
        db2 = np.sum(dz2, axis=0, keepdims=True) / m  # Gradiente do viés da camada saída
        
        # Cálculo do gradiente da camada escondida (usando derivada ReLU)
        dz1 = np.dot(dz2, self.W2.T) * self.relu_deriv(self.z1)
        dW1 = np.dot(X.T, dz1) / m             # Gradiente dos pesos da camada escondida
        db1 = np.sum(dz1, axis=0, keepdims=True) / m  # Gradiente do viés da camada escondida

        # Atualização dos termos do momentum para suavizar as atualizações dos pesos
        self.vW2 = self.momentum * self.vW2 - self.lr * dW2
        self.vb2 = self.momentum * self.vb2 - self.lr * db2
        self.vW1 = self.momentum * self.vW1 - self.lr * dW1
        self.vb1 = self.momentum * self.vb1 - self.lr * db1

        # Aplicação das atualizações ponderadas pelos termos de momentum
        self.W2 += self.vW2
        self.b2 += self.vb2
        self.W1 += self.vW1
        self.b1 += self.vb1

    def fit(self, X, y, epochs=100):
        # Treinamento da rede por 'epochs' épocas
        for epoch in range(epochs):
            output = self.forward(X)       # Passo forward
            self.backward(X, y, output)    # Passo backward para ajustar pesos
            # A cada 10 épocas (ou última), imprime métricas de desempenho
            if epoch % 10 == 0 or epoch == epochs - 1:
                acc = accuracy_score(y, (output > 0.5).astype(int))  # Acurácia com limiar 0.5
                mse = mean_squared_error(y, output)                  # Erro quadrático médio
                print(f"Epoch {epoch}: Acurácia = {acc:.4f}, MSE = {mse:.4f}")

    def predict(self, X):
        # Prediz a classe binária com limiar 0.5 a partir da saída da rede
        return (self.forward(X) > 0.5).astype(int)

# 3. Treinamento e avaliação
input_size = X_train.shape[1]  # Número de características (features) da entrada
hidden_size = 50              # Número de neurônios na camada escondida (hiperparâmetro)
output_size = 1               # Saída binária (spam ou não spam)

mlp = MLP(input_size, hidden_size, output_size, lr=0.1, momentum=0.9)  # Inicializa a rede
mlp.fit(X_train, y_train, epochs=100)  # Treina a rede com os dados de treino

# Avaliação no conjunto de teste
y_pred = mlp.predict(X_test)  # Previsões
acc = accuracy_score(y_test, y_pred)  # Calcula acurácia
mse = mean_squared_error(y_test, y_pred)  # Calcula erro quadrático médio

print("\n📊 Avaliação no conjunto de teste:")
print(f"Acurácia: {acc:.4f}")
print(f"MSE: {mse:.4f}")
