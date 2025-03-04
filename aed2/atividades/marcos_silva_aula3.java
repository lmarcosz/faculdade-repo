package aed2;

import java.util.Random;
import java.util.Scanner;

/*
 * Referências: GeeksForGeeks 
 * 
 * https://www.geeksforgeeks.org/shell-sort/
 * https://www.geeksforgeeks.org/quick-sort-algorithm/
 * https://www.geeksforgeeks.org/heap-sort/
 * https://www.geeksforgeeks.org/merge-sort/
 */

public class marcos_silva_aula3 {

	public static void main(String[] args) {
		Random random = new Random();
		char op = selecionaAlgoritmo();
		int[] vet = new int[100000];
		int aux;
		int pos = vet.length - 1;
		
		//Definindo o vetor aleatório
		for(int i=0; i<vet.length; i++) {
			vet[i] = random.nextInt(1000000);
		}
		ordenarVetor(op, vet, "Aleatório"); //Com o vetor aleatorio
		
		//O vetor já estará em ordem crescente (ordenação anterior)
		ordenarVetor(op, vet, "Ordem crescente"); //Com o vetor em ordem crescente
		
		//Definindo o vetor decrescente
		
		for(int i=0; i<vet.length / 2; i++) {
			aux = vet[i];
			vet[i] = vet[pos];
			vet[pos] = aux;
			pos--;
		}
		ordenarVetor(op, vet, "Ordem decrescente"); //Com o vetor em ordem decrescente
		
	}
	
	static char selecionaAlgoritmo() {
		Scanner scan = new Scanner(System.in);
		System.out.println("Insira o número do algoritmo a ser executado: ");
		System.out.println("[1]ShellSort\n[2]QuickSort\n[3]HeapSort\n[4]MergeSort");
		System.out.print("=> ");
		return scan.next().charAt(0);
	}
	
	static void ordenarVetor(char op, int vet[], String tipoVetor) {
		long iniciaTempo;
		long paraTempo;
		long tempoFinal;
		int n = vet.length;
		
		switch(op) {
			case '1': //ShellSort
				iniciaTempo = System.nanoTime();
				shellSort(vet);
				paraTempo = System.nanoTime();
				tempoFinal = paraTempo - iniciaTempo;
				System.out.println("ShellSort: " + tempoFinal + " ns (" + tipoVetor + ")");
				break;
				
			case '2': //QuickSort
				iniciaTempo = System.nanoTime();
				quickSort(vet, 0, n-1); //Pivô = último elemento do vetor
				paraTempo = System.nanoTime();
				tempoFinal = paraTempo - iniciaTempo;
				System.out.println("QuickSort: " + tempoFinal + " ns (" + tipoVetor + ")");
				break;
			case '3':
				iniciaTempo = System.nanoTime();
				heapSort(vet);
				paraTempo = System.nanoTime();
				tempoFinal = paraTempo - iniciaTempo;
				System.out.println("HeapSort: " + tempoFinal + " ns (" + tipoVetor + ")");
				break;
			case '4':
				iniciaTempo = System.nanoTime();
				mergeSort(vet, 0, n-1);
				paraTempo = System.nanoTime();
				tempoFinal = paraTempo - iniciaTempo;
				System.out.println("MergeSort: " + tempoFinal + " ns (" + tipoVetor + ")");
				break;
			default:
				System.out.println("Opção inválida!");
		}
	}
	
	
	//ShellSort
    static void shellSort(int arr[]) {
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
    }
    
    
    //QuickSort
    // Partition function
    static int partition(int[] arr, int low, int high) {
        
        // Choose the pivot
        int pivot = arr[high];
        
        // Index of smaller element and indicates 
        // the right position of pivot found so far
        int i = low - 1;

        // Traverse arr[low..high] and move all smaller
        // elements to the left side. Elements from low to 
        // i are smaller after every iteration
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        
        // Move pivot after smaller elements and
        // return its position
        swap(arr, i + 1, high);  
        return i + 1;
    }

    // Swap function
    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // The QuickSort function implementation
    static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            
            // pi is the partition return index of pivot
            int pi = partition(arr, low, high);

            // Recursion calls for smaller elements
            // and greater or equals elements
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    
    //HeapSort
    static void heapSort(int arr[]) {
        int n = arr.length;

        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // One by one extract an element from heap
        for (int i = n - 1; i > 0; i--) {

            // Move current root to end
            int temp = arr[0]; 
            arr[0] = arr[i];
            arr[i] = temp;

            // Call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }
    
    static void heapify(int arr[], int n, int i) {
        // Initialize largest as root
        int largest = i; 
        
        // left index = 2*i + 1
        int l = 2 * i + 1; 

        // right index = 2*i + 2
        int r = 2 * i + 2;

        // If left child is larger than root
        if (l < n && arr[l] > arr[largest]) {
            largest = l;
        }

        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest]) {
            largest = r;
        }

        // If largest is not root
        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }

    
    //MergeSort
    // Main function that sorts arr[l..r] using
    // merge()
    static void mergeSort(int arr[], int l, int r)
    {
        if (l < r) {

            // Find the middle point
            int m = l + (r - l) / 2;

            // Sort first and second halves
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            // Merge the sorted halves
            merge(arr, l, m, r);
        }
    }
    
    static void merge(int arr[], int l, int m, int r)
    {
        // Find sizes of two subarrays to be merged
        int n1 = m - l + 1;
        int n2 = r - m;

        // Create temp arrays
        int L[] = new int[n1];
        int R[] = new int[n2];

        // Copy data to temp arrays
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];

        // Merge the temp arrays

        // Initial indices of first and second subarrays
        int i = 0, j = 0;

        // Initial index of merged subarray array
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of L[] if any
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy remaining elements of R[] if any
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
	
}
