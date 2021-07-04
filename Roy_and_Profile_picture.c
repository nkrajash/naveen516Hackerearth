/*All Tracks --->   Basic Programming  --->   Input/Output  --->   Basics of Input/Output --->   Problem --->  
Roy and Profile Picture
Tag(s): Ad-Hoc, Basic Programming, Implementation, Very-Easy

Roy wants to change his profile picture on Facebook. Now Facebook has some restriction over the dimension of picture that we can upload.
Minimum dimension of the picture can be L x L, where L is the length of the side of square.

Now Roy has N photos of various dimensions.
Dimension of a photo is denoted as W x H
where W - width of the photo and H - Height of the photo

When any photo is uploaded following events may occur:

[1] If any of the width or height is less than L, user is prompted to upload another one. Print "UPLOAD ANOTHER" in this case.
[2] If width and height, both are large enough and
(a) if the photo is already square then it is accepted. Print "ACCEPTED" in this case.
(b) else user is prompted to crop it. Print "CROP IT" in this case.

(quotes are only for clarification)

Given L, N, W and H as input, print appropriate text as output.

Input:
First line contains L.
Second line contains N, number of photos.
Following N lines each contains two space separated integers W and H.

Output:
Print appropriate text for each photo in a new line.

Constraints:
1 <= L,W,H <= 10000
1 <= N <= 1000 

SAMPLE INPUT

180
3
640 480
120 300
180 180

SAMPLE OUTPUT

CROP IT
UPLOAD ANOTHER
ACCEPTED


#include <stdio.h>

int main()
{
    int L,W,H,nphotos,i;
    char *msg[]={"CROP IT","UPLOAD ANOTHER","ACCEPTED"};
    
    scanf("%d",&L);
    scanf("%d",&nphotos);

    for(i=0;i<nphotos;i++){
        scanf("%d",&W);
        scanf("%d",&H);
        if((W<L) || (H<L))
            printf("%s\n",msg[1]);
        else{
            if((W==L==H) || (W==H))
                printf("%s\n",msg[2]);
            else
                printf("%s\n",msg[0]);
        }
    }
    return 0;
}

*/


