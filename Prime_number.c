/*All Tracks --> Algorithms  -->  String Algorithms  -->  String Searching -->  
Prime Number
Tag(s): Very-Easy
You are given an integer N. You need to print the series of all prime numbers till N.

Input Format:
The first and only line of the input contains a single integer N denoting the number till where you need to find the series of prime number.

Output Format:
Print the desired output in single line separated by spaces.

Constraints:
1<=N<=1000

SAMPLE INPUT
9

SAMPLE OUTPUT
2 3 5 7

#include <stdio.h>
#define N 1000

int main()
{
    int i,j,n,flag=0;
    
    scanf("%d",&n);
    for (i=2;i<=n;i++){
        for (j=2;j<=i/2;j++){
            if (i%j==0){
                flag=1;
                break;
            }
        }
        if (!flag)
            printf("%d ",i);
        else
            flag=0;
    }
    return 0;
}

*/

/*Editorial:

package main

import (
    "fmt"
    "math"
)

func PrimeSieve (n int) []int {
    status := make([]bool, n+1)
    for i := 0; i <= n; i++ {
        status[i] = true
    }

    limit := 1 + int(math.Sqrt(float64(n)))
    for i := 2; i < limit; i++ {
        if status[i] {
            for j := i*i; j <= n; j += i {
                status[j] = false
            }
        }
    }

    var primes []int
    for i := 2; i <= n; i++ {
        if status[i] {
            primes = append(primes, i)
        }
    }
    return primes
}

func main() {
    var n int
    fmt.Scanf("%d", &n)

    for _, prime := range PrimeSieve(n) {
        fmt.Printf("%d ", prime)
    }
    fmt.Printf("\n")
}

*/


/*
n=int(input())
for x in range(2,n):
flag=0
for y in range(2,x-1):
if (x%y == 0):
flag=1
if (flag==0):
print(x,"", end="")

*/

/*
import java.util.Scanner;

public class TestClass {

public static void main(String[] args) {

Scanner limit= new Scanner(System.in);
int count=limit.nextInt();

for(int i=2; i<count; i++) {

boolean isPrime=true;

for(int j=2; j< i; j++){

if(i%j==0){
isPrime =false;
break;
}
}
if(isPrime){
System.out.print(i +" ");
}
}

}
}

 2 votes  Reply  Message  Permalink
 shreekant2 Shreekant Sonar 2 years ago
public class PrimeNumber {

public static void main(String[] args) {

Scanner sc = new Scanner(System.in);
int input = sc.nextInt();

for (int k = 2; k <= input; k++) {
int counter = 0;
for (int i = 1; i <= k; i++) {
if ((k % i) == 0) {
counter++;
}
}
if (counter == 2) {
System.out.print(k + " ");
}
}
}
}

 1 vote  Reply  Message  Permalink
 Darshana_Charu Darshana_Charu 9 months ago
why counter==2?

 0 votes  Reply  Message  Permalink
 navin_13 Navin Ojha 6 months ago
because if the number is divisible by 1 and itself then only it is a prime number so total count if equals 2 then print that number

 0 votes  Reply  Message  Permalink
 rakeshkumarg2 Rakesh Kumar Gupta 2 years ago
import java.util.Scanner;

public class PrimeTest {
public static void main(String[] args) {
Scanner scan = new Scanner(System.in);
String string = scan.next();
int n = Integer.parseInt(string);
int isPrime;
for (int i = 2; i <= n; i++) {
/* Assume that the current number is Prime */
isPrime = 1;

/* Check if the current number i is prime or not */
for (int j = 2; j <= i / 2; j++) {
/*
* If i is divisible by any number other than 1 and self then it
* is not prime number
*/
if (i % j == 0) {
isPrime = 0;
break;
}
}

/* If the number is prime then print */
if (isPrime == 1) {
System.out.print(i + " ");
}

}
}
}

 1 vote  Reply  Message  Permalink
 devanshtiwari98 Devansh Tiwari a year ago
Why the same output

 1 vote  Reply  Message  Permalink
 sunny192 Sunny Kumar  Edited 2 years ago
#include <iostream>
#include <vector>
 
using namespace std;
 
