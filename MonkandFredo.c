/*All Tracks -->  Math --> Number Theory --> Basic Number Theory-1  --> Problem --> Monk and Fredo
Tag(s): Greatest common divisor, Greatest common divisor, Mathematics, Medium, Number theory
Fredo and you are talking about a movie that you have recently watched while Monk is busy teaching Number Theory. 
Sadly, Monk caught Fredo talking to you and asked him to answer his question in order to save himself from punishment. 
The question says:
Given two weights of a and b units, in how many different ways you can achieve a weight of d units using only the given weights? 
Any of the given weights can be used any number of times (including 0 number of times).
Since Fredo is not able to answer the question, he asked you to help him otherwise he will get punished.
Note: Two ways are considered different if either the number of times a is used or number of times b is used is different in the two ways.

Input Format:
The first line of input consists of an integer T denoting the number of test cases.
Each test case consists of only one line containing three space separated integers a, b and d.

Output Format:
For each test case, print the answer in a separate line.

Constraints:
1<=T<=10^5
1<=a<=b<=10^9
0<=d<=10^9

SAMPLE INPUT 
4
2 3 7
4 10 6
6 14 0
2 3 6
SAMPLE OUTPUT 
1
0
1
2
Explanation
Test case 1:
7 can only be achived by using 2 two times and 3 one time.

Test case 2:
6 can't be achieved by using 4 and 10. So, 0 ways are there.

Test case 3:
0 can be achieved by using 0 times 6 and 0 times 14. So, there is only one way,

Test case 4:
6 can be achieved by using 2 three times or 3 two times. So, there are two different ways of getting 6.


#include<bits/stdc++.h>
#define dd double
#define ll long long
using namespace std;

ll g, x, y;

void extendedEuclid(ll A,ll B) {
    if(B == 0) {
        g = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        ll temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        ll a,b,d,e=0;
        cin>>a>>b>>d;
        extendedEuclid(a,b);
        if(d%g !=0){
            cout<<"0\n";
            continue;
        }

        ll k1=ceil(dd(-x)*(dd(d)/dd(b))),k2=floor((dd)y*((dd)d/(dd)a));
        if(k1<=k2)
            cout<<k2-k1+1<<"\n";
        else
            cout<<"0\n";
    }
    return 0;
}

*/


