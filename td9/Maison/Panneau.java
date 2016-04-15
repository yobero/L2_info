import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;
import javax.swing.JFrame;
import java.awt.event.*;

/**
 * Décrivez votre classe panneau ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */

public class Panneau extends JPanel
{
    private boolean test;
    public Panneau(){
        this.test = true;
    }
    
    public void paintComponent(Graphics g) { //this.getWidth()  
        //Base
        g.setColor(Color.gray);
        g.fillRect(300,400,150,150);
        
        //toit
        g.setColor(Color.red);
        int[] tx = {290,375,460};
        int[] ty = {400,350,400};
        g.fillPolygon(tx,ty,3);
        
        //fenetre gauche
        if(test == true)
            g.setColor(Color.black);
        else
            g.setColor(Color.yellow);
        g.fillRect(315,410,45,50);
        //fenetre droite
        g.fillRect(390,410,45,50);
        
        //porte
        g.setColor(Color.blue);
        g.fillRect(360,500,30,50);
    }
    
    public void changetest(int a)
    {
        if (a==1)
            this.test = false;
        else this.test = true;
    }
}