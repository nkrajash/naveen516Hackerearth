/*All Tracks --> Basic Programming --> Operators --> Basics of Operators --> Problem --> Going to office
Tag(s): Basic Programming, Basics of Operators, Operators

Alice has the following two types of taxis:
Online taxi: It can be booked by using an online application from phones 
Classic taxi: It can be booked anywhere on the road
The online taxis cost Oc for the first Of km and Od for every km afterward. The classic taxis travel at a speed of Cs km per minute. 
The cost of classic taxis are Cb, Cm, and Cd that represents the base fare, cost for every minute that is spent in the taxi, and cost for each kilometer that you ride.

You are going to the office from your home. Your task is to minimize the cost that you are required to pay. The distance from your home to the office is D. 
You are required to select whether you want to use online or classic taxis to go to your office. If both the taxis cost the same, then you must use an online taxi.

Input format:
First line: Single integer D that denotes the distance from your house to the office
Next line: Three integers  Oc, Of , and  Od
Next line: Four integers  Cs, Cb, Cm, and Cd

Output format:
If you select an online taxi to travel, then print a string 'Online Taxi'. Otherwise, select 'Classic Taxi'. You can print this string in a new, single line.

Constraints:
1<= D,Oc, Of ,Od,Cs, Cb, Cm, and Cd   <=10^9

SAMPLE INPUT 
13
6 7 4
4 2 1 2
SAMPLE OUTPUT 
Online Taxi

Explanation:
If Felix choose to use Online Taxi, it will cost Felix a total of 6+(13-7)*4 = 30
While the classic taxi will cost Felix a total of 2+|13/4|*1 +13*2 =31
Therefore Felix will choose Online Taxi over Classic Taxi

//C Code
#include <stdio.h>
typedef long int li;

int main()
{
    li d,oc,of,od,cs,cb,cm,cd,online,classic;
    scanf("%ld",&d);
    scanf("%ld%ld%ld",&oc,&of,&od);
    scanf("%ld%ld%ld%ld",&cs,&cb,&cm,&cd);
    online=oc+(d-of)*od;
    classic=cb+((d/cs)*cm)+(d*cd);
    if(online > classic)
    {
        printf("Classic Taxi");
    }
    else
    {
        printf("Online Taxi");
    }
    return 0;
}

*/

/*Editorial:
Calculate the cost using Online taxi as following :
if D is smaller or equal than Of then OnlineCost = Oc,
otherwise OnlineCost = Oc + (Od * (D - Of))
For classic taxi the cost will be calculated as following :
Calculate time needed to arrive as Time = floor(D / Cs)
ClassicCost = Cb + Time * Cm + Cd * D

After that we can just compare these two to determine which one Felix should take. In case of tie we choose online taxi.
Updated problem name
Updated problem statement

Alice has the following two types of taxis:
Online taxi: It can be booked by using an online application from phones 
Classic taxi: It can be booked anywhere on the road

The online taxis cost Oc for the first Of km and Od for every km afterward. The classic taxis travel at a speed of Cs km per minute. 
The cost of classic taxis are Cb, Cm, and Cd that represents the base fare, cost for every minute that is spent in the taxi, and cost for each kilometer that you ride.

You are going to the office from your home. Your task is to minimize the cost that you are required to pay. The distance from your home to the office is D. 
You are required to select whether you want to use online or classic taxis to go to your office. If both the taxis cost the same, then you must use an online taxi.

Input format:
First line: Single integer D that denotes the distance from your house to the office
Next line: Three integers  Oc, Of , and  Od
Next line: Four integers  Cs, Cb, Cm, and Cd

Output format:
If you select an online taxi to travel, then print a string 'Online Taxi'. Otherwise, select 'Classic Taxi'. You can print this string in a new, single line.

Constraints:
1<= D,Oc, Of ,Od,Cs, Cb, Cm, and Cd <=10^9

Author Solution by Sebastian Mualim
#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ll d; cin >> d;
    ll oc, of, od; cin >> oc >> of >> od;
    ll cs, cb, cm, cd; cin >> cs >> cb >> cm >> cd;
    ll online = (d <= of)?oc:oc + (od * (d - of));
    ll timeClassic = d / cs;
    ll classic = cb + timeClassic * cm + cd * d;
    if(online <= classic) cout << "Online Taxi" << endl;
    else cout << "Classic Taxi" << endl;
}
Tester Solution by Amirreza Poorakhavan
// In the name of Allah.
// We're nothing and you're everything.
// Ya Ali!
 
#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
const int maxn = 2e5 + 17;
int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int d;
	cin >> d;
	int oc, of, od;
	cin >> oc >> of >> od;
	int cs, cb, cm, cd;
	cin >> cs >> cb >> cm >> cd;
	ll fc = 0;
	if(d <= of)
		fc = oc;
	else
		fc = oc + (d - of) * od;
	ll sc = 0;
	sc = (ll) (d + cs - 1) / cs * cm + cb + cd * d;
	cerr << fc << ' ' << sc << '\n';
	if(fc <= sc)
		cout << "Online Taxi\n";
	else
		cout << "Classic Taxi\n";
}

*/

