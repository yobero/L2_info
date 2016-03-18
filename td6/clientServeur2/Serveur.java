import java.util.List;
import java.util.ArrayList;
/**
 * Décrivez votre classe Serveur ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Serveur
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    private List<Client> clients;

    /**
     * Constructeur d'objets de classe Serveur
     */
    public Serveur()
    {
        this.clients=  new ArrayList<Client>();
    }

    /**
     * le même client peut-il être connecter deux fois comment on différiencie 2 clients
     * */
    public boolean connecter (Client client)
    {
        for(Client c: this.clients)
        {
            if(c.getNom().equals(client.getNom()))
                return false;                     
        }
        this.clients.add(client);      
        return  true;
    }
    public void diffuser(String message)
    {
        for(Client c: this.clients)
        {
            c.recevoir(message);
        }
    }
}
