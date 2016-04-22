import javax.swing.SwingUtilities;
import javax.swing.JComponent;
import javax.swing.JPanel;
import javax.swing.JFrame;
import java.awt.event.*;
import java.awt.Color;
import java.awt.Graphics;

/**
 * Décrivez votre classe Panneau ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Panneau extends JPanel
{
    private Disque disque = new Disque();
    
    public void paintComponer(Graphics g){
        addMouseListener(new MouseAdapter () {
            public void mousePressed(MouseEvent e){
                disque.x = getX();
                disque.y = getY();
                
                if(SwingUtilities.isLeftMouseButton(e))
                    disque.rayon = 25;
                if(SwingUtilities.isMiddleMouseButton(e))
                    disque.rayon = 50;
                if(SwingUtilities.isRightMouseButton(e))
                    disque.rayon = 100;
                    
                if((disque.x-disque.rayon)<800/3)
                    disque.couleur = Color.red;
                if((disque.x-disque.rayon>800/3) && (disque.x-disque.rayon<(2*800)/3))
                    disque.couleur = Color.green;
                if(disque.x-disque.rayon>(2*800)/3)
                    disque.couleur = Color.yellow;
                    
                disque.dessiner(getGraphics());
                
                return;
            }
        
        });
    
    }
    
    public void mouseExited(MouseEvent e){}
    public void mouseEntered(MouseEvent e){}
    public void mouseClicked(MouseEvent e){}
    public void mouseReleased(MouseEvent e){}
}
