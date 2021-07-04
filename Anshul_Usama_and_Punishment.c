/* All Tracks  --> Data Structures   --> Arrays   --> 1-D   --> Problem
Anshul, Usama And Punishment - B
Tag(s): Easy

Anshul and Usama are fond of games and devote most of their time playing them. 
On one hand Anshul likes to play outdoor games like football, cricket, etc whereas on the other hand Usama likes to play mobile games like 
Clash of Clans, Mini Militia, etc. One day their teacher decided to punish them. As punishment, their teacher sent them to a building and locked all the 
exit points of that building. After locking the exit points, their teacher informed them from outside that the only way to come out of the building was by 
solving a problem.

The problem he gave was that they will be given some initial terms of a series and they have to use the series and tell him the maximum value of (|Ai + Aj|+|Ai - Aj|) 
where Ai and Aj are some ith and jth term of the series with the condition 0 <= i,j < n. Also, 'i' can not be equal to 'j'. 

The initial terms of the series are 20, 30, 40, 90, 80, 270,...

INPUT
The value of n= 62

OUTPUT
Output the maximum value of (|Ai + Aj|+|Ai - Aj|).

To see how to submit solution please check this link
Compile and Test can give Wrong Answer. Once you have written your answer, press Submit button to check your result.

SAMPLE INPUT 
5
SAMPLE OUTPUT 
180

#include <stdio.h>
#include <stdlib.h>
#define maximum(a,b) ((a>b)?(a):(b))
#define LEN 100

int main(){
	long int n,inseries[LEN]={20,30,40,90,80},i,j,max,temp;
	scanf("%ld",&n);
	if(n>5){
	    for(i=5;i<=n;i++){
            if(i%2)
	            inseries[i]=3*inseries[i-2];
	        else
	            inseries[i]=2*inseries[i-2];
	    }
	}
	temp=max=0;
	for(i=0;i<n;i++){
	    for(j=i+1;j<n;j++){
	        temp = labs(inseries[i]+inseries[j])+labs(inseries[i]-inseries[j]);
	        max = maximum(temp,max);
	    }
	}
	printf("%ld\n", max); 
	return 0;
}

//My Python Solution:
n = int(input())
l = [20,30,40,90,80,270]
if n>len(l):
    for i in range(6,n+1):
        if i%2==0:
            l.append(2*l[i-2])
        else:
            l.append(3*l[i-2])
y=0
for i in range(n):
    for j in range(i+1,n):
        ma = abs(l[i]+l[j])+abs(l[i]-l[j])
        y  = max(y,ma)
print(y)


//My Python Alt. Solution:
n = int(input())
l = [20,30,40,90,80]
if n>len(l):
    for i in range(5,n+1):
        if i%2==0:
            l.append(2*l[i-2])
        else:
            l.append(3*l[i-2])
y=0
for i in range(n):
    for j in range(i+1,n):
        ma = abs(l[i]+l[j])+abs(l[i]-l[j])
        y  = max(y,ma)
print(y)

*/

/*Editorial:
The series given in the question is 20,30,40,90,80,270 and so on. So, our first task is to identify the series and then find the nth term of the series. In order to identify the series do the following steps -
1. Divide the whole series by 10.
2. Now closely observe that the odd terms are in GP with 2 as first term and common ratio as 2 .
3. Similarly the even terms are in GP with first term as 3 and the common ratio as 3.
4. Now expand the series and find the nth term .
Store the series in an array of size n.
5. Now consider the equation |Ai+Aj|+|Ai-Aj|.
The above eqn can result in only 2 possibilities -
If Ai>Aj then the solution of the eqn will be 2Ai.
If Ai is less than Aj then the solution of the eqn will be 2Aj.
Now sort the array and find the maximum term , multiply it with 2 and get the required result .
The code for the problem is -

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n ,i,j=1,k=1;
    cin>>n;
    long long a[n];
    for(i=0;i<n;i++)
    {
        if(i%2==0)
        {
            a[i]=pow(2,j);//the odd terms of the series are in gp with first term and common ratio as 2.
            j++;
        }
        else
        {
            a[i]=pow(3,k);//the even terms of the series are in gp with first term and common ratio as 3.
            k++;
        }
    }
    sort(a,a+n);//Solve the given equation and you will get to know that it results in the (2*largest term of the array)
    cout<<2*(a[n-1])*10;//multiplication by 10 as the series given is 20,30...instead of 2,3...
    return 0;
}
*/

/*I/O:
In #1:
62

Out #1:
12353467925678940
*/

