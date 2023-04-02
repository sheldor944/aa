import java.util.Scanner;

class hello{
    int x , y ; 
    hello(int q , int t)
    {
        x = q ; 
        y = t ; 
    }
    void hello()
    {
        System.out.println("hello");
    }
    int addition(int x , int y)
    {
        return x+y ; 
    }
}

public class test{

    static {
        System.out.println("static block ");
    }
    {
        System.out.println("block only ");
    }
    
    public static void main(String[] arrgs)
    {
        Scanner sc=new Scanner(System.in);
        test ob = new test() ; 
        

    }
}