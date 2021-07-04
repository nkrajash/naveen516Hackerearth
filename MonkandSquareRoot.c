/*All Tracks --> Math --> Number Theory --> Problem -->
Monk and Square Root
Tag(s): Easy, Mathematics, Modular arithmetic, approved

Given two integers N and M, help Monk find an integer X, such that X^2 % M = N  and 0<=X. 
If there are multiple values of X print smallest one. If there is no possible value of X print 1.

Note: Make sure you handle integer overflow.

Input:
First line consists of a single integer T denoting the number of test cases.
Each test case consists of a single line containing two space separated integers denoting N and M.

Output:
For each test case print the required answer.

Constraints:
1<=T<=100
0<=N<M<=10^6

SAMPLE INPUT 
2
4 5
0 4
SAMPLE OUTPUT 
2
0
Explanation
2 is the smallest positive integer such that (2x2)%5=4

//My C Solution:
#include <stdio.h>
typedef long long ll;

int main()
{
    int test;
    ll n,i,m,ans;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%lld%lld",&n,&m);
        ans=-1;
        for(i = 0;i<m;i++)
        {
            if((i*i)%m == n)
            {
                ans = i;
                break;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

*/

/*Editorial:
Author: Vaibhav_Jaimini
Tester: r3gz3n
Editorialist: r3gz3n

Brief Description: Given N and M, find the smallest number X such that X^2 % M = N.

Prerequisite: None

Difficulty: Easy

Detailed Explanation:
Since 1<=M<=10^6, we can simply iterate X from 0 to M-1 and check if  X^2 % M = N or not.

Why till M-1??

Let  Y=q*M+X  where 0<=X<=M and 1<=q. q=Y/M and  X=Y%M;
So M-1 < Y
Y^2 % M =((Y % M) * (Y % M)) % M = ( X * X ) % M = X^2 % M
But 0<=X<=M.

Note: Make sure to use long integer as X^2 can be larger than integer's maximum value.

Few optimizations are:

instead of 0 we can iterate from sqrt(N) to M-1. Think about it.
instead of M-1 we can iterate till M/2 as the value of X^2 will start repeating after M/2.

Time Complexity: O(M)
Space Complexity: O(1)

Author Solution by Vaibhav Jaimini
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t; 
    cin>>t;
    while(t--){
        ll n, m;cin>>n>>m;
        ll ans = -1;
        for(ll i=0; i<m; i++)
        if((i*i)%m == n){
            ans = i;break;
        }
        cout<<ans<<endl;
    }
    
}

Tester Solution by Akash Sharma

// Author: r3gz3n
// Description: 
// Difficulty: 

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
const int MOD = 1e9 + 7;
const int INF = 1e9;
int main(int argc, char* argv[])
{
	if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
	if(argc == 3) freopen(argv[2], "w", stdout);
	ios::sync_with_stdio(false);
	int t, ans, n, m;
	char c;
	cin >> t;
	assert(1 <= t and t <= 100);
	while(t--)
	{
		cin >> n >> m;
		assert(0 <= n and n < m);
		assert(1 <= m and m <= 1000000);
		ans = -1;
		REP(i, 0LL, m, 1)
		{
			if((i*i) % m == n)
			{
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
	assert(!(scanf("%c", &c) == 1));
	return 0;
}

*/


