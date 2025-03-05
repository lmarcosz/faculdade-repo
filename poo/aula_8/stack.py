class Stack():
    #Inicia uma pilha vazia
    def __init__(self):
        self.list = []
    
    #Função p/ add um elemento no topo da pilha
    def push(self, n):
        self.list.append(n) #

    #Função p/ remover um elemento do topo da pilha
    def pop(self):
        qtd = len(self.list) #Quantidade total de elementos da pilha
        j = self.list[qtd-1] #j recebendo o ultimo do ultimo elemento da pilha
        self.list.remove(j) #Removendo o elemento (j) da pilha
        return j
       