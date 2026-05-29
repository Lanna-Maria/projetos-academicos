//Classe para represntar o problema da mochila binária.
class MochilaBinaria {
  constructor(itens) {
    //construtor que está recebendo um array de itens como parâmetro, representando os itens que podem ser incluídos na mochila.
    this.itens = itens;
    this.mochila = []; // Mochila vazia , escolhi um vetor para armazenar os itens da mochila.
  }

  // Método para resolver o problema
  Guloso(capacidade) {
    this.itens.sort((a, b) => b.valor / b.peso - a.valor / a.peso); // Heurísticaa ordenando os itens por razão valor-peso em ordem decrescente

    let valorTotal = 0;
    let pesoAtual = 0;

    //Esta expressão é uma construção de loop em JavaScript, sendo  utilizada para iterar sobre os elementos de uma coleção, como um array.
    for (let item of this.itens) {
      if (pesoAtual + item.peso <= capacidade) {
        // Inclui o item se adicioná-lo não exceder a capacidade
        this.mochila.push(item);
        pesoAtual += item.peso;
        valorTotal += item.valor;
      }
    }

    // Limita o valor total ao máximo da capacidade
    valorTotal = Math.min(valorTotal, capacidade);

    return valorTotal;
  }
}

// Array recebendo os dados da atividade
const itens = [
  { id: 1, peso: 10, valor: 15 },
  { id: 2, peso: 40, valor: 90 },
  { id: 3, peso: 26, valor: 50 },
  { id: 4, peso: 32, valor: 60 },
  { id: 5, peso: 8, valor: 12 },
];

const capacidade = 80; //Capacidade total da mochila
const mochila = new MochilaBinaria(itens);
const resultado = mochila.Guloso(capacidade);

console.log('Valor máximo (limitado a 80):', resultado);
console.log('Itens na mochila:');
for (let item of mochila.mochila) {
  console.log(`ID: ${item.id}, Peso: ${item.peso}, Valor: ${item.valor}`);
}
