#Nome: Marcos Lucas da Silva (RA: 140782)
#POO 2022/2 - 03/10/2022
#Atividade - Pilha e Fila em Python OOP

from stack import Stack
from queue import Queue

#Função da pilha
def test_stack():
    list1 = Stack() #Define list1 como pilha
    list1.push(1) #Empilha o elemento 1
    list1.push(2) #Empilha o elemento 2
    p = list1.pop() #Remove o topo da pilha
    assert p == 2

#Função da lista
def test_queue():
    list2 = Queue() #Define list2 como fila
    list2.enqueue(1) #Insere o elemento 1
    list2.enqueue(2) #Insere o elemento 2
    d = list2.dequeue() #Remove o primeiro da fila
    assert d == 1 
    