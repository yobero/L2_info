import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;

/**
 * Décrivez votre classe panneau ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Panneau extends JPanel
{
    public void paintComponent(Graphics g) {
        //Base
        g.setColor(Color.gray);
        g.fillRoundRect(this.getWidth()/4,this.getWidth()/2,this.getWidth()/5,this.getWidth()/5,0,0);
        
        //toit
        
    }
}