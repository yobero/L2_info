import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;
import javax.swing.JFrame;
import java.awt.event.*;

/**
 * Décrivez votre classe Panneau ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Panneau extends JPanel
{
    public boolean test;
    
    public Panneau(){
        this.test = true;
    }
    
    public void paintComponent(Graphics g){
        if(test==true)
            g.setColor(Color.red);
        else g.setColor(Color.black);
        g.fillOval(100,100,150,150);
    }
    
    public void change(boolean a){
        this.test=a;
    }
}
