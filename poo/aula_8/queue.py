class Queue():
    #Inicia uma fila vazia
    def __init__(self):
        self.list = []

    #Função p/ add um elemento na fila
    def enqueue(self, n):
        self.list.append(n) #adicionando o elemento no final da fila

    #Função p/ remover um elemento na fila
    def dequeue(self):
        k = self.list[0] #elemento na primeira posicao da fila
        self.list.remove(k) #removendo o elemento k
        return k
