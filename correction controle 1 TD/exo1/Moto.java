/**
 * Write a description of class moto here.
 * 
* @author (Kenza Kellou-Menouer)
 * @version (1)
 */
public class Moto extends Vehicule
{
   /**
     * Constructor for objects of class moto
     */
    public Moto(final String immatriculation, String proprietaire, final String modele)
    {
        super(immatriculation, proprietaire, modele);
    }
    
    public int getYear()
    {
              return Integer.parseInt(this.immatriculation.substring(4, 8));
    }
}
