/*All Tracks  -->  Basic Programming  -->  Input/Output  -->   Basics of Input/Output 
 Ladderophilia
Tag(s): Easy

Aditya is fond of ladders. Everyday he goes through pictures of ladders online but unfortunately today he ran out of ladder pictures online. 
Write a program to print “ladder with N steps”, which he can use to get his daily dose of ladder love.

INPUT:
Input contains integer N, the number of steps in the ladder

OUTPUT:

Print the ladder with the gap between two side rails being 3 spaces(“   “).

Check the sample output for format of printing the ladder.

CONSTRAINTS:

1<=N<=40

SAMPLE INPUT 
4

SAMPLE OUTPUT 

*   *
*   *
*****
*   *
*   *
*****
*   *
*   *
*****
*   *
*   *
*****
*   *
*   *



// Write your code here
#include <stdio.h>
 
int main(){
    int lad,n,i;
 
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("*   *\n");
        printf("*   *\n");
        printf("*****\n");
    }
    printf("*   *\n");
    printf("*   *\n");
    return 0;
}

//Python solution
n=int(input(""))

print("* *")
for i in range (n):
-	print("* *")
-	print("*****")
-	print("* *")

print("* *")


*/


//Cpp solution
/*
#include<iostream>
using namespace std;
int main()
{
int n,i,j,k;
cin>>n;
for(i=1;i<=((n*3)+2);i++)
{
for(j=1;j<=5;j++)
{

{

if(j==1||j==5)
{
cout<<"*";
}


else if ((i%3==0)&&(j!=1&&j!=(n+1)))

{

cout<<"*";
}


else
{
cout<<" ";
}
}


}

cout<<"\n";

}
return 0;

}
*/

