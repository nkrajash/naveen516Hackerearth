/* All Tracks-->Basic Programming-->Input/Output-->Basics of Input/Output-->Problem
Book of Potion making
Tag(s): Easy
Harry wants to find Voldemort's potion making book but he is confused about how to get it.

The book has a special ISBN(International Standard Book Number) which is  unique numeric book identifier only for Voldemort's book printed on it. 
The ISBN is based upon a 10-digit code. The ISBN is valid if:1xdigit1 + 2xdigit2 + 3xdigit3 + 4xdigit4 + 5xdigit5 + 6xdigit6 + 7xdigit7 + 8xdigit8 + 9xdigit9 + 10xdigit10 
is divisible by 11.Help Harry to find the book!
Input:
Input the ISBN code as a 10-digit integer.

Output:
If the ISBN is not a 10-digit integer, output the message “Illegal ISBN” and terminate the program.
If the number is 10-digit, extract the digits of the number and compute the sum as explained in the explanation.
If the sum is divisible by 11, output the message, “Legal ISBN”. If the sum is not divisible by 11, output the message, “Illegal ISBN”.

SAMPLE INPUT
1401601499
SAMPLE OUTPUT
Legal ISBN

Explanation:
For an ISBN 1401601499
Sum=1×1 + 2×4 + 3×0 + 4×1 + 5×6 + 6×0 + 7×1 + 8×4 + 9×9 + 10×9 = 253 which is divisible by 11.

//My C Solution:
#include <stdio.h>

int main(){
    int i, ISBNnum = 0,flag=0;
    char str[10];
    scanf("%s",str);
    if((strlen(str)!=10))  // For all cases >10 and <10 covered
        printf("Illegal ISBN");
    else{
        for(i=0;i<10;i++)
            ISBNnum +=((i+1)*str[i]);
        printf(((ISBNnum%11) == 0)?"Legal ISBN":"Illegal ISBN");
    }
    return 0;
}
*/

/*Editorial:
Author Solution by Kanishk Gupta
import java.io.*;
class ISBN {
public static void main(String args[])throws IOException
{ BufferedReader sc=new BufferedReader(new InputStreamReader(System.in));
   
        long isbnInteger =Long.parseLong(sc.readLine());
        String isbn = isbnInteger + "";
        int l=isbn.length();
if (l != 10) {
            System.out.println("Illegal ISBN");
        } else {
            int sum = 0;
            for (int i = 0; i < l; i++) {
                int digit = Integer.parseInt(isbn.charAt(i) + "");
                sum = sum + (digit * (i + 1));
            }
            if (sum % 11 == 0) {
                System.out.println("Legal ISBN");
            } else {
                System.out.println("Illegal ISBN");
            }
        }
    }
}
Author Java Solution:
import java.util.Scanner;
public class TestClass {
public static void main(String args[] ) throws Exception {
Scanner scanner = new Scanner(System.in);
long n = scanner.nextLong();
if(n <= 0){
System.out.print("Illegal ISBN");
return;
}
if(String.valueOf(n).length() != 10){
System.out.print("Illegal ISBN");
return;
}
long sum = 0;
long cnt = 10;
while(n > 0){
long mod = n % 10;
sum+= mod * cnt;
n/= 10;
cnt--;
}
System.out.println(sum % 11 == 0 ? "Legal ISBN" : "Illegal ISBN");


Python Solution:
sum = 0;
data = input()
if(len(data)!=10):
print("Illegal ISBN")
exit()
else:
for i in range(len(data)):
sum += (i+1)*int(data[i])

if sum%11 == 0:
print('Legal ISBN')
else:
print("Illegal ISBN")

C++ Solution:
#include<iostream>
using namespace std;
main()
{
long long int n,k,sum=0;
cin>>n;
int j=10;
while(n!=0)
{
k=n%10;
sum=sum+(k*j);
j--;
n=n/10;
}
//cout<<j<<endl;
if(j!=0)
{
cout<<"Illegal ISBN"<<endl;
}
else
{
if((sum%11)==0)
cout<<"Legal ISBN"<<endl;
else
{
cout<<"Illegal ISBN"<<endl;
}
}
}

*/


/*I/O:
Input #1:
1401601499
Output #1:
Legal ISBN
Input #2:
102356412345
Output #2:
Illegal ISBN
Input #3:
102569
Output #3:
Illegal ISBN
Input #4:
152569012
Output #4:
Illegal ISBN
Input #5:
0764526413
Output #5:
Legal ISBN
*/

