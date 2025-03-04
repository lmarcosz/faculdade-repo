import java.util.Random;

public class marcos_silva_aula1Pratico {

	public static void main(String[] args) {
		Random random = new Random();
		int[] vet = new int[1000];
		int maiorPrimo;
		long iniciaTempo;
		long paraTempo;
		long tempoFinal;
		
		for(int i=0; i<1000; i++) {
			vet[i] = random.nextInt(10000);
		}
		
		//Recursivo
		maiorPrimo = 0;
		iniciaTempo = System.nanoTime();
		for(int i=0; i<1000; i++) {
			if(vet[i] >= maiorPrimo && primoRecursivo(vet[i])) {
				maiorPrimo = vet[i];
			}
		}
		paraTempo = System.nanoTime();
		tempoFinal = paraTempo - iniciaTempo;
		System.out.println("Maior primo: " + maiorPrimo);
		System.out.println(" Tempo de execução (Recursivo): " + tempoFinal + "ns");
		
		//Iterativo
		maiorPrimo = 0;
		iniciaTempo = System.nanoTime();
		for(int i=0; i<1000; i++) {
			if(vet[i] >= maiorPrimo && primoIterativo(vet[i])) {
				maiorPrimo = vet[i];
			}
		}
		paraTempo = System.nanoTime();
		tempoFinal = paraTempo - iniciaTempo;
		System.out.println("Maior primo: " + maiorPrimo);
		System.out.println(" Tempo de execução (Iterativo): " + tempoFinal + "ns");
	}
	
	public static boolean primoRecursivo(int n) {
		return funcPrimoRec(n, n-1);
	}
	
	private static boolean funcPrimoRec(int n, int aux) {
		if(n <= 1) return false;
		if(aux == 1) return true;
		if(n%aux == 0) return false;
		return funcPrimoRec(n, aux-1);
	}
		
	private static boolean primoIterativo(int n) {
		int cont = 0;
		if(n<=1) return false;
		for(int i=n; i>=1; i--) if(n%i==0) cont++;
		if(cont==2) return true;
		return false;
	}
	
}
