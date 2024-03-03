import java.util.*;
import java.io.*;
class prog4
{
    int a,b;
    char x,y;
    prog4(int a, int b)
    {
        this.a=a;
        this.b=b;
        this.x=' ';
        this.y=' ';
        int sum=add(this.a,this.b);
        System.out.println("sum="+sum);
       
    }
    prog4(char x, char y)
    {
        this.a=-1;
        this.b=-1;
        this.x=x;
        this.y=y;
        char sum=add(this.x, this.y);
        System.out.println("sum="+sum);
    }
    public int add(int a, int b)
    {
        int sum=a+b;
        return sum;
    }
    public char add(char x, char y)
    {
        char sum;
        sum=(char)(x+y);
        return sum;
    }
public static void main(String args[])
    {
        prog4 obj1=new prog4('3','5');
        System.out.println("a="+obj1.a+", b="+obj1.b+", x="+obj1.x+", y="+obj1.y);
        prog4 obj2=new prog4(3,5);
        System.out.println("a="+obj2.a+", b="+obj2.b+", x="+obj2.x+", y="+obj2.y);
       
    }
}