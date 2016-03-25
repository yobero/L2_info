
/**
 * Write a description of class restaurant here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class restaurant
{
    // instance variables - replace the example below with your own
    private String localisation;
    private int place;
    private double prix2;
    private int nb2;
    private int nb3;
    private int nb5;

    /**
     * Constructor for objects of class restaurant
     */
    public restaurant(String localisation, int place, double prix2)
    {
        this.localisation = localisation;
        this.place=place;
        this.prix2=prix2;
        this.nb2=0;
        this.nb3=0;
        this.nb5=0;
    }

   public int nombrePlacesDisponibles()
   {
       return this.place - this.nb2 - this.nb3 - this.nb5;
   }
   
   public void vendreMenus(int nombre,int quelMenu)throws Exception
   {
       if(quelMenu==2 || quelMenu==3 || quelMenu==5)
       {
           if (nombre>this.place)
            throw new IllegalArgumentException("Le nombre de menu est plus élevé que le nombre de place disponible");
           
           if(quelMenu==2)
           {
               this.prix2 = this.prix2 + nombre;
               System.out.println("Le prix de votre repas est :"+ nombre*this.prix2);
           }
       }
       else
            throw new IllegalArgumentException("La variable quelMenu doit être 2, 3 ou 5");
   }
   
   public void remisAZero()
   {
       
   }
   
   public double chiffreAffaire()
   {
       
   }
   
   public double tauxRemplissage()
   {
       
   }
   
   public int getNombrePLaces()
   {
       
   }
   
   public int getNombreClients()
   {
       
   }
   
   public String toString()
   {
       
   }
   
   public void affichage()
   {
       
   }
}
