package aed2.trabalho2;

public class BTree {

  private int T; //Variável interna de t

  public class Node {
    int n; //Quantidadede de chaves no nó
    String key[] = new String[2 * T - 1]; //Chaves
    Node child[] = new Node[2 * T]; //Filhos do nó
    boolean leaf = true; //Indica se o nó é folha

    //Localiza a posição da chave no nó
    public int Find(String k) {
      for (int i = 0; i < this.n; i++) {
        if (this.key[i].equals(k)) {
          return i;
        }
      }
      return -1;
    }
  }
  
  //Construtor da árvore com a especificação de t como parâmetro
  public BTree(int t) {
    T = t;
    root = new Node();
    root.n = 0;
    root.leaf = true;
  }

  private Node root; //Nó raiz

  //Busca por uma chave
  public boolean SearchKey(String key) {
	    Node x = Search(root, key);
	    return x != null;
  } 
 
  private Node Search(Node x, String key) {
    int i = 0;
    if (x == null) {
      return null;
    }
    for (i = 0; i < x.n; i++) {
      if (key.compareTo(x.key[i]) < 0) {
        break;
      }
      if (key.equals(x.key[i])) {
        return x;
      }
    }
    if (x.leaf) {
      return null;
    } else {
      return Search(x.child[i], key);
    }
  }

  //Divide um nó cheio
  private void Split(Node x, int pos, Node y) {
    Node z = new Node();
    z.leaf = y.leaf;
    z.n = T - 1;
    for (int j = 0; j < T - 1; j++) {
      z.key[j] = y.key[j + T];
    }
    if (!y.leaf) {
      for (int j = 0; j < T; j++) {
        z.child[j] = y.child[j + T];
      }
    }
    y.n = T - 1;
    for (int j = x.n; j >= pos + 1; j--) {
      x.child[j + 1] = x.child[j];
    }
    x.child[pos + 1] = z;

    for (int j = x.n - 1; j >= pos; j--) {
      x.key[j + 1] = x.key[j];
    }
    x.key[pos] = y.key[T - 1];
    x.n = x.n + 1;
  }

  //Inserir uma chave
  public void Insert(final String key) {
    Node r = root;
    if (r.n == 2 * T - 1) {
      Node s = new Node();
      root = s;
      s.leaf = false;
      s.n = 0;
      s.child[0] = r;
      Split(s, 0, r);
      _Insert(s, key);
    } else {
      _Insert(r, key);
    }
  }

  private void _Insert(Node x, String k) {
    if (x.leaf) {
      int i = 0;
      for (i = x.n - 1; i >= 0 && k.compareTo(x.key[i]) < 0; i--) {
        x.key[i + 1] = x.key[i];
      }
      x.key[i + 1] = k;
      x.n = x.n + 1;
    } else {
      int i = 0;
      for (i = x.n - 1; i >= 0 && k.compareTo(x.key[i]) < 0; i--) {
      }
      i++;
      Node tmp = x.child[i];
      if (tmp.n == 2 * T - 1) {
        Split(x, i, tmp);
        if (k.compareTo(x.key[i]) > 0) {
          i++;
        }
      }
      _Insert(x.child[i], k);
    }
  }
  
  	//Exibe a árvore em ordem
	public void Show() {
	   ShowInOrder(root);
	   System.out.println();
	}
	
	private void ShowInOrder(Node node) {
	   if (node == null) return;
	
	   for (int i = 0; i < node.n; i++) {
	       //Visita o filho à esquerda da chave atual
	       if (!node.leaf) {
	           ShowInOrder(node.child[i]);
	       }
	       //Exibe a chave atual
	       System.out.println(node.key[i]);
	   }
	
	   //Visita o filho à direita do último elemento
	   if (!node.leaf) {
	       ShowInOrder(node.child[node.n]);
	   }
	}
	
	//Remove a chave da árvore
	public boolean Remove(String key) {
	    if (!Contain(key)) { 
	        System.out.println("Chave '" + key + "' não encontrada na árvore.");
	        return false;
	    }

	    RemoveFromNode(root, key);

	    //Se a raiz ficar vazia, ajuste a raiz
	    if (root.n == 0) {
	        if (root.leaf) {
	            root = null; //Árvore fica vazia
	        } else {
	            root = root.child[0]; //Primeiro filho se torna a nova raiz
	        }
	    }
	    return true;
	}

	private boolean Contain(String key) {
		return Search(root, key) != null;
	}

