/* All Tracks --> Basic Programming -->  Operators  --> Basics of Operators  --> Problem
Birthday Party
Tag(s): Easy
Mr. X's birthday is in next month. This time he is planning to invite N of his friends. He wants to distribute some chocolates to all of his friends after party. He went to a shop to buy a packet of chocolates.
At chocolate shop, each packet is having different number of chocolates. He wants to buy such a packet which contains number of chocolates, which can be distributed equally among all of his friends.
Help Mr. X to buy such a packet.

Input:
First line contains T, number of test cases.
Each test case contains two integers, N and M. where is N is number of friends and M is number number of chocolates in a packet.

Output:
In each test case output "Yes" if he can buy that packet and "No" if he can't buy that packet.

Constraints:
1<=T<=20
1<=N<=100
1<=M<=10^5

Problem Setter:
Akash Rakshit

SAMPLE INPUT 
2
5 14
3 21
SAMPLE OUTPUT 
No
Yes
Explanation
Test Case 1:
There is no way such that he can distribute 14 chocolates among 5 friends equally. 
Test Case 2:
There are 21 chocolates and 3 friends, so he can distribute chocolates eqally. Each friend will get 7 chocolates.



// My C code:
// Write your code here
#include <stdio.h>

int main(){
    int num=0,i=0,n=0,nchocs=0;
    scanf("%d",&n);
    
    while(i<n){
        scanf("%d%d",&num,&nchocs);
        if(nchocs%num==0)
            printf("Yes\n");
        else
            printf("No\n");
        i++;
    }
    return 0;
}


// My C++ code here
#include <iostream>
using namespace std;

int main(){
    int num=0,i=0,n=0,nchocs=0;
    
    cin>>n;
    
    while(i<n){
        cin>>num>>nchocs;
        if(nchocs%num==0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
        i++;
    }
    return 0;
}

*/


/* Best Submissions:
C:
//#include<stdio.h>
int main()
{
    int t;
int n,m;
scanf("%d",&t);
while(t--)
{
    scanf("%d%d",&n,&m);
    if(m%n==0)
     printf("Yes\n");
    else
    printf("No\n");
    
}
return 0;
 
}

C++:
#include <bits/stdc++.h>
using namespace std;
int main(){
    int test;
    scanf("%d",&test);
    for(int i=0;i<test;i++){
        int n,m;
        scanf("%d %d",&n,&m);
        if(m%n==0)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

C++14:
#include<iostream>
using namespace std;
int main()
{
    int T,N,M;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>N;
        cin>>M;
        if(M%N==0)
        {
            cout<<"\nYes";
        }
        else
        {
            cout<<"\nNo";
        }
    }
}

C#:
using System;
 
namespace Amir
{
	class Sohail
	{
		public static void Main(string[] args)
		{
            int n = Convert.ToInt32 ( Console.ReadLine() );                  
            
            for (int i=0; i<n; i++)
            {
                string st = Console.ReadLine();
                string[] tokens = st.Split();
                int[] num = Array.ConvertAll(tokens, int.Parse);
                
                if (num[1]%num[0]==0)
                    Console.WriteLine ("Yes");
                else
                    Console.WriteLine ("No");
            }
		}
	}
}

Java:
import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
       
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int i=0;i<t;i++){
        int n = s.nextInt();
        int m = s.nextInt();
        // if(m%n==0)
        //System.out.println("Yes");
        //else
        //System.out.println("No");
        System.out.println((m%n == 0) ? "Yes" : "No");
        }
 
    }
}

Java 8:
//import for Scanner and other utility classes
import java.util.*;
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        //Sample code to perform I/O:
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
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for(int i=0;i<t;i++){
            int a = s.nextInt();
            int b = s.nextInt();
            if(b%a==0 || a%b==0)
              System.out.println("Yes");
            else
              System.out.println("No");
        }
    }
}


Java(Rhino):

importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new Scanner(System['in']);	
var my_name = sc.nextLine();
for(var i=0;i<my_name;i++){
    var tmp = sc.nextLine();
    var num = parseInt((tmp+"").split(" ")[0]);
    var chocos = parseInt((tmp+"").split(" ")[1]);
    if(chocos % num == 0){
        System.out.println("Yes");	
    }else{
        System.out.println("No");	
    }
    
}// Reading input from STDIN

Java(Node.js):
// Sample code to perform I/O:
 
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
    // process.stdout.write("Hi, " + input + ".\n");       // Writing output to STDOUT
    
    
    var input = input.split("\n")
    var t= parseInt(input[0]);
    for(var i= 1;i<input.length;i++){
        var data = input[i].split(" ");
        var n = parseInt(data[0]);
        var chocolate = parseInt(data[1]);
        if(chocolate%n == 0){
           process.stdout.write("Yes"  + "\n")  
        }
        else{
              process.stdout.write("No"  + "\n")  
        }
    }
    
    
}
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
// Write your code here

Perl:
=comment
# Sample code to perform I/O:
 
my $name = <STDIN>;             # Reading input from STDIN
print "Hi, $name.\n";           # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
=cut
 
# Write your code here
use warnings;
use strict;
 
 
my $t=<STDIN>;
#my $n_m=<STDIN>;
my $n_m;
my ($n, $f);
#print "$n --$f ";
my $res=0;
 
#for (my $i = 1; $i <= $t; $i++) {
#	#$n_m=<STDIN>;
#	 #($n, $f)=split(/\s+/,$n_m);
#	
#}
 
for (my $i = 1; $i <= $t; $i++) {
	
	 $n_m=<STDIN>;
	($f, $n)=split(/\s+/,$n_m);
		$res=$n%$f;
		if($res == 0) { 
			print "Yes\n";
			}
		else { 
			print "No\n";
			}
	
}

Python:
t = int(raw_input())
for i in range(t):
    p,c = [int(x) for x in raw_input().split()]
    print "No" if c%p else "Yes"

Python 3:
'''
# Sample code to perform I/O:
 
name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''
 
# Write your code here
test_cases = int(input())
 
for x in range(test_cases):
    n, m = map(int,input().split())
    
    print("Yes" if (int(m) % int(n) == 0) else "No")


Ruby:
=begin
# Sample code to perform I/O:
 
name = gets.chomp                # Reading input from STDIN
print "Hi, #{name}.\n"           # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
=end
 
# Write your code here
test = gets.chomp.to_i
for i in 0...test
  friends, chocolates = gets.chomp.split(" ").map(&:to_i)
  if (chocolates % friends == 0)
    puts "Yes"
  else
    puts "No"
  end
end

*/

/* I/O:

In #1:
10
6 84
12 78
36 94
13 87
10 50
28 63
13 91
27 64
27 81
37 73
Out #1:
Yes
No
No
No
Yes
No
Yes
No
Yes
No

In #2:
20
84 30887
78 36916
87 1131
94 38336
87 60493
50 100
63 504
50 41422
63 90028
91 20060
84 168
78 858
94 1034
64 13927
41 83427
91 455
64 128
41 287
73 146
73 55737
Out #2:
No
No
Yes
No
No
Yes
Yes
No
No
No
Yes
Yes
Yes
No
No
Yes
Yes
Yes
Yes
No

*/


/* Editorial:
if the number of chocolate is dividable among friends then you can print "Yes" or else "No"


for _ in range(int(input())):
    n,m=map(int,input().split())
    if(m>n):
        if(m%n==0):
            print("Yes")
        else:
            print("No")
    else:
        print("No")



*/