/*Best Submissions:
C:
#include <stdio.h>
 
int main()
{
    int t, i, flag;
    long long int n, m;
    
    scanf("%d", &t);
    
    while(t--)
    {
        flag = 0;
        scanf("%lli %lli", &n, &m);
        
        if(n >= m)
        {
        printf("-1");
        continue;
        }
        
        for(i=0; i<=m/2 ; i++)
        {
            long long int root = sqrt(i*m + n);
            if(root * root == i*m + n)
            {
                printf("%lli\n", root);
                flag = 1;
                break;
            }
        }
        
        if(flag != 1)
        printf("-1\n");
    }
    
    return 0;
}

C++:
#include <iostream>
using namespace std;
 
int main()
{
    int m,x,n,t;
    cin>>t;
    while(t--)
    {
        int lim;
         cin>>n>>m;
         int ans=-1;
       long long temp=0;
        
        for(int i=0;i<m;i++)
        {
           if(temp==n)
           {
               ans=i;
               break;
           }
           temp+=2*(i+1)-1;
           while(temp>=m)temp-=m;
        }
        
       cout<<ans<<"\n"; 
 
    }
    
  
    
    return 0;
}


C++14:
#include<bits/stdc++.h>
 
#define ll long long
using namespace std;
int main(){
ll t,n,m,ans;
cin>>t;
while(t--){
cin>>n>>m;
ans=-1;
if(n>=m){
    cout<<ans<<"\n";continue;
}
int flag=0;
for(int i=0; i<=m/2 ; i++)
        {
            long long int root = sqrt(i*m + n);
            if(root * root == i*m + n)
            {
                printf("%lli\n", root);
                flag = 1;
                break;
            }
        }
        
        if(flag != 1)
        printf("-1\n");
 
}
return 0;
}


C#:
// Write your code here
using System;
class Program
    {
        public static void Main(string[] args)
        {
            long t, n, m, x, stp, endp;
            t = Convert.ToInt64(Console.ReadLine());
            while (t > 0)
            {
                string numArr = Console.ReadLine();
                string[] str = numArr.Split();
                n = Convert.ToInt64(str[0]);
                m = Convert.ToInt64(str[1]);
                stp = Convert.ToInt64(Math.Sqrt(n));
                endp = Convert.ToInt64(m / 2);
                for(x=stp;x<=endp;x++)
                {
                    if((x*x)%m==n)
                    {
                        break;
                    }
                }
                if(x>endp)
                {
                    Console.WriteLine("-1");
                }
                else
                {
                    Console.WriteLine($"{x}");
                }
                t--;
            }
        }
    }


Java:
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
 
class MonkAndSquareRoot {
	public static void solve(int n, int m)
	{
		int m1 = m/2+1;
            long x = -1;
            for (long i = (long)Math.sqrt(n); i < m1; i++) {
                if((i*i)%m==n)
                {
                    x = i;break;
                }
            }
            System.out.println(x);
        }
    public static void main(String args[] ) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int TC = Integer.parseInt(line);
        while(TC-->0)
        {
            int n,m;
            String b1[] = br.readLine().split(" ");
            n = Integer.parseInt(b1[0]);
            m = Integer.parseInt(b1[1]);
            //int i = -1;
            //for (; i < m; i++) {
                //if((i*i)%m == n)
              //     break;
            //}
            solve(n,m);
            //System.out.println(i);
        }
        
 
       
    }
}


Java 8:
//Author:-Harsh Chaudhari
//College:-DA-IICT
import java.util.*;
import java.io.*;
 
public class CM1_5_12_16 {
 
	public static void main(String[] args) {
		InputReader s = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		//My code starts here.
		int t = s.nextInt();
		while(t-->0){
			int n = s.nextInt(),m = s.nextInt();
			int ans = -1;
			if(n==0){
				out.println(0);
				continue;
			}
			for(int i=1;i<=m/2;i++){
				if((int)((i*1L*i)%m)==n){
					ans = i;
					break;
				}
			}
			out.println(ans);
		}
		//My code ends here.
		out.close();
	}

	static long PowerMod(long a, long b, long m) {
		long tempo;
		if (b == 0)
			tempo = 1;
		else if (b == 1)
			tempo = a;
		else {
			long temp = PowerMod(a, b / 2, m);
			if (b % 2 == 0)
				tempo = (temp * temp) % m;
			else
				tempo = ((temp * temp) % m) * a % m;
		}
		return tempo;
	}
 
	static class Node implements Comparable<Node> {
		int num, freq, idx;
 
		public Node(int u, int v, int idx) {
			this.num = u;
			this.freq = v;
			this.idx = idx;
		}
 
		public int compareTo(Node n) {
			if (this.freq == n.freq)
				return Integer.compare(this.num, n.num);
			return Integer.compare(-this.freq, -n.freq);
		}
	}
 
	static class InputReader {
 
		private InputStream stream;
		private byte[] buf = new byte[8192];
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
			while (isSpaceChar(c))
				c = snext();
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
			while (isSpaceChar(c))
				c = snext();
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
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}
 
		public String readString() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}
 
		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
 
		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}


JavaScript(Node.js):
function main(input) {
	var data = input.split('\n');
	var T = Number(data.shift());
	for(var t=0; t<T; t++) {
		var D = data.shift();
		D = D.split(' ').map(Number);
		var N = D[0];
		var M = D[1];
		var bool = true;
		for(var i=0; i<M; i++) {
			if(isPerfect(N+M*i)) {
				bool = false;
				console.log(Math.pow(N+M*i, 0.5));
				break;
			}
		}
		if(bool) {
			console.log(-1);
		}
	}
}
 
var isPerfect = function(num) {
	return Number.isInteger(Math.pow(num, 0.5));
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


Pascal:
Program HiHere;
VAR t,i,j,n,m,k:int64; b:boolean;
Begin
Readln(t);
for i:=1 to t do
Begin
Readln(n,m);
k:=0;
b:=false;
 
for j:=1 to m do
Begin
if (j*j mod m = n) then b:=true;
end;
 
 
if (b) then
Begin
 
while (frac(sqrt(k*m + n)) <> 0) and (b) do
Begin
k:=k + 1;
end;
Writeln(sqrt(k*m + n) : 0 : 0);
 
end else Writeln('-1');
 
end;
Readln;
END.


PHP:
<?php

// Sample code to perform I/O:
//fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
//echo "Hi, ".$name.".\n";                // Writing output to STDOUT
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

// Write your code here
fscanf(STDIN, "%d\n", $t);
while($t-- > 0){
     $input = fgets(STDIN);
    $nm = explode(" ",$input);
    $n = (int) $nm[0];
    $m = (int) $nm[1];
    //echo $n." vs ".$m."\n";
    
    $x = -1;
    if($n < $m){
        for($i =0; $i <= $m/2; $i++ ){
            if(($i*$i)%$m == $n){
                $x = $i;
                break;
            }
        }
    }
    echo $x."\n";

}
?>


Python:
for _ in xrange(input()):
    n, m = raw_input().split()
    n = int(n)
    m = int(m)
    res = -1
    if n == 0 or n == 1:
        print n
        continue
    
    for i in xrange(int(n**0.5), m/2 + 1):
        if i*i % m == n:
            res = i
            break
    
    print res


Python 3:
import numpy as np
 
def func():
    N = int(input())
    inputs = [None]*N
    for k in range(N):
        inputs[k] = [int(i) for i in input().split()]
        n, m = inputs[k]
        # now do the work, one by one
        # first compute the whole range
        x_range = np.arange(m)
        modulus = (x_range*x_range % m)
        where = np.where(modulus == n)[0]
        if len(where) ==0:
            print(-1)
        else:
            print(where[0])
 
func()


Ruby:
t =gets.to_i
 
t.times do
    n,m = gets.split(' ').map(&:to_i)
    ab= n**0.5
    ab=ab.floor
    bc=(m/2)+1
    bc=bc.floor
    ans = -1
    
    for i in ab..bc
        if (i*i) % m == n
            ans = i
            break
        end
    end
    puts ans
end    


Scala 2.11.8:
import java.io.{BufferedReader, InputStreamReader, LineNumberReader, Reader}
import java.util.StringTokenizer

  // Created by home on 12/21/2016.

class CustomScanner(reader: LineNumberReader) extends Iterator[String] with AutoCloseable {

  // First setting up the readers that can be passed here

  def this(reader: BufferedReader) = this(new LineNumberReader(reader));
 
  def this(reader: Reader) = this(new BufferedReader(reader));
 
  def this() = this(new BufferedReader(new InputStreamReader(System.in)))
 
 
  //Setting up the tokenizer elements
  private[this] val tokenizers = Iterator.continually(reader.readLine()).takeWhile(_ != null).map(new StringTokenizer(_)).filter(_.hasMoreTokens());
  private[this] var current: Option[StringTokenizer] = None;
 
  private[this] def tokenizer(): Option[StringTokenizer] = current.find(_.hasMoreElements) orElse {
    current = if (tokenizers.hasNext) Some(tokenizers.next()) else None
    current
  }
   // Setting up the base functionality

  def nextLine(): String = {
    current = None
    reader.readLine()
  }
 
  def lineNumber(): Int = reader.getLineNumber()
 
  def line(): String = tokenizer().get.nextToken("\n\r");
 
  def nextString(): String = next()
 
  def nextChar(): Char = next().ensuring(_.length == 1).head
 
  def nextBoolean(): Boolean = next().toBoolean
 
  def nextByte(radix: Int = 10): Byte = java.lang.Byte.parseByte(next(), radix)
 
  def nextShort(radix: Int = 10): Short = java.lang.Short.parseShort(next(), radix)
 
  def nextInt(radix: Int = 10): Int = java.lang.Integer.parseInt(next(), radix)
 
  def nextLong(radix: Int = 10): Long = java.lang.Long.parseLong(next(), radix)
 
  def nextBigInt(radix: Int = 10): BigInt = BigInt(next(), radix)
 
  def nextFloat(): Float = next().toFloat
 
  def nextDouble(): Double = next().toDouble
 
  def nextBigDecimal(): BigDecimal = BigDecimal(next())
 
  override def hasNext: Boolean = tokenizer().nonEmpty
 
  override def next(): String = tokenizer().get.nextToken()
 
  override def close() = reader.close()
}
 
object MonkandSquareRoot {
  def main(args: Array[String]): Unit = {
    val customScanner = new CustomScanner()
    val t = customScanner.nextInt()
    val output = new StringBuilder
    for (testCase <- 1 to t) {
      var n: Long = customScanner.nextLong()
      var m: Long = customScanner.nextLong()
      n = n % m
      output.append(findReverseQuadraticResidue(n, m) + "\n")
    }
    println(output)
    customScanner.close()
  }
 
  def findReverseQuadraticResidue(n: Long, m: Long): Long = {
    if (n > m * m / 2) -1
    else if (checkPerfectSquare(n)) math.sqrt(n).toLong
    else findReverseQuadraticResidue(n + m, m)
  }
 
  def checkPerfectSquare(n: Long): Boolean = {
    if (math.pow(math.sqrt(n).toLong, 2).toLong == n) true else false
  }
}



*/