	//Remove a chave do nó
	private void RemoveFromNode(Node node, String key) {
	    int idx = findKey(node, key);

	    if (idx < node.n && node.key[idx].equals(key)) {
	        // Caso 1: A chave está no nó atual
	        if (node.leaf) {
	            // Caso 1a: O nó é uma folha, remova diretamente
	            removeFromLeaf(node, idx);
	        } else {
	            // Caso 1b: O nó não é uma folha
	            removeFromNonLeaf(node, idx);
	        }
	    } else {
	        // Caso 2: A chave não está no nó atual
	        if (node.leaf) {
	            // Caso 2a: A chave não existe
	            System.out.println("Chave não encontrada.");
	            return;
	        }

	        // Caso 2b: A chave pode estar em um filho
	        boolean flag = (idx == node.n);

	        if (node.child[idx].n < T) {
	            fill(node, idx);
	        }

	        // Após preencher, vá para o filho correto
	        if (flag && idx > node.n) {
	            RemoveFromNode(node.child[idx - 1], key);
	        } else {
	            RemoveFromNode(node.child[idx], key);
	        }
	    }
	}

	//Remove de uma folha
	private void removeFromLeaf(Node node, int idx) {
	    for (int i = idx + 1; i < node.n; ++i) {
	        node.key[i - 1] = node.key[i];
	    }
	    node.n--;
	}

	//Remove de um nó não folha
	private void removeFromNonLeaf(Node node, int idx) {
	    String key = node.key[idx];

	    if (node.child[idx].n >= T) {
	        String pred = getPredecessor(node, idx);
	        node.key[idx] = pred;
	        RemoveFromNode(node.child[idx], pred);
	    } else if (node.child[idx + 1].n >= T) {
	        String succ = getSuccessor(node, idx);
	        node.key[idx] = succ;
	        RemoveFromNode(node.child[idx + 1], succ);
	    } else {
	        merge(node, idx);
	        RemoveFromNode(node.child[idx], key);
	    }
	}

	//Obtém o predecessor da chave
	private String getPredecessor(Node node, int idx) {
	    Node cur = node.child[idx];
	    while (!cur.leaf) {
	        cur = cur.child[cur.n];
	    }
	    return cur.key[cur.n - 1];
	}

	//Obtém o sucessor da chave
	private String getSuccessor(Node node, int idx) {
	    Node cur = node.child[idx + 1];
	    while (!cur.leaf) {
	        cur = cur.child[0];
	    }
	    return cur.key[0];
	}

	//Preenche um filho com chaves insuficientes
	private void fill(Node node, int idx) {
	    if (idx != 0 && node.child[idx - 1].n >= T) {
	        borrowFromPrev(node, idx);
	    } else if (idx != node.n && node.child[idx + 1].n >= T) {
	        borrowFromNext(node, idx);
	    } else {
	        if (idx != node.n) {
	            merge(node, idx);
	        } else {
	            merge(node, idx - 1);
	        }
	    }
	}

	private void borrowFromPrev(Node node, int idx) {
	    Node child = node.child[idx];
	    Node sibling = node.child[idx - 1];

	    for (int i = child.n - 1; i >= 0; --i) {
	        child.key[i + 1] = child.key[i];
	    }

	    if (!child.leaf) {
	        for (int i = child.n; i >= 0; --i) {
	            child.child[i + 1] = child.child[i];
	        }
	    }

	    child.key[0] = node.key[idx - 1];

	    if (!node.leaf) {
	        child.child[0] = sibling.child[sibling.n];
	    }

	    node.key[idx - 1] = sibling.key[sibling.n - 1];

	    child.n += 1;
	    sibling.n -= 1;
	}

	private void borrowFromNext(Node node, int idx) {
	    Node child = node.child[idx];
	    Node sibling = node.child[idx + 1];

	    child.key[child.n] = node.key[idx];

	    if (!child.leaf) {
	        child.child[child.n + 1] = sibling.child[0];
	    }

	    node.key[idx] = sibling.key[0];

	    for (int i = 1; i < sibling.n; ++i) {
	        sibling.key[i - 1] = sibling.key[i];
	    }

	    if (!sibling.leaf) {
	        for (int i = 1; i <= sibling.n; ++i) {
	            sibling.child[i - 1] = sibling.child[i];
	        }
	    }

	    child.n += 1;
	    sibling.n -= 1;
	}

	//Fusão de dois nós filhos
	private void merge(Node node, int idx) {
	    Node child = node.child[idx];
	    Node sibling = node.child[idx + 1];

	    child.key[T - 1] = node.key[idx];

	    for (int i = 0; i < sibling.n; ++i) {
	        child.key[i + T] = sibling.key[i];
	    }

	    if (!child.leaf) {
	        for (int i = 0; i <= sibling.n; ++i) {
	            child.child[i + T] = sibling.child[i];
	        }
	    }

	    for (int i = idx + 1; i < node.n; ++i) {
	        node.key[i - 1] = node.key[i];
	    }

	    for (int i = idx + 2; i <= node.n; ++i) {
	        node.child[i - 1] = node.child[i];
	    }

	    child.n += sibling.n + 1;
	    node.n--;
	}

	//Encontra o índice da chave
	private int findKey(Node node, String key) {
	    int idx = 0;
	    while (idx < node.n && node.key[idx].compareTo(key) < 0) {
	        ++idx;
	    }
	    return idx;
	}

}