/*Editorial:
Author: shubham1428
Tester: r3gz3n
Editorialist: r3gz3n

Brief Description: Given a, b and d, find the number of pairs (x,y)  such that 0<=x,y and  a*x+b*y=d.

Prerequisite: Euclid Extended Algorithm

Difficulty: Medium

Detailed Explanation:
As we know that a*x+b*y=d  is a linear Diophantine equation in two variables. The solution of this equation exists if and only if d is divisible by the GCD(a,b) .

Solution 1:
The simplest solution is to try all the values of x and y. As we know that the values of x will be in range from [0,d/a]. 
Similarly the values of y will be in the range [0,d/b]. Time complexity of this solution is [0,(d^2/a*b)] which won't run within the time limit.

Solution 2:
a*x+b*y=d
a*x=d-b*y

We know that for one value of y there is at-most one x which will satisfy this equation. 
So, iterate over all values of y in the range  [0,d/b] and check if (d-b*y) is divisible by a or not. 
Time complexity of this solution is [0,d/b]  which is better than previous solution's complexity but still not good enough to pass within the time limit.

Note: We can also iterate over all values of x from [0,d/a] and check if (d-a*x) is divisible by b or not. But a<b, so d/b < d/a.

Solution 3:
Let y1  be the smallest non negative number such that (d-b*y1)  is divisible by a. We can say that y1 is the first value of y such that (d-b*y) is divisible by a.

If we have y1, the next value of y will be y1+a.
Why ??

Let y=y1+a.
d-b*y=(d-b)*(y1+a) = d-b*y1-b*a

But we know that d-b*y1 is divisible by a and b*a is also divisible by a, so d-b*(y1+a)  will also be divisible by a.

So, the values of y will be y1,y1+a,y1+2*a,y1+3*a,..y1+n*a  where y1+n*a <=d/b.
The values of y seems to be a Arithmetic Progression. So we can easily calculate number of terms in the Arithmetic progression using y1+n*a<=d/b equation.

n=((d/b) - y1)/a

So number of terms in the Arithmetic progression is equal to n+1.

Now the only part thats left is to find the value of y1. An obvious solution is to iterate over all values of y and break as soon as we find the first value 
such that d-b*y is divisible by a. Time complexity of this solution is O(d/b) in worst case. But this solution is faster then previous solutions in other cases.

Exercise: What is the worst case for this solution ?

Solution 4:

Note: A small optimization is divide both the side of the equation a*x+b*y=d  by the GCD(a,b). Why ?? Think about it.
We can compute the first value of y1 using Modulo Inverse (Extended Euclid).
a*x+b*y=d.
y=(d-a*x)/b

Taking modulo a both side.
y1 = y %a = ((d-a*x)/b) % a = (d/b) % a
Now we need to check if (d-b*y1) is divisible by a.
Let z=(d-b*y1)
z% a = (d-b*y1) %a
z% a = (d%a - (b%a)*(d/b %a))
z%a = 0
So y1 is the first value of y such that (d-b*y) is divisible by a.

We can compute y1  in O(log(max(a,b))) and number of term using the formula computed in the previous solution  n=((d/b)-y1)/a in O(1).
So the overall time complexity is O(log(max(a,b))).

Time Complexity: O(log(max(a,b)))
Space Complexity: O(1)

Author Solution by Shubham Gupta
#include<bits/stdc++.h>
#define dd double
#define ll long long
using namespace std;
ll g, x, y;
void extendedEuclid(ll A,ll B) {
    if(B == 0) {
        g = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        ll temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        ll a,b,d,e=0;
        cin>>a>>b>>d;
        extendedEuclid(a,b);
		if(d%g !=0){cout<<"0\n";continue;}
        ll k1=ceil(dd(-x)*(dd(d)/dd(b))),k2=floor((dd)y*((dd)d/(dd)a));
		if(k1<=k2)
			cout<<k2-k1+1<<"\n";
		else
			cout<<"0\n";
    }
    return 0;
}

Tester Solution by Akash Sharma
//
//
//	Author: r3gz3n
//	Description: 
//	Difficulty: 
//
//
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define alli(a, n, k) (a+k),(a+n+k)
#define REP(i, a, b, k) for(__typeof(a) i = a;i < b;i += k)
#define REPI(i, a, b, k) for(__typeof(a) i = a;i > b;i -= k)
#define REPITER(it, a) for(__typeof(a.begin()) it = a.begin();it != a.end(); ++it)
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define eps 1e-6
#define pi 3.141592653589793
using namespace std;
template<class T> inline T gcd(T x, T y) { if (!y) return x; return gcd(y, x%y);}
typedef vector<int> VII;
typedef vector<ll> VLL;
typedef pair<int, int> PII;
typedef vector< pair<int, int> > VPII;
typedef vector< pair<int, PII > > VPPI;
const int INF = 1e9;
const int MOD = 1e9 + 7;
ll d, x, y;
void extendedEuclid(ll A, ll B) 
{
    if(B == 0) 
    {
        d = A;
        x = 1;
        y = 0;
    }
    else 
    {
        extendedEuclid(B, A % B);
        ll temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
int modInverse(int A, int M)
{
    extendedEuclid(A, M);
    return (x % M + M) % M;
int main(int argc, char* argv[])
{
	if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
	if(argc == 3) freopen(argv[2], "w", stdout);
	ios::sync_with_stdio(false);
	int tests;
	ll a, b, d, b1, ans = 0, g, z, l;
	cin >> tests;
	assert(1 <= tests and tests <= 100000);
	REP(i, 0, tests, 1)
	{
		cin >> a >> b >> d;
		assert(1 <= a and a < b);
		assert(a < b and b <= 1000000000);
		assert(0 <= d and d <= 1000000000);
		g = gcd(a, b);
		if(d % g)
		{
			cout << 0 << endl;
			continue;
		}
		if(d == 0)
		{
			cout << 1 << endl;
			continue;
		}
		a /= g;
		b /= g;
		d /= g;
		b1 = d / b + 1;
		ans = 0;
		l = ((d % a) * modInverse(b, a)) % a;
		if(d < l*b) l = -1;
		
		if(l == -1) ans = 0;
		else ans = (b1 - l - 1) / a + 1;
		cout << ans << endl;
	}
	return 0;
}

*/


