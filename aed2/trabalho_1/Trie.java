package aed2.trabalho1;

public class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) { // Percorre os caracteres da string
            if (node.children[c] == null) {
                node.children[c] = new TrieNode(); // Cria o nó filho se não existir
            }
            node = node.children[c]; // Move para o próximo nó
        }
        node.count++; // Incrementa o contador ao final da palavra
    }

    public String[] getSortedStrings(int size) {
        String[] result = new String[size];
        int[] index = {0}; // Usamos um array para manipular o índice de forma mutável
        collectStrings(root, new StringBuilder(), result, index);
        return result;
    }

    private void collectStrings(TrieNode node, StringBuilder prefix, String[] result, int[] index) {
        if (node == null) return; // Caso base: nó inexistente
        if (node.count > 0) {
            for (int i = 0; i < node.count; i++) { // Adiciona a string repetida vezes igual ao contador
                result[index[0]++] = prefix.toString();
            }
        }
        // Percorre os filhos em ordem crescente
        for (int i = 0; i < node.children.length; i++) {
            if (node.children[i] != null) {
                collectStrings(node.children[i], prefix.append((char) i), result, index);
                prefix.deleteCharAt(prefix.length() - 1); // Remove o caractere ao retroceder
            }
        }
    }
}