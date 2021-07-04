// Sample code to perform I/O:
#include <stdio.h>
int main(){
	int A, B, C, D=0;
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	D=A;
	A=B;
	B=D;
	A=A*C;
	B=B+C;
	printf("%d %d",A, B);
return 0;
}
Python:
b,a,c=input().split()
print(int(a)*int(c), int(c)+int(b))

Python 3:
'''
# Sample code to perform I/O:
 
name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''
 
# Write your code here
n=list(map(int, input().split()))
a=n[0]
b=n[1]
c=n[2]
a=a+b
b=a-b
a=a-b
print(a*c,end=" ")
print(b+c)

C++:
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int a,b,c;
    cin >> a >>b >> c;
    /*
    a = a +b;
    b = a-b;
    a = a-b;
    */
    swap(a,b);
    a = a *c;
    b = b +c;
    cout << a <<" "<< b << endl;
    return 0;
    
}
C++14:
#include<iostream>
using namespace std;
int main()
{
    int A,B,C,temp;
    cin>>A>>B>>C;
    temp=A;
    A=B;
    B=temp;
    A*=C;
    B+=C;
    cout<<A<<" "<<B;
}

C#:
using System;
 
class Program{
    static void Main(){
        string[] line = Console.ReadLine().Split(' ');
        int a, b, c, d;
        b = int.Parse(line[0]); // swap a avec b
        a = int.Parse(line[1]); // swap a avec b
        c = int.Parse(line[2]);
        a*=c;
        b+=c;
        Console.WriteLine($"{a} {b}");
    }   
}

Java:
/* IMPORTANT: Multiple classes and nested static classes are supported */
 
 
//imports for BufferedReader
import java.io.*;
 
//import for Scanner and other utility classes
import java.util.*;
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        
        Scanner s = new Scanner(System.in);
        int a = s.nextInt();
        int b=s.nextInt();
        int c=s.nextInt();
         
        int temp=a;
        a=b;
        b=temp;
        
        a=a*c;
        b=b+c;
        
            // Reading input from STDIN
        System.out.println(" "+a+" "+b+" ");
        
 
        
 
        // Write your code here
 
    }
}

Java 8:
/* IMPORTANT: Multiple classes and nested static classes are supported */
 
/*
 * uncomment this if you want to read input.
//imports for BufferedReader
import java.io.InputStreamReader;
 
//import for Scanner and other utility classes
import java.util.*;
*/
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
        /* Sample code to perform I/O:
         * Use either of these methods for input
 
        //BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String name = br.readLine();                // Reading input from STDIN
        System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        //Scanner
        Scanner s = new Scanner(System.in);
        String name = s.nextLine();                 // Reading input from STDIN
        System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        */
 
        // Write your code here
        int temp;
          Scanner s = new Scanner(System.in);
        Integer a = s.nextInt();     
        Integer b = s.nextInt(); 
        Integer c = s.nextInt();                 // Reading 
temp=a;
a=b;
b=temp;
a*=c;
b+=c;
System.out.println(a+" "+b);
    }
}
Perl:
my $str = <STDIN>;
$str =~ s/^\s|\s+$//g;
my @a = split / /, $str;
 
# step 1
( $a[0], $a[1] ) = ( $a[1], $a[0] );
 
# step 2
$a[0] = $a[0] * $a[2];
 
# step 3
$a[1] = $a[1] + $a[2];
 
# step 4
print $a[0] . " " . $a[1];
Pascal:
var a,b,c:integer;
 
begin
readln(a,b,c);
b:=b*c;
a:=a+c;
write(b,' ',a);
end.


/*I/O:
In #1:
13 5 2
Out #1:
10 15
In #2:
123 456 23
Out #2:
10488 146
In #3:
43 34 20
Out #3:
680 63

*/