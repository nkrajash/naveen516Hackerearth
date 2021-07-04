/* All Tracks -->  Math  --> Problem -->
Picking coins
Tag(s): Easy, Mathamatics, Mathematics, Mathematics
Alice and Bob are playing a game of picking coins. They are given a large pile of N coins and an integer k. 
In the ith move of any player, k^i coins are picked from the pile. A player who is not able to make the move during his turn loses. You are required to predict the winner of the game.

Note: In every turn, Alice plays first followed by Bob.

Input format:
First line: T that represents the total number of test cases
Each line of the test case: Two space-separated integers N and k.

Output format:
For each test case, you are required to print the name of the winner of the game. You have to print either Alice or Bob depending upon who is the winner of the game.

Constraints:
1<=T<=100
1<=N<=k<=10^18

SAMPLE INPUT 
4
10 3
14 2
18 10
37 5
SAMPLE OUTPUT 
Bob
Bob
Alice
Alice
Explanation
Test Case 1
In the first move: Alice first removes 3 coins, then Bob also removes 3 coins.
In the second move: Alice has to remove 9 coins but since only 4 are available, Alice loses and Bob wins.

Test Case 2
In the first move: Alice first removes 2 coins, then Bob also removes 2 coins
In the second move: Alice removes 4 coins, then Bob also removes 4 coins and only 2 coins remain.
In the third move: Alice has to remove 8 coins but it is not possible so Bob wins.

Similarly, the other two test cases can be followed.

//My C Solution:
#include <stdio.h>
#include <math.h>

int main(){
    long long int N,k,j,cntAB=1,T,Bflag=0;
    scanf("%lld",&T);
    for(j=0;j<T;j++){
        Bflag=0;
        cntAB=1;
        scanf("%lld",&N);
        scanf("%lld",&k);
        while(N>0){
            if(k==1){
                N=N%2;
                if(!N)
                    Bflag=1;
                    break;
            }
            N=N-((long long)(pow(k,cntAB)));
            if(N<0){
                Bflag=1;
                break;
            }
            N=N-((long long)(pow(k,cntAB)));
            cntAB = cntAB + 1;
        }
        if(Bflag)
            printf("%s\n","Bob");
        else
            printf("%s\n","Alice");
    }
    return 0;
}

*/

/*Editorial:
Let us solve this problem for k>=2. 
In the first move total removed coins are 2*k coins, then 2*k^2 and so on. For the least value of k 
i.e. k=2  this will reduce the given input N to 0 in at most 60-64 steps as 2^64>10^18. 
So if we just simulate the process then you can easily pass all the test cases.

For k=1 the above algorithm becomes very slow as 1^i =1 so we can check if N is even it means the last move was played by Bob and Alice is not left with any coins, 
similarly for odd N the last move will be played by Alice.

Note: You need to carefully implement the above algorithm in languages like C++ because overflow may happen in calculating powers of k if k is very large.

Author Solution by Saurabh
T = int(input())
for i in range(0 , T):
    n , k = map(int , input().split())
    if k == 1:
        if n % 2 == 0:
            print ("Bob")
        else:
            print ("Alice")
    else:
        ini = k
        for turn in range(0 , 10000):
            if n < ini:
                print ("Bob")
                break
            n = n - ini
            if n < ini:
                print ("Alice")
                break
            n = n - ini
            ini = ini * k
Tester Solution by Ivan Safonov
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    ll n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << ((n % 2) == 1 ? "Alice\n" : "Bob\n");
        return;
    }
    int t = 0;
    ll nn = n;
    while (nn >= k)
    {
        nn /= k;
        t++;
    }
    ll x = 1;
    for (int i = 0; i < t; i++)
    {
        x *= k;
        n -= x;
        if (n < 0)
        {
            cout << "Bob\n";
            return;
        }
        n -= x;
        if (n < 0)
        {
            cout << "Alice\n";
            return;
        }
    }
    cout << "Bob\n";
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}


*/