/*Best Submissions:
C:
#include <stdio.h>
long long int x,y,gcd;
void ext(long long int a,long long int b)
{
	if(b==0)
	{
		gcd=a;
		x=1;
		y=0;
	}
	else
	{
		ext(b,a%b);
		long long int temp=x;
		x=y;
		y=temp-((a/b)*y);
	}
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	long long int a,b,d;
    	scanf("%lld %lld %lld",&a,&b,&d);
    	ext(a,b);
    	if(d%gcd!=0)
    	{
    		printf("0\n");
    		continue;
    	}
    	else
    	{
    	//	printf("%lld %lld\n",x,y);
    		long long int min,max;
    		min = ceil((double)-x*((double)d/(double)b));
    		max = floor((double)y*((double)d/(double)a));
    		//printf("%lld %lld\n",min,max);
    		if(max>=min)
    		printf("%lld\n",max-min+1);
    		else
    		printf("0\n");
    	}
    	
    }
    return 0;
}

C++:
#include <bits/stdc++.h>
using namespace std;
 
#define fr(i,a,b) for(int (i)=(int) a;(i)<=(int)(b);++(i))
#define li list<int>
#define ll long long
#define mp make_pair
#define mod 1000000007
#define pb push_back
#define pi pair<int,int>
#define pr printf
#define vi vector<int>
#define vpi vector< pi > 
 
template<typename T>
void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( long long &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }
 
void sc() {}
template<typename T, typename... U>
void sc( T& head, U&... tail ) {
    _R(head);
    sc(tail...);
}
ll d,x,y;
void gcd(ll a,ll b)
{
	if(b==0)
	{
	    d=a;
	    x=1;y=0;
	    return;
	}
gcd(b,a%b);
ll t;
t=x;
x=y;
y=t-(a/b)*y;
 
}
 
int main() {
	// your code goes here
	int t=1;
	sc(t);
	while(t--)
	{
		ll a,b,c,l,g,res=0;
		sc(a,b,c);
		gcd(a,b);
		g=d;
		//cout<<g<<" "<<x<<" "<<y<<" ";
		if(c==0)
		{
		    cout<<"1\n";continue;
		}
		if(c%g!=0)
		{
		    cout<<"0\n";continue;
		}
		c=c/g;
		x=x*c;y=y*c;
	//	cout<<x<<" "<<y<<" ";
		ll u=a/g;
		ll v=b/g;
		
		if(y<0&y%u!=0)
		{
		   u=y/u-1; 
		}
		else
		u=y/u;
		
	    x=-x;
	   // cout<<x/v<<" "<<v<<" v ";
		if(x%v!=0)
		{
		    if(x>=0)
		v=x/v+1;
		else
		v=x/v;
		}
		else
		v=(x)/v;
	//	cout<<u<<" "<<v<<" ";
		if(u>=v)
		res=u-v+1;
		cout<<res<<"\n";
		
	}
	
	return 0;
}

C++14:
        #include <bits/stdc++.h>
        using namespace std;
         
        #define fr(i,a,b) for(int (i)=(int) a;(i)<=(int)(b);++(i))
        #define li list<int>
        #define ll long long
        #define mp make_pair
        #define mod 1000000007
        #define pb push_back
        #define pi pair<int,int>
        #define pr printf
        #define vi vector<int>
        #define vpi vector< pi > 
         
        template<typename T>
        void _R( T &x ) { cin>>x; }
        void _R( int &x ) { scanf("%d",&x); }
        void _R( long long &x ) { scanf("%" PRId64,&x); }
        void _R( double &x ) { scanf("%lf",&x); }
        void _R( char &x ) { scanf(" %c",&x); }
        void _R( char *x ) { scanf("%s",x); }
         
        void sc() {}
        template<typename T, typename... U>
        void sc( T& head, U&... tail ) {
            _R(head);
            sc(tail...);
        }
        ll d,x,y;
        void gcd(ll a,ll b)
        {
        	if(b==0)
        	{
        	    d=a;
        	    x=1;y=0;
        	    return;
        	}
        gcd(b,a%b);
        ll t;
        t=x;
        x=y;
        y=t-(a/b)*y;
         
        }
         
        int main() {
        	// your code goes here
        	int t=1;
        	sc(t);
        	while(t--)
        	{
        		ll a,b,c,l,g,res=0;
        		sc(a,b,c);
        		gcd(a,b);
        		g=d;
        		//cout<<g<<" "<<x<<" "<<y<<" ";
        		if(c==0)
        		{
        		    cout<<"1\n";continue;
        		}
        		if(c%g!=0)
        		{
        		    cout<<"0\n";continue;
        		}
        		c=c/g;
        		x=x*c;y=y*c;
        	//	cout<<x<<" "<<y<<" ";
        		ll u=a/g;
        		ll v=b/g;
        		
        		if(y<0&y%u!=0)
        		{
        		   u=y/u-1; 
        		}
        		else
        		u=y/u;
        		
        	    x=-x;
        	   // cout<<x/v<<" "<<v<<" v ";
        		if(x%v!=0)
        		{
        		    if(x>=0)
        		v=x/v+1;
        		else
        		v=x/v;
        		}
        		else
        		v=(x)/v;
        	//	cout<<u<<" "<<v<<" ";
        		if(u>=v)
        		res=u-v+1;
        		cout<<res<<"\n";
        		
        	}
        	
        	return 0;
        }


C#:
using System;
 
class MonkAndFredoCmNumberTheory {
    static long Bezout(long a1, long a2, out long x1, out long x2) {
        if (a2 == 0) {
            x1 = 1;
            x2 = 0;
            return a1;
        } else {
            var gcd = Bezout(a2, a1 % a2, out var y1, out var y2);
            x1 = y2;
            x2 = y1 - a1 / a2 * y2;
            return gcd;
        }
    }
 
    public static void Main() {
        var t = int.Parse(Console.ReadLine());
        for (int i = 0; i < t; ++i) {
            var line = Console.ReadLine().Split();
            var a1 = long.Parse(line[0]);
            var a2 = long.Parse(line[1]);
            var d = long.Parse(line[2]);
            var gcd = Bezout(a1, a2, out var x1, out var x2);
            if (d % gcd != 0) {
                Console.WriteLine(0);
            } else {
                if (gcd < 0) {
                    gcd = -gcd;
                    x1 = -x1;
                    x2 = -x2;
                }
                x1 *= d / gcd;
                x2 *= d / gcd;
                a1 /= gcd;
                a2 /= gcd;
                var tMin = -(double)x1 / a2;
                var tMax =  (double)x2 / a1;
                Console.WriteLine(Math.Floor(tMax) - Math.Ceiling(tMin) + 1.0);
            }
        }
    }
}

Java:
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;
import java.io.PrintWriter;
public class Problem5 {
 public static void main(String[] args) {
  try{
  Reader s=new Reader();
  PrintWriter o=new PrintWriter(System.out);
  int t=s.nextInt();
  
  while(t-- >0){
   long a=s.nextLong();
   long b=s.nextLong();
   long d=s.nextLong();
   gcd(a, b);
   long y=GCD;
   long ans=0;
   if(d%y==0){
    a=a/y;
    b=b/y;
    d=d/y;
    long n=-1;
    if(d%a==0){
     n=0;  
    }
    else{
     n=(d * modInverseUsingGcd(b, a))%a;
    }   
     if(d < n*b)ans=0; 
     else ans=((d/b) - n)/a +1;    
   }
     o.println(ans);
  }
  o.close();
  }
  catch(Exception e){
      
  }
 }
 static long GCD,Xinv,Yinv;
 static void gcd(long a,long b){
   if(b==0){
    GCD=a;
    Xinv=1;
    Yinv=0;
   }
   else{
    gcd(b,a%b);
    long temp=Xinv;
    Xinv=Yinv;
    Yinv=temp - (a/b) * Yinv;
   }
 }
 static long modInverseUsingGcd(long a,long m){
  gcd(a,m);
  return (Xinv%m + m)%m;
 }
 static class Reader
    {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
 
        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public Reader(String file_name) throws IOException
        {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public String readLine() throws IOException
        {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1)
            {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }
 
        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do
            {
                ret = ret * 10 + c - '0';
            }  while ((c = read()) >= '0' && c <= '9');
 
            if (neg)
                return -ret;
            return ret;
        }
 
        public long nextLong() throws IOException
        {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
 
        public double nextDouble() throws IOException
        {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
 
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
 
            if (c == '.')
            {
                while ((c = read()) >= '0' && c <= '9')
                {
                    ret += (c - '0') / (div *= 10);
                }
            }
 
            if (neg)
                return -ret;
            return ret;
        }
 
        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
 
        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
 
        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
        }
    }
}

Java 8:
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;
import java.io.PrintWriter;
public class Problem5 {
 public static void main(String[] args) {
  try{
  Reader s=new Reader();
  PrintWriter o=new PrintWriter(System.out);
  int t=s.nextInt();
  
  while(t-- >0){
   long a=s.nextLong();
   long b=s.nextLong();
   long d=s.nextLong();
   gcd(a, b);
   long y=GCD;
   long ans=0;
   if(d%y==0){
    a=a/y;
    b=b/y;
    d=d/y;
    long n=-1;
    if(d%a==0){
     n=0;  
    }
    else{
     n=(d * modInverseUsingGcd(b, a))%a;
    }   
     if(d < n*b)ans=0; 
     else ans=((d/b) - n)/a +1;    
   }
     o.println(ans);
  }
  o.close();
  }
  catch(Exception e){
      
  }
 }
 static long GCD,Xinv,Yinv;
 static void gcd(long a,long b){
   if(b==0){
    GCD=a;
    Xinv=1;
    Yinv=0;
   }
   else{
    gcd(b,a%b);
    long temp=Xinv;
    Xinv=Yinv;
    Yinv=temp - (a/b) * Yinv;
   }
 }
 static long modInverseUsingGcd(long a,long m){
  gcd(a,m);
  return (Xinv%m + m)%m;
 }
 static class Reader
    {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
 
        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public Reader(String file_name) throws IOException
        {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public String readLine() throws IOException
        {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1)
            {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }
 
        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do
            {
                ret = ret * 10 + c - '0';
            }  while ((c = read()) >= '0' && c <= '9');
 
            if (neg)
                return -ret;
            return ret;
        }
 
        public long nextLong() throws IOException
        {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
 
        public double nextDouble() throws IOException
        {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
 
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
 
            if (c == '.')
            {
                while ((c = read()) >= '0' && c <= '9')
                {
                    ret += (c - '0') / (div *= 10);
                }
            }
 
            if (neg)
                return -ret;
            return ret;
        }
 
        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
 
        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
 
        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
        }
    }
}

Python:
RI = lambda: map(int, raw_input().split())
 
def euk(a, b):
    if b:
        x, y, g = euk(b, a % b)
        return (y, x - y * (a / b), g)
    else:
        return (1, 0, a)
 
for _ in xrange(input()):
    a, b, d = RI()
    p, q, g = euk(a, b)
    if d % g:
        print 0
    else:
        p *= d / g
        q *= d / g
        l = a / g * b
        dp = l / a
        dq = l / b
        if p < 0:
            k = (abs(p) + dp - 1) / dp
            p += k * dp
            q -= k * dq
        k = p / dp
        p -= k * dp
        q += k * dq
        x = min(d / b, q)
        ans = 0 if x < 0 else (x / dq + 1)
        x = d / a - p
        ans = min(ans, 0 if x < 0 else (x / dp + 1))
        print ans

Python 3:
from math import ceil, floor
 
def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)
 
for _ in range(int(input())):
    a,b,c = map(int, input().split())
    a, b = min(a, b), max(a, b)
    d, x0, y0 = egcd(a, b)
    if c%d != 0:
        print(0)
        continue
 
    x0, y0 = x0*(c//d), y0*(c//d)
    sols = 0
    x, y = x0, y0
 
    if x > 0:
        t =  x // (b // d)
        x -= t*(b//d)
        y += t*(a//d)
 
        if y >= 0:
            sols += 1
        if y > 0:
            sols += y // (a//d)
 
    else:
        t =  y // (a//d)
        y -= t*(a//d)
        x += t*(b//d)
 
        if x >= 0:
            sols += 1
        if x > 0:
            sols += x // (b//d)
    print(sols)



*/