/*I/O:
In #1:
8581
838 5920 13352
6058 3019 2151 4140
Out #1:
Online Taxi

In #2:
13350712
812032 11636435 70538409
76770926 61331309 8735000 9057368
Out #2:
Online Taxi

In #3:
636374903
1 616932249 809021696
1 6946106 8702338 8810711
Out #3:
Classic Taxi

In #4:
572566841
1 736987437 631732533
1 7692672 5328439 7865455
Out #4:
Online Taxi

In #5:
15
14 32 65
8 8 5 5
Out #5:
Online Taxi

In #6:
142098087
687355301 987788392 75187408
7769196 16029678 21582154 7516010
Out #6:
Online Taxi

In #7:
1000000000
1000000000 999999995 1000000000
1000000000 1000000000 1 1
Out #7:
Classic Taxi

In #8:
264
29013295 452 415
266 475 635 92
Out #8:
Classic Taxi

In #9:
729676
210617691 481635 927713495
843517 893522 83933 186957
Out #9:
Classic Taxi

In #10:
60378941
939680953 25444245 662777192
86458039 89995573 56551736 60939263
Out #10:
Classic Taxi

*/

/*Best Submissions:
C:
#include<stdio.h>
int main()
{
long int D,Oc,Of,Od,Cs,Cb,Cm,Cd;
float O,C;
scanf("%ld",&D);
scanf("%ld%ld%ld",&Oc,&Of,&Od);
scanf("%ld%ld%ld%ld",&Cs,&Cb,&Cm,&Cd);
O=(Oc+(D-Of)*Od);
C=Cb+((D/Cs)+Cm)+(D*Cd);
if(O<=C)
printf("Online Taxi");
else
printf("Classic Taxi");
return 0;
}


C++:
#include <iostream>
 
using namespace std;
 
int main() {
	long long int d,a,b,c,e,f,g,h,m,n;
	cin >>d>>a>>b>>c>>e>>f>>g>>h;
	m=a+(d-b)*c;
	n=f+(d/e)*g+d*h;
	if (m<=n) {
	    cout << "Online Taxi";
	}
	else
	    cout << "Classic Taxi";
	
}


C++14:
// Write your code here
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long d,oc,of,od,cs,cb,cm,cd;
    cin>>d>>oc>>of>>od>>cs>>cb>>cm>>cd;
    long long a=oc+(d-of)*od;
    if(d<=of)
        a=oc;
    long long b=cb + (d/cs)*cm + d*cd;
    if(d<cs)
        b+=cm;
    if(a<=b)
        cout<<"Online Taxi\n";
    else
        cout<<"Classic Taxi\n";
    return 0;
}

C#:
using System;
class Test{
    public static void Main(){
        const string online = "Online Taxi", classic = "Classic Taxi";
        
        ulong distance = ulong.Parse(Console.ReadLine());
        
        string[] o = Console.ReadLine().Split(' ');
        ulong oStartCost = ulong.Parse(o[0]);
        ulong oFirst = ulong.Parse(o[1]);
        ulong oAfter = ulong.Parse(o[2]);
        
        string[] c = Console.ReadLine().Split(' ');
        ulong cSpeed = ulong.Parse(c[0]);
        ulong cBaseFare = ulong.Parse(c[1]);
        ulong cMinute = ulong.Parse(c[2]);
        ulong cKilometer = ulong.Parse(c[3]);
        
        ulong oOver = 0;
        if (oFirst < distance)
            oOver = distance - oFirst;
            
        ulong onlineAmount = oStartCost + (oOver * oAfter);
        
        ulong classicTime = distance / cSpeed;
        ulong classicAmount = cBaseFare + (classicTime * cMinute) + (distance * cKilometer);
        
        if(classicAmount < onlineAmount)
            Console.WriteLine(classic);
        else
            Console.WriteLine(online);
        
    }
}

Java:
import java.io.*;
import java.util.*;
 
 
public class GoingToOffice {
	static PrintWriter pw;
	static BufferedReader bf;
	static StringTokenizer st;
	
	static final String ANSWER_1 = "Online Taxi";
	static final String ANSWER_2 = "Classic Taxi";
	
	public static void main(String[] args) {
		try{
			pw = new PrintWriter(System.out);
			bf = new BufferedReader(new InputStreamReader(System.in));
			long D = nextInt();
			long Oc = nextInt();
			long Of = nextInt();
			long Od = nextInt();
			long Cs = nextInt();
			long Cb = nextInt();
			long Cm = nextInt();
			long Cd = nextInt();
			String answer = process(D, Oc, Of, Od, Cs, Cb, Cm, Cd);
			pw.println(answer);
			pw.flush();
		}
		catch(Exception e){
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	static String process(long D, long Oc, long Of, long Od, long Cs, long Cb, long Cm, long Cd) {
		long Op = 0, Cp = 0;
		// calculate online price
		if(D <= Of) {
			Op = Oc;
		}
		else {
			Op =  Oc + (D - Of) * Od;
		}
		// calculate classic price
		Cp = Cb  + Cm * D / Cs + Cd * D;
		
		if(Op <= Cp)
			return ANSWER_1;
		else 
			return ANSWER_2;
	}
	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	static String next() throws IOException {
		while(st== null || !st.hasMoreTokens()){
			st = new StringTokenizer(bf.readLine());
		}
		return st.nextToken();
	}
}

Java 8:
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
import java.util.*;
import java.math.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
        // Sample code to perform I/O:
        // Use either of these methods for input
 
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String name = br.readLine();                // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        //Scanner
        //Scanner s = new Scanner(System.in);
        //String name = s.nextLine();                 // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        // Write your code here
        Scanner s=new Scanner(System.in);
        int d=s.nextInt();
        int oc=s.nextInt();
        int of=s.nextInt();
        int od=s.nextInt();
        int cs=s.nextInt();
        int cb=s.nextInt();
        int cm=s.nextInt();
        int cd=s.nextInt();
        findans(d,oc,of,od,cs,cb,cm,cd);
    }
    public static void findans(int d,int oc,int of,int od,int cs,int cb,int cm,int cd){
        //long online=0;
        //long classic=0;
        BigInteger f=new BigInteger("1");
         BigInteger g=new BigInteger("1");
         BigInteger h=new BigInteger("1");
         BigInteger ans=new BigInteger("0");
        int online=(d-of);
        f=f.multiply(BigInteger.valueOf(online));
         f=f.multiply(BigInteger.valueOf(od));
         f=f.add(BigInteger.valueOf(oc));
        int x=d/cs;
         g=g.multiply(BigInteger.valueOf(x));
         g=g.multiply(BigInteger.valueOf(cm));
         h=h.multiply(BigInteger.valueOf(d));
         h=h.multiply(BigInteger.valueOf(cd));
        ans=ans.add(BigInteger.valueOf(cb));
        ans=ans.add(g);
        ans=ans.add(h);
       int compareans=ans.compareTo(f);
       
        if(compareans==0){
            System.out.println("Online Taxi");
        }
        else if(compareans==1){
            System.out.println("Online Taxi");
        }
        else{
            System.out.println("Classic Taxi");
        }
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
    var array = input.split("\n")
    var km = parseInt(array[0]);
    var onlineTexi = array[1].split(" ")
    var Oc = parseInt(onlineTexi[0]);
    var Of = parseInt(onlineTexi[1]);
    var Od = parseInt(onlineTexi[2]);
    var classicTexi = array[2].split(" ")
    var Cs = parseInt(classicTexi[0])
    var Cb = parseInt(classicTexi[1])
    var Cm = parseInt(classicTexi[2])
    var Cd = parseInt(classicTexi[3])
    
    var totalFairOnline = 0
    var totalFaitOffline = 0
    
    totalFairOnline = Oc+(km-Of)*Od
    totalFaitOffline = Cb+Math.floor(km/Cs)*Cm + km*Cd
    
    if(totalFairOnline > totalFaitOffline){
        console.log("Classic Taxi")
    }else if(totalFairOnline < totalFaitOffline){
        console.log("Online Taxi")
    }else{
        console.log("Online Taxi")
    }
}

Perl:
=comment
# Sample code to perform I/O:
 
my $name = <STDIN>;             # Reading input from STDIN
print "Hi, $name.\n";           # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
=cut
 
# Write your code here'
$line=<STDIN>;
chomp $line;
$d=$line;
 
$line=<STDIN>;
chomp $line;
($oc,$of,$od)=split / +/, $line;
 
$line=<STDIN>;
chomp $line;
($cs,$cb,$cm,$cd)=split / +/,$line;
 
$onlinefair=$oc+($d-$of)*$od;
$classicfair=$cb+($d/$cs)*$cm+($d*$cd);
 
if( $classicfair<$onlinefair){
    print "Classic Taxi"
}
else{
    print "Online Taxi"
}

PHP:
<?php
$d = trim(fgets(STDIN));
$a = trim(fgets(STDIN));
$b = trim(fgets(STDIN));
$x = explode(" ", $a);
$y = explode(" ", $b);
$ol = $x[0]+($d-$x[1])*$x[2] ;
$cl = $y[1]+(($d/$y[0])*$y[2])+($d*$y[3]);
if($ol > $cl){
    echo "Classic Taxi";
}else{
    echo "Online Taxi";
}
 
?>

Python:
d = input()
a = map(int, raw_input().split())
 
cost1 = a[0] + max(0, d - a[1])*a[2]
a = map(int, raw_input().split())
 
cost2 = a[2]*int(d//a[0]) + a[1] + d*a[3]
 
if cost1 > cost2:
    print 'Classic Taxi'
else:
    print 'Online Taxi'

Python 3:
'''
# Sample code to perform I/O:
 
name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''
 
# Write your code here
n=int(input())
l=list(map(int,input().split(" ")))
online=l[0]+(n-l[1])*l[2]
d=list(map(int,input().split(" ")))
classic=d[1]+(n/d[0])*d[2]+n*d[3]
if(online<classic):
    print("Online Taxi")
else:
    print("Classic Taxi")

Ruby:
=begin
# Sample code to perform I/O:
 
name = gets.chomp                # Reading input from STDIN
print "Hi, #{name}.\n"           # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
=end
 
# Write your code here
  #!/bin/ruby
require 'json'
require 'stringio'
 
def low_cost(d, oc, of, od, cs, cb, cm, cd)
    offline_cost = cb + (d/cs)*cm + (d*cd)
    online_cost = oc + (d - of)*od
    return (online_cost <= offline_cost) ? "Online Taxi" : "Classic Taxi"
end
d = gets.to_i
o = gets.rstrip.split
oc = o[0].to_i
of = o[1].to_i
od = o[2].to_i
c = gets.rstrip.split
cs = c[0].to_i
cb = c[1].to_i
cm = c[2].to_i
cd = c[3].to_i
lowcost = low_cost(d,oc,of,od,cs,cb,cm,cd)
puts lowcost


*/