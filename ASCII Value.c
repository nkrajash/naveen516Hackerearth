/* All Tracks --> Algorithms --> String Algorithms --> Z Algorithm --> Problem-->
ASCII Value
Tag(s): Implementation, Very-Easy

Given a character C, print the ASCII value of that character.

Input:
First and only line in input contains a character C.

Output:
Print the ASCII value of the character C.

Constraints:
ASCII characters

SAMPLE INPUT 
b
SAMPLE OUTPUT 
98

My C Solution:
#include <stdio.h>

int main()
{
    char c;
    scanf("%c",&c);
    printf("%d",c);
    return 0;
}

My Python 2.7.6 solution:
'''
# Read input from stdin and provide input before running code
 
name = raw_input()
print 'Hi, %s.' % name
'''
 
c=raw_input()
if len(c) == 1:
    print ord(c)

*/

/*Editorial:

Author Solution by omar khaled abdelaziz abdelnabi
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    cin >> c;
    cout << (int) c;
    return 0;
}

*/

/* I/O:
In #1:
a
Out #1:
97
In #2:
Q
Out #2:
81
In #3:
z
Out #3:
122
In #4:
4
Out #4:
52
In #5:
/
Out #5:
47

*/


/* Best Submissions:
C:
#include<stdio.h>
int main()
{
    char c;
    scanf("%c",&c);
    printf("%d",c);
    return 0;
}

C++:
#include <iostream>
using namespace std;
 
int main()
{
	char ch;
    cin>>ch;
    cout<<(int)ch<<endl;
    return 0;
}


C++14:
// Write your code here
#include <iostream>
using namespace std;
int main(){
    int i;
    char c;
    cin>>c;
    i = c;
    cout<<i;
    return 0;
}


Java:
import java.util.Scanner;
class TestClass {
    public static void main(String args[] ) throws Exception {
        //Read input from stdin and provide input before running
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String line = br.readLine();
        //int N = Integer.parseInt(line);
        //for (int i = 0; i < N; i++) {
        //    System.out.println("hello world");
        //}

        Scanner scanner = new Scanner(System.in);
        int a = (int)scanner.next().charAt(0);
		System.out.println(a);
    }
}



Java 8:
import java.util.Scanner;
class TestClass {
        public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        System.out.println((int) input.charAt(0));
 
    }
}


C#:
using System; 
using System.Numerics;
class MyClass {
    static void Main(string[] args) {
        
        // Read input from stdin and provide input before running
      var line1 = Convert.ToChar( Console.ReadLine());
            Console.WriteLine((int)line1);
        Console.Read();
    }
}

Java(Rhino.js):
importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new Scanner(System['in']);
 
var input = sc.next();
input = input.charCodeAt(0);
System.out.println(input.toFixed(0));


Java(Node.js):
function main(str) {
	console.log(str.charCodeAt(0));
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
Program ASCII;
 
var
  x : char;
 
begin
  readln(x);
  writeln (ord(x));
end.


Python:
C = raw_input()
print ord(C)


Python 3:
c=input()
a=ord(c)
print(a)

R:
cat(strtoi(charToRaw(readLines("stdin",n = 1L, warn = FALSE)),16L))

Ruby:
c = gets
c = c.ord
print c


PHP:
<?php


//Read input from stdin and provide input before running code
//fscanf(STDIN, "%s\n", $name);
//echo "Hi, ".$name;


fscanf(STDIN, "%s", $ca);
$intca = ord($ca);
fprintf(STDOUT, $intca);
exit;
 
 
?>


Perl:
use strict;
 
 
# Read input from stdin and provide input before running code
 
# Echo input to output.
while(my $fred = <STDIN>) {
   # print $fred;
    print ord($fred);
}
#print 'Hello World!'


VB:
Module Main
 
    Sub Main()
        Dim c As Char
 
        c = Console.ReadLine()
        Console.WriteLine(Asc(c))
        Console.ReadKey()
    End Sub
 
End Module



*/