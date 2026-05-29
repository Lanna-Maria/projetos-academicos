// Função que gera um indivíduo aleatório (solução candidata) para a população inicial. A função gerarIndividuo gera uma solução candidata (um indivíduo) para a população inicial. Cada valor no array gerado é um número entre 0 e 1, representando a fração do item que está sendo considerado
function gerarIndividuo(tamanho) {
  return Array.from({ length: tamanho }, () => Math.random()); // Valores entre 0 e 1 representando frações dos itens
}

// Função que calcula o fitness de um indivíduo para o problema da mochila fracionária. A função calcularFitness usa as frações para calcular o peso total e o valor total dos itens. Se a soma dos pesos não exceder a capacidade da mochila, o valor total é retornado; caso contrário, retorna 0:
function calcularFitness(individuo, itens, capacidade) {
  let pesoTotal = 0;
  let valorTotal = 0;

  // laços de repetição para fazer a interação sobre cada gene (fração do item) do indivíduo para calcular o peso e o valor total dos itens incluídos.
  for (let i = 0; i < individuo.length; i++) {
    pesoTotal += individuo[i] * itens[i][0]; // Soma o peso do item
    valorTotal += individuo[i] * itens[i][1]; // Soma o valor do item
  }

  // Se o peso total exceder a capacidade da mochila, o fitness é 0.
  // Caso contrário, o fitness é o valor total dos itens incluídos.
  return pesoTotal <= capacidade ? valorTotal : 0;
}

// Função de seleção para escolher um indivíduo da população para cruzamento baseado em seu fitness. A probabilidade de seleção é proporcional ao fitness do indivíduo em relação ao fitness total da população.
function selecao(populacao, fitnesses) {
  const totalFitness = fitnesses.reduce((a, b) => a + b, 0); // Soma dos fitnesses
  const selecaoAcumulada = fitnesses.map(
    (fit, i) =>
      fitnesses.slice(0, i + 1).reduce((a, b) => a + b, 0) / totalFitness,
  );

  // Gera um número aleatório e encontra o indivíduo correspondente na população baseado na probabilidade acumulada.
  const rand = Math.random();
  return populacao[
    selecaoAcumulada.findIndex((acumulado) => acumulado >= rand)
  ];
}

// Função de cruzamento para combinar dois indivíduos (pais) para criar dois novos indivíduos (filhos). A função cruzamento combina dois pais para gerar dois filhos. A combinação dos genes (frações) dos pais é feita em um ponto de corte
function cruzamento(pai1, pai2) {
  const pontoCorte = Math.floor(Math.random() * pai1.length); // Ponto de corte aleatório
  return [
    [...pai1.slice(0, pontoCorte), ...pai2.slice(pontoCorte)],
    [...pai2.slice(0, pontoCorte), ...pai1.slice(pontoCorte)],
  ];
}

// Função de mutação para introduzir a diversidade nos genes dos indivíduos. A função mutacao altera aleatoriamente a fração de cada item com base na taxa de mutação. Se um gene for mutado, ele é substituído por um novo valor aleatório entre 0 e 1:
function mutacao(individuo, taxaMutacao = 0.01) {
  return individuo.map((gene) =>
    Math.random() < taxaMutacao ? Math.random() : gene,
  );
}

// Função principal que implementa o algoritmo genético para resolver o problema da mochila fracionária. A função busca encontrar a melhor combinação de itens que maximiza o valor total dentro da capacidade da mochila.
function algoritmoGenetico(
  itens,
  capacidade,
  tamanhoPopulacao = 100,
  geracoes = 100,
) {
  const tamanhoIndividuo = itens.length; // Cada indivíduo terá um gene para cada item

  // Gera a população inicial de indivíduos aleatórios.
  let populacao = Array.from({ length: tamanhoPopulacao }, () =>
    gerarIndividuo(tamanhoIndividuo),
  );

  // Itera por um número fixo de gerações.
  for (let geracao = 0; geracao < geracoes; geracao++) {
    const fitnesses = populacao.map((ind) =>
      calcularFitness(ind, itens, capacidade),
    );
    const novaPopulacao = [];

    // Gera a nova população através de seleção, cruzamento e mutação.
    while (novaPopulacao.length < tamanhoPopulacao) {
      const pai1 = selecao(populacao, fitnesses); // Seleciona o primeiro pai
      const pai2 = selecao(populacao, fitnesses); // Seleciona o segundo pai
      let [filho1, filho2] = cruzamento(pai1, pai2); // Realiza o cruzamento
      filho1 = mutacao(filho1); // Aplica mutação ao primeiro filho
      filho2 = mutacao(filho2); // Aplica mutação ao segundo filho
      novaPopulacao.push(filho1, filho2); // Adiciona os filhos à nova população
    }

    // Substitui a população antiga pela nova.
    populacao = novaPopulacao.slice(0, tamanhoPopulacao);
  }

  // Após o término das gerações, calcula o fitness final de cada indivíduo.
  const fitnessesFinais = populacao.map((ind) =>
    calcularFitness(ind, itens, capacidade),
  );

  // Identifica o melhor indivíduo da última geração (aquele com maior fitness).
  const melhorIndividuo =
    populacao[fitnessesFinais.indexOf(Math.max(...fitnessesFinais))];
  const valorMaximo = Math.max(...fitnessesFinais);

  // Retorna o melhor indivíduo encontrado e seu valor associado.
  return [melhorIndividuo, valorMaximo];
}

// Função para gerar uma lista de itens com pesos e valores
function gerarItens(totalItens, capacidadeMax) {
  const itens = [];
  let pesoAcumulado = 0;

  for (let i = 0; i < totalItens - 1; i++) {
    const pesoMaximo = capacidadeMax - pesoAcumulado - (totalItens - i - 1);
    const peso = Math.floor(Math.random() * (pesoMaximo + 1)) + 1;
    const valor = Math.floor(Math.random() * 400) + 1; // Valor entre 1 e 400
    itens.push([peso, valor]);
    pesoAcumulado += peso;
  }

  // Adiciona o último item com o peso restante para completar o peso total dentro da capacidade
  itens.push([
    capacidadeMax - pesoAcumulado,
    Math.floor(Math.random() * 400) + 1,
  ]);

  return itens;
}

// Número total de itens desejados
const totalItens = 5000;

// Define a capacidade da mochila como 500
const capacidade = 500;

// Gera os itens com a função ajustada
const itens = gerarItens(totalItens, capacidade);

// Calcula o total dos pesos dos itens
const totalPesos = itens.reduce((soma, item) => soma + item[0], 0);

// Verifica se a soma dos pesos excede a capacidade
if (totalPesos > capacidade) {
  console.log(
    'Aviso: A soma dos pesos dos itens excede a capacidade da mochila.',
  );
} else {
  console.log('Total dos pesos dos itens:', totalPesos);
}

// Mede o tempo de execução do algoritmo genético
console.time('tempoExecutado');
const [melhorSolucao, valorMaximo] = algoritmoGenetico(itens, capacidade);
console.timeEnd('tempoExecutado');

// Executa o algoritmo genético e obtém a melhor solução e o valor máximo.
console.log('Melhor solução:', melhorSolucao);
console.log('Valor máximo:', valorMaximo);
console.log('Capacidade da mochila:', capacidade);

