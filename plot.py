import matplotlib.pyplot as plt
import csv
from matplotlib.patches import Circle

# Abrir o arquivo CSV em modo de leitura
with open("pontos.csv", "r") as csvfile:

    # Criar um leitor de CSV
    reader = csv.reader(csvfile, delimiter=";")

    # Pular a linha de cabeçalho
    next(reader, None)

    # Para cada linha no arquivo CSV
    for row in reader:

        # Obter o índice da linha
        index = row[0]

        # Obter as coordenadas x e y
        coordenadas_xy = row[1:len(row)-2]
 
        # Obter o raio do círculo, deslocamento em x e em y estimados
        dados_circulo1 = row[len(row)-2:len(row)-1]

        # Obter o raio do círculo, deslocamento em x e em y corretos
        dados_circulo0 = row[len(row)-1:]

        # Extrair coordenadas x e y
        x = []
        y = []
        for coordenada in coordenadas_xy:
            valor_x, valor_y = eval(coordenada)
            x.append(valor_x)
            y.append(valor_y)

        # Contar elementos do círculo
        raio0, deslocamento_x0, deslocamento_y0 = eval(dados_circulo0[0])
        raio1, deslocamento_x1, deslocamento_y1 = eval(dados_circulo1[0])

        # Limpar o gráfico antes de plotar os novos pontos
        plt.clf()

        # Plotar pontos
        plt.scatter(x, y, marker='o', color='blue')

        # Plotar círculo
        circulo0 = Circle((deslocamento_x0, deslocamento_y0), raio0, linewidth=2, facecolor='none', edgecolor='red')
        plt.gca().add_patch(circulo0)

        # Plotar círculo
        circulo1 = Circle((deslocamento_x1, deslocamento_y1), raio1, linewidth=2, facecolor='none', edgecolor='green')
        plt.gca().add_patch(circulo1)

        # Configurar labels, título e grid
        plt.xlabel('x')
        plt.ylabel('y')
        plt.title('Pontos e Círculos')
        plt.grid(True)

        # Definir limites do gráfico
        plt.xlim(-50, 50)  # Ajuste de acordo com seus dados
        plt.ylim(-50, 50)  # Ajuste de acordo com seus dados

        # Manter aspecto do gráfico quadrado
        plt.gca().set_aspect('equal', adjustable='box')

        # Mostrar o gráfico por 0.5 segundos
        plt.draw()
        plt.pause(0.5)

# Mostrar o plot final
plt.show()
