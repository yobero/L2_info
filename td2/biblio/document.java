import java.util.List;
import java.util.ArrayList;

/**
 * Write a description of class document here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class document
{
    // instance variables - replace the example below with your own
    private String titre;
    private String auteur;
    private int date;
    /**Liste des reference d'un documents*/
    private List<document> ref;

    /**
     * Constructor for objects of class document
     */
    public document(String titre, String auteur, int date)
    {
        // initialise instance variables
        this.titre = titre;
        this.auteur = auteur;
        this.date = date;
        this.ref = new ArrayList<document>();
    }
    
    public void ajoutRef(document doc)
    {
        this.ref.add(doc);
    }
    
    public String GetTitre()
    {
        return this.titre;
    }
    
    public List<document> GetRef()
    {
        return this.ref;
    }
    
       public String affichage()
    {
        String reference="";
        for(document doc:this.ref)
        {
            reference+=doc.GetTitre()+" ";
        }
        return "titre : "+this.titre+" auteur : "+this.auteur+" date : "
            +this.date+" référence : "+reference;
        }
}
