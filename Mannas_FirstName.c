/*All Tracks  --> Algorithms --> Searching -->  Linear Search  --> Problem -->
Manna's First Name
Tag(s): Easy
Manna is extremely disappointed to find out that no one in his college knows his first name. 
Even his classmates call him only by his last name. 
Frustrated, he decides to make his fellow college students know his first name by forcing them to solve this question.

You are given a long string as input in each testcase, containing any ASCII character. 
Your task is to find out the number of times SUVO and SUVOJIT appears in it.

Note: This problem must be solved in C language only.

Input Format
The first line contains the number of testcases, T. Next, T lines follow each containing a long string S.

Output Format
For each long string S, display the no. of times SUVO and SUVOJIT appears in it.

Constraints:
1 <= T <= 100
1 <= Length of each string <= 150

SAMPLE INPUT
3
SUVOJITSU
651SUVOMN
$$$$$SUVOSUVOJIT$$$$$

SAMPLE OUTPUT:
SUVO = 0, SUVOJIT = 1
SUVO = 1, SUVOJIT = 0
SUVO = 1, SUVOJIT = 1



#include <stdio.h>
#define LEN 151

void find_substrs(char str[]);

int main()
{
    char str[LEN],t;
    int i=0,len=0;
    char *ptr;
    
    fscanf(stdin,"%d",&t);
    fgetc(stdin);
    
    for(i=1;i<=t;i++){
        if(fgets(str,LEN,stdin)!=NULL)
                ;
        ptr=(char *)(&str[0]);
        
        len=strlen(ptr);
        if(str[len-1]=='\n')
            str[len-1]='\0';
        
        ptr=(char *)(&str[0]);

        find_substrs(ptr);
    }

    return 0;
}

void find_substrs(char str[]){
    char *str1="SUVO";
    char *str2="SUVOJIT";
    char *s1=str1;
    char *s2=str2;
    char *s=(char *)(&str[0]);
    int cnt1=0,cnt2=0;
    
    while(*s!='\0'){
        if(*str2!='\0'){
            if(*str1==*s && *str2==*s){
                str1++;
                str2++;
                s++;
            }
            else if(*str2!=*s && *str1=='\0'){
                cnt1++;
                str1=s1;
                str2=s2;
            }
            else if(*str2==*s){
                s++;
                str2++;
            }
            else{
                str1=s1;
                str2=s2;
                if(*str1==*s && *str2==*s)
                    ;
                else
                    s++;
            }
        }
        else{
            cnt2++;
            str2=s2;
            str1=s1;
        }
    }

    if(*str2=='\0' && *str1=='\0'){
        cnt2++;
        str1=s1;
    }
    
    if(*str1=='\0')
        cnt1++;
    
    printf("SUVO = %d, ",cnt1);
    printf("SUVOJIT = %d\n",cnt2);
}

*/

