import java.awt.Color;
import java.awt.Graphics;

/**
 * Décrivez votre classe Disque ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Disque
{
   private int x;//point en haut a gauche du carré qui entourre le cercle
   private int y;
   private int rayon;
   private Color couleur;
   
   void dessiner(Graphics g){
       g.setColor(this.couleur);
       g.fillOval((this.x-this.rayon),(this.y-this.rayon),this.rayon,this.rayon);
   }
}
