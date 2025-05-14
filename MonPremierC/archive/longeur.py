import matplotlib.pyplot as plt
import numpy as np

# Coordonnées des vecteurs
origin = [0, 0]
v1 = [7, 4]
v2 = [1, 2]

# Tracer les vecteurs
plt.quiver(*origin, *v1, angles='xy', scale_units='xy', scale=1, color='blue', label='Vector v1')
plt.quiver(*origin, *v2, angles='xy', scale_units='xy', scale=1, color='green', label='Vector v2')

# Tracer la distance entre les vecteurs
plt.plot([v1[0], v2[0]], [v1[1], v2[1]], 'r--', label='Distance')

# Configurer l'affichage
plt.xlim(-1, 5)
plt.ylim(-1, 5)
plt.grid()
plt.legend()
plt.show()
