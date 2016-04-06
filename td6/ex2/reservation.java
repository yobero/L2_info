import java.util.Scanner;

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
            while(i<nbRest)
            {
                restaurant rest = new restaurant() //valeur aléatoire
                
                i++;
            }
        }
        catch (IllegalArgumentException e){
            System.out.println("ERREUR : "+e);
        }
    }
}