int main(){
int n;
cin >> n;
vector <bool> A(n+1, true);
for(int i = 2;i*i <= n;i++)
if(A[i])
for(int j = i*i;j <= n;j += i)
A[j] = false;
for(int i = 2;i <= n;i++)
if(A[i])
cout << i << ' ';
}

 0 votes  Reply  Message  Permalink
 amanshu_kataria Amanshu Kataria 2 years ago
#include <iostream>
using namespace std;

int main()
{
int number;
bool flag;
cin>>number;
for(int i=2;i<number;i++)
{
flag=true;
for(int j=2;j<=i/2;j++)
{
if(i%j==0)
{
flag=false;
break;
}
}
if(flag==true)
cout<<i<<" ";
}
return 0;
}

 0 votes  Reply  Message  Permalink
 vivekcode2 The_Man_In_Blue 2 years ago
#include<stdio.h>
int main()
{
int i=2,j,N,flag;
scanf("%d",&N);
while(i<=N)
{ j=1;flag=0;
while(j<=(i/2))
{
if((i%j)==0)
{flag=flag+1;}
j++;
}
if(flag==1)
printf("%d",i);
i++;

}
return 0;
}

 0 votes  Reply  Message  Permalink
 talk2mehulnarang Mehul Narang 2 years ago
#include <stdio.h>

int prime (int x)
{
for(int k=2;k<=x/2;k++)
if(x%k==0)
return 0;
return 1; 
}
int main()
{
int n;
scanf("%d",&n);
if(n<1||n>1000)
return 0;
for (int i=2;i<n;i++)
{
if (prime(i))
printf("%d ",i);
}
return 0;
}

 0 votes  Reply  Message  Permalink
 himmel S.Mohammad Abdellahi 2 years ago
#include <iostream>
#include <math.h>
using namespace std;
void Eratosthenes_Sieve(int n)
{
bool *a;
a = new bool[n + 1];
cout << "2" << " ";
int sq = (int)sqrt(n);
for (int i = 3; i <= sq; i += 2)
if (a[i] != 1)
{
cout << i << " ";
for (int j = 2 * i; j <= n; j += i)
a[j] = 1;
}

int i = ((sq + 1) % 2) ? i = sq + 1 : i = sq + 2;
for (; i <= n; i += 2)
{
if (a[i] != 1)
cout << i << " ";
}
cout << endl;
}

int main()
{
int n;
cin >> n;
Eratosthenes_Sieve(n);

return 0;
}

 0 votes  Reply  Message  Permalink
 jeet.faldu6561 Jeet Faldu 2 years ago
#include<iostream>
using namespace std;

int main()
{

int i,h,j;
int flag;
int n=2;
cout<<" Enter a positive number";
cin>>h;
while(n < h)
{
flag = 0;
for(i=2;i<=n/2;i++)
{
if (n%i==0)
{
flag=1;
break;
}
}

if(flag==0)
cout<<n<<" ";

++n;
}

return 0;
}

 0 votes  Reply  Message  Permalink
 zain8 Zain Abbas 2 years ago
void main()
{
int N,i=2,j;
scanf("%d",&N);
while(i!=N)
{
if(i==2)
{
printf("%d ",i);
i++;
}
else
{
for(j=2;j<=(i/2);j++)
{
if(i%j==0)
break;
else
continue;
}
if(i%j==0)
i++;
else
{
printf("%d ",i);
i++;
}
}

}
}

 0 votes  Reply  Message  Permalink
 zodabest Zelalem Anley 2 years ago
using System; 
using System.Numerics;
class MyClass {
static void Main(string[] args) {

var input=Console.ReadLine().Trim();
int N=Int32.Parse(input);

for(int i=1;i<=N;i++)
{
if(primecheeker(i)==true)
{
Console.Write(" {0}",i);
}
}

}
public static bool primecheeker(int j)
{
int fact=0;
for(int k=1;k<=j;k++)
{
if(j%k==0)
{
fact++;
}
}
if(fact==2)
{
return true;
}
else 
{
return false;
}
}
}

 0 votes  Reply  Message  Permalink
 ivan.dev.job Ivan Romero Garcia 2 years ago
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;

