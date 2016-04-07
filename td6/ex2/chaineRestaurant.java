import java.util.List;
import java.util.ArrayList;

public class chaineRestaurant
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    private String nom;
    private List<restaurant> chaine;

    /**
     * Constructeur d'objets de classe chaineRestaurant
     */
    public chaineRestaurant(String nom)
    {
       this.nom = nom;
       this.chaine = new ArrayList<restaurant>();
    }

    public void ajoutRestaurant(restaurant r)
    {
        this.chaine.add(r);
    }
    
    public int taille()
    {
        return chaine.size();
    }
    
    public restaurant getRestaurant(int i)
    {
        return chaine.get(i);
    }
}
