/* All Tracks  -->  Basic Programming  -->  Implementation  -->  Basics of Implementation 
Little Jhool and psychic powers
Tag(s): Ad-Hoc, Basic Programming, Implementation, Very Easy, Very-Easy
Little Jhool always wanted to have some psychic powers so that he could showoff his skills, and magic to people and impress them. 
(Specially, his girlfriend Big Jhool!) But, in spite all his efforts, hardwork, dedication, Googling, watching youtube videos he couldn't garner any psychic abilities!
He knew everyone was making fun of him, so to stop all of that - he came up with a smart plan. Anyone who came to him to know about their future, he asked them to write a 
binary number for him - and then, he smartly told them if the future for that person had good in store, or bad.

The algorithm which Little Jhool follows is, as following:
If the binary number written by the person has six consecutive 0s, or 1s, his future is bad.
Otherwise, he says that their future is good.

Input format:
Single line contains a binary number.

Output format:
You need to print "Good luck!" (Without quotes, and WITH exclamation mark!) if the Jhool is going to tell them that they're going to have a good time. 
Else, print "Sorry, sorry!" if the person is going to be told that he'll have a hard time!

Constraints:
The binary number will be in string format, with the maximum length being 100 characters.

SAMPLE INPUT 
0001111110

SAMPLE OUTPUT 
Sorry, sorry!

Explanation:
Since the binary number given has six consecutive 1s, little Jhool tells the man that he's going to have a bad time!

My C Solution:
#include <stdio.h>
#define N 100
 
int main()
{
    char str[N];
    int i,j,cnt0,cnt1;
    scanf("%s",str);
    i=0;
    while(str[i]!='\0')
        i++;
    cnt0=0;
    cnt1=0;
    for(j=0;j<i;j++){
        if(str[j]=='0'){
            if(cnt0>=1){
                if(cnt1<6)
                    cnt1=0;
                cnt0++;
            }
            else if(cnt0==0)
                cnt0++;
        }
        else{
            if(cnt1>=1){
                if(cnt0<6)
                    cnt0=0;
                cnt1++;
            }
            else if(cnt1==0){
                cnt1++;
            }
        }
    }
    if(cnt0>=6 || cnt1>=6)
        printf("Sorry, sorry!\n");
    else
        printf("Good luck!\n");
    return 0;
}
*/

/* My Cpp solution :
#include <iostream>
using namespace std;
#define N 100
 
int main()
{
    char str[N];
    int i,j,cnt0,cnt1;
    cin>>str;
    i=0;
    while(str[i]!='\0')
        i++;
    cnt0=0;
    cnt1=0;
    for(j=0;j<i;j++){
        if(str[j]=='0'){
            if(cnt0>=1){
                if(cnt1<6)
                    cnt1=0;
                cnt0++;
            }
            else if(cnt0==0)
                cnt0++;
        }
        else{
            if(cnt1>=1){
                if(cnt0<6)
                    cnt0=0;
                cnt1++;
            }
            else if(cnt1==0){
                cnt1++;
            }
        }
    }
    if(cnt0>=6 || cnt1>=6)
        cout<<"Sorry, sorry!\n";
    else
        cout<<"Good luck!\n";
    return 0;
}
*/


/* Editorial:
Time Complexity: O(No of digits).
Memory Complexity:  O(No of digits).

Solution in C++:
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    cin >> s;

    for(int i = 0; i + 6 <= s.size(); i++){

        // check for 6 consecutive similar numbers

        if(s[i] == s[i + 1] && s[i] == s[i + 2] && s[i] == s[i + 3] && s[i] == s[i + 4] && s[i] == s[i + 5]){

            cout << "Sorry, sorry!";                
            return 0;
        }
    }

    cout << "Good luck!";

    return 0;
}

Alternate C++ solution:
#include<bits/stdc++.h>
using namespace std;
int main()
{
string s,s0="000000",s1="111111";
cin>>s;
int a,b;
a=s.find(s0);
b=s.find(s1);
if(a>=0 || b>=0)
cout<<"Sorry, sorry!";
else
cout<<"Good luck!";

}

Author Solution by Arjit Srivastava
a = raw_input()
print 'Sorry, sorry!' if '0'*6 in a or '1'*6 in a else 'Good luck!'

*/

/*
In#1
11000000011
Out #1
Sorry, sorry!

In#2
100000111110
Out #2
Good luck!

In#3
0
Out #3
Good luck!

In#4
1000111000111000111000111
Out #4
Good luck!

In#5
11111111111111
Out #5
Sorry, sorry!

In#6
000111000
Out #6
Good luck!

In#7
1111010100010100101011101100101101110011000010100010000001111100010011100101010001101111000001011000
Out #7
Sorry, sorry!

In#8
00000001
Out #8
Sorry, sorry!

In#9
1111111
Out #9
Sorry, sorry!

In #10
0101100011001110001110100111100011010101011000000000110110010010111100101111010111100011101100100101
Out #10
Sorry, sorry!


*/

