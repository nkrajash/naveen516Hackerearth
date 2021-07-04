/*All Tracks --> Python  --> Getting Started  --> Input and Output -->  Problem -->
Jadoo vs Koba
Jadoo, the space alien has challenged Koba to a friendly duel. He asks Koba to write a program to print out all numbers from 70 to 80. 
Knowing perfectly well how easy the problem is, the Jadoo adds his own twist to the challenge. He asks Koba to write the program without 
using a single number in his program and also restricts the character limit to 100.

Checker Code:

#include <iostream>
using namespace std;

int main() {
    char ch;
    int c,score;
    int flag = 0;
    while(scanf("%c",&ch)!=EOF)
    {
        if(ch >= '0' && ch <= '9')
        {   
            flag = 1;
            break;

        }
        else if(ch<=32) continue;
        else c++;   
    }
    if(flag == 1)
    {   cout<<0; return 0;}
    if(c <= 100)
    score = 100;
    else score= 50;
    cout<<score;
    return 0;
}
SAMPLE INPUT:
SAMPLE OUTPUT:
70
71
72
73
74
75
76
77
78
79
80
//My Python 2.7.6 Solution:
for i in range(ord('F'),ord('Q')):
    print(i)
	
*/

/*Editorial:
for i in range(ord('F'),ord('Q')):print(i)
*/

/*I/O:
In #1:
Out #1:
70
71
72
73
74
75
76
77
78
79
80
*/

/*Best Submissions:
C:
#include<stdio.h>
 int main()
{for(int i='F'; i!='Q';i++)printf("%d\n",i);}


C++:
#include<iostream>
int main(){char a='F';while(a!='Q')printf("%d\n",a++);}

C++14:
#include<iostream>
using namespace std;
int main(){
    for(char i = 'F'; i < 'Q'; i++)cout << (int)i << endl;
}

C#:
using System;
class t{
    static void Main(){
        for (char c = 'F';c<'Q';c++){
            Console.WriteLine((int)c);
        }
    }
}

Java:
class a
{
    public static void main(String args[])
    {
        for(char i='F';i<='P';i++)
        {
            int n=i;
            System.out.println(n);
        }
    }
}

Java8:
class TestClass{public static void main(String a[]){for(char i='F';i<'Q';++i)System.out.println((int)i);}}

Javascript(Node.js):
(function(){
"FGHIJKLMNOP".split('').forEach(alp => {console.log(alp.charCodeAt())});
})();

Pascal:
var i:byte;
 
begin
 
for i:=ord('F') to ord('P') do
writeln(i);
 
end.

Perl:
print ord, $/ for F..P;

PHP:
<?php
$a = ord("F");
$b = ord("Q");
 
for ($i=$a; $i<$b; $i++) { 
echo $i."\n";
}


Python:
a,b=len("abcdefghijk"),len("klmnoplkq")
for i in range(a):
print (b*b-a+i)

Pyhton 3:
1).ch=ord('F')
while ch<=ord('P'):
    print(ch)
    ch+=ord('B')-ord('A')

2).
for i in "FGHIJKLMNOP":
print(ord(i))


*/