/* Editorial :
There are multiple ways to solve this problem. One of them is to toggle the ASCII code of each Uppercase character to Lowercase and vice-versa. 
In case the character is uppercase, add 32 to it, else subtract 32.


import java.io.*;
import java.util.*;
class example_2
{
    static Scanner sc;
    static PrintWriter out;

    static void init() throws Exception
    {
        sc=new Scanner(new File("si.txt"));
        out=new PrintWriter(new File("so.txt"));
    }

    public static void main(String args[]) throws Exception
    {
        init();
        char[] a=sc.next().toCharArray();
        for(int i=0;i<a.length;i++)
        {
            if(a[i]>=97 && a[i]<=122)
            {
                a[i]-=32;
            }
            else
            {
                a[i]+=32;
            }
        }
        for(char ch:a)
        {
            out.print(ch);
        }
        out.close();
    }
}

*/
