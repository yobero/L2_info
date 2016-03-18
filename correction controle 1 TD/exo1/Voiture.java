/**
 * Write a description of class voiture here.
 * 
* @author (Kenza Kellou-Menouer)
 * @version (1)
 */
public class Voiture extends Vehicule
{
    // instance variables 
    private int nbPorte ;

    /**
     * Constructor for objects of class voiture
     */
    public Voiture(final String immatriculation, String proprietaire, final String modele, int nbPorte )
    {
        super(immatriculation, proprietaire, modele);
        this.nbPorte = nbPorte;
    }

    public int getYear()
    {
        
       return Integer.parseInt(this.immatriculation.substring(0, 4));
    }
}
