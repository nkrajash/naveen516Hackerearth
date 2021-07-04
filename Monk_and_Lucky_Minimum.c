/*All Tracks --->  Data Structures --->  Arrays --->  1-D --->  Problem ---> Monk_and_Lucky_Minimum
Tag(s): Data Structures, Easy, approved

PROBLEM
Monk just purchased an array A having N integers. Monk is very superstitious. He calls the array A Lucky if the frequency of the minimum element is odd, 
otherwise he considers it Unlucky. Help Monk in finding out if the array is Lucky or not.

Input:
First line consists of a single integer T denoting the number of test cases.
First line of each test case consists of a single integer N denoting the size of array A.
Second line of each test case consists of N space separated integers denoting the array A.

Output:
For each test case, print "Lucky" (without quotes) if frequency of minimum element is odd, otherwise print "Unlucky"(without quotes). Print a new line after each test case.

Constraints: 
1<=T<=10
1<=N<=10^5
1<=A[i]<=10^9

SAMPLE INPUT 
2
5
8 8 9 5 9
5
3 3 3 5 3

SAMPLE OUTPUT 
Lucky
Unlucky

Explanation
In first case, value of minimum element is 5 and it's frequency is 1 which is odd, so the array is Lucky.
In second case, value of minimum element is 3 and it's frequency is 4 which is even, so the array is Unlucky.

Monk_and_Lucky_Minimum.c

#include <stdio.h>
#define N 100000

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int occur,i,j,tc,n,k,A[N];
    scanf("%d",&tc);
    for(i=0;i<tc;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++)
            scanf("%d",&A[j]);
        qsort(A, n, sizeof(int), cmpfunc);
        occur=1;
        for(j=0;j<n;j++){
            for(k=j+1;k<n;k++){
                if(A[k]== A[0])
                    occur+=1;
                else
                    break;
            }
            break;
        }
        if(occur%2 == 0)
            printf("Unlucky\n");
        else
            printf("Lucky\n");
    }
    return 0;
}


Monk_and_Lucky_Minimum.cpp

#include <iostream>
using namespace std;
#define N 100000

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int occur,i,j,tc,n,k,A[N];
    cin>>tc;
    for(i=0;i<tc;i++){
        cin>>n;
        for(j=0;j<n;j++)
            cin>>A[j];
        qsort(A, n, sizeof(int), cmpfunc);
        occur=1;
        for(j=0;j<n;j++){
            for(k=j+1;k<n;k++){
                if(A[k]== A[0])
                    occur+=1;
                else
                    break;
            }
            break;
        }
        if(occur%2 == 0)
            cout<<"Unlucky\n";
        else
            cout<<"Lucky\n";
    }
    return 0;
}

*/


/* Editorial 
Author: Vaibhav_Jaimini
Tester: r3gz3n
Editorialist: r3gz3n

Brief Description: Given an array A of size N, find the frequency of the minimum element.

Prerequisite: None

Difficulty: CakeWalk

Detailed Explanation: 
This is the easiest task of the contest.

Solution 1:
First find the minimum element in the array A. The pseudo code is given below.

for i = 1 to N:
    mi = min(mi, A[i])
Now calculate the frequency of the minimum element.
for i = 1 to N:
    if A[i] == mi:
        cnt = cnt + 1
Time Complexity: O(N)

Solution 2:
We can combine the 2 loops in the previous solution and we can find the answer in a single loop.

for i = 1 to N:
    if mi > A[i]:
        mi = A[i]
        cnt = 1
    else if m1 == a:
        cnt = cnt + 1
Make sure to initialize mi.
See the tester's code for more clarification.

Time Complexity: O(N)

Solution 3:
This solution uses hashing. Count the frequencies of all the element in a map and you will get the frequency of the minimum element as map stores the element in sorted order. So the first element in the map is the minimum element. The pseudo code below is similar to C++ code. See the author's code for clarification.

map<int, int> m
for i = 1 to N:
    m[A[i]]++
cnt = (*m.begin()).second;
This code will run in O(N *logN).

Author Solution by Vaibhav Jaimini
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		map<ll,ll> m;
		for(int i=1; i<=n; i++){
			ll temp;cin>>temp;
			m[temp]++;
		}
		ll x = (*m.begin()).second;
		
		if(x&1)cout<<"Lucky\n";
		else cout<<"Unlucky\n";
	}
	return 0;
}


/*Tester Solution by Akash Sharma
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define be begin()
#define en end()
#define all(x) (x).begin(),(x).end()
#define alli(a, n, k) (a+k),(a+n+k)
#define REP(i, a, b, k) for(__typeof(a) i = a;i < b;i += k)
#define REPI(i, a, b, k) for(__typeof(a) i = a;i > b;i -= k)
#define REPITER(it, a) for(__typeof(a.begin()) it = a.begin();it != a.end(); ++it)
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define eps 1e-6
#define pi 3.141592653589793
using namespace std;
template<class T> inline T gcd(T x, T y) { if (!y) return x; return gcd(y, x%y); }
template<class T> inline T mod(T x) { if(x < 0) return -x; else return x; }
typedef vector<int> VII;
typedef vector<ll> VLL;
typedef pair<int, int> PII;
typedef vector< pair<int, int> > VPII;
typedef vector< pair<int, PII > > VPPI;
const int MOD = 1e9 + 7;
const int INF = 1e9;
int main(int argc, char* argv[])
{
	if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
	if(argc == 3) freopen(argv[2], "w", stdout);
	ios::sync_with_stdio(false);
	int t, n, m, cnt, a;
	cin >> t;
	assert(1 <= t and t <= 10);
	while(t--)
	{
		cin >> n;
		assert(1 <= n and n <= 100000);
		m = MOD, cnt = 0;
		REP(i, 0, n, 1)
		{
			cin >> a;
			assert(1 <= a and a <= INF);
			if(m > a)
				m = a, cnt = 1;
			else if(m == a)
				cnt++;
		}
		cout << (cnt & 1 ? "Lucky" : "Unlucky" ) << endl;
	}
	return 0;
}
*/


