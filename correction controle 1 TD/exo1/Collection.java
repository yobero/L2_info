/**
 * Write a description of class Collection here.
 * 
* @author (Kenza Kellou-Menouer)
 * @version (1)
 */

import java.util.ArrayList;

public class Collection
{
    // instance variables 
    private String name ;
    private ArrayList<Vehicule> listeVehicules;

    /**
     * Constructor for objects of class Collection
     */
    public Collection(String name )
    {
        // initialise instance variables
       this.name = name;
       this.listeVehicules = new ArrayList<Vehicule> ();
       
    }
     
     public void addVehicule(Vehicule v)
    {
            
        this.listeVehicules.add(v);
       
    }
    
    public void tri_vehicule(int year)
    {       
        
        for(int i =0; i< this.listeVehicules.size(); i++)
        {
        
            if(this.listeVehicules.get(i).getYear() < year)
             
             System.out.println(this.listeVehicules.get(i).getImmatriculation());
               
        }
                    }
}