/*Best Submissions:
C:
#include <stdio.h>
 
int main()
{
    char bin[100];
    int i=1,count=1;
    scanf("%s",bin);
    do
    {
    	if(bin[i-1]==bin[i])
    	{
    		count++;
    		if(count==6)
    			break;
    	}
    		else count=1;
    	i++;
    }while(bin[i]!='\0');
    if(count!=6)
    	printf("Good luck!\n");
    	else printf("Sorry, sorry!\n");
    return 0;
}


C++:
#include <iostream>
using namespace std;
 
int main()
{
	string s;
	cin >> s;
	
	
	int count = 1;
	char t = s.at(0);
	for(int i=1; i<s.length(); i++){
		if(s.at(i) == t){
			count++;
			if(count >= 6) {
				cout << "Sorry, sorry!" << endl;
				
				return 0;
			}
		} else {
			t = s.at(i);
			count = 1;
		}
	}
    cout << "Good luck!" << endl;
    return 0;
}

C++14:
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    
    int i = 0;
    int count = 0;
    while(i < s.length())
    {
        if(s[i] == '0')
        {
            ++i;
            count = 1;
            while(i < s.length() && s[i] == '0')
            {
                count++;
                i++;
            }
            
            if(count >= 6)
            {
                cout<<"Sorry, sorry!"<<endl;
                break;
            }
        }
        else
        {
            ++i;
            count = 1;
            while(i<s.length() && s[i] == '1')
            {
                count++;
                i++;
            }
            
            if(count>=6)
            {
                cout<<"Sorry, sorry!"<<endl;
                break;
            }
        }
        count = 0;
    }
    
    if(i == s.length()  && count <6)
    {
        cout<<"Good luck!"<<endl;
    }
    return 0;
}


JAVA:
import java.util.Scanner;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        Scanner sc=new Scanner(System.in);
        String str=sc.next();
        char arr[]=str.toCharArray();
        boolean flag=false;
        int count1=0;
        int count0=0;
        for(int i=0;i<str.length()-1;i++)
        {
        	if((arr[i]=='1')&&(arr[i+1]=='1'))
        	count1++;
        	else if((arr[i]=='0')&&(arr[i+1]=='0'))
        	count0++;
        	else
        	{
        		count1=0;
        		count0=0;
        	}
        	if((count1>=5)||(count0>=5))
        	{
        		flag=true;
        		break;
        	}
        
        }
        if(flag)
        System.out.println("Sorry, sorry!");
        else
        System.out.println("Good luck!" );
    }
}

Java8:
import java.util.*;
 
class TestClass {
    
    private static final String SIX_ZERO = "000000";
    private static final String SIX_ONE = "111111";
    private static final String SORRY_SORRY = "Sorry, sorry!";
    private static final String GOOD_LUCK = "Good luck!";
    
    public static void main(String args[] ) throws Exception {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        if (str.contains(SIX_ONE) || str.contains(SIX_ZERO)) {
            System.out.println(SORRY_SORRY);
        }
        else {
            System.out.println(GOOD_LUCK);
        }
    }
}


C#:
using System; 
using System.Numerics;
using System.Collections.Generic;
using System.Linq;
class MyClass {
    static void Main(string[] args) {
       string str = Console.ReadLine();
       int Onecount = 0;
       int Zerocount = 0;
       
       
       foreach(char c in str){
           if(c.Equals('0')){
               Zerocount++;
               Onecount=0;
           }
           else if (c.Equals('1')){
               Onecount++;
               Zerocount=0;
           }
            
            
            if(Onecount==6 || Zerocount == 6){
                Console.WriteLine("Sorry, sorry!");
                return;
            }
       }
       
       Console.WriteLine("Good luck!");
    }
}

Python:
import sys
b = list(sys.stdin.readline().strip())
last = b[0]
counter = 0
for i in range(1, len(b)):
    #print last == b[i], counter
    if last == b[i]:
        counter +=1
    else:
        counter = 0
    if counter >= 5:
        print "Sorry, sorry!"
        break
    last = b[i]
if counter <5:
    print "Good luck!"

Python 3:
num=input()
if(num.find("000000")==-1 and num.find("111111")==-1):
    print ("Good luck!")
else:
    print ("Sorry, sorry!")

PASCAL:
program psychic;
var	s:string;
	c:array[1..100] of byte;
	max,k,i:byte;
begin
    readln(s);
    c[length(s)]:=1;
    max:=0;
    for k:=length(s)-1 downto 1 do
    	if s[k+1] = s[k] then c[k]:=c[k+1] + 1 else c[k]:=1;
    for i:=1 to length(s) do
    	if c[i] > max then max:=c[i];
	if max<6 then write ('Good luck!') else write('Sorry, sorry!');
end.


Perl:
use strict;
 
$a=<>;
my @b=(split //,$a);
my $count=scalar(@b);
 
if($count < 6){
			print "Good luck!\n";
			exit;
	}
 
for (my $i=0;$i<($count - 5);$i++){
	if($b[$i] == 0){
	 if (($b[$i] || $b[$i + 1] || $b[$i + 2] || $b[$i + 3] || $b[$i + 4] || $b[$i + 5]) == 0){
	 	print "Sorry, sorry!\n";
	 	exit
	 	}
	 	}
	 	else{
	 		if(($b[$i] && $b[$i + 1] && $b[$i + 2] && $b[$i + 3] && $b[$i + 4] && $b[$i + 5]) == 1){
	 				 	print "Sorry, sorry!\n";
					 	exit
	 			}
	 		}
}
		print "Good luck!\n";


PHP:
<?php
 
fscanf(STDIN, "%s\n", $name);
        
        $name = str_split($name);
        $c = 0;
        $x = $name[0];
        $y = 0;
        foreach($name as $n) {
            
            if($x == '1' && $n == '1' ) {
                $c++;
                if($c>=6){break;}
            }
            elseif ($x == '1' && $n == '0') {
            	$y++;
            	if($y>=6){break;}
                $c = 0;
            }
            elseif($x == '0' && $n == '0' ) {
            	
                $y++;
                if($y>=6){break;}
            }
            elseif ($x == '0' && $n == '1') {
                $c++;
                if($c>=6){break;}
                $y = 0;
            }
            $x = $n;
        }
        if($c >= 6 || $y >= 6) {
            
            $str = "Sorry, sorry!";
        }
        else {
            $str = "Good luck!";
        }
        echo $str;
 
 
 
?>


*/