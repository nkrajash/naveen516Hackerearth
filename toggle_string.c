/*All Tracks  --> Basic Programming  --> Input/Output --> Basics of Input/Output -->
Toggle String
Tag(s): Very-Easy

You have been given a String S consisting of uppercase and lowercase English alphabets. You need to change the case of each alphabet in this String.
That is, all the uppercase letters should be converted to lowercase and all the lowercase letters should be converted to uppercase. You need to then print the resultant String to output.

Input Format:
The first and only line of input contains the String S

Output Format:
Print the resultant String on a single line.

Constraints:
1≤|S|≤100
where |S| denotes the length of string S.
SAMPLE INPUT
abcdE

SAMPLE OUTPUT
ABCDe


#include <stdio.h>
#include <string.h>

int main()
{
    char s[101],i;
    if(fgets(s,101,stdin)!=NULL)
        for(i=0;i<=strlen(s);i++)
            if(s[i]>='A' && s[i]<='Z')
                s[i]='a'+ (s[i]-'A');
            else if(s[i]>='a' && s[i]<='z')
                s[i]='A'+ (s[i]-'a');

    printf("%s",s);
}
*/


/* Best Submissions:
C:
#include <stdio.h>
 
int main()
{
    int c;
 
    while ( (c=getchar()) != EOF ){
        if (c >= 65 & c <= 90)
            c += 32;
        else if (c >= 97 &c <= 122)
            c -= 32;
        
        putchar(c);
    }
        
    return 0;
}
C++:
#include <iostream>
#include <cstring>
using namespace std;
 
int main()
{
    int i;
    string s;
    cin>>s;
    for( i=0;i<=s.size();i++)
        if(s[i]>=65&&s[i]<=90)
           { s[i]+=32;}
       else if(s[i]>=97 && s[i]<=122) 
            s[i]=s[i]-32;
    cout<<s;
    return 0;
}

C++14:
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int i,len=s.length();
    for(i=0;i<len;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
            s[i]=tolower(s[i]);
        else
            s[i]=toupper(s[i]);
    }
    cout<<s<<endl;
    return 0;
}


Java:
import java.util.*;
 
class myClass
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		char[] str = new String(in.nextLine()).toCharArray();
		String a,b;
		
		System.out.println();
		
		for(int i=0;i<str.length;i++)
		{
			a = Character.toString(str[i]);
			b = a.toUpperCase();
			if(a.equals(b))
			{
				System.out.print(a.toLowerCase());
			}
			else
			{
				System.out.print(a.toUpperCase());
			}
		}
	}
}

Java 8:
import java.util.Scanner;
import java.lang.StringBuilder;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        Scanner sc= new Scanner(System.in);
	        String s,s1,sx;
	        char[] temp=new char[100];
	        s=sc.nextLine();
	        int x=s.length();
	        for(int i=0;i<x;i++){
	            char c = s.charAt(i);
	            s1=Character.toString(c);
	        	if(Character.isLowerCase(c)){
	        		sx=s1.toUpperCase();
	        		temp[i]=sx.charAt(0);
	        	 }
	        	else if(Character.isUpperCase(c)){
	        		
	        		 sx=s1.toLowerCase();
	        		temp[i]=sx.charAt(0);
	        	}
	        	else{
	        		temp[i]=c;
	        	}
	        }
	        String s2= new String(temp);
	        s2=s2.substring(0,x);
	        System.out.println(s2);
    }
}


Python:
'''
# Read input from stdin and provide input before running code
name = raw_input()
print 'Hi, %s.' % name
'''
print raw_input().swapcase()

Python 3:
import sys
a = list(sys.stdin.readline())
answer = ''
for elem in a:
	if elem.isupper():
		answer += elem.lower()
	else:
		answer += elem.upper()
print(answer)


JavaScript(Node.js):
function main(s) {
    var a=''
    for(var i in s){
        if(s[i]==s[i].toLowerCase()){
            a+=s[i].toUpperCase()
        }
        else{
            a+=s[i].toLowerCase()
        }
    }
    process.stdout.write(a)
}
 
process.stdin.resume()
process.stdin.setEncoding("utf-8")
var stdin_input = ""
 
process.stdin.on("data", function (input) {
    stdin_input += input
})
 
process.stdin.on("end", function () {
   main(stdin_input)
})
 

JavaScript(Rhino):
importPackage(java.util);
importPackage(java.lang);
importPackage(java.io);
importPackage(java.lang);
 
var sc = new Scanner(System.in);
 
var input = sc.next();
var out=""
for(var i=0;i<input.length();i++)
{
	var c=input.charAt(i);
	if(c===Character.toLowerCase(c))
		out+=String.fromCharCode(Character.toUpperCase(c));
	else
		out+=String.fromCharCode(Character.toLowerCase(c));
}
print(out);

Pascal:
program Hello;
var s,r:string; i,t:byte;
begin
    readln(s);
    r:='';
    repeat 
      inc(i);
      t:=ord(s[i]);
      if (t>=97) then r:=r+chr(t-32) else r:=r+chr(t+32);
    until i=length(s);
    writeln(r); 
     
end.

PHP:
<?php
fscanf(STDIN, "%s\n", $num);
$numlen=strlen($num);
$final='';
if($numlen>1 && $numlen <= 100){
$i=0;
while($d=$num[$i]){
	if ($d >= 'A' && $d <= 'Z'){
		$d=strtolower($d);
	}
	else{
		$d=strtoupper($d);
	}
	$final.=$d;
	$i++;
}
echo $final;
}
?>

Perl:
use strict;
 
#=comment
# Read input from stdin and provide input before running code
 
# Echo input to output.
 
 
while(my $fred = <STDIN>) {
    
    $fred=~tr/A-Za-z/a-zA-Z/;  
    print $fred;
    
}
#=cut

R:
x <- readLines("stdin")
x <- chartr("AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz","aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ",x)
cat(x)

Ruby:
=begin
# Read input from stdin and provide input before running code
 
print "Please enter your name: "
name = gets.chomp
print "Hi #{name}\n"
=end
 
input = gets.chomp.split('')
output = []
 
input.each do |i|
	output << i.swapcase
end
 
puts output.join('')


VB:
Module Main
 
    Sub Main()
        Dim S As String = Console.ReadLine()
	Dim charArray As Char() = S.ToCharArray()
	For i As Integer = 0 To charArray.Length - 1
		charArray(i) = If(Char.IsUpper(charArray(i)), Char.ToLower(charArray(i)), Char.ToUpper(charArray(i)))
	Next
 
	Console.WriteLine(New String(charArray))
    End Sub
 
End Module

*/