/*Best Submissions:
C:
#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int N,K;
		int c=0;
		scanf("%lld %lld",&N,&K);
		if(N!=0)
		if(K==1)
		{
		    if((N)%2==0)
		    printf("Bob\n");
		    else 
		    printf("Alice\n");
		    
		}
		else
		{
		double a=(double)N,n=(double)N,k=(double)K,p;
		for(double i=1;i<=a;i++)
		{
			p=pow(k,i);
			if(n>=p)
			{
			n-=p;
				c++;
			}
			else 
		    break;
			if(n>=p)
			{
			n-=p;
				c++;
			}
			else 
			break;
		}
		
		if(c%2!=0)
		printf("Alice\n");
		else 
		printf("Bob\n");
	}
	}
}

C++:
#include<bits/stdc++.h>
 
typedef unsigned int uint;
typedef __int128 ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
typedef std::pair<int,int> pii;
 
#define xx first
#define yy second
 
template<typename T> inline T max(T a,T b){return a>b?a:b;}
template<typename T> inline T min(T a,T b){return a<b?a:b;}
template<typename T> inline T abs(T a){return a>0?a:-a;}
template<typename T> inline bool repr(T &a,T b){return a<b?a=b,1:0;}
template<typename T> inline bool repl(T &a,T b){return a>b?a=b,1:0;}
template<typename T> inline T gcd(T a,T b){T t;if(a<b){while(a){t=a;a=b%a;b=t;}return b;}else{while(b){t=b;b=a%b;a=t;}return a;}}
template<typename T> inline T sqr(T x){return x*x;}
#define mp(a,b) std::make_pair(a,b)
#define pb push_back
#define I __attribute__((always_inline))inline
#define mset(a,b) memset(a,b,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
 
#define fo0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define fd0(i,n) for(int i=(n)-1;~i;i--)
#define fd1(i,n) for(int i=n;i;i--)
#define fd(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define foe(i,x)for(__typeof((x).end())i=(x).begin();i!=(x).end();++i)
#define fre(i,x)for(__typeof((x).rend())i=(x).rbegin();i!=(x).rend();++i)
 
struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;
#define UC unsigned char
#define RX x=0;UC t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;\
if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RL if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0;UC t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define TR *this,x;return x;
I bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;I Fr&OP,(int&x)
{RX;if(f)x=-x;RT}I OP int(){int x;TR}I Fr&OP,(ll &x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I Fr&OP,(char&x)
{for(x=P();IS(x);x=P());RT}I OP char(){char x;TR}I Fr&OP,(char*x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS
(t)&&~t;t=P())*x++=t;}*x++=0;RT}I Fr&OP,(lf&x){RX;RL;RT}I OP lf(){lf x;TR}I Fr&OP,(llf&x){RX;RL;RT}I OP llf()
{llf x;TR}I Fr&OP,(uint&x){RU;RT}I OP uint(){uint x;TR}I Fr&OP,(ull&x){RU;RT}I OP ull(){ull x;TR}};Fr<Cg>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;UC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){UC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char*x){while(*x)P(*x++);RT}
I Fw&OP()(const char*x){while(*x)P(*x++);RT}I Fw&OP()(lf x,int y){WL;RT}I Fw&OP()(llf x,int y){WL;RT}};Fw<Cp>out;
 
int main()
{
	for(int T=in;T--;)
	{
		ll n,k;
		in,n,k;
		bool ans;
		if(k==1)
		{
			ans=n&1?1:0;
		}
		else
		{
			ll t=k;
			while(1)
			{
				if(n<t){ans=0;break;}
				n-=t;
				if(n<t){ans=1;break;}
				n-=t;
				t*=k;
			}
		}
		out,!ans?"Bob":"Alice",'\n';
	}
}

C++14:
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
      ll n,k,m,u,i=0;
      cin>>n>>k;m=k;u=n;ll z=1;
      if(m==1)
      {
        if(n%2==0)
      {
          printf("Bob\n");
          
      }
      else
      {
          printf("Alice\n");
      }  
      }
      else 
      {
          for(int i=1;i<n;i++)
          {
             u=u-(pow(k,z)); 
             if((u<0)&&(i%2==0)==1) 
             {
                 cout<<"Alice\n";
                 break; 
             }
             
             if(u<0&&(i%2==1)==1)  
              {
                  
                  cout<<"Bob\n";
                break;   
                  
            }
              if(i%2==0)
              {z++;}
          }
      }
  } 
}

C#:
using System;
 
public class Program {
 public static void Main() {
  int numTest = Convert.ToInt32(Console.ReadLine());
  while (numTest != 0) {
   string[] input = (Console.ReadLine().Split(' '));
   long n = Convert.ToInt64(input[0]);
   long k = Convert.ToInt64(input[1]);
   double challengeCount=k;
   long i = 1;
   while (1 == 1) {
    //alice
    i++;
    
    if(challengeCount == 1){
    
        if(n % 2 == 0){
                Console.WriteLine("Bob");
                 break;
        }
        else {
                Console.WriteLine("Alice");
                 break;
        }
        
    }
 
    
    if (challengeCount <= n) {
     n = (n -  Convert.ToInt64(challengeCount));
    } else {
     Console.WriteLine("Bob");
     break;
 
    }
 
    //bob
    if (challengeCount <= n) {
     n = (n - Convert.ToInt64(challengeCount));
 
    } else {
     Console.WriteLine("Alice");
     break;
    }
 
    challengeCount = Math.Pow(k, i);
 
   }
   numTest--;
  }
 }
}

Java:
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
//import for Scanner and other utility classes
import java.util.*;
 
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static long pow(long a,long b)
    {
        //System.out.println(b);
        if(b==0)
        return 1;
        long half=pow(a,b/2);
        if(b%2==0)
        return half*half;
        if(b%2!=0)
        return half*half*a;
        return 0;
    }
    public static String Solve(long N,long K)
    {
        if(K==1)
        if(N%2==0)
        return "Bob";
        else
        return "Alice";
        if(K>N)
        return "Bob";
        long count=1;
        long p= (long)2*(long)Math.pow(K,count);
        while(N>=p && p>0)
        {
           // System.out.println(p);
            N=N-p;
              // System.out.println(N);
            count++;
            
            p=(long)2*(long)Math.pow(K,count);
        }
        if(p<0)
        return "Bob";
        long j=N-(long)Math.pow(K,count);
     
        if(N==0)
        return "Bob";
        if(j>=0)
        return "Alice";
        else
        return "Bob";
        
        
        
    }
    public static void main(String args[] ) throws Exception {
       StringBuilder out=new StringBuilder();
       BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
       int t=Integer.parseInt(br.readLine());
      
       for(int i=0;i<t;i++)
       
       {
           String in[]=br.readLine().split(" ");
           long N=Long.parseLong(in[0]);
           long K=Long.parseLong(in[1]);
           out.append(Solve(N,K)+"\n");
       }
       System.out.println(out);
       
    }
}

Java8:
import java.io.*;
import java.util.*;
import java.math.BigInteger;
 
public class LittleMonkAndFlipOperations {
 
	private static Reader scanner = new Reader();
	private static Print printer = new Print();
 
	public static void main(String[] args) throws IOException {
		new Thread(null, new Runnable() {
			public void run() {
				try {
					process();
					printer.close();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}, "1", 1 << 26).start();
	}
	
	private static class Print {
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
	
	private static class Reader {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;
 
		public Reader() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
 
		public Reader(String file_name) throws IOException {
			din = new DataInputStream(new FileInputStream(file_name));
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
 
		public String readLine() throws IOException {
			byte[] buf = new byte[64]; // line length
			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == '\n')
					break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt);
		}
 
		public int nextInt() throws IOException {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
 
			if (neg)
				return -ret;
			return ret;
		}
 
		public long nextLong() throws IOException {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}
 
		public double nextDouble() throws IOException {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
 
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
 
			if (c == '.') {
				while ((c = read()) >= '0' && c <= '9') {
					ret += (c - '0') / (div *= 10);
				}
			}
 
			if (neg)
				return -ret;
			return ret;
		}
 
		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}
 
		private byte read() throws IOException {
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}
 
		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
		}
	}
 
    private static class Edge implements Comparable<Edge> {
	    public int x, y;
 
	    public Edge(int x, int y) {
	        this.x = x;
	        this.y = y;
	    }
 
		public int compareTo(Edge o) {
			if (x != o.x)
	            return x - o.x;
			return y - o.y;
		}
		
		public boolean equals(Object obj) {
    		Edge e = (Edge) obj;
    		return x == e.x && y == e.y;
	    }
	    
	    public String toString() {
	        return "(" + x + ", " + y + ")";
	    }
	}
	
    private static int max = (int) (1e6 + 1);
    private static int mod = (int) (1e9 + 7);
 
    private static List<Integer> primes = new ArrayList<Integer>();
	private static void init() {
	    boolean[] p = new boolean[max];
		p[0] = true;
		p[1] = true;
		for (int i = 2; i < max; i++) {
			if (p[i])
				continue;
			primes.add(i);
			for (int j = i + i; j < max; j += i) {
				p[j] = true;
			}
		}
	}
	
	private static void process() throws IOException {
		int t = scanner.nextInt();
		for (int i1 = 1; i1 <= t; i1++) {
		    long n1 = scanner.nextLong();
		    long k1 = scanner.nextLong();
		    if (k1 == 1) {
		        if (n1 % 2 == 1)
		            printer.println("Alice");
		        else
		            printer.println("Bob");
		        continue;
		    }
		    if (n1 < k1) {
	            printer.println("Bob");
		        continue;
		    }
		    BigInteger k = BigInteger.valueOf(k1);
		    BigInteger n = BigInteger.valueOf(n1);
		    BigInteger cur = BigInteger.valueOf(k1);
		    String res = "Alice";
		    while (n.longValue() > 0) {
		        if (n.compareTo(cur) < 0) {
		            res = "Bob";
		            break;
		        }
		        n = n.subtract(cur);
		        if (n.compareTo(cur) < 0) {
		            res = "Alice";
		            break;
		        }
		        n = n.subtract(cur);
		        cur = cur.multiply(k);
		        //cur *= k;
		    }
		    printer.println(res);
		}
	}
 
}
Perl:
use warnings;
use strict;
 
sub get_winner{
	my ($N, $k) = @_;
 
	if($k == 1){
		return "Bob" if(($N % 2) == 0);
		return "Alice";
	}
 
	my $coin_count = $k;
	while($N >= 0){
		$N -= $coin_count;
		return "Bob" if($N < 0);
		$N -= $coin_count;
		return "Alice" if($N < 0);
		$coin_count *= $k;
	}
	return "Bob";
}
 
my $t = <STDIN>;
 
while($t--){
	my $input = <STDIN>;
    my ($N, $k) = split(' ', $input);
    
 
    my $ans = get_winner($N, $k);
    print $ans."\n";
}


Python:
s=int(raw_input())
for i in range(s):
    n,p=map(int,raw_input().split())
    if(p==1):
        if(n%2==0):
            print('Bob')
        else:
            print('Alice')
    else:
        i=1
        while(1):
            l=p**i    
            if(n-2*l>0):
                n=n-2*l
            else:
                if(n-l>0):
                    n=n-l
                else:
                    print("Bob")
                    break
            
                print("Alice")
                break
            i=i+1


Python 3:
# Picking Coins
from sys import stdin, exit
 
testcase = int(stdin.readline())
for i in range(testcase):
    transition = stdin.readline().split(" ")
    N = int(transition[0])
    k = int(transition[1])
 
    if k is 1:
        if N%2 is 1:
            print("Alice")
        else:
            print("Bob")
    else:
        pick = k
        while N >= 0:
            if N < pick:
                print("Bob")
                break
            N -= pick
            if N < pick:
                print("Alice")
                break
            N -= pick
            pick *= k

PHP:
<?php
	
	while($input=fgets(STDIN)){
		
		$input = explode(" ",$input);
   		if(count($input)==2){
        	
        	$i = 0;
        	$rem = $input[0];
			$k =  $input[1];
 
			if($k == 1){
 
				if($rem % 2 == 0)
					echo "Bob\n";
				else
					echo "Alice\n";
			}else{
				echo divide_share();	
			}
    	}
	}
	
 
	function divide_share(){
		global $i,$rem,$k;
		$i++;
		
		
 
		$pow_value = $k ** $i;
		
		if($rem < $pow_value){
			return "Bob\n";
		}
		else if($rem < 2 * $pow_value){
			return "Alice\n";
		}
		$rem -= 2 * $pow_value;	
		return divide_share();
	}
	
?>

*/


