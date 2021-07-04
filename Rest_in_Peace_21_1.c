/* All Tracks --> Algorithms -->   Searching  -->  Linear Search  -->   Rest in peace - 21-1!
Tag(s): Ad-Hoc, Basic Programming, Easy

The grandest stage of all, Wrestlemania XXX recently happened. And with it, happened one of the biggest heartbreaks for the WWE fans around the world. The Undertaker's undefeated streak was finally over.
Now as an Undertaker fan, you're disappointed, disheartened and shattered to pieces. And Little Jhool doesn't want to upset you in any way possible. 
(After all you are his only friend, true friend!) Little Jhool knows that you're still sensitive to the loss, so he decides to help you out.
Every time you come across a number, Little Jhool carefully manipulates it. He doesn't want you to face numbers which have "21" as a part of them. Or, in the worst case possible, are divisible by 21.
If you end up facing such a number you feel sad... and no one wants that - because you start chanting "The streak is broken!" , if the number doesn't make you feel sad, you say, "The streak lives still in our heart!"
Help Little Jhool so that he can help you!

Input Format:
The first line contains a number, t, denoting the number of test cases.
After that, for t lines there is one number in every line.

Output Format:
Print the required string, depending on how the number will make you feel.

Constraints:
1 = t = 100
1 = n = 1000000

enter image description here:
Thank You Undertaker:
"The streak dies but the legened survives!"

SAMPLE INPUT 
3
120
121
231

SAMPLE OUTPUT 
The streak lives still in our heart!
The streak is broken!
The streak is broken!

// My C solution:
#include <stdio.h>
#define N 10

int main()
{
    int t,n,i=0,flag;
    char str[N];
    char *p;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        flag=0;
        if(n%21==0){
            printf("The streak is broken!\n");
            continue;
        }
        snprintf(str, N, "%d", n);
        for(p=str;*p!='\0';p++){
            if(*p=='2' && *(p+1)=='1'){
                printf("The streak is broken!\n");
                flag=1;
                break;
            }
        }
        if(!flag)
            printf("The streak lives still in our heart!\n");
    }
    return 0;
}


// My C++ solution:
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t,n,i=0,found;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        if(n%21==0){
            cout<<"The streak is broken!"<<endl;
            continue;
        }
        std::string str=std::to_string(n);
        std::size_t found = str.find("21");
        if (found!=std::string::npos)
            cout<<"The streak is broken!"<<endl;
        else
            cout<<"The streak lives still in our heart!"<<endl;
    }
    return 0;
}

*/


/*Editorial:
Submitted by Darshak Mehta:
The problem basically asks you to print a string about how you feel facing the number after the defeat of Undertaker's in Wrestlemania XXX.

After the defeat, you being Little Jhool true friend, he doesn't want to upset you in any way possible. He knows that you're still sensitive to the loss, so he decides to help you out. Every time you come across a number, Little Jhool will carefully manipulate it such that you dont face numbers which have "21" as a part of them If you end up facing such a number you feel sad... and no one wants that - because you start chanting "The streak is broken!" , if the number doesn't make you feel sad, you say, "The streak lives still in our heart!"

The problem is as simple as we you feel!

Implementation Two things to be taken care are:
1) The number faced by you should not be divisible by 21(i.e n%21 !=0)
2) The number should not contain '21'

Therefore, In Java and C/C++, first case can be taken care by using Modulo(%)operator

While in second case,we can implement using: 
1) Brute Force i.e comparing '21' in the entire numeral string OR
2) Using Rabin Karp Algorithm

The basic flow of the problem will be as follows:

Start  
Take the number of test cases  
While there is a test case remaining to be handled    
    Take in the number who has to be faced, let it be n    
    Compute n%21 if it is zero  
    print The streak is broken!  
    else if search pattern '21' if it is found   
    print The streak is broken!  
   else  
    print The streak lives still in our heart!
Note: In case of searching the pattern Integer n has to be converted to String to compute respective matching algorithms.
It is possible by sprintf.
Use of itoa() to convert int to string is not expected since itoa() is not a function in linux, itoa() has been deprecated.


Author Solution by Arjit Srivastava
tc = int(raw_input())
while (tc>0):
	tc = tc - 1
	n = int(raw_input())
	m = str(n)
	if (m.find('21')>=0) or (n%21==0):
		print "The streak is broken!"
	else:
		print "The streak lives still in our heart!"
*/