/* Best Submissions:
Bash:
#! /bin/bash
# https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/roy-and-profile-picture/
read L;
read N;
while [ $N -ge 1 ]
do
    read W H;
    if [ $W -lt $L ] || [ $H -lt $L ]; then
        echo "UPLOAD ANOTHER";
    else
        if [ $W == $H ]; then
            echo "ACCEPTED";
        else
            echo "CROP IT";
        fi
    fi
    N=$(($N-1));
done

C:
#include <stdio.h>
 
int main()
{
    int l, n, w, h;
    scanf("%d", &l);
    scanf("%d", &n);
    while(n--)
    {
    	scanf("%d%d", &w, &h);
    	if (w < l || h < l) printf("UPLOAD ANOTHER\n");
    	else if (w == h) printf("ACCEPTED\n");
    	else printf("CROP IT\n");
    }
    return 0;
}

C++:
#include<iostream>
using namespace std;
int main()
{
	long long int v,l,n,w,h,i;
	cin>>l;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>w;
		cin>>h;
		if(w>=l&&h>=l)
		{if(w==h)
		cout<<"ACCEPTED"<<endl;
		else
		cout<<"CROP IT"<<endl;}
		else if(w<l||h<l)
		cout<<"UPLOAD ANOTHER"<<endl;
	}
 
 
	return 0;
}

C++14:
#include <iostream>
using namespace std;
 
void check(int l,int w,int h){
    if((w<l)||(h<l))
    {
        cout<<"UPLOAD ANOTHER\n";
        return;
    }
    if(w==h){
        cout<<"ACCEPTED\n";
        return;
    }
    cout<<"CROP IT\n";
    return;
}
int main()
{
    int L,n;
    cin>>L>>n;
    for(int i=0;i<n;i++){
        int W,H;
        cin>>W>>H;
        check(L,W,H);
    }
}

C#:
using System; 
using System.Numerics;
class MyClass {
    static void Main(string[] args) {
    int sz = Convert.ToInt32(Console.ReadLine());
            int ct = Convert.ToInt32(Console.ReadLine());
            for(int i = 0; i<ct;i++)
            {
                string[] str = Console.ReadLine().Split(' ');
                int i1 = Convert.ToInt32(str[0]);
                int i2 = Convert.ToInt32(str[1]);
                if(i1<sz||i2<sz)
                    Console.WriteLine("UPLOAD ANOTHER");
                else if(i1==i2&&i1==sz)
                    Console.WriteLine("ACCEPTED");
                    else if (i1 == i2 && ((i1> sz)||(i2>sz)))
                    Console.WriteLine("ACCEPTED");
                else if (i1>sz||i2>sz)
                    Console.WriteLine("CROP IT");
            }
    }
}

Java:
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
class Test2 {
public static void main(String args[] ) throws Exception {
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int L=Integer.parseInt(br.readLine());
int N=Integer.parseInt(br.readLine());
for(int i=0;i<N;i++)
{
String s=br.readLine();
 
int j=s.indexOf(" ");
char w[]=new char[j];
s.getChars(0,j,w,0);
 
 
char h[]=new char[s.length()-j-1];
s.getChars(j+1, s.length(), h, 0);
String s1=new String(w);
 
String s2=new String(h);
 
int W=Integer.parseInt(s1);
int H=Integer.parseInt(s2);
 
if(W<L||H<L)
System.out.println("UPLOAD ANOTHER");
else
{
if(W==H)
System.out.println("ACCEPTED");
else
System.out.println("CROP IT");
}
}
 
}
}

Java 8:
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
		try{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	        String line = br.readLine();
    	    int L = Integer.parseInt(line);
			line = br.readLine();
    	    int N = Integer.parseInt(line);
			int X[][]=new int[N][2];
			for(int i=0;i<N;i++){
				String input=br.readLine();
				String[] tokens = input.split(" ");
				X[i][0]=Integer.parseInt(tokens[0]);
				X[i][1]=Integer.parseInt(tokens[1]);	
			}
			for(int i=0;i<N;i++){
				if(X[i][0]<L||X[i][1]<L){
					System.out.println("UPLOAD ANOTHER");
				}
				else if(X[i][0]>=L&&X[i][1]>=L){
					if(X[i][0]==X[i][1])
						System.out.println("ACCEPTED");
					else
						System.out.println("CROP IT");
				}
			}
		}
		catch(Exception e){
			System.out.println(e);
		}
        
        
 
    }
}

Pascal:
var l,a,b,n:longint;
 
procedure xuli(a,b:longint);
begin
    if (a<l) then writeln('UPLOAD ANOTHER')
    else 
        begin
            if b<l then writeln('UPLOAD ANOTHER')
            else
                begin
                    if a=l then
                        begin
                            if b=l then writeln('ACCEPTED');
                            if b>l then writeln('CROP IT');
                        end
                    else 
                        begin
                            if a<>b then writeln('CROP IT') else writeln('ACCEPTED');
                        END;
                end;
        end;
end;
 
procedure nhap;
var i:longint;
begin
    readln(l);
    readln(n);
    for i:=1 to n do 
        begin
            readln(a,b);
            xuli(a,b);
        end;
end;
 
begin
    nhap;
end.

Perl:
use strict;
 
my $l=<STDIN>;
my $n=<STDIN>;
my $i=0;
while($i<$n) {
    my $s=<STDIN>;
    my @a=split(" ",$s);
    my $w=$a[0];
    my $h=$a[1];
    if($h<$l || $w<$l)
    	{
    		print "UPLOAD ANOTHER";
    	}
    else
    	{
    		if($w==$h)
    		{
    			print "ACCEPTED";
    		}
    		else
    		{
    			print "CROP IT";
    		}
    	}
    $i++;
    print "\n";
}

PHP:
<?php

// Read input from stdin and provide input before running code
//fscanf(STDIN, "%s\n", $name);
//echo "Hi, ".$name;

 
$lengthAllowed    = (int)fgets(STDIN);
$numberOfPhotos   = (int)fgets(STDIN);
$photosDimensions = [];
 
 
 
$i = 0;
while($i < $numberOfPhotos) 
{
	$inputDimensions = fgets(STDIN);
    array_push($photosDimensions, explode(" ", $inputDimensions));
    $i++;
}
 
$j = 0;
while($j < $numberOfPhotos)
{
	$width  = (int)$photosDimensions[$j][0];
	$height = (int)$photosDimensions[$j][1];
 
	
	if($width < $lengthAllowed || $height < $lengthAllowed)
	
	{
		
		echo "UPLOAD ANOTHER\n";
		
 
	}
	elseif( (($width >= $lengthAllowed && $height >= $lengthAllowed) && ($width ==  $height)))
	{
		
		echo "ACCEPTED\n";
	}
	elseif($width >= $lengthAllowed || $height >= $lengthAllowed)
	{
	
		echo "CROP IT\n";
	}
 
	$j++;	
}
 
?>

JavaScript(Rhino):
importPackage(java.lang);
importPackage(java.util);
 
var sc = new Scanner(System['in']);
var l = sc.nextInt();
var t=sc.nextInt();
for(var i=0;i<t;i++)
{
	var w=sc.nextInt();
	var h=sc.nextInt();
	if(w<l)
		print("UPLOAD ANOTHER");
	else if(h<l)
		print("UPLOAD ANOTHER");
	else if(w===h)
		print("ACCEPTED");
	else
		print("CROP IT");
}

JavaScript(Node.js):
function main(input) {
    //Enter your code here
    var lines = input.split('\n');
    var d = parseInt(lines[0]);
    var len = parseInt(lines[1]);
    for(var i=2;i<lines.length;i++)
    {
    	var width = parseInt(lines[i].split(' ')[0]);
    	var height = parseInt(lines[i].split(' ')[1]);
    	if(Math.min(width,height)<d)
    	{
    		console.log("UPLOAD ANOTHER");
    	}
    	else if(width==height)
    	{
    		console.log("ACCEPTED");
    	}
    	else
    	{
    		console.log("CROP IT");
    	}
    }
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
 

Python:
l=input()
n=input()
list = []
for i in range(0,n):
    temp=raw_input()
    list.append(temp.split())
 
for i in range(0,n):
    for j in range(0,2):
        
        if int(list[i][j])>=l:
            if (int(list[i][j]) == int(list[i][j+1])):
                print "ACCEPTED"
                break
            elif (int(list[i][j+1])>=l):
                print "CROP IT"
                break
            else:
                print "UPLOAD ANOTHER"
                break
        else :
            print "UPLOAD ANOTHER"
            break

			
Python 3:
import sys
 
S = sys.stdin.read().splitlines()
 
L = int(S[0])
 
lines = S[2:]
 
for line in lines:
	while True:
		line = line.split()
		line = [int(i) for i in line]
		if line[0] < L or line[1] < L:
			print("UPLOAD ANOTHER")
			break
		if line[0] == line[1]:
			print("ACCEPTED")
			break
		print("CROP IT")
		break

R:
x<-scan('stdin',what =integer(),quiet = TRUE)
i<-3
y<-rep(NA,length(x))
while(i<=length(x) ){
  if (x[i]<x[1] | x[i+1]<x[1]){y[i]<-"UPLOAD ANOTHER"}
  else if (x[i]==x[i+1]){y[i]<-"ACCEPTED"}
  else {y[i]<-"CROP IT"}
  i<-i+2
 
}
cat(y[complete.cases(y)],sep = '\n')


Ruby:
l = gets.chomp.to_f
n = gets.chomp.to_i
while n > 0
  n -= 1
  d = gets.chomp.split(" ")
  d[0] = d[0].to_f
  d[1] = d[1].to_f
  if d[0] < l || d[1] < l
    print "UPLOAD ANOTHER\n"
  elsif d[0] == d[1]
    print "ACCEPTED\n"
  else
    print "CROP IT\n"
  end
end

VB:
Module Main
 
    Sub Main()
        Dim L as integer
        Dim N as integer
        Dim W as integer
        Dim H as integer
        Dim x as integer
        Dim Dims() as String
        
        L = console.readline()
        N = console.readline()
        x = 1
        
        Do while x<= N
        	Dims = split(console.readline())
        	W = Dims(0)
        	H = Dims(1)
        	if W < L or H < L then
        		Console.writeline("UPLOAD ANOTHER")
        	   else
        	   	if W = H then
        	   		Console.writeline("ACCEPTED")
        	   	   else
        	   	   	Console.writeline("CROP IT")
        	   	End if 
        	End if   	
        	x  = x + 1
        Loop
    End Sub
 
End Module



*/