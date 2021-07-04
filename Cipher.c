/* All Tracks --> Basic Programming -->  Input/Output --> Basics of Input/Output --> Problem -->
Cipher
Tag(s): Easy-Medium
Indian army is going to do a surprise attack on one of its enemies country. 
The President of India, the Supreme Commander of the Indian Army will be sending an alert message to all its commanding centers. 
As enemy would be monitoring the message, Indian army is going to encrypt(cipher) the message using basic encryption technique. 
A decoding key 'K' (number) would be sent secretly.

You are assigned to develop a cipher program to encrypt the message. 
Your cipher must rotate every character in the message by a fixed number making it unreadable by enemies.
Given a single line of string 'S' containing alpha, numeric and symbols, followed by a number '0<=N<=1000'. Encrypt and print the resulting string.
Note: The cipher only encrypts Alpha and Numeric. (A-Z, a-z, and 0-9) . All Symbols, such as - , ; %, remain unencrypted.

SAMPLE INPUT 
All-convoYs-9-be:Alert1.
4

SAMPLE OUTPUT 
Epp-gsrzsCw-3-fi:Epivx5.

Explanation:
First line contains the string to convert. S
Second line contains the number, encrypt key. K
A becomes E, Y becomes C, 9 becomes 3,
-, . unchanged.

//My C Solution:
#include <stdio.h>
#include <string.h>

int main()
{
    char S[1000];
    int k,m,n,p;
    unsigned int i,l;
    scanf("%s",S);
    scanf("%d",&k);
    l=strlen(S);

    for(i=0;i<l;i++)
    {
        if(S[i]>=65 && S[i]<=90)       //If between 'A' and 'Z'
        {
            m=S[i];
            if((m+k)>90)
            {
                m+=k;
                while(m>90)
                    m-=26;
            }
            else
                m+=k;
            S[i]=m;
        }
        else if(S[i]>=97 && S[i]<=122)  //If between 'a' and 'z'
        {
            n=S[i];
            if((n+k)>122)
            {  
                n+=k;
                while(n>122)
                    n-=26;
            }
            else
                n+=k;
            S[i]=n;
        }
        else if(S[i]>=48 && S[i]<=57) //If between '0' and '9'
        {
            p=S[i];
            if((p+k)>57)
            {
                p=(p+k);
                while(p>57)
                    p-=10;
            }
            else
                p+=k;
            S[i]=p;
        }
        printf("%c",S[i]);
    }
    return 0;
}

//My Cpp solution:
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int k,m,n,p;
    unsigned int i;
    cin>>s;
    cin>>k;
    unsigned int l=s.length();
    for(i=0;i<l;i++)
    {
        if(s.at(i)>=65&&s.at(i)<=90)
        {
            m=s.at(i);
            if((m+k)>90)
            {
                m+=k;
                while(m>90)
                {
                    m-=26;
                }
            }
            else {m+=k;}
            s.at(i)=m;
        }

        else if(s.at(i)>=97&&s.at(i)<=122)
        {
            n=s.at(i);
            if((n+k)>122)
             {  n+=k;
                 while(n>122)
                {
                    n-=26;
                }
             }
            else {n+=k;}
            s.at(i)=n;
        }

        else if(s.at(i)>='0'&&s.at(i)<='9')
        {
            p=s.at(i);
            if((p+k)>'9')
             {p=(p+k);
                 while(p>'9')
                 {
                     p-=10;
                 }
             }
            else {p+=k;}
            s.at(i)=p;
        }

    }
    cout<<s;
    return 0;
}

*/

/*I/O:
In #1:
All-convoYs-9-be:Alert1.
4
Out #1:
Epp-gsrzsCw-3-fi:Epivx5.

In #2:
abcdZXYzxy-999.@
200
Out #2:
stuvRPQrpq-999.@

In #3:
----------a
100
Out #3:
----------w

In #4:
AaZz190./Usa
26
Out #4:
AaZz756./Usa

In #5:
AaZz190./Usa
27
Out #5:
BbAa867./Vtb

*/

