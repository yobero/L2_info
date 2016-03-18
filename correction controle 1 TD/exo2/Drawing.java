
/**
 * Write a description of class Drawing here.
 * 
 * @author (Kenza Kellou-Menouer) 
 * @version (1)
 */

import java.util.ArrayList;


public class Drawing
{
   
    private String name;
    private ArrayList<Circle> listCirle;

    /**
     * Constructor for objects of class Drawing
     */
    public Drawing(String name)
    {
       this.name = name;
       this.listCirle = new ArrayList<Circle> ();
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    
    
     public boolean addCircle(Circle c)
    {        
        if (c != null)
       { this.listCirle.add(c);
        return true;
    }
        return false;
    
    }
    
    public String displayNameCircles()
    {        
        
        String circlesNames = "";
        
         for(int i =0; i< this.listCirle.size(); i++)
        {
        
        circlesNames += this.listCirle.get(i).getName() + " ";
        
        
        }
        
        return circlesNames;
      
    }
}
