
/**
 * Write a description of class voiture here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class voiture extends vehicule
{
    // instance variables - replace the example below with your own
    private int nbPorte;

    /**
     * Constructor for objects of class voiture
     */
    public voiture(String immatriculation, String modele, String proprietaire,int nbPorte)
    {
        this.type = "voiture";
        this.immatriculation = immatriculation;
        this.modele = modele;
        this.proprietaire = proprietaire;
        this.nbPorte = nbPorte;
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
}
