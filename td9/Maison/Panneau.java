import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;
import javax.swing.JFrame;

/**
 * Décrivez votre classe panneau ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Panneau extends JPanel implements ActionListener
{
    private JButton allumer = new JButton("Allumer");
    private JButton eteindre = new JButton("éteindre");
    
    public void actionPeformed(ActionEvent a) {
        if(a.getSource() == allumer)
            g.serColor(Color.yellow);
        else
            g.setColor(Color.black);
    }
    
    public void paintComponent(Graphics g) { //this.getWidth()
        this.add(allumer);
        this.add(eteindre);
        //Base
        g.setColor(Color.gray);
        g.fillRect(300,400,150,150);
        
        //toit
        
        
        //fenetre gauche
        allumer.addActionListener(this);
        eteindre.addActionListener(this);
        g.setColor(Color.black);
        g.fillRect(315,410,45,50);
        //fenetre droite
        g.fillRect(390,410,45,50);
        
        //porte
        g.setColor(Color.blue);
        g.fillRect(360,500,30,50);
    }
}