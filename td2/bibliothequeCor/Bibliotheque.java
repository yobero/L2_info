import java.util.List;
import java.util.ArrayList;
/**
 * Décrivez votre classe Bibliotheque ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Bibliotheque
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    private String nom;
    private List<Document> documents;

    /**
     * Constructeur d'objets de classe Bibliotheque
     */
    public Bibliotheque(String nom)
    {
        this.nom=nom;
        this.documents = new ArrayList<Document>();
    }

    /**
     *
     */
    public void ajoutDocument(Document doc)
    {
        this.documents.add(doc);
    }
    public Document rechercheTitre(String titre)
    {
        for(Document doc: documents)
        {
            if(doc.GetTitre().equals(titre))
                return doc;
        }
        return null;
    }
    public List<Document> rechercheReference(String titre)
    {
        List<Document> docs = new ArrayList<Document>();
        for(Document doc:this.documents)
        {
            for(Document ref:doc.GetReference())
            {
                if(ref.GetTitre().equals(titre))
                    docs.add(ref);
            }
        }
        return docs;
    }
}
