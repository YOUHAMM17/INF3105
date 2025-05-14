import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

class AlgebreLineaire3D:
    def __init__(self):
        self.fig = plt.figure(figsize=(15, 5))
        
    def chapitre1_vecteurs(self):
        """Chapitre 1: Visualisation des vecteurs"""
        ax = self.fig.add_subplot(131, projection='3d')
        ax.set_title("Chapitre 1: Vecteurs")
        
        # Définir les vecteurs
        v1 = np.array([2, 1, 1])
        v2 = np.array([1, 2, 2])
        v_sum = v1 + v2
        
        # Dessiner les vecteurs avec quiver
        ax.quiver(0, 0, 0, v1[0], v1[1], v1[2], color='blue', label='Vecteur 1')
        ax.quiver(0, 0, 0, v2[0], v2[1], v2[2], color='green', label='Vecteur 2')
        ax.quiver(0, 0, 0, v_sum[0], v_sum[1], v_sum[2], color='red', label='Somme')
        
        ax.set_xlabel('X')
        ax.set_ylabel('Y')
        ax.set_zlabel('Z')
        ax.set_xlim([-3, 3])
        ax.set_ylim([-3, 3])
        ax.set_zlim([-3, 3])
        ax.legend()

    def chapitre2_matrices(self):
        """Chapitre 2: Visualisation des transformations matricielles"""
        ax = self.fig.add_subplot(132, projection='3d')
        ax.set_title("Chapitre 2: Transformations")
        
        # Créer des points pour un cube
        points = np.array([[0, 0, 0], [1, 0, 0], [1, 1, 0], [0, 1, 0],
                          [0, 0, 1], [1, 0, 1], [1, 1, 1], [0, 1, 1]])
        
        # Matrice de rotation
        theta = np.pi/4
        R = np.array([[np.cos(theta), -np.sin(theta), 0],
                     [np.sin(theta), np.cos(theta), 0],
                     [0, 0, 1]])
        
        # Appliquer la rotation
        rotated_points = points @ R.T
        
        # Dessiner les cubes
        self._draw_cube(ax, points, 'blue', 'Original')
        self._draw_cube(ax, rotated_points, 'red', 'Transformé')
        
        ax.set_xlabel('X')
        ax.set_ylabel('Y')
        ax.set_zlabel('Z')
        ax.set_xlim([-2, 2])
        ax.set_ylim([-2, 2])
        ax.set_zlim([-2, 2])
        ax.legend()

    def chapitre3_applications(self):
        """Chapitre 3: Applications géométriques"""
        ax = self.fig.add_subplot(133, projection='3d')
        ax.set_title("Chapitre 3: Applications")
        
        # Créer un plan
        x = np.linspace(-2, 2, 10)
        y = np.linspace(-2, 2, 10)
        X, Y = np.meshgrid(x, y)
        Z = 0.5 * X + 0.5 * Y
        
        # Dessiner le plan
        ax.plot_surface(X, Y, Z, alpha=0.3, color='blue', label='Plan')
        
        # Dessiner une droite
        t = np.linspace(-2, 2, 100)
        ax.plot(t, t, t, 'r-', linewidth=2, label='Droite')
        
        ax.set_xlabel('X')
        ax.set_ylabel('Y')
        ax.set_zlabel('Z')
        ax.set_xlim([-2, 2])
        ax.set_ylim([-2, 2])
        ax.set_zlim([-2, 2])
        
        # Astuce pour ajouter une légende avec plot_surface
        ax.plot([], [], [], 'b-', alpha=0.3, label='Plan')
        ax.legend()

    def _draw_cube(self, ax, points, color, label):
        """Dessiner un cube"""
        edges = [[0, 1], [1, 2], [2, 3], [3, 0],
                [4, 5], [5, 6], [6, 7], [7, 4],
                [0, 4], [1, 5], [2, 6], [3, 7]]
        
        # Dessiner la première arête avec label
        edge = edges[0]
        ax.plot3D(points[edge, 0], points[edge, 1], 
                 points[edge, 2], color=color, label=label)
        
        # Dessiner les autres arêtes sans label
        for edge in edges[1:]:
            ax.plot3D(points[edge, 0], points[edge, 1], 
                     points[edge, 2], color=color)

    def visualiser_tous_concepts(self):
        """Visualiser tous les concepts"""
        self.chapitre1_vecteurs()
        self.chapitre2_matrices()
        self.chapitre3_applications()
        plt.tight_layout()
        plt.show()

# Créer et afficher la visualisation
if __name__ == "__main__":
    visualisation = AlgebreLineaire3D()
    visualisation.visualiser_tous_concepts()