/*Best Submissions:
C:
#include <stdio.h>
 
int main()
{
    int TestCases=0;
    //scan testcases
    scanf("%d",&TestCases);
    while(TestCases)
    {
    	char text[101];
    	int countSUVO=0;
    	int countSUVOJIT=0;
    	//scan text
    	scanf("%s",&text);
    	for(int i=0; text[i]!=NULL;i++)
    	{
    		if(text[i]=='S' && text[i+1]=='U' && text[i+2]=='V' && text[i+3]=='O')
    		{
    			if(text[i+4]=='J' && text[i+5]=='I' && text[i+6]=='T')
    			{
    				countSUVOJIT++;
    				i=i+6;
    			}
    			else
    			{
    				countSUVO++;
    				i=i+3;
    			}
    		}
    	}
    	printf("SUVO = %d, SUVOJIT = %d\n",countSUVO,countSUVOJIT);
    	TestCases--;
    }
    return 0;
}

C++:
#include <iostream>
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
    int t; cin>>t; cin.ignore();while (t--) {
    	int suvojit = 0;
    	int suvo = 0;
    	string s; getline(cin,s);
    	for (int i =0;i<s.size();i++) {
    		if (s[i]=='S') {
    			if (i+6<s.size() && s[i+1]=='U' && s[i+2]=='V' && s[i+3]=='O' && s[i+4]=='J' && s[i+5]=='I' && s[i+6]=='T') {
    				suvojit++;
    			} else if (i+3<s.size() && s[i+1]=='U' && s[i+2]=='V' && s[i+3]=='O') {
    				suvo++;
    			}
    		}
    	}
    	cout<<"SUVO = "<<suvo<<", SUVOJIT = "<<suvojit<<endl;
    }
    return 0;
}

C++14:
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int c1=0,c2=0;
        if(s.length()<4)
            goto LAST;
        for(int i=0;i<=s.length()-4;i++)
        {
            if(s[i]=='S'&&s[i+1]=='U'&&s[i+2]=='V'&&s[i+3]=='O')
                c1++;
        }
        if(s.length()<7)
            goto LAST;
        for(int i=0;i<=s.length()-7;i++)
        {
            if(s[i]=='S'&&s[i+1]=='U'&&s[i+2]=='V'&&s[i+3]=='O'&&s[i+4]=='J'&&s[i+5]=='I'&&s[i+6]=='T')
                c2++;
        }
        LAST:cout<<"SUVO = "<<c1-c2<<", "<<"SUVOJIT = "<<c2<<'\n';
    }
    return 0;
}

C#:
using System; 
using System.Numerics;
public class MyClass {
   public static void Main(string[] args) {
        
        // Read input from stdin and provide input before running
        //var line1 = System.Console.ReadLine().Trim();
        //var N = Int32.Parse(line1);
        //for (var i = 0; i < N; i++) {
        //    System.Console.WriteLine("hello world");
        //}
        //
        int n = Int32.Parse(Console.ReadLine());
        string[] str = new string[n];
        int suvojit=0, suvo=0;
        for(int j=0; j<n;j++){
            str[j]=Console.ReadLine();
            
        }
        
            foreach( var item in str){
          // Console.WriteLine(item);
           for(int i = 0; i<item.Length;i++){
                // Console.WriteLine(item);
                 //Console.WriteLine("Hello Worlds");
               if(item[i]=='S' && item.Length-1 >=3){
                   if((item.Length-1)-i >=6){
                       if(item[i+1]=='U' && item[i+2]=='V' && item[i+3]=='O' &&  item[i+4]=='J' && item[i+5]=='I' && item[i+6]=='T')
                  
                   {
                       suvojit++;
                       i=i+5;
                       continue;
                       
                   }
                   }
                   if((item.Length-1)-i >=3){
                   if(item[i+1]=='U' && item[i+2]=='V' && item[i+3]=='O' )
                   {
                       suvo++;
                       i=i+2;
                       
                   }
                   }
                   
               }
              
           }
            Console.WriteLine("SUVO = {0}, SUVOJIT = {1}",suvo,suvojit );
                   suvojit=0; suvo=0;
        }
       
       // System.Console.WriteLine("Hello World!\n");
    }
}

Java:
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
 
class TestClass {
    public static void main(String args[] ) throws Exception {
BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while (t--!=0) {
            String s = in.readLine();
                       // char[] s = in.next().toCharArray();
            int count1 = 0;
            int count2 = 0;
            int j = 0;
            for (; j < s.length() - 3; j++) {
                if (s.charAt(j) == 'S' && s.charAt(j + 1) == 'U' && s.charAt(j + 2) == 'V' && s.charAt(j + 3) == 'O') {
                    count1++;
                }
            }
 
            for (j = 0; j < s.length() - 6; j++) {
                if (s.charAt(j) == 'S' && s.charAt(j + 1) == 'U' && s.charAt(j + 2) == 'V' && s.charAt(j + 3) == 'O' && s.charAt(j + 4) == 'J' && s.charAt(j + 5) == 'I' && s.charAt(j + 6) == 'T') {
                    count2++;
                }
            }
            int p = count1 - count2;
            System.out.println("SUVO = " + p + ", SUVOJIT = " + count2);
        }
    }
}

Java8:
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
 
class TestClass {
    public static void main(String args[]) throws Exception {
 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		String[] strs = line.trim().split("\\s+");
		int size = Integer.parseInt(strs[0]);
 
		int suvoCount = 0;
		int suvojitCount = 0;
		
		//read each line
		for (int i = 0; i < size; i++) {
			line = br.readLine();
			strs = line.trim().split("\\s+");
			
			for (int j = 0; j < strs[0].length(); j++) {
				
				if ( strs[0].substring(j).startsWith("SUVOJIT")) {
					suvojitCount++;
				} else if (strs[0].substring(j).startsWith("SUVO")) {
					suvoCount++;
				}
			}
			System.out.println("SUVO = " + suvoCount + ", SUVOJIT = " + suvojitCount);
		    suvoCount = 0;  suvojitCount = 0;
		}
		
	}
}

Python:
import sys
 
 
def suvo(palabra):
    return palabra.replace('SUVO','',1)
 
def suvojit(palabra):
    return palabra.replace('SUVOJIT','',1)
 
T = int(sys.stdin.readline().strip())
 
while T>0 and T<=100 :
    palabra = sys.stdin.readline()
 
    contador_suvo = 0
    contador_suvojit = 0
    while ('SUVOJIT' in palabra):
        palabra = suvojit(palabra)
        contador_suvojit+=1
    while ('SUVO' in palabra):
        palabra = suvo(palabra)
        contador_suvo+=1
    T-=1
    print 'SUVO = %s, SUVOJIT = %s' %(contador_suvo,contador_suvojit)

Python 3:
t=int(input())
for _ in range(t):
    suvojit=0
    suvo=0
    s=input()
    suvojit=s.count("SUVOJIT")
    suvo=s.count("SUVO")
    print('SUVO = ',suvo-suvojit,', SUVOJIT = ',suvojit,sep='')


Perl:
use strict;
 
my ($t,@Input) = <STDIN>;
 
foreach (@Input)
{
	my $Line = $_;
	my @a = ($Line =~ /SUVO(?!JIT)/g);
	my $a = @a;
	my @b = ($Line =~ /SUVOJIT/g);
	my $b = @b;
	
	print "SUVO = $a, SUVOJIT = $b\n";
}

Pascal:
program Hello;
var t,i,first,last,tmp: integer;
	  s: string;
begin
    readln(t);
    for i:=1 to t do
    begin
    	readln(s);
    	
    	first := 0;
    	while(pos('SUVOJIT',s) > 0) do
    	begin
    		tmp := pos('SUVOJIT',s);
    		first := first + 1;
    		delete(s,tmp,7);
    	end;
    	
    	last := 0;
    	while(pos('SUVO',s) > 0) do
    	begin
    		tmp := pos('SUVO',s);
    		last := last + 1;
    		delete(s,tmp,4);
    	end;
    	
    	writeln('SUVO = ',last,', SUVOJIT = ',first);
    end;
end.

PHP:
<?php


//Read input from stdin and provide input before running code
//fscanf(STDIN, "%s\n", $name);
//echo "Hi, ".$name;

 
fscanf(STDIN,"%d\n",$num);
 
while($num-->0){
$cnt1=$cnt2=0;    
    $str=fgets(STDIN);
    $cnt1=substr_count($str, 'SUVO');
    $cnt2=substr_count($str, 'SUVOJIT');
    if($cnt2>0 && $cnt2>$cnt1){$cnt1=$cnt2-$cnt1;}else{$cnt1=$cnt1-$cnt2;}
    
    echo "SUVO = ".$cnt1.", SUVOJIT = ".$cnt2."\n";
}
 
 
?>


Ruby:
=begin
# Read input from stdin and provide input before running code
 
print "Please enter your name: "
name = gets.chomp
print "Hi #{name}\n"
=end
 
n = gets.to_i
n.times do
    str = gets.strip.upcase
    suvojit_count = str.scan(/SUVOJIT/).count
    suvo_count    = str.scan(/SUVO/).count - suvojit_count
    print "SUVO = #{suvo_count}, SUVOJIT = #{suvojit_count}\n"
end

VB:
Module Main
 
    Public Function CountSubString(ByVal sMainString As String, ByVal sSubString As String) As Integer
        Dim lPos As Integer = 0, count As Integer = 0, sLen As Integer = sSubString.Length
        While (1)
            lPos = sMainString.IndexOf(sSubString)
            If lPos = -1 Then Exit While
            sMainString = sMainString.Substring(lPos + sLen)
            count += 1
            If sMainString.Length < sLen Then Exit While
        End While
        Return count
    End Function
 
    Sub Main()
 
        Dim N As Integer = CInt(Console.ReadLine().Trim())
        Dim lSuvojit As Integer = 0, lSuvo As Integer = 0
        For i As Integer = 0 To N - 1
            Dim str As String = Console.ReadLine().Trim()
            lSuvojit = CountSubString(str, "SUVOJIT")
            lSuvo = CountSubString(str, "SUVO")
            Console.WriteLine("SUVO = " & lSuvo - lSuvojit & ", SUVOJIT = " & lSuvojit)
        Next
    End Sub
 
End Module


*/

