import javax.swing.JOptionPane;
public class main{
   public static void main() {
       String s = JOptionPane.showInputDialog("Entrez la première valeur");
       double x = Double.parseDouble(s);
       s = JOptionPane.showInputDialog("Entrez la deuxième valeur");
       double y = Double.parseDouble(s);
       s = Double.toString(x*y);
       JOptionPane.showMessageDialog(null,"Le resultat est "+s);
    }
}
