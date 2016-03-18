import java.util.List;
import java.util.ArrayList;
/**
 * Write a description of class drawing here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class drawing
{
    // instance variables - replace the example below with your own
    private String name;
    private List<circle> C;

    /**
     * Constructor for objects of class drawing
     */
    public drawing(String name)
    {
        this.name = name;
        this.C = new ArrayList<circle>();
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public void displayNameCircles()
    {
        String nom="";
        int nb = C.size();
        int i=0;
        circle cercle;
        
        while(i<nb)
        {
            cercle=C.get(i);   
            nom=nom+ cercle.getName() + ", ";
            i++;
        }
        System.out.println(nom);
    }
    
    public boolean addCircle(circle c)
    {
        if(this.C.add(c))
            return true;
        return false;
    }
}
