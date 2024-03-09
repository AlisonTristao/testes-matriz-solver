import pandas as pd
import matplotlib.pyplot as plt
import time

# Carregar o arquivo CSV
with open('pontos.csv', 'r') as file:
    lines = file.readlines()

# Converter cada linha em uma lista de pontos (x, y)
data = []
for line in lines:
    points = line.strip().split(';')[1:-1]  # Ignorar o primeiro e o último elemento (7.0 e '')
    points = [tuple(map(float, point.strip('()').split(','))) for point in points]
    data.append(points)

# Plotar cada linha com um intervalo de tempo
for points in data:
    plt.clf()  # Limpar o gráfico antes de plotar os novos pontos
    x, y = zip(*points)
    plt.scatter(x, y, marker='o')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Pontos')
    plt.grid(True)
    plt.xlim(-50, 50)  # Definindo limites x para cobrir de -10 a 10
    plt.ylim(-50, 50)  # Definindo limites y para cobrir de -10 a 10
    plt.gca().set_aspect('equal', adjustable='box')  # Definir o aspecto do gráfico como quadrado
    plt.draw()
    plt.pause(0.3)  # Intervalo de 0.5 segundos entre cada linha

plt.show()
