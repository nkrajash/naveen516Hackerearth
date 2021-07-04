#include <iostream>
using namespace std;

#define N 1000

int main()
{
    int i,j,n,flag=0;
    
    cin>>n;
    
    for (i=2;i<=n;i++){
        for (j=2;j<=i/2;j++){
            if (i%j==0){
                flag=1;
                break;
            }
        }
        if (!flag)
            cout<<i<<" ";
        else
            flag=0;
    }
    return 0;
}


/* Best Submissions:
C:
#include<stdio.h>
int main()
{
	int i,j,flag,n;
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
	flag=0;
		for(j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
			
		}
			if(flag!=1)
			{
				printf("%d ",i);
		
			}
	}
return 0;
}

C++:
// Write your code here
#include <iostream>
#include <math.h>
using namespace std;
 
int main(void)
{
    int N;
    int primeCount;
    cin >> N;
    
   
        for (int i = 1; i < N; i++)
        {
            primeCount = 0;
            
            for (int j = 1; j <= i; j++)
            {
                if ( i % j == 0 )
                    primeCount++;
            }
            
            if (primeCount == 2)
                cout << i << " ";
        }
    
    
    return 0;
}

Java:
import java.util.Scanner;
class TestClass {
    public static void main(String args[] ) throws Exception {
        
         //Read input from stdin and provide input before running
        // Use either of these methods for input
 
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String line = br.readLine();
        //int N = Integer.parseInt(line);
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();
 
        for (int i = 2; i <= N; i++) {
            boolean flag=false;
           for(int j=2;j<=Math.sqrt(i);j++)
             {
               if(i%j ==0)
               {
                   flag=true;
                   break;
               }
             }
             if(flag==false)
             {
                 System.out.print(i+" ");
             }
        }
        
    }
}

Java 8:
//import for Scanner and other utility classes
import java.util.*;
import java.io.*;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        //Scanner
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();
 
        for (int num = 2; num < N; num++) {
 
            int temp;
        	boolean isPrime=true;
        	
        	for(int i=2;i<=num/2;i++)
        	{
                   temp=num%i;
        	   if(temp==0)
        	   {
        	      isPrime=false;
        	      break;
        	   }
        	}
        	
        	if(isPrime)
        	   System.out.print(num+ " ");
        	
        }
    }
}

JavaScript(Rhino):
importPackage(java.io);
importPackage(java.lang);
importPackage(java.util);
 
var sc = new Scanner(System['in']);
 
var n = sc.nextInt();
var listPrime = [];
 
function isPrime(x){
    if (x < 2){
        return false;
    } else if (x == 2) {
        return true;
    } else if (!(x % 2)) {
        return false;
    } else {
        for (var j = 3; j < x; j+= 2) {
            if (!(x % j)) {
                return false;
            }
        }
        return true;
    }
}
 
for (var i = 2; i <= n; i++) {
    if (isPrime(i)) {
        listPrime.push(i);
    } 
}
 
 
print(listPrime.join(' '));

JavaScript(Node.js):
function main(input) {
    //Enter your code here
    var primes = [];
    var number = parseInt(input)
    for(n=2; n < number; n++){
        if(isPrime(n)){
            primes.push(n)
        }
    }
    
    process.stdout.write(primes.join(" "));
}
 
function isPrime(num){
    for(i=2;i<num;i++){
        if(num%i === 0){
            return false
        }
    }
    
    return true
    
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
 

C++14:

#include <iostream>
#include <string>
 
using namespace std;
bool isPrime(int n){
  bool flag = true;
  if (n == 1){
      flag = false;
  }
  else{
      for (int i = 2; i <= n/2; i++){
        if (n % i == 0){
          flag = false;
          break;
        }
      }
  }
  return flag;
}
int main(){
  int n;
  cin >> n;
 
  for (int i = 1; i <= n; i++){
    if (isPrime(i)){
      cout << i << " ";
    }
  }
  cout << "\n";
}

C#:
using System; 
using System.Numerics;
class MyClass {
    static void Main(string[] args) {
            int N = Convert.ToInt32(Console.ReadLine());
            int k = 0;
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= i; j++)
                {
                    if (i % j == 0)
                        k++;
                }
 
                if (k == 2)
                    Console.Write("{0} ", i.ToString());
                k = 0;  
            }
    }
}

Python(Py 2.7.6):
'''
# Read input from stdin and provide input before running code
 
name = raw_input()
print 'Hi, %s.' % name
'''
t = int(raw_input())
lst = []
for num in range(2,t+1):
   # prime numbers are greater than 1
   if num > 1:
       for i in range(2,num):
           if (num % i) == 0:
               break
       else:
           lst.append(num)
str = ' '.join(str(a) for a in lst)
print str   

Python 3:
'''
# Sample code to perform I/O:
 
name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''
 
# Write your code here
i=j=2
flag=0
n=(int)(input())
for i in range (2,n):
    flag=0
    for j in range (2,i):
        if(i%j)==0:
            flag=1
            break
    if(flag==0):
        print(i, end =" ")

PHP:
<?php
 
//Read input from stdin and provide input before running code
 
//fscanf(STDIN, "%s\n", $name);
//echo "Hi, ".$name;

class primeNum{
    private $number_listt=[];
    function set_number($num)
    {
        array_push($this->number_listt, $num);
    }
    function print_arr(){
        foreach($this->number_listt as $val)
        {
            echo $val." ";
        }
    }
}
fscanf(STDIN, "%d\n", $N);
if($N>=1 || $N<=1000)
{
    $obj=new primeNum;
    for($i=2; $i<$N; $i++)
    {
        $p=0;
        for($j=2; $j<$i; $j++)
        {
            if($i%$j==0)
            {
                $p=1;
            }
        }
        if($p==0)
        $obj->set_number($i);
    }
    $obj->print_arr();
}

?>

Pascal:
var i,t:longint;
 
function prime(n:longint):byte;
var i,d:longint;
begin
	d:=0;
	for i:=1 to round(sqrt(n)) do
	if n mod i = 0 then d:=d+1;
	if d=1 then prime:=1 else prime:=0;
end;
 
begin
	readln(t);
	for i:=2 to t do
	if prime(i)=1 then write(i,' ');
end.

R:
is.prime1 <- function(num) {
  if (num == 2) {
    TRUE
  } else if (any(num %% 2:(num-1) == 0)) {
    FALSE
  } else { 
    TRUE
  }
}
n<-scan('stdin')
x<-1:n
is.prime1 <- Vectorize(is.prime1)
cat(x[is.prime1(x)])

Ruby:
@upper_bound = gets.chomp.to_i
2.upto(@upper_bound) do |num|
	@prime_flg = 0
	for i in 2..num
		if num % i == 0
			@prime_flg = @prime_flg + 1
		end
	end
	if @prime_flg == 1
		print "#{num} "
	end
end


VB:
Module Main
 
    Sub Main()
        Dim limite, num, primo As Integer
        num = 2
    
    limite = System.Console.ReadLine
    while num <= limite
        primo = 1
        for i As Integer = 2 To num/2
            if num mod i = 0 then
                primo = 0
                Exit for
            End if
        Next
        if primo = 1 then
            System.Console.Write(num.ToString + " ")
        End If
        num = num + 1
    End while
    End Sub
 
End Module


*/

