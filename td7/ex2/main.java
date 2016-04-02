import java.nio.file.*;
import java.nio.charset.Charset;
import java.io.*;
import java.util.List;

/**
 * Write a description of class main here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class main
{   
    public static boolean inversement(String avant)
    {
       String apres="";
       int taille = avant.length()-1;
       
       while (taille>=0)
       {
           apres += avant.charAt(taille);
           
           taille--;
       }
       
       if (avant==apres)
        return true;
       
       return false;
    }
    
    
    
    public static void main()
    {
        try {
            String ligne;
            BufferedReader fichier = new BufferedReader(new FileReader("palindrome.txt"));
            
            while((ligne = fichier.readLine()) != null)
            {
                if(inversement(ligne))
                    System.out.println(ligne);
            }
            fichier.close();
        }
        catch (IOException e)
        {
            System.out.println("erreur"+e);
        }
    }
    
    public static void lignes() throws IOException
    {
        try {    
            Path chemin = Paths.get("palindrome.txt");
            List<String> ligne = Files.readAllLines(chemin,Charset.forName("ISO-8859-1"));
            
            for(String l : ligne) {
                String s=  l.replaceAll(" ","");
                boolean test = true;
                
                for(int i=0; i<(s.length())/2; i++)
                {
                    if(s.charAt(i) != s.charAt(s.length()-i-1)){
                        test=false;
                        break;
                    }
                }
                if (test) System.out.println(l);
            }
        }
           catch(IOException e){
               System.out.println(e);
            }
        }
}
