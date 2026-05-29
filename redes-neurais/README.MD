# 📧 Detector de Spam com Rede Neural MLP em Python

## 📌 Descrição do Projeto

Este projeto foi desenvolvido na disciplina de Redes Neurais Artificiais e consiste na implementação de um sistema de detecção de spam utilizando uma Rede Neural Multi Layer Perceptron (MLP), desenvolvida manualmente com Python e NumPy.
O algoritmo realiza a classificação de mensagens de texto em spam ou ham, aplicando técnicas de pré-processamento de dados, vetorização TF-IDF, treinamento supervisionado e avaliação de desempenho do modelo.


O objetivo é classificar mensagens de texto como:

* **Ham (0)** → Mensagem normal
* **Spam (1)** → Mensagem indesejada

O projeto utiliza técnicas de:

* Pré-processamento de texto
* Vetorização TF-IDF
* Divisão treino/teste
* Forward Propagation
* Backpropagation
* Momentum
* Avaliação com métricas de desempenho

---

# 🛠 Tecnologias Utilizadas

* Python
* NumPy
* Pandas
* Scikit-learn

---

# 📂 Estrutura do Projeto

```bash
📁 projeto-spam-mlp/
│
├── spam.csv
├── preprocessamento.py
├── mlp.py
├── X_train.csv
├── X_test.csv
├── y_train.csv
├── y_test.csv
├── spam_pre_processado.csv
└── README.md
```

---

# 📥 Dataset

O dataset utilizado contém mensagens classificadas como spam ou ham.

### Colunas utilizadas:

| Coluna   | Descrição                   |
| -------- | --------------------------- |
| Category | Tipo da mensagem (ham/spam) |
| Message  | Texto da mensagem           |

---

# ⚙️ Etapa 1 — Pré-processamento dos Dados

## 📌 Bibliotecas Utilizadas

### Pandas

Utilizado para:

* leitura de arquivos CSV
* manipulação de tabelas
* limpeza de dados

### NumPy

Utilizado para:

* operações matemáticas
* manipulação de arrays

### Scikit-learn

Utilizado para:

* divisão treino/teste
* vetorização TF-IDF

---

# 🧹 Limpeza e Tratamento dos Dados

## Conversão dos rótulos

```python
df['Category'] = df['Category'].map({'ham': 0, 'spam': 1})
```

Transforma:

* ham → 0
* spam → 1

---

## Remoção de mensagens vazias

```python
df = df[df['Message'].str.strip().astype(bool)]
```

Remove mensagens contendo:

* espaços vazios
* strings vazias

---

# ✂️ Divisão Treino/Teste

```python
train_test_split(
    X,
    y,
    test_size=0.2,
    random_state=42,
    stratify=y
)
```

### Configurações:

| Parâmetro       | Função               |
| --------------- | -------------------- |
| test_size=0.2   | 20% para teste       |
| random_state=42 | Reprodutibilidade    |
| stratify=y      | Mantém balanceamento |

---

# 🔠 Vetorização TF-IDF

## O que é TF-IDF?

TF-IDF significa:

* **TF** → Frequência do termo
* **IDF** → Frequência inversa do documento

Essa técnica transforma textos em números, permitindo que a rede neural processe mensagens.

---

## Vetorização

```python
vectorizer = TfidfVectorizer()
```

Transforma mensagens em vetores numéricos.

---

# 💾 Salvamento dos Dados

Os conjuntos processados são salvos em CSV:

```python
X_train.csv
X_test.csv
y_train.csv
y_test.csv
```

Também é salvo:

```python
spam_pre_processado.csv
```

---

# 🧠 Etapa 2 — Implementação da Rede Neural MLP

## 📌 Estrutura da Rede

A rede possui:

* Camada de entrada
* Camada escondida
* Camada de saída

---

# ⚡ Inicialização dos Pesos

```python
self.W1 = np.random.randn(input_size, hidden_size) * 0.01
```

Os pesos são iniciados com pequenos valores aleatórios.

---

# 🔥 Função de Ativação ReLU

```python
def relu(self, z):
    return np.maximum(0, z)
```

A ReLU:

* mantém valores positivos
* zera valores negativos

---

# 📈 Função Sigmoide

```python
def sigmoid(self, z):
    return 1 / (1 + np.exp(-z))
```

A saída fica entre:

* 0 e 1

Interpretada como probabilidade.

---

# 🔄 Forward Propagation

Processo onde os dados percorrem a rede até gerar uma previsão.

```python
self.z1 = np.dot(X, self.W1) + self.b1
```

---

# 🔙 Backpropagation

Responsável por:

* calcular o erro
* ajustar os pesos

Utiliza:

* derivadas
* gradientes
* atualização dos pesos

---

# 🚀 Momentum

O momentum ajuda:

* acelerar treinamento
* reduzir oscilações
* melhorar convergência

```python
self.vW2 = self.momentum * self.vW2 - self.lr * dW2
```

---

# 🏋️ Treinamento

```python
mlp.fit(X_train, y_train, epochs=100)
```

Parâmetros:

* epochs = 100
* learning rate = 0.1
* momentum = 0.9

---

# 📊 Avaliação

## Métricas utilizadas

### Acurácia

```python
accuracy_score()
```

Mede:

* percentual de acertos

---

### MSE — Mean Squared Error

```python
mean_squared_error()
```

Mede:

* erro médio das previsões

---

# 📈 Saída

```bash
Epoch 0: Acurácia = 0.6078, MSE = 0.2500
Epoch 10: Acurácia = 0.8658, MSE = 0.1930
Epoch 20: Acurácia = 0.8658, MSE = 0.1403
Epoch 30: Acurácia = 0.8658, MSE = 0.1228
Epoch 40: Acurácia = 0.8658, MSE = 0.1182
Epoch 50: Acurácia = 0.8658, MSE = 0.1169
Epoch 60: Acurácia = 0.8658, MSE = 0.1165
Epoch 70: Acurácia = 0.8658, MSE = 0.1163
Epoch 80: Acurácia = 0.8658, MSE = 0.1163
Epoch 90: Acurácia = 0.8658, MSE = 0.1162
Epoch 99: Acurácia = 0.8658, MSE = 0.1162

📊 Avaliação no conjunto de teste:
Acurácia: 0.8664
MSE: 0.1336
...
---