/*I/O:
In #1:
10
0 1
427637 851957
18665 412039
254493 522517
115128 142169
103382 198323
160443 195479
209 1000000
369 1000000
481 1000000
Out #1:
0
166891
183702
-1
68728
-1
-1
117047
111463
102191

In #2:
100
1 10010
0 1020
135048 138163
73794 300809
205645 786901
607992 728813
455248 584719
59146 602717
14699 20047
266934 462571
240870 829093
780414 793043
557255 810457
104176 362459
125822 579563
48952 486907
135501 190763
279026 426553
25765 57397
147548 209701
9371 754489
737 23561
234392 775097
17026 479137
143077 668203
633605 635737
66261 441737
25610 354869
77914 481489
35084 542093
6520 63659
94513 615557
201254 571759
430027 966307
487899 567263
451408 498599
111591 168023
466929 543703
24021 193741
63581 246371
260309 896369
7377 73009
32208 37951
83314 289297
50656 65437
53681 656519
227123 784351
79176 90977
21587 210857
291 54331
90754 92003
6508 15671
319130 981017
457367 747991
2652 468647
173897 747407
306361 787069
215199 395509
81730 133873
135013 384343
224575 613141
10172 40127
146045 208309
283978 635639
129116 884813
81201 112643
261054 972199
195006 769553
131628 369097
236031 607727
191049 386041
181127 944161
45565 60821
51278 56807
81611 101333
16165 103801
55774 375757
30035 833747
42984 143257
536527 941617
611078 872621
71418 696497
6088 49957
363117 431083
28212 867689
111242 161561
241069 284489
175729 307147
354507 484153
61756 423763
386109 519307
23530 33623
1041 1000000
1049 1000000
1129 1000000
1201 1000000
1241 1000000
1321 1000000
281079 557059
4681 392263
Out #2:
1
0
13647
112746
212521
4663
-1
144188
-1
-1
168582
-1
-1
13994
-1
55368
-1
-1
4959
65650
-1
435
-1
-1
9292
-1
-1
-1
-1
48219
-1
-1
158779
-1
-1
141857
-1
-1
45452
91504
-1
28971
16286
10081
27079
-1
-1
27288
59387
-1
-1
2137
-1
95741
190341
332924
114906
194623
4608
9531
-1
-1
36957
79896
-1
-1
-1
-1
163656
159563
-1
-1
13216
25597
-1
16289
115319
-1
-1
-1
92813
-1
23408
201118
65788
-1
26020
-1
24598
-1
-1
6464
130679
102757
152627
179399
172421
169139
-1
191758

In #3:
100
291608 697877
267685 585317
270219 670297
2649 1000000
2681 1000000
2689 1000000
2721 1000000
2921 1000000
217923 860581
511664 920323
744533 833839
48944 123113
8565 387967
281931 387791
725601 764789
471 5399
185763 716033
231320 433151
0 102445
0 1
141156 377297
223816 228427
30089 292241
155324 346039
12463 18097
149423 223247
403123 443689
75462 310127
79 479
200169 950281
10866 307409
511359 922739
60612 375857
73544 124951
147009 783077
89195 759491
309860 416501
147143 251291
198074 737059
97474 772921
474198 771587
76808 447877
22297 71293
179964 977203
162922 198257
598678 675341
233912 515777
41900 90107
70052 642947
764204 774127
138503 217691
437706 465833
40039 393383
93471 258331
177670 230611
495471 769207
182354 564353
280211 954263
95453 710683
288721 569021
377087 488797
144241 316177
141004 537401
6561 8861
482590 514123
216967 490313
63488 167047
88648 108827
398232 408869
381468 784009
41843 122029
202696 545723
277082 288227
975 211931
254629 261451
444398 818021
434472 759589
104516 674711
174260 253879
157467 191507
10760 136223
67779 234187
13882 196429
126659 972599
544750 615793
16573 162209
707565 816703
126075 145009
21813 95603
37778 172223
730842 887633
802216 856169
169713 845567
216150 454921
575582 913373
534576 777013
11988 72973
49171 231053
19270 246497
591225 790607
Out #3:
-1
10047
-1
129093
155541
102367
104561
147411
277817
-1
173961
6445
-1
169006
-1
-1
-1
-1
0
0
104583
-1
88697
137861
3154
14751
217127
141768
-1
-1
5816
45041
81585
-1
-1
253233
61231
-1
355824
141845
158294
-1
17434
279179
31735
300936
-1
-1
15195
366566
39874
-1
25323
75275
97835
-1
-1
-1
350733
-1
55834
142029
253993
81
-1
-1
-1
-1
-1
-1
-1
250031
135698
-1
-1
-1
107725
3595
111921
-1
34321
-1
50227
471709
130943
-1
138342
68228
-1
18864
124105
7043
-1
166173
-1
-1
17390
-1
76758
-1

In #4:
100
169165 731921
170714 797473
5630 14563
36321 1000000
36401 1000000
36409 1000000
36561 1000000
36649 1000000
36721 1000000
439185 691037
345564 417293
199871 756571
57568 218509
338233 718427
1344 58997
537307 603851
15512 17581
504975 541537
0 101000
1 10000
50191 647951
479380 574201
398235 574817
982474 983789
357470 421417
28228 741413
469423 551849
37180 248201
40471 209147
94843 471277
104645 462641
48790 771583
16434 30509
240264 357229
830048 944711
438801 635639
270836 433141
404428 658639
92701 249703
68806 137623
47650 159629
66732 82903
4882 82591
97866 385267
114127 193441
171332 271489
81418 488717
736605 869321
47782 75533
76542 80021
39169 118801
451040 458317
683891 829987
18762 287093
120195 452009
399521 473173
12740 38113
68134 228299
596518 796657
88858 118493
74693 209857
328232 363589
123136 155707
1749 117191
141737 163147
11414 121039
598686 622187
54717 559513
400834 418883
31083 405437
18185 23473
256920 393331
126402 336799
108023 875689
2655 2671
585511 661993
66579 265333
437355 811253
256 587
542932 552353
629304 841663
39977 316697
150578 814829
864711 989341
602847 639337
682822 845567
6476 7823
408555 577639
559299 585989
145304 180097
66059 487891
463489 478441
497614 593261
252977 933497
363384 941207
141307 610447
633171 693061
27250 269189
436789 722377
418741 436649
Out #4:
-1
-1
2952
107889
101799
185653
184919
101907
198439
-1
-1
93997
-1
355218
-1
44828
-1
184195
0
1
201615
144446
92455
266063
-1
189424
-1
-1
24671
-1
-1
339763
1662
-1
-1
12369
-1
44810
-1
-1
25829
-1
-1
149012
23581
67643
-1
419112
21765
1094
48298
174518
378500
95985
158379
44243
-1
96548
-1
38975
79383
-1
-1
-1
-1
8891
118397
-1
-1
-1
-1
-1
139208
-1
-1
217181
73444
343899
16
-1
-1
-1
-1
-1
46196
380180
2848
-1
114144
-1
-1
68029
-1
-1
294045
89173
194510
13188
204189
107350

In #5:
100
84457 260921
97958 746023
27412 703229
68340 759131
998929 1000000
998961 1000000
998969 1000000
999089 1000000
999289 1000000
54005 102769
120163 319211
204602 209201
451544 568831
39849 384623
658656 680881
0 1
1 10010
0 1010
626150 943031
117514 372941
22876 205603
144321 174169
52894 206407
236726 903641
43264 867131
400345 995381
39742 123581
600588 957949
22362 732731
637162 646397
694768 807731
59941 240899
150873 446713
5648 5743
464903 677543
32622 96703
423120 661777
31842 173819
458583 581143
843210 984017
35292 780421
485735 507491
56139 850979
143569 302891
352630 492721
514623 693529
178838 489133
120142 888959
460734 464699
21301 52009
93214 120877
649399 946031
61280 477047
515463 544627
17170 70039
233200 390893
34711 330247
539832 627811
39923 248861
373671 454759
944201 988693
292414 965777
551156 818011
187700 295951
183882 389797
79705 311371
267902 373291
93921 189691
199117 238801
5065 836683
136429 145601
14867 50069
190287 200731
7903 373489
255055 682277
57642 111253
391659 904867
45091 835739
435501 777433
242900 884003
72711 188701
551894 577427
75398 149909
100833 325189
250598 405143
245773 418909
235181 269539
688862 961657
187966 203579
221780 664633
64103 898253
114242 245897
25390 729041
250198 354329
121521 941947
229219 551809
740130 984397
367388 583519
24616 814631
214769 224267
Out #5:
-1
-1
-1
-1
170423
129031
192437
196967
198517
-1
-1
24042
255356
-1
-1
0
1
0
-1
104703
-1
-1
-1
199407
208
-1
-1
204192
-1
-1
-1
-1
-1
-1
-1
35387
110314
59485
278481
-1
-1
-1
128696
-1
-1
313767
78550
-1
-1
-1
-1
-1
-1
46715
-1
150693
-1
-1
-1
25437
239202
-1
11028
135236
2755
15223
-1
3033
-1
112207
-1
10546
4006
106559
74676
12860
404585
247836
189479
39615
-1
180634
-1
19155
15780
193616
-1
65098
-1
-1
-1
90878
-1
27554
70370
-1
-1
-1
-1
-1

In #6:
100
219932 230137
71224 192463
52555 60331
62752 624199
265623 274973
992201 1000000
992241 1000000
992361 1000000
992401 1000000
992409 1000000
197871 544807
240304 789731
70681 139969
396466 473719
421781 705161
190082 326251
649105 658117
18923 36013
0 10001
1 204506
803001 936769
127136 399571
688918 740687
85125 108631
66952 853793
293702 979117
39030 55103
39538 561359
447669 980149
189460 329627
335943 438281
136969 137827
431677 940691
197578 710909
358160 527993
172700 727261
409926 829511
266943 299471
504328 817237
60889 313127
377966 642869
138871 762973
410635 929009
569439 595319
237441 252253
153988 240623
22527 496259
35409 519691
159845 439349
223696 309269
168398 206827
144462 316793
57840 69239
203196 295363
881429 961319
31382 66271
364121 618593
109851 163987
9888 41479
158868 287387
514558 592601
157882 717653
416476 647893
512041 588947
277644 536561
502762 989753
428494 667477
211162 496813
805258 828029
72749 139999
126311 315743
115592 229409
577559 931387
26600 360959
611985 902299
551122 975217
75612 754211
232629 649291
512792 809581
77255 556181
608839 880331
629424 822391
196855 716249
287 1637
8896 26987
33859 178261
6165 212683
768 15083
257299 535529
278978 617273
118194 570221
213750 811469
915788 979519
65076 608759
334810 400391
659494 826849
363078 406631
287697 339257
439164 661889
257435 546367
Out #6:
88173
-1
-1
-1
119556
108899
101671
159731
223799
194597
186983
96187
2133
-1
41383
-1
-1
8608
0
1
-1
177267
-1
-1
-1
363516
5423
-1
-1
111258
-1
-1
95683
-1
-1
-1
251378
107610
-1
-1
262233
355954
193843
276337
107020
105221
-1
38452
-1
48138
-1
-1
31730
142899
-1
-1
16053
5765
-1
-1
-1
101778
123091
286186
217253
107696
-1
-1
400696
-1
-1
5596
-1
123420
144261
43715
204240
47022
-1
-1
-1
386121
-1
207
8369
51693
-1
4712
119786
219878
17793
-1
281195
-1
-1
-1
-1
-1
-1
-1

In #7:
100
2921 105607
64068 190409
403092 471101
485728 629921
525093 572909
116787 210127
604011 727733
36835 47809
15902 47743
356017 851797
0 10012
1 10024
459862 962197
283870 552581
42035 166301
896002 914443
84792 155303
8306 214031
997569 1000000
997609 1000000
997681 1000000
997801 1000000
997841 1000000
997969 1000000
998009 1000000
130931 831851
450086 875491
16309 402517
14187 842417
49849 54973
176 331
9621 10771
858719 952199
344662 667333
234458 979543
116931 478967
153978 183343
21033 37463
69545 387403
532115 707981
122870 318233
798058 933061
63418 63689
464412 901171
120300 181213
262780 605191
186599 593839
21797 28807
526713 711001
187646 300857
348745 351479
170372 749383
31370 77101
824382 940003
680438 712889
17673 562091
7255 53323
45521 117259
569306 703267
686449 713261
536907 654413
528479 587087
599140 633877
45679 674273
11346 20333
248341 729059
139787 307589
450359 630433
94996 787067
483276 571163
45850 76631
532126 592073
306912 329167
587376 769673
279319 424843
127549 640621
311661 500587
152071 222919
125871 735043
11731 34031
272935 416281
375111 829349
569923 951943
26515 33151
359472 912173
77651 95369
184627 445583
303729 626713
11734 116803
395816 725953
93370 576949
327872 523801
38786 479879
148042 964199
214389 369071
727540 858673
157356 606131
322972 608977
7802 22193
23729 143483
Out #7:
-1
37548
-1
7177
-1
-1
171342
23368
-1
-1
0
1
-1
152197
25432
18616
-1
-1
114913
139603
121959
106099
228471
119063
166997
-1
-1
-1
-1
25427
-1
1083
288456
-1
-1
-1
-1
-1
-1
334970
-1
-1
17235
-1
39737
-1
31804
-1
31682
-1
-1
-1
10662
431860
19674
7347
-1
-1
-1
-1
249147
131537
-1
292301
8161
-1
88873
282518
340653
-1
-1
-1
-1
-1
76668
-1
-1
89621
-1
9506
-1
327597
59465
-1
-1
-1
48740
-1
1031
-1
36948
170294
94654
138843
-1
192200
-1
6646
-1
-1

In #8:
100
642246 855031
264531 313307
304446 660167
158108 315851
421102 602137
12391 172421
128354 165397
608820 912089
163017 547501
1 10200
0 100245
175690 300961
342395 408971
779555 837659
352797 520747
728271 842587
495690 509521
18155 260987
216842 737617
7353 70687
42124 85711
190732 241783
26038 56489
85432 113177
38637 77153
780935 858919
194568 434849
69343 929869
518071 849917
346518 435307
184520 532267
291037 442031
3367 140939
771262 963047
82478 198031
251410 948973
138199 142111
39241 1000000
39281 1000000
39289 1000000
39441 1000000
39521 1000000
39569 1000000
39609 1000000
263309 282481
104722 317731
389756 458377
260102 594137
143828 378317
37546 369979
432588 434179
345085 777643
57625 553057
82677 491537
7232 11833
718623 979439
61044 87959
39248 176417
717187 792919
57625 102409
122714 395287
244885 805279
92287 97547
432990 542693
79202 836497
573776 988501
12112 125621
428688 567053
12358 22619
158698 170579
644770 803449
74495 733339
17124 85703
51467 91673
24350 27817
296231 848131
472094 506501
38237 176243
3037 96911
83 4297
357707 361481
47170 84589
72794 395293
396431 913327
85752 429431
121709 131023
59971 99349
15102 19373
56189 665419
666014 772477
35212 174257
800013 825397
180687 296551
14819 187127
565867 615623
159685 208391
229994 668347
410313 549553
63674 666109
46994 193937
Out #8:
172709
-1
188399
26165
-1
35168
-1
161524
46086
1
0
149557
-1
-1
136534
29813
-1
-1
122449
6337
-1
-1
21672
7938
23072
-1
-1
-1
229351
158909
187526
-1
-1
203390
75653
76322
27278
155171
173159
147733
195479
102289
100663
152853
22379
-1
136662
-1
-1
128350
-1
350139
-1
-1
2304
-1
-1
31119
367391
6648
-1
335408
10396
-1
100048
433775
-1
-1
-1
-1
-1
-1
35173
-1
10494
-1
-1
-1
43809
1093
66253
-1
-1
-1
-1
7971
42967
-1
-1
-1
-1
-1
-1
84399
-1
-1
26933
-1
56185
-1

In #9:
100
8921 1000000
8929 1000000
9001 1000000
9009 1000000
9041 1000000
182993 884371
238745 738499
111760 157327
30134 78893
0 1
1 101000
0 100234
40565 122761
323732 630319
55522 243917
147713 316189
20414 318299
657903 840589
167347 441697
711696 716413
124132 618269
362385 888133
84704 856943
4214 56359
80728 416263
117354 242329
162956 338389
74851 712739
10497 433513
30439 46141
77274 127321
28945 506993
19513 104107
500638 799873
288416 340939
715239 825059
1719 1873
34435 47857
329609 432869
419035 454507
255040 457817
260622 803053
427266 794743
337 171583
554813 742393
7026 822901
367972 645187
30442 46457
196629 375967
19832 29411
189247 219881
174112 593869
395383 406811
325241 754417
138924 434117
548487 610391
47739 823969
240375 609361
440200 625517
505994 725381
870867 909401
162867 966961
468962 759547
10862 18587
324328 898483
499754 960793
467695 752891
142543 204107
228726 716633
526677 737593
15882 66721
249664 974957
167860 461411
15012 187217
66008 238627
210540 343393
199887 332623
186895 568097
6735 344251
184402 293207
183237 483281
16732 67927
280092 310969
110661 114311
473312 968431
88248 248893
48670 87943
489918 599153
318931 670489
214564 536743
216839 416833
471861 778091
122108 254161
898350 948533
537360 633187
67889 564089
10090 25913
34752 79987
369703 618311
132582 249881
Out #9:
126661
105423
120499
126503
162071
-1
-1
60861
-1
0
1
0
3779
212346
-1
53698
100148
-1
-1
7849
-1
-1
-1
11008
-1
-1
-1
-1
113910
2379
20256
-1
25093
305953
-1
-1
143
-1
79063
187525
-1
-1
25938
45255
220233
394449
43043
21519
154707
13452
58947
-1
-1
177000
173515
-1
39505
-1
-1
244855
451106
290326
-1
-1
138233
340668
21371
-1
21999
-1
-1
-1
110870
71041
-1
-1
38837
38153
21875
87113
-1
-1
53365
38521
205824
-1
29485
-1
-1
261493
203595
67205
1851
-1
244900
-1
7023
-1
266684
51936

In #10:
100
412444 894391
5418 173141
73281 368171
69881 70753
0 10024
1 30455
131829 703357
528180 884437
123241 917809
260 631
373008 715973
435265 579883
140169 1000000
140241 1000000
140281 1000000
140409 1000000
140441 1000000
55254 774023
982 3389
361726 841933
146887 247279
150385 303491
22498 458333
160 3671
458502 731921
241393 438467
113158 767071
652209 695017
51217 97931
1955 311407
213347 748441
113982 150833
84628 413243
94051 235519
404553 464137
153111 751909
51722 88327
170956 388859
68326 130811
123744 820481
161094 227719
7519 28657
148898 173827
87530 274103
72207 954619
156937 398933
120935 935593
23681 29021
112822 366727
63245 451859
371964 886973
31360 457363
286275 323837
248710 394577
98207 132421
20367 49429
252762 354209
16283 83449
344508 476929
260679 712511
101911 870367
159013 162419
371717 567067
169504 841927
1729 3359
667669 686891
290638 379663
423530 525493
73077 919781
834181 918109
19092 48119
114511 291191
797778 909803
7173 26339
347915 451837
514111 879713
334339 736973
10386 817913
940535 951101
80807 138977
371667 645067
207780 480527
203679 881987
403982 463031
94253 856553
49731 704777
106274 201403
220141 347969
12887 98731
269611 363563
276867 819449
600656 773063
29444 159721
321753 742549
114107 759467
409248 731593
130023 413981
39785 144611
31062 123677
514897 785143
Out #10:
-1
5929
93451
31447
0
1
232404
-1
-1
-1
-1
224053
109987
195671
132341
169653
170021
59443
146
68857
40434
-1
-1
235
-1
73800
-1
-1
-1
-1
-1
-1
-1
-1
213335
274436
19465
166464
-1
206118
99429
11809
-1
-1
63003
-1
10288
3716
-1
104374
-1
170557
-1
-1
48454
-1
16904
-1
49789
118810
338631
12415
-1
-1
-1
-1
-1
17620
-1
174104
-1
-1
-1
7971
-1
140935
69028
227889
474465
40473
203037
78633
215952
-1
-1
-1
32627
-1
4434
-1
-1
-1
51747
6917
-1
-1
-1
-1
29344
27592

*/
