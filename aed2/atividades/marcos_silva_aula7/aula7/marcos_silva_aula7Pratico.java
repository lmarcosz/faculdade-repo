//Marcos Lucas da Silva (140782)
//From GeeksForGeeks
//https://www.geeksforgeeks.org/avl-tree-program-in-java/
//https://www.geeksforgeeks.org/find-the-maximum-depth-or-height-of-a-tree/
package aula7;

import java.util.Random;

public class marcos_silva_aula7Pratico {

	public static void main(String args[]) {
		Random random = new Random();
		AVLTree tree = new AVLTree();
		long iniciaTempo;
		long paraTempo;
		long tempoFinal;

		//Inserção de números aleatórios na árvore avl
		int auxInsert;
		iniciaTempo = System.nanoTime();
		for(int i=0; i<10000; i++) {
			auxInsert = random.nextInt(100000);
			tree.root = tree.insert(tree.root, auxInsert);
		}
		paraTempo = System.nanoTime();
		tempoFinal = paraTempo - iniciaTempo;
		System.out.println("===== Tempo de inserção na árvore AVL: " + (tempoFinal/1000000) + "ms=====\n");
		
		//Buscando o valor 50
		iniciaTempo = System.nanoTime();
	    Node encontrou50 = tree.buscar(50);
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
	    Node encontrou5000 = tree.buscar(5000);
		paraTempo = System.nanoTime();
		tempoFinal = paraTempo - iniciaTempo;
	    if(encontrou5000 != null) {
	    	System.out.println("O valor 5000 foi encontrado!");
	    } else {
	    	System.out.println("O valor 5000 NÃO foi encontrado!");
	    }
	    System.out.println("Tempo de busca: " + tempoFinal + "ns\n");
		
	    System.out.println("Altura da subárvore esquerda: " + tree.heightTree(tree.root.left));
	    System.out.println("Altura da subárvore direita: " + tree.heightTree(tree.root.right));
	}
}
