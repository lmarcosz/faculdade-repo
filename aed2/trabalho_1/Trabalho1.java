package aed2.trabalho1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class Trabalho1 {

	public static void main(String[] args) throws Exception {
		
		Scanner scan = new Scanner(System.in);
		
		int MAX_TAM = 9821;
		
		String[] vetOcc = new String[MAX_TAM];
		String[] vetState = new String[MAX_TAM];
		String[] vetDate = new String[MAX_TAM];
		String[] vetHour = new String[MAX_TAM];
		
		String filePath1 = "C:\\Users\\mluca\\eclipse-workspace\\Trabalho1_AED2\\src\\aed2\\trabalho1\\ocorrencia.csv";
		String line = "";
		
		try {
			BufferedReader br1 = new BufferedReader(new FileReader(filePath1));
			
			int index = -1;
			while((line = br1.readLine()) != null) {
				if(index>=0) {
					String[] columns1 = line.split(";");
					String[] date = columns1[12].split("/");
					String[] hour = columns1[13].split(":");
					
					vetOcc[index] = columns1[5];
					vetState[index] = columns1[9];
					vetDate[index] = date[2] + date[1] + date[0];
					vetHour[index] = hour[0];
				}
				index++;
			}
			
			br1.close();
		
		} catch(FileNotFoundException e){
			e.printStackTrace();
		} catch(IOException e){
			e.printStackTrace();
		}
		
		char op = '4';
		boolean flagWrite = false;
		
		while(op!='0') {
			System.out.println("\n== MENU ==\nInsira a opção desejada: ");
			System.out.print("1) Visualizar dados dos vetores\n2) Ordenar todos os vetores\n0) Finalizar programa\n=> ");
			op = scan.next().charAt(0);
			switch(op) {
				case '0':
					op = '0';
					break;
				case '1':
					char opVet = '7';
					while(opVet!='0') {
						System.out.println("\n	== VISUALIZAR DADOS ==\n	Insira a opção desejada: ");
						System.out.println("	a) Tipo");
						System.out.println("	b) Estado(UF)");
						System.out.println("	c) Data");
						System.out.println("	d) Hora");
						System.out.println("	=> ");
						opVet = scan.next().charAt(0);
						
						switch(opVet) {
							case 'a':
								printArray(vetOcc);
								opVet = '0';
								break;
							case 'b':
								printArray(vetState);
								opVet = '0';
								break;
							case 'c':
								printArray(vetDate);
								opVet = '0';
								break;
							case 'd':
								printArray(vetHour);
								opVet = '0';
								break;
							default:
								System.out.println("	Insira uma opção válida!");
								opVet = '7';
						}
					}
					break;
					
				case '2':
					System.out.println("\nOrdenando todos os vetores... \n");
					
					System.out.println("Tipo de Ocorrência");
					ordenar(vetOcc);
					
					System.out.println("\nEstado");
					ordenar(vetState);			

					System.out.println("\nData");
					ordenar(vetDate);
					
					System.out.println("\nHora");
					ordenar(vetHour);
					
					flagWrite = true;
					break;
				default:
					System.out.println("Insira uma opção válida!\n");
					op = '4';
			}
			
		}
		
		writeFile("num-occor.txt", vetOcc);
		writeFile("state-occor.txt", vetState);
		writeFile("data-occor.txt", vetDate);
		writeFile("hora-occor.txt", vetHour);
	}
    
	//Imprime todos os dados de um array
    public static void printArray(String arr[]) {
        for (int i = 0; i < arr.length; i++)
            System.out.println("	" + arr[i]);
    }
    
    //Executa os algoritmos de ordenação
    public static void ordenar(String arr[]) {
		trieSort(arr);
		radixSort(arr);
    }
    
    //Escrita dos resultados ordenados
    public static void writeFile(String filename, String[] arr) throws IOException {
    	String s = "C:\\Users\\mluca\\eclipse-workspace\\Trabalho1_AED2\\src\\aed2\\trabalho1\\resultados-ordenados\\";
    	s += filename;
    	try {
            FileWriter writer = new FileWriter(s); // Changed file path
            for (int i=0; i<arr.length; i++) {
            	if(filename=="data-occor.txt") {
            		String auxAno = "" + arr[i].charAt(0) + arr[i].charAt(1) + arr[i].charAt(2) + arr[i].charAt(3);
            		//String auxMes = "" + arr[i].charAt(4) + arr[i].charAt(5);
            		//String auxDia = "" + arr[i].charAt(6) + arr[i].charAt(7);
            		writer.write(auxAno+"\n");
            	} else {
            		writer.write(arr[i] + "\n");
            	}
            }
            writer.close();
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
    
    //RADIX SORT
    public static String[] radixSort(String[] strings) {
		long iniciaTempo;
		long paraTempo;
		long tempoFinal;
		
		iniciaTempo = System.currentTimeMillis();
    	
    	//Pega o tamanho da maior string do array
		int maxLength = 0;
		for(String s: strings) {
			maxLength = Math.max(maxLength, s.length());
		}
    	
        // Vai do caractere menos significativo para o mais significativo
        for (int position = maxLength - 1; position >= 0; position--) {
        	
        	//BUCKET SORT
            // Usa buckets para os 256 caracteres ASCII
            @SuppressWarnings("unchecked")
			List<String>[] buckets = new ArrayList[256];
            for (int i = 0; i < 256; i++) {
                buckets[i] = new ArrayList<>();
            }

            // Coloca cada string no bucket correspondente ao caractere na posição atual
            for (String s : strings) {
                // Pega o caractere atual ou usa 0 para strings mais curtas
                int charIndex = position < s.length() ? s.charAt(position) : 0;
                buckets[charIndex].add(s);
            }

            // Refaz o array de strings com base nos buckets
            int index = 0;
            
            for (List<String> bucket : buckets) {
                for (String s : bucket) {
                    strings[index++] = s;
                }
            }
        }
        
		paraTempo = System.currentTimeMillis();
		tempoFinal = paraTempo - iniciaTempo;
    	System.out.println(" - Radix Sort => " + tempoFinal + " ms");
        
        return strings;
    }
    
    //TRIE SORT
    public static String[] trieSort(String[] arr) {
		long iniciaTempo;
		long paraTempo;
		long tempoFinal;
		
		iniciaTempo = System.currentTimeMillis();
		
    	Trie trie = new Trie(); //Cria árvore trie
    	
    	for(String s: arr) {
    		trie.insert(s); //Insere cada string do array na árvore
    	}
    	
    	//Recebe a string ordenada
    	String[] sortedStrings = trie.getSortedStrings(arr.length);
    	
		paraTempo = System.currentTimeMillis();
		tempoFinal = paraTempo - iniciaTempo;
    	System.out.println(" - Trie Sort => " + tempoFinal + " ms");
    	
    	return sortedStrings;
    }
    
}
