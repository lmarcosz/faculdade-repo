/*
 * Universidade Federal de São Paulo - UNIFESP ICT
 * Algoritmos e Estruturas de Dados 2 (2024/2) - Turma I - Profa Dra Lilian Berton
 * Nome: Marcos Lucas da Silva (RA: 140782)
 * 
 * Trabalho 2 - Recuperação de Imagens Usando Árvores B
 * 
 * Referências:
 * - https://github.com/biello/B-Tree
 * - https://www.geeksforgeeks.org/b-tree-in-java/
 * - https://www.programiz.com/dsa/deletion-from-a-b-tree
 */

package aed2.trabalho2;

import java.awt.Desktop;
import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Teste {

	public static void main(String[] args) throws Exception{
		String dirPath = "C:\\Users\\mluca\\eclipse-workspace\\Trabalho2_AED2\\src\\aed2\\trabalho2\\repo\\"; //CAMINHO DO DIRETÓRIO DAS IMAGENS
		Scanner scan = new Scanner(System.in);
		File folder = new File(dirPath); //Arquivo pasta do diretório
		File[] files = folder.listFiles(); //Lista com os nomes dos arquivos do diretório
		BTree bTree = new BTree(3); //Cria uma Árvore B com t=3
		String chave;
		String fname;
		String rotulo;
		boolean aux;
		boolean foundNode; //Indica se o valor especificado foi encontrado na árvore
		char op; //Opção de escolha do menu
		
		do {
			op = menu();
			switch(op) {
				case '1': //Insere imagem individualmente
					chave = scan.next();
					foundNode = bTree.SearchKey(chave);
			        if (foundNode) { //Se já existir a chave na árvore, não ocorrerá a inserção
			        	System.out.println("Já está inserida na árvore!");
			        } else {
			        	aux = false;
			        	for(File f: files) { 
			        		if(f.isFile()) {
			        			fname = f.getName().substring(0, (f.getName().length()) - 4);
			        			if(chave.equals(fname)) { //A chave só será inserida se ela existir no repositório
			        				bTree.Insert(chave);
			        				System.out.println(chave + " inserida!\n");
			        				aux = true;
			        				break;
			        			}
			        		}
			        	}
			        	if(aux==false) { //Caso ela não exista no repositório
			        		System.out.println(chave + " não existe no repositório!\n");
			        	}
			        }
					break;
				case '2': //Insere todas as imagens do repositório
					int tam;
					for(File f: files) {
						if(f.isFile()) {
							tam = f.getName().length();
							fname = f.getName().substring(0, tam-4);
							foundNode = bTree.SearchKey(fname);
					        if (!foundNode) { //Para evitar redundância se já houver alguma chave do repositório na árvore 
					        	bTree.Insert(fname);
					        	System.out.println(fname + " inserida!");
					        }
						}
					}
					break;
				case '3': //Busca e abre imagens por rótulo
					rotulo = scan.next();
					aux = false;
					for(int i=1; i<6; i++) { //Procura as 5 imagens com o rótulo especificado e abre as que estiverem na árvore
						chave = rotulo + Integer.toString(i) + "";
						foundNode = bTree.SearchKey(chave); 
				        if (foundNode) {
				        	openImage(chave, dirPath);
				            aux = true;
				        }
					}
					if(!aux) { //Caso não exista nenhuma imagem com o rótulo inserido
						System.out.println("Não existem imagens com o rótulo inserido!");
					}
					break;
				case '4': //Imprime as chaves da Árvore B em ordem
					System.out.println("Árvore B em ordem: ");
					bTree.Show();
					break;
				case '5': //Exclui as imagens por rótulo
					rotulo = scan.next();
					aux = false;
					for(int i=1; i<6; i++) { //Procura as 5 imagens com o rótulo especificado e exclui as que estiverem na árvore
						chave = rotulo + String.valueOf(i) + "";
						foundNode = bTree.SearchKey(chave);
				        if (foundNode) {
				            bTree.Remove(chave);
				            System.out.println(chave + " removida!");
				            aux = true;
				        }
					}
					if(!aux) { //Caso não exista nenhuma imagem com o rótulo inserido
						System.out.println("Não existem imagens com o rótulo inserido!");
					}
					break;
				default:
			}
			
		} while(op!='0'); //Sai do loop de menu, indicando o fim do programa
		
		System.out.print("Fim de programa.");
    }
	
	//Função para o menu
	public static char menu() {
		Scanner scan = new Scanner(System.in);
		char op;
		System.out.println("================MENU================");
		do {	
			System.out.println("(1) Inserir imagem individualmente;");
			System.out.println("(2) Inserir todas as imagens;");
			System.out.println("(3) Buscar imagens por rótulo;");
			System.out.println("(4) Imprimir árvore;");
			System.out.println("(5) Excluir imagens por rótulo;");
			System.out.print("(0) Sair.\n=>");
			op = scan.next().charAt(0);
			System.out.println();
			if(op!='0' && op!='1' && op!='2' && op!='3' && op!='4' && op!='5') {
				System.out.println("Insira uma opção válida!\n");
			}
		} while(op!='0' && op!='1' && op!='2' && op!='3' && op!='4' && op!='5');
		return op;
	}
	
	//Função para abrir uma imagem
	public static void openImage(String image, String dirPath) throws IOException{
		File f = new File(dirPath + "" + image + ".jpg"); //Concatenando o caminho do diretório, nome da imagem (chave) e formato
		Desktop d = Desktop.getDesktop();
		System.out.println("Abrindo " + image + "...");
		d.open(f); //Abre o arquivo da imagem no desktop
	}
	
}
