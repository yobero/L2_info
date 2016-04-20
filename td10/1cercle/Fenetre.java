import javax.swing.JPanel;
import javax.swing.JFrame;
import java.awt.*;
import java.awt.event.*;

public class Fenetre extends JFrame implements WindowListener
{
    private Panneau panneau=  new Panneau();
    
    public Fenetre() {
        //titre
        this.setTitle("Cercle");
        //dimenssion de la fenetre (300 L, 200 H)
        this.setSize(800,600);
        //fenetre centrée
        this.setLocationRelativeTo(null);
        //fin du programme lorque que j'appuie sur la croix
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        addWindowListener(this);
        
        this.setContentPane(panneau);
        
        this.setVisible(true);
    }
    
    public void windowActivated(WindowEvent e){
        panneau.change(true);
        panneau.repaint();
    }
    
    public void windowDeactivated(WindowEvent e){
        panneau.change(false);
        panneau.repaint();
    }
    
    public void windowClosing(WindowEvent e){}
    public void windowOpened(WindowEvent e){}
    public void windowIconified(WindowEvent e){}
    public void windowDeiconified(WindowEvent e){}
    public void windowClosed(WindowEvent e){}
}
