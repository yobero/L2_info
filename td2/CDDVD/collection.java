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
    private List<document> collection;

    /**
     * Constructor for objects of class collection
     */
    public collection(String nom)
    {
        this.nom = nom;
        this.collection = new ArrayList<document>();
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
   
    public void ajoutDoc(cd CD)
    {
        this.collection.add(CD);
    }
    
    public void ajoutDoc(dvd DVD)
    {
        this.collection.add(DVD);
    }
}
