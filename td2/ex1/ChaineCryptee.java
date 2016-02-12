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
    private String chaine1;
    private String chaine2;

    /**
     * Constructor for objects of class ChaineCryptee
     */
    public ChaineCryptee(String chaine, int decale)
    {
       this.chaine1 = chaine1;
       this.decale = decale;
       this.chaine2 = chaine2;
    }
    
    private char decaleCaractere1(char c, int decalage) {
        return (c <'A' || c > 'Z')? c : (char)(((c-'A' + decalage) %26) + 'A');
    }
    
    private char decaleCaractere2(char c, int decalage) {
        return (c <'A' || c > 'Z')? c : (char)(((c+'A' + decalage) %26) - 'A');
    }
    
    //En cas de chaine null, la fonction renvoie " "
    public void cryptage()
    {
        char b;
        String c = "";
        int n=0;
        int taille = chaine1.length(); 
        while (n<taille)
        {
            b = decaleCaractere1(chaine1.charAt(n),decale);
            c = c + b;
            n++;
        }
       chaine2 = c;
    }
    
    //En cas de chaine null, la fonction renvoie " "
    public void deCryptage()
    {
        char b;
        String c = "";
        int n=0;
        int taille = chaine1.length(); 
        while (n<taille)
        {
            b = decaleCaractere2(chaine1.charAt(n),decale);
            c = c + b;
            n++;
        }
       chaine2 = c;
    }
}
