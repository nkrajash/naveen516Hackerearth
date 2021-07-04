/* All Tracks -->   Algorithms -->   String Algorithms -->   String Searching 
 Palindrome String
Tag(s): Very-Easy
Given a String S, Check Whether The Given String S is Palindrome or Not. If The Given String is Palindrome Then Print "Palindrome" (Without Quotes) else Print "Not Palindrome" (Without Quotes)

Input Format

Take String Input S

Output Format

Print "Palindrome" if String is Palindrome else Print"Not Palindrome"(Without Quotes).

Constraints

0 < S < 100
SAMPLE INPUT 
madam
SAMPLE OUTPUT 
Palindrome


#include <stdio.h>
#define S 101

int main()
{
    char str[S];
    int i=0,j=0,flag=0;
    scanf("%s",str);
    while(str[i]!='\0')
        i++;
    j=i-1;
    i=0;
    while(i!=j/2){
        if(str[i]==str[j]){
            i++;
            j--;
        }
        else{
            flag=1;
            break;
        }
    }
    if(!flag)
        printf("Palindrome");
    else
        printf("Not Palindrome");
    return 0;
}
*/

//My CPP Solution:
/*
#include <iostream>
using namespace std;
#define S 101
 
int main()
{
    char str[S];
    int i=0,j=0,flag=0;
    cin>>str;
    while(str[i]!='\0')
        i++;
    j=i-1;
    i=0;
    while(i!=j/2){
        if(str[i]==str[j]){
            i++;
            j--;
        }
        else{
            flag=1;
            break;
        }
    }
    if(!flag)
        cout<<"Palindrome";
    else
        cout<<"Not Palindrome";
    return 0;
}
*/


/*
In #1
acrobatsstaborca
Out #1
Palindrome

In #2
noon
Out #2
Palindrome

In #3
helloworld
Out #3
Not Palindrome

In #4
helloworldmynameishelloworlddlrowollehsiemanymdlrowolleh
Out #4
Palindrome

In #5
helloworldmynameishelloworlddlrowollehsienanymdlrowolleh
Out #5
Not Palindrome

In #6
bstringhelloworldmynameishelloworlddlrowollehsiemanymdlrowollehgnirtsb
Out #6
Palindrome

*/

