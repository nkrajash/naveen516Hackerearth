/* All Tracks -->Algorithms-->Searching-->Linear Search-->
Monk Takes a Walk
Tag(s): Algorithms, Very-Easy, searching
Today, Monk went for a walk in a garden. There are many trees in the garden and each tree has an English alphabet on it. 
While Monk was walking, he noticed that all trees with vowels on it are not in good state. He decided to take care of them. So, he asked you to tell him the count of such trees in the garden. 
Note : The following letters are vowels: 'A', 'E', 'I', 'O', 'U' ,'a','e','i','o' and 'u'.

Input:
The first line consists of an integer T denoting the number of test cases.
Each test case consists of only one string, each character of string denoting the alphabet (may be lowercase or uppercase) on a tree in the garden.

Output:
For each test case, print the count in a new line.

Constraints:
1<=T<=10
1<=length of string<=10^5

SAMPLE INPUT 
2
nBBZLaosnm
JHkIsnZtTL
SAMPLE OUTPUT 
2
1
Explanation
In test case 1, a and o are the only vowels. So, count=2

My Python(py 2.7.6) solution:
'''
# Read input from stdin and provide input before running code

name = raw_input()
print 'Hi, %s.' % name
'''

def count_vowels():
    vowels = ['a','A', 'e','E','i','I','o','O','u','U']
    M = 1
    cnt = 0
    N = int(input())
    for i in range(M,N+1):
        cnt=0
        mystring = raw_input()
        for ch in mystring:
            if ch in vowels:
                cnt+= 1
        print(cnt)


count_vowels()

My C solution:
#include <stdio.h>
#include <string.h>
#define LEN 100001

int main()
{
    char str[LEN],t;
    int i=0,j=0,cnt=0;
    scanf("%d",&t);
    for(j=0;j<t;j++){
        scanf("%s",str);
        cnt=0;
        for(i=0; str[i]!='\0'; ++i)
        {
            if(str[i] == 'A' || str[i]== 'E' || str[i] == 'I' || str[i]=='O' || str[i]=='U'||
                str[i] == 'a' || str[i]== 'e' || str[i] == 'i' || str[i]=='o' || str[i]=='u')
                    cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;   
}

My C++ solution:

#include <iostream>
using namespace std;
#define LEN 100001

int main()
{
    int t=0,cnt;
    char str[LEN]; 
    cin>>t;
    for(int j=0;j<t;j++){
              
        cin>>str;
        cnt=0;
        for(int i=0; str[i]!='\0'; ++i)
        {
            if(str[i] == 'A' || str[i]== 'E' || str[i] == 'I' || str[i]=='O' || str[i]=='U'||
              str[i] == 'a' || str[i]== 'e' || str[i] == 'i' || str[i]=='o' || str[i]=='u')
                    cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}

/*Editorial:

Author: shubham1428
Tester: r3gz3n
Editorialist: r3gz3n

Brief Description: Given a string S you have to count number of vowels in the string.

Prerequisite: None

Difficulty: Cakewalk

Detailed Editorial:
Solution 1:
For each vowel, count how many times it is appearing in the string S. Final answer will the sum of frequencies of all the vowels.

Solution 2:
Iterate overall all the characters in the string S and use a counter ( variable ) to keep track of number of vowels in the string S. 
While iterating over the characters, if we encounter a vowel, we will increase the counter by 1.

Time Complexity: O(N)  where N is the length of the string S.

Space Complexity:  O(N)

Author Solution by Shubham Gupta
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int len=str.length();
		string vowel="aeiouAEIOU";
		int count=0;
		for(int i=0;i<len;i++)
			for(int j=0;j<10;j++)
				if(str[i]==vowel[j])
				{
					count++;break;
				}
		cout<<count<<"\n";
	}
	return 0;
}


Tester Solution by Akash Sharma
/*
 *
 *	File Name: solution_ac.cpp
 *	Author: r3gz3n
 *	Description: Linear Search
 *	Difficulty: CakeWalk
 *
*/
 
