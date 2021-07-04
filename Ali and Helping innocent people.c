/* All Tracks -->Basic Programming -->  Input/Output --> Basics of Input/Output-->  Problem -->
Ali and Helping innocent people
Tag(s): Basic Programming, Basics of Input/Output, Easy, Input/Output

Arpasland has surrounded by attackers. A truck enters the city. The driver claims the load is food and medicine from Iranians. 
Ali is one of the soldiers in Arpasland. He doubts about the truck, maybe it's from the siege. He knows that a tag is valid if the sum of every two consecutive digits 
of it is even and its letter is not a vowel. Determine if the tag of the truck is valid or not.

We consider the letters "A","E","I","O","U","Y" to be vowels for this problem.

Input Format
The first line contains a string of length 9. The format is "DDXDDD-DD", where D stands for a digit (non zero) and X is an uppercase english letter.

Output Format
Print "valid" (without quotes) if the tag is valid, print "invalid" otherwise (without quotes)

SAMPLE INPUT 
12X345-67
SAMPLE OUTPUT 
invalid

Explanation:
The tag is invalid because the sum of first and second digit of it is odd (also the sum of 4'th and 5'th, 5'th and 6'th and 8'th and 9'th are odd).

//My C Solution:
#include <stdio.h>

int main(){
    int i,num1=0,num2=0,flag=0;
    char str[9];
    scanf("%s",str);
    for(i=0;i<9;i++){
        if(i==0|| i==3 || i==4 || i==7){
            num1=str[i]-'0';
            num2=str[i+1]-'0';
        }
        if(((num1+num2)%2)==1){
            flag=1;
            break;
        }
        else if((str[2] == 'A') || (str[2] == 'E') || (str[2] == 'I')|| (str[2] == 'O')||(str[2] == 'U')|| (str[2] == 'Y')){
            flag=1;
            break;
        }
    }
    if(!flag)
        printf("%s\n","valid");
    else
        printf("%s\n","invalid");    
    return 0;
}

*/

