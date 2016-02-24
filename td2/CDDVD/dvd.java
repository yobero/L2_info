import java.util.List;
import java.util.ArrayList;
/**
 * Write a description of class dvd here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class dvd
{
    // instance variables - replace the example below with your own
    private String titre;
    private String realisateur;
    private int date;

    /**
     * Constructor for objects of class dvd
     */
    public dvd(String titre, String realisateur, int date)
    {
       this.titre = titre;
       this.realisateur = realisateur;
       this.date = date;
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public String TitreDVD()
    {
        return this.titre;
    }
    
    public String Realisateur()
    {
        return this.realisateur;
    }
    
    public int Date()
    {
        return this.date;
    }
    
}