/*Best Submissions:
C:
#include <stdio.h>
 
int main()
{
    int t,a[100000],i,min,n;
    scanf("%d",&t);
    while(t--)
    {    min=1000000000;
        int cnt=0;
        scanf("%d",&n);
        
        for(i=0;i<n;i++)
       { scanf("%d",&a[i]);
          if(a[i]<=min)
           min=a[i];
       }
       for(i=0;i<n;i++)
        if(a[i]==min)
         cnt++;
         
        if(cnt%2==0)
        printf("Unlucky\n");
        
        else
        printf("Lucky\n");
    }
    return 0;
}

C++:
#include <iostream>
using namespace std;
 
int main()
{
    // cout << "Hello World!" << endl;
    int n;
    scanf("%d",&n);
    int x;
    for(int j = 0;j<n;j++)
    {
        scanf("%d",&x);
        int a[x];
        scanf("%d",&a[0]);
        int min  = a[0];
        int curr;
        if(x==1)
        {
            cout<<"Lucky"<<endl;
        }
        else
        {
        for(int i =1;i<x;i++)
        {
            scanf("%d",&a[i]);
            curr = a[i];
            if(min>curr)
            {
                min = curr;
            }
        }
        int count = 0;
        // cout<<min<<endl;
        for(int i=0;i<x;i++)
        {
            if(a[i]==min)
               count++;
        }
        if(count%2==0)
          cout<<"Unlucky"<<endl;
        else
          cout<<"Lucky"<<endl;
        }
    }
    return 0;
}

C++14:
#include <bits/stdc++.h>
#define fr(start,end) for(int i=start;i<end;i++)
#define ll long long
#define el "\n"
#define w(a) while(a--)
#define display(A,N) for(int i=0;i<N;i++){cout<<A[i]<<" ";}cout<<"\n";
#define input(A,n) for(int i=1;i<=n;i++){cin>>A[i];}
#define in(n) int n;cin>>n;
#define infinite 1000000007
#define max(a,b) (a>b)?a:b
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    in(t);
    w(t)
    {
        vector<int> Ar;
        in(n);
        fr(0,n)
        {
            int p;
            cin>>p;
            Ar.push_back(p); 
        }
//        for (auto i = Ar.begin(); i != Ar.end(); ++i) 
//         cout << *i << " ";
//         cout<<el;
        int cnt=count(Ar.begin(),Ar.end(),*(std::min_element(Ar.begin(),Ar.end())));
        if(cnt%2==0)
            cout<<"Unlucky"<<el;
        else
            cout<<"Lucky"<<el;
    }
    
    
    return 0;
}

C#:
using System;
using System.Linq;
using System.IO;
 
 
class Program
{
    static Stream ReadStream;
    static int Idx, Size, BytesRead;
    static byte[] Buffer;
    public static void Initialze()
    {
        ReadStream = Console.OpenStandardInput();
        Idx = BytesRead = 0;
        Size = 1 << 17;
        Buffer = new byte[Size];
    }
    public static int ReadInt()
    {
        byte _ReadByte;
        //For trimming
        do
        {
            _ReadByte = ReadByte();
        }
        while (_ReadByte < '-');
        bool neg = false;
        //Checking sign of number
        if (_ReadByte == '-')
        {
            neg = true;
            _ReadByte = ReadByte();
        }
        int m = _ReadByte - '0';
        while (true)
        {
            _ReadByte = ReadByte();
            if (_ReadByte < '0') break;
            m = m * 10 + (_ReadByte - '0');
        }
        if (neg) return -m;
        return m;
    }
    private static void ReadConsoleInput()
    {
        Idx = 0;
        BytesRead = ReadStream.Read(Buffer, 0, Size);
        if (BytesRead <= 0) Buffer[0] = 32;
    }
    private static byte ReadByte()
    {
        if (Idx == BytesRead) ReadConsoleInput();
        return Buffer[Idx++];
    }
    public static void Dispose()
    {
        ReadStream.Close();
    }
    static void Main(string[] args)
    {
        Initialze();
        int N, t, m,count;
        t = ReadInt();
        
        while (t-- > 0)
        {
            count = 0;
            m = -1;
            N = ReadInt();
            for (int n = 0; n < N; n++)
            {
                int num = ReadInt();
                if (n == 0)
                {
                    m = num;
                    count = 1;
                }
                else if (num == m)
                {
                    count++;
                }
                else if (num < m)
                {
                    m = num;
                    count = 1;
                }
            }
            
            if (count % 2 == 0)
            {
                Console.WriteLine("Unlucky");
            }
            else
            {
                Console.WriteLine("Lucky");
            }
        }
        Dispose();
        
    }
}

JAVA:
/* IMPORTANT: Multiple classes and nested static classes are supported */
 
