/* All Tracks --> Algorithms  --> Searching  --> Ternary Search  --> Problem  -->
The exam
Tag(s): Easy, Searching algorithm, Ternary search
Kate is wizard. Now she should pass the exam.
During the exam she have to go into the magic room N times. 
Initially there are X magic items in the room. Before each visit she can use magic to decrease the number of magic items in the room. 
For each item she spends 1 mana point to destroy it. After each visit the number of magic items increases by 2 times. 
She can't go into room if there are more than L magic items in it. What minimum mana points does Kate need to pass the exam?

You need to solve this problem for several test cases.
The first line of input contains single integer T (1<=T<=10^5) - a number of test cases.
Then follow T lines. The i-th of these lines contains three integers Xi,Li  and Ni(0<=Xi,Li,Ni<=10^18 ).
Print T lines.
The i-th of them should contain single integer - minimum number of mana points needed to pass the exam in the i-th test case.

SAMPLE INPUT 
2
2 5 3
6 5 0
SAMPLE OUTPUT 
1
0
Explanation
In the first case test Kate should destroy 1 item before the first visit.
In the second test case Kate has already passed exam.

#include <stdio.h>
#include <math.h>
#define M 100001

int main()
{
    int t,i,j;
    long long int X[M],L[M],N[M],x_max,mana;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%lld",&X[i]);
        scanf("%lld",&L[i]);
        scanf("%lld",&N[i]);
        mana=0;
        if(N[i]==0)
            printf("%lld\n",mana);
        else{
            x_max = L[i]/pow(2, N[i]-1);
            if (X[i] < x_max)
                printf("%ld\n",mana);
            else
                printf("%ld\n",X[i]-x_max);
        }
    }
    return 0;
}

*/

/*Editorial:
This problem was the easiest one in a contest. 
In order to solve it you need one key observation: removing magic item earlier is better. 
Let's assume that in optimal strategy you have to remove some item at step with number X, where X>1. 
Let's move this action from step number X to step number X-1. 
Now number of items in a room at steps X-1 and X decreased by 1, number of items at step X+1 decreased by 2, 
number of items at step X+2 decreased by 4 and so on - in general number of items at step X+K decreased by 2^K. 
Also there are no steps for which number of items increased - therefore new strategy is strictly better than previous one.
Now we know how does optimal strategy look like: you have to remove some number of items before entering room for first time. 
The only remaining part is to figure out how many items to remove. 

There are several possible approaches here, and constraints are loyal enough to allow you to pass with some log^2 per query stuff (while you can clearly make it faster). 
You can apply binary search: "let's say I'll leave X items before first iteration, is it fine?". 
For fixed X you can check it in log(L) using the observation that X=0 remains 0 forever and X>0 will become larger than L in O(log(L)) steps. 
You can speed it up to O(1) by simulating all steps with single multiplication by 2^K, which can be done as a bitwise shift (watch out for overflow here).

And finally you can get rid of binary search by approaching a problem from the other end: "it should be no more than L before the last iteration, 
it means no more than L/2 before the second to last, no more than L/4 before third to last...". 
Simply divide L by some power of two to get the initial restriction - once again, depending on your implementation and language you are using, 
take care of possible overflows or UB of your code. 

Don't forget that you don't have to print negative answer in case original number of items is even smaller than restriction you'll get.

And finally remember about tricky case when you don't have to enter room - you don't care how many items are there in this case.
Check codes by contestants and model implementations provided below in case some parts aren't clear.

Author Solution by kuchumov.ilya
def solve():
    x, l, n = map(int, input().split())
    min_erased = -1
    max_erased = x
    while max_erased - min_erased > 1:
        erased = (min_erased + max_erased) // 2
        cur_x = x - erased
        good = True
        for it in range(n):
            if cur_x > l:
                good = False
                break
            cur_x *= 2
        if good:
            max_erased = erased
        else:
            min_erased = erased
    print(max_erased)
def main():
    t = int(input())
    for i in range(t):
        solve()
main()



*/


/*Best Submissions:
C:
#include <stdio.h>
 
int main()
{
	long x,n,l;
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%ld%ld%ld",&x,&l,&n);
    	if(n==0)
    	{
    		puts("0");
    	}
    	else if(n>59)
    	{
         	printf("%ld",x);
    	}
    	else
    	{
    	  n=pow(2,n-1);
          n=l/n;
          n=x-n;
         if(n<0)
         {
         	puts("0");
         }
         else printf("%ld",n);
    	}
         printf("\n");
    }
    return 0;
}

C++:
#include <iostream>
#include <cmath>
#include <cstdint>
using namespace std;
 
bool dd(uint64_t x, uint64_t l, uint64_t t)
{	
	if(t == 0) return true;
	while(t--)
		x *= 2;
	return l > x;
}
 
int main()
{
	int t;
	cin >> t;
	uint64_t X, X1, L, N, temp;
	while(t--){
		cin >> X >> L >> N;
		X1 = X;
		uint64_t ans = 0;
		if(N == 0) 
		{
			cout << 0 << endl;
			continue;
		}
		if( L == 0) {cout << X << endl;  continue;} 
		if(X > L)
		{
			
			ans += X - L;
			X = L;
			temp = L/pow(2, (N - 1));
			cout << X - temp + ans << endl;
			continue;
			
		}
		if(( X < L && N == 1) || (X == 0)) {cout << "0" << endl; continue;}
		
		temp = L/pow(2, (N - 1));
		
		if(temp < X) cout << X - temp << endl;
		else cout << "0" << endl;
	}
    
    
    return 0;
}


C++14:
#include <iostream>
 
using namespace std;
long long int x,l,n;
bool check(long long int mid)
{
    long long int countt=0,c=(x-mid);
    if(c<=l)
    {
        countt++;
        c=c*2;
    }
    while(c<=l)
    {
        //if(mid!=0)
        //{
        //    c=(c-mid)*2;
        //    mid=0;
        //}
        //else
        //
        c=c*2;
        countt++;
    }
    if(countt>=n) return(true);
    else return(false);
}
int main()
{
    long int t;
    cin>>t;
    while(t--)
    {
        cin>>x>>l>>n;
        long long int high=x, low=0, mid;
        while(low<high)
        {
            mid=low+(high-low)/2;
            if(check(mid))high=mid;
            else low=mid+1;
        }
        cout<<low<<endl;
    }
    return 0;
}


C#:
using System; 
using System.Numerics;
using System.Linq;
class MyClass {
    static void Main(string[] args) {
    
    	
       long i,x,l,n;
   long tc=long.Parse(Console.ReadLine());
   while(tc!=0)
   {
   	long[]arr=Console.ReadLine().Split().Select(na => long.Parse(na)).ToArray();
 
x= arr[0];
l=arr[1];
n=arr[2];
    if(n==0)
 {
 	Console.WriteLine("0");
 }
    else if (n<63)
    {
    	 double p= (double) Math.Pow(2,n-1);
    	 double ans= (double) (x-l/p);
    	 double res = Math.Ceiling(ans);
    	if(res<0)res=0;
    	
    	Console.WriteLine(res);
 
    }
    else
    Console.WriteLine(x);
   
    tc--;
   }
 
 
 
}
}

JAVA:
import java.util.*;
import java.io.*;
 
//
//
// @author umang
//
 
public class TheExam {
    
    public static int mod = 1000000007;
 
    public static void main(String[] args) {
 
        InputReader in = new InputReader(System.in);
        PrintWriter w = new PrintWriter(System.out);
        
        int t = in.nextInt();
        
        while(t-->0){
            long x=in.nextLong();
            long l=in.nextLong();
            long n=in.nextLong();
            
            if((n==0)) w.println(0);
            else if(n>63) w.println(x);
            else{
                long p=pow(2,n-1);
                long ans=x-l/p;
                if(ans<0) ans=0;
                w.println(ans);
            }
        }
        
        w.close();
    }
    
    public static boolean isPal(String s){
        for(int i=0, j=s.length()-1;i<=j;i++,j--){
                if(s.charAt(i)!=s.charAt(j)) return false;
        }
        return true;
    }
    public static String rev(String s){
		StringBuilder sb=new StringBuilder(s);
		sb.reverse();
		return sb.toString();
    }
    
    public static long gcd(long x,long y){
	if(x%y==0)
		return y;
	else
		return gcd(y,x%y);
    }
    
    public static int gcd(int x,int y){
	if(x%y==0)
		return y;
	else 
		return gcd(y,x%y);
    }
    
    public static long gcdExtended(long a,long b,long[] x){
        
        if(a==0){
            x[0]=0;
            x[1]=1;
            return b;
        }
        long[] y=new long[2];
        long gcd=gcdExtended(b%a, a, y);
        
        x[0]=y[1]-(b/a)*y[0];
        x[1]=y[0];
        
        return gcd;
    }
    
    public static int abs(int a,int b){
	return (int)Math.abs(a-b);
    }
 
    public static long abs(long a,long b){
	return (long)Math.abs(a-b);
    }
    
    public static int max(int a,int b){
	if(a>b)
		return a;
	else
		return b;
    }
 
    public static int min(int a,int b){
	if(a>b)
		return b;
	else 
		return a;
    }
    
    public static long max(long a,long b){
	if(a>b)
		return a;
	else
		return b;
    }
 
    public static long min(long a,long b){
	if(a>b)
		return b;
	else 
		return a;
    }
 
    public static long pow(long n,long p,long m){
	 long  result = 1;
	  if(p==0)
	    return 1;
	if (p==1)
	    return n;
	while(p!=0)
	{
	    if(p%2==1)
	        result *= n;
	    if(result>=m)
	    result%=m;
	    p >>=1;
	    n*=n;
	    if(n>=m)
	    n%=m;
	}
	return result;
    }
    
    public static long pow(long n,long p){
	long  result = 1;
	  if(p==0)
	    return 1;
	if (p==1)
	    return n;
	while(p!=0)
	{
	    if(p%2==1)
	        result *= n;	    
	    p >>=1;
	    n*=n;	    
	}
	return result;
    }
    
    static class Pair{
		int x;
		int y;
		Pair(int x,int y){
			this.x=x;
			this.y=y;
		}
	}
    
    public static class CompareTable implements Comparator{
        public int compare(Object o1,Object o2){
            Pair p1 = (Pair) o1;
            Pair p2 = (Pair) o2;
            
            if(p1.x>p2.x)
                return -1;
            else if(p1.x<p2.x)
                return 1;
            else{
                if(p1.y<p2.y)
                    return -1;
                else if(p1.y>p2.y)
                    return 1;
                else
                    return 0;
            }
        }
    }
	static class InputReader {
 
		private final InputStream stream;
		private final byte[] buf = new byte[8192];
		private int curChar, snumChars;
		private SpaceCharFilter filter;
 
		public InputReader(InputStream stream) {
			this.stream = stream;
		}
 
		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}
 
		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}
 
		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}
 
		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			return a;
		}
 
		public String readString() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}
 
		public String nextLine() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isEndOfLine(c));
			return res.toString();
		}
 
		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
 
		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}
 
		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}    


Java 8:
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
 
// 1839
class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--){
			long x = nl(), L = nl(), n = nl();
			if(n == 0){
				out.println(0);
			}else{
				for(int i = 0;i < n-1 && L > 0;i++){
					L /= 2;
				}
				out.println(Math.max(x-L, 0));
			}
		}
	}
	
	void run() throws Exception
	{
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private static void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
}

Java(Node.js):
function main(input) {
    var k = input.trim().split('\n');
    var t = +k[0];
    for (var i=1; i <= t; i++) {
        var arr = k[i].split(' ');
        var x = arr[0];
        var l = +arr[1];
        var n = +arr[2];
        if (n === 0) {
            console.log(0);
        } else {
            if (l/Math.pow(2, n-1) ===0) {
                console.log(x);
            } else if (Math.ceil(+x - l/Math.pow(2, n-1)) > 0) {
                console.log(Math.ceil(+x - l/Math.pow(2, n-1)));
            } else {
                console.log(0);
            }
        }
    }
}
 
process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
 
process.stdin.on("data", function (input) {
    stdin_input += input;
});
 
process.stdin.on("end", function () {
   main(stdin_input);
});
 


PASCAL:
program THEEXAM;
uses    math;
var     x,l,n,k: int64;
        pow: array[0..63] of int64;
procedure main;
 var    z,t,i: longint;
 begin
        pow[0]:=1;
        for i:=1 to 62 do pow[i]:=2*pow[i-1];
        read(t);
        for z:=1 to t do
         begin
                read(x,l,n);
                if (n>62) then
                 begin
                        writeln(x);
                        continue;
                 end;
                if n=0 then
                 begin
                        writeln(0);
                        continue;
                 end;
                k:=trunc(l/pow[n-1]);
                writeln(max(0,x-k));
         end;
 end;
BEGIN
        main;
END.

Python:
import sys
from math import *
t=input()
while t:
    [x,l,n]=map(int,sys.stdin.readline().split())
    if n==0:
    	print 0
    	t-=1
    	continue
    try:
        m=log(l,2)+1
        if m<n:
        	print x
        elif n==m:
        	print max(0,x-1)
        else:
        	c=max(0,ceil(x-l*1.0/(2**(n-1))))
        	print int(c)
    except:
    	
    	if n==0:
    		print 0
    	else:
    		print x
        
    t-=1

Python 3:
t1 = int(input())
for t in range(t1):
	x,l,n = input().split()
	x,l,n = [int(x),int(l),int(n)]
	if(n==0):
		print(0)
	elif(x==0):
		print(0)
	elif(l==0):
		print(x)
	elif(n==1):
		if(x<=l):
			print(0)
		else:
			print(abs(l-x))
	elif(n>55):
		print(x)
	else:
		d = x-(l//(2**(n-1)))
		if(d<=0):
			print(0)
		else:
			print(d)


Ruby:
gets.to_i.times {
	x, l, n = gets.split(' ').map {|i| i.to_i}
	if n > 0 then
		puts "#{[0, x - (l >> n.pred)].max}"
	else
		puts "0"
	end
}

*/

/*I/O:
In #1:
2
2 5 3
6 5 0
Out #1:
1
0

In #2:
9261
15 1 9
2 8 8
9 17 6
6 12 2
11 1 17
8 20 8
1 9 14
18 13 14
12 8 6
11 14 12
12 20 16
16 12 6
9 18 4
16 5 13
19 15 2
7 18 4
1 10 0
3 4 12
5 9 18
3 5 15
8 9 13
7 13 0
10 12 3
10 6 1
16 15 12
7 8 5
1 3 10
16 9 16
4 9 6
1 2 10
20 10 1
19 11 10
4 15 5
3 5 6
19 11 13
9 9 9
0 20 10
4 1 13
4 15 8
1 2 20
15 16 18
15 14 13
0 18 18
4 13 17
1 19 15
2 13 5
1 3 15
13 20 1
3 8 5
8 5 16
13 2 7
3 6 9
1 2 14
15 11 1
20 5 10
20 3 20
10 18 19
11 12 14
8 15 12
1 6 7
6 12 9
14 2 14
4 14 10
4 19 13
2 1 3
1 20 20
15 3 11
10 0 0
6 20 0
20 1 20
1 12 11
19 14 16
10 14 14
8 0 9
3 2 3
17 15 16
16 16 20
10 0 15
10 9 19
6 16 17
2 11 8
17 20 18
0 8 19
4 10 10
18 16 3
5 17 0
9 19 7
8 19 18
14 11 7
2 19 14
19 3 2
8 9 1
14 12 0
7 1 16
2 0 12
9 3 7
15 18 18
13 7 4
3 1 7
0 2 14
15 13 19
4 16 3
0 13 9
16 4 4
13 1 11
3 14 14
6 17 14
13 3 4
18 20 8
3 3 6
13 16 13
11 8 11
3 13 15
5 18 19
20 14 19
14 0 3
17 18 14
10 12 1
13 15 8
19 0 7
12 8 18
15 19 9
7 6 3
4 16 4
15 16 8
0 17 6
11 17 11
14 0 12
4 13 20
0 15 17
13 8 20
13 20 19
8 18 12
0 9 3
9 4 1
2 7 18
11 0 18
3 7 0
18 15 11
13 9 17
19 6 13
9 5 11
6 12 10
3 6 13
8 12 3
19 9 3
18 9 7
2 16 4
8 2 14
5 5 2
18 9 18
4 1 15
7 10 7
10 18 17
9 15 7
12 20 15
10 14 0
1 9 0
18 15 20
12 18 12
3 5 12
4 11 9
20 15 10
19 20 7
7 12 12
13 0 18
1 9 4
18 1 17
1 15 6
20 1 12
16 20 12
7 11 0
4 14 12
14 2 1
2 0 2
1 10 10
6 2 15
11 16 19
19 19 12
20 20 2
5 2 19
18 2 16
0 2 10
10 13 9
9 16 5
0 17 13
9 17 16
5 2 17
11 7 10
6 8 8
17 3 10
13 11 2
18 18 1
10 18 20
3 10 5
4 2 0
4 6 17
18 18 13
6 1 15
8 17 19
19 11 5
5 20 13
3 3 13
20 10 2
16 11 7
18 7 18
17 20 15
14 0 1
8 12 17
20 17 14
1 11 13
14 8 6
16 9 10
5 5 15
4 20 8
16 19 0
18 5 17
18 4 20
0 11 4
17 10 5
1 8 13
9 7 17
3 14 16
3 8 3
14 18 5
13 19 4
19 15 15
6 11 8
5 1 10
17 17 1
19 2 20
16 15 9
0 8 3
11 7 3
14 14 10
7 3 20
13 0 14
11 5 17
2 17 2
11 15 18
15 12 0
4 16 12
17 0 3
6 3 6
9 3 14
12 16 4
12 7 7
6 15 9
15 2 17
15 8 7
17 8 1
13 11 18
7 20 15
3 11 18
16 19 17
16 12 10
14 14 14
2 18 16
14 16 1
4 16 16
8 17 12
2 4 2
9 4 13
9 12 20
19 9 17
14 6 10
1 17 17
10 19 17
8 0 17
13 8 10
4 17 14
17 7 13
5 15 6
19 19 19
8 16 20
12 16 6
14 0 4
1 18 13
16 1 4
6 9 7
1 12 13
9 3 10
19 14 9
18 15 19
5 14 15
16 10 10
13 4 3
6 13 7
13 8 16
16 11 13
11 13 3
2 17 10
20 16 0
2 20 18
1 19 0
18 16 15
13 0 6
7 1 2
20 13 19
4 2 18
18 0 17
19 10 18
13 2 15
16 10 6
6 5 19
18 16 19
14 2 9
11 3 0
15 15 0
10 8 1
7 20 11
5 13 9
11 8 0
2 7 13
8 9 0
1 18 18
2 14 14
3 14 7
12 18 9
13 15 11
7 5 11
9 18 0
11 18 8
9 1 1
19 3 11
7 14 14
18 19 7
13 16 18
14 13 2
14 0 9
2 19 16
3 18 3
14 13 1
12 2 6
20 18 6
14 16 12
17 6 7
11 12 11
16 0 6
0 3 19
10 14 17
19 4 14
13 17 11
9 9 16
17 14 7
5 5 18
18 18 20
14 9 11
2 12 6
12 8 14
6 20 7
11 3 7
16 1 13
14 13 20
5 4 9
7 1 17
9 19 0
2 13 9
9 13 8
5 11 3
15 2 5
20 6 14
9 4 20
14 11 16
10 8 9
18 4 4
12 4 14
0 1 3
9 11 7
18 3 2
2 14 6
13 8 18
1 7 19
8 0 2
15 6 9
20 0 20
5 13 5
12 13 6
1 7 9
5 3 5
0 12 16
11 3 9
14 5 1
0 6 0
10 13 2
15 5 2
13 9 16
17 12 0
9 8 5
4 9 16
16 17 5
5 10 11
6 12 0
4 17 3
9 18 10
16 14 16
19 4 5
20 9 5
3 1 17
15 11 9
9 18 5
1 19 16
3 5 2
20 17 8
15 19 0
8 15 5
2 11 15
14 3 16
16 5 16
2 9 8
8 13 1
20 7 4
12 17 18
12 20 9
20 16 3
1 1 9
14 10 19
5 3 2
7 6 1
11 8 13
15 18 8
3 20 20
4 10 0
0 0 10
10 15 7
17 5 16
18 1 0
7 13 4
5 15 0
18 11 17
9 10 0
9 8 16
2 5 1
0 20 3
20 13 13
18 1 9
20 8 15
8 17 18
13 12 4
15 0 11
8 18 20
7 16 14
9 20 15
15 19 17
5 9 6
20 17 0
17 15 5
1 4 5
18 19 19
2 3 10
0 10 13
17 16 2
12 4 10
14 20 15
6 12 15
13 1 18
16 7 19
15 12 7
20 5 4
7 3 14
12 6 10
4 11 8
5 3 20
18 2 0
3 17 4
16 17 15
14 18 2
18 19 10
7 3 17
9 17 8
1 13 1
6 3 5
9 1 9
2 10 0
14 16 6
14 13 17
20 17 3
11 20 20
17 17 8
6 3 15
15 9 17
17 10 12
5 18 6
6 1 18
14 17 2
1 20 14
1 11 10
8 14 13
20 0 7
19 12 20
2 17 7
6 8 11
3 16 9
14 19 10
2 16 8
18 16 1
7 14 16
1 10 1
0 17 16
11 20 7
8 4 18
14 20 12
11 3 6
20 2 10
1 9 20
1 19 17
1 19 2
14 6 7
0 16 15
15 0 12
6 4 4
19 12 4
15 17 15
4 17 11
14 6 8
20 1 2
0 2 19
7 5 6
11 10 14
20 16 7
13 3 14
7 14 18
8 6 9
16 15 8
5 19 3
18 14 16
5 11 7
17 5 1
13 15 5
4 0 17
15 15 18
1 9 3
12 18 1
11 4 9
9 20 8
20 11 8
5 4 20
19 9 4
0 15 9
4 15 3
9 14 17
9 6 12
11 11 13
20 3 5
18 7 14
9 10 18
16 2 19
11 0 16
14 20 19
15 12 10
12 7 6
17 11 7
18 9 5
5 2 7
18 12 0
2 16 19
5 14 8
5 15 13
16 10 18
11 1 9
5 9 10
18 18 10
18 2 6
16 4 14
10 20 17
17 11 2
0 5 19
6 19 0
5 2 6
11 12 15
6 5 5
14 20 3
8 4 20
9 4 17
6 8 0
0 0 12
3 10 16
8 13 13
18 8 5
5 8 3
13 3 17
7 4 6
9 15 2
5 15 8
8 14 19
2 16 10
0 10 20
11 1 19
10 15 4
20 2 12
18 1 13
11 10 0
2 6 18
17 6 20
5 3 0
18 8 1
20 17 17
16 9 3
11 2 18
19 2 0
0 7 7
6 14 19
8 11 18
1 1 10
0 9 18
17 5 11
18 4 15
19 16 19
17 6 5
14 19 7
9 7 16
15 15 7
19 16 10
3 12 3
7 18 19
4 2 11
19 15 4
20 0 17
12 1 3
6 10 14
4 11 13
17 19 15
0 8 14
1 17 1
20 2 2
6 2 16
10 14 8
2 4 12
7 14 8
19 17 2
1 4 11
17 16 1
17 16 11
12 4 13
13 6 15
17 1 8
7 13 5
2 12 5
13 19 8
6 19 10
5 9 13
0 1 9
16 16 19
4 19 14
2 2 5
0 19 15
6 3 13
9 17 14
18 14 20
17 11 5
16 13 1
8 18 9
0 15 7
1 2 9
2 13 6
6 11 20
8 15 14
3 11 16
2 5 16
16 13 0
0 18 2
18 13 13
6 19 7
17 13 6
5 13 14
2 5 15
4 19 1
20 6 13
12 10 17
9 19 10
8 18 14
18 11 11
13 2 17
9 8 17
5 19 13
2 17 6
18 4 2
6 15 17
18 2 20
8 10 13
2 1 6
14 9 3
12 11 10
18 16 13
9 7 20
7 19 18
1 0 0
17 12 15
14 1 15
6 16 3
17 6 17
8 17 17
14 8 14
3 19 8
12 11 5
16 18 18
16 10 9
17 0 15
5 5 0
16 20 1
10 14 3
6 16 2
7 11 14
2 12 14
11 12 2
11 5 10
13 17 4
6 6 2
14 16 19
6 18 1
9 3 0
17 2 16
14 17 5
14 0 13
19 15 10
17 14 5
16 18 14
6 9 1
1 16 16
20 20 17
3 1 9
2 12 10
9 3 15
0 20 5
14 20 10
16 16 6
5 16 14
8 14 0
12 7 19
19 15 5
6 8 5
9 2 0
11 1 20
11 7 18
9 11 11
9 0 9
10 7 4
10 11 7
7 12 13
18 2 7
2 14 10
11 3 18
0 11 1
10 4 6
15 20 18
18 0 2
15 15 9
10 9 5
8 19 19
18 7 19
15 4 5
10 12 12
14 4 5
8 18 7
17 19 9
4 20 14
13 16 17
12 13 0
20 18 11
5 17 17
13 4 20
12 14 7
6 15 0
18 15 8
19 17 1
12 0 20
2 12 16
13 9 15
6 18 16
5 6 0
5 16 0
7 11 18
13 6 19
18 8 15
15 4 2
6 15 3
17 2 13
15 18 17
7 17 10
14 2 0
0 0 3
2 18 9
7 6 18
8 15 16
6 0 19
8 6 20
18 0 19
7 1 12
2 16 6
5 20 18
2 3 13
14 5 16
3 0 0
5 18 17
4 5 6
5 18 4
18 5 6
12 16 16
15 13 15
8 1 19
2 5 19
8 11 7
12 15 11
18 10 20
17 16 19
6 6 14
5 18 14
18 4 0
15 14 2
0 11 19
15 6 19
9 9 15
18 10 18
18 14 7
6 4 13
8 0 14
16 19 14
17 5 15
3 4 2
13 0 3
11 1 18
1 10 11
15 5 0
9 12 16
13 17 13
19 0 3
7 12 9
5 6 9
13 9 18
11 2 5
4 19 2
18 19 9
1 5 12
11 15 17
1 11 12
3 4 6
18 4 12
16 12 9
2 0 19
1 9 19
11 6 20
8 8 20
14 11 4
1 2 7
19 12 1
16 12 20
15 6 20
4 12 5
5 2 0
5 0 9
7 7 16
18 16 10
16 7 10
13 17 9
10 1 20
7 13 17
12 3 12
6 13 4
18 9 9
2 0 6
17 11 12
16 2 17
14 15 17
18 20 4
13 0 17
9 11 16
6 19 5
6 11 1
13 3 19
20 7 3
14 1 18
0 12 14
4 7 5
9 8 8
11 1 0
13 20 14
1 5 18
5 11 6
9 15 0
0 9 19
15 6 10
13 11 5
8 19 14
1 1 18
14 7 17
18 4 5
20 17 16
10 8 7
17 15 4
10 17 3
15 18 2
4 3 3
9 19 2
14 19 6
17 18 18
13 10 9
15 19 13
5 11 12
2 9 14
10 8 17
4 14 16
13 0 19
7 15 12
17 13 19
18 17 14
20 3 6
16 16 9
5 1 12
2 20 5
5 10 7
0 3 4
18 19 1
0 1 2
3 9 4
20 2 0
13 13 4
14 20 8
10 5 5
7 12 19
17 17 11
17 14 18
7 9 10
12 17 6
13 18 5
4 15 7
5 9 12
0 4 4
20 12 17
14 20 7
0 16 7
16 8 2
11 2 11
1 17 11
13 9 5
18 16 11
14 8 2
15 13 1
1 7 1
6 4 5
16 2 9
8 17 11
3 17 17
9 15 10
7 17 20
15 1 18
11 0 13
17 15 1
15 20 13
4 6 10
0 15 16
2 3 16
20 6 2
5 20 0
4 8 5
12 17 14
5 11 5
5 11 13
12 10 4
11 19 15
11 6 3
13 19 12
7 1 3
10 19 20
15 6 16
19 18 14
15 12 18
5 5 16
13 15 4
14 4 7
19 7 20
19 0 14
3 14 12
10 11 10
6 12 6
9 15 3
11 6 18
3 18 14
14 10 13
1 18 12
2 0 17
15 12 4
17 17 5
19 7 12
3 1 10
8 19 9
12 5 5
9 8 4
10 4 11
17 14 3
8 20 12
8 4 9
17 7 18
12 0 11
9 7 4
5 6 4
0 19 19
9 19 16
5 6 19
15 2 7
15 15 4
2 3 17
7 13 1
10 20 0
13 13 14
10 5 0
15 16 12
17 9 10
8 6 10
15 0 20
4 1 18
13 16 16
1 0 5
7 6 10
16 8 3
8 6 18
14 17 3
10 18 12
16 15 20
5 10 2
15 5 11
6 6 10
0 8 16
18 20 6
0 1 10
7 0 15
3 20 11
3 16 2
3 3 18
12 3 13
13 9 19
16 19 20
6 17 10
10 1 0
16 3 7
11 4 19
14 10 6
14 11 0
1 11 3
2 15 16
13 18 3
6 10 7
8 2 12
7 7 7
5 8 4
0 2 17
5 17 19
13 6 5
13 6 18
4 12 20
3 12 9
11 10 10
7 15 13
6 9 2
0 19 13
0 18 5
5 12 16
6 3 3
5 19 12
5 3 10
18 9 16
18 17 8
9 11 0
15 10 19
7 3 15
3 6 14
15 4 6
15 15 6
20 10 12
6 3 11
3 19 19
2 2 18
7 8 3
7 0 5
6 0 1
0 6 10
11 10 17
5 7 6
0 13 7
18 19 17
17 19 14
5 4 13
12 1 20
14 4 13
16 9 0
16 0 1
18 6 4
8 16 8
0 2 5
19 9 14
9 12 19
19 9 15
4 3 20
19 1 0
19 15 6
15 15 17
8 10 3
1 14 1
6 16 11
11 4 4
5 18 0
8 7 2
11 12 8
4 16 6
15 6 5
16 13 3
4 5 14
20 10 5
7 10 16
18 12 17
15 9 4
6 2 20
7 8 12
13 14 5
6 15 14
9 0 13
5 8 7
7 6 9
19 14 7
18 3 0
19 13 18
6 11 19
8 4 14
13 4 4
4 5 5
5 4 5
1 12 16
12 2 7
14 13 12
10 12 11
10 19 12
3 19 4
5 11 10
11 11 18
14 8 19
2 12 17
3 19 5
3 11 7
13 18 6
7 17 18
7 4 12
2 15 9
10 0 13
14 15 2
8 4 6
11 10 3
15 8 6
16 3 10
12 6 13
1 14 13
17 15 14
20 6 12
14 16 8
3 8 8
11 14 8
19 4 18
18 17 10
7 10 5
12 18 3
11 11 17
16 8 19
14 9 5
12 18 14
8 2 9
19 19 0
2 2 16
9 9 4
1 14 20
1 5 20
20 1 18
18 16 6
0 19 18
9 11 5
10 15 3
14 14 3
10 4 1
11 16 4
0 2 2
14 5 4
11 18 9
12 19 2
19 8 19
19 0 18
11 18 6
14 9 18
19 19 17
15 3 10
20 12 15
18 4 14
12 0 10
13 0 11
3 4 1
17 6 13
1 4 19
12 16 13
15 18 14
2 1 9
16 9 6
19 19 1
20 6 18
5 13 16
17 0 11
18 5 15
15 11 5
12 14 4
18 12 16
20 19 17
2 1 1
13 0 13
18 9 15
4 9 0
10 13 16
12 20 3
12 17 5
10 9 10
7 17 0
2 14 4
18 13 11
18 12 13
7 2 9
15 17 18
17 1 1
13 3 5
12 11 13
4 7 9
0 19 9
8 3 15
4 8 16
7 12 8
16 14 20
1 9 13
17 1 18
17 8 20
9 10 5
1 13 18
11 1 10
17 2 2
11 12 20
17 9 13
17 10 9
12 1 12
6 3 9
4 12 17
5 13 4
1 18 16
1 2 11
16 1 8
14 4 20
12 20 4
1 3 20
19 12 12
1 18 5
17 6 18
15 10 17
7 15 19
15 13 7
11 18 14
4 12 6
17 14 13
1 14 5
11 4 20
6 2 19
9 12 5
20 3 10
15 11 14
15 12 3
0 11 0
18 20 14
2 15 5
2 2 7
8 8 13
5 2 3
13 5 4
2 12 20
5 17 11
18 19 18
4 11 17
14 0 18
7 9 12
4 12 16
10 13 13
5 12 18
3 19 17
15 18 7
4 11 15
15 10 4
18 18 3
0 14 14
6 8 9
14 8 1
7 19 7
12 15 19
0 5 2
4 14 2
2 2 8
12 6 7
9 9 0
17 1 19
12 6 2
2 15 10
13 11 20
1 19 19
8 15 13
9 2 4
7 0 4
7 19 10
15 7 16
16 8 18
14 15 15
19 16 3
3 3 9
2 5 10
15 19 3
16 7 1
8 1 6
14 8 10
12 6 12
9 7 12
7 8 14
7 13 7
18 14 9
19 10 3
0 20 11
1 11 17
11 1 16
14 13 19
1 14 15
18 12 20
19 19 8
16 0 14
4 5 8
1 12 9
1 4 13
5 2 13
13 1 20
14 2 10
20 16 13
7 2 3
3 9 15
9 13 16
5 16 4
12 3 19
17 8 15
17 12 18
6 9 6
13 16 19
7 18 0
9 2 14
9 7 19
3 18 1
13 1 6
8 1 2
8 14 8
15 11 20
12 19 18
4 3 16
15 17 7
6 2 7
11 4 18
2 3 2
11 14 18
8 16 11
6 8 15
13 18 9
4 18 10
3 14 5
0 13 2
10 0 12
14 5 13
1 20 19
8 14 14
1 12 2
7 18 9
11 7 8
6 18 6
0 16 19
20 5 8
13 1 17
6 8 20
9 20 20
3 5 13
15 9 8
4 4 19
16 0 19
10 13 20
15 11 18
17 11 1
12 17 2
17 3 2
3 0 2
3 3 1
0 7 15
2 9 10
14 10 17
4 9 8
2 3 18
0 19 17
16 7 4
13 16 12
10 15 13
8 13 7
4 5 10
19 20 0
17 8 7
9 5 15
15 13 17
12 10 8
1 3 18
14 10 16
5 11 2
9 4 14
15 13 16
20 2 11
14 8 18
14 3 10
9 2 2
10 10 19
16 15 7
0 20 20
17 14 14
20 10 7
6 1 0
1 1 3
3 17 6
11 4 0
2 10 6
12 9 1
11 14 13
11 5 6
7 16 13
18 5 20
15 19 1
14 13 0
7 6 4
11 2 2
3 0 7
12 1 0
6 20 12
13 15 13
2 6 4
6 16 16
6 5 8
2 15 0
20 18 17
1 16 0
5 16 11
17 6 11
8 10 2
1 19 20
2 20 7
11 11 6
3 15 20
2 10 14
6 10 0
5 20 8
16 0 7
13 8 2
12 16 8
8 2 19
10 20 11
19 6 3
2 9 2
7 4 1
8 5 0
5 12 4
14 1 10
5 6 13
10 12 7
11 11 4
0 12 11
2 3 12
6 15 15
4 12 9
8 7 1
6 17 0
11 11 7
6 9 19
13 6 4
7 0 13
17 3 5
1 0 2
9 20 1
1 4 14
16 11 18
10 11 19
18 11 20
2 16 5
20 1 14
18 12 4
18 17 15
5 7 9
12 7 10
16 0 12
9 15 17
12 7 2
0 10 19
5 16 2
19 2 5
2 11 16
7 13 19
19 11 11
0 16 0
20 17 12
18 8 2
19 18 11
9 11 3
8 8 5
1 20 8
8 5 18
16 9 17
13 19 13
5 2 4
12 7 4
7 13 10
9 14 15
16 5 10
15 15 19
14 15 8
16 20 7
8 14 5
14 11 6
20 2 6
14 13 5
15 16 10
9 13 20
11 5 11
12 14 16
0 1 7
13 20 16
16 8 5
20 8 16
17 2 4
16 3 18
13 13 7
11 17 8
18 13 9
3 19 2
14 2 17
5 17 5
12 20 17
13 0 5
12 15 13
6 4 8
20 17 11
12 16 11
14 14 4
0 0 4
7 2 11
14 18 11
15 7 5
1 6 6
11 9 7
14 16 3
5 0 12
13 4 19
12 17 13
15 5 4
8 1 20
2 4 18
14 7 15
17 7 6
15 17 3
5 7 0
16 20 11
6 6 17
7 16 17
15 14 15
13 2 1
1 9 6
19 4 2
10 10 6
10 1 10
17 14 15
14 11 20
11 14 2
0 14 4
16 4 1
15 15 14
12 8 10
14 20 0
19 3 4
7 2 20
8 15 15
14 9 16
12 0 13
4 11 2
14 13 3
9 15 18
6 4 19
19 20 13
14 14 17
1 10 7
18 6 9
19 4 0
11 0 19
8 10 8
1 20 18
11 2 14
2 11 4
4 1 20
11 19 13
14 17 19
3 7 9
8 2 16
6 10 4
16 6 11
12 20 5
5 1 15
20 14 6
10 3 19
7 7 15
16 13 13
9 6 0
6 13 5
14 15 9
7 19 17
16 0 4
0 15 1
18 10 3
8 0 7
20 9 16
2 4 15
17 12 20
16 3 15
20 18 2
15 20 10
14 12 16
7 5 8
10 14 5
9 20 13
12 13 16
10 12 13
10 7 15
4 0 7
16 18 7
19 20 5
4 11 18
9 4 8
8 9 5
10 3 0
10 7 6
12 15 15
19 16 11
13 6 14
19 7 14
16 2 16
5 9 19
4 0 8
10 5 2
2 6 13
4 10 4
3 12 4
18 10 14
10 11 3
3 0 15
2 8 3
1 15 18
6 11 4
12 9 20
16 5 19
12 11 20
9 16 18
14 2 19
8 0 0
4 10 7
19 7 9
4 3 17
6 2 9
7 10 12
11 4 7
11 15 14
17 0 1
12 19 1
0 17 20
11 13 8
19 5 12
1 14 18
20 3 0
20 8 18
8 4 11
8 7 0
7 6 20
19 7 8
1 20 0
1 1 7
0 0 1
17 11 4
7 14 19
15 2 0
17 4 7
3 17 19
3 6 0
20 4 20
9 9 17
16 15 5
3 15 15
6 6 7
9 14 12
15 20 0
19 8 18
4 19 12
9 0 12
14 11 2
19 4 1
6 3 19
18 8 0
10 6 13
16 7 3
16 19 12
1 14 14
18 18 8
9 11 10
6 20 19
16 11 1
12 1 11
17 20 5
5 4 4
2 9 1
9 1 8
0 4 20
0 2 0
14 10 8
10 18 6
5 7 10
14 0 7
7 15 1
9 5 17
13 9 8
3 18 15
19 0 16
17 20 4
20 17 7
1 15 1
0 11 7
11 8 16
9 0 7
17 15 8
9 15 11
20 2 5
19 1 6
15 2 18
13 15 2
10 16 11
17 9 7
19 7 11
7 8 6
3 13 1
20 6 0
8 1 9
1 12 12
16 16 7
1 8 4
19 4 8
4 17 20
0 7 4
20 20 6
8 16 17
5 5 6
2 7 15
9 6 10
15 7 11
15 15 10
2 3 11
3 4 8
11 0 1
2 0 7
18 6 8
5 11 19
20 5 19
7 18 1
5 3 7
0 18 4
11 1 15
7 15 11
16 17 13
16 8 12
18 1 12
6 2 8
12 10 2
10 6 11
3 10 13
3 2 5
19 16 2
19 16 18
20 13 17
0 12 1
8 11 4
6 18 19
7 0 6
6 7 2
18 14 3
4 4 18
20 12 13
0 8 20
19 18 19
8 9 2
13 14 13
3 14 3
17 20 12
12 6 19
12 2 15
11 6 19
3 11 11
11 0 20
3 13 0
20 0 11
12 10 7
15 18 5
2 19 5
16 3 3
14 18 8
0 9 13
0 9 5
19 9 11
5 15 4
18 14 17
18 6 15
2 19 17
1 11 1
0 14 2
11 0 17
10 15 0
5 8 9
16 6 18
2 19 9
16 20 10
7 18 11
15 10 11
1 1 4
4 0 11
9 12 6
13 18 14
20 5 6
17 9 12
13 18 17
12 10 16
5 9 15
4 13 0
18 2 8
4 3 4
20 20 9
1 6 15
19 15 18
5 10 3
16 3 13
16 0 15
11 20 12
16 5 1
5 14 20
10 7 12
11 12 12
14 10 7
13 14 1
18 3 17
10 20 7
19 16 9
9 0 14
11 5 7
17 4 10
10 20 14
16 13 15
16 18 12
13 13 15
5 8 2
12 12 13
3 17 3
6 20 2
12 15 3
9 5 6
2 13 14
16 13 10
15 12 1
11 13 0
2 10 11
19 6 11
12 19 13
12 20 12
7 3 6
17 19 13
7 17 13
18 20 12
16 15 15
12 11 4
13 3 18
6 0 2
14 15 20
9 3 12
16 5 11
17 18 16
0 16 13
5 17 13
10 19 16
10 7 16
17 5 6
2 13 3
0 16 11
19 17 9
18 1 1
7 7 2
19 6 9
2 17 3
10 1 6
14 8 9
5 16 15
3 4 15
6 1 2
12 14 20
0 14 3
19 12 15
12 20 19
3 15 10
12 7 5
5 13 1
20 5 18
10 17 14
8 1 7
20 5 13
4 15 18
0 10 3
1 6 3
5 8 20
2 1 16
19 13 5
12 8 9
11 16 20
13 16 10
0 18 11
18 19 8
19 3 12
16 20 15
5 4 17
13 2 14
2 3 0
15 1 0
0 3 20
15 5 15
10 17 1
12 17 1
19 20 2
8 19 7
1 13 15
13 8 11
16 9 9
4 12 15
16 3 5
8 13 4
18 19 2
8 18 1
15 1 12
13 8 15
12 10 12
12 4 11
20 14 3
9 15 15
5 19 8
10 4 0
19 20 3
10 6 12
6 1 10
11 15 2
16 7 8
20 14 11
1 5 0
8 15 9
10 8 3
17 10 19
19 10 6
5 14 5
17 8 3
14 9 4
3 16 4
6 19 13
2 15 12
0 2 9
19 17 4
13 19 3
6 14 4
13 19 18
11 4 5
17 0 17
13 20 7
18 2 17
15 17 16
8 0 10
6 18 4
4 18 13
4 15 12
18 5 1
4 20 4
18 17 4
19 10 14
5 10 16
18 4 13
14 15 11
19 11 12
11 17 2
20 6 20
4 11 6
0 6 20
4 17 16
15 1 17
19 16 5
9 10 11
20 2 20
13 15 14
20 7 16
11 1 6
14 13 8
14 14 20
0 18 15
12 8 0
20 1 11
8 17 16
2 4 5
6 7 20
1 4 9
5 3 14
3 2 1
5 18 3
1 15 9
11 13 6
7 6 14
7 14 5
20 19 3
17 11 8
7 17 12
4 7 6
14 17 8
19 4 17
19 9 8
1 10 15
11 15 8
2 15 2
16 9 2
20 9 20
5 19 4
1 17 12
10 10 18
19 8 1
0 16 3
0 7 18
7 1 19
17 15 3
5 11 11
12 1 7
13 13 19
2 1 7
13 13 1
6 6 4
15 10 16
7 7 14
20 5 7
6 20 11
14 14 16
16 6 4
4 0 9
18 6 7
20 19 11
2 7 20
19 5 18
0 14 16
5 19 15
11 13 5
10 10 2
16 10 4
9 17 9
4 15 1
8 18 13
20 11 14
14 1 12
19 14 5
1 0 14
0 4 15
17 5 18
15 13 6
19 18 4
15 0 6
16 20 8
7 0 3
9 17 12
12 14 15
6 10 2
13 1 0
1 13 10
6 0 8
3 15 2
10 6 8
5 0 18
19 8 10
17 15 17
11 8 9
14 0 2
12 18 16
17 1 6
3 4 9
5 19 9
20 10 0
11 7 14
15 11 3
14 5 10
10 7 0
11 0 12
11 10 7
5 6 8
5 10 8
13 12 1
1 17 9
13 0 15
3 13 6
12 10 18
17 14 1
11 15 5
5 17 2
20 6 11
15 2 6
19 1 17
2 7 0
4 2 2
20 6 8
4 10 5
2 6 12
7 16 2
16 18 4
19 13 2
19 11 19
13 10 4
7 16 12
11 10 15
7 8 10
8 12 1
10 15 20
15 2 8
9 19 8
13 4 10
18 14 1
10 2 4
6 19 4
8 17 8
2 19 2
16 19 8
2 3 6
12 5 9
19 9 6
18 14 2
12 16 9
12 16 15
5 1 20
6 12 19
14 14 1
17 13 12
6 14 5
18 4 9
10 6 4
13 20 17
10 8 13
14 3 18
7 11 15
10 17 17
7 7 9
19 9 20
5 18 18
0 11 17
17 7 17
7 16 0
20 7 10
15 18 3
17 1 20
11 3 14
17 1 17
11 5 1
2 12 15
17 6 10
4 10 9
7 15 3
10 3 9
3 16 10
3 5 18
10 5 8
8 8 4
1 15 13
8 20 15
5 6 3
10 1 14
9 13 12
11 0 10
19 3 14
10 11 6
12 5 8
10 12 16
8 13 11
20 14 10
4 16 15
8 0 3
14 18 7
12 16 3
19 14 17
4 15 10
2 10 5
11 20 16
0 12 19
12 13 9
7 8 17
15 20 2
16 10 20
4 0 1
3 15 0
19 2 17
1 10 3
5 0 14
18 18 7
15 9 11
13 2 13
9 7 9
11 1 2
6 12 17
11 2 17
7 17 7
18 2 18
10 18 7
8 17 3
12 1 10
7 14 10
18 2 2
10 1 18
19 19 2
13 14 12
5 6 18
7 18 3
2 14 1
17 17 19
13 9 2
18 13 5
15 11 15
5 8 1
2 0 18
9 13 5
3 13 2
16 10 7
19 5 11
20 13 3
17 3 18
18 16 5
16 4 12
16 8 8
1 11 8
5 20 2
18 4 10
14 19 8
10 10 20
0 2 8
10 6 3
4 19 5
1 8 20
7 5 10
2 17 16
9 1 19
3 17 5
12 16 12
0 0 11
14 2 6
4 3 18
3 9 5
9 15 8
19 1 14
8 15 8
13 4 18
19 19 20
11 8 15
4 20 16
14 5 20
13 10 20
9 6 5
3 13 13
13 9 1
14 3 12
2 16 3
17 3 19
0 20 1
6 4 16
3 1 12
2 18 4
0 0 0
17 13 11
17 16 8
3 15 16
9 0 10
4 11 20
7 14 1
10 0 3
6 14 10
1 9 8
8 12 7
0 10 9
15 17 20
3 6 6
9 11 20
15 0 8
11 7 4
14 16 11
9 0 17
19 3 18
19 8 15
19 17 14
8 6 3
8 1 15
4 0 13
6 18 20
17 3 16
4 0 12
14 12 12
13 16 2
12 7 13
12 2 18
20 11 18
1 12 15
2 2 4
13 7 0
2 2 12
3 19 3
20 7 2
11 12 4
18 0 0
9 5 10
14 3 6
5 6 6
15 19 10
5 15 7
10 9 14
18 17 11
6 13 18
5 19 18
5 9 14
1 3 8
0 12 2
1 15 4
13 9 9
8 13 8
0 7 16
9 20 10
20 1 1
12 9 16
13 13 5
20 1 6
1 4 7
18 10 16
5 8 15
13 16 20
0 10 7
17 4 18
15 8 17
9 10 10
7 16 10
15 17 8
0 2 1
3 18 10
14 16 18
17 20 7
6 16 8
14 3 8
18 16 14
20 6 1
7 1 18
3 7 5
14 12 18
15 0 16
0 14 5
3 20 3
3 3 20
12 10 1
9 3 16
4 3 6
19 2 1
3 10 14
0 3 2
4 19 9
6 20 10
18 17 3
11 3 11
1 17 18
3 8 11
13 18 18
19 9 12
19 14 14
12 20 18
19 17 8
5 5 20
15 9 5
16 3 2
14 4 12
4 8 9
11 20 3
1 13 16
7 12 3
6 3 17
3 6 12
11 13 17
1 20 6
20 18 15
7 17 16
7 20 9
1 18 11
19 9 1
8 3 2
3 7 10
18 3 6
1 19 6
15 3 6
16 13 7
14 16 7
14 8 17
2 18 3
1 1 11
8 18 5
12 14 12
2 0 14
19 18 3
2 12 7
19 8 6
7 19 14
17 18 8
20 9 7
12 6 0
19 15 9
19 2 6
6 13 20
10 11 15
16 12 1
4 3 10
5 6 20
20 13 11
15 2 15
6 11 5
1 15 12
10 20 16
9 3 9
15 9 14
6 16 6
11 2 15
8 3 16
18 8 11
16 3 6
8 19 11
3 12 10
9 17 13
15 13 9
14 8 12
17 14 19
13 6 1
8 4 13
17 17 13
10 10 16
14 9 6
8 20 11
2 4 0
4 19 18
15 9 16
5 11 15
19 3 7
1 1 8
17 3 17
17 7 8
3 5 7
15 17 5
3 1 6
4 13 14
3 0 19
0 4 14
19 18 16
4 10 6
9 15 9
6 16 10
16 20 17
3 10 9
14 16 4
17 17 15
10 2 19
2 19 18
14 14 7
3 17 1
5 15 12
2 10 10
9 4 15
2 11 20
11 0 11
11 4 10
8 1 13
8 3 11
10 13 4
3 3 14
14 15 6
2 7 19
20 19 20
20 7 11
0 8 7
18 15 1
5 7 4
1 16 18
16 20 20
6 17 18
12 5 13
20 19 19
5 10 12
11 20 13
4 5 1
20 16 1
12 13 3
18 1 8
5 15 1
6 12 8
3 17 9
13 11 19
7 10 10
2 13 10
17 1 9
7 8 18
3 14 10
15 5 6
13 6 17
7 0 11
11 0 5
2 2 3
17 19 2
18 14 15
14 14 12
8 8 7
14 1 5
18 13 16
8 6 0
13 0 10
5 3 13
7 11 16
15 13 4
19 18 0
11 16 6
20 19 10
11 7 1
4 19 16
12 8 5
3 9 17
13 18 16
11 19 18
16 4 16
1 3 11
10 8 14
17 6 14
7 20 7
4 20 19
16 13 18
19 5 17
8 10 9
7 9 0
8 2 7
19 6 5
9 11 17
15 17 14
17 19 8
5 12 6
10 3 2
19 5 9
3 5 10
17 0 0
6 7 4
1 13 17
14 3 7
5 9 8
15 16 4
4 12 0
14 8 3
18 11 12
7 10 20
13 3 20
12 8 2
1 13 2
6 18 3
10 10 5
5 16 7
18 14 0
7 15 7
10 19 11
15 1 19
2 18 5
4 13 19
11 15 20
19 6 15
17 11 14
4 7 12
18 20 11
17 16 20
13 17 12
14 16 15
14 8 11
16 4 10
8 6 4
3 12 19
17 7 5
7 14 17
0 6 2
9 19 13
14 17 14
1 16 15
12 19 4
4 20 3
3 18 19
0 16 10
0 11 8
16 20 14
6 7 3
13 6 3
1 0 10
14 7 9
3 14 11
17 1 15
20 19 13
9 14 20
13 16 6
11 13 11
5 7 20
6 9 8
1 16 14
10 7 7
11 18 20
17 5 5
19 3 17
8 20 1
16 14 1
0 18 1
4 10 1
18 8 14
11 11 10
13 7 11
9 9 10
1 7 17
20 1 10
16 4 0
4 7 3
12 18 15
18 17 16
19 2 8
15 10 12
3 12 13
2 20 4
19 2 16
8 15 4
4 5 3
4 9 13
5 3 17
9 4 3
2 20 11
18 4 7
20 7 19
8 17 4
13 5 13
20 14 16
1 9 18
19 11 17
1 15 20
0 20 2
12 9 17
13 13 20
0 15 4
14 11 8
19 3 8
6 18 8
4 0 15
14 2 20
9 0 6
15 5 16
3 8 19
14 16 2
11 5 8
18 5 0
11 9 5
13 11 13
15 7 8
12 4 15
18 13 17
1 18 0
14 12 11
1 18 17
9 13 2
0 8 17
6 20 1
11 17 10
11 20 10
4 16 14
10 20 15
7 2 10
13 16 8
6 11 11
1 10 8
19 19 4
9 4 11
4 5 19
20 5 1
11 20 2
2 19 3
11 11 11
3 2 12
0 10 11
13 11 6
17 19 5
20 20 0
1 11 5
19 2 2
3 9 2
0 5 8
20 9 15
11 10 13
18 3 10
17 0 12
9 7 2
18 3 19
9 3 20
19 13 19
8 19 17
13 6 10
10 17 5
0 6 14
14 17 1
1 17 15
18 4 11
10 10 11
10 3 6
2 0 20
2 14 5
6 10 10
18 3 13
3 14 15
2 6 7
6 8 10
10 3 8
2 15 11
16 14 15
18 16 8
20 3 19
9 14 0
20 16 18
8 17 15
13 19 15
0 2 7
17 0 10
11 18 11
7 10 3
13 5 8
3 3 7
16 6 10
8 1 10
7 2 17
12 2 14
13 9 12
13 5 3
10 12 14
7 11 3
10 5 10
0 13 15
10 2 3
4 9 14
18 19 13
5 1 0
0 11 5
17 8 2
0 7 10
7 9 14
11 13 15
17 7 9
8 11 15
9 15 14
15 6 8
8 15 6
9 16 1
3 7 2
16 14 12
4 8 15
3 19 7
3 5 0
20 6 7
5 1 5
10 20 8
8 12 11
8 16 6
7 0 2
13 2 12
2 13 16
2 11 2
9 12 0
2 15 1
4 2 3
12 18 19
7 1 5
19 2 11
11 11 9
3 15 7
4 11 1
16 6 14
20 9 3
2 7 16
2 7 5
2 7 2
4 16 19
0 5 10
12 19 19
5 10 18
9 18 12
2 14 13
12 15 18
3 4 7
18 19 5
14 7 12
5 9 3
20 6 6
10 4 14
3 4 3
18 19 6
19 19 16
4 7 8
17 1 3
7 1 7
11 8 12
13 2 6
12 9 12
0 11 14
10 0 14
11 7 9
17 16 18
7 6 7
7 17 2
15 15 15
1 8 19
14 4 14
10 3 12
9 5 2
11 1 4
0 20 4
11 4 15
14 15 5
5 13 8
17 8 5
5 16 5
0 20 15
13 0 1
10 13 15
16 20 9
15 16 7
2 9 15
20 14 8
11 12 16
2 16 16
8 7 9
3 14 19
6 17 9
12 10 15
2 5 0
19 20 4
7 3 16
0 7 11
5 3 12
12 8 12
1 14 12
1 6 9
1 0 9
8 18 2
13 18 13
16 12 11
15 17 10
0 15 0
20 2 13
11 5 3
10 4 15
15 6 0
1 5 9
1 19 11
16 19 11
4 10 20
14 12 20
14 12 9
11 11 15
10 12 4
10 3 4
7 14 3
10 5 17
3 2 19
11 17 19
1 0 19
10 2 14
12 10 14
17 18 6
13 15 10
16 2 6
16 1 9
10 14 19
6 18 9
16 6 15
19 17 6
13 9 14
0 1 0
10 11 9
18 2 11
14 6 17
14 8 7
3 9 12
12 19 3
13 2 4
12 1 1
10 2 15
0 10 14
16 15 1
11 12 17
15 11 17
16 0 9
6 9 15
7 3 11
15 9 18
12 12 10
0 19 20
16 17 14
0 1 18
3 11 8
4 11 7
3 12 16
17 4 12
8 3 10
10 11 13
15 5 7
15 14 9
15 18 15
14 6 16
13 1 13
15 14 8
19 12 7
3 4 19
6 8 7
18 12 1
4 13 18
4 13 10
5 18 2
3 16 14
5 20 19
9 7 7
0 6 1
15 18 11
6 12 18
13 5 6
11 18 2
4 0 4
16 10 16
4 6 14
2 20 8
13 18 15
9 14 3
12 1 13
15 19 20
11 0 0
2 19 15
3 1 8
11 9 12
16 17 1
4 14 3
10 16 5
1 18 3
1 12 19
3 2 10
15 7 1
3 7 1
18 4 6
10 4 17
16 5 7
5 18 15
6 3 7
3 1 14
20 4 5
13 5 5
9 17 5
18 20 3
17 3 9
17 12 13
6 3 12
17 4 2
13 10 6
20 12 3
4 18 7
20 13 16
12 3 3
20 7 12
10 0 2
18 3 8
0 10 10
5 9 20
0 19 7
11 16 0
2 1 11
9 4 9
15 5 8
12 17 8
15 14 1
8 7 15
4 0 14
10 6 15
6 13 8
17 5 4
14 17 0
20 10 17
2 5 5
10 6 7
2 6 17
16 3 9
17 9 16
19 15 0
2 17 17
14 19 0
5 17 4
18 5 14
8 14 18
1 1 2
13 17 10
0 7 3
5 14 0
20 12 20
20 16 5
1 17 16
10 16 12
1 9 5
20 11 5
6 8 1
7 2 13
15 2 20
8 13 16
12 17 4
1 8 2
17 13 18
1 16 5
5 20 3
19 12 17
10 19 4
9 10 12
6 1 14
9 2 11
1 16 2
19 8 7
5 19 1
4 6 18
2 5 4
16 12 14
20 20 18
12 15 14
2 7 4
12 5 7
12 12 0
11 19 10
0 0 18
6 7 6
9 19 20
13 19 1
4 18 2
0 8 5
1 7 14
2 7 17
9 12 2
13 6 0
3 11 15
13 14 18
1 15 11
0 20 19
1 10 4
7 16 1
8 13 6
4 6 15
1 14 10
17 18 12
17 12 12
4 6 9
16 7 2
9 1 2
3 19 1
6 6 1
12 6 20
14 19 5
13 12 11
14 6 11
18 8 8
18 15 4
10 7 11
9 3 6
15 10 8
17 1 12
0 7 14
20 9 18
13 4 6
4 15 17
5 7 18
10 4 8
18 16 4
6 10 17
5 17 12
7 0 8
0 17 5
9 1 5
4 9 3
12 6 3
2 6 6
18 1 20
7 7 3
19 17 7
16 16 12
14 19 16
14 8 15
6 0 13
15 2 11
18 17 7
20 15 7
3 0 10
4 12 4
4 15 14
10 17 10
10 3 7
17 1 16
20 14 4
2 0 0
0 9 1
11 0 2
11 7 0
13 1 4
10 13 18
5 12 11
3 12 17
17 0 2
7 19 20
8 7 12
12 14 14
12 4 3
17 11 11
18 4 16
2 20 20
20 3 7
0 17 4
4 15 9
6 16 0
15 17 17
9 15 20
6 14 17
9 11 6
5 8 8
14 16 14
20 0 4
11 5 4
7 10 4
20 5 20
10 20 3
6 0 18
13 16 3
15 3 9
17 13 1
18 8 9
7 13 11
1 17 10
16 3 1
15 1 20
2 2 11
18 18 18
4 17 7
2 13 8
19 4 9
0 5 15
9 12 10
3 7 14
5 12 1
17 7 11
4 8 17
7 14 9
17 0 7
8 16 1
12 19 9
2 8 4
7 3 9
7 15 17
15 20 9
9 10 2
17 2 18
19 14 2
15 6 13
18 7 15
5 17 16
1 2 17
0 15 15
2 14 11
0 9 15
6 1 16
6 20 5
6 3 10
0 18 14
10 14 9
0 18 17
19 17 5
9 10 4
5 19 6
15 2 3
4 20 1
8 12 16
20 6 15
4 6 0
20 3 11
14 12 13
5 13 17
18 10 19
2 4 8
15 0 18
17 20 14
8 19 5
0 18 20
13 14 17
16 18 3
20 14 9
16 16 11
3 16 12
16 10 12
3 1 1
19 6 20
20 9 13
2 11 0
13 0 7
16 2 20
4 11 0
12 12 2
11 18 19
18 2 9
7 18 2
19 7 1
5 19 11
2 16 7
1 6 13
14 3 11
5 13 15
15 14 10
8 17 13
17 16 12
11 4 3
10 17 18
16 16 18
12 17 10
13 19 20
1 1 16
5 18 5
10 2 11
10 2 13
5 10 1
19 0 6
9 0 1
19 14 6
8 19 13
16 14 17
5 2 11
12 3 16
8 5 6
2 15 3
12 0 3
5 4 14
8 9 6
12 13 15
2 9 0
9 19 19
18 5 18
1 4 20
19 7 18
7 18 17
14 19 14
4 14 15
2 18 10
15 12 9
17 4 14
10 17 13
15 3 8
3 11 0
13 3 8
14 0 17
9 0 5
20 19 4
15 16 13
3 18 2
16 12 0
17 19 3
4 6 13
12 2 1
12 15 17
8 15 20
14 18 18
16 12 7
15 2 1
10 5 19
18 7 20
17 3 14
8 10 15
20 19 9
5 3 3
14 10 9
12 18 20
9 15 16
7 13 15
13 14 19
11 17 15
1 15 8
5 12 20
11 18 5
16 9 20
19 7 0
9 13 14
10 19 19
13 11 4
17 6 2
15 3 13
0 4 6
9 6 16
6 14 14
0 13 14
4 7 19
4 20 17
7 9 7
6 2 2
8 17 2
17 10 20
7 10 19
11 2 19
6 7 13
14 2 3
7 15 16
17 15 7
13 2 0
20 10 3
5 7 3
12 18 4
1 20 11
7 10 17
6 17 17
14 15 19
20 20 16
2 7 10
9 2 20
1 5 11
8 20 18
3 12 15
11 5 16
3 12 2
0 2 18
7 20 19
5 19 14
4 18 17
16 14 7
6 13 19
18 9 13
18 15 9
5 15 20
3 2 2
12 3 14
10 1 17
2 16 20
10 8 20
20 16 19
1 8 6
8 5 13
9 17 4
19 20 10
15 20 16
11 0 14
2 7 3
2 10 1
20 8 14
13 1 3
1 8 17
10 13 1
18 6 20
14 6 12
1 20 4
15 5 1
18 7 3
8 0 20
11 14 1
7 18 15
11 12 5
12 8 7
13 20 5
17 12 14
19 3 5
7 4 13
15 3 16
0 9 20
16 16 14
4 0 5
20 13 0
8 1 1
10 4 12
11 18 0
5 11 0
9 11 12
20 4 10
19 7 5
11 4 6
13 6 13
6 14 9
6 9 18
0 8 13
8 4 0
3 11 17
10 0 5
11 14 5
6 18 13
16 4 7
12 8 3
2 9 18
14 9 1
1 13 7
1 1 6
0 8 8
11 7 11
1 12 5
2 1 12
4 7 15
20 9 4
17 7 10
20 20 7
12 0 14
12 9 2
5 8 18
13 1 5
6 4 2
20 15 18
3 12 18
6 20 6
9 8 13
10 10 13
10 6 19
5 4 19
15 14 20
10 5 18
19 19 5
3 3 16
11 19 9
10 8 16
11 10 8
8 14 17
8 12 0
16 18 2
13 19 7
20 1 0
10 11 4
11 15 19
11 19 1
15 12 13
13 0 20
13 5 14
15 18 0
5 10 19
19 13 17
16 17 20
2 13 0
1 7 6
6 10 16
3 10 4
18 11 3
20 4 0
15 1 14
15 7 10
14 2 16
13 18 11
19 7 6
14 19 13
19 12 11
0 14 7
16 13 2
19 15 7
0 5 9
12 14 8
16 16 8
11 16 5
1 16 19
13 15 7
20 5 11
5 3 6
14 15 13
14 5 17
17 13 4
1 0 1
18 12 7
11 7 13
7 12 6
16 18 0
2 5 8
12 19 5
6 1 9
1 4 4
20 7 9
20 8 4
15 14 7
5 2 16
5 17 10
13 20 3
19 1 9
5 5 17
5 4 15
19 13 4
19 20 19
16 9 11
18 19 0
13 18 0
20 4 15
10 16 16
7 10 1
4 2 19
2 1 8
13 10 15
10 11 12
6 6 11
18 12 19
4 10 12
2 18 17
17 0 5
16 5 8
13 12 6
2 5 20
11 17 14
15 8 5
12 7 14
4 7 20
6 7 14
16 0 2
20 17 9
2 2 17
20 20 3
2 19 12
0 14 18
18 1 19
11 4 12
19 10 13
7 12 0
1 5 4
19 14 13
13 13 10
16 0 20
11 19 20
12 2 10
7 7 20
20 20 13
10 14 2
3 0 16
7 16 9
10 12 6
12 17 19
9 10 7
3 16 19
13 2 9
0 9 16
13 11 7
16 1 18
13 3 0
14 13 16
19 7 19
7 14 15
4 5 15
0 19 16
16 11 5
2 10 20
2 14 3
5 1 14
14 7 18
18 14 4
20 20 15
19 10 7
11 15 10
1 3 4
8 2 13
4 7 16
3 15 4
19 10 4
13 17 20
6 11 15
19 1 2
2 16 12
10 6 5
3 10 19
14 17 4
9 10 9
10 8 11
2 6 16
3 17 16
1 13 0
20 8 12
1 18 6
5 19 0
17 4 9
14 3 2
11 2 6
10 2 9
5 4 12
1 10 2
12 2 12
9 0 2
17 7 3
12 0 12
20 0 5
1 13 11
1 0 17
3 7 17
3 3 11
16 13 9
15 20 19
19 14 1
9 4 12
20 8 19
18 13 12
15 11 6
14 4 17
19 17 0
16 12 12
19 20 20
0 16 2
18 8 4
14 4 16
4 0 3
1 1 12
8 10 19
11 9 20
5 4 10
2 20 14
12 4 7
7 5 13
7 5 19
8 14 15
12 15 20
10 16 8
8 2 18
1 16 17
7 6 12
15 20 17
11 14 6
11 12 6
2 4 17
2 1 15
9 8 6
10 14 7
12 5 17
10 11 16
15 2 10
15 16 19
11 18 3
15 18 20
19 0 19
13 20 18
0 6 4
17 12 8
17 18 0
12 5 3
20 11 12
14 2 4
11 14 9
2 9 6
6 20 8
8 15 19
3 3 4
7 5 12
9 8 3
5 20 11
16 6 7
17 0 19
6 18 18
4 13 11
16 2 11
6 13 3
2 8 20
12 16 2
15 7 15
0 16 5
4 6 8
13 15 15
17 9 3
1 19 3
4 17 4
0 4 5
11 11 8
8 10 16
8 7 10
11 17 6
1 11 15
19 10 2
6 16 7
8 5 7
4 16 13
7 15 2
18 0 15
6 12 20
1 19 13
1 19 5
10 0 17
2 8 6
5 7 1
12 14 9
7 13 8
8 10 10
3 1 11
17 17 18
18 17 0
13 15 17
18 13 7
3 3 5
11 20 11
17 5 3
6 10 6
9 20 7
6 17 15
0 8 9
8 19 2
20 0 15
7 20 13
4 6 6
19 10 0
0 12 6
8 1 18
9 18 19
3 2 17
14 6 3
8 3 6
6 5 2
7 5 20
19 1 13
10 8 12
1 16 7
3 18 20
7 8 7
10 20 9
8 7 13
7 15 15
15 4 7
2 15 4
9 7 0
10 19 10
17 17 6
15 12 17
8 12 2
9 0 19
12 15 16
12 7 11
14 19 18
2 11 12
7 19 16
13 4 0
12 19 8
4 8 10
16 16 4
16 8 15
2 12 9
13 14 11
4 8 13
5 1 16
6 8 13
11 5 18
2 4 9
8 4 19
13 10 0
7 12 15
3 16 0
17 13 20
1 16 10
1 14 9
14 12 4
15 2 13
12 13 5
17 14 20
10 14 15
15 10 14
14 5 9
3 13 7
10 7 18
17 0 16
2 18 19
18 11 14
20 5 5
12 17 15
15 17 12
2 1 20
3 20 10
7 0 1
7 3 8
11 18 1
20 14 15
7 7 13
8 1 17
14 1 0
12 9 9
3 10 12
15 8 18
13 3 12
1 7 0
19 5 0
2 16 18
13 2 10
4 2 14
19 15 3
8 9 9
14 19 19
8 13 17
11 18 10
11 8 10
5 5 4
5 16 19
5 18 16
13 3 1
9 16 9
5 4 3
10 9 20
7 6 8
19 5 8
17 11 0
4 15 11
15 13 10
3 14 13
2 8 10
14 17 16
1 3 13
15 18 4
15 18 19
9 3 4
1 10 14
18 8 20
14 19 3
6 11 13
19 6 14
14 3 9
11 1 1
18 7 17
11 14 10
14 6 5
6 10 19
10 6 20
6 10 11
19 8 5
1 17 3
9 13 17
17 9 15
10 14 6
11 17 9
16 16 5
8 10 1
6 6 16
8 14 16
13 18 20
9 20 17
3 0 13
6 19 1
19 3 15
11 9 2
10 5 12
16 17 4
10 17 20
0 1 8
1 6 4
13 11 3
6 5 0
19 7 4
0 7 9
0 20 14
11 19 2
8 17 9
12 14 17
13 15 0
19 2 15
9 4 5
20 6 9
11 13 10
15 15 2
17 13 14
9 2 8
3 6 17
4 19 20
11 10 16
12 1 14
0 7 5
13 7 5
0 14 12
3 12 11
9 7 8
8 6 19
8 9 20
5 18 12
14 8 5
4 20 13
19 9 19
3 13 3
3 18 16
16 19 18
13 6 8
12 4 5
15 17 19
15 8 13
9 16 3
16 9 19
20 6 17
20 9 10
0 15 19
20 18 18
19 6 7
6 15 18
14 14 19
0 12 4
11 16 17
19 19 13
5 14 12
17 8 13
16 11 14
1 15 5
10 8 2
16 14 0
0 0 20
17 10 17
3 10 1
8 15 11
5 18 8
0 0 2
17 14 12
8 0 18
4 18 9
15 6 15
15 5 18
15 7 7
14 10 3
3 4 10
1 11 20
18 2 4
17 9 8
18 1 4
18 16 2
13 14 16
7 7 19
20 10 20
2 0 4
8 19 20
8 10 7
13 17 16
12 7 16
10 0 11
10 1 16
13 1 1
0 19 8
15 14 18
8 18 0
17 4 16
13 4 15
6 7 17
15 13 11
11 3 15
0 2 13
3 10 18
4 7 7
14 20 5
9 19 1
8 16 7
13 1 8
2 9 9
18 4 18
4 17 2
18 8 17
5 12 10
12 4 0
1 7 16
9 13 7
15 0 2
0 14 8
7 2 0
14 14 2
4 16 8
0 13 4
3 2 6
11 19 5
13 19 10
14 0 0
12 8 1
18 18 0
4 14 8
4 17 6
7 2 1
3 8 16
19 20 15
15 19 8
0 2 4
2 1 18
0 6 15
15 19 11
2 8 5
16 2 15
6 17 1
12 18 17
0 3 11
3 15 12
17 5 17
8 0 15
16 5 14
9 16 2
16 1 5
0 15 18
6 13 12
17 16 14
0 4 16
8 11 5
20 13 10
20 12 5
4 18 15
11 1 11
7 2 18
13 15 18
9 3 8
9 19 3
7 13 3
5 7 13
7 16 19
10 4 16
16 18 16
7 18 6
10 13 17
1 15 3
7 16 5
14 5 8
2 11 13
18 0 5
0 9 14
1 8 15
20 3 3
20 1 17
12 6 4
16 20 18
19 18 5
12 16 10
7 9 13
6 1 17
3 15 5
17 13 16
0 2 12
16 10 2
10 4 13
20 13 14
9 7 13
6 16 12
3 18 17
14 2 7
15 10 0
13 13 6
20 8 17
2 8 9
10 20 12
4 3 15
3 15 17
19 19 14
9 10 1
6 14 2
6 6 3
9 12 4
5 1 19
3 15 19
5 9 7
9 19 6
13 3 15
15 5 19
4 14 4
1 5 15
8 8 1
10 19 8
12 20 2
1 7 2
14 7 14
7 17 19
17 1 14
19 9 10
10 18 5
4 18 12
17 12 3
0 5 3
14 1 2
15 16 6
16 8 6
8 5 1
0 9 0
17 20 6
8 10 20
3 0 11
11 8 6
15 14 4
19 16 0
6 2 0
8 6 13
2 13 2
6 1 5
13 6 6
12 13 19
8 18 16
20 7 6
19 19 10
5 10 14
13 8 8
6 16 5
7 12 1
19 17 18
8 3 13
1 11 9
16 3 19
9 12 18
9 19 18
1 15 0
4 4 9
6 16 14
10 18 1
17 18 4
16 15 19
3 7 3
11 19 4
9 18 17
13 10 10
11 16 7
9 1 11
2 14 19
8 5 5
4 17 9
1 2 12
15 1 7
2 0 16
7 2 2
20 8 11
0 16 9
14 3 15
10 10 14
6 0 11
7 18 16
14 16 9
10 16 13
10 17 6
17 10 4
18 5 12
20 9 19
20 16 8
4 19 11
7 15 4
7 10 0
7 4 5
20 1 15
5 15 5
19 18 9
13 2 16
15 5 14
11 6 14
4 8 12
10 3 5
19 3 10
5 14 17
6 15 13
12 13 11
11 1 13
3 8 10
9 16 7
2 3 8
8 18 6
4 6 3
4 4 14
16 10 11
6 0 16
12 6 18
15 19 19
4 17 12
0 13 5
4 3 1
10 12 17
11 11 3
18 18 2
6 19 17
16 6 19
11 16 9
2 5 14
16 3 14
12 5 15
16 15 11
12 10 10
16 10 0
16 17 12
19 0 20
18 20 18
9 6 18
5 6 7
12 10 3
0 20 6
14 14 0
19 8 4
11 6 12
14 6 0
9 19 12
9 20 6
11 10 11
17 11 13
8 8 3
5 14 6
13 9 6
3 11 12
8 10 14
0 12 15
17 0 20
7 9 5
14 9 17
18 13 0
18 6 10
0 12 17
0 15 6
9 9 1
12 9 4
11 9 9
17 8 16
12 2 8
8 7 17
12 16 19
5 1 7
6 18 10
19 10 5
9 5 12
17 16 9
19 4 19
12 14 10
2 15 15
9 11 8
17 10 1
4 10 14
20 20 19
6 16 19
0 3 9
13 17 1
6 3 14
9 13 1
1 18 7
14 10 0
18 9 0
8 1 5
18 2 15
12 14 1
12 9 11
20 1 16
16 19 1
17 19 0
6 19 12
7 8 1
13 16 7
15 11 4
10 20 1
4 15 6
16 20 16
4 16 10
17 20 0
18 0 8
9 5 5
0 6 8
4 18 14
15 6 14
5 16 3
11 0 7
12 19 0
9 16 4
3 15 14
4 6 20
1 1 13
3 11 19
15 16 2
9 1 4
16 3 17
8 12 9
12 0 0
9 8 14
20 19 0
8 0 1
9 6 13
9 3 19
0 16 6
17 10 13
9 16 12
12 20 7
19 17 15
18 14 18
6 7 15
3 7 16
20 15 16
2 9 17
13 6 12
16 5 20
12 15 6
19 14 18
14 12 17
18 6 3
13 12 5
11 16 18
6 12 4
6 20 13
6 1 3
11 10 1
14 13 14
1 3 5
19 12 0
8 15 3
1 5 7
8 9 10
6 0 17
3 8 20
17 8 0
20 12 4
18 7 8
18 8 13
13 7 12
19 18 1
2 11 3
20 17 10
18 12 8
16 15 6
16 11 17
3 18 11
18 11 1
16 5 2
6 20 9
5 15 9
19 19 18
5 7 7
11 14 16
8 5 11
20 0 3
2 4 10
15 11 0
11 5 12
15 5 17
1 16 13
20 11 4
11 11 1
12 6 8
4 18 8
18 10 17
13 3 16
9 14 4
7 18 14
19 19 3
10 5 16
6 3 8
2 18 6
9 5 0
2 16 2
2 13 11
7 16 11
1 1 15
20 13 6
11 9 15
8 10 12
19 20 16
16 17 10
18 20 2
4 2 10
8 16 0
19 10 20
16 0 18
1 12 8
8 8 6
1 18 4
1 17 0
2 10 12
5 16 1
17 18 3
0 14 9
3 15 1
2 6 10
18 10 2
0 10 17
10 11 1
7 17 1
20 13 4
15 9 7
8 6 11
6 6 13
17 18 13
3 11 9
15 14 0
5 19 20
9 15 1
13 11 0
0 5 16
4 13 4
1 6 20
3 1 5
10 9 18
6 6 20
9 16 0
8 14 4
3 20 12
4 19 0
6 11 12
20 0 8
16 16 16
20 5 15
5 3 1
9 7 3
14 18 0
16 12 4
15 15 12
5 20 10
8 3 7
14 15 14
1 8 5
17 3 15
14 10 18
17 2 1
15 16 0
0 6 7
17 4 0
6 4 17
13 1 7
9 18 16
1 4 16
15 1 10
10 17 16
6 19 3
2 15 8
12 1 19
12 12 7
7 2 14
6 5 6
11 10 2
13 19 9
12 8 20
9 18 15
14 10 1
13 5 11
18 8 10
15 18 9
6 17 13
7 11 6
0 11 11
0 8 12
0 12 18
3 8 2
3 14 1
11 12 10
2 20 15
11 19 19
3 17 10
1 16 8
16 11 10
10 5 15
15 10 9
13 7 8
19 2 13
12 0 2
14 7 4
1 16 3
18 14 12
15 4 13
7 12 2
9 2 10
19 11 4
12 18 10
18 9 3
20 20 14
11 8 7
2 20 13
17 5 14
7 10 9
9 13 11
10 12 20
14 20 4
0 15 8
9 20 2
19 10 12
10 2 10
12 6 9
9 6 9
4 2 9
9 2 19
3 16 6
18 15 0
10 17 0
12 17 12
9 3 11
10 16 20
7 14 4
18 9 2
19 8 14
20 16 15
3 13 4
3 16 11
10 2 12
14 11 1
3 9 6
17 6 16
11 13 9
3 19 9
14 9 12
14 1 17
13 12 20
1 7 15
2 0 8
20 7 7
19 8 2
4 14 14
7 3 3
13 19 11
1 0 13
9 10 19
0 16 16
17 6 6
5 11 8
7 20 6
8 9 4
2 10 2
9 9 3
14 10 5
2 15 20
18 20 13
16 14 3
0 4 2
20 16 12
2 7 8
8 8 9
2 9 13
9 1 0
15 8 0
15 0 5
8 19 6
15 10 7
3 8 7
3 19 20
17 12 1
3 18 12
4 20 15
14 4 2
8 5 14
19 15 16
11 5 15
4 1 7
4 20 5
7 5 18
12 9 13
18 6 0
12 18 8
7 14 20
18 6 18
4 3 8
16 4 8
20 8 0
4 14 1
16 12 17
5 5 13
12 15 7
14 3 0
7 9 9
17 13 2
13 4 1
8 20 17
8 16 14
8 20 14
20 5 14
16 18 6
18 14 10
6 4 14
1 18 9
8 13 5
8 3 14
14 10 10
19 10 10
5 6 2
6 8 6
0 16 14
13 9 11
2 9 5
4 4 10
4 19 6
17 12 19
3 10 0
16 2 7
11 7 12
17 6 3
15 19 7
12 9 10
14 3 17
13 19 0
15 5 10
7 8 4
12 12 20
17 10 7
10 13 6
0 10 18
19 10 16
13 2 20
4 20 20
17 8 8
17 16 16
2 8 18
8 11 13
13 17 0
11 5 0
12 0 8
17 16 5
3 4 17
7 18 18
14 20 9
11 19 17
12 3 1
13 2 5
10 14 4
20 20 10
12 8 17
18 7 12
16 15 18
19 12 3
17 1 2
20 3 8
17 11 3
13 20 4
11 20 15
14 6 14
11 2 0
6 18 0
16 7 12
10 20 10
4 15 16
11 12 1
8 20 6
10 4 7
4 20 9
12 12 5
11 2 9
4 16 11
10 1 3
0 5 7
17 10 16
1 20 2
13 16 11
4 13 8
4 10 11
20 20 1
16 1 3
10 2 5
0 7 0
8 9 12
1 2 2
2 6 0
10 2 7
15 1 8
13 9 4
5 7 14
3 9 14
8 7 11
14 7 6
18 2 1
19 5 16
11 6 5
20 16 6
13 12 10
12 0 15
10 3 15
2 2 0
16 17 17
0 19 4
16 8 9
14 3 20
3 3 3
3 20 7
2 20 9
1 14 6
3 2 8
10 2 1
13 3 2
10 9 15
17 19 18
11 18 17
8 6 1
9 18 14
10 9 1
7 13 14
16 13 8
4 5 11
14 2 18
14 13 18
18 13 20
12 11 9
15 20 6
15 18 10
8 10 17
15 3 18
10 10 9
7 4 0
18 0 16
10 20 13
18 13 8
17 1 7
2 2 14
16 12 13
9 1 7
6 9 20
6 17 4
8 13 9
2 4 16
14 20 11
4 6 5
17 17 20
11 18 15
2 5 7
12 11 7
1 0 8
17 17 16
7 18 10
14 9 7
12 11 2
7 17 8
17 1 4
2 3 20
0 13 13
20 19 1
14 3 4
8 14 10
20 11 17
20 1 13
15 10 3
19 3 19
4 4 0
14 5 18
11 2 10
7 17 15
14 8 16
7 6 19
14 1 19
17 17 12
16 20 6
2 14 17
18 15 5
13 5 18
16 14 11
10 18 3
12 18 6
19 12 8
15 14 17
14 7 13
7 5 2
3 9 18
19 5 3
3 19 13
16 16 10
16 5 5
2 10 17
1 10 13
0 20 8
4 12 19
4 8 18
4 8 20
1 9 7
8 4 8
7 0 17
11 8 18
2 2 15
13 5 12
5 8 6
11 3 3
12 7 12
17 12 9
14 0 10
1 12 10
13 15 19
19 7 3
4 6 4
8 15 1
8 5 12
17 4 8
3 10 7
0 13 11
11 7 20
10 1 4
3 8 12
11 17 7
7 20 18
7 12 11
18 15 15
16 20 2
7 9 6
6 4 6
14 6 20
2 12 11
10 2 6
1 7 8
17 5 8
20 11 1
19 15 14
7 6 17
17 2 20
15 19 5
1 6 5
0 9 8
14 4 11
19 12 5
18 17 9
10 10 8
1 18 19
12 4 18
19 5 4
4 16 17
11 16 12
6 17 19
18 20 20
18 8 3
9 6 4
0 12 20
8 9 17
13 7 14
0 9 9
16 7 17
14 8 0
8 20 3
9 6 2
7 4 14
20 18 1
11 3 8
9 14 16
6 18 7
20 3 1
3 20 6
20 13 8
10 19 1
1 13 9
16 11 12
0 1 11
18 12 11
12 8 15
18 1 10
0 9 2
12 4 16
20 12 8
6 0 7
14 12 14
13 11 9
3 3 12
6 3 0
16 11 2
13 20 8
19 11 7
14 10 15
4 11 19
12 10 6
19 18 2
17 7 16
0 1 1
0 7 8
15 0 9
13 3 11
1 19 4
2 5 2
9 4 16
4 10 18
1 0 6
0 2 16
14 0 8
2 6 15
15 6 1
10 8 8
11 8 19
10 18 11
9 16 20
16 15 0
12 20 11
10 17 19
11 15 7
11 9 13
5 14 13
5 1 11
15 3 15
13 6 7
1 8 10
20 14 12
19 6 2
7 9 20
19 0 10
15 6 17
14 10 2
3 4 0
16 17 6
11 9 18
15 6 12
5 9 2
7 13 12
16 1 10
13 14 6
5 4 8
3 9 3
2 6 2
2 3 15
16 12 8
20 15 17
18 6 17
5 4 18
19 4 11
15 14 12
5 15 18
14 0 15
16 6 20
0 15 3
14 16 16
0 19 1
7 19 13
10 6 18
7 20 12
14 2 11
11 1 3
14 17 12
2 12 0
12 16 18
11 20 18
7 8 15
9 2 1
5 1 1
0 16 12
10 6 0
9 9 7
3 7 20
17 2 8
16 18 20
20 0 19
8 8 18
6 5 16
11 14 3
3 18 13
17 7 19
20 3 17
14 19 4
10 13 19
3 1 13
3 15 11
6 9 13
12 0 17
13 8 7
14 15 1
17 7 0
7 4 18
10 3 16
14 0 5
0 5 5
9 1 13
2 4 3
17 19 20
15 16 14
18 11 10
4 2 5
5 2 9
15 16 9
12 18 18
15 6 18
19 11 16
1 6 19
17 5 10
4 1 14
15 7 20
20 18 20
13 2 2
5 13 18
19 15 12
16 18 5
13 4 11
8 17 7
12 10 9
10 0 7
6 4 20
20 8 10
6 2 12
12 20 10
4 9 12
15 19 6
7 4 11
15 20 5
6 15 5
8 7 5
17 14 4
11 14 20
18 0 7
2 19 13
2 4 1
19 4 3
1 18 8
6 6 12
8 11 8
12 1 5
12 13 1
18 9 14
6 12 14
2 19 1
10 16 4
11 13 2
0 9 12
12 5 16
10 13 11
1 1 1
20 11 6
14 7 16
13 5 9
17 11 6
19 11 6
11 6 9
14 4 10
3 11 13
18 0 3
2 13 17
4 3 9
0 11 3
14 18 12
14 19 20
8 11 20
19 0 17
19 13 10
9 1 15
12 8 11
3 6 5
19 20 8
7 20 16
13 3 13
10 12 10
9 1 17
2 11 18
17 5 0
9 18 13
11 20 17
11 18 13
2 7 14
17 15 13
13 12 13
4 2 7
3 9 1
4 12 10
15 1 5
17 7 2
3 11 4
5 14 16
10 7 3
7 12 18
13 17 2
4 14 18
12 19 12
6 8 14
9 9 8
12 19 11
17 14 0
11 19 14
1 4 2
17 7 7
16 19 13
12 5 0
13 8 1
12 20 13
3 9 7
14 1 16
15 10 13
3 4 20
19 3 0
14 18 4
7 0 12
11 20 0
20 18 4
14 18 3
16 11 11
2 19 7
6 7 10
6 6 18
11 20 4
5 7 5
10 3 1
3 5 9
0 15 2
19 13 13
15 9 0
20 16 16
12 9 14
15 1 15
4 20 12
20 4 11
18 8 6
2 0 1
12 15 1
9 4 6
18 19 14
18 9 20
3 0 4
11 9 1
20 13 18
19 17 12
16 10 8
1 11 7
11 15 9
2 20 12
2 3 9
18 8 12
4 13 1
16 12 3
20 8 7
19 16 8
10 19 18
14 7 8
16 15 13
12 5 19
12 11 6
1 0 11
17 5 12
14 16 20
5 20 16
7 20 5
20 4 8
10 16 10
8 12 8
13 13 8
6 15 2
14 5 12
0 6 12
20 7 5
19 0 0
1 8 9
5 1 4
13 4 7
16 3 11
7 7 1
18 18 16
12 14 5
8 7 19
13 0 12
10 15 16
5 6 17
10 19 2
16 13 16
20 18 16
8 7 3
4 14 11
1 2 6
0 11 12
9 11 2
14 17 7
10 1 12
16 4 13
10 3 17
4 0 6
20 2 7
0 4 12
10 3 10
15 18 1
18 15 3
4 13 16
18 20 15
16 0 17
7 16 7
20 4 9
7 15 20
14 7 7
11 7 7
17 14 9
7 9 2
14 20 17
18 18 19
14 17 15
8 17 6
6 3 1
4 6 16
5 6 14
20 17 13
17 4 19
5 8 16
1 13 6
9 7 6
4 5 2
20 9 2
13 12 15
9 16 16
18 14 6
19 12 6
0 12 8
10 11 14
20 17 6
6 5 3
1 6 16
9 2 12
17 8 4
4 8 14
1 8 1
11 4 14
16 5 4
18 13 1
10 9 6
15 7 19
7 9 18
5 2 18
19 8 3
19 2 4
16 1 15
10 14 10
3 4 11
18 17 20
13 8 0
10 17 8
7 20 20
7 3 10
8 9 3
2 9 7
2 2 10
4 9 19
17 19 17
16 11 16
4 6 7
12 19 6
8 1 16
20 2 1
7 5 7
3 4 5
11 12 13
7 19 19
18 12 18
5 17 3
13 9 7
13 3 7
9 6 15
1 12 18
17 11 9
15 9 15
20 9 9
20 3 9
12 9 6
16 15 14
6 12 13
20 7 13
0 5 20
6 8 4
12 5 12
5 4 6
19 10 15
16 17 8
15 10 10
4 1 10
0 18 13
8 20 0
0 19 11
13 11 14
9 14 2
16 8 13
16 5 0
6 9 10
6 5 17
17 9 1
7 12 5
11 16 2
11 11 16
20 0 6
12 4 8
17 5 20
18 19 11
6 6 19
8 19 16
15 11 8
14 4 8
11 13 7
11 4 11
12 11 3
1 18 1
4 16 18
1 10 19
12 17 11
20 16 14
17 14 16
14 5 5
5 19 17
10 0 18
6 1 7
7 5 15
5 15 11
12 3 7
3 20 16
8 6 8
10 5 7
1 4 6
20 2 4
15 9 10
8 8 16
2 17 19
16 11 20
6 10 5
17 5 13
13 14 0
6 19 15
0 1 6
9 8 2
8 4 4
7 6 2
8 10 11
4 20 10
4 19 8
11 17 12
18 0 14
15 13 3
7 9 11
0 3 17
4 4 17
18 18 4
9 3 1
6 6 6
11 8 20
11 0 3
19 16 7
3 7 12
5 7 15
5 13 6
3 13 17
19 18 7
14 11 18
14 8 13
7 19 0
13 6 16
14 13 13
9 1 16
5 6 5
20 15 13
1 18 20
14 15 3
20 14 20
12 6 14
17 20 19
19 17 17
20 13 7
9 9 12
16 7 0
13 1 10
5 9 0
15 15 3
6 15 7
13 9 20
15 8 9
14 20 16
0 14 1
13 1 9
11 14 17
15 2 4
6 15 1
9 12 11
9 18 2
14 15 7
9 5 8
18 10 15
7 10 11
20 4 18
8 8 19
8 8 12
10 9 2
6 0 10
2 9 3
16 8 20
8 0 5
4 9 5
3 4 13
3 3 2
7 10 14
8 12 4
4 6 2
20 0 1
8 5 8
8 19 10
0 6 11
12 1 16
8 0 8
6 11 6
6 15 20
10 12 19
20 5 9
1 14 3
9 16 17
1 12 7
19 5 5
3 0 8
10 10 12
0 3 10
13 14 20
5 20 7
6 1 4
11 16 15
0 9 4
2 20 17
15 1 3
16 5 18
4 4 12
2 9 20
10 2 16
5 0 16
12 4 12
0 0 17
17 19 10
18 7 9
4 1 2
10 12 9
0 11 16
0 1 16
1 11 6
2 14 16
5 19 10
3 15 3
20 14 1
12 7 3
1 15 7
15 13 13
8 7 6
4 5 7
11 16 16
20 11 10
2 14 9
1 10 9
11 20 6
1 10 16
1 7 12
20 18 9
17 15 18
9 0 20
20 14 17
20 8 20
11 9 19
14 18 10
7 19 5
4 7 2
7 19 6
2 10 16
6 7 19
20 6 19
19 18 13
11 6 17
6 11 16
9 16 11
3 16 3
11 13 1
11 4 17
1 17 14
20 18 8
0 1 5
16 19 7
1 19 7
14 5 3
6 17 7
14 12 8
13 20 9
5 14 1
18 3 1
10 16 15
13 0 16
11 17 13
2 10 15
10 10 1
15 18 6
11 18 16
4 7 0
8 4 3
1 6 10
16 18 11
3 11 1
12 2 4
6 10 18
9 14 7
12 20 20
17 9 18
18 10 4
10 0 9
1 2 0
6 13 13
2 17 15
9 2 16
10 16 19
11 6 16
13 17 5
17 6 19
7 10 8
14 17 13
16 11 3
1 13 3
18 3 20
13 11 17
12 12 12
18 1 16
3 14 4
8 19 15
16 1 11
3 17 11
7 5 4
1 14 19
7 7 12
14 19 17
17 2 15
3 9 19
15 3 17
6 6 8
1 7 5
8 20 7
19 13 12
0 6 13
2 3 5
15 20 8
3 19 12
5 8 11
8 12 15
15 0 0
9 2 13
20 18 13
10 4 18
4 16 5
11 3 16
15 8 14
15 9 9
5 10 10
10 9 7
11 2 4
0 20 18
12 12 9
15 4 8
18 15 7
18 7 0
4 5 4
3 0 6
5 18 7
3 19 14
6 1 12
8 14 11
18 5 3
1 3 19
5 17 14
20 7 0
2 14 7
14 5 0
7 8 9
17 7 14
20 9 14
5 15 19
3 17 14
3 5 11
4 12 18
14 9 2
13 2 18
20 12 11
3 19 0
15 4 0
9 16 19
13 7 16
4 8 3
20 0 10
9 12 17
0 3 14
2 11 10
18 9 12
1 9 1
19 3 3
6 14 7
3 9 9
19 10 9
4 14 5
17 15 11
3 2 13
13 5 1
17 3 6
15 10 5
19 16 17
7 11 19
10 20 2
0 15 10
9 11 15
4 9 2
10 19 0
13 2 8
6 5 4
5 18 13
16 2 0
3 20 9
20 0 2
15 4 4
12 12 18
0 15 5
19 15 17
6 19 8
6 3 2
5 0 3
20 17 15
16 4 17
14 9 20
10 13 12
4 4 2
6 13 14
5 2 12
3 10 15
9 8 11
3 16 20
15 4 20
11 15 4
12 6 1
10 8 0
1 14 0
1 2 15
6 12 5
18 11 8
7 9 15
1 2 8
20 10 14
14 13 7
3 15 13
19 20 6
0 3 7
2 0 11
6 13 17
12 6 11
16 5 17
8 19 3
18 4 3
3 13 19
7 4 7
1 15 2
18 7 5
10 19 3
17 11 10
16 10 15
14 17 18
9 6 14
15 8 3
2 18 0
14 2 2
14 18 13
3 17 12
5 3 11
11 0 4
7 14 6
5 8 0
3 4 16
6 10 9
1 14 4
9 19 5
8 5 10
18 11 4
17 17 3
4 18 5
12 2 17
0 10 8
6 10 15
14 16 17
16 14 6
15 2 12
19 8 20
13 20 6
13 17 18
8 0 11
7 19 15
6 0 0
0 0 7
3 2 0
16 10 13
2 0 5
13 8 3
18 5 5
4 3 7
11 3 5
1 7 13
15 18 13
9 1 20
9 2 17
19 8 8
0 6 5
5 15 16
8 20 20
0 4 17
5 8 13
2 3 4
0 3 6
16 17 9
20 19 16
19 11 20
16 18 1
19 10 11
16 14 8
17 18 19
1 15 14
20 11 7
4 14 17
18 19 15
5 11 14
0 6 3
4 19 19
9 17 10
20 13 20
8 9 19
3 6 19
17 15 2
8 0 13
3 3 15
7 20 10
11 9 17
6 17 11
19 7 17
20 0 13
0 4 8
14 14 15
19 5 7
16 10 1
0 12 7
20 11 13
3 5 5
3 16 7
5 19 7
2 19 10
19 16 4
11 3 10
7 13 13
13 18 19
13 20 15
11 10 9
10 0 6
6 15 4
4 13 12
15 1 13
17 3 12
2 6 11
20 6 5
17 6 9
9 3 2
19 8 12
10 2 2
7 4 19
18 2 3
17 20 10
5 0 10
5 17 18
9 18 7
19 0 5
13 6 20
15 8 11
16 18 19
18 9 17
15 8 20
10 7 17
5 1 6
19 13 16
19 4 15
0 4 18
10 2 8
0 3 5
13 10 2
16 7 7
16 16 15
20 12 9
18 17 5
4 2 16
1 9 9
6 8 16
7 11 13
3 7 7
9 16 15
0 2 6
9 13 15
9 12 14
17 2 3
5 15 10
1 20 3
20 14 14
10 13 10
20 4 19
1 4 3
18 6 14
19 13 7
8 3 9
5 0 5
16 17 19
5 16 16
4 10 2
2 4 14
19 6 19
5 1 18
13 3 9
0 1 12
2 2 19
17 18 17
20 2 17
12 9 18
7 8 11
5 9 4
7 5 0
3 0 3
15 20 12
8 19 4
10 9 4
10 15 8
9 13 10
2 4 11
1 2 16
5 6 16
18 3 14
1 17 5
5 15 2
16 14 9
5 4 11
14 1 13
7 5 17
3 11 10
14 12 3
17 0 13
12 3 8
5 12 5
2 8 12
20 2 15
10 14 11
9 12 3
15 0 17
2 5 3
10 15 15
16 9 4
16 9 18
7 5 3
9 4 19
13 14 10
18 6 19
7 0 14
20 7 20
14 18 20
10 1 19
2 7 12
19 4 7
10 18 2
15 16 20
3 20 0
0 7 6
9 0 0
9 17 11
10 16 18
2 20 1
12 3 15
13 12 7
12 1 8
15 17 2
14 9 10
14 17 9
8 6 17
3 3 19
19 3 6
18 2 10
8 16 12
3 5 19
0 3 18
11 14 19
13 20 13
19 8 13
16 14 2
16 0 11
1 20 5
1 5 14
5 1 8
8 20 4
20 5 12
19 1 7
20 14 5
15 7 12
7 1 20
6 5 10
1 2 3
20 19 8
16 0 8
16 4 3
11 10 12
18 14 13
20 20 12
0 20 12
7 1 9
6 16 9
17 18 1
10 15 14
1 0 12
20 17 18
6 11 18
17 18 20
13 1 16
6 19 11
8 11 14
1 5 3
0 11 6
16 7 11
13 19 6
6 3 16
16 18 13
8 11 12
14 14 13
14 13 4
4 14 13
6 19 18
19 17 13
10 16 0
12 3 9
4 12 8
12 5 6
4 2 15
14 15 18
5 9 9
13 20 2
5 0 0
15 2 2
20 19 7
9 7 10
13 8 14
1 18 14
10 10 10
3 9 11
9 2 9
5 7 12
19 9 0
4 3 5
18 20 7
18 20 1
16 19 16
9 16 8
1 19 12
16 17 16
1 5 5
8 2 17
16 1 17
12 17 3
6 19 14
16 1 19
5 13 0
20 10 18
0 20 17
2 20 0
20 10 13
19 14 20
7 11 8
1 19 9
0 13 6
10 11 11
2 15 18
17 14 2
6 17 12
19 16 15
4 2 6
7 8 16
10 15 10
3 6 3
12 19 16
15 16 3
2 9 11
9 9 13
1 8 11
5 17 20
15 5 5
1 8 18
17 15 10
15 19 4
7 6 13
7 11 7
7 1 0
3 8 6
16 8 14
14 19 11
12 14 6
2 8 15
6 15 8
0 12 9
4 18 0
17 2 10
4 17 17
8 18 17
18 5 4
4 4 6
0 8 15
12 20 1
0 17 15
8 19 8
2 4 7
13 4 16
5 14 7
16 4 18
17 3 7
10 5 14
7 13 16
10 17 2
16 18 17
5 0 19
14 6 2
7 19 3
13 19 14
19 20 1
5 5 5
8 16 4
6 11 9
12 11 16
16 15 10
12 15 0
15 14 3
10 0 10
6 5 7
7 14 2
7 1 10
15 20 1
12 11 15
3 10 3
1 4 17
5 9 5
20 18 0
9 17 0
5 2 2
2 3 14
18 20 17
7 4 8
16 19 6
12 16 17
16 6 1
13 10 5
13 4 13
20 13 2
15 18 16
10 9 12
15 9 13
15 6 6
6 17 6
20 14 0
17 8 9
3 10 6
10 9 3
9 10 13
3 15 6
20 15 0
19 1 11
11 16 14
3 13 18
9 10 15
7 13 2
12 13 4
6 17 3
18 5 16
14 7 19
17 7 12
17 8 12
9 14 8
18 3 16
0 5 4
20 19 5
20 10 10
3 12 7
20 4 2
19 20 12
11 19 8
16 19 15
2 7 1
8 9 7
5 14 4
18 0 18
8 2 10
20 1 4
16 6 6
10 12 5
3 2 15
12 7 0
0 4 9
17 10 15
18 17 12
11 2 12
7 14 11
3 8 0
19 0 12
15 7 2
8 12 10
7 7 0
20 14 13
20 9 17
5 12 19
19 4 12
10 6 17
20 10 19
13 17 3
6 1 13
5 12 13
19 11 18
11 8 3
11 0 15
5 10 15
6 2 6
8 18 4
8 0 16
2 16 0
14 7 0
13 4 17
9 19 14
6 7 8
19 0 9
2 9 4
2 6 19
14 7 1
12 10 11
20 4 13
18 11 2
5 16 9
13 4 14
18 16 17
8 14 20
13 15 20
16 20 0
0 13 8
12 6 5
2 13 19
5 13 3
18 16 18
17 9 4
19 1 3
12 2 11
10 20 18
7 4 3
14 17 17
9 14 10
10 1 15
15 14 5
18 0 12
2 18 8
5 10 5
10 12 8
15 1 11
3 19 6
16 5 15
9 5 18
3 20 17
19 16 13
9 12 13
0 5 12
3 6 10
11 19 7
1 0 20
3 0 9
1 16 20
7 15 9
17 12 4
2 0 3
4 20 2
17 13 10
18 1 2
19 19 15
5 4 0
15 19 18
11 6 7
8 11 19
16 9 8
12 3 10
16 20 19
6 8 18
14 11 5
15 20 15
16 7 18
0 3 3
5 8 17
3 14 18
17 13 8
10 14 16
18 1 18
3 13 10
4 8 1
20 16 20
11 4 16
4 17 8
0 20 9
12 12 4
17 2 17
18 14 14
17 5 2
1 19 10
18 3 11
0 6 19
12 15 2
0 17 2
7 19 11
19 8 17
14 0 14
12 2 20
18 17 19
5 6 12
7 11 4
12 4 6
7 20 4
16 4 11
12 12 3
20 20 5
4 1 1
18 2 14
1 20 12
14 1 8
4 3 12
9 7 1
18 6 12
0 14 19
10 1 8
20 15 14
0 0 14
20 0 14
16 4 20
16 6 0
8 2 20
12 9 0
11 19 16
7 17 4
7 20 8
9 16 14
9 4 0
9 5 7
14 20 2
20 10 16
7 2 16
15 7 4
12 8 16
15 9 1
14 12 1
19 4 20
3 16 18
15 3 14
8 17 10
4 13 9
15 8 16
1 20 10
6 8 17
15 11 12
12 7 17
19 1 5
7 5 5
8 9 8
8 14 7
16 13 20
4 2 8
10 9 16
20 1 5
15 4 16
1 9 10
0 0 5
15 11 7
15 2 19
19 20 11
7 9 19
3 17 18
19 2 19
13 18 10
10 4 19
20 8 9
7 3 7
20 15 8
8 11 10
8 6 6
7 13 20
14 1 11
20 17 5
8 6 14
14 12 7
17 16 10
3 19 18
19 15 8
1 0 7
0 8 11
17 6 15
19 14 8
7 3 13
16 17 2
19 10 1
0 12 5
13 17 6
9 5 4
17 8 6
0 4 11
3 20 1
5 10 17
8 7 8
10 16 6
11 17 5
19 0 2
0 8 2
14 17 11
12 13 12
16 12 5
4 7 10
18 0 20
16 0 10
1 4 12
7 8 2
1 3 7
13 12 19
3 12 1
10 5 6
0 15 12
17 12 6
6 16 18
14 3 5
15 20 20
1 10 6
2 20 3
4 10 3
9 4 4
12 12 6
5 8 19
0 19 0
1 20 9
4 16 9
5 1 2
8 10 0
4 12 3
13 1 12
12 13 13
13 15 3
9 14 5
20 5 17
16 3 12
8 5 3
9 14 9
14 15 10
18 20 5
13 13 16
1 3 0
16 2 3
10 12 0
20 17 19
8 4 5
12 19 14
15 17 1
8 8 14
11 2 1
2 8 16
16 9 15
3 6 20
1 10 17
18 7 4
3 20 18
8 8 10
18 3 18
13 20 20
19 6 17
2 17 9
14 1 14
7 9 16
19 15 13
19 11 9
11 16 10
5 7 19
12 2 0
10 11 5
0 9 7
5 2 20
17 9 0
10 13 5
2 11 17
1 5 8
5 6 15
10 7 13
8 8 17
15 3 12
16 1 16
2 6 14
3 14 8
15 9 3
12 16 0
13 8 9
19 10 17
0 9 17
13 12 3
7 2 7
11 8 2
4 12 11
4 17 13
8 13 15
9 9 11
5 13 19
3 20 5
1 13 20
8 15 10
12 4 17
13 10 1
18 11 0
3 17 8
4 15 13
4 8 19
17 10 3
13 17 8
19 9 2
10 15 11
17 19 19
9 19 15
4 9 15
5 17 15
3 19 11
11 8 1
9 4 7
0 14 6
14 14 9
19 7 13
3 0 18
17 18 11
13 7 19
20 5 16
1 7 20
14 3 19
17 0 8
1 1 20
2 19 8
9 18 1
5 14 2
15 12 8
15 4 17
16 13 11
0 10 5
4 13 13
14 13 9
8 14 9
10 15 9
1 3 6
4 1 11
10 10 4
13 11 11
19 17 10
11 19 11
10 17 7
11 8 8
14 18 1
9 4 10
16 12 18
4 1 5
13 12 18
2 14 15
18 11 9
5 16 18
3 14 2
14 6 15
3 8 17
1 12 4
2 11 19
11 14 4
8 18 10
4 5 0
13 12 8
7 8 0
15 16 11
6 2 14
20 8 13
0 5 14
14 11 19
18 13 10
11 6 10
15 0 3
4 0 18
13 15 16
3 16 13
9 11 13
9 5 14
4 9 11
10 6 16
2 10 18
18 3 15
6 0 20
2 7 11
11 18 18
10 1 7
11 5 9
2 8 13
8 1 8
17 3 4
18 17 6
6 5 1
14 17 10
18 9 10
3 4 18
19 18 10
16 6 17
7 18 13
15 17 4
3 4 4
1 12 20
18 19 16
8 17 14
2 16 11
11 1 5
11 9 3
10 7 10
17 12 11
14 11 11
7 7 18
20 18 10
8 17 1
1 7 3
16 11 9
15 16 15
16 7 20
12 3 18
20 12 6
0 8 0
6 13 11
20 4 7
13 1 19
4 4 1
5 14 11
4 10 15
3 1 18
11 12 7
19 14 19
1 13 12
2 15 13
13 17 14
1 3 1
13 20 12
10 15 2
10 16 14
11 2 8
12 13 14
1 7 18
7 11 20
16 9 5
14 19 1
4 11 5
12 5 4
9 14 14
3 6 18
0 4 1
14 2 8
20 16 2
2 11 14
0 18 0
9 8 1
19 13 14
11 14 14
20 19 14
7 10 18
1 6 0
4 3 0
12 2 16
6 17 5
13 5 2
18 5 9
7 6 11
20 0 18
5 20 15
19 6 6
15 14 19
9 19 4
20 11 2
2 1 14
11 20 1
12 11 14
2 3 7
20 4 6
17 2 9
5 17 9
4 4 15
5 3 18
7 12 16
9 1 18
5 12 2
11 11 20
20 12 12
14 7 10
3 6 4
12 2 19
1 13 13
14 2 5
19 20 18
17 10 10
16 5 9
19 18 20
14 0 6
1 1 14
3 1 3
15 10 20
3 8 1
13 12 2
7 0 18
20 3 16
20 4 3
14 7 5
13 12 9
2 19 11
7 11 17
10 15 17
18 18 15
15 19 12
16 3 8
8 11 3
16 14 19
11 5 20
18 6 5
12 14 18
18 1 11
18 13 6
12 9 5
7 8 20
12 3 6
19 0 4
2 16 15
1 14 8
6 2 3
14 7 20
16 1 12
18 7 10
16 11 15
0 17 1
17 9 6
8 11 1
5 1 3
20 18 5
10 2 18
1 17 6
6 15 6
9 9 19
8 20 19
12 0 7
12 1 9
17 17 2
5 9 16
11 12 18
6 19 9
17 13 5
4 13 5
9 20 12
16 10 19
8 2 1
8 20 5
0 19 14
20 4 4
8 12 18
7 2 19
1 19 1
13 15 1
2 17 0
4 9 7
4 19 10
0 4 19
6 1 20
1 5 6
12 9 3
7 16 16
18 16 20
5 20 9
8 14 2
16 10 3
17 20 17
17 19 6
19 18 17
15 11 13
12 15 5
7 18 8
2 6 20
15 12 6
15 0 1
14 1 7
0 10 1
4 12 12
8 9 11
16 18 15
19 5 10
11 9 0
18 1 15
16 2 8
8 13 2
15 4 9
9 1 6
16 2 2
0 4 13
15 7 13
4 10 13
0 1 19
1 8 0
4 1 6
16 11 4
12 11 8
17 15 15
2 1 2
20 2 19
10 11 2
10 4 3
2 12 12
15 12 14
19 17 3
2 13 7
18 12 3
7 14 7
0 16 8
10 8 6
6 0 14
20 12 1
7 14 13
7 16 15
2 17 14
18 13 19
5 17 1
0 17 12
3 1 2
3 15 8
19 5 6
17 12 16
6 18 14
0 17 3
12 10 0
9 3 18
12 18 13
4 5 13
13 19 16
10 4 20
18 11 19
17 13 17
5 5 12
18 19 4
16 13 5
11 3 13
2 10 19
4 12 7
15 11 11
2 2 9
13 1 14
17 7 1
9 13 3
2 12 18
6 4 11
6 5 12
7 8 8
1 9 2
18 10 6
8 2 6
15 4 11
13 4 12
0 16 1
17 9 5
6 13 1
16 2 5
1 17 19
14 11 12
20 9 1
4 1 3
15 12 19
10 10 17
9 0 15
15 16 17
17 3 13
17 16 15
13 19 17
15 7 17
10 10 7
5 14 14
7 7 10
19 2 10
11 15 6
7 7 4
2 17 20
16 12 19
10 8 5
13 11 8
8 13 3
19 19 11
7 1 14
4 13 15
14 19 9
6 15 19
17 3 1
3 2 14
18 19 3
10 8 18
1 16 4
1 3 9
4 0 10
13 13 3
4 2 12
16 14 14
12 12 15
11 6 0
8 10 4
8 7 18
7 3 18
8 10 5
2 12 4
8 20 16
14 3 14
20 3 12
8 5 2
18 1 5
18 16 16
10 7 2
7 12 7
18 15 10
16 2 14
18 15 18
7 19 12
10 20 4
16 19 10
1 2 1
5 20 12
16 13 14
14 9 0
9 8 7
15 10 1
6 14 13
14 9 15
2 2 6
11 6 15
18 0 6
6 18 17
20 15 6
8 3 0
20 3 13
17 7 4
19 16 16
4 3 19
6 16 4
16 14 5
0 0 8
19 6 1
13 9 13
1 2 19
6 10 20
13 8 5
11 18 12
15 3 5
17 5 9
2 1 10
6 19 16
12 0 18
1 19 18
9 10 3
12 14 11
11 11 12
13 8 19
1 17 20
17 0 18
9 15 13
1 7 10
18 14 11
17 12 10
15 8 10
11 15 0
13 18 1
2 5 17
15 17 6
11 1 8
16 3 4
3 0 14
11 4 2
19 14 3
18 5 8
4 12 14
3 3 0
0 20 7
1 12 0
13 9 0
1 9 12
13 18 12
7 8 19
8 16 18
12 8 13
11 16 3
16 16 17
13 12 12
15 13 18
17 3 11
8 20 13
16 2 12
17 13 15
17 16 6
11 17 18
13 13 17
0 3 15
16 0 0
15 11 19
16 15 4
1 5 19
20 0 12
14 18 14
4 11 16
14 18 17
9 4 18
18 20 19
7 15 0
5 0 11
16 4 19
8 5 19
11 15 11
12 14 19
7 9 4
8 18 8
17 11 15
19 5 20
19 12 13
7 12 17
0 3 8
1 5 1
17 8 10
0 9 11
9 4 2
1 12 3
6 15 12
16 13 17
8 8 2
14 18 6
18 3 7
18 5 7
19 3 20
15 10 2
15 4 1
13 18 7
1 4 18
5 18 1
8 3 19
17 13 3
10 9 11
10 9 0
3 3 17
11 12 3
15 2 9
8 6 12
18 7 6
2 17 5
7 3 12
17 14 6
7 9 8
6 2 18
16 10 5
5 5 7
2 10 3
2 5 12
16 20 5
13 7 7
19 13 15
0 5 6
4 13 6
4 2 20
19 4 6
6 5 15
7 6 0
20 7 1
9 17 1
20 1 7
13 2 11
11 4 1
14 12 19
12 0 1
11 6 4
17 4 13
19 12 19
3 9 13
13 16 0
12 6 15
15 2 16
20 1 8
8 1 14
11 20 19
13 14 8
12 17 20
1 1 17
16 6 16
2 13 12
6 9 0
13 8 17
4 4 16
17 13 13
10 15 5
19 1 18
12 10 19
15 15 5
4 4 7
3 17 20
1 11 18
13 7 20
5 11 9
17 2 7
0 3 16
12 4 4
0 7 2
2 14 8
4 12 2
0 5 11
15 7 3
20 18 12
6 9 12
0 13 1
5 5 10
18 18 5
10 20 5
18 14 8
8 13 14
17 11 16
3 5 17
11 9 6
0 16 4
0 6 9
5 0 6
2 18 12
12 2 9
13 19 5
18 10 9
0 18 6
7 20 14
5 19 2
12 5 2
20 18 3
13 0 0
10 17 11
17 15 6
19 7 16
5 4 16
18 11 15
20 5 3
10 11 0
3 5 14
15 0 13
7 4 20
10 19 5
20 11 0
12 9 8
9 0 8
16 7 13
2 18 2
2 6 1
17 2 5
17 0 14
8 20 10
20 19 6
2 4 6
1 15 15
14 6 6
17 2 12
1 11 14
7 15 14
0 20 16
3 6 1
15 19 2
17 4 20
18 8 16
10 18 0
1 7 11
0 17 17
14 9 8
14 11 17
4 2 1
4 17 5
19 15 11
16 16 13
19 18 12
11 18 4
17 1 0
20 12 19
12 13 2
10 12 15
15 14 16
17 4 5
3 1 0
4 14 20
16 6 8
1 18 10
9 2 5
17 14 11
9 17 7
4 10 8
9 3 13
1 17 2
8 15 2
13 7 3
6 17 2
4 0 20
1 16 11
0 13 10
7 6 16
14 5 19
12 1 2
12 14 0
19 5 13
19 15 19
16 11 6
5 7 16
18 10 12
7 0 19
12 3 5
16 17 11
9 3 5
8 4 15
14 3 3
17 17 14
4 9 18
13 9 3
12 17 16
16 5 3
4 7 18
8 13 20
17 19 7
7 11 2
8 1 11
20 3 2
1 0 4
8 6 15
2 17 11
9 11 4
7 4 2
15 14 11
6 1 11
3 14 9
10 16 1
7 0 16
4 9 1
0 14 13
8 18 19
1 10 5
7 7 17
13 13 9
7 13 6
19 13 8
13 14 4
19 12 18
14 4 1
0 10 4
17 20 9
17 8 14
15 15 1
11 7 16
14 13 15
9 18 18
12 0 5
16 2 4
11 17 17
0 17 8
10 5 4
19 16 6
8 4 7
11 16 13
6 19 20
0 1 20
15 8 2
1 6 12
8 5 17
19 19 7
6 0 9
15 8 8
1 3 12
5 13 10
1 15 10
15 7 6
0 18 9
0 1 17
12 19 10
18 3 4
4 11 10
12 5 1
8 4 16
8 0 19
11 10 20
10 17 9
5 0 15
17 8 17
2 9 12
6 1 8
12 1 15
13 1 2
18 8 7
4 1 19
15 15 20
12 13 20
20 14 7
19 12 10
18 20 16
18 2 19
20 7 8
12 5 10
5 20 14
2 6 9
18 5 19
3 20 8
9 12 8
5 14 18
11 17 3
18 0 4
17 2 0
0 18 16
0 7 12
15 19 14
15 20 3
8 7 14
0 6 18
20 20 11
10 14 12
11 12 0
9 8 18
5 12 8
4 18 3
7 11 9
3 12 0
12 18 0
2 13 15
9 14 19
0 14 20
9 16 10
6 19 19
8 12 20
19 14 4
6 1 1
11 11 2
0 19 3
6 6 9
11 8 4
3 7 8
10 18 14
3 10 11
5 11 17
20 13 9
4 11 11
19 1 10
7 4 10
16 1 14
2 13 1
10 18 15
5 4 7
12 7 20
6 0 5
15 20 7
11 14 15
3 2 20
19 15 20
18 11 6
19 2 7
3 18 5
4 9 4
3 10 8
7 0 10
15 5 12
17 18 9
9 20 16
2 18 18
17 2 11
17 14 8
4 8 8
6 13 15
5 7 8
17 16 0
12 5 18
19 18 15
15 0 7
3 8 9
5 9 11
1 6 8
18 1 14
17 2 19
6 4 0
16 8 17
13 0 9
18 9 11
5 0 1
0 8 18
4 20 7
9 11 14
16 3 20
20 19 12
3 20 14
12 11 12
7 13 18
8 5 20
13 16 1
9 7 18
1 13 8
14 16 13
12 8 8
8 2 8
16 7 14
17 19 12
2 17 18
19 2 18
0 18 8
17 1 11
18 5 11
2 4 13
14 9 14
10 13 8
12 14 2
15 11 10
10 19 15
15 17 9
13 10 12
3 2 7
15 12 12
4 8 4
11 2 20
8 15 18
12 12 17
3 0 5
18 3 3
13 5 15
13 11 16
12 2 5
4 20 0
9 12 7
10 20 6
11 10 6
9 19 9
15 8 19
6 19 2
10 17 12
8 3 12
0 2 20
4 0 0
9 9 5
7 4 4
5 8 12
10 5 9
7 2 5
5 6 10
9 13 4
9 6 19
19 5 2
10 6 10
7 10 15
3 1 4
2 0 9
20 20 8
10 19 14
3 6 16
13 5 20
2 11 11
13 3 10
9 20 0
7 20 2
18 19 20
6 14 18
3 18 9
8 2 4
1 14 17
16 13 12
13 13 2
0 16 18
16 2 13
0 7 20
10 18 4
16 16 1
8 6 7
19 9 16
9 9 18
5 20 20
8 14 1
15 16 1
0 18 19
11 15 15
0 1 15
0 18 10
1 14 7
16 9 12
0 16 17
4 16 2
16 4 9
16 13 19
12 16 20
15 19 16
2 1 19
5 16 13
16 18 9
3 17 15
17 15 12
16 5 6
20 4 1
13 5 19
11 13 20
19 6 18
17 16 7
13 11 15
16 2 1
0 15 14
0 18 7
9 12 9
3 8 13
6 17 16
2 18 7
11 1 14
4 17 10
10 4 4
15 12 5
17 9 2
2 10 9
7 15 18
9 0 16
4 19 15
18 14 5
18 7 16
5 8 10
8 12 6
7 3 19
6 0 4
0 11 2
11 20 14
16 19 5
15 3 19
0 8 6
7 17 11
20 13 15
13 16 14
13 6 2
14 10 20
1 4 8
8 14 3
16 1 0
5 3 19
4 10 19
13 1 15
16 16 2
9 17 3
12 12 8
5 12 12
19 8 16
8 8 0
4 0 19
5 13 2
19 12 2
9 17 2
20 16 4
18 3 12
20 0 9
3 9 8
15 14 6
3 13 16
6 13 10
11 10 4
0 11 15
13 18 4
6 6 15
6 14 16
6 10 12
10 6 14
9 8 20
0 19 10
7 18 5
2 15 6
11 6 2
10 3 11
3 11 3
0 7 19
16 4 2
3 1 16
2 0 15
12 0 6
4 4 4
18 16 9
20 2 8
12 0 19
3 6 8
10 8 15
4 19 17
10 15 1
3 16 1
16 12 2
6 2 10
11 3 12
11 4 13
8 3 17
19 4 4
15 2 14
10 12 18
0 3 1
16 20 3
0 11 20
16 20 13
12 1 18
6 10 3
2 2 13
18 14 19
4 19 7
20 15 1
16 0 3
5 3 4
15 3 20
6 7 7
0 17 9
18 6 11
4 14 0
6 13 6
18 9 4
8 18 15
0 5 0
6 11 17
9 6 17
8 12 5
5 5 8
16 17 0
3 7 13
2 7 7
16 9 7
8 12 12
11 14 7
15 5 9
14 12 10
4 1 16
7 11 12
10 2 0
18 0 10
4 9 17
13 10 3
16 15 2
1 8 16
5 0 8
10 19 7
13 15 12
17 15 9
16 3 0
13 10 18
11 20 5
9 14 18
7 8 13
6 13 2
16 11 0
3 7 18
14 0 16
1 16 9
6 3 20
7 10 6
20 15 20
20 20 20
19 11 3
2 1 0
5 17 7
11 4 8
1 13 14
19 11 15
0 0 6
0 13 20
3 15 18
9 9 6
9 18 20
13 14 14
10 5 13
14 4 9
14 8 20
16 7 15
6 5 20
13 10 19
20 6 10
0 10 2
19 9 7
6 2 1
1 4 0
20 18 7
1 17 4
14 1 4
9 15 6
20 3 15
2 6 5
12 13 8
10 7 5
5 2 8
3 5 20
14 12 6
6 20 3
18 13 3
6 7 12
2 19 0
6 4 9
2 16 14
5 5 9
18 15 16
14 20 20
20 17 2
6 11 10
2 3 1
6 14 20
3 11 14
17 8 11
19 6 16
0 19 5
7 7 5
19 11 2
4 7 4
18 10 1
13 17 7
9 6 11
15 1 2
2 10 7
8 16 5
3 16 15
16 8 7
1 13 5
14 19 2
1 20 17
4 11 4
13 7 10
12 20 6
13 16 4
13 13 18
3 2 4
11 10 5
5 3 9
17 10 8
0 0 9
15 8 15
12 14 3
20 10 15
11 13 16
1 0 3
13 0 4
19 6 4
0 17 19
13 7 13
11 16 8
14 18 16
11 14 11
19 9 13
4 4 11
3 10 10
4 5 12
17 18 2
17 0 4
10 5 20
13 10 11
7 12 10
18 19 12
2 0 10
2 20 2
1 14 11
18 0 9
11 17 20
5 12 3
7 17 9
18 13 2
5 14 9
0 12 3
6 16 1
1 5 16
20 15 15
15 7 14
5 11 4
6 20 20
6 5 14
14 11 10
4 17 0
18 3 9
9 6 6
15 16 5
10 1 13
0 4 0
20 10 4
3 19 15
5 19 5
5 5 11
6 11 2
3 10 17
19 4 16
5 11 1
14 15 4
14 11 13
7 11 5
12 13 18
20 16 17
0 6 6
15 4 19
2 8 19
10 14 20
19 6 12
10 8 10
19 2 14
2 17 4
4 17 1
15 4 3
18 12 15
16 6 2
2 12 3
18 12 5
17 19 11
13 17 15
0 3 0
18 5 13
20 13 5
17 10 2
2 16 13
11 3 17
11 6 6
10 13 0
13 2 19
15 18 12
4 7 14
14 20 13
7 3 5
8 0 4
3 13 8
10 1 11
13 14 2
4 14 9
16 19 19
17 10 6
16 17 3
1 13 4
19 1 12
9 6 7
1 2 13
8 19 1
16 1 1
17 3 3
0 6 17
17 15 20
14 1 9
10 17 4
6 9 16
9 9 2
7 4 17
13 18 2
4 20 6
15 19 15
2 8 1
15 4 14
19 3 13
6 2 5
8 3 4
0 2 3
6 12 3
18 15 14
2 17 12
18 18 12
9 14 1
11 8 14
13 9 10
2 16 17
12 20 8
12 9 15
13 20 0
8 18 3
6 4 15
8 12 13
20 11 20
4 3 11
5 19 19
20 10 9
18 15 17
9 5 20
9 13 9
13 11 10
14 0 11
10 7 19
7 9 1
3 16 16
6 11 0
8 14 12
11 2 7
5 9 1
15 0 14
12 6 16
19 0 15
1 3 3
13 20 11
12 12 19
15 13 12
14 11 3
6 2 4
20 15 9
3 14 0
19 17 19
19 11 1
10 2 20
1 9 17
1 6 2
15 15 8
19 17 20
19 1 20
15 20 14
14 9 19
0 9 10
18 6 13
9 8 19
15 5 13
7 19 4
9 7 15
17 10 0
16 0 16
12 13 17
20 2 9
8 0 6
6 9 3
2 16 9
13 8 13
0 9 6
2 12 13
17 16 4
10 0 16
1 3 16
19 18 8
4 8 6
5 18 10
5 10 4
15 14 14
3 12 5
11 15 3
0 5 17
3 10 20
16 8 10
16 13 6
6 18 12
9 0 18
13 12 0
6 20 15
11 19 3
2 18 1
12 8 19
8 4 10
1 15 19
1 5 17
16 13 4
19 1 15
20 3 4
9 2 7
9 0 11
8 3 1
7 20 1
11 13 12
20 8 6
11 0 9
4 8 11
13 19 2
1 11 11
2 5 9
20 12 14
0 15 13
19 2 9
9 5 19
2 20 10
14 4 3
20 0 0
8 15 7
3 20 4
7 3 0
8 16 2
10 0 8
13 17 17
7 17 5
14 1 1
5 2 15
14 5 7
16 6 3
6 15 11
13 14 9
20 9 0
5 16 20
4 13 7
1 10 12
13 16 5
1 2 5
11 15 13
12 8 4
16 9 13
6 13 9
9 2 15
6 5 18
0 17 14
2 10 8
17 20 1
10 13 3
16 19 3
0 7 17
8 3 5
3 2 16
5 5 19
0 6 16
1 2 4
15 15 16
4 11 12
4 15 2
20 20 4
15 9 19
16 6 9
18 10 13
12 11 18
17 15 0
2 8 2
4 18 19
17 7 15
15 3 0
8 11 9
6 12 11
9 20 11
17 4 17
17 19 16
7 11 1
12 15 10
11 5 14
3 13 5
2 17 8
16 4 5
18 20 9
0 13 0
10 0 4
6 14 8
0 12 12
12 12 14
13 4 2
4 15 15
13 20 10
2 12 2
19 6 8
11 19 0
4 0 16
19 3 9
20 7 18
7 17 14
13 19 19
4 18 11
2 15 19
9 20 14
8 7 16
3 11 5
18 10 5
1 20 15
3 18 7
12 7 15
16 17 7
6 8 19
3 14 20
10 11 17
15 9 12
10 12 2
20 16 9
19 12 16
3 9 0
11 5 2
2 6 8
20 7 17
14 6 4
2 10 13
10 11 20
15 13 2
1 1 0
11 19 12
2 9 19
11 0 8
11 16 11
17 4 15
19 16 12
0 0 19
17 5 7
20 10 6
14 5 15
8 16 13
0 4 7
0 10 16
16 7 9
12 16 7
6 7 16
17 16 17
11 13 14
7 15 6
13 4 8
11 0 6
7 12 14
19 16 20
18 0 13
6 7 9
15 12 20
14 7 2
16 6 13
6 9 9
0 13 3
18 11 13
20 18 19
8 17 5
3 12 12
12 10 20
17 20 20
9 3 17
15 6 7
19 0 11
9 1 14
15 9 6
10 16 3
1 4 10
3 9 20
17 4 4
9 17 15
20 6 4
12 4 19
5 7 11
5 18 20
15 12 16
3 0 12
8 15 17
4 16 0
6 19 6
12 13 7
14 18 15
20 9 11
17 1 13
8 13 19
17 18 10
10 3 13
18 7 1
19 1 19
1 8 3
18 0 1
9 12 15
8 11 17
18 18 11
14 7 3
0 4 3
11 6 13
14 3 13
5 13 20
17 3 8
0 14 17
12 12 11
16 16 3
5 10 20
0 1 4
9 1 10
12 7 8
4 15 0
6 17 8
10 5 3
19 9 5
17 5 19
16 11 19
10 1 1
6 11 14
19 9 18
13 10 7
8 8 11
3 2 9
2 2 20
15 1 4
17 13 0
0 18 12
0 17 18
1 17 8
9 5 1
8 12 14
8 11 16
8 11 6
0 8 4
12 3 2
2 7 6
19 3 1
0 13 18
19 16 1
17 20 2
3 5 16
3 18 8
20 11 3
5 3 15
6 0 6
17 19 4
4 14 19
15 7 0
4 10 17
17 4 3
1 8 14
16 7 16
16 12 15
6 3 4
4 3 14
20 14 2
9 13 13
18 7 13
5 11 20
4 17 15
12 20 0
7 19 1
14 19 15
19 14 12
9 17 17
18 15 12
5 18 11
2 19 4
9 7 5
10 1 2
9 19 17
5 7 2
13 7 17
17 6 0
9 14 11
6 4 10
14 20 14
19 3 16
6 4 1
7 0 7
18 2 13
10 18 8
20 1 3
13 12 17
5 12 17
6 2 13
2 19 19
5 17 6
7 19 9
14 2 15
4 16 20
1 3 14
10 18 13
19 18 18
9 15 5
2 15 7
14 13 6
14 5 11
13 6 9
11 3 2
14 8 8
12 3 20
3 18 18
5 20 5
16 1 6
11 13 4
6 12 16
0 10 0
9 20 18
14 16 10
19 13 9
1 16 6
17 11 19
8 4 2
20 12 7
19 5 1
19 11 0
2 6 3
2 12 8
10 11 8
20 15 2
10 6 2
9 6 8
13 7 6
15 13 8
3 11 2
3 5 1
2 1 5
19 2 12
12 0 16
18 6 16
11 5 13
13 5 10
17 12 7
18 18 6
5 16 8
20 16 11
9 8 12
8 13 0
9 10 6
16 16 0
8 1 12
5 15 17
10 15 12
13 13 11
11 20 9
14 0 19
1 12 6
2 8 14
10 4 9
7 2 12
10 3 3
18 17 18
2 16 1
3 6 2
4 11 3
17 9 9
0 15 11
4 18 20
8 10 18
6 13 16
10 16 7
18 7 7
9 10 8
20 1 19
2 13 13
6 1 19
13 10 8
12 9 19
5 11 18
9 2 18
15 6 3
11 9 14
13 2 3
8 16 9
7 14 0
16 6 5
3 5 8
20 1 9
13 10 14
4 16 7
20 11 19
7 16 18
13 15 6
12 11 17
11 3 1
0 10 12
8 9 18
8 9 14
19 17 16
0 1 13
7 11 10
16 15 3
12 2 2
15 17 11
9 10 17
9 18 11
18 9 19
2 15 14
3 1 20
5 2 5
19 7 7
9 2 6
19 14 15
11 11 5
0 0 15
19 13 11
18 11 16
5 8 14
10 19 9
19 8 0
3 11 20
11 18 7
15 15 13
13 7 18
0 20 13
15 15 11
18 7 11
2 0 13
5 16 10
18 16 12
14 11 14
0 5 13
9 20 4
20 8 3
11 10 18
6 4 12
5 5 3
17 12 5
19 8 9
6 4 18
10 20 20
3 6 7
20 15 19
1 1 5
17 20 8
20 5 0
12 6 6
9 1 12
6 9 14
12 11 0
12 3 0
12 12 1
12 3 11
7 15 10
4 1 12
15 13 0
6 10 1
10 4 2
3 18 6
12 16 1
15 4 18
3 4 14
6 12 1
18 13 18
6 18 2
3 1 19
16 14 13
6 16 15
18 10 11
6 20 16
16 11 8
11 9 8
3 5 3
11 7 5
4 7 1
12 4 9
12 18 11
16 8 0
10 11 18
18 20 10
11 7 6
4 9 20
7 3 2
0 14 0
14 13 10
20 3 14
8 13 12
20 17 4
5 4 1
3 17 13
12 11 19
3 17 7
15 6 11
20 4 17
6 18 11
10 16 9
1 15 17
9 5 16
3 20 15
11 14 0
11 5 5
19 20 14
19 14 10
4 15 19
18 13 15
7 4 15
14 14 11
3 10 2
2 11 6
7 18 12
6 15 16
1 0 18
9 15 4
13 7 2
4 5 9
11 11 19
5 12 14
7 5 16
9 13 18
9 0 4
10 3 18
11 3 19
12 1 4
16 1 20
2 19 6
13 5 7
1 12 1
14 6 13
8 11 0
3 12 20
19 20 17
2 11 1
7 9 17
11 5 19
17 4 6
3 16 17
7 6 6
9 13 0
4 1 9
7 2 6
17 6 1
15 8 1
7 17 17
18 10 7
0 11 9
4 2 4
17 14 17
1 19 8
19 7 10
6 8 3
7 1 6
8 0 12
18 10 8
14 15 12
5 12 15
8 13 10
7 17 3
20 0 16
20 15 3
15 7 18
0 14 15
10 1 5
15 20 11
3 0 20
8 19 0
19 13 6
15 5 20
6 6 0
19 18 6
1 5 13
15 4 15
20 4 16
19 10 19
9 19 11
16 0 5
3 2 18
16 4 15
16 9 14
2 4 20
9 8 15
8 7 20
15 0 15
18 9 6
15 12 2
9 13 6
16 5 12
19 0 1
6 1 6
8 17 0
8 8 8
20 8 2
19 14 11
13 7 9
18 18 14
4 15 20
20 2 16
20 12 2
5 15 3
5 13 7
8 2 11
19 15 1
4 18 16
11 6 1
4 1 17
11 1 7
13 16 9
11 17 0
8 19 12
2 18 15
10 19 6
17 8 18
2 12 19
0 4 10
12 15 12
2 13 18
0 13 17
9 9 20
8 3 3
1 17 7
18 9 1
1 6 14
6 2 11
15 4 10
20 14 18
3 17 2
1 4 15
12 13 10
6 13 0
5 4 2
10 7 9
10 10 0
19 1 4
13 15 9
3 7 19
13 5 17
8 14 6
1 9 16
6 2 17
19 4 13
20 8 5
7 19 2
11 2 16
9 11 9
0 12 0
4 8 2
7 11 11
3 13 11
5 6 1
8 16 19
10 0 19
17 0 6
19 5 19
12 18 5
18 5 10
6 6 5
0 17 0
1 0 15
18 4 17
6 15 10
5 1 9
6 14 6
15 12 15
6 9 4
6 18 5
1 14 16
8 5 15
14 9 9
17 10 18
17 11 18
8 2 5
17 18 5
9 17 19
10 13 7
4 6 1
0 17 11
19 6 0
12 10 13
20 11 15
16 9 1
12 7 9
10 10 15
18 12 10
4 10 16
11 13 13
9 11 18
8 16 16
0 19 6
20 11 16
9 17 20
5 10 0
16 10 17
7 0 20
0 18 3
16 3 16
3 6 11
14 3 1
10 6 6
20 12 10
14 11 15
18 2 12
14 4 0
3 7 15
7 1 11
14 6 1
9 7 14
2 18 20
5 0 20
15 0 4
10 17 15
8 6 2
14 4 4
19 19 6
7 5 1
10 5 1
6 12 12
2 2 2
6 7 0
6 4 3
15 3 7
0 11 13
9 14 6
20 13 1
9 13 19
9 6 1
19 13 1
10 9 17
8 3 20
10 10 3
18 18 9
2 17 13
4 6 11
4 3 13
4 4 5
20 9 12
3 20 13
13 13 0
11 1 12
4 2 17
12 15 8
7 19 8
7 3 4
10 7 14
2 18 14
20 17 1
8 16 10
11 17 16
1 11 16
13 12 16
20 7 15
17 1 5
17 2 6
2 14 12
3 18 4
10 15 18
12 2 3
11 2 13
11 7 2
17 6 12
13 0 8
10 9 8
1 1 19
7 16 4
20 15 5
16 0 13
7 16 8
1 20 1
10 14 1
2 8 7
9 8 10
20 19 2
1 9 15
2 20 6
12 3 4
1 3 2
4 4 13
11 12 19
6 7 18
9 14 13
19 20 9
20 13 12
3 15 9
10 6 9
9 17 18
18 12 9
15 1 1
12 14 13
5 3 16
1 3 17
1 9 11
7 0 0
17 9 20
20 17 20
7 15 8
9 11 1
6 9 11
15 20 4
19 9 9
11 3 20
15 7 9
18 6 1
4 7 13
14 2 12
4 20 18
10 7 1
18 17 17
17 10 14
14 4 15
5 1 17
17 20 13
7 13 9
17 2 14
2 13 4
7 2 4
13 13 13
1 19 14
8 15 0
4 18 4
4 9 10
1 20 16
0 2 15
12 7 1
6 14 11
4 11 14
15 3 4
3 13 20
1 18 15
18 2 5
6 8 2
9 11 19
19 8 11
16 18 10
17 15 19
1 11 2
7 9 3
1 0 16
7 7 11
2 18 13
6 14 0
6 10 8
4 1 0
0 16 20
0 10 6
17 4 11
17 6 4
10 9 9
12 0 9
7 5 14
12 4 2
15 8 4
0 15 20
0 3 13
16 8 4
0 13 19
12 1 6
12 6 17
9 6 3
13 7 1
13 16 15
17 20 16
7 16 3
19 0 8
19 7 15
7 6 15
10 4 5
12 5 11
4 8 0
5 14 3
10 3 14
5 13 12
17 13 7
8 3 18
16 14 18
17 17 7
18 8 19
20 16 10
5 11 16
15 17 0
14 12 2
13 13 12
17 18 7
6 10 13
17 7 20
9 18 6
3 3 8
0 20 0
14 16 0
15 10 6
3 8 15
10 19 13
15 0 10
0 3 12
14 18 9
11 16 1
15 11 16
3 7 11
19 5 14
2 9 16
10 18 9
4 5 18
16 2 10
1 6 18
9 3 3
7 20 17
20 9 8
13 10 17
0 5 18
9 20 5
9 15 12
11 12 9
7 10 13
1 11 0
2 1 4
6 11 7
15 12 11
1 16 1
8 4 12
20 4 12
1 6 11
5 2 10
6 7 5
7 4 9
12 11 11
11 11 14
17 4 1
3 16 8
9 15 19
18 10 0
0 19 2
2 11 7
19 7 2
14 11 9
8 5 9
17 16 3
2 13 20
14 10 4
5 1 13
9 8 9
2 11 9
5 20 1
3 20 19
14 9 13
7 18 20
9 7 11
19 13 0
2 14 20
10 8 19
15 6 2
11 2 3
1 7 7
2 8 11
7 1 13
7 7 8
5 12 0
17 19 1
18 10 10
9 18 9
5 12 9
3 11 6
18 12 6
12 10 5
18 7 2
8 3 8
7 20 0
18 18 17
6 18 15
13 6 11
7 15 5
11 10 19
5 0 4
1 18 2
11 8 5
4 2 13
13 0 2
8 7 4
17 13 9
3 7 4
3 2 11
19 14 0
13 10 13
16 4 6
9 2 3
17 20 11
4 18 1
10 8 4
14 5 2
5 15 15
2 20 16
14 6 18
18 16 7
13 5 0
14 1 6
7 1 8
14 12 15
9 10 20
3 19 16
7 1 1
6 20 4
16 15 17
15 10 18
14 14 18
1 6 17
4 4 3
18 4 1
2 3 19
9 12 12
10 14 18
19 19 9
13 4 9
16 8 1
5 19 16
14 14 5
10 18 10
13 8 12
2 4 4
12 3 17
5 7 17
4 18 18
3 19 10
16 20 4
6 17 20
11 19 6
5 10 6
8 11 2
8 20 9
3 8 4
19 12 9
18 13 4
8 9 16
7 6 5
3 1 15
13 7 15
6 3 18
11 15 1
17 14 10
20 19 18
12 1 17
16 1 7
0 0 13
3 12 8
1 12 14
14 6 19
16 15 16
17 17 0
6 11 3
19 12 14
1 8 7
15 6 4
6 9 17
8 16 15
14 17 6
4 4 20
8 9 15
4 1 8
18 1 3
0 14 11
4 7 17
16 8 11
15 9 2
20 11 9
9 8 0
19 1 1
19 2 3
5 6 11
18 1 7
2 8 17
14 4 6
17 12 17
20 12 18
15 3 3
4 12 1
1 11 4
0 11 18
12 16 5
12 17 9
1 11 19
11 9 4
1 10 20
5 5 1
4 16 1
20 8 1
10 3 20
6 5 13
14 1 3
13 4 5
10 16 17
14 8 4
8 4 17
9 5 13
16 19 4
17 18 15
17 3 0
11 13 18
8 12 19
14 16 5
11 7 19
14 13 11
3 14 6
13 14 3
6 0 3
3 16 5
18 3 5
6 14 15
15 9 20
18 6 2
5 20 6
8 2 0
19 17 11
3 20 2
3 5 4
13 17 19
9 5 9
3 17 0
16 18 8
8 8 15
10 15 19
6 20 18
8 6 16
18 17 13
15 13 20
4 5 20
13 11 12
12 18 7
4 9 9
9 18 8
8 11 11
11 3 4
13 18 8
14 6 9
5 14 10
17 17 9
18 15 2
15 3 2
6 14 12
2 8 0
4 17 18
5 15 14
0 0 16
2 1 13
9 10 16
13 5 16
4 6 12
17 3 20
5 0 2
7 2 15
14 1 20
1 5 10
2 10 4
18 17 2
17 9 17
10 16 2
12 19 15
20 11 11
20 9 6
1 17 13
11 6 8
17 17 17
1 8 8
5 0 17
15 1 16
15 0 19
14 10 14
11 7 17
15 10 15
0 10 15
20 10 8
4 19 4
3 0 1
9 20 9
7 3 1
18 15 13
7 0 9
20 3 18
2 12 1
19 13 20
6 16 13
14 2 13
2 5 13
7 16 6
12 4 1
18 8 18
14 0 20
19 16 14
14 14 8
5 5 14
9 9 14
19 6 10
12 7 18
7 14 12
1 5 2
0 17 7
4 14 6
9 0 3
8 16 3
0 11 10
8 1 4
10 4 10
18 11 18
1 14 2
19 5 15
5 18 9
5 14 19
20 18 14
12 18 2
16 1 2
2 2 1
17 11 17
0 12 10
18 9 8
12 17 7
3 13 9
14 18 19
7 16 20
4 8 7
9 16 6
11 17 4
8 18 18
2 5 11
10 1 9
14 20 1
5 9 17
18 15 6
15 17 13
6 7 1
9 10 14
0 7 1
15 11 2
17 1 10
7 2 8
7 5 9
16 7 5
12 12 16
14 15 0
12 17 17
14 4 19
12 15 9
6 4 7
6 8 12
8 4 1
19 10 8
4 14 7
12 19 20
3 8 14
17 0 9
20 6 3
13 11 1
1 4 1
16 14 4
20 2 3
6 16 20
12 9 7
18 1 6
5 10 13
3 12 6
2 14 0
17 17 4
1 15 16
11 20 8
2 18 11
20 19 15
17 10 11
14 5 14
3 0 17
1 13 19
0 5 1
3 9 16
12 16 14
20 7 14
20 8 8
15 13 5
7 7 6
1 6 1
8 1 3
16 8 16
10 14 13
18 12 2
10 18 16
2 7 9
19 1 16
13 8 4
10 2 17
5 8 5
11 6 11
15 4 12
4 0 2
12 2 13
6 7 11
5 0 13
11 15 12
6 14 3
1 8 12
11 17 1
5 20 17
2 11 5
15 5 3
7 20 3
11 13 19
16 12 16
6 0 15
5 10 9
4 20 11
20 6 16
17 16 13
20 15 12
5 2 1
2 1 17
20 10 11
14 4 18
5 20 4
5 12 7
0 8 10
12 19 17
16 2 18
13 10 16
15 8 12
12 17 0
10 0 20
14 17 20
20 2 14
3 7 6
0 8 1
8 5 4
9 5 3
0 13 12
6 5 11
8 7 7
2 4 19
18 0 11
18 12 14
18 4 8
10 20 19
2 15 17
7 12 4
10 18 18
14 12 5
10 9 13
16 10 14
20 15 11
13 12 14
5 2 14
3 9 10
5 13 13
20 2 18
5 3 8
19 11 14
4 15 4
14 7 11
0 13 16
14 20 6
15 1 6
17 9 11
3 12 14
4 1 4
0 7 13
16 6 12
1 20 7
16 17 18
12 20 14
8 2 15
5 13 11
4 3 2
9 16 13
3 6 15
7 12 20
8 10 6
0 2 11
10 7 20
2 5 18
9 20 3
7 18 7
10 0 1
4 6 19
2 5 6
0 19 12
11 9 10
10 7 8
0 14 10
5 17 8
13 3 6
5 0 7
0 12 13
4 5 16
7 1 4
1 20 13
9 20 19
18 6 6
14 20 18
12 11 1
18 11 5
16 7 6
18 20 0
4 5 17
17 12 2
5 16 17
12 15 4
20 15 4
8 2 3
11 11 0
16 19 2
18 16 0
20 4 14
11 9 16
18 4 19
4 13 2
9 18 3
13 14 15
2 17 1
14 15 16
12 5 14
18 17 1
18 5 2
6 12 7
14 10 12
17 8 19
4 12 13
12 5 20
0 17 10
14 19 12
4 7 11
9 1 3
19 4 10
16 19 9
2 3 3
17 9 14
3 14 17
4 18 6
4 13 3
14 10 11
3 8 18
10 13 14
0 1 14
3 3 10
19 1 8
8 2 2
13 14 7
15 16 16
3 13 14
8 17 20
17 17 10
4 19 3
12 4 20
10 5 11
17 9 19
6 5 9
5 16 6
2 20 19
3 13 12
6 0 12
14 5 6
11 7 15
4 4 8
13 8 6
11 8 17
6 14 1
15 13 14
11 15 16
18 12 12
20 5 2
10 15 6
19 0 13
6 20 17
11 9 11
8 20 2
19 11 8
18 11 7
13 3 3
7 1 15
3 18 0
17 20 3
20 12 16
12 19 7
8 18 11
1 2 18
7 4 16
2 19 20
12 0 4
1 12 17
17 6 8
4 17 19
9 6 20
16 14 10
6 20 14
17 11 20
8 1 0
8 6 5
1 10 18
2 14 2
5 16 12
1 16 12
2 14 18
8 13 18
19 13 3
7 10 2
14 14 6
1 7 4
6 9 5
7 17 6
20 12 0
9 12 1
15 3 1
Out #2:
15
2
9
0
11
8
1
18
12
11
12
16
7
16
12
5
0
3
5
3
8
0
7
4
16
7
1
16
4
1
10
19
4
3
19
9
0
4
4
1
15
15
0
4
1
2
1
0
3
8
13
3
1
4
20
20
10
11
8
1
6
14
4
4
2
1
15
0
0
20
1
19
10
8
3
17
16
10
10
6
2
17
0
4
14
0
9
8
14
2
18
0
0
7
2
9
15
13
3
0
15
0
0
16
13
3
6
13
18
3
13
11
3
5
20
14
17
0
13
19
12
15
6
2
15
0
11
14
4
0
13
13
8
0
5
2
11
0
18
13
19
9
6
3
5
17
18
0
8
3
18
4
7
10
9
12
0
0
18
12
3
4
20
19
7
13
0
18
1
20
16
0
4
12
2
1
6
11
19
10
5
18
0
10
8
0
9
5
11
6
17
8
0
10
3
0
4
18
6
8
19
5
3
15
16
18
17
14
8
20
1
14
16
5
4
0
18
18
0
17
1
9
3
1
13
11
19
6
5
0
19
16
0
10
14
7
13
11
0
11
0
4
17
6
9
10
12
6
15
15
9
13
7
3
16
16
14
2
0
4
8
0
9
9
19
14
1
10
8
13
4
17
5
19
8
12
14
1
16
6
1
9
19
18
5
16
12
6
13
16
8
2
0
2
0
18
13
7
20
4
18
19
13
16
6
18
14
0
0
2
7
5
0
2
0
1
2
3
12
13
7
0
11
8
19
7
18
13
8
14
2
0
1
12
20
14
17
11
16
0
10
19
13
9
17
5
18
14
2
12
6
11
16
14
5
7
0
2
9
3
15
20
9
14
10
18
12
0
9
17
2
13
1
8
15
20
5
12
1
5
0
11
9
0
4
13
13
0
9
4
15
5
0
0
9
16
19
20
3
15
8
1
1
20
0
8
2
14
16
2
0
20
12
12
16
1
14
4
1
11
15
3
0
0
10
17
0
6
0
18
0
9
0
0
20
18
20
8
12
15
8
7
9
15
5
0
17
1
18
2
0
9
12
14
6
13
16
15
20
7
12
4
5
0
1
16
5
18
7
9
0
6
9
0
14
14
16
11
17
6
15
17
5
6
6
1
1
8
20
19
2
6
3
14
2
2
7
0
0
11
8
14
11
20
1
1
0
14
0
15
6
18
15
4
14
20
0
7
11
20
13
7
8
16
1
18
5
12
13
4
15
0
0
11
9
20
5
18
0
1
9
9
11
20
18
9
16
11
14
15
12
17
18
5
0
2
5
5
16
11
5
18
18
16
10
12
0
0
5
11
6
9
8
9
0
0
3
8
18
3
13
7
2
5
8
2
0
11
9
20
18
0
2
17
0
10
20
14
11
0
0
6
8
1
0
17
18
19
17
14
9
15
19
0
7
4
18
20
12
6
4
17
0
0
19
6
10
2
7
11
1
1
17
12
13
17
7
2
13
6
5
0
16
4
2
0
6
9
18
17
3
8
0
1
2
6
8
3
2
0
0
18
6
17
5
2
0
20
12
9
8
18
13
9
5
2
16
6
18
8
2
12
12
18
9
7
0
17
14
2
17
8
14
3
12
16
16
17
0
0
7
0
7
2
5
11
11
3
14
0
0
17
13
14
19
17
16
0
1
20
3
2
9
0
14
16
5
0
12
19
6
0
11
11
9
9
10
10
7
18
2
11
0
10
15
18
15
10
8
18
15
10
14
8
17
4
13
0
20
5
13
12
0
18
2
12
2
13
6
0
0
7
13
18
13
3
17
15
7
0
0
2
7
8
6
8
18
7
2
5
2
14
0
5
4
3
18
12
15
8
2
8
12
18
17
6
5
0
8
0
15
9
18
18
6
8
16
17
1
13
11
1
0
9
13
19
7
5
13
11
0
18
1
11
1
3
18
16
2
1
11
8
13
1
7
16
15
4
0
5
7
18
16
13
10
7
12
5
18
2
17
16
14
16
13
9
5
0
13
19
14
0
4
9
0
13
1
5
0
0
15
13
8
1
14
18
20
10
16
6
6
4
0
14
17
13
15
5
2
10
4
13
7
17
18
20
16
5
1
5
0
0
0
2
0
12
14
10
7
17
17
7
12
12
4
5
0
20
14
0
12
11
1
13
18
10
2
0
6
16
8
3
9
7
15
11
2
15
4
0
2
17
0
4
12
5
5
11
11
10
13
7
10
15
19
15
5
12
14
19
19
3
10
6
6
11
3
14
1
2
14
16
19
3
8
12
8
10
14
8
8
17
12
9
5
0
9
5
15
14
2
0
0
13
0
15
17
8
15
4
13
1
7
14
8
10
10
16
0
15
6
0
18
0
7
3
0
3
12
13
16
6
0
16
11
14
0
0
2
9
6
8
7
4
0
5
13
13
4
3
11
7
2
0
0
5
6
5
5
18
18
0
15
7
3
15
15
20
6
3
2
5
7
6
0
11
5
0
18
17
5
12
14
0
16
18
8
0
19
9
19
4
0
19
15
6
0
6
11
0
5
11
4
15
13
4
20
7
18
14
6
7
13
6
9
5
7
19
0
19
6
8
13
4
5
1
12
14
10
10
1
5
11
14
2
2
3
13
7
7
2
10
7
8
9
15
16
12
1
17
20
14
3
11
19
18
7
8
11
16
14
12
8
0
2
8
1
1
20
18
0
9
7
11
6
9
0
14
11
3
19
19
11
14
19
15
20
18
12
13
0
17
1
12
15
2
16
0
20
5
17
18
15
11
18
20
1
13
18
0
10
7
11
10
0
1
18
18
7
15
16
13
12
4
0
8
4
7
16
1
17
17
9
1
11
16
11
17
17
12
6
4
4
1
1
16
14
10
1
19
0
17
15
7
15
11
4
17
1
11
6
9
20
15
12
0
18
2
2
8
5
13
2
5
18
4
14
7
4
10
5
3
15
4
14
14
0
6
6
7
12
0
0
2
12
0
17
9
2
13
1
8
9
7
7
15
16
14
15
3
2
11
9
8
14
12
9
7
7
18
17
0
1
11
14
1
18
19
16
4
1
1
5
13
14
20
7
3
9
3
12
17
17
6
13
0
9
9
0
13
8
8
15
12
4
15
6
11
1
11
8
6
13
4
3
0
10
14
1
8
0
7
11
6
0
20
13
6
9
3
15
4
16
10
15
6
4
16
3
0
0
2
14
4
2
0
16
13
10
8
4
0
17
9
15
12
1
14
0
9
15
20
14
14
8
10
16
0
17
20
0
1
3
0
2
3
11
11
7
18
0
0
7
10
3
0
6
13
2
6
6
0
20
0
5
17
3
1
2
11
3
2
0
5
16
9
12
8
10
18
0
3
0
4
14
5
10
10
0
2
6
4
1
0
11
6
13
7
17
1
0
1
16
10
18
1
20
17
18
5
12
16
9
9
0
0
19
2
7
19
0
20
14
19
7
8
1
8
16
13
5
12
7
9
16
15
14
16
8
14
20
14
15
9
11
12
0
13
16
20
17
16
13
11
18
0
14
4
12
13
12
6
20
12
13
0
7
14
15
1
11
10
5
13
12
15
8
2
14
17
11
0
16
6
7
15
11
1
17
10
10
17
14
4
0
12
15
12
0
19
7
8
14
12
0
11
9
6
19
14
1
18
0
11
8
1
11
1
4
11
14
3
8
5
16
11
5
20
10
7
16
0
6
14
7
16
0
16
8
20
2
17
16
11
15
14
7
10
9
12
10
10
4
16
18
4
9
8
0
10
12
19
13
19
16
5
4
8
2
3
2
18
8
3
0
1
5
12
16
12
9
14
0
4
19
4
6
7
11
11
17
0
0
11
19
1
0
20
8
0
7
19
0
1
0
16
7
0
17
3
0
20
9
16
3
6
9
0
19
4
9
9
15
6
0
10
15
16
1
18
9
6
5
12
16
5
0
9
0
0
14
10
5
14
0
9
13
3
19
15
20
0
0
11
9
17
9
20
19
15
6
10
17
19
7
0
0
8
1
16
0
19
4
0
20
8
5
2
9
15
15
2
3
11
2
18
5
20
0
5
0
11
7
16
16
18
6
7
10
3
3
11
19
20
0
7
6
7
3
15
4
20
0
19
4
13
0
17
12
12
11
3
11
0
20
12
14
1
16
14
0
0
19
4
18
18
2
0
0
11
0
5
16
2
16
7
15
1
4
9
13
20
17
13
12
5
0
18
4
20
1
19
3
16
16
11
11
5
10
11
14
0
18
10
19
9
11
17
10
16
16
13
1
12
0
0
9
9
2
16
3
0
2
19
12
12
7
17
7
18
16
11
13
6
14
9
16
17
0
5
10
10
17
0
0
19
17
4
19
0
10
14
5
3
6
12
0
19
12
3
12
0
20
10
8
20
4
0
0
5
2
19
12
11
13
0
18
19
16
5
13
0
0
0
15
0
0
9
8
1
13
16
4
16
7
9
0
15
13
12
12
17
9
5
0
14
10
6
4
16
20
0
8
8
17
19
5
15
13
1
6
2
0
17
9
5
13
11
17
13
18
15
8
4
4
4
13
2
16
19
5
18
14
19
3
20
4
0
4
15
18
9
20
13
20
11
14
14
0
0
20
8
2
6
1
5
1
1
1
11
7
7
16
17
7
4
14
19
19
1
11
0
12
20
3
1
10
11
0
0
7
14
5
12
13
2
0
6
15
7
20
6
14
16
4
18
20
2
19
0
5
11
5
15
9
0
8
20
14
19
1
0
17
15
17
15
16
7
9
12
1
0
1
6
0
10
5
19
17
11
14
12
17
3
5
0
11
13
14
0
11
11
5
5
1
1
13
3
12
3
11
0
20
15
19
0
3
20
4
2
0
14
13
19
12
7
11
7
0
10
15
9
13
4
10
4
8
0
16
2
12
19
11
12
12
5
6
0
17
6
18
10
13
10
14
7
10
7
19
5
0
17
0
20
11
17
11
17
6
2
17
4
4
10
3
3
10
7
1
8
4
10
9
11
19
10
12
10
8
20
4
8
14
8
19
4
2
11
0
12
7
5
16
4
0
19
0
5
18
15
13
9
11
6
11
7
18
10
4
12
7
17
10
10
13
5
3
0
17
9
18
15
0
2
9
0
16
19
17
17
17
16
16
1
0
18
14
10
0
9
3
1
7
2
9
2
12
0
14
4
3
9
19
8
13
19
11
4
14
13
9
3
4
14
0
17
0
6
3
0
0
17
17
3
9
4
0
10
6
1
8
0
15
3
9
15
11
14
9
19
19
19
7
8
4
6
17
4
14
5
12
12
20
1
2
0
2
0
17
10
0
9
14
5
15
5
10
18
6
5
5
1
0
0
13
8
0
9
19
12
13
20
1
18
5
13
0
17
15
9
7
15
0
3
14
17
6
14
18
14
7
3
14
15
0
0
3
2
9
4
17
3
0
4
6
14
11
1
3
13
19
19
12
19
5
15
15
14
4
6
1
4
6
3
11
1
20
7
7
1
10
7
3
18
1
15
16
14
14
0
1
7
12
2
15
2
19
7
17
20
0
19
19
6
10
4
4
5
20
15
6
1
10
9
15
6
11
8
18
16
8
3
9
15
14
17
7
8
17
10
14
8
0
4
15
5
19
1
17
17
3
14
3
4
3
0
19
4
9
6
16
3
12
17
10
2
14
0
5
2
9
2
11
11
8
8
9
3
14
2
20
20
0
3
5
1
16
6
12
20
5
11
0
4
9
18
0
6
3
13
7
2
17
7
3
15
13
7
11
2
8
18
14
8
14
18
0
13
5
7
14
0
11
20
4
4
12
3
13
11
16
1
10
17
7
4
16
19
8
0
8
19
9
15
17
5
9
19
3
0
6
1
14
5
13
0
12
18
7
13
8
0
2
10
5
0
7
10
15
1
4
11
19
17
4
18
17
13
14
14
16
8
3
17
7
0
9
14
1
10
0
3
0
0
16
5
12
1
14
3
17
20
9
13
11
5
6
1
10
11
17
19
0
2
0
0
18
11
13
9
1
20
0
3
12
18
19
15
3
0
19
7
3
4
5
8
2
18
20
6
13
20
1
19
1
0
12
13
0
14
19
6
4
14
9
15
3
6
11
0
11
13
15
12
18
0
14
1
3
0
0
11
11
4
10
7
13
6
1
17
9
4
15
1
0
11
3
0
13
16
0
1
18
0
0
20
11
18
17
6
18
9
19
8
13
9
0
0
1
18
10
10
2
2
6
18
3
2
6
10
2
16
18
20
0
20
8
13
0
17
11
5
13
3
16
8
7
12
13
12
10
5
10
0
10
4
18
0
0
13
0
7
11
17
8
9
15
8
0
0
16
4
3
0
20
5
10
8
8
7
13
2
0
0
0
4
12
7
19
11
3
0
16
18
2
2
0
4
0
12
5
9
2
12
3
17
14
3
20
10
2
18
19
4
17
7
11
13
12
0
10
11
17
7
0
15
1
14
10
7
11
0
11
14
5
17
4
0
13
10
16
15
2
20
11
2
8
3
6
12
0
17
7
0
5
12
1
1
1
0
13
16
15
0
20
10
10
0
1
1
16
4
14
14
11
9
10
4
10
3
11
1
10
12
17
13
16
16
10
6
16
19
13
0
10
18
14
14
3
8
13
11
10
0
1
11
15
16
6
7
15
12
0
16
0
3
4
3
17
8
10
15
15
15
14
13
15
19
3
6
6
4
4
0
3
5
9
0
15
6
13
2
4
16
4
2
13
6
12
15
0
2
3
11
0
1
9
0
1
3
8
0
18
10
16
5
6
3
20
13
8
13
17
17
6
15
13
17
4
20
12
20
10
18
0
5
0
0
2
9
15
12
1
8
4
10
6
17
0
20
2
10
2
16
17
0
2
0
3
18
8
1
13
0
0
20
19
1
10
1
20
0
7
15
8
10
0
17
0
0
19
8
9
6
9
0
19
0
4
2
16
20
12
2
12
0
11
0
6
9
0
0
0
1
2
3
0
3
13
1
0
0
0
8
4
1
17
17
4
13
9
0
0
12
13
13
14
18
17
10
9
15
17
0
20
13
4
5
10
16
6
5
7
0
9
2
11
2
18
6
19
16
14
14
6
15
18
20
3
3
4
10
10
17
19
0
0
11
0
13
10
5
3
17
7
8
12
11
17
18
2
20
0
4
0
15
9
6
9
5
14
20
11
6
20
5
6
9
15
4
18
7
1
13
15
2
18
4
2
19
0
9
3
0
17
4
7
17
0
12
1
7
7
15
4
17
12
15
18
5
1
0
2
0
6
5
6
0
10
0
18
8
5
15
0
8
20
0
20
14
5
18
2
15
17
7
0
13
12
20
16
3
16
2
19
20
0
13
16
0
6
11
18
0
12
5
2
1
14
5
15
8
17
10
10
16
12
13
1
4
10
10
0
19
9
19
8
16
5
12
8
0
12
5
8
12
0
9
18
1
19
7
14
4
2
15
17
10
15
0
13
14
9
18
15
0
0
13
4
10
12
8
14
16
13
10
18
17
8
20
5
14
12
9
7
13
11
1
5
10
16
0
9
10
12
14
15
0
9
6
0
4
4
7
5
0
17
7
11
6
14
7
17
0
18
4
10
1
7
6
14
20
2
9
1
8
3
11
0
0
7
5
4
16
6
18
18
5
2
12
10
2
10
20
1
8
7
19
15
11
1
0
20
13
1
0
18
14
0
10
17
8
0
7
11
12
12
17
19
7
15
0
16
4
0
7
10
0
0
9
20
19
11
13
6
6
0
0
3
10
11
6
16
10
2
5
1
1
0
11
1
2
4
19
17
20
12
8
5
13
4
20
3
6
9
10
10
5
15
10
18
3
11
10
11
8
0
7
13
0
9
11
0
15
13
13
0
5
19
16
0
1
6
2
16
0
15
15
14
13
19
14
19
0
10
19
0
12
16
10
1
13
20
5
14
14
16
1
18
11
7
0
2
11
6
1
20
19
15
5
5
8
19
5
5
18
19
16
0
0
20
10
0
4
2
13
10
6
18
4
2
17
16
13
2
11
15
12
4
6
16
20
2
15
2
0
18
11
19
0
1
19
13
16
11
12
7
20
3
3
7
10
12
9
3
13
0
13
16
0
14
19
7
4
0
16
2
0
5
14
17
20
19
11
1
8
4
2
18
13
6
19
2
10
3
12
9
10
2
3
0
20
1
0
17
13
11
10
5
0
12
9
16
12
20
1
1
3
3
16
15
5
9
20
18
15
14
0
16
19
0
17
14
4
1
8
11
5
2
12
7
7
8
12
10
8
1
7
15
11
11
2
2
9
10
12
10
15
15
7
15
19
13
0
17
0
11
20
14
11
2
6
8
3
7
7
5
16
17
6
4
16
3
2
4
15
0
4
13
15
0
2
0
11
8
8
11
1
14
6
8
4
0
18
6
1
0
10
2
0
12
7
8
3
17
0
13
18
3
11
16
6
9
6
0
0
20
7
4
0
0
8
9
3
13
8
4
7
19
10
1
3
7
10
8
7
15
1
0
10
17
15
2
9
12
12
14
2
7
0
12
4
14
16
2
13
4
5
6
11
2
8
0
7
0
17
1
1
13
15
12
17
10
15
14
3
10
17
2
18
20
12
15
2
3
7
7
0
20
7
8
0
12
3
15
13
0
0
2
13
4
16
8
14
8
11
11
5
5
5
10
9
4
10
7
19
0
4
15
3
2
14
1
13
15
9
1
18
10
6
19
14
10
18
11
14
6
10
6
19
0
9
17
10
11
15
0
6
8
13
9
3
0
19
7
10
14
10
0
1
11
0
19
0
0
2
8
12
0
19
9
20
11
8
17
9
3
4
11
12
0
13
0
3
9
8
8
5
14
4
19
0
3
16
13
12
15
15
5
16
20
20
0
20
19
6
14
0
11
19
5
17
16
1
6
0
0
17
0
8
5
0
17
8
4
15
15
15
12
3
1
18
17
18
10
13
7
20
2
8
8
13
12
10
10
12
0
15
0
17
13
6
15
11
0
3
4
13
0
8
13
2
18
0
18
5
0
1
9
15
0
0
7
4
0
3
10
13
0
4
0
4
4
5
3
19
15
0
2
0
15
2
16
0
12
0
3
17
8
16
1
16
0
6
17
0
8
20
20
4
11
7
13
9
5
4
5
7
10
16
7
10
0
6
14
2
18
0
1
20
20
12
16
18
12
7
6
3
17
0
11
10
20
9
6
3
14
0
13
20
2
10
4
3
19
0
0
5
8
5
3
5
9
13
15
3
1
0
10
2
0
14
7
17
19
9
4
14
0
14
15
16
3
0
17
8
3
11
14
0
0
8
0
6
13
12
8
20
19
5
13
5
0
19
8
1
16
9
9
0
4
6
0
15
16
2
9
9
13
11
9
2
8
4
1
15
2
6
20
0
14
10
6
7
14
10
10
16
18
20
20
4
6
0
7
20
5
19
13
15
11
4
10
19
5
6
12
11
3
9
2
8
3
4
16
6
12
15
4
0
1
10
9
9
6
16
11
2
16
12
16
12
0
16
19
18
9
5
10
0
0
18
11
0
9
9
11
17
6
5
13
3
8
0
17
7
14
0
18
0
0
0
11
11
17
12
8
12
5
6
19
9
17
19
12
2
9
7
4
20
6
0
0
6
0
1
0
0
8
18
0
12
20
0
0
6
0
13
14
0
4
16
4
0
18
9
0
4
15
1
11
0
7
3
4
1
3
7
9
16
8
0
9
0
8
9
9
0
17
9
12
19
18
6
3
20
2
13
16
12
19
14
17
13
11
5
6
6
1
14
1
0
5
1
8
6
3
0
19
18
18
13
1
0
20
18
16
16
3
7
14
6
5
19
5
11
8
20
2
0
11
15
1
19
0
12
4
18
13
8
7
15
10
6
2
0
0
2
7
1
20
11
8
19
16
8
4
0
19
16
1
8
0
0
2
0
13
0
0
2
13
0
0
0
19
15
8
6
17
3
0
5
0
0
0
3
1
3
10
6
0
7
3
0
6
20
16
20
2
8
0
15
15
5
8
14
1
17
14
15
0
0
0
6
13
9
1
15
10
2
2
12
12
7
6
6
13
12
9
4
13
18
15
6
7
0
0
0
0
0
11
2
11
3
1
16
10
15
13
19
12
14
0
18
15
1
9
18
12
16
20
11
2
17
7
9
10
12
0
0
19
10
12
9
4
9
3
0
0
12
9
10
6
14
19
20
2
3
10
3
3
17
11
3
14
14
13
1
2
20
15
4
7
13
1
9
0
17
5
7
7
0
7
14
2
18
13
0
20
2
8
2
0
0
15
8
15
3
3
5
3
4
12
8
19
11
4
3
7
12
0
12
7
18
4
16
0
0
16
5
12
0
7
11
9
8
8
8
20
16
18
6
1
8
8
14
19
2
6
0
13
2
4
4
17
0
16
11
16
15
12
14
0
15
6
12
17
10
0
19
13
4
17
17
2
8
0
0
12
16
3
7
14
11
9
13
9
20
12
18
16
16
17
20
15
11
11
14
0
0
16
10
4
0
8
10
4
12
11
4
10
0
17
0
13
4
4
0
16
10
0
8
0
0
10
15
12
5
3
8
14
16
19
11
20
13
12
10
0
16
0
16
14
3
3
2
1
3
8
12
10
17
11
2
9
1
7
16
4
14
14
18
12
15
15
8
15
10
0
18
10
18
17
2
16
9
6
4
8
2
14
4
17
11
2
12
1
17
7
14
7
7
17
2
0
1
14
8
20
20
13
19
0
14
11
7
14
7
14
17
16
2
18
13
16
6
12
19
15
14
5
3
18
3
16
16
2
1
0
4
4
4
1
8
7
11
2
13
5
11
12
17
14
1
13
18
4
0
8
17
3
0
11
10
3
11
7
7
18
6
7
6
14
2
10
1
17
9
19
7
17
14
1
0
14
19
18
10
1
12
19
4
11
6
18
16
9
0
8
13
0
16
0
3
6
7
2
11
9
6
17
3
20
0
1
16
0
18
12
18
0
12
20
6
14
13
3
0
11
13
19
14
4
12
10
17
0
0
15
13
0
0
9
4
1
0
14
2
9
10
11
10
9
0
12
10
11
11
5
5
15
13
1
20
16
7
19
15
9
0
16
11
15
1
7
16
13
5
1
0
2
16
20
18
5
19
15
5
14
16
0
14
0
7
10
7
14
11
14
0
12
11
7
7
4
0
0
9
3
17
16
20
8
6
8
3
17
20
12
10
3
3
6
12
13
0
0
7
10
14
0
9
1
17
15
18
4
5
15
12
15
19
1
17
4
15
20
12
5
19
15
13
8
12
10
6
20
6
12
4
15
7
14
6
8
16
11
18
2
0
18
1
6
8
12
0
18
6
0
8
5
0
12
10
0
20
14
13
17
19
11
14
3
18
2
4
0
14
14
8
19
19
9
12
3
19
7
13
10
9
2
0
9
11
11
2
17
13
4
0
4
15
14
2
5
9
7
5
4
12
6
9
12
0
11
0
17
16
0
5
12
3
14
15
3
0
12
7
0
18
10
16
2
6
6
9
5
7
3
0
19
0
20
12
15
4
20
18
2
0
9
18
18
3
2
20
19
16
1
11
2
2
18
0
13
20
19
10
14
16
12
12
1
17
14
5
6
20
10
8
13
0
14
0
20
0
1
5
13
16
0
18
12
8
13
10
5
1
16
20
7
4
1
0
4
14
10
16
10
4
20
0
10
0
15
4
18
16
7
20
7
14
11
17
3
14
18
14
8
3
4
5
20
17
5
1
9
2
16
13
9
18
19
0
10
20
5
1
9
16
4
0
11
16
5
10
15
7
5
17
19
16
10
3
18
0
10
7
7
6
2
2
4
17
16
4
12
8
18
7
3
11
7
18
1
13
13
9
1
17
15
20
20
12
16
6
20
0
5
12
5
19
16
15
4
0
0
0
13
2
16
0
6
6
8
7
3
11
20
12
17
18
6
8
15
14
11
11
10
0
4
1
12
20
17
14
5
10
6
7
5
12
3
8
10
1
20
15
8
2
16
6
17
0
6
0
5
8
4
8
4
4
11
18
12
7
0
4
16
6
6
11
11
19
3
5
5
3
19
14
14
0
13
14
9
5
20
1
11
20
12
17
19
20
9
0
13
0
12
6
13
15
14
0
13
11
15
0
9
0
14
9
18
7
20
8
8
6
6
0
16
8
4
3
2
7
7
1
20
8
8
0
12
8
6
6
10
20
0
9
1
19
3
10
0
13
5
6
11
0
2
15
16
4
2
10
5
12
0
17
18
4
10
0
0
1
2
5
0
6
11
1
15
8
4
11
20
2
1
11
1
1
20
17
9
20
20
11
14
6
1
7
2
6
20
19
11
6
9
0
0
11
1
20
0
16
1
13
6
14
13
0
15
10
13
11
2
0
15
11
0
7
1
16
0
12
6
9
12
17
17
10
0
6
2
9
10
11
12
17
7
14
14
0
18
13
12
18
2
8
16
3
7
1
7
14
17
3
15
6
1
8
19
0
2
15
3
5
8
0
9
20
10
3
11
15
15
5
10
11
0
12
15
18
0
4
3
5
3
6
8
17
1
5
0
2
0
7
17
20
5
3
3
4
10
13
20
0
0
9
13
2
20
9
0
2
18
0
19
6
3
19
4
17
3
8
17
15
19
7
0
0
9
0
0
13
6
5
0
3
20
15
12
0
19
6
5
5
20
16
14
10
2
6
5
3
9
3
15
10
6
0
0
1
6
18
7
1
20
14
3
19
0
2
6
12
16
4
17
3
7
0
18
6
17
16
14
9
13
0
13
14
3
5
11
7
0
3
6
0
8
8
17
13
3
12
0
6
14
16
15
19
13
13
8
7
0
0
0
16
2
11
18
4
11
1
15
9
9
19
0
5
8
0
5
2
0
16
20
19
0
19
16
17
1
20
4
18
5
0
4
9
20
8
3
10
8
3
7
11
6
19
20
0
14
19
6
0
20
3
3
5
2
17
11
7
13
13
11
10
5
4
15
17
2
20
17
8
19
9
7
18
17
5
5
9
19
13
15
16
18
15
10
5
19
19
0
10
0
8
16
16
20
17
4
1
6
7
3
9
0
9
9
17
5
0
20
10
20
0
18
19
8
5
16
5
0
2
19
5
13
0
2
17
20
12
7
4
0
3
15
6
9
10
9
2
1
5
18
0
0
16
5
14
7
3
11
17
12
5
2
20
10
6
15
1
10
15
16
6
9
13
18
7
20
14
10
2
19
1
15
0
0
0
9
10
0
12
13
12
7
14
14
8
3
19
18
8
3
0
11
13
19
9
16
0
1
5
6
20
19
20
15
7
6
1
20
16
15
11
18
20
0
7
6
0
10
1
20
6
17
13
6
8
0
0
16
13
6
16
8
14
13
4
6
19
0
12
4
12
4
14
5
3
0
14
20
9
13
1
10
3
9
5
0
4
18
0
16
9
1
16
1
8
16
8
6
16
0
20
0
0
20
19
7
1
0
10
2
10
6
19
4
7
10
2
12
11
2
9
1
5
15
1
17
13
7
7
0
3
16
14
12
2
6
0
0
17
4
8
18
4
0
0
0
8
2
13
5
16
17
10
7
2
16
5
11
3
13
0
5
6
6
12
16
0
12
10
6
0
7
0
12
1
1
5
0
0
4
2
18
7
16
12
10
13
13
14
15
10
15
15
6
0
17
3
8
9
3
0
19
11
3
9
1
11
2
18
14
17
17
9
18
0
19
20
3
18
19
11
16
0
8
4
18
8
20
16
10
3
0
0
17
18
11
7
0
19
12
8
0
20
20
5
19
10
20
9
6
5
19
9
11
5
6
6
8
0
0
13
9
6
19
1
2
7
12
20
13
5
13
18
8
13
0
0
12
2
2
18
16
19
12
10
6
14
9
10
15
18
2
5
10
15
3
16
9
3
19
9
0
3
11
1
3
1
7
16
2
0
17
18
19
0
15
11
8
16
12
16
6
14
15
16
0
5
3
17
10
18
3
0
20
11
4
0
11
17
18
15
1
18
0
5
0
7
19
14
12
18
5
6
12
5
16
9
19
3
18
1
14
4
2
18
0
10
20
0
20
16
0
8
0
11
5
7
9
0
9
4
20
7
15
12
6
2
19
3
15
8
4
15
1
6
15
12
19
7
8
8
16
4
10
20
15
1
0
15
15
19
7
3
19
13
10
20
7
20
8
8
7
14
19
8
14
17
3
19
1
0
17
19
7
8
9
0
13
9
17
0
0
5
8
10
10
19
0
14
12
16
4
18
16
1
3
1
13
0
10
0
17
6
14
15
1
0
2
9
12
5
0
1
4
5
0
1
13
12
10
9
20
16
7
9
14
17
13
0
16
0
20
8
12
0
8
9
2
16
3
1
18
3
8
18
13
19
2
14
7
19
19
11
5
0
10
0
5
0
10
2
1
5
10
8
15
16
2
3
13
0
13
19
0
10
7
7
4
4
8
9
5
2
1
8
12
3
0
3
4
4
15
13
15
10
17
9
4
5
3
3
9
0
14
19
3
17
13
20
1
14
17
1
2
0
0
15
15
16
0
4
14
8
10
1
4
9
13
19
11
10
11
0
9
16
4
13
2
18
5
0
14
3
0
2
10
8
0
13
0
15
6
20
0
14
18
11
15
4
13
3
9
9
4
10
2
18
6
2
11
10
11
2
8
17
18
1
14
18
3
19
16
7
13
3
1
18
8
2
11
9
10
17
14
7
20
0
0
16
15
16
12
20
0
6
20
13
0
5
4
3
11
19
1
2
13
0
13
3
10
11
12
1
7
16
0
4
12
9
3
0
14
12
2
0
1
19
11
20
7
0
0
12
5
11
18
7
20
5
19
15
7
15
2
0
12
2
20
17
5
4
5
7
9
0
11
20
14
3
12
1
14
19
17
16
19
14
1
3
15
0
7
7
20
19
14
13
2
7
10
18
15
16
6
16
11
18
12
18
18
12
7
12
19
2
1
6
14
16
18
16
0
17
0
5
19
10
1
6
9
8
12
12
9
5
11
6
17
4
9
16
6
7
0
20
8
7
0
0
0
4
4
0
6
1
10
7
18
5
1
14
17
17
19
15
12
7
2
15
15
14
0
4
8
16
19
0
18
16
2
15
9
15
0
15
4
0
0
4
15
12
17
2
20
5
9
2
15
15
2
15
7
0
10
6
8
7
7
2
18
0
0
3
3
19
17
6
0
0
9
12
4
13
10
18
17
5
16
16
11
2
4
15
2
13
10
6
2
6
6
7
0
18
8
15
13
0
17
0
16
1
14
11
4
15
10
9
15
17
17
13
15
10
5
7
19
11
7
2
16
10
13
5
19
7
4
14
6
14
3
14
10
0
1
4
10
4
16
12
0
7
8
7
8
1
8
14
20
6
18
18
7
7
18
16
18
7
8
16
0
5
16
0
9
5
6
14
2
11
18
6
20
0
20
17
19
4
4
16
0
13
13
1
6
13
11
15
17
2
6
12
1
7
12
11
13
1
17
9
1
18
17
15
0
0
2
15
11
16
3
9
16
18
4
0
0
0
0
1
13
7
8
12
7
16
13
15
17
8
16
17
17
11
13
0
0
15
15
1
20
14
4
14
9
18
0
5
16
8
11
12
6
8
17
19
19
7
0
0
17
0
7
0
6
16
4
14
18
18
19
10
11
13
1
0
8
14
10
0
3
8
15
8
18
1
7
17
7
6
16
5
0
2
15
13
19
0
4
4
19
6
0
13
0
20
13
7
14
12
11
17
19
3
0
12
15
20
8
11
13
12
1
16
2
0
13
4
17
10
19
12
15
4
3
1
13
5
17
0
12
0
2
0
0
14
20
6
0
5
17
9
18
8
17
3
11
0
0
5
2
12
12
18
0
7
0
10
16
0
10
17
19
5
18
19
0
3
15
7
9
0
12
9
16
0
0
17
17
8
20
2
1
14
17
1
7
0
0
6
17
18
0
1
0
14
14
2
3
19
16
19
9
0
20
6
10
15
17
0
4
16
1
9
17
9
4
9
0
1
12
0
4
1
0
7
14
12
0
19
19
16
5
18
7
12
16
9
8
14
17
4
11
12
15
4
8
17
2
8
19
1
8
2
8
5
15
6
3
0
7
0
0
8
1
7
13
7
19
12
19
10
0
17
17
0
11
14
9
12
16
11
0
10
19
8
11
6
0
11
1
8
19
6
15
1
5
1
15
0
0
12
18
4
7
8
8
11
10
5
17
2
6
12
13
18
4
15
12
20
19
18
18
20
12
5
2
18
3
9
5
7
18
0
0
0
15
10
8
0
20
10
0
9
5
0
7
0
0
2
9
0
9
6
8
18
5
6
0
6
10
3
10
3
5
20
4
19
7
16
0
10
5
12
6
15
11
3
19
18
19
2
3
3
7
15
17
9
2
17
17
4
6
5
0
12
19
15
3
5
1
18
17
0
16
13
18
5
0
4
9
16
20
3
12
7
8
0
9
1
14
12
8
16
17
2
19
0
17
18
2
14
10
5
15
10
15
13
3
15
3
11
8
12
3
18
13
13
12
0
9
10
11
9
15
0
10
8
0
0
9
7
5
10
7
5
8
9
17
10
7
3
2
20
10
3
13
2
13
0
0
18
6
3
8
1
16
7
0
16
0
8
0
8
19
9
5
0
0
0
11
0
0
1
16
0
0
16
16
12
15
2
5
16
3
17
16
16
13
11
19
17
13
14
0
0
9
3
6
2
11
4
10
15
13
2
7
9
4
18
18
5
8
7
6
0
11
15
15
0
7
20
13
10
14
1
5
0
5
4
13
8
5
12
5
19
0
4
0
13
1
18
18
20
3
15
3
6
10
0
11
6
6
6
10
9
0
6
2
8
10
1
0
14
3
2
12
4
18
20
12
3
10
4
0
0
10
6
11
11
8
19
15
10
0
11
0
16
12
4
2
18
4
5
16
5
15
6
0
18
0
6
17
8
0
6
9
8
5
0
3
2
16
8
11
15
14
4
7
0
18
4
11
9
1
5
10
13
17
0
13
10
9
7
0
0
3
14
1
6
7
20
20
17
0
5
11
1
19
0
0
3
9
9
13
10
14
14
16
6
13
20
0
19
4
0
20
0
14
9
20
2
12
10
5
3
14
1
15
6
0
6
2
5
18
14
12
6
0
6
3
17
19
0
7
14
4
8
13
9
15
2
7
3
16
1
5
1
3
13
12
11
13
3
11
5
17
0
15
9
20
11
1
13
19
0
13
11
14
11
19
4
3
4
8
17
10
13
7
18
2
0
1
18
11
2
7
12
5
0
0
1
20
15
4
6
6
14
0
18
9
14
10
0
19
3
4
5
1
3
19
0
13
14
7
12
20
0
15
2
10
19
10
19
0
0
14
18
13
0
18
17
13
0
18
20
12
2
11
11
0
13
15
4
14
7
8
3
10
6
4
16
17
12
0
19
9
1
0
15
17
0
17
14
8
6
5
7
4
4
15
0
15
19
6
8
0
3
18
2
18
0
11
13
2
12
12
0
4
6
8
20
4
5
20
18
9
9
13
14
10
0
3
0
8
11
0
15
12
19
1
13
12
15
12
6
20
0
19
8
10
1
0
15
19
19
15
14
0
18
9
15
5
9
0
16
12
20
8
4
2
13
0
2
15
10
1
19
4
5
4
15
3
8
0
3
16
16
6
9
0
6
7
0
12
8
1
1
15
19
20
9
9
5
0
11
20
11
4
4
1
2
20
0
19
9
2
13
0
8
1
0
0
10
13
6
13
5
14
15
6
13
0
5
4
1
12
1
11
11
16
6
9
6
0
2
0
7
12
0
8
3
5
0
1
15
4
0
18
15
16
18
12
0
0
4
17
0
8
6
9
17
17
0
12
11
3
2
16
18
0
10
6
0
12
11
4
13
0
19
0
4
19
20
7
13
4
2
9
8
3
18
1
3
12
16
6
3
10
15
4
20
19
0
9
2
20
14
2
10
9
0
11
2
11
11
17
19
0
17
20
14
8
0
0
16
12
6
17
11
7
13
11
7
19
18
6
15
11
16
6
0
18
20
7
3
12
17
9
15
19
9
15
6
1
3
17
9
20
12
5
5
15
3
8
0
6
12
14
20
17
8
17
10
11
19
0
18
9
8
18
13
0
11
14
5
17
0
12
12
5
0
9
12
0
6
9
19
17
16
9
6
19
13
8
3
2
15
0
0
0
1
4
8
8
8
0
11
2
16
0
3
7
3
3
18
5
6
15
4
0
4
16
1
16
16
6
4
13
9
18
5
4
0
0
14
19
9
18
5
0
9
10
9
2
13
0
9
6
14
19
2
7
18
10
20
13
5
6
2
5
7
14
4
1
10
19
9
2
14
14
13
10
14
12
3
4
16
10
6
0
9
14
19
1
17
6
20
14
0
1
2
10
13
7
9
13
15
0
0
2
19
12
18
11
13
17
18
5
20
9
0
9
0
8
5
10
13
11
14
1
2
10
7
10
18
0
0
2
17
0
4
8
6
10
18
9
20
2
6
13
12
5
9
14
11
13
8
0
16
3
20
13
4
20
7
13
12
8
0
8
8
19
0
7
13
11
15
9
9
18
2
3
5
19
9
19
11
0
19
18
5
10
0
3
11
15
13
0
15
18
2
5
18
14
0
7
18
11
6
4
17
19
6
10
3
20
1
17
0
12
9
6
0
0
0
12
7
4
0
0
8
3
0
15
3
0
18
0
3
16
6
18
6
16
11
2
11
0
12
12
0
10
18
11
4
6
0
14
20
8
18
1
3
12
3
15
20
6
10
1
9
3
0
11
19
19
4
18
7
14
0
2
7
6
1
8
10
4
11
5
7
9
9
10
11
12
16
2
13
0
14
0
3
19
0
7
11
17
3
7
0
4
7
11
7
7
18
0
4
17
1
19
4
7
8
18
14
5
8
3
20
17
15
0
10
15
3
0
19
15
0
19
1
15
20
19
9
16
3
16
16
2
9
8
15
18
9
9
16
19
6
0
8
16
19
13
18
4
20
14
2
5
8
4
4
5
4
11
13
0
8
2
10
17
2
0
12
2
0
9
8
1
9
1
6
15
20
0
1
12
0
3
10
0
19
13
3
13
8
1
6
19
20
0
11
9
0
0
7
3
0
8
10
17
19
11
18
6
0
1
18
6
5
6
15
5
5
1
8
14
17
17
8
16
9
10
0
0
0
12
20
7
12
10
18
4
11
9
8
0
20
9
0
16
7
0
16
3
11
10
20
14
18
0
3
7
8
9
2
5
15
10
5
14
19
2
5
6
1
0
5
15
0
9
7
9
3
6
10
8
8
18
2
4
4
4
20
3
0
11
4
12
7
7
10
2
3
8
11
1
13
20
17
17
2
1
10
12
11
8
17
13
10
1
5
20
16
7
0
0
2
9
11
1
2
12
0
4
11
6
9
19
20
3
10
9
18
14
12
5
1
1
0
17
20
7
0
6
13
19
11
15
12
4
14
4
3
18
17
14
5
17
7
17
1
7
13
1
0
2
4
1
0
5
6
4
15
3
1
18
2
9
19
16
17
0
5
1
7
2
0
6
0
0
0
17
17
10
12
7
10
14
0
0
15
0
12
12
8
6
13
17
3
19
19
7
10
12
0
2
10
5
17
8
16
17
18
20
5
0
8
13
17
6
17
9
3
0
0
15
3
10
15
0
14
0
15
3
19
2
10
4
16
1
9
7
20
13
0
8
9
11
7
0
2
6
15
0
8
20
1
5
6
7
12
11
13
3
9
0
0
2
16
14
8
13
2
13
5
9
2
0
3
14
7
9
0
2
10
12
11
1
2
7
7
0
0
18
9
5
3
18
12
15
8
0
18
6
13
7
11
5
0
11
4
13
8
17
3
3
0
13
16
9
17
0
9
12
5
2
14
18
0
14
7
14
9
3
6
4
16
15
14
1
3
14
2
9
10
19
13
8
5
14
10
13
2
12
5
4
3
14
6
11
5
3
8
2
19
17
8
7
3
13
6
0
17
20
12
16
0
3
1
14
16
0
4
19
1
15
6
8
14
4
8
4
18
0
4
16
11
20
0
18
19
5
18
2
14
17
20
15
0
0
0
11
12
1
10
1
0
0
12
10
6
14
13
10
13
8
9
14
17
0
11
8
13
11
14
3
10
6
2
18
6
15
15
5
0
19
0
3
13
9
0
16
8
10
6
8
18
15
4
13
12
4
9
8
11
13
14
5
17
11
14
6
0
4
5
0
2
9
13
4
17
5
7
14
1
1
10
17
2
12
20
20
1
11
17
1
5
15
15
14
11
15
0
20
2
3
9
4
18
7
20
0
19
6
14
2
7
8
18
14
19
14
5
9
19
12
7
0
0
4
9
4
0
8
10
18
0
19
5
5
20
3
16
0
17
0
18
12
3
14
7
4
9
9
8
2
10
0
5
18
15
0
9
0
10
17
7
7
16
12
0
12
14
12
6
6
4
19
4
12
3
17
19
2
0
15
20
6
12
18
5
3
0
15
1
11
2
20
17
14
3
1
0
3
12
20
20
15
7
0
8
16
10
12
10
2
19
12
10
5
11
15
4
12
6
5
11
3
1
0
5
2
14
2
11
16
6
5
4
20
17
20
3
2
20
14
3
5
0
12
16
13
15
0
10
14
20
3
0
8
8
0
6
8
2
18
18
18
10
2
6
10
14
10
16
20
13
5
3
5
20
5
19
3
14
0
14
15
17
3
4
0
16
1
16
12
8
5
3
9
3
7
8
0
10
2
4
7
10
4
2
0
11
10
0
5
13
5
0
4
7
1
9
18
14
1
18
16
0
4
11
5
11
19
8
0
7
0
20
11
18
0
5
13
0
14
12
1
16
6
14
17
4
12
0
14
4
9
19
16
2
17
3
4
1
14
3
10
0
3
19
7
13
15
3
8
17
0
12
10
17
6
5
2
3
6
14
11
4
13
11
0
15
11
18
18
10
19
6
11
0
19
18
13
7
0
12
20
12
8
1
7
2
12
1
17
4
9
16
6
17
0
8
1
0
5
1
2
8
16
2
14
1
6
7
0
0
12

In #3:
10000
778753534913338579 662851008325436054 938229232136483014
642392242490442144 784606205617394132 235809985868754547
540322527919825917 955887397569669876 528508608288439163
250851252510130310 156642679234741525 334318234076026939
860671253717015340 928395870487315002 187514281875266706
654711549545037954 149008213104367657 975136138262497498
698495325302727184 793612507966353933 235362796868494842
20384617135243333 215429819132447421 355944361740879059
835587899706964759 836880934397609258 69662276760119256
514556759638908155 341726195989468978 82544805744809277
589112983058087273 458930747054299614 493319149921283646
225581936138663895 977096721650608687 274714050451024134
184954731962896181 502132138668870680 548795864313502482
546526404686817103 117458358073138232 603399843280438425
343653705720249865 906703164469197525 673918401863050312
661787515534440565 326322145915832774 393923862335234919
975253959564875354 383419609801007608 87454703002689580
721688151994769746 814688563287018480 326003465546149094
706740175281471692 895062599289875336 248847573172740945
496187135189144873 746923605934951293 460938478237218408
88673808451480160 618247851282568481 112239618979140277
677622678741862954 789385989881993444 410400703421342829
636402885908495913 741255537293384471 522755991547823651
898590048003587392 713319443240961834 152737031464545320
671405546322700149 766178371547351436 242183768870735463
236555091781943488 57086021624368677 836537549982890345
611117801762781070 532839913904521597 538312774864213780
956670085608628818 872314995012562786 474222171035391321
564657167928804525 383384540657830784 715209967578942881
705597630710791268 854443112709135725 21796103193227357
136994613647498034 831398455276829203 903030416595032686
92216862484583179 30092941272312043 51481388750868419
866752632057718233 841430472482709201 402585024728757757
591179997819946845 695349061717879149 25108806157458114
56856351876015688 82601858122468784 984695707048160503
905811715037834262 969961751617079594 751953839896894709
149244774680560857 789223899399481530 57842649340391362
813870999423858548 348775926920974492 114089485911505358
512072700277527413 187943140524503496 105452628269271360
141268916617481777 998732186697075868 101510401054379427
810926286383833074 11203590903569629 387819178972354757
416441572175668245 548986792997989468 263696415427803050
509925048299991399 931260974279581730 372259639582681930
963480857315667307 976471433464672842 670617706934110539
410062380701388070 78538568405225463 827631688398888441
58296288359044170 79178364851754725 737091512148696680
368428020940357148 265580736126583767 621733510750269685
84346337649698643 404275573109073283 335639948692479444
762672525332522969 171345108172912250 507258235367977452
977851116931936784 268943194933482436 189097278157722704
895615252051540983 76139855383339583 749641961154970227
781869924441132463 741809472688525873 238562671012215244
650124326268673757 462378294830700348 606339256796832786
216787866613304121 809638976120537467 72196822017971735
281415331634071694 692397086406601943 529193135398555503
629838100202977869 314494817110351047 661447625306733353
881527297963983186 837245560872839537 187388190667666002
492230714216311636 544755801796376954 916999082698356978
16476192110218737 100947722878938548 669425734288157348
833207521564850358 581019170808477172 926325794585419884
575310926278905437 92412111548796324 234768379272171702
912068224076321212 470101788302551915 686970622560001048
849461914425316141 769552092602241714 523318834435255438
150355922242994761 634752951424647012 657111602967173492
886544748948702922 364955416561885954 274999097928807157
79608426018567145 927304217290534890 835857450523312113
202279510600893855 321155824279587373 874312029411534126
408761139282961470 124556698654177179 919604759352144148
56711181996523903 458168700808290036 85973878093017158
921271889382018206 684220496420365374 588420750052543915
116126387082382471 612230298703889021 834726479748736917
679560494274410218 812936113416502639 383409498750074011
656612749405546232 761304823314019476 889950293031433864
543087639676500898 47803222166443449 474811451924819607
466277037677751419 816059132544956763 42456000820159870
666600006473459029 256883259256087439 592547365187590991
383087713674886330 645753711813889061 718784947124588047
571220007383348535 597995574159029177 899868628038941411
282481648850819971 130447354563451548 58868786873713884
582624923099010050 397072339158615510 759407510398861534
742933867162978987 125652369883000054 105545270208053635
138384073569946298 357912262586469715 817444289842798955
4105120109376538 411037905256302677 529720465833639008
634822071310861192 501328202268503517 599425652357453210
484502735058692450 585332762504534693 87992350767238196
468351061599277645 615145097983635870 356058850513726534
738757077140619528 391036355522362398 906696848783570270
955678531867389305 800318955295128760 798965837315317040
311931081870877547 187683287824450516 263486213398552594
869851717532932055 234043281473030250 846048256884251291
297944377962824633 365009834009806060 77894309994040951
525382274218739394 821596376403272453 388180681012694567
405580569620306909 607163167013161337 483229701932065474
73091954619504840 688623765831205239 246689073264517786
259201607393945463 134611953304190953 460575439677077794
869522803132248888 408483953711430659 872143466014318382
527474089787470950 322839734001741848 440679680568166439
225033094191639844 327615998037981903 202042436791428154
334777919476881128 885322535247996370 367555149894080642
687437173545141069 11288098103733539 534883254283158832
341847658039254203 129098925534596147 251054162340851733
228603388869431725 397258533639109497 158988479609985987
844576884613232297 543903585711901714 543419346999086584
900529505129728385 335135065390100216 544317764838700926
82089256000033564 707002887875348106 599988732748234596
912582580585510690 441245352833896366 819531734163192409
27158063003451685 534619408845374240 783634996754673665
291328707079953738 459337846387637364 617893101918608789
243094111535172289 179058428861890306 212993908281512684
490094263818797405 366033392111498035 363746198021545227
327023296761166377 408782981587787838 25211088063618008
312165225919777072 732697971709527603 534420316501569974
869470573544966372 45999231869083684 434063244930253851
387115412157354311 632885165294375629 679738103638282194
54600388894745666 40705724593204469 27157927067728041
634113391211916824 777376122523628835 223780734386701303
429210755950157583 861847947356876169 526192304488625415
289788844125648197 826613625200970675 89241544820459341
786702434313329916 97784849346236994 900119317727144023
385765236814997940 23277235481822524 732324616812637374
757407894653127434 697261498892264439 411917075417604655
18701180539996878 523205943666725456 349857777464129473
417466194661859834 565194821132736591 305761223428987752
621449737635050422 845916897924860590 858334738756479309
68301264248441074 907146324255661540 146391643671554316
916911863968156806 801860061508344160 103827915408027226
234679832237297372 533863289062911462 639615411218943332
25644174050630027 32311496731107696 775126962871208220
892541843200712366 848377961543019256 53678822729021505
941115282736196616 421749364327974424 316352921868169074
381116509243116384 801208919620847916 616911116858626669
12135719642771427 41448190052708818 62416664660466257
633486496253185720 380622789531401105 700902611812397140
527407437778653933 195311855051339999 613589263932883637
120473777036449692 45199156847764132 421222194975311907
166078697564946708 28891228337828623 253019956757432287
959342823269893016 670620625542510659 958974165371619075
198499639689212455 963452851765176480 456040082201868912
608067838269349770 643449550283551950 421211473897021803
239328701246063779 428793443192041124 266835072462670148
160913105402891147 933553827108088166 56915363845208837
427699692451045829 542495953243508313 607541841522707241
362215614555496028 976664281461099430 987795688846459289
120258633190057699 948902959615611904 12554828997288448
781251731060237244 426043928220626533 666934283472852810
496723222766587936 830561057918312616 668933489553240855
780164881152217648 573934430849164287 726775257022670870
643008510797340722 610998320537164733 408782633836916959
288433382035690489 368378813585458559 619995554902558360
725471628773507477 278926788444249909 859722821608042916
821444589276479336 122265272610822982 256915947214121972
525121507714129098 714746092000230256 616954646322319300
6034626826279471 138038190373528331 824097412995457029
156736560859819578 224837646851870451 717713938412667964
377043369331404489 717409557797013316 595826551455462404
565953331613460718 838801735517504242 837405472733619652
536646557061060908 320785128065895860 917841349172238893
688504790103228938 996169881283556189 396118436630805579
431776174832143163 883899552895120053 998227880787816431
348734784983395798 978002112757512373 430504969152160585
714643919074627375 902135572374038979 882684057330193221
659668217461004935 163113343956127456 810143209939284961
23287670892768356 713833360213299474 572225255291430087
55221728256527167 473586252846422202 659881275058509789
489674790412699912 917751456546338897 152712047744656013
562070403730345651 859752977977331911 867175770283404242
490194309946821736 119800179613084324 975194396662274198
843667484480629987 144710136805827489 664667403243572400
323276096848887549 43362290948397019 152329128308810389
830158518673287190 309364545994370808 280676974947085455
605826048631071592 292565748447934695 601159886442674819
153135439387536640 97835093606163084 406932021732100746
658452855058728174 293267653279386525 755023704281780469
690976364051369550 377108225974271396 730861128723982866
33535292153542390 877908819794395587 603722670160325225
545008243151087232 60814791674815819 691893318909264376
133050871816585005 672303584203292102 29427238428574368
383077875625334418 893528165196920564 894069859308616089
182173421848265562 172775598830981217 527032159908339135
999546558130673679 753657370140284751 230976259804133356
598941402482285055 372569693640674036 616036000491105099
468811735461384416 788586945810368597 101371316836497988
547643370028101447 44706939948860459 64658048297445851
825428795653691051 468837402169404712 125162685975108313
357323370070637573 493957801332502318 433181585054681159
241328778508699905 3286158864180213 181944819171882575
710470438058771672 724885457458594386 831308294362097721
8081862199902445 541276932012210274 858696683000279851
848628683134162267 38512702591492405 255125197196588218
774625140909817129 41547034746637573 81025148571050930
540936279920754693 86706605519965539 110896756757215387
451125383530562996 85945498440363914 970109228875266822
352189144198777794 147705225177791473 474218023821218270
396592763773105633 899134885050603208 238202223188297948
67011129474247079 829747191437411514 864935160693106983
687566242865128272 47348411211446241 401048267742204947
447528807270073369 681125381847641337 273741293897569948
405088476419200109 25907129617685770 406154768853203137
109048336604357444 662259587774179534 197224326249066530
820822200170504591 721644008010365262 553388002871354733
746991868412895906 502794422223908982 267946078307253380
559756793939992057 91803558947435932 194772938514355054
235259095395529661 891847697434313816 878930329131419709
484763445987042248 313567379590148932 447271298021988065
684639806051363465 861489838514355371 903430601398097739
314133035805875989 776947432659255185 624106169494593918
943796519538118280 482702485545041918 780216392941858871
78380203804341383 711605176969442452 788166116795290816
407881879717342596 830329610186292595 425566379216780415
759047263145074450 286757455023784746 858005090378137498
312814646289640279 13295535453930932 138272559077308977
62501353539821778 516380865592648349 381499294839907080
699757225207630636 60796856490991539 321704124192881340
501250894576509832 126490291155476730 995569719895513628
874765310409944474 623746219274236974 739162116939131698
860932994198938573 969715256240935185 47296204783075615
537498190599749782 600641640360946921 472886949860876658
760589820257551364 831246123223929230 387674994958563396
873403263508716528 214420149709841047 785131581597231827
30843749604450864 840778692348619079 544975491506478388
356596007311460295 798228491270223523 472195233787762728
738547342169886023 824493824752792813 998372906173208605
33373910732269472 730569043145995218 743560746255696530
292283006904694206 179718791218946505 302318256368588759
671973786981746489 869419812948791832 228912339987531308
931162610137412872 249455112850256388 819113475601668490
842742034138563642 994432656385522197 223563239067053410
923677287280036054 128572659478894427 45090874199544156
375715629751804785 301096754268735995 822977388207742249
480201344612886089 967383504112007744 235244823537880808
72230132409690757 812542860002211616 502612444709044712
776522710103166191 562000006232124274 883207230480643099
901205363938408831 315464252388163785 174276103986620292
966549223699522835 349932621102145738 516187728889431586
911435031902232700 576377451276217391 266970327671111428
665935599951512106 64236225708687518 671719710076524603
978828526810495265 807135350829276657 277029466142464317
909495229700458301 326470180677171330 177347567597506824
932958259427586367 697172835081132255 126589353328369982
942008405070429170 920313884875629501 398490605039677721
191170809888725212 632794164381422233 857271033065721396
785949929378237066 127901805524720805 991194750473262828
611592098449627384 827505311516911682 234111065629188943
537547847890212216 639257071458171882 736136802547903529
882616864595051781 578817906600721606 148627170229076270
855246854458102820 3075856465848028 134458572884983350
230616305600001822 478684281454026197 840298425754635142
892805567053409735 571126039981674342 798696588453887787
687574407448696887 111222628884433151 969336106358346082
348644701362560248 827174794970050318 218226316128195979
498467997647985802 639404669130133834 867470450347659149
242743887507815218 291609065454551582 771826872034755432
212225181992101982 689991276688442557 175566035149522858
967051107638019191 875038771391812824 564440088641327200
688498374030156561 729779271669955504 249524077375220717
472550905173423971 755006912823428282 432937881318996352
596633130199782687 840979818304284647 117904107512079076
583752118539565626 614287039700797194 402224083578226470
51845604513046563 256359857169150124 200181659931497943
894766574806918160 220934850260664792 832169645168992414
484158323852120528 578077509129239006 735545650124977873
673683860747667767 494058955402556879 600970331115029094
436488326198963596 975386628534822316 981173786006444222
197270823051639536 905615237025274245 281642625191279858
951544779224771491 392220418840875195 544831985202874218
919954963425848616 665741932520046624 464062103691494395
113779596791889756 374742729661443205 771773478194791383
426980052607984515 56712509186529094 213922020201493554
106910655639269292 747548214448742034 136808456890789801
639656958760357635 481546274228156992 535155615892634409
307374328885054933 50625686253696985 473499515865127502
688931523564362915 27689195153032860 714054108442298412
558017379719469404 160620074521139764 794998773636200663
809176121029719686 92532938458920483 922251107222021466
644515889396438970 806172110410638585 916556278410696455
498337789293723769 964391925815133553 76830894770372555
18217657886231703 522838919504889133 182504389317426603
613195519506541491 956117851330110505 927307063774837501
452139408752676847 974342006599369869 710943083734944324
11052712432647620 256677226525780581 275472838481865665
939375365827198241 930402740269528088 780371057323127798
194088877236414179 117010723914960673 89887611805095429
45116085293348635 441172011087629808 766589938790381921
395675155510959170 988865447594838573 446802740784365117
281375788727904810 277477657695499338 96929047002063939
861641844592122805 958140025941867896 523338753226543869
899101225052807941 309712963199864335 180008337547901346
191006308283447778 43558617057354283 483636559592031379
908744042418377076 408302603117791055 465817093727066162
824495670819569913 773439584507426339 721552201269158743
638184590741886456 753307772020889594 304411305651900483
479436273203396128 17547385168718223 597656361654285884
140173546373971948 969558125183127141 50247298786335660
891421682283684915 705739948275324721 656866890539274203
9197972619973192 536083564687617176 658478519973438599
373814202944360955 916568644184146692 812856669837071111
262716617744469335 415116910407751196 666536889689044415
463369523274455656 112254267131099286 978216708484546134
991897724082706186 622140739940965254 142095643363821843
274118990251199423 835340222086912677 715667665656867691
828680334043293733 474599556037258497 606311019802471941
574597522866098691 889355186643427324 740194405611838686
483507145545022173 40681891691434118 480853685599749715
499989082224693424 914435421379279229 941470828927285246
49411865906624209 991090160796284638 533420898561987452
649298644255530397 462211420601238881 706661283143030311
639766189437471834 760339140673950142 199366428505200724
490551996971119864 409386423383381233 50909227271258045
844902304045899863 614286978237963291 601063996937607952
158199015783326739 777699855267861227 975993954846802019
608333724080280998 887882972700557313 217656698024341132
884287962571722101 151557385509102171 491626236274349130
269481520508287000 849002525723176839 291453052227247148
256850383385136146 681973688031263248 816081015556180081
466118693316619882 890138966543606562 563446216811132752
98959541005210849 366435126209746372 299393742611553889
623683428300846257 350377190676610421 704938635973191909
597833168591568105 869278183083040364 582732589354800217
646139007418156822 229489305720408717 340473288212749931
826936386818463404 790466714832765512 591904306218472432
450858969408328596 631434355917865164 879697474869081486
557254516920815273 269027207421898200 968211463626065686
751756128857079874 242629568011657429 362641840300455941
160272798422027437 88649395391817107 749511196775864658
186508485417280971 594793706869105278 956459367087031843
926330869586444161 372392890805885537 827778249139115868
542277826426039731 231712504068704021 89216889713508060
250390467788122645 905039308272679843 725836054777272794
44030424058805159 434479453560144104 564433121547041049
720480048159095717 367953183974828522 387350032012261071
671135047010957370 151268484882046724 314384051281235457
665814920405579151 252649445395310626 819641120062594700
599587232892773500 930435842999467072 17780746934861678
255217246026525575 991245235971028114 152847713839592917
649397007778412198 536278405959715893 641252589995782847
815221762569002896 711255632777302723 785974890873334376
682011314889552675 887097338074431370 405294045601824696
93878016350073380 430529979846994962 332936983910345518
110146082770729703 66644297075834856 73913848964909226
809533737230933438 356471932410793385 524224894823112526
200810390637447964 863496997450096328 787542198662551499
36563922559900038 198716775140917110 984882828442613947
566490686521584143 905553786889409473 501641581966982603
877220495434153804 432417924617367712 6756976662019566
581220635344420100 139511153714734606 38531770921283006
347267073948356841 630955571500299576 146769571001280232
48610804153385968 413682112706239792 457439209254326816
550836639549962370 375717689790189766 423183966072514899
51685032437609929 746577501607040251 339264736826234715
745707454137180282 478690849952664274 901591094396784680
196623019542411913 552294824421380322 691816641204414246
159267184730897987 439397382164809685 517574951340276311
932877289803300440 475195532616493646 546092858145935768
853694806931713204 535447356139562032 698707109491973286
383669801851002679 693887711111737730 816282902145338316
266821010799813418 335113189069114135 383569399164370774
984838847299520569 923050152440891879 380909716095257401
540805103156333955 476467259497610794 724772824695729111
145107046521326908 529466881027168959 455262337948571194
356024192268034774 978001272015870819 585860538660336501
961586222124231953 453641756709281704 330764799357927225
38940060417972354 484204404860067246 648133508781390020
534313588276016113 342252238287156625 629766118274898971
254408915600001187 248262011057858812 24988357363623833
974821648102432705 150055661360305268 594318833245426542
314073802998930956 207953701620216377 212167086889948585
496659286467185704 749974051054867690 488219371578804177
57047588965984171 598871299421293007 182750913335878931
398626425320093950 876514874003071912 663263159279562663
244636323967352027 520629476932021807 244073559761998740
752630686621999824 639525745928409713 261870305929583320
34960398260819096 207761419412140222 927483461830749831
604029824568495100 805181666300004742 675985304123114935
5632939924801217 529311365782062801 247578920463277411
144326275313300309 281083835525408812 740036371074938623
145370859342255602 140754283540039441 773568942928343512
105347709719670104 688185972913092145 95097129609080992
475976171273887543 421812509349506607 889299080441655471
63625035496945832 583224158686520002 577202945153601542
124917757027166810 456886302415603470 159053081670209633
478898592932653523 259835549229943989 285101915226487179
67688596889524201 857417277368930734 689050974869825679
224081117251160635 113561950068412320 10719199189855062
160405234559330384 63483189395949065 32219135888477906
804986203262469757 977185206514274986 539832475707937579
492947803828197416 153482594316701055 212425964791749889
849110021300717484 917678285348574289 753827691544921031
849616426096135651 714391950435323899 540442730811743342
549051030197474380 390796960861302670 199626072023852358
517106693281748105 928684737267118112 421942997284508298
256816601020535835 118660758177863202 212414504776809718
769844534768656384 470269959464293082 869354211038423742
512202188886610806 884186523300691017 940705815191627842
927452203987865089 91462283369462163 517904756140122564
421980367911432592 315899683773556447 586038879529966099
82571969400166989 364832613007086846 606508716128921371
822445178237575890 451469065902624897 359963926776500945
176048557538485436 548388566517038592 187406115750382959
673256709429871042 451318730949988691 141300867270552965
492263637743835881 804118496076486545 649208915348756645
633402373328784762 995795326111795741 641941771762389851
866329929992408800 473456105399641771 35188146822777351
80352963729862515 59186500843458846 922210876207402499
899477924046559136 563295404900412221 149632315026867237
283927489366666291 996296430160611139 432872907521606877
626673446272179196 173934830346896355 79639045269326634
527668459257536679 202125414217178328 680818660830870144
402538392786894723 929724928638445515 874356519478905933
688612801731675269 335103963259763863 709748389983515602
141947088934429918 206306390271019301 111521557401897146
63561778223811683 174576941356407891 47687985880010048
593432615597328083 523836030121605632 276048876733348433
119304399895358838 601286537757127891 744874445026584637
381118950667468482 309343372348078676 867565637691447415
590011746645121141 131862797347372045 718170911157470957
896642222997070910 27142831945280391 851753153415350809
158773840126329040 506773100853137354 159587027350431708
448558689479940273 372304184555433103 985635039887568840
426723147317877219 110621281022586193 329393247436622769
534255698285022809 599550065668392585 352034143980421043
748393648844685454 809292074382392828 962818876311439641
704053560431250437 449675238992163642 599620010131619568
905402544982292443 868400225755312868 540303028471939816
760153827789618627 617022824694292400 76773722883617407
671777593438238884 167679741139192303 655551601665351247
611709786220594440 822697711092812160 580379966036319259
91572136729349346 434182580704825190 192766135523010932
93957428361260261 790427984687757987 175495404050358135
74500107249282427 753379627461630752 874157585327208227
989299854783789753 432042393325387372 5583096597652122
334050914160471287 661047671897275592 908025556707222094
806158784794266660 558214054216025544 42515722217352090
147152202385453857 308686792055456930 537326462297274598
181798401695588966 173593167837449800 832389871532364000
823884973970082556 602232811052593214 720617864555086793
893900372269420601 681229040626737382 391663310662764004
866701871719006468 761788963068408195 896153054914493976
536603769908471521 944228984737916700 35725334749785484
719222864724984612 489371138726153182 249120585542873504
600375216597782922 716998738623200286 381624307217503551
254856980263628010 677291881596328364 392585937173319078
359749292174867604 131313173657721764 667452184540715842
220035412653948003 724129250805412403 194603969064206589
423170398677636626 917847580555741172 154464300439368596
21605990780932553 835721482755947279 119017922472470678
43933627989160275 500954191789461262 630790502595967422
400668059839949487 802545441670311287 848455223275609391
392414733429953591 576653709467418962 667234394651922901
888146446360673959 879587077520137625 745957389225666792
730641953944327809 276726965030936143 570157591384754360
396740076819765613 61101807552755840 339468245838653938
525036303597553232 928031243949099281 692702458088226829
498759871765085397 858423645303403465 971804162003533526
929349608451676000 695429869846501943 433474343737137578
72968603879683286 930955027100135641 886152743770585023
756285481732110835 868033025624378080 653832787048037828
870993093118744586 538569046903959251 743909247765022986
541420823391040709 140057487017260340 965357735924832503
537372607599866384 859881903415044159 233852903455472454
736629571325500965 695956230229419493 177825662743981311
161068910933971641 200697981316183997 672545642246493222
636728394625667223 421621623741217535 207372818374119737
267840831470485178 798382409600983032 983667233064105210
986414234206336662 610882632804715567 472990711069621730
734864029784358285 700513439702930160 481028010901187135
445063197491251555 384618891549923313 586359882072850169
168819106785050724 400342323502847070 675983358648838267
177294986960707430 518594112870101586 914428067397495331
451861218018008782 367886334576087965 680570590180520536
889908950937150888 489104534950801569 278550721074263034
499961257714754579 581082795845277792 228450855779001356
10139742145880196 21500790096924351 616550415564226693
882640646330919454 290213648419102529 144693331301031913
184750691381219224 436299426379041112 50858950145903337
884520187132771763 800516322902769918 964979299903117368
572690180117483815 767308872043211132 134181701431312494
229334202162169772 220894464401899853 818576873643029094
949480665149546599 719220032635911572 970423375202282167
904165344380123052 166268574266663115 369121409040154424
118835780568943460 345658563155245925 12943220189218123
573270324746349562 429165618754113116 179312027387446442
758999893089893347 384275886164248441 500425535652844145
33108333471847286 99081020719862914 629437141402431401
332400308229889491 205398152946926115 495008701825515299
733564203559540734 284183911530998934 469170957912783863
115526339673626501 135144052219110280 616886340964824003
784806076836239673 699194539772648491 165026585353943094
308540442638633497 124526842247138581 414348113266316439
254146313770020871 986440679522249331 443843518304218120
519508276890074041 77255880410793880 965854675349030517
231802450855232104 751286645831809673 944807229868973195
250414771936979186 35084206128265926 196326593095037527
287022769420942370 886307178680592508 943852195797505901
906885003853414830 856687711845329333 807576770860804839
118094492933675943 572656956560524569 874454327326519849
830317311286905349 659429408845162669 366088053275793749
115125771038394972 808945342295594752 641469835644398244
13037248286464754 899449881277444285 883016539384022447
357202985423301316 291992327711870607 25152354387581907
484183497638534937 821492073981442449 109513873075785582
720117689586994379 908381341276051515 665098225918093714
946956453918805450 558394301768167980 220351917332920398
283214923093334477 219109708709223816 798182526224652818
631333300742606705 840863247558823983 127767096858760341
511820359870543067 43166882320071952 655225790232372249
112493035464128888 884856576765601688 124128553813722729
773776850757712102 45732247966335440 734256097602612869
932887675337358609 109338924477155437 892917988920189128
2866868105400227 493069317935789422 533377770356702552
255036587472053661 783260860544605455 714733017118264629
591826832181370357 51891947089144359 161039418832586672
234637408445989383 564430348084495961 207459247401570638
746472745326346648 125131483163416505 764606274929472300
158871463260493207 337886886685044876 578880951514992381
465743935719021553 317397363697330064 799929646125527176
981650971396451313 990986255357255107 689292231367744602
480326051929941562 550239764290571372 830026639976330627
971050421948279866 732298100263707006 532041322108800673
762359774961470131 655309576205160443 122070675621545879
384889611930519968 518302387461805156 172460060812918635
989361866638051757 288760976314879528 95888020892294921
148580241332695126 679535913026583309 396659979413806614
399354548858869352 254563396694308971 153337847884741693
814611301891978151 400439461195201447 163854551494309144
342405983291514515 401828234973911047 513424453249219052
282696016868019693 386022849491299014 781238550090206686
522616501212747016 411469632206735159 867614361828505414
753659155246697402 29645568924510161 304579714833917061
484642213916643061 445574300552742581 311063612370449063
171022098257681159 401313265566705509 522921181401681104
29285330794297893 981153269879690286 863939899774281640
7835098975776632 702731501630715208 749415361971863559
71721735623081610 532413722041122329 663893558786903121
506847350548101113 532473647203125541 393812122478629006
675641364753114851 296809684520612088 867805424167569786
899305498783949218 297625713650092773 568758467116629585
577679657509317828 655099501802191274 726601248985310182
183393407120499256 455952658614855890 26202551901144018
594350294732749022 671536845248086339 414688268517364165
407348973363719485 110935187814406676 179620898429665320
736056886563062829 322552711075919393 131644364878457986
603802220146948733 400382839704528659 36765793750758454
5728337602408446 988034220398692294 583985202472285069
696425700636926529 862285565687685485 966333563513495985
967596048056762131 882042225018859160 18276576726035831
594399813955656419 366262069539100175 69939968314300864
500455083011355384 490296719815632188 169502340008191589
70777542263760048 33689152292001142 941076048531286148
581950030628026872 144667608333963132 232609915235475401
441575889411008727 983954532389191955 798440404568401891
816535936248577288 867966301912739059 170069819690461085
9451567772375494 71009937680602471 994038333996194379
385138264436187910 892987432683059584 117981191080202738
625758837458848703 584871678697588601 520393381738436112
923435559395207452 849867869963777148 244037102772218373
521676916102378440 443949695625846292 292774337668584063
521831385240020400 869778730100563221 486637788113028960
846229923534674266 270821535411467572 544426859320370543
660432114020183172 716270869857245729 407153750633650811
946455129689671913 22806787706546660 897959499968584168
248440838229301510 984025095814170966 984113294130621912
119160858461187360 907105654999354265 169667246892265041
202868734125164793 253681138719036864 147079613693352032
400941189856744430 730667539474705223 189950447247636265
784551112110162601 862953458523284999 216182488887079017
455747363932151373 353636411035317312 628520117598203399
429827317143203322 800743836169455225 961535008734369734
82848749417079401 686351696152173650 180714341161514031
357058642676641192 856996180348236521 897227167539964479
994423080179852479 545312650054721913 753691256073288314
783080405580327792 347980800466817109 137539441685940163
855911413297260565 578681712619730903 128223786625445986
540304290503215206 580621221718093142 696664405551496721
403131739412682308 270530982299670871 616809592948794854
189566537087996306 963114164104939766 915742758987684097
426566962543641331 497395112321046670 339305663474734809
72941219800700356 194859501523576541 878425454996821165
444421710307419167 386188149901455366 459399608389544620
283685361067551006 201000222102982737 550063833745096601
711981600271793426 292819774080565472 601348951968667347
215333355412110647 824272263303869513 793615511850481030
599810236246608692 706508317837661949 976166015896817104
465062726537811799 36068303021779871 351251800756684514
691504183784499519 325007719880665994 407200357850612636
349955130634811683 842020343331000972 637707554292906764
524091008061316683 194924550185681631 554251782055025828
739417253711753404 338917756919302400 297204639591868542
913280566192901099 945218624051480626 216793604905756110
34259571714520118 624902056188219585 116449975588965378
405280823626550776 869806826875952304 360787989681541618
659983340181677153 471761706649191537 146773916490201917
413836667465877309 255766103219942783 51263320890161258
776909165919605418 712134531174474709 68204836303343164
908844168366299073 958340001823614324 224214173463662819
734995838362773114 284084097414820225 230696580912782482
834067899865298938 122396332356857285 228364522270599283
331757965640596916 596551131279941060 514022090373917096
584182579105953178 74363131086156264 878659963139050543
278619153133003850 623431106281536158 182780875705572359
977607445899726135 646693845233281753 477931139995149418
496535528242184007 844037038433940822 861172404483562544
848663605475302788 438924714331092399 609623345998527959
117810485919794985 763951508228772034 713425775319103138
207828346494218148 29332457755334983 272103332100438941
23167297686089029 622262830625561980 84638526465203453
192259615014539470 474435122633826083 565933564621303444
12045657923700862 340242142233340603 73855164159140502
605113087325403439 736787943079205873 986768305951165950
394521110705775935 813892288814771424 169649932051271703
649040496112319456 673911789164659373 467804468054084942
857722661384082652 525894766488229101 230155235211848355
926494399934586776 865230937089166157 465608172138141645
51239159469806949 923766744009722330 705699157281777017
170961506261358124 526539908773123722 106147547179073458
185603212278763655 375907433466616210 781470569842793550
882310940461563470 709311868104590037 301596825489941530
369065578775260055 623587891597468266 94089946971614807
557190581754870980 441407667048746017 833395037038134991
105738201489687384 55206312806053326 381508108611892036
368566643725972208 929058808741593797 922968781655343977
420664668623191604 804452530086402373 699299134600569013
404003910722576891 893231022510029984 389129825921295833
855688006189381390 101587091393514710 779835747439708952
464427391164619969 568319444423935950 773253280547996810
30364469780217282 54895688415889610 250656954684428221
43279746802099600 441433511656970911 345015035003500968
996124023162218688 434413150558168119 570180449037030085
492691402602970259 801083192240527220 678828808128541668
367155577848342932 100570886176573175 725592953850648268
584980258535875743 574998237711873044 661020484862470287
683233461364865406 827116800293932348 852217478993086308
614424644901800213 126873766361966746 91944410116033282
176643173258667559 183366802791123465 452147757656752136
87453431060324136 660532408047077637 989784019009934588
40939786337831567 826684012854983617 791281851092398706
272790971310738575 192923560471766451 460224644972920401
479279939828786145 688523913930474022 602882820360801721
582066239332446432 405088731755585183 920585065588047347
409927256785374645 405865776808772467 117232041249212952
306219583771163515 805757068078319154 223582108088351416
385371357896754818 116603998921605167 621028677825652644
8396217897184873 316237161551253317 311782252838468850
691276748208363469 374609724723391864 665154054155738271
567131720612693512 770403854924148815 330097988824349277
988654225581808315 252772844390408749 165805642010664930
447702568861397490 873168313319868870 14503649847249590
130201592306465677 189890200980657522 67420021593743806
801870027190050144 973509317617538025 513174896458259906
431689205644426096 689370436830099155 514036491508618161
416484938407804400 158154188417750813 592882637021666608
128698177862037022 848753635281515998 946717507465343675
698627742761958050 879417493064277405 536415181112292484
400261652613902486 713502726610364322 983063762967917072
111771180869569177 48944598550007266 645738672545220026
159375902474399599 691792118916607245 678436350145325327
5665549715958244 417743623794080866 86045782635808633
626915191808317553 104637559014495995 68898795212611727
174540806014607025 385764333682839733 117517557668497512
735109110007550755 351104886156051259 958543893253118787
506117279954963575 837943145772112266 361299854534104012
744514172057918707 418227927172509412 105162134285989265
726389756203995108 917915458774756444 797020569015366519
943956809315017790 927336152283183632 674233876195653749
959001642507755609 558668291523292193 308690206495345341
878631094642972830 913488358917127122 544365637192364643
619476509837792049 756471576344053479 962553436815071370
226901465662237767 678826124970324954 923479274624292796
664474252446882974 882200980690018526 278692064170275401
495561915397621211 757061829939533899 597090648319092891
614692057027128289 603030512471643201 50338743596072173
24573423872327728 301169122365751438 564877754965866563
97053363398274509 113307984433186900 348671515073527658
238487946256535946 378533717521015091 356056258985057433
635823607991647307 155836083379699017 278982353637512973
223238634896890715 854242108075473899 25323934139937969
603694516363385746 454062809845754980 69719943307959933
741064782629796764 449843344907508126 123832740126267193
306784985645586999 264508140544007933 633601926044007742
995550827889273282 141437507544122785 236009474078360393
630866187780974131 457336638949813949 672301185309880930
363904584632828684 587166812570593928 36852167514469414
68992853832144742 185611880000740738 330395137810278625
25425316825981418 641724343543204798 125305538140812490
532486172501699359 402664332761980984 753795786939977929
834036659143285956 859594060433397978 669157341891415580
608622549020896486 777098588873554248 584680716480018919
759296936069367789 477685812422989298 640182348925988046
103792327809386683 113716503377575383 779156227380538283
767062981467051747 66574743992882434 217546946941508189
631000638443340374 969998325510218406 220799907308336691
298446395721873640 245397325429554467 443307263963211069
761818930169761243 575026188810431501 29656318498928820
789448890703301755 396971819234155094 932712197475587161
286166893931365797 36506671495601465 595899544044886296
888721492779026081 227969146584068870 583972138731930068
967408538114652512 420130124638421636 114810428000118986
555929745891649764 822716417261723287 982436721219418372
646304335006995057 67169347182146407 99850941114675929
56640767272198888 503009938087582042 953982541085717408
876882989988448644 734490650733061985 861851496396910448
729282197860121404 492901627026395529 799560464325431899
771505892858571126 463910384571365906 708325186483689527
382702701598481188 290622615821658553 953135583161281663
143886020402404210 911749210869562086 645606501635381870
243810003229289568 176517913332437763 986938238115461188
359789289917146040 674718373450277341 506575431757571027
737811195549428953 538551803841290934 967270866397469418
235337574477796068 836579164310419779 170006328987473579
339864622195773765 112177475589685688 203507589211615368
587126126164747367 874128445906711551 715275921717707303
195699594594460738 359360768871088506 913084975806744152
177475192637101204 761567575970134736 324155394549953714
490050968959201202 274849634972722380 769757185897645434
48805254520287431 808608834423125836 370182600109849235
712669117406471744 934620158412228778 503864193328903626
523646388194720184 37285206596696971 802728288947526984
665537141629892181 448154284223120902 991668604186296345
947992946520090848 905554346781536164 916848917464849869
14430317292805432 2525248761386364 353353494827161715
700789293907971462 120458230683394937 523956943363059651
628546094026274055 329614821030219580 193940380612124697
569849135704857534 162582414013331587 609631389103335146
307646510447520744 57201941551337430 159834748775767191
605535582826656166 617000815363330369 185415258288490893
729083904687918591 316132253826271206 249340015873567442
526828883266846921 489611277311556361 558126308670943160
615322371427179058 645589775259386487 180667246642410007
721734377857294181 614894009469521452 826152933075884772
364468351822467093 643143823469826030 119222087755569532
258815074990362707 785468913639063315 874402755985923982
708003577300080925 508506319621287304 331509993337881785
456941342308287517 94420967495723756 124571143004199982
698014507916320938 315603880883654075 950987720717136913
108569601464110961 18390688711555888 84299087443196220
676174427832219541 90967694506360421 50481886038369187
32969655066677922 148558276080876732 211195582269484698
333170206066401011 297376399329863578 141719344647734715
134397101372706443 513517638838060573 563769213596125715
613512043015050759 523206896686391341 796139317356197062
420690097908785844 499305380593142004 16394535554102125
605868353421182850 271785145215046469 415419167859210268
73095084095598760 744986533518551716 47985326346709328
351873640308306436 389042929631441713 306886151948154984
81611622931751062 116548251050983533 766716857621656508
450170739367094215 357125228956726646 531848055626202876
374718490830015153 81284967008454571 431391443529957803
801881351142904929 46811866461887662 724388225243270259
330044731885194029 315798118707894211 556624480619995497
538369511743885664 445483972141142962 111493656763278539
271882638320292634 432380921373707963 990454764941696803
206684385595995402 812425510378873088 702675992664394221
207846800703300550 290066844687101552 77955516022259202
997665181118810145 671871424920092838 677002533984255476
242706639149104910 552421320317292714 858617822654104640
444721603176677889 383741665133595045 651201968465264545
829919416150786757 61564754331698406 7718468001387112
564856387074598974 250445584006708434 483915595839735668
761222259670068092 769164249028986749 278887173552920019
968377965527145325 966329373302203189 949973033129133708
836896854320306802 673335876689956355 261178914165977680
718443050595650890 945349951952426831 352362432829268573
740336862184520395 720467229383713986 88950911958875974
253998436748024862 905469687109391892 887014076870142398
57462186084852237 642036909949131210 524477172094989258
521047095138504511 123356776272278207 776698025672507256
202451070569957382 944129832753557736 297429480539790885
386002696272359692 182500018728798732 95436950501438883
659680930839851390 229654401787583750 942438678554739366
286143248300868100 942840679621775578 319110483522721473
454821743564810934 808991969396914905 591159459292560771
895300293726077195 804897250166888878 431125800337364901
668615707108469938 713804608083019945 206437753327191073
174052900161291527 131588604285873640 295358165035698714
706399922218473335 327400183202455946 507518000593527790
705549449451476453 397293202971561357 861100968893906730
513928818033095002 389161506280245805 40230549201838747
225568773226048610 490971419252978902 133040369392287969
391013920281620758 31723768014463730 377885267353660000
341590735536052575 940690104983168329 133541573519615877
605407080423724858 336416956705669000 77600744273039393
117251364274283293 983066951087313011 276121685351651981
684799078454965560 959361482159778880 512265991343557632
48043015807537906 593178251187788822 240772911888413023
341680674339363467 727196888257399365 368661565266852250
182047639953515678 748419429714361573 667881734773988558
726840275286383864 146943687052998496 856535200158871030
375386810238847154 306893067067850099 144100383788942882
839678992035683293 334277254158357600 752495259094271163
463508140264089334 731312455693310590 390152682826810654
242166987131005290 557222427586234357 997636213875762638
25911300792329622 463875861104777618 688492250907663837
38428599397659808 306869298666609701 387591509580789049
988797324524036720 394158290416966369 619355638503100826
578840213063407853 68694270439564049 25970507030002737
942178377882347400 23800924994631696 913645180598394672
602741818220924536 73021138003721949 876424766932731784
995728830852298445 72484419349499479 644512715180554292
790032100144032012 486201654790240049 148770994537498894
523377863473742169 798263897277375128 147604267617569507
932318524879262948 168808869560974142 762074530431196211
501865366617587455 519916040847724819 739142946399406483
482838011687651622 792268580858755532 640721645491956921
893308934588323323 34079672132474349 488263037243691764
90269455824014631 264451615022111396 143931239723284091
427132848431383989 650106108551840922 781619918918761613
780068530396480740 378612048865260427 452105694325987492
957785760858699342 770967511804325837 676167374979659423
54293127034034338 695452245756334661 926173253334874344
207585412129457241 5201946441909309 266671043534517626
231351942147392403 80776511268642760 695591474394022417
223216926428608958 57469333559571242 787884814498716744
63469417419974127 829282555537545318 88442304972691867
29424940078346179 721976420354115453 652063056616678582
505132102538065397 917932828188251513 656991338191186130
351987315296573051 112685073613734615 828092723876118605
932896559634410680 457368656686539869 807048127968318703
926267614215052634 736502212506021500 618944348961245573
963429729607336635 264654639010527486 432828949831173367
534699204697851012 682586113730349361 884094202080376410
663544352921960743 933518952295055972 2584757803562987
142412398269047330 258508155139484705 965039482362416877
302774311178319701 315443347590916935 972948315505825393
354775874922745789 971921683874441150 995176236024721070
485882358112104914 342404402787369901 473821171121309660
858305189059740090 664979612032130925 602643768740771135
324067870657080088 238526521930697913 464392046715981471
861727617725971754 333588670516084801 57115561420518762
713634698083789645 894138046747071711 572941353687787509
552739945020397959 818352240558529646 99287426503014668
261997342551857961 381384094322432323 149615191118500496
472100742839213044 880200794970268069 157878165064135101
395859135617050192 570429960971216952 480591256192178309
381845252808484743 559314817264731893 713013559672574716
70838836622706881 60110650686030113 383752616567699636
120334395262566090 82484195094384008 163363693981208986
943166886519530352 560702535338864064 162029411547892479
292703962413175513 726995022734717220 507304707759965240
846579293205787797 808040308089950271 416961265795628113
595664809724074815 561462188535374720 553391534823792942
457951593485061772 630891638861619993 708821138439699803
292805959056323436 789651473958924043 431058015288055233
448982075266411150 766730375370384829 695967412961394948
355318673317853526 759894985453296845 263495459066081874
868878137098334803 793164591550821061 99104593972979125
574496401451673935 651272330208492007 555806098120108059
700562239049440537 245927318504728118 472586425790453684
681387256096592901 537854035374783439 183673263650137030
778640472986725794 724876859678819411 500825033784435676
834801866990768836 573516552406372526 553909949681712433
585085501744622237 122058416908239868 197247244299252499
401159332728822298 479463087477378524 93840717134567681
298769542033456609 681524505342999402 877456639890103155
920286658706019232 523490058594965355 95910895131652333
672932553659260889 962325458623309909 420531670313826787
722630586750678137 823882458697409704 343667349097767134
39140052562090436 340596861986255943 165321508250959593
395285392734031502 380659742195522679 473014434922261891
480763372907834837 661809656264953103 259972971807219351
967008105966261974 355443579713128751 107898820445754546
159617601821543084 707889396375526095 258816113827528672
766831012206599402 974325610115989390 327231157545116299
636951764645176898 62442147298791156 936483597306201820
542996919349211135 519653147129304286 6813876990511177
862609341394590613 857660044825938082 300734207905765061
611752909222210797 881900826713784453 541191415742771173
746722527838971950 427223280979905103 309434421085955798
898954358650679700 232360403263882446 632978225365715295
604476421450556541 938522220675562637 525132318458152562
130350100728377695 762237086726535873 426086441664761095
163300260304327566 143317937597364805 448256405610785992
360481369450850129 743517829718842763 854503386927279909
742889043752953352 531603683724943871 564207040528248701
556243625490391267 209864248863518915 375045092691312833
77185346679786630 414238162451884169 147983454413962381
618747728520928940 742999739442749018 478913390681700816
531359634036045030 67539396878182593 660516586284774344
385144122849740198 98870562349868941 78778126346201220
102138789700177712 820949602820304068 138743232977779471
159247785064947294 300017938910659829 275819449278710251
162775839859914079 680595990090181683 272424457642076713
706288978436267195 27570547012014653 572989332383715301
747684743420220130 756193634755443699 797062988694890947
845677491915386292 338817194457260238 686818226588416014
707170330886219467 239039060755704558 753682028711322022
445929113144165809 353497271276768669 424726831606061122
731363996469902802 52003482981124149 429640489639187008
783513252296535136 933534415129900724 230727877094847540
659513389918371615 984116494172229198 491555953672484155
867123812684071416 30639484162534250 610789630652706868
460977080160331916 434982527082852339 997820955682439595
926373969158404499 88538665476846665 709607101314979171
345879436924294732 942958214780142032 862069320487710502
770516265361998992 686990310279892475 861793413526838005
11023215370072430 368461453398867372 452373454748980289
300487696670534608 11197635489510286 671653438187106541
132433561072640509 816536906907720372 676936712372501613
610197266470998372 756773407161635800 268905252905781235
205907630442438690 527354308328306485 608853639620546772
92966062139545673 519042770650467910 131987893467107915
121420552841068745 159223338949037920 235552976941265031
169898714151496894 574797792090673900 60024738922256688
193777972673740134 864806689683133496 70339003552852572
856919943427965337 604981440137480769 295910957684266496
746057645630291701 213227634317498543 311192857075129084
363287354027402341 541780216084463762 172456745938985329
645202655150046095 82699405235145959 666534101909293873
914702175419769204 463224774291115674 256943131881130177
722928525907205990 799433640969072611 723413271039721449
563250531602545561 924084497904955785 914747004918441719
373508690551298324 178441231796182051 148819554721622414
507333478910499934 391229548751565794 298617151249088538
262425351412051484 741617554567915321 552868462844573387
285061510331554165 280097363832540734 233432967887832315
570033581303852790 309066744394190264 96228635266021709
451935960334238315 323678312600135294 95221270665775752
55072390999488214 317895624707219885 416527655801278221
147250081939584023 50049432906135827 836774203191931050
782591286109748240 431284442828596145 919314347609341817
474589672846782364 930457765238615448 135494077347690042
458346496610519346 272305793603913648 463275284593912458
668894645134191253 332929321091848085 439247848058786108
470127706293185362 612451079187894357 344238372703420595
147283259917347470 617175732199609420 720702928934422026
999083495421989316 960693894545202751 288508875690311732
51001195835836384 120901511419625938 660648404648532384
486371637683100380 599244709501816357 617380400990942198
907833514032165761 972239929575689074 960628983988222888
673272398069320217 393404378675413602 189950909918375703
700670592199433297 129917867169793865 93714863736095544
25304629465310068 645528525967930276 260336995401056843
175255919743061933 415939397509194008 43854867702242090
128696392386373661 74387369697518806 28158848263497216
855301791557316874 963437172616679027 890388337467570569
385615824458526756 91063864265381502 546798780341245473
18689865085756671 682873309803431939 787818275874733656
615703225762012617 14345352035243326 86260197473721057
762673651550522240 381139441839162423 391174187119564193
106284819876717995 326507223924588380 879612092137585379
680969958185051481 552014995964243742 584966345799334008
383564630675515518 59817922282479092 176548248183509627
30080497555603713 253186731100986235 140146937842952633
226640061014464999 270647492021316881 633043959919397992
75906433968212566 597580805104970007 677830629197302145
496546008231719057 910485257910808398 119062223029761955
186636079398427173 334745131318746253 658611147514125441
67432044254403463 957280582741469295 860658214047282808
291692038929195135 545091625352307667 737316025041330644
349721499753707729 487399072127785816 70825675135812347
399828547578889837 582622515165398192 630251532149363914
736498558952147294 412690524822815852 106254106477601548
623476634250948569 934480663648007570 503460594771500546
157754268467028231 636693605459800652 574939536863911842
290875561068131752 144183002492843276 962558646128835053
595022271048155396 1288959365365856 503339418345563962
882402703787317238 604496182200262714 964937616067651137
118253021641213957 280865237059637269 458570243795877199
930912307680015655 2094363656136367 998429569261122287
869752357471678568 174444677394047764 8111572642977753
399216029130377372 398938660789213234 161370689735336139
821747642632866811 437279669985135380 703965547159951479
127103046399310910 203293102708078025 330405972390179041
811887165588596890 110330380497441558 108626151094993123
421959836394538866 171864637269619211 741583439159366963
527785893503260725 347447250258042281 136093025201864401
808421127591597845 319457963009113209 612041675258904166
987113145161562109 99617642380080266 980897499193830085
780855293972216554 533251564658881613 971536511044698888
232142155030352642 279849013109228923 468522219920430707
387723403825288245 840461387777597042 566739271120362443
472019268547607501 311701146835961966 73520763182024217
958427531962515847 250670617600195267 296383752065872197
516666399880296805 10857318481611469 190890130907853138
293067784454767629 762448437191496838 742982577015060139
952410636191933324 651864377375628342 53308717995321096
220104181826836899 853498004991699484 738938313097580017
647764865012124237 169709958473930797 13742857685610671
423785474116798624 946550031346698253 34208788817867067
526029261128320157 214569471009622367 340803144621428933
881090727619041458 866805384315499330 931713370312990062
470132193924268639 957191313387381206 401924370158221462
86483263523058901 877793952275578492 527445649364711929
125589537736408486 665342281637512381 331725465588928805
223855949186167520 132098972768036618 794728840447719965
72904130588747570 374925789101579565 592510383591273328
503797981537188861 14302778230707413 868486240748843786
744293210899819053 414106061089848884 792095369033493503
691769249700909721 144409783848769931 456483322017031115
472623420100829973 766077328998746197 270885241945023870
865507296306016616 194180257726663475 547942569356372425
801294352746653197 439543558704910342 469940081308686040
475538515959726067 860928269218584004 911817730022563647
717343076673957966 690985941406007718 205328072958988369
588337083928598503 400303043832307778 892933927604084303
921100107833579 581332922371292797 895236058005931051
786260277365004344 84835764449059056 369232402543928767
376401299629233357 262392441191001901 540944833491101251
977843549593993501 200277492242365641 254707955230055125
329499392139854298 901641830523340603 933488432226221855
78625684973131121 676546553560403513 732032060491719798
365879702092197251 288475689873454617 309933516328209943
492507317650062657 70903045579550499 456070268456999777
290852138746108563 15597858226995449 667035373080221406
569661783175243218 328927425627087366 639555233385057273
253185362145675784 14115443407667809 418975027618297417
70256884010228339 562908536276055721 193409553300260112
566086336656763726 979664741706615492 607822217806371384
571630463162258235 191121425310205343 335452303293962225
942643501496655412 400933104371790919 202727633535672168
535310713188855247 64540443260761609 839047770344491948
196478006096929537 590960204186712783 52361590227421851
512980424440231521 932641546910735996 993254745021225308
759149724336229959 172262223582368565 651791577205042533
88820201988010932 359709338395664911 412275115679810108
605403519306019242 786605437729674329 648555106462367326
334588285330036552 546739944285981169 367982761561768181
566981219300856267 442196696084208713 826062346245904467
862817688617149567 658548918266520555 193469368316991664
124504164668738030 449630692942532017 613163361610869779
871116127176673074 774375300389152430 919604212145493035
882118650396921954 722436308027430630 150299285960455472
42708868611521239 409926170718932118 102761955246553129
684949599425699635 897464016458233899 626181857130254137
553298666306531110 621668885067577485 223080292624498589
187576351514303473 833647596380961389 155832987840809340
272590864869363814 836693622960553515 419878365333424457
79734488882161955 344721941495501735 591217077774470025
910202268706849383 559117550170138674 725365801798060836
576740538292205132 9265100224027203 250077624273898301
787007959907667911 461951813672513530 993817330475579836
428185352565675350 945938168587034599 454191110429776849
123881369392018549 580770620746031736 688237481292267037
966639234854113584 398943155748589413 245059812490596892
486259136987307880 777982754455563849 739425779111499624
161618290202591653 16458395771513342 792032542138628691
323128001688782736 779197946518083316 403821425936466853
233909309793359986 22108348535799778 845367617638177502
297926243173085215 199183321322064325 259286540355881891
418842706928329624 967690281232465877 348246159236235343
492456112214423544 728530477373886315 777285370831277635
603437310701060401 920049682264767053 18525878993473275
322789649203040373 897694302470313778 818461815355959020
871006736079044591 920800994150839185 768052885901415788
756633964876167032 411690329762174809 218086737237035853
506595378846722452 122855208648745310 470582842896817213
658763604671631474 537875022664040104 450163728366451796
617196136558391829 869929033397055319 64028117104095049
919652366013380868 206551179314115425 687404890457138800
939989989224302666 622826444740093780 713389274951506937
550654607141795016 164004814550047548 485635761543580923
453002949795546035 126623433006782577 72619506972582124
875340537285987358 370763808895068392 702275873736940830
462483731027700688 520815168630413708 38306386203888337
613450322104466065 870285017180842628 222825756408054677
278001803558982697 893903905066320671 10170828365462132
185324145586407494 863009011767137673 728890770534212142
585859762692147750 647241559600512002 180968108401168409
811027448847313592 939304112100166640 734419512573526002
90409245822472174 439409507417601500 328296497072896072
470866194019453111 711014141014054540 717987685768634449
248049269912269985 67442445565105500 625986297777274247
12170999746875523 120830087460370525 300026010574863635
556604091144667867 724738060742834071 418672879471067237
217067467460522569 776027095651590586 468691811503343370
705537364285304263 585001874029989390 526792607175432724
977825563895924590 402258302644468438 163281663468047986
603628975603334684 890778498484054467 628598476866135618
582993337785437463 833276836169594805 555725238957105128
252480721242787273 478095373363912105 177721459655658242
329659892588241671 796339128845342857 453918814788582518
623739018677496018 395692424144898584 879512220384375197
108147101982936275 610928940339106082 100362689875898489
857928693064536714 834573945931704230 175686665194243497
597711323355556943 932811526586277337 458773564022356474
162520264003341392 395045978182931730 149904237433063808
207289603987665760 116962706917507520 96768240252656139
413181543115479388 706084042348643464 187008122060307391
814262735839045868 837374425987459539 83500893161827755
343554625456454612 764365844874044455 248894232242309686
363827299145014552 258368272074158532 423191498099026311
448954114832901954 49440281496788408 583504046167166456
573300654529128628 515738889015330232 614372820282824067
550905033242665997 470362587792066954 9484402494868674
676430465127306246 658886341810281828 851384204731130605
870993782833881212 133156260680495344 692002377525509000
802646685384281220 518280496144415327 102511281258932911
402375482790837100 66815830278831711 111897812977447849
353425593906029645 254446191537593530 452003265980190717
43667192253490092 696836679445356938 832652204559783923
161130072428880487 237328483672027995 153681779848437184
843909868283547520 538211515770783725 306646226567404602
416455882025363710 6133743184112539 516371549172639457
993858935562062480 258506711561289953 159142048072268856
175789962542954882 59848914104808288 24413406116300463
217484786315445649 869456157136139869 127998085623660699
113168770175524294 419922221458041411 577628897757646370
53275244788623032 537504016549612312 234663491343685894
93031644223350891 4952713550761493 178796507296188011
729894246102725140 206914379865048715 839648879332914084
729440151009763269 189427642301005888 476050844525955110
466771304183414728 515350380827533132 946021385666761525
113534829590523430 910661085176056452 401175223872344119
97086664933311964 128553973846776247 96656272693130808
976544612712550225 290962099498512585 294517225397748448
387325759056611911 194248004118456708 87335765814406355
981960868046822794 897153337100339777 496352678639064904
354517435373146315 909552943268477461 628707383939169079
850947056699060023 693214683776948553 878688046491397403
729650765070792375 719221314847570723 463711631894960933
633816633222979975 902235057596172922 884570133184759485
736849316995011608 469971987614830106 756654209234281938
895773197863275399 182993396310103465 38493325826302125
601331674953815869 516101654140016459 300832708046311409
402421127318883514 329380869597937398 489860802629796535
481983119268228080 240197031938746796 438239723496116580
894507457685206983 36830084420974095 368814851686031792
579787337007589800 783142324839778384 934034547552082117
374723206507818975 197671298744691727 918346697957987433
663587427089376994 299950131699330817 249221062993885360
741339295552717066 620066389172303417 204998986893031403
580262099454275000 403407383276027529 822308484292119070
303252713193705454 469474654638897680 829405357586177792
204696264530644405 196817134958782357 181631342007238636
458252166217481445 601103741639958194 935936898919934194
749592440861165330 619308106781143419 978049085502040002
537286355556488726 840925634602310500 877480324019047137
248241202591807424 856125477365126194 64854881202533644
37921704701140018 832351803291655096 291101246387752156
654059606500670263 731009295586536472 774505782536889188
336305519087223106 324997802209321846 251082262956679707
772679955909894696 343424488535677743 752965255464215232
123221083058415378 306281031191104519 547124496137267517
78827574001189843 790420493951672281 892575585493169196
317030154652713256 399238890614508992 825411659063670714
992850733075307326 764499696264393316 272121207932336746
41320913261017849 886515262883728890 745707891166628003
39644424433073419 956352222056464717 235741739785737140
730336987492474442 286735026690169027 285661270103631960
996279200441429216 532214197209808605 780532689296443110
722270991480577595 77197215578661232 737543239888329128
744161991385116082 791866267945171972 98207712338009979
295746936844977187 399827277716743854 779529906012565563
490755342156425643 744697094455004300 343555229201306947
777848854754195800 934785723056215471 136252023865809966
185034897537256727 190330585799307334 789432958612757214
806067925674158644 430014356507003069 92696508386832540
498242178609593816 147159514340847630 130766788568841866
927273461442788564 920378127610003749 635006423739772595
987991555573762687 539165415630688916 816491885913547587
424849073635891893 806035276677788284 435629113041797237
515220165596252969 576868445308201717 166479022589632830
483676646919368500 100417746826058209 232667034349059468
237296527327963866 350578259417911310 856162137964789055
234717234760625799 940604791022176116 998918260464114532
122471559922160198 587176656787324465 220403458994134419
175346314168590104 411814602276804533 138307054915536830
365001409893588154 673212684590325052 384392036512428135
415487322464503707 711979053678733267 728956832862222931
756043058030900746 619543530114658843 212737040878735322
542649091547331597 52513394283961184 572101278901967340
224863265074028063 856203207681497014 86680375267073790
529299750801942140 876969849561034491 80349330168041608
530802501244145048 757024057634019996 344164589724884006
589061675507885691 883493621375472796 63905324412611301
313516012921632612 676722250065368197 794044405708334255
579174870338069579 973321996636509405 665857902240292651
630165895932011565 46524363109917342 446426109920454066
202499484713906968 369746299139593980 373330679505035901
737202338709197684 947757360196318772 462386494058225218
146133271755310519 583233482663860379 112467214719010924
718095627652016067 343431966636267112 85879758819671656
229348103858773611 789074069527489422 494418334374724235
715945197503873729 93580386217595021 489410898592657692
187061878226372973 715579101153825832 511640800348875744
54726554174580124 376977008277763704 938404558822445135
797592514505430185 248652196044096173 124205637669186414
109778193286124112 295260394667653343 574375767873684659
952892253937040156 409116105141031281 304113938169795236
25301568300003688 268082018522239918 594796186172903299
544354456738527968 462215123054931546 993715158236395856
687619684508702581 631413901465324448 711039388224087926
109106814611542165 986293925601676231 285080998587028140
354493914977420650 814748530921882895 744699840850170888
210519095708120140 469465716914763752 161084724013629537
219226071609498702 966710613800909295 887386819927896551
753676430165271414 685440062137736336 249211583974585995
663242915558092739 160851827177045769 734157658170661163
90865721604266546 131914515745888131 366718530654266579
623776361638242856 985646453701533876 769689194096080304
196694912982482267 877689589515345334 623444025281640412
583534580186687458 335763799060874825 122443024614997069
818357078469296619 213715146245510950 776878203789591823
776149663488687960 143083407646879749 613211102076245687
687805150231202109 524268214056589169 407535175626697937
486451751061688927 141829906986450723 471804260887937817
673197560693610216 17359275420896488 408310620523713102
282030387543536942 191615888807168862 622593928757456594
893310678944407529 685046156680186704 754008572894707759
582051779162530962 324368872589375841 791766552837772413
387620360090595028 235792217574853960 843989053267785437
797098571826063233 291305568121212585 43378044780525843
241201991803885984 593981541440342405 635758425265217434
215197803436865463 895035709766581955 321226358601131138
796154142842651761 21630055370307330 138273879134134643
169441886830808512 932086158086565231 333049524753805660
794374741213130147 166592650407009377 290061894995514063
119100808644734014 420205719126991475 563242310680252364
723389129330982715 126707365961090739 593840855512532156
273697455416706653 978159335240133215 910845367456536550
853436721042956689 782026238252434337 632795858047198016
586823073043062150 142358252265250972 739897846075426576
236355196129528564 299992834441640532 146107996240701160
373338667792986723 78606265868885741 626738481029055674
832052310800632075 986561098826055737 73455635864032165
791668844283700522 956701479496666600 296934727626771077
313269787680472831 125907714599158942 546095948018860293
7223850208895223 215543916483089101 885663097868553027
900597816595322153 321731954320076723 639823699900786521
931444408697597615 403167357837825736 317086873588594065
489132557149984240 753587603943395506 398515121374424732
127008146094475990 944412357431534408 222276135161032102
199239262350701550 584788482733160333 18002008743901686
1997811366517476 771050612055297882 272754218482981407
147604345492419883 540880471833957750 210354876892622124
498007852189752768 436108479931546346 872860899223740530
471368835583590359 839818474841604343 974233589179000513
82723506134807403 731239703058731660 816455989677960239
669208529270146084 167320921095338282 482292812013611945
952833348154415123 479539600358856960 276921362854092284
635438940363046739 414562958304216111 429152899100098615
292226811866197564 371179436414054848 491735194739178847
587087552543347735 509351045966185704 623979891549121027
559569465045857349 382507891539847411 134731996586543614
640521581097382982 593182257321174007 763396275787077506
856789250255667499 369122519125619809 722157137940318278
611585879421704059 191816584427415568 606552746422626445
833997683242428918 975455903961949440 288975902575590268
383906375784765 78786125010883603 388587212346049867
577693603220629314 638149908999916602 337309559522208097
497018499771894753 441345876361799566 512488707929693560
186456796815550046 187495748524052424 984475292545236050
385771021967109751 352266813700217606 27352375981468308
980441186884353056 664041691952838780 658701633678796080
23669561830766310 727604632035686106 801036335809868603
275219781693979459 936170950916628241 63465686616631287
373550421208664867 119144423628441240 397040879597648722
433539602801572152 677743777289644022 304274841815941267
932526094844499225 890544373599814503 405436179373961189
938269946541211346 729646565043947809 738825474828537695
749006817589358033 274964111578443668 213476428342393031
327981667600034982 286668486139790775 370138920143819918
626969861672247163 181033481544135004 593584280754085184
788048440535279075 332418931444376455 281894931569622889
682908075318148073 313793968010219749 277279019331827803
627637917804866332 402612444484359596 671545701562156651
256424512759419165 825062092948550015 547841996061156734
473198359875197294 570389699215123249 630006141277847298
173644766919792579 777353371643227499 624134486329145492
732096516408428014 221597893858854101 291419432108619013
587666582680113815 814193863878059209 9604370376883066
641157327413149794 754608772796374060 631753034322599167
163971606392806272 467866895259196365 415437693343181951
988707097854155094 323998309604147216 645012886260383250
871536136354077040 204949568820249684 582976234548886097
478187125074659111 169286445344348680 464159508541763287
472612110509366250 977224189180989050 536345742382348575
980055785693103777 693654573075992943 97616910934688163
238125091740899231 512670016464903360 8735248726248660
543246876545716940 977845289473047559 647939812844797979
894211023575988007 956619780037988276 999692683211564973
840438180744246663 624637380612930317 730277829592783299
451147523473466601 761525553562862799 616993759309165740
735486682533345696 745978376244570290 8809369484638835
734118315811903264 526845629930406515 751290221692038591
622113251938584825 246608793066356013 732526874449240504
845940164618126172 692639037454552699 520567120040913201
130848141856101841 449180127978940330 972750577817318198
825435831081781201 768451580637820013 132950454925144658
952487365227108331 758553671718191691 547875705434325242
926036331772907258 237810677357024373 70743717674213674
868578487719334750 668420877737297820 388340541353903678
697178908367650471 360320046547193396 681968515830210372
340596561184648905 270557677264947504 428803759938086269
77186689471429736 878367482112860716 240771986752607705
55598526664750348 804087614729823082 50038134917367191
290021030149718780 455652429258827515 446352375969923367
14891274298121654 107852361720326813 676271522906090060
552441450231989616 241113370016345451 886437747632350456
447323117869611338 122206043541638538 838044460413608984
958634331529195526 190375363034832569 238083466285325369
572275617427040462 139066622956090115 141816572651466897
433188010366134730 11672759615803453 559416789119559050
533154322087053260 777564561418926340 433696532684389211
621384163204329512 798863023920767089 157505093129632912
995062105087872734 595602077425031002 389528426736789638
574887147057310783 288138860243193021 16651454718157279
128392081462807186 460511807889478506 823645470318462631
28219514489294676 641532026486327302 652800167739436928
763808757330813033 600620080720125588 304878769322156980
782093844114366087 223234004917019294 640993646591222892
769581018938858632 814633320574295458 753383805406649596
932367871670006256 923924943667623885 647404883891754864
48184857926801669 725345348879354634 585195425593662399
671731582183260860 639147117041032284 841416389400980718
316564368730339854 297990338005717214 288032482169600866
971870259177383079 301607126548073061 576913591061806002
223901314411787685 808078733312562407 909693893310105294
801051895017326208 387639738478104603 61848919713172641
368734515009222825 198232680185211731 87502993830369176
128723561682827801 8164292386860667 840415736338379363
10903430508329325 559758992250254784 765337391536941046
492358849990852347 286930673916228237 648042163815548523
967822161832804932 98293407712258547 835763414382483544
382014299555392305 753344787398327684 338911365383171839
596863718527970941 14726232664270412 915081107071210677
700354212270544946 910255945573488189 152550181938050240
61597980183867660 128687777348814222 899439504163755357
62880483529543463 950802551027823478 145905185805039605
862308564542484615 399643295307089976 339849525550479109
250866664442402697 620609942143292899 243895991524483979
399141133208078926 277637467975997326 510327687871498878
542350762689187852 255403741655374485 637238999427347978
53030455421644276 275850430173214007 878756161698557314
72220260523883232 512328419666940323 821259679760363529
680812715451222432 439775768437973757 83406295239459876
85654713865032710 517358168947060008 216826782706522454
672357510839022866 925322254853600467 716651616935051572
543426738791400380 447409202789783233 389353237654950415
767521606144020735 361222809326935397 522641236045132979
888744007089181092 248264947166067816 165797356536638457
822918624714690395 180393362694795837 222226479035281209
365187802038948974 988727286009090409 725251294614735550
847167535182206863 619903859926386009 120538844212599593
204532372979499265 890202860962152589 479443961015326034
983355641471681833 215554383179812879 57025606490111192
7617414631109015 181694022504084138 204450034679127784
672508520628330724 535748596709301368 964261125743064087
263613990519154370 859361579951422395 734186481016830364
465598958049208762 125926907204799293 524799449718994793
557684134032299418 661811681024520928 677654097548601334
111681413533470488 974460066365967500 109644250810471692
118787104319931476 669826153489327928 679457410585341014
30599072657490895 567963776380198224 997167707074383779
337586112021898929 163311557452993924 591880282668928555
173345118610527634 73020591999934782 311321252729730558
502386363529112017 963283744457140375 845494938406697512
15274869973375518 947470379916362820 100905538801385093
754029238244356117 107387878155456117 429643986393745961
153420220616113288 620577489895429512 555616406653012738
939371172116087172 837314356896530060 450803369349158528
793522030684650486 57138128713725040 235536683460687134
872449217924864922 490804199538698770 207231140213371688
177395211275405723 842423318103418093 433776616752940210
661613646502865523 756719901703303534 856370087759617099
295667995406740844 374572886078666106 934503373654497406
857668972085047990 182079745546143099 510855814361346676
946826612883660129 278278819257884638 62626678909214583
928916128616930712 663190182961500962 423651836104794917
891991982677278376 269802141516382750 170101962927798024
948436757155989039 183195890066562483 866398586554098857
978524705604591312 223970808404291392 619855625450833195
596814129574641114 205246066924943185 85543180248335321
703013562147811807 137405851418969258 531168720238285564
989555049447299906 628543702422326116 447686753077250346
133819930095454289 901510363999420621 993995009510451919
723557316228669133 243852506249142376 914319305804908204
411785004001554662 386483286115145462 636884409020503394
20581964871739435 576132067487706308 354399031270263676
497120979837182217 298169215290391635 406327434324857449
624208924002269509 347936540342098730 147029934475671637
647392874188587293 158226575870978689 755336886753896486
493366825914188338 228637239638186501 784714875383099752
462277911526012792 870129465094476532 386808313029928592
227720733254972092 219717516229022264 398552668022450568
716231659524050694 978181129664430086 864724174290991478
27368371773513996 335180103112147567 369979536085832953
634864689294171884 94820112361743868 271044698870985962
938056828434231675 764750507846925928 289685212432861613
187043944349085445 582706244192931687 950949169305647630
152689141645873333 819874438366461742 702440313131958560
834419209778025151 636827122059271926 510919494111876415
426906278304750018 231712770654211584 35656714564652599
50209665422064926 709311190176885585 784622652153567394
147615339394503820 849284603108616466 872959829145277822
960109603515431183 698624568606423761 653037912492641365
312577163752383510 140357360244707819 613033301073355601
538718513507861925 393387110943882604 25716762117054485
828010719464495521 321273815420543195 97009101122126796
584261790486763908 669704853180480885 717505888348271987
266718947583050957 157758809424949543 65527501864593470
681721978848167592 406696856365623934 138242395176741438
799053981153303265 49256694942788613 179772154115308800
717695981099912746 161774322122842636 587688859238602266
538756725243526913 391226002098263074 93809831770534663
809837956680808968 66778324104309576 366352663510198133
429161459245818129 45589269904426218 414219659889413550
506398302715715845 438652205910262067 585039027986291302
569014582353482327 456498545951494865 704542016713873834
284684075294621555 897939242000477189 853682292742555735
28009356794690027 419740515283872877 672106540222173104
476460283180909902 721582495315990271 692944850068336295
929234002581279427 410125298891683171 939648441496404385
640814364605632981 365135081412864765 114627871238622371
961468167957260598 280544081650795393 252957734402966870
71013401825755318 80959973334743009 264152759847377452
149610067141780176 285664020632259465 749192703209494807
64926178251800526 480928369794582273 511296433275993539
705195012674687024 802822159125900360 3118684311697037
20162216139645229 996133980736577221 668894501803880444
724244928464192942 779496803611650900 684178127474457429
394047126741225013 564665595638970053 780086361033637876
613826832297645993 681759830381782982 747226504460052646
897615412803142515 192722625298085727 867944215036720471
181475596183715194 164681830545462901 946588889487839777
313199757277339752 760445148920138591 93675427218349994
982097356976150072 141605648323294571 567000293817115308
848626418429981457 865661043969605950 218727398405650084
564895839087272861 929067826822282413 113517010725516459
25716302253914965 822242835357088676 980229431555103415
306153519175417490 87531616687627873 539497733446555631
697646006192886852 259785082050687952 877653621182880953
891351170111924183 437409868359032769 760198153103252183
534929932198036436 699513274889744230 403384322634561909
603194284596356593 141872825956577379 454717198799645157
50652242840750577 836156082018024956 35143005731003529
679626413493599290 826709093296659605 497734944318504583
495781803898058667 46212097318561314 900195213668742975
830838064093755182 747604793138981883 657629399260830505
697784453564872911 502656995906130032 820956165197662798
220083615830529676 896935072154635528 265349187936340934
449566431904438118 958025247602692092 64288706681567865
417356137571008703 892143948112309817 344526830663377560
322837629772909847 382112290309639056 601932244290097791
23511092526785317 143352269872550125 987275089125722967
967075577147724566 222820873391589100 226514957285956706
570418408223764734 235289573315394710 351019659346565613
365664773914307282 229074118995107158 741997192267783110
921425909363410308 597946377560098578 576152282544394205
61002887261392930 43629510096856793 124898760070022646
693778033745765656 656867451718938209 237951269913949565
835137275042943142 75978758578693409 316553902211805932
942708002562604907 877497871958680113 999174736307881053
408241448128205648 622827228430336982 724633400006813447
75969776260515330 868962796992909234 790793566918714243
416257680399332734 928794453434628697 956383973226008744
262093879475377421 279983964837655966 64557012634272494
459573262756691424 570904091725082923 150988310115360831
6404684510729725 329182929021765619 599673439277877583
180779468029434636 955809312983017807 367175385317222531
325229847703296724 787084200592096935 286229088252395947
914087788247036879 243341494531300560 643439451908186086
264524924782690357 444871967455927171 760838542485521468
848277920179584383 446835362209407788 801919071210429007
508628701328837364 21274512662543884 631740765652885749
27959300358629992 637452535902864818 900258341437718507
847316200085246115 669258313256485592 651600956382630676
114170142104557877 777269300740200020 82244713231308338
39517540722182460 353678555209344680 203136821176242375
55871276372374253 104465511968403488 885089695117232642
826044863819004897 195163880185768400 176139213346950224
456337910273996975 551198722583126857 854548607430575212
29515929011419437 831405264526219798 440751005663421665
898770368431131563 629279699875779481 38663616972535361
698705425289364287 602199572447239754 998554047363249282
814087346722272336 659350112458475539 297839962654414701
649116125811161889 496472562795407584 320242147238868703
900631117118850285 796030515451275193 115575966044566725
330700527554465616 945687659299778056 138429262687208973
711965022953435973 307114987936276418 456159166347897297
291961002525222838 935867496486238420 894112103965992895
271276243293291942 760137620998745812 877692537109242214
606557429329480346 344373552328981451 439095548615092349
774364711188164376 553137579185607108 241392559588325823
512932818151880496 36992635058796686 255537242351714162
484659460408784613 637801389162990950 557392534659737463
498578686274105612 927975130350754543 735002216299001875
671481415518900634 786551584711308389 602263437048854793
17357234146239244 268737776451263598 818962768022011691
684807844208243118 873618274238428425 760406769746276228
979908861688216293 806520876531752255 678277296958039087
620091955053162001 611526304006263200 57569913443441533
806045144437887772 591926895590748926 563600981754383918
128421513485093653 565349746461130362 948338460020609898
490995038674985667 431830224753079347 131529668637141917
950865812173730071 699055881082634063 275186495851479785
721826412817491665 925138949480471820 682421747782023221
42477265972236742 885883579000476176 350007153089694213
95045464357403790 783957353023620164 592433730991014739
77664271301480160 113155934181858533 273270647108858209
959863992295224116 64466363075852625 332093091354337663
335611540299718155 521552507497970521 278766025387651094
255171282493436159 760072462974715786 234291429758739708
298085486293558717 944333843232032485 20624920731663937
366961335996794748 50166997782452998 820575101686626806
896485553035382761 331551110156711599 90419908552388959
425409064753009369 226488802803106377 982534013492101533
227137648223948124 650499409600672370 234443903361752442
900138003144655047 909774584382982503 98260460393679004
184122367568168619 405752789166634195 966177492189411327
529231633145404004 736397154467375726 517192352801551616
695452782296495711 169998885797484738 7730067733067599
328137669381614989 32482615804186376 428726520764925692
217040861921683519 843883816854875734 916709222814673939
193515247965155616 653858768786857777 976603807403411792
386451509652396522 532572076505911188 293881261563887878
810232880712063366 102415044758883511 905558009814808765
128092643790128906 861765253694325562 265439949952519416
796991856646910067 567964308245613199 284524744477636863
961817156494296019 206060473808682365 17871544316614357
768655586127128821 594713214494591743 475584768497648138
926699623265780148 615262171675434999 117121001488374796
282944149781706315 28789402207922703 177163440315362347
387652698292958934 13062565412254415 389296087728916065
351236827493175109 58572886765951010 201554580351879991
736244461567525703 198479055955476807 102449986760278004
117955923105462387 331899561931502054 187340542004167386
157864787168348206 867775529261077397 711674281212626544
407480159306416110 862600380422458118 99636014620614642
859080003948570286 698315151857238544 226979214056528251
103403846842508791 611242324621494424 580314091005686538
80158653890773482 980887412968562045 236132987036819589
428635301540949848 443827248838485640 266135225571649599
990264577643241502 364269480498587832 787258030350328798
394100147611327622 931238701027574890 173810059688269956
515766704972400439 702358540513746816 205108676975064218
675817779472204383 603737295849870660 925572304073478087
953762802100711562 773182184448640668 608510721867833474
616451380003700734 358631416384589563 385640116087751855
203286617138950093 314653376987627829 618383170069187687
881893469980249559 822038673563038911 575996202897751397
475596989742868811 155298161135642490 594270910927983207
220301386714538494 510802061288413383 175991998530526655
363054052163498882 655968569092856441 242107326664015611
235121728521168376 699675740714611007 456609930699283111
386065430971793311 654336654922076447 157867709301819786
468702077642914131 681125541607922829 837214523410992765
153672252163990971 372144727330642638 36354294880560172
539356542043110905 519032077085225200 141111463257828173
582601408389672948 824372403190420153 634304141961363096
418890995275409789 598164513725412079 594914170547684753
699079768139710706 565105243184955639 235570052136196171
47013497846945681 825083501222432692 547917966955001048
947425865053139370 985364482352129137 759053518721170995
563310562553551397 456023169451177442 254553044922254629
256220110992441918 525643530058343012 923930581107003210
552488679712375379 34935900435510769 368448772091214428
940707414918420188 400073080454292647 972747259803623115
305076003995366427 788988478806327878 766843318689698991
558952488161559217 364546126945859743 351659075609881433
116955871808633501 171533081841364477 232558114348814741
7254159118471816 127166317402417493 344129875127496185
958117351082816704 617904535474787458 863616986100092175
704895304854584127 389986258302218866 923661903201680548
435007270443074010 508280511299761301 337608016742806553
956914879263123329 605933820384606751 683137578688514732
428567614739494242 291710270792561939 71074721035137700
180704498203888967 306093388767235255 449479513365038404
601209735612735733 236343914838067085 54403159431113913
995885381145372435 264815298281649013 367518597383452723
934497439024910282 774906786386831149 610734731250099209
279659532661546492 504395858227861784 148870700758008222
321709075423370736 610006491551505847 892552932758248066
161772791725220448 813545621094686626 113227303828748730
73726013253990141 440780335683332314 721299102344179282
286490182679198757 738650164596908996 896842393280530694
153700595719730051 633162065046353097 942617316944940187
850082070561690773 443238678382125394 979457705314859730
609621986736842382 478950073428149700 66922835907188371
556724325239898949 737581735458482891 563784452656823802
360299216811999552 758239915077011322 536563180094775515
790514983817958420 780119236831056157 582308608327973766
879923232753842483 771830204476224287 876409627844049419
262100161964561656 831773775510747089 309782346363652275
696379716613949099 741199881602130203 407448959008599709
947824130601321323 522718869079407305 571054521276410760
786465593070831597 325600008592269717 832391495672268278
94735745890022597 342489153074979099 789011952297103230
156348423422281193 103492238965438612 253680993771369703
698127849995671044 702622802240395540 731796407139042460
78461919967106569 731390666511931683 800760810751508748
179634879663398599 66061674198399404 528884505716074104
712593607584732471 783115743539887071 897890368353522164
88835829004096396 301590089180251422 3388801628571147
1040608852031606 378333884811275428 930908452919995121
550216516954895153 700390566871607482 872135105463677704
978784211504885304 557384236387789713 322221608200768182
772381807617207196 30915038948374027 534241404323479631
15804334685048170 587570493282532672 837219124852353991
988465237162013123 987485369381703975 502088180292902790
233930277854989688 510564759185180228 99193262681268823
799484887243774210 245180679680823400 696621758671974483
940900424107066299 698373813957955054 615190163893261198
705910501129471331 7577697876691232 261649503942958708
361072105003704843 656546292512228402 860779974652363179
595038039512946048 257544466790745548 79615729768721212
417403604988686995 449949643753465592 382685080037075407
349748241785642878 722532962561909091 350180127668649555
321902248651066604 356754972851167898 343726514085244612
816727744705699102 627938363989312539 214374205703051689
490220228007870628 4282672269347216 663694363212827910
873194579006104452 403314252263427281 676015607890473112
729561812777467748 917498521130964059 886619774842225074
494066282992891222 938722284792365910 971403877566143478
220560468989342497 763444898956681755 536301135388369573
149828780836780218 926213917794716297 519080552835027044
400355973428987013 387123472733641056 954776987204013685
361552935581372121 429829171731425924 273573449370730811
161967558024556802 114072232366330859 586105673175328499
786428699554685538 137438236687822435 432335104959365170
673613237765251964 19381755012417683 584997883338193757
588470943790526714 390419527460255656 632222502116397906
511346887354434506 443768028147573457 432215289912364858
249965188575789236 570067349723724054 369686777161081814
846529920571547881 105281928617871284 992724128173469895
913059631129630352 938034963696284835 498092187455406809
321288840281674480 219803712308069384 644431563335973451
304194187916880498 700814262021413049 627641646766292628
886724571726655469 360194548643356524 403359548097796835
808503641567728708 252554810164648082 185152018017977747
55807043152474168 690365412844851532 319004857573180032
166008251169074734 65304481985944616 920906599353979543
575995305068223964 464371885459690100 804980404026838318
830856222272432214 744780182333743881 128303443195321871
263041776289688390 22412580954048598 101513604949363041
403715652072802723 376529249176581802 943848454605328539
708851936347409787 334696201412986183 816296908519486969
187776825860725230 616759557373888450 547685707384386302
352204476739745039 141863275815803453 69651232285528824
57050643183972677 430887736045703993 803656761675716396
75969304546902719 933711763172423057 410146220060811765
894736975674747044 781279106569972219 362498334162843327
186849402489606979 141337534605282079 87903794674446693
902329475744556979 587465538502703168 814815662241825389
635913887013076515 879549206693708214 398711234871463831
490676573980904454 636010120515315727 970738989571464955
485412340724818949 718754447061164422 688095497586131042
613336749282278120 862498928678554461 819421555082799160
71633846406676548 878369764377301673 583166827464442648
653004437115483881 376147737552776191 29604452266045767
806238560864790000 241814453417832624 892242148674588563
631315003914666696 636748583363065722 69023620200566049
813132270226892681 514351164130428898 22376517824482709
216808037125947472 998672727974630465 913971341904802390
251381382070468823 313217091445300532 864654026437679143
794799127736018970 86582309601559811 33910885366323238
698608694678166169 219987679806021783 806395845626054690
242500228018202884 452012706647134609 568724733236729567
941655502498307968 134723218392735965 570504133409036887
454004248050106107 916398776928748768 763158179145780298
788143017531361742 472641399409241517 383412060529340648
288206357161103867 181344735393853191 457616509233651511
836948228777330115 80334007136149825 656472804899726811
407249235963923857 588042071960324488 312329694656671848
115581026296576334 932446659052394259 214598641119768770
961694591308942182 726008314712135180 442651991500354776
697041892601821424 163279895248958011 116850489416682752
865599658561896809 462532550516101896 476388229112137603
278994844300731860 961013524961365770 837174591086747137
323176272770485976 627034433229848912 109440752329723494
829370239233372451 182967998927305598 132374248005389310
969021885307831544 281460140374324931 396168959351721680
454525064129872031 577490403085128581 69717387726509740
782449043900761764 732885884351462040 203834939688520881
431051387214966934 868985929558350853 109821610024097933
716171906157894505 305159590764881582 173856901528637810
621792249473333622 421716114335234056 998998909983887769
226370082132396557 537525403358934527 499786382249732936
210237208127282594 549549575922221401 93211424440944886
961164530286955486 130636463691045174 611518237869951094
750639576542668291 343240961667831339 638068562249954767
209581906597216712 173352458964516455 137783983860873345
123573071836863862 254983611498290493 418506212987641745
86638454851444566 904810682794003262 305452622232036901
803375664374702784 878424397284910670 936130209670943082
247038883793220609 485089641956980693 768678150093579925
378153138242915311 271130437741289799 431688910418018192
758190662087660905 756031002401268469 36561936926560680
402387783341635102 541376970472780456 640868917732498793
744949395098192066 144178570235653540 166864872627570489
889799060236714823 266402575976452204 36995602362161355
68576635979985811 618335867636158571 163390256933039969
942643401397953818 666112916756024906 648685874624147371
992197798701622689 153002887466750595 289056338397802751
788768137315503431 740940055071039108 392480796446221582
830245894370796574 532602964370848135 304803261714235912
805852345932306034 186312160246631614 695442071450787070
215942910214940927 574697016972306349 792847478770636993
154531370164456912 705084267830113080 616249356158533843
920371721420369941 695470935173226701 288495469423069571
426342146477604535 527414592750447335 400107535173887266
701678209849792774 659179584103745562 990416336215871348
255125088715750872 925347616490995209 327507911828123172
363675352110401401 45325991604815151 122076103761433879
516616182786088298 567949392082179044 399923187515036860
35212308475064055 854927558352486657 136800932757134097
568394116573001648 662410792779073374 358970935593032923
151792863740037006 72181771781582183 157195750218582836
481010151311227002 342845972733179489 345240647870577683
842829560000720734 944305445980887356 503507789295203783
518985609958265598 253807654287709943 663212421655072003
547720675522319218 33663806681709872 92030186785196526
327902674048222376 61203819590220602 573177740231599075
454655802254064540 707820320387481187 60374628739442037
662204926616641805 630806426742513941 487204869637357679
561699042732676529 683313435143938493 78501292969367510
490113247369569144 447375589592459502 325108730213734622
304472168867617830 632295940161400099 229102696701326427
887120772945903988 590065752994746262 935811259886779013
4874800330273690 607462265251262776 279988697218944935
631027045751798435 42802472056522629 558737046864050983
82547178995211277 430126473642932477 248864595678053491
74283830811550172 128301329122659683 166867280853104635
267638726213112029 395717400879979059 650085074105899928
564493112315124621 800825401946526653 762015406857067980
809047511006049392 872939727687836548 924189326887056174
311143130949422423 629445613405069812 967938529730360886
691934338659001061 607527546013426506 817037246217240849
458986832792910553 105836519859844700 814062049927071749
946016722591040544 500666034885659829 938728873045003236
598657239584021729 250015872472304323 454476741966746769
49790606136212089 774294707227655169 371767850400118733
639108338255992110 456714991314099284 459866193580535457
520985735751876439 240786011978207134 773691513558962696
105243578666094927 397031721175288557 37881526139009406
228526290386709091 115064057744618492 71940894838012822
211327835293161650 581384337258598553 816892700373438064
19112912826810419 846773824912900144 951168397583540588
21966618182746934 123031086954123693 584753940417650020
970582320225306570 586805592817187479 366946644958972150
673867189960820054 392110156813406805 314432845582325469
812131274245655593 145616696431948345 332161676913007133
851050782129733321 189053667143834841 995020803334354409
333222340534483179 528359937363277833 409447097846396598
691897574735199383 939898236525907949 232825335004893631
315063249870380797 277320813887168049 730055859872849675
486488198993067569 89002016377750824 692346728129947382
813396707781542256 773772698566703115 366564345760340162
154817016769702004 383518928035169151 233456903355252910
542994393137170376 7125561459122720 55799999362777876
8266150622310306 116958854901296172 573533480082890129
445899652379313059 556395753254427028 31726966266577698
594072460580631226 92108320581515227 309553051781527416
968349596926772591 56392574932470565 654518459973634758
829122040281560388 676142616695883930 323986153645512178
65569722630253331 518031211236184564 987576207367178801
117597783970042849 74486770595883102 653727209751716985
742236438114353604 996563665677238622 57128475305064685
382323910293483242 248361533903415879 240985520030630644
917355375355660263 420522162547767695 434134328101167860
761235790683887621 783363681977055236 713329416675217417
910108850484813232 916254835700283934 959440232630152724
191494260443147105 171272822778066324 287331833658864192
45668233623878409 327977674931302124 311359449904100617
404219034508671682 577499530315497588 124566544250081997
520164548529679436 863966992012556792 301851769900003047
21581779657180721 116569229907384318 708411606893071549
53947537693136010 870803407424283165 778341000125650811
544932258943574223 251182574005205933 192333123273993142
719787271700722557 508659367732272983 744235905906432287
205651852869641941 445052559994746003 509498924246083469
464944080728640191 906584568458819735 701196590091045296
253116086679378179 844568612706985503 88170095741999547
698020178983321204 229986235215097417 729644665003103939
674549584532904255 224063992448516606 791356016181880680
464565054597483727 242232252281794253 232029075482934572
227906385783899231 841234474172676992 709103764745903437
361718147678042400 742233839513522059 368275696868632492
184469956425901407 357836249496114677 967990142488836183
841534650220169140 553854597521068292 989548611474783646
915241151008025204 833391153744123873 479891742834416500
862099649072736273 541182812524823827 391949854595423890
453240481972568269 973347275332392202 942964720530764323
215426232984849455 738145136437501281 458202536817217703
177678279883708373 109759368098052933 410199559625155815
994615097341034637 967895506328605938 258096542900355900
949473962045028569 281239667176529498 989805902060715853
859907721462225535 924728746472427273 950431573731590685
494374068452405855 340649065513650511 256039983147100191
545305977412091086 526760137490918820 696142633907661853
925312662889190941 978444404513948400 193689875005031926
14772200419168966 70079821193864916 624965227050505769
694497091205636930 582253197491791429 592682156103115633
184893675512179029 460891276408261620 373015976055545241
105397684986459786 807887992839339396 916817652822017621
456150350167773439 71360441335106396 526318545614438425
424830172521097550 26813808683137695 115107592586507567
270494464875923848 276178314006511355 545106165398084850
737132088352602541 83159085915253737 725554919763048254
867962535123450160 612412139658718063 923283098520277335
51978257879919132 725494356155208849 160622355291843213
738880309984340566 755207031521170900 613356820000256275
764807670309776719 331737047217121239 932522736152698218
589653201167153536 805652006966911741 948182055413326422
270308835344484949 955268299337432377 243261079245866770
622211508882959259 241108219687270795 76452116144540964
90097328796628352 24772137683057217 82663697250901449
541624117505472037 583882867363080555 305510021412998151
499203222469731869 799631180622252935 188737498941787011
668824309934725221 75356964335776878 158820747278762368
460959486759587979 7538231677637377 710120169414206467
990430366489221067 888197682040241720 223948192810934234
761379629736367115 623562742162078154 405275884520196459
536280139420961904 389800056332318307 688000903091394705
119768303618240219 249023629018366450 561645080746193851
477939704756640868 860394790014734789 439511559857244962
683193679552420978 927371637458177889 517334692810407300
254198024654556788 752858650703539776 133323521500316386
264945205135863232 858747354935872729 348700184563779708
907303214342575613 952261328455435539 11550165308128310
549331786970352257 2988088391333891 480503072866259786
902639471414850005 68027469333478114 537815300421856283
439627909805825286 846107422821591752 297207839836599778
436092353038814602 417741364434112898 891353607610055355
641587840567818201 44927065049732721 351717394189640182
930055436550719982 514394339113323763 307797796648651402
388234372951120937 675845052937945577 325724002573792533
623581473316252509 489967831295895366 711008983135053001
375537482523948846 237926521943315188 203979307063941640
131304341269666132 436151695428671071 760890181349398748
886973077765316207 654650083498961507 173697563404318509
786845408101468144 56880312470323472 951483913080019349
713739547376448983 518814251048311091 169269917300895640
142558603324178891 895021995743563021 928004437483519480
949470144863553351 973155544409573765 320668650794683470
501050622409800326 53292747443188577 829447801053111670
43561935291145812 78066478775341229 520460292768750559
209559847917972247 3024452855390152 23133587218545192
495490799362993 319796249628488457 812736513700693401
205282212128060186 190828115324401508 70428084579077015
975054357446906774 555614518142997673 582598261685676954
788822294359735134 996398069515379418 964749387202363240
890160959208041348 333715365397304210 280650588350330955
952837062671144412 294691949904328569 931326367590322853
515917167307320115 847927598380058382 296954389071328069
512003837792147134 279772931229621170 274096832921797860
395210344187404347 875786387037829413 914736376818442945
884146545055498977 892261428330406959 979648987396282579
353415187240691721 997901250520330954 450816381293620945
802127387107646536 504618529500529272 432131910766630867
87901807246415391 257128932450346997 863804105232362719
475506487344566592 111324593661262906 105146294868748697
756001975530044778 561641973034928349 759796828521652753
973834423638683319 456296807951294533 727301800635494811
843666056153270704 505832189598310918 357746721123390967
723152535357892824 418792800256167904 557510311819348552
220389319386347146 260480600080804736 56224243603165351
670062405397349896 675097807414229099 69515108948100718
575021932677692270 862278232778220101 141957888820618201
863797649373092202 147964721652137590 852063954579723872
711189971544158878 548202940994757138 246094523163655870
986257443216039616 91750436933906082 853003782373146175
129318878595063466 327925579321485121 698866914690965597
341605182600281690 511762239375496287 817739156840367526
579398165123288408 9345226805217320 543918150823281705
373626609010198183 557769888038242558 809773878482695182
994419138589359098 550797138119870341 824122627534616718
476464871677909010 897127975483916226 572126508587508653
931991073196337935 57774525283898905 229477055407621639
632069038346433552 310252337282084715 195640520115160076
644828655916662520 799712244957321412 75754817004487479
875743935337539477 906148628313662213 721081659973571224
659725874788865352 84800323518423603 905288245727000901
220769760863527340 572250422639223929 401880951698248515
254529618806733272 142064823227330384 833565907366125037
660638595694174892 506875164453297290 35491487141642372
254212938645214102 952666850318949177 727509275238102815
578368628691777683 845934335918195380 275192153750410543
17513799698459650 791104152883227481 16088502067227259
810047263592067276 787041564044454061 929802444706742273
127898152681927256 493699732322803896 928637113003996208
260534752698377071 367226346193592463 708844393266496655
145997872054602393 596308168589058243 916248863330587499
533882092589963980 667349755800700222 64115212203219546
297911413032769117 969776307067102826 149739021686726759
660741213987247897 95313153737077457 908548475809853152
483162675715987616 93439932792043931 416482926693123389
630541768841249936 955327390527806677 532746530560951246
564251929189223316 153894148730222738 728882295857289
969864280462388586 429181728684662678 766905231884393213
125097933269433998 837363735793207945 22573522083348898
568510489034639732 799815397828602697 394917365634728474
200030187809649394 378974134155333064 184676209367398261
35398228144886849 517743828948656192 96489846006680635
367494477119300193 831878948554912041 103520249257450542
934455245713752649 603873975656627372 501827970918817567
758816530828831191 762710104778609896 398959549416020626
634030195676082540 264776246023198547 690869357190475557
42939848583730835 263653243322224274 88819479630145572
599542122297995440 844525350045164520 923896474890536692
932038751521132483 421527294730284095 965888255656964319
407505222085376829 766696160983219228 514199617524856342
754781496393882017 908930323968414472 338445671492546569
264268780298109602 379053463117474415 442127272202863389
590910865926106600 872490961023898834 697411049364075074
645622567737238575 568024664372425213 47692332624215223
738161672003233115 131218767695976781 553249908559363336
413134500703938026 962585223146557336 676384353685177927
830955026899791545 713289633826428697 566232954419648074
410682281451073576 326826915908844436 845968172457676455
503106284570874450 178535509268754054 494298121324686242
274361795489470534 63397067430086578 678173462806308178
279168192067367244 710720675018839980 912726740551876250
877277646483536135 796261905809197950 930799549225940165
819488148916977792 445838215326343583 153202596641881037
505850501882261043 400517700553715383 434827592071374086
571953428696450291 859428581321456580 958714576167577818
561059611864883604 242597511761770783 957820883264635131
562174889092186985 651729707528513693 413303013981231273
950244721380937623 750643074559643181 424366435324864743
612789397112176760 820614330940406286 834317561596848841
526792968262707489 259015523934988417 191297155384112636
892626735753442095 561730544465908359 855944609124545106
682965338815663793 310239363594760224 565363589116726059
51663259696727952 65020492964030397 492428502535659452
579345427606495404 792122347339810929 223133528167255905
175457600977210357 696230706817450632 665674448393423413
74775706085646611 118624847760208139 859534331806305481
964521801963546057 117780111652386805 304263729277301787
404898599539614297 509079879308821 472593749267280223
963494743059917197 758442942124087186 518934311756539550
574446116207787874 534437299975662492 464242499357519072
439156720441979395 599032328469302077 650920574459560168
829106855207508230 384060899113562220 615068455503538158
752315524656091851 131386975591801796 157237329264301600
593292566999209110 218483587992335363 229211137223430221
284385922959163894 31950542364086051 33926895582197547
154090526811019214 774990309556157389 197353088761149081
651686924457792793 544981829157254107 667209283437658917
435773947409087942 362694998646989716 280185055167019287
342606906534620576 566861839421713822 4663084611607445
919072791259316594 684685149020485589 781107012201099273
438063625215239926 188924529165703031 743764941706123601
533380466128008221 6038276923674113 347206661684077283
289334215281314971 331911050781495769 137519850174906370
692716731392169588 665679246864895121 253671542961787039
564127835747128766 705323872539144092 588073467777885862
470946538623298463 626549679654007301 85185833285262725
982480154145454159 382284244676906007 717172536828405890
452135073689934762 939554567606541582 858593048248388126
729167619712736905 875388901953582492 546104010101675919
302999295813462985 836856015817552833 22845088803699894
242453106828743502 204488474452919461 954089228079671315
833811671601127794 921679579588169751 534733924538222276
522970166597288173 873075564653487621 925359399466571929
235071924574870827 622930608010946493 722079306956857577
957952051636603088 732755469882791494 954861206770407592
26213855103979311 942489736251516041 333402709579472513
349365642148176092 158634689588246316 936403298889219557
994016732383447733 308541433046248713 400140979777411815
26416599630261210 531326125470429881 689655140933855240
723971275287689886 443490283906240707 69639325599275984
21101581958900028 40719779430278972 536052257358835881
377437445036225328 734836906545722145 826850464457843933
660473245445232660 892544262601005195 898190170749321668
334319064361606502 509599991781446212 959703090514376832
748799797154097480 855929839527486177 589667817337319375
335478319953606432 531132153490343011 608001511109929586
100458288815747798 574280111029085370 52146712004495638
345060822961595638 637848335933106183 104524151315072187
321237456796834604 224549337836884000 267458877596567912
531974331149397461 577062655505988193 425529471804659402
470952469192465664 128494032448540836 546995772121523043
282997787766185949 888181204474005472 523005775505663198
192908630745108307 676240036811282583 599748422310288387
445017222984952332 938990743629844283 697895314126142029
153868308632478643 405829053999929564 85144652857466250
56681954225666557 624067623067678807 691128787833999557
117679206601466650 257059306612452896 130696766802020214
870123575846763817 873292967046598680 618376670877937858
739081231478940265 770628061685675590 313134045394698123
716629689267323364 517939835453587607 211347710845781932
108103313509949945 868944950413129282 948813531161858612
168657077119043248 343117318512523228 895985862116586885
80636989705134770 1977582840576267 438878250883374118
330711635548047621 135351298363951885 617378495616043844
959096069719006886 987119495885371929 447749518485468332
68240962181027644 997021435050798793 323535384774181052
992422632537336697 40665027361897109 176993260194026952
219120360256717299 937163500097814693 526744192839384419
809255951766438242 676980492634791529 113497212111256870
981573647803222131 840245680708034114 940854593388990660
777578905370684400 951939679112692379 206907267814677578
300069786145424694 338953950476809694 201536831211382905
215458200344038230 721109668566818705 464224194391840913
609139172679546999 958956726953754077 895963543026016550
230761514464830463 624950571506403291 712737834703578881
802218349189479980 107964109854478362 431084576617209818
386648272616920223 429106287645070823 260299809597771688
457717579200830877 271356082213810568 101277317548715261
141905514340380167 846398675900729413 372524500607458881
385740490927004895 936262717283453318 25250728870425914
127766498210875795 632076735093611100 314109831445396972
76769021722981980 955644190139941588 616174092780014623
942541846053478136 105601734658693273 516037783287700668
466387865661436177 716506277615895240 453406267300164239
714192134986702738 887188474454857460 291035075573128323
562437768808153814 207638067662670828 744283002217210100
278057318127625918 666215590636035752 943524135910124805
838398145186913772 692962436365442572 387913852124311625
412999057450974037 151694331952656180 656479606007139161
397132566333326745 341237201039380217 475905338023968472
873422507653439127 616910010460286614 686623804063474246
663379486778082886 805367667475700024 373725327808228271
905158629890466910 826923343444878519 945441227330570378
759511838150044808 977308815684994513 698917238515322974
770071787173174876 958666611345954699 987465654242182516
790271669577779797 921069477809173703 159308376985490119
699626332808758354 564991002322513403 236684600044342764
222356583373213221 643627613947914572 219756417624358739
3100509001148233 182047145352564354 658306363092446627
506012307886463104 805320251858762131 426310114567486128
291751115406507016 555797559819985621 220671101482867118
858499940939801478 475521680769237777 136777108831083251
928028653065310845 625654174629123689 321893225639697666
159396920737602067 963001930738038392 116238062991014006
391005946848421111 142478236404567877 438257463059618823
780575084992737970 953158939215881962 962693138445650186
184151009672435751 298630363491668159 471997126090727720
990880469117152564 8925213136582611 19313519769738938
118637262494234764 570947200838282456 920998543534151593
184493725780526110 835828004652357734 91446126005713693
770122203849694419 603045307714482810 338114143620735839
765198070994175133 472195484512994601 300725401988429867
320262913701005823 306235405146663425 598590417213613428
561713407480144540 115827529832673560 80047379984829013
559971936625096744 185602056032792856 847264448341157966
958035257417801097 671388168524135362 700133354070021891
831404741812236446 693259585973509925 116019978000359783
353870911364959867 354926500047737563 708297159716227209
81203712498322224 573581740079200985 116459576836605477
558023738934451086 540904428431284956 565003523161660184
219029079599343219 952949680133733645 331734693843849285
52195353397578873 35453527484103449 819925955916226365
627102749087872970 490973310994291940 432849522509008165
179161753265257580 728570703837030635 129160267588365710
720208167754141215 234549798392291635 285706413681611953
601805708001469752 134514625996951102 853056813725255481
872717905231488060 177581513727242998 93762923240637228
542346575612510105 608474461642630981 190317616977387662
47137675164360260 470151915281067348 814169255587189390
805838470512260318 965347974062388070 798494926702628844
559865423988575880 605052182641551009 620324076162620870
653300282478007699 351374701808967345 946527965658258747
2705689145618136 793004738342068917 990791149515098768
469243483170701226 747159809268463339 353829252959481873
114645529950076676 752088325685490789 308493473106530392
485551571311904072 482102289065159304 910189872210095193
405408242221586008 795530422107756072 740789497367500741
851242357520986559 758208672476417951 854364124445061385
602736606352048159 755727673773293226 201568027003447516
122589768922774857 706501639792324126 836744043969012614
445385735904427814 866961702822480355 672087534951329805
536144697681165685 35689760853932691 941662637002402805
931360817189870178 450099602404932888 322155120765647007
399671979694583075 476701058509068893 434040546585443526
685178916290676425 315350969890949664 275101976346974284
338312193406756650 164960842628164860 662960414790533432
45782304111471189 112415516044750295 609786400969246751
875099133079122141 923048961205081778 645294856868777898
81272985737278581 958191851309401587 974326199028196984
956798466860003149 640606101800437851 930447504977099394
118699842956937152 28908577336048065 22455285834161798
393923242418487434 69941185732615395 596144098737099457
80738503559672027 127633717574159841 403675088407200216
704968675627974231 880274299667572110 48103977292013490
279046376264161604 807364957132654176 302358955453987494
476842420758751670 897353388085922922 582469939739623365
222175200974130646 382634171549875721 546008145143912905
27859938386023305 991049339112112386 946762008660455465
239936879011779434 403885489106218298 186411522583284954
924872941228632932 840490032343013658 493889621844834708
585616742300017438 420294806415792483 389943461212365640
289953395460650183 687801729519722841 945245029753165984
302888929749015870 410455830240332065 496913598892938071
287958546304041691 808284715425877960 415545913237732749
333887167184684397 760785870116750273 750731067867962262
427169152360182794 610384590205888337 536542957009387327
948059728356590550 301913129131161628 502749948906126923
829578062988953625 57362681101568166 879034337306025332
978696954997286896 503572531384329842 869068896783765923
711552370651655730 717121914513845372 451293636846890551
541280226765596756 614322647325714865 971119267236651361
122252712936089005 452556282383319727 185912416466997953
435532362029751236 157952642979019743 228250695742021037
506498310073421410 802737458455212807 584744330831712075
987183694701569962 166633827539407374 92436059033211699
408223715417654314 442705932335217409 413937848254751336
98487170440175491 722572700853611274 745990477878831236
500125654653559185 545802679575012606 971875895929894743
75039057372402159 306443835612474837 356660987663064252
994282713893373398 383772152587523194 929051205964512944
432068761051738886 730529677274055493 360025399777638931
918788018640331741 214204404025082314 66782446104015358
595895691055060339 134588759906777352 484240674256802286
804027230148988709 477841372799787454 698858316387090751
493081394781529710 318785472856247996 201164905302401809
644035309829761047 613875699452623913 201641694276429001
533604353556242601 964482344974659668 766816277553483705
237704138692244308 980475494354676514 113711198754666239
238048394378703588 949935210911409149 231134508574879917
997808179458564477 626431417329369372 541022941880588805
343225393577278624 644701045948511498 63038948151719735
763720943922190861 637487441342876604 550942074041078031
254052868030621288 88636307936007200 514816860682044001
562401791724774914 853774544020262626 52070925778485876
102380142782705454 91901154726263674 228221416494352967
14508082337519573 456441970667560300 718271039005001469
397827400621458993 35866403230105120 774665092193875875
216666049113903717 675676824846323376 896398850501289137
729641969886476796 15975415777817167 159221328388974783
590252981824823068 518554644777088246 695046040368483520
352162540930710750 761993738305934190 421588742341631907
830859607507529602 373430503250776417 836339953055086794
972082223276735064 226349525216507582 156138960329086269
981227813213054460 684358081531199766 493547233482883932
2441896469854763 505722767134601170 17411861249699365
35379983531639229 506176196279263104 751789924781496229
486416004639247464 237975414690938863 697178107983023217
820870963544492541 201115020922132993 958144330976777336
328988776044198567 658069798390099172 755495896856394453
96635944428000400 656816227450958030 600034544683417209
639189410013493987 897036751972113105 40801500399856871
378146562776417143 452657508083458282 84894784883383736
37473595418894090 312674453212939675 800693471369908445
555990438110860805 976858396190225321 737281432721662545
251531529182985826 418268401805161797 177761702173552192
278547561436178693 62040206887677780 840534428566203500
369961846004356018 581174944118196669 314458994555211339
853771382689497663 245597389938844875 561161528972940176
717974450926341373 104701755582527940 82096744697948390
949253641133654831 334354984310019813 53807457185122547
302318766484949055 487624615344988502 526915968022614957
805016395922595577 994039829165045379 399212359224422755
839180173949417904 218312160715520744 872972551940910439
53455156218900413 163845260807254152 248679438012404269
655671256301123329 128018710059704409 82443212630246268
69257651218335475 523994327505160294 659898439930965336
173936984097956870 246939054470999760 617411161149451280
702872751793378640 925628163682401360 257937744525469989
829298978050473090 256676988301011469 209128545421054394
780123595551589788 861689681579810503 520447514535147367
784317867752209081 370248029257493600 853244529586185970
381237527877865622 533404331866319983 418867456002539261
595260840593958007 361756842102825794 313229338722910805
889405656275487178 966295490997659233 39686385643109039
894244503320317557 421071801050190978 688858861866792793
470949989860252091 738376055464256976 14681996798213125
78901817392692597 669263573875014692 852893743471898087
323756110362419636 902705186337025984 83999933234532317
117599402084565204 638501005423533236 578273125724105103
403623846258277165 247618043536515377 538456649415374587
362285940207437213 724977474608715057 997642091164670568
874376590636478085 395259480438588122 151657624710780533
816858597201832834 187844275198239725 865161768441239264
475163921954926387 247243562140959072 115618439429167326
765287431024316545 193528139115736613 639474904146805080
598709258945445516 518303115653696066 409802663452325557
926433774643110857 528176000849712215 278271583293500643
392048769069336492 252895407252987504 288402431782999573
42068223103336920 918951321421451705 988181543537286919
771942617977912006 993249314090522029 179279712029285827
149741353125139892 99672892832154366 201511558047951572
169807234005533587 968922182930403234 426875307845293909
119392327150009279 925456578059366476 222208214961054042
953496101585876750 910276763782237636 328060239051259088
395902116022411634 712379028000781916 57835810413728879
629713288284631770 971610860444896567 127821952706387567
952267116574518079 550118956139372430 820294345436919169
12288967376806808 187185595357725863 850464318173463278
995281699918666169 381918827510680528 184921776114321893
604945316105372751 965459846264886151 638896500173150053
348401572456673429 440539548266242429 193575116748290588
394442334092333118 329505819623747866 263692257109838143
182037773380796589 24385835269213318 640361253963713839
202703925832074695 749932703608628494 955239534817231151
48879419272259175 527886590378653505 495444967402171950
834789038227383349 333762947740361888 133958298144218689
347714694082296464 666339616207708005 715867192552713364
564924490842060381 78718748167052996 199430107811222211
567121128295720525 852507728927921132 866235718073919222
646224889023108014 684841172170743281 762054249832134206
349701001936400349 737397588650587885 87160495569818507
329115407554436889 143503706100828429 6545059998270610
456261084270938554 476718043074545263 784566959318712422
826308672554597902 784493985037808954 65807170991729246
697684171893532470 668662799392428040 662889011238334357
851151849900237973 961073461784199659 414019288670353607
926497200337067499 347190690157237883 198318076701345264
862844519825114489 614733632295604069 447854953649040305
897163546291871722 144954743449910458 709548559684938714
101547911294069889 232596398454753880 964034732631922996
906624596319711768 80846913862574195 175085590647763976
333874237693268960 275695484221589134 641660752396501167
67976394883430052 73291843958554307 356194498873545151
466571319007230643 707618792979733808 827074549301817177
198775264686272192 708190544688726672 523682695042235005
625627129823672592 98776023401834946 695113599428015525
309212773843210140 562910897845948019 833226751888985318
467921292903361054 54787882072147629 829792978678161309
153862254430758068 393530444194323603 467571359110793427
632574484208825779 193286511122309962 385443232174708326
822666881824942672 322359814803450655 376661717528192240
291555855604206184 185261940076174914 829468467893675304
982338349340570924 793338814372624390 971535329126038168
191481124467668692 843179285845622529 55265715590650104
177615624020099860 800487593020873591 136407755339120529
235676885038615545 941041802775672990 500128277341581549
569550232898424897 942169607543120750 348350306121665516
161340891122052554 367519047170670988 178131885336822732
174795610723246026 202254766694901745 993007322861831515
346210839664087570 193823552284122061 503094096094735141
875570343287810429 898683876540985947 906750995838815930
137584558086315899 774712900678001229 595537612699375196
858215795921756428 601220775627210716 112600455779132666
581116726297271251 296269176953313115 667682222485676157
88014253681136193 203782365502733067 343076149073257754
850357636824532337 206148655380623563 339885651909690752
974225280473599690 803212453971118372 299626091089033138
70724975831086114 551984117519080648 872812799536343308
379833062542558726 562319853013147000 719188811012840673
271835805807311958 222460384995765975 267034171693791247
416846110507584471 649767068955400465 511584016843674944
521735258111479546 434807120319124563 128857346315264294
774010979682165154 291091056509825605 485340657013535214
100054418006772590 61158248067685455 271262385409614400
59837545955339640 93395092416089680 433050495821929550
794092792088502757 937886814403802028 197380735210330625
102479717745313167 436212057449273705 899693266693438330
741717679074829127 849713988364064717 155779304144439473
227028949673245894 731864326337691093 673354877691710624
673410807766485472 752371334030309051 224873072137307850
168894260296025693 721089270866453431 32180146633983583
980201220294156091 845170601604484691 88188923245505609
290721342714383602 649751302290470597 595173321021219706
616357923166124860 67094822490842804 433618139113989587
801708759395965135 980810998905007230 835852417078161671
981987413367183470 725451621511775210 80291661416739515
799420246291079504 449107958738339952 195990693743475572
305874158287059381 112635290361342767 63073479912949818
284133392144442789 622794369987598592 303994321102681874
431680883066838311 328862624441751252 1483162124916294
915144388424657103 608846357982046700 627616769608974309
534399546875131913 96935645705057785 588416462280288579
232596561070501075 214566605049629841 276545826021783649
371145019326796591 72369835244783959 250363687415378276
729088572351262864 679976489969076066 355619471775759983
45575491969045988 20289910607264050 256825815764619474
244592751556479420 308248400053258592 147266724538111584
839571321886019823 612900036206394250 854915796988795864
551113024132330746 629609713311815386 816177019618938090
699605159113466944 923884186748445678 39061751988483062
674080363999618643 3427032746371840 113426468879434425
269874398579215942 78835470182839799 977770338287821928
628064407545004033 500000086470673169 613521445602596463
314421642308860744 742768620774565871 443294403040516429
863534887113983277 96340555229899617 554647210379133643
27735994976453671 88163309681453276 746034137564638186
633482119586612068 172035487794017654 754523215181342740
807150457649375750 835713329247749537 263901812999618649
154321254749228992 486501338449777499 161008475045534974
590216393507589015 55217354740500871 193687998391578735
486790031620223769 993737246007628830 932071841539957378
518379915366698825 892939439721969174 632363906213527457
352997473196908941 598220787676108572 77417620962705156
10684290853170646 164943271912576177 313158529579735306
629041390443036899 261844248168957286 663358072872653061
730932682923486911 838999269616546819 454163737931776927
972742228812310961 71299679766698465 578178973135271858
636603815967766445 977841669299107947 774296278422595894
774491087998192412 871536681687262198 967244336569595132
176560677889261664 954713758981257261 732624533161189083
42279763112674219 22988433355286535 587380593287680162
136439516060883976 852695427858170160 215083559681533290
461568752670381045 162957915465605884 619394066507678051
174124174597692690 909129403716539892 575279914238679514
267558176490757562 978866995395872056 548474193431737676
938122642565308314 490331767840936886 919096630680823874
878158495767585273 957017809283790512 111865001665164135
719754513292916567 718884154879800256 658413695578275717
683939496645074431 616082495006125247 588365458054140117
423576598191817469 268976757988430902 230746839513595532
361041410430166046 810836621801819358 813292235137144024
8568023478149350 621901677805102073 585401282270631537
673107013316217678 785602434403227861 125946980852951165
825989252593549550 457302872077995548 423057345277484654
834597377636520475 863385412218511368 65319807547878727
425091350791262083 558379260490940443 220822274977141844
306413496966402281 767714136056197670 806356781178836760
353344200513779186 457828865983834052 947714666267150092
89114197089589136 43353795945680609 214073229624452514
248021159825108020 100736231294010412 997729753643787687
996226967657714136 897267720256278337 56757943622883482
886839102688417710 824922182559786464 179638930473758736
495270429161230270 399195709272163282 754995830267689914
197209879358567207 128448967765064280 960924673124058373
522723769460132989 117046686343382096 481353151533393279
672393272921865341 224703608032100066 452765124868491522
186503331330461966 215833750325881986 874139279818524062
695183653356544732 690063532348421711 843896350975255242
160137530628525577 161705697746862666 438574044627033679
618798581566485238 263305114618625685 588312623713356003
494662477636356208 457743057638375732 967137474872624438
923521490875759573 196364010396819682 850240469373410435
154412092306634248 722218078731814583 951324433540532025
898715845091555749 616473581471059363 819357852801754325
917575007786851436 192769711076199369 607741887272980488
813306619656491875 807482708847150193 179799463858850257
10200206856362745 976461713360638837 885365199463490899
182892456984776964 681011693743131581 955411217475310295
803346268321112688 496120710011530608 501571561297683034
344050738872976204 618362219540150539 106009272746498062
130050893069640695 119232870333546704 112533208667146971
801651757535266188 733612119805332868 718022983072794673
464702709570189470 486987084756108429 237370783395616281
247268601628769695 953278789311630450 502143422901840985
939780413055238534 610277675866784551 26559387542467698
331499653308062534 127244273492378315 34580402333474574
708471488740347175 453640017707435349 355298460455432830
705105203252395025 438258346722333294 888831731544702454
821842156468158453 386969772117989925 891961795595521338
80053104656146535 79061563071594943 194472868405784147
152542639492538718 235312134574251712 272822777243324557
894957047238113261 907316677461109263 127528448630050184
391007535884966338 116744128654231888 307416686264701096
398736301414944635 348451107467028024 74858671631203082
739092403715762190 316238630701101202 488173110924671569
116371149035768369 128604914263432680 312664735076322225
898367965100305381 20296606998620330 768225079954533711
940366305664522610 682807329106521598 970111791348312347
466502973858253528 990038171039322333 332287201635168052
696312538374386859 964605278746768825 108880729935615218
779697576158699543 45479265990150586 85666730129726063
632426622171159274 633401179761720745 324183746363968012
732910342970688803 168989249583096036 210617417465211841
174047592305187241 139268421151220767 545842431672742980
892561522673541089 824449445034052874 290173582599953024
367249504877774932 110006086202989391 500419925798414286
942514119796073098 350323005521910943 961138166006117853
749446153830034203 775182892773015594 939025911935939470
565857472071055441 882943455934035005 449376689659020179
848716928773265629 513291250580129498 36378794981042953
805289659719588760 678385443096639515 540886500572486555
604595263844647006 811325830417119318 318717055741395757
959098523634782521 885901832605646013 986029851855224210
966031402006194378 518450194754780490 862283651631062724
697074997150483783 485869370608278280 745821237831408321
5750765674613132 130031962281832991 432205055679718831
914008533226177703 873770518582346572 835997469535965695
613920758992377099 38339550854119521 273641219408118752
439856357786472570 960699972822133777 684568104215238740
341913000952582942 618825026441034086 220991635965389610
130401662902519371 649965282977855363 991881915050707776
142140624960136831 692416053214064154 971184838943290511
606595360997022123 160435365579320463 285567442524481527
452932389426174313 195243404947472406 504704387510942911
856925163178203931 580188565195104056 190472506288776232
622952158506438067 555477543934601245 342206898244589521
143576483889023005 572008368695108587 932539554228921241
797269583003741188 280791329851698565 740389292865337401
312062231524532389 597818875208591933 389328551227934601
911398333863341635 441547742556359489 728349570441864451
6845041093901732 182853423740148488 312774847301014232
13015122115699038 999962185850699241 717186937905994585
221786919211967701 281591432537085329 140824715594964908
477648554697816668 114590641225119513 238584095673874248
910286938458789366 927136577859889145 719222787176309358
606791710909766223 828767529410441737 744164239925591950
800101437070953763 423192513667833632 392512787548091848
368652380214238772 533630683061265770 839286888259481886
963957106846103122 260380515615115615 889876771968101364
131512682798880107 376458857197735568 310946231222854997
990053268767100501 207607078611503391 46737996555411837
304356885780806586 483548817225847213 559968599114280935
266220460480654551 648183556688253419 37925232931245318
646581825365365406 721942503319038883 404569828783984578
297456436376286166 877286175824981398 597414117246552177
31443738254865861 329667135353974929 459609037024628548
98997353818185767 810083457199662047 730780751627915041
300665040976316076 707174346980267087 903051987331411940
722208632579225427 27546456220869102 210850353445973430
616916553167899603 452717313288386429 133419631018163374
661198550329200332 682335223601577114 218185224810585814
156018471682318006 349167166364726830 196648647821467770
456978633096734754 986592953119763030 592977008195342673
125138110731175290 85094598641710067 319703119333546747
659323479353859779 61129654010925057 48787145537753986
245448829770060697 843749526745440443 717837907000127825
674330822235546308 697890880996752721 811769482276249544
654742054206909921 971757619673641811 381311663420814785
456988119892557063 836043794865452068 406928745294825110
850869509839752617 171025343721362666 393718767347008195
974887422168111239 908554058370160456 921121498610987387
927381568107388741 709042250902026756 340437090902656269
677546865641590028 471350787122535567 862111509604268899
965166998260914151 858545840253674650 506979593763074371
879511245617964769 735086931627171294 145522191103760976
147250035180641898 499930850804599625 34910768072245399
527252701302138913 389998797055796710 943994864428193346
584968677694284735 676316210630631972 193188597847572215
411515658361951137 977363765772912930 774532192001820219
866339687632027765 216179775941247888 76262203045211428
498799300503433586 866769095202120796 311244663012760695
467797769122684900 551135188124514455 336602414603541789
626993001102564193 239622751031506749 122647442212520753
74980212278276272 388880806232375262 256813175221706717
404230231502868610 905058175651885834 840748297485175445
784081829982273427 513077893243870779 408857669118528457
79501444750780382 342752555646770887 282951495533094984
396676929080918477 511276118037321862 810095195641266169
321421643674339198 951845282496483821 177198863604498803
74147003451134517 721700224486150880 804437147324659639
440871878027385638 93490875492167725 107230406375867262
215754416551641918 532363881188914131 167447558796346722
325576334935179504 264198531976906261 874982241853400997
20243864060964191 368822442810141050 55682662674545771
67520316684394108 91470228163192231 971447934628483157
199814073814134723 141573331458044581 755423045207316542
70095537794092146 714085922967300405 115361390339827506
843650004228961816 918757991323981490 878178700212237347
706434118490500757 802629648721568146 811239572159772836
3942183871000729 789427245590872319 435839964555527
672388491417881319 536211928573752794 134977692361786134
365718636751180103 88343509366162323 393674972474197212
829764417996848186 891702662435418129 681030262972353227
730086835877944621 842275899891848855 866691677104593913
895083959963644808 528690192502216300 151618124837571587
570305151228206700 284805837550341147 766824771203596012
107848806847764471 752027224358214096 407589853305681248
374028220788099684 147185608412798197 803365802775372216
457167810819745341 423486262866579419 574957046096708367
253740102300569174 914339215147515500 150349733715435566
208388326477230656 411563664964680406 930590077539756231
226977942335450257 870009720472919265 376175296060265479
241906395771588070 640760738295332106 889702161156807280
741846872255346376 649471296539235995 819852492149044991
856728609106730655 497336184737332839 341495678761349978
896718137699116035 526896963056121326 468323217241957979
376718179993273544 121983874907982624 963042680351757725
653500245578601380 973003333533202977 571644813303816736
622056221913014299 431430883627407119 232476817196412868
930925352181945505 532946354183289382 884052475086379785
501283698301546985 829688129047171519 180981882675518151
518033805730736195 41933302068898824 218484393917204396
296029007840993669 944731409106731441 243870433020396947
839704247182998225 224812435433195623 303400370586190794
793485470730582186 789866200264906312 174780770498097473
409189851044554988 242802693788962932 430977256974225003
464567697859972137 776584308241503231 213771321610041256
932470653895168824 521375703641067043 331072903011035855
28663836625000223 767967298436125423 817587831346315431
822247234459911228 267805691034684545 945917727130462790
374629486612336816 102053924084137844 269349891988926994
992153342765764857 841868980327647399 351677084075164383
861582337437686639 804518865914651427 779833787588845727
136676222926129311 885443525759345827 314201757572502080
162069232784568669 3886073152091253 743595124953795230
73065833111353853 146486722725663464 565662049373697751
978793308099269535 389431601678923426 185523155497269097
814533311756207410 623046416018934866 537448749015269366
711099258631286799 757604622991434838 638404457629525817
632489227507151604 803644413672374093 355585915621247928
159812565603811443 998610856233333417 359207983293467371
545592524065641076 854908665529701197 327745216734416845
394198896613257827 316863340123669110 729035590182206467
207274198646646555 416156655631159638 479078713051635438
184197842642903622 780971420493893614 525657554923950636
514205206997383925 252539221577413576 996262929141815983
702787096179003508 644262674770517999 829795533774024348
936731350308691793 996965757688138610 861869111659037705
566351471015574491 822230342541728756 968285116014274722
837874512141701346 658032578339740168 922800062818132787
415734717817292344 746197487707912645 341992437907478421
251084538275093205 118007806472740243 951176926971011692
112099595426667894 722537276996520464 187944619050907083
246407348080252267 557161598745233801 870347783571011676
83730525538788904 826034513134537355 868097575195253029
847136616902433707 160111473720764583 757398644788182403
711203064585528206 739109149522876162 592630355552451713
981680037437543520 378711366427223167 419237273306597623
333504402215426195 555783964976780786 520290794685470382
417767298039278151 651582780377607680 322001359696162909
278184598239845957 364530677203221560 949795603570178707
112422014859133772 55840359604995872 518611019569703757
950524889349801005 629278827359894625 74766720256387309
524874506902075653 79195094489303290 425446065913164698
685914309150070871 824953556650015415 150837490335161364
743966399144467401 700310089036706090 773791325458156947
675913998928238214 660531298625206051 268348811418836020
969424608757290032 688439394237059527 332234634309143250
446452605760497675 963234362577454614 681589173509388819
520675779457313345 582893005656027478 161983707373598220
561588346216741174 214734835117811018 282587973748635024
295389503152892075 629735911753248992 338211313838638814
498609818034419030 310266594802252515 884981691423081810
965044961455694745 285898322326300426 622164356399945868
608692954951006102 738935190095607830 943975018590697764
23874063467594427 2478347250307156 474701847041496974
249496586290078962 399202414410114648 644861251838712325
363937520845302344 539398153068400860 579394788403069607
956019035318709166 394372620246416421 323497623707304723
892045755808767945 32527413497168697 273810485741247249
246979632458736620 697086664081904935 856665448170401814
912821459063457173 456653418914877557 769982714051125245
97801089659325841 1653824566077774 276784172053003504
170577534092020195 798208813570182530 790332137274093915
893197058953865053 48142554781310784 743293999688159902
760854269846054158 646848246272645589 837374471201109449
685688885941476134 188625326759941694 402243452136865093
28896137309766418 735198982962117431 715623104978001864
577771695460940726 735555515714552572 890727588618938231
815268866312893488 999565498949530364 560393490195902026
137826969229954932 452652285428988928 954169294231353091
13559714328035581 387820441817090091 525957586348754024
684500171890107523 799516507783663855 926038539390387868
919142297640467872 198774166853370719 273507545066271841
671804018076396090 631207190625929589 883024797060921635
388067063455742036 101501369911842649 704456682494286277
520015291752876959 835840774184609573 945700535911424464
566361258291355402 954815931286221660 617782665749683976
985941105267623784 999434862604404426 246478133438283264
14724378946730107 703867679418251879 645584902831295015
960505463068016889 115034335434259662 597958054407126001
244515122013326418 968661895396776918 290662052187122874
45061074968905403 404150763710122242 988516073661139700
105276355772192442 302099746735425860 890174479805354795
369944402730941861 228651440635523245 308120789760451367
303625030804885278 588679993915343608 308222418306053502
613247042695978962 904181092064422429 952849217440663948
474634402713993336 433206074025342325 870535599654898648
909837826916355745 403978339479124216 663549096564065874
404397839674530237 316084509734376795 395524908033357383
455381060029388449 10966230638749190 333595933886712631
942684155618067375 655206238898310061 479461626985672952
699980389965569295 709479666664410269 187246420972634825
30828347871230240 35880826403557781 166140706556799202
496623327946602027 190235296999273898 70166906193671703
967021309580889802 181920707822801606 73829481949255528
451283224282130336 657472005731579803 890766826031475739
175579761868692965 220087167369429404 551677543209899458
318265655974209152 844349099831676383 240863536500002759
177033928655338158 716255312442961149 872327582534573109
703652194403321590 260838605486926554 58147233205598210
549974247343349694 692525445044490514 940864926696262695
225990903991451786 157406828533150740 253340121859542494
947457054386282596 342453466442858177 488966739343629294
118991428504992108 456463175681101805 639991650081847359
706564153355989957 3585246391935645 477839869337224185
576247987239411416 33262287859709001 455915447123472819
20603370613145304 216002027503568081 895281365918301894
665337240437453409 771361495230315950 213405975793049077
576235081691854885 172705532402684553 674937054948206683
988210874799815671 970516506955110686 644272290814158783
224073209209131492 414761154894848338 476307429656113190
208403744165027208 601985007352300021 40613438870415675
737835184120329648 620260458816098143 149809635392303942
217424523089717781 887735028456632939 431907678883664684
986891333602812463 118874450844051435 420685026811721175
89129490474062810 430257767749561089 254854464094443282
418017133502176479 257983434896849840 528484485498124479
845479484674092678 441267720615176222 963887235237146368
305410134788293482 783925071501740668 810982990523196066
615203619278853762 650629280689020582 763401856311008972
883672844271720517 100610549489940977 873788344838232102
580307373738408358 680899428323138613 710004965522123360
208215848887232034 563891448623175118 336596282284433256
51016497463082230 728188354755585542 346716168692628808
624056795589662517 338907593180927286 477237398286674613
55508645743866821 133926731255005097 212228470655769389
636237860765737277 865738372437075600 227748654148410424
194367894194118924 91141305354900548 871960592327833837
158560506355554528 673125063890364154 536707833492403374
404807486295487104 533206810787003370 600433490570176301
295064560148778934 737273586332073640 594639343470381571
719690417891596794 786432432331982949 394480843200886760
875223193104929878 91877311680205573 641850496460334640
994807644508804706 246725627314775600 392180512654005963
35475975793371899 251039916495924027 636230377490549000
75477554201172125 339036301371115415 137538251975132320
144835066272599694 132545512520819720 523800668073746973
340179589451061275 160224531155746552 856344928845836099
291340627502034044 844379662040939829 546394633371555722
324116819388300751 565122135750298370 701987120316446701
58674871984331051 232249774132302538 974401268307053237
214288284215792432 792937904942737090 99171334019380105
15835785334269969 239347184553020267 721035502486043172
642252655244322127 77429472722651378 560465378949907200
403995326483951869 366926649182481035 265791120609883256
788918736147703722 685391266940345489 16635500248031231
853895982148396146 26783361111879858 349345919300690612
57875196769014922 116008108608543182 208336336911038677
257928731217460740 167324809692539205 14522901003322482
562826509441009440 758857097944977247 763750207683346383
511018607644249050 827369052708255337 44919463377048706
221637232423638209 167324624922045851 400662225122129822
821763610802843249 181344679190522395 644216931203312595
60472502420055146 240280850427377672 295944507019362771
755009924333161416 233929658141827523 804081859191352457
963960955164747871 981946949484799032 355160049707733546
974010149277605364 592665070962921229 441402596320853009
351963390149597299 151087643865938851 292378907738584775
355071981708605642 875589783957809696 114870859467221186
515521990206561511 9045087207813607 636617304716124895
664166919817251028 297801291686778495 259037968277520925
618474217985767506 252102446474682528 594487739963022795
966896925835269991 775527637519142583 565827010496321854
894009947452072854 648477694488554270 628730836740340124
251126532987334233 7361843322949561 397955085174920629
966722800677331153 905326854763888994 890912036636391167
411102102299021071 77415420252009654 725591506760887453
864885714063130652 123348432743900192 795196768501277478
583549813292301434 295981885044467708 152439540124667281
169410984234946595 509695345375829841 379543809934584002
724631804185184322 493321466628591705 95047761945018152
172869670802178406 20184319369843718 97352906128930467
895352256844022846 538501110162390070 242224112651656729
765620030841569892 568395377068746605 302937369976882510
706444510370839469 848772298339032596 375764030624535792
992232120283697437 693045297367708803 161233380987760063
889288774059613846 129066578828841716 536662736757103919
684779642723462542 276974792796798562 7955625392866157
493684577470202310 82088990557134896 940284966723512611
161004566405805810 103248483069124694 534218014919576942
602346187881099447 681902034188567622 243736604933436242
420857017095360683 236047373835138769 575264741703809802
293375409935731764 906092222608258902 235337014901026628
373086014309460517 965348536735137249 936200213430415219
136619432277258926 272326681348191829 985448845643519785
73664651873207841 155876452600512685 673148853406330210
505349916045899264 350463440463827709 117977144563916057
973895158811113155 249219134387520998 646651380600217356
566129291478358216 976782817160934659 785698950014138133
617636215711410502 689967384393109729 200791445215129558
667825370290996235 441683814291015490 816140991489382575
734470714587037509 920269699087527595 566640743092318791
188049811786068091 29277292995536499 367883868806242080
353366988032592345 725802951764364230 538940461751631323
877178141501657606 247011574627608078 237579749586364405
142441321770511866 624517196261824275 663928054779918943
572599832158122678 91884151894194618 166231050574235610
729223073867530396 190938333802911994 115738020827225341
78639633899216845 836378262087144316 859976131250873109
775173182544736041 497976100069455415 483385470847152387
821111320591534414 719029636458521390 341013149113828421
673911619649046833 690636604171968865 581220402570281387
678606758211222238 57194351034412270 712048481347108863
56002929207684431 9712195069105238 828660055536395086
392478260139888996 223837961969081052 190498750429246831
418291460771392878 548868477953335355 432176331681260303
827359328947120774 176834442786090717 854567614626374091
487680045962405497 830752539682564305 151799036103999781
27260934905926159 702388510356768445 640332752407195960
250230391827664799 30647446260959536 621560379309839012
571336247416650238 484212628648352285 640298901831878902
549323893026683169 329224442908610268 739319868408209625
803798658111740357 289577445024529327 877835276833814032
301615387031298329 6945035415130738 469305676792493847
634178729287414643 685959160914678975 107757349859781202
649600423008254469 129304339522978480 942630104385368271
645380053085215760 145023994054028118 114649083407819259
212900546411787205 155311949630347265 720971013727682791
781680455071132792 692488354913780824 435796298164192955
535513736510981581 379552787723928751 621288053329158065
660524654420679531 169955164451942646 767864707568553774
386715499623127077 199585246504564366 908511340575017896
298397451229396210 650913899620524928 925677983369140302
969881601673455602 722673504653731313 21066792183527866
267427148073394937 127870003791226703 947717550523958116
460675914144263588 648296524528144621 511350897387658012
965522209781340170 386367965710886559 632396481396390000
18462259935881315 974723329108495583 516752733642442187
71348111817438254 281061418771748913 212850819162592035
479961577567440726 741803954531640306 258196087817241267
695431955357148853 785790088353195566 533320023436068684
667137688577545755 432172024787815531 645002538123652699
667714012067636245 914692348183322870 430803949671555291
323899997863935904 479493170770427145 356465526329584861
519130058654070403 934180564752996396 14107221488134362
479955649812202639 806329054858657320 912057072305640817
890537913220162523 609095983469225269 161865642591028212
836425972783584509 881619195781650252 197856338775925840
571003800301230340 302075952551767520 639106715286389145
932166403861437871 799251127433018656 614877059053270117
95520784820441234 625321267474590676 691669513368609471
242869480713785555 332137762521586690 119104263157032524
37477270774550936 574528999540483483 269667002686812187
955578538574721062 627417537137678611 471826279372162591
938328497622455971 332541943669232334 757946298459077894
744470921096075412 565087327912755065 833798538516346133
681648864468787921 139024320685869615 664087330137057170
160522617526646114 704427668512719952 603524950175613951
47478870399201616 397839391829048056 253222228959680816
899664571022550511 475280996941087542 660540806727164221
377773205386283634 962141281533498241 143239805490394725
790010634599991889 475349967663974618 804731175209168418
569546112429298927 507052782006681988 321051439473931149
408670799528697761 849415629544269993 356165159544327807
623222820418548945 333637410004818272 700834915637728406
265050027651025165 624020811849861130 416315196937902962
673152303608163233 948728824869934154 447028878444428136
100125457381273177 827130925946518555 977353808513796522
331684614566609833 711481015042075430 796883433614611685
714982152296325496 839618914587460210 92551564985983743
315735706890521851 317628529025579333 864808714808520904
345059148712463761 601100310315423276 5158967140182674
807224965324528058 604580929704576937 639797036905881436
536811093463855380 708946098657240266 892588183028457894
999017683086493502 767813950122582384 444318773781098593
286749032066055672 589447520156311194 524679209213423493
430569781341863022 221027037564403625 476927302159825689
997280388350919962 847424902855533756 527912355083339982
62222192322009444 101931353109522494 205749971476933534
738518667136665875 668925138353541126 167609971138916833
623200843116991573 203660599347600446 458292458778186140
322355361974752307 747382932714343839 759348005317949602
781842691688362315 303023015855778833 816534975094238635
723809413169187945 843483247529345417 786944784559027411
842324590790931028 402154403293310572 673973338067192362
292508673127266301 262576302055474101 965445257362498088
932648069286732723 403984247920065285 809570779764233059
871059579495464116 250892857640996995 259201729018835819
637361460062651947 514484014117588611 1898651892622169
981361822040772882 235167515595719254 703077637656188324
975166709564528881 460297273412062780 198608203509366873
297118074803957354 10671015351652170 179417036363153120
68414761928277940 47157149189740600 33241282209378914
149689239087281727 417930577661733346 682883320148658201
817999652736402698 112768046569992698 755012087018613953
115344198324999142 161541042171275489 835203813508917703
958707923518836841 217190638798346439 35804437492779281
416848767186140649 701309011120769466 649255837461729733
400373440084710572 824719116678215101 955647327763946661
718689385168977455 385882674024122705 922175928553082416
263267745592200949 299751823251498 10399863293218163
901657870633670714 121880571109452412 312699304959056692
678341181703019263 801206685785892730 487656348905181159
747623891393108641 465677784408685040 467298666626715805
430107877326186505 725443073045695132 877639089824348114
450247991163521894 253574106539870699 981062989230465102
762589420680441724 509106817487903411 941335650945887179
749755066184377968 649131398071319402 660380576944940069
996382253684651472 689133305701197501 950868431750726947
124239104190774285 907181007638604170 943304969345803225
240336528573736252 597822312897954966 795402733969829657
522301157041133937 992042864798359864 293429615445568983
81703283083154964 209925589522971074 260564028753553760
593160989568234434 496369764893872120 414106132794846215
120475733224094491 46238974955013279 218476245035449042
138508972997368610 586488999405704096 171291094673930111
671266062488681350 47573270748926985 340221625175667254
144094394428418172 796851492791694398 259905291985251070
492152405332681438 974809412446012432 494833175231162462
408906665517680936 620099215344459815 537677951576442637
86523206645086878 103471032945213880 221201315978225187
332492178739411762 475730541797765420 527821929968235989
787588049635867011 530796839328212410 23112586391420138
81031243881923934 528068855847739101 10249744245031362
701559582995101628 985133260402536804 813519496086962449
146229825329842924 215776167508095785 619428943674789549
201352299152173017 726747135222011853 847637479564302011
441575709205940286 63813780758085183 6329749644149856
507490946617904785 53629913867678134 716238112149924138
508836589197339819 45663387235994109 417448345052981762
15185553148554696 951445493889677075 874648861577595316
810734906201279915 737729058141480988 413442028951334647
370795637376597658 718359333276875155 256669487424950656
387485563210772272 712333197520517176 872670228649991456
954603195810600753 864504792941419643 28756025612329729
863711285689277722 36139268771496100 264179370635800615
875369833889863455 978536684721784287 221703501245081151
106212288427053655 700857093539608258 760550845044674047
406873392229496743 125155511827154103 659923506337504432
388210066657781974 974464249270293076 483410589814234338
439414154249984698 734854343204989151 613206322391902245
753427390443622108 951486611966363742 802070077536776797
271238489211008445 321876284719908775 970100295076274446
881071358469651888 680843274647161105 7999148830726068
741067426289382117 134902310072658421 815646824629098496
497314315316260214 979344735719169299 580892483243941759
387096415310702236 859659755982692301 91180148702355021
776583506404065880 596313855917653487 87791521262667896
47345768792224615 743052579189028031 401330394060436023
981269398829428424 928733773078136271 405212085653072286
107898627543120279 820506911038718453 767065294470556141
237170080215172887 927991123702686629 114039576448200155
191629510203906310 625843393166441024 405109573460902524
321462175381174209 472096034658833257 353394712866190194
97829935759393937 444836357813220417 381867578074211592
429968635932220549 193011495404863979 107413190306698545
65902538315782611 890785614122292793 246826844053032714
676935886829625332 251060896221662577 528465500726639140
887288834232031071 396776660226345969 743622877102140869
722990524270928184 563631436894865345 917888899888623921
58090710826700114 474914665203857971 333608366915651868
32058185256896207 244931131394754015 923248613441138721
923206860023548596 757076247358763382 149092805652753115
122033325048389881 388226339257228485 184867022685790693
202583209250065405 981009525092787176 489332763449989891
4148050670306177 759969011408373664 963209418852573185
972623190563792668 222704242826001056 821888883273903452
434801382975009458 663625672803627825 883692848771478347
532138089721245795 719886136350500387 901810914754550859
801746342377734033 518023718810757704 293422367656130543
66264915158455542 616489888782763542 116375110061305128
798470744771997544 217910649311993763 471574217739174044
251975353091794544 138911627608425544 157829549970037055
740400540869544548 916708720279818549 419076103487034641
451095447914599345 95149792497581777 790711512002033850
536645469923962282 884935614806868041 936310075358717918
204980021068253962 204710719720463806 683741090170743377
534932161293171868 147886586353941324 694096237977263950
601810203700756860 303165242387705750 812626012931486831
782468746950937898 152726941789615248 73377443907767694
128175544486288261 285750408497260948 18108930824297369
266877737766546375 912093658981835366 319232636070999158
963231027162804930 630400322539841170 630214142394952212
200084662163313192 823775707222467736 998360638083559394
36017188755944761 399194527378063837 260647301022590093
410983287019138488 583152552997251793 524758728356209661
799681417461307803 893085174709659815 128366972119033971
990418900814336236 289723954721560755 880569691366591076
549767032058569965 701214083981868870 209085660155424553
523644152934280217 164016580768555724 285718164422949502
821447734240689491 866368597612999981 376310781527814853
319430965120657769 591505368534638834 878814772036831604
732273892074915409 477910884786054298 9155832380993472
964009551227078647 533734824479003139 872346613406227727
674907661506560489 125316934097901875 636345575796555842
825026904366076555 212830336336006294 765873240301325783
248657822482068359 999117439020227115 469380617026210888
551166143527079189 175734450349545760 27795760351327447
560906407577436057 478850132206670651 573889766054546301
158762357294773728 667210042644951423 868387025186914329
541504731260863684 780156809331226967 70351216196113384
399771238618215851 215086466727059784 854359204853967537
226877277553912380 369044611929622124 517285567174865436
9953141199592217 46263164298249181 970856726385292295
768513889238687621 534970291516172341 771080234628417155
266953010238635427 273216737244322681 505605898659721822
416806396424374530 941856705331920507 117720766288192545
779946399712109406 74955105216118152 574773384326700138
854717664050730588 153780661552252093 868975385005567028
53109280247500865 174587354355181155 322682671996976557
886594195201868482 435085742729503626 190247573023167884
706981492661374523 16795817896138818 667447222609305770
446390019131751615 910531561548384754 78050333729799955
462939631948493617 953072502419020881 737028937374071307
431866953153660834 764173664522867814 51903350743887915
555156756986924195 538244935115069212 719159463191764699
51453934166232530 296450242465387238 485648893481226899
224327668721343972 692090013195393377 664875303446264794
713236993945938896 454245309828485900 552112873958888562
79420538143290373 336299486777395462 916508055226501995
816147203793340531 323441584217987251 819967019137048434
627970795207720497 31562610034034945 411672998409797264
643571577667444148 247310842385726254 76186898362074730
902961483564664865 368721206012700255 903599183403821370
211935851352043571 466986811911474242 932524961850972803
762613744164508859 184033832800429972 404482545532652686
65320465742394412 691464260024405555 605960789533819373
639016218281671683 84709678469689528 377477791739353284
803225465651714913 399815562787607927 233190779373177764
929218164103260291 778369342916426061 880251731426247168
95643743483365569 751679894083154239 70368431623879856
616456849695543210 25046558182297317 161726902063424699
257600401363220391 508659750122656342 751577549184303477
629534702624285041 373586117127697712 688344191087251274
599590904554426579 208871260061890022 160948319578385321
282430940633060459 21478144376501730 839692870008171251
554588182130367838 103925082308681051 610394104032848844
629759075542798748 130283611411182064 911261826779741486
526087342699811910 873915770495292853 244946573483347140
793226702117558520 611967270507984396 969036789096292377
796173309206557602 923071382445863454 145638959205338000
555998479705098621 789735782459835686 245863925585756457
808353435371953341 64114197828190009 536420300276883439
467083028277707786 903985096249682265 694180575805424714
350901530566459418 334209750373803555 659585387126593625
426220190289136272 581480717981134628 975481122670257034
859519494120843875 798259454186229755 929326698708014818
146350489393188407 648800276284966889 427557897677184319
408948328566233001 351867203670376841 488348342186532108
660141383156949248 552856879566285543 807085469117606423
663671637966531621 536283486319163999 643101235297005972
138093249265170472 855993848405640309 658126492762100599
257303342469227060 525114184727070836 956668333314018234
341514176434186780 330691039778010984 256476453023417493
295069112934270544 444970099028099632 797211506751362435
187164509176107576 185370299082110911 468417900051364501
125393643961212613 407847491302508870 312819660921007799
10074129799891172 588406056990363961 272537596882777621
950337872012192310 370087738557093926 936896848298803599
199521054768050437 580123281529468491 196519574919821442
637413184917245648 261485826862274245 589812682952653446
592199864684089832 21520983297054920 392459021997908752
623703950374623400 690684505278309997 388331994663339684
407028384058219263 424483400010128111 692724105516983527
385633034112589167 969535114627991470 255137846332322489
371507042113751885 470619526160393837 633253225816375463
780927665809540836 108942819452836187 217947899935548887
456673573755618937 568738950756569731 953618113877005051
463691420982681885 747277189625359622 174533974504149802
209837539539292878 775563844737398157 718199743093724746
303289785354372984 896697938133101734 760477916993208021
882275311443475601 565095706198474167 633419629816324099
840140022483357027 729950576547237171 269581735153807925
514493169508293294 437083256599375112 698513853285094122
711593904303881676 740946491286227715 38006024568896350
30697718087397505 12854764927931521 151497560439521977
915492438200471135 302373172368485150 766201281138742249
569876517420099858 273256060863949517 634906904081450198
322626032175702419 408814984354758062 481066954970106576
403606520448821068 532686193792211397 622678447984847547
179303755584042052 389188471387627008 869168841807760827
53459398116384635 464485528921792757 13726734790382171
485034341673823158 236612403180694921 819540310135037585
992098638033776673 437630610117537494 759740899698751703
294347971722181107 882005710260650767 499810199447976356
647616665327065714 430617065053747969 346398172697487793
512029273460887692 891166583933212153 117620177678603019
87079400901990646 6468848333439398 8256405723478816
506071563872377404 862419824536510859 481476642198948385
982273353858270529 564878296734554412 230783592611215600
695471097103684991 470451199028082762 521366491303529193
473012171910960134 699899028157561159 396680560615968694
412743419037613625 612514861661275253 54690550743524884
195746325933825298 503106489354803227 945645617604427605
354426100766642665 592526153249683092 299380777003329080
424255913172087693 922179886856139456 453214959124608364
440373150519624063 109437669671399486 749466730302556424
221159581444359268 309662447189983345 490524989575519102
415931434868865560 377064805146476131 273130005632203241
581125212596713634 652170455297702609 702288167472159968
907774358327695207 250467743266684638 530223780814129644
43277901280671329 369593080150325141 506126001191534512
459639077332581049 764577825708100861 341371987322183895
364470980425981293 930722216704593751 456760553924586745
905389458645222354 88629788696973776 967170254707155830
328805285236955904 29690868144065997 101531655284311115
659234095675631275 64837072919532294 661925975340338007
666617791670530224 144263352542586626 980106063249921640
200604817568864916 520794451230043007 313413451542284972
363043843951373821 637621046492619593 630960645353135760
784381005369370597 453979803515035303 442894040508907834
358808730814482588 494027326265210694 125811490493452014
623499095568811450 526195934770715281 520115379221750144
601713850133857204 602614104241752102 989099701715996020
852380750497047690 547666783909894514 239153910185259703
266311891813666424 25311444192629516 800909278007199513
915220437787140974 562267120419627785 324397476348495994
635084986498012450 810370307988526591 689245476606968634
427982520564157102 326249151400921812 703558072269886219
742679595454791472 311369156380231597 960361357543994555
85262217759382171 783102589121752468 812689074874869807
721584417157331796 483935575957233349 678689319305095739
746631054258745908 485498397282470246 865016468528909831
49943885501817980 68511151921658718 169491836308308602
370208546667916737 334525081104809416 426558702235167614
941181145143544197 252583513777947883 911786372165580848
959229067821420339 88808305998485325 182536973705205329
570319339539936448 365795143325858354 94479574023823580
483646682285812544 388325753762726439 146836067079961088
167063485146615317 939058048822488576 388093650969459502
758966437670099003 506100759651074115 518744247637693508
795361688200754473 580826313666178370 743634985217697897
712829299725638065 464710292379516536 59619561763750566
453962860141604336 414960500027378271 545528223804779812
545636502730016188 191340949823382799 929216284871564650
663406498855845184 738542262160640501 971632437586761044
567724594192031570 854474070354804585 559111338009828225
239679598477070359 219976485875018887 150093271641626464
641209527777468858 26771958777035781 726245480550713959
386985985052758471 62720746585215685 531248031500581288
173652574109605358 97505737021845734 559510081308743965
578144768504213694 622353854897833433 500152851698968340
463172822066643898 563961527372908174 205193186023875402
538525068164915597 516361625693230755 301460355126002914
12990765573493453 755228108071781686 597664747244205736
260920358534935644 553929187834170128 948889589340860710
878052384727281675 789150015098980140 80975526121327470
470591832676094258 48895503869660347 955286824750617441
202723176688966184 404213431420895313 579660959477955333
125210970600185234 347190627617215295 885677494301885471
825941131308872501 974070663192863472 998402821139239559
878952367797048646 120472938013779708 660771920437741697
99160385386492589 305916714881009635 607712691212431399
302771474451670702 355523421193204420 716006152196500644
914259539082068745 279692777722708624 380978925340184535
290167432111679111 32135508782944859 737332629721894134
214459235762160057 489427784606860146 756281959622216079
961831347847882865 374038763252381713 72458593227934820
540848221622130492 76859167690739716 369590698442544099
964837914131734460 498531745820462438 772302042192615409
529918713364747423 878233440346111900 311548644472160189
583674909349996321 985274139982208951 855641880360574491
108596020950774270 965399854646848323 641105252497054602
29072416797462446 504860812598247778 821717495828629831
32130113265027192 559630346103968772 170699096557866274
146465644618419924 633648160063610576 751819957901270865
788840526116934710 252436418337754814 817485989155265995
945185738093919875 33872436434536417 902332038196395342
556197222238545834 313216308255627579 287715453490554854
937197454677476263 95798909042452582 153722249800931791
470646577476216081 956638557269616399 481716974881708074
475585842272171024 732695292618623895 927095277770389347
37029330643766733 488128507163163506 61967674436468117
62018021242948997 148025866847068513 727925215000054261
42115316567145902 195825639117052403 561762207379316402
849791127815910969 631013911362161007 850453943409460031
668724497047308224 55778178889456223 918732135608517612
719570833553839251 834782797862971188 227748034257791535
894935058708557831 402181539537828895 856453740106625780
22777052050135539 615844227993254718 979843113699334582
849792552477146761 412094443621356713 345619821576607718
65396156025527621 837155884616203732 701381054042604203
104342301998229463 290077875957544240 528195781866559293
167001262969085994 523824618494097117 892120082496636545
669454073300534585 814555308238576618 899449123668872977
947456679187149950 985209967570608661 585627115356881670
450900753142185592 721181226559435099 708186682360944141
732214503830092840 301426981939445511 6776705857668793
669185412350385608 699144099298056224 687412723358251593
133356625740092784 900476516266226766 706089065563344227
982656285207268203 601029781205068070 529053758231244192
947926178310887026 659328527164326360 582395513314475737
370456078901682482 956334636779397216 783768351470449593
621898744234810192 458428188566630 186570904107796821
405348271409930332 183600991878115772 292649830812161322
688566817737682708 764498629071971010 645927294040218120
661450579333248060 406278404055403883 466338185216783395
175861104677164934 267358141136048106 574142069061692606
745732676265393791 130336746607439706 815773541653921383
610852437182619789 542075629533292652 752297998444238310
787522656209401914 121325708682429071 198087360486859660
162960684234699230 912231995658483076 5986700235537372
238261097921617120 342936185233588275 854374845635026045
40096536164673588 250929061903242094 305963247503765936
775289808685174813 605181966691784561 485015115808187064
743976859739679411 534138891766539012 194323426514989598
337073356537601328 734904314110337459 550215340102146579
374242873592922158 230668355051697847 674683509856112037
535928450000191199 415364001352286034 172147333922733858
660870391928890543 684481550868627993 861761720143006126
149359332018400447 403828820436363892 359274729647009349
70266913313541152 346338168287819480 503415586829864651
818860330504415750 700436923947207909 887733800112242717
257996785122712557 344420123506543304 800795544990646803
704524793708794153 160431489835185505 938884775031387914
473324669234427915 371343219398009644 948715903021999627
1127638046595363 850206470557353983 639311205588810288
58940564542144267 496171825873396100 167410871948598906
676980039820677046 734591572321109516 660971275781085541
494944565916275177 891002153698872629 186947709408195511
697492048856974614 193774394412157161 919073425293645472
898702443117298270 845308983051622090 606935384844497178
733708424809555158 496361286282080437 300848577461060936
161557297383239720 62603013845187286 899077517158643670
581834723332285485 657145151629535975 544638190253360019
127771848010102379 854877755976611525 287811834765118408
662603661352892507 330692454020320859 844554363621517026
364880178782988407 699620640981001418 961246774610656178
75181375071069630 919217107800039467 700659703248338232
370459431205316430 641553243377205845 236329344850089445
521397403748146411 262077839893104942 96984701150302193
565677064630303554 47458945746588893 215164903773395713
516851617390304443 822498592322300612 946028384437750292
694360752645020340 848090957444315197 837547063211217491
585329577017680925 773751186331032815 112479026972772797
7247269104692699 896845999456586652 396097145234911101
873259470536193760 854241514756608450 69895548147677408
983081885056846822 205836152719989265 5410235183760718
790513893095461416 676660336922253797 937970956408621359
599827946493324618 833159389206846058 673644375544824293
332530847134739416 578795967673009778 817548405705633684
970907551947624329 923410175975678448 429662526720765930
925137402679007545 559369602509104178 188970644121369167
902503749902960081 716304139783562993 924945361817205085
689753580820936961 547151867652164557 778993823861939975
379497658444428112 338562251683163653 617170787299927883
841896051862944941 560677986273919867 137789932006235034
682081059260574307 917672119937597137 165331586670222084
695579243304758767 328186243696019043 304670352049433936
747299223028874261 528487479421549669 632376342020146394
261145748007830112 238264612640500151 803479334440127515
628785247792167652 120605864987531644 667624343338762805
455322310095849941 432702923214096031 140869558071761818
462125383170520320 734976685121368915 389789656097669714
812672891412569571 27174758558636759 766077293964034517
246857578107122387 240802136994559035 116844908598905932
543910034279670908 912820852103661067 670381641564869544
32122411400398895 728468116819725029 666583399886872957
588873455626044674 800182359859210833 680113690651410336
422192051250249906 590923756695070519 792483017651171762
59362601534427828 177501620126065620 392277241058542081
516211640890447655 246816609268880415 783082445173542434
567774118550431796 748341708502627323 804243083725610555
377340479909385307 305561242903554677 873476467470743585
76386559920599167 389719852722273136 321569084558913792
227612544279927215 957811726186211019 929314042467080422
108703240123031489 575729197287010981 918532354277857023
781347138862334284 638401482051657713 615900558223911050
957784538995210270 426475957409338129 30530488260763103
873608681208502166 734048798411505764 939511132579117287
443057408732929331 987244321480881521 111597934108040854
534959489014372876 847161119991058300 162769498082610102
573730244319721609 423413256935177481 85497398052977280
104526531048292974 422195902085265840 475292786445941257
340013652386819819 157440094092606103 474802413140832645
87507932836085132 229369984574213818 418428115634714791
160892061923213867 963193235037084319 522568879368954807
957760351101918976 64097181038862009 931538184441785750
754240488021542419 927867039673890961 151994114745014776
564679102222110331 81546205144912567 715842632997032731
785659074588279995 963980417795494799 673435514464367086
526150890197117420 38920815094750298 758220062114980794
457803977795415523 377971657210896429 468927018384476518
744002550040303909 153285947029756165 239573607194217373
671843885017083358 893452670967133079 912179809252066466
254921967980170963 860329027940172768 466594334966684463
396671188818069316 273704723892519917 935521919274322986
22647643673539228 66047943168217961 423444462327166694
813250543444921467 964046719253330388 205193673923976653
586948432003575865 737999698019475008 949048738991456382
76170982249993233 119911276461739883 126831447846816993
797247764623155996 827494273970156883 781338758392333415
90304262634993753 98564983415164332 816323507699711686
137563077579886568 837608477525163473 892299031226569426
92131249380495125 786970960370100245 453029396527267930
950198160711033978 229146113121872512 208733901748490677
190146528246186924 782883264602353121 167756828959236286
600853823251336201 460965565248248352 416906896362039820
988907809364215676 503497279166631830 336703910440322880
686443370481257072 92018280969438412 260030122584972352
118413645326447195 312336233232559415 609344444512446914
574924025798039596 597052560706709729 50431784493835256
453509132211805420 834084481873477115 192977232912380185
454486392166631946 435941800820757683 877010980661418848
226417279159348295 820994331426843421 721390566315401739
617925203558522797 160398092911331739 266010262271310271
930854163793742556 915646960242653761 182424905010628681
290233146377065927 880615319501517936 877698177597425941
238251119551416931 106413223126622965 585740709940764176
54032182935115575 673929886572050196 250562424381026102
178146410561629057 337947094058871613 938433848196001094
674682986784270699 537693887537676135 110911528053941715
542013242105103886 150281395344025543 836989204827694579
680605120944386131 884576711211394874 181490141367205435
801836121958616891 473967346897500930 904762110752122320
112775186798765349 718061553953278931 468554339703404680
358033319045738408 573724796493950239 148534115382680785
696768095864617552 805618532933423691 880801552531088429
26411111969376900 44142577565416630 835727671797397838
20315900836857826 852294814130901667 954310415549196963
984259424082030422 218741278619097490 323163659945714281
630663524416961161 128752567541175274 507452203175128475
624203019403457818 844779550586433848 607082698897629632
36518403950581177 85768909132395530 588715299022636424
634544536824503205 690673248954121745 19853433297873834
425657358057014327 113307578705988492 918861436546556884
12354594845668980 718040135644377478 636098030670352008
531412744882444447 796156125704841969 558653617997428377
116619733795624258 727021016999319452 289977932239612502
77442812234999902 228601557550748199 733343630973284642
461108942364705565 97478809963048476 380279446506472525
143545505686968582 564549381256651624 297648237540751340
424698691575075226 856790749155263803 702529690860100512
1360963851715888 31265267328971118 649485878542326857
403326434407398196 334728311277135652 620581916999971782
188236254600036117 931266918266260355 329235666622368905
561475942430449379 223552094312246418 124346505726306948
845170571600178274 348433955849080036 576012339227454315
105093406033434103 687244928198257889 382058355522156437
289943286688812147 663429067210828654 166701295292238385
711817217296605675 134785175219855811 552064341832175298
976366167842775277 571015479631832668 791667785044472097
674423707337285815 859588186591447194 983125911678522751
102779378510263937 353946791749240150 641155996925738581
114802000997442674 824000116665808540 64537108801698421
803261335507869440 786265139281013622 118090424132116816
639332822239116884 256062988063601169 353647573010756691
901095363867657259 890261059017229806 360522263731618794
276679801075325163 362964404337544455 179705274843743145
469073506208043098 831740276541780407 854576122439916633
231779658895654320 464329482586783024 9390136381379656
571588915941337051 539173201385780366 10778824718525609
795001089640767910 332548917945904361 257174871743338894
819194805675831280 612697614389847324 728320324231607078
461653076305515877 316494722837938607 53778575764030041
71223760316178146 354138870531338355 223627110944830540
760745975040938902 38370856569216991 944791716548153694
212939441060502351 97617943956678272 322214632086335228
369997411188707925 541663762907618288 666192468275077386
854983561340539626 175125155179422954 268486378313895227
977087864214278985 415994324832098932 256921156574345325
621792215160223595 551368928950597279 272881402288145074
802981341640475850 408236892622135848 652483859534323731
283291038152025289 534850550799627090 61489850001834701
92050907902503079 10054805073789110 297496687612894535
504194345545220811 894480959326143171 592997040885205194
298008767900507533 97925314333382443 31862199539266421
609675006352146340 288598974683958047 865027132776463561
250012216438329596 97940991209313528 38441991913239859
211248192684210344 888846960446478077 709939491956740035
340417353276969321 708669270723619456 797098428122250472
557305231244101929 957950440098691736 754364623361847129
855911867760581760 812969714233210515 368525961970925346
900266968088662985 712325623380420698 695389363970835573
439561867424563052 347539411767285429 824320713794155104
461524938068443322 413452044012313729 222692708080647072
505366185232974416 941707575925871928 283227446174168696
904944606929333588 413995432878734408 265751828848333369
522984957166189321 412447532087455809 649904267565684518
23114322622908666 428683670694183918 386228754630157596
495039118556586787 160199673986102840 677556788889798005
339638827163441982 34396583410688089 39732598602251421
901834069112261917 124072992265958208 908297893795751206
548588584387850038 42972375684779980 878828764106477914
72710619131827403 440091273470012462 837549089622493338
417102144605773848 525830280855004609 351402557830366959
79322834354709143 235870817635629178 905211320608064251
906227399142772313 596386042952980298 194159093981937047
352689261389831748 848721552445055561 793379678821214782
233268768799927474 158385035785104298 873468281719105382
217165808858920886 525884119933274780 771663364187749758
936899662443458737 886434152288853704 205905763677093896
906375203272482824 73630875420057127 972354265663660951
821425210466877427 215086486110381063 887940578433330030
448920305711571463 462522390570221126 286047106357737769
829128755391335980 37875351952429116 17695612932240921
973753934472173716 244132692817028282 425936632747086073
371940768678690929 867566759046889318 537805524709160039
930869131796305486 344137461342141106 197027053680736545
244951159786911774 685677973223953382 117764294365396203
210212706900539980 518669946267352801 766117683273040309
631001038118527135 104728271753366233 833788344252586568
331190510962208339 667655105298224943 836296107708973235
939674009168370938 507240796614762906 551637404892287012
350978599749306936 551717912419035456 898408366105300740
914091230628655115 464642756059482292 859382428698333020
18890143247030359 56533112998336163 884933424247929581
716086211124182077 729505943033864196 184230030172632464
204189910125082527 125575823306274779 245036991785184156
744637476217370312 917822069273884664 546174416883807171
903419027611096713 144558265194377996 703745191310242318
732928843075021203 718244387536000074 158257282599778431
729560994469184387 826930055729988395 442200781726933257
357122696136125402 568444077585381606 773100767306026637
379452129063762165 89288048483620619 942788006116286601
500553415556604316 730602445463369050 841505713550243848
992189428258524006 280391852150188472 81517725782995773
121962863761724678 600349464539425011 703257405931926273
679240548526889212 656148933108361216 770013604688205951
203938318920791326 723950887896281106 663445065819016322
341821489836530538 161166036850702930 850153769212530756
641117357115066059 604609547169546435 264401404810536297
440092662387657923 152703408258598316 995570437949838981
912983878868687070 182330732071595708 809274458351886618
566761067510418352 197992354817105312 64862443406737345
497435239112665229 388478953962382095 368600976133495147
606877805161178216 490102635320131986 793167680080721308
682136935434802500 260711148391237311 399695352852354648
902830593296483592 779709586719659018 392920140595089585
816642779999032338 700448167107386931 345988257676933369
644463964093593266 675012052943698319 334520828414430133
833505004530777604 623647759308608036 867485614697723322
894429558677231712 534214322246990499 337461746690788309
640993776902395382 744800104302059937 47903309010369006
524487489456445072 96435103692752087 212729045199731266
437144550000648569 404161346208512407 753192273072216195
618623695191235732 956222967248512905 165319083797801751
816927384342114583 930229275635805498 951515770726603232
939849756840573617 971831191200327535 618642390447754632
907679645177082864 684032241948789765 68548163422112593
580972419370960273 447922577528463638 765712250818327101
82966682071355585 987163733731993960 687239733038085359
457441620265686436 499677637601061974 809339993329437548
655695715346736639 858942218950001063 705359706771668860
597477722683748519 122663698638574444 644257331869154174
527280194824251301 350770734659582420 111270382942472108
646548558460966772 234130500112247541 331254756215433546
382539230529771834 454222127834890710 780404843649792945
142853874986053513 15935522280348590 907004484510920176
348734232786663473 27437249440701698 578500757453125892
488235509065621034 644206821135991937 599414714998353334
188987841822004167 701258247932569519 517841899405948387
115522662155257294 915414757711318509 535982829187771149
456839896907759731 269943643089637368 554228550720291904
469514355018818743 211548958932716096 488655867124661253
120135511750373557 648123662289638270 313620546692904373
798320945868016972 118935061826034917 132173191230238443
490132865093680207 710404800262519099 927538218349438134
36739404142276079 166124167425153265 25719103602906595
454173138637981882 241329165428940103 824899820874138229
818631274842314840 498687788940923043 175163568765584906
462282615641699876 199983307396244300 365991787495079423
144526999855916056 613833437472379460 79093652440343927
782823793347628640 982052365127904444 174836962077950084
721237331570952240 640243136905956923 4414860587295994
557339573566697613 201306034514521578 257673158774897427
250903863183558710 910667916421611681 737706284390250029
428520867328982694 75773321681273182 240829605669277786
758155547685963542 125662041602368481 439651168569691585
880745888132170191 941572796675468782 865386267332844855
129068675772209177 951734932333513892 931600367586952729
165280826273661033 346835521133103956 712034928197306929
349495321836157102 387384959291804148 231842923229431627
297888442704155608 864598503153532661 526430569542902718
815829989864885088 829207669030531474 803246386472727804
511288419578510184 402261775644160211 488139597744035942
244317380742855651 312396277322230027 256154604664796511
541011266678044907 770223154424835216 491267080663852399
566583662480070073 663420871986339289 774692699921357360
442059837079081146 269187233576220671 994070999998470770
998391416375485570 601490339603040509 545983108408534617
181478169624578324 588291119848970899 475329352880705672
441211958226360647 340332220621248943 560242310082374929
860053005348062322 535885542036623945 25906054218838082
772919606397972715 487802523069375307 666983874537850452
670527903079682905 612529148457087421 130749247084012382
932959790486018133 917588122932931238 35577764496938077
458412278836451646 437925623928710053 210973402215681388
641951612134902091 442735917672574589 457733939665720990
332021377002594549 213818283191439183 895224140022212562
226887824328776956 841249796591453990 709193066373858764
151759209656843233 730479600631962223 323820510404484350
736238524042743649 891679883057035684 142483079562523954
52111734323382526 956304241255711860 436065792243121885
839319679196622954 556529808759567747 25609795318120109
438358276020229783 109030804615328958 374316573995171274
458521941061572606 456866987410781264 591387154671162360
848446064115295693 723015335410023450 267098527807054483
609488665714857315 164856723688641954 539174565961195853
208858281812400358 577107625565476777 89933938206284879
408372724116636129 247512792470482711 761424163674893043
309666453008191776 115223388004164003 951850928035092364
632664323354944962 659097514192043782 738979610441495662
351534670405963628 978000120351713284 831971012913554553
248810003051568889 514323509411016699 263767927487815151
357195069095905573 253531213821501814 205050245728984340
983032580725805667 335962895779484837 739489898602877455
323281537979581334 747635129805574501 730440423554315476
111282080910501729 637035764944365577 965127965837957832
240778617383474295 32753160512705287 997674843416577278
783394162400060551 345941466486661516 906154989638478839
609796605040540046 769135063217843521 583948760555430901
294402133378263351 600206128771385354 146833863653859054
815582564735460327 810762100850977835 593701073984201770
894822827279057167 89499636054270066 517970046068857649
517912636451770838 801097699453713286 940557613915575785
179785979674889244 717582185820590982 408291307110967488
530725603968029823 764395466902027976 113225345850616003
303940534373202032 172508113887356595 85597147715689641
429771161563816460 918486561937164253 481918422928034059
816425450324026476 413940133113587488 714113625563196076
46005348761297031 881710234313723344 29753156517815802
128356260321955748 266518541350313571 402540335466200495
241455251913849897 822706235487120274 32097730145612199
147414550032793210 362045038213085395 353230783098461719
973127410486731347 448060156604424050 739579728643848260
160304581350357979 40987430319684133 255828283702465232
682181055181670325 44285044299936440 568793498720418862
602229998393341168 842285406077130673 964693608253327993
639507949870724257 936235450735118996 277150962872557727
271977240868304503 923218006989983923 384231595931282182
259043412103062733 417600322198295312 469838779140353629
423989970438483822 536281883518856806 577745697634699208
653409766835650222 735509512282970419 620012308782471717
427394316222797217 272819752529344659 411192068132161706
861792198585954718 54243743352518075 657372356909341446
135328402680300393 39301644644894685 238717654703374288
228284815401732828 841915493584550434 145153429397033153
237796673423637975 746280807361561290 630970616382270885
122913537799833798 480309676887333841 603706152700782545
380725227242256121 851003003375073896 155535022349079178
866074151971214802 812927950042299907 782227239601221787
673312134558359460 44110199788183178 745714648196105863
232364022024418701 540093002790856654 774408702935642143
865313274964048612 785586166566592736 32984091607853443
424442707987778404 336852312619828826 66986280974988881
734821663730401141 356223692585585309 359715518108073882
344534768352302145 283557110384161536 586834697009428454
468655310929765196 568854919161115152 896730833613921967
793429698716709771 183583118458855048 409005597005721286
741238786756436177 468820747290831575 793710209705503081
393345135661559659 284360808609144294 349135556257472074
625517984246526314 653260358397267374 215523142397104909
831299815815100488 834474129887155210 905237281259132474
665319414076455096 553524468564620162 746083664713902378
708316406695565166 578101776926930158 292383583600349576
640099938220547517 205221579122671518 921166650857020931
884166202381541677 279260018063678998 853013946376276933
92422762825731317 115515919267894560 529943813608198251
173457363747456503 796776719783919614 658930629546240623
220517531436359559 905093995699311547 61040783050116337
952834260236639967 562533543375017237 860874171461309651
940637941737169918 261674529970157494 54493141786379328
912756299735503230 79792380370985442 167446813163263964
729389134630880286 418001094115440920 987233360279925422
40901322782074540 70391111914650168 425800742200438937
706696984497177612 440770465860339283 804624691715175696
854278362793341163 343485164142757876 506739838217067076
563497195352659613 355832035448010169 786535801931745013
656220740020313559 461409096760872648 759207414447848353
52439987256771310 437895532166449836 834710567182771689
805968995482734304 414299581905004905 727665138704846655
740808038060709717 539398919002597841 646935398317430288
805722369928009035 99328786218728401 374363948924937051
273283072257664349 539221556615272583 552863409380000783
148281447605316969 339039525489465074 728406585918475482
924839862928360262 837844397282878349 708982877889921058
798710067479991560 673398195321391499 931308573877430647
48993442473971332 324676986140051767 580410450724081276
396787143518902605 13471128026143299 390698683833994573
315065232838749092 37556313302073943 717766491190949781
763230641305675503 710732331030837122 116459597786627958
79533179002668832 230953817486380388 195839022692887988
557445105806828900 787585787165534816 249346410150649167
826720881020037754 408483912275637953 302885207507228044
147470344642085156 938618262947185246 745460121263204045
543868100142147907 535477666970179989 394804768182298529
418293335826961015 974987269746092258 436725273303177329
758985676642289786 674592078332052208 85863346362843444
194743493482277619 788236086020242882 575049796581277715
758286454231670454 766712426805179443 363121128464124256
544418265990705901 430351239304795223 624478329146693599
337145748641998039 804806911450814548 4487870599270861
697943081066222710 445077014202818481 950565520952656703
104773222719875610 403886639478304260 925600395586129437
260651036083367762 754941126071364143 459646669533014155
970999789350487878 715151356479071091 622310902631546675
328033815598568039 305093728801240069 791729688257831997
400003086891904306 369026353077690119 351557860444515650
645627081332438650 27861198528599421 957955071650550075
996395166228327012 244214319024370083 785992713086094678
88947930432370118 101372829161979892 83337397119345272
882493168834020413 578089943322799589 978218357222485540
55177380577885519 290244214166715005 342143853798820312
965560968435089164 27328278627328204 71323509624031176
108673639735784242 178877813640754559 77836998465988670
508629275476177319 442252849394771854 404332413490219864
498730537429650981 847256093013607167 27826274642280454
9674232310800057 230648144943320350 871462889494469253
17092567242831619 903865911596431972 36623983188253025
157272617237915281 502599999171929697 557863097280636991
617913991951373428 887112389467684244 408679283655267677
215996696958302379 549676754710178431 610219743722266201
381497139472394913 868111954253199261 116885220710403197
988355018012019397 360982408089307909 228691474507968352
622930091914262188 427906357742547468 673735552668846063
963042474366073564 282775553159399225 496696862248430444
860661043801595361 322762417617823786 730568622256940176
982090783887392927 421892716969116372 668122997534927664
540322382912435195 926917613328271406 31843652260709629
717944581044953066 334425887470018583 617332979797807170
789943955109509392 585643953398373668 350493652336439116
907358811064785107 881795456744306886 146098435868088015
388499714358946409 264084367089660303 3762678231945352
527011704740188933 470336058061993082 104425130119889622
539140456135319601 264304000236464642 781960560999575515
896687515353476258 912791458598961243 113344239412872737
657296697486369133 450952877904875019 376332562829914816
554116862944000636 943449717946769527 850293377383117761
606745432340083417 58866554713607417 754305946068378945
513949728125335159 352913596780902484 356774359841668309
477782280838542209 664358426857982356 726879739606735129
150564575861953755 832732261208627591 62785470321597988
18592375730054962 496574026675610472 910126015176530490
856361980254884174 861502849420400973 214667928379106360
894868942306928072 639039218857550984 322379893574554886
101282283490456029 849098113951386332 810968983163425284
753973289160853927 198346104960382659 202887752745151271
209975591962079009 804975540350113519 537472027510257627
164268826529155578 372670985865092859 644384117330805606
98614344495787777 715743098337727715 265049400041865967
489742470798112151 909589956467687248 331697302601983689
467009766673780008 972550863950446290 443420931899926222
692490982431764457 646775883530568730 865614199559971456
191003302487882715 294302851897049890 54375704002783913
683712896746370886 436396607273284379 149801063950036376
505364978122304245 945891944677129550 808776573329246683
962222118898256144 499212869839236353 983419031949285555
698327893937341551 440446423839153812 872440513620950304
95209433774316538 419320577772190918 883606843257460950
294626493525181059 50153649452933809 508900347312455918
83298903936141000 668822450080171408 405097221209390013
311782692734337385 672330933213883909 913886822485280424
22704358329738247 428895817951006695 380003249441549660
743807382080971880 404849928319668473 551135123917532589
359317846735253331 467208094454370895 571161462984952548
853127608915372556 621298043398876322 320887017351880480
707359557892413303 503926079688380641 367599853996900038
750002582859303800 237377297637504127 782910375570336042
431450666360111699 306964395000541271 910829951215591970
907423122854282097 726682577856072107 17477284005426557
393027503230467462 729393118003157082 19301438588968781
409949492204525578 108016534809602869 323026452265170728
863330718803581057 81862215985561825 285766623836099006
910156647204373519 475373500810786748 697084434987133785
488848359176512545 522995405572703987 835105454160633626
572312074545748859 80050216712600644 409995006430792148
48485447531664120 586961552718750900 233483043099526549
263052020076480296 422896042529360996 225223933667442766
400849219551491946 145086822512208013 163357788707396519
625782429549802449 889501055622881163 718450984629032240
209881848716171954 996931136717752234 142583580082683077
157230815108730960 937359863557320631 896575939001290125
945812530536212803 860789712769558475 685201436181094282
244481507501127447 865862182540596522 805897527564890754
803294619886661706 875704196011457576 68436806285103393
771345640134696691 558195139595869108 835238594775404908
389762551180404918 92621181974172089 704217617448800708
121593610097225469 641949421499747559 577225127717327860
252719355766426405 255723826777122483 67179234903641771
637401877904331227 748989576511957963 754265274588170946
714139558988392826 43844552164813118 602456962802611513
415496200719770676 505568028484132271 706583997147367419
523105125204773185 498915790592309613 791830044287244942
902360754696780895 934685364339844231 182881490670140308
976823015169559171 438323010480453704 873513893806837062
666682327627844840 481399528838917739 679753118956928875
439220710500035951 163152726344646909 480582171275827791
418686927480222012 886583059777319588 638303718127509122
903662075592496210 597204681760823796 778476419859376012
573730744262620252 691647279192749051 656254566494091390
988120648200443184 456235019519882981 468162729423831663
785114955220694647 476006813109345674 788052804663877288
238794024528854306 494942506655117015 623308952659879449
953221763506771649 55973683669362740 27481449952330863
38311166619521596 899179225404537677 9315343082762489
601742923897571431 602168287967612371 271039399315892242
489853663518842998 205398316213268664 798566272336189150
663285687950581217 512935935678144165 735948811572427802
512882855021006367 960172159789138213 6050046536316242
797622172605673291 2475922739945287 342469975132304761
950705961525084211 683829873894045667 941656412809459041
70612909160885149 604624686525131159 183674084974967183
440126530589815692 240268106611186859 301226221049643281
382267772494049114 42830821995029387 669141826847710291
351831291516080658 93419056061982302 974011843645273125
86336429130218391 333305521316186715 298780134870009855
299749689435686834 629409050700495637 987527730698612873
758837231701128385 364701279350657696 118394352662924712
480444690280475260 621402362800533128 738946637760662015
126036044937816805 780760948272108548 186120846577488666
945374655647982040 440263854450405760 483594659873416495
3570049414473434 344112475846155250 648084034146540036
855620298298337506 878287537204342522 86021762928698870
833475928902826254 466706397904700252 353628419579419701
465052186252347467 321539948093166076 608380222231529637
429910343506887993 589011241468453967 426665907296024928
152889628770050857 367849462453088530 864242892775393165
66322290218732064 515882492437803486 112995926672814968
221313260109208308 915304881519462413 674123484589641503
441387315928021344 451936702213548738 715747141520970075
400817180737781837 942149452280941407 63686399005813093
886128309252074159 663171318572332882 786102676632183255
547418044663183069 154740603336171424 996174665505291027
830083919161316631 556373927604495242 78819307623123193
389966522625642983 949830922200861731 136407374160396901
699542130651882360 639798625100266509 709572614236371714
750020062822058911 911972280344278558 787155731568787019
212433419824001355 363682201286053668 581882011907672260
13268099945954375 396089816683854002 325329161006429953
382132995050334858 174504080366428972 870227482490373000
635134343508171279 41425778833426554 100293137652687899
464605822880623381 346365965203070545 875198738094150637
364584045117226644 724875104984727115 770279878803368823
541681583777626362 649642253273963291 379567318616399933
683530457133297011 475468547534087465 311001217607382439
563341526399891042 903266297201354461 929031504053607881
221120038957422622 658838927514969983 489732703278224265
703532703015921271 403388313246344418 933898004096395720
541615149366139655 45044650577229747 326164925241569590
976245910186123660 195763950520537865 164102138441073981
94355559542845429 21313317709860788 528826565413523967
426094387122984127 800015402286164926 72968807855149105
923911787410329991 83048684354839592 914546963692278226
91150369363781792 612234311421436161 115960213252595778
528700702387162184 176094757125711514 376805043825649652
262838547063057198 258491811908431035 598462822865423954
70087332655200410 167006278145585873 279490397193053865
873703044473198861 286174842460385893 844640604286769006
640131914724399645 149006034083136439 168024945661195396
360791396703674913 252884657080167925 522755322101148994
303227127632355414 327165218232535901 498215173550406307
339478780715451686 53515097394424792 974459692693590359
56697880692212865 431318417805773309 697115319062627413
969409523515891374 415377929578661460 520664768760862725
150573423739830468 330101850728644792 438515285192608742
152495666889131885 14662181205435476 862423132928847421
250465588992498785 477693889571778781 767797702055763401
88761237349381359 190024840295038698 126249564164786547
718143331969526855 851927142409900853 269351498546632293
243459184068895970 147147270188798824 568856789156925377
638557151424961295 986315501299535900 303144789498130480
793402909514745998 727552802772405020 647935868667298000
287940636054706577 522111505632664481 192472337529595836
571110703206856687 379714215121258152 995328064455192924
764347958908289986 48335406345909244 578322343017006485
706304634705303342 688975403981513223 507792500487484369
23664883499467173 147800501712136669 797791809388667917
846753530442795242 676623110935747073 180890955326230582
763575233494501465 118613802865441260 813684221745301568
197197853300688245 319379065897203972 509226093202404688
380621162024556200 246216422235386838 522585202316601920
686435534063227810 83246050813566704 637837445394467036
568739697143573050 181395074399504540 515760749054271062
295223514365442213 266657863311584666 505316754718285675
281174671641798699 308180120772895501 323934155642495985
91053064551569943 553850054027438939 991987743305749922
133600755314534323 99529898837932179 596766952109685350
21776935598633057 17356492339395067 75862043040850610
188402979358426546 743567309817554064 127999091034187031
181075794704518810 827369792553920027 475442400020169424
699829482323160852 763188003530454846 425979133093295984
501562003522263560 498817057699929128 591093483723940586
369054329634587387 139545209372599706 623224521807249733
801852925064100286 126775143053294060 120676670232726519
224244924972312210 276763229362613300 70145283279716347
841799746819534131 320119997940201948 358681090209425800
552475769136203197 438718162704630124 16768939126034740
277345006739039834 937180386146808651 475058153547646815
600949019378466129 103454959895114526 429082704887128748
581914332982248142 832235440892505131 636260064654631578
594855972273531490 580821566889921308 664851041443879794
756042791738294365 802570680566953954 633915435179370933
689137722197547756 390432525498521428 387821983551568379
728475087517780131 633958025638715199 616696615912359999
738504051235986331 177799843632656634 697173446450422805
275929481198121013 414196561790094857 85295336547622652
531248424558665501 170848486797222785 110549953086244032
798802288670048657 242686503610375733 426745243299346882
978577273643495495 161481780985859123 770633179997439621
583493768916546656 648330774296220258 298141988857213046
496483849620367216 737001184034359183 306815706959833369
573303533259834277 345245043977862462 771292213184893525
629886706191014014 739362556298182963 848112977030412133
989493182345595184 452879907844610346 336451797677759830
931056582862917465 295350153728372901 541563050006165229
150486650909632369 283885748069396154 10136258864670623
882908146023210752 284045277284269204 337017959440311840
724783518013096442 982953878773563083 613418280622721549
362135649457255257 760893516027147019 857395677466866249
595889422096342996 185491801340319775 114733042314922008
491508573690282624 96981001641481003 834340824563007604
865869491628929755 162586248012559373 530338878013239533
783322403379165486 84303731708781588 737249116464194972
844761149185701493 809722142010750434 888084371834142336
455470002292069598 370817526510201418 768934085597603403
150175844309986571 529344965578011091 921580596374940418
235820337153057267 796071462395376934 860255380940159967
540602836155247044 536730369396612699 400524197640392409
37894744764546024 501760989576329493 791954552849777759
68233781720995000 586692729323434372 188917461027103547
557632864616573699 172416012426920559 45290441796040087
164865091764031696 593758627832324499 597819517625254706
946543365304298639 976949419956174688 716287157037959781
486125785790730339 408364113177479484 685672372870498216
35452539590460727 97410446457200600 437761568605118211
564955877991609424 483358046210927055 184795857025393294
482663936771425422 256135600129484873 35100756964479571
375464221512471329 889212211684197923 803102304466752863
167380941923907040 208438244356396061 680144868289800293
385164110918959777 884051683835941645 536690051710377670
83335460144440071 880086019347868260 690415938179072358
932023990090103017 641143152144874454 294372065684237772
436447809965244365 723376988115082021 365836220527682169
660353715517640068 591081539170000473 349131418039450762
441853442686985327 916682856369657106 463604091563346101
969684421377140847 308336301104555719 913291925964562641
936355118708124114 789080672564579824 709029122257842226
852407118688568481 422033207336702999 399864860929246678
285922506152766946 295007268733034685 23648014424466233
690702100783744083 449722429335607228 377708917874521079
986835366470537936 713817814415299464 374994736318017189
647697603362602602 906349396746085561 445363211038154272
210503178270821155 799508771561354207 156541226317436844
699085140971096476 548956357019417527 494625403521760837
629833574744255926 365717159028863890 163127718551375948
632074131042468537 902885383215664998 773720725712931055
410707013663372003 812748213682219537 353761949090202516
548066874526572694 356407765318586682 646647987776228213
619282146142567266 759634977703638586 122344612500106790
344771574499491171 534437187863152345 685530753672763196
950232110182804941 891001361759564713 806706382703212927
853099451208623970 571160200596352698 513947227534923381
377694406824653415 636816652140237317 371806889718562878
909528643561643276 148436579894246096 90051269104487619
491456117401397509 357307424149354502 604952236791346297
725440432875792875 850723906406825352 897891430898469882
274376475031017534 755899755526060810 568006568693466795
944429576436890616 391964499733775503 84155308477956931
461490927659464714 875297621208400897 893797190550690792
248215608096750094 238929310498043558 60783991995147151
855744592338678620 68164030124924300 369621736685104971
616599584934057980 607563717498360091 283726735209075973
337243243702648098 909963146585548603 216335821346224869
943762876178178946 590274135871365146 466824783394175489
601368492220175491 244539691460264836 574750685634004650
914361243691191911 705055503033482039 786946386494411898
504971114868345702 877199223567983618 788856877807238015
3478973345835130 770968988219431138 463456569295694432
623962006651360742 912540472106070980 956950927620943038
178438016774500003 925558193803722119 801434529065160692
276794371305233418 813345601742791807 190174375524057121
491756438790853251 53062214105746900 186692219402937550
466577383913597078 649961874887619361 167603631349595098
785178086908817814 512068133623562878 501324677279120842
235229150663280669 356268721555851268 284100704831615088
305944130193003079 217506917660092569 901584732451134821
546954303076639433 394093509761317617 48336696341855081
91521147563526778 941245382714530695 935379680365139472
433514911415921729 767417946189611460 711018108208344998
320626342965068510 459331467804201692 956871422942613988
761790091856252247 645012360929545239 327701495944585617
234679210643060790 438286312945275571 667958115141640807
589151403817460675 412900877265159000 646574119861695498
605265145850750690 514320607058873472 829569253459903884
198843684797395624 504793581832029590 242267614657680589
657167934439233349 138043331137610519 531115148073181207
615719390178912842 253398998131911096 76315446931604388
738621943819847639 80979023314267592 480096273071745357
335443458573345559 973709886494263484 143283104130351479
131742231346982933 720015644945045232 573145815350821801
712790349773383631 706524649857599575 895438913382777353
668501069476206838 342194771621163452 166967093185920789
652704331483818771 430358245054997229 629902559320276304
840164079512176265 90739219149349656 927266881590706249
60915432887616535 529432017996081294 815388825396886500
433138498443505332 671735539749845460 376958652469135685
589812789646298787 429327039909016921 32830262090398406
924285217257175416 196214880820335199 234734533539864402
402944616479656519 452677424977123629 287539239604437613
11007751660570156 912768551270506825 897699670264842783
782152097422284002 765132206051519584 497209602009107655
349163808641413676 843191357561241932 196974780343003117
280552551477533782 312902095459407605 759805742988123314
354316136342921381 806371982233588586 825890778385376129
130921863571064594 789341220424694252 926941602301862888
793931591311649127 18815263353689687 844821012748859012
606186654235905854 309567004667373165 27198251580069716
505981953777647951 472574317285664223 402652538088237620
722668354506104896 753121402510170973 99365928529935549
209873377036510118 573054496645710571 778561516243843358
143313812449432769 292733654655810119 637781832337187063
573646593128734883 575782838067535455 451811713540922936
607437561565653135 210216096077159987 283288923355222414
897989116972244214 230569612291079428 320347529561000762
87708949678332045 855546103443992703 44209004137858356
740685536324699756 708614214346807754 639029625082776073
437722024826690170 258631969381211555 600208693065403199
112163899231118609 879368129745635369 737763501660923496
667807173157135143 171845568793788130 910875976389882143
515145513847035220 524853844821046878 464122848858873255
624793104444253776 628981708176785863 551934989562014357
759963405732758442 252588443228218616 270786298739469446
910165728390553872 344301656263581102 61055338772064486
692289580842047009 469398342600274163 434864614546538936
909411849380144499 827547155584741841 130276147190283565
309368781205751977 94982355592093247 694265141096519245
504455971060970415 682714775392934974 602475514898999175
262988840361891419 636987565434080608 435865203425032606
307213484391359023 514528912201804283 733222307715413362
310024205854710698 279701694888808297 869193101720851351
302124248623343796 786169229877561148 558479953401051797
585875961545724949 864495632431386728 165483716046831360
48176984271197634 678058545301062394 500829612328462184
602661225466945515 347823903267546603 665859086316396019
126470839819976867 375797619395325316 626839603048431688
992405720689768737 506445992399930509 987735632469359643
802141193563990292 136478717835489967 669021449035449783
493128381953455969 535568052743568876 453140888133149039
500133933077156723 763205107155728588 288728397028307042
207949069886165807 447311628951739464 215539560988945977
257540958988292243 788886896973699929 400108163652231273
118179713934757970 883984740375013238 526202630795489659
328253175240176705 45464647313434892 953629839576080773
875599616971890596 755291966691054312 870793280434711089
52070946274232606 477966210881159424 943978298854424771
863593910970160120 982475534834471203 764973112554098756
34864525661552068 842143372001684289 348573570964811624
997206275952346709 558498446433667120 604192299277140074
215465780049332015 800849268848937094 102636228586729205
763443293506094470 73099728390497201 818661351257417553
836248688536908854 829140296313877779 31133100251824794
644128603807657174 886827786869112772 614858310163384401
217430101625859718 248043327072811811 153804110934647216
485811729792171495 234105433556986262 940548462110669554
836786013213140152 981966339046764592 447516397675587530
930844609103796760 274689477807157451 353930048876280838
927374024153373086 170023271326079462 916106692988485017
397093673140827892 311357535536465542 203858756079899884
631458932743910883 108881801037805409 384527943931898333
314686651365533020 182687748320043928 905866654395937042
1543069763600686 100195937044161713 339959074961237808
496767725761221733 687605639339704926 705547210363148925
912960950393507074 218729209833033800 771463273071323656
728013161067548882 124465430170391360 916090633780632618
512370659232880138 744710035782708520 306765000825179953
981127370847164535 815686872740934153 497396223756650741
258893578326298366 399808576548146492 813041464589019748
20125176114760625 514686649998616681 417883474367487265
769487886642678542 711673032907730109 912406199277735917
513288266758860357 707383782847415760 408069479368601582
818036376791183096 898405782071887813 564135362046810793
635333070726498630 337069563266224487 741255842408985105
609808540194111534 215247911078285352 517654596320812659
532834244475417866 346922845920592829 493646443018701441
450579251070787627 67631899404475487 622892503339617427
179994032254364529 842160780136981935 431689820008144396
751991676976555650 859638196918460792 910352045927233024
296751857307832556 269421327616875557 179231775216055645
431616216117006877 494027753893294893 555883700569498024
854455850103568482 463379273241626594 241679146897588427
863161468362690343 191896392358920923 5574661353542742
216180627875043877 723996032876145458 287588836626809533
441010381919409708 442441883565128276 945031991073670461
809627844236745220 352538878276177989 445543844635672023
160095708011356232 363782481114746182 131114222911503439
558415679361871162 910305940454228521 171613873521175822
128476743561698940 8111214239176040 134412344529882615
979764154911752464 829211193975223729 844134374867572003
58834995355046898 668748862787937559 426908135400137086
521272805548746296 623672027602908179 825665579714127492
83972573292721772 879013255334558302 505428895331322170
243011536944862723 406289199593316731 437891074690876866
429374614513891342 315458764359940580 216239529185156731
115010412156590462 936793576668876062 234065091485487285
483844011776458357 106686512136104877 273408353760617396
128028539522924135 40337604715527759 462143908638591989
891001238729861463 259119520946269588 833281975227797746
309884094440049127 135879042977494972 285196267860173831
574142086387749873 717998151237272423 38873970304976712
506774639628355895 903696065870554812 942021830266799875
69515103182570757 974139033007270497 682278586666759345
408744988178354757 544657061870794042 108203894608961816
421958261106343823 899288367592792174 921256738689541592
992554524105902541 646614505003842090 768264122266781884
340772278894424320 791410378037299750 167400252477272735
154765041551518964 794401200392720295 913462016484517833
757199467529358633 881629622817486869 485876944645995472
823340745323277961 922065157148724827 943653545007656077
179309000155972 102755269405370150 364916603394504133
536580243006368261 572178783703162285 895229298004732022
959629201584216179 694577881804979382 241170596304091123
112028368588204896 414246054077508931 757858821585597251
269448903854300222 705728000135818733 478980225175352105
668076516522623800 706234343853074310 17128758971114618
338438361000225806 47178571940594289 490763741543527463
304774640388223720 954572003906902116 412390619981625693
389782026251022424 35927974530770684 891869655954273720
732475978085647799 626637178945569950 400596771158295274
363914173040971050 127876111499660514 578067300840016459
746996092710803438 350305134732923368 156739340982713978
484231243279536655 729845072662900893 592264012673666991
833421145400780487 655691457020148320 385229561829690280
454010519746718055 161261340109967708 892795980065953310
338436626571666943 513009646878943091 290561929132833631
414965322814628584 250132806073439678 689747161026975332
321873343079601730 171868545908854712 605102343441265733
881324568857834808 323007054729353760 780016010761950061
120689284219640073 226254375033877549 108662962853210191
627141093822468888 345590216611619808 325371325308863224
153832339301465557 912888940429891775 188391841134942103
249605686610079596 988427130196751855 651261650767157666
438643785056961664 588779349837091824 633680990711766146
218807199474978023 422008825342608067 589386349608244726
475420350022226111 972443040642568700 380485985433402650
154081150560367769 380893418118739829 723012809881446194
934085927461456677 780740925083051764 91220229074288041
909946368225456161 257009443918109683 342401725970975416
414751109430962978 54549825869171762 97818171458236558
501320201196413615 627584000343475414 162437736054630001
467700747735695195 908076089683107250 585629861310435857
469746190981634771 848408388747739556 869669709765945250
144648138352486734 787531636717243507 403149455173154603
150285257445427909 30015027876068865 143286618549764663
955888005817397939 299640030183478046 998070690889074815
371215451644760533 206499428805566658 287432241686093740
89662177667482108 466299757137820930 462158996372572666
35876546885609617 489528412979810101 303546107036459033
109909752904082867 838509317580264953 456474083194321615
385106591414939778 83673441731525771 240222626774935090
375666801803935723 632227124625328955 748161108723571396
282484345636316274 964471935455831187 550348326959600338
130387141610057557 759604111052825680 902015777827479682
390588511882596333 512462259978604348 734856956610374305
138328189462166886 462257256772761720 904041695635365062
853300063771106660 476787343673521757 514075157407424650
523611412202829705 800020950311352193 123918899119880135
707942912369577055 425463481902894174 762052845125432143
780676580359208094 415151970163262218 975565482885770224
178512275686196498 411588178574855388 51247688325034156
128123705401061704 512215734637880712 337223520988449839
366604573300136247 978176829980637247 252759360963734628
453986223607470134 586379073416616646 848042770638627837
220345350463044294 729203548182476622 638666641884348451
586738431137035654 147325197811111616 386305126326510416
800903333071663661 800163057904734474 959406541895047553
829679457796839950 583316244570663151 245604900967151251
762394410231682605 998383428927876782 930251279142743413
307659961607038857 820875036659088482 493746127402060129
804314003860036746 537345741166716678 518825900229608070
364782596947116492 726948139216112772 85233863210188621
746080500192707591 984498759406609498 922703912731100858
902492784853608636 678113304715938488 279110478429731036
914140336332845560 206632519094368296 163435191795998973
885798941006551278 102905393414819042 672997609120603535
885979006038815862 820747550854289038 109708216398788787
962873796926255741 455823653828003956 456991047919760002
294421013152961413 345963175607064726 817328472143591576
502277661640106717 930847751688004337 156669804360787985
176509896189201161 887438890764429714 794111466571091580
567684363940507198 392898020529640260 750565125249546980
734010268182211114 600038927312856177 361483139295949814
152045546708553952 69852132455384082 69896726308344807
362760313940959520 79998704005959444 902546566057757246
865695014607260600 365166367166059695 217641359368477959
950382953838010621 201853931575487782 74757919633575228
224438752388098458 730747776098056331 9554685062136609
686453598977535005 332494511965435012 272292063637257501
321982470716294365 70129351458290713 782593684256241919
77411906113668489 988529763435391028 35121133088589751
982131983976081454 771734519062745537 403699249040131128
934670972948217829 384263716466652079 391870244069841212
243195611973616560 228867276636861021 78029387100514325
798019635536062358 633832309814186014 175588361023280992
237926758591042783 641694392739355041 823735995055784978
900328186805506962 151254593374433378 279432864684101285
183108003678443871 925062402449914124 580126996238000876
293078426509064519 193837314211836445 154392660072040756
947728437145469782 181777245410987076 286158861071486367
329478522455528675 529444731545132826 889841175907989209
26768069861753037 444036132507121303 19756269847458825
538212716874817114 72128579771461251 431612178378451723
624556522555501261 240365586823522704 314819113483245672
42399432333440775 568861721855408390 443483714187907108
141573802101849926 139902098031207410 950386379826364990
451171242525466035 691707648733502193 697289976867625532
788436803532553800 143316541501193278 181274775330302178
918400991098131488 167672316168400844 317293446792842963
846283698370661011 709665151290826767 674422189581937344
183271545872702422 829037629436015650 53179406921085731
653396065400417012 451540947284608959 44985376854600365
533491115464068011 568562746812201612 808378725420703592
151171276479664888 402107371277149110 552070883810683013
883288034348135067 16802596765093851 7478237199381368
887366820469673769 6628995311992480 224057173726851240
260019255569253344 772596379233757844 922388346856335530
271635293916622833 571173053909815582 949119721324887863
517032075769694323 143087164398518709 745822207876054260
403104874247327845 603793286466208402 124303367243002388
436577190379458935 280228765723223719 855046465297937187
330892130172572614 165524081998205797 545438857135777411
939298656993437732 576261400071765658 98818544737789098
363133922121496244 714029869528968210 312279134443363824
653907134940165880 557206638481110725 903688395036123243
151985101777997607 662219385618107941 286188165400626611
822900484886784009 587391162189664344 287718077175583428
101718026606450739 972688382911062467 677140529442700955
200344665589511304 51406310249045859 921156413667160817
574520047484642451 382111440486096123 808108508006612766
112614213909389764 270793375783164170 780968916388671932
760077607654790318 756153361234624508 322865141950704974
733509386905708325 670499998084369681 970347277389096251
773207299209323225 586734529627982772 695009354289691049
801726458521708176 152997783615073815 387168959445016790
541488827472269383 30427423634888090 562574921682401365
129090320755986417 52023628685758885 174274299378845070
462432164100057542 476419404336326265 474337049970636347
101814628367423025 689882443361797575 751363563609166059
718138823238322375 420922089231768955 545421990188787525
335618472294312353 393473240749874876 470953569471926812
244877195779688443 271313165364684721 721834850431387651
726482446556833725 713658594399132118 480096282819988572
138939794459058587 618246657085777783 77892545707367645
218383113709239647 321764138300113961 65694300729594437
849035665501565419 269345887567470449 458068941208445542
873284258013307717 122671074117378344 68565342834180283
412823453340465034 606921051039638061 772899468006158484
532577398131118917 667346731419141625 548938478890927641
655514662320933504 949902928304388012 346603549440697749
105909377896163250 267306663463138335 860201707708192618
825534044476556257 818195654913905632 818019654688165741
928173116573084433 503798264600399439 992701676930369559
128194124538800809 593705653550108460 981619058600317898
570748711702318437 733838144155446394 26770334960143869
787703286624316628 187087709416322374 988197442949278499
34801255122580683 802027655598506025 404625432619150472
557397348145887865 613894988087807373 966514286801884478
323621189848846785 249976486781934892 924725600831518386
506991863679179762 124267451414166637 124764863802110525
852946982649881819 762658589971484888 941133423395088470
96974006916940642 11794014407465031 321050524229749647
637831887748701319 589011887549144528 456404758553859118
516755224123806478 319620920475307385 167674298199630803
330751972384049416 784156601121718412 498528024469273656
38267922253323072 959493350240225015 882842839053202995
411792387596193958 98617039980137494 669306667778293844
597620524150089047 904654118630032438 120993080422493903
237338349571939387 235375920042730836 481652294923557940
942673559537003275 25486542047811806 411304154191255969
408100503631164532 724346954397066734 408070642286460479
346359483242735804 814636169121585593 448080349795999947
937815966498840714 335333085944316495 914206220043088945
688049238388926321 974967438544990867 457269961887626752
999064866622325253 376189786168495802 275452609326295151
933485967300581784 261017449963774420 595668784248390461
553788159725775340 207676368273211364 320667663397530931
645718026032293749 294515861787481346 732617642271948513
245114461826360097 872532787954795155 347130598931861600
23539029857781362 310958991582569108 46532222606016217
859654362914008545 674130995042141911 521433900694762752
680869342532745212 651496935449369884 11563030027609863
775400167707289795 475698957835475447 4698170568781293
36679932214053740 622218856006007726 143873848914775859
43372666968613570 371594298996108330 847305218251724171
603778011563130679 119757653512311634 548268985383287748
580953593131717272 299837456858897704 715646555566120705
517680665777446299 558364012542451210 99373577142928947
900881298696187759 478037408799599703 464845466411981953
493318254460465192 871780153372871393 308099920683061365
306799806007600780 814752962971969488 163995752167765741
494671581439502031 690024892344079181 236876049442774942
143880857407662774 655604455550800561 555370674862673438
281274786100662703 799931603141409299 694479648485873725
724480758234913878 925050249038749171 509018201566179526
676926407362139471 341282095310808195 506602328351419093
148945546848815694 571440714749100994 428777372455780434
248617916603264866 747855827426450076 226972853255798886
841714705917798291 549614017543176408 111163589900935417
743409931722552714 32096090819092155 87595676120638739
506347774342241933 618258437941564776 162234958663202106
967481240371705157 571939568920640704 647164086048941214
33915436585391125 542020609267912767 729958120914961377
726641222011966677 617696893794999427 867818898417278225
876713918060765578 599400808333668123 150769992494519850
144790641805696362 752544027386625826 357247190089027206
48376305010355672 347635783836799057 6079445864261755
53769586307394187 16252545939702760 726276051136668770
988771317697249838 71666058856903067 711138839337781966
103278626740943489 688878151507693588 168196348818813846
324487366932247952 786508563765639214 34075708640201729
389994677888425047 691359828998354505 354486480887147051
793528738732379126 388070514867387954 3851134928653480
863313056495564547 187501817282279659 246915375915265118
692154002753315939 235704559742624073 389210554315511055
1936570244556184 292864484867556318 563381515543386733
206732484289204859 704860626223173249 992039138584300155
526320248368112896 875533716554889611 794617954597911610
332415787693784887 590060622172981051 39186693337456515
628161066609004238 805557620449373990 718376869608574371
5172487611882445 448738865817607150 716654694333701480
46348285975016452 582333775463753891 119781967546284624
87092609159648999 347081883542050735 783385551686743366
12760096887357578 959888621001230392 76889742622048604
635022680083306131 416518598859244805 756051746471554983
512918572307752937 293770126870372576 991806546398850227
641227123970428474 974531530497435150 913737381729821298
614241429303421352 3036685979666964 146000811667677378
942582073808416261 127372319341398395 765985180750815532
254167082923228645 431960365334852950 591487728932541409
526914071752731527 202622764045593239 31413294035235706
263945345495464210 998915300503285263 473763743494074859
884175220245112713 364642386655449215 244114538836960040
275137869911793440 470441446008661755 618124779911818536
657604147666094203 735747208175849654 192367954923396510
97818537465665900 411990908580900184 748879143847134775
527329594032068600 677926795322913286 239948203658442007
610707650837534622 758733370209319591 226033506805686490
409236040220688723 206947058643203389 616982133218032120
257304393131735914 224246707140493921 212472812130482224
964040785504994669 415569071248473226 524052341735833558
807370698798429243 966161050268975960 821651591695524076
814884245556774477 805417099253532692 911010258913467590
548667503529890049 692512367705028430 750978822222663443
939055095620401532 168529740601743356 859447205877796214
38248163807440839 480421947909159061 548548513028651754
508333038839270620 794092175731228447 879935514196884184
227134390042704707 650418656893709492 188450453127105174
549157596047621763 576020590508574483 444621515644594151
926164085414862664 447922720480291513 219552676430385978
869628117948603232 284677277552626840 832679405289379301
321355904030082597 774240125268489387 297990789019563660
41392867654294594 578770476380975663 969468678028521569
467631987792689262 71143645105653345 63648813689167900
355323339472545959 2675532742498101 293303418049544111
641546971064478133 16111710789825490 462298884567958532
995587941075492066 782342256636666925 388735768050389662
452727842842128061 158750346461278866 112825291533163182
733827553970695945 344441456355977338 253649926932560795
660845183138502857 278671418384214668 591442595772159482
682263254262894517 583109718257272099 965120496198827178
279469174275879484 334125069653027314 529872295930596266
973491393841062302 471661615006605541 377699539164659506
225409596146538600 863673015961098392 909348657684123880
139750624953001119 997468382569603518 12647662566011494
659237813311418058 830719086451082820 358610005348483869
645612498178043876 454893150520371043 971118576061148543
521198047380875081 629404862793773202 52734578360351274
951526359767897989 742764096097174284 370688868062163182
267536246323895248 502326100042439629 908357737966002087
385964963835713827 198714789898234054 109895726739890873
97180014160442700 541143082833320792 732981833619498912
909928708476890103 867308077241357728 972508948722475612
508513663472212905 968480932750238963 222319799076415037
931424723606638590 649150148953679718 17606729318518679
834678039885916969 279142875591166893 641488333286080279
177646084940544134 838417740153626983 261248375237632245
805521673671387935 645495440368369074 430085128888969584
506159500008173027 838603952505887381 826945834612483313
772592489442492834 960205179768988063 848565317930763733
903040840963883622 120392079717159143 617589843160173300
859663357615907045 397133119816380164 792999095623172363
588337286808827551 751342011004902912 971600343779757857
864503226590505294 611305262063476244 589842137572868117
186948978402519257 450341544470726891 549205810723120586
594004437801319744 950708482311817879 815546933342540182
735354257014975440 250638225367183711 17002767345844657
699421013908619746 591081437375866433 595318427275747442
169981645344596144 452784860696498155 96409421689754073
435491502271170889 659126600383911446 963539245311452091
24938757426851935 12451630422673352 14710990925058718
161664330903626193 817393853134247731 633728823131080606
979150864130670559 792398032829023636 873081445155589573
278862338371012257 959268172889130696 490109471369726960
365452821582412821 85124189286672225 970030842439607832
388000042514083260 818649140982769990 248291149903057829
574570781065189593 20340421502282303 606002105123621385
219718813189222105 371120889296309502 430994192949305796
781519276016951052 643234582428571820 815418174545848770
589490559772426235 28728729634759606 370597362223021957
321979876380976698 636564471572838030 496028761712577647
410961410341667565 965630689856614329 313833543501006745
749357212877215021 179206862213178930 389235521558634627
551432064399188007 634226767791972355 590624915476910786
605232894617945626 964251469457015487 471951486633747359
215972704338668255 548788147374913513 941943014448660961
451421123089869235 219241658113207251 132207591075823002
759441994122300015 63647534471028118 953996164923793609
967055660988990915 789985390151581265 800228365588228758
821659747288327436 48467496075996205 86762234977803997
421412596390046394 113413572099110538 136155269840605330
92114581048035163 857507279454168328 421297981942814851
271117626964851954 371801018506737536 341156136659098652
816700434999281110 223760461930454055 973456551235268094
22072047527996583 420791843877286820 152784471432265821
654658960077116166 259653504616063931 601539347692435861
349501090191995558 843087257976895054 145082379022911253
774583649340423200 162806363081508707 731689472983588277
194088807084486771 141459157315344165 843341824786093268
698146357019502625 337653948213925572 913700163738630940
709952264892322261 350248954626354723 91930552500823958
504968514080280672 5836426138608483 149714332673436017
227166549569104323 510258339551927690 939340856218953421
669965262092010300 4926846091096019 519516282356612638
487813693751037035 853529669099614945 843502767585450625
667838218219448535 842246174342906361 905106528931441726
931236993364421437 936197148469298784 67555645614615867
676192698783129169 599137194665404073 181767411881358940
46460569872974246 538184430744225562 253972137513954422
763322317909533306 624081485304116960 873278586134413078
264432053138614756 768218163932823073 398761177124107566
567942491394214887 526288400506675438 130134417971517416
172044041040201960 758937946668996595 85124365009630413
30573435198409404 254102985529713109 909344032468168046
117348773587915157 668082645119260829 769298205212914171
566127328144292008 433041868783940287 335441850681677030
81941155249167023 478448990120294783 840041151318122228
182912640105286601 198102263531639662 120061183698889877
148538150691160241 493471584765283822 980411396067635436
918204479235286150 581550716479141408 701886496590557008
873357167682702268 222006343379306746 290921764551608102
818195732308450498 357010738786696564 301570668716667423
321417701229474467 609771454126130261 626063757373236716
530537918002600078 767380082222812964 159759750429083609
757687264036856280 28964088774324190 377342405003520308
315336942002749251 977609533476245847 847454653066481925
700470445619507703 926689607854279493 448920264666705464
975126997927884045 687348638048615848 274236351690486446
23947793132765013 303270228117590545 269810155693043267
231335789004836814 609067073880561729 725181234786043166
780371109153355945 721814973260477417 426262724879407019
946569159085075257 68124263711118179 766515194571694387
637247951328083801 843111686197286392 34208647856263201
245743054141445160 738235661633062283 719059025438417514
467039630391085144 162380403458832934 809472289934438249
138611982044649414 625183036053184418 636370678194304993
445661273936837532 730409213684979164 567164344660334142
963040808170815437 364638060804840632 141194845521810296
102837688650378173 543525168224467126 271664534310552530
733656379909647625 559709304489464141 163431440772641878
335787487795346158 583654406391196765 381876986511324582
296346595758821231 385575223043123382 61312103811672330
442709146794149734 67892831361016335 359122066322873507
886008685660906186 332376822543992549 109772499446002404
992402362931312694 82142783036777925 274993866868044922
558603365397953785 834854841287756537 861406234626496919
93813786410490336 46113377105145542 384305720523609310
490010303978506614 915830149100471110 41645885916774836
359575436002388235 45525002237683910 905117685465435992
652559775969724626 943683924052041806 933135819377887691
922138073934662078 365810597247110993 915133939264265134
810788281794307121 886299301430269317 618320131411281627
380542587116497750 820008498610350019 157672191651055160
264111176388397839 523847243779224846 632621683194991074
169912851576199120 692673992794906795 319960594713178087
548561592122563680 354880644530575368 935187756979958422
499295473883621832 713113742009184534 233055727447450603
66539332583333998 170862588179998326 522728825057023469
682906781556479895 914281643325272294 963504637920921099
54393683063076640 483901992771148982 165058442313041023
872964907305352046 606493352014119421 581220504462395657
799600893261027298 227879920051098320 49583924120014644
55034022765415656 70343337151305321 23110034657462339
521851254723173736 60838292256960950 357392974810250416
459816736815525424 730269225399835589 957120480857466994
631152971997121266 943480223909831625 311575462024004677
36951265431382073 507991028581730228 384554196341496742
665989462945744512 593333867106737311 837334097530180123
665745032277570073 332962901902197224 453628568949580910
737368595275662487 278821813385270233 104508975218036842
729933140804575211 593753356863006507 750311401703175278
895472546646024422 696225538877099896 352117189487129140
414184606589965499 522528117500993970 891097698032468501
687928625443250341 261851451720784230 301237136234871573
103317266211820469 844511942107124415 465576776813932915
478044614483335626 929731330324659209 817690320197189716
26611794900536510 459786219347413375 908845028662701244
854358238749227923 5195614762836593 98972245219237735
800752608221003801 531510882220049206 200529105034659726
543812954526299270 251006037050439541 372250134039471442
528467346379150692 614747010646798459 357368630164195771
889403000295256467 768481671167254558 266332803374834625
987584481038336493 612503439337585642 530919042844146999
750005749464527422 904698246544043430 532082806913117935
295852035972291074 517520486617648625 875127670571064200
162660759814270588 907377913418621469 338985641490907441
155951343475206615 248100865469319692 483952051374192121
862446555755612479 920443645052314855 652192858395705194
367622322111230324 484903753776414966 628029069161411994
104602712081763576 685543524525031967 844335143179868928
413742223918047206 52467743249273949 294499637666680306
990582298732866700 499717316769075544 746944248918265067
330668068086065593 408925749188069306 819513319819460509
584041535316123533 463705577349408295 677187840881497818
970557355170773626 467101154943567194 985549891467305805
326614813465639015 367588103145828646 175393943676560223
764544221130295097 275617905938041117 909185347246911840
83841739908410049 76724681509429457 398605848399630316
472832730027312260 837477487591062500 790521938458636410
96700935518839895 990965507100248226 150498760752299276
599723682101125775 407599967307164930 911635958502167289
9670559336136900 344587269835626979 8360249174421005
607816016331858563 99416005479283839 646288508693088806
847267460224903110 218835294494106219 194652554679783148
906475201831723680 2425366324528376 505359179965627529
178222292622988966 323300494704805991 160179729684863378
826349452534529018 855292995619100810 655158845966082343
321060318209683733 429827690553327488 224358422017996374
825053409652141421 733555064431897868 497005700195499035
722734684732355848 77098549217538864 592645493069345695
661220082880434031 815138502417060748 341516412920133757
40168489516772870 382370642545893987 398778195586887959
3414418554899894 543192768448239381 134094171283315593
255422079873794989 235030393272166460 973311023781927340
984942182025961918 888262091936194210 905415578454936809
718821206206365496 706486155216645732 445929818460457260
595001062091770496 751223216286395984 545784822074372166
662744006058697939 573414133201126457 843803197073389822
804214947742137794 121664088942224358 991345878333738060
934714232067177350 643140127702652781 502863023906148378
173199189991165536 297790041374755500 262165009179703972
125501796878704878 680503503904803337 311356924911301189
347804280037442521 2490595603685927 310273056870473045
182133344972063673 637888904399331666 615431268196543098
67726074168270655 56073224339436686 672722775434007909
923620316095160805 814422797430835785 283620835407547613
228133534575675722 430444928763500593 706848085793289934
268421030207710673 147071676429725508 226673816155433854
592927236821362095 900368865135786023 324736742521795929
740591606045523660 146426354637134525 822267627479628455
778146335175624650 23603052523815013 993518707075401533
917316960207900867 562532560332153733 999864782595948638
631991042139997289 356707101027895524 928828214974429344
7012498063693625 190341538806177269 900079692102478636
613909736031575305 385860882656566328 21383995576872048
254431665064728500 549240923222150838 640415007435549690
539200905592619003 769891565461337392 907371409142908530
494126643825524455 661818864173324948 312865779851964260
805888671262939693 741971539549376455 676449379897260743
130899041194182079 363635284505472900 381654643017830966
719536278410409464 641425809711671714 797645380449730145
784561951772096791 376583202750325527 52944003098979607
427959687045260103 136456680074464563 576791534019679468
122596783244378425 247293991798374910 379595104585651093
788302088178934998 119987478622651575 557176849528879096
9243925241955367 388385739695574279 348154730522206806
256646604135194337 6300096932548639 421373561846649657
169352330011344739 498549017660808990 778969456078780569
343699568602776348 650028147569310281 498422395359466046
587803715356751098 136438265828669637 239783018829560076
130614526087492998 999948097700407661 465334950333758271
195557307505182646 554948359823207542 628815290293284221
908759570170783510 318443343185921782 708313816705143600
317831571347202717 315033667915032774 367982575940741749
718429752230125858 203376993705712232 305206822709053238
26884529898276757 213784019483204443 976283201310821751
719780314771619406 470698845915394989 670704730914494260
799651135472804255 981694710806473042 884186249038066359
383658181854776475 100292401832132749 277072474068991387
354072953531708855 776589151305251016 38748727637048905
71589692045792476 15849271079397705 959664357872046247
63611817142472620 576975464287438801 178651472429159462
882855102336664388 642188224315248860 33411336503728275
771351986814977425 100977847548038276 386534946118614
415466802681670972 398033218501858281 415379248075151197
860975618263346943 917814691433634397 954007554809080588
127156106900910202 50260278870729586 538025625520913783
924476718351543051 745631406598359258 215023953335907235
309334436303316865 258655896985307160 699526996572262895
129541963564111703 811274164775555312 742587885280734974
98863782175081572 94795785939660226 125099855539079706
824649271720480814 434907556622694635 813624307935088184
581063554427057180 18147525594961510 156710281713351868
970060720811692089 543350082599790715 549954990815155255
764096592398552979 230814433344294078 313536501237327323
981014235657082008 227143519391740810 638386278390146644
607009834834682002 807635824198283604 121852658301175762
88944887526844322 537564688027927851 317363903085943170
640147675269886719 891909521190161115 69127846364293135
860035677990165898 252644934206651197 542319862368851487
6851905800178252 741934824263875717 591067665842691506
846583344133810977 225473030196262458 438151411685469139
796467360239351076 496398555606659121 335048450755506529
591850369192843486 240582544856436259 570955090213093468
570219389003572966 88779706188856567 495864207439045704
596654705059941873 573631681293667950 789492999972415482
442038230488035510 110669401113990374 697516605663306334
54065043320347286 177441842641848504 107830940726959449
929266658782111343 17413857812181257 63828288436325400
975461278542106154 433906839541349930 832716536827321727
709270885706097617 834767424060084090 42939894233469814
881415367512126096 471973475144142931 46733550648196354
451525552090598681 652751411944425525 675163208637065411
702828861714093320 936313176880640563 568699727724635801
321629645696953702 739642226280951605 109197167610585797
66122835499765978 801719003105648589 506566602365750509
995866832057434476 823713235897185959 77081661354451416
841461245699781382 863473446242446728 828217716367041180
143617557449665959 258419626288219894 619239233484434566
58763748424223550 81117887444455287 800342001303200880
816393905336842739 684075957498707005 711217775704772046
308248028837190586 684388693081726185 84693877454162172
119626823945330686 495375863201795076 963577482585654942
938193444264513299 428570121688839342 968000000876236282
584930082753298642 175435688633387223 528192731435518041
13367311886003749 523770235678583906 622364835321327566
621603385814633451 768180588780746660 255914297081499569
759487474672824098 222967557491809009 734087974373510761
319353220929189203 215461690259908168 35562111142298227
13860777908034029 947440999288330845 671398180918770525
219756759549269827 853234083771301779 157059427349540065
300386495383731634 350897640280169602 902475768684506436
587302159841532602 902055534310201416 325420957933156899
777468021669901259 663650462327762854 761755617717474400
668365362145919866 517323182986965358 738476142335542284
477044189202263022 539452028408286623 995933100422401121
85874846601083759 52081851528293389 165970840383477250
900816024770739541 642085473565119188 174810816191080345
191404260314347773 743824645614840296 784057653144043366
305299960505088403 127063577231702037 5878774668676914
430764891696487628 91868009252394939 262564095974281421
227348383861619766 348002360823262181 543603658545378573
504487801180758748 787971399359175802 360321622001279226
27879589765985326 549921701275510488 687915761039086176
878916107316691585 794170974862584305 364334152482763965
751652202358874589 777017282573014927 563962050563387376
168909731601930810 559384820958063297 967376870965847595
568081552496871137 432631843626352993 805153658522055504
822947006138581512 398034144479250755 334774592551266094
841602465437565663 330412663253625581 651899923757608377
487187484254822858 135544461430557717 102019202349529902
635259133525154215 520383274267391817 205162313792792472
994980374771394089 52542239566119845 323084246911992847
931046032077489902 453166338082481642 882249322000593236
912900568981046529 389576633126338185 571771284657045760
284804780760071085 552579102298006649 425833070059365010
770718119205449240 557755159654566253 344497821965547125
757139026773605334 101694503336395136 619362286544326983
686428015073996498 69455138279636322 996808128379343048
704535102266283645 481030689107269429 526620330177074174
361601119003972296 236417045474637248 816766245228854445
257091486290410075 532245188800513534 758802183362432759
50113662883269377 253869347710864032 820412689687995245
354241197190392006 548513066603865054 800819284616984259
867746011191928033 237636515135138035 196273902074241763
200465303709485780 689875119643822993 518562515186581135
32537324808047707 622032025603489698 416115813189432945
809520886299598023 861624939611737000 560801334703660336
871099242579593442 750392365596951827 284270544911483314
804435963379592510 77222408190763277 810555222139839350
869359362244197793 991055929824812642 559993500965613960
710745727221819540 899409393388401426 818156198955677747
945757291625037706 49020299639720358 986076803079187281
336550090370491429 750229826795810914 885861665582059259
588428483578425323 895654737086549170 188661239208467303
477930844379377376 906752431802267811 866420739143325599
953879088404313427 187771359866469427 555198054838713817
365162632438316189 895672053094845165 214491568098682096
510563149128244013 769375466698877834 981754635743431511
981334692778295460 938992007093715469 902207142173541175
38689981060195004 620027993804156667 652257640870165481
416177313739610047 364325575873995935 90349662121100827
366086938972355854 937729139138185495 940320948357777052
749958170553651546 673365206926001904 180280690613217661
765019288482212512 438489272001748885 786548502837533361
882292691868300301 971621613375469988 322876609523032497
181969734798480169 482953516934565392 321856311717124422
65172259024257517 712266690924951317 541384993008791095
525745021048444636 43134676041972931 478177513420487790
898572409081059042 336328323362621614 687735441254622484
60519181575889552 819758264087746007 704075394114623738
442732337672937487 344028735092019772 681271340463387727
395219922068757651 727348433511387541 844308925779833854
711106726942372198 195670066907156832 901534620466986691
364271350131971772 894287055342292167 908516523905445087
693167803731853389 600300017121863216 278506660063453431
968490118545799852 232926376156431678 124885042771538272
427623970185629180 150196071268666084 475038064746636599
617814165940207919 182862900434056149 486158814921027776
740196822128345885 845066256472587982 612490983762672876
527623680414011659 724521996944916365 555768887785581130
36535058193397926 860333771343872177 155494147626842964
234703669579342080 623310058778396103 700409142065689379
30131840541223399 672149772200817685 440803473845947690
527815847305754858 86694441435476988 646089885672165149
122108466341219335 214630514483432990 327044741830715908
643615454779698780 70839616359706249 920639169063778553
87600639375361665 523181176244987267 256530156256721503
551731775461013568 809639577455362269 482049065685268004
209894800226748695 851487778481357262 814123600028413835
148372669932336628 77964238030115515 295731332386263300
505336461468383944 584085009309894070 154801953984858205
928089650012603757 780523356794134265 779575743472179032
539107716557045342 173804142076432670 90923194027458369
255482776838014125 921889387414038321 96899325071718215
216096012573345776 981578268549739991 876354991042338222
371375298964740762 467118885015642379 698294918162110417
318132412934733745 581637988465531881 605162824179151058
409416296314741476 903948671654713457 626030737356458150
507617124684738095 510550497980018985 78095447608679212
928688411324143937 682200712149975883 596980680477107492
987550701364309388 422256277509013450 130741601401028599
521459065334947845 169223938002240059 472995257604933218
193516896374103097 259344481387874434 602134028152849216
413344863198461375 594434017426311900 304007053107503352
704933283739798701 558502539462671276 22016696246639560
60696821394550325 76911863883020031 897657452945287553
434161015145279144 342545217533701581 286251897853407645
311256248938832566 491641329402557786 755031426600148136
54239131579706746 513310843460346709 236610448979183204
808924956048887178 376407621110863714 38098436264953451
283082770816663443 689208964803530633 632820457743786662
280976660534236327 57077643282364503 313096286230193281
257660790327501699 543906662958637782 420947722268542907
131169907017578936 409621936286122055 828005676828231167
533643406927201352 989134485988199143 594898685114627425
664162380062101717 489443586180291446 266366623163698474
74002274255639079 295126388706155555 482484582303726487
110932402992619931 783222808336501921 484419271055312225
266464085274871337 72365523036765874 180075710135775111
110468423403971275 123573844312696453 104284016585698035
68435605317310586 537303523320412271 411337233074669375
928485915562575581 6992946372988211 178957848788680299
71205403391830399 299169191516207626 754747046987819165
660317127250913355 897122341484136201 154549456220856304
838716864238299628 677083476764387777 382310093660237597
952856288976163750 845121457198385235 714012517572878560
36192367286064508 79605528958036928 596722975886176943
987234431127293035 317688554714142955 374033133651890732
624661723505447574 676656301661720924 510592846010750069
892766236780584074 548071793339307874 244363682374632219
987058993200373434 180533104310040283 284749563262264093
75879273579360407 160445646488849829 855933740429338568
955030049845139705 223553292849303909 715373788238752563
95182075638389306 404464763638332776 618822135217688678
439020595079881732 226218045004263386 332741275724172476
73237024531170953 447054227940984246 668057593401009017
591026873335177635 215866418091296057 308019708843871620
617846449457085334 736365923270519681 557130339162370219
519532226795570897 108442369204145394 562997407016990001
810895680613247678 257470768143104370 708840919728639226
652248186535443275 87735650141981981 336537713326581872
750940611651138643 382682322675684039 959619323562161146
873681569274601540 930988816541102412 846948321287561071
745982828889856112 814980147508745637 476285289741560446
459180512391289433 94548538799979287 296638412361225146
571292744838123800 586988399416535155 863093070476041851
716083821887535827 353501426260231056 476639268641358083
474343855656554891 658799444142657221 714834491667464217
749817560717763626 122980228835936840 775765244030571923
862909832617355000 484748958098465087 45629936542388239
85055406131185075 307738632775601489 460019223003934105
88417561311344191 590318604726928585 705531039686254427
831908679269550778 177263724026652317 945461014612513555
606324448220019985 848178512199416810 550363350307264653
383083484527192728 779432687359119959 756257032925277280
189685456167466579 733866152353236697 815023766798645282
289717193996338202 60921895856316987 378845424690498013
738335023736808014 217025671556394956 698594120077362880
525819999058921831 187259972650369429 742678911364519663
282151502190494835 532585364402950531 163048998026185214
945084483246016151 684949169439055991 502796401542428367
530387707413907832 23677295199513532 803888571800879884
477563792149887283 741120071180865062 568430267892047300
937558147327067651 696374203843032646 789544730493394197
548501539665754378 196378910917284655 237985229195602904
428751433280633000 82906116893690232 394424496326218513
446508387310963295 904446516923791112 707132303687287998
589246852514622260 476937753707255701 242694568025303221
809266716056655141 341107251818646697 470579008826400987
196211377824763658 470228611532403686 599042276235596459
530932413743447497 853189873830470325 80156254045803408
867489096918757640 811555052585427639 323589139527805488
13453555203119823 358756199127167624 672997901116474139
733856095639937113 63729236885958318 138684403128158110
47126567159825469 982179010704272072 153010919134645536
282491198167196882 245617118922997621 737943328735912076
649510940993009571 245498215563325755 554012965923673327
337927898102767720 468235696588549536 888969778878596346
270402944437587447 191541690171897584 832898869726525386
353546201867571102 38507385347538530 172821860801560459
777137440326294798 827631783918591640 230388798511594565
75928239548587671 848259190285429313 330173193648564998
622247415533023424 682392590205559400 304478320961453654
118403428836263049 909943396489883288 163778898545406482
906799682772870690 339580923915194725 720792109725234525
384000784662277302 309782698671355568 322904895611231550
152156064027286561 579660019727898622 112074241390337988
28470159457873790 956240036700326896 560864493908139717
435177697172409934 840075902730039780 714639113434171990
938519036528779106 251976821453168373 20426789231121321
843660723360303677 882850559783608466 653249647411785967
8650676825310694 972739667731189870 905340016930383539
59184181889328943 936973001685375699 146806563080249851
554537303824280602 129817473423425019 754306905987740356
561780198844529820 601125796622501185 869727002758118442
154664122801336062 995742790923651606 149752497460208337
961535019372052994 515479240112643123 804883446112243382
568435804979880993 790392440984264592 28469273677229323
610296571334404070 840005758025791960 431075697332615982
813257414529844377 984740309667175086 943671914897954851
494965417599174690 636164853637714179 638414939857744402
421397063780317585 338027254638038260 228052537729381814
342111781917355458 734229323389399373 991952293717031417
727279118575535678 846915540416381044 727778532365520303
818019160130670576 704743353661132921 801441703200595578
569994794270149332 21898754170607196 714589950648039252
264884123155471409 169141185290114316 223234547822289437
82626084416462103 519383278005001350 26509856252222284
562903644529077212 786694162181086739 708399562038677393
321659673842545102 920028768579729057 219164533915605769
763889161696411880 970430500724589676 325763897928533568
89614009328292762 666693297234966084 832715904249928020
443362185308808678 468195375656554746 511310437463301602
408644427449639753 852076130231762584 241597795574964284
334178866977590559 849136548364543062 794990741786951073
472574769712241904 550956549113401066 690339684984643615
698067900628568887 730418019710864273 699679883403461189
290395506340011679 850992840716570815 111047830788391953
522294858726656191 716146364102561697 845637884836637795
525373883940750603 542633593552918378 256565401158666096
150316539912061656 519648322576116070 230716770084809998
848158938437889185 753579682952706246 865675013719184918
751001329241927959 725585786722873108 947261815327005943
641488217499731979 600227992201418224 947527966085156950
309035837540587034 336538583943272252 897863020910784840
617698457003297370 150957530319891820 40053550385055030
21725340519362148 6520433812538874 610118425508587770
290584595337157529 541869278981689562 215597072781336895
797514080698988122 704148975564118693 276589327028635370
439711720902395423 714997617929020704 156605047077697425
707934945975634943 420667356736983262 348726926991634762
249050528367766351 431426237643397961 985543117790168721
11402442856308158 521327400617325078 423558383386254253
476578313943539434 430848637388706673 276891013214806658
828950271774820967 640597537845663005 443970970909781500
677239974447658443 817090438156187986 192649415107188517
621424279919196310 857780201227149022 438183794115801567
717466358507523274 54066650363266921 67601620420345073
649637072275269320 715480445111458108 349701645228349797
782091227027631589 660369292724849298 514392637776664167
598067451011412160 157843245592294954 211155154767600547
736362630413098479 190962197992136525 947330728296652732
409681601492313482 22115440427240861 395015065747250930
721020446688664587 230165216343811939 260254802423669306
243446931713083409 212878351958411885 983020926790099125
106996151248237341 445961321935244753 353387479537741667
74388857579577416 966610821073689299 231936949180512816
438708420433867844 318661497453094145 432589811274888238
66656523631064226 898531426359431664 736258560726568016
277926522687614116 595523913034291269 910149635331951389
919010447649296584 4020696371570422 126658688095951521
2266224840292120 20021256536610942 822095374346349946
412090749571531273 342736606127496206 229867520579457971
133676781722039512 898986761887165488 95145036110207387
474491848081074971 418819764358622808 957821786401186963
723881195580449635 101015861587852946 928078288298879615
719636160721603339 504713165517982563 331265001329439626
700663689511684990 162623581095791151 1815968748461231
327216166360454028 20881499643627457 789983663791693321
889434020464035253 941679014749076129 601970960570842229
952747727218584174 497652895365206743 102121491224303095
925195121406676951 915713813187060077 33400960902740213
931691126872650318 39072096076096504 468562639622535699
988522878053150695 365219634882714226 832134057325811992
130808324488541858 635281410948619490 633739921278846417
837093400605941788 547427877862914869 152000444028357930
805541998392497883 936637385490488623 952149046920475717
189036160008519788 392719844254902701 848825788479167008
964792233448459545 824953516853691211 241140330604868184
505789529729763580 677056652846151247 541778510822136266
947874523125377937 815792556516677251 648178904164170828
846149239014341127 409524159811720494 839449638379900074
15883124117990887 934165701346137716 951514673018208910
518311493155030289 745492818881991335 622908695783422082
149165679197993240 269649906795867034 169481540801278334
177465692431592221 469098415965380308 843817195009773771
54464014888691497 600152209797248276 96740023449811163
300486007371975793 361868954024971454 820773502231454643
559313127928510943 687856302809378806 947418167862601028
354336877034152089 529786238391568654 6684338880336024
904090115068162937 50150428502959728 45567801366082584
724251608616913190 552722131850923512 746137144851054012
289340574245944998 565839218957017915 666260632500159701
135484333285138559 936607192979003902 629237929829095168
68546436974302007 878381915896114900 820266536965512597
560764999382175760 394474008556620168 382273360866630995
792780582871341471 718393984314327992 572956146378623064
75559822724412352 851514654215879033 66108420873344960
406355419211827845 65046918358195045 669545264723506755
710147905379047580 202817697592786927 932510978992618916
339660256403003716 651453408384106558 79899864456837115
359366847806419561 862561193981709949 573268863571283004
61010560411753436 60547735799643861 763855321089214228
935978689793598640 513267324329425245 465518033923744620
465740108187970559 248999882122859111 685829815774895404
581651730067045099 761472147850207311 993083279139997070
691954614886677872 943361703470246048 255989787311444956
799185020180769823 549411999392166964 454021766817502938
673602837448238494 721807505977038970 803794480024717842
27106638146848129 860459230780790349 452815400267462591
378556171709419661 262158749083117728 407980719309408990
23419258271488107 276798214770183312 259362038507689679
522703745205608160 243446480581492940 716690898453147904
901682733990905785 449593233357997874 298655521733039499
376279224877787466 952121715688661643 141773596937421916
641132592536113170 887976367845553076 881543508314938539
378470518755288333 268930834154849599 197379384896048125
75148807623141359 416167830519371966 812901187301784482
308163151520212462 945273600143421780 346953688122774024
791596241159377470 384261362822068138 31329045619650418
687530007770773835 877679273477535433 117558280812532813
208074185491005669 243544325771587340 304943197622479986
831447833910875761 744171390629911261 725038167201390224
827427894785810963 139150196790024867 174810549968914340
394301392261963839 57513419879110916 928631134240180698
479290681428210976 210307778381327434 208943467908471627
206021624429343743 832047655584813886 150921636535835912
145723073753989729 704257676177570439 862784514864235135
871609369215435141 73139727874444678 5347320158669510
938793642647933578 477574981016010756 689652728107780155
126712070804400256 800141135844446328 95998207114152066
121327265920516356 232348546982578296 97395852111062429
167433159298864927 112581222923800453 646951239479016170
603996989276472779 133099530025977542 156642070347852627
228886278368814585 980014274255646176 976253393341985660
465800945150349918 299843656957202503 295486106370372204
767228475209919767 722058223984820045 309075743889324890
158220125984710127 352037130890295682 142258339120590904
719517910777925183 339418270774370200 193622661355136881
431798613040790775 111546144401199091 948877794744043944
436439540747743441 212707568942546374 114521726612517333
166342099184197595 130060041069571373 798451927326998945
888577755647175246 112171912365880853 75379992591668305
9723342359958760 276293637700230972 363764304106708701
415162543456260287 140518682628694097 979879773785598384
902843155412378149 667389879017415892 618666685476860377
140338486786568619 162391619122089975 611280400028125016
340771485226231559 482133401857620994 623634843390766015
767882979974545915 466151531394337905 471165460572382846
343070417871610830 645222619529946439 984461706106233535
124900779280066029 64256527254594993 297587991933875722
901565609220270320 246216368836498632 479124839379734676
2887474247066599 200904344805472018 444860604484030868
48884188179068901 441936129025380322 418140685351643290
974265932743814484 813703976152282561 47576496132924102
795362962928211684 296398852662487620 844905637816176004
703404330154587065 532081909978801102 453822053498178081
475430233612951085 462781992484077232 114811105289147443
961182374376467631 493895239391849205 648792454865631829
777800627254410846 509613883339116491 620145010559050157
87668248020349027 301140839652292258 128829766605856731
287280287960691786 737399135995142933 461397367747274382
893519911497784298 624838136059745045 358090738315504644
536301638671275845 612402787522745107 424892358133519270
824991041541733455 139032235315935352 467452111572774671
390593352202864492 912871708011075310 926739106890342125
717112801981404875 281785282551030323 136660255491382125
338016260790096650 414264701517029625 264881237067231365
52752034059984941 338745013992959801 933063851164931689
41140437654724185 738163180982967587 919061487481917061
23079536901375153 838263749709466992 174974693945320997
905703305776073477 194770948982628499 513183704914000848
545024950230660469 547038609284975728 672317973243951231
410345137322343026 830570695563888225 385810300445976180
179524516328814371 527795292755653507 304148276155449237
63905206508242809 39279205588186592 454192815520596243
571290610614152630 921949224859334368 807120152092450636
55373544558187408 332622462030450153 377966211902186405
72711874640060830 726942981047216172 437983866148579386
417546312757183201 97762821859684709 516356786756456308
561363920177953331 820516283355233841 581017160950127553
97009000948843463 450746315526746434 951915159259361880
915915999743437080 183207219243700187 417526659703518563
748967688352841116 137472086136491909 890201021405103412
660487656043004777 624206900944985704 921846864161895763
843110447874228906 684303533098358695 278734924930179489
533076795877081979 883604827170753270 744273631157430394
861158949246198108 561136868935272494 333044172651850513
696766436021923974 545014066543317821 217309282072602973
31330568904339676 305432269190760845 168749079115654885
101061617059899164 864712559771545989 655097162670528167
318297922650780843 888612742607253043 769177378462130174
812697325230685943 335562630338526169 293352291188243123
905593323192611752 324382129054742534 763079003330326890
509957076358367813 604358609770634907 727692166125248595
222573191377165910 134931831576908906 641217173068360148
998639432857505326 756706242738622746 981579154864726096
473225104106755192 78366088551894446 207898165394928333
756451727302691830 1469777305893001 522833621491890438
656610316231278963 210736377619699159 520245683900244331
923515701847071374 290692356254525646 958070104114395066
233922466774120408 449913273164962085 934328270635029844
155385488723344717 730410381928316049 437971766446896840
26265086433646233 518584740713572977 102923097597481657
331150032533675779 102102347243950593 749043168699560435
534606016991533685 389991556245816696 178390415492597005
643771783719435249 839591693883300691 227503355393447013
750560003229259780 320272324949294170 345484815969304302
311926787625102088 826037577209790541 282618521954359674
816163313933114159 328959617035447367 692950353677972252
171587471712232024 279185278811376917 987273125739240713
798931621391312838 202116638966699373 601911079378281208
263919219751932641 358360876126743124 578762237756241651
216675444555896633 811559995690807906 711534656892468754
2562155473893244 446450559887694500 121803961872924082
369023572509036524 576451677193022067 424137960353705722
499253713318693 109525713894947102 399869121035324557
700323278968263022 284179671241489279 862198231204794735
988861376828955241 54984065311651110 426168401270679732
133001256744456713 472365873699075804 521159469765070271
29136262636586045 880055907701295008 129806189863575969
694485796850166214 102728449330785705 481928104709150006
23290601129082316 626074918017621324 275673935597586722
446480502572713599 232228179442296879 977463034195967045
171230679138237924 359524690194149978 368141051121638920
284008354367137046 821151810498364607 702293201914408279
760062832494359381 82745702358948655 336234049485801098
811484996949085257 969548902989142405 930688709993214289
294302358536293049 339851989732456101 933977008413242794
385604938813981777 672565733808420325 940734208809355564
637844307710986087 190927947589535079 864020711366547486
533240877779945530 799157819834883835 790071350672987336
345935988777601956 154524982409503339 864226370334008348
749358871646399515 558815053216654125 886803004501197588
331617929950702669 218321149461928168 691610716344559765
98853554183468208 956623388650447194 263324431774648145
859161447580183381 289162175767443431 699921520732806221
9214263414005476 474738133362741202 390564950628890117
456538866520580175 434686017297418594 18745854527963363
702143188314884460 266662181819349433 799667900696576491
3024734552655621 859511012770508357 102749907251820410
564869313107722052 651957636144594477 332185301546050965
143846367817001816 424370920139306554 141273587358597282
718762429228465051 309476176125056143 812696960596527161
492174022393166152 244761677250322043 76150672603339370
386759059886440894 410380586586637906 939780501600421031
752618748812351115 431521266207713482 674953175077694343
786070339321881445 199800450647437208 529194107639782278
769545016574727417 296425200041882960 10915715747447700
600428768048742058 749659192387185006 391896270332383458
144576475287855776 372704679554907125 189388506075901126
181741799699189454 678423755939666220 325647439455162579
41679272046310065 780010701438746816 718969417698708144
844450207116422319 16429942162891025 79304313210533772
706494317282237441 172066836760190864 558279783089996395
916061334856358408 920428108306591235 912578471701698701
220291325550258312 785246698813426484 701510175699150854
177927459052467281 500418892722413269 788982121651708170
895471759640465996 294222197829065637 515501568266841352
16676236791933625 231187741838590072 144137770702713304
473562739753363827 231282710322464594 766902485424852035
825083294683648857 614215119990283191 688238651168476217
827977379449167815 166797499510531106 401392642363633425
91700044199803824 970023130124305 938152366581198400
413402663242746674 450216598365177763 332932033604538468
537949216411776950 830630138836728361 620039047229849853
217977867134188610 415885951921446025 921244093614405704
701254544250900747 39005775466841383 173090206273132183
564020596731386903 779017227767660968 876694747294269053
773788893487409455 546635004138121583 859353016373083178
707974009915550249 368377780074347078 248176036658554877
48827972641145823 613052786861504321 82106014428165404
202815852423514563 832943821005373570 519034793948418137
57166645035809935 409122780129386921 887452560126924988
748736316715203123 548045250386996663 946174246003206595
386198176040852665 527178066918556165 10950758960001635
497298908728056356 679558936463573132 288853976989236267
880234416912425885 930522428595293978 350825659003365072
535936430194463389 256496992199457815 446506274748989391
117392493877623539 285367851903673169 11545124759149243
919127119738324141 897604653242276848 244679962290564830
982042760819660072 576320750477143581 245515880735872699
878886822734452473 615683312242629165 966145208498973365
748503632582439069 422173588239936717 778191453043778647
784514541559758312 213527053144719861 339163265089408954
96566389621079136 855077866969810569 791209356078063748
260122031681412010 406376220442414011 447656504615606784
197915976926832513 396278850920890113 709909728212423405
472782271066362849 806629120133003394 488069277421778798
24267501263403879 979956923412310369 252544671487136482
856715645982819599 567822263479060290 107818722931127113
620475149617124596 100405512571392523 100373905209696701
949009487725538348 511832470681014845 781586381435282781
664940403015741376 310394654768192438 476571132316838140
172641363038006820 821653552688419411 110765510625596613
327797829902374971 566932689860101259 924355872128900339
193971071651088048 311804587901418117 343492998702960008
963290839513657326 52566120175437574 787019787010731428
264195463187660863 413019844469191985 962860437004774962
997477736767864908 298090904056803315 76628117201347303
593397377312824814 310266689627315383 324737595612347005
295321544097254899 750769203996317645 735752492411929371
929290487172581066 220338186737175652 614616348874367918
198187143643911169 416736542248440667 917127475206645761
895558969205327431 973346840675543815 256105689822844080
903795214206623936 730288291992815538 634577810874157358
351521587474326520 753268102232686428 913615784714701236
71625493504577385 887672747577851256 972427627398281131
312708634563833501 908922864890808621 249431655733776114
342996832787684175 179605375521984352 102550701305136858
81597703281251908 265207296675683341 401511004021850732
967740700824340536 231001536197828191 196393584399561181
635988020502951716 665600864667530603 87568198447520764
224875023758787137 89782020134973896 839049210590186478
3671317537920597 113195255448750309 796216408015906147
249309086086185618 742378663869520109 336145521533653636
785966456017369230 818253429542379822 496628680950139939
871556719071967645 298543781122246118 606795025542252181
581619475806230401 482690870106803446 660671718921004670
525230834131089201 971079506814538791 822873729924089410
345215202100661327 938516495531522953 529241410904166286
182926962291675248 287180712498687180 687362135398485687
637489689478258140 458155423895903844 373316897134426986
601104458608942300 352215888143187025 698627290295324975
222214531646698484 33290256405451186 31990392984011777
588562042121318095 922177274050737476 986267777157363481
59959674159262749 127688508365236372 824042877948406692
422523179066188646 108498319062506651 473181713171788182
990933766054792006 717904332445775904 619672084198150297
692785824959620429 47181523826612947 861169188619939918
194683904648595701 46935319509204486 349753655218671093
917464880917872404 649567919046119094 542077085201652559
830086568060252085 935495346562973228 712507317033960857
920365176832792741 532646682935778600 552065828016352336
26787410672225930 333376750174745540 860541224739901375
298167466409098226 646513217050802750 128906175048713023
927275735430232057 536270482568802679 89003042706852745
838831910508657936 383226534945040302 573920287257989600
932057897716009458 702057412026092782 98714226141760698
564301442357846364 339119582494286919 899951630802991846
679578239714327404 931202264668500348 815438254837228289
311855207381557741 460057569766082820 721569463367467037
486680806016395959 38800171135415868 368898639480370735
638461885455000962 969782256239890141 991938623756721119
48871687679437221 580827577982636829 570437125171229692
773403255356935480 559487963888564851 6213536781296100
339543419467661912 382595393494438269 910700052096354993
113637984428060914 170978074830399602 427655462799360831
727310397984338408 421863815595283431 470074114518003062
530812899271059158 566809905751455629 53682020975956347
602129092508881865 552556296125026566 612064627592600969
947214691806638600 119829776878111607 195547749617950020
582921810170198716 217891047241817566 62631362966271197
477609232562467966 76952535980680573 680450311976193018
619528393180689127 883225655797900113 966860265314856476
150474750946836589 451165679170866650 710549017319866568
46725636070238536 60373389792139981 408200063065384329
474210113145922753 597508047957805752 856930114384590027
331413169745277981 752313153047293529 868965164227694488
365044623327617120 510657845023742630 248060197847070965
838514046877538260 585271961884123219 784317586839726815
484629257999570530 278877347824658725 755346091595967409
628533946369710919 7297962128302175 476064936930998171
182492471153573472 513150211354241351 24276853074191074
104916251700754658 914536032074197759 912054222161259068
167052747837454280 564645564868453265 333396639256706402
784335882605031870 401640443756581251 773294736527195629
653596702073236752 828617914855098445 204290122959983952
20507487500713026 160793361227145157 542437115446227368
441830520143103486 602995222288002938 674837852640852973
240696197867979650 558366642781339200 482722616597103507
120021906337139505 127109575110069183 78110378204347203
145627160416751122 39668205018246362 647565431104472883
529390691664820018 559528260315311260 574689502477801596
327783215580751852 425977971243602839 5057258335220582
918965429191503963 115617189120633822 843646579118658554
63765727395720130 241512294121415648 11297689864831831
103551530599278685 605717473111712377 55979552677831221
971007270194857823 717187158088058791 142052417103906452
331184839602445487 239988706354593903 413896445727168395
900919873612929381 675642227341622464 224659706447017122
807009317038400514 349444536837084568 986704621040924381
738707047679172967 507978062236014612 1753899976931394
348579673389059140 845962399498705944 560546318697059457
742215389935731610 79607667748281559 592922239218254549
19379053311196219 721458208605283200 182112550607917027
216777450103162938 146092549099053702 73411473293531341
45539331850232601 317218064357220291 202452747578986030
186020117694049596 912147108249534227 399072625587868422
88818534461135896 475836595763547617 557140887097821
35686242325262370 769168386437353994 983448212527440275
328360232726858076 773734912297257050 233637418652680408
967265942077009798 321356997610741263 264674977711750770
855972653964637978 475382042740774336 32545312305392978
536718200311113042 593278534620890013 834652079723696032
555117868262794225 701572364125073003 635105076894599146
817788680068435031 555577778253740227 618711400002152517
398904563023223458 242255664565572968 747605142617831159
433145153424428290 680314414064106044 929471557429200165
584861166160713933 388108166954770642 382400597092519748
958689614259178817 808701760692220376 933173071687671936
316529738487267082 581566629259562300 548172062240057785
337412862592876512 818105593334369824 735403578415905001
779189708942706295 979062805469362277 878247053806326441
207659021595299552 762975215362869024 365572365287122823
198993282413688606 216371618085625651 360774446352764452
806108706700967266 681187852473748630 766043537674281389
920539785591675875 234333968366893852 154199704485981549
949243461765471332 982185514631813441 783677873355342200
893095890809302937 875796453929278044 852822477778530825
92921162486165314 967382059607418725 563360835000676824
907591167814745992 894253244803813348 273170539446860222
595915587725810438 378833767645496046 271161938281093586
127515677316529850 956352995865777735 495218247017164781
17810345222962470 598385625325876278 914602263267943152
810835468187125532 943210716303000055 127368495362408507
932678664074904986 744797982803378338 350542913362130684
326833162123101075 706256235236433590 965167748138681978
484033210260041725 862133240030739494 544839054396035326
269113929868934949 688959394316440667 842211768199034780
941455134162417686 539855925654317079 275388756745010574
29095136495130066 948246625531293412 907399444100366372
956447186833614218 324424953716054866 295803317907351077
92109124069114426 628885729295770999 599013257750500322
429484816344877807 153594470756364189 218849168730981374
851514513691198712 554607812611505453 292222528407743111
630926555895518184 351082770759364665 233304753169552916
685987308011774138 827254900358898303 740160850756511255
357928547189784249 223214445341902285 82291953954649644
184887173956806664 363616824314287737 995961016438955501
109841217050959098 671545340040747888 497321911536200088
876839155483744298 55378830871775982 462313136534096820
808532685211760536 567311960979159291 969162513717758137
881260337916722444 271091428797188566 673736739037762787
406783346656473605 257779178080571095 646517794481953298
12870781609695952 88527628088296500 241864086757223978
710702256462022858 216791121191513754 934692539710609494
201907908916388827 423906448984429475 162293625550931746
905080126933691738 690347504689249524 610631492988102429
405375871598984431 325147933812396643 541907677909012506
854566153695685348 114818842671329928 167296495565448281
780404806259178018 827802239406366605 573096766622619317
989212622124694108 541754876802563909 478633752149798724
578660406428459175 390306265824032812 138573262005510512
289594690900551722 947098837625441990 868544789852909786
495453197301237452 974723941920453876 814951717277937936
860263501417713819 811380340827020095 92491994238388697
21299003974451761 507938278898876054 513032662921194545
967379906513916583 781885230736512173 374539326812288945
388236635678258037 659364613135469 917916291581419805
806784085835537205 972346019071683667 797392998853401498
178962742110231412 744251485468434453 603875246590382842
676295478031153435 820020656852461634 731888589000316065
279610453020911091 787915542595848215 834336149272799564
434689901695240942 946206274246359856 275503437842060511
859525416189823172 865337828133178769 630636736695365381
242318076395430217 112897879654813126 701457224084197158
892448323109098994 991255316824556641 705437090358396650
711901072930527455 3522350871039811 464900492336792760
940281799515523343 384386417730070364 14309403672915131
122354181530723363 6084334310842767 163256644013066866
737674153738429792 476511366051588395 863972066808997460
972052066124531424 478513991904237670 535413546033899828
496505751620799455 986865629215350693 689374395802507548
339123932057863559 689091328120534474 519025931636109079
25682314136078090 613211612458284549 66577775280440638
829735770255546654 710358233340986534 687055758945264475
161215139355031433 808887483826671085 522293149201071517
896188659846173132 228980906717074551 648535350276332637
865371729518247298 201687531700427639 124080084872604916
680405778155492486 879902948481472066 62844933568477954
745647574489115011 980784431732439591 853243864530835077
280588947244951024 303543701377525931 40607315366954814
322813291105669220 817815644699293522 623144644420365722
516851517829480063 528051037421399994 908580122496084511
272769736775573134 750932502224522700 549705264791232700
468302644497621952 59882795368190784 189137568226328758
974418017968621162 407240283677658776 327988624648369071
261487478710305539 871679230187438373 922132705220723834
227424092730762800 242771675485909828 819059426161526050
629561322375679592 909475994053182746 577424511888408805
211673694201337083 500049228941761389 367172769002730478
532788286707602364 608246285656649471 949382379769374315
48968714155804004 27316568732980306 558680578998376425
966774146495160616 81347720301812673 686898008956233515
963578687911232599 894872993311167613 646292399975094418
318155453557024035 919360754011891529 4919408074190560
521058736904048384 839017487527186900 29349566881615045
84496735795192520 226394221172278912 632029161359008330
914363937537725786 188347704627023148 984960561935307585
270013569283480369 447547584007134376 426498009739811416
190142450894786532 759388829308512084 790248923420413577
540096523120443665 746495482766256179 458874949031043484
958200948720950974 526885252594004608 718759383420770157
113491808241651766 44889636446736552 258940537216326334
13253106944459111 237682844642780889 730640093167964318
884319498473084814 32503879076664782 218537707164897100
175847053320678726 589145129089391388 286466133401691177
940156775840868763 89353190326285368 832244458188830302
654762098149271835 707588578180490080 388548306562638611
110067174604299939 179011185255761660 530795012381914508
804454129714603662 551887356966709080 864169843887020569
386335361140189893 426383901751172917 538969230128306943
137553670994252011 694191472931307489 556480598092303614
809580770565907826 424468672519314048 952995375426532982
705573078085871018 62730973820767882 865538510691411174
473647211489638214 913185366967647041 412824315489174684
502478109106662355 763529273333138620 895094200347259570
163075174296024799 423305704646563583 122529211053292945
983108420964239926 212804321206747149 40517955982076101
141036822992629532 636371162685059046 652417010275557581
990407948747816081 828979324035151850 915177380494075921
221103473554262589 740931203155039581 325894742152149585
18923145857352713 952498867351189611 419200176286383164
846879229760888516 879116500387522625 759788073246907615
459558712446709463 866235646946059887 33722575742427947
879967453294024978 216231245262167523 698399127142288822
846167192153953139 158114946627324137 457385468322331567
170853652666793643 390870669152345754 605056965296397649
10671601394375316 621975774758982564 582442490176092039
272035371260446351 392629551432407957 987699651281791390
256486081245148397 648872689139543800 971016977578585274
893314036702528189 456220506291238841 281307929143592262
337551689553221530 45574186420336886 120125701876916703
90612957438056230 414940321147232235 485408176750149726
93533714049768570 428711736944294854 771034950735786483
670262781889133003 948970855612083845 578770141996895794
121613948360024327 945934002008790324 978184913340293988
884718050623862780 315689968026613277 447779736229823578
578992424850440494 589102235079543717 969339760918433322
473530795852234014 621536052385959788 333333370960965418
558849197044811980 697883412361350184 887642168869072237
348125596453394013 146703961688262323 459637983278135100
817559736600295621 424738560600198581 124867936961804301
868262461423841264 629505370914964475 827186887033295981
608175944325282617 78743170274498047 433209344223632602
951542545418323802 949781679692712722 128078518143814096
314520014727144190 50574504610913067 517193613109067168
155973138143465224 510703071751548504 622821397286266638
527075064993665627 553067036760833786 195836408969037232
617553404561604400 969689155652899070 602733920000166706
94044295098672418 691423613418200842 687298168582879149
995243027080400886 337911680699864224 303817926039708736
789179240141683126 920785365610509997 381083415505063537
346445815989295295 642551948606459385 757959620376537227
773482979261199786 126724049816653190 74687729385180516
367955051886317786 788733803147189421 971766093515949282
109335601957888381 801749041813663670 362744926145584075
818922496007925060 467915101767254752 133984636213065605
677365134175398762 203044375197534135 288846599619565519
710295633077819221 792255147289277726 305400128741818959
825059989705396008 576753450062187495 932868358363937669
305924487991832432 834558347757366857 832303783409690073
605314816509208033 807726759531312387 466080674111627849
809023252354571266 311377078531087280 766715591964323985
417618406001978355 658007149288669727 298332906717798304
732627054337971620 71827949074391613 854504900515237691
348312112017717667 565009164404513894 492986726698353872
648984418365092916 199784197973946808 42695505151246352
994404367747604113 574955605108425277 135023865445554756
207563803753581924 657895710599313436 465717151750529378
987732541153192628 72995748465525078 714796145394932286
412336241007892224 912997839973886422 261059531269846863
888725612500459629 353197683467295806 190947521045588081
116892187591731170 409816373249907544 861600628170802352
814280299976657870 788992133944034167 563413788296770711
321826563316525060 781490675874829125 802146061127875416
357893006059448241 945174753032415956 31880594601485079
670039356383797828 544350463725409733 505149904171189352
883333615986177739 461261001857225141 890055532033083624
319826273649924782 80011583266900263 244543294512664352
893816492667116860 987110019440471390 109645916426501549
91438540637051301 581591892459523899 515073684586403483
235079949860495250 936038191396418342 903495295134644550
533386078251303311 719061783404462871 98706523317100096
183355796733556969 762162095641819215 215244702500984923
490013813777417210 10542703346484615 157614969385618802
583900817708521817 610015722880114099 138975210537229513
179725676053881188 346840397754839239 117552406313944751
23183773800292144 864715094965323352 480815450203072809
986341517861309572 936579897738569415 360972087349965860
362167867621968834 810856193704544745 618459331330057639
251060130213595844 377004689716946720 784520653562024178
337212652272477433 68198901377983939 755346773692917141
85341856602501439 177198845262592707 67700206728246380
971507135626709083 239569222509579553 957187564289594302
807653342264244397 686716981428408510 519591431316024226
804090348490623433 439386525763409775 128726505762199435
238941524902113481 62638576825850735 624991413139344252
622656135627125167 248032698264936357 522381387808870012
517312990612425697 584805418564860524 846578728041720048
627107287757873749 503031168282477193 740426295484444165
267540764328888680 17387160835904174 298050178937164463
371228359938004023 541015773822400610 449491613993724398
266479890942685018 595667918026390178 404044846024369732
853300885914772381 628163709856416250 603638526206279519
318869797188864787 928459055487524616 885909423776637125
747260780016642948 852120992030344418 626929358038884774
259525742261441853 932577692903234968 533918614041855564
440470930415315361 709685907395916495 244724240903209997
858912875393570057 995353074165403750 314951840736427297
363883306403522516 651108775128881268 459202145604123906
756046139385224894 792225437422323405 474057350204717034
559029708825093825 555789094849965962 161315976043937360
319975264553453923 997540872713889704 524052667459586860
870389194900391328 761736462296567773 877354416711917292
286480831804045232 519949596509763712 433376245494024698
451522501195555686 88002500197899234 231316046422602138
444614427181437050 422905417358394938 36976599131964925
217723161676248337 496898139735590033 155928490618365239
971754945559626226 563524502862048007 860258679192784545
789121876852657499 672374245964627994 98628450841963013
490357020601527438 778986290340851046 402611586771110816
333213455270859142 949046450592288873 366653094319986739
788860601172791541 887083021181744257 711693501214346943
477586888089048940 616504085562356856 901059548368131041
521773300646518071 191440009024736736 560860102361479368
777952100379453697 386024769374937366 445630340590266905
415460614301857103 511934755225108536 147999306918071720
994129464218855634 63399747875020006 147175236750615364
492417614579815131 495113793996154746 494512875873866800
655421436144505821 854919347570121628 456381012348257960
155473058312837140 2751493474129459 182135296741071999
701234581052103871 340352304806802530 782823910870928226
919363075464933924 188144172286507074 814514476518017588
995168281582656514 756444760729276354 1880043101942394
490351177878611584 703263686009926301 554396994775465384
596407917317018059 492244272592742522 569294165957576241
732330575577016233 648879724983483499 256755979283281992
936707773790254245 948424588168395708 228278713330776748
430077235688361285 698855069771132260 703096604645333100
109241196791187867 955425888939558087 947854932928752585
612850374421138242 806970588422684030 126389622931654743
142783273277260200 336563287008599939 361826792893854801
695842049449034838 703671231777616298 144901366789462067
952267616965439115 307289497723673110 946387646719562674
703215064820232713 404143125590826107 100534078126616338
862183595348828255 561489044894436329 485997487506614802
797192912679847230 601248258182984947 45937746608333713
269809634797334529 858369765372111899 663996542274689516
921064137083809025 174606677435075161 809137714811410619
362015968191429755 231846577553155307 803275302703443701
709545793384751126 732624185367276765 413317749086155556
408238577223013398 168428959486574999 106478409087839448
275022324906417494 423633946673784495 208449235816317342
157147986589896271 377339799651174716 656942155315909629
610865792559358399 551806338087866209 258546012061127086
814222086374676100 160755354412741801 776144692022140270
799667715913605321 725989770138245992 268619342461050922
261377525283563728 676850961572374467 854387021306217437
607125484671805308 681168928307671322 839950234644957020
385844433443433101 174079928983545429 658932494109446814
411279942528347656 963404446395096574 385411756861624225
208696021581949152 138815484560211606 115044826209643344
467060779430083530 879717802559897879 307297402016024239
332440401847941249 403170373236901702 656007178204126381
659687255412835675 938453113391476480 267319435194515764
41610478897365949 349130805377139037 859212046854190645
669172050749729212 561015257800091553 549615869962350562
53408931375562239 696230574922186906 599089440594597211
205352405964024531 699132321365465388 446203666567111589
481262207334070314 892582574043445135 403706011894474758
830197424671817017 801235952210570227 652921728709647652
365050472319537858 24575097467896532 270379695129070361
745678453120586769 471417251406234509 731779812931487952
606530297360142241 381984287155688331 154868119299212923
532263061878793143 787457788715572832 25481552200831048
65016203892783439 395515575966713961 754888232031004363
468850456173615961 749072868579667675 701572097945013193
363720173271972503 628891071955771955 163691531387956610
377187145748263563 664691121412211828 641902778633636169
479638029488770472 504507364703400830 116597895392710195
518692802243188339 487074270098204763 712455282142431803
209661671717869477 57291212251524003 741334874656167349
283748979330767226 705164072132459738 858719642298618122
248404240122592098 108732584355470776 680230265632451763
695300833469960191 547031340374879009 890964664261799846
155121831867363187 868154355301162289 417764808022004051
863349823341221529 702702715615591720 985485929493451582
189893567806387017 364240381774801693 999691296748381235
350561546175118669 89295029597060632 695964996012673423
275397681010294735 990780802040541541 662470026651133134
83889777716565073 90287988599979654 998536036876630813
106104240001634053 763552285409412770 830443434806826461
32792977481373572 975806352407008991 513355764441929497
784534221209679764 423153741797956238 250172497076857120
458316570378602801 379272707945687840 49754563298825362
489460116288754096 802304604952972250 389215765875626101
538756756775479176 227321084309471172 67200483370461976
353182530712610381 201504758026626785 609462751586471923
271878064082781319 263232443334920625 161118029112173476
70527427518900286 438733669467254489 385582536907057233
830527258511068133 298447156189232081 735720185099426610
438335391729162364 719060878233057907 592296644235680683
918381876865466030 322542098834298749 902219880586156370
456919890752527651 315149333287673051 396698246768941139
691001984930010176 899859476540444761 128698716356567598
187541433634644471 568704341111986969 71936560746120914
277220105132035758 490517013546417660 928657707256280197
817628670777092571 966663477521444913 292875946686527249
879718241006149721 415936119370850574 780401040305990953
67116417568401268 253037112613882394 400199507443026160
46136758449692371 443889630483584880 291195643768605555
890752362894014793 555969953977646079 868535328819997674
799703200480411369 463876007130487729 547174846835790683
117002281840174311 416801449662259736 936126512788214311
365829174896514595 154810755472075756 113530040797349973
746704248287735150 128018108117578347 873439646618628768
887078153594379556 404694840139756446 736290123089083846
677300645736915243 722045266203195085 358420099253352104
679432799088062412 724323631898039529 466009981775018174
25453194784570066 869383217936018537 425394064321097387
118807311645345306 721282153226366255 508443098013867676
980485395439841639 464953252281058379 959010100699490864
289672717757555390 554751104529264806 40500403186806096
965695980330505242 789562868270760227 137716514094599937
555656170535760489 561456094933023091 952842039912872113
712571655494306973 175531941704068768 923170395445808037
705622034023962891 846343579346937284 60050365795657996
886031845933049205 868855131984964982 429140672952205632
971131746681464728 824757152330178924 174727071873939224
649738364839440140 674292040340754770 56459474593251440
704853988188485521 519695492634211993 542840750932762879
596757557924372537 856904438175501160 843147674237908359
965840599702382493 13734450245730767 362167645553726636
224292748590386667 965074752289267410 463185174964363279
278536264357082444 536117346871731459 765994509475548047
381928591395804725 253698372101298617 534894710885331357
420779882920996965 454617656847308360 730403678984803164
957047441948318371 312194716672315415 982186634042011556
674722632549253881 464737644056077696 131596465228660776
282169660915459438 145064512311513954 609023815666021564
87225222863833935 170174147739784501 508895013389386712
915537291590080133 244049137627718642 437325433461845316
784670887469761155 257033129409209086 257702763630110378
436684207248192345 136621925919037197 438586278220098752
577700675734166250 896871811716504845 520648372905834032
951135751771500224 621950887066446786 632999593763245710
369407970172834359 942160717539292888 702203299894540435
771243887755976342 653629633708011648 651910060763358072
592387642395567449 627657371597104015 879806454798554394
78792226137487815 639443478188948969 518837256953434601
353305670097999161 567167762058184706 310939609198287959
738410601570010755 441613024318236064 234790602770536513
325477568092987292 735825983350841641 899378831806314765
981831010862822067 5522659247813146 786122025671978790
666528213831315189 177092932774965333 655841745786298328
432280243495429547 406588860079444428 811006161161346364
297959799681236304 502037787334665632 787032474118941520
116506126981111243 105247335428470778 772680096594183835
565007190720902270 279689888382392809 700394129622594681
357086832442840929 876538855375834529 813763299246646804
491752345283641325 377561659835547593 536571278747461793
795321561533102359 909973226578605271 258066578079808298
836240092977809192 262275569832837764 289916393941353631
843651130010515202 250215282535873793 404784870740422982
248235952221397554 188839006564041027 105661385225618129
970653977963055643 102000994955590750 301605319194380052
381968288374134865 683815781362404893 38648975779317885
754831663794496291 572260286427363057 637225739099468072
372053937922727114 412998663691861038 24487092015502444
158235785241403534 248749406315256569 586033266842121102
394667335096759564 978326445587896642 534231900689623725
205838728510432164 777243441690676849 600540274164321984
507140081754244102 453980565789093495 989254445019347424
49855518201749810 969184878767540770 479653606231415820
584871829068838612 362223450436936742 485418466049127788
575997131930028313 372891597594414712 552609400525463860
528783588190544236 859442288655185947 353228320033636860
161026714829095699 835120538867539441 863877200860793416
445020247230427270 912673970315498609 852638535767411837
648320241613192262 754627630500671704 806359546702260541
679403952233091756 481284216147861348 88825008966365196
652313834854046383 853380388399737182 961056048040711849
94452541897079216 33031535367882466 904902138827738851
505757721190852470 46153735551013215 101345707748605431
157771211895533087 656939818312248752 375532604870424961
657945700690131892 767824577349732645 765678846740331442
321768637046913307 251472165118065272 327145798721507450
758938552066668909 889553748138883310 700020943496630118
791501654930505130 889687367896433369 408959123859719635
763208596433760504 120165802640211370 347034753087837838
264122499637683055 695640402850418056 481473797961984853
900752988310672441 963926672866340511 831083019362464176
77822035149986331 529066569478425371 828254512466300892
923370330722352870 469309451524649024 237324770922453119
443532381904879081 982933643875758582 388622137890820483
72893273382213204 934832738030489648 43941967403563398
627346775910554032 963771306550319498 585779268592263512
322757305356606601 470096031680194272 702157275688386729
195831293700440502 64569549022032067 292519022078833725
816189343761060451 693736157810604498 83767156792467790
425936273273570396 34077356912225253 775093722187635951
979824665300813087 921850538942634947 778541386615259004
563520712140368764 955408113201022330 493353037259000692
697968005171487487 594647899499513252 939457126089512042
787356939921197917 104110656699854436 522338036786228659
229034899149337451 602227517771326688 97397081420655154
870800161135155917 470672700220852657 81018170017295696
164386739698617859 571786118640327462 442445529855168647
956014297254940420 777560800506775232 110432199246818634
755755779520228158 768916547824631414 394574899371721140
18790849595355317 858496422306166186 412461532856285219
275677814273412855 23363933413389489 988605782720495091
523872515732054286 597835911393718923 739707695802310431
163705890619945654 278526743502599582 729540881682474044
902423961093608122 640100020003929482 453513703907059818
9599388062175749 69656860574004623 901037420650474853
858335071684022436 845058087043052173 456442338116945790
867501269877109076 531418407516203118 13301797531330501
231948621740361903 914284755348464300 873960491565013936
627096181632299056 887939420214386660 510605998951605819
231726539331301054 519423099054994022 772112511789217475
613449557596209805 895165809084101314 427059532880961302
77392219718592547 730879359050147076 495449055483912683
10105205836137756 595883331990477351 894098300148970727
317785528379606298 918007541294703611 106409521956111818
859214222405770247 631699594689702822 844967656130506852
886505911983976654 873558933988520119 787439176285163031
694213956543943408 333787318456383502 301722001520478322
32091780799093055 767607016368665242 552532577835900402
656810887501802094 236279216642221261 86207762286169973
274005358036658435 969471719468700191 548700589262305714
738017846419516664 217375643799851602 301825525320221074
354276018485094590 597142366463069306 75380792991220751
554873893510538290 901300702389285148 213410119670740963
581866672162744301 667408902851674351 869629820162733758
29532414992964609 548712798287611336 899126653245832468
250591901980084460 663723258553414419 279223930014102021
942456335030595202 189724465951652049 892476937763520356
548522805253278741 496939799949016684 458795963557068757
991604589920589201 863565146770574606 616351566886427544
826017902126757448 9949390382249780 109707398034668825
439598986190199241 686285685277113723 687028457313480383
24951014519321780 178461592993096634 291812733083620181
169359348528014342 870654107658850636 985720647530622950
815587804073459783 853615735693047337 668367580240630157
327163663416160999 519361701452759759 652154087973840807
28416012000323162 417654326838624417 94500534987029181
413831623729953661 142843910195856703 657645081593881317
271992370114782192 876197977833534405 867174918017895153
510637882749550513 213691671203635391 568873626697687096
749032758110416381 564998964191056990 454601718406298758
231608981007450365 878457223432365552 896452809987509647
117224976328957714 529499131033273684 365244480961348527
627596917275820271 747702695772206920 486928974328008082
521899501750387098 733541829485630355 87695881823214615
866540422660337669 650589378405483737 312045304344589735
147643773218220700 699532142045759780 809933076542883347
535880485256301716 616474637784839293 791801452511317533
630996780159133580 834421443499027936 955696312459738725
287901999088987979 639164761233579018 196138189478324601
623920144444591801 399886071410248409 685875249659501831
417047586989843509 134933034028190666 83879451446521597
981221148902289766 634218341479809656 173367116434926224
362848705090530491 878764590955660251 804576251918918273
303327432771841306 218875676716972619 185638973192931685
419015815395976967 923430290647101693 92360978403042703
956080429635663837 825071877253550536 64246713229299183
163466086901765802 189481285809048679 273844803584716257
370440135980663867 508703567208145500 701402533195014674
686293110450686570 108193318080822069 840109986038148281
825973998267815972 319011024937977076 127554561791889358
671227785799261029 564475575614589128 810896158709375993
698284681627595521 195865300194908250 782041952796217202
870613461458059635 782585529859299437 841123094693585962
693770355632070537 55357174861268295 330595119821370551
192576457685186742 445120871286499995 707479846780383196
842190452821691419 736309316300749687 680088165785032482
494299636095480950 590860135900696806 903903587249307691
257902670092797683 247355327790375899 819989805068587524
384347667590634319 188138080006188457 917523574542100171
716865080930728305 820916404131300465 82496021763766073
911865826170325104 684110383386237624 51387352031316207
182232120722423398 695551769350836450 829588160744886656
911375599603207767 474461756862518101 636898098020200391
790494103676219381 924495610774627555 300993824049484262
676512224616314518 411198223282240863 231926390940068364
553843635874695273 972859930893869905 905785647395685546
317538326523329267 815771257213545971 498718312059779821
243734561253323445 930477523116750581 390690817508714742
886056065797256145 367012223804867864 572785083862110749
339336091790910881 9150873175158862 689067773969811548
836652570088552370 915387933990747287 784770036865272115
71343696415434428 582999330234236073 331245777407158583
261678912321382464 18794849766098548 504972059276206640
958442149533978689 802160771478598313 157507884092848222
621709912183990305 61276294442702401 376212433873568664
276005266154583642 881268120667090835 52077327413610017
588110455760074411 353951334741144041 571366784070495557
688988482241464208 450821893711004274 999605466791735973
164839669781490749 667063120689456549 487538639636357875
903402075895235751 391670641606434846 519497779732374836
887144661724255266 894476304357865266 425163891240191943
884746458111535984 511912920620293234 884331205365459729
209929744554401765 694848085317137520 157358039872218414
353003553168546173 369785177104641890 227283668245641445
253699405975971624 322629384160258007 800494140020750740
396120927006871265 850729714116799113 924742150213256950
138373719772815148 731052575152499491 736103539905551281
923274326556684085 509684563651782725 298272238311231468
982265737912152134 443358308561958539 562306117043206148
419267942902849148 915871188474513302 378222528854589338
15577819500516668 654069255469676015 11071493897881360
457454445424023417 921607023376490240 780626086809770961
156526939237305133 344264730680570076 130098660184451207
378311833791136338 747747585504327903 469793684446993207
279534839021355495 152345173806015958 986301070493382190
873917445779635242 161293493969448495 493238432235278862
988746606952040336 145714718081601397 487285594709438500
353135567468644764 787415873008945622 675499671662401342
359209656096766999 781241372802986964 349164716192433755
429856972172355202 103928460535425052 545461916099289065
44240423036875175 908003255760110439 721793026511409843
894193357301370757 664118777314490821 783357676329408955
577710883105823001 128608648729891140 376200239965594820
682579768195530114 820235884268101103 698455690832571206
984942082685779832 346395965671193995 808203502179278760
10122154167113097 314210745209428879 648079516338718145
631798355930799881 961469135792260240 330884133949726328
904961903480295882 494835071244244381 338916904396440521
713491931190910877 805484707339464577 895833692182281305
226159228339118105 611155665666021125 538821182833676661
375778486345998837 979174490607362645 403660497512012744
651817535592493414 763408888867819919 87846116131854802
943166521676493459 737879582902092497 489380109754632460
848291362737092302 805449111624559667 635042001814189408
290399903256018858 32976026953594100 238879388903625715
344759440549136233 267444994834168937 324602298855953911
655757447322414650 196972983363807369 151994537539681467
751578690689444854 151229973863221007 976895179534003194
87396168149412571 428776463737500668 724978307897774203
306584475968523077 241682490105472074 800965869231538309
503293818493227303 760089416762783887 23842041819107434
403971864167035930 726733547208843986 159392919207772479
972721361794713328 797324512869171397 542359067320254563
942092667673527918 766262573939259642 809137293559981661
790713919333835094 866031261229431467 437617002015608186
452214276953570706 468094799037886984 402342691902895204
322547008762699128 422713496543987126 184076779450985118
184987791490071936 43306258283288737 363165483958527805
175706504589474597 514567623736670072 534721975468137401
808574742982581191 933583527372023603 158925750435191402
622816811054357533 199304766425199887 387462311544000188
474814138242646657 36431585040258570 228759007298548765
694149082914928153 206898535138884152 985786486466943876
806609375684426676 386697699505978479 126114299613205782
577211372023329409 546927852825449138 568210618225664579
598156564700977676 454643763076531098 387344354493423573
301394379589615122 228902829889919099 293351958413262490
747162377360477140 544911426464378479 573171151408376415
579831600130608349 380702640049181107 837168237186362238
228360953223020693 210758291004658246 930655206319732807
19409326084354821 86970729572278031 222952502025494581
311870279143995422 995761626392984250 795627817776891055
405732109212388174 56137883517821496 349096546965093072
563485300351351322 597678516835098096 673326542028822110
206299646438082654 880293926941388777 45799187610327716
166661762507688357 3611159401316349 959893856359017801
77836318484319914 953707179865103621 532859523954065460
307635790058655375 570014520961676398 942786999810556848
677832386616292350 454204026940101528 779242448600983065
716693551191570898 817754406885502292 314984990799625815
645333502662942721 891553740635392717 452339175483248526
449197968191471941 486587012544074564 19505006272309213
210849244199111191 369276138308648451 863976828458518545
543066239600496294 438008083452371626 665892041480147913
704304622089818219 897836067764322164 80956064980684812
836869963344788931 503540136053394049 840695752016929912
711455789502411552 238413647943026217 174803371919116301
242005431445040886 606165279820679280 30312272358765934
7329663348261750 931570147263163269 954390279025671201
590725506531032758 88405478934551090 647243592770409517
299861824149255745 97795251812930049 468479135089112402
154888534611765765 715645736281679730 627409104369269052
528012391086742980 462549777412706628 580562202254928804
670318458511900297 469951914151970569 706169978344857545
111050897459035233 767118720566616822 909943664207866214
305851992431033191 419569102730425201 867855256732394728
173430254197337290 856029782889875602 539125416402263396
260349341261059720 185497420782445289 833408068366280932
346200091795299290 351083915091592273 417354084332179978
15435968984992106 662130629086091336 874069466881928101
488319765059768152 413576590512554334 439066425138759233
789432741364777259 702542731325958533 526346342734725254
451873940692203025 747095192737089385 751531258854548247
971334805504937397 487477077891348287 497760018529760561
702773424220732714 984683410656400737 991307244066523905
940371667764964393 758098603205939635 382312680726677506
70766379316881099 557827671518003008 225913489911135787
764894625926940851 379383354329056939 333221104075147615
245877587898965504 558047726908697503 959767270644584444
228549026759840661 984254584329983237 583631686681494660
956081742743929797 843155878632131548 812617404769036814
223264105102427440 838985695808192825 253320129850362760
945052256937931108 266622255119019020 339312889640638551
379907052388969911 417642712596563776 32054787802907276
35500274651147313 23008645840319963 657652593986640459
889274708878337443 122953057778812473 390445577982035491
401735921660461780 108897497770194366 378199927123125869
843731750825721318 677296555949410677 373772623632377913
454071941812132330 14357290476226187 769682298791994987
122163557227808266 174216370611504754 471739870229381540
449924587276416022 168274614855747543 309492194245880481
537102283934943125 50575386658381536 856853669347022970
770475258252289115 96900973184504382 832794385116713944
482410592271165311 245432284677654364 85414706399819651
37106237237591831 850890085218618283 870199928378606532
426754924377289651 839738324305369670 335001457391089015
455732921967582324 139532911350432773 336671069242700174
559202401564388779 718302702952468781 451531776225956385
838105647283698511 550894771197117302 240739418998024667
761468648991279234 813596779330101061 505971527387938869
568078829793660193 78367635836792660 890134154839420352
172283673227285289 178750930410374433 38016616031243689
40543801828949303 539401971549568723 99874484427051344
221603266172870442 556719687411825874 511921492509405087
720439935448129835 743113351015895690 17452327936513784
507968084185096751 956841521854832284 38416440410052636
414681225260868551 444007472495516188 759075176968013964
925099029758541890 129871863000591238 375572526836787260
459969919651650894 107340700817271278 526083599622584619
599693528846008631 196319674103272739 463534618787217705
317779682079522031 835839299411026970 205771952498846920
593142697013185937 35931366722911937 489920799748821183
291928232057815030 382049662747594962 586763348378378409
894906898065182277 56154925844067279 284302051087480135
342298505360650635 842898837898133940 607744565332865378
227933382132845620 121543836228390745 220013753629824096
298489963919765578 643126299323210891 880515097227745741
75396226210081389 126346355240177918 835452963244963034
305269336030914906 434032834622293880 623563584924620825
645502886344530702 813666861468192372 952740504054797730
563254193312743315 302994693142085710 299984888449193313
527297925952394707 774711273449170429 435450550565454875
867658128159583898 663934368319755610 194770002459518878
328462820838847530 959967780837737953 430296107399184126
570721762714582370 999350860500950765 739267235164313829
113447570543596928 57341474513500996 262686677050193413
381514819103792521 501390383145909754 405976969928744649
2812124243624139 20210106248001706 814020287562390173
479414081816849827 688494710101565125 377170883708388429
998783204592547070 41639113986221048 510188464082360895
925211134079755880 83548215294621851 921017377758982932
432373790893574814 988046209815115589 816471068715285886
457971719531597787 285755436161648396 140787759843358718
816394700536930947 448055539107533123 708552855036520672
252864210624354547 227157800135784481 362319383559839423
543197048867790386 197604898999210092 549587696892459691
630349996770406143 477775989899297019 475252361849003247
173243245007771165 844793023492260351 807778655903117321
74365993430065837 455227024768902247 481750664477997721
164846889103428687 953221091474344730 108666405968549044
838002455828230126 210162199110648925 671593140531317589
972307551895735009 833277274809498904 561449053951831313
959013780201576712 799863762066432631 132170389657571534
927260096937490474 472260511554880704 330070354376363268
592023377005408284 57243817543187127 252310965839504505
904557085904781484 887328646633046929 653980638800825920
840719209351526055 484395460168323912 885813764125508077
273414978366939750 529263697470503370 726376790322185897
745015966143544280 799402095515313767 909215519072142581
328012886636484997 745942151303353507 503637521312591614
652357404203905427 674231278551176553 828228511787230080
622272756985256710 978529330692601402 425771450958100738
741169486224939518 208971996570410426 299560066296870143
484988485530266284 922543344060791402 562373055446227264
801099559022680610 404602438591019793 757799247579766377
454913998788102471 391868554517973594 491652758476420985
750560321550044563 290104102102990184 150822833211220355
260418285878119521 728064075313406880 565439730893169571
76065584771629320 887298433526429706 597922113308084044
893406124791882501 673875775621754490 377739715182120154
860891109250707585 642552036167452160 495552679127941597
748024318543807466 118686651441004325 389129719041799412
700539735465550942 673809572184219546 761107065938354498
931089810419466443 890780473725902530 858882773128535525
510674369201736170 410662157388102997 231855182060009432
673421579934399239 258416073871292240 576431943429024717
694864053080253195 961701393386177519 461092201025980841
985385058437395820 864844711763246790 626535814349273290
925421049482619224 309034576066967008 572088780097889055
785953623230250847 898463070343478696 951266792997869008
811701860772773941 193107053325608392 37243255328682810
737329726806226256 676580236009655495 454211196273947832
222616606685074042 898780992776447585 707906178847245463
525395539882201632 457184939303364148 85422769767970690
573669605889177343 224672461916648367 688102572012017
575768350878846513 454136836912620918 437128430162256189
823023936911980711 328570772084085055 286866661201408510
753288801035650901 742451335948669712 455794495132279688
697470202967825849 888443648978033091 2862889154909765
834332873381703265 270240771067877195 480714269261858295
897525879522527794 136167495819410439 265511973559507318
747438236061037968 253551846177353730 74060697091220022
411853032035719579 151310321677099268 990283313002780883
558318028337167491 334239715533194772 105334732715471318
566129413217274879 358026472880305957 459029309521351915
543559981366457679 955866266355514823 94671516065278223
904311791479317039 291726280814649076 882058482507126194
983566516932542179 29547413655002750 61854286957370087
768434855481165085 319425003989775619 882140924484095384
351391411136721029 967200386222452163 680759340575662694
668306555659916492 880691423628571898 270460926339061788
246252551893619441 154849980100843896 400593039670250885
228641224489712155 164374991302226410 151285845765091214
531660134138249752 768313859019672923 675061735065502884
257906878237906983 490455774409023486 309395931778102765
374116102162543840 224906020425355210 830583191070944271
605457056415168679 925650761675860803 62289605122518331
965628624810501478 38254410189062572 381263685714120638
530018199944796115 879836600820480768 562655411117332247
798176222861729189 578209926167936609 287993037274985204
739739100914673456 11945656496657119 175132647248786871
894746837962724026 203996713682245563 591253650569895790
190548033207631564 803693433048442049 347752148513851831
929206795113305583 84369634714423610 918765053256952677
299020676948806659 515792984070760961 14047387338833365
410146510334084922 653464718952916480 995881261773422305
194026621515211045 813947385551057413 419711915878778350
307068596936156635 708165464305905622 43799827169609671
677520160097250564 629733555773675379 479808270456754173
418670303987201806 797225778964258082 740157697324532872
493495442508753197 256505611218047488 656787985808214216
695870894348300651 837334866798306625 617697272840374204
352621794086816425 186751179902048956 289945635101344573
486650092163256021 254832264236733418 417367824870344611
994614609828572707 924448213240291290 919072006446967532
206022081419865246 405721878192415540 881992900292706242
858089055016139126 63815605285543371 271968295620896886
123038714526784139 540961455485528956 140955686899765643
292899455072637805 421609138989280646 504249159169351061
147605366461494002 468783944267603793 112193229774723913
263262075483915318 869771307094332331 807867719326218246
959744834846928327 851896064366121310 414115915784764135
776017691839422496 320516903790869088 616760271841096324
462462731793115343 403872776216864389 404748327232450777
215180087886880394 93886794099167455 603754480472575343
785167814748752418 932411090894933392 52932922158656773
148969143381079915 796936538237703856 502381347351391051
703567977068229615 525010842241040925 972921707947433258
421227113800260032 207952194725240765 415642256667324539
153561890446035106 731984236623954843 868387407856239674
25627847910598018 625258666649675612 3875454529715906
678674162288653730 575471434522570397 476162843524790558
156745828921147069 555230599751466747 821165764270448172
542846262568439249 724771703661975403 966264872530225323
295896896354268679 595187771801957345 55803493962469190
200085525181697739 707493605887320574 858698171280619229
500470005793063408 582102734961051637 936797384091681339
813459104601566696 161601209583571680 953163087140494197
337006602651600375 24183832078637619 476018501426999221
559116716630525943 924393283822818785 821738483056465269
426367429556069037 751182508651846145 143235260986986114
165116236549951643 187166899603305807 11555007744971359
498857224904674032 462820988928238083 881275043988841178
816454478061001919 791519000468651817 719246312061838400
722968620087499450 358181839299106328 228669673369035426
216081458731394130 213889527794520826 924633983840641850
96705805208038079 91517729227006062 186487662373677825
43927968800479047 416647517186725223 367215128570123864
981977812000988629 418741552065587775 823284306942673767
218445368488002726 443770993706614636 605044751824724733
676665288182147923 615154783296678244 146382645746629604
398384905861933665 110054706314257996 960644003102517557
735789228883701024 490291719291494989 569910344011931589
916104638592526063 26310238514691940 193465086049894480
215682030165613797 272084054769733021 794782683875263573
385993604602384778 944905272745675116 78957082562732798
682365832548829533 930986350071231748 515580275606042124
399321894639184395 515439125478293054 933068721069811262
221187313494075197 761265324978804055 483326531300764562
366723813126952857 929474389444293469 109971664180464080
685217243227257165 498145996975922438 7743109978714484
828503571860795651 581287116506301726 628725564092900959
520253117024630695 167702548887968678 183542288042101022
529394901720271331 849205289942100381 929565199269000252
898790670416892476 762225144985935584 44657132041377555
34086740938080615 909288169571108516 60150049285253134
156021726187268713 570261225265232013 269022837870607481
569373857763053064 187923680387491580 43266469323907125
388431785597083669 28166169963866605 486015132483811284
571846422176088757 397481043507309236 489083127518109656
579354694206721535 759505233549144198 192399756706605271
171158214491769160 564778344115638046 523142474438808260
705188449498124526 292996474698493876 459059204255912949
629694590310403562 593122465261201822 713029853603501827
57729282480289481 501599649616114686 409017010379587699
751892071296718882 384987594133254648 434546398561994572
441070314160648264 405458220980390750 82608663871835784
953668510409936095 308199881374955472 436849370114736896
5102049457054327 506296576028241628 740368892798476302
421040233619658187 746698281368166236 164416638763577129
914399693702066909 410818423693195617 838684611940280817
295581876405551452 401562899903786229 319577207798049671
275540424643880944 442494823215872663 490447937524970396
183715163905509994 744187835858714939 856176656604811739
738243974895591144 384123890237832835 116764892188036984
570903849367106904 424800009859262797 503581782373125339
50377589543809170 170994934501676158 370468614215491782
61058958556396810 411119321868327221 557388808342238882
526562310646309171 706600746543896504 974853952371504939
11125953799086447 90393253713387272 271771092200928545
667163451195548662 113983252192333640 353142800874144126
930516836365032341 729056227181619043 728098186074289685
261976821638696290 416522894586359290 174406608875964873
675067480407399771 839360810240958314 854950056162961994
495579897676297945 123985066106733857 457332846999172813
364000641764014100 133192541177507809 977759451135843368
506504613490429854 993411862236743427 90402882332184184
715863110555977345 839835967760485757 81223165155327290
139305343475816150 519865359772841002 548131703191156202
184094399665813006 33778463420439144 879067434787719018
312398824954723042 645180119853830229 260904430588832349
532756183668640586 709532314875106651 259539614717037836
272419264350870027 126973399964236348 85062580676407222
545855833582878130 72289371198919047 560285050715247743
448385310457815125 445903410135728863 771555597609480200
185491201143256052 217996050015673028 493788437466873485
308496846947852312 169978347171907680 93956182232514465
64898838254137916 405323648611998106 848314891119343298
535983405677336134 200934036319682296 692302948284328882
381790366448291407 660152201615060136 29174942188861912
432617857891857730 344646299020992165 470284396119017537
383440507668532124 609975565522596362 619238531635204684
491827297920976032 253060921090421562 286128404556415249
266841473464686919 729308875911283178 696274119220025447
271811102238309168 183374556573983635 627007940736803678
432131288533462530 493378100069882282 761050927808687006
495669655704182210 423739581864125607 469571855777361020
442509016901275851 977252506678597110 207729073254133022
581488721888960771 770714551744102884 819577755968130944
118231915575659239 458461721259284592 381279743484295099
45577657520122587 843635047624472248 211280140145217085
862672333833650059 390047012907037735 569636060127449326
865630401005948629 643968734749775231 637365786016973201
313043223536084003 938801248647806421 843290054972149571
188213433153905128 64524171537463215 365740213878975687
240061011532600947 946366939871812364 791054077201297934
178212903152271724 241446050301227788 14896757826811992
636539486454926211 276484427517897857 131464953862759967
757576277685882978 864160326069563383 711184541430273050
358976287556399130 559267110995325923 725116294692763042
779912350874009435 399916016470745045 977301999739105857
105752851853309345 585475328977851095 742953618052836152
597342048927646614 511492484413746407 729712436953414724
425625013788246820 269496313291644432 399067138735055822
352083100182320889 187564706576008437 878780751809349798
473283742838522992 809552343373899306 102950964161820964
73160172239601009 611164817346232634 351764709307178880
787568575268004283 866553152383392847 313914570704309111
172763466173744541 214454116571388137 991761264266571081
721899663515736514 858111570525721240 47263503236185946
213254757702021921 310570665526017681 381780561857802879
900480065424374493 264662304656412099 787262556460961440
100360962993982908 961169629066020038 385906264368803033
357661901912283015 824991514841637847 473079835548616852
179317538070079031 127388044597360032 409302023621825087
999333982025245817 55229910749126002 815949850217873402
408777357269634280 400948249221697884 178163396802190404
15772181011203636 570670997905609016 910100508698542159
228909686229988493 615066125929884814 919650090856924154
342533088247977226 689171887749509533 698115017113068207
546468152589288579 748333351829488097 309132167522578041
132761019527454292 574311325917670193 907528778690275947
102506909513841791 430026517332944271 178376970640381955
200526496544658921 141815761288092147 794604966352415084
86457826832994582 122427199116587493 796722074549352537
666782087956295803 844455803960471817 662232572247090299
366083340550689546 76670092693164328 780304832253207965
300019544074907417 255359085003560395 522660730512751730
956926682192576015 206103114071810254 979334465904087830
823186894642366930 149085959936530668 102357434534087370
546233908366813596 896235980485674695 298556157597686121
867940320077430935 423409431968354346 219124106856341525
463286034184006020 114673019100848773 362580590231588732
16245293599095870 598842578362550297 494183812830117734
192472630595398230 701713985810979837 408502465915285068
225765701494132064 197500447069867211 331369864322140319
682801010139521501 937071373241417854 768609566718150389
482415090671407736 744081355387787235 179690989810987284
563246810822760298 431047987437035386 722573980471158530
738744302578192966 527821112634082725 40664412505459103
832279394724350503 258466633415587975 371608503195503776
417997201422994816 703469715565474555 46266654753828915
824906936605676858 300208639502043325 266187500193754191
226926745369420777 960197330678546647 133838579465111725
140463719698861218 797414323371115461 415824722646231178
379451583365609651 422908465810610333 548527631827701708
623138667397283904 837791214756001264 481853493290352912
753408274205216411 838005286683124426 718817180562230525
301925679183884646 114918798025780327 731832870830206139
585346084714675239 426637255418223959 702714337840263764
333216855151092389 811597149784029702 986209134888472089
269237149249663211 722301567735046096 160047166506977243
97517719201544327 897129054750620355 366200945088369789
367519141441295368 718256875794080751 500822168569573068
519260570349999239 391990597458341058 147883311217008736
104191412976095999 930936707429201383 411994076243624537
614180743379651919 881787644898475708 90771517703552797
680585725169170914 661329772232175606 30399749027390918
985088112751316902 792283048014060012 866148118162198696
966847887946128650 682760009465874831 991293133533061021
690273347773864810 291553368904743372 416394512447381177
3855751604632531 107811693117179144 297324842863710521
716848887413773524 674532230491075207 781606217619014133
255278434181645779 598512060658306731 640399045226362653
684624521040474552 468904015241704049 800855865732609348
794010443948966764 755657979402615933 325017162326023856
505805150567767781 838711628910996613 311663372336809727
260804106410862711 117599495742163063 424628465697368753
701233088475701532 294812772664372736 606611210513881454
139466056109729711 916426828529989733 785431846074106949
697524572607970862 527392132371389810 683825652821269162
164687727507307941 986868827827245712 63463939955885167
323161394562205797 41365223916257373 140221008325860427
995512670844686881 154523181421631304 486506920159423703
86711126427194796 911861494015248300 400991593408455874
915113774623511684 541593948638021596 739631402974269512
661090320208926825 939305646444281856 112069838137226624
913174466228137906 358744363057903234 789850705119233498
629791950303352107 88036644716495047 351212175592211104
908310473540530384 146526465017584638 875235853996590066
853997510440710646 343878330754840216 265601921068881888
581803258854260151 218370959851531747 820207600316235303
102031060553226841 959612197096449334 380676511605335694
626281511757837908 76642016454521540 955978699843330687
504926287037085012 495731562550705220 867137120361838858
680777498532846953 121065881750490919 641784916628296169
35761304059340791 764711631980157887 931070817013942092
340907337568035971 977011595957356486 699468927686504411
29058095862702513 388023541781291853 45127702009948351
393365355721471816 755220864759870841 229008149054875045
211950327774768518 454093287354722562 368239766001737595
700790805370986965 623361497317061692 200616720770368702
410084384539669373 60344008875948153 704782403819712154
83324080854672646 493204862111150606 642045143875870399
455062830112084728 174565619317456199 678091659937388368
394394735228972566 295072056805085092 744051640273386013
132671333373703631 762296562393117409 296010665705301265
543648193595947630 307763705015418749 23074566203611919
731673405473363026 31058180749140417 472804570323475481
785679352997408877 480931013633858938 56263400153316066
826316157319303091 412196039711155034 584812612541074986
794981649932266039 895871888283922743 965380948264068359
980067880430247992 127750911736017018 499744271633051880
177655924102189612 825130281265047529 36272791062625546
611468931731992257 663803662666362229 513015081437008564
957431668810076269 358391763720921399 146896418028726779
264558264047465870 575876382284459757 742280895265115009
223698333560538583 993383302072675208 591467895711949586
211846562242774052 89470774951359618 41875174560040016
238376254172925945 256999244176509817 439059615907010933
920136067282846355 119081076123751446 567315794133152324
640303875720778412 48904422818179759 843642177789983601
563050662271963144 824505828235203320 561804731343462645
887483074879455831 45780957736323478 117872419091188916
73114123880454241 100025520273352657 781474559924889522
803054920692280350 405170708652003584 768465251264090115
162003906525527366 382929481308758532 270780534105302638
62759106380134104 554339240771755575 612357069960789521
528986507551944283 633454576028545653 908091008296150459
264707969218320740 804904511464302351 776478932764378523
455114788276374715 447957941917339929 113218427447129568
234923445363098201 34071180391698587 875517962230026435
650356680513729983 707093169320082523 941867945827871102
31966964508552400 15836083129128364 262648357771119505
767693926017716449 58870289205333318 895266497385760567
736509683771432603 834221859158235151 280298344198154252
452341488339778840 724622315775155521 585100975423065783
329774787977317242 269677168969267586 937133471402203935
205864308116945211 889241830947453147 555469200075009224
128965642679769557 46031469334828927 205424992451104513
512283842975081426 968423763752688614 412441751525931799
212032114723325082 15192232582235795 578906688374540013
353295990888148470 78582331167847128 237498412394669737
243643694889244223 407728275610626272 325300740720390104
624546902069648801 518282539205172591 952678259566811643
153906020445239609 331126672817527466 679592828959947564
693812736930885236 883329673042298435 638293577143769463
753872945531189439 8552301479680906 6597799749207565
116157995261551863 910572046149724113 732034203906626420
203376993194419738 177787753687861884 17164708597435574
761070114464602763 122135989959156193 586458142727941140
199746266810954188 165758905237496117 479167191167910910
749842891951219471 555235268912549258 52647840404147763
157914931295581346 698587887869915740 871599174347929968
550770168515533133 625885501210957842 964656154360711462
662420972578043937 649447882168743348 551924999780023588
373900272911603013 564313510752259143 910196246773353619
566889209447127991 826915520278783453 819469970384936630
577933364308723581 60535814660629325 12581120925162915
564753115829007654 895617212757420818 224632236082387324
459464516335220123 208155808000784552 894074078630543697
514935460109977705 739345144011149166 907293507377400847
492011634604282919 811347391980191057 392540335447332863
121530036799484579 726882215735064597 891997552067647224
391363589133040110 815437266922210909 953403189174855273
946160773834728517 262547376561938432 139228529305517724
64782295496845315 891034626778043047 393212140283332520
625410765446383256 154237468609728431 485925687402949811
218076100375241643 339252950622872518 770672251576353947
970831811983452290 821565441909608041 818760325031947397
984919012011384066 314648496310765126 468118796411325564
676747361479904894 362958508921440390 244754384931208899
405764582440378152 681109908397598006 918108719236909755
951408716753338832 902574767661754114 625901185831608451
672800747187455202 708553958878549563 516597274009795320
549501974445266034 132170640471695727 44706236723786549
804671745153824109 879615960079238041 301892149840767764
972884166898869597 851373639777699077 964283385816967300
207207458369729581 389934527579220794 635980803591866389
446348026453421296 113354869342486663 17943404647602482
543947935697241720 537612748169128874 63466459634401370
6303145468772749 477567010233824620 170304078158949401
263208753751323793 745552806721427576 298951437013229759
107019744443879764 563816269466147420 674361585103080540
401393993845159322 72848217907556476 588432330520625792
698483376486293674 248941242124086998 832813560046703626
524491694473843082 184367545585746724 241469142329300783
942639887940647106 854848787196240867 659131661534263764
316235483048853089 714609854231804059 667027512240871497
577397642545465143 773973874705352656 508412854060907833
449426704763733597 993578181235311806 930401973699053801
987440833512374901 263519439084569871 53627430712986954
147750882755819452 56441545203149023 274630702692286731
426200375279302573 357531880707414071 817883118975099770
122414043614781768 324357294712549873 263133039162116146
87074236390033483 976797308374461378 377143002783470527
544583303414088830 643605454567372400 390081708612719783
599056942907419129 692125331814874459 474528232783346528
14841072948239752 984714331084591674 879787984208907842
153592890781103928 969370278790189154 988287431123668420
437637598817714011 108898816312538376 529203014124281162
910032216346051599 804886949196844090 343273176210003283
826699680493471963 261452224798774609 792538564810291772
268853105630840980 944004886315985631 599395188936178912
992690744536170259 211511320418621876 513036032766966935
631144429515490271 427153629474830159 242721739843307671
237647572636759909 78694191287698322 731539869486083259
606676479570441359 590557278423515974 152754426968356863
514836737236757779 523940944351172333 836261168599987519
31420610741477961 462349767000289367 951295466384493924
127045155988528623 405807460684675948 319630393222008675
568685479036810403 148719479508068358 4342476324173420
165623691749460569 261059272052691670 178067792081356488
725368368536802092 220268361516605253 582524842606580240
379749459808810127 406176249798377632 45144953572864119
844216043959110373 919196369412030801 928970907052494728
962481114270694157 129474759107387089 563508935416393997
47052623346480332 697298924102425999 754852564180165314
650759303368125005 322931454441462783 608684288029535810
982194471943461296 533289851995911367 495789843521194503
356981493549605328 774411750816300778 523015941081532332
301121887743741796 822416815409643951 821063381416992963
350361488719063137 604110585396431566 818055149943354032
149541769292024586 678382457584425143 58955837300685738
664458358166670187 493037910872080745 976389250632848825
553942697171543213 677739341834877656 482658589288057369
290974599660381669 666884760991252002 500259287464705720
719824277194770478 4593984930691044 804324916893251740
317257656441416238 51399384278509127 694925792595906804
201448337172533069 233346379961203752 780629526396702960
814728395339238226 809580381235243703 666790991521301994
681894870020178198 236338901380474086 459977724136608497
416255622731440522 244665030092117686 609766562808749456
390453213173592677 342349308172515441 63723879282672433
896084848016188905 218101618416166935 628945578499987938
656630468507747293 396884343605206405 220860322737220176
133832794179002743 456188012082982034 569063503955517835
741792317246896377 43860054602018191 85410583329767935
216033054999587650 837824573411237970 937069253220492769
402315979526071394 349638883918118530 997579209242200871
540208432231404039 284619102265068004 66998138948036660
111370621287409042 720784492835536865 565177307121355047
310201753282071760 341445290205908827 90645380144757287
625979224616481713 226559283577800426 544216105691438719
786234481908764395 31461203345506444 723909295462962600
731371842790224295 968557048478672377 973534065728161454
348213525573802821 949725574790779576 85746380669986718
21610118202115977 510705487322737549 302476979798944075
780937516384137929 474037869414222200 201019798800755296
362437303750868258 448886502445573096 293033583005139538
575869689292651065 301631427251751104 572563747365579559
266579430771577311 285432854263200410 798408754791341020
444768857776435967 691214347233676380 985138963513169580
364742457474518497 202439896821782229 708822770498868475
667162456921891731 214516810450092119 787652580456360267
619710011372243033 363849598615162660 446436590513697185
159092364926552808 830766259333560089 665588147126623788
12504588226584372 52075205334323322 612408294828453961
309549717798075165 965972913736300617 531208964803131822
788695379143416794 126079443019109493 708364840372936789
3332288293566339 284213314426185044 913377934457621331
984291805907534186 241773543500497590 865288307994605068
737461536057389521 384305520680611550 708212945721918079
774742569408856053 354950240641767868 278529783147190199
86899082742760138 60003482682578888 299266497134719717
506154095427733809 652674844352281317 359874422648233945
830992095287441828 369313941460009275 862800947057697782
427394217773843041 351928458946639238 207923736482484476
663750872683847524 957411648539376649 840887880132003717
222921519956086596 63683203381276029 936025816802915948
442180026513950921 27313126347092970 590014872536822439
807582627832199440 635536305455017556 375549576869843973
277093951039587255 612098617123945756 2802199824793538
83463818677080474 356381314513426735 105089982840843597
165932574400067110 740862416964127048 7105839355074920
569698626208625684 666348568750533197 89841081451067119
702368646702369876 799108700183378371 363306543390903378
629013334700086723 827019416091406468 61066723249596760
809899631512590217 941701887090343945 446453256788723708
605863347027269493 379499579260074363 480636779237742184
205174796692645532 57285409886944976 100931613932252255
185580321917620108 689019800529521333 852290250983295169
199288324903852613 880175268795877408 81789088783813554
90173086286245853 910805950800053142 486577171983060293
227015863683803275 872266190181184110 151997694547375495
339212081512363792 914182562465719892 353954220255630563
793249593793908906 723766303859004154 354612070740410043
778942527221953648 296026443028438860 904696833128586875
355300993773117044 562535035837409663 515590823340538932
220107285195575697 238086571639321553 482908566789454373
970726170500778209 935139066069825799 255343533872254253
907476960138878114 586985934388605993 220360799871033663
358643213707364217 725419752385808890 772667592434995397
877668934042177668 999980508230667473 947423571425648741
892735519429802941 821903363804959115 804660012434973378
68488152539764168 593660489632256732 79745889838550525
196313183316773116 544396879957097017 224978193464802126
576188489503947025 44881971110062032 65750708540770952
918154018525345826 899672286507878872 683337983948230295
203103098608177848 582520836741681312 30027799425336791
494221113010766388 614342852756742275 938256935732594408
685911911113399195 479404892023495604 646861547783423438
789684477200850562 67170187457957134 562107960651855533
302682236582898497 412550600513188546 470011442564639269
127910010068578239 704494759182889632 887565802280869177
260922455795833648 563835708814308138 173749271842810239
459317087539489908 235275255451597693 909466646659750719
410571836018363283 582767095536354274 318738247574445806
522782166780663112 120880085487251980 100817406256694541
196156503061368867 877820686092248639 195307803586189315
299754861697675812 905118461619808881 111239793991906264
745435694804524770 458431566855781211 708255596288143749
902531167952718750 302343224014503600 17313981885593647
880245359301992321 687403870877525446 81500855789845362
3240318896529975 560722514210923447 377287352123852746
105039174532926303 982055643004903285 163882701217083650
700647927898306251 275601825294699928 743646439636147398
557344989419052130 732956418262481444 893195231571939452
638951099158378656 154773201056762699 147826346460474852
747457212326078548 574278509696302427 379423514371617371
979098127757206868 386885244745389493 849610486485740471
357667588752139208 157008737555438951 287871528727034880
854722543562741117 154273002151751113 643849257665888076
777786346392774644 494584892934490085 468288449659062587
326139803734618838 412023898150200861 412790013537256979
895827694673238010 113668432220242207 405106643954723169
350899260438090651 795155655480112022 566095144532166375
701681940531675518 350712072360135585 828589365851092796
760235940465500538 356051651213466777 704557841508701231
737166998902386100 110595200607188530 34213421390906498
19006624343740732 266831131486702811 5441249483360206
694553394343577201 812004694304311685 196651871556200272
803880176506679247 934467677068571157 557845744446287230
915333692276498791 887916834976414486 612525773310643114
376884309826498052 323711320330789600 600588084597767119
968693207167238112 105225864273549964 910012292984679654
975843649685344808 931394732782232354 600745023480599408
344886344822222783 93112359507634232 466357621738337292
982212151607513194 744350504705144060 277608236391407826
89099380352167398 475467380325119726 96733647857162824
797617705969571284 4165583773985590 311471235440443601
741327257578265502 843576685486925480 256375849291952821
462042634257837582 19790395100206794 213558669095187778
268471353146745507 290778746377267716 904912256273431641
9996405662591368 595149598464478818 436037170810324461
685850165795651193 762297785968387413 444082668704104977
227802839101726878 207888700030641126 465026559934108853
204305808441659054 839617280034135021 595804697461043566
611107381960724617 298214974491150107 609453934030145473
188792115120571840 29612940116629864 75709369120699803
446356886847747194 874010351198729406 787901968113630331
810243864252210874 535001747354123236 122110195847848655
516282209891919608 999750121066699272 401148952724953750
368879018428237553 709517408655463491 597206707518293421
497333016767758969 343199967682149491 685318528706088740
136323082162262713 575039468323644 170117704635278319
821887035404681238 347668682530153693 242123732942601853
517735160677740769 621911219162031746 699668060844339694
127021658790499614 514264449001674794 530601330779628154
233311322752521341 773525079476305383 958948891429227176
69326728509731588 455610139256286796 86321641087347693
726979456399392669 608700247758341348 221134782805793488
979128609605518608 766633669094739786 175102488047210696
443811306619220407 519696478379485333 624957580674260334
549149590437317137 25808447684860247 466495533058737537
869315573629195183 153796696265121060 353777495122930003
545848642224210239 20582670245964834 21321606977830404
29806447411338466 494823678572703243 923718082241678303
689665102635255482 401613234877732224 584865700222374239
811543411658108272 830918863779538413 88956243921464679
776138671449635498 465079143303174967 978491688789794149
809247001498196467 640531648620947871 934932236568869434
939072848859762782 127464597403016758 54829712115336385
5530058667156559 680830511883919936 537762276641049979
666391513461694445 675028411496846020 890329399408960768
7441551239601615 168330572018488010 712310383416465647
598479486913615789 850594792190664559 140506090425151102
126125652420326625 965300765150479867 642011403296090274
943668438084864558 851617515005448522 256021748607647186
56549714264520855 767885812862143526 378876981011827245
254650506691177395 143116390942758734 576720471251597417
86623611900888047 103396513702770851 89471988752757008
55284168232288668 234964674568190058 468847187586747667
570059962883040051 880323461731800498 385757538781560491
190802015876748237 441710190595050536 439708400038849625
776684627457608777 750696092416992658 956495604137793894
588879876220792324 7970904737175305 595516065680867576
264509418003996735 888369013529295856 310567215593924963
426580341515286919 224231896451614981 216083252983940472
686463985274248223 836107617815150074 321890222553725322
233534645083764340 587528780938406057 350034396459347711
436464602395250556 246759709954487781 316865313386482600
676346089561474438 894006570576538378 472294694790067283
423738561077786461 93185637595842905 233343524063447371
78483113954232934 248253462868203119 203995535205373829
62378919484813026 587799929403991893 72872204598631948
8757372397779215 433892174707237462 182947209078099813
816495523858231465 566938262832105764 655256652355499676
230647553927801469 376342134321008751 454745243728325614
333755095431030193 561405731430490750 90808613601403313
270199875239646417 504110021321276136 136724001471582709
645313629883760006 156021526812056851 931884817929063840
13850686714102403 21083011611104312 693610989670312510
173913208618290098 507352918335781713 432987775554953129
292152052936647869 422448106759427025 281162393251717017
647950009255110164 242427983649635915 443395717579808823
371576640044080443 438103341034114131 79344914919213184
955002932146503943 95424121247427358 515051162917714038
838729792815569717 117282711289521888 407175840044685242
725524007829013580 185058689444055843 463006690981772637
469088670184482726 557178215954120644 904807597323743328
367574783578199412 628569432960779272 797013398791357323
684759099582643386 292253331862560807 412783257324108049
555658435610022803 924330091918828149 254666145925314783
603838196158186657 309750335379083625 724061599814077073
838310527469912062 704590633703814280 685411933686316760
780582977503877989 529887378006037825 34116891693912161
845427796749746861 182394884494110810 781274781410545587
366575964864158313 656897051543774796 566886280255314672
896393415273418303 786874851188449890 527904987671801171
549747064546923559 215631811924125579 491025636934124499
437178307469135480 149314066631160791 862835094976107514
790626957699311934 118310196014576706 458989756330535122
733150862722190087 165996911942250857 945600855218800587
712483215962294152 909426423912887776 246111055740413453
274990407706413839 260757887648409713 96928796002595331
389686422926656022 742647106437890955 854368696533341875
881870007729038200 103934999064463449 224717726732235925
104468112896527978 929574630483236772 888096242343078387
554442165028039186 526207835026230103 442024312188565384
187796084524465384 811808918188528349 741180827566892879
778830263763569244 286350346093609601 251886044391140140
649664656008202421 283312370787780623 634529091312926173
143922634208933696 984900786054062335 189916490037132229
60201819858377315 503266499207576383 539862285558478414
668002781597213295 74650439665726040 958450114365034690
202264094820238732 780709065023176717 79919757180479680
513471507632668382 570947594307743545 824791978699777012
646383186883589246 521410078156026244 788572337518832938
625534849542334341 613967304374960176 382050155601824107
426962511179474432 466907933657058096 592755884872736842
292381076728977764 12390878985543579 649181186329587923
80932076063156686 147532395928320264 1957934667814350
430795907019380307 878752663406833881 585705547579565843
674885844476616862 620182905206251511 586607254188594957
566037875342605306 258155872183479037 898728015357883143
387676213200087619 791527106488544363 672193911484430621
727898301567967276 177183779282621116 270190428237634495
512635247561490195 657106088967151120 215251051333718499
611298334268128917 399727776747931451 468614979284472788
715621794511212745 183645106354736421 431044826798778579
427966825546232713 505047671134486117 393701664785827318
767842969603853937 25469929880413360 840434245614190192
303833763331358764 703529692239809629 965190656150273732
522726084545357725 896078673669983794 498949417684780896
16354752449467317 933891386822169144 990713629353652246
225876350306183927 677741281335216734 124496022190667427
219166137108567593 991181768084500470 525054488105371929
301453022469594070 225843199578616682 223911841447949090
996011085187821601 878358452638569951 745408310959579154
807025892371520369 891128752498320454 293450296739894352
824976183381986292 415615668139315382 855285517407480108
955792164970365156 450678164737360189 151142190212694568
125701765939727359 979834495482260956 669835449669056181
398222837960768709 570831693876895191 643439618031998098
563922239748026969 859564193138102746 380588296561671732
603840517427012593 553943929153027051 839254312133512596
877286625596143014 321001893656911617 236712371720167247
13755745285422440 939259753396297750 473464224150621020
96488246529277733 657607441002604407 36699028245213086
42625374981355319 643275211320184070 651903268217572893
702239970728387087 941126400012963612 719572454978054374
106873942410578271 361563746266998518 655586729294036101
115007639007047193 245344640851700738 825834795220361029
731448735016482272 605599406096908874 904287632774439095
585146409737651948 839946501209412822 634979650916893525
361309453447001270 434491782367183742 148781951116642489
402159936111541784 69879093172007445 332561402386956960
809273146940184848 838683863815320744 365479390718347883
693245533188581501 562475427537926176 931911792963581173
818162379458761032 64115245486640748 911343064153122136
624473699101966144 615875995942635167 597791698539729218
722604971385413595 463214013466341725 458319824783421419
881950227243018507 924153238822143359 408319216933374453
789851771496577528 347732012544349949 917357525733029920
299101240590988477 878425531979140608 439375098813216479
283520996919975705 878482380499405949 157880834551818283
425967281660411833 207198728696801231 249031609852509425
758335843534045374 647775779355399342 792398426038839548
604161729456155985 232597942189816464 556106309766600607
128021867908446923 39259585408377220 82446111441652636
508356048027850066 108155355779400438 757780497239161125
672956475616839539 789950160293500702 594260311293574765
668252848285391609 283633704511600664 738377638232750995
180660071377283874 493884115702211885 425192913727255357
727750563331783059 936459374304610071 18552869300762874
270757171764058552 508313923326519387 960475492123007683
490683956196690207 257712524878203442 241253720941835750
12781435527287672 397449511533443220 854472694181159793
728611622201519522 381076716046052875 807372324052748476
195369641286506220 513278090989686441 354737660049371471
219794530438699061 597555935094983515 571807826915357323
116831933527701622 761714919618162949 672213012378439461
889495318796764065 342632135941279163 315393010053883752
540015059466853084 394985227409326993 906880029585855675
191874627204679719 440841059911656412 503569717142577637
77637288651654424 199134431656875808 810854745160056484
334364322120524376 216654327730926798 403494670201314737
400821029231628647 963150405604692911 159571510460609252
287629999696660842 874289538437650064 516914035702175191
289857758201524695 588148750298356313 246891887595532092
524403081796251802 448897506756968978 832783821024829864
677071720150484418 404470865398381097 928841239203929180
540343650174914581 569561395726352424 987097143818145143
908812093781179550 710658155944973432 173278364249916070
603562072677077195 18457208964959244 613775485521463853
164571937230651951 19737387884366923 399610542818974697
585303024954832816 338628998184085213 938225009597845597
732677678729932761 716640033789386007 242275596262424208
67629079558515809 143230686604335234 943179593087701626
635156090074939213 837216089933231326 146898324632821248
107754457815194070 632492474719640134 245682300999416390
820346264224214314 543473978883562524 667959491820310378
837949055763719140 773812766109199777 188365244160975816
677853320526954448 692768208954615882 872630578287927648
852014655834906793 456943115746023022 328629455132661329
115456489831830128 250998039789627237 453999447351612426
839185312367229143 552525775181212153 251697561562272678
453621576019948965 708032407679557936 874631396405018254
957182056468134639 768183905945332535 174029271931355536
335185482422792974 887668402113982185 726776622067719668
215695916116645805 382714763801437368 880130261783023609
488690524100609774 132033999026530106 241733015210551800
7563501176532902 607663807879501185 605323901886399574
52758358172704988 200634300302443318 717452958408566264
760954671569038846 884060786815815018 96829228198405685
344185981425829831 399311441342494918 570852098037188676
456658602356862142 680948703381492834 646808160488933664
18230880344276263 912006823510001210 189433136790705515
409759652381302272 919946349675264353 642671966029557701
162372945467538297 732089347443043133 187921272705895004
180477764906350250 986330406309061718 386458442492036152
310730952735140858 858275125718321881 146848231111274955
253386894624052778 524155528089241438 20311098341237145
530163799678169025 119440656760943328 111521861978472716
850244368335906756 550756491604855581 512643653406731005
117818470557571017 419000463628141683 626480145196029967
250415888301429458 503304542995393405 425147288514095250
182614600225225228 175440945131389057 127231126811082723
930144005526237941 528187509603580827 442769768159626443
757648300940723798 466575486015015008 823033900905222882
347371133603887010 35010860460238792 445314532114357074
905622301594486993 902902800812757927 427874032101540810
922823213241587231 239265630292005981 29804788563702920
307178320374321981 266950824006615390 128106809431729361
707440539122066804 885836762331175586 19010000560765588
652100206935407757 534966114354642889 967657064967793846
831922833405344394 69836000271326023 654837456582220134
23654374832569579 496720034970168284 135180803999299782
765969681516725067 278247253147599319 435626584960848251
965715313780444981 943089747327637510 645002137456437211
546244003642064179 336803554453091750 349085133298096686
85800718810157954 873170121207944739 613888854831221439
898489950766572284 504950807108334594 6366584768360237
574958461313969918 248249179056332993 201769348098926036
816783704912145826 733424136719175525 359236946420229456
672352193048356128 500111132939616151 689972185691226086
299024004602692779 833378808021192765 272998135212188274
45481281955964381 111694798571750218 483109277336074810
556162836641544577 365653928424616615 989345474732348609
742103500124851550 906534969702315081 250976419315920399
275264437659691600 912928260527766937 315603408995075375
21503554303086811 408737754012242219 196776752288713497
856254743559432189 723824303066492740 274070629891825973
378852877576501305 821941073171657568 751767695094922054
338581783229545112 527608088844097482 405617070819796959
167879378582198241 512244208567521389 120997657688155485
857034997465354820 802590033437124004 94036067735363645
853038897589060370 194953261541006748 454577574875821991
173590736315186359 184994115858279610 78422078426764512
47461921976845357 407808162206196658 319145894567468692
375704181744627064 845176083003945717 792199880204398794
326333149818522519 560418375808541117 814692904355986414
660025810475687894 757225858333991975 233186414985354132
405470350607390095 92736117513838407 36852937907940476
271351950983589564 892921978427585370 981484385404646091
690830714206806790 196192254677574525 943285295398655084
145327086289282524 275878956374603575 547151469057265905
272984237316673027 295391849247985571 306926322956093399
550961054092287441 417057754925931928 368761054239875286
500302663711509684 558675532020637880 157728689137518101
502438366502294426 830929169613382296 336599990111316270
905798253854993082 332208382773115809 497776959170045327
753620526642264498 370512330229080812 873755391074360809
527234111535756540 88789560479221586 119528527226424530
851433787258177336 446218366713572950 478087385090111548
328153869941501871 810197021048305527 83611832927662630
905047283749465756 460658946701426766 736190745980442924
800577502853380339 336821466052627135 784937578844355425
233770221342714299 486503588933786878 394402563986896414
72865214571491587 875922092918294370 150538039390960058
324950051122804165 744388399478822569 45182791574037182
849928416873382976 461245434229380256 33965191941839233
431607818374556078 519665175395575208 903087321170274421
297228383761129653 984134491100102070 577478390614349472
180045464190600108 803013489725980528 523455112805316901
120354771713036927 603021044871031285 90832712957450525
420157125314218077 830017372669391853 839249370794560502
36674173495576623 396382873039727047 95152966963726270
692081473728526739 835764052340672669 598094662875651175
620421606660792204 667138694550616200 155696252296240745
786359982247998472 44338916383599350 255752552809825067
16853585707023207 631919899368888244 522793873619895740
892861016098011880 724485526646172451 828527915485739324
148834017336940309 754427906407285765 578214662289063935
517809262592833019 7623037847067924 962428578842980158
423389148301059425 666574146123201665 931797764064930846
267003462797622685 378452947115388479 868369273836830495
913050737491125604 611520058387069761 458488853789946802
363290727260386885 496075833583828343 251849774788864422
812746028695618402 724629503358694172 219867587459306158
201666625046559308 933170520120221181 31693301806940703
437492382840148939 675431912746752287 974149586272290272
797471101914684746 4804981771056714 622221108597638895
406287607954845431 820591895399021836 266787785961096235
793015699311285621 749874964449879073 53299281768255169
905755920610872074 211602506868993063 63987406314049270
932755340497492552 764735932245506842 834694537329236325
592439800097462232 287119601330982814 714499407472956930
537308081668196226 344068858017872453 8788101107257905
526046122769529120 197683818687957535 321030498568575660
492519905482067216 272104161463830474 538419306044285241
635594667047736413 858601347716168143 419925307457526511
323797371481509521 229886552600493434 402585898461526764
496555798297436053 818483117127849995 745911913173151121
301501400580982362 900315100255880518 410621994419526213
640052870778147806 40719078786965521 117828167697644732
502895168165210900 552943104635428370 683139099159503957
91982180346496564 885851381135887355 690960198643707544
302139750460924548 363286081131859952 134705066322013378
245880555351810890 126970111787059046 882621109326619871
900745252680039874 647775753717246913 433368626553100201
5192390176516858 442123786953265835 186485722443542507
256292222451022463 645836460151468498 745030391156430030
959352242142417936 221214690468827393 557219929939985853
941369019108195301 886408891052126180 731692699188008645
393150810408473011 519618962319894452 679657998104853389
547193212356740707 760142912716993061 86555074274972763
598823525582491909 765040765376341690 972730837746884658
725356142490580194 138796976826994999 349020748147318968
874637177265067835 138225919680457665 841259136282791569
702671070221561314 530100259419350862 952601888351461675
824483155551160164 460513484514727645 863314657132205991
832981355056933311 970581810698727545 981652449998782920
814966899318790473 585308616041200860 430108552066027422
376390103235006706 380832265718024538 57713117171328516
98220640175345958 197980371708527535 460335223546398089
153440947633253065 365435943504197711 561987895389504870
200633436027937412 153411955280844181 561261952856781815
714726082418564927 574705029514049016 330090243720935669
164423405633079196 830266732033030196 914548867026421475
201628203803454699 714349265123474284 68091148281618434
687264950387955249 81599600242477422 239899651448625835
189489976272253300 177598014036067607 814831334711390457
992410347037491733 87715472962110777 520890808101227409
324789221707786970 656378549186674329 629504272453563404
848640449223737088 826562368235802093 58903896069913514
866783594012174701 470714745249114264 794823818305059589
149733839996535243 359320935249987088 437334658319707094
756485687226771277 97432856780850470 793068481183109726
892137114927250706 902760785530074875 406597068713378778
227189471244108021 313955138136893438 745920178793031609
645240293923091648 199656952856199453 602644996943537683
691736149956119323 622686489063703977 673397384050041178
429748602851804463 233022932723994931 758039858833828349
463954061520060895 568300054167020287 79764928012171594
166269838351079193 980848382736259661 557987859090885878
388452030895791507 881733640831564845 882117913839569945
110792203510282611 308978694370808347 738615082528413036
713215713824936835 495978629313559393 592207792294736269
96750718560174807 705538040475702651 902722941628311699
745217476129084603 771076254575993521 126336534670918216
371939006872896570 289797375696716050 258089359895503835
984339417773239308 102060904271690150 615537585889208077
113764450618435714 12037136885181766 631451502185817721
905575314599637173 936518708463745145 955498476300039504
567626157682253869 634203676636922835 400508722605563999
782892846921336905 127521832590278184 487553366529144123
290523185549028183 367258325377446758 63150785688672367
478949569088787639 408334159551708368 399418534714001185
566570165848615660 536798100274362742 494181394882629285
246245743091697925 292011951396751283 95646381774112690
29887561957400966 970727287975691106 904254401776321099
967880021054492198 919140579501162651 249979904647169533
606978502893063555 971719172622094931 997545583188261529
805505022228930316 583509150041297556 689571604234521441
254048103407281294 295187987569911088 332291193645900954
542779836555267536 144373113519079828 936693398219798030
164931744554910740 798016507604591924 101423478406548229
458103752713043901 417934856542157046 788676607560089807
592075399678240545 118459621165521751 734449762813358424
24554221232027166 596218448304598895 293394866062800735
512825232956764116 982316287429071703 70364856930207566
548087195963871821 280159075081734695 79089327029158347
712417513420980858 658672747266196743 223036710670563237
536729746558613661 802380658055256939 251741604904295795
99948434302103472 190243239250673430 183129437859756556
681978321189456103 672783545097721913 560011665109434154
744775224875665923 47766518861893296 160880801266123847
350714734860757021 610911418161979732 53286472061082239
816995763470058114 716031103069692113 994394234688747232
337203684966644622 607837756005845592 239078264718780621
415145977130508471 233202647279374986 644991817802715926
30956534806025955 407587687992584792 628268005411313255
383964088955287058 570621502001133775 359615625207244386
975730709897794721 693613998711532779 61184907824655818
520246242301466319 710644337775505442 919762167303140376
925872809440368826 464243816764940342 275371391353799314
658057764966399983 627802866386799250 394849781968455752
863470520419008190 778177099907949320 540244229311202366
826438547585016617 10213001453896943 279063707060943698
688085104027866976 318050153588014227 912944844690270298
256741069156069454 497515953370202534 496692029648533610
553033833777134937 509971097291292148 897733557819066190
846048553152323246 173636331661850277 899871365458907376
425613152896798619 835988974566971986 982834793833286982
363188035215517482 565227600338022357 304115835588814326
323485279092980188 877148917582873563 640671041598067005
221144776788303505 227712866726016745 763985227467013969
414633515289233990 343627380089287519 758128987102088043
561628453538796903 68259078484119829 318327304829410433
490925818443949405 641634162446222355 244325311444729350
531852789008720216 836215852351079438 872590143815694807
781591095614676530 2073655449562925 41859430034830058
290514340616098888 822740086757971398 960109162076258189
1501324861363126 2073285402996373 197294580585976525
446235508707249886 61793498778876207 466624672709853190
488366946981449564 54920648181555939 476057981599814035
686781573295295082 111072404438574187 789169851115168044
912532129228316931 110457347333888178 11756120161105305
110184234806348831 134713465134943565 342600233417815002
349786959973370072 212259830461854324 813897800406368486
866636294333104128 885701736565540619 500247034976393475
409662247787032709 502065650713615643 550688955138586107
642548104284579031 327449016271633529 924166284404343566
978106947363920872 207236197718189384 190246108274996873
909621622381217654 605124217254606295 269536188631428801
613757879730192536 46142281669074961 728850921699769893
149532386578973980 435159018425170713 578822498658760034
735677033636348675 468152755273766415 706008360746189721
359871642856867110 45418413192088817 36244768413205290
566769095998706874 476243667263034689 844088122107985878
914892578891320587 524338024980755381 422677367325150376
277248647468872813 602770837401619717 894181556810829419
883644222753141161 960581690936197216 137550507322000869
13286739553652838 619605339554969352 929177395173621927
516934659594838039 705743667884316365 45479613745805946
206304123978115909 125036403667568680 374663878823883548
879239631032716026 546974924065208759 228688618033274156
166087973412552034 205408794617708366 456805230297817951
138507243945389897 296678522514290431 942575839735028902
121927376445302810 328578652750794301 266939514402241774
174257765113744623 137261042334427840 46678313378965461
180204704899451502 444027349768938874 745349667417349008
531624779662308994 629937525995601261 610444728612565699
236310981331664822 649130234076626704 571553080472654896
409646156046908161 42160002303255167 105213445356120615
129176186768295948 343061229124119533 96127458774185465
756799094599719370 850519937785224353 110217653644104873
735154621413537767 547004615679505832 832704792016310619
35475752980207143 738068006855707402 825328719095653058
195512688540076035 170467328837709298 98071670417163717
29918209301001651 708471736901761833 23730758525407357
987739155788353663 53914486289757536 944912412381136064
210328245727695779 1163170045940806 844339623015443790
496327701423666309 846731032551401792 36514624643545395
454937036082778182 70538005958030987 185739335794223520
724730344572171510 172278942170098356 23465622418000322
665457183778893321 48243020562704714 302066650546562384
101881675670308439 850714105282542379 39803835186418313
682081626098997113 552719892476114010 846446158928886700
415522708016776732 814122113792305589 696127395799183930
691463149405244079 722685135775006970 814009887096359001
460858914943462186 93900241897492025 326115281310893636
997772857594979794 644240348522421688 742644946675196386
444050686076816790 141892131354938714 114613754297954876
501093285884399890 509748352476627364 740459173306598730
557163530473382262 596311493938651586 502534893887721157
289658842380806874 974214069261561544 331053195612586323
805165471725922049 613398856579079005 316121912508076665
30646399369049163 975309175265074189 484764902782821274
553909131614626089 30109576788070330 217083656805559582
766602535240810138 264891941762888581 105200409345070894
352701623916035598 672327055932794938 252606850299576655
791865724358150248 295139288040934659 767087045170979743
850202857615248286 458899819148446110 564089488423634120
864873344921620940 778291619033864071 430103725371121504
880336846528796695 477939820398622887 689028915674736423
554279079871223464 917403452497210231 714582417389985116
814182975571046412 598000186938093300 862728520300265442
972739329329407099 396876684755582126 355210637204249167
616260046361401118 378400177986424371 399754353458712663
734382980245134790 669369593265971094 383653104150052235
925017531346732777 895374241976948259 317952757213994041
686216426766600629 690671056054425095 867359864744193977
312952607663123684 664312068433718905 474945319246146010
31911965940382790 743663174278668224 893215259166596540
390104139023336339 888585627629548894 477728169312770096
719778312931391571 455774966202704201 850552910338514079
100809887627514294 519282577174271071 127208037803632800
398661416900766280 475338419381826189 215886663425151925
317789080335638811 469484757711047575 749212111883284020
348132828521269940 702179370646748841 981444833438839147
770942286148941771 118656646845101673 324298391435328592
201382051217780416 713472344666244262 92815514916471613
462442605401851493 427629398457591573 674583096658435805
178815950638719866 387267391908443460 245754495045864703
842656599894951856 369581923910653888 111179152975081640
715981947392158229 460400001681898287 730091446017658256
252594882304138855 446746437928951095 638539698322022103
687360882694451701 624366733886016767 361901686818174713
915067162543803171 115811420420347403 325078799950044247
580364283511795304 635825017631396088 319594402442890099
347666678099223552 155435915199319622 436820685136125460
928963715502964414 25723765359497594 556628608679425943
473072451143762811 558527953525645809 503231299672758004
789628907529155594 114698635070484 801270091003291401
32886620151245210 122746038129793137 688773995945009932
320570215448103533 522794455043428433 944023810522511228
44581563670497906 914771515885186435 592648037465653736
948975225577333732 974145418678575520 475440556789154071
27973482532475862 434278441836659500 661276029769710529
162205621795813547 144371754151899147 599473353144419931
723543128130353501 504571793054240389 455364198254488797
121639287451598783 255719708332534652 97674145062583696
818566315599226442 890597504153845158 239315016693820918
601234966206277272 303545565809558932 245648180364805005
958929583299718255 617472455461101931 755495416290650430
934022609265897694 618540410585172870 735621373431638423
335991287706833251 367026821962333782 846113694150059622
87969520488101611 236896335541268481 50579310985984841
624047606205531668 642775621370744935 542354505601573082
501657775015635998 770916221286813645 593112635587417178
118276820434095644 662056751402499493 711307182325270587
575484815444352203 334576027836081856 725127472262455235
198253940309422662 577425912883642873 181199012983285001
951404563650752431 992949545331408196 302003789179890893
240903838941111576 53565638211777191 930177345559233448
407534618013841769 550354770104060770 136201275152293970
467885533408319892 110756636922215223 858470287207808351
529826229248420638 197908104900552589 517941399531756841
400428904593507793 60589495839353595 608972576460986344
30836220895278511 131310882089068471 838035188387369206
121363785784065173 819951260905343871 649012101121101207
488019644501715058 212177672086857550 202073959100243520
822760757980625112 104378734042066645 758340027818720231
240478553670102230 835428331217923165 640460145024959026
126092641736983273 390736958759259136 744088015926437634
400231328710238105 810033249867697172 564707280691907791
396327886777036305 722829130887066038 456553276482150641
893559220033991482 346287710445168592 352379355435282261
582965311944591129 48834202134740072 272016364556682733
698491755719608773 678305046470620539 933262768420306968
562261691655498609 436179617934117387 369160631259783624
318192207160155758 320456215873105 834426066649404842
687711907102552457 353182904479912944 168734737062720128
626017101770884429 160176779528407120 209826338055842103
982263033331653792 812901316424540454 696766167318582146
432178344235890350 63683860537132141 681240354704673941
811722142914425025 10193719511199561 921567121885154096
145560266710481072 886549089210393758 369787916276267757
393667467005137484 832932260568721085 171264696801632504
361698711325597915 326723838924515763 719994776704776891
892223967690283899 972004430754611829 691973719601598069
648974078292581860 508535303808578603 966329779572663650
175640489113745708 747268857912717600 674040301675129821
989418573572214364 652241598211734671 466307773143420795
233966473859328706 243606990079781771 801371725261812700
735432045105193169 910495789522933464 941478427760955137
297037140088832373 286310112933674025 903462202350156401
902636433631492425 438233086095318329 44372569744382501
970381688264997558 316400233395106798 590269995996328767
987588673878104002 155541597953580575 587588645271960542
630103732403147276 294007518981916818 18606926376592121
1876614720437257 81898985956747590 569609125123955062
841929222168503799 178621540930983863 699380892429948990
684467683571892970 233399764843681916 361988760158487890
585730291752586299 137218610208197550 269088655899051882
721926486706190477 739498378414534428 218472103714511651
322165170423722314 629830152148262187 983930962161935844
610928415386622980 657178660128075044 746208199504978259
174878078567636768 389724304425774735 691562231921090738
653282689046024229 79934649058259310 240638054832974692
888521979535869714 114567308512640055 409656777590327806
375606888961242551 624021829024728879 945254918594705939
672489089631873838 656906787937918455 157240315534121564
430201812662938296 306558501401721537 36901048495789133
981210758379438763 443440549812721168 267347930249765053
32280646676179729 757087580395065720 883790886018651525
330101869690369436 120076675293276514 195673173544467988
903521897967947374 83834062143144191 231026104247283053
900936931171273742 715570726791871641 569641756153530393
54354636737142587 875168670286037455 698493642446621885
298647835689774103 385881665790669545 527151692795883281
461768033050773284 98469118076377313 893680632887245655
519832320204866399 453205857615841755 998508648804680539
41283898529483932 374609584059298988 216831054040847259
379294221610629113 56917563902946951 628594281683449236
908835980037791197 842433490749782365 562784645602074368
10156547816029247 352577449289680813 784022960295947946
835754825976685764 945741452984195200 377610164552601611
70182789252096532 381823281492292013 798109222184852101
207501065627246685 677046192934080358 797770673687762261
213533744112634212 124053787282106122 713431884531499646
686095646774394762 904592868058048870 692531075234431456
710592742250628580 6064270469403334 985770679311094480
665474090298308769 216491240650121493 629857722437355191
480927542294190104 374567265838827420 296888480141387566
921788093050624722 383743273340026002 248827938273671664
859352730533418338 743184017287469229 507163229730962161
32166796136141898 197822620950184310 268266330271884936
184524968021892032 118712210218553165 121106795061712970
556088728898922997 206972686463476203 894364858344959046
695644817160763945 394490470435267221 785547879412636732
307729403784713196 707518961555481228 912310541645515087
686829259223437742 745212888921462860 902723822463579444
746097861436879023 448386562792207258 80998927392632201
313091353406466016 928652415362497541 538483816572247951
432884822416745085 456461580769338068 848346922078865302
131176031551026178 508388140615125334 194937378639790298
979034163346555042 57615108699379017 996749619682297846
287089273299739413 863757761799305563 935533363063108336
397893985172461457 702781337759814384 959079492890695294
323718568038913534 2263678374229747 68019832678512823
836872734172735904 42746753892040589 577044516822117676
71142078750614026 166280798942452689 407006867931207515
894084906629733360 17886115565688907 204994969607383075
644074417579223606 414611417130885699 763965080654448465
141730053544961549 81222101020227692 31051661977358009
847849324026114981 158107065782772740 9711180740613245
900502956949103164 775866067658047800 803555728030487008
388976206428934505 528320717649519186 156218885108500933
864119330863807372 758971150320615749 359302838763551678
764861195617387366 53314774635008846 110130499765437383
308471615102170357 586182273983264514 724780931008728163
167548107923186862 875137176776224938 78325742926890707
801632998977439114 685601795874081358 155785405388636216
768981105046045919 665305281492665176 760069999684662293
364650913213269548 740927091576707485 527673673956932345
784709230500890872 213981150889650381 573039734313040437
384978852522519670 188751158833427990 114670479137936546
737727626671009599 366809587887557982 436066526697151747
302259249902259914 516440759239633679 609538112718701342
151532737265390217 875927514659936185 389749695423557727
813693115009559980 745192011294125288 675573471351643502
921683654788663475 691942773023408605 292084940535538322
611222764047892044 766884132744432363 626089034479039501
601342621866504628 523203326405358214 340235689113698439
271206945747597953 866656137176252941 177486322103740545
269782769579883007 285942570914136535 711576924961603132
483281050011310088 297495423169499588 465996577690287670
133800313175455818 412877491668442983 766317109429872310
843774617020899890 624172518560316738 285172198861420024
295072005304724670 975870173917895959 334947555551492803
16803702639020189 628336176308345252 9144413565278480
829920090192873273 95952403772971111 398408218316351306
264338746086965650 637617505539902639 20146809439512804
183004660071016013 173948688355760637 946955666659345148
306172342199123647 491451495134142600 825992757010097120
597742793081404032 453180442811772468 93022152249543555
113666988872963522 385295155689469579 797667781872564631
311082603214850801 555479732211933538 481945960438716387
464156738021556173 332822678470050626 601326341768956530
898373624529639241 323393640614263505 109718300132949010
434284384629755092 367477335479046110 147899300001549871
347321531053511370 615583761805595476 970542191221217733
556012444083692928 593812535499799781 563779420202188309
164197454506620061 956325173915296522 857533738347633319
697822210428123391 661948706538357219 372989197872045583
233290922862025086 348527468037808723 779695630405439380
421917762427089252 966371118605051546 339695045915459892
879464312116130468 846436957984758286 260009733772112207
981051173612817411 432268272208884091 475084178282308992
66675552711933360 450840414489329413 860023978127638122
106802783521927260 274983743159600893 217690427336475345
518487024668672579 357872708504974543 380085706435080745
399886735092835014 233705460108687041 414856797732212835
964381048612901791 407697817482694945 676089410994728470
793736856371392901 77132995389065723 171112526890417288
451381154872954276 801372653504792232 273660034276909227
745471068233311369 894788241340746061 541588889063806095
286386324129648498 477212963172732873 74380826669217947
303446591596721721 574230335733789008 250030132090636865
973767341512161200 242788439280791376 206491174894836535
864743154439561181 814617601158030802 723909372180549294
91659352516182605 312224550260369187 719499773588059080
445198063244370174 618346428341219999 317411662074157926
194197828041556593 584769323496813311 690554796643685758
527320331976116088 959141942932951362 11208009691374636
356142638294288423 185024230596640801 228340633477676235
819051080646969659 591617788590555680 771672749684928171
587177029456858401 573090306647809695 950069674297035699
161171361939827511 648788913000043653 463929974754314972
912114854136857750 447379593972934521 105859368621366703
102860263968862544 104865390044691006 545192175922669813
368417799253289594 731999017477182587 105203026586340997
215829995241919433 778795458088714831 201870710011922570
795817045964828190 93649294124795118 119065755581534396
390445611908396540 167522832812005104 135397221515918557
365748076954293202 234230918949792727 685016252607033052
677389834595326465 957548810658732730 415964184659985032
673456793373682162 19016288315482925 434450719395107894
63869024824839675 378373682463244612 138902275243385394
544497921569025289 497912920180695165 299132791207491847
102185180206141023 818856479901777579 460899879056121081
147067447543412578 699941414108382955 161553893110716815
973696748341488331 534631725433544055 800249531523192757
995547263259496976 149454048928333962 63373842138820777
353362949061964622 939639457587096212 369015774973438772
428915827236492958 233722789012389132 96968331588420050
926833601565890392 875145552125843131 178545591937864631
253650111005932400 16942610048137037 340695160307283381
47147500583447541 587120536818678612 120918841413227003
41296557953466733 529249401356281950 44289488311763427
365854091692049468 1657904320414186 624941104521530248
757015929374862807 254461021374949108 910380685875846728
214525623512358702 554621269300861514 943169368951019875
998369784924465964 462590436955760335 988413396879709465
680935289039281103 383764880460734993 364301203979134340
413862557472438763 757888455213159465 888214646555631431
641091074104173218 184065991182533990 155062624417374221
609055043658980894 124190428843368536 989227530200910061
684218389617918403 879226404279698740 904545459803723728
973917352576618739 95033837309285312 714373560280093302
947109457221291602 387061237387906736 507740590972884548
288490764851378419 974698549796320854 197427867092675573
501560590579050150 725311272216928336 651943691096939732
617975829090677749 664184790783340548 632417510027122452
197372407136519071 21792979179221536 456889376072756642
54195102131067180 754945349548968981 481887433221218418
28039028343946636 825149897106089527 985126774064525684
829967739100243432 911148473796690672 167948147041757246
412071865390027649 309531997141755168 434408531713300649
149909285384350236 816877616892383466 64499561079986895
720655661645992927 363122027922628096 678238599193080281
419868566710881350 936806835988223581 188603942377010145
709871526938927704 886977661051602380 87003414505877794
470383377638146060 996869693878058244 437196027265362260
302710340169389801 423140523256574396 479666085423064411
501350656792480996 193361643030863518 223264539128437087
834995676806410825 659441924822051099 870968117391562203
925776791360372553 770471203258558651 794679544632678280
730710609020281715 923528620748769817 619870767665612304
909806186794983814 871118223381101034 710763533097710926
240212698695998096 667406798714953293 907208793104095749
619484344172828593 940440240207803403 771067841845338580
259923904821503267 669788609261976033 387847171490011191
222231302384810765 935906957203898359 147798627612425432
994340483206582075 576307528299414152 573843160528536782
147948463247413321 135835722990534208 434426950799653102
748606994518918708 217408990468700514 993005011290575317
911108525668578664 687803299228967279 821654513177930004
139783076854282368 338797704023893055 212878893396467942
573236561589576344 203060289377545538 368606535004591451
356959384123190976 866421528628670987 336811926533591555
383492063264348840 211720321037342560 518125189714932440
948270607582796346 254020771030415020 936982552113404882
474607493842626118 199504904834745650 501392214839991043
17465867352200277 858092606209219034 318994330662774973
942303122226755291 111475249386840807 99366205051870727
722506578699324301 160986774985692527 728441097730520493
714260930909473922 971840801612451819 527107980674010265
293513157797009795 86219762622815963 82746891386826234
102036111220505409 471422211534707841 452191244648502518
793875357042589268 55708743349622758 577992659273597037
797058281634802581 962645135982793864 416601445843521314
952757840534699326 92862718661124789 126908881648462237
397074259556381198 203934036881429412 286636520362791995
759058009254925961 739176712788014307 810456695280021383
652007824643594851 363952700100288185 96161341940923772
4757017360521844 3991851564287529 811576040246315664
584460171452924327 504691204502027842 22801466482714084
767968939033579998 629253893162448370 87480838877935458
434608117115935708 175430814462875252 325050854806883277
917218655684589454 907045535745049717 744356110498918025
705555275747704938 830551645491984433 970111184943623460
3838767577399118 352781023377816306 678972186049608922
712345492108204674 8289342313752426 311666586856635183
712703045476853220 873238887415832336 346846220905609585
70563412084938737 901497304384574156 841293786168607148
266669106359944819 638983254551088562 237842990875874492
470277669525779441 926327208748087415 433754582645529834
49684080214946105 8354573193730273 690855781670419680
638724435716995246 516454539368264781 806325890531662674
869488962512387885 299599240627782954 786064360345441105
419475160884434007 421978388760474408 626429763371623977
390538016675356492 964354477523370485 8618506034605992
681722546333736298 156506841823774588 721572460636392827
209704480474372334 866276495102884178 923687651294030795
108134694810919419 564483232904731454 800617889529975665
219033130732371802 158257587133092592 357481082645493048
244204466974285498 435480546651454204 412270275229684393
102920969749877387 394714438889539163 416809146934534089
897376884144437421 824376623974725179 602933001900710926
949852923844512126 753765015466793087 746974429044389211
571286010077124244 748953348963307778 588766989595420640
34499310258176355 108962597337210962 965187726381629187
823188922099709276 805559380616938181 81144529255167410
2482618086772314 389255961390542570 58483340837077869
389587423726785472 910614210362474133 619349190009059394
306195484568561960 313416287491274393 126422447957915251
891273673250967930 137377285235884103 325534078495401942
467697531218540145 672681883444268417 214823561528890887
750099125394103632 739948393537248062 484254025011828874
27787613768590119 274985937679591254 860913521351569457
136560884257328811 857623346464966215 331292302795943756
866994350725538367 197041596795195013 906759098706396726
120796197960982665 277378635079193219 300470364109706741
433063714665988898 284093103529542317 54515838508151298
299140855356501012 349610808958775730 917979259331540864
306608248470240541 25655672191291496 840067825044820135
44236632059951454 549508660192608396 338235524385569995
10736600664924241 136960905413865572 718084262499618758
816100807307231279 122728568891523333 549097554804159699
760800187037436862 678936391518726374 275611241983238598
90312078443880880 15281416421275912 478842073737101100
784063765991915158 151966088736569127 36431126310102722
815369183648075717 703335209754488595 452682408725138729
146422440858068150 706330480872900204 943234246805751017
200171091210540495 569068267911629331 872649809821718580
998420163935746668 554218403372543960 824344647454329813
755403326641733185 85836284345921776 825147535964522846
56861162663732055 55183428374544413 314745039198191449
288038523304120836 650293979815347388 184043526646206018
290751478901854395 828226098652954053 298344698114434428
393431837577604272 560930281847935642 309113104292894517
393866666561835753 841305211853991247 44213702311146400
76715068870877736 3157174536755370 264657594161658476
321291890296812064 624600109243518497 726232708740593457
175231471838228845 215849242701609552 749062452711667943
278977960935762520 905392278367505675 216216346580030759
407578312742830304 710779575533027238 655480429512302583
620196874035963552 987913774896097192 464768360408349989
205498794116685679 161524593644452927 766611584714835110
76856626955851664 220891866238647686 202244720934251424
602352243332269911 148685373748476174 379540749212472276
749328448432570642 670703224628201981 395119992884631422
277256831053553129 328920904894365123 202846489406485524
779646570133625645 437711501010486202 13960496037947041
820504004291980468 919052873441891641 523139751746909242
867805780730159763 458274326635863361 972021148524021252
663721860029272010 991119714316593448 521087694582449092
482614914080732116 867910048145367759 775411502175207678
587093928651675014 204575947341877553 719400362674089982
62359933049900590 34310586443821430 500397725775066000
108146727583124272 508679460972114187 277205037138191049
284605246853732777 215787682130920334 424284895231620200
768567524491277138 838205735415448078 334422427062165059
806751059837144111 194653414827036200 879710716215759259
205537201868153064 733007286362661844 725530929404162588
339334153751972364 367013203485977620 885208589943667958
993918911363511318 237403393933463653 250764697666774473
428177325932436916 386394997339918801 152428764866331540
900390026391745525 754783504215379783 728834958111118383
635402720623993546 930169756772910876 79288758392630397
515641737035317697 247537017691374591 149864007786804356
84694685193568315 837985404773392727 665767801154542238
817537643789803799 402813142756324334 16769124205235309
908966233703353810 535996160294108057 401740606115925541
438684399530234295 476376897591320352 960386064214345529
808392794995179784 366079959705741210 502083193092808930
14505103666230841 402577006972061877 618907841218916013
141668837614369982 183016019542266930 734329247107897854
700541479348356173 264937607194872374 305481323898880191
483151191995736250 605527384441349354 131568608696235287
280464717349943792 338447139970289240 707848739999456966
810157650190595091 591907974104987342 513481573275236441
130598145664111682 514291767001026341 486049712892187067
543464976151709397 772667477583826576 795849573553059350
329610899589727015 466927799360402159 688412541071073263
291657190254307087 911384998304295917 721150488604218727
702479641400383084 423564558648780039 212766937533411299
671034681629066517 520593843792543298 93592147844349507
28711089729593426 498869560312202574 535089187514578025
919565976313455336 792847894538221161 623279670346975473
125285096655850347 90406714570415575 605189139064613649
703129525799416253 599030166067752719 640535787597238074
867662494455888061 672098979419327702 439076483414903418
826977987284695721 179712953793410143 658967832141935354
195284683632522767 565523317390770737 664166986575895067
366113026675690653 239265939730564171 54799928318539837
857382080029132763 314822588572426670 756350171932112483
449202528619262280 104023199306945565 344797478459738166
702619618553139043 290098703794538215 694231727662021478
748278569218156788 413619245226983973 418228016856599090
48259445619163529 805769231918590207 769068356663511024
739002012389947869 346579750417687532 896767689030099007
329732618783521551 593337700548255902 213728688171834438
759458422136807393 294251074115191087 199408151595549654
968241675623641828 112550999005858050 504014006288139767
193889362182775264 862743937145905521 453798290469974791
450426455331620228 656439416347050189 766860249060918554
347325842275181087 912958381809470621 931263401334006132
466336461539413470 832962896370837158 664330639083718149
48864185790198422 656347783330789281 603851845428449604
815856744007942329 299109843841519601 667108282011046169
524130876590968221 773800001751757310 816839625922616977
786740230151893703 704738126755592079 572766453141884731
492930076342932433 911338680811299486 720258989585517192
100196998105611366 479802011038877598 308723484931353139
905258611951967159 816611358613883541 662512317970241332
393161570568224150 26485001925076192 540077412082779725
126999951307708280 288058801809093023 677647606324371127
881387951825851986 402969578406123395 354481311655330427
327662033524108131 33999040965077479 516728229210633000
422220153098840611 767553988501901562 79696542795282270
651720792158614887 925571566144571121 408429632671990786
644293363711167151 172351441409477367 260623467174924804
417927783976845825 609751379727033302 514579956074497215
829269597023643111 364906842872953840 670316694809306469
369397988365331041 830088505243129051 201669905134620848
542761603797848843 404478556405898415 677279543032860551
166655546001135525 872434895869714443 103427221799438378
217084619695659874 335543837164026650 8346645824228772
192538016804251546 95616823751268677 693173305759621838
511722509524883918 444563811872593508 39621568964189120
708461236462628489 894981056824081791 473215292352148266
902533170437262788 88041672356397162 324712219168160569
213808451691762247 875859242927139116 77281297964062624
220865822926142893 31552333317259335 70780136115420414
493883524244208300 325814208134448650 861148228424815715
173286689240155189 976082881141010985 316930826539674263
672682560713872145 989701120556403736 612593079539290886
828195001040495919 666214285804167289 987346524569381559
42806434415532350 279864320238432727 326334888992228073
690231316189398397 872190206510354987 390096724867529978
753196213774415241 375853859787073456 707887078978148146
874607527644717638 538406692529638014 936609632968747230
490168917436454937 166861625075825374 78494225258208729
368378525502038902 453949943777228192 285780143483059200
990892331538257838 586776471761533735 709517468576459773
296515857749796236 738573134877130480 756298757323092881
192526921821048153 412997243697102952 423344243550657447
492878741791774350 992105945763531857 623887153159597334
687720919653296534 447404711230761678 918784035228702322
487509193035121184 889303571556063932 306122629528992367
950792780332416706 374073715894483628 48233946843015634
902213943995296064 238300487792572474 986927101942592756
875470993070423207 718500862050982778 416632104057757769
97275509718040784 384533638333486816 464655534734552110
878806752587684181 226803044624662034 732577250964888636
904297446595408804 140731402700928293 117839876496624443
948446464094921543 812134549782388261 839352829020368772
791466354987025356 100317553839069095 869186714614813215
878310900119768813 665814405366721744 289551772959631089
104175552629166061 667362562307243461 493507353063399502
954307306981550922 948067882529893831 672439992646679078
259981622056275072 187348456552938406 429490602392600292
76354413789119704 140834242663549654 368069823982938326
239835756292304448 3353494130263131 107034319614682779
893092966253899399 848676155286061039 494265919594832671
387608725405949732 285229153685961139 162212071169178463
215428331280514640 946885698882157220 24760795005468464
101574939533010417 666490167061865472 599295053394421856
327550322775777812 652610492767636872 481478057275253243
433396903462990682 214119462923987549 839716897045095161
185068696154055689 265538870257091813 790308368665856860
571340305247888516 841881827068404384 589195908457232082
239358976519010857 840574370126370911 359936373643813158
736298609340249692 264009237492847671 574692198958962486
435688999666154678 547047425903228492 690901980030260688
364454089650906808 687634107501464179 571599626386616748
297374393767796888 972678963021816807 8645763707340290
798029433175146055 364360082635117038 955916353011023314
38497279759192125 994947995140026109 479522239476410792
737752488798978042 3118295834705278 493311436749260423
59396253337550932 190942933544987855 233239632674108465
480004784254826931 848494560577719766 64223131381786671
43405353689848668 311940381501522456 940726521077039103
974242942921290233 996043491721877800 465731903356059757
849467509291311317 916156441207091318 382520066023366956
936255248740462387 50545520511995206 478907545377229540
546065395959501623 947808145359971602 584853260113181580
255623960450241543 96548705367665057 355185807485626226
111572581137027502 391232818098521204 85921870274508743
446700766794239181 957597658891275295 650188491045012818
736911626682251439 339555257936523141 130876086683595788
185304310533720745 304819100809997680 711877142133190654
731682103975192074 573534842590461453 51343784371407785
453887626790782845 2102776488716403 330571504376658157
192624644621499407 487251731422751306 179913267309580790
592952324771172146 360371416760461558 347501917229972115
131792404446806043 246480678935095753 340975050614365375
202526854750980767 827486549417565642 486126248939254005
760046668245545059 197929183247120805 756263817860712925
314184952806056717 456232669495045305 305654356206768842
933703662967466715 180499838624495516 272745789048475863
808383190666746329 632057200287125258 634920012877502737
733787953838212914 938919617575824227 685067791839500975
89999971965722691 232292688207843007 203067780440824445
610956507660687652 241368780381959485 563819353682307793
346677304680073399 23563334752340819 134539044922933682
62754277666134434 776268539477049483 701652422459278918
443174830417802113 452766308221704858 309789856264445942
312813624048116103 291268343674883930 395035191879255318
120363668907774688 769503734345561546 568188010460648195
408589466983362228 915549253107899808 350912259035507525
201674142632421383 702308002224333287 92928316954703762
824816234964031561 349331123229222428 257977740217672832
564938595205100902 195958346393219012 513657388085814711
103731695228980770 3935627295327208 192096186070400940
355089251795346043 275469339210886840 897214626676486712
749679594072932237 900986526924877243 150602031204304141
453276970258025604 736372147847704325 221768445222433036
877041340576646469 14500488025294415 874902772585776213
128284304683532438 373201291483672382 34676427099141429
267593174525618875 847677143041244640 969124607545898319
141665102306794272 794158765798066693 246410582562648704
503384744577581332 261463686014290021 228250230457419879
93912628982493507 705516009091375457 204291301793853978
935000562705248535 740666171882324444 118553687856079473
512548846085242590 288255984414257994 254071559091019997
133524107026227456 200994534204472533 541415897137752071
270916724623142306 603082359412607718 459348423217722947
661559752175342703 275917835865370872 414537256111360319
898948312544976898 867318345588358238 949057358303900519
926662282651794241 536067535544522743 302020280016790473
450247186300125318 28431356669391783 88823013049706209
894067341808209383 296382693550642077 668747942402481814
410342722251370808 787815522052087997 171088482375709842
368012363110746353 543060786531550515 105546212502349301
402592839930177773 428251682310669439 843996299752663628
404766841106086513 385601369565256133 349859814462242467
888381815638276330 417020416048118594 868821231661444853
873526664829022465 487271431035932152 215233962069982171
176001635179494377 202613530314591422 214603439830741579
595106207362247876 481300403042945388 175458553952771430
655037594329891591 830694493562087971 913265243053869017
761433676571213653 187069415972752498 784145039152568870
821598280935231940 978147990953027114 894853332101592109
697587268803353491 505372680019525247 786464938173756263
623969470444467151 534912081517790278 336592051767968918
463248475609324775 189045351750640476 479608572583358375
851289224719707198 705442293497307980 458130432170611683
173436616687312183 777682017675727317 771354093083039893
752104023883086286 839696925099368208 350612370729662596
219699815124711059 679158547366324109 873063653707356256
750799452723522714 861738685243376995 96045511078991862
719901401066130398 937735983042065949 362625208086811146
321284060677245144 664280614147455572 939368261332015946
483874345912300733 464627559668950402 846811158079590714
77470365132567317 857606127122245553 166415741280469284
115003103633762562 899268293623318426 260696694383930706
149661060356546926 667697181060436909 859902663258491047
24520768376309476 412869866969110792 984621994721016691
67086847402937940 72567117393165057 635710739195113969
737194237858910454 84869273259518820 820713227734887457
494803758574708807 739099502621575690 121114985801306034
896493289579560709 804625035220956290 828452624853086217
233415910800816894 186379385017438535 553575548170216970
958962675562167907 755734247808941850 358336481224458188
417642355762384333 145856639018570023 584234274826998414
572454294827007318 282279500905232538 926144210800501602
396964295729312546 870764750563801338 611687770511948231
332598321215954378 771113302055295049 985868730017027229
342179590412486029 12508547059987750 500458128049173942
99158167206636410 15921490899999664 911308870632249530
204335949271190983 808231519189936299 13860780986089920
341651587162272000 49190465344017410 813863718378450314
400443379925994990 802954503941254634 593629303891255224
578560143787231306 807691444771291458 161173430019253648
940207781914226272 929436130213821062 830832206564438597
57025038369751703 830657042755876392 693617304221863821
277057302467839850 135907096795300535 692046864554166393
710135472377348894 649434455403561379 603163897624970557
963487991881745511 955370491514075072 944599089246754507
387616472387512721 347828998580967737 904584437533195592
975279351803845689 555930070858775975 153412284939196658
190586172112037743 303112113049092406 976124059016936571
64066907133500094 517402261416768559 751384458992245117
824410749598686395 927180031824162181 483761505494319711
72793693527816135 716160154696249112 851180660539038310
216967053205985332 42852574349970635 237068390307378995
189975176670591394 521903089463597781 859952037782017595
577794231594469610 85829844341477132 221639647086661179
429784966679314763 50862423143003706 997406455141440402
633857548847876589 471066456068798466 890447416436640278
655854515866764198 956606081503287506 863257320880195315
234912915708413474 487906227932652457 92771044919260134
641558323836263373 731087490651637034 599063317970373753
147280735400465359 404274739606171049 609614311549864636
45749593725019867 436368933691693625 863566597534708849
251674220615224335 290231706602570958 186803536128038664
901751222648237790 365761597183907545 225635792903217177
648248280900709674 129242553084966304 141733916042485751
949907349131080924 616603772244592938 181185799535302401
521965279078132554 876993904555809853 539295188276379565
561107040881547669 427969854795583958 11386903588976326
457182812177611756 262000618889924248 897261153781536926
478038816258975502 136867338222550573 708921500961715325
333934054762469077 53787777724472335 401473237335698000
355033042268514670 333331793225477281 185777673329273781
998849505262757437 555541817612856764 677886689001883999
357183826025921894 343178574876067978 65564294597228150
848744386279113311 842473931284317307 617369707223029442
232666873964138477 653876328686778666 543218167798401722
819336549001139232 417836446481436680 567482939561972262
518784392797948657 540893498085400536 730553433678764281
527581296049535763 577370398710750026 589609399723090884
962706712944438169 657134806952755587 256388626515847163
5820537372807897 548826945584384517 167752897028585818
491526665002876302 849602575545726851 697212779422886402
807586200122929993 404820396729951134 641991172280128089
531012541378688892 351453699400074084 364135452194588458
699377814739454093 232988392363091760 320644646834329466
455729284170052918 995145293151445582 994857708983507206
812013337145990616 294563097843721511 412543611235703145
767012650982345346 389524807625784179 401664759332180821
946263814169376698 906245083973392759 452372498565534380
551662986042944424 962147034167035334 690294535772624483
930766157769595313 357668976096543701 363360529838794495
112096566270099715 883929522018641451 183808173552243376
882802006741366956 478740398886382082 627364196586728397
381125466786831837 101181424122053381 784858726598782289
453052945595672424 90751073573650004 248434972748257883
117003260817977723 573855415751171979 534756878744035070
777776174667190823 849964368167539011 787256789127010634
322510196432179270 277246108848631731 918915002694390372
855099722875908775 339516339145254555 790213382639660111
943262671678565323 87372675939969325 216093827718629427
122541469984300107 6097406676813813 52619270256480274
684070389477813412 855726975094395150 753724896945048366
628417127772836620 937430262497222320 474526645696191490
869126191061344648 987064225952057328 505677339083948424
696735918482537074 173880466440790866 397919035638763818
579634414180674448 679083312469831868 554215495479467042
209168263598062752 98650803211261621 886397142946069625
836086502728544245 231734762957072601 845244279851991616
373935303403333158 656440511169137598 866137622295388884
215243776863492545 805204669241992404 615700904023823671
381434106986052176 32788840269071526 432165973514518925
763833875446781730 178287781375966271 881561541249043641
446309967801590227 338101421271257060 135506759598613836
510592108571694214 738444095610675729 473156051781226477
312319693698311242 76093264501595657 98869990092357681
143425586295662653 358862538881182938 481201797846540537
858527981191173644 962145163746601207 615882291790387624
280236674732237798 45254518722719679 529658368736436022
239941334599448133 272710215459924741 58203305125578330
855867295652105771 844641322650709954 740803105548785697
968097586550264100 172281213845431788 562484392400670197
316437112603885023 509905993596521857 458738105112819456
978476462267275075 143578965888606042 782342628707131500
757829520990197181 326259466880966365 796765084242594475
578998529293989121 133074049159519381 435518594450656079
753102681650152263 160512797031688922 127406924899810992
95870010055830788 187882118486981810 25805386803516594
976053061511686780 506907337031148703 753444202867844317
714398146623997658 820081225254665228 144954866705570227
440774463604749751 907834762936565673 835009662452302108
694847780365782088 498008598541231165 312740557406061646
373220911730946943 326158834430233134 63860713731449458
295158378422304309 612208948166169580 853710629879363847
531903122396257266 931665514257185094 671721726178883715
92552747958908531 645850788932033431 957365090456547791
24831304701509690 511827516300408815 245915083854293731
80720577668059640 998212637148999327 847245153546301538
572981183317767063 223302047682909327 666439989314088077
718325793839376539 914022758120167368 485560892622806548
367054935325833490 888635637735278722 669334676213473539
318896989743457918 629247617551570357 504635619573698238
863367886062301322 510978837122724788 397121179687126308
35594322300646174 602102468727252480 483426727834084378
254976776360352164 446789898491238691 275437713267398108
465702592522668271 381937316822635391 135170455464628884
82728497581002734 253496343804203273 5017449166868376
263224707596267990 643829727536723421 507252121267340060
614709093985027569 47183320635813014 686404520888082828
848025807767013451 38425392794130453 551561445444947482
189668103365565393 996621455715043003 634732166038876068
76615609525107194 434359171113067193 839554279896435724
289378645150756055 972929460705771119 3330410086580291
334385519330215871 871906390805374190 769936052389410541
220555195338404008 662837573016638921 668602140727505107
760508084285013662 240663682148129033 597474389180143907
446089043548703594 678904365565358809 457383799228141004
858950417850738235 319113356799262792 511438207803033000
327247805791643943 625425993441656142 885026024913971702
746837675068317784 929975225941193152 674647528001262917
726089344710033588 293375986788521430 973014588003438842
720766541975827923 479862336394393781 501532553454527831
144239401315916164 836068353153557035 882661890059940058
753384943210859690 574596287137780608 682436733811059445
694474939651381048 312526373619630941 146499144881961135
872125053407638248 554832066390907648 45810646727460453
388126859557248373 87602271118798232 856533613801497174
150573391251109529 707178408912714102 322488977078095011
612735609309667347 601021344156872167 978166532890978797
92724013604228331 437552734721484667 359021552279605443
581010452579835308 591166500201589001 872236327062479499
761805440830646414 426527805459264391 590061646117362638
816788676017150108 983543668577455647 558494295523715334
73044320403354285 425794239848219881 297568442593371189
250353152010541222 837282646294687845 363157702593051881
303452827485577754 505540329294219398 46165334904700751
241090038966494979 462567639893765623 524442632002930908
362686752432387090 573027943106396364 337363554868316016
959163159072399978 561864208007159801 365774384767890904
637416155657437717 296271081945273615 581791157679584142
587997864007583224 531905517451923469 136979956278371886
312396886045896944 113943166400674764 700999110047636543
548849404216049489 283285865229987 291959711200572232
995482260420212004 349297403672222869 919691591242131894
830627371149258833 252713348400170799 385693735443270420
472681714662385798 684916793901794557 529211605466228536
555157475861231505 298528332463697170 393875209938765900
144859256507034893 799634960270494943 353978752109442966
471747639042317434 226050848084581871 429090707243000421
500040977590442247 789609657572935095 737246568072128292
854326033188895387 72035210512340342 611467554599178351
694256488898619471 78609479941050761 66814551750923988
637036871600900077 285760784188247567 368725671735098209
878874207681310486 143146299407580358 978680389382569086
274015936027595461 693785871451564810 377754382011571066
467941647236270494 332078280752183182 504631490060416146
443043126550303414 165614945105894671 848254471003030888
308833198507166233 642958783342878959 283913971672787140
616554300988451159 830455513743468696 612054811603058540
738220857000927392 297805576502120691 966687565586524916
673745668649503305 965715216882674131 652212767966409718
54808482662255154 184649669125402328 26130173092681473
481254167668474860 258690061685404224 850247068093430607
846391340637718250 530653499577151083 330723718925191255
987456360169621863 194203496662094560 283097929139072992
419638449227465102 693459210513299662 683962171832782163
326181796899943889 480980536835770696 160255269360236954
312242147113209924 428390284133863826 141950243601446841
567531806730217178 869837261970414529 786467907991976590
699514199528331375 103494109453496600 890569208629331052
553347126921650432 376050386717278404 810832946007808206
456986521579647483 381001371916767301 786514101449127537
356376621527398625 732546628745293256 440052207791087994
273376583185245689 945628446754906432 666470544103473449
64087671121755616 54920317860473142 543489136795222313
422695359353234466 879585481306616187 847594451031285219
608498365386072568 268452212316994478 252772654163529087
179739886838844419 611056479838630237 425509022753876079
796184624968768210 991388983267908706 809224040449793050
711284596785341718 485691048657394826 801167366209560366
123830528138623041 374733636038374639 165542495100854909
152970745802056302 239395039120654316 545026696243653543
180316155864209520 379922070773324726 469773739178659112
748164685031758019 677280503779462745 382714683824569618
276617081104664944 672522681823325878 21043931018539689
248476228652288250 968008124397243843 772227615508916520
738065084179459000 546915944585646679 488953834269618644
156554971185568992 698248535327915544 3024544483517577
823572468275772622 879011819603159661 498191001044484940
404324303444401629 638391708096447507 96497883283783817
830827473874202658 327495103796975999 396572430357032606
218033145592752945 655805242901671141 987199970908506639
116220864763512665 838339558685111152 808376093109824645
730964786327055444 653383831671476995 815408248955950753
793446974227827737 795601949911678703 444630986588443180
468914265567430177 414466322390275856 562562401778028560
964507774484293182 752006327560017723 411057089253547773
300042435499017515 615706395673330386 674219058211407959
227293789162677408 672881887413848484 976194346463590345
249178166838528366 995187315361167338 278089723087853504
968043019358404222 80844708731018204 247330186102790482
783288266001292972 595198272217036365 216402156115758328
2667388228581505 291651789837231252 503240131451996849
321480813871284386 558218164620657312 451025736059566458
887799752559634972 625441554311760773 546779475398263021
480701582878751102 895517496732781630 113698835031547354
118520286975592256 558858994573516679 998264387591522489
277389730210774484 930893599942750848 135374168366049194
336877357911965037 277984365552292358 581099091265976114
223421696135545259 634770446579959046 577536977993251848
549352784081846233 342318467297497982 659430296674943699
886558101547604910 588142003397053400 482454431880716027
251067240098418030 698129724027043040 669079346276975779
722929382109290862 349472700658527546 526707636871235388
617833056520992096 101814744267453426 315167849263528089
907744726787616424 868029024510293488 546277463479026409
600707162623849831 477186768114673037 50085330401513667
132134160088977015 960023127779496808 706428953195027338
973024691529262486 16247460620767530 996109150380750554
296542930922195884 19211057115110346 203567467069453901
956773630075146991 824684931688766250 945601360750929140
61652809200148637 877382135729247301 12934968908957649
322239042053181299 734823837553541265 176133543771560826
924518833182320229 68586815323826358 927654179875453684
428815290013435796 460703027948745069 358232546592403463
779681558953647996 553945929949384859 348973808656672608
408889497975003332 935370608314822429 352595843873059337
949076513391196487 205254402053840133 903277775436886695
39286404855276859 44017451806312801 392752543187673141
904886227286843713 611084837670890511 897878449001249123
31193957492613440 96817090817775329 706801478941862747
406214306641034607 148800775824218836 762990671075038563
30347038174348529 31326316817171118 886932222950585909
149533193848218715 76769014813803614 426334978955022887
153151640054012542 97495254274057462 689154288703174774
466783978073166494 792585611138521071 189670822232166608
225051231642405460 654359874689889075 677565158927115299
821813606080952575 721497183810324906 172101686258695568
918127949598699671 305283561114386564 101148345684355913
300624258532784313 216174748191543558 884207168747480807
324051106718455693 941072712885230416 766624143997563397
61232072461247133 667152275348261097 784520607834607142
747150543556272000 969733858833714039 983786979128573657
684096917579291450 701903954349413727 896228751441831429
121367697495835166 176158897482728257 649417469432109723
937002429544731540 592635535122204271 396764361957836934
104495980090209894 648368200746219198 350491720603833984
917118951712437571 374713019608690565 119794940297616880
704977618473560994 110351607350707067 766010641099109010
171662941965774969 281532917209960566 424585254189106085
792776541316275371 79442979086826860 345661150728590134
32215269982819048 91468231095932390 336426200959097295
35322358521186400 914788433270890967 483426495208815556
155464114729242439 568314563376979239 939954548215270095
567027025431944121 791939150712003222 810935918232320489
838905654456711310 524526892519275965 298961496176163327
43542660204475582 45561445638691975 388011433035759278
775175830931180530 860444310692041716 404023044116182444
481505215155616479 769283170029501779 428466950221340796
624190523542578847 300831077886609550 936582517176797246
849607071746514023 413373718349382281 583948231845691970
596964762060706356 151426432876741845 32803719792812660
843482873946143506 253031110922771796 183957726646981923
411840510470613886 545680765580241658 816965691225355999
902607111249453127 807759443501212852 137871520856158548
698873163033737918 359914237030858131 781401494030541740
849027363443811086 225613709566248640 954067858497535794
273357314863605476 854573752639416605 339204800461913280
89112038126139555 435429631000395849 169526049862283048
630223196518389091 237365454862243120 45841500318502862
31127601439187399 77873053930275449 672724061287972486
430514010511478224 828891638741531977 171475848908513673
985009683215536907 256598086864102801 950424073907530740
435705278927601229 96066766020914338 739936056394440683
880755266329834673 21032132598637883 277191646799017685
258157861959179652 99380023360338302 876093687779411430
823434111283123612 662664461113434517 12922009303139812
495410548888118708 299490069136137162 38948224508177465
232761166185377156 427175104318218800 588621689216766324
931022726884812038 254929553715952281 29762131139855236
409358732256709250 659033105834530185 460487833201339495
100991437511270204 249886785673448780 78353053559796659
445301875777799628 568683761766287986 126550695651133644
995038638404992127 29343036173609908 341906859734473855
149051942877797257 731167816525176400 399199214816007089
535895645441229183 873828476553472442 261096997661864819
95381143751475801 307165877496650911 339030852128165068
225684088441100755 988008222545148641 397477197949705611
99180369964518401 896851279279257708 259950081548948857
954589469746320212 171601732154871384 240478815449409263
396005951194440760 316004400386916818 210831622811199230
778527251134175056 468807164322136115 293431886818536430
484399039610055033 865004219374629625 621939961287693876
231717528764952919 701629286664602736 88944286057249170
643052773961984309 380467577475929389 411262272694528994
335540552940629814 338469929536267496 678272563167614007
275335349942686654 236492377725131555 452612493977141287
383239484768504759 533149954250832506 245683094777370145
750897646039347087 290803128222822317 81446207703679858
654412627093661965 773590435265357800 634238014202122622
282591356944703874 677154994020105075 44623028778102962
849689073226921554 720712495726580071 338612201996915138
149601759802099352 572868220713221551 882672306867561583
660347648654810152 8654259159207443 536492129290852337
824034265580247730 883634455126725839 168585596782744998
490139194486312125 240977844796509671 788429683631910524
667113510807873720 5035963346227604 894935778209164194
398897739686925080 197053993810309560 522787062010163266
428593876308951027 880988382538953210 630475386724101356
643891575973199229 305155557428891607 948737356477882035
326086931847588527 735201536078552899 807321575577371583
366451045156798292 514002113998660143 585163608886633301
436054809744204312 967142477423905537 29459136515117999
814994141557253594 802823960015772088 210471685827664005
66334064966007615 798105091028928464 669741142847396993
551828097376189604 893382946872333084 364823282562872702
211568164994681251 894588619569117392 967385696040379951
626469281521466622 951157035792410726 827428365680818547
413078698895159971 821488544653440212 682013842860110446
11232840159437998 454028127418031170 836672317501977146
23692188356275806 320184638509054099 390947257835007767
383571597125324757 508668312878930506 793754234251344350
887301825251062252 178406306393883654 320674708991452733
496181357224555093 745917503471438003 579973880977475491
214517012495154863 652719561999564628 127490314147358470
424953209708104755 237334642623260435 889980499608514653
347870147228963536 919058456022647470 799344340046898259
648835363323393381 920273458080544403 750593818609447370
374369977385803138 64676375852073999 745572063367339175
837302993676183342 42528133382219125 751280461609395919
470792314172094751 291748943460916307 609762919246665197
120230179447146085 707321384496346744 29793135789853290
526854955116353849 274004503412609977 51877237248895771
495416823274714861 710604041333163755 656280677054121549
221719200655526026 150242690605131747 394106864981498538
135732093580865636 906869370448517048 272695581500321578
440487705911821829 901627354145138580 2708144113034038
19602966093024120 446377429006627609 655357219451407154
104167753099494774 607717648743190143 595818132271310678
27696559296408316 609206464383300461 987758482034109326
441553546538759632 181669813114355056 595598262233028335
915299198649472521 990050619702723020 912549310204094059
754214072618219865 678020070301307220 68959672645602723
780443512725224950 852873348228188190 777944839100690313
101715113288369428 935630313703795845 358936350084573532
1092588440100708 817899914544660380 223061869064489892
644956596320467034 32745885071351284 348093793362597736
908400280179755911 40417668635763289 452336697141081353
171639768089437295 268977020202369094 214925229703519147
92320081819295145 414147543725040399 355914284525448302
969577622770331195 826766727914386060 203135540520413795
778857416388320121 746939501558700060 188323526497383064
772077507802051312 631487234336590947 796784408745572823
38643892146901865 725243217611435269 526344862684834831
235419344321631503 696778294668420925 546940659883417565
849637802551991055 162204547439509104 905007909072274723
973977335644905497 373378215147359201 775578684639217001
670103508648600211 324080314071884092 446700812204561826
695475700119656648 797874961980544243 276102042539299901
175597412776061000 494503856944236576 527613392184862582
805876792496809156 560398264004560446 121056729539259201
614328964109543217 701516046950595439 765443143486499327
866637378704404297 872335682674911424 836131770506860398
740878544300103883 656927957277868711 611048862096608531
730335078792365340 150632189336948748 703932564416108507
410119982362760248 398442085100126485 70222173877980205
245675481354252896 699576551229400786 61710039029465356
579865055279885710 872342340497436517 791528737437691417
399605677046891385 631791248078729406 832704248162273158
765865754908330103 837147407341034870 420882658889857471
347839735659906654 28800959842884135 273036366704880458
11568078241347409 6361681164885820 410340857588037957
908526094758522540 386017071992255404 124595272801013749
872562157746002611 518439026756290865 894314861663457014
650958910560329576 223076850917766290 836274901436637883
196424843371268547 195835845400390684 991968137683099649
676187509957975981 408114480380758686 93498059714981567
933381891101649161 211641673761206718 531657090912941076
323136133866602721 665905719020061876 704441422790934396
653987974810019408 345442790275889294 783608530759715406
485104842480883592 560467288347366843 83548854012692769
28735108881949393 542734366991004074 477618010930414696
970278366555624043 837069403973511838 294094175909237353
616968729509706885 958530146769854013 650493492795620165
501830131273601900 491326831898755728 168932380512185039
526737898239867378 141953193949484583 989022292662504415
781615763942147407 741011023343498687 882728978753783340
171557647283209514 434292006611563615 308030003895391874
208040726429248461 419273738684623074 608477011570602661
30231339393850124 352000848699477639 547659004777358825
141280596044720090 265590844033017755 343057310566208984
412661731516127708 654693379485951323 370987634027701361
850195348756087733 30525587781085761 354157845382753966
324757932321257754 476422585914360392 963214985267314116
309186586738708466 500406905152209659 235008125377565370
969552517966000177 649708525059708154 702342788741610254
291330817024285446 491912872917565548 963221817741223806
25656861227382934 53779789905030259 613551686199704243
317595716878269948 467001678279099268 1694591416080927
850662178136978235 703381669151316446 482334642557843181
117812274378219390 871984804893085878 767864738748814895
532685405240989399 952437830795077305 516714995492750884
149302047292138191 346645582357233617 604836601827123307
705904333164700512 277793794517780506 591808913247540685
563928335832922814 156880318718397611 775963827455566972
763750624390215315 411206421431160645 923693556359976050
41779283702343828 616671199286925498 195179255715327581
210701843584130847 487543798368532294 842607899898122801
789967663988410879 383270426617450938 201590993778309144
745320857239039665 329695190799871986 565272676116615252
385781149875157467 96627683085801049 972713347479770250
210243842877852835 882270258976810228 206124707455419402
565000225308945671 984258415192941668 177146267342962202
655118005438221308 248072822291028510 981134266206621688
205151840285440164 458700480132313665 625314885814329981
945453994873495730 531636902195829036 689303883939888433
193818573499535268 602307362195466220 53156894318743606
885128237826190430 740397307258985437 318615471294149485
224097779829483935 597014991571253495 158975048822530780
745499930883572197 743288759293564416 249198028575657404
151294538363066519 236910084387687861 23370986142521830
422677119000445549 365828993668785327 204072911041611932
427962389179804167 226443205624504168 784993567900813179
237651177226468218 551717799743503536 712755447857511349
937739178143155188 786459024348828405 874580390603653678
16512146047826758 838507366947045953 489633279100814871
691066415002365771 811580526253776334 819769966699741791
247584976779873459 157301851034245032 592592362617625850
888883550446558812 866850475853145591 315415219651860588
964569042072886022 755266222701403397 545607053241560809
779298943405351242 264704170698855524 612540971740596435
646534536102606343 929564893108940487 148460754788686886
462073063260540895 814294587265554026 51949559001993274
265515522929205644 203279224458194255 345529805366128082
654882345030476617 144511430043906853 286857498046916390
751543679261887403 599806269471342861 568581062762952781
301506088218843837 397278076906542641 386591606499459371
6138648842639744 181245685182877045 675959052396585386
885903450595158339 170044099904977552 875599260112937480
589748439273316111 681046584444485593 32406430856057102
761735658475049786 833412516333623880 842700902781480577
671517261407013620 358217577604218405 410916555681974515
145334945590572181 520867245353024760 395110577517095076
509687418531457438 860398824218595689 447697421661868352
339572004747177371 206376736453316577 127492500130778636
797111177807404688 327923910622920982 278054533049513676
972399005599746854 771178698938447070 248517132808474627
703544504273431947 987909074512413143 85038607104027412
371473939316140352 937910653868213613 667889197826693770
11781891585296799 590633201939803229 46454996657087626
541091887759836039 650723830158361816 322111428539598845
949294372600129579 594833098464171856 652149361668048780
593661503854594108 182228890954667826 194189390253445976
905519980917656948 566160347726886243 258737926494594268
524574647399554648 418201145120230861 919923271293780550
70263022252131080 826230829170564841 73818495135462841
110643570972543700 917697614506722490 87835401509216735
187104524376863449 490955182778966660 413985707526721725
917283886448021747 656013851592641978 776520424504747026
602370331657058622 481041002574828654 2062817079700021
598396800966239342 585706038099435930 717110273105188057
826842607011527064 218113265030480549 67716491321618739
506756931881002866 895547210535035861 12570358430870864
940795722956924435 241086409734834588 724341653820431322
720506429076886331 217145929979222945 219750437540857896
344991972783813400 733306640967300588 827949680446300419
690113042950461467 920327306364734479 867199049836421043
675579577359501821 205004754359887110 467309247164576780
548922828318757403 666858654641443507 694922215085782656
716015410001152484 525110171968898984 90486477857095641
924061020435912884 682378798244578948 698229803588137073
780304611438919264 227292677807816487 920313257459325911
634385994194957084 320787514647126046 869129631331068027
114340277764959918 434704999561067345 365248923555333631
512759557848964212 307974156685682070 821069391152662356
143600043318370781 192426979593752462 590921559303125047
215461229408000053 679002488456932889 611616350939981811
591294231005015939 198612046650814132 158357438392967344
385320446798631056 964649315250575156 31317324040489387
322265376091303400 223299607209492408 848981780444555417
198028317112063091 56444037323020962 361548703436311949
559806819902932195 739644296165549460 616600235509178120
510609652750326389 153224934042189767 614833169840475399
457549315213727974 552735994982204877 143734812571810284
891797109230662402 969263173172219483 502559699065336860
275944435038832174 926100278358818844 947022019386500567
864699764538211858 267397839311534682 858645012175178770
740595837123485133 672062692697151651 958670113299420895
909070860908683248 253467720138512266 632008894681954432
878813215980049717 470167532966689678 981380328594542076
468957428802305143 882047358129065822 619436688323314544
379515382141686252 350433963164565365 72008416615169649
414241692935037807 413198101265100894 671583777923523260
463821725499377960 161313295632761066 236835045601913154
633714133816879251 123243131139482160 614318582902816154
11332488201418194 386572427533098661 544873271032461037
563777394559404506 451149480036523809 680653772709697709
803198311090630092 418674461574727478 293483149947708559
605907293680286388 35483533091452089 919585723324414723
740612631906087501 239221013644287968 848670227165057198
519931193829484539 79565007324612749 45033962902252653
118974882191797982 808637793380961628 499194082100795461
872184917952253350 200862148597227717 571504231098626356
830336626956041876 692228315270185311 203632441208176164
641379556686821350 392660028907366431 3277430088410355
556889441527297241 19250852174136526 979252020636131540
214489744909596766 66596391062746778 637072618226881853
747763928747565514 164857854247174350 87339563472052074
807822306709195491 52611695815466899 561569863933721389
382607833017773089 286157279594366580 47958581295753436
971177383203151506 940423267143024868 66551048090096153
803267211629499644 776852192825323217 295397955667656630
265439217135541223 511746537034400322 511163372326477544
851540013283929836 704724642569158758 546869421883794583
931648004587357077 7076552822828970 242487001487828258
685040928997696522 71210739304043952 62037956187554933
579080004825621259 914388552717355808 950562482285348080
899961773553969040 745885158944735491 443780938969253265
500490594389219865 53454993226609065 928428149950103150
479647430803107481 970889969312082356 828217403147554870
758186066625802109 258724903359010428 217412780034837500
155599934061157969 319429373964774967 99024792538620890
979599733011111839 756593353129695300 855179553811516328
684546269349091453 248107456237166098 947743855100192162
732008405832102513 467951707866968251 986427289383103887
51238366174541104 465961442676990223 542510943115409373
756736278843940507 996373087984893207 80836993889790151
308031693826796869 134217199604083021 737606499242788975
589932177070617676 336796446644010634 232072889217370794
30374267924003089 169493844355125197 75546262465440210
47036124160255638 401814950141080316 226721295931828639
39392297250716808 473408013989622403 187336973421316779
611173196605777098 352199787682032098 866719831221186501
438899028847084481 564912007629831078 313887532717961592
849704386137077281 235005503572041569 84371948524401170
302627066750801342 773909585447013985 481662662001359575
217690391988590669 313763175396090455 767682418628680888
708280021301149159 108447304136514851 38881212511716078
721907744713481040 157973969751349651 157868925369217204
137695191435536720 844380969826346171 152903432820930236
24660942536197182 799124651551444639 946011751669625499
860671056500934970 508740772090971584 924949012058149861
983304381426454958 562476802442250983 891133739954682300
453228704311299992 997713662608292295 989720434093115796
7259276593654890 575770295906699043 609558197583979178
892897108655304935 700383534469865666 476883606908142825
309195264582571062 384381427203345568 67214879131277099
872006079092458160 191864392524256485 217811447365655366
338587105618076620 194519934320518222 720076781890152517
604767927752503432 752865111738537262 61576301442580986
160574926662229362 400411049613518785 889309272321141426
96945545092694759 849032916048342416 744485206196201124
807284373697731312 642862105031133115 34057321199364727
938329932622098282 631287498158811766 102136746483279121
942328452776066295 272595973442569112 185713648571044375
49836157390695914 840178566312047492 220761218349962865
229293999883728241 98025227407412816 24456994123128980
439585257431551835 28966336390900106 210449808715543989
55565818484836684 290837947831721072 480643818815097638
69171246254051717 358659795093022067 879833125368846230
549596878924801482 21002525674351650 20994909868386410
446101484421832895 805042520529068838 504983081754555138
178048725042147151 82915243706585927 367309992505916485
959353681527909264 516950792161482567 463679406939184474
739053238843743382 777546160430607084 95288082524431812
403079113895526321 257545096892565812 462544516986571767
924402008613584647 885484495772329963 290407437604699957
646470768666882483 84123230079085753 265819544796044048
478007129327018578 782231184729709027 601222358985864254
725974556244701241 673196326813465429 994272014136131450
110520961398668638 586401213353679576 958853915252344473
875239465135656218 485638996654786731 141768826150323562
358377228980671128 541540571262214049 202505750786569764
414929246050774609 332994863177603225 273137448067930996
873069037823780296 42098356482533349 565302762328096979
399564372004154035 876557731098483449 354977200495901360
658975473362987213 327429301999718125 39415308304568138
833882854109381869 547197254575928309 640584463565395970
840708004747028280 124011855903034591 616900275178101319
638810261262601638 788011396653637167 131444752288157976
431409730770288672 337038501764808957 326802228821399328
886124302717506534 946084805035447998 75930551713582613
260050037049850668 412161835696577985 947267814892429982
378001612618188406 575197724512151527 364223865564336083
922980859978781231 74420814701620111 684969176945258017
685738205824550530 397649399938540578 343106201301367119
370119811006930959 217353970669636584 296793030112304624
771967572613873813 759311631328096286 265219549614103112
121489543802884748 470203747206844864 666641641994051404
435880396004322976 331374319539615886 18453360212768532
251575541367946134 781315608190561064 265848659077239052
475682486656515916 19012522581110428 102552475186661840
297189461100289496 840103850866071570 246957168933592091
961789808541933219 182904525737601044 987001566026594450
197780168073105483 712307736412498541 823996215851194060
570057199294454764 977703695412231812 212520700397747521
771370915478082895 526731018236562338 125390968034660283
284767902479263950 23064849979050440 799656575791512114
202146149472305402 366408135782400758 727921346084199344
25436151117671832 981494618432410055 871307328739047531
634992537933433428 878403656177334713 720861070542996172
141902937063730924 767015338391835476 276824830578182902
813972381609993297 962095741932009482 489898480659261746
37747237525586074 10067817345037475 35811007358515644
370926388609931117 427788669415624359 772961884208480695
467278083215410308 722399481920660522 639837010470316124
370588683988870735 191572230237618562 704359227829853687
52627117445308736 890094864740252333 1893141931480961
465459473282742520 68902802696577285 196119945112588365
405987379402711716 854212954301583548 417165506407744986
162954785405641593 116641146111855303 619582717056688856
181155877667988239 44179575344332186 715726332149443138
430124670147238211 88219816064143226 402536097540007904
661163354169705500 892162305557292268 163527809721789846
42082774882077392 249505274669525049 345342628783999566
493553215291420383 572192729320322702 501934576825594237
826185070062910172 405864020981646063 123738089424923637
998577266869978506 476491421994355678 185541375446002368
95506961253921389 612824518366689829 649477682239025045
125664684319921031 84156407681890982 325517458116321401
174362428986049248 580452834764335372 641242233704002874
484478065826774962 784536528081832865 751335552050542711
925728691702331663 171097202282831731 637203660898879312
406451223509328516 909934315835161043 383610544584876616
699761427712674195 493674409578470964 624093718619541139
417010508198047795 761552224912632437 143565835783932726
263541388941903930 307304433481822508 1379108224189768
654296357888021600 599231336423053294 726060917377243050
333208244386678472 606431170751095375 463292613680973245
387095428693523199 12568725325810655 367635352951545308
762626710000973566 159571903206277645 971508038172676105
194018883322970738 690186858123527397 200270252644523410
217556351112801210 167858055178773247 824157124717908686
131870935443039011 277690351986585932 38763953402566034
139017248388617714 688342262262744179 926539042698286740
649545147492399178 308505672764683425 518118168107986926
788286880962057397 654842720455184511 683847255594931942
470006407021796315 632604783018969248 433772479830419848
556699977287272785 310950916281141914 786202631856815280
278136767613991112 150827815806653736 257140263178305678
672040662071929573 700263177393822377 172279013221725327
7524288059107542 773890793100899602 268035063880092068
481288416561345195 985025563835381699 516900018212866889
768365228122925185 891445497709050409 21017770615659874
824625800677155477 404146379556248872 877774951621817333
381269682498799596 519729819470936890 871936970471979723
153232162798810461 543486688870446673 964170722867902290
173954536738159781 272267153435770604 12528179635034791
157779803671331159 7280523708813415 227659216007498406
149110948404972755 467123876941234840 245430346186256570
995460200305846963 285622117813734624 844554184879729059
599923356374192033 335848766391646146 270195510707344769
937169573751406829 100696460588060977 764187799128690594
938956975745105588 440690239798498620 28553633569101283
281585279618032556 230274685373460497 372203959304596512
98246403271513378 881278150310106957 256519267159991173
787011032039901842 969439493565630431 631186858984664732
645565030898972563 731497787580402498 121362799877759722
284373464868523167 10010331316310537 57044256378766673
425154951054795154 677883448786666009 150572739545993800
700692869831819940 702270501631074322 513294826266323891
217148053175768077 884237320964376174 490417696955123243
966461259162738905 774622690231648692 113364155117986757
923914820999446900 163704473500135905 632221105419499214
428777935568430093 192990600585859102 98846961884739292
739476550635270812 219769770190372215 727795096335309612
146401349256534686 67796391258626465 520882295592902949
324937251269093720 743701670487919880 436811423843691477
211546040508346507 571724472609541959 51632515876455213
379033178022090700 265949105378619956 251033275822958295
552039720853898297 168489763430721558 805802454793880600
992837553251923829 840426624621242210 926457688256107655
279611224096416646 5243605118400273 120378995866527410
464774006078937299 972469895967909817 53971397894768823
797885037072990551 469839915828747010 946075683224554624
133785190467717890 909637251718557243 527529466941759961
722947477733706882 533543914483283616 968800586783563387
388563128550284187 293488706862058473 62371682755218656
677589119423696863 549620141523399738 636158924113760962
63683706665408026 952144475463266153 862552558713437191
63932463973308326 795281048915374135 237003027874253780
603679501577903667 723019728329103881 423143617835691313
366899971956873237 349850962073003829 870538460971207920
297977789383164335 953599161139510708 571840829615364964
779463108196307259 429451774301520726 616836840432713621
621914031798164816 704202415566651463 720359155369899872
327948163180014646 125070770182661255 962966651118863973
579008776565911827 846270318179426388 487145840597205965
444043682359151957 538883438150516846 812787645690435928
557758718211112889 923756477846630483 549456558146263032
766246053418382662 544618977438017300 259127173694100834
694353862883070577 438123994366726201 85744403782934319
168184858687007790 794446816958691164 464250508035133874
739672164324599730 145343335723599867 172168729742999551
385267677293766307 207758543637711668 544080905705296127
774809478260134583 101499225627414085 547115766020661421
250950053087253293 376404462498575808 534768585540325565
54241645387589132 697543259657264234 846029091106197860
323703714340750696 909851797499407030 350418837659364157
292324199821951680 625684747288603022 781737507318712842
788397350354267456 797724957045571085 674220861674473152
368813750007985602 795734756952427938 633419523409658180
308593242922314092 315054681306697911 510664081080570796
906812317664908945 940855775872640834 491151116259547401
52491178600386848 360604036720338 133400525509375457
10639032988312300 973111350953631995 368155310167645202
688847021183291678 455112511712207612 773849462360552882
872554124152804387 407545585975243190 244032227997452484
749879042198960084 579056123513103098 217066371550909369
339258605533915476 264250444925592911 995013972655803644
728480709146573206 496163832004043511 820540314169045956
416223115899541759 406827671468560447 777633813410906510
315563488047371528 571090964450683881 608184430302593762
706089483282826970 665103844845468458 823362800365913649
103996034531042421 252454423858703209 109405464578262099
591793356527117723 427545056246162048 689416235053710555
652119640087628055 745572869364874348 343334808219104817
26438204139098272 487847824073380538 756916844124736454
726778733563396769 668633994316105296 297270982361883135
328015005243772504 1625164664144814 74811627404483135
137642638736295244 417578753051554488 57087243308813342
557420857339217904 176651840647282563 598279741322487288
892431570985325680 527654847270485135 917742327310581324
465797360647941642 531889613935614225 683602849402755464
895384018105229469 24741146466571370 441976478990747942
902198947033761546 637080356380200258 284170194469658766
310804324827432153 968156235169240659 870879339887303019
698474857705333312 122331948676164572 809886021717963893
331207428335402763 96851409405676625 280829902067825682
514386077096455338 370454314690437999 57648122629693209
369605767835271119 767458406427589339 884829034348998066
975637036440314556 347882436525739151 571447366585347632
164193570274897217 743090436951634420 766225788837941614
483581687296711552 579180856002449523 188018087516083280
834319235710023044 193959764260757459 387363189035985634
552035201551526144 29361331559941761 628233546438767340
352857855456791530 391767445767020790 368222023085881141
204613272554244536 148560548173047143 157867849439709620
557200330149588488 184909264853272798 880904240338747877
325187167694890926 670593918612120409 925761177645598525
196099564918213463 260371909224702156 229714722146963506
4561890846007387 75141683309617519 769035840104904412
705370234423504055 898583608802154245 237248122962280519
19947228974453292 700110159169945225 602897919598233517
52112763648833226 817576649338067982 93223233027487602
454480285981190916 387758484455828787 31281042517993758
846207545851372480 325120500521674846 676791234648308625
633428163979572246 185282451667265770 639078050837854285
617761301823885383 992444991088355341 208941796185871330
84683162468636450 867903634620726033 670365602360227771
274384938498918227 80474594978958568 362632187482757288
262515575349091355 954739491037832201 71854854842563522
894135811432619087 469110708624374722 961975128230380466
770439458220719052 659333224697289716 838219226679071475
4490448490900051 82496560661273739 402290463592694378
420987112233090585 637446354880121938 370348638647630557
107524259435641362 381512838161147939 930568621505994896
259499353057138537 679455678017251121 118913678417873191
527115813095588690 664401401700810052 861958714712437387
539671772045604013 700370701350955135 288452295939646402
349380143282419837 962602533910289958 318820761445768045
381238784459328512 20697105462512332 379511876919959325
469326861351720947 749954524127723622 317509618929633528
622460138854839652 136012545737204495 435863820827108476
736314938493912566 738279114423151796 304540682540494064
766875886621279419 503272218144778439 927961763517453559
864804676810401553 834105830531924257 100987376842005231
654663414770619597 394722395990137533 547327756831917965
184042397513008946 444003161079024644 827839709667053469
736223260623068778 568537743329601461 850417786421855786
223089931719197228 153419628196134648 933490976655369434
187516090665729272 730361006794287657 912317017862258699
549766594752955264 355686882927635157 998709539667562814
703662231389671510 541015101042385824 72323588646890851
756872139621136728 776606496963232000 840742749245509331
530805398393436168 217699550332687170 201648856438054965
507103250378839720 887655115561653823 134271250640192798
921046933755306871 220668512028787555 418776710449299022
301324891761787085 303253702792766054 703084126966043206
224891778463544233 336718293791861411 603100064758702319
280224852961756210 985575300732238193 841836998048698277
970312782597106179 855830530820422676 574469329923265794
829034906223602773 969009718268049935 644469887463894399
303586397511639155 69384619132469977 828200338140412254
951041245423540986 45242587262168314 688836612678140380
845359755710645970 379742584712307901 166547996025959826
586372791287380670 999976136130499091 167590329830532878
241086022165471594 839255327671494710 278928398278231654
786378511356389559 143226955749594713 817653582775747794
846202491508835572 474300186011195817 104303333277457275
960997979959193981 822558351708811091 999072227201130851
839996422642715537 37287036168662000 888280620151783959
6802042454097265 329398980336621458 76704644960113963
751286769159827453 544488299777677624 946126972229290008
62603054928111811 94734733679869496 168502562662793195
943123353234115358 443742618593771266 621825552952839832
251959399693045406 301569541777299364 531074581019146540
103521514873201572 772449748478824235 165537137071198766
904386685348386351 954994207414493713 327657734065224833
586229873837640857 821235143720101058 372512218513196930
999602473251569375 739148474045421186 271316743247807942
965728458126336574 470957461565695091 513286517765040165
707377460144862695 995459957909100535 122264350726362340
166420998894203455 940539369558437479 19087226170113071
454789990903794635 435352208276266158 28537401974278094
700672814546417332 640458989078029101 605216458183955669
727914391503891532 804010726916405805 475343587856215577
100280241313442887 446974976078682712 566294757479910044
46110739338420994 738305432388683540 504144931965122316
650359516944896969 440819967659710024 421105465747233369
593713112250806451 55432708676489187 173390550217245898
190054034112887518 406577381202669908 537712747205869012
892009971566440019 36716340420737913 446766412845343025
702626242392762359 96549988842356794 326609594963385221
63883257512753465 816013036594739799 156945865154711460
518945111972627850 13261894050801035 547790932485384573
896158435646088262 163918837945671045 576404989700421631
897458818821957794 234163506018325188 72286113937448865
541039320202422941 59841644508049518 549224182689621800
117944473388813976 791956686572319274 931632073687766339
228675618738921355 634226347343868451 612211392306962578
948625430694571493 301847827305789015 348798793005147567
540735220201510777 664832171294968312 319666907897724167
610712275489289897 615725071375239876 81499574906337378
178550997175436931 778143292323304187 650197338301668835
939766916307067287 319679030171240468 243554872234594266
535567108129577867 811638567404102559 378428842938798150
464121851969116909 88711356971566407 629388923955659478
988851845189874298 438790939490077121 273359162521790541
973283550433329386 113412933345030146 175875176029683923
505410265223537065 314769199350539657 769060031266079545
955775219518625184 180825983105877195 168983192400955595
670546409119198776 670900007524417914 142224417449513450
617440182229036490 997587218895182069 445026070542869453
364436612217388161 819320620004977923 689352581934978267
254734018459058695 799526612959424236 124716407804392331
611418608388917248 717702933969129500 574319198916474492
99699590409512036 580282136454905418 987938019113892683
447423998134778766 915959265985610770 990743788165794058
265614019924116854 782149925831103863 561411915324076681
226403454433811521 193604936367764563 993074392828736891
401558238241717472 590614763600425242 888285850494810070
374676695086903649 865433855695661999 229902644650457227
60292333729915099 340340621134618063 20808999007347105
585391713491314577 143518089540778226 746035559775668744
445634689613371430 818780103811170814 424240300693988574
384710051085801268 95066367544774440 899715160503683688
47076197248447003 614287439433732368 329381169172024164
813363340784399867 28970822696041011 929196743684666274
543810062140815789 953541156524170042 367617497057839637
677296452990426499 575840694537174457 26459588550658163
730220036707687601 891517702311946812 183565963087963484
437629702286128483 562102191520073206 958662311672332828
813564683325221480 203306252939169774 312217794712021351
998064911705189587 151383791365910421 290254651916507110
799819751463056921 446521172510898443 518928807140618402
986999806643487294 429304491123189415 21858347039870391
546677355957398466 889587727440956812 193641328400345967
155239053419978904 617497799595736073 234870394989502576
246917402916306129 521170401324794891 615666543759898647
687075691603402358 514205047747385674 972805829690762971
40041653980258406 231139520897941320 126519758539971062
763955813710406274 268640156248224500 743078191824044257
750744568599965897 711617287366124305 181521873647188080
246636908929040263 719023852292985095 190927296510183415
698607717910119037 543236875549425544 377559888487220229
985593862182817721 188122786854542664 821549474035316902
465145725269283115 220839531471570870 482055204842350173
790179063785258565 490446542448257467 564239739634152465
701901919732890995 541466485905598614 92732466230167958
587991212255918010 11533450418922003 540194410077758925
476642547003012515 141439860338177722 573166075087706667
237838365265233014 351143530449439325 518305582586235088
674417712234244210 497576886238383668 489021748177099347
713086965161507839 842347090484499187 193807935927955959
102768782847401137 748352244166518516 556294706911361410
988614994378440397 232857863964535723 170978210670840722
437471146007313503 995156224010055189 213414864786264850
51698040261069169 729222214519419528 301188698244169261
760720971896827587 350192856212201556 480419612824793194
200919958495501560 111847768789637438 805199483853243075
47682997136842270 933250233243034161 144363505388939776
799080111283042416 239678901715181111 45041115879053855
526141332342850607 781103306175156419 780412237405504526
144898574483464167 258119588461360371 205294152924783942
169286659260111427 620516270317897781 327184779830501919
814917664387361888 234331751794309469 174367942330506145
853255750109628552 686111256467495807 161150333569183278
602195273632620865 162289272261495446 466142050848430559
416968018918518884 347698182229276928 556459206283284179
477803888560046840 955619788447901937 911615238226839141
984536859511352902 710132503782963415 749342071463299232
511185927355296465 136843757740471077 67364789016872671
449175832352190119 311240972828479522 198545199860737845
750805075467392008 349837413433253615 54117730137670443
712392845329199670 806529933854614925 9058356626852046
506788079730662953 820441951636785304 456234925949694314
86672578578013527 679430220228379484 999810985119394254
652731155061211320 815498101985228297 920290150583428971
90920066302013165 682144294160556626 967566331616512806
248228719571921923 519112040973150485 698961683213380919
282945597608426054 410087513543789092 433993655378923507
64463566591775544 335675931851201757 690867296434228464
372437910635397217 961895079862010681 852415151397121715
73013792320461769 598988048982592174 796715663955958761
62430722868364379 581975518556083512 683726503224611148
925298878936067613 498487829867024836 442691242423613711
149837504910669649 594655464520794282 760448944024511273
239595749225979590 260001671557872773 621057018377656095
277641180785677797 304166115748542298 524016990784965616
541431636039003660 320334647372387433 730909569775394006
925304464918376536 500418527550404528 534922566548065661
897911346269308299 424627697628646170 259428639255451163
188687070202910145 929057457383014623 588617519227457213
374102785925874084 217830962790249046 100000186753517022
391398150500151711 94768143251636117 994291004142383946
946179244199243811 819225334314838128 315405224839372322
360686853021439372 990910588228157072 501757167011784797
53951718439171750 280300605781086238 663695027153753274
230123716464427480 53120059052595993 322594114724970505
72545335906075745 277153671812689792 787890708262766935
320469047589805459 381509947175433326 640083561492231592
913783123778328133 958696940966369730 877240087720963974
993575874218857114 401510547060728818 142417860680649398
477282685809150646 27102841118492939 789456803592794116
950754041044704868 531983893245123540 685548896642988722
971879174604763679 464645365865553128 97026980731076619
428725247846208172 291173811030215312 424259396751964929
965738340308464211 845142763343396899 18867455733498039
327246952496577734 535289365679223314 693648804491608210
591361201901850996 695209355902953437 56468998264961375
163520362545478270 285287515535969740 911206700588844596
147111662054720440 867336709721352162 685958846179407986
192085612285863021 326320583830327460 138637366399408334
658301925937010787 616710029843311913 695181309700117789
679752386800394333 533202314031934344 968472893107872860
491306662696372381 286068074807947858 614709261835380142
596530614027586516 598525586715089907 416415854979005853
793973463401233202 796190828589922097 351507783703369666
524919176775552047 313059253702869950 716649240845464167
286203365605386066 430539585436963228 621168718308420772
750712437916203069 364202370426991277 268520343801301388
67946330516388726 36605307234777302 501147925227178358
458998582908298791 575593926059352171 805395133528829966
554145165663198512 435707970544602814 951559366762404090
221439470433504320 813973101197134800 446190176910732838
631677805299262024 754668538192127082 955864069078383195
801023734879162717 32289227388140466 668618810348486421
554065898564042529 775000346022483430 985421595737946434
664136213646092397 725463188012326016 345962133421123670
211756939734558271 489653535599188231 635501141313473363
891454728767869667 823066111253624741 10828701562924113
704955924605850950 621084528369733263 78262979354027779
969654737388224412 397652669222925264 951196047308409578
941294892316528045 314970991327495538 713127549182637299
863770389918379459 430000457978809137 280256330737672817
24470569214242986 484496261181328348 209431235828508488
479728343091277083 89362970007719563 677677315920613428
897113018973015301 634792202627154312 861131548013509311
7402367048846975 950282139403362613 528906408441789346
524013309127976049 787972468114302364 495463764068002085
992476638198972881 864813843709742199 347430128400495125
112816530274648262 519192110180704132 44427044306772917
942886423037907152 272002675793174911 364504871914434451
948268113591957911 531019785380507954 116924463211755644
490427760303789748 320520299351538364 931515689553639409
178956166146641450 407510638625750826 915434490293924233
478512147857487922 198969719204036146 492609505371171100
187221849647617148 987706435047549158 696817345628137564
503085097633403735 765050026839168033 47065947917122786
93930083019924054 889861061336371121 312070876294857467
364859668425664001 703878073228615705 527252528459576737
887609570501641544 84041162757693673 20486169030201010
38823770407420069 239066002721690469 77986782767709076
160026028153093789 813333290529996493 890930982473649280
331620453266058188 495055777694916144 550492753291743046
281017039068607934 68426982107104331 301362656965308626
149769567450209418 581999806419051098 744372611426339530
312755752955961412 200969128463858109 79600118418540018
644780082428655847 143668992812664562 112102290952889192
827968354177799841 731225446356893156 325913443139156326
560415750022053810 994650021403628252 330935443102907241
820290872667784611 646222316911778411 467206707829536753
97789969434484749 645857991401230800 572256908504262559
551295760476768368 238238645207339507 295923856841509540
795663605417337558 307746979986729249 384287535497765352
586237233419153837 168496646931900371 698786100705491473
299999252673813753 42672986344609314 320865601895739662
509105190913617971 309667641615184706 209171738290893123
246121865464567672 56523380197914727 990131853717519571
325871313369404827 401973553717709243 31305059855596433
238726095955751105 142174809536601333 459810332820665088
957011531288979702 118272367048504251 599610788404042443
156451137158017317 76255303510167766 288063054140192384
95162618537123511 878608372312251233 102851494068227815
38928253325223011 536606287026964273 177892570092050640
32400965001397457 340604760883454420 629594950246359983
974131256332043981 249114178706564276 716522210947111636
283563838599194511 829584579581194132 572812436486867873
280960308889854311 714988317368626241 220127662759996439
799798109229390913 664685622842917878 77708776667754866
248196455225526418 986792526657488142 228132031246212104
124951782538496423 130979720287272452 202145844752185129
748604785221644189 454016258252430919 114739779767619047
802573463639362034 124561433532221352 632820652876962474
633720496224211787 999005664481171731 159160725749549319
657912243981745788 279685864643247696 315734342134681633
64218025334224358 647126628390582658 816377719146103196
12816937282771482 987855104207104285 27715845176834657
511321189950056933 692677910946946047 506258318420813006
253414976834246971 88406317856132204 7803015794624437
516566659237751037 202002566460297788 294641884482340235
702202981138906665 944772837697067531 680049149478490067
762462461290448682 218034985848996394 539018010758641419
498070561809712542 147108564353660752 259342677849340554
720348230633939074 237915013362473597 311303903453945485
874588873973499128 408496198282702524 783768239884706662
523588829928416922 745001923033913416 104215402168637539
758292259416698284 803158799283054756 84546111716521716
797929352283646192 67648433904114091 70583604046826500
915241637197902269 575811927375791910 752668226892711194
187198157952677024 577794482767100442 298182516719782822
837885656204772785 632547505633591663 395421125923947674
70354021971175275 41456502520443827 538099565594123008
895809811733134246 966068266181368379 922631886011188262
963024914200580595 964089370174325192 481532073768450342
107101079519736747 375693624673947004 603602825207137324
971616704632145197 544978456266211533 165446168522426865
893290472732220756 488075456508072319 423702559930988157
897226912489563932 401510165494155118 631391029761112651
372584501358085818 427991743073978106 471047174846471869
377614561359293164 640681563429139679 62942777797082138
192143087531619426 578730900142372008 176709475964293197
455334398751361021 402395078950727842 208039687219705108
357093300629176011 654315750252653034 697370842855392613
319976268126309523 990185330570663702 900561614992882958
358976744936075479 261586710223578334 762770789460429669
623606563774654288 770127250246062052 188659465017575305
396102561269130220 354682065317730192 964557571432611990
179931052138988672 37504317854976308 236326299931710646
888288016984385645 245756430923161306 361960325839493654
256412345883284540 474414353067115368 416817289518444003
103571982069991956 597313927002312663 491460862278975294
709081297146093381 417145842645952638 597097046783869804
730906869131855413 300023547751630437 373160721672170281
486571800707123347 900301674753685840 131409639919565746
14178092318611436 241496818932046099 251511947848169191
133836061302753020 389529920934015821 695577894452273507
577521900032864556 977749487993543171 771212357396053697
506279661688529734 978486257143583902 89943087167511311
465961307343193962 731317997478193184 962107963805302425
173474713936150338 632769629372171401 880543608390321023
140083386325648338 733602458229421398 986286340227155413
332039026623391162 76446348108105392 521284302582194125
115425031173419570 774029818038648402 862356840447614500
887308841167970250 373100273210349059 505075945086430840
818007791391820731 434546679720865590 230220818228036039
726166904959339426 245060101994857088 838502781216131996
683609014029924522 678285067688145387 926881838615526726
288919480729940055 969091734134910648 820400698739582628
300273392221676835 462993647989317955 361455173432514503
54786515479923414 733968953312069650 680442604293440829
57267124418069913 993177679503416764 777765646030872423
481843832318890109 521620458673378973 119817377387859769
950425093913984831 693995658983978057 115933417299878528
739502199717576711 151932453031518254 4600314738516391
564688804980498526 312689882186854159 877009674276941545
244662543110789600 597884226101549527 656549526459816689
975563231056739987 71773835176787628 868798996457634496
567852177387087635 835305343648560163 15655658858239683
126867906319100921 502473548042099011 691601371790446886
600199197930511509 289172718951532071 149281147581272088
501262205232909822 899760388492860558 354461970808312888
643867961194924404 638678293975532688 579979217779205032
780281615291016609 580843682070755625 225888621456779973
411753326493974038 946638131712078139 91584209284804407
3706199267548368 617833608367949166 545534035699468145
203066645288761355 620172650919804790 991820225163842802
291265168289960812 572112040457389345 201940873037925518
121154335553959187 291710788589414876 743204379863265968
446853623877527068 149870769972679797 434602955738161125
118839226787949851 305526477560849235 323623450507321825
47435105861269190 345381000956774548 774282236172998700
218126175113786675 411117881618585309 430528815931348035
456756098598945335 891291600052099749 842683504610627486
421036344063057608 138417988718931679 619392342729386750
546810011450669188 966351810375814395 637400117052216691
437250784697911252 742286472447971792 368809587062230564
550128871546520703 72453678852041122 586373457781086765
796845492343128285 519505664990722357 741449069442550786
552830566542147935 355582639702669676 677537667850158792
936853230165205137 826958781253168021 837603031005202614
297066341091744988 268943142453807362 347084949714115306
92538056754009572 919158239891459226 396279262937730962
702913878745218608 209724870450046460 580862630931847967
501259092421404077 242076576887100264 103867910227673681
478900792195112945 48769198520873513 870988609278712388
781405305584627464 33497710071864200 751533693686755360
349838167725954740 798375515581182364 998904101069726191
63458800905018640 952044906371834711 548053866004539224
777287998199207160 994550554887944116 912953328319304697
528497190727592942 475021915148414741 695609588194577983
351192848287967281 901162093009244115 767039213345267074
436853694835416328 896379125918240161 59627322601332422
727637670245296911 17685141224652022 535044460386382542
664938882377971309 617763030265444981 778852784102072828
987164358951381330 55862676331670715 920352935209111778
889648627537357231 342093925806671484 446985910255595626
217805512193849773 973234087496417254 410187428777639369
976679558243418804 476800188657315372 388430141814544534
160749114043175733 450241771868362864 661393566293667210
838425393938698006 775594819605420541 66872662193343844
272446386687205984 483495421745775224 14405247293216237
927756562174124447 283178674891637526 470915478058235769
659646289405739924 907024811853330776 740503257602959155
595508210638281444 742700877698015993 885460872184590023
254928764115710319 447732623640089365 352254662032545347
158756089975517422 242131556136896288 118332053891531703
684169121861242293 810957821233535732 395413927822718731
179081122020828201 279441749268907705 127211229694250943
905861725301457202 340054623715663232 446121187961532223
321680401457169951 988802507739723974 573663207270298940
415668701372080992 418927085217278945 103384869334442856
852142095895674096 461707638319106069 328071750649984537
113277198002943754 840050574768949951 491133299990768392
898669230718489493 4701849017575858 682277781169682401
98076516868285720 382519516688438171 791124170221632461
93184349686034217 260904337882074332 827843579854019628
210373399116354221 399664920617618297 720619140900567338
489225345676751012 441189321185649458 870104828924970564
716487068377863027 753001320955627562 376988716731984931
697401391288104469 566911048284781161 709852540049863755
198357670282264764 493589809904573703 653248779027412100
925141972785076059 165187443737535275 192318887792281420
45071649160802890 166074200171342608 951578644732604190
554972411346581933 94590589144293655 873964466587030557
761514326026711033 588890984485981547 501234573648713360
826049371864965190 645822372184681388 305299228282295678
93624183031066847 980677055736273551 804690896617034306
466941352189602740 395424695507500487 162361239758892400
103902079505554379 731194461604325678 526792044731366669
569109093625569617 690873657218453881 173267954994360391
553298636414418131 127886180069893905 514767336506989575
614542669501734652 767492547988230178 476697964102775424
486466598367765060 78678461799354757 264105730344047918
721057488716375254 782505806665611161 935199429480723673
216772412645362733 648452951511353184 621878387436083844
901447159166576918 448090935180443013 575275403325150661
675925126324323076 571196835318051866 329048474016379010
130008432678574233 545602005735227712 968604073407382495
134145061000819130 402219083801939973 955834080429239293
504028701535846715 700361252564412836 479491258760080888
50360470863224557 651334452662678027 756986192447800065
178796355973538059 250834370098907521 244151515041967111
612288478915617130 631983105784311443 79795196708556068
4089083757745913 638112945721976771 646059048041979281
962556520759847888 233175851713347454 442168762074435294
44339168192803006 738042545377593010 932500781890681163
299916543333043126 186581913323434370 426187605355244649
913788632340632037 518571772810954307 786526537921628690
231548309959866311 308021455820886765 588878161557708739
452646048542732329 431934087162248718 708358410254767305
987258822569969978 221604951464320865 905521444839722417
976409417409618184 539040729306360337 7711605661557729
731929733483101356 782902688190047464 239185153616270974
115803770832975040 451297357812795157 679319108665291756
223135531577136659 380905977515384439 899337376793738637
428358835368024650 269800732792617512 985759608679873916
69046424393761746 990716483073245012 591331050378101866
876138879763597510 19909216905535278 781243974299539499
813351490645859704 242566353831963704 177620581210445057
930103204246678044 359345919188884251 466792139285033757
407464063381297473 433843212725574949 456495735468234499
8480566621913792 930102788836084989 275146132418141802
801648067348665661 399397751252526307 637907799078374613
831301993306542824 399647431220787863 427039377827013165
535862906715606886 953893276697991591 879099310905561927
342426144357952720 406102422774420499 266867339809431166
692395524233029961 847607959874132695 919138535624188189
841671254806035562 285313615328455401 517959670594597072
304222988329570950 324571906731765810 436120544403874132
773892228883659845 923486579662838442 26726896867604225
954871920449502761 871314380736726241 542872394961720190
721727726132366928 431563040600499547 345352348718681113
119640805535746949 361055448166934478 679253708033399106
71117160409501992 612316969966223156 417652192611375363
593770291055645735 479444896242853208 219859164460579162
468731981827592883 475532055927688661 372584154681104020
970228214210684243 517625259939035011 227542782303778306
200624624245435867 48352580219728341 496357793044185690
869081030166118107 318703340086623662 143209887359075112
211439330481323283 94678134741120895 370221335661461682
830983466142987738 171469825174455998 32549309957043849
369734629077534752 982266066902872359 893374458200615498
609013065581335667 122765747511474758 701316622415268228
823647961049007362 751180782747416133 731185796117815542
859538772973695780 883210123203099889 568155914090981362
136464385529284649 34923525198185547 815274403412395922
314294931675203284 351297566712835170 593487040910706711
132915435454005268 460233941201206351 459651466960632127
404475923806216392 615632963103903259 653842010751944743
186677036500916205 996223292549102162 71906849566448640
235191117903158054 526403882185313704 989242450572774625
143694178579389831 305049299105071481 968931163600480840
751399811091836757 709373098519733824 969735203612007751
822559460458235581 513326286491138488 651007739619299343
451643249437913388 76113759530980214 808511676312762334
194638165034545579 586923529569041094 96430265678903058
838407921248742336 285570531136988444 912466077730282767
906779561391652026 699510209082859516 129352216889630277
894544393141000956 527369216044356247 663296831615896200
209429484584145238 400749966595482106 759121224813631613
159580129422737140 763702941879675220 831829627100308599
368516104288075355 799201575242272420 833740594336826427
495707985280943944 652239417147587955 343248980881804560
514614842042572986 466005964950863203 84072133712342083
92711785665429308 778860473812778994 26464906122270393
640395296154059373 390956109908404706 346285989443400030
526303297368236273 125744311788199579 409725148326663604
483695070820003533 658665620858209874 124920953035337032
689578765436567358 157401170162469142 689126273260908638
979378208130109262 585189549652779412 800248013764267
89268784018750031 294369321962524761 723004859569524913
874212327140291082 968397336969589653 658190349899918678
855305437496960015 68770056556849223 522890159470211649
31739603500100384 685286907490005279 5265167590373257
191312163799266739 936739149517192408 830007322953498013
791956111185697004 999785055519996540 197467134716433033
578831545201587780 885423494928815390 996207869215156043
786911198880626184 134042153170758124 934810858583479372
106611398621972588 693202840249947743 512064201616452611
361433050735498116 38861239812492106 77974745687759911
915965806439393707 496770615146878371 473409862757596222
546574348742625270 186234025784976832 146441121660619992
583380279260694074 75158680753410717 678216498113325446
373405182979943049 896211776570005152 40041804313934442
866125245357523960 908339557926429968 349352034200971709
606030958904648635 653149353511110574 13105327581897995
754646510477169154 466756185737872642 110029730959620496
695652413016109672 43956985170510677 560548366733120841
220031883949450024 312086290650876643 966638317362367892
294664384939068070 444556987805218102 495265839825815692
559511665166493447 99435687409084604 177119640827836977
78269516438149200 362351030825551600 511181803739733854
152079480662513860 472229227162042470 316039570224599036
823516538362132692 195792284650219086 336262873373259494
41440528948529890 142147273489275030 468604523556096356
318812240396142634 816754597091717294 913535802579896724
185424286682442825 923920755716443502 148893432502306182
242514214552804579 964530308603707260 414254233022182202
907038292478575321 785445793593055282 215457067319708715
960100555377659895 827924258034274857 634379692307133483
210009203393124023 891337107440781897 696896784201176933
380491842928601892 366177280465473839 229992643032829899
5746350220168041 248909452727048071 259693148652625385
809080194081332044 849122472090494603 748996639641526841
515433196543730146 489663472313551739 4919592519539480
533399256001331530 213177793418700615 479606434529020260
378784920575893449 786073568723437150 501572366668140545
231014670832729807 247776232504609357 924275947755142432
794930928164902957 739467799252933886 948078084651514315
582181384514394591 271170059147995286 297111818621694686
988197864055787861 596521291344164836 811359507617659202
58885679148815311 946393706279600775 879133244366612522
63517843228034022 841004062394453487 173302719705180116
528055564839587754 30138456770250349 901228387731697856
301914509027094323 365926122168391171 745615863271953785
619325727463269262 321234763183346829 137645652926194646
748466332070821595 593798975260052475 149655098304031810
23201564557209952 621092016387570705 172231397638898818
2091167044189600 837373393203078400 526592459289343196
297545714350400241 425994109463495052 331965736107495852
386129732804120288 983469888146962534 572590425706996995
848106529354817057 512058672497813581 448729276364897704
485032026180982520 224761344829832092 262221177975979516
473080426662058347 302081162513999630 475485770859570070
411314422847902723 371304869998959463 92039161939769947
785967312167221842 770656480000869507 676998839569837927
97448626282426710 515310558519456563 623519454687759200
598988286763753949 145326834924599729 88114216707189178
170624314636745921 228565221886202806 734111346296751815
924273730335209555 938387186068480779 973707077966689923
412321160002609317 871524330348330821 145963491912725640
402225686218656476 352251171505604248 795873186177944339
890000454089301525 961868137545658085 813005200761266563
12637147053591349 713143676108922212 253424424652242155
438474492490368669 244041674748680280 197383860478192569
607403073702902202 932260765781297597 126174561999932180
163167913476536365 946704504021734210 680095064853405699
260708985813377619 805163113953604201 706245845177724675
344958605184995888 964177756435052988 680640492844000496
175796413606955152 687159142953418553 694804732005355627
734438402282545114 742850877303824382 260349362694270666
719793601011441465 977459557663748880 374945950684559510
80712926227084239 714545344236715861 232028446628837630
708087557086619429 815866755922255586 38119072322183376
521482777468760337 302925934778626183 791274088137310396
175675830851358976 920310024013212182 787294158842656819
185828366961835246 746091503553728788 534847938184363223
629573821593992880 758705834150259751 50227537551178893
646533545124501131 766373240060702759 563691699368824511
70843015652807532 37521290087203517 595653187771846500
152823822206934647 5293371534059801 979769667995870525
891200425065944406 809081579611376139 955693565146325290
293667569330896259 656496932487276315 515081797759846493
514835526267364267 366411138272540403 131973052461767929
935816935404988958 728871781387358629 318585065428558113
269972026672259904 789387430999085364 69138375172234763
447346323659705638 804091679175624586 660445443079479220
192886594103222506 965719799960352494 91022060022031658
778766880085028117 425507070445911165 247316000933361833
210039577642174240 686920663700268395 527405081745211793
373793986169694347 952068295743018419 835655438298579979
56942408039132546 728375991872953074 519386979772689441
864761228211382488 366284485059977659 528569060396905317
739186447913014692 93177484455560451 941508036247491148
930360597986901094 683415286230265336 178508967947599719
599577212326767683 529004918050038091 383053461243081358
191664927412941734 675921035331168699 191332175480040982
750905221260847414 127018033580876201 453247361792114540
7149509897661250 176050789038222157 512333269815712046
563672114160294653 842705349168347200 998705052591604795
603433806169832441 803690662224669019 742447490113533428
399519064152121364 197070727553355932 425456457914232124
592841985326793018 43371313029482980 253518295128483049
831871349950260657 238012646989806931 243302996376877665
622503412436566090 95575832342627495 362958444215086745
281596803162908263 715764901681689951 125406764502099111
957316406586932472 401772886502123946 319171839825818331
226507167138018602 796835871614813897 294906848782175639
135116423230467725 548318570861987408 71023296599544779
903566243474667905 857576075137877670 744265226433227034
907286020661660169 473404321937717987 729464584720108728
158589271340139532 941071852984771620 374757174274594783
171034063483083800 746263112098221478 588414728000417754
517330722522034662 743118985333801080 385731783046174414
320369882326654071 38162919147059206 171924258070473841
865788307576579437 445630245218539861 333363547710105991
131856477290004425 1704079654117076 256920158371382402
832416683286521974 156623443324558912 392119488231653959
453656437660002539 76595513070558192 433802654976988629
573305329192203140 957274217423703365 564122695290184435
20825854456632668 816004338184983868 484315483811238445
237711002832770700 290950016565064447 329129516843987862
544957365975720180 761327781748038792 818385614083179206
321689675649728178 19586224413682171 664059109129128434
291396500455308548 645131161965106440 833200941537358623
823186436053980531 19246881136456922 359108039414341168
459752239395665510 252073516974299656 884858793183370950
297772134875788562 227973273918378091 26307054191929672
247530709391057557 594391716269833945 268516986418408960
292301208542713975 949909800710563863 24890538266570476
168294839933345460 675082136747725400 896209529818126831
810965152134011892 543174783615516719 560897081887182716
959965186852473309 625009727362072018 436364245894838230
815574912967425180 98491590124994965 890555135600494469
741232055678709320 520221287698800277 282030401916816716
981166598279624094 700895332907057628 867906839578413364
86266958370215452 556503582210796720 930574363203029284
72693054304134547 401198535570401289 412796374411683170
497821109317896362 199895747480052569 151371415141431255
360095868135630066 611901170558163384 727314062715296082
428725880425943057 809721226266899989 41137449759328475
961812389489513575 656047990557943448 499312465483901208
964097177156670833 65891855223802894 742192967530209780
668433736933720842 757237516750841024 30987823296070550
27772832340547518 430654690933825587 151662972893800547
802547248234337488 638248868314471217 133077701858240130
399752207348520117 151157072310422133 905955002903468923
459099005308618791 954479342352574329 70874353837673154
534994961571713663 489027101939684864 700739870752325175
511562969259020773 178075256122671911 216150911076098592
763988798764104930 713514922513759340 449493142066677729
545972150405198406 268164881220715559 372017937985233396
55893970796097875 841036426530210433 753961019704686608
667404698305937272 943492084246099094 249158824935413603
998139702285883011 855512085521936879 191983407189813735
564197062432153831 580952146817228206 896475424334905553
103451289180920598 230519021629336734 113426038489678488
254995475137460348 352910354782659071 664258849111337032
26780198061406119 371361979724764350 543646099426563871
306923145991517285 860879687790412544 730177554033572708
440193134271385592 85837170862819002 854437945078523178
348251213010454190 280235725755821483 898397616434240665
398693669659660155 98240711002693569 200068824994954093
833593084501999011 678079496485481127 473806910570473808
630019211157347589 133130372714827303 369905134780902688
663089363700431334 928717176231972162 935077261655552435
623676120562729402 133249510803760799 380423824611372181
746003799407279461 995519404419464748 515577717034671471
232174800656818050 720159722336680642 842082990134028647
871023801414750157 305324009415556393 266024318727436757
338310187533472324 74047279409278246 525551953709075869
343478549954294778 506867129688307158 892122473225121098
575734160212875436 785026720306806331 639427861341845019
685931352238041890 293051963184153642 483344378440387527
183347895968702565 638440835000651487 294566998731555445
607035510225191061 193236193038222285 894815606831810747
618115329946439938 872079939119780805 568817695492413390
527357238777699178 209674930253383396 703044065217856051
61171716664816295 592374154933466759 159782196425077570
735476848860041439 473357511303892986 980811433309397292
212331914516679631 435535773988036496 382196549832697655
920675905210315863 940349954674092879 428731563841948471
738715937446449696 241086158186259858 744151487248965669
855473612157575283 161279954222940994 96198707653189959
498385308324334273 171252414814903850 23096666912083099
383366267260941659 107912604374535210 317884515465299946
149234209795257818 972964302715489190 490365403299955822
215781350639569003 761009031870407455 505758134115349626
66394344125718861 234287411533538352 190165711011302228
223981238863331596 906693418036345986 539861040787454941
837712480906985123 575622135781633561 133701756144339552
735476408377597648 931669205181807918 580443007378808394
277513660839647312 102940384803450268 802932207722995014
174006413733651646 991265732703001426 695290739774016650
535131501753336377 949438511047729017 295177019993099896
251974919996974610 73901679418548863 366277580890120722
597941043508748637 830452772593745249 243539038666120838
567820010204458994 63839888859870925 281081856138432735
148396203575977718 638237727581275912 27723158230168337
481699308568267942 55841749662937949 635019972083415612
578337681555970683 659327699370036468 325895104986384536
960881491304602593 693983087573843987 423670285519778000
179629012724174680 173451319843764279 807758012603204568
884126418631326826 335502238838389401 225581376401334285
447173329335656816 782909141704526766 590296846819671601
415037283867067135 257308416927272586 75663930244404404
777773032548619611 140240118965279285 71007215646337378
597077541371869767 959451455686711552 957331132160844497
665705857699837789 891861081673002602 923323169611441804
663256344840284261 52378791686402915 153168995566216397
902762723991934484 685273187942637400 653252838464990323
374116750696371563 67517497465225501 261829279437000638
847526650255307819 441836971121381085 761930937570597109
908380702054649699 36257319599430965 904681050153081077
819172295822544193 205345739076406455 375463538925816261
295329358136370991 568481577230500473 853663306122651913
244995753843542584 752003130910645080 123907253652904031
685549248980345614 796233397691730786 243646145896552396
153294295983947935 12141277916418450 731824354718294582
681882392339834147 276733359386340793 896006807755364744
927865968385512950 87314360093515449 994781921821748647
774312699121799599 975883812105889415 948870189611613053
778416132377259753 652099056294489583 407757090862281262
7417316456214794 575507512243884959 85249752206566497
332316516614977680 682284075751841806 358351982333881231
123491831173146697 40676366827149890 755052304561352414
125567036811395267 783692558414211897 479190106884464349
811036673110573539 698325090935729836 257590608608997177
52941192903880843 390300140902443372 891347760055050236
873983736852770206 6168650283886073 652721857492577365
225863905749064903 624531874182007118 821528871367352920
69169480675436898 883990222165676414 830066814389947106
646043209395101350 795084640829961366 126304638094316554
218171899171831725 490281686706629229 313683114820834896
147018437742510092 624344457578618821 9007570884300611
894169023843474959 183141996591601717 449429427574378714
768612372946039232 888916085271983510 405006824191155202
84591764144405472 930182489488276091 215445718973290965
648003615406425117 133980860210223017 160022715434067595
860050663892357579 682259802187721814 620506836205599092
264715990147363926 548406921888442404 690564511792828089
457988567880186547 436306945353405135 397520000435169176
387567341662503582 472260966345049143 523182458921627055
61532681576534848 264099843492464838 335581263913358485
67399717118954778 263231285048256017 971309291012263837
524063206940326025 31538351526150209 190682288946622845
369755873663651563 759166321832401778 353023943684778929
652686852103373602 612433570724746838 294262532121286164
869506017258008783 300045597703575163 252504864761170295
35519359930038346 394858886786125842 894156577441037164
913826090324109914 953602912214308742 271207810357992363
913007733844397200 497124820269233152 253796814915185975
870000006087129613 389752835350345194 832566926182335714
250639743999444367 437756643794106458 72373359676922203
266268934279658915 927377290453560537 642146912046804677
530538787269613141 934663832417751604 576979848753867162
661216387947857768 608702252636382109 827830632803450388
462686252620365528 815372191695652714 28062221795448445
310016198412478641 753349480882146677 744456762869269245
707373240062290975 924838107386389626 590699110155233698
159961234771400325 842794246694212673 100910668454182273
813112149028441388 622208271440600408 404231164998306673
723782059059058665 626358853127592484 821250841248937990
518790430396581333 498687224687156834 498361944073121097
728498099066512136 643280551744530794 133596897358479547
415273946034651274 78904418652380443 531587448403286200
802982241541505615 966967793889992076 611942669418896857
718379799400680741 556362141005191315 586121737657851955
711776068964965417 77132396364179 693680659167598987
773668710550440190 865609055177499858 713489436942085357
909670376351382096 720171967343484868 360875418688012519
378181712912649323 710078144927735183 140934297876194790
337180927012531274 607638014301994579 863035372295336463
749333050937006367 206591885305666616 306344191794048098
362432186827530521 303450160229959110 195021325866325441
803588461814695486 430044811711253793 296130343596075374
657647254734148688 280321169306438650 840644299870838827
686047201918182744 30406242076835864 815146759556540594
800201053610961461 431960983807361299 979621201982731423
822466105581657319 920542417455173614 427480615699332276
980531864786605894 569597010248792329 291049085837068569
178720570766750636 182552938923343303 623495109059555061
78655984339275544 313675107552060581 128983221891500510
895524250714430197 278228063514282034 686453098844009912
707783269759868352 755697480477054203 578697655191010053
413028304846888636 685384161960754435 257037269717045790
410298818964474037 599751464060581802 416507646606452065
37453995836424945 172514890644834883 775878075601811803
1518892492788623 499147361216016942 187905241048912555
634688754126390266 97713795298323879 209903592662971159
558899530317742545 108894592083408274 890723918788754895
780074373904408587 72541535803238067 415551473567748195
4985948651338882 25499219627698418 523799986362331641
885443955280245158 508977292895202136 854655510909792727
43406221199308967 351742596370530102 664280830651875645
299723665431660104 919819246927804716 558184613674261256
668591070693506781 637648007930101685 610687020669545057
656190989768448553 530335663182987763 857830764419749242
956685523042211048 678576587231374061 198806486913986508
838019775731484228 818850216403746187 45288702935103774
699031094992529996 634777005562360209 985227955741416174
390538514318125153 984134003432771188 462919645102242300
561627278196554759 732115238501474038 804471934676501194
76158661130106847 887984503288004235 379243825215299579
704386520055125493 146849893876333501 800263086315247023
678065870256584189 26081411044240677 790767737216917721
309142451956654164 647353979874012548 416968943588803251
848074909777489825 415862042791546805 499677074112946076
681955632681907299 501523750681448520 400362062446173692
111598357158191675 572846488443014439 87662548353422481
573065598151296126 593064890740677823 772928729319597370
930244293191492267 278735758281778709 656059166399538044
448964717365341917 86105113528337385 316663860058317996
667521516311278516 876201950315530732 941376733394941608
446514822342731012 212923548633278094 855079505570833071
276156331357209246 375173181294520146 33929638070050806
799326249334064105 595668286059908976 24643578654753215
24872986296618188 30651415071914436 49054004870630127
32338237613861604 842289138612454390 866035846631677918
757822396498580572 356400911108966609 728731574727645313
440202187213438026 974126533505504539 280537022380093881
746320519374665225 38349112878622726 761591101140657192
675170738835500666 23632283640088193 965742864562547529
468810816721019629 890892909446329068 835143597695078777
559297005374552003 574542539658919611 590126607651828201
570015719295629440 297515828479860975 866283653074462916
545073939562693070 368179092421846265 142784451872623736
632450374384992077 893428106596695887 904052433362383192
974466783190093995 108184772768070071 679521443222971848
678697443549110495 854617224629658308 799275866197350808
56613325209137191 541710002484990071 952865140099169609
838008993048924118 354865153619082916 991518526415749698
435927330308584811 274743855214997225 376220660905146299
85035183561668542 259907671449933126 643985311697802600
236832132427942469 132845515709473075 79537401866073793
993989633611402942 311161961746593608 12235045605853354
96947524393923234 134802669959046246 115982994085703920
852634085831369098 358282511596163081 188438037829265454
205895113902811397 715810132848261834 557394362045856509
425906449691168496 74993200512823118 762976462084374958
270503420294138565 452214584035056366 499153899831255096
478038385609643046 534025146719672443 624786514687776347
705462799455839040 213194922457228105 267085009117472146
528351313118322147 682740946487490920 607494649163163128
546519810937573973 713099134197300015 8203676497927130
929433303316618050 217134760060576867 114460626063134546
780692288836823617 612791539293428952 83186807136230696
591513930714418513 293804695337953650 592966358599385519
414892522700513382 644095104403129519 671443981154669005
722072471696724089 630396783179180731 809204108677577676
307650323028503998 823223266611675658 301299193276946441
464216077816781475 320910535263389766 782873786790777838
312237291320916508 764347899927536894 13247710298762116
358061243625417446 900191876425989881 262245085439935787
141974562879188774 615021913727796593 750369871902107541
849477616890685035 168562833073592036 41530816088587827
711331757702303260 465619744527736703 256147024283943205
579728675668090504 475613032167767220 46242139677699326
421371063722370381 810331099067154696 331685906331440043
292038049103494151 611791919727895116 475284115301450748
879198122104864837 512197752822940851 807565659268537669
124254617150360542 945831641934201606 657789906381239429
122988809498177487 378264706438895061 93651661846070870
31810276325828857 161746015662532277 866878055687019085
664754127343535326 478114796149045749 384764778135294002
578389697135886172 836550181979558995 860248153738402489
986508311695334209 805824183218341672 285182182516024440
187199159808197424 624605769877686019 173148072099597424
607833442284769433 347509324816323494 491889216088460558
841878863869297543 559423086392111556 785126465359634081
769486739679561425 982051188387268326 786802508325436716
209351664681128050 476625615219146483 979498650609282529
720610700237766181 348017086534955821 10767021646092395
907660147539890065 375707598383981589 763049839189127880
302631869396875916 172576613939237247 174158218220491742
549529059840703732 716649723402192769 307473802414621218
471368199961183873 332997296801039278 544816937694028488
340068883289719680 720810098960201629 721716490154200963
297510013508945835 571416620107613562 241191191720551379
757164495250711116 846900955930095562 771173740330391407
632177406447561106 629300460244896172 178287579206639526
722932340912082096 125108020031537417 881548477798973201
299502746122292210 589136649898023548 634837568257869097
359294624264735636 349761063510197764 824186676075541213
3471467694175631 691194041700918073 785725275438801163
554477065465147736 237001979541694357 476064624146229431
423485308718116127 193308553844603279 958081624758012092
14209589782574132 728047256240284132 28100300251964850
536650114770579786 145332254241909146 130308584642189525
911139151657698579 532793127271597751 452135815571955501
475756888337061876 519877604308626060 56073181741280795
565920382673556489 850807308746599475 856439586469808909
384798276561620709 257917137895913112 919378684782269426
673741631236238361 469478436599806745 424460222927010193
859349278006829655 124869338839524323 308712069253612061
732157068968820183 955653735961993197 844409390792304732
193499071347511057 751584832037982853 904778433827574544
940215548858268584 218508864697536174 878703089628996823
53923089079424168 54184045488334232 212405293995453824
43182277022488551 644299566804330133 957432779509501775
872316058191576691 292360167200100193 138598344201618016
253349749546857854 784771295605174585 900376824178149830
770597402299086733 460961635826281269 395587931206654172
162408120905108268 621794386065300037 456148690348305428
223490649315082814 20166031949698944 677983933727424961
89473731823075080 228968521423395472 507245016297559764
77085344285730983 261316479586624985 107830053540655002
117631693448802906 757984725743005105 486956090153190786
849907129036583319 561933229843811275 65275206043428269
193877594211569318 723937783770746868 9926517037086639
689219258292919630 105629713776799957 149725433951841260
594077057006679589 194150911114430718 341373584576769129
598216447096395176 617418661221388640 20224238297057095
899609905131788556 56686308369315536 767823747964865581
603232746297553801 431926093765344309 760256833517522179
618739252822810707 436534106456836160 432057163956662205
142569717300425796 871312932912713032 262307160422076834
516567696852949065 46705698104852891 695971541723477655
571338239489372194 302357905585695708 823612761979776373
719218778123965007 736522401179921106 960415588887955524
637416437065289283 96717151753267089 233640227511505412
260475804931529117 975142580173415129 249162640705363236
438267501669528016 848557588029051113 228291344440765712
697684924458685528 714884586935970410 420237103259819053
413979622112143642 101612593733489827 399279484934964293
434856352109627230 95088374328659280 516305414307856584
29027744055900256 157776624960617116 637791711143365784
539475823964161470 190285469792337687 925523803078693932
531923506844570895 24356978693569950 753055630422896501
378959884929756727 276602443397748126 447702059134902279
928581600436495741 223931165877374637 984796665268411402
182323030848498036 271317326821805722 140159501947222327
393357477071989228 248469206274534732 771946466602191408
390167642635420586 743645078508552249 155807382896853114
426685324272965706 824925580653045926 135497921562391983
78684339856372697 727624612506359808 806505361796983261
51228339254975841 626554158533631672 379327514395514368
296615329302135496 775575658692689198 511635044632525141
498119885603875600 527145567244626708 314525402453644369
263139823634188128 253737313920379519 959089625361983772
165412036135399920 908660855877997190 303115991884357826
667082121935123582 754509220149205842 472204445456282859
230105107714105797 253309238713346162 302655671415800510
767869317084361616 917044091083483047 748805061768529532
98662063732231615 394412147059157248 798900734721442053
592600139276372175 354750293067628465 558828067461271454
534614683585053888 817713268656946253 541522639848045723
861607023721617083 97744434174369125 456143305889826328
696551144349768085 703389234327181768 336413327136310808
573338767966895334 244239314211631098 113131620114074291
362500696278635732 685037785851025525 400556662156948227
499522806131411079 48943362700059843 21035152463428284
259133961324771966 447267166258310623 370301510778620104
225018696066606741 319706245544746268 581925889717088112
307349101096766991 109036865488946742 731698855613340407
411716541146679940 647727376914891151 127029921760188457
350303192013767525 829392484576137904 639523545118237953
416319645007459345 988921045610563009 384345776566146987
337858233987507136 8504398120626819 401630438335854215
174556018855485964 61009155471006879 215824378292213584
750307931086580366 788192508251980920 325765020591099580
495049584358640669 532150366076780723 334790236503399819
966498713844871039 982524304039758385 538862844454478710
508027622127263932 56836763203536686 859101980619186401
363068462229457823 738349404188810462 429922598251699097
208303400262409221 636395805299217039 678879809070322313
679216910730816115 515743258293387935 731490488433890543
675985445112027828 83501027812324327 150072921508259126
645739670231983379 636540894293794094 761297200995734805
748972120872811636 9873122100874632 721828321772607237
327403384561742483 212734176669144969 870853059904971666
827483418121187630 586958276732105456 284595271326571200
226171446427494808 551144623797118712 298315464651344162
818710415581810171 490255590402392511 668427855673506922
583033645710675730 263698171166472998 493373151137001585
978765238496101618 925764261632569398 897076146558819530
345388545219931820 436325937106909655 5597266534392799
923342118373661824 733282354714954943 771405751084146864
898629497744570320 238828244216865142 406218801796867236
417115788765823441 135539002542828245 150233116528045795
569560083843882102 879922092830994193 285460063044114213
260337855499784882 581085353252092182 132909867664415206
371133693116640475 49067162693280690 773546687761023144
672110011484371528 253058977812806816 682632961081938047
843631137039985884 604517687524033760 760218607783612936
973099510293151123 271770089128439228 657497486103458238
984223919346834947 960700959802225687 773527006352997362
166465372520436416 534975242255970720 770328572286869585
401163939370253158 13284710873627175 551954144976767039
465287025449967615 74819758556966307 753680782163620074
432339073412424258 177319555551912213 266306025023501429
4218519052778859 112116251456368520 969575528248299512
440064838752396388 352296410353220051 792740482717125066
523069022923855414 454993643910637347 887358007054088888
219961382339280718 618520454425323758 722738016880258577
7867953472488794 598166190130539840 723017360947324759
949429555937473737 112716004187002486 148008891888953928
194317626921584939 514632930033767327 45727439924443272
809861689683853563 997064123463933259 973812723342680598
586023628483062360 58770710883105388 711539364259846182
245332180228745556 401942872298018212 799046631128365216
20239365220594242 110433242848913121 852684104791610702
521517507857473782 86645976123168419 171912863423831742
417104488632585280 406254106368349931 668432196307411331
270472116613987922 27593308705393543 838246958969652825
303708724977299096 571961149102509725 187396613222353191
109818469892144643 882191031292475323 559454801600001752
941579254550816356 279741154703301181 102860714703094594
865325646000344818 639536550228051558 481853731988258617
773263388798886584 479313900779454993 377219611860399254
521583203805012899 331508268860293408 823090691261055238
705841531482299210 130445138786183972 438459548092465571
204511089731503331 710196003713698317 119914612100780226
160109546696601076 764489512738595163 494551552698469465
120757105664418191 760101585137415388 772836039064856435
770514021245243384 588257308915451656 608087960371533755
762890576117865333 36046966339789208 66652724614589946
880250599204496679 64457416262554811 623031392960262948
380851741687253408 853249009135404844 220376553341343635
612857515406891406 300405842103828432 721733761285135521
676779557086895118 554615000163571994 702028420617753145
746522769053982190 443992095388888338 829575538063570699
964488385517956747 625925664778690503 275802818008428251
76751524713915416 950229740403449134 980425892552222087
894992649626056052 547571462109984492 671352785598545794
537212242008146876 929242880994224969 592256037773948562
893976194213158535 354545509154247350 207278071630301066
652885631675495732 942975323832781134 481362783959953646
84650267077825740 286256315318155845 368150419378078591
168326034248632163 495177586185436481 133014255833236438
350164067082138363 831296641570481166 227186729740644379
536860319372690072 227563250317519176 748251677681612366
874402595597490597 200276954864998451 965873068396824778
951991911594465017 527643822224277576 184347761603028081
859097586692047562 196641574041297982 18108155936469172
266106136737854586 823229518549516483 263984061506030154
67936407390615378 374968772037822667 481720458113882289
544374519321564699 667247101502818567 628416698776947578
964296351010413007 255550958992782545 694688788185356331
603724305738797908 464412914207371530 787797673922975627
699264334874557963 116749196055266918 331478296248782796
379338914491599254 744655981556763742 785220577647338024
530556351928373297 855859407638404559 387219372343316780
780031959036908971 410408650148891276 397657352668946507
572105682301998954 193778712466763666 648876315744302803
385723875240146873 987326698925710052 848483810534912917
944522300534306660 758325444943141457 419123758556414768
976546870050429468 21478743755825549 640237758916176993
834130901329552896 442520945451144953 703295724961048599
571280511768538844 952762837948553671 809347650041966543
171528168891798963 904065285116755373 557416552372000800
971696845301621385 439536089120298905 198189915687312994
235086597198884969 393006110933670899 476428536391849945
423720143027396267 658319693450660392 904530511541894696
43333411108399130 67325108337197746 833056727841748899
213961721078576923 927822288639015905 531736080126231494
324034059829762114 119931954694907664 163533019180757785
234438137534586563 427929584070609716 971055756836902673
176734327185093833 558059118023733911 704825515351978445
536054920115044252 506282851024492871 269413048933805767
532732119850697248 281819769323101925 873600859038147826
37983392306287091 84961762661706098 985499271010246537
430409321039467162 491864436055947337 252926091173838511
374409999100759786 223763626245205499 945980277988833803
375820132018717968 3602403649577913 115799315809386056
108070555586976256 990980627791478375 553803698979411098
613575811883008169 330845800972108839 80978486728019404
546823981048757858 99832271271310008 193286486888242151
407927806622771726 186135559194860245 21365002471419153
438784977160903399 326494016604971026 909300971633526516
719145372403387828 236766703779397442 271167428648314268
68917051581716893 487758358462313110 98520515311028782
728209163740478341 933704032548784653 330902672508896291
602553176052977287 549677587351363686 862238422387615300
311533610227109821 417311025643491101 950395061472465673
588485376658381213 888584444901061180 437719745644457328
7931398101378290 496777904339338063 156026070681424493
259467234034460683 126234029061643463 416659711225306333
241293494857018236 439559019266238730 47990498916526325
972612418447011999 374986134415058855 731541892960789650
276253505267966494 210010544226164791 704209645439912589
975669082940983165 971949033113853321 780650954083740619
980839796115453340 49806754591788974 228224823153501520
179714018514256238 549067241314162774 397161849397083864
213827080965934403 444726950904609396 706713767646723381
654258809670813038 268766521272791829 455941107993733454
404787010555429967 130327646101628035 58345613258292872
270569229439729257 282282591987818178 142379385604367986
82282324551656886 10361956223570595 435027420104711516
418499340973543740 135324703912502191 614407538960630218
731443028389351140 620102491005528354 487431779639688875
216610294407386399 100184064337473218 154546252777784082
909579899393285837 230123950226570721 857474182944465778
390560813430597417 961737298924795023 127561359988170686
388934114992868602 3222108639150913 658153378845617969
629793262538369872 912351695763104643 888705066818645359
216939869367763798 780956915700500650 678949920134325706
987630019627923035 714703205983814000 192921477199368673
725104342583351176 790033716104629256 604234385902615608
142156196293401963 696703756353998884 986715994641198102
956528710893633348 175023394990184623 193853072587757834
536057246063912552 809788641973392779 699084712143532702
156136177311833163 965384188921704326 360581500174114765
219928464645101077 640505974064538349 292405043447776052
819816802536684307 414949911342625866 333080615310123957
669667635648960230 248791613772756814 41978465393516435
448271818217513306 736792721884716100 375202729467190706
792690226150143389 766902721044027690 773489603809858492
533535797189035860 686519191430158875 889976272626106775
730491299311267540 156049293535069075 368412551739752719
511189062274095265 34159026455446223 408287231920787111
794440921305188779 253479435923540787 978774005959747674
960001672451323734 628773778572065822 203284236855286118
529926993338016156 526217309247701860 567444911315920138
315549934210487394 719614849812108232 372920506383180537
122711121580478668 762107156781733004 234294641519547874
938734837746279236 425187429322413403 916357061919741286
844401177985639858 179483393266365922 514450321290464108
579134106015212616 752745443780529206 741175577729249286
501665351482171157 737156528579195613 61376779508502030
283660349967998614 10933286398991642 965788551597961702
40061456158837236 628130735573928120 218558689954675122
397075529934207870 913758733734340394 416708628367639074
260927665332610773 908769910140571073 79304031480796155
779356852858457586 27528707581836002 172393889197561150
516823173820175469 863529075185078475 501313254448178938
489324137314862949 724306121184895088 736734924669359013
383071682355428756 122384776776256836 224034271661691551
741204648644318735 778159252715424008 41727235834838451
859965374801995429 233099656241328361 789031213992718836
578449450129926162 412255133735962550 481684078294649022
103888760367461840 676170400490008248 90455695308615475
344367728375983464 671385829226066267 72324800444044028
41364982858750675 524785014615221088 292647193437898691
378863875901285387 147490703344844580 1176429567556262
176312374298397715 685266132703403234 528616893540583828
677775755870921992 879214505188636019 484461275740233779
64136119293749658 951424796025242228 905466874466969386
518599716089674581 960122132245885853 84898121691529245
531262285139153603 862577993880149876 435745851179161066
696040647553899738 860441015282158195 752209911622509585
695032500228070731 625517219596087635 357838942910255871
512670942510818965 189895093464076074 953232568371552795
130072722073755489 142343585670769226 436395032926518492
161040417200997052 193210845730028010 865854270515232439
3468918285602357 622345330339161205 326454206149523087
183031621359482440 538347249150958567 503278302943540350
300759848539927930 959676781457845432 175092316712196662
761409368852130469 262307569403032966 133687116515401120
719032979954586427 19243261868591075 790770669863040707
998394638447299284 749837981917327774 379782652564317353
331893537221389571 299208174976021268 633725254546444173
99527625302901312 354777251358201974 378504230400055856
662497388834126777 442525055554939160 711328255047341765
180329306034182740 800069324581519200 255684635754708861
902275784471366209 992458251718586585 252945541874672221
696988649452994820 384799545524225512 197453451754895366
934784140654312570 193569642467740015 313248703035644456
432665090020981195 39778538948256834 600385036945434437
565748229183957794 621819589317536217 564198048935308598
431830086385286714 275130119234918229 178527181530591351
275206553763706481 668067939990092207 661309616738725418
851701897651946722 300826371390490916 669231020963303230
627852478829016639 713817248287856547 92607300843095841
627551625294385463 315963636310098971 363154324410518891
945748141163964723 749909587939545380 102955738484465799
170155105527810365 638943572002573781 224962961143288369
41876745020407609 977423681773176601 573550495559456631
639372411538541512 609264407764976936 503509094805407347
714609097141082945 237919256047500312 937448997647834903
956317641533605042 157244445688979287 784412882913790559
250738687892203584 338998506484238265 88120442703374704
870349616504207786 715733745868710023 648140359069687130
237129504163670847 962951163055911745 478372296077053137
213332364102462352 722130360973848833 879427643587874187
147226408926266201 679772796027834226 70815771520610325
448620966656197846 700266229930142883 341304132808957476
938759628051616597 68111339612474743 961148465619617355
762781376678634681 79588882114153925 367435360068878582
332091312297682283 36296415596402413 304234328135675177
716937331990197455 249651712604762371 751523258311429501
581678159495019628 838556289753866435 185922176924789913
933432525578360027 727761030117963332 207039079223874921
895070645691110042 253337031019137908 239113690290653056
375983798573040305 832064088536727278 551516779366355010
626358443171488176 481915827098685010 202916414135298407
201289180571959645 239606984458657177 490464148580629100
190981349922107468 981506939457489540 38613442592693203
60853407300219628 268011430913295219 344353431388102812
466428506282778838 688719413424864251 504542344972607094
165404007387116480 752433252574701436 828891380598782997
760819046832252669 205978505844159921 255499571912238120
262523405594742790 138175146663606448 406255730681829401
716431685775028462 723800124537508517 975879914088633660
850806715940509650 179061035743507255 200086124658170995
214150170586676355 207920734342619572 539047471267835076
818287683623276091 419549169949448935 14868629935604854
755211209065081210 321840504142891585 636261671985465983
108321118363080092 648369732644178494 563159124284166891
404531012790572431 773365804694288392 29612560882184028
466679704242567466 28103304964294943 932197490156286565
357666363569402657 990852479546858241 580941957706454883
509828317369210293 727534809839285318 776925813586735653
54907400161528372 969349136491492300 120267044487622789
912229991115649586 741240724980467137 287309400732020478
686153476527994734 973149870112053950 299354320236864244
182083374763260619 691584866377155904 226999954228389453
706552500108701036 885259270224909455 536450737981936393
246757699177621015 374387650958510450 762655171764712032
876321191160151531 855794733310613963 545955075874628814
925676182605622848 285698828373730959 384063576496312516
8508638803960676 359048657582801606 301262729171605662
799869138745246105 744010865514156658 302754935391187988
91178562298360788 628082732116291247 225065514581453145
596510592329468477 314603119290032166 54112710036273014
261828725871331438 950487812898051496 61257381118176582
735112491457380516 544415896431752632 923755196859386358
814192955850449691 784467838461514088 200619357342081206
417391903125926021 108515993017661549 953320518726364636
189297845362852109 725193369981856478 776129762468698467
965537163085709719 196888915003950332 510414352240821567
417208601382354396 494293434224417322 367611606281998273
755282716806666514 333455534465208364 211050583832867202
512005490551343160 476506828189663112 869134992195117914
980893411306621091 896516900007868255 993642275715847160
565162701203880418 567205864300319201 451123248774137462
509747831243676660 464846261178183385 710273905776983609
71113176063835697 355424877988227737 810849726510441963
159585354460564544 975865116027107318 157848471230018728
801207227370511934 41944600235290035 862052969771960838
883610687083408117 434266252895356056 517619043709247090
663255191779046637 969127539598845092 188316940000472811
569766933699328911 495911442719006614 511762146896378201
224340999702735540 251809160028599760 951925394738482609
15185469308492682 267810399059498041 271369833191138889
365160363645797248 383162388208757127 925170193669178983
112788172748130876 470972077286025454 227050269654384610
817954953913567042 239413977657216604 129873885682621305
749686106455756656 581152937796374504 545352504849668904
41482662469445927 134948778467858345 219153364381368066
952843911073809954 299562926046473071 853100321982558521
220276128001877420 633100676221668220 564773224909384225
611367983454178893 499612460757111083 671989200558022705
738268755328810502 848041372635940066 526642650699371788
882582138804550708 429521379462699163 227004627426316684
128741182712285204 384438324303556291 719935873219171162
474487637116134874 365176556791576610 808803983095965285
911315846545710105 309749594096144856 839095055746513052
826761564898927444 331215066411625348 840772066636717706
430098975025971472 811388640816773630 783129641681308556
155747148957857890 766471025740651405 264955378306491765
122959239636758022 192669296987859403 950231634704393016
440680590639507996 549683075660010257 286567679664334245
310869200883585746 517350606532478961 637366315557175220
588357502860304823 531503565150872358 747210571023465775
275683095449830435 150827088455795022 405823929165183406
241677063147624640 574564695230337688 150678720162172834
893288862026491593 320021629949320400 536157722188703094
261157879724853854 802747996138599573 204508215932498223
177859043445257731 498097215517047836 578505820817474875
187702821353137645 220743499880694499 829685570104567543
338376365467812186 890898502155863491 296368435291727490
326362539243896572 88369282509067984 986352506550204584
676370870809869733 452985824670954657 277260210750654185
427055661784495682 102655654424681947 99191118735855443
229575934449960233 73491332931815529 978454548717656068
745479355005183363 445314294729989544 748789203255567149
91426759265162113 650685363058826018 263600596132031431
219254386256878087 927775974236556574 182581996753749669
922683306398999104 900703401814727338 24796130464788758
286698085206021339 359131825529072830 476848200915056719
550990871982651172 566814397109169421 127407534042039706
238311352486204916 704661505134730466 76907377296813998
561674075233441894 898457459238604051 402372470893604991
484894548542801079 986618302061851751 833850876354798547
63340061069670979 198230155166224160 185861977284907981
985741324232809202 423426985150771941 707014447200966325
544000051152527442 829174149835710149 633525466448405602
671997962871690390 379657175581523235 556413719185092453
411642823612769805 710891481543794641 142603841998095551
825109351305181888 829269064375848765 268595187101196205
627260145931042570 995032142363381273 107774302008860210
525535323846326189 791828640692867274 340924654948883750
647996756077341322 598240772115473575 569018589919317638
60288883808674687 14728323341192099 752266542293671127
217458934047232505 486807427608314300 711553327040332441
773661568523017833 895561567309074257 338491650786167050
694847302925278508 973870290323252572 973205041789361823
951835161947509208 519766630647748717 172998004870779390
842750831211824752 697269685902363142 98446551054684951
197666423527088000 466047235553597008 110910897661858715
764551429592813563 143985309344279128 91781322808496427
271285536790448346 869455681375667920 503369571091212266
302123630672416359 433926345264894058 380301275928668063
272130653541336036 602913904872700543 155918600429077820
824892257234949154 934344930138136949 273942653589035726
784549375341876235 297605150347145014 79784427689065054
293064430537396025 202415981466126925 786925009465331068
641420767126732885 996191870527681202 617309404908828831
204295937007557598 486400782131832709 159819119918066132
266472063240086861 988243668393055786 132370211203334412
10897898906108211 411445103163166445 359776826308808050
614430280016782731 684316454772612117 578760470850879171
270950248701607604 14102063779245955 794600440846627501
212579095834307376 753699906277213678 923583805253607664
555703248930925164 194310199312569594 773984569095599813
15777428514223300 93860385286027636 290464247955382625
813127052087946403 400455848757278545 891117505498444784
761562544374444323 336299691542730305 714312558304654932
333583049883164156 392049876076455898 170720026418756788
429216930644393919 794517658255610873 57528171840026685
810040762462713678 829368911568563648 898303369345301415
723270257327042686 720060824251475929 800211087753460013
948437567819733653 765556149325739225 679945881230244173
63984210410626087 582128527319973031 202679094726625753
641944672301100561 618186786422408300 954687927554271889
101016255273463580 701740546969616076 817338955378136573
233558923432947820 366989892672473496 817026877204482200
724160351768067459 201108692001895425 561417004744646226
722732308185189301 335069796349137627 670513124949515162
612835117594549422 879511533994719723 861446265604590499
289926214953141295 930558979722901772 40344041073480999
892824711276887465 420508862654728232 825762702561220428
517293235053419982 1833550711386472 444589650223601067
555845254348834093 778537769969488239 523793795072033942
908001774496765243 627909745979507950 313177901499906351
622772208723909768 776521777340145721 740202501830895547
942700342864480313 873072175657986292 198705527066281804
355588914627016768 47187272387758677 406582106059322903
461505568374352114 481724930035725590 373822244139213409
46857787992461172 321557402588469246 716425270020086592
940211981487544508 997954827481772611 435687957461668376
704993495746429132 523646398217484793 341839416400105469
219722822791759420 519081099364957993 583727375388607781
455702791339974827 932375864266189622 158752347228597688
85979674687400549 334463722224305573 622756748315715123
823868845639117914 530662783165192580 763572273621187586
964431773525541158 948604756728544744 495318904814657606
242821646089477863 406837920414036314 934674774305419939
244056787662117146 754272671218793035 705826640256314864
607956693097341627 589089746662238581 470550418432404824
889787473017755231 340084688313710821 96786931477188708
849271906362367195 21402641809402079 287556217955749053
716103909402789125 379388364761462246 909589957219174685
721635542957329749 847552728508441882 844961777003348013
380205754804278916 131798922718034884 316079261706957667
821813117339959473 287722080327750350 185166017650783608
440993909056644676 47919729753861126 470219009619712165
916973374651158241 651490748991292971 879062782410156316
828505837169844702 39525156948311539 72645329167653911
952137416388453234 681078073276784209 418279010211107956
871190126437330995 150331991388450252 716896837896526338
508672640608701117 74460069502425112 159604830214337711
831030026071749586 522360585771653651 581888367650706835
777337011884343472 77610607855625233 780556522631685909
513520297338537212 221597883632945466 586519148293558978
717133287384775810 175717143194622906 821495560520554214
276195420983869007 624208426848621932 671353446155843267
490372181148677616 338974566103658982 906864372689188839
595137383975581996 119485429187229905 687221105866132506
229199106333548404 14671232580319908 737737658357648064
258637372359120202 603644412520363922 587424411836220897
846113613052301841 218041867250869794 791044847114282528
883379060638902055 987485786863788790 571804181121064500
34203229383386640 219472715926719197 192062165920268699
361384329055169113 885021650119422385 118359435278625794
386922471697282322 393010735024446275 591169432757796159
519511229778465422 890616570535946631 814461757127855082
880523816560116107 243190888758190640 633256689850688229
110450838969129011 958042174971410575 38676400583016258
241878695795041086 476157288696028264 247015690292517880
371087448185915754 917259616867233303 650816021480765761
490348952645122493 238304451791641446 735549390244167174
229738796466659399 215100672548140230 252029332051136747
215502621295055676 271189394027851258 676899266930246698
669056022820637155 937208375699779380 232169506310476372
105061443991298415 461033215170821358 1022296766458671
153789334553971515 119511422582638399 612170475593570783
765050533332606698 603367315068481288 441165220785995733
682244546172091444 430112400606811849 878672359177357074
458156232990262159 882273007437950386 534788522023361178
591609199320283667 368927843608143692 686921361323243721
755298798728561662 604026934595569363 97483994728176383
161798014931323664 38699564608185583 896037600045403759
134570568531048511 31777058793678823 752070366653005362
629829277571936020 966379097770827952 783257122706418387
537891234139096542 265136108238663255 43238321002458233
534747515604654609 126337199014575589 6528009198711730
325038138134440174 875436349124905248 949556079057214083
612962762165408552 445022549626103539 298349636409887519
179053589028665567 817187614238468025 397003154714663277
30331588546131296 902642717637043554 626819477099937201
881816920279909351 356641738475139585 702260322558554690
259691030031027585 930121131139234039 369173524216390212
682607674062118421 974248923496826338 641550386032175308
956361528924131595 812691179013573191 885977451396720280
491246320397533107 872200564118844821 776409107583041939
567514956355955429 591720366979961966 297494916789863868
374002704328101514 513229591023895520 5124537571940502
96836698323444230 584447183020483381 150456501556571843
578909658051926239 686386980328589772 552300568570778981
686298903993121129 43167054018234264 112861413886293726
463397032225811589 868375551228041472 988668255494196839
366080345378722848 433236498870811269 621578081634050774
706252098308842050 556088734565313728 492059132493568975
974283563152997812 659944510380897713 364981542811493065
261499120875246025 448871434225434738 447802751245384575
105289369937016222 713079517797723458 553972964993917070
524308554783013169 228182534891575397 666546424048208136
557640937703108744 100202754882578806 777521126037625002
931146436937012314 72439659325484679 674294153101684398
481195364532343991 24457539648187747 180414604838249151
906523560581158275 39501946410500681 826287372730321861
190569798413241837 331955048485906232 186248191046632658
978526409827810082 97576070972483562 40240049346169941
522341409990612012 123010063054005632 5980465995886118
454683069950574346 171119962859991798 690267569326632414
92673632519832107 487941749699497419 422069208103515453
208325044838390454 345868377264134154 92031594944310696
28316857555654333 707025181919891568 980417760800928994
774728596512234760 410637656116978091 89857427347971046
777769969562566021 710455663359628769 553001997829530866
383802782852320487 867938361197089971 858034733962722018
897308650634332627 998374627378140589 446027675493982107
336494321098144926 296180590350849891 163831287466746294
801870701576525719 81795144231925815 266682053973422455
65969941697418847 541471013722105362 826400367159097384
76604116572873768 576788212825554350 640365070622397353
517481310945171587 652440200417411628 407878553318939754
581009202960843989 824664025716664147 666051526586524494
438245543929779333 246202411942551631 462553806201548567
293576348351967982 804300087751006121 715408547458778547
927964158167077184 39196115968822910 581385735369828771
992706284080829427 648305310013075631 693887876617237505
44200700298720009 37265494486826948 612994969422163000
513120748339249298 664920527378899878 331369715281508928
431910323545008437 398175152976395991 577353376202400998
510912532103702355 815430953753275864 998960494572275106
350979313996225650 566785113713681452 169996384688983009
954085230749607480 260699799694802616 301128401738669536
719568646783916783 279406059219135243 318417622643241266
100394662154434516 206842351951069996 587946864120227354
927807717552979263 148367509438661187 802774165318506396
642755400460537708 247658144143643212 486605363255197873
514601459088012214 750922138479646867 977786712562663558
292381811623900967 956788085448602280 772275590011949923
981700417255718765 145892115054988721 10914148047998350
447579695966442465 427517710769545721 467486797765528624
911812034053326292 368495907830922075 423916883031407093
727119305873496588 911864171576314726 754717029797957055
318521314166594853 468451367104985229 894122926503361365
459623249796748370 503087020790139775 449122494861593954
706980500813164086 524741278309339127 703390054873490900
328369624254217539 64632244044584634 978019011813669817
443851804541105253 228205853017790042 390847720325230638
711899947153809276 894401058306161951 810183571447909053
928613965317749993 283680711959638575 528461408885254748
354538464871447282 633762075672941788 173710979150531736
70452205241827657 523286811017285750 583011968283116551
836638615107218336 998693567742584923 54325741886859343
165157267876378873 315381422177403614 454172845273677282
813833369808227674 219408490081534825 27392049105231648
44706800834559621 910100739544580862 643729384633475716
443545412509882625 610760385959623609 641482641768636279
766597007508906912 504173220725970727 787976687216321097
47695381724346018 625078496654512302 884635090034974987
481868314706858196 441972042477147172 649522201611611803
799922813671391564 481654702838791759 242204835186787891
76086514510400512 36713815532746821 520458345970528386
555865713647106031 734168902021685108 752358740475838084
447183800535351948 793074879069363177 328651012742608435
468515460868446008 385348781664811868 855253525273962159
356035972703531653 248568586987074273 912080180898575402
953008230514268472 746704295124245060 272252590365925788
66545722020384544 526714412731751290 113463085370602853
952449076718425553 985913258352835993 681692956623038164
940707369370303606 289111429249758851 491078739479189219
370864445500997800 392224686616844028 41248796910813694
221195462157008517 131083131504641206 319070566218836541
259402839434264625 442694209077140202 848257472869859276
20857025421752167 241920377946948936 54643945157696467
244921086755133965 625051865224743511 564368969728214044
786697706247065806 67016852260098491 411446517909043188
550807266403299530 953491436219748281 374057134472562006
93991077080378563 96092296751510297 328124622052600658
223768167939427971 69822829215714127 666265759794292986
77830899035765149 18802255864376383 491116888070118081
341865685251782951 576332477794986627 517961180098411915
249243919560607048 363153961266017654 661636795074162231
94695646945708996 936238836178396865 810459571370872205
792275847299967925 790045487249909073 329017614074293008
983033489809117480 758505743811577705 891352554051373068
717131027094715542 828214751725109961 107079864218728819
47833391048858555 314181338696909553 444305930051090981
389817396784133222 838972185290538138 960186254506471728
901175380841223849 796022807062518668 200292850992960991
755882429091734671 781187927512236519 129672289438534033
204089466859752478 951136741651632843 942644386243543596
778345823199471362 206778540921800905 120921034134789377
329249438477799596 770720207209820302 32850185497114854
727317906434230686 815314272548326960 143360030655227336
920111159708817842 262713863796536167 190230753010718864
6449167318731547 835263941156033597 706438945477414016
428866989606121628 469788272954741250 817296743747617464
496358850287333428 597784521417966959 731877151987823682
685339248764468944 603557025317754256 837987704640957201
240918214468456126 745535555794059375 329195318273921486
204557250692587710 617686346150038450 690992881267608544
303299625736858336 876704751093082010 156939738089495898
641272065598582953 243838681519340001 85176634129852702
245937914327992416 841713998881544159 812887772542332305
614718680729140836 222344723719807645 234474227962789188
139867892395336324 565035122080712837 221161135828555922
188590485463784055 196689382891401591 343503088863232439
30994176428271246 494892450576430128 92557163945633311
756768339169354122 83457924016909552 171118994935281938
35766188099773718 385040465136539238 308563169540196853
427005913357578839 52724535764971573 372959885086764345
539620201443544181 484557221697177483 331682565221063373
217988168726072387 551658801189834055 590827761486707409
927488347254204526 50896873118415594 378056252767908589
977136903552103706 945733518645881969 44602493844399350
364498221632946187 209593909754738832 243650814288913783
654070017396117699 318413383952344573 794933584935335752
568443621850855476 707837376449256882 694472077680191320
709656966989396399 951342993280137658 156857185907282619
827922854220565097 727377011382654195 734055164568029726
967695196718775549 399817850283498396 566028618520654238
528996706291203823 290252010934148629 888541339376091186
119264612461437460 105151994562256281 339497609007786687
483408631471609984 972603171175483664 816131340877161992
447620681896450379 546707393109209766 650062703468089353
543381626096954661 298894698826514459 747261595971816682
336700998356676069 270275306408396613 49099316878738456
21070363500128322 771315316675902808 256511357252944549
163696368229570401 814895793420200687 529121025253008218
346902897326436873 659258133585676161 670918073812161231
982434761640265170 341061176186717990 206585440036363318
94047360603551748 817546942242542039 305948913481465109
681873455682618813 18173727368945492 132152044099474044
166649261248746239 209195482873502576 142394240667524296
239206033747826437 989188172827203168 974515482021669446
854234683602257428 218051748759923114 405770346771299781
942834378533229363 493276073471751457 165335152305575379
707100375591932698 818478961184733656 332373033512770200
813039472759111392 340781249438576211 727906582303703774
122259187117482037 328875108832429679 147124715405918145
868566752673555069 592493091252509595 309364202351657720
183035491265522353 179349437148134152 573798902455160942
892657743175976514 637911664218058741 800055591267126117
750187377108386591 614217848951043066 647627399097526336
997986046736264590 860070693274819430 771076886007949314
485489354473000639 761831527599564052 855316281405150849
652476481506077993 693977714827041679 313772332078677391
539536402001758723 404541841301537679 241822902660820557
421802748801546558 284435574078699050 465198888948660007
947175003059718269 499270931181391718 815863172549797996
684182053518132774 223021653448415251 878519289318030057
519217773889973750 902178029640603560 321990966835548689
337295184138590391 676447462463362573 964996146762007075
622150300486900939 943305092936996432 88038547989447898
490825895422583246 752797808713714336 859718144134295638
405987507747624325 796135599820652352 729885762098750562
572006151380566260 894327899414072605 452302054713968088
269503693996852173 566099676996771433 882670590533033149
35062389068483166 305476947644005902 222114048658917770
299846876574020679 718620334856790368 178489174219038299
961160826080209985 497592766931543253 585956939561076155
233283705166688334 196170634533562383 605848322066813732
299609512935100198 829069393385773681 497724217274135681
46547164917561911 370685626308196527 12526189690210511
688783135020436932 444527764254866869 592356977444943677
920451894214403931 922579818149180173 46484620360109186
161018029513793534 699998511795432585 773445723312502058
675641283662009144 243116727864221425 547912750083797932
180673110283146492 437468725779512983 385577572808523136
698784209073448871 647834500689555956 18894150392155696
116577269369010383 534150137001082175 795948359954647204
170510895561012910 35041374110574699 954297353046965672
538713879135109417 745523458453001330 20204161989358760
663897088748003616 729650405306092972 274490120260087321
497270862835735860 339000890886895941 430527661400987905
164852570858030839 841881670890138546 33079921921688815
929928130117222787 301643838462135673 292300022123379821
43602064152875520 224912897404625840 307738902397823103
226827210484416648 211603135113822422 844678126674407470
990419624702851528 869025316337220895 284205773450262723
422788432438506071 441677260009051097 319923208555036465
718948682660319617 12171873529279853 819282694684827002
832547795866303249 939650257878946682 763619964201485154
438849839350719346 990427696680805114 765469983066645217
779727422209799023 146607951798072 142479547206924765
988117484625577449 10015381353891036 912384639280575806
863604170133353945 626139141294885626 400787166659871637
941142250340070085 372455168291389281 825930423095828336
706857691745255513 339447438816457902 208562144965080499
497125496074313034 940154384535042640 433879590917954665
523563627873929964 518181056941833499 853541804096724899
441196287570601018 824445028508110029 108712800930796605
97297756637728843 984300635782035147 320921365051465315
418521576352511256 274383172346858015 236305279541755142
115612506010565774 253121875473975232 623999185576341424
598881732976113057 903779985643348009 841869052513588033
417152469864262335 543834429058931644 946818015299586175
756046579925568591 354700028825919167 281723699896163633
851696809713669592 323207916841300903 304878509942909801
121551794741846337 917388266074682333 981915177416262817
942437822956699406 719335774099889926 240308567346779198
442184136037807012 17608046765177158 409736911499264978
273679254753458456 456402438543113398 980690943826615642
673445137070057963 804278745116135286 322651525569216987
372207337790297278 651285530007428824 990721828586920415
864792865048902090 213311879981990312 232982364275358201
595166931783854805 547999842075209258 98122567668621680
459873257771057912 941722362955067192 673122986589948502
554634372799561528 641736068403587177 353639535145879783
987894093796587948 33525603677402687 141988596474660390
441944271918725439 584257823284221475 586754116208411794
905991680062553058 568028420423949199 124873714448541377
172114399752482142 161116792224928660 484225464380747647
17015744763227683 527522150575532928 424518416958797845
964527729333810134 551731223694985472 930400891054355490
651222763878218654 808412152388407466 304974426106748050
64796784017836290 992024718700286488 159340645213951302
56745066216807217 852291906107851777 850510277239255718
84874210983490805 981714749746937189 245932576763497553
775401112662160863 637773530033058231 727258333479921271
571064103198521251 954243888843592380 640029986879300615
707422059445568540 123732961746890286 935358886241971728
538919121103324579 318613259473329434 800825140666365609
107505220487030097 706401300749549510 202502632745976830
153802499473403022 360292904704239800 337807763395086774
993872162630343036 534612407534716565 496910752327575069
458650104630548326 605695677180944136 485282379413957997
716578431866471215 149864867144390599 543289946126866755
665290366486094342 754634095065049116 572149856151602034
322593788318319233 639288374171939878 160761519389055501
366004211320617715 470633427158255846 939972735092909439
806821473842017686 584250244353029868 138568201538875707
342519054668798230 910869618880446362 146892539983587788
752162029902778477 487088508456079293 716609516716689628
342026238327500817 523204473635181192 742517573577608044
125028387550184275 405701440289371675 981624261729858303
676901357496704908 999252432407597441 234456003587693818
396733566213313290 513164317506890605 684275014804620542
447895908867726565 104509901678239819 923006353270711517
478474282879511805 667750789779486686 847896626294246169
701437741338489498 285394766978479286 154162399834455049
870011579581959483 807559112334776034 941101273330487819
900313384718997068 610591083284168766 932315819489683929
899859683618194400 67958727123498157 725134105286575110
332289929674433557 336753044542005425 911778560019183870
705900995291936079 308440727969757488 159864585785029903
193212716394052413 530680520042542104 708905697143357993
950926050884334111 878172765663501323 530112499424426566
748783606089447422 173001520013224988 922870620080613204
748501891868705296 425493754400554524 990340433710524636
985626701702399659 297534485731867769 240145797376949462
494922149204540978 835745350484362205 65589106990143461
311849070013484051 813402227821215911 345803955029351270
753949026758645379 186526820968492431 295181011459981743
319142522860936955 853636448593802443 494932463346587528
973198421093129842 793561143543244803 691546111948922904
367928946875289401 153458806967033372 696284170334329368
360876793323715867 695927486931850042 3377923313180802
515641288595699084 198203879000899163 645546842328602160
229208085211667563 87461977872742869 849179563558292123
605510094833305879 86950860810628686 775393465717364789
271792402669695876 430086334893667843 1511671086315186
635858160334517784 556174640112892958 486299913587026517
799464750747207844 623890270043029390 983119326223281978
874870502470758790 243069560456783946 821791620876306943
605918172377662950 254629680785907556 241880233036093803
154586630736610910 440229688189738546 198791046579776211
579698127262514644 331385580751193082 263385977335890269
578915746100172806 132570544301917160 910089426941297320
455876205835254407 392913720663077685 165360420926776612
708588497667806629 81824179923147546 902313629586338971
706030925184128438 665698178542345088 636668969182878550
628124591645883751 634510089995445228 167320273115548975
891364964550711021 207107478218928449 112998191900982272
184563809764525480 426679335878263541 2707635016820466
461666642349004521 980194386993306279 37119425830301927
823550787527731416 675872890759978329 575999248587111125
665028202496518446 629711403992617826 895179090825783831
599169590117266435 761443123104421310 80514107415774101
627056113841249462 641518175614061063 215195468393675872
8661715862328721 293924512680147968 206105983791242472
949698931207031143 839925349249200893 774270366707820655
608788227841761174 698335550814022157 323852146160857506
521418005441142427 491838241855135306 945349375497811734
908940939622629836 601215461794941431 81202825235141904
268183874817093404 8068993527573738 218087710988527370
909937635547305554 651464253656793414 837896451112674295
426712352658191902 822620534262989112 790346511289231262
228140791075528207 716870591338298794 318463363557984359
29878955692249511 811017754976585413 602181655122631911
945998861076516 95480701735853794 609307339101830370
714200485955661362 116182378246024505 394385356480325939
323181034383925431 661869262311111060 713557446609660700
216598497324031864 907061180049044117 890992797658689552
621156438159933811 549911031533757111 232616130213140658
689011807783273287 12234886460795248 502760478810397594
304896245750111247 386350784699139534 970241115567006225
364519875885980159 298437013206383788 211465131483743062
259092735278275865 786520241758531591 976918679343641010
566381575972425994 154423714005038273 217516364207398017
510641921636601888 678195857797253113 374118204830706279
801462391724846443 872636415367934279 163715439270481857
521743147497829631 58496783585276537 756960581414463827
268782293701130448 210546236619054976 606048579222814627
93592157737766330 67895054432380710 584321466857731980
333313614745747323 117714755393358804 537553190664293309
347352765386921429 940863273768505143 422580391955936174
574208728759106140 44360196132557370 127420728276662378
33430981024848275 981071772712292282 529428166917927525
366774198286279478 44361610391886105 321788618829411514
140764647070840000 113347566155496751 817740789251843310
433225586003373397 466197842269862651 219656099325586516
240026207492067916 43521383484417826 300810666411621469
104152384991970668 863003770942436174 872756932071577521
783527614498080882 3163340097966734 831017089283948934
123970737426836288 113817030429972865 416743991325845924
104726424182626437 961524348887548705 790402389164226304
452613072011776769 647566453833809977 293252579614426151
345717815211360178 660892542800021411 854269222557037893
99386916375508476 697939213068455969 689556098936336156
267815503003725310 906767813734252264 812756233752881818
656339449105949443 208762489250436339 577397587531880463
363808891826889121 701066598050596386 977144847661809777
544582557444958895 698995369129200703 842024338928427811
8875342466737261 871188388982613119 719715549927203808
576384538919971356 365409068433534321 979984436318073885
695506657382645449 793439977202032727 952216446422862503
456139003700781230 668491996970309271 738227008050816178
784153154370657731 275448901579221689 354159298968636642
201148962336074769 840851298149100489 763805753057597528
40093226590767045 698318038874199099 190908380936319900
784361531717070704 76374347796426884 797879532313773568
968650443620930674 226979578632241279 24122791817609693
997538067382797395 798375690247749845 83926504661444294
181673499481891062 951289240771040930 968665954569008461
507404774586804384 979144511237974644 871936192590336638
292579740773313715 765428084680551942 569466710796202786
953198824056920436 740332244107889209 328882306809418090
256578024179359195 385121422694375454 70241604249720292
665481242910688750 119245713147226461 578047286512966143
200458510825056591 209443364583919087 114569968696193918
589626931236321149 885828629480591162 746152379911570936
125292348067383304 19639106592085654 898107671296284929
662037257394117687 959924117990882728 207042671275265621
670792185268304933 592528743517442855 42187976686704932
853408346511147204 159248555914925015 823116471137309697
478325648183562106 825549620916666376 334135209828028571
387517712900645534 398038789344948780 948175387640787625
24203307341182851 830688715116628793 466644735844500748
907951211593256831 776806870978524355 611443116967443490
800800450568829286 445689186316925413 921047445743977803
864313924773021040 699529526651349088 447235208166654049
443425639827249468 405440988397649821 134341985070439857
684213136053463797 595914964839974513 823492441500484078
567014042716303869 298692710782720459 841637670339070704
410679374572906746 280498428511810903 971781154884919164
26076687082319161 788014114178935240 127491045967455265
22541227747138054 694662769071524199 274715369826094536
61689325406726852 590740158534131757 181316147203158310
573368486584776391 692575317656434934 119713446828796373
767828688330397528 199706518149168051 980784469419008186
799252597328417677 559096361828631742 718655619653906269
556830191297188658 300182992841883923 773535205589778030
680946940135385876 784969866135695101 164728282639798240
604424430757117011 877250595972999448 80060191675817708
342587783168072097 253413474896408481 366691028232728346
785975187467552841 577419925739390636 126009194151467376
81792219489880266 369052353385515391 428718536820748444
333459140182782229 400583270904353346 362044613956208782
797446703217726641 143046615130102489 919118268796916369
642617154815480204 71536709592962672 887430144226389569
891585259114489400 411111992696669468 406097653039632889
120396122912935080 612477612513442236 94882298993350388
185226668176162489 581355004100544458 660740632008168440
83178558442921057 756291819188576716 861897122572277797
677182645276586208 869328758482971334 471127745545883759
637521280664232860 551303733400366009 973003444358530588
599543135072289448 276488947377116117 132056917844736464
51553480781471595 310744602541700514 599713754571259112
310299762298746078 641685616738329427 372620771271007818
5081281397052310 767899468662732193 702258822818486396
47531178184633281 676966740391588890 397490216728661563
986194923320170957 201965133269334121 396890709123036333
216418595524893401 907076636274594675 655449558428212957
439030557421759903 115022974267992662 614181397939856748
932840484400890015 642591382552020620 301574844218154148
176283226137051289 237551641062283301 711720752247607389
432116255661945947 140436161288047780 881913098116175811
359401430380677641 823481608714736937 141921493747550808
526332579662975000 338588532409035491 45100371564712521
926455283364349501 228798902666028701 735956065995308349
286178987601546516 594791461548890902 115741303546518560
984949465857788125 713277420327773027 965742106427180105
202049725572801347 346616292839853439 390700838549990971
894701002245931129 563199688226064114 193697055651319116
538677742740049953 913206629783995392 908933470502625539
817217076171138919 700604726469219253 14176019697892192
880245075880026236 920092878635483745 839765843237919292
986480740473429479 443108294606495838 193940117890467518
236493167833782771 50939610163286017 419164818716511720
668457361246284164 913721903839128755 626176434403235277
24417441153752879 293160541737109157 563933976119946878
472481008571454893 179631140082882977 341996694077868926
64396037731970000 427493174329731751 251571090314684534
966540775850144107 543869405044138044 67229178072499983
641815744810926927 669588359191824440 695735422148904186
364098592698164944 589559216134857870 937186622076096681
40942070263304715 644818266998001641 7913671366616813
545282684405661439 236047492730040250 17968158730856691
529452722619366707 360514924328213767 738000509320964054
368806202648353180 674910351698781708 830160697493653976
623768943789151789 233498716376123528 123502722035969817
476229274610514951 697671599901985979 211154244885962700
118107586784578388 874967853673795260 998084280388265527
35177030144380339 369873448576122935 126368288035563632
663062440344491821 121898401729786796 914872304983490611
17528608973354768 293859129668793984 91273876884868763
458236552560760277 939207640662325674 522253790031356758
956176296603560429 903347466279385926 561886422874352838
813255445360638627 704687989768932782 26666684742071060
291617329000437355 808223604057675194 415024219857043697
225940083754291361 293924030325353957 791421649788392405
184242544518329584 3537775660167567 361658108947014123
126810497661947292 708676042338300794 604806802160914470
852130367405649641 294201092858154904 84800858696703320
814430354709521895 133710538083026375 128992001760011495
131705607900412153 363621731100597769 978630033647747613
785206451763343732 982373965729435889 671093854947334146
988667846987264249 231907041382096075 452650987587101243
477546216343140838 10428750366304017 218543056113257549
561015051279424279 721554307162673926 712980753211713443
219459595601964493 312719328371239226 710158896162672239
287340744604932754 267236379875824158 484557449057048694
837114573257504093 349699873251054391 622458766872270737
453062660665655606 304503098963952054 36370281362122415
773715749861352533 242982551848814310 41806723162210469
125203576884400737 817584775926706456 910657149918160541
524289537077806334 885436301448016549 246771351971619712
245675070061024638 545118711463340492 630213241155307796
365426863498475670 44360418060332857 478533616721536198
444475585189401370 345946008932155242 196758206591939734
441985099495237866 90121458724892790 585312760839709563
483097627465767423 999794414608619737 185940041040927179
428535886662764341 83196381987382747 982433880493885805
738293206703810300 808048909671296641 459088543284977463
535165442518717495 206968839979132356 199985067010177327
316032195147615264 309937198109391353 409167657542156355
53533957487488402 676496520010858577 81289803964880169
270193031796929368 453373046044562161 839922762443422595
412902387789583686 612098225642560499 566725508782790678
851095978923406639 454696129330621465 337442423941767497
256516271323335011 91365115808519678 983677944863003694
675193793988471823 139176091207969398 645096802313402648
511589497916978887 420667938137526360 68984392756812890
499852096274833152 528346521744117866 989113980604929951
443628716217349305 343494077040238818 867412155471562613
379128123855321955 460868713224420427 227098460425081631
568880289841795749 618936607192592280 794634909716446550
763385130901600202 215220149478911863 177018395331394833
8707190352781898 141688561281581373 674081630343456973
865148241763314728 502630911411577879 345395593776211044
695005159030598986 83089395950059298 236424753760389304
632406522004962172 322092589766817287 234505310616042695
203724388517556703 663277508204132459 854064675801627853
323070941685729982 575895920472996667 77732675671910225
377479757986448075 799739648165091382 134206425443887368
801438062389739754 701810559794161407 993167507139254324
40325909132388003 436547367995051340 76350076020493506
74122041521935605 439344563823023655 193883585743573562
656720012437184276 659335579720624395 793655831915293020
251355628932716251 164287993247223408 120312847093668475
533177211413867422 741862825550631423 723248964477134393
487570863902433764 721448325960874669 854984852230732102
610156214340537059 741811329232930691 684432394625392669
811983816332572445 227960665617028023 868104709553586615
466599631235928986 358404510338888032 968143566676391292
783174545413825365 835091048814955940 363747893024841640
372036989569776861 226233058684869219 957019110848719307
898611394124378600 705950192838318362 799858221700284012
533648419031161205 824219306202187498 383360416331216457
813827345856786192 387198153143150120 383540694116545220
497353271066929153 800229749596930696 236329315413443613
46393799720031590 350145237195416529 88855760710075412
765480267868189902 805855652720034073 128663246311721894
145938398469456540 520168046727280987 346097468293771511
635208315557152894 614016542799671055 995762024922682661
906287073328992105 377749508381635763 530647523718023918
263266493845332029 687833969129426089 677944049987081900
14850324712416982 616044632761985495 750094368616482123
272365650191362855 177161217360900341 514315739916397307
268632570140260545 647491620325212137 599472626157228942
378030418218387659 597925538863501241 790928088108850736
337892050767750001 154776627652831010 65140867854381772
462008597366818075 345235423218622100 168149588129385244
820286385737969877 3467452985537608 956900182110911075
580978733982993783 661793113590117789 366085304814356035
136261146860585600 289269596250381620 295326408017793050
550964599894334237 977112858111674116 567963286913339904
90239914984589632 959179670391608010 558495594904591153
2134832733802172 417117426889787955 519220760916154290
528920230382035921 696923121429132285 45952039813534460
159257314546579767 311513415896823243 510730945171219082
999538634707288315 887275742829794864 212302695017890952
353471511091596782 600498051433047398 936086635319072606
104982786560040661 900445427687238587 654605628436101645
320371687729071652 279930751236711850 397442820689416266
112734945943792223 297410932997323602 840967335624908031
527687074861360838 992055602603273725 711304996643061480
427766824025504811 721820511793410226 605934642672410249
122549788897642172 509784041523616169 398571210645603285
589517925180601342 128476771066285644 684350365555056046
702582809142001894 314390344252268397 568644052097447168
993461631134844079 983118672269531612 923276336779507005
947217036246412555 989894297301854334 647730307043190760
35929194980014456 381078385088827718 81833366970717434
4340791620129334 536314987808816412 731841519950318391
895221888676891707 197323597351686660 361658880172546242
778532900858496461 538623444128269979 494502818071271890
663604936711829494 373823706397253173 462539455624472351
582025621506799801 233224068713974755 842097204521088380
529306167026816337 125324811151927184 772137037618352476
129734715359620535 649192928256831441 987378348420804733
755159080104116339 591160334803021189 132067495274471586
661385526415402022 739401120331205602 611168544215922507
288811246202487775 612441570073925735 488130848164037539
745755146700197845 78635734058332676 127252561242584711
651789761257310039 331026393527841977 286454297430071924
715595397668149773 720333282979481814 803610467557188325
472504790390074906 293577717168799478 596858670958649009
125838801877216538 341710708846402005 952997602143413939
349713581448045163 42076133509140711 426073450124633841
893402263981144129 622889334248555701 718220162116118428
395980186205849458 891708535232931606 50594510220955455
397272206428437916 807779195779526958 323031513951524237
906811470471990547 141401520722507927 393036495447223450
403693251169146674 907751328256884636 467725461145030320
659127710231890351 889352650344194894 267093928941606149
421771727787041002 224711997231627900 151148247620818782
708409852819533544 20754620727698903 396512637687010730
723664395237001616 533308078530377881 854988860028609505
261116148309847284 428374596151946057 865912034329267666
878882036504951811 455205099888657317 859259324301507485
363970217179377943 160946274310079501 897144611606862107
88076957753182679 295775972850799176 219581480101605739
675750604640131932 317956733133670388 830910474756760850
507876973964858192 775009669521794392 36515158779637037
869160649840090495 761496169255112131 715429981814433887
616979270173407319 16177957045846706 682724334772585792
220596962379981480 331491105145429460 681317135278431999
514228600816026911 237966556365574619 887161030815914992
762042700575617673 861234053332782517 208635379570744050
84621340343991034 981050657047620575 541212310482580719
869123917310041641 74273918482809463 906638165252441289
122917083621341689 233709834672015845 659296170651246915
188689422154181101 283411531184938088 931821487998876298
106631350764855612 611881137269649902 860863337923307220
298236551179881148 383438130228319156 443212341090130443
414911392584458181 469628867069897205 719495478684671236
662901804709440939 400663496332237807 415435386373284590
598545530175971044 837673643865765015 870761717224526027
896151773092737632 966049054054527759 18098171249373669
760545092807341806 395734291203632421 481989294827287999
948809775671554570 126862043849112759 529320273665865500
477862796578037765 838014353126271419 902386484357580979
985237074455890265 797735463591948924 454265136384828449
264937924130589729 740683889997613249 433401191153119149
862885500606873991 303429610572146025 393644531663121576
115474416020989583 277562852647437776 515070467322925763
336158630450263318 802996912786017561 25820590051014377
2321342021153914 761042585740554627 378613092411255482
187731089842424663 471581419787755421 451667496099190561
144799344301822640 561438926974517371 573873349941733271
461580793098694367 100129198912827968 810871130320489727
958092733345520124 752939936671442720 682949488258189138
432063102962590678 855068968314604099 843884777134461239
305417442578174049 135894448119089905 108898189506808788
867840735472403315 212709555412814392 332216512989778027
635178171635256137 893243065256110152 989917956151806610
362242460401476866 296521856207597633 159007266233131083
114861071880871292 374025423131884740 233058309645600705
247598794752602273 342562041957848985 804891683221874054
464277214272241327 468315136869302666 168266475281004749
889859570984693122 336305454722182277 665361406117309639
512705362114715314 798621838557813190 851590116797722016
423876107237940297 386998393848727311 952769162741722275
816667155906940376 707877529910917241 155434592827990636
896564159315442774 851820138910860020 751084532927460972
778389401921427794 297121620146419501 430944429943134385
653537826950959233 739831915100210426 548296875774927798
649633802360498440 840712677547804738 353942403415504878
768405134130510645 877639342570261422 548473848267231738
60158750349260988 268195154070266945 616578013656238970
28874836726210875 517676100032709175 225322109121233900
725521087265904869 795913880311175969 638549876971829752
64481315699021871 159695028975462502 213969379111508276
358154872754517772 375643186199110276 513382591699656994
512855352240864120 785190074861705268 97937055395701322
827949070668012331 688910168635444050 737382395639048860
429659167971450731 199272948879666767 869614646758223297
201346904607023162 526994249482962096 805963274707669091
846459306987333130 312345680482883154 964766094115883624
289329198256423865 968988754228619277 70315178245958678
286397960394961083 484981249003869666 502971204899486448
151111244944615652 728903990568733274 28030898986069469
764555044688161676 413431461146194708 974116993178162922
809930906111584973 567649726923689709 802539859488052802
181237684967173504 171219788324983401 4644399730054355
606286310368958920 254904262027622186 884527457675497340
131656362589350438 537785213541246852 372796690271992144
413138648914657379 439595496144792483 372965256813920771
653005819264446587 48242796951262611 102833720259864591
660376322703231788 694008818453150339 525050849591459859
667139454140723967 541760138621459140 276317632044781896
518764052760817645 614975898865256247 352291932874007770
906205834309309705 101404413511934691 891256133047777574
258147436565770329 636639439218075407 425454617633964711
385491568785815944 990560156858228097 276186394394776592
221859175633785756 931617779123005360 230625776236788831
826522694025367226 715754481637798687 319169957790561331
673245308570039122 55624182307650073 14615998476363315
370647410539991893 657127386368701842 829047911270499411
41835172641421287 930557884423356301 415226195042994612
746440893415051483 583960201898305518 106529123714092055
764864675344113674 172946683538387760 487411889623836912
793182803643221836 556640726219471186 442013751450597692
335539929817657150 583941684745641224 77020923822999015
651038746813763396 900977206344264258 583295626380337175
510046927206726526 114209920035122162 415202085108510039
935673305920731946 492261682817365579 866662884584420681
517756730910329505 66858230148280637 315987137323489038
469763471095428852 375505315181522458 197511898377258539
883121192033967472 923169904338515610 905281376164699599
759186981016896807 184034418958619297 619976597325488777
461360453592386708 213838179695777578 225118911280186287
15614478981124117 574530621322181737 149955476019521921
236198307005746221 931461531546798644 547266072695124233
196318212749780067 1805193207312545 327602108718526426
254734994848920161 803728693959962946 928484624474458356
3275915963867812 307129069168811778 148025272425402733
66577335767841556 269666297958171974 90897834381758157
77796752305996941 866233177328452952 307681809692363243
688511241916581182 373226265017892624 870569405376092446
44560901019209965 185223073481700375 681170152301850827
648913031043892509 562476037281404721 115447491707358655
229065839059114844 874028899144986640 952625982048203952
168473088816506845 627959974550010042 735406350239933226
710159060044753661 578316659584888269 165525386836242851
360599583754167430 166576940939576245 198474527441527572
7813725518799930 11309039781241277 853654362092191492
394624894041388534 948784646257392234 83609471048149595
117421481273954887 566622031319441881 377387291552419960
884337239019010636 529019645035230802 410868648979767794
375468436933585796 245585407648814222 365099412603651607
697911736698303380 370814009462947815 988030227278343564
712943512835452185 583930688785066194 888428842898982895
54454744393770380 844792860182177272 113668432028781281
295417956691946032 580944208472134499 557155017179056342
451070872214768845 886022940576313360 447130531989184219
740467397645117954 647672450098744752 784761544251968577
673445826192452386 412481687416277065 251674696906238833
544546825357078878 251325829368910169 361069158872452000
426420053716886811 344052980067711048 484822376846519075
980089800276906863 151391363530870148 536775577275963059
881467816451910932 583785699606795613 845793313518980503
918433775916557750 290202589789376805 637120022303558535
400602728715908868 748071977273767964 908335607803089250
256832333785903911 6791530471597753 367253645359579436
105411455697023526 172914448382352140 468844262952449850
558652194714831590 412653913062743261 875414587693597206
443937757384786796 363166932402961564 901635544423795283
701246111187895732 502641895182416055 44228496792711571
871277087755828566 418154380433072259 890814697637018062
327704084474961728 591687071490133272 926316839098218629
430187961357455655 732395428898999291 300557110094954461
695363927415815690 644889783222317905 650698535781963116
558869899230000445 149968889664379325 534449397476938144
548781875361515303 580820258701959381 845697908029303688
100793290030677147 609235662878769381 368898055747097771
469330078586296527 790746123393816164 531905247968144732
85208432469384132 412871736733750651 769723195560741005
133371163183981722 483559375237348996 61846716255540985
658599645771167289 904427074676833161 505925380797546542
330309520792551727 773227292470601867 787291663476446587
484783494594395346 707724748967327273 108197320866387588
82806234264742453 298744123089665868 818720406780794383
325407168440418906 924418606144855809 712996945843830520
782149590085800424 121696533066780735 439018814570070299
410404058077126230 92142876101283269 497527692174322849
714048259558740017 591585986120808818 70756340494439308
608804871081493192 201223824800962782 214026793977447530
57654851109754165 847035697894458183 175399007072083760
115383440854613900 748566238253087392 779221758948055351
397335698779347436 428924598353550468 639469725293901697
807320048279992698 362620125628823444 400196103736444347
870357532250243477 813914634772564316 977546761013418091
655158487159809811 419083515205410747 811767798456751037
914046687727247995 19674232657727762 812881471357234871
586249137755611011 577577753910287053 213912952717106054
297083571750435325 596444899851940897 285785040059914212
786836025924941394 953320458904736088 703273756374019380
462313102476661704 683790208716898327 417714357299535705
571312136430698324 865873044938927011 83132311363156476
398989370576544684 323691408196676863 698018507210649432
884491924769042014 677865159504363526 520273510935988514
614608000405264497 669189091240327811 996838746367592618
275642880815896464 933438325866651848 317634602518141105
89612104185636968 670841335765073355 139218686537771333
346108973264695347 974940153095235351 469037630560392472
148040798702937930 639053785586712619 752715146444065970
836279580471817042 940115396907385475 48097123500852409
926874772929159807 137740627188011575 470260216908679769
266108003411613138 902594426794972292 946112754584629135
348671726554163213 701932726386653324 486386477048386543
787242831117333331 185094387431745894 862796465117654385
187301735886309798 737955998380582486 739643406169905921
635596203831316291 316744445077706952 507674168276875471
553410429155963662 360122014981849415 111198878651347233
376270261077334192 353956919534537642 417852218385723828
815709256315181144 866736987772611929 816173085781333190
14892128913644339 875201846669583602 102335978798229918
197540614713256509 365462650233279129 877563332273360110
658725046928934258 639493807718532281 664434939258991467
442177149876147871 833445912837993397 525373886029437933
698084301688992402 382527331766003370 104612438000295885
543221911389689622 443338109477523587 486130759299364483
791149542957369345 154894260497869697 587691602083798022
623609677424007935 177020007075325985 916278875087211281
755956934820742276 807529092799650481 67939089335546851
Out #3:
778753534913338579
642392242490442144
540322527919825917
250851252510130310
860671253717015340
654711549545037954
698495325302727184
20384617135243333
835587899706964759
514556759638908155
589112983058087273
225581936138663895
184954731962896181
546526404686817103
343653705720249865
661787515534440565
975253959564875354
721688151994769746
706740175281471692
496187135189144873
88673808451480160
677622678741862954
636402885908495913
898590048003587392
671405546322700149
236555091781943488
611117801762781070
956670085608628818
564657167928804525
705597630710791268
136994613647498034
92216862484583179
866752632057718233
591179997819946845
56856351876015688
905811715037834262
149244774680560857
813870999423858548
512072700277527413
141268916617481777
810926286383833074
416441572175668245
509925048299991399
963480857315667307
410062380701388070
58296288359044170
368428020940357148
84346337649698643
762672525332522969
977851116931936784
895615252051540983
781869924441132463
650124326268673757
216787866613304121
281415331634071694
629838100202977869
881527297963983186
492230714216311636
16476192110218737
833207521564850358
575310926278905437
912068224076321212
849461914425316141
150355922242994761
886544748948702922
79608426018567145
202279510600893855
408761139282961470
56711181996523903
921271889382018206
116126387082382471
679560494274410218
656612749405546232
543087639676500898
466277037677751419
666600006473459029
383087713674886330
571220007383348535
282481648850819971
582624923099010050
742933867162978987
138384073569946298
4105120109376538
634822071310861192
484502735058692450
468351061599277645
738757077140619528
955678531867389305
311931081870877547
869851717532932055
297944377962824633
525382274218739394
405580569620306909
73091954619504840
259201607393945463
869522803132248888
527474089787470950
225033094191639844
334777919476881128
687437173545141069
341847658039254203
228603388869431725
844576884613232297
900529505129728385
82089256000033564
912582580585510690
27158063003451685
291328707079953738
243094111535172289
490094263818797405
327023296761166377
312165225919777072
869470573544966372
387115412157354311
54600388894745666
634113391211916824
429210755950157583
289788844125648197
786702434313329916
385765236814997940
757407894653127434
18701180539996878
417466194661859834
621449737635050422
68301264248441074
916911863968156806
234679832237297372
25644174050630027
892541843200712366
941115282736196616
381116509243116384
12135719642771427
633486496253185720
527407437778653933
120473777036449692
166078697564946708
959342823269893016
198499639689212455
608067838269349770
239328701246063779
160913105402891147
427699692451045829
362215614555496028
120258633190057699
781251731060237244
496723222766587936
780164881152217648
643008510797340722
288433382035690489
725471628773507477
821444589276479336
525121507714129098
6034626826279471
156736560859819578
377043369331404489
565953331613460718
536646557061060908
688504790103228938
431776174832143163
348734784983395798
714643919074627375
659668217461004935
23287670892768356
55221728256527167
489674790412699912
562070403730345651
490194309946821736
843667484480629987
323276096848887549
830158518673287190
605826048631071592
153135439387536640
658452855058728174
690976364051369550
33535292153542390
545008243151087232
133050871816585005
383077875625334418
182173421848265562
999546558130673679
598941402482285055
468811735461384416
547643370028101447
825428795653691051
357323370070637573
241328778508699905
710470438058771672
8081862199902445
848628683134162267
774625140909817129
540936279920754693
451125383530562996
352189144198777794
396592763773105633
67011129474247079
687566242865128272
447528807270073369
405088476419200109
109048336604357444
820822200170504591
746991868412895906
559756793939992057
235259095395529661
484763445987042248
684639806051363465
314133035805875989
943796519538118280
78380203804341383
407881879717342596
759047263145074450
312814646289640279
62501353539821778
699757225207630636
501250894576509832
874765310409944474
860932994198938573
537498190599749782
760589820257551364
873403263508716528
30843749604450864
356596007311460295
738547342169886023
33373910732269472
292283006904694206
671973786981746489
931162610137412872
842742034138563642
923677287280036054
375715629751804785
480201344612886089
72230132409690757
776522710103166191
901205363938408831
966549223699522835
911435031902232700
665935599951512106
978828526810495265
909495229700458301
932958259427586367
942008405070429170
191170809888725212
785949929378237066
611592098449627384
537547847890212216
882616864595051781
855246854458102820
230616305600001822
892805567053409735
687574407448696887
348644701362560248
498467997647985802
242743887507815218
212225181992101982
967051107638019191
688498374030156561
472550905173423971
596633130199782687
583752118539565626
51845604513046563
894766574806918160
484158323852120528
673683860747667767
436488326198963596
197270823051639536
951544779224771491
919954963425848616
113779596791889756
426980052607984515
106910655639269292
639656958760357635
307374328885054933
688931523564362915
558017379719469404
809176121029719686
644515889396438970
498337789293723769
18217657886231703
613195519506541491
452139408752676847
11052712432647620
939375365827198241
194088877236414179
45116085293348635
395675155510959170
281375788727904810
861641844592122805
899101225052807941
191006308283447778
908744042418377076
824495670819569913
638184590741886456
479436273203396128
140173546373971948
891421682283684915
9197972619973192
373814202944360955
262716617744469335
463369523274455656
991897724082706186
274118990251199423
828680334043293733
574597522866098691
483507145545022173
499989082224693424
49411865906624209
649298644255530397
639766189437471834
490551996971119864
844902304045899863
158199015783326739
608333724080280998
884287962571722101
269481520508287000
256850383385136146
466118693316619882
98959541005210849
623683428300846257
597833168591568105
646139007418156822
826936386818463404
450858969408328596
557254516920815273
751756128857079874
160272798422027437
186508485417280971
926330869586444161
542277826426039731
250390467788122645
44030424058805159
720480048159095717
671135047010957370
665814920405579151
599587232892773500
255217246026525575
649397007778412198
815221762569002896
682011314889552675
93878016350073380
110146082770729703
809533737230933438
200810390637447964
36563922559900038
566490686521584143
877220495434153804
581220635344420100
347267073948356841
48610804153385968
550836639549962370
51685032437609929
745707454137180282
196623019542411913
159267184730897987
932877289803300440
853694806931713204
383669801851002679
266821010799813418
984838847299520569
540805103156333955
145107046521326908
356024192268034774
961586222124231953
38940060417972354
534313588276016113
254408915600001187
974821648102432705
314073802998930956
496659286467185704
57047588965984171
398626425320093950
244636323967352027
752630686621999824
34960398260819096
604029824568495100
5632939924801217
144326275313300309
145370859342255602
105347709719670104
475976171273887543
63625035496945832
124917757027166810
478898592932653523
67688596889524201
224081117251160635
160405234559330384
804986203262469757
492947803828197416
849110021300717484
849616426096135651
549051030197474380
517106693281748105
256816601020535835
769844534768656384
512202188886610806
927452203987865089
421980367911432592
82571969400166989
822445178237575890
176048557538485436
673256709429871042
492263637743835881
633402373328784762
866329929992408800
80352963729862515
899477924046559136
283927489366666291
626673446272179196
527668459257536679
402538392786894723
688612801731675269
141947088934429918
63561778223811683
593432615597328083
119304399895358838
381118950667468482
590011746645121141
896642222997070910
158773840126329040
448558689479940273
426723147317877219
534255698285022809
748393648844685454
704053560431250437
905402544982292443
760153827789618627
671777593438238884
611709786220594440
91572136729349346
93957428361260261
74500107249282427
989299854783789753
334050914160471287
806158784794266660
147152202385453857
181798401695588966
823884973970082556
893900372269420601
866701871719006468
536603769908471521
719222864724984612
600375216597782922
254856980263628010
359749292174867604
220035412653948003
423170398677636626
21605990780932553
43933627989160275
400668059839949487
392414733429953591
888146446360673959
730641953944327809
396740076819765613
525036303597553232
498759871765085397
929349608451676000
72968603879683286
756285481732110835
870993093118744586
541420823391040709
537372607599866384
736629571325500965
161068910933971641
636728394625667223
267840831470485178
986414234206336662
734864029784358285
445063197491251555
168819106785050724
177294986960707430
451861218018008782
889908950937150888
499961257714754579
10139742145880196
882640646330919454
184750691381219224
884520187132771763
572690180117483815
229334202162169772
949480665149546599
904165344380123052
118835780568943460
573270324746349562
758999893089893347
33108333471847286
332400308229889491
733564203559540734
115526339673626501
784806076836239673
308540442638633497
254146313770020871
519508276890074041
231802450855232104
250414771936979186
287022769420942370
906885003853414830
118094492933675943
830317311286905349
115125771038394972
13037248286464754
357202985423301316
484183497638534937
720117689586994379
946956453918805450
283214923093334477
631333300742606705
511820359870543067
112493035464128888
773776850757712102
932887675337358609
2866868105400227
255036587472053661
591826832181370357
234637408445989383
746472745326346648
158871463260493207
465743935719021553
981650971396451313
480326051929941562
971050421948279866
762359774961470131
384889611930519968
989361866638051757
148580241332695126
399354548858869352
814611301891978151
342405983291514515
282696016868019693
522616501212747016
753659155246697402
484642213916643061
171022098257681159
29285330794297893
7835098975776632
71721735623081610
506847350548101113
675641364753114851
899305498783949218
577679657509317828
183393407120499256
594350294732749022
407348973363719485
736056886563062829
603802220146948733
5728337602408446
696425700636926529
967596048056762131
594399813955656419
500455083011355384
70777542263760048
581950030628026872
441575889411008727
816535936248577288
9451567772375494
385138264436187910
625758837458848703
923435559395207452
521676916102378440
521831385240020400
846229923534674266
660432114020183172
946455129689671913
248440838229301510
119160858461187360
202868734125164793
400941189856744430
784551112110162601
455747363932151373
429827317143203322
82848749417079401
357058642676641192
994423080179852479
783080405580327792
855911413297260565
540304290503215206
403131739412682308
189566537087996306
426566962543641331
72941219800700356
444421710307419167
283685361067551006
711981600271793426
215333355412110647
599810236246608692
465062726537811799
691504183784499519
349955130634811683
524091008061316683
739417253711753404
913280566192901099
34259571714520118
405280823626550776
659983340181677153
413836667465877309
776909165919605418
908844168366299073
734995838362773114
834067899865298938
331757965640596916
584182579105953178
278619153133003850
977607445899726135
496535528242184007
848663605475302788
117810485919794985
207828346494218148
23167297686089029
192259615014539470
12045657923700862
605113087325403439
394521110705775935
649040496112319456
857722661384082652
926494399934586776
51239159469806949
170961506261358124
185603212278763655
882310940461563470
369065578775260055
557190581754870980
105738201489687384
368566643725972208
420664668623191604
404003910722576891
855688006189381390
464427391164619969
30364469780217282
43279746802099600
996124023162218688
492691402602970259
367155577848342932
584980258535875743
683233461364865406
614424644901800213
176643173258667559
87453431060324136
40939786337831567
272790971310738575
479279939828786145
582066239332446432
409927256785374645
306219583771163515
385371357896754818
8396217897184873
691276748208363469
567131720612693512
988654225581808315
447702568861397490
130201592306465677
801870027190050144
431689205644426096
416484938407804400
128698177862037022
698627742761958050
400261652613902486
111771180869569177
159375902474399599
5665549715958244
626915191808317553
174540806014607025
735109110007550755
506117279954963575
744514172057918707
726389756203995108
943956809315017790
959001642507755609
878631094642972830
619476509837792049
226901465662237767
664474252446882974
495561915397621211
614692057027128289
24573423872327728
97053363398274509
238487946256535946
635823607991647307
223238634896890715
603694516363385746
741064782629796764
306784985645586999
995550827889273282
630866187780974131
363904584632828684
68992853832144742
25425316825981418
532486172501699359
834036659143285956
608622549020896486
759296936069367789
103792327809386683
767062981467051747
631000638443340374
298446395721873640
761818930169761243
789448890703301755
286166893931365797
888721492779026081
967408538114652512
555929745891649764
646304335006995057
56640767272198888
876882989988448644
729282197860121404
771505892858571126
382702701598481188
143886020402404210
243810003229289568
359789289917146040
737811195549428953
235337574477796068
339864622195773765
587126126164747367
195699594594460738
177475192637101204
490050968959201202
48805254520287431
712669117406471744
523646388194720184
665537141629892181
947992946520090848
14430317292805432
700789293907971462
628546094026274055
569849135704857534
307646510447520744
605535582826656166
729083904687918591
526828883266846921
615322371427179058
721734377857294181
364468351822467093
258815074990362707
708003577300080925
456941342308287517
698014507916320938
108569601464110961
676174427832219541
32969655066677922
333170206066401011
134397101372706443
613512043015050759
420690097908785844
605868353421182850
73095084095598760
351873640308306436
81611622931751062
450170739367094215
374718490830015153
801881351142904929
330044731885194029
538369511743885664
271882638320292634
206684385595995402
207846800703300550
997665181118810145
242706639149104910
444721603176677889
829919416150786757
564856387074598974
761222259670068092
968377965527145325
836896854320306802
718443050595650890
740336862184520395
253998436748024862
57462186084852237
521047095138504511
202451070569957382
386002696272359692
659680930839851390
286143248300868100
454821743564810934
895300293726077195
668615707108469938
174052900161291527
706399922218473335
705549449451476453
513928818033095002
225568773226048610
391013920281620758
341590735536052575
605407080423724858
117251364274283293
684799078454965560
48043015807537906
341680674339363467
182047639953515678
726840275286383864
375386810238847154
839678992035683293
463508140264089334
242166987131005290
25911300792329622
38428599397659808
988797324524036720
578840213063407853
942178377882347400
602741818220924536
995728830852298445
790032100144032012
523377863473742169
932318524879262948
501865366617587455
482838011687651622
893308934588323323
90269455824014631
427132848431383989
780068530396480740
957785760858699342
54293127034034338
207585412129457241
231351942147392403
223216926428608958
63469417419974127
29424940078346179
505132102538065397
351987315296573051
932896559634410680
926267614215052634
963429729607336635
534699204697851012
663544352921960743
142412398269047330
302774311178319701
354775874922745789
485882358112104914
858305189059740090
324067870657080088
861727617725971754
713634698083789645
552739945020397959
261997342551857961
472100742839213044
395859135617050192
381845252808484743
70838836622706881
120334395262566090
943166886519530352
292703962413175513
846579293205787797
595664809724074815
457951593485061772
292805959056323436
448982075266411150
355318673317853526
868878137098334803
574496401451673935
700562239049440537
681387256096592901
778640472986725794
834801866990768836
585085501744622237
401159332728822298
298769542033456609
920286658706019232
672932553659260889
722630586750678137
39140052562090436
395285392734031502
480763372907834837
967008105966261974
159617601821543084
766831012206599402
636951764645176898
542996919349211135
862609341394590613
611752909222210797
746722527838971950
898954358650679700
604476421450556541
130350100728377695
163300260304327566
360481369450850129
742889043752953352
556243625490391267
77185346679786630
618747728520928940
531359634036045030
385144122849740198
102138789700177712
159247785064947294
162775839859914079
706288978436267195
747684743420220130
845677491915386292
707170330886219467
445929113144165809
731363996469902802
783513252296535136
659513389918371615
867123812684071416
460977080160331916
926373969158404499
345879436924294732
770516265361998992
11023215370072430
300487696670534608
132433561072640509
610197266470998372
205907630442438690
92966062139545673
121420552841068745
169898714151496894
193777972673740134
856919943427965337
746057645630291701
363287354027402341
645202655150046095
914702175419769204
722928525907205990
563250531602545561
373508690551298324
507333478910499934
262425351412051484
285061510331554165
570033581303852790
451935960334238315
55072390999488214
147250081939584023
782591286109748240
474589672846782364
458346496610519346
668894645134191253
470127706293185362
147283259917347470
999083495421989316
51001195835836384
486371637683100380
907833514032165761
673272398069320217
700670592199433297
25304629465310068
175255919743061933
128696392386373661
855301791557316874
385615824458526756
18689865085756671
615703225762012617
762673651550522240
106284819876717995
680969958185051481
383564630675515518
30080497555603713
226640061014464999
75906433968212566
496546008231719057
186636079398427173
67432044254403463
291692038929195135
349721499753707729
399828547578889837
736498558952147294
623476634250948569
157754268467028231
290875561068131752
595022271048155396
882402703787317238
118253021641213957
930912307680015655
869752357471678568
399216029130377372
821747642632866811
127103046399310910
811887165588596890
421959836394538866
527785893503260725
808421127591597845
987113145161562109
780855293972216554
232142155030352642
387723403825288245
472019268547607501
958427531962515847
516666399880296805
293067784454767629
952410636191933324
220104181826836899
647764865012124237
423785474116798624
526029261128320157
881090727619041458
470132193924268639
86483263523058901
125589537736408486
223855949186167520
72904130588747570
503797981537188861
744293210899819053
691769249700909721
472623420100829973
865507296306016616
801294352746653197
475538515959726067
717343076673957966
588337083928598503
921100107833579
786260277365004344
376401299629233357
977843549593993501
329499392139854298
78625684973131121
365879702092197251
492507317650062657
290852138746108563
569661783175243218
253185362145675784
70256884010228339
566086336656763726
571630463162258235
942643501496655412
535310713188855247
196478006096929537
512980424440231521
759149724336229959
88820201988010932
605403519306019242
334588285330036552
566981219300856267
862817688617149567
124504164668738030
871116127176673074
882118650396921954
42708868611521239
684949599425699635
553298666306531110
187576351514303473
272590864869363814
79734488882161955
910202268706849383
576740538292205132
787007959907667911
428185352565675350
123881369392018549
966639234854113584
486259136987307880
161618290202591653
323128001688782736
233909309793359986
297926243173085215
418842706928329624
492456112214423544
603437310701060401
322789649203040373
871006736079044591
756633964876167032
506595378846722452
658763604671631474
617196136558391829
919652366013380868
939989989224302666
550654607141795016
453002949795546035
875340537285987358
462483731027700688
613450322104466065
278001803558982697
185324145586407494
585859762692147750
811027448847313592
90409245822472174
470866194019453111
248049269912269985
12170999746875523
556604091144667867
217067467460522569
705537364285304263
977825563895924590
603628975603334684
582993337785437463
252480721242787273
329659892588241671
623739018677496018
108147101982936275
857928693064536714
597711323355556943
162520264003341392
207289603987665760
413181543115479388
814262735839045868
343554625456454612
363827299145014552
448954114832901954
573300654529128628
550905033242665997
676430465127306246
870993782833881212
802646685384281220
402375482790837100
353425593906029645
43667192253490092
161130072428880487
843909868283547520
416455882025363710
993858935562062480
175789962542954882
217484786315445649
113168770175524294
53275244788623032
93031644223350891
729894246102725140
729440151009763269
466771304183414728
113534829590523430
97086664933311964
976544612712550225
387325759056611911
981960868046822794
354517435373146315
850947056699060023
729650765070792375
633816633222979975
736849316995011608
895773197863275399
601331674953815869
402421127318883514
481983119268228080
894507457685206983
579787337007589800
374723206507818975
663587427089376994
741339295552717066
580262099454275000
303252713193705454
204696264530644405
458252166217481445
749592440861165330
537286355556488726
248241202591807424
37921704701140018
654059606500670263
336305519087223106
772679955909894696
123221083058415378
78827574001189843
317030154652713256
992850733075307326
41320913261017849
39644424433073419
730336987492474442
996279200441429216
722270991480577595
744161991385116082
295746936844977187
490755342156425643
777848854754195800
185034897537256727
806067925674158644
498242178609593816
927273461442788564
987991555573762687
424849073635891893
515220165596252969
483676646919368500
237296527327963866
234717234760625799
122471559922160198
175346314168590104
365001409893588154
415487322464503707
756043058030900746
542649091547331597
224863265074028063
529299750801942140
530802501244145048
589061675507885691
313516012921632612
579174870338069579
630165895932011565
202499484713906968
737202338709197684
146133271755310519
718095627652016067
229348103858773611
715945197503873729
187061878226372973
54726554174580124
797592514505430185
109778193286124112
952892253937040156
25301568300003688
544354456738527968
687619684508702581
109106814611542165
354493914977420650
210519095708120140
219226071609498702
753676430165271414
663242915558092739
90865721604266546
623776361638242856
196694912982482267
583534580186687458
818357078469296619
776149663488687960
687805150231202109
486451751061688927
673197560693610216
282030387543536942
893310678944407529
582051779162530962
387620360090595028
797098571826063233
241201991803885984
215197803436865463
796154142842651761
169441886830808512
794374741213130147
119100808644734014
723389129330982715
273697455416706653
853436721042956689
586823073043062150
236355196129528564
373338667792986723
832052310800632075
791668844283700522
313269787680472831
7223850208895223
900597816595322153
931444408697597615
489132557149984240
127008146094475990
199239262350701550
1997811366517476
147604345492419883
498007852189752768
471368835583590359
82723506134807403
669208529270146084
952833348154415123
635438940363046739
292226811866197564
587087552543347735
559569465045857349
640521581097382982
856789250255667499
611585879421704059
833997683242428918
383906375784765
577693603220629314
497018499771894753
186456796815550046
385771021967109751
980441186884353056
23669561830766310
275219781693979459
373550421208664867
433539602801572152
932526094844499225
938269946541211346
749006817589358033
327981667600034982
626969861672247163
788048440535279075
682908075318148073
627637917804866332
256424512759419165
473198359875197294
173644766919792579
732096516408428014
587666582680113815
641157327413149794
163971606392806272
988707097854155094
871536136354077040
478187125074659111
472612110509366250
980055785693103777
238125091740899231
543246876545716940
894211023575988007
840438180744246663
451147523473466601
735486682533345696
734118315811903264
622113251938584825
845940164618126172
130848141856101841
825435831081781201
952487365227108331
926036331772907258
868578487719334750
697178908367650471
340596561184648905
77186689471429736
55598526664750348
290021030149718780
14891274298121654
552441450231989616
447323117869611338
958634331529195526
572275617427040462
433188010366134730
533154322087053260
621384163204329512
995062105087872734
574887147057310783
128392081462807186
28219514489294676
763808757330813033
782093844114366087
769581018938858632
932367871670006256
48184857926801669
671731582183260860
316564368730339854
971870259177383079
223901314411787685
801051895017326208
368734515009222825
128723561682827801
10903430508329325
492358849990852347
967822161832804932
382014299555392305
596863718527970941
700354212270544946
61597980183867660
62880483529543463
862308564542484615
250866664442402697
399141133208078926
542350762689187852
53030455421644276
72220260523883232
680812715451222432
85654713865032710
672357510839022866
543426738791400380
767521606144020735
888744007089181092
822918624714690395
365187802038948974
847167535182206863
204532372979499265
983355641471681833
7617414631109015
672508520628330724
263613990519154370
465598958049208762
557684134032299418
111681413533470488
118787104319931476
30599072657490895
337586112021898929
173345118610527634
502386363529112017
15274869973375518
754029238244356117
153420220616113288
939371172116087172
793522030684650486
872449217924864922
177395211275405723
661613646502865523
295667995406740844
857668972085047990
946826612883660129
928916128616930712
891991982677278376
948436757155989039
978524705604591312
596814129574641114
703013562147811807
989555049447299906
133819930095454289
723557316228669133
411785004001554662
20581964871739435
497120979837182217
624208924002269509
647392874188587293
493366825914188338
462277911526012792
227720733254972092
716231659524050694
27368371773513996
634864689294171884
938056828434231675
187043944349085445
152689141645873333
834419209778025151
426906278304750018
50209665422064926
147615339394503820
960109603515431183
312577163752383510
538718513507861925
828010719464495521
584261790486763908
266718947583050957
681721978848167592
799053981153303265
717695981099912746
538756725243526913
809837956680808968
429161459245818129
506398302715715845
569014582353482327
284684075294621555
28009356794690027
476460283180909902
929234002581279427
640814364605632981
961468167957260598
71013401825755318
149610067141780176
64926178251800526
705195012674687024
20162216139645229
724244928464192942
394047126741225013
613826832297645993
897615412803142515
181475596183715194
313199757277339752
982097356976150072
848626418429981457
564895839087272861
25716302253914965
306153519175417490
697646006192886852
891351170111924183
534929932198036436
603194284596356593
50652242840750577
679626413493599290
495781803898058667
830838064093755182
697784453564872911
220083615830529676
449566431904438118
417356137571008703
322837629772909847
23511092526785317
967075577147724566
570418408223764734
365664773914307282
921425909363410308
61002887261392930
693778033745765656
835137275042943142
942708002562604907
408241448128205648
75969776260515330
416257680399332734
262093879475377421
459573262756691424
6404684510729725
180779468029434636
325229847703296724
914087788247036879
264524924782690357
848277920179584383
508628701328837364
27959300358629992
847316200085246115
114170142104557877
39517540722182460
55871276372374253
826044863819004897
456337910273996975
29515929011419437
898770368431131563
698705425289364287
814087346722272336
649116125811161889
900631117118850285
330700527554465616
711965022953435973
291961002525222838
271276243293291942
606557429329480346
774364711188164376
512932818151880496
484659460408784613
498578686274105612
671481415518900634
17357234146239244
684807844208243118
979908861688216293
620091955053162001
806045144437887772
128421513485093653
490995038674985667
950865812173730071
721826412817491665
42477265972236742
95045464357403790
77664271301480160
959863992295224116
335611540299718155
255171282493436159
298085486293558717
366961335996794748
896485553035382761
425409064753009369
227137648223948124
900138003144655047
184122367568168619
529231633145404004
695452782296495711
328137669381614989
217040861921683519
193515247965155616
386451509652396522
810232880712063366
128092643790128906
796991856646910067
961817156494296019
768655586127128821
926699623265780148
282944149781706315
387652698292958934
351236827493175109
736244461567525703
117955923105462387
157864787168348206
407480159306416110
859080003948570286
103403846842508791
80158653890773482
428635301540949848
990264577643241502
394100147611327622
515766704972400439
675817779472204383
953762802100711562
616451380003700734
203286617138950093
881893469980249559
475596989742868811
220301386714538494
363054052163498882
235121728521168376
386065430971793311
468702077642914131
153672252163990971
539356542043110905
582601408389672948
418890995275409789
699079768139710706
47013497846945681
947425865053139370
563310562553551397
256220110992441918
552488679712375379
940707414918420188
305076003995366427
558952488161559217
116955871808633501
7254159118471816
958117351082816704
704895304854584127
435007270443074010
956914879263123329
428567614739494242
180704498203888967
601209735612735733
995885381145372435
934497439024910282
279659532661546492
321709075423370736
161772791725220448
73726013253990141
286490182679198757
153700595719730051
850082070561690773
609621986736842382
556724325239898949
360299216811999552
790514983817958420
879923232753842483
262100161964561656
696379716613949099
947824130601321323
786465593070831597
94735745890022597
156348423422281193
698127849995671044
78461919967106569
179634879663398599
712593607584732471
88835829004096396
1040608852031606
550216516954895153
978784211504885304
772381807617207196
15804334685048170
988465237162013123
233930277854989688
799484887243774210
940900424107066299
705910501129471331
361072105003704843
595038039512946048
417403604988686995
349748241785642878
321902248651066604
816727744705699102
490220228007870628
873194579006104452
729561812777467748
494066282992891222
220560468989342497
149828780836780218
400355973428987013
361552935581372121
161967558024556802
786428699554685538
673613237765251964
588470943790526714
511346887354434506
249965188575789236
846529920571547881
913059631129630352
321288840281674480
304194187916880498
886724571726655469
808503641567728708
55807043152474168
166008251169074734
575995305068223964
830856222272432214
263041776289688390
403715652072802723
708851936347409787
187776825860725230
352204476739745039
57050643183972677
75969304546902719
894736975674747044
186849402489606979
902329475744556979
635913887013076515
490676573980904454
485412340724818949
613336749282278120
71633846406676548
653004437115483881
806238560864790000
631315003914666696
813132270226892681
216808037125947472
251381382070468823
794799127736018970
698608694678166169
242500228018202884
941655502498307968
454004248050106107
788143017531361742
288206357161103867
836948228777330115
407249235963923857
115581026296576334
961694591308942182
697041892601821424
865599658561896809
278994844300731860
323176272770485976
829370239233372451
969021885307831544
454525064129872031
782449043900761764
431051387214966934
716171906157894505
621792249473333622
226370082132396557
210237208127282594
961164530286955486
750639576542668291
209581906597216712
123573071836863862
86638454851444566
803375664374702784
247038883793220609
378153138242915311
758190662087660905
402387783341635102
744949395098192066
889799060236714823
68576635979985811
942643401397953818
992197798701622689
788768137315503431
830245894370796574
805852345932306034
215942910214940927
154531370164456912
920371721420369941
426342146477604535
701678209849792774
255125088715750872
363675352110401401
516616182786088298
35212308475064055
568394116573001648
151792863740037006
481010151311227002
842829560000720734
518985609958265598
547720675522319218
327902674048222376
454655802254064540
662204926616641805
561699042732676529
490113247369569144
304472168867617830
887120772945903988
4874800330273690
631027045751798435
82547178995211277
74283830811550172
267638726213112029
564493112315124621
809047511006049392
311143130949422423
691934338659001061
458986832792910553
946016722591040544
598657239584021729
49790606136212089
639108338255992110
520985735751876439
105243578666094927
228526290386709091
211327835293161650
19112912826810419
21966618182746934
970582320225306570
673867189960820054
812131274245655593
851050782129733321
333222340534483179
691897574735199383
315063249870380797
486488198993067569
813396707781542256
154817016769702004
542994393137170376
8266150622310306
445899652379313059
594072460580631226
968349596926772591
829122040281560388
65569722630253331
117597783970042849
742236438114353604
382323910293483242
917355375355660263
761235790683887621
910108850484813232
191494260443147105
45668233623878409
404219034508671682
520164548529679436
21581779657180721
53947537693136010
544932258943574223
719787271700722557
205651852869641941
464944080728640191
253116086679378179
698020178983321204
674549584532904255
464565054597483727
227906385783899231
361718147678042400
184469956425901407
841534650220169140
915241151008025204
862099649072736273
453240481972568269
215426232984849455
177678279883708373
994615097341034637
949473962045028569
859907721462225535
494374068452405855
545305977412091086
925312662889190941
14772200419168966
694497091205636930
184893675512179029
105397684986459786
456150350167773439
424830172521097550
270494464875923848
737132088352602541
867962535123450160
51978257879919132
738880309984340566
764807670309776719
589653201167153536
270308835344484949
622211508882959259
90097328796628352
541624117505472037
499203222469731869
668824309934725221
460959486759587979
990430366489221067
761379629736367115
536280139420961904
119768303618240219
477939704756640868
683193679552420978
254198024654556788
264945205135863232
907303214342575613
549331786970352257
902639471414850005
439627909805825286
436092353038814602
641587840567818201
930055436550719982
388234372951120937
623581473316252509
375537482523948846
131304341269666132
886973077765316207
786845408101468144
713739547376448983
142558603324178891
949470144863553351
501050622409800326
43561935291145812
209559847917972247
495490799362993
205282212128060186
975054357446906774
788822294359735134
890160959208041348
952837062671144412
515917167307320115
512003837792147134
395210344187404347
884146545055498977
353415187240691721
802127387107646536
87901807246415391
475506487344566592
756001975530044778
973834423638683319
843666056153270704
723152535357892824
220389319386347146
670062405397349896
575021932677692270
863797649373092202
711189971544158878
986257443216039616
129318878595063466
341605182600281690
579398165123288408
373626609010198183
994419138589359098
476464871677909010
931991073196337935
632069038346433552
644828655916662520
875743935337539477
659725874788865352
220769760863527340
254529618806733272
660638595694174892
254212938645214102
578368628691777683
17513799698459650
810047263592067276
127898152681927256
260534752698377071
145997872054602393
533882092589963980
297911413032769117
660741213987247897
483162675715987616
630541768841249936
564251929189223316
969864280462388586
125097933269433998
568510489034639732
200030187809649394
35398228144886849
367494477119300193
934455245713752649
758816530828831191
634030195676082540
42939848583730835
599542122297995440
932038751521132483
407505222085376829
754781496393882017
264268780298109602
590910865926106600
645622567737238575
738161672003233115
413134500703938026
830955026899791545
410682281451073576
503106284570874450
274361795489470534
279168192067367244
877277646483536135
819488148916977792
505850501882261043
571953428696450291
561059611864883604
562174889092186985
950244721380937623
612789397112176760
526792968262707489
892626735753442095
682965338815663793
51663259696727952
579345427606495404
175457600977210357
74775706085646611
964521801963546057
404898599539614297
963494743059917197
574446116207787874
439156720441979395
829106855207508230
752315524656091851
593292566999209110
284385922959163894
154090526811019214
651686924457792793
435773947409087942
342606906534620576
919072791259316594
438063625215239926
533380466128008221
289334215281314971
692716731392169588
564127835747128766
470946538623298463
982480154145454159
452135073689934762
729167619712736905
302999295813462985
242453106828743502
833811671601127794
522970166597288173
235071924574870827
957952051636603088
26213855103979311
349365642148176092
994016732383447733
26416599630261210
723971275287689886
21101581958900028
377437445036225328
660473245445232660
334319064361606502
748799797154097480
335478319953606432
100458288815747798
345060822961595638
321237456796834604
531974331149397461
470952469192465664
282997787766185949
192908630745108307
445017222984952332
153868308632478643
56681954225666557
117679206601466650
870123575846763817
739081231478940265
716629689267323364
108103313509949945
168657077119043248
80636989705134770
330711635548047621
959096069719006886
68240962181027644
992422632537336697
219120360256717299
809255951766438242
981573647803222131
777578905370684400
300069786145424694
215458200344038230
609139172679546999
230761514464830463
802218349189479980
386648272616920223
457717579200830877
141905514340380167
385740490927004895
127766498210875795
76769021722981980
942541846053478136
466387865661436177
714192134986702738
562437768808153814
278057318127625918
838398145186913772
412999057450974037
397132566333326745
873422507653439127
663379486778082886
905158629890466910
759511838150044808
770071787173174876
790271669577779797
699626332808758354
222356583373213221
3100509001148233
506012307886463104
291751115406507016
858499940939801478
928028653065310845
159396920737602067
391005946848421111
780575084992737970
184151009672435751
990880469117152564
118637262494234764
184493725780526110
770122203849694419
765198070994175133
320262913701005823
561713407480144540
559971936625096744
958035257417801097
831404741812236446
353870911364959867
81203712498322224
558023738934451086
219029079599343219
52195353397578873
627102749087872970
179161753265257580
720208167754141215
601805708001469752
872717905231488060
542346575612510105
47137675164360260
805838470512260318
559865423988575880
653300282478007699
2705689145618136
469243483170701226
114645529950076676
485551571311904072
405408242221586008
851242357520986559
602736606352048159
122589768922774857
445385735904427814
536144697681165685
931360817189870178
399671979694583075
685178916290676425
338312193406756650
45782304111471189
875099133079122141
81272985737278581
956798466860003149
118699842956937152
393923242418487434
80738503559672027
704968675627974231
279046376264161604
476842420758751670
222175200974130646
27859938386023305
239936879011779434
924872941228632932
585616742300017438
289953395460650183
302888929749015870
287958546304041691
333887167184684397
427169152360182794
948059728356590550
829578062988953625
978696954997286896
711552370651655730
541280226765596756
122252712936089005
435532362029751236
506498310073421410
987183694701569962
408223715417654314
98487170440175491
500125654653559185
75039057372402159
994282713893373398
432068761051738886
918788018640331741
595895691055060339
804027230148988709
493081394781529710
644035309829761047
533604353556242601
237704138692244308
238048394378703588
997808179458564477
343225393577278624
763720943922190861
254052868030621288
562401791724774914
102380142782705454
14508082337519573
397827400621458993
216666049113903717
729641969886476796
590252981824823068
352162540930710750
830859607507529602
972082223276735064
981227813213054460
2441896469854763
35379983531639229
486416004639247464
820870963544492541
328988776044198567
96635944428000400
639189410013493987
378146562776417143
37473595418894090
555990438110860805
251531529182985826
278547561436178693
369961846004356018
853771382689497663
717974450926341373
949253641133654831
302318766484949055
805016395922595577
839180173949417904
53455156218900413
655671256301123329
69257651218335475
173936984097956870
702872751793378640
829298978050473090
780123595551589788
784317867752209081
381237527877865622
595260840593958007
889405656275487178
894244503320317557
470949989860252091
78901817392692597
323756110362419636
117599402084565204
403623846258277165
362285940207437213
874376590636478085
816858597201832834
475163921954926387
765287431024316545
598709258945445516
926433774643110857
392048769069336492
42068223103336920
771942617977912006
149741353125139892
169807234005533587
119392327150009279
953496101585876750
395902116022411634
629713288284631770
952267116574518079
12288967376806808
995281699918666169
604945316105372751
348401572456673429
394442334092333118
182037773380796589
202703925832074695
48879419272259175
834789038227383349
347714694082296464
564924490842060381
567121128295720525
646224889023108014
349701001936400349
329115407554436889
456261084270938554
826308672554597902
697684171893532470
851151849900237973
926497200337067499
862844519825114489
897163546291871722
101547911294069889
906624596319711768
333874237693268960
67976394883430052
466571319007230643
198775264686272192
625627129823672592
309212773843210140
467921292903361054
153862254430758068
632574484208825779
822666881824942672
291555855604206184
982338349340570924
191481124467668692
177615624020099860
235676885038615545
569550232898424897
161340891122052554
174795610723246026
346210839664087570
875570343287810429
137584558086315899
858215795921756428
581116726297271251
88014253681136193
850357636824532337
974225280473599690
70724975831086114
379833062542558726
271835805807311958
416846110507584471
521735258111479546
774010979682165154
100054418006772590
59837545955339640
794092792088502757
102479717745313167
741717679074829127
227028949673245894
673410807766485472
168894260296025693
980201220294156091
290721342714383602
616357923166124860
801708759395965135
981987413367183470
799420246291079504
305874158287059381
284133392144442789
431680883066838311
915144388424657103
534399546875131913
232596561070501075
371145019326796591
729088572351262864
45575491969045988
244592751556479420
839571321886019823
551113024132330746
699605159113466944
674080363999618643
269874398579215942
628064407545004033
314421642308860744
863534887113983277
27735994976453671
633482119586612068
807150457649375750
154321254749228992
590216393507589015
486790031620223769
518379915366698825
352997473196908941
10684290853170646
629041390443036899
730932682923486911
972742228812310961
636603815967766445
774491087998192412
176560677889261664
42279763112674219
136439516060883976
461568752670381045
174124174597692690
267558176490757562
938122642565308314
878158495767585273
719754513292916567
683939496645074431
423576598191817469
361041410430166046
8568023478149350
673107013316217678
825989252593549550
834597377636520475
425091350791262083
306413496966402281
353344200513779186
89114197089589136
248021159825108020
996226967657714136
886839102688417710
495270429161230270
197209879358567207
522723769460132989
672393272921865341
186503331330461966
695183653356544732
160137530628525577
618798581566485238
494662477636356208
923521490875759573
154412092306634248
898715845091555749
917575007786851436
813306619656491875
10200206856362745
182892456984776964
803346268321112688
344050738872976204
130050893069640695
801651757535266188
464702709570189470
247268601628769695
939780413055238534
331499653308062534
708471488740347175
705105203252395025
821842156468158453
80053104656146535
152542639492538718
894957047238113261
391007535884966338
398736301414944635
739092403715762190
116371149035768369
898367965100305381
940366305664522610
466502973858253528
696312538374386859
779697576158699543
632426622171159274
732910342970688803
174047592305187241
892561522673541089
367249504877774932
942514119796073098
749446153830034203
565857472071055441
848716928773265629
805289659719588760
604595263844647006
959098523634782521
966031402006194378
697074997150483783
5750765674613132
914008533226177703
613920758992377099
439856357786472570
341913000952582942
130401662902519371
142140624960136831
606595360997022123
452932389426174313
856925163178203931
622952158506438067
143576483889023005
797269583003741188
312062231524532389
911398333863341635
6845041093901732
13015122115699038
221786919211967701
477648554697816668
910286938458789366
606791710909766223
800101437070953763
368652380214238772
963957106846103122
131512682798880107
990053268767100501
304356885780806586
266220460480654551
646581825365365406
297456436376286166
31443738254865861
98997353818185767
300665040976316076
722208632579225427
616916553167899603
661198550329200332
156018471682318006
456978633096734754
125138110731175290
659323479353859779
245448829770060697
674330822235546308
654742054206909921
456988119892557063
850869509839752617
974887422168111239
927381568107388741
677546865641590028
965166998260914151
879511245617964769
147250035180641898
527252701302138913
584968677694284735
411515658361951137
866339687632027765
498799300503433586
467797769122684900
626993001102564193
74980212278276272
404230231502868610
784081829982273427
79501444750780382
396676929080918477
321421643674339198
74147003451134517
440871878027385638
215754416551641918
325576334935179504
20243864060964191
67520316684394108
199814073814134723
70095537794092146
843650004228961816
706434118490500757
3942183871000729
672388491417881319
365718636751180103
829764417996848186
730086835877944621
895083959963644808
570305151228206700
107848806847764471
374028220788099684
457167810819745341
253740102300569174
208388326477230656
226977942335450257
241906395771588070
741846872255346376
856728609106730655
896718137699116035
376718179993273544
653500245578601380
622056221913014299
930925352181945505
501283698301546985
518033805730736195
296029007840993669
839704247182998225
793485470730582186
409189851044554988
464567697859972137
932470653895168824
28663836625000223
822247234459911228
374629486612336816
992153342765764857
861582337437686639
136676222926129311
162069232784568669
73065833111353853
978793308099269535
814533311756207410
711099258631286799
632489227507151604
159812565603811443
545592524065641076
394198896613257827
207274198646646555
184197842642903622
514205206997383925
702787096179003508
936731350308691793
566351471015574491
837874512141701346
415734717817292344
251084538275093205
112099595426667894
246407348080252267
83730525538788904
847136616902433707
711203064585528206
981680037437543520
333504402215426195
417767298039278151
278184598239845957
112422014859133772
950524889349801005
524874506902075653
685914309150070871
743966399144467401
675913998928238214
969424608757290032
446452605760497675
520675779457313345
561588346216741174
295389503152892075
498609818034419030
965044961455694745
608692954951006102
23874063467594427
249496586290078962
363937520845302344
956019035318709166
892045755808767945
246979632458736620
912821459063457173
97801089659325841
170577534092020195
893197058953865053
760854269846054158
685688885941476134
28896137309766418
577771695460940726
815268866312893488
137826969229954932
13559714328035581
684500171890107523
919142297640467872
671804018076396090
388067063455742036
520015291752876959
566361258291355402
985941105267623784
14724378946730107
960505463068016889
244515122013326418
45061074968905403
105276355772192442
369944402730941861
303625030804885278
613247042695978962
474634402713993336
909837826916355745
404397839674530237
455381060029388449
942684155618067375
699980389965569295
30828347871230240
496623327946602027
967021309580889802
451283224282130336
175579761868692965
318265655974209152
177033928655338158
703652194403321590
549974247343349694
225990903991451786
947457054386282596
118991428504992108
706564153355989957
576247987239411416
20603370613145304
665337240437453409
576235081691854885
988210874799815671
224073209209131492
208403744165027208
737835184120329648
217424523089717781
986891333602812463
89129490474062810
418017133502176479
845479484674092678
305410134788293482
615203619278853762
883672844271720517
580307373738408358
208215848887232034
51016497463082230
624056795589662517
55508645743866821
636237860765737277
194367894194118924
158560506355554528
404807486295487104
295064560148778934
719690417891596794
875223193104929878
994807644508804706
35475975793371899
75477554201172125
144835066272599694
340179589451061275
291340627502034044
324116819388300751
58674871984331051
214288284215792432
15835785334269969
642252655244322127
403995326483951869
788918736147703722
853895982148396146
57875196769014922
257928731217460740
562826509441009440
511018607644249050
221637232423638209
821763610802843249
60472502420055146
755009924333161416
963960955164747871
974010149277605364
351963390149597299
355071981708605642
515521990206561511
664166919817251028
618474217985767506
966896925835269991
894009947452072854
251126532987334233
966722800677331153
411102102299021071
864885714063130652
583549813292301434
169410984234946595
724631804185184322
172869670802178406
895352256844022846
765620030841569892
706444510370839469
992232120283697437
889288774059613846
684779642723462542
493684577470202310
161004566405805810
602346187881099447
420857017095360683
293375409935731764
373086014309460517
136619432277258926
73664651873207841
505349916045899264
973895158811113155
566129291478358216
617636215711410502
667825370290996235
734470714587037509
188049811786068091
353366988032592345
877178141501657606
142441321770511866
572599832158122678
729223073867530396
78639633899216845
775173182544736041
821111320591534414
673911619649046833
678606758211222238
56002929207684431
392478260139888996
418291460771392878
827359328947120774
487680045962405497
27260934905926159
250230391827664799
571336247416650238
549323893026683169
803798658111740357
301615387031298329
634178729287414643
649600423008254469
645380053085215760
212900546411787205
781680455071132792
535513736510981581
660524654420679531
386715499623127077
298397451229396210
969881601673455602
267427148073394937
460675914144263588
965522209781340170
18462259935881315
71348111817438254
479961577567440726
695431955357148853
667137688577545755
667714012067636245
323899997863935904
519130058654070403
479955649812202639
890537913220162523
836425972783584509
571003800301230340
932166403861437871
95520784820441234
242869480713785555
37477270774550936
955578538574721062
938328497622455971
744470921096075412
681648864468787921
160522617526646114
47478870399201616
899664571022550511
377773205386283634
790010634599991889
569546112429298927
408670799528697761
623222820418548945
265050027651025165
673152303608163233
100125457381273177
331684614566609833
714982152296325496
315735706890521851
345059148712463761
807224965324528058
536811093463855380
999017683086493502
286749032066055672
430569781341863022
997280388350919962
62222192322009444
738518667136665875
623200843116991573
322355361974752307
781842691688362315
723809413169187945
842324590790931028
292508673127266301
932648069286732723
871059579495464116
637361460062651947
981361822040772882
975166709564528881
297118074803957354
68414761928277940
149689239087281727
817999652736402698
115344198324999142
958707923518836841
416848767186140649
400373440084710572
718689385168977455
263267745592200949
901657870633670714
678341181703019263
747623891393108641
430107877326186505
450247991163521894
762589420680441724
749755066184377968
996382253684651472
124239104190774285
240336528573736252
522301157041133937
81703283083154964
593160989568234434
120475733224094491
138508972997368610
671266062488681350
144094394428418172
492152405332681438
408906665517680936
86523206645086878
332492178739411762
787588049635867011
81031243881923934
701559582995101628
146229825329842924
201352299152173017
441575709205940286
507490946617904785
508836589197339819
15185553148554696
810734906201279915
370795637376597658
387485563210772272
954603195810600753
863711285689277722
875369833889863455
106212288427053655
406873392229496743
388210066657781974
439414154249984698
753427390443622108
271238489211008445
881071358469651888
741067426289382117
497314315316260214
387096415310702236
776583506404065880
47345768792224615
981269398829428424
107898627543120279
237170080215172887
191629510203906310
321462175381174209
97829935759393937
429968635932220549
65902538315782611
676935886829625332
887288834232031071
722990524270928184
58090710826700114
32058185256896207
923206860023548596
122033325048389881
202583209250065405
4148050670306177
972623190563792668
434801382975009458
532138089721245795
801746342377734033
66264915158455542
798470744771997544
251975353091794544
740400540869544548
451095447914599345
536645469923962282
204980021068253962
534932161293171868
601810203700756860
782468746950937898
128175544486288261
266877737766546375
963231027162804930
200084662163313192
36017188755944761
410983287019138488
799681417461307803
990418900814336236
549767032058569965
523644152934280217
821447734240689491
319430965120657769
732273892074915409
964009551227078647
674907661506560489
825026904366076555
248657822482068359
551166143527079189
560906407577436057
158762357294773728
541504731260863684
399771238618215851
226877277553912380
9953141199592217
768513889238687621
266953010238635427
416806396424374530
779946399712109406
854717664050730588
53109280247500865
886594195201868482
706981492661374523
446390019131751615
462939631948493617
431866953153660834
555156756986924195
51453934166232530
224327668721343972
713236993945938896
79420538143290373
816147203793340531
627970795207720497
643571577667444148
902961483564664865
211935851352043571
762613744164508859
65320465742394412
639016218281671683
803225465651714913
929218164103260291
95643743483365569
616456849695543210
257600401363220391
629534702624285041
599590904554426579
282430940633060459
554588182130367838
629759075542798748
526087342699811910
793226702117558520
796173309206557602
555998479705098621
808353435371953341
467083028277707786
350901530566459418
426220190289136272
859519494120843875
146350489393188407
408948328566233001
660141383156949248
663671637966531621
138093249265170472
257303342469227060
341514176434186780
295069112934270544
187164509176107576
125393643961212613
10074129799891172
950337872012192310
199521054768050437
637413184917245648
592199864684089832
623703950374623400
407028384058219263
385633034112589167
371507042113751885
780927665809540836
456673573755618937
463691420982681885
209837539539292878
303289785354372984
882275311443475601
840140022483357027
514493169508293294
711593904303881676
30697718087397505
915492438200471135
569876517420099858
322626032175702419
403606520448821068
179303755584042052
53459398116384635
485034341673823158
992098638033776673
294347971722181107
647616665327065714
512029273460887692
87079400901990646
506071563872377404
982273353858270529
695471097103684991
473012171910960134
412743419037613625
195746325933825298
354426100766642665
424255913172087693
440373150519624063
221159581444359268
415931434868865560
581125212596713634
907774358327695207
43277901280671329
459639077332581049
364470980425981293
905389458645222354
328805285236955904
659234095675631275
666617791670530224
200604817568864916
363043843951373821
784381005369370597
358808730814482588
623499095568811450
601713850133857204
852380750497047690
266311891813666424
915220437787140974
635084986498012450
427982520564157102
742679595454791472
85262217759382171
721584417157331796
746631054258745908
49943885501817980
370208546667916737
941181145143544197
959229067821420339
570319339539936448
483646682285812544
167063485146615317
758966437670099003
795361688200754473
712829299725638065
453962860141604336
545636502730016188
663406498855845184
567724594192031570
239679598477070359
641209527777468858
386985985052758471
173652574109605358
578144768504213694
463172822066643898
538525068164915597
12990765573493453
260920358534935644
878052384727281675
470591832676094258
202723176688966184
125210970600185234
825941131308872501
878952367797048646
99160385386492589
302771474451670702
914259539082068745
290167432111679111
214459235762160057
961831347847882865
540848221622130492
964837914131734460
529918713364747423
583674909349996321
108596020950774270
29072416797462446
32130113265027192
146465644618419924
788840526116934710
945185738093919875
556197222238545834
937197454677476263
470646577476216081
475585842272171024
37029330643766733
62018021242948997
42115316567145902
849791127815910969
668724497047308224
719570833553839251
894935058708557831
22777052050135539
849792552477146761
65396156025527621
104342301998229463
167001262969085994
669454073300534585
947456679187149950
450900753142185592
732214503830092840
669185412350385608
133356625740092784
982656285207268203
947926178310887026
370456078901682482
621898744234810192
405348271409930332
688566817737682708
661450579333248060
175861104677164934
745732676265393791
610852437182619789
787522656209401914
162960684234699230
238261097921617120
40096536164673588
775289808685174813
743976859739679411
337073356537601328
374242873592922158
535928450000191199
660870391928890543
149359332018400447
70266913313541152
818860330504415750
257996785122712557
704524793708794153
473324669234427915
1127638046595363
58940564542144267
676980039820677046
494944565916275177
697492048856974614
898702443117298270
733708424809555158
161557297383239720
581834723332285485
127771848010102379
662603661352892507
364880178782988407
75181375071069630
370459431205316430
521397403748146411
565677064630303554
516851617390304443
694360752645020340
585329577017680925
7247269104692699
873259470536193760
983081885056846822
790513893095461416
599827946493324618
332530847134739416
970907551947624329
925137402679007545
902503749902960081
689753580820936961
379497658444428112
841896051862944941
682081059260574307
695579243304758767
747299223028874261
261145748007830112
628785247792167652
455322310095849941
462125383170520320
812672891412569571
246857578107122387
543910034279670908
32122411400398895
588873455626044674
422192051250249906
59362601534427828
516211640890447655
567774118550431796
377340479909385307
76386559920599167
227612544279927215
108703240123031489
781347138862334284
957784538995210270
873608681208502166
443057408732929331
534959489014372876
573730244319721609
104526531048292974
340013652386819819
87507932836085132
160892061923213867
957760351101918976
754240488021542419
564679102222110331
785659074588279995
526150890197117420
457803977795415523
744002550040303909
671843885017083358
254921967980170963
396671188818069316
22647643673539228
813250543444921467
586948432003575865
76170982249993233
797247764623155996
90304262634993753
137563077579886568
92131249380495125
950198160711033978
190146528246186924
600853823251336201
988907809364215676
686443370481257072
118413645326447195
574924025798039596
453509132211805420
454486392166631946
226417279159348295
617925203558522797
930854163793742556
290233146377065927
238251119551416931
54032182935115575
178146410561629057
674682986784270699
542013242105103886
680605120944386131
801836121958616891
112775186798765349
358033319045738408
696768095864617552
26411111969376900
20315900836857826
984259424082030422
630663524416961161
624203019403457818
36518403950581177
634544536824503205
425657358057014327
12354594845668980
531412744882444447
116619733795624258
77442812234999902
461108942364705565
143545505686968582
424698691575075226
1360963851715888
403326434407398196
188236254600036117
561475942430449379
845170571600178274
105093406033434103
289943286688812147
711817217296605675
976366167842775277
674423707337285815
102779378510263937
114802000997442674
803261335507869440
639332822239116884
901095363867657259
276679801075325163
469073506208043098
231779658895654320
571588915941337051
795001089640767910
819194805675831280
461653076305515877
71223760316178146
760745975040938902
212939441060502351
369997411188707925
854983561340539626
977087864214278985
621792215160223595
802981341640475850
283291038152025289
92050907902503079
504194345545220811
298008767900507533
609675006352146340
250012216438329596
211248192684210344
340417353276969321
557305231244101929
855911867760581760
900266968088662985
439561867424563052
461524938068443322
505366185232974416
904944606929333588
522984957166189321
23114322622908666
495039118556586787
339638827163441982
901834069112261917
548588584387850038
72710619131827403
417102144605773848
79322834354709143
906227399142772313
352689261389831748
233268768799927474
217165808858920886
936899662443458737
906375203272482824
821425210466877427
448920305711571463
829128755391335980
973753934472173716
371940768678690929
930869131796305486
244951159786911774
210212706900539980
631001038118527135
331190510962208339
939674009168370938
350978599749306936
914091230628655115
18890143247030359
716086211124182077
204189910125082527
744637476217370312
903419027611096713
732928843075021203
729560994469184387
357122696136125402
379452129063762165
500553415556604316
992189428258524006
121962863761724678
679240548526889212
203938318920791326
341821489836530538
641117357115066059
440092662387657923
912983878868687070
566761067510418352
497435239112665229
606877805161178216
682136935434802500
902830593296483592
816642779999032338
644463964093593266
833505004530777604
894429558677231712
640993776902395382
524487489456445072
437144550000648569
618623695191235732
816927384342114583
939849756840573617
907679645177082864
580972419370960273
82966682071355585
457441620265686436
655695715346736639
597477722683748519
527280194824251301
646548558460966772
382539230529771834
142853874986053513
348734232786663473
488235509065621034
188987841822004167
115522662155257294
456839896907759731
469514355018818743
120135511750373557
798320945868016972
490132865093680207
36739404142276079
454173138637981882
818631274842314840
462282615641699876
144526999855916056
782823793347628640
721237331570952240
557339573566697613
250903863183558710
428520867328982694
758155547685963542
880745888132170191
129068675772209177
165280826273661033
349495321836157102
297888442704155608
815829989864885088
511288419578510184
244317380742855651
541011266678044907
566583662480070073
442059837079081146
998391416375485570
181478169624578324
441211958226360647
860053005348062322
772919606397972715
670527903079682905
932959790486018133
458412278836451646
641951612134902091
332021377002594549
226887824328776956
151759209656843233
736238524042743649
52111734323382526
839319679196622954
438358276020229783
458521941061572606
848446064115295693
609488665714857315
208858281812400358
408372724116636129
309666453008191776
632664323354944962
351534670405963628
248810003051568889
357195069095905573
983032580725805667
323281537979581334
111282080910501729
240778617383474295
783394162400060551
609796605040540046
294402133378263351
815582564735460327
894822827279057167
517912636451770838
179785979674889244
530725603968029823
303940534373202032
429771161563816460
816425450324026476
46005348761297031
128356260321955748
241455251913849897
147414550032793210
973127410486731347
160304581350357979
682181055181670325
602229998393341168
639507949870724257
271977240868304503
259043412103062733
423989970438483822
653409766835650222
427394316222797217
861792198585954718
135328402680300393
228284815401732828
237796673423637975
122913537799833798
380725227242256121
866074151971214802
673312134558359460
232364022024418701
865313274964048612
424442707987778404
734821663730401141
344534768352302145
468655310929765196
793429698716709771
741238786756436177
393345135661559659
625517984246526314
831299815815100488
665319414076455096
708316406695565166
640099938220547517
884166202381541677
92422762825731317
173457363747456503
220517531436359559
952834260236639967
940637941737169918
912756299735503230
729389134630880286
40901322782074540
706696984497177612
854278362793341163
563497195352659613
656220740020313559
52439987256771310
805968995482734304
740808038060709717
805722369928009035
273283072257664349
148281447605316969
924839862928360262
798710067479991560
48993442473971332
396787143518902605
315065232838749092
763230641305675503
79533179002668832
557445105806828900
826720881020037754
147470344642085156
543868100142147907
418293335826961015
758985676642289786
194743493482277619
758286454231670454
544418265990705901
337145748641998039
697943081066222710
104773222719875610
260651036083367762
970999789350487878
328033815598568039
400003086891904306
645627081332438650
996395166228327012
88947930432370118
882493168834020413
55177380577885519
965560968435089164
108673639735784242
508629275476177319
498730537429650981
9674232310800057
17092567242831619
157272617237915281
617913991951373428
215996696958302379
381497139472394913
988355018012019397
622930091914262188
963042474366073564
860661043801595361
982090783887392927
540322382912435195
717944581044953066
789943955109509392
907358811064785107
388499714358946409
527011704740188933
539140456135319601
896687515353476258
657296697486369133
554116862944000636
606745432340083417
513949728125335159
477782280838542209
150564575861953755
18592375730054962
856361980254884174
894868942306928072
101282283490456029
753973289160853927
209975591962079009
164268826529155578
98614344495787777
489742470798112151
467009766673780008
692490982431764457
191003302487882715
683712896746370886
505364978122304245
962222118898256144
698327893937341551
95209433774316538
294626493525181059
83298903936141000
311782692734337385
22704358329738247
743807382080971880
359317846735253331
853127608915372556
707359557892413303
750002582859303800
431450666360111699
907423122854282097
393027503230467462
409949492204525578
863330718803581057
910156647204373519
488848359176512545
572312074545748859
48485447531664120
263052020076480296
400849219551491946
625782429549802449
209881848716171954
157230815108730960
945812530536212803
244481507501127447
803294619886661706
771345640134696691
389762551180404918
121593610097225469
252719355766426405
637401877904331227
714139558988392826
415496200719770676
523105125204773185
902360754696780895
976823015169559171
666682327627844840
439220710500035951
418686927480222012
903662075592496210
573730744262620252
988120648200443184
785114955220694647
238794024528854306
953221763506771649
38311166619521596
601742923897571431
489853663518842998
663285687950581217
512882855021006367
797622172605673291
950705961525084211
70612909160885149
440126530589815692
382267772494049114
351831291516080658
86336429130218391
299749689435686834
758837231701128385
480444690280475260
126036044937816805
945374655647982040
3570049414473434
855620298298337506
833475928902826254
465052186252347467
429910343506887993
152889628770050857
66322290218732064
221313260109208308
441387315928021344
400817180737781837
886128309252074159
547418044663183069
830083919161316631
389966522625642983
699542130651882360
750020062822058911
212433419824001355
13268099945954375
382132995050334858
635134343508171279
464605822880623381
364584045117226644
541681583777626362
683530457133297011
563341526399891042
221120038957422622
703532703015921271
541615149366139655
976245910186123660
94355559542845429
426094387122984127
923911787410329991
91150369363781792
528700702387162184
262838547063057198
70087332655200410
873703044473198861
640131914724399645
360791396703674913
303227127632355414
339478780715451686
56697880692212865
969409523515891374
150573423739830468
152495666889131885
250465588992498785
88761237349381359
718143331969526855
243459184068895970
638557151424961295
793402909514745998
287940636054706577
571110703206856687
764347958908289986
706304634705303342
23664883499467173
846753530442795242
763575233494501465
197197853300688245
380621162024556200
686435534063227810
568739697143573050
295223514365442213
281174671641798699
91053064551569943
133600755314534323
21776935598633057
188402979358426546
181075794704518810
699829482323160852
501562003522263560
369054329634587387
801852925064100286
224244924972312210
841799746819534131
552475769136203197
277345006739039834
600949019378466129
581914332982248142
594855972273531490
756042791738294365
689137722197547756
728475087517780131
738504051235986331
275929481198121013
531248424558665501
798802288670048657
978577273643495495
583493768916546656
496483849620367216
573303533259834277
629886706191014014
989493182345595184
931056582862917465
150486650909632369
882908146023210752
724783518013096442
362135649457255257
595889422096342996
491508573690282624
865869491628929755
783322403379165486
844761149185701493
455470002292069598
150175844309986571
235820337153057267
540602836155247044
37894744764546024
68233781720995000
557632864616573699
164865091764031696
946543365304298639
486125785790730339
35452539590460727
564955877991609424
482663936771425422
375464221512471329
167380941923907040
385164110918959777
83335460144440071
932023990090103017
436447809965244365
660353715517640068
441853442686985327
969684421377140847
936355118708124114
852407118688568481
285922506152766946
690702100783744083
986835366470537936
647697603362602602
210503178270821155
699085140971096476
629833574744255926
632074131042468537
410707013663372003
548066874526572694
619282146142567266
344771574499491171
950232110182804941
853099451208623970
377694406824653415
909528643561643276
491456117401397509
725440432875792875
274376475031017534
944429576436890616
461490927659464714
248215608096750094
855744592338678620
616599584934057980
337243243702648098
943762876178178946
601368492220175491
914361243691191911
504971114868345702
3478973345835130
623962006651360742
178438016774500003
276794371305233418
491756438790853251
466577383913597078
785178086908817814
235229150663280669
305944130193003079
546954303076639433
91521147563526778
433514911415921729
320626342965068510
761790091856252247
234679210643060790
589151403817460675
605265145850750690
198843684797395624
657167934439233349
615719390178912842
738621943819847639
335443458573345559
131742231346982933
712790349773383631
668501069476206838
652704331483818771
840164079512176265
60915432887616535
433138498443505332
589812789646298787
924285217257175416
402944616479656519
11007751660570156
782152097422284002
349163808641413676
280552551477533782
354316136342921381
130921863571064594
793931591311649127
606186654235905854
505981953777647951
722668354506104896
209873377036510118
143313812449432769
573646593128734883
607437561565653135
897989116972244214
87708949678332045
740685536324699756
437722024826690170
112163899231118609
667807173157135143
515145513847035220
624793104444253776
759963405732758442
910165728390553872
692289580842047009
909411849380144499
309368781205751977
504455971060970415
262988840361891419
307213484391359023
310024205854710698
302124248623343796
585875961545724949
48176984271197634
602661225466945515
126470839819976867
992405720689768737
802141193563990292
493128381953455969
500133933077156723
207949069886165807
257540958988292243
118179713934757970
328253175240176705
875599616971890596
52070946274232606
863593910970160120
34864525661552068
997206275952346709
215465780049332015
763443293506094470
836248688536908854
644128603807657174
217430101625859718
485811729792171495
836786013213140152
930844609103796760
927374024153373086
397093673140827892
631458932743910883
314686651365533020
1543069763600686
496767725761221733
912960950393507074
728013161067548882
512370659232880138
981127370847164535
258893578326298366
20125176114760625
769487886642678542
513288266758860357
818036376791183096
635333070726498630
609808540194111534
532834244475417866
450579251070787627
179994032254364529
751991676976555650
296751857307832556
431616216117006877
854455850103568482
863161468362690343
216180627875043877
441010381919409708
809627844236745220
160095708011356232
558415679361871162
128476743561698940
979764154911752464
58834995355046898
521272805548746296
83972573292721772
243011536944862723
429374614513891342
115010412156590462
483844011776458357
128028539522924135
891001238729861463
309884094440049127
574142086387749873
506774639628355895
69515103182570757
408744988178354757
421958261106343823
992554524105902541
340772278894424320
154765041551518964
757199467529358633
823340745323277961
179309000155972
536580243006368261
959629201584216179
112028368588204896
269448903854300222
668076516522623800
338438361000225806
304774640388223720
389782026251022424
732475978085647799
363914173040971050
746996092710803438
484231243279536655
833421145400780487
454010519746718055
338436626571666943
414965322814628584
321873343079601730
881324568857834808
120689284219640073
627141093822468888
153832339301465557
249605686610079596
438643785056961664
218807199474978023
475420350022226111
154081150560367769
934085927461456677
909946368225456161
414751109430962978
501320201196413615
467700747735695195
469746190981634771
144648138352486734
150285257445427909
955888005817397939
371215451644760533
89662177667482108
35876546885609617
109909752904082867
385106591414939778
375666801803935723
282484345636316274
130387141610057557
390588511882596333
138328189462166886
853300063771106660
523611412202829705
707942912369577055
780676580359208094
178512275686196498
128123705401061704
366604573300136247
453986223607470134
220345350463044294
586738431137035654
800903333071663661
829679457796839950
762394410231682605
307659961607038857
804314003860036746
364782596947116492
746080500192707591
902492784853608636
914140336332845560
885798941006551278
885979006038815862
962873796926255741
294421013152961413
502277661640106717
176509896189201161
567684363940507198
734010268182211114
152045546708553952
362760313940959520
865695014607260600
950382953838010621
224438752388098458
686453598977535005
321982470716294365
77411906113668489
982131983976081454
934670972948217829
243195611973616560
798019635536062358
237926758591042783
900328186805506962
183108003678443871
293078426509064519
947728437145469782
329478522455528675
26768069861753037
538212716874817114
624556522555501261
42399432333440775
141573802101849926
451171242525466035
788436803532553800
918400991098131488
846283698370661011
183271545872702422
653396065400417012
533491115464068011
151171276479664888
883288034348135067
887366820469673769
260019255569253344
271635293916622833
517032075769694323
403104874247327845
436577190379458935
330892130172572614
939298656993437732
363133922121496244
653907134940165880
151985101777997607
822900484886784009
101718026606450739
200344665589511304
574520047484642451
112614213909389764
760077607654790318
733509386905708325
773207299209323225
801726458521708176
541488827472269383
129090320755986417
462432164100057542
101814628367423025
718138823238322375
335618472294312353
244877195779688443
726482446556833725
138939794459058587
218383113709239647
849035665501565419
873284258013307717
412823453340465034
532577398131118917
655514662320933504
105909377896163250
825534044476556257
928173116573084433
128194124538800809
570748711702318437
787703286624316628
34801255122580683
557397348145887865
323621189848846785
506991863679179762
852946982649881819
96974006916940642
637831887748701319
516755224123806478
330751972384049416
38267922253323072
411792387596193958
597620524150089047
237338349571939387
942673559537003275
408100503631164532
346359483242735804
937815966498840714
688049238388926321
999064866622325253
933485967300581784
553788159725775340
645718026032293749
245114461826360097
23539029857781362
859654362914008545
680869342532745212
775400167707289795
36679932214053740
43372666968613570
603778011563130679
580953593131717272
517680665777446299
900881298696187759
493318254460465192
306799806007600780
494671581439502031
143880857407662774
281274786100662703
724480758234913878
676926407362139471
148945546848815694
248617916603264866
841714705917798291
743409931722552714
506347774342241933
967481240371705157
33915436585391125
726641222011966677
876713918060765578
144790641805696362
48376305010355672
53769586307394187
988771317697249838
103278626740943489
324487366932247952
389994677888425047
793528738732379126
863313056495564547
692154002753315939
1936570244556184
206732484289204859
526320248368112896
332415787693784887
628161066609004238
5172487611882445
46348285975016452
87092609159648999
12760096887357578
635022680083306131
512918572307752937
641227123970428474
614241429303421352
942582073808416261
254167082923228645
526914071752731527
263945345495464210
884175220245112713
275137869911793440
657604147666094203
97818537465665900
527329594032068600
610707650837534622
409236040220688723
257304393131735914
964040785504994669
807370698798429243
814884245556774477
548667503529890049
939055095620401532
38248163807440839
508333038839270620
227134390042704707
549157596047621763
926164085414862664
869628117948603232
321355904030082597
41392867654294594
467631987792689262
355323339472545959
641546971064478133
995587941075492066
452727842842128061
733827553970695945
660845183138502857
682263254262894517
279469174275879484
973491393841062302
225409596146538600
139750624953001119
659237813311418058
645612498178043876
521198047380875081
951526359767897989
267536246323895248
385964963835713827
97180014160442700
909928708476890103
508513663472212905
931424723606638590
834678039885916969
177646084940544134
805521673671387935
506159500008173027
772592489442492834
903040840963883622
859663357615907045
588337286808827551
864503226590505294
186948978402519257
594004437801319744
735354257014975440
699421013908619746
169981645344596144
435491502271170889
24938757426851935
161664330903626193
979150864130670559
278862338371012257
365452821582412821
388000042514083260
574570781065189593
219718813189222105
781519276016951052
589490559772426235
321979876380976698
410961410341667565
749357212877215021
551432064399188007
605232894617945626
215972704338668255
451421123089869235
759441994122300015
967055660988990915
821659747288327436
421412596390046394
92114581048035163
271117626964851954
816700434999281110
22072047527996583
654658960077116166
349501090191995558
774583649340423200
194088807084486771
698146357019502625
709952264892322261
504968514080280672
227166549569104323
669965262092010300
487813693751037035
667838218219448535
931236993364421437
676192698783129169
46460569872974246
763322317909533306
264432053138614756
567942491394214887
172044041040201960
30573435198409404
117348773587915157
566127328144292008
81941155249167023
182912640105286601
148538150691160241
918204479235286150
873357167682702268
818195732308450498
321417701229474467
530537918002600078
757687264036856280
315336942002749251
700470445619507703
975126997927884045
23947793132765013
231335789004836814
780371109153355945
946569159085075257
637247951328083801
245743054141445160
467039630391085144
138611982044649414
445661273936837532
963040808170815437
102837688650378173
733656379909647625
335787487795346158
296346595758821231
442709146794149734
886008685660906186
992402362931312694
558603365397953785
93813786410490336
490010303978506614
359575436002388235
652559775969724626
922138073934662078
810788281794307121
380542587116497750
264111176388397839
169912851576199120
548561592122563680
499295473883621832
66539332583333998
682906781556479895
54393683063076640
872964907305352046
799600893261027298
55034022765415656
521851254723173736
459816736815525424
631152971997121266
36951265431382073
665989462945744512
665745032277570073
737368595275662487
729933140804575211
895472546646024422
414184606589965499
687928625443250341
103317266211820469
478044614483335626
26611794900536510
854358238749227923
800752608221003801
543812954526299270
528467346379150692
889403000295256467
987584481038336493
750005749464527422
295852035972291074
162660759814270588
155951343475206615
862446555755612479
367622322111230324
104602712081763576
413742223918047206
990582298732866700
330668068086065593
584041535316123533
970557355170773626
326614813465639015
764544221130295097
83841739908410049
472832730027312260
96700935518839895
599723682101125775
9670559336136900
607816016331858563
847267460224903110
906475201831723680
178222292622988966
826349452534529018
321060318209683733
825053409652141421
722734684732355848
661220082880434031
40168489516772870
3414418554899894
255422079873794989
984942182025961918
718821206206365496
595001062091770496
662744006058697939
804214947742137794
934714232067177350
173199189991165536
125501796878704878
347804280037442521
182133344972063673
67726074168270655
923620316095160805
228133534575675722
268421030207710673
592927236821362095
740591606045523660
778146335175624650
917316960207900867
631991042139997289
7012498063693625
613909736031575305
254431665064728500
539200905592619003
494126643825524455
805888671262939693
130899041194182079
719536278410409464
784561951772096791
427959687045260103
122596783244378425
788302088178934998
9243925241955367
256646604135194337
169352330011344739
343699568602776348
587803715356751098
130614526087492998
195557307505182646
908759570170783510
317831571347202717
718429752230125858
26884529898276757
719780314771619406
799651135472804255
383658181854776475
354072953531708855
71589692045792476
63611817142472620
882855102336664388
771351986814977425
415466802681670972
860975618263346943
127156106900910202
924476718351543051
309334436303316865
129541963564111703
98863782175081572
824649271720480814
581063554427057180
970060720811692089
764096592398552979
981014235657082008
607009834834682002
88944887526844322
640147675269886719
860035677990165898
6851905800178252
846583344133810977
796467360239351076
591850369192843486
570219389003572966
596654705059941873
442038230488035510
54065043320347286
929266658782111343
975461278542106154
709270885706097617
881415367512126096
451525552090598681
702828861714093320
321629645696953702
66122835499765978
995866832057434476
841461245699781382
143617557449665959
58763748424223550
816393905336842739
308248028837190586
119626823945330686
938193444264513299
584930082753298642
13367311886003749
621603385814633451
759487474672824098
319353220929189203
13860777908034029
219756759549269827
300386495383731634
587302159841532602
777468021669901259
668365362145919866
477044189202263022
85874846601083759
900816024770739541
191404260314347773
305299960505088403
430764891696487628
227348383861619766
504487801180758748
27879589765985326
878916107316691585
751652202358874589
168909731601930810
568081552496871137
822947006138581512
841602465437565663
487187484254822858
635259133525154215
994980374771394089
931046032077489902
912900568981046529
284804780760071085
770718119205449240
757139026773605334
686428015073996498
704535102266283645
361601119003972296
257091486290410075
50113662883269377
354241197190392006
867746011191928033
200465303709485780
32537324808047707
809520886299598023
871099242579593442
804435963379592510
869359362244197793
710745727221819540
945757291625037706
336550090370491429
588428483578425323
477930844379377376
953879088404313427
365162632438316189
510563149128244013
981334692778295460
38689981060195004
416177313739610047
366086938972355854
749958170553651546
765019288482212512
882292691868300301
181969734798480169
65172259024257517
525745021048444636
898572409081059042
60519181575889552
442732337672937487
395219922068757651
711106726942372198
364271350131971772
693167803731853389
968490118545799852
427623970185629180
617814165940207919
740196822128345885
527623680414011659
36535058193397926
234703669579342080
30131840541223399
527815847305754858
122108466341219335
643615454779698780
87600639375361665
551731775461013568
209894800226748695
148372669932336628
505336461468383944
928089650012603757
539107716557045342
255482776838014125
216096012573345776
371375298964740762
318132412934733745
409416296314741476
507617124684738095
928688411324143937
987550701364309388
521459065334947845
193516896374103097
413344863198461375
704933283739798701
60696821394550325
434161015145279144
311256248938832566
54239131579706746
808924956048887178
283082770816663443
280976660534236327
257660790327501699
131169907017578936
533643406927201352
664162380062101717
74002274255639079
110932402992619931
266464085274871337
110468423403971275
68435605317310586
928485915562575581
71205403391830399
660317127250913355
838716864238299628
952856288976163750
36192367286064508
987234431127293035
624661723505447574
892766236780584074
987058993200373434
75879273579360407
955030049845139705
95182075638389306
439020595079881732
73237024531170953
591026873335177635
617846449457085334
519532226795570897
810895680613247678
652248186535443275
750940611651138643
873681569274601540
745982828889856112
459180512391289433
571292744838123800
716083821887535827
474343855656554891
749817560717763626
862909832617355000
85055406131185075
88417561311344191
831908679269550778
606324448220019985
383083484527192728
189685456167466579
289717193996338202
738335023736808014
525819999058921831
282151502190494835
945084483246016151
530387707413907832
477563792149887283
937558147327067651
548501539665754378
428751433280633000
446508387310963295
589246852514622260
809266716056655141
196211377824763658
530932413743447497
867489096918757640
13453555203119823
733856095639937113
47126567159825469
282491198167196882
649510940993009571
337927898102767720
270402944437587447
353546201867571102
777137440326294798
75928239548587671
622247415533023424
118403428836263049
906799682772870690
384000784662277302
152156064027286561
28470159457873790
435177697172409934
938519036528779106
843660723360303677
8650676825310694
59184181889328943
554537303824280602
561780198844529820
154664122801336062
961535019372052994
568435804979880993
610296571334404070
813257414529844377
494965417599174690
421397063780317585
342111781917355458
727279118575535678
818019160130670576
569994794270149332
264884123155471409
82626084416462103
562903644529077212
321659673842545102
763889161696411880
89614009328292762
443362185308808678
408644427449639753
334178866977590559
472574769712241904
698067900628568887
290395506340011679
522294858726656191
525373883940750603
150316539912061656
848158938437889185
751001329241927959
641488217499731979
309035837540587034
617698457003297370
21725340519362148
290584595337157529
797514080698988122
439711720902395423
707934945975634943
249050528367766351
11402442856308158
476578313943539434
828950271774820967
677239974447658443
621424279919196310
717466358507523274
649637072275269320
782091227027631589
598067451011412160
736362630413098479
409681601492313482
721020446688664587
243446931713083409
106996151248237341
74388857579577416
438708420433867844
66656523631064226
277926522687614116
919010447649296584
2266224840292120
412090749571531273
133676781722039512
474491848081074971
723881195580449635
719636160721603339
700663689511684990
327216166360454028
889434020464035253
952747727218584174
925195121406676951
931691126872650318
988522878053150695
130808324488541858
837093400605941788
805541998392497883
189036160008519788
964792233448459545
505789529729763580
947874523125377937
846149239014341127
15883124117990887
518311493155030289
149165679197993240
177465692431592221
54464014888691497
300486007371975793
559313127928510943
354336877034152089
904090115068162937
724251608616913190
289340574245944998
135484333285138559
68546436974302007
560764999382175760
792780582871341471
75559822724412352
406355419211827845
710147905379047580
339660256403003716
359366847806419561
61010560411753436
935978689793598640
465740108187970559
581651730067045099
691954614886677872
799185020180769823
673602837448238494
27106638146848129
378556171709419661
23419258271488107
522703745205608160
901682733990905785
376279224877787466
641132592536113170
378470518755288333
75148807623141359
308163151520212462
791596241159377470
687530007770773835
208074185491005669
831447833910875761
827427894785810963
394301392261963839
479290681428210976
206021624429343743
145723073753989729
871609369215435141
938793642647933578
126712070804400256
121327265920516356
167433159298864927
603996989276472779
228886278368814585
465800945150349918
767228475209919767
158220125984710127
719517910777925183
431798613040790775
436439540747743441
166342099184197595
888577755647175246
9723342359958760
415162543456260287
902843155412378149
140338486786568619
340771485226231559
767882979974545915
343070417871610830
124900779280066029
901565609220270320
2887474247066599
48884188179068901
974265932743814484
795362962928211684
703404330154587065
475430233612951085
961182374376467631
777800627254410846
87668248020349027
287280287960691786
893519911497784298
536301638671275845
824991041541733455
390593352202864492
717112801981404875
338016260790096650
52752034059984941
41140437654724185
23079536901375153
905703305776073477
545024950230660469
410345137322343026
179524516328814371
63905206508242809
571290610614152630
55373544558187408
72711874640060830
417546312757183201
561363920177953331
97009000948843463
915915999743437080
748967688352841116
660487656043004777
843110447874228906
533076795877081979
861158949246198108
696766436021923974
31330568904339676
101061617059899164
318297922650780843
812697325230685943
905593323192611752
509957076358367813
222573191377165910
998639432857505326
473225104106755192
756451727302691830
656610316231278963
923515701847071374
233922466774120408
155385488723344717
26265086433646233
331150032533675779
534606016991533685
643771783719435249
750560003229259780
311926787625102088
816163313933114159
171587471712232024
798931621391312838
263919219751932641
216675444555896633
2562155473893244
369023572509036524
499253713318693
700323278968263022
988861376828955241
133001256744456713
29136262636586045
694485796850166214
23290601129082316
446480502572713599
171230679138237924
284008354367137046
760062832494359381
811484996949085257
294302358536293049
385604938813981777
637844307710986087
533240877779945530
345935988777601956
749358871646399515
331617929950702669
98853554183468208
859161447580183381
9214263414005476
456538866520580175
702143188314884460
3024734552655621
564869313107722052
143846367817001816
718762429228465051
492174022393166152
386759059886440894
752618748812351115
786070339321881445
769545016574727417
600428768048742058
144576475287855776
181741799699189454
41679272046310065
844450207116422319
706494317282237441
916061334856358408
220291325550258312
177927459052467281
895471759640465996
16676236791933625
473562739753363827
825083294683648857
827977379449167815
91700044199803824
413402663242746674
537949216411776950
217977867134188610
701254544250900747
564020596731386903
773788893487409455
707974009915550249
48827972641145823
202815852423514563
57166645035809935
748736316715203123
386198176040852665
497298908728056356
880234416912425885
535936430194463389
117392493877623539
919127119738324141
982042760819660072
878886822734452473
748503632582439069
784514541559758312
96566389621079136
260122031681412010
197915976926832513
472782271066362849
24267501263403879
856715645982819599
620475149617124596
949009487725538348
664940403015741376
172641363038006820
327797829902374971
193971071651088048
963290839513657326
264195463187660863
997477736767864908
593397377312824814
295321544097254899
929290487172581066
198187143643911169
895558969205327431
903795214206623936
351521587474326520
71625493504577385
312708634563833501
342996832787684175
81597703281251908
967740700824340536
635988020502951716
224875023758787137
3671317537920597
249309086086185618
785966456017369230
871556719071967645
581619475806230401
525230834131089201
345215202100661327
182926962291675248
637489689478258140
601104458608942300
222214531646698484
588562042121318095
59959674159262749
422523179066188646
990933766054792006
692785824959620429
194683904648595701
917464880917872404
830086568060252085
920365176832792741
26787410672225930
298167466409098226
927275735430232057
838831910508657936
932057897716009458
564301442357846364
679578239714327404
311855207381557741
486680806016395959
638461885455000962
48871687679437221
773403255356935480
339543419467661912
113637984428060914
727310397984338408
530812899271059158
602129092508881865
947214691806638600
582921810170198716
477609232562467966
619528393180689127
150474750946836589
46725636070238536
474210113145922753
331413169745277981
365044623327617120
838514046877538260
484629257999570530
628533946369710919
182492471153573472
104916251700754658
167052747837454280
784335882605031870
653596702073236752
20507487500713026
441830520143103486
240696197867979650
120021906337139505
145627160416751122
529390691664820018
327783215580751852
918965429191503963
63765727395720130
103551530599278685
971007270194857823
331184839602445487
900919873612929381
807009317038400514
738707047679172967
348579673389059140
742215389935731610
19379053311196219
216777450103162938
45539331850232601
186020117694049596
88818534461135896
35686242325262370
328360232726858076
967265942077009798
855972653964637978
536718200311113042
555117868262794225
817788680068435031
398904563023223458
433145153424428290
584861166160713933
958689614259178817
316529738487267082
337412862592876512
779189708942706295
207659021595299552
198993282413688606
806108706700967266
920539785591675875
949243461765471332
893095890809302937
92921162486165314
907591167814745992
595915587725810438
127515677316529850
17810345222962470
810835468187125532
932678664074904986
326833162123101075
484033210260041725
269113929868934949
941455134162417686
29095136495130066
956447186833614218
92109124069114426
429484816344877807
851514513691198712
630926555895518184
685987308011774138
357928547189784249
184887173956806664
109841217050959098
876839155483744298
808532685211760536
881260337916722444
406783346656473605
12870781609695952
710702256462022858
201907908916388827
905080126933691738
405375871598984431
854566153695685348
780404806259178018
989212622124694108
578660406428459175
289594690900551722
495453197301237452
860263501417713819
21299003974451761
967379906513916583
388236635678258037
806784085835537205
178962742110231412
676295478031153435
279610453020911091
434689901695240942
859525416189823172
242318076395430217
892448323109098994
711901072930527455
940281799515523343
122354181530723363
737674153738429792
972052066124531424
496505751620799455
339123932057863559
25682314136078090
829735770255546654
161215139355031433
896188659846173132
865371729518247298
680405778155492486
745647574489115011
280588947244951024
322813291105669220
516851517829480063
272769736775573134
468302644497621952
974418017968621162
261487478710305539
227424092730762800
629561322375679592
211673694201337083
532788286707602364
48968714155804004
966774146495160616
963578687911232599
318155453557024035
521058736904048384
84496735795192520
914363937537725786
270013569283480369
190142450894786532
540096523120443665
958200948720950974
113491808241651766
13253106944459111
884319498473084814
175847053320678726
940156775840868763
654762098149271835
110067174604299939
804454129714603662
386335361140189893
137553670994252011
809580770565907826
705573078085871018
473647211489638214
502478109106662355
163075174296024799
983108420964239926
141036822992629532
990407948747816081
221103473554262589
18923145857352713
846879229760888516
459558712446709463
879967453294024978
846167192153953139
170853652666793643
10671601394375316
272035371260446351
256486081245148397
893314036702528189
337551689553221530
90612957438056230
93533714049768570
670262781889133003
121613948360024327
884718050623862780
578992424850440494
473530795852234014
558849197044811980
348125596453394013
817559736600295621
868262461423841264
608175944325282617
951542545418323802
314520014727144190
155973138143465224
527075064993665627
617553404561604400
94044295098672418
995243027080400886
789179240141683126
346445815989295295
773482979261199786
367955051886317786
109335601957888381
818922496007925060
677365134175398762
710295633077819221
825059989705396008
305924487991832432
605314816509208033
809023252354571266
417618406001978355
732627054337971620
348312112017717667
648984418365092916
994404367747604113
207563803753581924
987732541153192628
412336241007892224
888725612500459629
116892187591731170
814280299976657870
321826563316525060
357893006059448241
670039356383797828
883333615986177739
319826273649924782
893816492667116860
91438540637051301
235079949860495250
533386078251303311
183355796733556969
490013813777417210
583900817708521817
179725676053881188
23183773800292144
986341517861309572
362167867621968834
251060130213595844
337212652272477433
85341856602501439
971507135626709083
807653342264244397
804090348490623433
238941524902113481
622656135627125167
517312990612425697
627107287757873749
267540764328888680
371228359938004023
266479890942685018
853300885914772381
318869797188864787
747260780016642948
259525742261441853
440470930415315361
858912875393570057
363883306403522516
756046139385224894
559029708825093825
319975264553453923
870389194900391328
286480831804045232
451522501195555686
444614427181437050
217723161676248337
971754945559626226
789121876852657499
490357020601527438
333213455270859142
788860601172791541
477586888089048940
521773300646518071
777952100379453697
415460614301857103
994129464218855634
492417614579815131
655421436144505821
155473058312837140
701234581052103871
919363075464933924
995168281582656514
490351177878611584
596407917317018059
732330575577016233
936707773790254245
430077235688361285
109241196791187867
612850374421138242
142783273277260200
695842049449034838
952267616965439115
703215064820232713
862183595348828255
797192912679847230
269809634797334529
921064137083809025
362015968191429755
709545793384751126
408238577223013398
275022324906417494
157147986589896271
610865792559358399
814222086374676100
799667715913605321
261377525283563728
607125484671805308
385844433443433101
411279942528347656
208696021581949152
467060779430083530
332440401847941249
659687255412835675
41610478897365949
669172050749729212
53408931375562239
205352405964024531
481262207334070314
830197424671817017
365050472319537858
745678453120586769
606530297360142241
532263061878793143
65016203892783439
468850456173615961
363720173271972503
377187145748263563
479638029488770472
518692802243188339
209661671717869477
283748979330767226
248404240122592098
695300833469960191
155121831867363187
863349823341221529
189893567806387017
350561546175118669
275397681010294735
83889777716565073
106104240001634053
32792977481373572
784534221209679764
458316570378602801
489460116288754096
538756756775479176
353182530712610381
271878064082781319
70527427518900286
830527258511068133
438335391729162364
918381876865466030
456919890752527651
691001984930010176
187541433634644471
277220105132035758
817628670777092571
879718241006149721
67116417568401268
46136758449692371
890752362894014793
799703200480411369
117002281840174311
365829174896514595
746704248287735150
887078153594379556
677300645736915243
679432799088062412
25453194784570066
118807311645345306
980485395439841639
289672717757555390
965695980330505242
555656170535760489
712571655494306973
705622034023962891
886031845933049205
971131746681464728
649738364839440140
704853988188485521
596757557924372537
965840599702382493
224292748590386667
278536264357082444
381928591395804725
420779882920996965
957047441948318371
674722632549253881
282169660915459438
87225222863833935
915537291590080133
784670887469761155
436684207248192345
577700675734166250
951135751771500224
369407970172834359
771243887755976342
592387642395567449
78792226137487815
353305670097999161
738410601570010755
325477568092987292
981831010862822067
666528213831315189
432280243495429547
297959799681236304
116506126981111243
565007190720902270
357086832442840929
491752345283641325
795321561533102359
836240092977809192
843651130010515202
248235952221397554
970653977963055643
381968288374134865
754831663794496291
372053937922727114
158235785241403534
394667335096759564
205838728510432164
507140081754244102
49855518201749810
584871829068838612
575997131930028313
528783588190544236
161026714829095699
445020247230427270
648320241613192262
679403952233091756
652313834854046383
94452541897079216
505757721190852470
157771211895533087
657945700690131892
321768637046913307
758938552066668909
791501654930505130
763208596433760504
264122499637683055
900752988310672441
77822035149986331
923370330722352870
443532381904879081
72893273382213204
627346775910554032
322757305356606601
195831293700440502
816189343761060451
425936273273570396
979824665300813087
563520712140368764
697968005171487487
787356939921197917
229034899149337451
870800161135155917
164386739698617859
956014297254940420
755755779520228158
18790849595355317
275677814273412855
523872515732054286
163705890619945654
902423961093608122
9599388062175749
858335071684022436
867501269877109076
231948621740361903
627096181632299056
231726539331301054
613449557596209805
77392219718592547
10105205836137756
317785528379606298
859214222405770247
886505911983976654
694213956543943408
32091780799093055
656810887501802094
274005358036658435
738017846419516664
354276018485094590
554873893510538290
581866672162744301
29532414992964609
250591901980084460
942456335030595202
548522805253278741
991604589920589201
826017902126757448
439598986190199241
24951014519321780
169359348528014342
815587804073459783
327163663416160999
28416012000323162
413831623729953661
271992370114782192
510637882749550513
749032758110416381
231608981007450365
117224976328957714
627596917275820271
521899501750387098
866540422660337669
147643773218220700
535880485256301716
630996780159133580
287901999088987979
623920144444591801
417047586989843509
981221148902289766
362848705090530491
303327432771841306
419015815395976967
956080429635663837
163466086901765802
370440135980663867
686293110450686570
825973998267815972
671227785799261029
698284681627595521
870613461458059635
693770355632070537
192576457685186742
842190452821691419
494299636095480950
257902670092797683
384347667590634319
716865080930728305
911865826170325104
182232120722423398
911375599603207767
790494103676219381
676512224616314518
553843635874695273
317538326523329267
243734561253323445
886056065797256145
339336091790910881
836652570088552370
71343696415434428
261678912321382464
958442149533978689
621709912183990305
276005266154583642
588110455760074411
688988482241464208
164839669781490749
903402075895235751
887144661724255266
884746458111535984
209929744554401765
353003553168546173
253699405975971624
396120927006871265
138373719772815148
923274326556684085
982265737912152134
419267942902849148
15577819500516668
457454445424023417
156526939237305133
378311833791136338
279534839021355495
873917445779635242
988746606952040336
353135567468644764
359209656096766999
429856972172355202
44240423036875175
894193357301370757
577710883105823001
682579768195530114
984942082685779832
10122154167113097
631798355930799881
904961903480295882
713491931190910877
226159228339118105
375778486345998837
651817535592493414
943166521676493459
848291362737092302
290399903256018858
344759440549136233
655757447322414650
751578690689444854
87396168149412571
306584475968523077
503293818493227303
403971864167035930
972721361794713328
942092667673527918
790713919333835094
452214276953570706
322547008762699128
184987791490071936
175706504589474597
808574742982581191
622816811054357533
474814138242646657
694149082914928153
806609375684426676
577211372023329409
598156564700977676
301394379589615122
747162377360477140
579831600130608349
228360953223020693
19409326084354821
311870279143995422
405732109212388174
563485300351351322
206299646438082654
166661762507688357
77836318484319914
307635790058655375
677832386616292350
716693551191570898
645333502662942721
449197968191471941
210849244199111191
543066239600496294
704304622089818219
836869963344788931
711455789502411552
242005431445040886
7329663348261750
590725506531032758
299861824149255745
154888534611765765
528012391086742980
670318458511900297
111050897459035233
305851992431033191
173430254197337290
260349341261059720
346200091795299290
15435968984992106
488319765059768152
789432741364777259
451873940692203025
971334805504937397
702773424220732714
940371667764964393
70766379316881099
764894625926940851
245877587898965504
228549026759840661
956081742743929797
223264105102427440
945052256937931108
379907052388969911
35500274651147313
889274708878337443
401735921660461780
843731750825721318
454071941812132330
122163557227808266
449924587276416022
537102283934943125
770475258252289115
482410592271165311
37106237237591831
426754924377289651
455732921967582324
559202401564388779
838105647283698511
761468648991279234
568078829793660193
172283673227285289
40543801828949303
221603266172870442
720439935448129835
507968084185096751
414681225260868551
925099029758541890
459969919651650894
599693528846008631
317779682079522031
593142697013185937
291928232057815030
894906898065182277
342298505360650635
227933382132845620
298489963919765578
75396226210081389
305269336030914906
645502886344530702
563254193312743315
527297925952394707
867658128159583898
328462820838847530
570721762714582370
113447570543596928
381514819103792521
2812124243624139
479414081816849827
998783204592547070
925211134079755880
432373790893574814
457971719531597787
816394700536930947
252864210624354547
543197048867790386
630349996770406143
173243245007771165
74365993430065837
164846889103428687
838002455828230126
972307551895735009
959013780201576712
927260096937490474
592023377005408284
904557085904781484
840719209351526055
273414978366939750
745015966143544280
328012886636484997
652357404203905427
622272756985256710
741169486224939518
484988485530266284
801099559022680610
454913998788102471
750560321550044563
260418285878119521
76065584771629320
893406124791882501
860891109250707585
748024318543807466
700539735465550942
931089810419466443
510674369201736170
673421579934399239
694864053080253195
985385058437395820
925421049482619224
785953623230250847
811701860772773941
737329726806226256
222616606685074042
525395539882201632
573669605889177343
575768350878846513
823023936911980711
753288801035650901
697470202967825849
834332873381703265
897525879522527794
747438236061037968
411853032035719579
558318028337167491
566129413217274879
543559981366457679
904311791479317039
983566516932542179
768434855481165085
351391411136721029
668306555659916492
246252551893619441
228641224489712155
531660134138249752
257906878237906983
374116102162543840
605457056415168679
965628624810501478
530018199944796115
798176222861729189
739739100914673456
894746837962724026
190548033207631564
929206795113305583
299020676948806659
410146510334084922
194026621515211045
307068596936156635
677520160097250564
418670303987201806
493495442508753197
695870894348300651
352621794086816425
486650092163256021
994614609828572707
206022081419865246
858089055016139126
123038714526784139
292899455072637805
147605366461494002
263262075483915318
959744834846928327
776017691839422496
462462731793115343
215180087886880394
785167814748752418
148969143381079915
703567977068229615
421227113800260032
153561890446035106
25627847910598018
678674162288653730
156745828921147069
542846262568439249
295896896354268679
200085525181697739
500470005793063408
813459104601566696
337006602651600375
559116716630525943
426367429556069037
165116236549951643
498857224904674032
816454478061001919
722968620087499450
216081458731394130
96705805208038079
43927968800479047
981977812000988629
218445368488002726
676665288182147923
398384905861933665
735789228883701024
916104638592526063
215682030165613797
385993604602384778
682365832548829533
399321894639184395
221187313494075197
366723813126952857
685217243227257165
828503571860795651
520253117024630695
529394901720271331
898790670416892476
34086740938080615
156021726187268713
569373857763053064
388431785597083669
571846422176088757
579354694206721535
171158214491769160
705188449498124526
629694590310403562
57729282480289481
751892071296718882
441070314160648264
953668510409936095
5102049457054327
421040233619658187
914399693702066909
295581876405551452
275540424643880944
183715163905509994
738243974895591144
570903849367106904
50377589543809170
61058958556396810
526562310646309171
11125953799086447
667163451195548662
930516836365032341
261976821638696290
675067480407399771
495579897676297945
364000641764014100
506504613490429854
715863110555977345
139305343475816150
184094399665813006
312398824954723042
532756183668640586
272419264350870027
545855833582878130
448385310457815125
185491201143256052
308496846947852312
64898838254137916
535983405677336134
381790366448291407
432617857891857730
383440507668532124
491827297920976032
266841473464686919
271811102238309168
432131288533462530
495669655704182210
442509016901275851
581488721888960771
118231915575659239
45577657520122587
862672333833650059
865630401005948629
313043223536084003
188213433153905128
240061011532600947
178212903152271724
636539486454926211
757576277685882978
358976287556399130
779912350874009435
105752851853309345
597342048927646614
425625013788246820
352083100182320889
473283742838522992
73160172239601009
787568575268004283
172763466173744541
721899663515736514
213254757702021921
900480065424374493
100360962993982908
357661901912283015
179317538070079031
999333982025245817
408777357269634280
15772181011203636
228909686229988493
342533088247977226
546468152589288579
132761019527454292
102506909513841791
200526496544658921
86457826832994582
666782087956295803
366083340550689546
300019544074907417
956926682192576015
823186894642366930
546233908366813596
867940320077430935
463286034184006020
16245293599095870
192472630595398230
225765701494132064
682801010139521501
482415090671407736
563246810822760298
738744302578192966
832279394724350503
417997201422994816
824906936605676858
226926745369420777
140463719698861218
379451583365609651
623138667397283904
753408274205216411
301925679183884646
585346084714675239
333216855151092389
269237149249663211
97517719201544327
367519141441295368
519260570349999239
104191412976095999
614180743379651919
680585725169170914
985088112751316902
966847887946128650
690273347773864810
3855751604632531
716848887413773524
255278434181645779
684624521040474552
794010443948966764
505805150567767781
260804106410862711
701233088475701532
139466056109729711
697524572607970862
164687727507307941
323161394562205797
995512670844686881
86711126427194796
915113774623511684
661090320208926825
913174466228137906
629791950303352107
908310473540530384
853997510440710646
581803258854260151
102031060553226841
626281511757837908
504926287037085012
680777498532846953
35761304059340791
340907337568035971
29058095862702513
393365355721471816
211950327774768518
700790805370986965
410084384539669373
83324080854672646
455062830112084728
394394735228972566
132671333373703631
543648193595947630
731673405473363026
785679352997408877
826316157319303091
794981649932266039
980067880430247992
177655924102189612
611468931731992257
957431668810076269
264558264047465870
223698333560538583
211846562242774052
238376254172925945
920136067282846355
640303875720778412
563050662271963144
887483074879455831
73114123880454241
803054920692280350
162003906525527366
62759106380134104
528986507551944283
264707969218320740
455114788276374715
234923445363098201
650356680513729983
31966964508552400
767693926017716449
736509683771432603
452341488339778840
329774787977317242
205864308116945211
128965642679769557
512283842975081426
212032114723325082
353295990888148470
243643694889244223
624546902069648801
153906020445239609
693812736930885236
753872945531189439
116157995261551863
203376993194419738
761070114464602763
199746266810954188
749842891951219471
157914931295581346
550770168515533133
662420972578043937
373900272911603013
566889209447127991
577933364308723581
564753115829007654
459464516335220123
514935460109977705
492011634604282919
121530036799484579
391363589133040110
946160773834728517
64782295496845315
625410765446383256
218076100375241643
970831811983452290
984919012011384066
676747361479904894
405764582440378152
951408716753338832
672800747187455202
549501974445266034
804671745153824109
972884166898869597
207207458369729581
446348026453421296
543947935697241720
6303145468772749
263208753751323793
107019744443879764
401393993845159322
698483376486293674
524491694473843082
942639887940647106
316235483048853089
577397642545465143
449426704763733597
987440833512374901
147750882755819452
426200375279302573
122414043614781768
87074236390033483
544583303414088830
599056942907419129
14841072948239752
153592890781103928
437637598817714011
910032216346051599
826699680493471963
268853105630840980
992690744536170259
631144429515490271
237647572636759909
606676479570441359
514836737236757779
31420610741477961
127045155988528623
568685479036810403
165623691749460569
725368368536802092
379749459808810127
844216043959110373
962481114270694157
47052623346480332
650759303368125005
982194471943461296
356981493549605328
301121887743741796
350361488719063137
149541769292024586
664458358166670187
553942697171543213
290974599660381669
719824277194770478
317257656441416238
201448337172533069
814728395339238226
681894870020178198
416255622731440522
390453213173592677
896084848016188905
656630468507747293
133832794179002743
741792317246896377
216033054999587650
402315979526071394
540208432231404039
111370621287409042
310201753282071760
625979224616481713
786234481908764395
731371842790224295
348213525573802821
21610118202115977
780937516384137929
362437303750868258
575869689292651065
266579430771577311
444768857776435967
364742457474518497
667162456921891731
619710011372243033
159092364926552808
12504588226584372
309549717798075165
788695379143416794
3332288293566339
984291805907534186
737461536057389521
774742569408856053
86899082742760138
506154095427733809
830992095287441828
427394217773843041
663750872683847524
222921519956086596
442180026513950921
807582627832199440
277093951039587255
83463818677080474
165932574400067110
569698626208625684
702368646702369876
629013334700086723
809899631512590217
605863347027269493
205174796692645532
185580321917620108
199288324903852613
90173086286245853
227015863683803275
339212081512363792
793249593793908906
778942527221953648
355300993773117044
220107285195575697
970726170500778209
907476960138878114
358643213707364217
877668934042177668
892735519429802941
68488152539764168
196313183316773116
576188489503947025
918154018525345826
203103098608177848
494221113010766388
685911911113399195
789684477200850562
302682236582898497
127910010068578239
260922455795833648
459317087539489908
410571836018363283
522782166780663112
196156503061368867
299754861697675812
745435694804524770
902531167952718750
880245359301992321
3240318896529975
105039174532926303
700647927898306251
557344989419052130
638951099158378656
747457212326078548
979098127757206868
357667588752139208
854722543562741117
777786346392774644
326139803734618838
895827694673238010
350899260438090651
701681940531675518
760235940465500538
737166998902386100
19006624343740732
694553394343577201
803880176506679247
915333692276498791
376884309826498052
968693207167238112
975843649685344808
344886344822222783
982212151607513194
89099380352167398
797617705969571284
741327257578265502
462042634257837582
268471353146745507
9996405662591368
685850165795651193
227802839101726878
204305808441659054
611107381960724617
188792115120571840
446356886847747194
810243864252210874
516282209891919608
368879018428237553
497333016767758969
136323082162262713
821887035404681238
517735160677740769
127021658790499614
233311322752521341
69326728509731588
726979456399392669
979128609605518608
443811306619220407
549149590437317137
869315573629195183
545848642224210239
29806447411338466
689665102635255482
811543411658108272
776138671449635498
809247001498196467
939072848859762782
5530058667156559
666391513461694445
7441551239601615
598479486913615789
126125652420326625
943668438084864558
56549714264520855
254650506691177395
86623611900888047
55284168232288668
570059962883040051
190802015876748237
776684627457608777
588879876220792324
264509418003996735
426580341515286919
686463985274248223
233534645083764340
436464602395250556
676346089561474438
423738561077786461
78483113954232934
62378919484813026
8757372397779215
816495523858231465
230647553927801469
333755095431030193
270199875239646417
645313629883760006
13850686714102403
173913208618290098
292152052936647869
647950009255110164
371576640044080443
955002932146503943
838729792815569717
725524007829013580
469088670184482726
367574783578199412
684759099582643386
555658435610022803
603838196158186657
838310527469912062
780582977503877989
845427796749746861
366575964864158313
896393415273418303
549747064546923559
437178307469135480
790626957699311934
733150862722190087
712483215962294152
274990407706413839
389686422926656022
881870007729038200
104468112896527978
554442165028039186
187796084524465384
778830263763569244
649664656008202421
143922634208933696
60201819858377315
668002781597213295
202264094820238732
513471507632668382
646383186883589246
625534849542334341
426962511179474432
292381076728977764
80932076063156686
430795907019380307
674885844476616862
566037875342605306
387676213200087619
727898301567967276
512635247561490195
611298334268128917
715621794511212745
427966825546232713
767842969603853937
303833763331358764
522726084545357725
16354752449467317
225876350306183927
219166137108567593
301453022469594070
996011085187821601
807025892371520369
824976183381986292
955792164970365156
125701765939727359
398222837960768709
563922239748026969
603840517427012593
877286625596143014
13755745285422440
96488246529277733
42625374981355319
702239970728387087
106873942410578271
115007639007047193
731448735016482272
585146409737651948
361309453447001270
402159936111541784
809273146940184848
693245533188581501
818162379458761032
624473699101966144
722604971385413595
881950227243018507
789851771496577528
299101240590988477
283520996919975705
425967281660411833
758335843534045374
604161729456155985
128021867908446923
508356048027850066
672956475616839539
668252848285391609
180660071377283874
727750563331783059
270757171764058552
490683956196690207
12781435527287672
728611622201519522
195369641286506220
219794530438699061
116831933527701622
889495318796764065
540015059466853084
191874627204679719
77637288651654424
334364322120524376
400821029231628647
287629999696660842
289857758201524695
524403081796251802
677071720150484418
540343650174914581
908812093781179550
603562072677077195
164571937230651951
585303024954832816
732677678729932761
67629079558515809
635156090074939213
107754457815194070
820346264224214314
837949055763719140
677853320526954448
852014655834906793
115456489831830128
839185312367229143
453621576019948965
957182056468134639
335185482422792974
215695916116645805
488690524100609774
7563501176532902
52758358172704988
760954671569038846
344185981425829831
456658602356862142
18230880344276263
409759652381302272
162372945467538297
180477764906350250
310730952735140858
253386894624052778
530163799678169025
850244368335906756
117818470557571017
250415888301429458
182614600225225228
930144005526237941
757648300940723798
347371133603887010
905622301594486993
922823213241587231
307178320374321981
707440539122066804
652100206935407757
831922833405344394
23654374832569579
765969681516725067
965715313780444981
546244003642064179
85800718810157954
898489950766572284
574958461313969918
816783704912145826
672352193048356128
299024004602692779
45481281955964381
556162836641544577
742103500124851550
275264437659691600
21503554303086811
856254743559432189
378852877576501305
338581783229545112
167879378582198241
857034997465354820
853038897589060370
173590736315186359
47461921976845357
375704181744627064
326333149818522519
660025810475687894
405470350607390095
271351950983589564
690830714206806790
145327086289282524
272984237316673027
550961054092287441
500302663711509684
502438366502294426
905798253854993082
753620526642264498
527234111535756540
851433787258177336
328153869941501871
905047283749465756
800577502853380339
233770221342714299
72865214571491587
324950051122804165
849928416873382976
431607818374556078
297228383761129653
180045464190600108
120354771713036927
420157125314218077
36674173495576623
692081473728526739
620421606660792204
786359982247998472
16853585707023207
892861016098011880
148834017336940309
517809262592833019
423389148301059425
267003462797622685
913050737491125604
363290727260386885
812746028695618402
201666625046559308
437492382840148939
797471101914684746
406287607954845431
793015699311285621
905755920610872074
932755340497492552
592439800097462232
537308081668196226
526046122769529120
492519905482067216
635594667047736413
323797371481509521
496555798297436053
301501400580982362
640052870778147806
502895168165210900
91982180346496564
302139750460924548
245880555351810890
900745252680039874
5192390176516858
256292222451022463
959352242142417936
941369019108195301
393150810408473011
547193212356740707
598823525582491909
725356142490580194
874637177265067835
702671070221561314
824483155551160164
832981355056933311
814966899318790473
376390103235006706
98220640175345958
153440947633253065
200633436027937412
714726082418564927
164423405633079196
201628203803454699
687264950387955249
189489976272253300
992410347037491733
324789221707786970
848640449223737088
866783594012174701
149733839996535243
756485687226771277
892137114927250706
227189471244108021
645240293923091648
691736149956119323
429748602851804463
463954061520060895
166269838351079193
388452030895791507
110792203510282611
713215713824936835
96750718560174807
745217476129084603
371939006872896570
984339417773239308
113764450618435714
905575314599637173
567626157682253869
782892846921336905
290523185549028183
478949569088787639
566570165848615660
246245743091697925
29887561957400966
967880021054492198
606978502893063555
805505022228930316
254048103407281294
542779836555267536
164931744554910740
458103752713043901
592075399678240545
24554221232027166
512825232956764116
548087195963871821
712417513420980858
536729746558613661
99948434302103472
681978321189456103
744775224875665923
350714734860757021
816995763470058114
337203684966644622
415145977130508471
30956534806025955
383964088955287058
975730709897794721
520246242301466319
925872809440368826
658057764966399983
863470520419008190
826438547585016617
688085104027866976
256741069156069454
553033833777134937
846048553152323246
425613152896798619
363188035215517482
323485279092980188
221144776788303505
414633515289233990
561628453538796903
490925818443949405
531852789008720216
781591095614676530
290514340616098888
1501324861363126
446235508707249886
488366946981449564
686781573295295082
912532129228316931
110184234806348831
349786959973370072
866636294333104128
409662247787032709
642548104284579031
978106947363920872
909621622381217654
613757879730192536
149532386578973980
735677033636348675
359871642856867110
566769095998706874
914892578891320587
277248647468872813
883644222753141161
13286739553652838
516934659594838039
206304123978115909
879239631032716026
166087973412552034
138507243945389897
121927376445302810
174257765113744623
180204704899451502
531624779662308994
236310981331664822
409646156046908161
129176186768295948
756799094599719370
735154621413537767
35475752980207143
195512688540076035
29918209301001651
987739155788353663
210328245727695779
496327701423666309
454937036082778182
724730344572171510
665457183778893321
101881675670308439
682081626098997113
415522708016776732
691463149405244079
460858914943462186
997772857594979794
444050686076816790
501093285884399890
557163530473382262
289658842380806874
805165471725922049
30646399369049163
553909131614626089
766602535240810138
352701623916035598
791865724358150248
850202857615248286
864873344921620940
880336846528796695
554279079871223464
814182975571046412
972739329329407099
616260046361401118
734382980245134790
925017531346732777
686216426766600629
312952607663123684
31911965940382790
390104139023336339
719778312931391571
100809887627514294
398661416900766280
317789080335638811
348132828521269940
770942286148941771
201382051217780416
462442605401851493
178815950638719866
842656599894951856
715981947392158229
252594882304138855
687360882694451701
915067162543803171
580364283511795304
347666678099223552
928963715502964414
473072451143762811
789628907529155594
32886620151245210
320570215448103533
44581563670497906
948975225577333732
27973482532475862
162205621795813547
723543128130353501
121639287451598783
818566315599226442
601234966206277272
958929583299718255
934022609265897694
335991287706833251
87969520488101611
624047606205531668
501657775015635998
118276820434095644
575484815444352203
198253940309422662
951404563650752431
240903838941111576
407534618013841769
467885533408319892
529826229248420638
400428904593507793
30836220895278511
121363785784065173
488019644501715058
822760757980625112
240478553670102230
126092641736983273
400231328710238105
396327886777036305
893559220033991482
582965311944591129
698491755719608773
562261691655498609
318192207160155758
687711907102552457
626017101770884429
982263033331653792
432178344235890350
811722142914425025
145560266710481072
393667467005137484
361698711325597915
892223967690283899
648974078292581860
175640489113745708
989418573572214364
233966473859328706
735432045105193169
297037140088832373
902636433631492425
970381688264997558
987588673878104002
630103732403147276
1876614720437257
841929222168503799
684467683571892970
585730291752586299
721926486706190477
322165170423722314
610928415386622980
174878078567636768
653282689046024229
888521979535869714
375606888961242551
672489089631873838
430201812662938296
981210758379438763
32280646676179729
330101869690369436
903521897967947374
900936931171273742
54354636737142587
298647835689774103
461768033050773284
519832320204866399
41283898529483932
379294221610629113
908835980037791197
10156547816029247
835754825976685764
70182789252096532
207501065627246685
213533744112634212
686095646774394762
710592742250628580
665474090298308769
480927542294190104
921788093050624722
859352730533418338
32166796136141898
184524968021892032
556088728898922997
695644817160763945
307729403784713196
686829259223437742
746097861436879023
313091353406466016
432884822416745085
131176031551026178
979034163346555042
287089273299739413
397893985172461457
323718568038913534
836872734172735904
71142078750614026
894084906629733360
644074417579223606
141730053544961549
847849324026114981
900502956949103164
388976206428934505
864119330863807372
764861195617387366
308471615102170357
167548107923186862
801632998977439114
768981105046045919
364650913213269548
784709230500890872
384978852522519670
737727626671009599
302259249902259914
151532737265390217
813693115009559980
921683654788663475
611222764047892044
601342621866504628
271206945747597953
269782769579883007
483281050011310088
133800313175455818
843774617020899890
295072005304724670
16803702639020189
829920090192873273
264338746086965650
183004660071016013
306172342199123647
597742793081404032
113666988872963522
311082603214850801
464156738021556173
898373624529639241
434284384629755092
347321531053511370
556012444083692928
164197454506620061
697822210428123391
233290922862025086
421917762427089252
879464312116130468
981051173612817411
66675552711933360
106802783521927260
518487024668672579
399886735092835014
964381048612901791
793736856371392901
451381154872954276
745471068233311369
286386324129648498
303446591596721721
973767341512161200
864743154439561181
91659352516182605
445198063244370174
194197828041556593
527320331976116088
356142638294288423
819051080646969659
587177029456858401
161171361939827511
912114854136857750
102860263968862544
368417799253289594
215829995241919433
795817045964828190
390445611908396540
365748076954293202
677389834595326465
673456793373682162
63869024824839675
544497921569025289
102185180206141023
147067447543412578
973696748341488331
995547263259496976
353362949061964622
428915827236492958
926833601565890392
253650111005932400
47147500583447541
41296557953466733
365854091692049468
757015929374862807
214525623512358702
998369784924465964
680935289039281103
413862557472438763
641091074104173218
609055043658980894
684218389617918403
973917352576618739
947109457221291602
288490764851378419
501560590579050150
617975829090677749
197372407136519071
54195102131067180
28039028343946636
829967739100243432
412071865390027649
149909285384350236
720655661645992927
419868566710881350
709871526938927704
470383377638146060
302710340169389801
501350656792480996
834995676806410825
925776791360372553
730710609020281715
909806186794983814
240212698695998096
619484344172828593
259923904821503267
222231302384810765
994340483206582075
147948463247413321
748606994518918708
911108525668578664
139783076854282368
573236561589576344
356959384123190976
383492063264348840
948270607582796346
474607493842626118
17465867352200277
942303122226755291
722506578699324301
714260930909473922
293513157797009795
102036111220505409
793875357042589268
797058281634802581
952757840534699326
397074259556381198
759058009254925961
652007824643594851
4757017360521844
584460171452924327
767968939033579998
434608117115935708
917218655684589454
705555275747704938
3838767577399118
712345492108204674
712703045476853220
70563412084938737
266669106359944819
470277669525779441
49684080214946105
638724435716995246
869488962512387885
419475160884434007
390538016675356492
681722546333736298
209704480474372334
108134694810919419
219033130732371802
244204466974285498
102920969749877387
897376884144437421
949852923844512126
571286010077124244
34499310258176355
823188922099709276
2482618086772314
389587423726785472
306195484568561960
891273673250967930
467697531218540145
750099125394103632
27787613768590119
136560884257328811
866994350725538367
120796197960982665
433063714665988898
299140855356501012
306608248470240541
44236632059951454
10736600664924241
816100807307231279
760800187037436862
90312078443880880
784063765991915158
815369183648075717
146422440858068150
200171091210540495
998420163935746668
755403326641733185
56861162663732055
288038523304120836
290751478901854395
393431837577604272
393866666561835753
76715068870877736
321291890296812064
175231471838228845
278977960935762520
407578312742830304
620196874035963552
205498794116685679
76856626955851664
602352243332269911
749328448432570642
277256831053553129
779646570133625645
820504004291980468
867805780730159763
663721860029272010
482614914080732116
587093928651675014
62359933049900590
108146727583124272
284605246853732777
768567524491277138
806751059837144111
205537201868153064
339334153751972364
993918911363511318
428177325932436916
900390026391745525
635402720623993546
515641737035317697
84694685193568315
817537643789803799
908966233703353810
438684399530234295
808392794995179784
14505103666230841
141668837614369982
700541479348356173
483151191995736250
280464717349943792
810157650190595091
130598145664111682
543464976151709397
329610899589727015
291657190254307087
702479641400383084
671034681629066517
28711089729593426
919565976313455336
125285096655850347
703129525799416253
867662494455888061
826977987284695721
195284683632522767
366113026675690653
857382080029132763
449202528619262280
702619618553139043
748278569218156788
48259445619163529
739002012389947869
329732618783521551
759458422136807393
968241675623641828
193889362182775264
450426455331620228
347325842275181087
466336461539413470
48864185790198422
815856744007942329
524130876590968221
786740230151893703
492930076342932433
100196998105611366
905258611951967159
393161570568224150
126999951307708280
881387951825851986
327662033524108131
422220153098840611
651720792158614887
644293363711167151
417927783976845825
829269597023643111
369397988365331041
542761603797848843
166655546001135525
217084619695659874
192538016804251546
511722509524883918
708461236462628489
902533170437262788
213808451691762247
220865822926142893
493883524244208300
173286689240155189
672682560713872145
828195001040495919
42806434415532350
690231316189398397
753196213774415241
874607527644717638
490168917436454937
368378525502038902
990892331538257838
296515857749796236
192526921821048153
492878741791774350
687720919653296534
487509193035121184
950792780332416706
902213943995296064
875470993070423207
97275509718040784
878806752587684181
904297446595408804
948446464094921543
791466354987025356
878310900119768813
104175552629166061
954307306981550922
259981622056275072
76354413789119704
239835756292304448
893092966253899399
387608725405949732
215428331280514640
101574939533010417
327550322775777812
433396903462990682
185068696154055689
571340305247888516
239358976519010857
736298609340249692
435688999666154678
364454089650906808
297374393767796888
798029433175146055
38497279759192125
737752488798978042
59396253337550932
480004784254826931
43405353689848668
974242942921290233
849467509291311317
936255248740462387
546065395959501623
255623960450241543
111572581137027502
446700766794239181
736911626682251439
185304310533720745
731682103975192074
453887626790782845
192624644621499407
592952324771172146
131792404446806043
202526854750980767
760046668245545059
314184952806056717
933703662967466715
808383190666746329
733787953838212914
89999971965722691
610956507660687652
346677304680073399
62754277666134434
443174830417802113
312813624048116103
120363668907774688
408589466983362228
201674142632421383
824816234964031561
564938595205100902
103731695228980770
355089251795346043
749679594072932237
453276970258025604
877041340576646469
128284304683532438
267593174525618875
141665102306794272
503384744577581332
93912628982493507
935000562705248535
512548846085242590
133524107026227456
270916724623142306
661559752175342703
898948312544976898
926662282651794241
450247186300125318
894067341808209383
410342722251370808
368012363110746353
402592839930177773
404766841106086513
888381815638276330
873526664829022465
176001635179494377
595106207362247876
655037594329891591
761433676571213653
821598280935231940
697587268803353491
623969470444467151
463248475609324775
851289224719707198
173436616687312183
752104023883086286
219699815124711059
750799452723522714
719901401066130398
321284060677245144
483874345912300733
77470365132567317
115003103633762562
149661060356546926
24520768376309476
67086847402937940
737194237858910454
494803758574708807
896493289579560709
233415910800816894
958962675562167907
417642355762384333
572454294827007318
396964295729312546
332598321215954378
342179590412486029
99158167206636410
204335949271190983
341651587162272000
400443379925994990
578560143787231306
940207781914226272
57025038369751703
277057302467839850
710135472377348894
963487991881745511
387616472387512721
975279351803845689
190586172112037743
64066907133500094
824410749598686395
72793693527816135
216967053205985332
189975176670591394
577794231594469610
429784966679314763
633857548847876589
655854515866764198
234912915708413474
641558323836263373
147280735400465359
45749593725019867
251674220615224335
901751222648237790
648248280900709674
949907349131080924
521965279078132554
561107040881547669
457182812177611756
478038816258975502
333934054762469077
355033042268514670
998849505262757437
357183826025921894
848744386279113311
232666873964138477
819336549001139232
518784392797948657
527581296049535763
962706712944438169
5820537372807897
491526665002876302
807586200122929993
531012541378688892
699377814739454093
455729284170052918
812013337145990616
767012650982345346
946263814169376698
551662986042944424
930766157769595313
112096566270099715
882802006741366956
381125466786831837
453052945595672424
117003260817977723
777776174667190823
322510196432179270
855099722875908775
943262671678565323
122541469984300107
684070389477813412
628417127772836620
869126191061344648
696735918482537074
579634414180674448
209168263598062752
836086502728544245
373935303403333158
215243776863492545
381434106986052176
763833875446781730
446309967801590227
510592108571694214
312319693698311242
143425586295662653
858527981191173644
280236674732237798
239941334599448133
855867295652105771
968097586550264100
316437112603885023
978476462267275075
757829520990197181
578998529293989121
753102681650152263
95870010055830788
976053061511686780
714398146623997658
440774463604749751
694847780365782088
373220911730946943
295158378422304309
531903122396257266
92552747958908531
24831304701509690
80720577668059640
572981183317767063
718325793839376539
367054935325833490
318896989743457918
863367886062301322
35594322300646174
254976776360352164
465702592522668271
82728497581002734
263224707596267990
614709093985027569
848025807767013451
189668103365565393
76615609525107194
289378645150756055
334385519330215871
220555195338404008
760508084285013662
446089043548703594
858950417850738235
327247805791643943
746837675068317784
726089344710033588
720766541975827923
144239401315916164
753384943210859690
694474939651381048
872125053407638248
388126859557248373
150573391251109529
612735609309667347
92724013604228331
581010452579835308
761805440830646414
816788676017150108
73044320403354285
250353152010541222
303452827485577754
241090038966494979
362686752432387090
959163159072399978
637416155657437717
587997864007583224
312396886045896944
548849404216049489
995482260420212004
830627371149258833
472681714662385798
555157475861231505
144859256507034893
471747639042317434
500040977590442247
854326033188895387
694256488898619471
637036871600900077
878874207681310486
274015936027595461
467941647236270494
443043126550303414
308833198507166233
616554300988451159
738220857000927392
673745668649503305
54808482662255154
481254167668474860
846391340637718250
987456360169621863
419638449227465102
326181796899943889
312242147113209924
567531806730217178
699514199528331375
553347126921650432
456986521579647483
356376621527398625
273376583185245689
64087671121755616
422695359353234466
608498365386072568
179739886838844419
796184624968768210
711284596785341718
123830528138623041
152970745802056302
180316155864209520
748164685031758019
276617081104664944
248476228652288250
738065084179459000
156554971185568992
823572468275772622
404324303444401629
830827473874202658
218033145592752945
116220864763512665
730964786327055444
793446974227827737
468914265567430177
964507774484293182
300042435499017515
227293789162677408
249178166838528366
968043019358404222
783288266001292972
2667388228581505
321480813871284386
887799752559634972
480701582878751102
118520286975592256
277389730210774484
336877357911965037
223421696135545259
549352784081846233
886558101547604910
251067240098418030
722929382109290862
617833056520992096
907744726787616424
600707162623849831
132134160088977015
973024691529262486
296542930922195884
956773630075146991
61652809200148637
322239042053181299
924518833182320229
428815290013435796
779681558953647996
408889497975003332
949076513391196487
39286404855276859
904886227286843713
31193957492613440
406214306641034607
30347038174348529
149533193848218715
153151640054012542
466783978073166494
225051231642405460
821813606080952575
918127949598699671
300624258532784313
324051106718455693
61232072461247133
747150543556272000
684096917579291450
121367697495835166
937002429544731540
104495980090209894
917118951712437571
704977618473560994
171662941965774969
792776541316275371
32215269982819048
35322358521186400
155464114729242439
567027025431944121
838905654456711310
43542660204475582
775175830931180530
481505215155616479
624190523542578847
849607071746514023
596964762060706356
843482873946143506
411840510470613886
902607111249453127
698873163033737918
849027363443811086
273357314863605476
89112038126139555
630223196518389091
31127601439187399
430514010511478224
985009683215536907
435705278927601229
880755266329834673
258157861959179652
823434111283123612
495410548888118708
232761166185377156
931022726884812038
409358732256709250
100991437511270204
445301875777799628
995038638404992127
149051942877797257
535895645441229183
95381143751475801
225684088441100755
99180369964518401
954589469746320212
396005951194440760
778527251134175056
484399039610055033
231717528764952919
643052773961984309
335540552940629814
275335349942686654
383239484768504759
750897646039347087
654412627093661965
282591356944703874
849689073226921554
149601759802099352
660347648654810152
824034265580247730
490139194486312125
667113510807873720
398897739686925080
428593876308951027
643891575973199229
326086931847588527
366451045156798292
436054809744204312
814994141557253594
66334064966007615
551828097376189604
211568164994681251
626469281521466622
413078698895159971
11232840159437998
23692188356275806
383571597125324757
887301825251062252
496181357224555093
214517012495154863
424953209708104755
347870147228963536
648835363323393381
374369977385803138
837302993676183342
470792314172094751
120230179447146085
526854955116353849
495416823274714861
221719200655526026
135732093580865636
440487705911821829
19602966093024120
104167753099494774
27696559296408316
441553546538759632
915299198649472521
754214072618219865
780443512725224950
101715113288369428
1092588440100708
644956596320467034
908400280179755911
171639768089437295
92320081819295145
969577622770331195
778857416388320121
772077507802051312
38643892146901865
235419344321631503
849637802551991055
973977335644905497
670103508648600211
695475700119656648
175597412776061000
805876792496809156
614328964109543217
866637378704404297
740878544300103883
730335078792365340
410119982362760248
245675481354252896
579865055279885710
399605677046891385
765865754908330103
347839735659906654
11568078241347409
908526094758522540
872562157746002611
650958910560329576
196424843371268547
676187509957975981
933381891101649161
323136133866602721
653987974810019408
485104842480883592
28735108881949393
970278366555624043
616968729509706885
501830131273601900
526737898239867378
781615763942147407
171557647283209514
208040726429248461
30231339393850124
141280596044720090
412661731516127708
850195348756087733
324757932321257754
309186586738708466
969552517966000177
291330817024285446
25656861227382934
317595716878269948
850662178136978235
117812274378219390
532685405240989399
149302047292138191
705904333164700512
563928335832922814
763750624390215315
41779283702343828
210701843584130847
789967663988410879
745320857239039665
385781149875157467
210243842877852835
565000225308945671
655118005438221308
205151840285440164
945453994873495730
193818573499535268
885128237826190430
224097779829483935
745499930883572197
151294538363066519
422677119000445549
427962389179804167
237651177226468218
937739178143155188
16512146047826758
691066415002365771
247584976779873459
888883550446558812
964569042072886022
779298943405351242
646534536102606343
462073063260540895
265515522929205644
654882345030476617
751543679261887403
301506088218843837
6138648842639744
885903450595158339
589748439273316111
761735658475049786
671517261407013620
145334945590572181
509687418531457438
339572004747177371
797111177807404688
972399005599746854
703544504273431947
371473939316140352
11781891585296799
541091887759836039
949294372600129579
593661503854594108
905519980917656948
524574647399554648
70263022252131080
110643570972543700
187104524376863449
917283886448021747
602370331657058622
598396800966239342
826842607011527064
506756931881002866
940795722956924435
720506429076886331
344991972783813400
690113042950461467
675579577359501821
548922828318757403
716015410001152484
924061020435912884
780304611438919264
634385994194957084
114340277764959918
512759557848964212
143600043318370781
215461229408000053
591294231005015939
385320446798631056
322265376091303400
198028317112063091
559806819902932195
510609652750326389
457549315213727974
891797109230662402
275944435038832174
864699764538211858
740595837123485133
909070860908683248
878813215980049717
468957428802305143
379515382141686252
414241692935037807
463821725499377960
633714133816879251
11332488201418194
563777394559404506
803198311090630092
605907293680286388
740612631906087501
519931193829484539
118974882191797982
872184917952253350
830336626956041876
641379556686821350
556889441527297241
214489744909596766
747763928747565514
807822306709195491
382607833017773089
971177383203151506
803267211629499644
265439217135541223
851540013283929836
931648004587357077
685040928997696522
579080004825621259
899961773553969040
500490594389219865
479647430803107481
758186066625802109
155599934061157969
979599733011111839
684546269349091453
732008405832102513
51238366174541104
756736278843940507
308031693826796869
589932177070617676
30374267924003089
47036124160255638
39392297250716808
611173196605777098
438899028847084481
849704386137077281
302627066750801342
217690391988590669
708280021301149159
721907744713481040
137695191435536720
24660942536197182
860671056500934970
983304381426454958
453228704311299992
7259276593654890
892897108655304935
309195264582571062
872006079092458160
338587105618076620
604767927752503432
160574926662229362
96945545092694759
807284373697731312
938329932622098282
942328452776066295
49836157390695914
229293999883728241
439585257431551835
55565818484836684
69171246254051717
549596878924801482
446101484421832895
178048725042147151
959353681527909264
739053238843743382
403079113895526321
924402008613584647
646470768666882483
478007129327018578
725974556244701241
110520961398668638
875239465135656218
358377228980671128
414929246050774609
873069037823780296
399564372004154035
658975473362987213
833882854109381869
840708004747028280
638810261262601638
431409730770288672
886124302717506534
260050037049850668
378001612618188406
922980859978781231
685738205824550530
370119811006930959
771967572613873813
121489543802884748
435880396004322976
251575541367946134
475682486656515916
297189461100289496
961789808541933219
197780168073105483
570057199294454764
771370915478082895
284767902479263950
202146149472305402
25436151117671832
634992537933433428
141902937063730924
813972381609993297
37747237525586074
370926388609931117
467278083215410308
370588683988870735
52627117445308736
465459473282742520
405987379402711716
162954785405641593
181155877667988239
430124670147238211
661163354169705500
42082774882077392
493553215291420383
826185070062910172
998577266869978506
95506961253921389
125664684319921031
174362428986049248
484478065826774962
925728691702331663
406451223509328516
699761427712674195
417010508198047795
263541388941903930
654296357888021600
333208244386678472
387095428693523199
762626710000973566
194018883322970738
217556351112801210
131870935443039011
139017248388617714
649545147492399178
788286880962057397
470006407021796315
556699977287272785
278136767613991112
672040662071929573
7524288059107542
481288416561345195
768365228122925185
824625800677155477
381269682498799596
153232162798810461
173954536738159781
157779803671331159
149110948404972755
995460200305846963
599923356374192033
937169573751406829
938956975745105588
281585279618032556
98246403271513378
787011032039901842
645565030898972563
284373464868523167
425154951054795154
700692869831819940
217148053175768077
966461259162738905
923914820999446900
428777935568430093
739476550635270812
146401349256534686
324937251269093720
211546040508346507
379033178022090700
552039720853898297
992837553251923829
279611224096416646
464774006078937299
797885037072990551
133785190467717890
722947477733706882
388563128550284187
677589119423696863
63683706665408026
63932463973308326
603679501577903667
366899971956873237
297977789383164335
779463108196307259
621914031798164816
327948163180014646
579008776565911827
444043682359151957
557758718211112889
766246053418382662
694353862883070577
168184858687007790
739672164324599730
385267677293766307
774809478260134583
250950053087253293
54241645387589132
323703714340750696
292324199821951680
788397350354267456
368813750007985602
308593242922314092
906812317664908945
52491178600386848
10639032988312300
688847021183291678
872554124152804387
749879042198960084
339258605533915476
728480709146573206
416223115899541759
315563488047371528
706089483282826970
103996034531042421
591793356527117723
652119640087628055
26438204139098272
726778733563396769
328015005243772504
137642638736295244
557420857339217904
892431570985325680
465797360647941642
895384018105229469
902198947033761546
310804324827432153
698474857705333312
331207428335402763
514386077096455338
369605767835271119
975637036440314556
164193570274897217
483581687296711552
834319235710023044
552035201551526144
352857855456791530
204613272554244536
557200330149588488
325187167694890926
196099564918213463
4561890846007387
705370234423504055
19947228974453292
52112763648833226
454480285981190916
846207545851372480
633428163979572246
617761301823885383
84683162468636450
274384938498918227
262515575349091355
894135811432619087
770439458220719052
4490448490900051
420987112233090585
107524259435641362
259499353057138537
527115813095588690
539671772045604013
349380143282419837
381238784459328512
469326861351720947
622460138854839652
736314938493912566
766875886621279419
864804676810401553
654663414770619597
184042397513008946
736223260623068778
223089931719197228
187516090665729272
549766594752955264
703662231389671510
756872139621136728
530805398393436168
507103250378839720
921046933755306871
301324891761787085
224891778463544233
280224852961756210
970312782597106179
829034906223602773
303586397511639155
951041245423540986
845359755710645970
586372791287380670
241086022165471594
786378511356389559
846202491508835572
960997979959193981
839996422642715537
6802042454097265
751286769159827453
62603054928111811
943123353234115358
251959399693045406
103521514873201572
904386685348386351
586229873837640857
999602473251569375
965728458126336574
707377460144862695
166420998894203455
454789990903794635
700672814546417332
727914391503891532
100280241313442887
46110739338420994
650359516944896969
593713112250806451
190054034112887518
892009971566440019
702626242392762359
63883257512753465
518945111972627850
896158435646088262
897458818821957794
541039320202422941
117944473388813976
228675618738921355
948625430694571493
540735220201510777
610712275489289897
178550997175436931
939766916307067287
535567108129577867
464121851969116909
988851845189874298
973283550433329386
505410265223537065
955775219518625184
670546409119198776
617440182229036490
364436612217388161
254734018459058695
611418608388917248
99699590409512036
447423998134778766
265614019924116854
226403454433811521
401558238241717472
374676695086903649
60292333729915099
585391713491314577
445634689613371430
384710051085801268
47076197248447003
813363340784399867
543810062140815789
677296452990426499
730220036707687601
437629702286128483
813564683325221480
998064911705189587
799819751463056921
986999806643487294
546677355957398466
155239053419978904
246917402916306129
687075691603402358
40041653980258406
763955813710406274
750744568599965897
246636908929040263
698607717910119037
985593862182817721
465145725269283115
790179063785258565
701901919732890995
587991212255918010
476642547003012515
237838365265233014
674417712234244210
713086965161507839
102768782847401137
988614994378440397
437471146007313503
51698040261069169
760720971896827587
200919958495501560
47682997136842270
799080111283042416
526141332342850607
144898574483464167
169286659260111427
814917664387361888
853255750109628552
602195273632620865
416968018918518884
477803888560046840
984536859511352902
511185927355296465
449175832352190119
750805075467392008
712392845329199670
506788079730662953
86672578578013527
652731155061211320
90920066302013165
248228719571921923
282945597608426054
64463566591775544
372437910635397217
73013792320461769
62430722868364379
925298878936067613
149837504910669649
239595749225979590
277641180785677797
541431636039003660
925304464918376536
897911346269308299
188687070202910145
374102785925874084
391398150500151711
946179244199243811
360686853021439372
53951718439171750
230123716464427480
72545335906075745
320469047589805459
913783123778328133
993575874218857114
477282685809150646
950754041044704868
971879174604763679
428725247846208172
965738340308464211
327246952496577734
591361201901850996
163520362545478270
147111662054720440
192085612285863021
658301925937010787
679752386800394333
491306662696372381
596530614027586516
793973463401233202
524919176775552047
286203365605386066
750712437916203069
67946330516388726
458998582908298791
554145165663198512
221439470433504320
631677805299262024
801023734879162717
554065898564042529
664136213646092397
211756939734558271
891454728767869667
704955924605850950
969654737388224412
941294892316528045
863770389918379459
24470569214242986
479728343091277083
897113018973015301
7402367048846975
524013309127976049
992476638198972881
112816530274648262
942886423037907152
948268113591957911
490427760303789748
178956166146641450
478512147857487922
187221849647617148
503085097633403735
93930083019924054
364859668425664001
887609570501641544
38823770407420069
160026028153093789
331620453266058188
281017039068607934
149769567450209418
312755752955961412
644780082428655847
827968354177799841
560415750022053810
820290872667784611
97789969434484749
551295760476768368
795663605417337558
586237233419153837
299999252673813753
509105190913617971
246121865464567672
325871313369404827
238726095955751105
957011531288979702
156451137158017317
95162618537123511
38928253325223011
32400965001397457
974131256332043981
283563838599194511
280960308889854311
799798109229390913
248196455225526418
124951782538496423
748604785221644189
802573463639362034
633720496224211787
657912243981745788
64218025334224358
12816937282771482
511321189950056933
253414976834246971
516566659237751037
702202981138906665
762462461290448682
498070561809712542
720348230633939074
874588873973499128
523588829928416922
758292259416698284
797929352283646192
915241637197902269
187198157952677024
837885656204772785
70354021971175275
895809811733134246
963024914200580595
107101079519736747
971616704632145197
893290472732220756
897226912489563932
372584501358085818
377614561359293164
192143087531619426
455334398751361021
357093300629176011
319976268126309523
358976744936075479
623606563774654288
396102561269130220
179931052138988672
888288016984385645
256412345883284540
103571982069991956
709081297146093381
730906869131855413
486571800707123347
14178092318611436
133836061302753020
577521900032864556
506279661688529734
465961307343193962
173474713936150338
140083386325648338
332039026623391162
115425031173419570
887308841167970250
818007791391820731
726166904959339426
683609014029924522
288919480729940055
300273392221676835
54786515479923414
57267124418069913
481843832318890109
950425093913984831
739502199717576711
564688804980498526
244662543110789600
975563231056739987
567852177387087635
126867906319100921
600199197930511509
501262205232909822
643867961194924404
780281615291016609
411753326493974038
3706199267548368
203066645288761355
291265168289960812
121154335553959187
446853623877527068
118839226787949851
47435105861269190
218126175113786675
456756098598945335
421036344063057608
546810011450669188
437250784697911252
550128871546520703
796845492343128285
552830566542147935
936853230165205137
297066341091744988
92538056754009572
702913878745218608
501259092421404077
478900792195112945
781405305584627464
349838167725954740
63458800905018640
777287998199207160
528497190727592942
351192848287967281
436853694835416328
727637670245296911
664938882377971309
987164358951381330
889648627537357231
217805512193849773
976679558243418804
160749114043175733
838425393938698006
272446386687205984
927756562174124447
659646289405739924
595508210638281444
254928764115710319
158756089975517422
684169121861242293
179081122020828201
905861725301457202
321680401457169951
415668701372080992
852142095895674096
113277198002943754
898669230718489493
98076516868285720
93184349686034217
210373399116354221
489225345676751012
716487068377863027
697401391288104469
198357670282264764
925141972785076059
45071649160802890
554972411346581933
761514326026711033
826049371864965190
93624183031066847
466941352189602740
103902079505554379
569109093625569617
553298636414418131
614542669501734652
486466598367765060
721057488716375254
216772412645362733
901447159166576918
675925126324323076
130008432678574233
134145061000819130
504028701535846715
50360470863224557
178796355973538059
612288478915617130
4089083757745913
962556520759847888
44339168192803006
299916543333043126
913788632340632037
231548309959866311
452646048542732329
987258822569969978
976409417409618184
731929733483101356
115803770832975040
223135531577136659
428358835368024650
69046424393761746
876138879763597510
813351490645859704
930103204246678044
407464063381297473
8480566621913792
801648067348665661
831301993306542824
535862906715606886
342426144357952720
692395524233029961
841671254806035562
304222988329570950
773892228883659845
954871920449502761
721727726132366928
119640805535746949
71117160409501992
593770291055645735
468731981827592883
970228214210684243
200624624245435867
869081030166118107
211439330481323283
830983466142987738
369734629077534752
609013065581335667
823647961049007362
859538772973695780
136464385529284649
314294931675203284
132915435454005268
404475923806216392
186677036500916205
235191117903158054
143694178579389831
751399811091836757
822559460458235581
451643249437913388
194638165034545579
838407921248742336
906779561391652026
894544393141000956
209429484584145238
159580129422737140
368516104288075355
495707985280943944
514614842042572986
92711785665429308
640395296154059373
526303297368236273
483695070820003533
689578765436567358
979378208130109262
89268784018750031
874212327140291082
855305437496960015
31739603500100384
191312163799266739
791956111185697004
578831545201587780
786911198880626184
106611398621972588
361433050735498116
915965806439393707
546574348742625270
583380279260694074
373405182979943049
866125245357523960
606030958904648635
754646510477169154
695652413016109672
220031883949450024
294664384939068070
559511665166493447
78269516438149200
152079480662513860
823516538362132692
41440528948529890
318812240396142634
185424286682442825
242514214552804579
907038292478575321
960100555377659895
210009203393124023
380491842928601892
5746350220168041
809080194081332044
515433196543730146
533399256001331530
378784920575893449
231014670832729807
794930928164902957
582181384514394591
988197864055787861
58885679148815311
63517843228034022
528055564839587754
301914509027094323
619325727463269262
748466332070821595
23201564557209952
2091167044189600
297545714350400241
386129732804120288
848106529354817057
485032026180982520
473080426662058347
411314422847902723
785967312167221842
97448626282426710
598988286763753949
170624314636745921
924273730335209555
412321160002609317
402225686218656476
890000454089301525
12637147053591349
438474492490368669
607403073702902202
163167913476536365
260708985813377619
344958605184995888
175796413606955152
734438402282545114
719793601011441465
80712926227084239
708087557086619429
521482777468760337
175675830851358976
185828366961835246
629573821593992880
646533545124501131
70843015652807532
152823822206934647
891200425065944406
293667569330896259
514835526267364267
935816935404988958
269972026672259904
447346323659705638
192886594103222506
778766880085028117
210039577642174240
373793986169694347
56942408039132546
864761228211382488
739186447913014692
930360597986901094
599577212326767683
191664927412941734
750905221260847414
7149509897661250
563672114160294653
603433806169832441
399519064152121364
592841985326793018
831871349950260657
622503412436566090
281596803162908263
957316406586932472
226507167138018602
135116423230467725
903566243474667905
907286020661660169
158589271340139532
171034063483083800
517330722522034662
320369882326654071
865788307576579437
131856477290004425
832416683286521974
453656437660002539
573305329192203140
20825854456632668
237711002832770700
544957365975720180
321689675649728178
291396500455308548
823186436053980531
459752239395665510
297772134875788562
247530709391057557
292301208542713975
168294839933345460
810965152134011892
959965186852473309
815574912967425180
741232055678709320
981166598279624094
86266958370215452
72693054304134547
497821109317896362
360095868135630066
428725880425943057
961812389489513575
964097177156670833
668433736933720842
27772832340547518
802547248234337488
399752207348520117
459099005308618791
534994961571713663
511562969259020773
763988798764104930
545972150405198406
55893970796097875
667404698305937272
998139702285883011
564197062432153831
103451289180920598
254995475137460348
26780198061406119
306923145991517285
440193134271385592
348251213010454190
398693669659660155
833593084501999011
630019211157347589
663089363700431334
623676120562729402
746003799407279461
232174800656818050
871023801414750157
338310187533472324
343478549954294778
575734160212875436
685931352238041890
183347895968702565
607035510225191061
618115329946439938
527357238777699178
61171716664816295
735476848860041439
212331914516679631
920675905210315863
738715937446449696
855473612157575283
498385308324334273
383366267260941659
149234209795257818
215781350639569003
66394344125718861
223981238863331596
837712480906985123
735476408377597648
277513660839647312
174006413733651646
535131501753336377
251974919996974610
597941043508748637
567820010204458994
148396203575977718
481699308568267942
578337681555970683
960881491304602593
179629012724174680
884126418631326826
447173329335656816
415037283867067135
777773032548619611
597077541371869767
665705857699837789
663256344840284261
902762723991934484
374116750696371563
847526650255307819
908380702054649699
819172295822544193
295329358136370991
244995753843542584
685549248980345614
153294295983947935
681882392339834147
927865968385512950
774312699121799599
778416132377259753
7417316456214794
332316516614977680
123491831173146697
125567036811395267
811036673110573539
52941192903880843
873983736852770206
225863905749064903
69169480675436898
646043209395101350
218171899171831725
147018437742510092
894169023843474959
768612372946039232
84591764144405472
648003615406425117
860050663892357579
264715990147363926
457988567880186547
387567341662503582
61532681576534848
67399717118954778
524063206940326025
369755873663651563
652686852103373602
869506017258008783
35519359930038346
913826090324109914
913007733844397200
870000006087129613
250639743999444367
266268934279658915
530538787269613141
661216387947857768
462686252620365528
310016198412478641
707373240062290975
159961234771400325
813112149028441388
723782059059058665
518790430396581333
728498099066512136
415273946034651274
802982241541505615
718379799400680741
711776068964965417
773668710550440190
909670376351382096
378181712912649323
337180927012531274
749333050937006367
362432186827530521
803588461814695486
657647254734148688
686047201918182744
800201053610961461
822466105581657319
980531864786605894
178720570766750636
78655984339275544
895524250714430197
707783269759868352
413028304846888636
410298818964474037
37453995836424945
1518892492788623
634688754126390266
558899530317742545
780074373904408587
4985948651338882
885443955280245158
43406221199308967
299723665431660104
668591070693506781
656190989768448553
956685523042211048
838019775731484228
699031094992529996
390538514318125153
561627278196554759
76158661130106847
704386520055125493
678065870256584189
309142451956654164
848074909777489825
681955632681907299
111598357158191675
573065598151296126
930244293191492267
448964717365341917
667521516311278516
446514822342731012
276156331357209246
799326249334064105
24872986296618188
32338237613861604
757822396498580572
440202187213438026
746320519374665225
675170738835500666
468810816721019629
559297005374552003
570015719295629440
545073939562693070
632450374384992077
974466783190093995
678697443549110495
56613325209137191
838008993048924118
435927330308584811
85035183561668542
236832132427942469
993989633611402942
96947524393923234
852634085831369098
205895113902811397
425906449691168496
270503420294138565
478038385609643046
705462799455839040
528351313118322147
546519810937573973
929433303316618050
780692288836823617
591513930714418513
414892522700513382
722072471696724089
307650323028503998
464216077816781475
312237291320916508
358061243625417446
141974562879188774
849477616890685035
711331757702303260
579728675668090504
421371063722370381
292038049103494151
879198122104864837
124254617150360542
122988809498177487
31810276325828857
664754127343535326
578389697135886172
986508311695334209
187199159808197424
607833442284769433
841878863869297543
769486739679561425
209351664681128050
720610700237766181
907660147539890065
302631869396875916
549529059840703732
471368199961183873
340068883289719680
297510013508945835
757164495250711116
632177406447561106
722932340912082096
299502746122292210
359294624264735636
3471467694175631
554477065465147736
423485308718116127
14209589782574132
536650114770579786
911139151657698579
475756888337061876
565920382673556489
384798276561620709
673741631236238361
859349278006829655
732157068968820183
193499071347511057
940215548858268584
53923089079424168
43182277022488551
872316058191576691
253349749546857854
770597402299086733
162408120905108268
223490649315082814
89473731823075080
77085344285730983
117631693448802906
849907129036583319
193877594211569318
689219258292919630
594077057006679589
598216447096395176
899609905131788556
603232746297553801
618739252822810707
142569717300425796
516567696852949065
571338239489372194
719218778123965007
637416437065289283
260475804931529117
438267501669528016
697684924458685528
413979622112143642
434856352109627230
29027744055900256
539475823964161470
531923506844570895
378959884929756727
928581600436495741
182323030848498036
393357477071989228
390167642635420586
426685324272965706
78684339856372697
51228339254975841
296615329302135496
498119885603875600
263139823634188128
165412036135399920
667082121935123582
230105107714105797
767869317084361616
98662063732231615
592600139276372175
534614683585053888
861607023721617083
696551144349768085
573338767966895334
362500696278635732
499522806131411079
259133961324771966
225018696066606741
307349101096766991
411716541146679940
350303192013767525
416319645007459345
337858233987507136
174556018855485964
750307931086580366
495049584358640669
966498713844871039
508027622127263932
363068462229457823
208303400262409221
679216910730816115
675985445112027828
645739670231983379
748972120872811636
327403384561742483
827483418121187630
226171446427494808
818710415581810171
583033645710675730
978765238496101618
345388545219931820
923342118373661824
898629497744570320
417115788765823441
569560083843882102
260337855499784882
371133693116640475
672110011484371528
843631137039985884
973099510293151123
984223919346834947
166465372520436416
401163939370253158
465287025449967615
432339073412424258
4218519052778859
440064838752396388
523069022923855414
219961382339280718
7867953472488794
949429555937473737
194317626921584939
809861689683853563
586023628483062360
245332180228745556
20239365220594242
521517507857473782
417104488632585280
270472116613987922
303708724977299096
109818469892144643
941579254550816356
865325646000344818
773263388798886584
521583203805012899
705841531482299210
204511089731503331
160109546696601076
120757105664418191
770514021245243384
762890576117865333
880250599204496679
380851741687253408
612857515406891406
676779557086895118
746522769053982190
964488385517956747
76751524713915416
894992649626056052
537212242008146876
893976194213158535
652885631675495732
84650267077825740
168326034248632163
350164067082138363
536860319372690072
874402595597490597
951991911594465017
859097586692047562
266106136737854586
67936407390615378
544374519321564699
964296351010413007
603724305738797908
699264334874557963
379338914491599254
530556351928373297
780031959036908971
572105682301998954
385723875240146873
944522300534306660
976546870050429468
834130901329552896
571280511768538844
171528168891798963
971696845301621385
235086597198884969
423720143027396267
43333411108399130
213961721078576923
324034059829762114
234438137534586563
176734327185093833
536054920115044252
532732119850697248
37983392306287091
430409321039467162
374409999100759786
375820132018717968
108070555586976256
613575811883008169
546823981048757858
407927806622771726
438784977160903399
719145372403387828
68917051581716893
728209163740478341
602553176052977287
311533610227109821
588485376658381213
7931398101378290
259467234034460683
241293494857018236
972612418447011999
276253505267966494
975669082940983165
980839796115453340
179714018514256238
213827080965934403
654258809670813038
404787010555429967
270569229439729257
82282324551656886
418499340973543740
731443028389351140
216610294407386399
909579899393285837
390560813430597417
388934114992868602
629793262538369872
216939869367763798
987630019627923035
725104342583351176
142156196293401963
956528710893633348
536057246063912552
156136177311833163
219928464645101077
819816802536684307
669667635648960230
448271818217513306
792690226150143389
533535797189035860
730491299311267540
511189062274095265
794440921305188779
960001672451323734
529926993338016156
315549934210487394
122711121580478668
938734837746279236
844401177985639858
579134106015212616
501665351482171157
283660349967998614
40061456158837236
397075529934207870
260927665332610773
779356852858457586
516823173820175469
489324137314862949
383071682355428756
741204648644318735
859965374801995429
578449450129926162
103888760367461840
344367728375983464
41364982858750675
378863875901285387
176312374298397715
677775755870921992
64136119293749658
518599716089674581
531262285139153603
696040647553899738
695032500228070731
512670942510818965
130072722073755489
161040417200997052
3468918285602357
183031621359482440
300759848539927930
761409368852130469
719032979954586427
998394638447299284
331893537221389571
99527625302901312
662497388834126777
180329306034182740
902275784471366209
696988649452994820
934784140654312570
432665090020981195
565748229183957794
431830086385286714
275206553763706481
851701897651946722
627852478829016639
627551625294385463
945748141163964723
170155105527810365
41876745020407609
639372411538541512
714609097141082945
956317641533605042
250738687892203584
870349616504207786
237129504163670847
213332364102462352
147226408926266201
448620966656197846
938759628051616597
762781376678634681
332091312297682283
716937331990197455
581678159495019628
933432525578360027
895070645691110042
375983798573040305
626358443171488176
201289180571959645
190981349922107468
60853407300219628
466428506282778838
165404007387116480
760819046832252669
262523405594742790
716431685775028462
850806715940509650
214150170586676355
818287683623276091
755211209065081210
108321118363080092
404531012790572431
466679704242567466
357666363569402657
509828317369210293
54907400161528372
912229991115649586
686153476527994734
182083374763260619
706552500108701036
246757699177621015
876321191160151531
925676182605622848
8508638803960676
799869138745246105
91178562298360788
596510592329468477
261828725871331438
735112491457380516
814192955850449691
417391903125926021
189297845362852109
965537163085709719
417208601382354396
755282716806666514
512005490551343160
980893411306621091
565162701203880418
509747831243676660
71113176063835697
159585354460564544
801207227370511934
883610687083408117
663255191779046637
569766933699328911
224340999702735540
15185469308492682
365160363645797248
112788172748130876
817954953913567042
749686106455756656
41482662469445927
952843911073809954
220276128001877420
611367983454178893
738268755328810502
882582138804550708
128741182712285204
474487637116134874
911315846545710105
826761564898927444
430098975025971472
155747148957857890
122959239636758022
440680590639507996
310869200883585746
588357502860304823
275683095449830435
241677063147624640
893288862026491593
261157879724853854
177859043445257731
187702821353137645
338376365467812186
326362539243896572
676370870809869733
427055661784495682
229575934449960233
745479355005183363
91426759265162113
219254386256878087
922683306398999104
286698085206021339
550990871982651172
238311352486204916
561674075233441894
484894548542801079
63340061069670979
985741324232809202
544000051152527442
671997962871690390
411642823612769805
825109351305181888
627260145931042570
525535323846326189
647996756077341322
60288883808674687
217458934047232505
773661568523017833
694847302925278508
951835161947509208
842750831211824752
197666423527088000
764551429592813563
271285536790448346
302123630672416359
272130653541336036
824892257234949154
784549375341876235
293064430537396025
641420767126732885
204295937007557598
266472063240086861
10897898906108211
614430280016782731
270950248701607604
212579095834307376
555703248930925164
15777428514223300
813127052087946403
761562544374444323
333583049883164156
429216930644393919
810040762462713678
723270257327042686
948437567819733653
63984210410626087
641944672301100561
101016255273463580
233558923432947820
724160351768067459
722732308185189301
612835117594549422
289926214953141295
892824711276887465
517293235053419982
555845254348834093
908001774496765243
622772208723909768
942700342864480313
355588914627016768
461505568374352114
46857787992461172
940211981487544508
704993495746429132
219722822791759420
455702791339974827
85979674687400549
823868845639117914
964431773525541158
242821646089477863
244056787662117146
607956693097341627
889787473017755231
849271906362367195
716103909402789125
721635542957329749
380205754804278916
821813117339959473
440993909056644676
916973374651158241
828505837169844702
952137416388453234
871190126437330995
508672640608701117
831030026071749586
777337011884343472
513520297338537212
717133287384775810
276195420983869007
490372181148677616
595137383975581996
229199106333548404
258637372359120202
846113613052301841
883379060638902055
34203229383386640
361384329055169113
386922471697282322
519511229778465422
880523816560116107
110450838969129011
241878695795041086
371087448185915754
490348952645122493
229738796466659399
215502621295055676
669056022820637155
105061443991298415
153789334553971515
765050533332606698
682244546172091444
458156232990262159
591609199320283667
755298798728561662
161798014931323664
134570568531048511
629829277571936020
537891234139096542
534747515604654609
325038138134440174
612962762165408552
179053589028665567
30331588546131296
881816920279909351
259691030031027585
682607674062118421
956361528924131595
491246320397533107
567514956355955429
374002704328101514
96836698323444230
578909658051926239
686298903993121129
463397032225811589
366080345378722848
706252098308842050
974283563152997812
261499120875246025
105289369937016222
524308554783013169
557640937703108744
931146436937012314
481195364532343991
906523560581158275
190569798413241837
978526409827810082
522341409990612012
454683069950574346
92673632519832107
208325044838390454
28316857555654333
774728596512234760
777769969562566021
383802782852320487
897308650634332627
336494321098144926
801870701576525719
65969941697418847
76604116572873768
517481310945171587
581009202960843989
438245543929779333
293576348351967982
927964158167077184
992706284080829427
44200700298720009
513120748339249298
431910323545008437
510912532103702355
350979313996225650
954085230749607480
719568646783916783
100394662154434516
927807717552979263
642755400460537708
514601459088012214
292381811623900967
981700417255718765
447579695966442465
911812034053326292
727119305873496588
318521314166594853
459623249796748370
706980500813164086
328369624254217539
443851804541105253
711899947153809276
928613965317749993
354538464871447282
70452205241827657
836638615107218336
165157267876378873
813833369808227674
44706800834559621
443545412509882625
766597007508906912
47695381724346018
481868314706858196
799922813671391564
76086514510400512
555865713647106031
447183800535351948
468515460868446008
356035972703531653
953008230514268472
66545722020384544
952449076718425553
940707369370303606
370864445500997800
221195462157008517
259402839434264625
20857025421752167
244921086755133965
786697706247065806
550807266403299530
93991077080378563
223768167939427971
77830899035765149
341865685251782951
249243919560607048
94695646945708996
792275847299967925
983033489809117480
717131027094715542
47833391048858555
389817396784133222
901175380841223849
755882429091734671
204089466859752478
778345823199471362
329249438477799596
727317906434230686
920111159708817842
6449167318731547
428866989606121628
496358850287333428
685339248764468944
240918214468456126
204557250692587710
303299625736858336
641272065598582953
245937914327992416
614718680729140836
139867892395336324
188590485463784055
30994176428271246
756768339169354122
35766188099773718
427005913357578839
539620201443544181
217988168726072387
927488347254204526
977136903552103706
364498221632946187
654070017396117699
568443621850855476
709656966989396399
827922854220565097
967695196718775549
528996706291203823
119264612461437460
483408631471609984
447620681896450379
543381626096954661
336700998356676069
21070363500128322
163696368229570401
346902897326436873
982434761640265170
94047360603551748
681873455682618813
166649261248746239
239206033747826437
854234683602257428
942834378533229363
707100375591932698
813039472759111392
122259187117482037
868566752673555069
183035491265522353
892657743175976514
750187377108386591
997986046736264590
485489354473000639
652476481506077993
539536402001758723
421802748801546558
947175003059718269
684182053518132774
519217773889973750
337295184138590391
622150300486900939
490825895422583246
405987507747624325
572006151380566260
269503693996852173
35062389068483166
299846876574020679
961160826080209985
233283705166688334
299609512935100198
46547164917561911
688783135020436932
920451894214403931
161018029513793534
675641283662009144
180673110283146492
698784209073448871
116577269369010383
170510895561012910
538713879135109417
663897088748003616
497270862835735860
164852570858030839
929928130117222787
43602064152875520
226827210484416648
990419624702851528
422788432438506071
718948682660319617
832547795866303249
438849839350719346
779727422209799023
988117484625577449
863604170133353945
941142250340070085
706857691745255513
497125496074313034
523563627873929964
441196287570601018
97297756637728843
418521576352511256
115612506010565774
598881732976113057
417152469864262335
756046579925568591
851696809713669592
121551794741846337
942437822956699406
442184136037807012
273679254753458456
673445137070057963
372207337790297278
864792865048902090
595166931783854805
459873257771057912
554634372799561528
987894093796587948
441944271918725439
905991680062553058
172114399752482142
17015744763227683
964527729333810134
651222763878218654
64796784017836290
56745066216807217
84874210983490805
775401112662160863
571064103198521251
707422059445568540
538919121103324579
107505220487030097
153802499473403022
993872162630343036
458650104630548326
716578431866471215
665290366486094342
322593788318319233
366004211320617715
806821473842017686
342519054668798230
752162029902778477
342026238327500817
125028387550184275
676901357496704908
396733566213313290
447895908867726565
478474282879511805
701437741338489498
870011579581959483
900313384718997068
899859683618194400
332289929674433557
705900995291936079
193212716394052413
950926050884334111
748783606089447422
748501891868705296
985626701702399659
494922149204540978
311849070013484051
753949026758645379
319142522860936955
973198421093129842
367928946875289401
360876793323715867
515641288595699084
229208085211667563
605510094833305879
271792402669695876
635858160334517784
799464750747207844
874870502470758790
605918172377662950
154586630736610910
579698127262514644
578915746100172806
455876205835254407
708588497667806629
706030925184128438
628124591645883751
891364964550711021
184563809764525480
461666642349004521
823550787527731416
665028202496518446
599169590117266435
627056113841249462
8661715862328721
949698931207031143
608788227841761174
521418005441142427
908940939622629836
268183874817093404
909937635547305554
426712352658191902
228140791075528207
29878955692249511
945998861076516
714200485955661362
323181034383925431
216598497324031864
621156438159933811
689011807783273287
304896245750111247
364519875885980159
259092735278275865
566381575972425994
510641921636601888
801462391724846443
521743147497829631
268782293701130448
93592157737766330
333313614745747323
347352765386921429
574208728759106140
33430981024848275
366774198286279478
140764647070840000
433225586003373397
240026207492067916
104152384991970668
783527614498080882
123970737426836288
104726424182626437
452613072011776769
345717815211360178
99386916375508476
267815503003725310
656339449105949443
363808891826889121
544582557444958895
8875342466737261
576384538919971356
695506657382645449
456139003700781230
784153154370657731
201148962336074769
40093226590767045
784361531717070704
968650443620930674
997538067382797395
181673499481891062
507404774586804384
292579740773313715
953198824056920436
256578024179359195
665481242910688750
200458510825056591
589626931236321149
125292348067383304
662037257394117687
670792185268304933
853408346511147204
478325648183562106
387517712900645534
24203307341182851
907951211593256831
800800450568829286
864313924773021040
443425639827249468
684213136053463797
567014042716303869
410679374572906746
26076687082319161
22541227747138054
61689325406726852
573368486584776391
767828688330397528
799252597328417677
556830191297188658
680946940135385876
604424430757117011
342587783168072097
785975187467552841
81792219489880266
333459140182782229
797446703217726641
642617154815480204
891585259114489400
120396122912935080
185226668176162489
83178558442921057
677182645276586208
637521280664232860
599543135072289448
51553480781471595
310299762298746078
5081281397052310
47531178184633281
986194923320170957
216418595524893401
439030557421759903
932840484400890015
176283226137051289
432116255661945947
359401430380677641
526332579662975000
926455283364349501
286178987601546516
984949465857788125
202049725572801347
894701002245931129
538677742740049953
817217076171138919
880245075880026236
986480740473429479
236493167833782771
668457361246284164
24417441153752879
472481008571454893
64396037731970000
966540775850144107
641815744810926927
364098592698164944
40942070263304715
545282684405661439
529452722619366707
368806202648353180
623768943789151789
476229274610514951
118107586784578388
35177030144380339
663062440344491821
17528608973354768
458236552560760277
956176296603560429
813255445360638627
291617329000437355
225940083754291361
184242544518329584
126810497661947292
852130367405649641
814430354709521895
131705607900412153
785206451763343732
988667846987264249
477546216343140838
561015051279424279
219459595601964493
287340744604932754
837114573257504093
453062660665655606
773715749861352533
125203576884400737
524289537077806334
245675070061024638
365426863498475670
444475585189401370
441985099495237866
483097627465767423
428535886662764341
738293206703810300
535165442518717495
316032195147615264
53533957487488402
270193031796929368
412902387789583686
851095978923406639
256516271323335011
675193793988471823
511589497916978887
499852096274833152
443628716217349305
379128123855321955
568880289841795749
763385130901600202
8707190352781898
865148241763314728
695005159030598986
632406522004962172
203724388517556703
323070941685729982
377479757986448075
801438062389739754
40325909132388003
74122041521935605
656720012437184276
251355628932716251
533177211413867422
487570863902433764
610156214340537059
811983816332572445
466599631235928986
783174545413825365
372036989569776861
898611394124378600
533648419031161205
813827345856786192
497353271066929153
46393799720031590
765480267868189902
145938398469456540
635208315557152894
906287073328992105
263266493845332029
14850324712416982
272365650191362855
268632570140260545
378030418218387659
337892050767750001
462008597366818075
820286385737969877
580978733982993783
136261146860585600
550964599894334237
90239914984589632
2134832733802172
528920230382035921
159257314546579767
999538634707288315
353471511091596782
104982786560040661
320371687729071652
112734945943792223
527687074861360838
427766824025504811
122549788897642172
589517925180601342
702582809142001894
993461631134844079
947217036246412555
35929194980014456
4340791620129334
895221888676891707
778532900858496461
663604936711829494
582025621506799801
529306167026816337
129734715359620535
755159080104116339
661385526415402022
288811246202487775
745755146700197845
651789761257310039
715595397668149773
472504790390074906
125838801877216538
349713581448045163
893402263981144129
395980186205849458
397272206428437916
906811470471990547
403693251169146674
659127710231890351
421771727787041002
708409852819533544
723664395237001616
261116148309847284
878882036504951811
363970217179377943
88076957753182679
675750604640131932
507876973964858192
869160649840090495
616979270173407319
220596962379981480
514228600816026911
762042700575617673
84621340343991034
869123917310041641
122917083621341689
188689422154181101
106631350764855612
298236551179881148
414911392584458181
662901804709440939
598545530175971044
896151773092737632
760545092807341806
948809775671554570
477862796578037765
985237074455890265
264937924130589729
862885500606873991
115474416020989583
336158630450263318
2321342021153914
187731089842424663
144799344301822640
461580793098694367
958092733345520124
432063102962590678
305417442578174049
867840735472403315
635178171635256137
362242460401476866
114861071880871292
247598794752602273
464277214272241327
889859570984693122
512705362114715314
423876107237940297
816667155906940376
896564159315442774
778389401921427794
653537826950959233
649633802360498440
768405134130510645
60158750349260988
28874836726210875
725521087265904869
64481315699021871
358154872754517772
512855352240864120
827949070668012331
429659167971450731
201346904607023162
846459306987333130
289329198256423865
286397960394961083
151111244944615652
764555044688161676
809930906111584973
181237684967173504
606286310368958920
131656362589350438
413138648914657379
653005819264446587
660376322703231788
667139454140723967
518764052760817645
906205834309309705
258147436565770329
385491568785815944
221859175633785756
826522694025367226
673245308570039122
370647410539991893
41835172641421287
746440893415051483
764864675344113674
793182803643221836
335539929817657150
651038746813763396
510046927206726526
935673305920731946
517756730910329505
469763471095428852
883121192033967472
759186981016896807
461360453592386708
15614478981124117
236198307005746221
196318212749780067
254734994848920161
3275915963867812
66577335767841556
77796752305996941
688511241916581182
44560901019209965
648913031043892509
229065839059114844
168473088816506845
710159060044753661
360599583754167430
7813725518799930
394624894041388534
117421481273954887
884337239019010636
375468436933585796
697911736698303380
712943512835452185
54454744393770380
295417956691946032
451070872214768845
740467397645117954
673445826192452386
544546825357078878
426420053716886811
980089800276906863
881467816451910932
918433775916557750
400602728715908868
256832333785903911
105411455697023526
558652194714831590
443937757384786796
701246111187895732
871277087755828566
327704084474961728
430187961357455655
695363927415815690
558869899230000445
548781875361515303
100793290030677147
469330078586296527
85208432469384132
133371163183981722
658599645771167289
330309520792551727
484783494594395346
82806234264742453
325407168440418906
782149590085800424
410404058077126230
714048259558740017
608804871081493192
57654851109754165
115383440854613900
397335698779347436
807320048279992698
870357532250243477
655158487159809811
914046687727247995
586249137755611011
297083571750435325
786836025924941394
462313102476661704
571312136430698324
398989370576544684
884491924769042014
614608000405264497
275642880815896464
89612104185636968
346108973264695347
148040798702937930
836279580471817042
926874772929159807
266108003411613138
348671726554163213
787242831117333331
187301735886309798
635596203831316291
553410429155963662
376270261077334192
815709256315181144
14892128913644339
197540614713256509
658725046928934258
442177149876147871
698084301688992402
543221911389689622
791149542957369345
623609677424007935
755956934820742276

In #4:
1
0 0 1000000000000000000
Out #4:
0

In #5:
1
0 1000000000000000000 0
Out #5:
0

In #6:
1
0 1000000000000000000 1000000000000000000
Out #6:
0

In #7:
1
1000000000000000000 0 0
Out #7:
0

In #8:
1
1000000000000000000 0 1000000000000000000
Out #8:
1000000000000000000

In #9:
1
1000000000000000000 1000000000000000000 0
Out #9:
0

In #10:
1
1000000000000000000 1000000000000000000 1000000000000000000
Out #10:
1000000000000000000

*/

