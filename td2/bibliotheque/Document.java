import java.util.List;
import java.util.ArrayList;
/**
 * Décrivez votre classe Document ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Document
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    private String titre;
    private String auteur;
    private int annee;
    private List<Document> reference;

    /**
     * Constructeur d'objets de classe Document
     */
    public Document(String titre , String auteur, int annee)
    {
        this.titre=titre;
        this.auteur=auteur;
        this.annee=annee;
        this.reference = new ArrayList<Document>();
    }

    /**
     * ajoute un document dans référence
     */
    public void ajoutRef(Document doc)
    {
        this.reference.add(doc);
    }
    public String GetTitre()
    {
        return this.titre;
    }
    public List<Document> GetReference()
    {
        return this.reference;
    }
    public String affichage()
    {
        String ref="";
        for(Document doc:this.reference)
        {
            ref=ref + doc.GetTitre()+" ";
        }
        return "titre : "+this.titre+" auteur : "+this.auteur+" année de publication : "
            +this.annee+" référence : "+ref;
    }
}
