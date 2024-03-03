import java.io.*;
import java.util.*;    
class one
{
    public static void main(String args[])
    {
        int i, inte=65;
        String sum="";
        char b;
        for(i=0;i<=50;i++)
        {   
            b=(char)inte;
            sum=(i==14)?(sum+b+b):(i==15)?(sum+b):(i==41)?(sum+b):sum;
            inte++;
        }
        System.out.println("Sum="+sum);
    }
}    
