import java.io.*;
import java.util.*;
/**
 * Write a description of class main here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class main
{
    public static void bufferedWriter() throws IOException
    {
        BufferedWriter fichier = null;
        
        try {
            fichier = new BufferedWriter(new FileWriter("test.txt",true));
            
            fichier.write("C’est la fin du fichier.");
            fichier.newLine();
            
            fichier.close();
        }
        catch(IOException e)
        {
           e.printStackTrace(); 
        }
        finally {
            fichier.close();
        }
        
        
    }
    
    public static void RandomAccessFile() throws Exception
    {
        RandomAccessFile fichier = null;
        
        try {
            fichier = new RandomAccessFile("test.txt", "rw");
            fichier.seek(fichier.length());
            fichier.writeBytes("C'est la fin du fichier (2)");
            fichier.close();
        }
        catch (IOException e)
        {
            System.out.println(e);
        }
        finally {
            fichier.close();
        }
        
    }
}
