/* Arvore Binaria em Java (insere, apaga, busca, caminha)
   Criado por: profa. Divani Barbosa Gavinier
   Curriculo Lattes: http://lattes.cnpq.br/8503400830635447
   divanibarbosa@gmail.com
*/

package aula6;

import java.util.Random;

public class marcos_silva_aula6Pratico {
	
	public static void main(String args[]) {
		Random random = new Random();
		int[] vet = new int[10000];
		long iniciaTempo;
		long paraTempo;
		long tempoFinal;

		//Inserção no vetor aleatório
		iniciaTempo = System.nanoTime();
		for(int i=0; i<10000; i++) {
			vet[i] = random.nextInt(100000);
		}
		paraTempo = System.nanoTime();
		tempoFinal = paraTempo - iniciaTempo;
		System.out.println("===== Tempo de inserção na vetor aleatório: " + (tempoFinal/1000) + "ms=====\n");
		
		//Buscando o número 50
		boolean aux = false;
		iniciaTempo = System.nanoTime();
		for(int i=0; i<10000; i++) {
			if(vet[i]==50){
				aux = true;
				break;
			}
		}
		paraTempo = System.nanoTime();
		tempoFinal = paraTempo - iniciaTempo;
		if(aux) {
			System.out.println("O valor 50 foi encontrado!");
		} else {
			System.out.println("O valor 50 NÃO foi encontrado!");
		}
		System.out.println("Tempo de busca: " + tempoFinal + "ns\n");
		
		//Buscando o número 5000
		aux = false;
		iniciaTempo = System.nanoTime();
		for(int i=0; i<10000; i++) {
			if(vet[i]==5000){
				aux = true;
				break;
			}
		}
		paraTempo = System.nanoTime();
		tempoFinal = paraTempo - iniciaTempo;
		if(aux) {
			System.out.println("O valor 5000 foi encontrado!");
		} else {
			System.out.println("O valor 5000 NÃO foi encontrado!");
		}
		System.out.println("Tempo de busca: " + tempoFinal + "ns\n");
		
		int[] vetOrdenado = new int[10000];
		vetOrdenado = shellSort(vet);
		
		//Buscando o número 50
		aux = false;
		iniciaTempo = System.nanoTime();
		int res = binarySearch(vetOrdenado, 0, vetOrdenado.length - 1, 50);
		paraTempo = System.nanoTime();
		tempoFinal = paraTempo - iniciaTempo;
		if(res != -1) {
			System.out.println("O valor 50 foi encontrado!");
		} else {
			System.out.println("O valor 50 NÃO foi encontrado!");
		}
		System.out.println("Tempo de busca: " + tempoFinal + "ns\n");
		
		//Buscando o número 5000
		aux = false;
		iniciaTempo = System.nanoTime();
		res = binarySearch(vetOrdenado, 0, vetOrdenado.length - 1, 50);
		paraTempo = System.nanoTime();
		tempoFinal = paraTempo - iniciaTempo;
		if(res != -1) {
			System.out.println("O valor 5000 foi encontrado!");
		} else {
			System.out.println("O valor 5000 NÃO foi encontrado!");
		}
		System.out.println("Tempo de busca: " + tempoFinal + "ns\n");
		
		arvoreBinaria(vet);

	}
	
	public static void arvoreBinaria(int[] vet) {
		long iniciaTempo;
		long paraTempo;
		long tempoFinal;
		Tree arv = new Tree();
		
		iniciaTempo = System.nanoTime();
		for(int i=0; i<1000; i++) {
			arv.inserir(vet[i]);
		}
		paraTempo = System.nanoTime();
		tempoFinal = paraTempo - iniciaTempo;
		System.out.println("===== Tempo de inserção na árvore binária: " + (tempoFinal/1000) + "ms=====\n");
		
		//Buscando o valor 50
		iniciaTempo = System.nanoTime();
	    No encontrou50 = arv.buscar(50);
		paraTempo = System.nanoTime();
		tempoFinal = paraTempo - iniciaTempo;
	    if(encontrou50 != null) {
	    	System.out.println("O valor 50 foi encontrado!");
	    } else {
	    	System.out.println("O valor 50 NÃO foi encontrado!");
	    }
	    System.out.println("Tempo de busca: " + tempoFinal + "ns\n");
	    
		//Buscando o valor 5000
		iniciaTempo = System.nanoTime();
	    No encontrou5000 = arv.buscar(5000);
		paraTempo = System.nanoTime();
		tempoFinal = paraTempo - iniciaTempo;
	    if(encontrou5000 != null) {
	    	System.out.println("O valor 5000 foi encontrado!");
	    } else {
	    	System.out.println("O valor 5000 NÃO foi encontrado!");
	    }
	    System.out.println("Tempo de busca: " + tempoFinal + "ns");
	}
	
	//ShellSort
    static int[] shellSort(int arr[]) {
		long iniciaTempo;
		long paraTempo;
		long tempoFinal;
		
		iniciaTempo = System.nanoTime();
        int n = arr.length;
        //aqui, o h(gap) é definido inicialmente como a metade do
        //tamanho do array, e vai sendo dividido pela metade
        for (int gap = n/2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i += 1) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
        paraTempo = System.nanoTime();
		tempoFinal = paraTempo - iniciaTempo;
		System.out.println("===== Tempo de inserção na vetor ordenado: " + (tempoFinal/1000) + "ms=====\n");
        return arr;
    }
    
    static int binarySearch(int a[], int l, int r, int x)
    {
        while (l <= r) {
            int m = (l + r) / 2;

            // Index of Element Returned
            if (a[m] == x) {
                return m;

            // If element is smaller than mid, then
            // it can only be present in left subarray
            // so we decrease our r pointer to mid - 1 
            } else if (a[m] > x) {
                r = m - 1;

            // Else the element can only be present
            // in right subarray
            // so we increase our l pointer to mid + 1
            } else {
              l = m + 1;
            }  
        }

        // No Element Found
        return -1;
    }
	
}