/* Best Submission:
C:

#include <stdio.h>
 
int main()
{
long int t,n,x,y,j;
scanf("%ld",&t);
for(int i=0;i<t;i++)
{
	j=0;
	y=0;
scanf("%ld",&n);
if(n%21==0)
y=1;
else
{
while(1)
{
x=n%10;
n/=10;
	if(x==1)
	{
		y=n%10;
		if(y==2){
			y=1;
			break;
			
		}
		
	}
	else
	{
		if(n==0)
		break;
		
	}
}
}
if(y==1)
printf("The streak is broken!\n");
else
printf("The streak lives still in our heart!\n");
}
    return 0;
}

C++:
#include <iostream>
using namespace std;
 
bool substr21(const string & s) {
    for (int i = 0; i < s.length() - 1; i++)
        if (s[i] == '2'  and  s[i+1] == '1')
            return true;
    return false;
}
 
int main()
{
    int t;
    cin >> t;
    string s;
    int n;
    while (t) {
        t--;
        cin >> s;
        if (substr21(s))
            cout << "The streak is broken!" << endl;
        else if (stoi(s) % 21 == 0)
            cout << "The streak is broken!" << endl;
        else
            cout << "The streak lives still in our heart!" << endl;
        
    }
    return 0;
}

C++14:
#include<bits/stdc++.h>
 
 
#define X  first
#define Y  second
typedef long long ll;
 
#define FOR(i,a,b) for(ll i = a;i<=b;i++)
#define FOD(i,a,b) for(ll i = a;i>=b;i--)
#define pb push_back
#define mp make_pair
 
using namespace std;
 
 
typedef pair<ll,ll>ii;
typedef priority_queue<ll,vector<ll>,greater<ll> > heap_min;
 
ll t,a,f[10005];
 
bool check(ll x)
{
    ll i=1;
    while(x>0)
    {
       f[i]=x%10;
       x/=10;
       i++;
    }
    FOR(j,1,i-2)
        if (f[j]==1 && f[j+1]==2) return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>a;
        if (a%21==0) cout<<"The streak is broken!"<<endl;
        else
        {
            if (check (a)) cout<<"The streak is broken!"<<endl;
            else cout<<"The streak lives still in our heart!"<<endl;
        }
    }
    return 0;
}


Java:
// IMPORTANT: Multiple classes and nested static classes are supported
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
public class RIP {
    public static void main(String[] args) throws NumberFormatException, IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        short t = Short.parseShort(br.readLine());
        while (t-- > 0)
        {
            String number = br.readLine();
            boolean isBroken = number.contains("21");
            if (!isBroken)
            {
                int n = Integer.parseInt(number);
                isBroken = n % 21 == 0;
            }
            
            if (isBroken)
            {
                System.out.println("The streak is broken!");
            }
            else
            {
                System.out.println("The streak lives still in our heart!");
            }
        }
    }
}

Java 8:
//IMPORTANT: Multiple classes and nested static classes are supported 
//uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;
//import for Scanner and other utility classes
import java.util.*;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        //
        // Read input from stdin and provide input before running
        // Use either of these methods for input
        //BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int N = Integer.parseInt(line);
 
        //Scanner
        //Scanner s = new Scanner(System.in);
        //int N = s.nextInt();

        for (int i = 0; i < N; i++) {
            String stringRepresentingNumber = br.readLine();
            int numberToTest = Integer.parseInt(stringRepresentingNumber);
            
            if(stringRepresentingNumber.contains("21")){
                System.out.println("The streak is broken!");
            }else if(numberToTest%21 == 0){
                System.out.println("The streak is broken!");
            }else{
                System.out.println("The streak lives still in our heart!");
            }
        }
        
    }
}

JavaScript(Rhino):
// Below is a sample code to process input from STDIN.
// Equivalent in effect to the Java declaration import java.io.*;
importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new Scanner(System['in']);
 
var t = sc.nextInt();
while(t>0){
	var n = sc.nextInt();
	var ind=n.toString().indexOf('21')+1;
	
	if(ind>0 || n % 21 ===0){
		print('The streak is broken!');
	}else{
		print('The streak lives still in our heart!');
	}
	t--;
}

JavaScript(Node.js):
function main(input) {
    //Enter your code here
    input=input.split("\n");
    var output=[];
    var count=0;
    for(i=1;i<input.length;i++){
        count = (input[i].match(/21/g) || []).length;
        if(count){
            output.push("The streak is broken!");
        }else{
            if(parseInt(input[i])%21)
                output.push("The streak lives still in our heart!");
            else
                output.push("The streak is broken!");
                
        }
        count=0;
    }
    process.stdout.write(output.join('\n'));
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

C#:
using System; 
class MyClass {
    static void Main(string[] args) {
        //Read input from stdin and provide input before running
        //var line1 = System.Console.ReadLine().Trim();
        //var N = Int32.Parse(line1);
        //for (var i = 0; i < N; i++) {
        //    System.Console.WriteLine("hello world");
        //}
        
 
        int T = 0;
            T = Convert.ToInt32(System.Console.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string temp = System.Console.ReadLine();
                if (temp.IndexOf("21") != -1 || (Convert.ToInt64(temp) % 21 == 0))
                {
                    System.Console.WriteLine("The streak is broken!");
                }
                else
                {
                    System.Console.WriteLine("The streak lives still in our heart!");
                }
            }
    }
}

Pascal:
var
  t,i,n,counter,pos1,pos2,ok:longint;
 
begin
  readln(t);
 
  for i:=1 to t do
    begin
      readln(n);
 
      ok:=0;
      pos1:=0;
      pos2:=0;
 
      if(n mod 21<>0) then
        begin
          ok:=1;
          counter:=1;
          repeat
            if(n mod 100=21) then
              begin
                ok:=0;
                break;
              end;
            n:=n div 10;
            inc(counter);
          until
            n=0;
 
          if(pos1 < pos2) then ok:=1;
        end;
 
      if ok=1 then writeln('The streak lives still in our heart!')
      else writeln('The streak is broken!');
    end;
end.

Perl:
use strict;
 
my $count;
my @list;
$count=<STDIN>;
if(($count<= 100)&&($count>=1)) {
	for(my $i=0;$i<$count;$i++) {
		$list[$i]=<STDIN>;
		if(($list[$i]<= 1000000)&&($list[$i]>=1)) {
			if(($list[$i] % 21 == 0)||($list[$i] =~/21/)){
					print "The streak is broken!\n";
			} else {print "The streak lives still in our heart!\n";}
		}
	}
}

PHP:
<?php 
$firstrun = true;
while ((string)$str = trim(fgets(STDIN))) {
    if ($firstrun == true) {
        $cnt = $str;
        $firstrun = false;
        continue;
    }
    if ($cnt == 0)
        break;
    if ($str % 21 == 0 || strstr($str,'21'))
        echo "The streak is broken!";
    else
        echo "The streak lives still in our heart!";
    echo "\n";
    $cnt--;
}
?>

Python:
'''
# Read input from stdin and provide input before running code
 
name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
def find_21(s):
    if len(s) <= 1:
        return False
    for i in xrange(len(s)-1):
        if s[i:i+2] == "21":
            return True
    return False
 
t = input()
for _ in xrange(t):
    tmp = input()
    if tmp % 21 == 0 or find_21(str(tmp)) == True:
        print "The streak is broken!"
    else:
        print "The streak lives still in our heart!"

Python 3:
for i in range(int(input())):
    s = input()
    if ('21' in s) or (int(s))%21==0:
        print("The streak is broken!")
    else:
        print("The streak lives still in our heart!")

R:
con <-file("stdin")
 
data <- readLines(con, warn = FALSE)
a <- "The streak lives still in our heart!"
b <- "The streak is broken!"
output <- c()
for(i in 1:as.numeric(data[1])){
    output[i] <- a
    value <- data[i+1]
    sep_value <- strsplit(value,"")
    for(j in 1:length(sep_value[[1]])-1){
     test <- paste0(sep_value[[1]][j],sep_value[[1]][j+1])
     if(test =="21"){
     output[i] <- b
     break
    }
   }
   if(as.numeric(value) %% 21 == 0){
   output[i] <- b
   }
}
close(con)  
cat(output, sep="\n") 

Ruby:
testcount = gets.chomp
 
i=0
while (i < testcount.to_i)
    i+=1
	val = gets.chomp
	if (val.include? "21")
		puts "The streak is broken!"
		next
	end
	if ((val.to_i % 21) == 0)
		puts "The streak is broken!"
		next
	end
	puts "The streak lives still in our heart!"
end

VB:
Imports System
Module Main
 
    Sub Main()
        Dim lineas as integer
        Dim numero as integer
        Dim x as integer
        
        lineas = console.readline()
        for x=1 to lineas
        	Numero = console.readline()
        	if Numero Mod 21 = 0 or numero.tostring().indexof("21") >=0 then
        		console.writeline("The streak is broken!")
        	   else
        		console.writeline("The streak lives still in our heart!")	
        	End if
        Next 
    End Sub
 
End Module

	
*/


