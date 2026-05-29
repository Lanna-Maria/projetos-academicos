// Função para resolver o problema da mochila fracionária
function mochilaFracionaria(itens, capacidade) {
  // Ordena os itens pela razão valor/peso em ordem decrescente.
  // Isso garante que os itens com melhor relação valor/peso sejam considerados primeiro.
  itens.sort((a, b) => b[1] / b[0] - a[1] / a[0]);

  // Inicializa o array que armazenará os itens selecionados e o valor total acumulado. Estado inicial
  let itensSelecionados = [];
  let valorTotal = 0;

  // Itera sobre cada item da lista de itens.
  for (let i = 0; i < itens.length; i++) {
    const peso = itens[i][0]; // Peso do item atual
    const valor = itens[i][1]; // Valor do item atual

    // Verifica se o item inteiro pode caber na capacidade restante da mochila.
    if (capacidade >= peso) {
      // Adiciona o item inteiro à lista de itens selecionados.
      itensSelecionados.push([peso, valor]);
      valorTotal += valor; // Adiciona o valor do item ao valor total
      capacidade -= peso; // Reduz a capacidade restante da mochila pelo peso do item
    } else {
      // Se o item inteiro não cabe, calcula a fração que pode ser adicionada.
      const fracao = capacidade / peso; // Calcula a fração do item que pode caber
      itensSelecionados.push([capacidade, fracao * valor]); // Adiciona a fração do item à lista de itens selecionados
      valorTotal += fracao * valor; // Adiciona o valor correspondente à fração ao valor total
      break; // Como a mochila está cheia após adicionar a fração, encerra o loop
    }
  }

  // Retorna um array com dois elementos: a lista de itens selecionados e o valor total obtido.
  return [itensSelecionados, valorTotal];
}

// Lista de array com alguns itens incluso
const itens = [
  [10, 60],
  [20, 100],
  [30, 120],
  [40, 140],
  [50, 180],
  [60, 220],
  [70, 260],
  [80, 300],
  [90, 320],
  [100, 400],
];

// Capacidade total da mochila
const capacidade = 355;

// Chama a função e armazena o resultado e o valor máximo
const [resultado, valorMaximo] = mochilaFracionaria(itens, capacidade);

// Exibe os resultados no terminal ou seja estado final
console.log('Itens selecionados:', resultado);
console.log('Valor total:', valorMaximo);

