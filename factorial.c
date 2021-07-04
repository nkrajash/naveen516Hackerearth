/*All Tracks --->Basic Programming ---> Input/Output --->  Basics of Input/Output ---> Problem --->
Factorial!
You have been given a positive integer N. You need to find and print the Factorial of this number. 
The Factorial of a positive integer N refers to the product of all number in the range from 1 to N. 
You can read more about the factorial of a number here.

Input Format:
The first and only line of the input contains a single integer N denoting the number whose factorial you need to find.

Output Format
Output a single line denoting the factorial of the number N.

Constraints
1≤N≤10

SAMPLE INPUT
2

SAMPLE OUTPUT
2


#include <stdio.h>

long my_factorial(int n);

int main()
{
    long n;
    int num;
    
    scanf("%d",&num);

    n=my_factorial(num);
    printf("%ld",n);
}


long my_factorial(int n){
    long l=1;
    int i;
    if(n==0)
        return l;
    else{
        for(i=1;i<=n;i++)
            l*=i;
    }
    return l;
}

*/

/*Editorial:
All one needs to do here is to find the product of all the number in the range from 1 to N. This can be done by iterating over the entire range from 1 to N.

Author's Solution:

import java.io.*;
import java.util.*;
class example_2
{
    static Scanner sc=new Scanner(System.in);

    public static void main(String args[]) throws Exception
    {
        long n=sc.nextLong(),prod=1;
        for(long i=1;i<=n;i++)
        {
            prod=prod*i;
        }
        System.out.println(prod);
    }
}

*/


/* I/O:
In #1:
5
Out #1:
120
In #2:
7
Out #2:
5040
In #3:
8
Out #3:
40320
In #4:
10
Out #4:
3628800

*/


/* Best Submissions:
Bash:
# Sample bash code
function fact() {
    #echo $1
    if [[ $1 -le 1 ]]
    then
        echo 1
    else
        smaller=$(($1-1))
        echo $(($1 * $(fact $smaller)))
    fi
}
 
read n
#echo $n
f=$(fact $n)
echo $f

C:
#include<stdio.h>
int main()
{
int N,i,fact;
fact=1;
 
scanf("%d",&N);
 
 
for(i=1;i<=N;i++)
{
fact=fact*i;
}
printf("%d",fact);
return 0;
}

C++:
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n,f=1;
    cin>>n;
    for(int i=2;i<=n;i++)
    	f*=i;
    cout<<f;
    return 0;
}

C++14:
#include <cstdio>
 
int main() {
    int n;
    scanf("%d", &n);
    int f = 1;
    for (int i = 1; i <= n; ++i) {
        f *= i;
    }
    printf("%d\n", f);
    return 0;
}

C#:
using System; 
using System.Numerics;
class MyClass {
    static void Main() {
		int fac = 0;
		int ans = 0;
		int.TryParse(Console.ReadLine(), out fac);// to factorial
		ans = fac;
		while ((fac - 1) > 1) {
			ans = ans * --fac;
		}
		Console.WriteLine(ans);
		//cin >> fac;//stop look
    }
}

Java:
import java.util.Scanner;
 
class Factorial
{
	public static void main(String... strings)
	{
		int N;
		int result = 1;
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		for(int i = 2; i <= N; i++) {
			result = i * result;
		}
		System.out.println(result);
	}
}

Java 8:
import java.util.*;
 
 
class TestClass {
    public static void main(String args[] ) throws Exception {
    
    	try (Scanner input = new Scanner(System.in)) {
 
			int fatorial = input.nextInt();
			
			int total=fatorial;
			
			for(int i=fatorial-1;i>=1;i--){
				total = total * i;
			}
			
			System.out.println(total);
			
 
		} catch (Throwable e) {
			e.printStackTrace();
		}
    
    }
}

JavaScript(Rhino):
importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new Scanner(System['in']);
 
var n = sc.nextInt();
var f=1;
for(i=1; i<=n; i++)
    f=f*i;
print(f);

JavaScript(Node.js):
function main(input) {
    //input = parseInt(input,10);
    var fact = 1;
    for(var i=1;i<=input;i++){
        fact = fact * i;
    }
    process.stdout.write(fact);
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

Lua:
n = io.read("*n")
p=1
for i=1,n do
    p=p*i
end
print(p)

Pascal:
var n,s:longint;
 
procedure nhap;
begin
    readln(n);
end;
 
procedure xuli;
var i:longint;
begin
    s:=1;
    for i:=1 to n do s:=s*i;
    writeln(s);
end;
 
begin
    nhap;
    xuli;
end.

Perl:
use strict;
use feature 'say';
 
my $num = <STDIN>;
 
my $fact=1;
$fact *= $_ for (1..$num);
 
say $fact;

Python 2:
'''
# Read input from stdin and provide input before running code
 
name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
a = int(raw_input())
b=1
for i in range(1,a+1):
	b = b*i
print b

R:
n<- scan('stdin',quiet=TRUE)
fact<-1
repeat { fact <- fact*n;n<-n-1; if (n==1) break;; ;;;;;;;;;}
 
cat(fact)


Python 3:
n = int(input());
result=1;
 
def fact(a):
    if (a==1):
        return 1;
    else:
        return a*fact(a-1);
 
print (fact(n))



PHP:
<?php

//Read input from stdin and provide input before running code
//fscanf(STDIN, "%s\n", $name);
//echo "Hi, ".$name;
 
fscanf(STDIN,"%d\n",$num);
$j=1;
$fact = 1;
while($j<=$num){
	$fact = $fact * $j;
	$j++;
}
echo $fact;
 
?>

Ruby:
=begin
# Read input from stdin and provide input before running code
 
print "Please enter your name: "
name = gets.chomp
print "Hi #{name}\n"
=end
 
number = gets.chomp.to_i
factorial = 1
for i in 1..number
factorial = factorial*i
end
puts factorial


VB:
Module Main
 
    Sub Main()
  		Dim M as integer
  		Dim N as integer
  		Dim x as integer
  		M=1
  		N = console.readline()
  		For X = 2 to N
  			M = M * X
  		Next 
  		console.writeline(M)
    End Sub
 
End Module
*/