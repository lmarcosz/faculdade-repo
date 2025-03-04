package aed2.trabalho1;

public class TrieNode {
    TrieNode[] children = new TrieNode[256];
    int count = 0; // Conta quantas vezes a string termina neste nó
}
