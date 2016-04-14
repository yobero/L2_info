import javax.swing.JFrame;

/**
 * Décrivez votre classe fenetre ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Fenetre extends JFrame
{
    public Fenetre() {
        //titre
        this.setTitle("Maison");
        //dimenssion de la fenetre (300 L, 200 H)
        this.setSize(300,200);
        //fenetre centrée
        this.setLocationRelativeTo(null);
        //fin du programme lorque que j'appuie sur la croix
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        this.setContentPane(new Panneau());
        
        this.setVisible(true);
    }
    
}
