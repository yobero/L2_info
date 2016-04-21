

public class Police
{
    private String nom;
    private int style;
    
    public String toString(){
        return getNom() + getStyle();
    }
    
    public String getNom(){
        return this.nom;
    }
    
    public String getStyle(){
        String s="";
        if(this.style == 0)
            s+= " PLAIN";
        if(this.style == 1)
            s+= " BOLD";
        if(this.style == 0)
            s+=" ITALIC";
        
        return s;
    }
}
