import java.io.*;
class Manna
{
   public static void main(String args[]) throws IOException
   {
       BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
       int l,s1,s2,t=Integer.parseInt(br.readLine());
       while(t--!=0)
       {
           String s=br.readLine();
           l=s.length();
           s=s.replace("SUVOJIT","");
           s1=(l-s.length())/7;
           l=s.length();
           s=s.replace("SUVO","");
           s2=(l-s.length())/4;

           System.out.println("SUVO = "+s2+", SUVOJIT = "+s1);
       }
   }
}