/* All Tracks --> Math -->  Number Theory --> Basic Number Theory-1 --> Problem  -->
Calculate the Power
Tag(s): Algorithms, Easy
Given two number A and B. Calculate the value of AB. Output may be too large so print the answer modulo 10^9+7.

Input:
Input contains two integers A and B separated by space.

Output:
Print value of AB modulo 10^9+7.

Constraints:
Test File 1 to 5: 
1<=A<=10 
1<=B<=10

Test File 6 to 10: 
1<=A<=10^6 
1<=B<=10^10

SAMPLE INPUT 
2 5

SAMPLE OUTPUT 
32

#include <stdio.h>
#define mod 1000000007
#define ll long long int

long long int CalculatePower(ll b, ll e){
	ll x = 1, y = b;
    while(e > 0) {
        if(e%2 == 1) {
            x=(x*y);
            if(x>mod) 
                x%=mod;
        }
        y = (y*y);
        if(y>mod) 
            y%=mod;
        e /= 2;
    }
    return x;
}

int main(){
	ll A, B;
	scanf("%lld%lld",&A,&B);
	printf("%lld\n",CalculatePower(A,B)%mod);
	return 0;
}

*/


/* I/O:

In #1:
2 5
Out #1:
32
In #2:
2 10
Out #2:
1024
In #3:
1 10
Out #3:
1
In #4:
10 5
Out #4:
100000
In #5:
5 5
Out #5:
3125
In #6:
2 1000
Out #6:
688423210
In #7:
567 10000
Out #7:
77038307
In #8:
1234 1000000
Out #8:
587327303
In #9:
2 10000000000
Out #9:
291251492
In #10:
5 1000000000000
Out #10:
365103863

*/

