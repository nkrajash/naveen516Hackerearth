/*All Tracks  --> Basic Programming -->  Input/Output -->   Basics of Input/Output   --> Problem --> Back to School
Tag(s): No tags
In our school days, all of us have enjoyed the Games period. Raghav loves to play cricket and is Captain of his team. 
He always wanted to win all cricket matches. But only one last Games period is left in school now. After that he will pass out from school.

So, this match is very important to him. He does not want to lose it. So he has done a lot of planning to make sure his teams wins. 
He is worried about only one opponent - Jatin, who is very good batsman.

Raghav has figured out 3 types of bowling techniques, that could be most beneficial for dismissing Jatin. He has given points to each of the 3 techniques.
You need to tell him which is the maximum point value, so that Raghav can select best technique.

3 numbers are given in input. Output the maximum of these numbers.

Input:
Three space separated integers.

Output:
Maximum integer value

SAMPLE INPUT 
8 6 1 
SAMPLE OUTPUT 
8

Explanation
Out of given numbers, 8 is maximum.

//C Solution:
#include<stdio.h>
#define MAX(a,b,c) (a>b?(a>c?a:c):(b>c?b:c))

int main()
{
	int a,b,c,l;
	scanf("%d %d %d",&a,&b,&c);
	l=MAX(a,b,c);
	printf("%d",l);
}


//R Solution:
input <- file('stdin')
lines <- readLines(input)
#print(lines[1],quote = F)
#print(typeof(lines[1]))
temp2 <- unlist(strsplit(lines, " "))
temp2 <- as.numeric(temp2)
temp2 <- max(temp2)
#print(as.numeric(temp2))
#print(lines[1])
cat(temp2)

*/

/*I/O:
In #1:
230 1425 4767
Out #1:
4767

In #2:
3659 3152 914
Out #2:
3659

In #3:
2316 6011 8825
Out #3:
8825

In #4:
8 6 1
Out #4:
8

*/

/*Best Submissions:
C:
#include <stdio.h>
#include <math.h>
int main(void)
{
    int q1,q2,q3, i;
    scanf("%d %d %d", &q1, &q2, &q3);
    i = fmax(q1, fmax(q2,q3));
    printf("%d", i);
    return 0;
}

C++:
#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a>b)
    {
        if(a>c)
        {
            cout<<a;
        }
        else
        {
            cout<<c;
        }
    }
    if(b>a)
    {
        if(b>c)
        {
            cout<<b;
        }
        else
        {
            cout<<c;
        }
    }
    return 0;
}


C++14:
// Write your code here
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,c,max1=0,max2=0;
    cin>>a>>b>>c;
    max1=max(a,b);
    max2=max(max1,c);
    cout<<max2;
}


C#:
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace BackToSchool
{
	class Program
	{
		//Maximum integer value
		static void Main(string[] args)
		{
			long[] arr = Array.ConvertAll(Console.ReadLine().Split(' '),t=>Convert.ToInt64(t));
			long result = arr.Max();
			Console.WriteLine(result);
		}
	}
}

Java:
import java.util.*;
public class schooldays1
{
    public static void main(String[]args)
    {
        Scanner in=new Scanner(System.in);
        int max=0;
        int[] arr=new int[3];
        for(int i=0;i<3;i++)
        {
            arr[i]=in.nextInt();
        if(max<arr[i])
        {
            max=arr[i];
        }
        }
        System.out.println(max);
    }}


Java 8:
import java.util.Scanner;
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static void main(String args[] ) throws Exception {
      //  Sample code to perform I/O:
      // Use either of these methods for input
      //
      //  //BufferedReader
      //  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      //  String name = br.readLine();                // Reading input from STDIN
      //  System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
      //
      //  //Scanner
      //  Scanner s = new Scanner(System.in);
      //  String name = s.nextLine();                 // Reading input from STDIN
      //  System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        int[] arr = new int[3]; 
		int max = 0;
		Scanner scan = new Scanner(System.in);
		for(int i =0;i<3;i++)
			arr[i] = scan.nextInt();
		
		if(arr[0]>arr[1] && arr[0]>arr[2])
			System.out.println(arr[0]);
		else if(arr[1]>arr[2] && arr[1]>arr[0])
			System.out.println(arr[1]);
		else
			System.out.println(arr[2]);
    }
}

Java(Node.js):
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
   input= input.split(' ').map(Number);
 
     console.log(Math.max.apply(null, input))       // Writing output to STDOUT
}

Perl:
@d = split " ",<STDIN>;
@m = sort { $a <=> $b } @d;
print(@m[-1]);

Python:
points = [int(x) for x in raw_input().split()]
print max(points)


Python 3:
i=3
l=input()
l=l.split(" ")
n=[]
for i in range(3):
    n.append(int(l[i]))
print(max(n))


Ruby:
=begin
# Sample code to perform I/O:
 
name = gets.chomp                # Reading input from STDIN
print "Hi, #{name}.\n"           # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
=end
 
# Write your code here
n=gets.split
n.map!(&:to_i)
puts n.max


*/