/*
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define sz size()
template<class T> inline T gcd(T x, T y) { if (!y) return x; return gcd(y, x%y);}
using namespace std;
typedef vector<int> VII;
typedef vector<ll> VLL;
typedef pair<int, int> PII;
typedef vector< pair<int, int> > VPII;
typedef vector< pair<int, PII > > VPPI;
const int MOD = 1e9 + 7;
char a[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
bool isVowel(char s)
{
	for(int i = 0;i < 10;++i)
		if(s == a[i]) return true;
	return false;
}
int main(int argc, char* argv[])
{
	if(argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
	if(argc == 3) freopen(argv[2], "w", stdout);
	int t, ans;
	string s;
	cin >> t;
	assert(1 <= t and t <= 10);
	for (int i = 0; i < t; ++i)
	{
		cin >> s;
		ans = 0;
		assert(1 <= s.length() and s.length() <= 100000);
		for(int i = 0;i < s.length();++i)
		{
			assert(('a' <= s[i] and s[i] <= 'z') or ('A' <= s[i] and s[i] <= 'Z'));
			if(isVowel(s[i])) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}

*/

/*
A Java Solution:
class Test {
public static void main(String args[] ) throws Exception {
String results = "";
HashMap<Character, Object> vowelsMap = new HashMap<>();
vowelsMap.put('a', null);
vowelsMap.put('e', null);
vowelsMap.put('i', null);
vowelsMap.put('o', null);
vowelsMap.put('u', null);
vowelsMap.put('A', null);
vowelsMap.put('E', null);
vowelsMap.put('I', null);
vowelsMap.put('O', null);
vowelsMap.put('U', null);

BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
int numberOfString = Integer.parseInt(br.readLine());
String tmp;
for (int i=0; i < numberOfString; i++){
tmp = br.readLine();
results += countVowels(vowelsMap, tmp) + "\n";
}
System.out.print(results);
}

private static int countVowels(HashMap<Character, Object> vow, String inputString){
int count = 0;
for (int i = 0; i < inputString.length(); i++) {
if (vow.containsKey(inputString.charAt(i)))
count++;
}

return count;
}
}
*/

/*

Another Solution in JAVA

import java.util.Scanner;

public class MonkTakesAWalk {
public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
int t = sc.nextInt();
for(int j=0; j<t; j++) {
int count=0;
String s = sc.next();
for(int i=0; i<s.length(); i++)
if(s.charAt(i)=='A' || s.charAt(i)=='E' || s.charAt(i)=='I' || s.charAt(i)=='O' || s.charAt(i)=='U' || s.charAt(i)=='a' || s.charAt(i)=='e' || s.charAt(i)=='i' || s.charAt(i)=='o' || s.charAt(i)=='u')
count++;
System.out.println(count);
}
sc.close();
}
}

*/


/*
Another Solution in JAVA
using System;
using System.Linq;

namespace FindFaultyTrees
{
class Program
{
static void Main(string[] args)
{
int testCases = Convert.ToInt32(Console.ReadLine());
string[] treesList = new string[testCases];
char[] faultyTrees = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
for (int i = 0; i < testCases; i++)
{
treesList[i] = Console.ReadLine();
}
for (int i = 0; i < testCases; i++)
{
var treeChar = treesList[i].ToCharArray();
var count = 0;
foreach (var item in treeChar)
{
if(faultyTrees.Contains(item))
{
count++;
}
}
Console.WriteLine(count);
}
}
}
}


*/


/*Best Submissions:
C:
#include <stdio.h>
#define MAX 100007
 
int isVowel(char ch)
{
	if(ch >= 97)
	{
		ch -= 32;
	}
	if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
	{
		return 1;
	}
	return 0;
}
 
int main()
{
    int T;
    char str[MAX];
    scanf("%d", &T);
    while(T--)
    {
    	scanf("%s", str);
    	int i, len = strlen(str), count = 0;
    	for(i=0;i<len;++i)
    	{
    		if(isVowel(str[i]))
    		{
    			++count;
    		}
    	}
    	printf("%d\n", count);
    }
    return 0;
}

C++:
#include <iostream>
 
using namespace std;
 
int main(){
  string word;
  int n=0,countvo=0;
  cin>>n;
  for(int x=0; x<n; x++){
    cin>>word;
    for(int y=0; y<word.size(); y++){
      if(tolower(word[y]) == 'a' || tolower(word[y]) == 'e' || tolower(word[y]) == 'i' || tolower(word[y]) == 'o' || tolower(word[y]) == 'u' )
        countvo++;
    }
    cout<< countvo <<endl;
    countvo = 0;
  }
  return 0;
}

C++14:
/*
// Sample code to perform I/O:
 
cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
 
// Write your code here
#include <iostream>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    string temp;
    string vovel0 = "aeiou";
    string vovel1 = "AEIOU";
    int count;
    while(t--){
        cin>>temp;
        count = 0;
        for(int i=0;i<temp.length();i++){
            for(int j=0;j<vovel0.length();j++){
                if(vovel0[j]==temp[i] || vovel1[j]==temp[i]){
                  count++;  
                }
                
            }
            
        }
        cout<<count<<endl;
    }
    return 0;
}


C#:
using System; 
using System.Numerics;
class MyClass {
    static void Main(string[] args) {
        /*
         * Read input from stdin and provide input before running
        var line1 = System.Console.ReadLine().Trim();
        var N = Int32.Parse(line1);
        for (var i = 0; i < N; i++) {
            System.Console.WriteLine("hello world");
        }
        */
       char[] si = new char[]{'A','I','O','U','E','a','i','o','u','e'};
            int n=int.Parse(System.Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                
                int no = 0;
                var inputLine = System.Console.ReadLine();
                 foreach (char ch in inputLine.ToCharArray())
                {
                    if (Array.Exists(si, x => x == ch))
                        no = no + 1;
                }
                System.Console.WriteLine(no);
            }
        
    }
}