/*
 * uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;
*/
//import for Scanner and other utility  classes
import java.util.*;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        /*
         * Read input from stdin and provide input before running
         * Use either of these methods for input
 
        //BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int N = Integer.parseInt(line); */
 
        //Scanner
        //Scanner s = new Scanner(System.in);
        Reader s = new Reader();
        int T = s.nextInt();
        
        while(T>0){
            T--;
            int count=0;
            int min=-1;
            int N = s.nextInt();
            for (int n=0;n<N;n++){
                int num = s.nextInt();
                if(n==0){
                    min = num;
                    count=1;
                }
                else if(num==min){
                    count++;
                }
                else if(num<min){
                    min = num;
                    count=1;
                }
            }
            
            if(count%2==0){
                System.out.println("Unlucky");
            }
            else{
                System.out.println("Lucky");
            }
        }
    }
    static class Reader
	    {
	        final private int BUFFER_SIZE = 1 << 16;
	        private DataInputStream din;
	        private byte[] buffer;
	        private int bufferPointer, bytesRead;
	 
	        public Reader()
	        {
	            din = new DataInputStream(System.in);
	            buffer = new byte[BUFFER_SIZE];
	            bufferPointer = bytesRead = 0;
	        }
	 
	        public Reader(String file_name) throws IOException
	        {
	            din = new DataInputStream(new FileInputStream(file_name));
	            buffer = new byte[BUFFER_SIZE];
	            bufferPointer = bytesRead = 0;
	        }
	 
	        public String readLine() throws IOException
	        {
	            byte[] buf = new byte[64]; // line length
	            int cnt = 0, c;
	            while ((c = read()) != -1)
	            {
	                if (c == '\n')
	                    break;
	                buf[cnt++] = (byte) c;
	            }
	            return new String(buf, 0, cnt);
	        }
	 
	        public int nextInt() throws IOException
	        {
	            int ret = 0;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	            do
	            {
	                ret = ret * 10 + c - '0';
	            }  while ((c = read()) >= '0' && c <= '9');
	 
	            if (neg)
	                return -ret;
	            return ret;
	        }
	         private byte read() throws IOException
	        {
	            if (bufferPointer == bytesRead)
	                fillBuffer();
	            return buffer[bufferPointer++];
	        }
	          private void fillBuffer() throws IOException
	        {
	            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
	            if (bytesRead == -1)
	                buffer[0] = -1;
	        }
	    }
}
 

Java 8:
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;
 
public class Ideone {
	static class Reader
    {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
 
        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public Reader(String file_name) throws IOException
        {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public String readLine() throws IOException
        {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1)
            {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }
 
        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do
            {
                ret = ret * 10 + c - '0';
            }  while ((c = read()) >= '0' && c <= '9');
 
            if (neg)
                return -ret;
            return ret;
        }
 
        public long nextLong() throws IOException
        {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
 
        public double nextDouble() throws IOException
        {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
 
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
 
            if (c == '.')
            {
                while ((c = read()) >= '0' && c <= '9')
                {
                    ret += (c - '0') / (div *= 10);
                }
            }
 
            if (neg)
                return -ret;
            return ret;
        }
 
        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
 
        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
 
        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
        }
    }
   
