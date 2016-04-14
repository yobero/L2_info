import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;

public class bouton implements ActionListener {
    
    private JButton allumer = new JButton("Allumer");
    private JButton eteindre = new JButton("éteindre");
    
    public void actionPeformed(ActionEvent a) {
        if(a.getSource() == allumer)
            g.serColor(Color.yellow);
        else
            g.setColor(Color.black);
    }
    
    
}