/* All Tracks --> Problem  --> Destroy the Monster
Tag(s): Very-Easy
Erza is a fearless Warrior of her guild. She is fighting a monster with Power P. 
She is using her special armour which helps her to defeat her enemy easily. With each attack the power of her attack increases by X amount. 
But after  attack, she has to wait for i seconds to recharge her armour. Initial power of her attack is X.

Each attack takes 1 second. The enemy is defeated when its power reduces to 0 or below.
After every attack, the Power of monster reduces by the power of attack.

How much time does she takes defeating the monster?

Constraints:-
1 <= X <= 10
1 <= P <= 10^9

Input Format:-
Single line consisting of 2 space-separated integers - P X

Output Format:-
Time taken by Erza to defeat the monster.

SAMPLE INPUT 
8 3
SAMPLE OUTPUT 
3

#include <stdio.h>

int main()
{
	long long int p,x;
	int tim = 0,a,i =1;	
	scanf("%lld%lld",&p,&x);
	a=x;
	while(p>0)
    {
        p=p-a;
        tim++;
        if(p<=0)
            break;
        tim+=i;
        a+=x;
        i++;
    }
    printf("%d",tim);
	return 0;
}

*/

/*Best Submissions:
C:
#include <stdio.h>
 
int main()
{
    long long int p, x, power, i=0, count=0; 
    scanf("%lld%lld",&p,&x);
    if(p<=x)
        printf("1\n");
    else
    {
        power=x;
        while(p>0)
        {
            i=i+1;
            count+=1;
            p=p-power;
            power+=x;
            if(p>0) count = (count + i);
        }
        printf("%lld\n",count);
    }
    return 0;
}

C++:
#include <iostream>
using namespace std;
 
int main()
{
long long p,x,i=1,j=0,z;
cin>>p>>x;
z=x;
while(p>0)
{
    p=p-x;
    x=x+z;
    j=j+i;
    i=i+1;
    
    
}
cout<<j<<endl;
    return 0;
}


C++14:
#include<iostream>
using namespace std;
 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	//driver code here
    int p, x, i, count=0, temp1, temp2, tim=0;
    scanf("%d %d", &p, &x);
    temp1=p;
    temp2=x;
    for(i=1; ; i++){
        temp1-=temp2;
        temp2+=x;
        tim++;
        if(temp1<=0){
            break;
        }
        else{
            tim+=(i);
        }
    }
    printf("%d", tim);
    return 0;
}


Java:
import java.util.*;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        Scanner sc=new Scanner(System.in);
        int p,x,t=0,f=0,i=1;
        p=sc.nextInt();
        x=sc.nextInt();
        while(p>0)
        {
            f+=x;
            p-=f;
            t+=i;
            i++;
        }
 
        System.out.println(t);
    }
}


Java 8:
import java.util.Scanner;
import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.Math.*;
 
 
 
public class Main
{	
 
	static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static long mod=(long)1e9+7;
    static int i,j,k;
//////////////////////////////////////    CODE STARTS   ///////////////////////////////////////////////    
	
	
public void solve() throws IOException{
		long p = l(),x = l();
		long l=-1;
		boolean flag=true;
		long r = (long)1e9+2;
	//	long r =10;
		while(r-l>1)
		{
		    long m = (r+l)>>1;
		    if((m*x)>=(p)) r=m;
		    else                  l=m;
		 
		}
	    long y=0;
	    long left = -1;
	    long right = (long)1e9+2;
	    while(right-left>1)
	    {
	      long  m = (right+left)>>1;
	        if(m*(m+1)==(2*r))
	         {   flag = false;
	            
	            break;
	         }
	         if(m*(m+1)>(2*r))
	            right=m;
	          else
	            left = m;
	          y=right;  
	    }
	    
	    if(flag==false)
		out.pl(r);
		else
		out.pl((y*(y+1))/2);
	}
 
    static int gcd(int a,int b)
    {
        return b==0?a:gcd(b,a%b);
    }
 
 
 
 
 
 ////////////////////////////////////     CODE ENDS      //////////////////////////////////////////////
 
 
	static InputReader sc;
	static OutputWriter out;
	Main() throws IOException {
	    sc = new InputReader(System.in);
	    out = new OutputWriter(System.out);
		solve();
		out.close();
	}
 
	public static void main(String args[]) {
		new Thread(null, new Runnable() {
			public void run() {
				try {
					new Main();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}, "1", 1 << 26).start();
	}
   
    
    
    
    
    /////////////////////////////////////////////////////////////////////////////////////
	
 
public static int floor(int[] a,int x){
				int low = 0;
        		int end = a.length ;
        
       
        		while (low < end) {
        		  int mid = (low + end) >> 1;
				  if(x==a[mid])
						return mid;
            	  if (x <a[mid]) 
			
                	end = mid;
        		  
        		  else 
                		low = mid+1;
				}
				return low-1;
				
 
}
static int Ceil(int[] A,int l,int r,int key)
{       while(r-l>1)
        {
            int m=l+(r-l)/2;
            if(A[m]>=key)   r=m;
            else            l=m;
        }
        return r;
}
  
  
 
 
	static int visit[];
	static Stack<Integer> temp1;
	static Stack<Long> temp2;
	static class InputReader{
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;
		
		public InputReader(InputStream stream)
		{
			this.stream = stream;
		}
		
		public int read()
		{
			if (numChars==-1) 
				throw new InputMismatchException();
			
			if (curChar >= numChars)
			{
				curChar = 0;
				try 
				{
					numChars = stream.read(buf);
				}
				catch (IOException e)
				{
					throw new InputMismatchException();
				}
				
				if(numChars <= 0)				
					return -1;
			}
			return buf[curChar++];
		}
	 
		public String nextLine()
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
		}
		public int nextInt()
		{
			int c = read();
			
			while(isSpaceChar(c)) 
				c = read();
			
			int sgn = 1;
			
			if (c == '-') 
			{
				sgn = -1;
				c = read();
			}
			
			int res = 0;
			do 
			{
				if(c<'0'||c>'9') 
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			while (!isSpaceChar(c)); 
			
			return res * sgn;
		}
		
		public long nextLong() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') 
			{
				sgn = -1;
				c = read();
			}
			long res = 0;
			
			do 
			{
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			while (!isSpaceChar(c));
				return res * sgn;
		}
		
		public double nextDouble() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') 
			{
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') 
			{
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, nextInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') 
			{
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) 
				{
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, nextInt());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}
		
		public String readString() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do 
			{
				res.appendCodePoint(c);
				c = read();
			} 
			while (!isSpaceChar(c));
			
			return res.toString();
		}
	 
		public boolean isSpaceChar(int c) 
		{
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
	 
		public String next() 
		{
			return readString();
		}
		
		public interface SpaceCharFilter 
		{
			public boolean isSpaceChar(int ch);
		}
		
 
		
 
	
	}
	static class OutputWriter {
		private final PrintWriter writer;
 
		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}
 
		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}
 
		public void p(Object...objects) {
			for (int i = 0; i < objects.length; i++) {
				if (i != 0)
					writer.print(' ');
				writer.print(objects[i]);
			}
		}
 
		public void pl(Object...objects) {
			p(objects);
			writer.println();
		}
 
		public void close() {
			writer.close();
		}
 
		public void flush() {
			writer.flush();
		}
 
	}
     
    ////////////////////////////////////////////////////////////////////
 
	static int i() {
		return sc.nextInt();
	}
 
	static long l() {
		return sc.nextLong();
	}
 
	static double d() {
		return sc.nextDouble();
	}
 
	static String s() {
		return sc.readString();
	}
 
	static int[] iarr(int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++) {
			array[i] = i();
		}
		return array;
	}
 
	static long[] larr(int size) {
		long[] array = new long[size];
		for (int i = 0; i < size; i++) {
			array[i] = l();
		}
		return array;
	}
 
	static double[] darr(int size) {
		double[] array = new double[size];
		for (int i = 0; i < size; i++) {
			array[i] = d();
		}
		return array;
	}
 
	static String[] sarr(int size) {
		String[] array = new String[size];
		for (int i = 0; i < size; i++) {
			array[i] = s();
		}
		return array;
	}
 
	static char[] stoc(String ss) {
		return ss.toCharArray();
	}
  
 
}


Python:
p,x=raw_input().split(" ")
p=int(p)
x=int(x)
i=1
time=0
f=0
while p>0:
  f+=x 
  p-=f 
  time+=i
  i+=1
  
print time


Python 3:
p, x = map(int, input().split())
if(p<=x):
    print("1")
else:
    power=x
    count=0
    i=0
    while(p>0):
        i=i+1
        count+=1
        p=p-power
        power+=x
        if(p>0):
            count = (count + i)
    print(count)


*/

/*Editorial:
check the code

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll p,x;
    cin >> p >> x;
    ll time = 0,attack = x;
    ll i = 1;
    while(1){
        p-=attack;
        time+=1;
        if (p<=0) break;
        time+=i;
        i++;
        attack+=x;
    }
    cout << time << endl;
    return 0;
}


*/

/*I/O:
In #1:
8 10
Out #1:
1

In #2:
10 2
Out #2:
6

In #3:
12 2
Out #3:
6

In #4:
14 2
Out #4:
10

In #5:
1000000000 1
Out #5:
1000006281

In #6:
1000000000 10
Out #6:
100005153

*/
