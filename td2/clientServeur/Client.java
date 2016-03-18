
/**
 * Décrivez votre classe Client ici.
 *
 * @author (votre nom)
 * @version (un numéro de version ou une date)
 */
public class Client
{
    // variables d'instance - remplacez l'exemple qui suit par le vôtre
    public String nom;
    private Serveur serv;

    /**
     * Constructeur d'objets de classe Client
     */
    public Client(String nom)
    {
        this.nom=nom;
        this.serv=null;
    }

    /**
     *  se connecte au serveur
     */
    public boolean seConnecter(Serveur s)
    {
        if(s.connecter(this))
        {
            this.serv=s;
            return true;
        }
        else
            return false;
        
    }
    public String getNom()
    {
        return this.nom;
    }
    public void envoyer(String message)
    {
        this.serv.diffuser(message+" émetteur : "+this.nom);
    }
    public String recevoir(String message)
    {
        return message;
    }
}