/*Best Submissions:
C:
#include<stdio.h>
#include<stdlib.h>
int main()
{
int i;
scanf("%d\n",&i);
printf("*   *\n");
printf("*   *\n");
while(i--)
{
    printf("*****\n");
    printf("*   *\n");
    printf("*   *\n");
}
 return 0;   
}
C++:
#include<iostream>
using namespace std;
int main()
{
 short n;
 cin>>n;
 while(n--)
 {
  cout<<"*   *\n";
  cout<<"*   *\n";
  cout<<"*****\n";
 }
 cout<<"*   *\n";
 cout<<"*   *\n";
 return 0;
}

C++14:
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	
	int count=1,m=0;
	int loop=0;
	for(int x=0;x<n;x++)
	{
		if(loop==0)
		{
			for(int i=0;i<5;i++)
				{
					for(int j=0;j<5;j++)
						{
							if(count==1 || count==5)
								{
									cout<<"*";
								}
							else if(m==2)
							{
								cout<<"*";
							}
							else
							{
								cout<<" ";	
							}
							count++;
						}
		
					count=1;
					if(m==3)
					m=0;
					m++;
					cout<<endl;
				}
				loop=1;
		}
		else
		{
			for(int i=0;i<3;i++)
				{
					for(int j=0;j<5;j++)
						{
							if(count==1 || count==5)
								{
									cout<<"*";
								}
							else if(m==2)
							{
								cout<<"*";
							}
							else
							{
								cout<<" ";	
							}
							count++;
						}
		
					count=1;
					if(m==3)
					m=0;
					m++;
					cout<<endl;
				}
		}	
	
	}
	return 0;
}

C#:
// Write your code here
using System;
 
class Program
{
    static void Main(String[] args)
    {
        int n=Convert.ToInt32(Console.ReadLine());
        for(int i=0;i<n;i++)
        {
            for(int k=0;k<2;k++)
            {
            for(int m=0;m<5;m++)
            {
                if(m==0 || m==4)
                Console.Write("*");
                else
                Console.Write(" ");
                
            }
            Console.WriteLine("");
            }
            for(int j=0;j<5;j++)
            {
                Console.Write("*");
            }
            Console.WriteLine("");
        }
        for(int k=0;k<2;k++)
        {
            for(int m=0;m<5;m++)
            {
                if(m==0 || m==4)
                Console.Write("*");
                else
                Console.Write(" ");
            
            }
            Console.WriteLine("");
        }
    }
}

Java:
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
//import for Scanner and other utility classes
import java.util.*;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
    Scanner reader = new Scanner(System.in);
        int N = reader.nextInt();
        int steps = (N*2)+(N+2);
 
 
        for(int i=1; i<=steps; i++)
        {
            for(int j=1; j<=5; j++)
            {
                if(i%3==0 && i!=0)
                {
                    System.out.print("*");
 
                }
                else if(j==1 || j==5)
                {
                    System.out.print("*");
                }
                else
                {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
 
    }
}

Java8:
import java.util.Scanner;
class HackerEarthBP1
{
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		for(int i=0;i<(n-1)*6+11;i++)
		{
			for(int j=0;j<5;j++)
			{
				if(i%2!=0)
					if(j==0 || j==4)
						System.out.print("*");
					else
						if((i+1)%6==0)
							System.out.print("*");
						else
							System.out.print(" ");
				//if(j==1||j==2||j==3)
					
			}
			System.out.print("\n");
		}
	}
}

Javascript(Node.js):
// Sample code to perform I/O:
 
//process.stdin.resume();
//process.stdin.setEncoding("utf-8");
//var stdin_input = "";
 
//process.stdin.on("data", function (input) {
//    stdin_input += input;                               // Reading input from STDIN
//});
 
//process.stdin.on("end", function () {
//   main(stdin_input);
//});
 
//function main(input) {
//    process.stdout.write("Hi, " + input + ".\n");       // Writing output to STDOUT
//}
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
// Write your code here
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
    let len = +input;
    const lad = `*   * \n*   *`;
    let final = lad;
    let i = 0;
 
    while(i < len) {
        final = final + '\n' + '*****' + '\n' + lad;
        i++;
    }
    console.log(final)
}

Perl:
=comment
use feature say;
# Sample code to perform I/O:
 
my $name = <STDIN>;             # Reading input from STDIN
print "Hi, $name.\n";           # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
=cut
 
# Write your code here
my $n= <STDIN>;
my $big = qq{*****};
my $hand = qq{*   *};
for ($i=0;$i<$n;$i++){
print "$hand \n";
print "$hand \n";
print "$big \n";
    }
print "$hand \n";
print "$hand \n";


PHP:
<?php
fscanf(STDIN, "%d\n", $n);           // Reading input from STDIN
for($i=0; $i<=$n;$i++){
    echo "*   *\n";
    echo "*   *\n";
    if($i<$n){
        echo "*****\n";
    }
}
 
 
?>

Python:
'''
# Sample code to perform I/O:
 
name = raw_input()          # Reading input from STDIN
print 'Hi, %s.' % name      # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''
 
# Write your code here
n=input()
for i in range (n):
    print "*   *"
    print "*   *"
    print "*****"
print "*   *"
print "*   *"

Python 3:
'''
# Sample code to perform I/O:
 
height = input()                  # Reading input from STD
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''
 
# Write your code here
height=int(input())
 
def legs():
    for i in range(5):
        if(i ==1 or i==3):
            print("*   *")
 
def rails():
    print("*****")
 
def ladder(height):
    legs()
    for k in range(height):
        rails()
        legs()
        
ladder(height)

R(Rscript):
n<- scan('stdin',what=integer(),quiet =T)
for(i in 1:(((n+1)*3)-1)){
    if(i %% 3 ==0){
        cat("*****","\n")
    } else{
        cat("*   *","\n")
    }
}

Ruby:
n=gets.chomp.to_i
puts "*   *"
puts "*   *"
n.times do
    puts "*****"
    puts "*   *"
    puts "*   *"
end

*/