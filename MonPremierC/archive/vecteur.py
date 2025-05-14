import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.widgets import Slider, Button, RadioButtons
import matplotlib.gridspec as gridspec

class VectorVisualizer:
    def __init__(self):
        plt.style.use('default')
        self.fig = plt.figure(figsize=(15, 10))
        self.fig.canvas.manager.set_window_title('Visualisation Interactive des Vecteurs')
        
        # Création d'un layout plus sophistiqué avec GridSpec
        gs = gridspec.GridSpec(2, 3, height_ratios=[2, 1], width_ratios=[2, 1, 1])
        
        # Vue 3D principale (plus grande)
        self.ax_main = self.fig.add_subplot(gs[0, :2], projection='3d')
        self.ax_main.set_title('Espace Vectoriel 3D', pad=20, fontsize=14)
        
        # Vues de projection
        self.ax_xy = self.fig.add_subplot(gs[1, 0], projection='3d')
        self.ax_xy.set_title('Projection XY', fontsize=10)
        self.ax_xz = self.fig.add_subplot(gs[1, 1], projection='3d')
        self.ax_xz.set_title('Projection XZ', fontsize=10)
        
        # Zone de contrôle
        self.ax_controls = self.fig.add_subplot(gs[:, 2])
        self.ax_controls.axis('off')
        
        # Valeurs initiales
        self.initial_v1 = np.array([2, 1, 1])
        self.initial_v2 = np.array([1, 2, 2])
        self.v1 = self.initial_v1.copy()
        self.v2 = self.initial_v2.copy()
        
        self.setup_controls()
        
    def setup_3d_view(self, ax, elev=20, azim=45, proj_type=None):
        """Configure une vue 3D avec des options de projection"""
        ax.clear()
        ax.set_xlabel('X')
        ax.set_ylabel('Y')
        ax.set_zlabel('Z')
        ax.set_xlim([-3, 3])
        ax.set_ylim([-3, 3])
        ax.set_zlim([-3, 3])
        ax.grid(True, linestyle='--', alpha=0.3)
        
        if proj_type == 'xy':
            ax.view_init(elev=90, azim=0)  # Vue de dessus
        elif proj_type == 'xz':
            ax.view_init(elev=0, azim=0)   # Vue de face
        else:
            ax.view_init(elev=elev, azim=azim)
            
    def draw_vector(self, start, end, color='blue', label='', linestyle='-', alpha=1.0, ax=None):
        """Dessine un vecteur avec style"""
        if ax is None:
            ax = self.ax_main
            
        vector = end - start
        ax.quiver(start[0], start[1], start[2],
                 vector[0], vector[1], vector[2],
                 color=color, label=label, alpha=alpha,
                 arrow_length_ratio=0.15, linewidth=2)
        
    def draw_projections(self):
        """Dessine les projections des vecteurs"""
        # Projection XY
        v1_xy = self.v1.copy()
        v1_xy[2] = 0
        v2_xy = self.v2.copy()
        v2_xy[2] = 0
        
        self.draw_vector(np.zeros(3), v1_xy, color='blue', alpha=0.5, ax=self.ax_xy)
        self.draw_vector(np.zeros(3), v2_xy, color='red', alpha=0.5, ax=self.ax_xy)
        
        # Projection XZ
        v1_xz = self.v1.copy()
        v1_xz[1] = 0
        v2_xz = self.v2.copy()
        v2_xz[1] = 0
        
        self.draw_vector(np.zeros(3), v1_xz, color='blue', alpha=0.5, ax=self.ax_xz)
        self.draw_vector(np.zeros(3), v2_xz, color='red', alpha=0.5, ax=self.ax_xz)
        
    def setup_controls(self):
        """Configure les contrôles interactifs"""
        y_pos = 0.85
        x_pos = 0.7
        width = 0.25
        
        # Titre et informations
        plt.figtext(x_pos, y_pos+0.05, 'Contrôle des Vecteurs', 
                   fontsize=14, fontweight='bold')
        
        # Vecteur 1
        y_pos -= 0.08
        plt.figtext(x_pos, y_pos, 'Vecteur 1', fontsize=12, color='blue')
        
        y_pos -= 0.05
        ax_v1x = plt.axes([x_pos, y_pos, width, 0.02])
        self.s_v1x = Slider(ax_v1x, 'X', -3, 3, valinit=self.v1[0], color='blue')
        
        y_pos -= 0.04
        ax_v1y = plt.axes([x_pos, y_pos, width, 0.02])
        self.s_v1y = Slider(ax_v1y, 'Y', -3, 3, valinit=self.v1[1], color='blue')
        
        y_pos -= 0.04
        ax_v1z = plt.axes([x_pos, y_pos, width, 0.02])
        self.s_v1z = Slider(ax_v1z, 'Z', -3, 3, valinit=self.v1[2], color='blue')
        
        # Vecteur 2
        y_pos -= 0.08
        plt.figtext(x_pos, y_pos, 'Vecteur 2', fontsize=12, color='red')
        
        y_pos -= 0.05
        ax_v2x = plt.axes([x_pos, y_pos, width, 0.02])
        self.s_v2x = Slider(ax_v2x, 'X', -3, 3, valinit=self.v2[0], color='red')
        
        y_pos -= 0.04
        ax_v2y = plt.axes([x_pos, y_pos, width, 0.02])
        self.s_v2y = Slider(ax_v2y, 'Y', -3, 3, valinit=self.v2[1], color='red')
        
        y_pos -= 0.04
        ax_v2z = plt.axes([x_pos, y_pos, width, 0.02])
        self.s_v2z = Slider(ax_v2z, 'Z', -3, 3, valinit=self.v2[2], color='red')
        
        # Options d'affichage
        y_pos -= 0.08
        ax_radio = plt.axes([x_pos, y_pos, width, 0.12])
        self.radio = RadioButtons(ax_radio, ('Tous', 'Vecteurs', 'Somme'),
                                active=0, activecolor='gray')
        
        # Bouton de réinitialisation
        y_pos -= 0.10
        ax_reset = plt.axes([x_pos, y_pos, width/2, 0.04])
        self.reset_button = Button(ax_reset, 'Réinitialiser')
        
        # Connexion des événements
        for slider in [self.s_v1x, self.s_v1y, self.s_v1z,
                      self.s_v2x, self.s_v2y, self.s_v2z]:
            slider.on_changed(self.update)
        self.reset_button.on_clicked(self.reset)
        self.radio.on_clicked(self.update)
        
    def update(self, _=None):
        """Met à jour l'affichage"""
        self.v1 = np.array([self.s_v1x.val, self.s_v1y.val, self.s_v1z.val])
        self.v2 = np.array([self.s_v2x.val, self.s_v2y.val, self.s_v2z.val])
        
        # Configuration des vues
        self.setup_3d_view(self.ax_main)
        self.setup_3d_view(self.ax_xy, proj_type='xy')
        self.setup_3d_view(self.ax_xz, proj_type='xz')
        
        mode = self.radio.value_selected
        
        if mode in ['Tous', 'Vecteurs']:
            # Vecteurs principaux
            self.draw_vector(np.zeros(3), self.v1, 'blue', f'V1 {tuple(np.round(self.v1,2))}')
            self.draw_vector(np.zeros(3), self.v2, 'red', f'V2 {tuple(np.round(self.v2,2))}')
        
        if mode in ['Tous', 'Somme']:
            # Somme des vecteurs
            v_sum = self.v1 + self.v2
            self.draw_vector(np.zeros(3), v_sum, 'purple', f'V1+V2 {tuple(np.round(v_sum,2))}')
            
            # Parallélogramme
            self.draw_vector(self.v1, v_sum, 'red', '', '--', 0.3)
            self.draw_vector(self.v2, v_sum, 'blue', '', '--', 0.3)
        
        # Projections
        self.draw_projections()
        
        # Calculs et informations
        dot_product = np.dot(self.v1, self.v2)
        norm_v1 = np.linalg.norm(self.v1)
        norm_v2 = np.linalg.norm(self.v2)
        
        if norm_v1 > 0 and norm_v2 > 0:
            angle = np.arccos(np.clip(dot_product / (norm_v1 * norm_v2), -1.0, 1.0))
            angle_degrees = np.degrees(angle)
        else:
            angle_degrees = 0
            
        info = (f'Produit Scalaire: {dot_product:.2f}\n'
               f'Angle: {angle_degrees:.1f}°\n'
               f'||V1|| = {norm_v1:.2f}\n'
               f'||V2|| = {norm_v2:.2f}')
               
        self.ax_main.text2D(0.02, 0.98, info, transform=self.ax_main.transAxes,
                           bbox=dict(facecolor='white', alpha=0.8, edgecolor='lightgray'),
                           fontsize=10)
        
        self.ax_main.legend(loc='upper right')
        plt.draw()
        
    def reset(self, _):
        """Réinitialise tous les contrôles"""
        self.v1 = self.initial_v1.copy()
        self.v2 = self.initial_v2.copy()
        
        self.s_v1x.set_val(self.v1[0])
        self.s_v1y.set_val(self.v1[1])
        self.s_v1z.set_val(self.v1[2])
        self.s_v2x.set_val(self.v2[0])
        self.s_v2y.set_val(self.v2[1])
        self.s_v2z.set_val(self.v2[2])
        
        self.update()
        
    def show(self):
        """Affiche la visualisation"""
        self.update()
        plt.tight_layout()
        plt.show()

if __name__ == "__main__":
    viz = VectorVisualizer()
    viz.show()