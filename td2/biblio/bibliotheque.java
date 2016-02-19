import java.util.List;
import java.util.ArrayList;

/**
 * Write a description of class bibliotheque here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class bibliotheque
{
    // instance variables - replace the example below with your own
    private String nom;
    private List<document> docs;

    /**
     * Constructor for objects of class bibliotheque
     */
    public bibliotheque(String nom)
    {
        this.nom = nom;
        this.docs = new ArrayList<document>();
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    
    public void ajoutDoc(document doc)
    {
        this.docs.add(doc);
    }
    
    public void rechercheParTitre(String titre)
    {
        for(document doc: docs)
        {
            if(doc.GetTitre() == titre)
            {
                System.out.println("Ce livre est dans la bibliothèque");
                return;
            }
        }
        System.out.println("Ce livre n'est pas dans la bibliothèque");
    }
    
    public void rechercheDocs(document doc)
    {
        System.out.println(doc);
    }
}