/*I/0:
In #1:
6
44756 7
4589 2
31821 5
98250 7
39023 8
87305 10
Out #1:
Bob
Bob
Alice
Bob
Bob
Bob

In #2:
1
29996 9
Out #2:
Bob

In #3:
6
36268 9
69809 9
58305 9
10033 2
60430 6
51238 1
Out #3:
Bob
Bob
Bob
Bob
Bob
Bob
In #4:
10
71909 10
76657 5
40624 10
13704 4
46145 2
69095 2
24957 10
46193 10
71918 5
72894 8
Out #4:
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Alice
In #5:
10
69106 1
79881 1
98803 2
4430 7
73001 9
14746 7
97387 8
46583 3
21205 2
30681 1
Out #5:
Bob
Alice
Alice
Alice
Bob
Bob
Bob
Alice
Bob
Alice

In #6:
7
320230004 7
106357884 3
578939987 7
53619688 4
759556267 6
598709645 6
38448348 8
Out #6:
Bob
Alice
Alice
Alice
Bob
Bob
Alice
Alice
In #7:
8
93792026 2
822074098 3
844599638 6
92094121 7
978746505 9
226742201 5
579882236 6
886488125 2
Out #7:
Bob
Alice
Alice
Alice
Bob
Bob
Alice
Alice

In #8:
1
661533943 2
Out #8:
Bob

In #9:
8
359725409 2
270776079 10
102586586 4
122361663 7
303408890 3
819779304 3
9788880 3
528682246 1
Out #9:
Bob
Bob
Bob
Bob
Alice
Alice
Alice
Bob

In #10:
1
69687408 9
Out #10:
Alice

In #11:
9
959458241 7
498459723 6
443711494 7
317960712 9
767764394 1
815317068 6
407131845 2
153412342 5
119330100 7
Out #11:
Bob
Bob
Alice
Bob
Bob
Alice
Alice
Bob
Bob

In #12:
5
519106189 2
149402477 5
572948198 7
443873809 1
3962462 8
Out #12:
Alice
Bob
Alice
Alice
Alice

In #13:
25
33533867086248778 10
72843204887357550 3
552290278351427392 3
209927122637326185 8
7092489159942360 6
10251099367495308 2
5999286940666902 8
44058531470356172 3
504125783985988818 7
71906413836422567 3
288533311872859147 10
71057348544431664 2
55304916188110680 6
71880133415216688 10
25075138919892976 3
8254350794039994 3
5016867706671996 10
163176122342795831 1
91723125341482680 6
223690933427283084 4
820933881911513120 4
176933541381414363 3
158697330760247832 4
37286020161845433 9
51257004567729400 1
Out #13:
Bob
Bob
Bob
Alice
Alice
Bob
Bob
Alice
Bob
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Alice
Alice
Bob

In #14:
94
520513544284070400 3
541198346186742438 10
71163227404258288 6
139229316320791608 2
44555584323565146 8
130228063815461760 1
355114544102622480 5
185210218698335917 1
295048650006957888 1
332247977591259048 2
118759808122592226 2
449326587230962896 9
131555417197037592 5
8718651778403567 10
112034890765894390 1
177783471978101440 10
39561630619716870 2
245240197083323780 4
145251896059137984 7
339039034691121916 5
7948584386481600 8
221357185036583941 5
282375090785540536 8
236526032575481428 2
26817096243700961 1
10321746368422374 2
29097314668913768 7
223727006889668780 3
6900766019512233 9
44957912640758358 9
292172234987040245 10
408009922649958442 2
34528058920269720 6
210237227865173967 10
160304197309958520 2
3928004996639250 3
32715701068844112 4
144782038953618110 9
176772816471304201 9
5755937628513303 6
693386069623544187 3
65133914909764844 9
36428689552010742 6
109540478834074148 10
310876109571184770 1
192120034451737915 10
317760306075582587 9
124041398554347356 9
5804391011030724 5
432492956226743558 5
27671908792018728 5
34471121528523300 10
3131838950038647 6
94205411105385110 1
147184904228413608 6
363913712960543856 4
236100642381629927 4
36722329163830391 6
277110241163972955 1
4171117320802247 9
73645529618916808 1
36389285298049782 6
187095848175090964 1
205658224130762309 5
137506942736420400 5
37043495243995695 6
139611503193855480 6
178261825877460660 8
39463566448681151 4
16344043334328423 10
373429533692572371 4
147844579726183469 7
77917127088693486 10
3584747392170363 6
77892576155799328 10
21286632176311050 2
143126961149407993 1
339789113160563808 7
481351993279852728 10
41918492533791965 4
540085109863628269 7
319445912583228240 1
254928324832770996 7
12668279192438544 1
271638059858448080 4
13044685701857735 3
57505457518649003 1
58628204816406348 5
214079293809434475 6
39596916802193024 2
293404437042946680 9
129872724458813318 10
6078877088895180 3
166733929111671616 6
Out #14:
Bob
Bob
Bob
Alice
Bob
Bob
Bob
Alice
Bob
Bob
Alice
Bob
Alice
Bob
Bob
Alice
Bob
Bob
Alice
Bob
Bob
Bob
Alice
Alice
Alice
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Alice
Alice
Bob
Alice
Alice
Bob
Bob
Alice
Bob
Bob
Alice
Bob
Bob
Alice
Alice
Bob
Alice
Bob
Alice
Bob
Bob
Bob
Bob
Bob
Bob
Alice
Alice
Bob
Bob
Alice
Bob
Bob
Alice
Alice
Bob
Bob
Alice
Alice
Bob
Alice
Bob
Bob
Bob
Bob
Alice
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Bob
Alice
Alice
Bob
Alice
Bob
Alice
Alice
Bob
Bob

In #15:
7
360266165507132738 9
257096784253120840 1
1803126241959480 9
13167366043817536 2
62971618435588508 8
151876706871471662 5
211023370638015852 3
Out #15:
Bob
Bob
Bob
Bob
Bob
Bob
Bob

In #16:
10
21592813067783856 595289155541719808
477240902104096515 27180113834725326
363054239352820392 66658794763643392
83671844479201707 436455145584794583
201701217204973680 36791369173054636
152493824552978720 513960358809317650
410908585265816580 20808276271481390
69827709730012520 349634290240304910
448365987887290894 2499861888883296
21920458468942056 1031611562762704
Out #16:
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob

In #17:
9
78159692118262586 21500175737579338
110906877144756420 140331073946542734
102637416593941582 206308604346422622
197133345254409460 172519146856731184
149284940243335454 406149007548986225
34832853389778708 159719567363970630
230049797627561975 20080437898999170
464991387903899978 192759592131416994
322246206694193903 589527819889925796
Out #17:
Bob
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Bob

In #18:
6
85294821236309980 33374166735669056
172402911293617587 347495352903116379
271255197462555042 396218805064329819
434366375951694312 58874279927407350
151048415386343835 451066113869729016
993770522728950 357324197795884283
Out #18:
Bob
Bob
Bob
Bob
Bob
Bob

In #19:
1
505692864817209352 540175499905195125
Out #19:
Bob

In #20:
8
399545103963888234 25067522009961748
68386329236749944 190626843423320576
160965110555112064 9915182536718465
4822439813077140 12463178566608000
481732024217401365 296558982455953625
264563188063811465 180067972682083290
503899980129721332 28304777285163150
691619075997205312 179561500007810866
Out #20:
Bob
Bob
Bob
Bob
Alice
Alice
Bob
Bob

In #21:
22
228839351999339772 93372843886380696
38338342836486930 215994393424771360
91571764564675572 353949519885285105
156755933485325640 145885791134538216
698890538558368650 15427393341529700
8754039779932992 64492105857686682
127160810668095136 325521392877258
345134501843469976 785589527316627484
65490905330868072 767288491117482900
278671139873431620 31397451580817829
334138051611427945 454102241190022125
278436063097505534 287259775362510802
35856377209358208 304103787660173667
257985231502356022 457969042955206370
335361473929144505 28719570239034668
10526761237522315 119239820646152745
616418297194458918 16504124253709670
14110028287801950 234898474566462093
93062573011473600 282696196929256071
245320465483075200 339782251695789800
39125734800718368 66283600176603770
518560839269107404 2807332065063075
Out #21:
Bob
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob

In #22:
59
462142832603429096 477945508403589542
6864148924518808 92271637457452426
20781566519875140 7063738191847440
430350149061824835 148021621874302029
433712801044151620 348740781489241800
131034744544273700 284182394428394924
12414232096393370 35784514560209377
93870628105620240 157831705026391749
198466687894965050 664226718051658476
75932925787834197 471337285016194322
76678289313840060 274098372533658156
98518786493710968 536875593326589925
509720698470623468 7345875759283173
439989217790477400 548834909006664126
431195432160391090 26529949996853310
849991371417508080 81293294292640512
558958130719524 31994771084095072
72777731203418501 220748384364451889
23335949402067000 345186324890155344
831298210708274316 612845812717690320
362462420891714688 169701557540838821
46523833932018872 55188189357802608
683438990134620 491079845878961586
144752938797357220 268038779589542
89560633880392916 432670577416715240
145480215427395480 3962992750669998
6259575540141057 298033225537210
152849758313329620 60244546531412544
286094674104462070 6848320446868153
140921030345148345 311508074873345180
132983908001008884 111827353808357114
11768471825852970 656779252375397136
1054781174482982 77750812654998354
129307883212649556 66580433799042336
300452713754403075 195866834254259230
581393256155429774 200438082182428510
77535182316200577 273376567192517004
15111352899680646 14613928688846676
53943594724424916 199767442777682500
103648208062431635 23831962463765699
212789888262790515 283739942137086032
183399684090175158 741165918839937584
85704574468770 170815856719224652
839246165097959656 28889226274538116
43221030273168000 179332872683878968
72774341723715485 77799039747975480
110931034004258274 36697640051285952
140139328171733920 378899909161845478
41955771696423354 13710244317546464
453259987664649074 80645767662221862
319752123639818151 27948362594214392
189486309912531936 362442910795257894
143792552241900153 938342795595960096
273947212095605048 73924049704587420
104315470859031330 693762868720350114
139836074643590930 132003023713584674
92899584484512156 467266574874163971
10514992695488112 339413143638714975
467673224931353434 217633568502815530
Out #22:
Bob
Bob
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Alice
Bob
Bob
Alice
Alice
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Alice
Bob
Bob
Bob

In #23:
53
325389065029677410 418770424536570132
27617532435995175 321553416110094608
60170341264623196 75427872558749880
608771028120834310 22885022854143591
438004028184609744 259912285350167406
48761845018253618 49201652470304178
32237652355935464 11350863160663440
570961432290777577 98255192397610776
142383114433515307 147506542626297474
142089542911215060 360642072260487589
87628711508782136 828949171498791288
151438204137097456 51939935144735328
95477991637494330 550920776666551920
152146696903023060 24013779011343570
736930095357318395 12259838866121982
272699209900945825 498934679983199268
83703068225356916 76071608514555948
71573845037367260 188891431591598857
451316048495513658 4034366691121965
70453757367578452 13272306324339172
873148588341692955 24937807625124304
444466030483857240 33973199706944264
47690181200372040 751546327490118138
201861313619600557 114955961191701198
288737687571456906 409376195669262624
229772070434218968 555148609698794514
306411412622605099 435454345522507376
6473109216086260 389040739350492724
39473719914514434 398653049652315444
418819740920256000 654159285886606218
563207193830673422 178448312996369724
85638345779705970 235748018228828490
141467956622674873 662093484918464676
418597187281267368 176413785476959712
216071925463159808 907568828737685688
35257531728462010 646134647830930440
59427940795012392 156539556574920558
31599006400342452 14580106276802220
488809426739824551 150588086790069204
369972784537792150 1291754846060235
591332839955257542 520593198250579680
14155875906518814 749708259040570440
206156973412076709 248532483704873550
299271837295902840 20499029432099790
289290492747998125 497700868556489874
328046772992127266 72323694677277066
325980743161185684 509673240303398052
158075358039715725 257927491543327885
649474752072165955 772060182851293150
559947889101265110 631537070177910136
50219005231605351 98484638683078555
162588192489266544 26974099649061587
825135567586297480 216923073036359760
Out #23:
Bob
Bob
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob

In #24:
4
876973224130200 12588885336319984
17243495885526920 531870963771322071
98336789825927925 65354172269939807
8846610633212135 145021616167276224
Out #24:
Bob
Bob
Alice
Bob

In #25:
95
128000883249085956 490022750294213419
333813224739211051 913226800693592628
42511099210484160 416834311710005370
121556210789906860 49055771929927598
129090554966747137 213591293900555910
50668195661303895 13897203566747904
539795071864663604 310964557535092860
122195421417213056 1249136076039264
330254566590566422 306383462794560140
637728593795494455 26573164812608610
455406194598843255 726217422451366720
236524444731725332 215405724125719580
812380162007417476 1647034055648739
19786943333136477 43517721161068284
459365374899216054 884298112498471564
107448863946921522 525579220908516432
80979350348653398 60009448424437410
10984529618273070 672889683605016780
433108440745055174 438938088129242975
237655031127630112 92981011366421488
483588322274943136 7528234977787305
262345698457198318 86106491643340980
761734788689348640 208029149818196460
625731860323225168 346230693963692610
112174287093054195 201219111992049448
203702723349931568 37528153234006024
35352184449662010 351064546301928532
18599151924649386 264954877206216437
112633047923369250 343389384993739050
482577815238695658 123351709674535258
188263703666253100 6864460583032534
172465245646205123 493757204185343693
374690316092560416 14612218656036321
619424651688425022 3479626454854492
684188864465489242 4145315606728296
50129732474994425 81846912900960256
244845323236729156 2962337525855461
28696792473161587 275457155605668945
689029906004272350 54226012872472612
21796680287531768 78791968273145155
154702610144763044 46079818487083282
48176732067574176 356223135604293702
449906889336440220 518788008440911910
59195255790009554 801828631692614346
625243348948602296 722896734364567532
33529311535980628 201855970717403966
65217702455447432 317508518336018392
215363686800702272 10960014762748955
218464474967272683 151041957965992040
187466691669767224 172380473192203948
332325392543628813 370611020815520801
267777431547113025 207238011257362920
21663914837265314 37842885042447240
195210254751999036 681771850455099251
522831617527572966 72837287184314081
450235776159307719 227047399620782879
777883780612222407 75873511434977274
12137371450303392 569840159370306396
149955770272725801 284117888286499280
397312279975517850 51230957312991582
25956033819768644 351647435172265210
161245469736823485 91452450645227714
334357577305320864 534436919122614175
176796324323267948 44096519648169872
744784095098487510 176843386602878715
93925534017680079 23655617604105928
111457078973129448 674858822635534647
61098928492229833 1159674164934780
32270581964429940 279926178430954320
49611214227270921 438048706480772811
79510519081082430 45989433694660377
99332574369900828 177867794255177122
782906570638596344 261132726134301828
15800685255897695 252040388918256852
426740683508599400 30773721505859706
114439319072124 16914543497759304
333176889280858720 92442674227983120
83925200713315354 812707611107219732
18537198083700500 569874453327794560
108636078260359800 79692914131979520
12807108573228830 29621590541562922
50198356239437022 243036274957119200
119665275601642368 640577415372080266
83621718968860940 452505934556262741
160259975977517404 14689687926770035
177027484714542437 340318135596406758
390162446088468396 31495153112648368
620598564455616660 902626322727912727
19439928317433470 6973063509404379
54352361595794070 779598357971257400
90421993577186106 189409561234375909
64310111604330174 573923038682828961
368609747492128398 456396208038724086
2466249069222210 119055141438847686
112476823240403768 279430418907982872
Out #25:
Bob
Bob
Bob
Bob
Bob
Bob
Alice
Bob
Alice
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Alice
Alice
Bob
Alice
Bob
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Alice
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob
Bob

*/