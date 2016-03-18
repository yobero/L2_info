
/**
 * Write a description of class Circle here.
 * 
 * @author (Kenza Kellou-Menouer) 
 * @version (1)
 */
public class Circle
{
       
    private String name;
    private String color;
 

    /**
     * Constructor for objects of class Circle
     */
    
    
    public Circle(String name)
    {
       this.name = name;
       this.color = "orange"; 
    
    }
    
    public Circle(String name, String color)
    {
       this.name = name;
       this.color = color;
    }
    
      

 
    public String getName()
    {        
        return this.name;
    }
}
