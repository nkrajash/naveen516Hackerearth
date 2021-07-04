/* All Tracks -->Algorithms --> Searching --> Linear Search -->
Simple Search

Given a List of Distinct N number a1,a2,a3........an.Find The Position Of Number K In The Given List.

Input Format
First Line Take Input Value Of N.
Second Line Take Input N Space Separated Integer Value.
Third Line Take Input Value Of K.

Output Format
Position Of K In The Given List.

Constraints:
0 < N < 100001
0 < ai < 1010
0 < K < 1010

NOTE:
Array Indexing Starts From 0.

SAMPLE INPUT 
5
1 2 3 4 5
4
SAMPLE OUTPUT 
3

//My C solution:
#include <stdio.h>
#define N 100001

int main()
{
    int pos,A[N],n,num,k,i;
    scanf("%d",&n);
    k=-1;
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    scanf("%d",&num);
    for(i=0;i<n;i++){
        if(num==A[i]){
            k=i;
            break;
        }
    }
    printf("%d",k);
    return 0;
}

//My C++ solution:
#include <iostream>
using namespace std;
#define N 100001
 
int main()
{
    int pos,A[N],n,num,k,i;
    cin>>n;
    k=-1;
    for(i=0;i<n;i++)
        cin>>A[i];
    cin>>num;
    for(i=0;i<n;i++){
        if(num==A[i]){
            k=i;
            break;
        }
    }
    cout<<k;
    return 0;
}

//My Python solution:
A=[]
n=input()
num=0
k=-1
 
A = raw_input().split()
A = [int(x) for x in A]
    
num=input()
 
for i in range(0,n):
    if(num==A[i]):
        k=i
        break
 
print(k)

// Editorial:
Contributed by Santosh Kumar Shaw (devsks).

//@author Santosh Kumar Shaw (devsks)
//@quote "Code like there's no tommorow!"

#include <stdio.h>
#define ll long long
int main()
{
    ll n,x;
    scanf("%lli",&n);
    ll arr[n];
    for(int i=0;i<n;++i)
        scanf("%lli",&arr[i]);
    scanf("%lli",&x);

    for(int i=0;i<n;++i)
        if(arr[i]==x)
        {
            printf("%i",i);
            break;
        }
    return 0;
}

//I/O:
Input #1:
10
1 2 3 4 5 6 7 8 9 10
10
Output #1:
9
Input #2:
10
1 2 3 10 5 8 9 7 6 4
10
Output #2:
3
Input #3:
20
1 2 3 10 5 8 9 7 6 4 234521 87962 1234 3456 12345 9876 7894 2345 34 11
11
Output #3:
19
Input #4:
20
1 2 3 10 5 8 9 7 6 4 234521 87962 1234 3456 12345 9876 7894 2345 34 11
87962
Output #4:
11

*/


