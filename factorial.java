import java.io.*;
import java.util.*;
class example_2
{
    static Scanner sc=new Scanner(System.in);

    public static void main(String args[]) throws Exception
    {
        long n=sc.nextLong(),prod=1;
        for(long i=1;i<=n;i++)
        {
            prod=prod*i;
        }
        System.out.println(prod);
    }
}