/*Editorial:
Author Solution by Arpa
// In the name of God.
// You are anything and We're nothing
// Ya ali!
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 17;
string s, vowel = "AEOUIY";
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	bool ok = 1;
	for(auto i : {0, 3, 4, 7})
		ok &= (s[i] + s[i + 1]) % 2 == 0;
	ok &= vowel.find(s[2]) == string::npos;
	cout << (ok ? "valid" : "invalid") << '\n';
}


Tester Solution by Anand Jaisingh
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
// Anand Jaisingh
#include<bits/stdc++.h>
using namespace std;
typedef complex<double> base;
typedef long double ld;
typedef long long ll;
#define pb push_back
#define pii pair<int,int>
#define pll pair< ll , ll >
#define vi vector<int>
#define vvi vector< vi >
const int maxn=(int)(1e5+5);
const ll mod=(ll)(1e9+7);
int a[maxn];
bool check(int pos,char ch)
{
    if((pos>=0 && pos<=1) || (pos>=3 && pos<=5) || (pos>=7 && pos<=8))
    {
        return (ch>='0' && ch<='9');
    }
    if(pos==2)
    {
        return ch>='A' && ch<='Z';
    }
    if(pos==6)
    {
        return ch=='-';
    }
}
bool vowel(char ch)
{
    //cout<<ch<<endl;
    if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='Y')
    {
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;cin>>s;
    bool ans=true;
    for(int i=0;i<s.size();i++)
    {
        assert(check(i,s[i]));
        if(i==2 && vowel(s[i]))
        {
          //  cout<<i<<endl;
            ans=false;
        }
        if(i>=1 && s[i]>='0' && s[i]<='9' && s[i-1]>='0' && s[i-1]<='9')
        {
            int curr=(s[i]-'0')+(s[i-1]-'0');
            if(curr%2==1)
            {
                cout<<i<<endl;
                ans=false;
            }
        }
    }
    cout<<(ans?"valid":"invalid")<<endl;
    return 0;
}

Java Solution 1:

import java.util.*;
class TestClass {
public static void main(String args[] ) throws Exception {

Scanner s = new Scanner(System.in);
String ch = s.next(); 
int i;
boolean flag=false;
for(i=0;i<9;i++)
{
if(!(ch.charAt(2)=='A'||ch.charAt(2)=='E'||ch.charAt(2)=='I'||ch.charAt(2)=='O'||ch.charAt(2)=='U'||ch.charAt(2)=='Y')&&ch.charAt(6)=='-')
{
if(i==2||i==6)
{}
else
{
if(ch.charAt(i)>'0'||ch.charAt(i)<='9')
{
flag=true;
}
else
{
flag=false;
System.out.print("invalid");
break;
}
}
}
else
{
System.out.print("invalid");
break;
}
}
if(flag)
{
int a=Integer.parseInt(String.valueOf(ch.charAt(0)))+Integer.parseInt(String.valueOf(ch.charAt(1)));
int b=Integer.parseInt(String.valueOf(ch.charAt(3)))+Integer.parseInt(String.valueOf(ch.charAt(4)));
int c=Integer.parseInt(String.valueOf(ch.charAt(4)))+Integer.parseInt(String.valueOf(ch.charAt(5)));
int d=Integer.parseInt(String.valueOf(ch.charAt(7)))+Integer.parseInt(String.valueOf(ch.charAt(8)));
if((a%2==0)&&(b%2==0)&&(c%2==0)&&(d%2==0))
System.out.print("valid");
else
System.out.print("invalid");
}
}

}

Java Solution 2:
/This is probably the best solution
import java.util.*;
class Helper_Ali
{
public static void main(String args[] ) throws Exception 
{
Scanner sc=new Scanner(System.in);
String S = sc.nextLine();
String V="AEIOUYaeiouy";
for(int k=0;k<12;k++)
if(S.indexOf(V.charAt(k))>=0)
{
System.out.print("invalid");
System.exit(0);
}

for(int k=0;k<S.length()-1;k++)
{
char c1=S.charAt(k);
char c2=S.charAt(k+1);
if(Character.isDigit(c1) && Character.isDigit(c2))
{
int sum=((int)c1)+((int)c2)-96;
if(sum%2==1)
{
System.out.print("invalid");
System.exit(0);
}
}
}
System.out.print("valid");
}
}
Java Solution 3:

import java.util.*;
class TestClass {
public static void main(String args[] ) throws Exception {

Scanner s = new Scanner(System.in);
String ch = s.next(); 
int i;
boolean flag=false;
for(i=0;i<9;i++)
{
if(!(ch.charAt(2)=='A'||ch.charAt(2)=='E'||ch.charAt(2)=='I'||ch.charAt(2)=='O'||ch.charAt(2)=='U'||ch.charAt(2)=='Y')&&ch.charAt(6)=='-')
{
if(i==2||i==6)
{}
else
{
if(ch.charAt(i)>'0'||ch.charAt(i)<='9')
{
flag=true;
}
else
{
flag=false;
System.out.print("invalid");
break;
}
}
}
else
{
System.out.print("invalid");
break;
}
}
if(flag)
{
int a=Integer.parseInt(String.valueOf(ch.charAt(0)))+Integer.parseInt(String.valueOf(ch.charAt(1)));
int b=Integer.parseInt(String.valueOf(ch.charAt(3)))+Integer.parseInt(String.valueOf(ch.charAt(4)));
int c=Integer.parseInt(String.valueOf(ch.charAt(4)))+Integer.parseInt(String.valueOf(ch.charAt(5)));
int d=Integer.parseInt(String.valueOf(ch.charAt(7)))+Integer.parseInt(String.valueOf(ch.charAt(8)));
if((a%2==0)&&(b%2==0)&&(c%2==0)&&(d%2==0))
System.out.print("valid");
else
System.out.print("invalid");
}
}

}


C++ Solution:

#include<bits/stdc++.h>
using namespace std;
int main()
{
string x;
int a,b,c,d;
cin >> x;
a=x[0]+x[1];
b=x[3]+x[4];
c=x[4]+x[5];
d=x[7]+x[8];
if(a%2==0 && b%2==0 && c%2==0 && d%2==0&& x[2]!='A'&&x[2]!='E'&&
x[2]!='I' && x[2]!='O' && x[2]!='U' && x[2]!='Y')
cout << "valid\n";
else
cout << "invalid\n";

}

simple c++ sol is below:
#include<iostream>
#include<algorithm>
using namespace std;
main()
{
string s;
cin>>s;
sort(s.begin(),s.end());
int l,i;
l=s.size();
for( i=0;i<l;i++)
{
if(s[i]>='0'&&(s[i]<='9'))
{
if(((s[i]+s[i+1])%2)!=0)
{
cout<<"invalid"<<endl;
break;
}
}
else if(s[i]>='a'&&(s[i]<='z'))
{
if((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u'))
{
cout<<"invalid"<<endl;
break;
}
}
}
if(i==l)
cout<<"valid"<<endl;
}

*/


