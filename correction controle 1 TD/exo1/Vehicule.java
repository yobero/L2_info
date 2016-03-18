/**
 * Abstract class Vehicule - write a description of the class here
 * 
 * @author (Kenza Kellou-Menouer)
 * @version (1)
 */
public abstract class Vehicule
{
    // instance variables
    protected String immatriculation ;
    protected String proprietaire ;
    protected String modele ;
   
      
    protected Vehicule(final String immatriculation, String proprietaire, final String modele)
    {
    
        this.immatriculation = immatriculation;
        this.proprietaire = proprietaire;
        this.modele = modele;
        }
    
     public void updateOwner(String newOwner)
    {
    this.proprietaire = newOwner;
    }
    
    public abstract int getYear();
    
    public String getImmatriculation()
    {
    return this.immatriculation;
    }
    
}