/*Best Submissions:
C:
#include <stdio.h>
#define i64 long long
i64 m = 1000000000+7;
i64 F(i64 n,i64 p){
    if(p==0) return 1;
 
    if(p%2==0){
        i64 ret = F(n,p/2);
        return ((ret%m)*(ret%m))%m;
 
 
    }
    else return ((n%m)*(F(n,p-1)%m))%m;
 
 
}
 
int main(){
 
 
    i64 a, b;
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",F(a,b));
 
}

C++:
1).
#include <iostream>
#define ll unsigned long long int
#define mod 1000000007
using namespace std;
 
ll Exp(ll b, ll e){
	
	ll x = 1, y = b;
    while(e > 0) {
        if(e%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        e /= 2;
    }
    return x;
	
}
int main(){
	
	ll base, exponent, x = 1;
	cin >>base>>exponent;
	cout<<Exp(base,exponent)%mod<<"\n";
 
	return 0;
}

2).
#include <iostream>
#define ll long long int 
#define mod 1000000007
using namespace std;
 
ll getExp(ll a,ll b)
{
    if( b ==0)
    return 1;
    if(b%2)
    {
        return (((getExp(a,b/2)*getExp(a,b/2))%mod)*a)%mod;
        
    }
    return (getExp(a,b/2)*getExp(a,b/2))%mod;
}
int main() {
	ll a,b;
	cin>>a>>b;
	cout<<getExp(a,b);
}

3).
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll power(ll a,ll b)
{
ll result=1;
while(b!=0)
{
if(b%2==1)
result=(result%mod*a%mod)%mod;
 
a=(a%mod*a%mod)%mod;
b=b/2;
}
return result;
}
int main()
{
ll a,b;
cin>>a>>b;
ll result=power(a,b);
cout<<result<<endl;
return 0;
}



C++14:
1).
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
 
int main()
{
    long long int a, b;
    cin>>a>>b;
    long long int res=1;
    while(b>0)
    {
        if(b%2!=0)
        {
            res=((res)%mod*(a)%mod)%mod;
            b--;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    cout<<res;
}

2).
#include<bits/stdc++.h>
using namespace std;
#define N 1000000007;
int main()
{
	long long int a,b,res=1;
	cin>>a>>b;
	while(b>0)
	{
		if(b%2==1)
		{
			res=(res*a)%N;
		}
		b=b/2;
		a=(a*a)%N;
	}
	cout<<res<<endl;
}

3).
#include<bits/stdc++.h>
using namespace std;
 
#define END '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i)
 
string alpha = "abcdefghijklmnopqrstuvwxyz";
const int mod = 1e9+7;
const int inf = 2e18+5;
const int nax = 101010;
//
int fexp(int a, int b){
    if(b == 0) return 1;
    if(b&1) return (a*fexp(a, b-1))%mod;
 
    int z = fexp(a, b/2);
    return (z*z)%mod;
 
}
 
 
 
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("fin.txt", "r", stdin);
        freopen("fout.txt", "w", stdout);
    #endif
    //
    int a, b; cin >> a >> b;
    cout << fexp(a, b);
 
    return 0;    
}

4).
#include <bits/stdc++.h>
#define lli long long int
#define plli pair<lli,lli>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define MAX 100005
#define M 1000000007
#define pf printf
#define sf scanf
 
using namespace std;
 
int main()
{
     lli a,b;
     cin>>a>>b;
     
     lli ans=1;
     while(b>0)
     {
         if(b%2)
         ans=(ans%M*a%M)%M;
         
         a=(a%M*a%M)%M;
         b=b/2;
     }
     
     cout<<ans%M<<endl;
}
5).

#define ll long long int
int func(ll a,ll b)
{
    ll MOD=1000000007;
    
    if(b==0)
    return 1;
    
    if(b==1)
    return (a)%MOD;
    
    if(b==2)
    return (a*a)%MOD;
    
    if(b%2==1)
    return (a*func((a*a)%MOD,(b-1)/2))%MOD;
    
    else
    return (func((a*a)%MOD,b/2)%MOD);
 
}
#include <bits/stdc++.h> 
using namespace std;
int main()
{
long long int a,b;
cin>>a>>b;
int ans=func(a,b);
cout<<ans;
return 0;
}

Java:
1).
import java.util.*;
public class FoodLove {
static long p[]=new long[10000];
    static int top=-1;
    public static void main(String[] args) {
         
long a,b,c=1,d,mod=1000000007;
 
    
        Scanner s = new Scanner(System.in);
         a = s.nextInt();
         b=s.nextLong();
 d=a;
      while(b>0)
      {
      if(b%2==1){
      c=c*d;
      if(c>mod)
          c%=mod;
      }
      d=(d*d);
      if(d>mod)
          d%=mod;
      b/=2;
      }
       System.out.println(c);
      
      }
 
       
    }
2).
import java.util.*;
import java.math.*;
class Solution
{
    public static void main(String args[])
    {
        Scanner scan=new Scanner(System.in);
        BigInteger A=scan.nextBigInteger();
        BigInteger B=scan.nextBigInteger();
        BigInteger C=A.modPow(B,BigInteger.valueOf(1000000007));
        System.out.println(C);
    }
}

3).
import java.util.*; 
import java.lang.*; 
import java.io.*; 
  
class exp_sq { 
    static long N = 1000000007L; // prime modulo value 
    public static void main(String[] args) 
    { 
        Scanner sc=new Scanner(System.in);
        long base = sc.nextLong(); 
        long exp =sc.nextLong(); 
  
        long modulo = exponentiation(base, exp); 
        System.out.println(modulo); 
    } 
  
    static long exponentiation(long base, long exp) 
    { 
        if (exp == 0) 
            return 1; 
  
        if (exp == 1) 
            return base % N; 
  
        long t = exponentiation(base, exp / 2); 
        t = (t * t) % N; 
  
        // if exponent is even value 
        if (exp % 2 == 0) 
            return t; 
  
        // if exponent is odd value 
        else
            return ((base % N) * t) % N; 
    } 
} 
4).
import java.math.BigInteger;
import java.util.*;
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        // Sample code to perform I/O:
        // Use either of these methods for input
        //
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String name = br.readLine();                // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
        //
        //Scanner
        //Scanner s = new Scanner(System.in);
        //String name = s.nextLine();                 // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        // Write your code here
        Scanner s = new Scanner(System.in);
        BigInteger a = new BigInteger(s.next());
        BigInteger b = new BigInteger(s.next());
        BigInteger p = new BigInteger("1000000007");
        BigInteger c = a.modPow(b, p);
        System.out.println(c.toString());
    }
}
5).
import java.util.*;
import java.io.*;
import java.math.*;
class Test{
 
    public static void main(String[] args) throws Exception{
        InputReader in = new InputReader();
        OutputStream outputStream = System.out;
        PrintWriter out = new PrintWriter(outputStream);
        long mod = (long)1e9+7;
        long a = in.nextLong();
        long b = in.nextLong();
        long answer = power(a,b,mod);
        out.println(answer);
        out.close();
    }
 
    static long power(long x, long y, long mod){
        long result = 1;
        while(y>0){
            if((y & 1) >0)
                result = (result*x)%mod;
            x = (x*x)%mod;
            y>>=1;
        }
        return  result;
    }
 
    static class InputReader {
        BufferedReader br;
        StringTokenizer st;
 
        public InputReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e) {
                    throw new RuntimeException();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                throw new RuntimeException();
            }
            return str;
        }
    }
}


Java 8:
1).
import java.io.*;
import java.util.*;
class TestClass {
    public static void fact(long x,long y){
        long res=1,mod=1000000007;
        while(y>0){
            if(y%2!=0){
                res=(res*x)%mod;
            }
            x=(x*x)%mod;
            y/=2;
        }
        System.out.println(res);
    }
    public static void main(String args[] ) {
        Scanner sc = new Scanner(System.in);
        long a=sc.nextLong();
        long b=sc.nextLong();
        fact(a,b);
		
		
        //Sample code to perform I/O:
        // Use either of these methods for input
        //
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String name = br.readLine();                // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
        //
        //Scanner
        //Scanner s = new Scanner(System.in);
        //String name = s.nextLine();                 // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        // Write your code here
 
    }
}

2).
import java.util.*;
 
class TestClass {
    static long power(long a, long b)
    {
        if(b==1)
        return a;
        if(b%2==0)
        {
            long res=power(a,b/2)%1000000007;
            return (res*res)%1000000007;
        }
        else
        {
            long res=power(a,b/2)%1000000007;
            return (a*((res*res)%1000000007))%1000000007;
        }
    }
    public static void main(String args[] ) throws Exception {
        //Scanner
        Scanner sc = new Scanner(System.in);
        long a=sc.nextLong();
        long b=sc.nextLong();
        System.out.println(power(a,b));
    }
}

3).
import java.util.*;
import java.lang.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
        Scanner sj = new Scanner(System.in);
        long a = sj.nextLong();
        long b = sj.nextLong();
         long x=1000000007;

     //   long i, s=a;
     //
     // for(i=1;i<b;i++){
     //     a = ((s%x)*(a%x))%x;
     // }
     // a = a%x;
     //
    long result=1;
    while(b>0)
    {
        if(b % 2 ==1)
            result=(result * a)%x;
        a=(a*a)%x;
        b=b/2;
    }
        System.out.println(result);
        
    }
}

4).
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
 
public class APowerB {
 
	private static Scan scanner = new Scan(System.in);
	private static Print printer = new Print();
 
	public static void main(String args[]) throws Exception {
		init();
		//scanner = new Scan(new java.io.FileInputStream(new java.io.File("Test.txt")));
		process();
		printer.close();
	}
 
	private static void init() throws IOException {
	}
	
	public static void process() throws IOException {
		long a = scanner.readLong();
		long b = scanner.readLong();
		printAPowerB(a, b);
	}
	
	private static void printAPowerB(long a, long b) throws IOException {
		printer.println(fastPower(a, b, mod));
	}
	
	private static long mod = (long) (1e9 + 7);
 
	private static long fastPower(long base, long exponent, long modulus) {
		long result = 1;
		while (exponent > 0) {
			if (exponent % 2 == 1)
				result = (result * base) % modulus;
			exponent = exponent >> 1;
			base = (base * base) % modulus;
		}
		return result;
	}
	
	static class Print {
		private final BufferedWriter bw;
 
		public Print() {
			this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
		}
 
		public void print(Object object) throws IOException {
			bw.append("" + object);
		}
 
		public void println(Object object) throws IOException {
			print(object);
			bw.append("\n");
		}
 
		public void close() throws IOException {
			bw.close();
		}
	}
	
	static class Scan {
		private byte[] buff = new byte[1024];
		private int index;
		private InputStream inputStream;
		private int total;
 
		public Scan(InputStream stream) {
			inputStream = stream;
		}
 
		private int scan() throws IOException {
			if (total < 0)
				throw new InputMismatchException();
			if (index >= total) {
				index = 0;
				total = inputStream.read(buff);
				if (total <= 0)
					return -1;
			}
			return buff[index++];
		}
 
		public final int readInt() throws IOException {
			int c = scan();
			boolean neg = false;
			while (isWhiteSpace(c)) {
				c = scan();
			}
			char d = (char) c;
			if (d == '-') {
				neg = true;
				c = scan();
			}
			int res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = scan();
			} while (!isWhiteSpace(c));
			if (neg)
				return -res;
			return res;
		}
 
		public final String readString() throws IOException {
			int c = scan();
			while (isWhiteSpace(c)) {
				c = scan();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.append((char) c);
				c = scan();
			} while (!isWhiteSpace(c));
			return res.toString();
		}
		
		public final long readLong() throws IOException {
			int c = scan();
			boolean neg = false;
			while (isWhiteSpace(c)) {
				c = scan();
			}
			char d = (char) c;
			if (d == '-') {
				neg = true;
				c = scan();
			}
			long res = 0;
			do {
				res *= 10;
				res += c - '0';
				c = scan();
			} while (!isWhiteSpace(c));
			if (neg)
				return -res;
			return res;
		}
		
		private boolean isWhiteSpace(int n) {
			if (n == ' ' || n == '\n' || n == '\r' || n == '\t' || n == -1)
				return true;
			return false;
		}
		
		public final char readChar() throws IOException {
			int c = scan();
			while (isWhiteSpace(c)) {
				c = scan();
			}
			return (char) c;
		}
		
	}
}

5).
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.TreeSet;
 
 
public class Practice {
	private static InputStream stream;
	private static byte[] buf = new byte[1024];
	private static int curChar;
	private static int numChars;
	private static SpaceCharFilter filter;
	private static PrintWriter pw;
 
    public static void main(String[] args) {
    	InputReader(System.in);
		pw = new PrintWriter(System.out); 
        new Thread(null ,new Runnable(){
           public void run(){
               try{
                   solve();//This is solution method
                   pw.close();
               } catch(Exception e){
                   e.printStackTrace();
               }
           }
       },"1",1<<26).start();
   }
    private static void solve(){
 
    	pw.println(pow(nextLong(), nextLong(), 1000000007));
    	pw.close();
	    	}
 
static long d,x,y;
static long modInverse(long A, long M)
{
extendedEuclid(A,M);
return (x%M+M)%M;    //x may be negative
}
static void extendedEuclid(long A, long B) {
if(B == 0) {
d = A;
x = 1;
y = 0;
}
else {
extendedEuclid(B, A%B);
long temp = x;
x = y;
y = temp - (A/B)*y;
}
}
 
public static void sieve(int n){
	boolean prime[]=new boolean[n+1];
	for(int i=4;i<=n;i+=2)
		prime[i]=true;
	for(int i=3;i*i<=n;i+=2){
		if(prime[i]==false){
			for(int j=2*i;j<=n;j+=i)
				prime[j]=true;
		}
	}
	for(int i=2;i<=n;i++){
		if(prime[i]==false)
			pw.print(i+" ");
	}
}
public static boolean isPrime(long n) {
	
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
 
	if (n % 2 == 0 || n % 3 == 0)
		return false;
 
	for (long i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
 
	return true;
}
 
    public static long pow(long n, long p,long mod) {
		if(p==0)
			return 1;
		if(p==1)
			return n%mod;
		if(p%2==0){
			long temp=pow(n, p/2,mod);
		return (temp*temp)%mod;
		}else{
			 	long temp=pow(n,p/2,mod);
			 	temp=(temp*temp)%mod;
			 	return(temp*n)%mod;
			 	
		}
	}
	public static long gcd(long x, long y) {
		if (x == 0)
			return y;
		else
			return gcd( y % x,x);
	}
	
	
	public static void InputReader(InputStream stream1) {
		stream = stream1;
	}
 
	private static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
 
	private static boolean isEndOfLine(int c) {
		return c == '\n' || c == '\r' || c == -1;
	}
 
	private static int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}
 
	private static int nextInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}
 
	private static long nextLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}
 
	private static String nextToken() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}
 
	private static String nextLine() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isEndOfLine(c));
		return res.toString();
	}
 
	private static int[] nextIntArray(int n) {
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextInt();
		}
		return arr;
	}
 
	private static int[][] next2dArray(int n, int m) {
		int[][] arr = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = nextInt();
			}
		}
		return arr;
	}
	private static char[][] nextCharArray(int n,int m){
		char [][]c=new char[n][m];
		for(int i=0;i<n;i++){
			String s=nextLine();
			for(int j=0;j<s.length();j++){
				c[i][j]=s.charAt(j);
			}
		}
		return c;
	}
 
	private static long[] nextLongArray(int n) {
		long[] arr = new long[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextLong();
		}
		return arr;
	}
 
	private static void pArray(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			pw.print(arr[i] + " ");
		}
		pw.println();
		return;
	}
 
	private static void pArray(long[] arr) {
		for (int i = 0; i < arr.length; i++) {
			pw.print(arr[i] + " ");
		}
		pw.println();
		return;
	}
 
	private static void pArray(boolean[] arr) {
		for (int i = 0; i < arr.length; i++) {
			pw.print(arr[i] + " ");
		}
		pw.println();
		return;
	}
 
	private static boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}
 
	private interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
 
	
}

C#:
1).
using System; 
using System.Numerics;
class MyClass {
	public long modularExponentiationIterative(long x,long n){
    long result = 1;
    while (n > 0){
        if (n % 2 == 1)
            result = (result * x) % 1000000007;
        x = (x * x) % 1000000007;
        n = n/2;}
    return result;
	}
    static void Main(string[] args) {
        MyClass obj=new MyClass();
        string[] s=Console.ReadLine().Split(' ');
        long[] f=Array.ConvertAll(s,long.Parse);
        Console.WriteLine(obj.modularExponentiationIterative(f[0],f[1]));
    }
}
2).
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace calculatethepower
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            long result = 1;
            string[] a = s.Split(' ');
            long[] arr = new long[a.Length];
            for (int i = 0; i < a.Length; i++)
            {
                arr[i] = long.Parse(a[i]);
            }
            long y = 1000000007;
            while (arr[1] > 0)
            {
                if (arr[1] % 2 == 1)
                    result = (result * arr[0]) % y;
                arr[0] = (arr[0] * arr[0]) % y;
                arr[1] = arr[1] / 2;
            }
            Console.WriteLine(result);
        }
    }
}

Pascal:
Program HiHere;
VAR a,b:int64;
 
function Putere(a,b : int64) : int64;
VAR x:int64;
Begin
if (b = 0) then Putere:=1 else
Begin
x:=Putere(a,b div 2) mod 1000000007;
if (b mod 2 = 0) then Putere:=(x*x) mod 1000000007 else Putere:=(((a*x) mod 1000000007)*x) mod 1000000007;
end;
end;
 
Begin
Readln(a,b);
Writeln(Putere(a,b));
Readln;
END.

Python :
1).
a, b = map(int, raw_input().split())
print pow(a, b, 1000000007)

2).
def expo(a, b):
	if b == 1:
		return a
	if b == 2:
		return a*a
	if b % 2 == 0:
		return expo(expo(a, b/2) % 1000000007, 2)
	else:
		return a*expo(expo(a, (b-1)/2) % 1000000007, 2)
 
data = [int(i) for i in raw_input().split(" ")]
n = data[0]
p = data[1]
print expo(n, p) % 1000000007

3).
def expo(a, b):
	if b == 1:
		return a
	if b == 2:
		return a*a
	if b % 2 == 0:
		return expo(expo(a, b/2) % 1000000007, 2)
	else:
		return a*expo(expo(a, (b-1)/2) % 1000000007, 2)
 
data = [int(i) for i in raw_input().split(" ")]
n = data[0]
p = data[1]
print expo(n, p) % 1000000007

4).
def pow(x, y, z):
    "Calculate (x ** y) % z efficiently."
    number = 1
    while y:
        if y & 1:
            number = number * x % z
        y >>= 1
        x = x * x % z
    return number
a,b = map(int,raw_input().split())
m = 1000000007
print pow(a,b,m)


Python 3:
1).data = input().split()
print(pow(int(data[0]), int(data[1]), pow(10, 9) + 7))

2).
x = input().split()          # Reading input from STDIN
a = int(x[0])
b = int(x[1])
print (pow(a,b,1000000007))     # Writing output to STDOUT

3).
n=input().split()
a,b=int(n[0]),int(n[1])
print(pow(a,b,10**9+7))

4).
import math
a,b = map(int, input().split())
p = (int)(1e9+7) 
d = pow(a, b, p) 
print(d) 


PHP:
1).
<?php
 
function findPowerMod($iBase, $iPower, $iMod, $iRes)
{
	if($iPower==0) return $iRes;
	
	if($iPower%2==0)
	{
		$iBase = pow($iBase, 2)%$iMod;
		$iPower = $iPower/2;
		return findPowerMod($iBase, $iPower, $iMod, $iRes);	
	}
	else
	{
		$iNewRes =($iRes * $iBase)%$iMod;
		$iBase = pow($iBase, 2)%$iMod;
		$iPower = floor($iPower/2);	
		return findPowerMod($iBase, $iPower, $iMod, $iNewRes);	
	}
}
 
fscanf(STDIN, "%d %d\n", $iN, $iP);
$iMod = 1000000007;
 
echo findPowerMod($iN, $iP, $iMod, 1);
 
?>

2).
<?php
 
$res = 1;
$mod = 1000000007;
fscanf(STDIN, "%ld %ld", $a, $b);
while($b>=1){
	if($b%2) $res = ($res*$a)%$mod;
	$a = ($a*$a)%$mod;
	$b = floor($b/2);
}
echo $res;
 
?>


Scala:
object HelloWorld {
    def main(args: Array[String]) {
        var Array(a,b) = readLine.split(" ")
        println(BigInt(a).modPow(BigInt(b),1000000007))
    }
}

Ruby:
1).
=begin
# Read input from stdin and provide input before running code
 
print "Please enter your name: "
name = gets.chomp
print "Hi #{name}\n"
=end
def power(x,y,z)
 
    res = 1
    x= x%z
    while (y > 0)
        if (y%2==1)
            res = (res*x)%z
        end
        y = y/2
        x = (x*x)%z
    end
    return res
end
arr = gets.chomp
arr = arr.split(' ')
a = arr[0].to_i
b = arr[1].to_i
 
#c = (a*b)%1000000007
puts power(a,b,1000000007)

2).
require 'openssl'
a,b = gets.strip.split(' ').map(&:to_i)
puts a.to_bn.mod_exp(b,1000_000_007)

*/

/*Editorial:

Author Solution by Ashish Khatkar
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
 
 
LL pow(LL a, LL b, LL mod) {
    LL x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}
int main()
{
    LL A,B,MOD=1000000007;
    cin>>A>>B;
    cout<<pow(A,B,MOD)<<endl;
    return 0;
}

*/