Java:
/* IMPORTANT: Multiple classes and nested static classes are supported */
 
 
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
 
class TestClass {
     static int numChar;
    static int curChar;
    static byte[] buffer = new byte[1024];
    static InputStream stream;
    static PrintWriter out;
 
    public static void main(String[] args) throws IOException {
        stream = System.in;
        out = new PrintWriter(System.out);
 
        int t = readInt();
        for (int i = 0; i < t; i++) {
            String data = readString();
            char a[] = data.toCharArray();
            int count = 0;
            for (char ch : a) {
                if (isVowel(ch))
                    count++;
            }
            out.println(count);
        }
 
        out.flush();
        out.close();
    }
 
    private static boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
 
    public static int read() throws IOException {
        if (numChar <= curChar) {
            curChar = 0;
            numChar = stream.read(buffer);
            if (numChar <= 0) {
                return -1;
            }
        }
        return buffer[curChar++];
    }
 
    public static long readLong() throws IOException, InputMismatchException {
        int c = read();
        if (c == -1)
            throw new IOException();
        while (isSpaceChar(c)) {
            c = read();
        }
        boolean negative = false;
        if (c == '-') {
            negative = true;
            c = read();
        }
        long res = 0;
        while (!isSpaceChar(c)) {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += (c - '0');
            c = read();
        }
        if (negative)
            return -res;
        return res;
    }
 
 
 
    public static int readInt() throws IOException, InputMismatchException {
        return (int) readLong();
    }
 
    public static String readString() throws IOException {
        int c = read();
        if (c == -1)
            throw new IOException();
        while (isSpaceChar(c)) {
            c = read();
        }
        StringBuilder builder = new StringBuilder();
        while (!isSpaceChar(c)) {
            builder.append((char) c);
            c = read();
        }
        return builder.toString();
    }
 
    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == -1;
    }
}

JAVA 8:
/* IMPORTANT: Multiple classes and nested static classes are supported */
 
 
import java.io.*;
import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        InputReader inputReader = new InputReader();
        
        PrintStream ps=new PrintStream(System.out);
        int N = inputReader.readNextInt();
        
        while(N-->0)
        {
         int count=0;
        char ch=inputReader.readNextChar();
            
           while(!inputReader.isWhiteSpace((int)ch))
                {
                
                switch(ch)                
                {
                case 'A':
                    ++count;
                break;
                
                case 'E':
                    ++count;
                break;
                
                case 'I':
                    ++count;
                break;
                
                case 'O':
                    ++count;
                break;
                
                case 'U':
                    ++count;
                break;
                
                case 'a':
                    ++count;
                break;
                
                case 'e':
                    ++count;
                break;
                
                case 'i':
                    ++count;
                break;
                
                case 'o':
                    ++count;
                break;
                
                case 'u':
                    ++count;
                break;
                }
	               
                    ch=inputReader.readNextChar();
                }
        ps.println(count);
        }
        ps.close();
        
    }
}
class InputReader
{
	private byte[] buf=new byte[1024];    //Buffer of Bytes
    private int index;
    private InputStream in;
    private int total;
    public InputReader()
    {
        in=System.in;
    }
    public int readNextInt()throws IOException
    {
        int integer=0;
        int n=scan();
        
        while(isWhiteSpace(n))    //Removing starting whitespaces
        n=scan();
        int neg=1;
        if(n=='-')                //If Negative Sign encounters
        {
            neg=-1;
            n=scan();
        }
        while(!isWhiteSpace(n))
        {
            if(n>='0'&&n<='9')
            {
                integer*=10;
                integer+=n-'0';
                n=scan();
            }
            else throw new InputMismatchException();
        }
        return neg*integer;
    }
 public int scan()throws IOException    //Scan method used to scan buf
    {
        if(total<0)
        throw new InputMismatchException();
        if(index>=total)
        {
            index=0;
            total=in.read(buf);
            if(total<=0)
            return -1;
        }
        return buf[index++];
    }
 public boolean isWhiteSpace(int n)
    {
        if(n==' '||n=='\n'||n=='\r'||n=='\t'||n==-1)
        return true;
        return false;
    
    }
    public char readNextChar()
{
	int val=' ';
	try
		{
			val=scan();
			/*while(isWhiteSpace(val))
			val=scan();*/
		}catch(Exception e){}
 
return (char)val;
 
}
}