/*Best Submissions:
BASH:
# Sample bash code
 
 
read -r line
read -r key
 
encrypted=""
 
while read -n1 char; do
    code=$(printf "%d" "'$char")
    if [ "$code" -ge 65 -a "$code" -le 90 ]; then
        code=$(( $(( $code + $key - 65 )) % $(( 90 - 65 + 1 )) + 65 ))
    elif [ "$code" -ge 97 -a "$code" -le 122 ]; then
        code=$(( $(( $code + $key - 97 )) % $(( 122 - 97 + 1 )) + 97 ))
    elif [ "$code" -ge 48 -a "$code" -le 57 ]; then
        code=$(( $(( $code + $key - 48 )) % $(( 57 - 48 + 1 )) + 48 ))
    fi
    encrypted=${encrypted}$(printf %b $(printf '\\%03o' "$code"))
done < <(printf "%s" "$line")
 
echo "$encrypted"

C:
#include<stdio.h>
void main()
{
    char a[1000];
    int d,b,c,i,flag = 1,k,l;
    scanf("%s%d",a,&k);
     l = k%10;
    //if(k!=26)
    k = k%26;
        for(i=0;a[i] != '\0';i++)
        {
            if((a[i]>=65)&&(a[i]<=(90-k)))
                a[i] = a[i] + k;
            else if((a[i]>=97)&&(a[i]<=(122-k)))
                a[i] = a[i] + k;
            else if((a[i]>=48)&&(a[i]<=(57-l)))
                a[i] = a[i] + l;
            else if((a[i]>(90-k))&&(a[i]<=90))
            {
                d = 90 - a[i];
                b = k - d;
                a[i] = 64 + b;
            }
            else if((a[i]>(122-k))&&(a[i]<=122))
            {
                d = 122 - a[i];
                b = k -  d;
                a[i] = 96 + b;
            }
            else if((a[i]>(57-l))&&(a[i]<=57))
            {
                d = 57 - a[i];
                b = l - d;
                a[i] = 47 + b;
            }
        }
        printf("%s",a);
}

C++:
#include<stdio.h>
#include<string.h>
 
int main()
{
	int i,j,k,l,n,m;
	char a[10000];
	scanf("%s",&a);
	scanf("%d",&n);
	l=n;j=n;k=n;
	m=strlen(a);
	for(i=0;i<m;i++){
		if(a[i]>=65 && a[i]<=90){
			while(k>26){
				k=k-26;
			}
			if(a[i]+k>90){
			    a[i]=a[i]+k-26;
			    printf("%c",a[i]);
		    }
		    else{
		    	a[i]=a[i]+k;
		    	printf("%c",a[i]);
			}
	    }
	    else if(a[i]>=97 && a[i]<=122){
	    	while(j>26){
	    		j=j-26;
			}
	    	if(a[i]+j>122){
			    a[i]=a[i]+j-26;
			    printf("%c",a[i]);
		    }
		    else{
		    	a[i]=a[i]+j;
		    	printf("%c",a[i]);
			}
		}
		else if(a[i]>=48 && a[i]<=57){
			while(l>10){
				l=l-10;
			}
			if(a[i]+l>57){
			    a[i]=a[i]+l-10;
			    printf("%c",a[i]);
		    }
		    else{
		    	a[i]=a[i]+l;
		    	printf("%c",a[i]);
			}
		}
		else{
			printf("%c",a[i]);
		}
    }
    return 0;
}

C++14:
#include<iostream>
using namespace std;
main()
{
	string s;
	cin>>s;
	int n,k;
	cin>>n;
	k=n;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]<=57&&s[i]>=48)
		{
			k=n%10;
			if(k>57-s[i])
				s[i]=k-10+s[i];
			else
				s[i]=s[i]+k;
		}
		else if(s[i]<=90&&s[i]>=65)
		{
			k=n%26;
			if(k>90-s[i])
				s[i]=k-26+s[i];
			else
				s[i]=s[i]+k;
		}
		else if(s[i]<=122&&s[i]>=97)
		{
			k=n%26;
			if(k>122-s[i])
				s[i]=k-26+s[i];
			else
				s[i]=s[i]+k;
		}
	}
	cout<<s;
}

C#:
using System;
 
namespace HackerEarth_BrickGame_006
{
    class Program
    {
        static void Main(string[] args)
        {
                string STRING = Console.ReadLine();
                int K = Convert.ToInt32(Console.ReadLine());
                for (int i=0; i<STRING.Length; i++)
                {
                    int t=Convert.ToInt32(STRING[i]);
                    int offset=((t>47 && t<58)||(t>64 && t<91)||(t>96 && t<123))?K:0;
                    //offset=(t+offset>57)?(offset-10):offset;
                    t=(t>47 && t<58)?(48+(t-48+offset)%10):t;
                    t=(t>64 && t<91)?(65+(t-65+offset)%26):t;
                    t=(t>96 && t<123)?(97+(t-97+offset)%26):t;
                    //((48+(t-48+offset)%offset)
                    //offset=(t+offset<57)?(offset-10):offset;
                    //offset=(t>96 && t<123)?K:0;
 
                  Console.Write(Convert.ToChar(t));
                }
        }
    }
}

Java:
import java.util.*;
import java.io.*;
public class Solution
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        char[] arr = str.toCharArray();
        int n = Integer.parseInt(br.readLine());
        int rotateAlpha = n % 26;
        int rotateNum = n % 10;
        for(int i = 0 ; i < arr.length ; i++)
        {
            if(arr[i] >= 65 && arr[i] <= 90)
            {
 
                arr[i] = (char)(((arr[i] - 65 + rotateAlpha) % 26) + 65);
            }
            else if(arr[i] >= 97 && arr[i] <= 122)
            {
                arr[i] = (char)(((arr[i] - 97 + rotateAlpha) % 26) + 97);
            }
            else if(arr[i] >= 48 && arr[i] <= 57)
            {
                arr[i] = (char)(((arr[i] - 48 + rotateNum) % 10) + 48);
            }
        }
        System.out.println(new String(arr));
    }
        
}

Java 8:
//import for Scanner and other utility classes
import java.util.*;
 
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static void main(String args[] ) throws Exception {
      
        //Scanner
        Scanner s = new Scanner(System.in);
        String name = s.nextLine();   
        int k=s.nextInt();// Reading input from STDIN
        char cipher[]=name.toCharArray();
        String a="abcdefghijklmnopqrstuvwxyz";
        char alphabet[]=a.toCharArray();
        String al="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char alphacap[]=al.toCharArray();
        int num[]=new int[]{0,1,2,3,4,5,6,7,8,9};
        for(int i=0;i<cipher.length;i++)
        {
            if(Character.isDigit(cipher[i]))
            {
                int n=Character.getNumericValue(cipher[i]);
                {
                    n=(n+k)%10;
                    n+=48;
                    cipher[i]=(char)n;
                    
                }
                
            }
            else if(Character.isLetter(cipher[i]))
            {
                
                int flag=0;
                if(Character.isUpperCase(cipher[i]))
                flag=1;
                if(flag==0)
                {
                    for(int j=0;j<alphabet.length;j++)
                    {
                        if(cipher[i]==alphabet[j])
                        {
                            j=(j+k)%26;
                            cipher[i]=alphabet[j];
                            break;
                        }
                    }
                    
                }
                else
                {
                    for(int j=0;j<alphacap.length;j++)
                    {
                        if(cipher[i]==alphacap[j])
                        {
                            j=(j+k)%26;
                            cipher[i]=alphacap[j];
                            break;
                        }
                    }
                    
                }
                
               
                
            }
        }
        for(int i=0;i<cipher.length;i++)
        System.out.print(cipher[i]);
 
        
 
        // Write your code here
 
    }
}

JavaScript(Node.js):
process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
 
process.stdin.on("data", function (input) {
    stdin_input += input;                               // Reading input from STDIN
});
 
process.stdin.on("end", function () {
   main(stdin_input.split('\n'));
});
 
function main(input) {
  var string = input[0], k = Number(input[1]);
  console.log( encrypt(string, k) );
}
 
function encrypt(string, key) {
  let length = string.length, result = '';
  for (let i = 0; i < length; i++) {
    let code = string[i].charCodeAt();
    if(code >= 65 && code <= 90) { //A-Z
      code = mapTo(code + key, 65, 90);
    } else if(code >= 97 && code <= 122) { //a-z
      code = mapTo(code + key, 97, 122);
    } else if(code >= 48 && code <= 57) { //0-9
      code = mapTo(code + key, 48, 57);
    }
    result += String.fromCharCode(code);
  }
  return result;
}
 
function mapTo(n, start, end) {
  if(n > end) {
    const diff = end - start + 1;
    const overflow = (n - start) % diff;
    return start + overflow;
  }
  return n;
}

Pascal:
const num=48;up=65;low=97;
var s:ansistring;
n,i,ch:integer;
begin
    readln(s);
    readln(n);
    for i:=1 to length(s) do
    if (s[i]<>'-') and (s[i]<>',') and (s[i]<>'.') and (s[i]<>':') and (s[i]<>'@') and (s[i]<>'/') then
    begin
        ch:=ord(s[i]);
        if (ch>=low) then
        write(chr(((ch-low+n) mod 26)+low))
        else
        if (ch>=up) then
        write(chr(((ch-up+n) mod 26)+up))
        else
        if (ch>=num) then
        write(chr(((ch-num+n) mod 10)+num));
    end
    else write(s[i]);
end.

Perl:
=comment
# Sample code to perform I/O:
 
my $name = <STDIN>;             # Reading input from STDIN
print "Hi, $name.\n";           # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
=cut
 
# Write your code here
use Data::Dumper;
my %l,%m;
my $i=1;
for (a..z) {
    $l{$i} = $_;
    $m{$_} = $i;
    $i++;
}
my $out;
my $s= <STDIN>;
my $n = <STDIN>;
my @a = split('',$s);
foreach my $c (@a) {
    if( $c =~ /[a-zA-Z]/) {
        my $upper_case;
        if($c eq uc $c) {
            $upper_case = 1;
        }
        my $pos = $m{lc $c}+$n;
        while ($pos > 26) {
            $pos -= 26;
        }
        $c = $l{$pos};
        if ($upper_case) {
            $c = uc $c;
        }
    }
    elsif($c =~ /[0-9]/) {
        my $s = $c + $n;
        if ($s =~ /(\d)$/) {
            $c = $1;
        } 
    }
    print $c;
}

PHP:
<?php
fscanf(STDIN, "%s", $string);
fscanf(STDIN, "%d", $n);
 
foreach(str_split(trim($string)) AS $c){
    if(ctype_alnum(trim($c))){
        if(ctype_digit(trim($c))){
            $i = ord($c);
            $nn = $n;
            if($n > 10){
                $nn = $n % 10;
            }
            $t = $i + $nn;
            if($t > 57){
                $t = $t - 57;
                echo chr(47 + $t);
            }else{
                echo chr($t);
            }
        }else{
            if(ctype_lower(trim($c))){
                $i = ord($c);
                $nn = $n;
                if($n > 26){
                    $nn = $n % 26;
                }
                $t = $i + $nn;
                if($t > 122){
                    $t = $t - 122;
                    echo chr(96 + $t);
                }else{
                    echo chr($t);
                }
            }else if(ctype_upper(trim($c))){
                $i = ord($c);
                $nn = $n;
                if($n > 26){
                    $nn = $n % 26;
                }
                $t = $i + $nn;
                if($t > 90){
                    $t = $t - 90;
                    echo chr(64 + $t);
                }else{
                    echo chr($t);
                }
            }
        }
    }else{
        echo $c;
    }
}
 
?>

Python:
msg = raw_input('')
key = input('')
alphabet = 'abcdefghijklmnopqrstuvwxyz'
ALPHABET = alphabet.upper()
temp = ''
 
for char in msg:
    if char.isalnum():
        if char in alphabet:
            
            ind = alphabet.index(char) + key
            if ind > len(alphabet) - 1:
                ind = ind % len(alphabet)
            temp += alphabet[ind]
            
        elif char in ALPHABET:
            
            ind = ALPHABET.index(char) + key
            if ind > len(ALPHABET) - 1:
                ind = ind % len(ALPHABET)
            temp += ALPHABET[ind]
        
        else:
            
            ind = int(char) + key
            if ind > 9:
                ind = (ind % 10)
            temp += str(ind)
    else:
        temp += char
 
print temp

Python 3:
# Write your code here
import string
a=string.ascii_lowercase
A=string.ascii_uppercase
i=input()
k=int(input())
for t in i:
    b=a.find(t)
    B=A.find(t)
    if t.isdigit() :
        print(str((int(t)+k)%10),end="")
    elif b!=-1:
        print(a[(b+k)%26],end="")
    elif B!=-1:
        print(A[(B+k)%26],end="")
    else:
        print(t,end="")


Ruby:
=begin
# Sample code to perform I/O:
 
name = gets.chomp                # Reading input from STDIN
print "Hi, #{name}.\n"           # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
=end
 
# Write your code here
str=gets.chomp
n=gets.chomp.to_i
for i in 0..str.length-1
if (95<str[i].ord&&str[i].ord<123)
  b=n
  if(b>26)
    b=b%26
end
  a=str[i].ord+b
    if a>122
    a=a-26
    end
 print a.chr
elsif (64<str[i].ord&&str[i].ord<91)
b=n
if(b>26)
    b=b%26
end
  a=str[i].ord+b
    if a>90
    a=a-26
    end
  print a.chr
elsif(47<str[i].ord&&str[i].ord<58)
b=n
if(b>10)
    b=b%10
end
  a=str[i].ord+b
    if a>57
    a=a-10
    end
  print a.chr
else
  print str[i]
end
end



*/



