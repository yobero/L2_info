
/**
 * Abstract class vehicule - write a description of the class here
 * 
 * @author (your name here)
 * @version (version number or date here)
 */
public abstract class vehicule
{
    // instance variables - replace the example below with your own
    protected String type; /**le type du vehicule*/
    protected String immatriculation;
    protected String modele;
    protected String proprietaire;

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y    a sample parameter for a method
     * @return        the sum of x and y 
     */
    
    public void update_owner(String newOwner)
    {
        this.proprietaire = newOwner;
    }
    
    /**pas fonctionnnelle*/
    public int get_year()
    {
        String c="";
        
        if(this.type == "voiture")
            c = immatriculation.substring(5,8);
        else
            c = immatriculation.substring(0,4);
        
        //convertion du string en int
        int annee = Integer.parseInt(c);
        
        return annee;
    }
}