
/**
 * Write a description of class circle here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class circle
{
    // instance variables - replace the example below with your own
    private String color;
    private String name;

    /**
     * Constructor for objects of class circle
     */
    public circle(String name, String color)
    {
        this.name = name;
        this.color = color;
    }
    public circle(String name)
    {
        this.name = name;
        this.color = "orange";
    }

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public String getName()
    {
        return this.name;
    }
}
