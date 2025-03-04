# Universidade Federal de São Paulo - UNIFESP ICT
# Algoritmos e Estruturas de Dados 2 (2024/2) - Turma I - Profa Dra Lilian Berton
# Nome: Marcos Lucas da Silva (RA: 140782)
#
# Trabalho 3 - Análise de dados em formato de grafos
#
# Referências:
# - https://snap.stanford.edu/data/feather-lastfm-social.html
# - https://www.geeksforgeeks.org/network-centrality-measures-in-a-graph-using-networkx-python/?ref=header_outind
# - https://networkx.org/documentation/stable/tutorial.html
#

import matplotlib.pyplot as plt
import networkx as nx
import numpy as np
import scipy as sp
import random
import time

def show_menu(a):
    if a:
        print("==========MENU==========")
    else:
        print("\nINSIRA UMA OPÇÃO VÁLIDA!")
    print("[1] Plotar grafo")
    print("[2] Graus")
    print("[3] Closeness")
    print("[4] Betweenness")
    print("[5] Pesquisar vértice")
    print("[0] Sair")
    option = input("=> ")
    return option

def plot_graph(graph):
    start = time.perf_counter()
    nx.draw_spring(graph, node_size=20, linewidths=0, width=0.1, node_color="blue", with_labels=False)
    plt.savefig("graph.png", dpi=1000)
    end = time.perf_counter()
    print(f"Tempo de execução para desenhar e plotar o grafo = {end-start:.6f}s\n")
    plt.show()

def show_degree(graph):
    start = time.perf_counter()
    gdegree_unsorted = nx.degree_centrality(graph) #Cálculo do Grau de Centralidade
    end = time.perf_counter()
    alg_time = end - start
    start = time.perf_counter()
    gdegree_dict = dict(sorted(gdegree_unsorted.items(), key=lambda item: item[1])) #Ordenação do dicionário
    end = time.perf_counter()
    sort_time = end - start
    print(f"{'Vértice':<10} {'Grau':<10} {'Grau de centralidade':<10}")
    print("-" * 43)
    for vert, valor in gdegree_dict.items():
        print(f"{vert:<10} {graph.degree(vert):<10}{valor:<10}") #Cálculo simultâneo do grau bruto do vértice
    print("\nTempos de execução:")
    print(f"- Cálculo do Grau de Centralidade = {alg_time:.6f}s")
    print(f"- Ordenação = {sort_time:.6f}s\n")

def show_closeness(graph):
    start = time.perf_counter()
    gcloseness_unsorted = nx.closeness_centrality(graph) #Cálculo do Closeness
    end = time.perf_counter()
    alg_time = end - start
    start = time.perf_counter()
    gcloseness_dict = dict(sorted(gcloseness_unsorted.items(), key=lambda item: item[1])) #Ordenação do dicionário
    end = time.perf_counter()
    sort_time = end - start
    print(f"{'Vértice':<10} {'Closeness':<10}")
    print("-" * 34)
    for vert, valor in gcloseness_dict.items():
        print(f"{vert:<10} {valor:<10}")
    print("\nTempos de execução:")
    print(f"- Cálculo do Closeness = {alg_time:.6f}s")
    print(f"- Ordenação = {sort_time:.6f}s\n")

def show_betweenness(graph):
    start = time.perf_counter()
    gbetweenness_unsorted = nx.betweenness_centrality(graph) #Cálculo do Betweenness
    end = time.perf_counter()
    alg_time = end - start
    start = time.perf_counter()
    gbetweenness_dict = dict(sorted(gbetweenness_unsorted.items(), key=lambda item: item[1])) #Ordenação do dicionário
    end = time.perf_counter()
    sort_time = end - start
    print(f"{'Vértice':<10} {'Betweenness':<10}")
    print("-" * 34)
    for vert, valor in gbetweenness_dict.items():
        print(f"{vert:<10} {valor:<10}")
    print("\nTempos de execução:")
    print(f"- Cálculo do Betweenness = {alg_time:.6f}s")
    print(f"- Ordenação = {sort_time:.6f}s\n")

def search_node(graph):
    for node in graph.nodes: #Percorrendo de forma iterativa os nós do grafo
        if node == node_value:
            return True #Se o nó for encontrado, a função retorna True
    return False

#-------Início do programa-------
#Para manter sempre o mesmo plot de grafo
random.seed(0)
np.random.seed(0)

#Leitura das conexões de arestas do arquivo txt e geração do grafo
start = time.perf_counter()
G = nx.read_edgelist("lastfm_asia_edges.txt", create_using=nx.Graph(), nodetype=int)
end = time.perf_counter()
print(f"Tempo de execução para importar os dados e gerar o grafo = {end - start:.6f}s\n")

#Loop para o menu
aux = True
aux_menu = True
while aux:
    op = show_menu(aux_menu) #Opção de menu inserida
    aux_menu = True
    match op:
        case "1":
            plot_graph(G) #Plota o grafo
        case "2":
            show_degree(G) #Apresenta os graus de centralidade dos vértices
        case "3":
            show_closeness(G) #Apresenta os Closeness dos vértices
        case "4":
            show_betweenness(G) #Apresenta os Betweenness dos vértices
        case "5":
            while True:
                try:
                    inpt = input("Número do vértice => ")
                    node_value = int(inpt)
                    break
                except ValueError:
                    print("\nINSIRA UM VALOR VÁLIDO!")
            start = time.perf_counter()
            found = search_node(G) #Busca vértice
            end = time.perf_counter()
            search_time = end - start
            if found:
                print("Vértice encontrado!")
            else:
                print("O vértice não foi encontrado no grafo!")
            print(f"Tempo de execução = {search_time:.6f}s\n")
        case "0":
            aux = False #Opção para sair do loop e encerrar o programa
        case _:
            aux_menu = False #Caso a opção de menu inserida seja inválida
