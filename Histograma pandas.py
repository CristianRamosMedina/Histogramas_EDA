import pandas as pd
import matplotlib.pyplot as plt
from google.colab import drive
drive.mount('/content/drive')

file_path = '/content/drive/MyDrive/EDA/resultados 5000.txt'  


with open(file_path, 'r') as file:
    lines = file.readlines()


values = [float(line.strip()) for line in lines]

plt.hist(values, bins=10,rwidth=0.6, color='#607c8e')
plt.title('Histograma de la dimensión 5000')
plt.xlabel('Valor')
plt.ylabel('Frecuencia')
plt.grid(axis='y', alpha=0.75)
plt.xlim(0,30)
plt.show()