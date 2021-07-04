/*All Tracks  --> Basic Programming  --> Input/Output  --> Basics of Input/Output  --> Problem
Palindromic String
You have been given a String S. You need to find and print whether this string is a palindrome or not. If yes, print "YES" (without quotes), else print "NO" (without quotes).

Input Format
The first and only line of input contains the String S. The String shall consist of lowercase English alphabets only.

Output Format
Print the required answer on a single line.

Constraints 1≤|S|≤100

Note: String S consists of lowercase English Alphabets only.

SAMPLE INPUT
aba

SAMPLE OUTPUT
YES



#include <stdio.h>
#include <string.h>
#define MAX 101

int main()
{
    char s[MAX];
    int i=0,j=0,flag=0;
    if(fgets(s,MAX,stdin)!=NULL){
        j=strlen(s)-1;
        while(i!=j/2){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                flag=1;
                break;
            }
        }
    }
    if(!flag)
        printf("YES");
    else
        printf("NO");
}
*/

/*
//Python code:
print("YES" if string == string[::-1] else "NO")


//Cpp code:
#include<iostream>
#include<string.h>
#include<algorithm>
#include<iterator>

using namespace std;

int main(){

string s,m;
cin>>s;	

m=s;	

//REVERSE THE STRING
reverse(m.begin(),m.end()); 

if(s==m){

cout<<"YES";
}

else cout<<"NO";
}

*/

/*
In #1
fnjzxnxnjplfwzowfdrhrvhegkmoncbkembjoudteqchjwqfzlofyflkmxnooasxulwofjzknthqqxgshvwxdvhdnlzjzdjdiifg
Out #1
NO
In #2
eovbgggijqjdsdhjyojeaujcdyyyxtpjlllowjyarfhxjxwkxpranhtlucoklahtokmqyozlrwhldozgbgpalkqlcsiowyeslusn
Out #2
NO
In #3
sqfopldohhwnbhhpnbxiwzvkybggkgtftvvaqpejznlxluatcppctaulxlnzjepqavvtftgkggbykvzwixbnphhbnwhhodlpofqs
Out #3
YES
In #4
izvnxvusaemgsgujwjaxkwdyeufbpfgbilfyxozyssuufxwfduudfwxfuussyzoxyflibgfpbfueydwkxajwjugsgmeasuvxnvzi
Out #4
YES

*/

/*Editorial 
There are multiple way to solve this problem. Efficiently we can use the below algorithm which will also cater when the string is large. 
It will check if the first element of the string is equal to the last element of the string, continuosly we will increase the startIndex and decrease the lastIndex untill we 
reach the point where lastIndex is greater then startIndex.


import java.io.BufferedReader;
import java.io.InputStreamReader;

class CheckPalindromicString{
    public static void main(String args[] ) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        System.out.println(palindromeCheck(line.toCharArray())?"YES":"NO");
    }
    public static boolean palindromeCheck(char [] arr)
    {
        int startIndex=0;
        int lastIndex=arr.length-1;
        while(lastIndex>startIndex)
        {
            if(arr[startIndex]!=arr[lastIndex])
                return false;
            ++startIndex;
            --lastIndex;
        }
        return true;
    }
}
*/


/* Python soln:
 ##With recursion 

def function(String):
if len(String)<2:
return True
elif String[0]!=String[-1]:
return False
return function(String[1:-1])
tempString=input()
temp=function(tempString)
if temp==True:
print("YES")
else:
print("NO")
*/

/*

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main() 
{
char str[10];
int i,len,flag=0;
printf("\nENTER A STRING: ");
gets(str);
printf("Input string in lower case: \"%s\"",strlwr(str));
len=strlen(str);
for (i=0;i<len;i++)
{
if(str[i]==str[len-i-1])
flag=flag+1;
}
if(flag==len)
printf("\nTHE STRING IS PALINDROM"); 
else
printf("\nTHE STRING IS NOT PALINDROM");
fgetc();
}

*/

/*
#include<iostream>
#include<string.h>
#include<algorithm>
#include<iterator>

using namespace std;

int main(){

string s,m;
cin>>s;	

m=s;	

reverse(m.begin(),m.end()); 

//REVERSE THE STRING

if(s==m){

cout<<"YES";
}

else cout<<"NO";
}

*/