/**
* PrimeNumber
*/
public class PrimeNumber {
public static void SieveOfSundaram(int n) throws IOException{
OutputStreamWriter osw = new OutputStreamWriter(System.out);
BufferedWriter bw = new BufferedWriter(osw);
int nNew = (n - 2) / 2;
boolean[] marked = new boolean[nNew + 1];
for (int i = 1; i <= nNew; i++)
for (int j = i; (i + j + 2 * i * j) <= nNew; j++)
marked[i + j + 2 * i * j] = true;

if (n > 2)
bw.append("2 ");

for (int i = 1; i <= nNew; i++) {
if (marked[i] == false) {
bw.append(String.valueOf(2 * i + 1));
bw.append(" ");
}
}
bw.newLine();
bw.flush();
bw.close();
}

public static void main(String[] args) throws IOException{
InputStreamReader isr = new InputStreamReader(System.in);
BufferedReader br = new BufferedReader(isr);
SieveOfSundaram(Integer.parseInt(br.readLine())); 
}
}

 0 votes  Reply  Message  Permalink
 yusuf.matrix2008 Mohammed Yusuf 2 years ago
require 'prime'
l = gets.chomp.to_i
puts Prime.each(l).each {|x| print "#{x} "}

 0 votes  Reply  Message  Permalink
 ykc.krishna Krishna Chaitanya Yalamanchili Ykc 2 years ago
class TestClass {
public static void main(String args[] ) throws Exception {

Scanner s=new Scanner(System.in);
int n=s.nextInt();
if(n>=2) System.out.print("2");
for(int i=3;i<=n;i=i+2) {
if(isPrime(i)) {
System.out.print(" "+i);
}
}

}

public static boolean isPrime(int n) {
if(n%2==0) return false;
for(int i=3;i<=Math.sqrt(n);i=i+2) {
if(n%i==0) return false;
}
return true;
}
}

 0 votes  Reply  Message  Permalink
 nikita284 Nikita Khandave 2 years ago
#include <iostream>
using namespace std;

int main()
{
int n,j;
cin>>n;
for(int i=2;i<=n;i++)
{
for( j=2;j<i;j++)
{
if(i%j==0)
break;
}
if(j==i)
printf("%d ",i);
}
return 0;
}

 0 votes  Reply  Message  Permalink
 anonymous_1998 Rudra Nandan Mishra 2 years ago
#include<stdio.h>

int main()
{
int i,j,f,n;

scanf("%d",&n);
for(i=1;i<=n;i++)
{
f=0;
for(j=1;j<=i;j++)
{
if(i%j==0)
f++;
}
if (f==2)
{
printf("%d",i);
printf(" ");
}
f=0;
}

return 0;
}

 0 votes  Reply  Message  Permalink
 th3proinformatique Bilal Elbouardi 2 years ago
#include <iostream>

using namespace std;

int isprime(int a){
bool flag=false;
for(int i=2;i<=a/2;i++)
{

if(a%i==0) {flag = true;break;}
}

return flag;

}

int main()
{

int n;
cin>>n;
for(int i=1;i<=n;i++){

if(isprime(i)==0 && i!=1) {cout<<i<<" ";}

}
return 0;
}

 0 votes  Reply  Message  Permalink
 hardevsandhu404 Hardev Singh 2 years ago
#include <stdio.h>
int main()
{ int n,i,isprime,j;
scanf("%d",&n);
for(i=2;i<=n;i++)
{
isprime=0;
for(j=2;j<=i/2;j++){
if(i%j==0){
isprime=1;
break;
}
}
if(isprime==0)
printf("%d ",i);
}
return 0;
}

 0 votes  Reply  Message  Permalink
 decoder1 Decoder Encoder 2 years ago
import math
n = int(input())
x=list()
for i in range(2,n+1):
flag = True
for j in range(2,math.floor(math.sqrt(i))+1):
# print(j)
if i%j==0:
flag=False
break
if flag == True:
x.append(i)
print(*x)

 0 votes  Reply  Message  Permalink
 abhishek2433 Abhishek Verma 2 years ago
#include <bits/stdc++.h>
using namespace std;

int main () 
{int n;
bool flag;
cin>> n;
for(int i=2;i<=n;++i)
{flag=true;
for(int j=2;j<=i/2;j++)
{
if(i%j==0)
{
flag=false;
break;
}

}
if(flag==true)
{ cout<< i << " ";}
}
return 0;
}

 0 votes  Reply  Message  Permalink
 manoharvinoothna vinoothna manohar a year ago