/*Best Submissions:
C:
#include <stdio.h>
 
int main(){
	long long int num;
	int mult=10,result=0;
	scanf("%lli", &num);             			// Reading input from STDIN
	while(num>0){
	    result+=(num%10)*mult;
	    num/=10;
	    mult--;
	} 
	if(result%11==0)
	    printf("Legal ISBN");
	else
	    printf("Illegal ISBN");// Writing output to STDOUT
}

C++:
#include <iostream>
 
using namespace std;
 
int main() {
	int i, num, x=0;
	cin >> num;									
	int box=num;
	
	for( i=0;box!=0;i++ )
	{
	    box=box/10;
	}
	
	if(i!=10)
	{
	    cout<<"Illegal ISBN";
	}
	
	
	else
	{
	    for(i=10;i>0;i--)
	    {
	        box=num%10;
	        box=box*i;
	        x=x+box;
	        num=num/10;
	    }
	    
	    if(x%11==0)
	    {
	        cout<<"Legal ISBN";
	    }
	    else
	     cout<<"Illegal ISBN";
	    
	    
	    
	    
	    
	    
	    
	}
	
}

C++14:
#include <iostream>
#include<stdlib.h>
using namespace std;
int main() {
	long int num,sum=0,t;
	int i ,n,r;
    cin>>num;	
	t=num;
    for(i=0;t!=0;i++)
    {
       t=t/10;
    }
    
    if(i!=10)
    {   cout<<"Illegal ISBN";
        exit (0);
    }
    for(;i>0;i--)
    {r=num%10;
        sum+=i*r;
        num=num/10;
    }
    
    
    if(sum%11==0)
   cout<<"Legal ISBN";
    else
   cout<<"Illegal ISBN";
    
}


C#:
using System;
 
class Program
{
    static void Main(string[] arg)
        {
            string Cadena = Console.ReadLine();
            char[] newCadena = Cadena.ToCharArray();
            string[] Cadenas = new string[newCadena.Length];
            int[] Nums = new int[newCadena.Length];
            int sum = 0;
            for (int i = 0; i < newCadena.Length; i++)
            {
                Cadenas[i] = newCadena[i].ToString();
                Nums[i] = int.Parse(Cadenas[i]);
                sum = sum + (i + 1) * (Nums[i]);
            }
 
            if (sum % 11 == 0)
            {
                Console.WriteLine("Legal ISBN");
            }
            else Console.WriteLine("Illegal ISBN");
        }
}

Java:
import java.util.Scanner;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        
        //Scanner
        Scanner s = new Scanner(System.in);
        String input_isbn = s.nextLine();                 // Reading input from STDIN
        
        int multiplier = 1;
        int sum=0;
        if(input_isbn.length() ==10){
            for(int i=0;i<10;i++){
                sum = sum + (input_isbn.charAt(i) * multiplier++);
            }
            if(sum%11 ==0){
                System.out.println("Legal ISBN");
            }else{
                System.out.println("Illegal ISBN");
            }
        }else{
            System.out.println("Illegal ISBN");
        }
    }
}


Java8:
public class isbn {
 
    public static void main(String[] args) {
        java.util.Scanner s = new java.util.Scanner(System.in);
        String number = s.next();
        int sum = 0;
        if (number.length() != 10) {
            System.out.println("Illegal ISBN");
            System.exit(0);
        }
        for (int i = 0; i < 10; i++) {
            sum += (number.charAt(i) - 48) * (i + 1);
        }
        if (sum % 11 == 0)
            System.out.println("Legal ISBN");
        else
            System.out.println("Illegal ISBN");
        s.close();
    }
}

Pascal:
Program BookofPotionmaking;
const nmin=1000000000; nmax=9999999999;
var ISBN,d,t:int64; m:longint;
begin   //assign(input,'bookofpotionmaking.inp'); reset(input);
        //assign(output,'bookofpotionmaking.out'); rewrite(output);
        readln(ISBN);
        t:=0; m:=1; d:=1000000000;
        if (ISBN<nmin) or (ISBN>nmax) then writeln('Illegal ISBN')
        else begin
             while ISBN>0 do
                begin    t:=t+m*(ISBN div d);
                         ISBN:=ISBN-d*(ISBN div d);
                         d:=d div 10;
                         inc(m);
                end;
             if t mod 11=0 then writeln('Legal ISBN')
             else writeln('Illegal ISBN');
             end;
        //close(input); close(output);
end.

Python:
'''
# Sample code to perform I/O:
 
name = raw_input()          # Reading input from STDIN
print 'Hi, %s.' % name      # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''
 
# Write your code here
isbn=raw_input()
sum=0
if len(isbn)==10:
    
    for i in range(0,len(isbn)):
        sum=((i+1)*int(isbn[i])) +sum
    if sum%11==0:
        print "Legal ISBN"
    else:
        print "Illegal ISBN"
else:
    print "Illegal ISBN"

Python 3:
n=input()
sum=0
if len(n)!=10:
    exit(print("Illegal ISBN"))
for i in range(len(n)):
    sum+=int(n[i])*(i+1)
if sum%11==0:
    print("Legal ISBN")
else:
    print("Illegal ISBN")

Pascal:
Program BookofPotionmaking;
const nmin=1000000000; nmax=9999999999;
var ISBN,d,t:int64; m:longint;
begin   //assign(input,'bookofpotionmaking.inp'); reset(input);
        //assign(output,'bookofpotionmaking.out'); rewrite(output);
        readln(ISBN);
        t:=0; m:=1; d:=1000000000;
        if (ISBN<nmin) or (ISBN>nmax) then writeln('Illegal ISBN')
        else begin
             while ISBN>0 do
                begin    t:=t+m*(ISBN div d);
                         ISBN:=ISBN-d*(ISBN div d);
                         d:=d div 10;
                         inc(m);
                end;
             if t mod 11=0 then writeln('Legal ISBN')
             else writeln('Illegal ISBN');
             end;
        //close(input); close(output);
end.

Ruby:
=begin
# Sample code to perform I/O:
 
name = gets.chomp                # Reading input from STDIN
print "Hi, #{name}.\n"           # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
=end
 
# Write your code here
number = gets.chomp
sum = 0
number.split("").each_with_index do |n, i|
    sum = sum + n.to_i * (i + 1)
end
if sum % 11 == 0
    puts "Legal ISBN"
else
    puts "Illegal ISBN"
end

	
PHP:
<?php
 
$inputString = (string)trim(fgets(STDIN));
 
$inputArray = explode($inputString);
 
$sum = 0;
 
for($i = 0; $i < strlen($inputString); $i++) {
    
 $sum = $sum +  (($i+1) * (int)($inputString[$i]));  
 
// echo $sum . "\n";
 
}
 
if($sum % 11 === 0) {
    
    echo 'Legal ISBN';
    
} else {
    
    echo 'Illegal ISBN';
    
}

*/

