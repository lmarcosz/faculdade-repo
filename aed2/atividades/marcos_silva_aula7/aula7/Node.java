//Marcos Lucas da Silva (140782)
//From GeeksForGeeks
//https://www.geeksforgeeks.org/avl-tree-program-in-java/
//https://www.geeksforgeeks.org/find-the-maximum-depth-or-height-of-a-tree/
package aula7;

public class Node {
    public int key, height;
    Node left, right;

    Node(int d) {
        key = d;
        height = 1;
    }
}
