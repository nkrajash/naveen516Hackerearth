/* All Tracks --> Data Structures--> Arrays--> Multi-dimensional--> 
Add Alternate Elements of 2-Dimensional Array

You are given a two-dimensional 3*3 array starting from A [0][0]. You should add the alternate elements of the array and print its sum. It should print two different numbers the first being sum of A 0 0, A 0 2, A 1 1, A 2 0, A 2 2 and A 0 1, A 1 0, A 1 2, A 2 1.

Input Format
First and only line contains the value of array separated by single space.

A 0 0  --> 4
A 0 1  --> 6
A 0 2  --> 9

A 1 0  --> 2
A 1 1  --> 5
A 1 2  --> 8

A 2 0  --> 1
A 2 1  --> 3
A 2 2  --> 7

Output Format:
First line should print sum of 
A 0 0, A 0 2, A 1 1, A 2 0, A 2 2
Second line should print sum of 
A 0 1, A 1 0, A 1 2, A 2 1

SAMPLE INPUT 
1 2 3 4 5 6 7 8 9
SAMPLE OUTPUT 
25
20


#include <stdio.h>

int main()
{
    int i,j,A[3][3],sumo=0,sume=0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&A[i][j]);

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if((i+j)%2==0)
                sume+=A[i][j];
            else
                sumo+=A[i][j];
    printf("%d\n",sume);
    printf("%d\n",sumo);
    return 0;
}

#include <iostream>
using namespace std;
 
int main()
{
    int i,j,A[3][3],sumo=0,sume=0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            cin>>A[i][j];
 
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if((i+j)%2==0)
                sume+=A[i][j];
            else
                sumo+=A[i][j];
    cout<<sume<<endl;
    cout<<sumo<<endl;
    return 0;
}

Alternate Solution:

#include<iostream>
using namespace std;
int main()
{int sum1=0,sum2=0;
int a[3][3];
for(int i=0;i<3;i++)
{for(int j=0;j<3;j++)
{ cin>>a[i][j];
int x=a[i][j];
if(((i+j)&1)==0)
{
sum1+=x;
}
else
{
sum2+=x; 
}


}
}
cout<<sum1<<endl<<sum2;

return 0;
}



Input #1:
1 2 3 4 5 6 7 8 9
Output #1:
25
20
Input #2:
21 422 423 443 586 645 657 846 904
Output #2:
2591
2356
Input #3:
201 212 673 685 16 604 762 147 762
Output #3:
2414
1648
Input #4:
121 75 63 85 1 4 464 125 791
Output #4
1440
289

*/

/*
Best Submissions:
C:
#include <stdio.h>
 
int main()
{
    int a[9],i,sum1=0,sum2=0;
    for(i=0;i<9;i++)
    {
        scanf("%d",&a[i]);
    }
    sum1=a[0]+a[2]+a[4]+a[6]+a[8];
    sum2=a[1]+a[3]+a[5]+a[7];
    printf("%d\n%d",sum1,sum2);
}

C++:
#include <iostream>
using namespace std;
 
int main()
{
    int a[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        cin>>a[i][j];
    }
    int sum1=0,sum2=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if((i+j)%2==0)
            sum1+=a[i][j];
            else
            sum2+=a[i][j];
        }
    }
    cout<<sum1<<endl;
    cout<<sum2<<endl;
    return 0;
}

C++14:
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int i,j,A[3][3];
    
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            cin>>A[i][j];
            
    cout<<A[0][0]+A[0][2]+A[1][1]+A[2][0]+A[2][2]<<"\n"<<A[0][1]+A[1][0]+A[1][2]+A[2][1];
}

C#:
using System; 
using System.Numerics;
class MyClass {
    static void Main(string[] args) {
       string[] substrings = Console.ReadLine().
                    Split(new char[] { ' ' }, System.StringSplitOptions.RemoveEmptyEntries);
            int firstOp = 0, secondOp = 0;
 
            for (int i = 0; i < substrings.Length; i++)
            {
                if (i % 2 == 0)
                    firstOp += int.Parse(substrings[i]);
                else
                    secondOp += int.Parse(substrings[i]);
            }
 
            Console.WriteLine(firstOp);
            Console.WriteLine(secondOp);
    }
}

Java:
import java.util.*;
 
class TestClass 
{
    public static void main(String args[] ) throws Exception
    {
        
        Scanner in = new Scanner(System.in);
        
        int array[][] = new int[3][3];
        
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                array[i][j] = in.nextInt();
            }
        }
        
        int c1=0;
        int c2=0;
        
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if((i+j)%2==0)
                {
                    c1+=array[i][j];
                }
                else 
                {
                    c2+=array[i][j];
                }
            }
        }
        
        System.out.println(c1);
        System.out.println(c2);
    }
}

Java8:
import java.util.*;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        
        Scanner s = new Scanner(System.in);
       
        int[] a=new int[9];
        for (int i = 0; i < 9; i++) {
           a[i]=s.nextInt();
        }
        int sum1=0;
        int sum2=0;
        
 for (int i = 0; i < 9; i++){
     if(i%2==0)
     sum1+=a[i];
     else
     sum2+=a[i];
 } 
 System.out.println(sum1);
 System.out.println(sum2);
    }
}

Perl:

=comment
# Sample code to perform I/O:
 
my $name = <STDIN>;             # Reading input from STDIN
print "Hi, $name.\n";           # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
=cut
 
 
# You are given a two-dimensional 3*3 array starting from A [0][0]. You should add the alternate elements of the array and print its sum. It should print two different numbers the first being sum of A 0 0, A 0 2, A 1 1, A 2 0, A 2 2 and A 0 1, A 1 0, A 1 2, A 2 1.
 
# Input Format
 
# First and only line contains the value of array separated by single space.
# A00 A01 A02
# 4   6   9
# A10 A11 A12
# 2   5   8
# A20 A12 A22
# 1   3   7
 
# Output Format
 
# Output Format
 
# First line should print sum of A 0 0, A 0 2, A 1 1, A 2 0, A 2 2
 
# Second line should print sum of A 0 1, A 1 0, A 1 2, A 2 1
 
# SAMPLE INPUT 
# 1 2 3 4 5 6 7 8 9
# SAMPLE OUTPUT 
# 25
# 20
 
 
# Write your code here
my @A;
my $pares = 0, $impares = 0;
@A = split(/ /,<STDIN>);
 
for(my $i=0 ; $i < scalar(@A); $i++){
	if($i % 2 == 0){
		$pares += $A[$i];
	}else{
		$impares += $A[$i];
	}
}
print "$pares\n$impares";

PHP:
<?php
 
$g = explode(" ",fgets(STDIN));
$i=0;
$sum1=0;
$sum2=0;
while(isset($g[$i])){
    if($i%2==0){
        $sum1 = $sum1 + $g[$i];
    }else{
        $sum2 = $sum2 + $g[$i];
    }
    $i++;
}
echo "$sum1\n$sum2";
$sum=0;
?>

Python:
'''
# Read input from stdin and provide input before running code
 
name = raw_input()
print 'Hi, %s.' % name
'''
a = raw_input().split()
a = map(int, a)
 
print sum(a[::2])
print sum(a[1::2])

Python 3:
L=map(int ,input().split())
L=list(L)
sum1=0
sum2=0
for i in range(len(L)):
    if i%2==0:
        sum1=sum1+L[i]
    else:
        sum2=sum2+L[i]
print(sum1)
print(sum2)

*/