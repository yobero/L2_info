public class quadratique
{
    public static double calculRacine(double a, double b, double c)throws Exception
    {
        double d;
        
        if (a==0)
            throw new IllegalArgumentException("a doit être different de 0");
        else  d = (b*b) - (4*a*c);
        
        if(d<0)
            throw new Exception("d est negatif");
        else return (-b + Math.sqrt(d))/(2*a);
    }
    
    public static void main(String[] args)
    {
        double a;
        
        try {
            a=calculRacine(Double.parseDouble(args[0]),Double.parseDouble(args[1]),Double.parseDouble(args[2]));
            System.out.println(a);
        }
        catch(Exception exception)
        {
            System.out.println(exception);
        }
        catch(ArrayIndexOutOfBoundsException exception)
        {
            System.out.println("Il manque des arguments pour la fonction");
        }
    }
}
