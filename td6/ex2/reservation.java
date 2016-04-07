import java.util.Scanner;
import java.util.Random;

public class reservation
{

    public static void main() throws Exception
    {
        try {
            Scanner scanner = new Scanner(System.in);
        
            System.out.println("Choisissez un nom pour la chaine de restaurant");
            String nomChaine = scanner.nextLine();
            chaineRestaurant chaine = new chaineRestaurant(nomChaine);
        
            System.out.println("Combien de restaurant voulez-vous ?");
            int nbRest = scanner.nextInt();
            
            if(nbRest<0)
                throw new IllegalArgumentException("nbRest ne doit pas être négative !");
                
            int i=0;
            Random rand = new Random();
            int places = rand.nextInt(400);
            double prix2 = rand.nextDouble()*20;
            String it;
            while(i<nbRest)
            {
                it = Integer.toString(i);
                restaurant rest = new restaurant(it,places,prix2); //valeur aléatoire
                
                i++;
            }
            
            
        }
        catch (IllegalArgumentException e){
            System.out.println("ERREUR : "+e);
        }
    }
}