#include <stdio.h>
#include"math.h"
int prime(long int n){
if(n<=1)
return 0;
if(n==2||n==3)
return 1;
if(n%2==0||n%3==0)
return 0;
for(long int i=5;i<=sqrt(n);i+=2)
if(n%i==0)
return 0;
return 1;
}
int main()
{
int n,k;
scanf("%d",&n);
for(int i=2;i<n;i++){
k=prime(i);
if(k==1){
printf("%d ",i);
}
}
return 0;
}

 0 votes  Reply  Message  Permalink
 arup.shibai Arup Kumar Gupta a year ago
#include <bits/stdc++.h>
using namespace std;

int main()
{
int n;
cin >> n;
vector<bool> seive(n,true);
seive[0]=seive[1] = false;
for(int i = 2; i*i < n; i++ )
if(seive[i]){
for(int p = 2*i; p < n; p+=i)
seive[p] = false;
}
for(int i = 0; i < n; i++ )
if(seive[i])
cout << i << " ";

return 0;
}

 0 votes  Reply  Message  Permalink
 BindalRohit Rohit Kumar Bindal a year ago
#include<stdio.h>
void main()
{
int i,j,count=0,num;
scanf("%d",&num);
for(i=1;i<=num;i++)
{
count=0;
for(j=1;j<=i;j++)
{
if(i%j==0)
count++;
}
if(count==2)
printf("%d ",i);
}
}

 0 votes  Reply  Message  Permalink
 sakshiarya451 Sakshi Arya a year ago
#include<iostream>
using namespace std;
int main(){
int N,i,flag=0,num;
cin>>N;
for(num=2;num<=N;num++){
flag=0;
for(i=2;i<=num/2;i++){
if(num%i==0){
{
if(i==num){
continue;
}
else{
flag=1;
}
}
} 
}
if(flag==0)
cout<<num<<" ";
}
}

 0 votes  Reply  Message  Permalink
 chadad.mohamed Mohamed CHADAD a year ago
#include <bits/stdc++.h>
using namespace std;

vector<bool> seive(int n){
vector<bool> P(n+1,true);
P[0]=false; P[1]=false;
for(int p=2;p<n+1;p++){
for(int i=2*p;(P[p] & i<n+1);i+=p){
P[i]=false;
}
}
return P;
}

int main(){
int n;
cin>>n;
vector<bool> P;
P=seive(n);
for(int i =2;i<n+1;i++){
if (P[i]) cout<<i<<" ";
}
}

 0 votes  Reply  Message  Permalink
 me.rajneeshkumar rajneesh kumar a year ago
using System;

namespace ConsoleApp2 {
class Program {
static void Main(string[] args) 
{
int n =Convert.ToInt32(Console.ReadLine());
for (int i = 2; i < n; i++) {
if (isPrime(i)) {
Console.Write(i + " ");
}
}
}

static bool isPrime(int n)
{
int i = 2;
if (n == 2) {
return true;
}
while (i < n) {
if (n % i == 0) {
return false;
}
i++;
}
return true;
}
}
}

 0 votes  Reply  Message  Permalink
 zeel4 Zeel Mehta a year ago
can anybody please help me this code..?? is this logic right for the program asked?
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int N;
int count=0;
cin>>N;
for(int i=2;i<=N;i++)
{
for(int x=1;x<=i;x++)
{
int j;
j=i%x;
if(j==0)
{

count=count+1;
}
}
if(count==2)
cout<<i<<setw(2);
}
}

 0 votes  Reply  Message  Permalink
 uditgogoi12 Udit Gogoi  Edited 8 months ago
#include <iostream>
using namespace std;
int main() {
int sum=0,N;
cin>>N;
for(int i=2; i<=N; i++) {
sum=0;
for(int j =1; j<= 9 ; j++) {
if(i % j == 0) {
sum++;
} 
}
if(sum ==2) {
cout << i <<" ";
}
}

}

 0 votes  Reply  Message  Permalink
 pranjalgore Pranjal Gore 7 months ago
is there an o(n) solution?

 0 votes  Reply  Message  Permalink
 abhilesh2 Abhilesh Gupta 7 months ago
