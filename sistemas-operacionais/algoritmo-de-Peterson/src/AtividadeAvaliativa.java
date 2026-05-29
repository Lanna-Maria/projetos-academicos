
public class AtividadeAvaliativa {

	static int c = 0; // variavel  
	static boolean flag[] = { false, false }; // sinalizadores
	static int turn; //inteiros

	public static void main(String[] args) {
		new Thread(tarefa1).start();
		new Thread(tarefa2).start();

	}

	private static Runnable tarefa1 = new Runnable() {
		public void run() {

			flag[0] = true;
			turn = 1;
			while (flag[1] == true && turn == 1) {
				continue;
			}

			 // região critica
			for (int i = 0; i < 10; i++) {
				c += 1;
				System.out.println("Tarefa 1: c = " + c);
			}

			// 
			flag[0] = false; // fim da região crítica

		}
	};

	private static Runnable tarefa2 = new Runnable() {
		public void run() {

			flag[1] = true;
			turn = 0;
			while (flag[0] == true && turn == 0) {
				continue;
			}

			  // região critica
			for (int i = 0; i < 10; i++) {
				c += 1000;
				System.out.println("Tarefa 2: c = " + c);
			}

			 // 
			flag[1] = false; // fim da região crítica

		}
	};

}