/*Best Submissions:
C:
 #include <stdio.h>
 #include<math.h>
int main()
{   
    long long int n,a=20,b=30,r1=2,r2=3,k,l;
    unsigned long long int m1,m2;
    scanf("%lld",&n);
    k=n/2;
    l=n-k;
    m1=b*pow(r2,k-1);
    m2=a*pow(r1,l-1);
    if(m1>m2)
        printf("%llu",2*m1);
    else
        printf("%llu",2*m2);
    
    
}

C++:
1).
#include <iostream>
#include<math.h>
#include<limits.h>
using namespace std;
int main() {
	// Writing output to STDOUT
	long long sum=0,x,y;
	int size;
	cin>>size;
	if(size%2==0)
	{
	    x=10*pow(2,(size)/2);
	    y=10*pow(3,(size)/2);
	     if(x>y)
	    {
	        sum=(x+20)+abs(x-20);
	    }
	    else
	    {
	        sum=(y+20)+abs(y-20);
	    }
	    
	    
	}
	else
	{
	    x=10*pow(2,(size+1)/2);
	    y=10*pow(3,(size-1)/2);
	    if(x>y)
	    {
	        sum=(x+20)+abs(x-20);
	    }
	    else
	    {
	        sum=(y+20)+abs(y-20);
	    }
	    
	}
	cout<<sum;
}

2).
#include <iostream>
#include<math.h>
#include<limits.h>
using namespace std;
int main() {
	// Writing output to STDOUT
	long long sum=0,x,y;
	int size;
	cin>>size;
	if(size%2==0)
	{
	    x=10*pow(2,(size)/2);
	    y=10*pow(3,(size)/2);
	     if(x>y)
	    {
	        sum=(x+20)+abs(x-20);
	    }
	    else
	    {
	        sum=(y+20)+abs(y-20);
	    }
	    
	    
	}
	else
	{
	    x=10*pow(2,(size+1)/2);
	    y=10*pow(3,(size-1)/2);
	    if(x>y)
	    {
	        sum=(x+20)+abs(x-20);
	    }
	    else
	    {
	        sum=(y+20)+abs(y-20);
	    }
	    
	}
	cout<<sum;
}

3).
#include <iostream>
 
using namespace std;
 
int main()
{
    int i,j,n;
    long long int max=0;
    cin >> n;
    long double a[n];
    a[0]=20;
    a[1]=30;
    for(i=2;i<n;i++)
    {
        if(i%2==0)
        {
            a[i]=a[i-2]*2;
        }
        else
        {
            a[i]=a[i-2]*3;
        }
    }
    if (n%2==0)
    {
        max=2*(a[n-1]);
    }
    else
    {
        max=2*(a[n-2]);
    }
    //for(i=0;i<n;i++)
    //{
    //    cout << a[i] << endl;
    //}
    //
    cout << max;
    return 0;
}

4).
#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout << "12353467925678940";    
}

C++14:
1).
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
     long long int x=20,y=30;
    for(int i=3;i<=n;i++){
        if(i%2==0){
            y=3*y;
        }
        else{
            x=2*x;
        }
    }
    cout<<abs(x-y)+abs(x+y);
}

2).
#include <bits/stdc++.h>
#define ull unsigned long long
#define pb push_back
using namespace std;
int main () {
int n;
scanf("%d", &n);
vector <ull> a;
for (int i = 1; i <= n; i++) {
a.pb(pow(2, i) * 10);
a.pb(pow(3, i) * 10);
}
ull maxn = 0;
for (int i = 0; i < n; i++) {
maxn = max(maxn, 2 * a[i]);
}
printf("%llu\n", maxn);
return 0;
}

3).
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main() {
	
    long long int n,k=1,j=1;
    cin>>n;
    long long int a[n];
    for(long long int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            a[i]=pow(2,j);
            j++;
        }
        else
        {
            a[i]=pow(3,k);
            k++;
        }
    }
    sort(a,a+n);
    long long int s=2*a[n-1]*10;
    cout<<s<<endl;
	return 0;
}

4).
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a=ceil(n/2);
    int b=floor(n/2);
    
    long long int p1=pow(2,a-1);
    p1*=20;
    long long int p2=pow(3,b-1);
    p2*=30;
    if(p1>p2)
        printf("%lld",2*p1);
    else    
        printf("%lld",2*p2);
}

5).
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
using namespace std;
#define PI 3.14159265
#define For for(i=0;i<n;++i)
ll Min(ll a,ll b)
{
    if(a>=b)
        return b;
    else
        return a;
}
ll Max(ll a,ll b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vll a(63);
    a[0]=20;
    a[1]=30;
    ll n,i,j;
    cin>>n;
    for(i=2;i<=62;i++)
    {
        if(i%2==0)
            a[i]=a[i-2]*2;
        else
            a[i]=a[i-2]*3;
    }
    ll m=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(i!=j)
            {
                m=Max(m,abs(a[i]+a[j])+abs(a[i]-a[j]));
            }
        }
    }
    cout<<m;
    return 0;
}


C#:
1).
using System;
 
internal static class Program
{
    private static void Main()
    {
        Console.WriteLine(12353467925678940);
    }
}

2).
using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Threading.Tasks;
 
namespace HeArray
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            long max = 0;
            if (n > 3)
            {
                max = 30 * Convert.ToInt64(Math.Pow(3, (int)n / 2 - 1));
 
            }
            else
            {
                max = n == 3 ? 40 : 30; 
            }
            Console.WriteLine(2 * max);
        }
    }
}

Ruby:
1).
t=[20,30]
999.times{
    t<<t[-2]*2<<t[-2]*3
}
def f(t)
    m=0
    i=0
    while i<t.size
        j=i+1
        while j<t.size
            s=t[i]+t[j]
            s+=t[i]<t[j]?t[j]-t[i]:t[i]-t[j]
            m=s if s>m
            j+=1
        end
        i+=1
    end
    return m
end
p f(t[0,gets.to_i])

2).
n=gets.chomp.to_i
exp3 = n/2
exp2 = (n%2==0 ? n/2 : ( n / 2)+1)
max2=2 ** exp2
max3 = 3 ** exp3
puts 2*max3*10


Java:
1).
import java.util.Scanner;
 
public class AnshulUsamaAndPunishment {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long arr[] = new long[63];
        long odd = 10,even = 10;
        for (int i = 1; i < 63 ; i++) {
            if (i%2==0){
                even *=3;
                arr[i] = even;
            }else{
                odd *=2;
                arr[i] = odd;
            }
        }
 
        long ans = 0;
        for (int i = 1; i <=n ; i++) {
            for (int j = i+1; j <=n ; j++) {
                long diff = arr[i]+arr[j] + Math.abs(arr[i]-arr[j]);
                ans = diff>ans?diff:ans;
            }
        }
        System.out.println(ans);
    }
}

2).
import java.io.*;
import java.util.*;
 
class Punish{
	public static void main(String args[]) throws IOException
	{
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long arr[]=new long[n];
		arr[0]=20;
		arr[1]=30;
		long max=0;
		for(int i=2;i<n;i++)
		{
			if(i%2==0)
			{
				arr[i]=arr[i-2]*2;
			}
			else
			{
				arr[i]=arr[i-2]*3;
			}
		}
		if(n%2==0)
		{
			max=arr[n-1];
		}
		else{
			max=arr[n-2];
		}
		System.out.println(max*2);
	}
}

3).
import java.util.Scanner;
 
public class PunishmentA {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] arr = new long[n];
		arr[0]=20; 
		arr[1]=30;
		long max=0;
		for(int i=2;i<n;i++){
			if(i%2 == 0){
				arr[i] = arr[i-2]*2;
			}
			else{
				arr[i] = arr[i-2]*3;
			}
		}
		//find largest odd number
		if(n%2 != 0){
			max = arr[n-2];
		}
		else{
			max= arr[n-1];
		}
		System.out.println(max*2);
	}
 
}


Java 8:
1).
import java.io.*;
import java.util.*;
import java.text.*;
 
public class Template {
 
	private static Reader scanner = new Reader();
	private static Print printer = new Print();
 
	public static void main(String args[]) throws Exception {
		// Not Working
		init();
		process();
		printer.close();
	}
 
    private static int max = (int) (10000 + 1);
    private static int mod = (int) (1e9 + 7);
    // private static int[] v = new int[max];
    
	private static void init() throws IOException {
// 	    List<Integer> primes = new ArrayList<Integer>();
// 	    boolean[] p = new boolean[max];
// 		p[0] = true;
// 		p[1] = true;
// 		for (int i = 2; i < max; i++) {
// 			if (p[i])
// 				continue;
// 			primes.add(i);
// 			for (int j = i + i; j < max; j += i) {
// 				p[j] = true;
// 			}
// 		}
// 		for (int i = 0; i < primes.size(); i++) {
// 		    int pi = primes.get(i);
// 		    int sum = pi;
// 		    for (int j = i + 1; j < primes.size(); j++) {
// 		        int pj = primes.get(j);
// 		        sum += pj;
// 		        if (primes.contains(sum)) {
// 		            v[pj] = 1;
// 		          //  printer.println(i + " " + j + " " + sum);
// 		        }
// 		    }
// 		}
// 		for (int i = 1; i < max; i++) {
// 		    v[i] = v[i] + v[i - 1];
// 		}
	}
	
	public static void process() throws IOException {
		int t = scanner.nextInt();
		long n1 = 20;
		long n2 = 30;
		List<Long> dist = new ArrayList<Long>();
		while (t > 0) {
		    dist.add(n1);
		    t--;
		    n1 *= 2;
		    if (t <= 0)
		    break;
		    dist.add(n2);
		    n2 *= 3;
		    t--;
		}
		Collections.sort(dist);
		n1 = dist.get(dist.size() - 1);
		n2 = dist.get(dist.size() - 2);
		long res = n1 + n2 + Math.abs(n1 - n2);
// 		for (int i1 = 0; i1 < t; i1++) {
// 			int n1 = scanner.nextInt();
// // 			for (int i = 0; i <= n1; i++) {
// // 				printer.print(v[i] + " ");
// // 			}
// 			printer.println(v[n1]);
// 		}
		printer.println(res);
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
}

2).
import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
        Scanner obj=new Scanner(System.in);
        long[] A=new long[62];
        A[0]=20;
        A[1]=30;
        for(int i=2;i<62;i++)
        {A[i]=(i%2==0)?2*A[i-2]:3*A[i-2];}
        int X=obj.nextInt()-1;
        if(X%2==0)
        {X-=1;}
        System.out.println(2*A[X]);
 
    }
}

3).
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
//import for Scanner and other utility classes
import java.util.*;
 
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static void main(String args[] ) throws Exception {
    
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine()); 
		
		long[] arr = {20,30,40};
		if(tc <= 3){
			System.out.println(arr[tc-1]*2);
			return;
		}
		
		if(tc%2==0){
			int n = tc/2 -1;
			System.out.println((long) (30*Math.pow(3, n)*2));
		}else{
			tc = tc-1;
			int n = tc/2 -1;
			System.out.println((long) (30*Math.pow(3, n)*2));
		}
		
		br.close();
	
    }
}

4).
import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
        Scanner obj=new Scanner(System.in);
        long[] A=new long[62];
        A[0]=20;
        A[1]=30;
        for(int i=2;i<62;i++)
        {A[i]=(i%2==0)?2*A[i-2]:3*A[i-2];}
        int X=obj.nextInt()-1;
        if(X%2==0)
        {X-=1;}
        System.out.println(2*A[X]);
 
    }
}


JavaScript(Node.js):
process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
 
process.stdin.on("data", function (input) {
    stdin_input += input;                               // Reading input from STDIN
});
 
process.stdin.on("end", function () {
   main(stdin_input);
});
 
function main(input) {
  let n = +input;
  let arr = [];
  let e = 2;
  let o = 3;
  let k = 1,
    j = 1;
  let max = -Infinity;
  for (let i = 0; i < n; i++) {
    if (i % 2 === 0) {
      arr[i] = Math.pow(e, k) * 10;
      k++;
    } else {
      arr[i] = Math.pow(o, j) * 10;
      j++;
    }
  }
  for (i = 0; i < arr.length - 1; i++) {
    let temp = Math.abs(arr[i] + arr[i + 1]) + Math.abs(arr[i] - arr[i + 1]);
    if (max < temp) {
      max = temp;
    }
  }
  console.log(max);
}

JavaScript(Rhino):
importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new Scanner(System['in']);		
 
var k = sc.nextInt();
var a=Math.pow(3,parseInt((k-2)/2));
var b=Math.pow(2,parseInt((k-1)/2));
if(20*(b)<30*(a))
System.out.println((60*a).toString());
else
System.out.println((40*b).toString());


Python:
1).
n=int(input())
l=[]
a=20
b=30
for i in range(1,n+1):
    if(i%2==1):
        l.append((a))
        a*=2
    else:
        l.append((b))
        b*=3
ai1=max(l)
l.remove(ai1)
aj1=max(l)
l.remove(aj1)
 
print(ai1+aj1+abs(ai1-aj1))


2).
a=2;b=3;seq=[]
for i in range(1,int(raw_input())+1):
    if i%2==0:
        seq.append(b*10)
        b*=3
    else:
        seq.append(a*10)
        a*=2
m=0
for i in range(len(seq)):
    for j in range(i+1,len(seq)):
        m=max(m,abs(seq[i]+seq[j])+abs(seq[i]-seq[j]))
print m

3).
n=int(input())
l=[]
a=20
b=30
for i in range(1,n+1):
    if(i%2==1):
        l.append((a))
        a*=2
    else:
        l.append((b))
        b*=3
ai1=max(l)
l.remove(ai1)
aj1=max(l)
l.remove(aj1)
 
print(ai1+aj1+abs(ai1-aj1))


Python 3:


*/

