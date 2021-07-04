/*All Tracks --> Basic Programming -->  Input/Output -->  Basics of Input/Output -->  Problem --> 
Count Divisors
Tag(s): Very-Easy
You have been given 3 integers - l, r and k. 
Find how many numbers between l and r (both inclusive) are divisible by k. 
You do not need to print these numbers, you just have to find their count.

Input Format:
The first and only line of input contains 3 space separated integers l, r and k.

Output Format:
Print the required answer on a single line.

Constraints
1≤l≤r≤1000
1≤k≤1000

SAMPLE INPUT
1 10 1

SAMPLE OUTPUT
10

#include <stdio.h>
int main()
{
    int l,i,r,k,c=0;
    scanf("%d",&l);
    scanf("%d",&r);
    scanf("%d",&k);
    for(i=l;i<=r;i++){
        if(i%k==0)
            c++;
    }
    printf("\n%d\n",c);
}

*/

/*Best Submissions:
Bash:
#! /bin/bash
# https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/count-divisors/
read l r k;
if [ $(($l%$k)) != 0 ]; then
    l=$[ $l + $k - ($l % $k)];
fi
if [ "$l" -gt "$r" ]; then
    l=0;
else
    l=$((($r-$l)/$k+1));
fi
echo $l;

C:
#include <stdio.h>
 
int main()
{int l,r,k,i,count;
    scanf("%d ",&l);
    scanf("%d ",&r);
    scanf("%d ",&k);
 for (i=l;i<=r;i++){
 	if(i%k==0){
 	count++;	
 	} 
 	else count = count;
 }
 printf("%d",count);
}

C++:
#include <iostream>
using namespace std;
 
int main()
{
    int l,r,k,i,count=0;
    cin>>l>>r>>k;
    
    for(i=l;i<=r;i++)
    {
        if(i%k==0)
        count++;
    }
    cout<<count;
   
    return 0;
}

C++14:
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int l,r,k,count=0;
    cin >> l >> r >> k;
    
    for(int i=l;i<=r;i++)
    {
        if((i%k)==0)
        count++;
    }
    cout << count << endl;
}

C#:
using System; 
using System.Numerics;
class MyClass {

    static void Main(string[] args) {
    //   Read input from stdin and provide input before running
    //   var line1 = System.Console.ReadLine().Trim();
    //    var N = Int32.Parse(line1);
    //    for (var i = 0; i < N; i++) {
    //        System.Console.WriteLine("hello world");
    //    }

    int count = 0;
    string s = System.Console.ReadLine().Trim();
    var a = s.Split(' ');
    //int l = Int32.Parse(a[0]);
    //int r = Int32.Parse(a[1]);
    int k = Int32.Parse(a[2]);
    
    //if(Int32.Parse(a[0]) % Int32.Parse(a[2]) == 0 || Int32.Parse(a[1]) % Int32.Parse(a[2]) == 0)
    //    count = r/k - l/k + 1;
    //else
    //    count = r/k - l/k;

    if(Int32.Parse(a[0]) % k == 0 || Int32.Parse(a[1]) % k == 0)
        count = Int32.Parse(a[1])/k - Int32.Parse(a[0])/k + 1;
    else
        count = Int32.Parse(a[1])/k - Int32.Parse(a[0])/k;
    Console.WriteLine(Convert.ToString(count));
}
}

Java:
import java.util.Scanner;
 
class CountDivisor
{
	public static void main(String... strings)
	{
		int l, r, k;
		Scanner scanner = new Scanner(System.in);
		l = scanner.nextInt();
		r = scanner.nextInt();
		k = scanner.nextInt();
		int count = 0;
		for(int i = l; i <= r; i++) {
			if(i % k == 0) {
				count++;
			}
		}
		System.out.println(count);
	}
}

Java8:
import java.util.Scanner;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		int l = sc.nextInt();
		int r = sc.nextInt();
		int k = sc.nextInt();
		
		sc.close();
		int count = 0;
		if(l == r && l%k != 0) {
			System.out.println(0);
			System.exit(0);
		}
		
		while (l <= r) {
			if(l % k == 0) {
				break;
			}
			l++;
		}
 
		count = (r - l) / k + 1;
		System.out.println(count);
    }
}

Pascal:
var l,k,r,d:longint;
begin
	readln(l,r,k);
	while (l<=r) and (not (l mod k = 0)) do l:=l+1;
	if l mod k = 0 then d:=1 else 
	begin
	writeln('0');
	exit;
	end;
	while l<r do
	begin
		l:=l+k;
		d:=d+1;
	end;
	if l>r then d:=d-1;
	writeln(d);
end.

Perl:
use strict;
use feature 'say';
 
my ($l,$r,$k) = split / / , <STDIN>;
 
my $count;
for ($l .. $r) {
    $count++ unless ($_ % $k);
}
 
say $count ? $count : 0;

Python:
'''
# Read input from stdin and provide input before running code
 
name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
x=raw_input()
y=x.split()
l=int(y[0])
r=int(y[1])
k=int(y[2])
count=0
for i in range(l,r+1):
        if i%k==0:
                count+=1
print count

Python 3:
import sys
 
S = sys.stdin.read()
S = S.split()
S = [int(i) for i in S]
 
l = S[0]
r = S[1]
k = S[2]
 
output = 0
for i in range(l,r+1):
	if i % k == 0: output += 1
 
print(output)

PHP:
<?php
 
        $j = 0;
    
	    fscanf(STDIN, "%d %d %d", $l, $r, $k);
    
	    for($i = $l; $i <= $r; $i++)
	    	if($i % $k == 0)
	    		$j++;
     
 
        echo $j;
 
?>

Ruby:
input <- scan('stdin',what = integer(),quiet = T)
cat(length(which(input[1]:input[2]%%input[3]==0)))

#!/usr/bin/ruby
count = 0
s = gets
input1 = s.split(" ")
(input1[0]..input1[1]).each do |i|
 
i = i.to_i
if i % input1[2].to_i == 0
count = count + 1
end
end
 
puts count


VB:
Module Main
 
    Sub Main()
    Dim l,r,k as integer
    Dim split1() as string
     Dim strin as String
     
    strin=console.readline()
    split1=strin.Split(" ")
    l=split1(0)
    r=split1(1)
    k=split1(2)
    Dim count as Integer = 0
   
    For i as Integer = l to r
    
    if i Mod k=0 then
    count=count +1
    else
    
    End If
    
    Next
    
      Console.WriteLine(count)
    End Sub
 
End Module


*/

