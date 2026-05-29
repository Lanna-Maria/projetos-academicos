import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class ArvoreGenerica {
    private int chave;
    private int filhos;
    private List<ArvoreGenerica> lista;

    public ArvoreGenerica(int chave) {
        this.chave = chave;
        this.filhos = 0;
        this.lista = new ArrayList<>();
    }

    public ArvoreGenerica getSubArvore(int i) {
        if (filhos < i) {
            throw new IndexOutOfBoundsException();
        }
        return lista.get(i);
    }

    public void addSubArvore(int chave) {
        lista.add(new ArvoreGenerica(chave));
        filhos++;
    }

    public int contarNosRecursivo() {
        if (this == null) {
            return 0;
        } else {
            int count = 1;
            for (int i = 0; i < filhos; i++) {
                ArvoreGenerica subArvore = getSubArvore(i);
                count += subArvore.contarNosRecursivo();
            }
            return count;
        }
    }

    public int contarNosNaoRecursivo() {
        if (this == null) {
            return 0;
        } else {
            int count = 0;
            Queue<ArvoreGenerica> fila = new LinkedList<>();
            fila.add(this);
            while (!fila.isEmpty()) {
                ArvoreGenerica no = fila.poll();
                count++;
                for (int i = 0; i < no.filhos; i++) {
                    ArvoreGenerica subArvore = no.getSubArvore(i);
                    fila.add(subArvore);
                }
            }
            return count;
        }
    }

    public int somarConteudosRecursivo() {
        if (this == null) {
            return 0;
        } else {
            int soma = this.chave;
            for (int i = 0; i < filhos; i++) {
                ArvoreGenerica subArvore = getSubArvore(i);
                soma += subArvore.somarConteudosRecursivo();
            }
            return soma;
        }
    }

    public int somarConteudosNaoRecursivo() {
        if (this == null) {
            return 0;
        } else {
            int soma = 0;
            Queue<ArvoreGenerica> fila = new LinkedList<>();
            fila.add(this);
            while (!fila.isEmpty()) {
                ArvoreGenerica no = fila.poll();
                soma += no.chave;
                for (int i = 0; i < no.filhos; i++) {
                    ArvoreGenerica subArvore = no.getSubArvore(i);
                    fila.add(subArvore);
                }
            }
            return soma;
        }
    }

    public int profundidadeNoRecursivo(int no) {
        if (this == null) {
            return -1;
        } else if (this.chave == no) {
            return 0;
        } else {
            for (int i = 0; i < filhos; i++) {
                ArvoreGenerica subArvore = getSubArvore(i);
                int profundidade = subArvore.profundidadeNoRecursivo(no);
                if (profundidade >= 0) {
                    return profundidade + 1;
                }
            }
            return -1;
        }
    }

    public int profundidadeNoNaoRecursivo(int no) {
        if (this == null) {
            return -1;
        } else {
            Queue<ArvoreGenerica> fila = new LinkedList<>();
            fila.add(this);
            int profundidade = 0;
            while (!fila.isEmpty()) {
                ArvoreGenerica noAtual = fila.poll();
                if (noAtual.chave == no) {
                    return profundidade;
                }
                for (int i = 0; i < noAtual.filhos; i++) {
                    ArvoreGenerica subArvore = noAtual.getSubArvore(i);
                    fila.add(subArvore);
                }
                profundidade++;
            }
            return -1;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        // Criação de uma árvore genérica com alguns nós
        ArvoreGenerica arvore = new ArvoreGenerica(1);
        arvore.addSubArvore(2);
        arvore.addSubArvore(3);
        arvore.addSubArvore(4);

        ArvoreGenerica subArvore2 = arvore.getSubArvore(0);
        subArvore2.addSubArvore(5);
        subArvore2.addSubArvore(6);

        ArvoreGenerica subArvore4 = arvore.getSubArvore(2);
        subArvore4.addSubArvore(7);
        subArvore4.addSubArvore(8);
        subArvore4.addSubArvore(9);

        System.out.println("   1    ");
        System.out.println(" / | \\ ");
        System.out.println("2  3  4     ");
        System.out.println("/ \\        ");
        System.out.println("5  6        ");
        System.out.println("  / \\    ");
        System.out.println(" 7   8    ");
        System.out.println("      \\    ");
        System.out.println("       9    ");

        // Contagem de nós recursiva e não recursiva
        System.out.println("Contagem de nós (recursiva): " + arvore.contarNosRecursivo());  // Output: 10
        System.out.println("Contagem de nós (não recursiva): " + arvore.contarNosNaoRecursivo());  // Output: 10

        // Soma dos conteúdos dos nós recursiva e não recursiva
        System.out.println("Soma dos conteúdos dos nós (recursiva): " + arvore.somarConteudosRecursivo());  // Output: 45
        System.out.println("Soma dos conteúdos dos nós (não recursiva): " + arvore.somarConteudosNaoRecursivo());  // Output: 45

        // Profundidade de um nó recursiva e não recursiva
        System.out.println("Profundidade do nó 9 (recursiva): " + arvore.profundidadeNoRecursivo(9));  // Output: 3
        System.out.println("Profundidade do nó 9 (não recursiva): " + arvore.profundidadeNoNaoRecursivo(9));  // Output: 3
    }
}