   public static void main(String[] args) throws IOException{
	   	Reader sc = new Reader();
	   	int t = sc.nextInt();
	   	while(t-- >0)
	   	{
	   		int n = sc.nextInt();
	   		int a[] = new int[n];
	   		int min = Integer.MAX_VALUE,count=0;
	   		for(int i=0;i<n;i++)
	   		{
	   			int value = sc.nextInt();
	   			if(value<min)
	   			{
	   				min = value;
	   				count = 1;
	   			}
	   			if(value==min)
	   				count++;
	   		}
	   		if(count%2!=0)
	   			System.out.println("Unlucky");
	   		else
	   			System.out.println("Lucky");
 
	   	}
	      
   }
	   
   
}

Javascript(Rhino):
// Below is a sample code to process input from STDIN.
// Equivalent in effect to the Java declaration import java.io.*;
importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var stdin = new BufferedReader(new InputStreamReader(System['in']));
var t = stdin.readLine();
t = Number(t);
 
for(var i = 0 ; i < t ; i ++){
    
    stdin.readLine();
    var input = stdin.readLine().split(' ').map(Number);
    var min = input.reduce(function(p,n){
        if(p > n) return n; return p;
    });
    var result = input.map(function(x){ return x === min ? 1 : 0}).reduce(function(p,n){
        return p + n ;
    }) % 2 === 0 ? 'Unlucky' : 'Lucky';
    print(result);
    
} 

Javascript(Node.js):
function main(input) {
    var inp = input.split("\n");
    var test_cases = [],i = 0,j = 0,test_cases_K = Number(inp[0]);
    while(i < test_cases_K){
        var l = i * 2,j = 0,min_val = -1,min_count=0,result="";
        var len = Number(inp[l+1]), data = inp[l+2].split(" ");
        while(j < len){
            var a = Number(data[j]);
            min_val == -1 ? min_val = a : null;
            if(a < min_val){
                min_val = a;
                min_count = 0;
            }
            min_val == a ? min_count+=1 : null;
            j++;
        }
        (min_count % 2) == 0 ? process.stdout.write("Unlucky\n") : process.stdout.write("Lucky\n");
        i++;
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
 
Pascal:
program Project1;
 
{$mode objfpc}{$H+}
 
uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };
var
  t,i:shortint;
  n,min,cnt,j:integer;
  a:array of integer;
begin
  readln(t);
  for i:= 1 to t do
  begin
    readln(n);
    setlength(a,n);
    for j:= 0 to length(a)-1 do
    begin
      read(a[j]);
    end;
    min:=a[0];
    for j:= 0 to length(a)-1 do
    begin
      if a[j]<min then
      begin
        min:=a[j];
      end;
    end;
    cnt:=0;
    for j:= 0 to length(a)-1 do
    begin
      if a[j]=min then
      begin
        cnt:=cnt+1;
      end;
    end;
  if cnt mod 2=1 then writeln('Lucky')
  else if cnt mod 2= 0 then writeln('Unlucky');
  end;
  
end.
 
  end;
  
end.

Perl:
use strict;
use warnings;
use List::Util qw /min/;
 
chomp(my $t = <STDIN>);
while($t-- > 0) {
    chomp(my $num = <STDIN>);
    chomp(my $line = <STDIN>);
    my @arr = split ' ', $line;
    my $mini = min @arr;
    my $count = 0;
    foreach my $el (@arr) {
        if($el == $mini) {
            $count++;
        }
    }
    if($count % 2 == 0) {
        print "Unlucky\n";
    } else {
        print "Lucky\n";
    }
}

PHP:
<?php
/*
// Sample code to perform I/O:
 
fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
echo "Hi, ".$name.".\n";                // Writing output to STDOUT
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
 
// Write your code here
 
fscanf(STDIN, "%d\n", $test);           // Reading input from STDIN
 
while($test>0){
    fscanf(STDIN,"%d\n",$n);
   
    $arr = explode(' ',trim(fgets(STDIN)));
    $min = min($arr);
    $oc = array_count_values($arr)[$min];
    if($oc%2==0){
        echo "Unlucky\n";
    }else{
        echo "Lucky\n";
    }

 $test--;
}
 
 
?>

Python:
t=input() #test cases 
while t>0:
    x=input() #fake input 
    y=list()
    y=map(int,raw_input().split(" ")) #number storing 
    t2=y.count(min(y))
    if(t2%2!=0):
        print "Lucky"
    else :
        print "Unlucky"
    t=t-1

Python 3:
test = int(input())
for i in range(test):
    n = input()
    array = list(map(int, input().split(" ")))
    print("Unlucky" if(array.count(min(array)))%2==0 else "Lucky")

Ruby:
test = int(input())
for i in range(test):
    n = input()
    array = list(map(int, input().split(" ")))
    print("Unlucky" if(array.count(min(array)))%2==0 else "Lucky")

	

*/