/*Best Submissions:
C:
#include <stdio.h>
#include <string.h>
int main()
{   int i;
    char a[100],r[100];
    gets(a);
    strcpy(r,a);
    for(i=0;i<strlen(a);i++){
        r[strlen(a)-1-i]=a[i];
    }
    if(strcmp(a,r)==0)
    printf("Palindrome");
    else
    printf("Not Palindrome");
    
    return 0;
}
C++:
#include <bits/stdc++.h>
#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { ll B, T, F, P; };
 
unsigned MOD = 1000000007;
ll _MOD = 1000000007;
double EPS = 1e-10;
int UNKO = INT_MAX;
 
string s, r;
 
int main() {
    cin >> s;
    r = s;
    reverse(r.begin(), r.end());
    if (s == r) {
        cout << "Palindrome\n";
    } else {
        cout << "Not Palindrome\n";
    }
    return 0;
}


C++14:
// Sample code to perform I/O:
//cin >> name;                            // Reading input from STDIN
//cout << "Hi, " << name << ".\n";        // Writing output to STDOUT
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
// Write your code here
#include <bits/stdc++.h>
using namespace std;
#define  ll long long
#define pp pair<long long,long long>
#define f first
#define s second
#define pb push_back
int main()
{
    ll n,m,i,j,k,l,t;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin>>str;
    n=str.length();
    for (i=0;i<n/2;i++)
    {
        if (str[i]!=str[n-i-1])
            break;
    }
    if (i<n/2)
        cout<<"Not Palindrome\n";
    else    
        cout<<"Palindrome\n";
    return 0;
}


C#:
using System; 
using System.Numerics;
class MyClass {
    static void Main(string[] args) {

        //Read input from stdin and provide input before running
        //var line1 = System.Console.ReadLine().Trim();
        //var N = Int32.Parse(line1);
        //for (var i = 0; i < N; i++) {
        //    System.Console.WriteLine("hello world");
        //}
 
       string input=System.Console.ReadLine().Trim();
       string revInput=string.Empty;
       for (int count=(input.Length-1);count>=0;count--)
       {
           revInput=revInput+input[count];
       }
       if(input.Equals(revInput))
       {
           System.Console.WriteLine("Palindrome");
           
       }
       else
       {
           System.Console.WriteLine("Not Palindrome");
           
       }
    }
}

Java:
//IMPORTANT: Multiple classes and nested static classes are supported
 
 
// uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
//import for Scanner and other utility  classes
import java.util.*;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in) );
        char []arr = br.readLine().toCharArray();
        boolean valid = true;
	     		int i = 0,j = arr.length-1;
	     		while(i<j)
	     		{
	     			if(arr[i] !=arr[j])
	     			{
	     				valid = false;
	     				break;
	     			}
	     			i++;j--;
	     		}
	     		if(valid)
	     			System.out.println("Palindrome");
	     		else
	     			System.out.println("Not Palindrome");
    }
}

Java 8:
//IMPORTANT: Multiple classes and nested static classes are supported
//uncomment this if you want to read input.
//imports for BufferedReader
//import java.io.BufferedReader;
//import java.io.InputStreamReader;
 
//import for Scanner and other utility classes
//import java.util.*;


import java.util.*;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        //
        //Read input from stdin and provide input before running
        //Use either of these methods for input
 
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String line = br.readLine();
        //int N = Integer.parseInt(line);
 
        //Scanner
        //Scanner s = new Scanner(System.in);
        //int N = s.nextInt();
        //
        //for (int i = 0; i < N; i++) {
        //    System.out.println("hello world");
        //}
        //

        Scanner input = new Scanner(System.in);
        String inputString = input.nextLine();
        
        String result = (isPalindrome(inputString, 0, inputString.length()-1))?"Palindrome":"Not Palindrome";
 
        System.out.println(result);
    }
    
    public static boolean isPalindrome(String s, int startingIndex, int endingIndex){
        if(startingIndex >= endingIndex)
            return true;
            
        if(s.charAt(startingIndex) != s.charAt(endingIndex))
            return false;
        else    
            return isPalindrome(s, startingIndex + 1, endingIndex - 1);
    }
}

Javascript(Node.js):
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
  var existing = input;
  var reversed = [];
  //var reversed = input.split('').reverse().join('');
  
  for(var i=input.length-1; i>=0;i--){
      reversed.push(input[i])
  }
  
  if(existing === reversed.join('')){
      console.log("Palindrome");
  }
  else{
       console.log("Not Palindrome");
  }
    
}

Perl:
$str=<STDIN>;
@list_of_str=split('',$str);
$flag=0;
$last=$#list_of_str;
for(my $i=0;$i<=(int($last/2)-1);$i++){
    if($list_of_str[$i] ne $list_of_str[$last-$i]){
        $flag++;
    }
}
if($flag){
    print "Not Palindrome";
}else{
    print "Palindrome";
}

PHP:
<?php
    fscanf(STDIN, "%s\n", $str);
    echo ($str==strrev($str)?"Palindrome":"Not Palindrome");

Python:
'''
# Read input from stdin and provide input before running code
 
name = raw_input()
print 'Hi, %s.' % name
'''
i = raw_input()
ch = list(i)
length = len(ch)
 
palindrome = True
for pos in range(length):
    if ch[pos] == ch[length-1-pos]:
        pass
    else:
        palindrome = False
        break
if palindrome:
    print 'Palindrome'
else:
    print 'Not Palindrome'


Python 3:
p=input('')
n=0
k=len(p)-1
while n<len(p):
        if p[n]==p[k]:
                n=n+1
                k=k-1
        elif p[n]!=p[k]:
                print ('Not Palindrome')
                break
else:
        print ('Palindrome')

Ruby:
s=gets.chomp
if s==s.reverse
 puts "Palindrome"
 else
puts "Not Palindrome"
end

VB:
Module Main
 
    Sub Main()
        Dim stIn As String = ""
        stIn = Console.ReadLine()
 
        Dim tstString() As Char = stIn.ToCharArray
        Dim len As Integer = stIn.Length - 1
        Dim ttl As Integer = stIn.Length / 2
 
      For i As Integer = 0 To (ttl - 1)
        If tstString(i) <> tstString(len - i) Then
            Console.WriteLine("Not Palindrome")       
            Exit Sub
        End If
      Next i
      
      Console.WriteLine("Palindrome")
    End Sub
 
End Module


*/