/*Best Submissions:
Bash:
read n
read string
read k
array=(${string// / })
for i in "${!array[@]}"
do
    if [ "${array[i]}" -eq "$k" ]
    then
        echo "$i"
        break
    fi
done

C:
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int main()
{
int i,n,k;
scanf("%d",&n);
int a[100];
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
scanf("%d",&k);
for(i=0;i<n;i++)
{
if(k==a[i])
{
printf("%d",i);
}
}
return 0;
}

C++:
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    int arr[n];
    int index=-1;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>m;
    for(int j=0;j<n;j++)
    if(arr[j]==m)
    index=j;
    cout<<index<<endl;
}

C++14:
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    int arr[n];
    int index=-1;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>m;
    for(int j=0;j<n;j++)
    if(arr[j]==m)
    index=j;
    cout<<index<<endl;
}

C#:
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
 
namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
 
 
            int n = int.Parse(Console.ReadLine());
            int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), e => int.Parse(e));
            int k = int.Parse(Console.ReadLine());
 
            Console.WriteLine(Array.IndexOf(a, k));
            
 
 
            Console.ReadLine();
        }
    }
}

Java:
// IMPORTANT: Multiple classes and nested static classes are supported
// uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;
//import for Scanner and other utility classes
import java.util.*;
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

class TestClass {
    public static void main(String args[] ) throws Exception {
        // Sample code to perform I/O:
        // Use either of these methods for input
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String name = br.readLine();                // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT

        //Scanner
        //Scanner s = new Scanner(System.in);
        //String name = s.nextLine();                 // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        // Write your code here
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int []arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        int index=0;
        int k= sc.nextInt();
        for(int i=0; i<n; i++){
            if(k==arr[i]){
                index=i;
            }
        }
        System.out.println(index);
 
    }
}

Java 8:
import java.util.Scanner;
import java.util.*;
 
class TestClass {
    public static void main(String[] args) throws Exception {
 
        Scanner in = new Scanner(System.in);
        int array_size = in.nextInt();
 
        ArrayList<Integer> arr_list = new ArrayList<>(array_size);
        
        for (int i = 0; i < array_size; i ++){
            arr_list.add(in.nextInt());
        }
 
        int elem_searched = in.nextInt();
 
        int len=arr_list.size();
 
        for(int i = 0 ; i < len ; i++){
            if(arr_list.get(i) == elem_searched){
                System.out.println(i);
 
            }
        }
 
 
    }
 
}

Java(Rhino):
// Below is a sample code to process input from STDIN.
// Equivalent in effect to the Java declaration import java.io.*;
importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new Scanner(System['in']);	
var T = sc.nextInt();
 
var t = [];
 
for(var i=0;i<T;i++){
    t[i] = sc.nextInt();
}
 
System.out.println(t.indexOf(sc.nextInt())+"");

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
    let splitInput = input.split('\n');
    let arrEle = splitInput[1].split(" ").map(arrTemp => parseInt(arrTemp, 10));
    let searchEle = Number(splitInput[2]);
    
    console.log(getElementIndex(arrEle, searchEle));
}
 
let getElementIndex = (arrEle, searchEle) => {
    return arrEle.indexOf(searchEle);
}


Pascal:
var i,n,k:longint;
a:array[1..1000] of longint;
begin
    readln(n);
    for i:=1 to n do
    read(a[i]);
    readln(k);
    for i:=1 to n do
    if k=a[i] then break;
    writeln(i-1);
end.



Perl:
chomp($num = <>);
chomp($value = <>);
chomp($req = <>);
@arr = split / /,$value;
if($num == @arr){
    for($i=0;$i<@arr;$i++){
        if($req == @arr[$i]){
            print "$i\n";
        }
    }
}

PHP:
<?php
 
//Read input from stdin and provide input before running code
//fscanf(STDIN, "%s\n", $name);
//echo "Hi, ".$name;
// 

$n = (int) fgets(STDIN);
$values = array_map('intval', explode(' ', fgets(STDIN)));
$k = (int) fgets(STDIN);
 
$flipped = array_flip($values);
 
echo $flipped[$k];
 
?>

Python:
'''
# Read input from stdin and provide input before running code
 
name = raw_input()
print 'Hi, %s.' % name
'''
 
n = input()
a = map(int, raw_input().split())
print a.index(input())


Python 3:
'''
# Sample code to perform I/O:
 
name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''
 
# Write your code here
n=int(input())
l=[]
str=input()
l=str.split(' ')
#print(l)
m=input()
print(l.index(m))

R:
con <- file('stdin', open = 'r')
stringToVector <- function(string){
    return (as.numeric(unlist(strsplit(string," "))))
}
inputs <- readLines(con)
input_value <- stringToVector(inputs[[1]])
search_element <- stringToVector(inputs[[3]])
input_element <- stringToVector(inputs[[2]])
 
index <- c()
for (i in 1:input_value){
    if(search_element %in% input_element[[i]]){
        index <- c(index,i)
    }
}
 
cat(index-1)

Ruby:
n=gets.chomp.to_i
array=gets.chomp
item=gets.chomp.to_i
array = array.split(' ').map(&:to_i)
puts array.index(item)



*/
