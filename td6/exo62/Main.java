
/**
 * Write a description of class Main here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */

import org.apache.commons.math3.complex.Complex;


public class Main
{
    // instance variables - replace the example below with your own
   

    /**
     * An example of a method - replace this comment with your own
     * 
     * @param  y   a sample parameter for a method
     * @return     the sum of x and y 
     */
    public static void main()
    {
       
        Complex c1 = new Complex(5, 1);
        System.out.println(c1);
        
        Complex c2 = new Complex(2, 9);
        
        c1.add(c2);
        System.out.println(c1);
        
        System.out.println(c1.add(c2));
    }
}
