import java.util.List;
import java.util.ArrayList;
/**
 * Write a description of class collection here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class collection
{
    // instance variables - replace the example below with your own
    private String nom;
    private List<cd> collectionCD;
    private List<dvd> collectionDVD;

    /**
     * Constructor for objects of class collection
     */
    public collection(String nom)
    {
        this.nom = nom;
        this.collectionCD =new ArrayList<cd>();
        this.collectionDVD = new ArrayList<dvd>();
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public void consulterDVD(dvd titre)
    {
        String Dvd = collectionDVD.GetTitreDVD();
    }
}
