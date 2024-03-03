import java.io.*;
 import java.util.*;
class prog2{
    int a[][]=new int[3][3];
    prog2(int number)
    {
        number=number-1;
     int i,j,c=0;
        int temp[]=new int[3];
       for(i=0;i<3;i++)
       {
         for(j=0;j<3;j++)
        {
              c=c+1;
                a[i][j]=c;
            }
        }       
       for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {                    if(j==number)
               {
                   temp[j]=a[i][j];
               }
           }
      }
       temp=reverse(temp);
       for(i=0;i<3;i++)
       {
           for(j=0;j<3;j++)
           {    
               if(i==number)
               {
                   a[i][j]=temp[j];
               }
         }
       }
        
       for(i=0;i<3;i++)
        {           for(j=0;j<3;j++)
            {
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        }   
    }
    public int[] reverse( int[] a)
    {
        int temp=a[0];
        a[0]=a[2];
       a[2]=temp;
        return a;
    }
    public static void main(String args[])
    {
       Scanner sc=new Scanner(System.in);
       int x=sc.nextInt();
       prog2 obj1=new prog2(x);
    }
 }