#include<stdio.h>
int main()
{
int i, prime,upper,lower, n;
scanf("%d %d", &lower,&upper);
for(n=lower+1; n<=upper; n++)
{ prime = 1;
for(i=2; i<n/2; i++)
if(n%i == 0)
{
prime = 0;
break;
}
if(prime)
printf("\t%d",n);
}
}
any one can tell me 
1 to 9 
input 
but output
2 3 4 5 7 
why 4 will be at the output
i m confused

 0 votes  Reply  Message  Permalink
 sowmiya182 Sowmiya Sankar 7 months ago
#include<iostream>
using namespace std;

int main()
{ 
int f =0,n;
cin>>n;
for(int i=2;i<=n;i++)
{
f=0;
for(int j=2;j<=i/2;j++)
{ 
if(i%j==0)
{ f=1;
break;
}
}

if (f==0)
cout<<i<<" ";
}
}

 0 votes  Reply  Message  Permalink
 pavan193 Pavan Singh 5 months ago
import java.util.Scanner;

public class Starting {

public static void main(String args[])
{
Scanner s = new Scanner(System.in);
int i1=s.nextInt();
int n,i,fact,j;

for(i=1; i<=i1; i++)
{
fact=0;
for(j=1;j<=i1;j++)
{
if(i%j==0)
fact++;
}
if(fact==2) {
System.out.print(i+" ");
}
}

}

}

 0 votes  Reply  Message  Permalink
 ajay1525 Ajay bairwa 4 months ago
#include <stdio.h>
int main()
{
int i,j,a,b;
scanf("%d",&a);
for(i=1;i<=a;i++)
{b=0;
for(j=1;j<=a;j++)
{
if(i%j==0)
b++;
}
{
if(b==2)

printf(" %d",i);

}

}

return 0;
}

this is correct code.

 0 votes  Reply  Message  Permalink
 zohak.rameez ZOHHAK RAMEEZ 4 months ago
Hi

 0 votes  Reply  Message  Permalink
 hamhammyham hippo.buddy 3 months ago
import java.util.*;

class TestClass {
public static void main(String args[] ) throws Exception {

Scanner s = new Scanner(System.in);
int N = s.nextInt(); 

int test = 1;

boolean loop = true;

while(test < N){
boolean prime = true;
if(test == 1){
prime = false;
}
for(int i = 2; i < test; i++){
if(test % i == 0){
prime = false;
}
}
if(prime == true){
System.out.print(test + " ");
}
test++;
}

}
}

 0 votes  Reply  Message  Permalink
 nab Nab Deuri 3 months ago
#include <iostream>
using namespace std;
int main()
{
int count = 0, num;
cin >> num;
for (int i = 2; i < num; i++)
{
for (int j = 2; j < num; j++)
{
if (i % j == 0)
count++;
}
if (count == 1)
cout << i << " ";
count = 0;
}
return 0;
}

 0 votes  Reply  Message  Permalink
 ajaykr250 AJAY KUMAR 2 months ago
#include<stdio.h>
int main()
{
int n,k,i,j;
printf("Enter the limit ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
k=0;
for(j=1;j<=i;j++)
if(i%j==0)
k++;
if(k==2)
printf("%d ",i);

}
return 0;
}

 0 votes  Reply  Message  Permalink
 himanshu2078 Himanshu Prakash 2 months ago
#include<stdio.h>
void main()
{
int n,i,fact,j;
scanf("%d",&n);
for(i=1; i<=n; i++)
{
fact=0;
for(j=1; j<=n; j++)
{
if(i%j==0)
fact++;
}
if(fact==2)
printf("%d " ,i);
}

}

 0 votes  Reply  Message  Permalink
 vikash657 vikash kumar a month ago
n=int(input())
for x in range(2,n):
flag=0
for y in range(2,x-1):
if (x%y == 0):
flag=1
if (flag==0):
print(x,"", end="")

 0 votes  Reply  Message  Permalink
 iamsid2 Siddhant Mund 24 days ago
n = int(input())
for i in range(2,n):
cnt = 0
for j in range(1,i):
if(i%j==0):
cnt+=1;
if(cnt<2):
print(i,end=" ")

*/
