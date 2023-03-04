import numpy as np
import matplotlib.pyplot as plt

# Leer datos
data = np.loadtxt('forward_difference_error.txt')
data_2 = np.loadtxt('central_difference_error.txt')
data_3 = np.loadtxt('central_difference_error_h.txt')
# Graficar
x = np.linspace(-np.pi/2, np.pi/2, len(data))
plt.plot(x, data)
plt.xlabel('x')
plt.ylabel('Error porcentual')
plt.title('Error en el intervalo ]-pi/2, pi/2[ para el método de forward difference')
plt.grid(True)

x_2 = np.linspace(-np.pi/2, np.pi/2, len(data))
plt.plot(x, data)
plt.xlabel('x')
plt.ylabel('Error porcentual')
plt.title('Error en el intervalo ]-pi/2, pi/2[ para el método de central difference')
plt.grid(True)

h_values = data[:, 0]
errors = data[:, 1]
plt.loglog(h_values, errors)
plt.xlabel('h')
plt.ylabel('Error porcentual')
plt.title('Error en función de h, en pi/3 para el método de central difference')
plt.grid(True)


# Guardar gráfica
plt.savefig('err_derF.pdf', bbox_inches='tight')

plt.savefig('err_derC.pdf', bbox_inches='tight')

plt.savefig('err_der_h.pdf', bbox_inches='tight')