/* I/O:
Input #1:
43
69521
7484
78175
86424
18929
5093
32256
85231
79632
41092
23030
63277
76607
30523
25835
9218
35751
81305
31418
89505
32057
57009
24955
82525
78177
56949
81996
49202
69475
42669
37698
48269
92648
70010
72777
45342
44735
68903
16283
25350
96967
80658
9803
Output #1:
The streak is broken!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak is broken!
The streak lives still in our heart!
The streak is broken!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak is broken!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
Input #2:
43
32015
50965
72495
73726
30981
17867
45603
49304
24440
94760
28136
19599
46262
6842
22463
71743
44054
63691
89497
26919
80135
24378
57469
49317
85944
94443
63800
62307
52119
28565
44150
65241
39054
853
68685
60944
61875
36545
59750
76769
83327
32208
84076
Output #2:
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak is broken!
The streak is broken!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
Input #3:
43
70094
32451
81996
94945
66592
95666
56597
30999
37838
69486
12189
49843
99036
99581
66047
25991
97370
95747
24363
78941
81920
32127
36071
74224
59348
56285
40357
44730
69466
67521
34774
96220
94847
74993
83466
14454
99893
49313
91338
62333
6140
96093
75101
Output #3:
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak is broken!
The streak lives still in our heart!
The streak is broken!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak is broken!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak is broken!
The streak lives still in our heart!
The streak is broken!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
Input #4:
99
23807
19577
66853
74334
31342
59455
48392
1150
44169
29286
7278
70126
52222
23505
53519
67573
45707
54015
15400
10310
93905
14504
50836
97511
33584
79722
15739
83149
99326
83388
17518
65177
61809
26489
75046
15050
69836
84181
27903
23614
70304
15195
63071
38153
83127
71740
23790
96930
62692
88286
83469
81975
55947
61854
53457
90868
26492
39087
62266
10028
73385
22276
66700
96718
33901
79567
74393
19537
83095
73897
75268
25539
37950
91175
93990
12485
53564
96946
88829
19309
27775
75499
89023
59001
33794
46724
21933
51635
46565
83566
77987
55558
5247
53639
85182
55535
65718
13480
58335
Output #4:
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak is broken!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
Input #5:
43
12873
57519
11487
92337
57687
98679
43743
21546
57351
50862
99519
14952
52374
48384
10353
42399
35217
62013
40194
42294
59934
72765
72492
6006
84651
15309
35364
45759
62664
80010
16695
52962
79023
71106
21378
38367
14154
32445
9765
32277
40971
14700
99435
Output #5:
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
The streak is broken!
Input #6:
99
4075
84776
88708
62456
98094
35976
97063
55399
30661
70097
30509
41052
17837
63493
74793
40526
63993
74576
35849
30595
24809
82359
19862
45878
91260
19968
69278
80396
86384
49145
80651
59992
42238
75334
35668
46528
27859
99366
75734
84813
75963
8444
9530
20408
89006
86821
61857
42493
27322
57842
95241
26625
43747
66937
2144
52573
13405
30318
64036
76621
88181
30359
74418
32230
34165
77655
42018
15937
49730
44453
6142
70496
51922
7952
15122
74767
11615
66121
93283
58287
769
51098
45747
57016
17389
21549
52925
59004
42728
92577
97421
56884
91062
26223
33085
255
84191
85913
71266
Output #6:
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak is broken!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak is broken!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak is broken!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak is broken!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak is broken!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak is broken!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
Input #7:
99
39316
41257
22796
75956
90742
20444
16206
30113
1831
14134
83032
18625
4671
49260
18652
88359
47254
71710
22658
52733
51022
15952
4415
80569
63936
74153
18959
79123
53618
22624
4678
40936
86267
96046
82637
80198
69073
98291
10891
93803
44238
85709
78644
78412
81634
25232
65946
23929
64312
52673
95353
8764
46234
48595
69946
5886
96857
21122
68259
90822
41758
74079
42752
44818
84386
52715
82822
10415
41987
79489
25603
23511
29633
56759
35865
42879
37822
21349
27421
29845
74766
83703
62416
93383
67071
57985
80916
99534
91948
72763
52270
71553
20758
26277
11086
53660
39953
93742
5656
Output #7:
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak is broken!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak is broken!
The streak is broken!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!
The streak lives still in our heart!

*/

