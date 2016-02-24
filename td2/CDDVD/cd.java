import java.util.List;
import java.util.ArrayList;
/**
 * Write a description of class cd here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class cd
{
    // instance variables - replace the example below with your own
    private String titre;
    private String artiste;
    private int nbTitre;

    /**
     * Constructor for objects of class cd
     */
    public cd(String titre, String artiste,int nbTitre)
    {
        this.titre = titre;
        this.artiste = artiste;
        this.nbTitre = nbTitre;
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public String TitreCD()
    {
        return this.titre;
    }
    
    public String Artiste()
    {
        return this.artiste;
    }
    
    public int NbTitre()
    {
        return this.nbTitre;
    }
}
