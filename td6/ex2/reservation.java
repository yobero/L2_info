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
                throw new IllegalArgumentException("Le nombre de restaurant ne doit pas être négative !");
                
            int i=0;
            Random rand = new Random();
            int val = rand.nextInt(400);
            float prix2 = rand.nextFloat()*20;
            String it;
            while(i<val)
            {
                it = Integer.toString(i+1);
                restaurant rest = new restaurant(it,val,prix2); //valeur aléatoire
                chaine.ajoutRestaurant(rest);
                i++;
            }
            
            boolean venteTerminer = false;
            int val1;
            int val2;
            int choix;
            
            while(!venteTerminer)
            {
                System.out.println("Choisissez un numero de restaurant compris entre 1 et "+nbRest);
                val=scanner.nextInt();
                
                if(val<1 || val>nbRest)
                    throw new IllegalArgumentException("Vous n'avez pas choisis un nombre entre 1 et "+nbRest);
                    
                chaine.getRestaurant(val-1).affichage();
                
                System.out.println("Quel type de plat voulez-vous ? 2,3 ou 5");
                val1=scanner.nextInt();
     
                if(val1!=2 && val1!=3 && val1!=5)
                    throw new IllegalArgumentException("Le type de plat choisi n'est pas correcte");
                
                System.out.println("Combien de plats de type "+val1+" voulez-vous ?");
                val2=scanner.nextInt();
                
                if(val2<0)
                    throw new IllegalArgumentException("Vous avez choisi un nombre négatif");
                    
                chaine.getRestaurant(val-1).vendreMenus(val2, val1);
                
                System.out.println("Voulez-vous arrêter la reservation ? 1=oui ou 0=non");
                choix = scanner.nextInt();
                if(choix==1)
                {
                    venteTerminer=true;
                    System.out.println("reservation terminer");
                }
            }
            
            i=0;
            double chiffreAffaire=0;
            while(i<nbRest)
            {
                System.out.println("Localisation : "+chaine.getRestaurant(i).getLocalisation() +", Taux de remplissage: "+chaine.getRestaurant(i).tauxRemplissage()+", Chiffre d'affaire: "+chaine.getRestaurant(i).chiffreAffaire());
                chiffreAffaire += chaine.getRestaurant(i).chiffreAffaire();
                chaine.getRestaurant(i).affichage();
                i++;
            }
            System.out.println("Chiffre d'affaire total: "+chiffreAffaire);
            
            
        }
        catch (IllegalArgumentException e){
            System.out.println("ERREUR : "+e);
        }
    }
}
