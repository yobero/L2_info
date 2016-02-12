import java.util.*;
import java.lang.*;
import java.io.*;

/**
 * Write a description of class ChaineCryptee here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */

public class ChaineCryptee
{
    // instance variables - replace the example below with your own
    private int decale;
    private String chaine;
    private String crypte;

    /**
     * Constructor for objects of class ChaineCryptee
     */
    public ChaineCryptee(String chaine, int decale)
    {
       this.chaine = chaine;
       this.decale = decale;
       this.crypte = crypte;
    }
    
    private char decaleCaractere(char c, int decalage) {
        return (c <'A' || c > 'Z')? c : (char)(((c-'A' + decalage) %26) + 'A');
    }
    
    //En cas de chaine null, la fonction renvoie " "
    public void cryptage()
    {
        char b;
        String c = "";
        int n=0;
        int taille = chaine.length(); 
        while (n<taille)
        {
            b = decaleCaractere(chaine.charAt(n),decale);
            c = c + b;
            n++;
        }
       crypte = c;
    }
}