/* I/O:
Input #1:
12X345-67
Output #1:
invalid
Input #2:
13X357-22
Output #2:
valid
Input #3:
13X357-21
Output #3:
invalid
Input #4:
13A357-22
Output #4:
invalid
Input #5:
13E357-22
Output #5:
invalid
Input #6:
13Y357-22
Output #6:
invalid
Input #7:
13U357-22
Output #7:
invalid
Input #8:
13O357-22
Output #8:
invalid
Input #9:
13I357-22
Output #9:
invalid
Input #10:
23X357-22
Output #10:
invalid
Input #11:
13X657-22
Output #11:
invalid
Input #12:
11B242-73
Output #12:
valid

*/


/* Best Submissions:
C:
#include<stdio.h>
int main()
{
    char a[9];
    scanf("%s",a);
    if(a[2]=='A' ||a[2]=='E' ||a[2]=='I' ||a[2]=='O' ||a[2]=='U' ||a[2]=='Y')
    {
        printf("invalid");
    }
    else if((a[0]+a[1])%2==1 ||(a[3]+a[4])%2==1 ||(a[4]+a[5])%2==1 ||(a[7]+a[8])%2==1)
    {
        printf("invalid");
    }
    else
    {
        printf("valid");
    }
}
C++:
#include<iostream>
 
using namespace std;
 
bool check_sum(string str)
{
    int sum1, sum2, sum3, sum4;
    sum1 = str[0] + str[1];
    sum2 = str[3] + str[4];
    sum3 = str[4] + str[5];
    sum4 = str[7] + str[8];
    if((sum1 % 2 == 0) && (sum2 % 2 == 0) && (sum3 % 2 == 0) && (sum4 % 2 == 0))
        return true;
    else
        return false;
}
 
bool check_vowel(string str)
{
    char c = str[2];
    if((c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U') || (c == 'Y'))
        return false;
    else
        return true;
}
 
int main()
{
    string a;
    cin >> a;
    if(check_sum(a) && check_vowel(a))
        cout << "valid";
    else
        cout << "invalid" << endl;
    
    
    return 0;
}
Java:
import java.util.*;
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
        Scanner s = new Scanner(System.in);
String ch = s.next(); 
int i;
boolean flag=false;
for(i=0;i<9;i++)
{
if(!(ch.charAt(2)=='A'||ch.charAt(2)=='E'||ch.charAt(2)=='I'||ch.charAt(2)=='O'||ch.charAt(2)=='U'||ch.charAt(2)=='Y')&&ch.charAt(6)=='-')
{
if(i==2||i==6)
{}
else
{
if(ch.charAt(i)>'0'||ch.charAt(i)<='9')
{
flag=true;
}
else
{
flag=false;
System.out.print("invalid");
break;
}
}
}
else
{
System.out.print("invalid");
break;
}
}
if(flag)
{
int a=Integer.parseInt(String.valueOf(ch.charAt(0)))+Integer.parseInt(String.valueOf(ch.charAt(1)));
int b=Integer.parseInt(String.valueOf(ch.charAt(3)))+Integer.parseInt(String.valueOf(ch.charAt(4)));
int c=Integer.parseInt(String.valueOf(ch.charAt(4)))+Integer.parseInt(String.valueOf(ch.charAt(5)));
int d=Integer.parseInt(String.valueOf(ch.charAt(7)))+Integer.parseInt(String.valueOf(ch.charAt(8)));
if((a%2==0)&&(b%2==0)&&(c%2==0)&&(d%2==0))
System.out.print("valid");
else
System.out.print("invalid");
}
}
}
C#:
using System;
using System.Collections.Generic;
using System.Reflection;
 
class MyClass {
    static void Main(string[] args) {
        
        string str = Console.ReadLine();
        int l = str.Length;
        char[] array = new char[l];
        string[] array1 = { "A", "E", "I","O","U", "Y" };
        int count=0;
        if(l == 9){
            array = str.ToCharArray();
            string s = array[2].ToString();
            if(s == s.ToUpper()) {
                bool a = Array.Exists(array1, element => element == s);
                if(!a) {
                if(array[6]=='-') {
                    for(int i=0; i<l-1; i++) {
                        int temp =0;
                        if(Char.IsDigit(array[i]) && Char.IsDigit(array[i+1])) {
                            temp=(int)Char.GetNumericValue(array[i])+(int)Char.GetNumericValue(array[i+1]);
                            if(temp%2==0) {
                                count++;
                            }
                        }
                    }
                    if(count == 4 ){
                        Console.WriteLine("valid");
                    }
                    else {
                        Console.WriteLine("invalid");
                    }
                }
                }
                else {
                    Console.WriteLine("invalid");
                }
            }
        }    
        
    }
}
PHP:
<?php

// Sample code to perform I/O:
 
//fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
//echo "Hi, ".$name.".\n";                // Writing output to STDOUT
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
// Write your code here
$s=fgets(STDIN);
//echo $s;
$sum=(int)$s[0]+(int)$s[1];
if($sum%2==1)
{
    echo "invalid";
}
else
{
    $x=$s[2];
    //echo $x;
    $flag=0;
    switch($x)
    {
        case 'A':$flag=1;break;
        case 'E':$flag=1;break;
        case 'I':$flag=1;break;
        case 'O':$flag=1;break;
        case 'U':$flag=1;break;
        case 'Y':$flag=1;break;
    }
    if($flag==1)
        echo "invalid";
    else
    {
        $sum=(int)$s[3]+(int)$s[4];
        if($sum%2==1)
            echo "invalid";
        else
        {
            $sum=(int)$s[4]+(int)$s[5];
            if($sum%2==1)
                echo "invalid";
            else
            {
                $sum=(int)$s[7]+(int)$s[8];
                if($sum%2==1)
                    echo "invalid";
                else
                {
                    echo "valid";
                }
            }
        }
    }
}

?>

Python:
'''
# Sample code to perform I/O:
 
name = raw_input()          # Reading input from STDIN
print 'Hi, %s.' % name      # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''
 
# Write your code here
V = ('A','E','I','O','U','Y')
T = raw_input()
SD02 = int(T[:1]) + int(T[1:2])
SD35 = int(T[3:4]) + int(T[4:5])
SD46 = int(T[4:5]) + int(T[5:6])
SD78 = int(T[7:8]) + int(T[8:])
alpha = T[2]
if not SD02%2==0:
    print "invalid"
elif alpha in V:
    print "invalid"
elif not SD35%2==0:
    print "invalid"
elif not SD46%2==0:
    print "invalid"
elif not SD78%2==0:
    print "invalid"
else:
    print "valid"
*/