Javascript(Rhino):
// Below is a sample code to process input from STDIN.
// Equivalent in effect to the Java declaration import java.io.*;
importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new Scanner(System['in']);
var iTC = sc.nextInt();
var iSArr = [], iReg = /^[aeiou]$/i;
for(var i=0;i<iTC;i++){
    var iS = sc.next()+'',count=0;
    iSArr = iS.split('');
    for(var t=0;t<iSArr.length;t++){
        if(iReg.test(iSArr[t])){
            //print('here');
            count++;
        }
    }
    print(count);
}
 
 
//System.out.println(input);
//System.out.println('Hello, there!\n');
// End of input processing code.
 
 
//print ('Hello World!\n');

Javascript(Node.js):
"use strict";
function main(input) {
    //Enter your code here
    let inputs = input.split("\n");
    let inputArray = inputs.slice(1);
    
    // inputArray.forEach(function(x){
    //   console.log(x.match(/[aeiou]/gi).length); 
    // });
    
    for(let i = 0; i < inputArray.length; i++) {
      let res = inputArray[i].match(/[aeiou]/gi);
      console.log(res === null ? 0 : res.length);
    }
    
    // console.log(inputArray);
    // process.stdout.write("Hello World!");
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
type int=longint;
 
var s:ansistring;
n,test,i:int;
count:int;
t:set of char;
 
begin
	readln(test);
	t:=['O','o','i','I','A','a','u','U','E','e'];
	while test>0 do begin
		dec(test);
		readln(s);n:=length(s);
		count:=0;
		for i:=1 to n do 
			if s[i] in t then inc(count);
		writeln(count);
	end;
end.

Perl:
$\=$/;map{
	$_=<>;print 0+s/[aeiou]//gi
}1..<>

PHP:
<?php
 
fscanf(STDIN, "%d\n", $T);
while($T-->0){
	fscanf(STDIN, "%s\n", $str);
	echo preg_match_all('/[aeiouAEIOU]/',$str).PHP_EOL;
}
/*
fscanf(STDIN, '%d\n', $nb);
while ($nb--) {
    fscanf(STDIN, '%s\n', $string);
    $count = 0;
    for($j = 0 ; $j < strlen($string) ; $j++){
        
        $char = $string[$j];
        $upperChar = !ctype_upper($char) ? strtoupper($char) : $char;
        
        if($upperChar == 'A' || $upperChar == 'E' 
                || $upperChar == 'I' || $upperChar == 'O' || $upperChar == 'U'){    
            $count++;
        }
    }
    echo $count.PHP_EOL;
} 
*/
 
?>

Python:
t = int(raw_input())
 
for i in range(t):
	c = raw_input()
	r = 0
	for l in c:
		if l in 'AEIOUaeiou':
			r += 1
	print r


Python 3:
t=int(input())
counts = {i:0 for i in 'aeiouAEIOU'}
s=[]
n=0
for i in range(0,t):
    s.append(input())
    
for i in s:
    for char in i:
         if char in counts:
             n=n+1
 
    print(n)
    n=0

R:
count_and_print_vowel <-function(input){
b <- gsub("[^aeiouAEIOU]","",input)
v <- nchar(b)
return (v)
#cat(v, "\n")
}
con <- file('stdin', open = 'r')
 
string <- function(string){
    return (unlist(strsplit(string, "\n")))
}
 
inputs <- readLines(con)
test <- string(inputs[[1]])
#cat(test, "\n")
for (i in 1:test){
data <- string(inputs[[i+1]])
count <-count_and_print_vowel(data)
cat(count, "\n")
}

Ruby:
=begin
# Read input from stdin and provide input before running code
 
print "Please enter your name: "
name = gets.chomp
print "Hi #{name}\n"
=end
 
n  = gets.strip.to_i
n.times do
    str = gets.strip
    p str.count("AEIOUaeiou")
end


*/