/*I/O:
Input #1:
RrHRxcUsSrvSnTyolvsxHoGyzwBMzuLCUjcSeWmBAhodtEkgZjDkFjaXXAvjTvRfHuHGtopoxaeONzFFurfNlRdAvRYlnlfdIMsI
Output #1:

rRhrXCuSsRVsNtYOLVSXhOgYZWbmZUlcuJCsEwMbaHODTeKGzJdKfJAxxaVJtVrFhUhgTOPOXAEonZffURFnLrDaVryLNLFDimSi
Input #2:

MxZJSlbaXqShPGtKludEEBwyaTJwRsUlMMCSwWzkQpgOtSWrNwkkkxMZVtESwfdUOHXKdybIdyVOrvHwLWHgDmEUlaBIUWlsEKRA
Output #2:

mXzjsLBAxQsHpgTkLUDeebWYAtjWrSuLmmcsWwZKqPGoTswRnWKKKXmzvTesWFDuohxkDYBiDYvoRVhWlwhGdMeuLAbiuwLSekra
Input #3:
NxmcyqOnWLhhPuxhvRnEWgJyQPjVuVoIPIjqweGXrLToPBafJzRmErhkflqoaCSppYyAowwhJIndeYhooZpQkpTUjjbMNcdSsfxL
Output #3:

nXMCYQoNwlHHpUXHVrNewGjYqpJvUvOipiJQWEgxRltOpbAFjZrMeRHKFLQOAcsPPyYaOWWHjiNDEyHOOzPqKPtuJJBmnCDsSFXl
Input #4:
OgzCLPSSbWhqZufRHsrqEHIbFzXHdKKNlPJLvfbbbrLPCEhEeKDfhqghUWhBHzKIIEhsGAyIMJLPkvKvjEBtfaarZHgqphBjUcoE
Output #4:

oGZclpssBwHQzUFrhSRQehiBfZxhDkknLpjlVFBBBRlpceHeEkdFHQGHuwHbhZkiieHSgaYimjlpKVkVJebTFAARzhGQPHbJuCOe

*/