/* Best Submissions:
Bash:
# Sample bash code
#!/bin/bash
:'read S
bool=1
for ((i=0; i<$(#S); i++))
do
    a=${S[0]:i:1}
    b=${S[0]:$(#S)-i-1:1}
    if [[ $a -ne $b ]]
    then
        bool=0
        break
    fi
done
if [[ $bool -ne 1 ]] 
then
    echo "NO"
else
    echo "YES"
fi '
 
read S
 
bool=1
for((i=0; i<${#S}; i++))
do
  a=${S[0]:i:1}
  b=${S[0]:${#S}-i-1:1}
  if [[ $a -ne $b ]]
  then
     bool=0
     break
  fi
  #echo ${S[0]:i:1}
  #echo ${S[0]:${#S}-i-1:1}
done
 
if [[ $bool -ne 1 ]]
then
   echo "NO"
else
   echo "YES"
fi

C:
# Sample bash code
#!/bin/bash
:'read S
bool=1
for ((i=0; i<$(#S); i++))
do
    a=${S[0]:i:1}
    b=${S[0]:$(#S)-i-1:1}
    if [[ $a -ne $b ]]
    then
        bool=0
        break
    fi
done
if [[ $bool -ne 1 ]] 
then
    echo "NO"
else
    echo "YES"
fi '
 
read S
 
bool=1
for((i=0; i<${#S}; i++))
do
  a=${S[0]:i:1}
  b=${S[0]:${#S}-i-1:1}
  if [[ $a -ne $b ]]
  then
     bool=0
     break
  fi
  #echo ${S[0]:i:1}
  #echo ${S[0]:${#S}-i-1:1}
done
 
if [[ $bool -ne 1 ]]
then
   echo "NO"
else
   echo "YES"
fi


C++:
#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    string str;
    cin>>str;
    int len = str.length();
    //string res="YES";
    for(int ind = 0; ind < len/2; ind++)
    {
        if (str[ind] != str[len- ind -1])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}


C++14:
#include<iostream>
#include<string>
 
using namespace std;
 
int main(){
    
    string s;
    
    getline(cin,s);
    
    int i=0;
    int j=s.length()-1;
    
    for( i,j ; i<=j; ){
        int flag=0;
        if(s[i]==s[j]){
            flag=1;
        }
        if(flag==0){
            cout << "NO" << endl;
            break;
        }
        
        flag=0;
        
         i++,j--;
        
        if(i==j || i+1==j){
            cout << "YES";
        }
        
    }
    
}


C#:
using System; 
 
class MyClass {
    static void Main(string[] args) {
    	
    	string str = Console.ReadLine();
    	string rev = "";
    	char[] chars = str.ToCharArray();
    	
    	for(int i = str.Length - 1; i >= 0; i--)
    		rev += chars[i].ToString();
 
    	if(str.Equals(rev))
    		Console.WriteLine("YES");
    	else
    		Console.WriteLine("NO");
    }
}

JAVA:
import java.io.*;
class palindrome {
    public static void main(String args[] ) throws Exception {
       InputStreamReader read=new InputStreamReader(System.in);
       BufferedReader in=new BufferedReader(read);
       int i,len,flag=0;
       String str1="";
       String str;
       char ch,ch1;
       str=in.readLine();
       len=str.length();
       for(i=0;i<(len/2);i++) {
           ch=str.charAt(i);
           ch1=str.charAt(len-1-i);
           if(ch!=ch1)
            flag=1;
       }
       if(flag==0)
        System.out.print("YES");
       if(flag==1)
        System.out.print("NO");
    }
}

JAVA 8:
import java.io.*;
class palindrome {
    public static void main(String args[] ) throws Exception {
       InputStreamReader read=new InputStreamReader(System.in);
       BufferedReader in=new BufferedReader(read);
       int i,len,flag=0;
       String str1="";
       String str;
       char ch,ch1;
       str=in.readLine();
       len=str.length();
       for(i=0;i<(len/2);i++) {
           ch=str.charAt(i);
           ch1=str.charAt(len-1-i);
           if(ch!=ch1)
            flag=1;
       }
       if(flag==0)
        System.out.print("YES");
       if(flag==1)
        System.out.print("NO");
    }
}


Java script(Rhino):
importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new Scanner(System['in']);
 
var input = sc.nextLine();
 
var revr = input.split("").reverse().join("");
 
if(input==revr)
	print ('YES');
else
	print ('NO');

Javascript(Node.js):
function palindrome(input)
      {
        var size = input.length;
        var search;
        var count = 0;
        var flag = true;
 
        if(size % 2 != 0)
        {
          search = size / 2 - 1;
        }
        else
        {
          search = size / 2;
        }
 
        while(count < search)
        {
          if(input[count] != input[size - 1 - count])
          {
            flag = false;
            count = size;
          }
          count++;
        }
 
        console.log(flag ? 'YES' : 'NO');
      }
 
process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
 
process.stdin.on("data", function (input) {
    stdin_input += input;
});
 
process.stdin.on("end", function () {
   palindrome(stdin_input);
});
 

Pascal:
var s:string;c:byte;
i:longint;
begin
    readln(s);
    c:=0;
    for i:=1 to (length(s) div 2)+1 do
    if s[i]<>s[length(s)-i+1] then c:=1;
    if c=1 then writeln('NO') else write('YES');
end.

PHP:
<?php
$inputArray = fscanf(STDIN, "%s\n");
$name = $inputArray[0];
$length = strlen($name);
$reverseName = strrev($name);
if($length >= 1 && $length <= 100){
 
    if (ctype_lower($name)) {
        if($name == $reverseName){
            echo  "YES";
        }
        else
        {
            echo "NO";
        }
    }
    else
    {
        echo "NO";
    }
}
else{
    echo "NO";
}
?>


Perl:
use strict;
 
=comment
# Read input from stdin and provide input before running code
 
# Echo input to output.
while(my $fred = <STDIN>) {
    print $fred;
}
=cut
 
while(my $fred = <STDIN>) {
    
    my @input = split(//,$fred);
    my $palindrome = 1;
    
    for(my $i = 0; $i <= sprintf("%d", (scalar @input)/2); $i++){
        if($input[$i] ne $input[$#input - $i]){
            $palindrome = 0;
            print 'NO';
            last;
        }
        
    }
    
    print 'YES' if($palindrome);
}



Python:
a = raw_input()
la = len(a)/2
flag = 0
for i in range(la):
	if a[:i+1] == a[-(i+1):]:
		flag = 1
print ('YES' if flag else 'NO')

Python 3:
s1 = input()
li = list(s1)
li.reverse()
s2 = "".join(li)
if s1==s2:
	print("YES")
else:
	print("NO")


R:
S <- readLines('stdin', warn=FALSE)
t = scan(text = S, what="")
b=paste(rev(substring(t,1:nchar(t),1:nchar(t))),collapse="")
if (t == b){cat("YES")}else{cat("NO")}

Ruby:
# Read input from stdin and provide input before running code
 
 
 
s = gets.chomp
s == s.reverse ? puts("YES") : puts("NO")


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
            Console.WriteLine("NO")       
            Exit Sub
        End If
      Next i
      
      Console.WriteLine("YES")
    End Sub
 
End Module


*/



