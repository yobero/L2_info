import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JButton;
import java.awt.*;
import java.awt.event.*;

/**
 * Décrivez votre classe fenetre ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Fenetre extends JFrame implements ActionListener
{
    private Panneau panneau=  new Panneau();
    
    private JButton jour = new JButton("Jour");
    private JButton nuit = new JButton("Nuit");
    
    public Fenetre() {
        //titre
        this.setTitle("Maison");
        //dimenssion de la fenetre (300 L, 200 H)
        this.setSize(800,600);
        //fenetre centrée
        this.setLocationRelativeTo(null);
        //fin du programme lorque que j'appuie sur la croix
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        this.setLayout(new BorderLayout());
        
       panneau.add(jour);
       panneau.add(nuit);
       
       jour.addActionListener(this);
       nuit.addActionListener(this);
       this.setContentPane(panneau);
       
        
       this.setVisible(true);
    }
    
    public void actionPerformed(ActionEvent e){
        if(e.getSource() == jour)
        {
               panneau.changetest(0);
               panneau.repaint();
        }
        else
        {
               panneau.changetest(1);
               panneau.repaint();
        }
    }
}
