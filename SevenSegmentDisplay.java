/* Seven-Segment Display
All Tracks -->  Basic Programming --> Input/Output --> Basics of Input/Output -->  Problem
Tag(s): Ad-Hoc, Basic Programming, Basics of Input/Output, Easy, Input/Output
You all must have seen a seven segment display.If not here it is:
 _           _     _            _
| |    |     _|    _|    |_|   |_
|_|    |    |_     _|      |    _|
 _    _      _     _
|_     |    |_|   |_|
|_|    |    |_|    _|

Alice got a number written in seven segment format where each segment was creatted used a matchstick.
Example: If Alice gets a number 123 so basically Alice used 12 matchsticks for this number.
Alice is wondering what is the numerically largest value that she can generate by using at most the matchsticks that she currently possess.
Help Alice out by telling her that number.
 
Input Format:
First line contains T (test cases).
Next T lines contain a Number N.

Output Format:
Print the largest possible number numerically that can be generated using at max that many number of matchsticks which was used to generate N.

Constraints:
1<=T<=100
1<=length(N)<=100

SAMPLE INPUT 
2
1
0

SAMPLE OUTPUT
1
111

Explanation:
If you have 1 as your number that means you have 2 match sticks.You can generate 1 using this.
If you have 0 as your number that means you have 6 match sticks.You can generate 111 using this.

//My C Solution:
#include <stdlib.h>
#include <string.h>
#define LEN 101
#define MAXLEN 1024

int main(void){
    int  t , N ,j,i,k,ind,nummatchsticks,nOnes,nSevens,sevenflag;
    char max[MAXLEN],str[LEN];
    int segnums[] = { 6,2,5,5,4,5,6,3,7,6} ;
    scanf("%d",&t);

    for(i=0;i<t;i++){
        j=0;
        nummatchsticks=nOnes=nSevens =sevenflag= 0;
        scanf("%s",str);
        N= strlen(str);
        for(k=0;k<N;k++){
            ind =str[k]-'0';
            nummatchsticks+= segnums[ind];
        }
        if((nummatchsticks%2) != 0) {
            nSevens = nummatchsticks - 3;
            nummatchsticks-=3;
            sevenflag = 1;
        }
        nOnes = nummatchsticks/2;
        while(nOnes--){
            if(sevenflag){
                max[j++]='7';
                sevenflag=0;
            }
            max[j++]='1';
        }
        if(sevenflag){
            max[j++]='7';
            nSevens=0;
        }        
        max[j]='\0';
        printf("%s\n",max);
    }
    return 0;
}

*/


/* Best Submissions:
Bash:
# Sample bash code
i=0
read t
while [ $i -lt $t ]
do
sum=0
j=0
read n
x=( $( echo $n | sed 's/\B\B/ /g' ) )
for j in ${!x[*]}
do
d="${x[$j]}"
if [ $d -eq 0 -o $d -eq 6 -o $d -eq 9 ]
then
sum=$(( $sum+6 ))
elif [ $d -eq 2 -o $d -eq 3 -o $d -eq 5 ]
then
sum=$(( $sum+5 ))
elif [ $d -eq 7 ]
then 
sum=$(( $sum+3 ))
elif [ $d -eq 4 ]
then
sum=$(( $sum+4 ))
elif [ $d -eq 8 ]
then
sum=$(( $sum+7 ))
else
sum=$(( $sum+2 ))
fi
done
while [ $(( $sum%2 )) -ne 0 ]
do
sum=$(( $sum-3 ))
echo -n "7"
done
k=0
while [ $k -lt $(( $sum/2 )) ]
do
echo -n "1"
k=$(( $k+1 ))
done
i=$(( $i+1 ))
echo 
done

C:
#include <stdio.h>
 
int main(){
	int n,sum=0,i;
	char s[101];
	scanf("%d", &n);
	while(n--)
	{
	    sum=0;
	    scanf("%s",s);
	    for(i=0;s[i]!='\0';i++)
	    {
	        switch(s[i])
	        {
	        case '0':sum+=6;
	        break;
	        case '1':sum+=2;
	        break;
	        case '2':sum+=5;
	        break;
	        case '3':sum+=5;
	        break;
	        case'4':sum+=4;
	        break;
	        case '5':sum+=5;
	        break;
	        case '6':sum+=6;
	        break;
	        case '7':sum+=3;
	        break;
	        case '8':sum+=7;
	        break;
	        case '9':sum+=6;
	        break;
	        }
	    }
	    if(sum%2==0)
	    {
	        sum=sum/2;
	        for(i=0;i<sum;i++)
	        printf("1");
	    }
	    else
	    {
	        sum=(sum-3)/2;
	        printf("7");
	        for(i=0;i<sum;i++)
	        printf("1");
	    }
	    printf("\n");
	}
}

C++:
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
short t;
char n[101];
scanf("%d",&t);
while(t>0)
{
int  c=0;
scanf("%s",&n);
for(int i=0;n[i]!='\0';i++)
{
switch(n[i])
{
case '0':c=c+6;
break;
case '1':c=c+2;
break;
case '2':c=c+5;
break;
case '3':c=c+5;
break;
case '4':c=c+4;
break;
case '5':c=c+5;
break;
case '6':c=c+6;
break;
case '7':c=c+3;
break;
case '8':c=c+7;
break;
case '9':c=c+6;
break;
default:break;
}
}
if(c%2==0)
{
for(int i=0;i<(c/2);i++)
{
printf("1");
}
}
else
{
c=c-3;
printf("7");
for(int i=0;i<(c/2);i++)
{
printf("1");
}
}
printf("\n");
t--;
}
return 0;
}


C++14:
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
short t;
char n[101];
scanf("%d",&t);
while(t--)
{
    short c=0;
    scanf("%s",&n);
    for(short i=0;n[i]!='\0';i++)
    {
        switch(n[i])
        {
            case '0':c=c+6;
            break;
            case '1':c=c+2;
            break;
            case '2':c=c+5;
            break;
            case '3':c=c+5;
            break;
            case '4':c=c+4;
            break;
            case '5':c=c+5;
            break;
            case '6':c=c+6;
            break;
            case '7':c=c+3;
            break;
            case '8':c=c+7;
            break;
            case '9':c=c+6;
            break;
            default:break;
        }
    }
    if(c%2==0)
    {
        for(short i=0;i<(c/2);i++)
        {
            printf("1");
        }
    }
    else
    {
        c=c-3;
        printf("7");
        for(short i=0;i<(c/2);i++)
        {
            printf("1");
        }
    }
    printf("\n");
    
    }
}


C#:
using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
 
namespace bosch
{
    class Program
    {
 
        static void Main(string[] args)
        {
            var lookup = new SortedDictionary<int, int>()
            {
                {1,2},
                {7,3},
                {4,4 },
                {5,5 },
                {3,5 },
                {2,5 },
                {9,6 },
                {6,6 },
                {0,6 },
                {8,7 }
            };
            var n = int.Parse(Console.ReadLine());
            for (int i = 0; i < n; i++)
            {
                var t = Console.ReadLine();
                var input = t.ToCharArray().Select(x => int.Parse(x.ToString())).ToList();
                var matchSticks = input.Select(z => lookup.Where(x => x.Key == z).Select(x => x.Value).First()).Sum();
                var list = new List<int>();
                while (matchSticks > 0)
                {
                    if (matchSticks % 2 != 0)
                    {
                        list.Add(7);
                        matchSticks -= 3;
                    }
                    else
                    {
                        list.Add(1);
                        matchSticks -= 2;
                    }
                }
                Console.WriteLine(string.Join("", list));
            }
            Console.ReadLine();
        }
    }
}

Java:
1).Best Solution:
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
class Seven
{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int test = Integer.parseInt(br.readLine());
        int[] SevenSegment = new int[]{6,2,5,5,4,5,6,3,7,6};
        String[] result = new String[test];
        for(int i=0;i<test;i++)
        {
            String input = br.readLine();
            char[] number = input.toCharArray();
            int sum =0,c=0;
            StringBuilder max = new StringBuilder();
            for (char var : number) {
                c = var - '0';
                sum += SevenSegment[c];
            }
            if(sum%2 == 0)
            {
                for(int j=0;j<sum;j+=2)
                    max.append(1);
            }
            else
            {
                max.append(7);
                sum -=3;
                for(int j=0;j<sum;j+=2)
                    max.append(1);
            }
            result[i] = max.toString();
        }
        for (String var : result) {
            System.out.println(var);
        }
    }
}
2). Other Solution:
import java.util.*;

public class SevenSegmentDisplay {
    public static void main(String[] args) {
        int[] segmentNumbers = new int[]{6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
        int numOfSticks = 0;
        int t;
        
        Scanner in = new Scanner(System.in);
        t = in.nextInt();
        String[] resultArray = new String[t];

        for(int i=0; i<t; i++) {
            String num = in.next();
            numOfSticks = 0;

            for(String c : num.split("")) {
                numOfSticks += segmentNumbers[Integer.valueOf(c)];
            }
            int oddOnes = 0;
            
            if(numOfSticks%2 != 0) {
                oddOnes = numOfSticks - 3;
                numOfSticks -=3;
            }
            
            int countOfOnes = numOfSticks/2;
            char[] result = new char[countOfOnes];

            Arrays.fill(result, '1');
            String resultStr = String.valueOf(result);
            
            if(oddOnes > 0)
                resultStr = "7" + resultStr;
                
            resultArray[i] = resultStr;
        }
        
        for(int i=0;i<t;i++) 
            System.out.println(resultArray[i]);

        in.close();
    }
}

Java 8:
import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;
 
//Title: Seven-Segment Display 
public class Ex12 {
 
    private static class FastReader {
 
        private final InputStream stream;
        private final byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;
 
        public FastReader(InputStream stream) {
            this.stream = stream;
        }
 
        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                try {
                    curChar = 0;
                    numChars = stream.read(buf);
                    if (numChars <= 0) {
                        return -1;
                    }
                } catch (IOException ex) {
                }
            }
            return buf[curChar++];
        }
 
        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }
 
        public String nextLine() {
            StringBuilder res = new StringBuilder();
            int c = read();
            while (c != '\n') {
                res.appendCodePoint(c);
                c = read();
            }
            return res.toString();
        }
 
        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        public interface SpaceCharFilter {
 
            public boolean isSpaceChar(int ch);
        }
 
        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public long nextLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public double nextDouble() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E') {
                    return res * Math.pow(10, nextInt());
                }
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E') {
                        return res * Math.pow(10, nextInt());
                    }
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }
 
        public String next() {
            return readString();
        }
 
        public char nextChar() {
            return readString().charAt(0);
        }
 
        public void close() {
            try {
                stream.close();
            } catch (IOException ex) {
            }
        }
 
    }
 
    public static void main(String[] args) {
//        Scanner reader = new Scanner(System.in);
        FastReader reader = new FastReader(System.in);
        int T = reader.nextInt();
        for (int i = 0; i < T; i++) {
            String N = reader.next();
            int matchsticks = howManyMatchsticks(N);
            StringBuilder output = largestValue(matchsticks);
            System.out.println(output);
        }
        reader.close();
    }
 
    private static int howManyMatchsticks(String s) {
        int[] v = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
        int matchsticks = 0;
        for (int i = 0; i < s.length(); i++) {
            int k = s.charAt(i) - '0';
            matchsticks = matchsticks + v[k];
        }
        return matchsticks;
    }
 
    private static StringBuilder largestValue(int n) {
        StringBuilder sb = new StringBuilder();
        if (n % 2 == 0) {
            sb.append('1');
        } else {
            sb.append('7');
        }
        for (int i = 0; i < n / 2 - 1; i++) {
            sb.append('1');
        }
        return sb;
    }
}


JavaScript(Node.js):
// Write your code here
 
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
    var arr,i,j,sum,num,n,len;
    arr = input.split('\n');
    len = arr.shift();
    for(i=0;i<len;i++) {
        num = arr[i].split('');
        sum = 0;
        for(j=0;j<num.length;j++) {
            
            switch(Number(num[j])) {
                case 0: 
                    case 6:
                        case 9:
                    sum += 6;
                break;
                case 1: sum += 2;
                break;
                case 2: 
                case 3:
                    case 5: sum += 5;
                break;
                case 4:sum += 4;
                break;
                case 7: sum += 3;
                break;
                case 8: sum += 7;
                break;
                
            }
        }
        if(sum%2===0){
            n = ""
        for(let k=0;k<sum/2;k++) {
          n += 1; 
        }
        }
        else {
            n = '7';
            for(let k=1;k<Math.floor(sum/2);k++) {
          n += 1; 
        }
        }
        process.stdout.write(n + "\n");
    }
    // process.stdout.write("Hi, " + input + ".\n");       // Writing output to STDOUT
}


PHP:
<?php

// Sample code to perform I/O:
//fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
//echo "Hi, ".$name.".\n";                // Writing output to STDOUT
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
// Write your code here

fscanf(STDIN, "%s\n", $T);
for($x=0;$x<$T;$x++){
    fscanf(STDIN, "%s", $N);
    $len=strlen($N);
    $total_matches =0;
    for($i=0;$i<$len;$i++){
        $num = substr($N,$i,1);
        
        if($num==8){
            $matches = 7;
        }else if($num==0 || $num==6 || $num==9){
            $matches = 6;
        }else if($num==2 || $num==3 || $num==5){
            $matches = 5;
        }else if($num==4){
            $matches = 4;
        }else if($num==7){
            $matches = 3;
        }else{
            $matches = 2;
        }
        
        $total_matches = $matches + $total_matches;
        
        if($total_matches%2==0){
            $ctr = $total_matches / 2;
            $result='';
            for($j=0;$j<$ctr;$j++){
                $result .= '1';
            }
        }else{
            $ctr = ($total_matches-3)/2;
            $result='7';
            for($j=0;$j<$ctr;$j++){
                $result .= '1';
            }
        }
    }
    $print .= $result . PHP_EOL;
}
 
echo $print;
?>

Perl:
=comment
# Sample code to perform I/O:
 
my $name = <STDIN>;             # Reading input from STDIN
print "Hi, $name.\n";           # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
=cut
 
# Write your code here
 
use strict;
use warnings;
 
my $tests = <STDIN>;
 
my %sticks = (
    0, 6,
    1, 2,
    2, 5,
    3, 5,
    4, 4,
    5, 5,
    6, 6,
    7, 3,
    8, 7,
    9, 6,
);
 
while($tests--){ 
  my $num = <STDIN>;
  
  my $sum = 0;
  $sum += $num =~ tr/0//d * $sticks{0};
  $sum += $num =~ tr/1//d * $sticks{1};
  $sum += $num =~ tr/2//d * $sticks{2};
  $sum += $num =~ tr/3//d * $sticks{3};
  $sum += $num =~ tr/4//d * $sticks{4};
  $sum += $num =~ tr/5//d * $sticks{5};
  $sum += $num =~ tr/6//d * $sticks{6};
  $sum += $num =~ tr/7//d * $sticks{7};
  $sum += $num =~ tr/8//d * $sticks{8};
  $sum += $num =~ tr/9//d * $sticks{9};
 
  if($sum % 2){
    print "7";  
    $sum -= 3;
  }
  
  my $digits = $sum/2;
  while($digits--){
    print "1";    
  }
  
  print "\n";
  
}

Pascal:
program sevenSegmentDisplay(input, output);  { HackerEarth problem 'Seven-Segment Display' }
 
  var
  TC, t, sticks, i : integer;
  segments : array [0..9] of integer = (6, 2, 5, 5, 4, 5, 6, 3, 7, 6);
  number : string;
  digit : char;
 
begin
  readln(TC);
  for t := 1 to TC do
  begin
     readln(number);
     sticks := 0;
     for i := 1 to length(number) do
     begin
        digit := number[i];
        sticks := sticks + segments[ord(digit)-48]
     end;
     if sticks mod 2 = 0 then
     begin
        for i := 1 to (sticks div 2) do
           write('1');
        writeln()
     end
     else
     begin
        write('7');
        sticks := sticks - 3;
        for i := 1 to (sticks div 2) do
           write('1');
        writeln()
     end
     {writeln(sticks)}
 
  end
end.

Python:
from __future__ import print_function;
 
numOfMatch = {1: 2, 2: 5, 3: 5, 4: 4, 5: 5, 6: 6, 7: 3, 8: 7, 9: 6, 0: 6};
test = input();
for i in range(0,test):
    numGiven = raw_input();
    matchAvail = 0;
    for j in numGiven:
        matchAvail += numOfMatch[int(j)];
    if(matchAvail%2==0):
        for j in range(0,matchAvail/2):
            print (1,end='');
        print ("");
    else:
        print (7,end='');
        for j in range(1,(matchAvail-1)/2):
            print (1,end='');
        print ("");


Python 3:
def cll(n):
    sum=0
    # print(n)
    n=list(n)
    # print(n)
    for d in n:
        # print(d)
        d=int(d)
        if d==1:
            x=2
        elif d==7:
            x=3
        elif d==4:
            x=4
        elif d==2 or d==5 or d==3:
            x=5
        elif d==8:
            x=7
        elif d==0 or d==6 or d==9:
            x=6
        sum+=x
    # print(sum)
    return sum
n=int(input())
for i in range(n):
    d=input()
    x=cll(d)
    
    if x%2==0:
        for i in range(x//2):
            print("1",end="")
    else:
        print("7",end="")
        for i in range(x//2-1):
            print("1",end="")
    print()


Ruby:

seven_segment_values = {
  '1' => 2,
  '7' => 3,
  '4' => 4,
  '2' => 5,
  '3' => 5,
  '5' => 5,
  '0' => 6,
  '6' => 6,
  '9' => 6,
  '8' => 7,
}
 
test_cases = gets.chomp.to_i
 
test_cases.times do
  sticks = gets.chomp.split('').inject(0) { |sum, n| sum + seven_segment_values[n] }.to_i
 
  puts sticks % 2 == 0 ? "1" * (sticks / 2) : "7" + "1" * ((sticks / 2) - 1)
end

Scala:
import scala.io.StdIn
object SevenSegmentDisplay extends App{
    
  val array = Array(6, 2, 5, 5, 4, 5, 6, 3, 7, 6)
 
  val tc = StdIn.readInt()
  for (t <- 1 to tc) {
    val sticks = StdIn.readLine().map(_.toInt - 48).map(array(_)).sum
    println((if (sticks % 2 != 0) "7" else "") + ("1" * ((sticks - (3 * (sticks % 2))) / 2)))
  }
}

*/


/*
Editorial:
Count the number of matchsticks that you have in total(i.e 0 has 6 matchsticks 1 has 2 matchsticks etc.).Let X be the total number of matchsticks that you have.
Now you need to obtain the largest number.Lets say we have 2 numbers A and B and number of digits of A > number of digits of B then its implied that A>B. 
So have only 1 number (i.e 1) which uses 2 matchsticks and all other numbers use more than 2.So if X is even then we can have X/2 1's and this will be the largest number.
If X is odd then in the most significant digit we can place a 7 (since it is the only number using 3 matchsticks) and in the remaining digits we can place a 1.
Author Solution by Aashray Agarwal
//Created by Aashray Agarwal urf maniAC
//MY ATTITUDE ISN'T BAD,IT'S IN BETA.
//YOU BETTER BE NICE TO ME,I COULD BE YOUR BOSS IN A FEW YEARS.
//I TURN COFFEE INTO CODE,JUST BE ABLE TO AFFORD MORE COFFEE.
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
string s;
ll t,a[10];
void solve()
{
    ll i,j,k;
    cin>>t;
    a[0]=a[6]=a[9]=6;
    a[1]=2;
    a[2]=a[3]=a[5]=5;
    a[4]=4;
    a[7]=3;
    a[8]=7;
    while(t--)
    {
        cin>>s;
        ll val=0;
        for(i=0;i<s.size();i++)
        {
            val+=a[s[i]-'0'];
        }
        if(val%2==1)
        {
            cout<<"7";
            val-=3;
        }
        while(val>=2)
        {
            val-=2;
            cout<<"1";
        }
        cout<<"\n";
    }
}
int main()
{
    //for(ll uu=0;uu<=9;uu++)
    //{
        //string s=to_string(i);
        //string s1=to_string(i);
        //stringstream ss;
        //ss << uu;
        //string s = ss.str();
        //string s1=ss.str();
        //s="in0"+s+".txt";
        //s1="out0"+s1+".txt";
        //freopen(s.c_str(),"r",stdin);
        //freopen(s1.c_str(),"w",stdout);
        //solve();
    //}		
	solve();
	return 0;
}

*/


/*I/O:
In #1:
100
0
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99

Out #1:
111
1
71
71
11
71
111
7
711
111
1111
11
711
711
111
711
1111
71
7111
1111
71111
711
11111
11111
7111
11111
71111
1111
111111
71111
71111
711
11111
11111
7111
11111
71111
1111
111111
71111
11111
111
7111
7111
1111
7111
11111
711
71111
11111
71111
711
11111
11111
7111
11111
71111
1111
111111
71111
111111
1111
71111
71111
11111
71111
111111
7111
711111
111111
7111
71
1111
1111
711
1111
7111
111
11111
7111
711111
7111
111111
111111
71111
111111
711111
11111
1111111
711111
111111
1111
71111
71111
11111
71111
111111
7111
711111
111111

In #2:
100
8445914752334217384616425239834258842968210917150466215005566541456111472213037091760933758638073416
4398815833497404383300557458891269646867767909076453103008765853958604906216333634684797106664206428
8286771082877029164940354990379968768154829776376901173153395618049641671077534448274921118429399256
1759362752007192598405721111785707192826295647037746676744509574541822331633266077224086286928225362
4766425718403211513238334361607082528939511144853001865874651160354655664922072793207675869081297808
7476694835879461819149601640515425966637796410111524956164959905235395848851133183518183702317829483
1862023611973198955654432506765855495914192509942516306983591929195702176378084076187933431938077680
9964687630526775878706585245324442562437533956780357546230525667725095096099836357139173592228550170
7053827914567519264570030558599867733482516660054438344889366140838050518138181151403636760904189639
1052533765856592915599910616487594957943849123190774465049119294466691102175972864128981350234241733
6434442825551675377756324897056204190637194110220225019577555800894327574650015816218999410626029272
8078571261219053281720727033171846464431008125484024132157535209203607140471750973116393424552761263
5893924042249012121198655806386508444955397818373210445864180853294479775892734203136767461629803382
8630655633138976181284323497731212249407128412472036445716362381255654303925966937317994815722846681
6709605462495724142054390987440573538507070445548723494333704967970397118262557548692640345273367633
6199439961945692448258929730881959764323343627806586792523428344855260980003652323727374292504951646
4668308999879600145970394363920628405491659829289058606288102376825994477934530164881751188389440226
3581009814898714381929112919780581151597205649589287097246439301831224162971324997028955009008319198
1107505751545346030465314731171830721292263130790222072170310489672046850991539898050398357000101118
8917570708621518852787074371119114462055599788027306588623386109406704760102234312489684138169141873
1069620854104396625626964274858446101361184444407116163778515910759910160172954929178745734586900393
8763797011269036359150323315146763492728086849234384319286080578046156990051448944927883035172544707
0818832959819887945213801165747017356085041777149028544145996921242358468026973252724319378013683385
6494102455849072287431408200204575004627998732779334057370347518467922955393085711886763408635638331
6057846843362610056888932416686771116347246286933699205986488300524574895564820813652705169891665798
6918206426617057513859603617587592792428766191195366310009347190656117256509724003444031494492047494
0186267096180384418295549200214085030700509176274010574572280420353404671811243027021189343165894798
9928304198594568133434668032905902062827741724242919013776844119375001677277424553970108563128883278
4368372726824582803220559105658896015373263375639766424908578494117614339159059998899778598689962384
9398799350642274170439126968960640387087199317033488813137835082732303530779316831452724390060284156
6030549843664249131919905227093491464621359499959006363520065527255126300364679294105474189071652681
1880500918502126113149128997122394084478871684927155302201972617733615297001651025352968809511689449
2675111906151873306987976981291966304330609788265986548852439973998586992860654044530927239601946587
9475474057489899399454366027887412818694591134758447139964709869876332990471644154624073388975350846
3867004140342436181422856968582317914948299341379745984961503818846067147838085725771154023713068782
5062984601590389814667187473586801175782566832158446006586928388373515649954923253455916734329256600
5020665155603011330247557184726594212372607461886311342567098421575630454343219182129905131398531906
2950805194516340130045886215719774412037733787553677527545427683184389339805495082856331335322867089
6796517974928768356275204536399381371135516034808349018634815567992632796684756212174705352795051080
9371494024931711961248649329348608895403884767515664063643806174374144768345939779897540085568874545
2590606035269263452788907901646695397412531368695596837912893073654508206982969165037737489652817468
1415225480133266370119528692029246974364988322260619253246763181625394329658977490842927396248194146
7731529606692501525915277536441676945362732689736814130656789073701707610601510457349968096499181482
4280602687528465550397334644434298011290179261257029339067560452105890526897520290536751564288918027
2264339643429116256674422468682644132837756170701706054299719121163765649493445316488978582450147541
7161048673223918222283689925721200004232031178274364826452725584923929662432098819605980943272229706
7783123722804006618317883573042598747889677932382582916311282066594909194737609615053875530743923616
9787273148488995999071220742492020065316507177436997177832194346812333138312409160873138557736041898
3066110151531210449438289485418284105289298005050017932370427349814507851729764959541357985126801852
0085903744865643959519973062137253526377117720531179019728314549032695915323697707616601895220763900
3739228093750831715254061881998909861747473240415859365188975919611922237752096745381693302370014580
4330434259018581730324912818701247484365773110859206373455161990402472072267804358692179798490940761
7335988216320747165679441995989425192361490849380506336176363900914885439522367235684710548779078093
5336242967863216453196061643078902285033913784045361556627219960556403372473572378913454027243822705
1177520919122701784919620763393028164168070085410860194489216067443490822830709161933249560661349700
8548446210194222747978851951313704738140502113128089733708604971340316311467846099519215764180135669
3318046527846174803134826892246976819339376398538159469377374244929717920338626826106440989895755425
3719210175300067658215833512196533977719989678712578343962121010451229639438382176731419567368433049
9245172213791129317126262486621027786970171913109578235029438128232264462820160773778934985738607346
9302295372913568689251173490222596889436090388086658029023137535015615307761622450237198555131754628
8569253987764832750642050195275078520203120178380463087027348718481410199700775998474610379551260829
4373420302244415894011022095941274373096277651612189523634224950112771983697634686072976436659947415
0550317954798860445682096006343275634731218640914171415527728373427699281243210680142643161584997079
2435074793278445145243528188697805129872126846015538936968161746201118008644492484845723547842866380
4825489306134351896789174804625962461652308592298759638271452328101818767862568351004119850625637815
2914533789225703275626357194371306088868394274845117946072090062613209342750715630381804941185360886
5246017148359863238979112273452621024791637256576321227289392630432182760608823706426478088201495552
8945665112301723822904262858430900378658259094588884460383125359873344592586335818986661163123217256
3409130191623848944097671807197894830369982594595375577569920081174657249061984911035524358701248762
9251744082908619670341283320249338412016577105254997960119873915218827735269140728007373665857367283
0559735232726034677140688484234712833064098135989917309758828071999068647115387179300072346398770635
0766090857551993586300043521437893120102341507490335961370149940170837899220641851030056411988454769
6827152003588007553612591022018694603061949834682784302056929883933279767171047150572367498552718899
7808345063441233401193883089995520685681139741270736462112456929032170258836105862345635402487129353
6105320458283656357357569035156608199629209425958313298416488615400137658812813198761393203763150666
5956561461012083395183899254337546673133474269005921990383673649246437577566973676283431903347343733
8842700459314424592433160644001465546937787005137823311397651034054448678690545659163419630545964203
9365833933083560760841745941259878408850089859183399110809598115253067422007305698754719031665888628
5045992572494618372379313570133438578674111023866827841392668317157031998571435299181805506813760778
6675687786572763566329374061093338063106541659640037822876774547816158937415386566697369679008429897
6919350149111781322316555280892060623353917161912439600955194877109384311778989201874412266186756916
4774053495355906706185446796453480044771500321965489346755291546433681077728714648665233921202324128
1814114184374295035363469679462311909146566575217599012663640554123393400151543001472254989352173193
6362768306957232408331130171123813248708082644719239627577899403453348474874155070937359182694410975
5617060201427294855745185389957500726086928235034912402934777164287667678464339051995578928327007461
2697738344837141317820484950989929235978358915854051235712595874069000158309206136040485496163537490
4873283047730918511298950025158858237464662684934812758001834129176933644129647861419140022782213387
0181084801581333987147519779888849114378436703349056610031762953128227946066670685104703642004395655
6934299431951864670100328152851345777365656908228974391424046315212970097403035797378662240149655047
8435851411403011155886842451545451344965107994346831408788753532269791480911478798770630451304381114
2287077822020222709823590913844591593447542790477337874733574028351370312795821512026929827410736792
8394411689208174538928887678859634969116795306373824127034875169279483791617115429836672961275877647
9908887263460069563455979464006625624847862457160373761085185516766155939248917459109493067706632838
9570689848624289688461393365354068741129228735421212005410994345601841040160362424708687607640540647
5261266700726315834785375303689026757685578734196307589407394478972947013926534061739765292360150577
5511873146051845805699858063007444704744427510420477710407757089457610981584115175763857489275481457
3234672126879746044476222562074471653903897915562173797049105599969755743691546768298143305433327918
5159634983016142065776346177262056470518942523729579397901276263189897939559440919704040769338611847
2986560624684030434672433728342835113167029184072600956299506882456367624015190847369747502727123282
9492899108268116253810265742683000273332566249079464036872515907831050602735875842032834895864663052
Out #2:
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111

In #3:
100
6519936315637362324645875088717980186240914507009008367439995824993092497403979345979041899918567104
4401851715543162234439500051641829348269858698279743913928783093953517263677068923647348609864601445
7869669572350617470145219093671868170405698640368283017941402875995579681364879601976257735233618773
6227689923547611251864149960894777493180330799191047553764285634501226308013303621318635160688994776
9162509512281712333682193179324630063137396358127908691845068503646587587347205683280924261674792487
2329691542658621683994434105142317426884951919964855256934823612756488285515752654697598468044364665
1990565869894046563356682978549678257408206954084233533386364880019562196998576860090361327349672291
9086647449156567264134328288556980098396614533025743133989242958316606295745104292287241023147192555
0473950211142119341319693986930148536870967903505847842929344204087620278995199228423187352139078448
0078880767556297761744261035001226980095710421962283183666397372189614563716997548226945421359296903
5061319190459866584092797076953552701012592370805446187965132876747871768686213745394743515143138176
8067102107081170239390238853844055503928162333564907826563243315237649392522893763497787174378792457
1191347541289733856052234179142805017168392962602099092889085292396191539245523950930297584048952406
1893935143170711354644028097904155113457017649073972143597358796608655928560583740142581032676764794
9253825224503548736651756952099912663065510742990060193205042474916915473692098658537377383476429301
8973244607214141360060779278591129223664604911609893648688817482545438722415823072203012228922239396
1827108382233043338749020730259363242672514724387728203124078357233734901766150594787969577706092429
3376635421370923868684710328991946096496200766627863270387685673898718175752898577815334868554471015
3978389283597976411348387336975154892541837504980366262073550442110813242871716811988206879128997600
6894080962314708700305046824973083467336033412281789262062869968761859523826445407504421387073018107
1219794177252153111743523790357420230565744093957806797037472457897187658082197847740202458506471758
3834177022656461438788636498128250027372661779936135872141062411874469181720676661881004394011913601
0313820111265559194792224116671177081390355919338408649815046067318150442546031236392540887740385445
3476547047843515522536175974299576564045353063157882450422026893725553809912319809699838359303186820
9488677400764993054772438415843947693996767571871611569646428408964240672937654583153927016748670097
8976530953844932288501077854269585738017829075132717815316759371483254795064939858015268661874470325
3184815567639048520914098056143581562435694579751314257428114142629806618243735420274255277070461831
4682918080384757716076071472340319029182372932512001756182234523169131970184176170837281899107626450
3289569501768361971070300445226875564481999793347963147957301970370031318746268279488752103317295109
0253117429439967854559752245759778740368016229132864344538308726510134286022610501645035623908074995
6652329544897684165407258069440695271968343807343081630437197922222506667181572262767465187714307208
4276484001546878085541318935971251300682630961505060625667352516098411742981163432137023134117343829
4528623637757499644247529179348262411063027891149404335019801472385615622333860738924520216553910325
8748778803700858578326092710354889788024144019918945099774138866522250023684053211077839197810929883
3007033226834356594652558349678602003921116783609033959344093720376760538449958554262342307443730806
6951941766029788684647080795327045369522176439075382837727073702626267881214655254971331081267206818
0380293266024151378601113833492537399390408703250374582845068263303764941980100046972763816113638899
0626380102388064178859861432016190902397104237703203573856200616008648139319922248782876942445777060
3961945579202949203702014410019001529324133714600994423988021100013710677267384520656224234801163528
2165944821932188217103821974036474557444252358601059033165977944043198986470199230198084880200866365
0174695879891665723712985651357185346317412558931522579923439406307123806990189795720269904769263938
0830234052754064489938806085346307944353525716873240233499368919015454411969555619327566518716995790
3185560103013818156667879837488202086449304478352393514142737084650507005202022327608983585279427484
1163203455911162767422352226349893419368290832096011992325466393045623239000337715632563942099766510
9872424456474112949136954394904409651656130851324153397039551529881553473897384416161928468074243338
4386986004857173655759315315208334217186532003087443234920087869429957404743790026631837798738900361
3196237430665166883325772663105754248027689207259746177100972679246366624503322232715132682495510500
1509294697592292353739909587881113993483511648961664119321533195030115113613504584353452957740935336
3673626215266594944303552786055039914059416256111598345331765274161732764203116374408828875764607056
7099639464953270729741939071384983650658004118525053138810901875179581932323182238488784085572268162
2221888996133783300413296210216060361196697689940251037065918983681268008510233639848709694300988249
7641406211569203536392186442229387605102557828421184397429629604948898462609357600358235084813728995
0741287735469845524137527277843217160155056549425617268203718284751689982993282327523814081443354175
1502932242291967533277513737576100301982069204560058272719016906920178634580589045606625414618342185
2135082089573438184161250683757620864009190112472827880339312593698450566678510850682470221000940617
0363735792128375367685987069048039493758816970609846798037462986344588095035883498472699615083864069
5025801395009779685861056776225010259916650639273875937276245268269527272655236498267390964118422820
3178914413482146606419440823310797079141614283206128609854377598772863676891029532188599698290477853
2359904707810172187708779331069876833704904299161502461934932432960545835504246663542171124234683176
2720593754499733096499333651680756915693890265753718135865778325987062554668312463911913790922464178
0232690925625358330703488192623381136685140834621823237201470544618277256451882266634587690680341214
3430756688486948483821394665748900112605786630558400790849388510822972603482515849371158871203783562
5590077424624452528751819481714883424566630877864788265277707270592942747922809844285612234799455973
4192012732409399797377594823650670849980568294284562412311132746259347196061269642149291215226653146
9290489035283511041834306551656060967064979239735597515352043309730838090738607104429086118265354033
3488979948003564353896712769337932824842453226282932568017908428257951932210433042735766719202367465
4525569511669479996641407199040506132326774598000510649395571142725389336376636942821721037465562746
0062296843052421534320549362321367053374900231002022369778077432323892089499721807429134770728786729
1466536501536852906014894846377363915290643029511700073439569143405622333362533318266866379829368487
9369377942748328392650818730459529304390886713859029339618830309162133596957395415297290702661439749
2984225779867475655871745398770077043838775201998046958279611438428399147324089024524926950808607433
1765062649337297942664430171814298422475486296664450675574547063054843640874747577108087998190898189
9021849196076762311266392134813807070898073197964816986733602024431478742857952226620145130773739701
3767233789225049008243121771026733865668860804071460038993633892185203994534509166541502523133038029
4903868606233094160276698365242412735587916064795156552738435166482785200915403470221420581501117085
3207386808257522815987299830604298902743283338716222502696257151016150255897524768316667640505811483
3814793679680552593438059434060443468424336850657596805105469130350901737792152265123744384367627748
3668722906858528088286335657459436442809647873977178870021778817850945804967941010715361188562112778
0896014692356279396391239708830273761931914977332117814852952723761445564266272084474839579891662146
9192256146561402353870794840533904362971177817767744342318558132196946045117586829927306668481338851
8461928335014523158784463787015692885095368137415501748961822495963281473739651268004315144527755418
2006154171974217534960335240779983097924934763871440156217194831003057135586196927677687801741260522
9984338596232626426523061668268141129931824731395558324317490262425244480576434219017635685152942546
7755360995890963383890337923580727390811312001387651209439387131427056669599194382858813185486895824
4684560031029720922862397030561087052493288423680683060457802449518177380318308415633918473862809604
5349646250616239854335319772059073024767944687489645274362437851188682383974724714553040959505950774
2283639545704020287458713849491169602253536931973761513838343945670278551413273948175618807174166918
1620026336303992925264620767784347568669680817047287121161071080613453409112069350099083964257035857
9562948968110623196316176418340576004049701883306319944309763411871337959662670686001280947818812841
8736033486440141346737623406255521760773570345387369815355758276910620261453022895505534157286016701
3315010668963931231951546686909572981957061617005503710248119666135200794443493685276148108565799206
8138589092725263081652713059583664831419204244355468987744855837819739158085598434110740436054007195
6828384084250053243307466075281303313281580706147192147146290913585505769375756050904598630982413140
5953676557106422780638738547219588023743229278109575130033073952446995125730159763006689764641180874
0109673869433884619662854780032547242167147505011527400737128564824201468646627020795894415308780770
5752175223462831567678860868368281272734070772826366295504139945176738985485027449650627652958303691
7913338139733502311535231687103643701252094981736197320115323777788473075473950262332882994285701283
4501972942651410223703802903204510026025525872537050062753908278345218596913862198048842451356825688
2704005067678331772974907747506967080091356384143476994047062273592703085871057489540490025425459313
3190118020618034952123168772262936189001030453808785687241820464043979046478313578010826392863350643
Out #3:
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111

In #4:
100
9376612761144493239161830066715776904631337530028118382911037729549003918123560187769612144184671433
7053118718408982227715155547394931214261337839187671518526940903393994094189364646332168738620989366
8148407837412762653541634818270014313754029483566928786691186910102933110193785923326004355726050191
8600323025149472127122310410316338120302745255221512771931939589471321619301149376076164549243940490
3785035803127019295433538163299409820556300948511594148453408449775109275432498165761603582640114973
1940410090201097110157782719383725937120726101705421940408360167891123512129712769947947474532599217
1144533013407040769864964950397186890212660484819467329848651204549083843937472679351714323653498314
2125216153863304085083621734507066530788591859298345477496484998824779154233908712517970180279892364
9144699722229413963152943032206053541378898709989244779104355120201029814490954601796893847670734623
1817931047572263071378266681837971663290200487981468515058082896377767242888621131580795662582383257
3131038409298816440828276503182643726595075069942793091107655336293196614531148364342732476856389585
2966886255902192143669588859892315296122846186043637018989827827301951221821443958222988497020822451
1725868988175512788860733326637130119317627215213574711196729655650643600634747080667659262933396070
7063700910984960576873178461538147009143344950351314178327972533116298393256026060546781942068439713
6548667482466515431422877842483628494539528180633729567168190338911816882851617177214304136097154268
7319528025204466793307535365009308338408434641764074368742577293877951574388280691762609884546267199
8602781949698666196073813655796671708521049223582622395741543694948215420627176730089742573533180860
7663891972013759733186694275570143178509319307755790116193245982446925818864457538794425461969491317
3625531291411542029237220138711254843756799998323767550792768059176142318070758545029330929652260650
0257427607874908724913142930833422476365060745556079765346757256600842819076598085490996269871097866
2989735856445294641989932593676505762409713194962601850579981016680384022422806343130565831727404062
3797896468807751453319612266208177604261485855227704898355852035003985378204757718457861628142237777
8986386450580415248653561701648747622086897183387529941794749105058596126145369088780623016585299191
0910908315789487663446427777777018287548024753356777954007187830415623656655812703977876312267650222
8478769359087906009272914457922216777850993275661674020015306943089150806987799068554960344599347803
7136810392841281156723531186282919078240785242867997996945475582566329303712510686095561618402075679
1029711780380808631706075094446219072143390435297502027204785650563012178669110964639683939244857245
2408595617983266644194862616759305037100104461147266287898161527717284173120267035548035170845219379
2019930719323964503066922823287410071118830141975216865242464821993872071898519380041160376503182939
1532101961032528414170554915666421774093240983963156053650242756226042493202542933188812854366829613
5015113937023974950957873980962099536212130794007911540376964247582629469059545869923018382328087117
5832109508083376446465009120860992893251784443891439452059748170894940442249112106266493229300406872
6856497822838740609931338497011528307386146297517616811498340801099150392563334893777865521100629667
4759941027661496229514206903715121811843835921837187342506552436984889331492761685336145770033005642
5585988214601157223268795513499495829967279354856926767529799167091890447193609152257174771363416943
6934870025338398612683812815930750394251927120688456519762323482803750659103347637652134899011747677
8638087988921526986801761841069253798612722640744730536097877695307959192071684938038479583433430350
8855355224532311921094410668957137626779669721931193597922242640988678830692365069397567100622829432
2529015688236785758538537028139192818914429239617409484556303382269406871087352526004609420583150165
6907314798256583336021401734933453453587901366173652658749339148203442284463919853026212467229387640
8588417770715692917032014366194600112897072112551012525650826700236587055574992632614693537561934596
2031055491491330663290067626242895874934180917399566975048956485642177011337231013305428519182935342
6583075703265523951819541466981310644481055213075904216997836268604608914690498213035651972564985591
8383732118991584289580353696501698671072642575119797439930048648446701179105835545991817077593515931
8671320144375585785009873763930193673343012778070507924161204607293990333457870957400166637569213396
4691711446004906989435024227374549252249056737541142353725386554521751114265553395770669219153159575
9765675664350219877562632419645781292772071259156445479877050448753176609361202565613070645433618388
3887028729586274954823924877328561063461235768263129106171346269367143932692095516690099147031700068
0946140005136783238610764216710955609453490506123568357931138556352603207462390491397376517138730959
8604786437082269256386106950011521487325906786609188700950370495447682133673697641837855556014295762
2337088912658460680989743130844850393392757915190015299232773248395588785475984425521751185855404374
5630736041219464792111849995731526481792226479996435398424684394957692781570922966693122974699461090
3411186013953905936163254991183505815337181589097166293072225541498191779495393201119485242283524503
2570309818422882318013714805948810659477708731308383205071671321605186625368360467211840588200103730
6260536805613014934969112946981903666717803610662968056733043683167273751449218839042504064858753621
4529628214857197810982884889486988534704479307421105368580492797723714727845477708722088744670045247
2684025220819422311074332894252232091510095527288374284344580025214040479669622730424092504497049209
3128518881908182705768352476719714049860662748798485599853344691547498603888704012144752546018875517
1731154745357082144599831947042753990427873398649325783303348178236123307395534320881961992776012884
7466534316553422120413357005061994402352072945835042568697061980450802131414831562024251599733759575
3096261995244773659168832955076691642968955661450874574206798795988637678182248607272345591369535160
7685246951618610148353184499174003378535164166406852253506601863838429472351891277733454407814127606
7996777465988615212425991644965298222170832452565756509894193536790605394935577868681110080794659160
0928167149983488664603046998618161721656462163550360889454850920194171843740305815229003685323776630
2282764896021388140970844179411225288579696084140900926772914067590565939104248636709277174501160216
1705502416975801798477765132709627784599869660254595871998337693179647005824543862135250224660838966
7753717168233810332568977694790456699740146956058707507189502723531348834746073799435213768953241565
5689341823984974077720798757370642954921781551224526915485297683896718420296446393745998930572809938
1183700274296554066208463117685609908416615797375473318211917804927236363093082836587493598352357856
4591253392716571493438846345020458437977842240621522227530058315271996704480188420914588200601981072
0268081879424098037346427201061060556587393370765929795478788172548791139209466310372611328299253453
1829112238088995507519663499219649341988297615106354387787170459085816571709230137893608613248985983
3231419480148999798994724089790616754112512649517108248807794034529607578574433976749922885757629653
8889105248704698164366392820588218532266146182143248649097284936950819735660271397970891015860862085
7272487650207149084216969710843426104401174130267062880258765445936057402091382515243476432153789144
4360807148235450752657341270020076591537979864839326794730716167157145786119864270072277223353407083
3397040751414294592117421751711449007334027681000551234522813125526114336452904337725226832991490065
8327743254894691800709613362575347240221198713469832236029168000484658387956884035248689330295460664
6773890963484326017885978713349771702367195092092176097804652790226489084805229369133947706035609388
2252202704488740112676682815802008845012229991322505684316390409357792224651143149906607856731682059
4396973291009467330268064531780263729949251767063329600661283283844485596483945170516904950223060717
5496387939761795793579449499781207771919594232135547328122781305123789761278125625036944384653558360
5665328953186586292567321065383724540733712114580378838642691076114052887793248522649221801630364730
4859332158920340587848431900353629391157323683833651212609120645570880133436410735451929073377131835
2564734323029742589319982673439797313711317292456527133511382726579416767139949126086248336214878072
9913527312029231089961265097090226410503329971886514762229963596978881528217690943553405175945988329
7579219899413764470087571165642134307488877520554571702481167924658855749327544822610686953854371987
0887864665216823390288708727390546003915560271678867192601706574153843686375174697206210681071051729
5684429996231814359501082862121768877447933642574030149938075173251019857754473146298906457963389580
6930157210351181972672159078622343836744118661450825739964702804773409784074437590336934172565541716
6277641086888225506998651733003135247553384986109444356138594588591599295520089022743456302898560223
5336519843240411840427398755061910853010168518308480643831345738496204923765799830820459827893769479
8388685374911439852352014009791865176750783623840961670414169890949490846885871583694277418691413810
8635436948999561418539300146960192488815049697226025857652987321764882121465193311975603666849427656
2030649916497612239887540844113174531071836988701099589409759959126324792205221651125550769198441200
7013174197634164586661521163812881088076994651229670894265136375262184877637700920925220734244831889
7091575068294254448321591660210481088649254260524224417529459123584277147516658796573774669915096861
6397348501262139774572564416188770077605089857500535667517164702393331642805046603581425022638747622
9144704909336938209881810973371250010393701803563513720856770542397053142023100165366917748348761112
3816919289309020388689525032995280769324115585605567935930047902422129784011120077507768496359929733
Out #4:
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111

In #5:
100
4376926306430791439901952833355917770815817059122787784669805412731665687995457960635885057252265477
5046197104207559112314238412794242526507341878425436585198876410764541455538336702178598444741007939
1241623754711967311415666767849915002903364021340009813706928219791178543370908602597509465525301899
7661939231227948214758880949903209277967290343965720145430601142188141329010991652567442154859234316
2031680464636269176858261360866288738131977466182057199011234687198212133871945824825381111407067253
3109255654551103970063574642037942941566876871415323849153132126544859402990223785272606221356178400
8623647554096092577692656472602948236932306684071757111714585827537419790090896188562775884460111174
6185522655587168090582303258863518532493951995063728599182964845215159292068610617498922427647626374
2627528453928242601522498386634597050328830370961581003544254830988467605226809243373636217436730981
1311644146663819919123721716935329949959060330598693455467525016156784754395035003878126032584328870
9193252347791402759431132263977331362764760718863071911295536445848521849245012911624117911407485088
5968612741540352459458957580364000972351230040016099844340080694544946484133988349226741725566741724
2103393613726768292175630916096363082645898746220817040096718983683882791489465764420689320074518040
6481669348292925811831206658463266073742682823478305512815162219960007987469373332767214385782222115
7592932550499176783049645643172788434395369355167807907295203084517451170790992492528665023225246817
7111064572186827331441504984737717797362937444897376329711597568808112285311898195651191450745826071
2651471335593498859359633681194459304228962122165804738872862227551444418848617534127310851775310775
6587498537866332186249747428712856249277105195588655605276570020197844976535837397778464181452624280
2833277732947933596054568918123278857217276133009722448258002970447652600646589632052676050325603771
4570316666335575464105363337033194302377653019528065164108091204663926495960197052936611500109987583
7060563867669706228127440629017986736942455504723825910198033860002967222019541816608804813865260416
7868738427597435091245977798311690991398805727407318997135295223388162681705065074521767437555375222
0426868861611884630183497472100279705044808450516442715051961984792729454212081825249736918551946448
5574218956758375484152435312165588626384654556572882388655468349232669772933385115763498295575540186
2375576871652726180152148779068355316502772137460328288478039030741893151752944261064403251637913666
1090810150964432940538998841815994024394771893285861757704922229256407945726748821580342715912327040
9878415844919104534921996386815238488104150602023605148209148848753969483106686940263822953932920993
8009854580578551969245606130941137147375016395989725535198343706328867042734561265188380952241624125
1606225854405898509210125544675102794826376831796174101905763601312300299701546570378576396980164850
6747802913758378865450083723206697325515470828576961322490003508747393142029900026550777160449870603
7310359027467819586191542648645733601073456223766124550050453463597323503374214537561875591010639450
6325776721149069117741168313050332721605654768492218895426936590467889677722026425638454214316821088
2712149378148328693784679860908524109446543620136258242305909293827878936195573826198191912113454369
9600001931621723091386823693839214598643935047198455229993482471899383029364855389131989581568902525
2102490925241270655969620680354606782380431193035513644065924526268883156714333226633119533091676823
0341527493609972300038611430829061867567436430172746411012806621090564866930015564158851435400030193
4982445117473936113738127961888816878237594779807363874657594191827813032863290566652034000673752777
7012822415063450146403437870717339987395010604421426316440024103500839141697989400288873807618251881
8430825549378452867756274228370388245161779776603451960213471023834885960461584704640152001003738983
5315557522443890220377105268400250656814222429978577121620230753808618850195319366998920034045745504
9399820106475114171879844572294069026661155544943151515541226319430821024473164401588678379124275399
6999440346034306041856988665576983445336608757285934554333228388080785388881944041684716117628375500
4117439213563696268445838361526391451106168331267804999606372756378770040748958459540157679386077686
6746428110784561562248617768066724914311702132864221627076436976978245993714263594450657418186535975
7759705675411010207384514015987193000075959768536240199881419536793025847533750786674058473780215274
7917602541917183175903909377089708647152418391808822810745588561790364917729084312343710587598938899
1191774963708639139625753970916607238037714114925472186441263718434936075451221282181549287702525269
8507066843266537351594118575782046017046130276761646609301552519844302239834721326295465437185744694
9480864167822427485785064492447172166868596416945792498878480645118035067140769829272541354822866648
3395078979221612797499077816936222563564798165892544322809202607446008496126734351069557574357686045
7246019136555643731756091593680767140766427405911778482544918683960800871583260481094830161923049304
4270575051936975500492012048033575393803139786305846767205943080801406658491151545274993863936677213
8061342131903851605216742024190447284851704463692888133104720990586820962428643829816988145400349953
0299131048967548285217999237560125339147219536283510577452137078494244484948306755539203812278488317
9879797449424009692029259667051729998992436724594346522320915758579377932553774504589367068856666913
5885028962062683743162454836728844142824738922857341010769934354410117580476147473615271927010127861
1809968238623420337199506515526045644843565538644279600785290779424450222109687315522055597381897892
4010210715675303789138296266230461638820240962239032006421853501399899854439920616446553520239141070
0580147304329110375881564307023948181147353531803692138498480648709324428553564310682806422813500015
4481767852765518576557325983929017628927821197358356926382408675391032255573440001636121489945229468
4743848947311900723826830371372098532268777154498880013550272565144698549779676680108751817972318684
7921536164119452009072971681820406903717576236888086424033805873449092703349267465760971120092195395
6411648460372423953689085531854449288823692170235512329960615318188224628018739567814681431631933864
2513532641508520442426937332671173797624497232601267475610581767283791577548384538298806904398888066
1507316197142377240282024605433891278057561569146200762294174817198206099217403826496281433338306110
3769754742993628894179717750459880749712184815913147682215890672762131966756514073701371586296378184
5569156500308357987809803330550875778806890807126597830344250657710892787829726139052334607526946034
6227341474287231642475332080083520366507239824167111211563153773509631849399940651908579536292962337
2900254773791762971272660053728509168694917516516354098137059317916864334854344411454814390668978447
6172084891898065172289657299300203552191568879151303712969199769318608950757251304652304450888977410
0008128381205525309774723293145463730296145506388402213483653197673327108182650197165393293325738711
5460098041098480876318108726474911773760606477201875384573896739084979324652315981480157171774126465
0505520840483724236676483431818824044661582301527739114707036542616310571043809994734845600839565997
5989807774973178651438808390567183324681594190290031193319991833214403418670975063412745443659111942
5576421097846858380675831736336752213849933813238024801194094827378992409430008558312577385968325726
4212914673823937201362408257529854083517101861174717875006179025248061574684448670672511989337062406
4470241393197580164929241997841013463292089860963314171860424736162618671757672540928077445524082905
8730498192222173477623659992808767478611360513236014798248863838546234783035985849411680328601160727
3408527362969144456399418997746467952685940972740142651851241517439559122814676550102960261255568454
6781979683642670515394188631500416614795199220987913054995369373342432089751327484053015442714911894
4976885566755658911869957682736094733717512480838832471113938953757886022519668411686259157766942365
6709582366699355983057759009514365918139073007967601618378207321040042378762553927884339232729732828
9044093059020248443401142504707085534377134846259073165749032571475057988884289897237469305032771134
8681093553849682195115613179754650006201222926269610781142648370779729087086717970021373477068724452
0682110477879112744836522261038407511933020213003631539987921016857746689060951714106647909846046194
9185007591003837819818585148457243639579419578050041990274086777427509118293462346817134073952867265
9420126661677007321192077654398261719851098229580042462497806986385464771851530203997561449429022595
0246551480050987363503503433476977210992818840139522916994049815155136488102749992776816430774760034
7886095531776250622712682887177748093654602425725299491727344111320691129239178868451066953701286413
8931796550743031245950114906787883026175096305729173562195320992347039254764157980335355058132083821
0727383022869106329757062671230943847081736634706680543592599393121124755422707007929019318689645809
7033423415185133991186760937815680749281262235530315765561373400319495074136198185429635423423056144
8391928173169194869025003113960149601003707607948430385212645367563659606839527145514945402797655876
1117070915431379596362893036176648277667405410005087301126481839118870459361198240383285878195748969
2337012979444358614237068461384579469073920936262716195008796030106924365541762082656000128713366888
1536779103954503621795632640725594899146472603279355575490914555946259342411847563927887553471947958
9060037124055103362841400284298868227249234242174343800959752278635581438555521060715361125677367844
7384648849799321304987929178752585310692977790000350314708624821615079780582697585251034943288934522
7726604977041922463009923349623304092937368107097623247021879842659101286061337273504378191259007745
7307927568615513608763456161243096490161783048114418344787142462659617648716062529148067584510368310
Out #5:
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
In #6:
100
4893174469394291551798214496560277648511483885434605490336232863246265850646687757205345216237491181
1138875056948661015431745215181281096177115888969885268796264822196123554454529009427339910322879459
8707254114947541641695981224496465521479628221902266321554905182929094976257326433733398285920311438
8338769253716113821107156216412995045973595349942106248852508287253692275485556851925777246910636845
1143681053988714987650087311610190270108783135915179033665800924955332856845533110673109920189737708
1860471592283201031942289007770987658416904954670733523887039787959884344923486327103790778815162075
0702876982768885075638347592893947728375633434392820422186972133847104837747978257936350625102638880
6449920944048614307403880639633749890349407891765519940089759103294502411593832646268645813292418793
5294337520948058057771340491438355675495501830377173200707803369873314149849865321525876102176719146
4252877090571735551856562153812653242511290393080233856366835165036168597795654885295519978228479249
9007069558259857513370639606680971135592361598718562672261565472747240424762177135908215549573885867
0396152397934873852061112381999493596834274074432604878380265913161821059883253575095070286811797557
9157061436896479487504320707760687279145510773454406245803769755436141868313682872330674821579128304
7736560846765387357898302439789319311660622233839185970788329220551166634738345267735007624911319699
4091576341885866288128403401444358279284668967625315384863594812716867658533761411486942833212395915
4683032481002001969900415696746073550518141474466189002603862745933060763372225286627659933401813932
0849101979787381766101056699593175561128077424095593692520436762935941529856111813590946412859905657
4771253592754206085513530167818495151228067743990689104098842417519961304230307229271898291055752048
2106692377902045971870290220247030568557838677894706517600598758767413689632427546338314333408394441
9165489352793756925745949365899853794448915707836027390482137533946216930857401640796098946010515252
0104671314205872149909665845557433525439640454316524326851977757081238601855797398714799985885808159
5703500871204385606142237672789134152249699210115624679662454770612677965998813513653560672173225692
5870853707512371173733159163861627764209311003653114754064837113585000977579701397582630431689920545
5464236993715859215831285119633220822721045364748397530537625733969028090521832929579820336139921175
3393549994835443051034208728213757820577910173676678491785528805792139932153132205142060103713919844
0653786430254865954996489412195232619001783448711262519723857306692582660884603265165292055811900459
9290768684525340327816323535806405922860124285117540578581664461517001843458473953793084684977184695
7736192227601891752462805438119959566345440956565136597802965087236968320897951694725854621287500150
7311457535679080059379073566563095352819062566160770531368549890440314070631712236977871445417689667
6899354861208806135634037068332134011465062114546884769881140060762562181252909879585379706772178445
5100592648786349859940740213207191736477991314036263585635751847457980354114573107534013494916723546
7169840396532258368998573667095573961105159268259255969254235574912962608969899808204385023862233108
1891680065082644943832603341578591475150039970285682080202837618850258838596167926347587114774018991
2592433808164058249698529918998701121275484730715323448198395698104436123128794014761248265064527026
0187723091770499320334832585791682291944208579400439452986787692730196096734030166866431215748527996
9677029162886344769062749542682451890469335553315042044003433447935905767104188043128407166086883222
6357780859450906294031606052717367867492718526024176478191728328338443119251042268657606493622403820
4841780850935642486982310657368383545960032733400550157805826953600793871566973016572081582866488499
1853464562625325555024993536064302103097960240002746117254674681871624303955568288749980487334777924
2859298444701490204581439729501718323648006318430260752451396178711296075225201806800791903509693624
2895285921384335196402965811735415881076097167750695602346080825858420921869044556639555682994465815
8637393021120943211234518796856108423472985556089893464281234650681294813906098750171663727713001494
5556958348866840852401156820357795465082365358503010319410692497999425666231023201500270142203848914
6077631733372414744082857241435651015465840551412367869634694091594958121577273656010072892100949686
5034741405716943955221915102789067764291715702961856650514632645602739789125502830778953212193908929
8525495734273616915757726078620984592291624811708029704095264910953566068256920766982483800569697976
4795338690910629580931818362981850959591729302494836969623417804143240151666748699169051277187077526
9654763589320398752351696041331342276936134494714311726168687437233741949299217860619654407766580658
2227897632213763410943858942049975406342873690218246660841674019922433178508615332282205602595822745
0227141609230354140150386825919871213693038869847912156698577331156408698561960555756845952801317382
6238976944195265283861251329148897182450992389905982212241432493371114638702045309969896722837133025
2324524091797152795280813758599688420276878447666652713259816838675677881203075733494074769164858624
0707307413128881679026336574546768505258803123773160237099647941970813700105082808765348931089694911
6514384545012699133397966150833594534343433098364922997258867760523574360731908087483817588417529561
9209273401609623021869078031762482543715078052562362913740488288606298020290502690458747095627243894
1432076914253521879620020771360497348802380823704916834849858766625911853384320266536512192309134153
5935165558852228402763642466926438771922062124726484783063528645827339661454007420281260022799876082
6741297618730832225808523689655514519910130761741679882213576514204382194596795002940141568716934284
1312238794156901456000019685386556275567091485598891314781777668657239606825527040713845011859593980
0839517725513853577372409500427246031286566955615483425084606819712824775792265728450313026570452462
5251050145180750395904517831728820563445510379732367436273341318323141469873938354352797859611284383
2257204327206230243606688606978103015481238535690183475492854299619622955664841842640898449951919855
9222709733034520642383098070132840254008804959526979594279153274772314260994569781046453992017208496
6603393828678540502681448168797211939383025027167691004630632235292705709665875700629530365169977104
4585564130153229952314655198919479816564743640628580387685671948788568794766486386630650853930729582
6729402693584551016637696661094262023544461122945965977761066791800799803895671785639871762920676301
0621615768514873888259434912871456681764285283306333205909244411402305986435782240476617096701270076
4315805638998751533271573074719485528446420469392277354457924191829288745884839333241483588666593403
9537665822326074268759071748926677877177201138436959672200896446549223954524058088958765959702094198
3460190677705313061441321956171569257986090342722419885363469229501984524492426775663213963762153968
6700841652451667980015749794437394856197828079764453342227836335587579419010308349401331267273764104
5293267796228538314994373145995403763113313916689383091701317994253123189862993219600349853809224897
5409039530912199961633307517602685031067781713834916717825985118168984637753253693543809929874701019
8105394445763071591021053615278459249904312864675776162771471147595707903011728170593788791513644210
4199254532773687024094208573646080238107226972199285350262117151647712822128719212182732269743525328
4344273424284868415771635292346270500821001826987817129033230346997033755881586805091317996293243533
7417731393271789767472949465961636624291173301181880306388085487937308149283184195861332324743137556
1534013830301166381586317293019793898606415653698875756784174585462666804789262461036757277502419726
4062430686553915187997434223686425496620610702062928728991823395590082189978516898674313720565293097
2514766280566177472941183140389785202083798549971605068421491237457169181794127598431504152101654962
3005413330314313872874104416978284480352602271755723042393171441788265952455638753292385575481780478
6142130218980535353808636486776425659914624918143739760535990147472590469363603226898481199516602745
5990026893684602727802876927177260179554148031089220461614394344225872228195318248230901437997866995
4699386839519967046034295060756401110012113092307885525521249180189328511746093087524636843491101526
5971921992735987002599575931822877293139079708325855979118222638603658054778813112432296445191574039
5762570048985377940301445101435825426179672349956899748011515888268865413179405846585740115293669837
0555735982296233678241427240312714126192013249573283525419262823722783868008830474267520978922257318
7757843003762061749255949158744595684092017070171924756833251199532022099557898506618917443493911764
1833940817931537650553587713037593190476289946042826099012727507553009113122497978375706741929628028
3653160934599780603753247123852092570147377648453536378263971065628835519087254043956984949831674697
6899309719103175421497128798787048152054056332467103473015109039761288772827648172421492679876285259
8674387421476061662261605757178623222327716283526018977059682356632437471579113094036259340208940472
0622662449725266320570426758648734174894354979953159669500359862656799302593566904123301083463572840
7782171183777138228007039972784159716610125703284049878434990350308235642374225332730100869547381669
8666085830749749257622001934996593408642903946940929133237203379922170416606425650423750699396018480
0225272039953239987820501514961174253966254409869049444503701022317436995576867486503530405464488348
1109539999443865766454234460042730847172518244871385528341255966152614708227577975550010776230385197
3447341021769862621514452380187726258665917256231720395061573430387364174709126813113222725750968886
1747576298743826786415327133092321877410053435087569328903461151123262884310895691035519029051743148
2612069352521568117848448718460876701500603015327635751003329565901632455740083319992310780587154960
Out #6:
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
In #7:
100
8305926188572442602330530059619476371973190531059310839598554093787356463432459329411716569049960498
4077235106868195098286537594341769374574722577898818898245090642765092099032843442210732549834419924
0425001236324101703801596189249864276452615345555998295994538838749815523806516658978725878411926287
7189712230361676845110280478166015470848368597013654373793290349715975127312752751904307707450935902
2745275011448152988478356939328583498564719769615640911624795890713115322787991586057347393893977582
1136404235158567695705075239599410022259843265023308818046918410114511826962106683849937510606604255
1436445211398830355985108733017207480981167152296572463604342656330767873579349304783299886725607229
8482181864924899169327558652487448171412283315580128630553081861640576605333786111836585000268318241
1213758379850465673051079567384994039304999961054503341889697794623113643470309927864040145483050911
0761745247419845489341871092078290586255996595771671184229509893440024830821668796072381953355349372
2906268541660728055184868078926609284617141569403439203696067944923409870688747078119991563672543521
7027444303878058629587564440244656681865746388595135718724880283485728917515710356204096340097795787
3243935295561839129254540574548202644070183251394132884051795442337331903951503293004801238365488288
0283869186244432134007182973178287394672463217792848337194021048617223870837817235938252298860980037
2149462224435873894097699180389131817451302390839840009115613447595537889609772201605823638461639741
2699627719135429034829122201984218924440632218305692369126852891875131871243607901491814889343478872
9142276414252034750239233456358114362421762676219671827991448648577897767009708021103477252396209296
7685616940052837434196854162344423602968462180833999981819313157804906377795434702072666444157345557
0111515731651787507745267376968540766014330309848521492393875358608672511012461711294485374319186185
0804741892646476505206244599490701324743914851411333610098284382290301690074022202355639207461948600
3045098225656472757136720035027090267075191796430850101214157049450852018635793349067878798482106805
4323625278841143732606945056501790485872320789894122833359778048605856530211552840407310282716201640
7367778827735204186425136801405125146136779596606484547655875633881252362050492016249651008462598711
7739334565934674079371549745429974868013563876899328227710940614199299760664264400503917747123214129
6603925751692712786777588363268744187625829309730014026049697517150494651373656904116977695734829114
3526281324595628108401450792451450872116650496716428524467224031073815618184800577063659983798845455
6588115829433130274728395791843887443455279645868074908012068711771816359880976253383229577271629734
9785970109441783162038429219549262615955128220751107272365144699063236708215901852747370677127082445
3650922822649908557978212646065234590028423796459862705127273052862318431721034657149706693612898814
7196674766689700300060945666665387019890331421222365885978601539806899473212885178322030561196097547
2868258801409204468713721333926153278810122198007369780066576554017393146543788013017799934083804853
3574833750547293980499597946981869467903578483098068675887299274730688004730168649895314717700204716
5297843218639136698202416523140975825470631111207176563285498432275130427155833523516516145219149665
4596333327751200952311534157940703496363526529554744981191158124808271907212940123249092321776440616
4979728143391972772648204429582970509640213769139187714275734199856422255470330577616528513430195254
5390841872909915637581928812712909694010670989466073254918686885159658051961824600635991877494109915
5923846322371964983068277857153899216237138199947893068880337669807734499053888011654599486326574500
0407013751416885957078870517282718491767437309015796334310984708677998143022237883441302134883383534
4897201504686393207528314466075394603007864130154317200204782997623176517489268900992742889903507187
8874169535000447082235648698094419609847587209675514594174741214819775417643293848473848330707452164
6632991833259662685426087448710047853720791485290710042043405367562854359676943554937159611164165122
7496941285189476751598939080607084040120005009519427543201839238371600764454756076748837462402968948
1753871061720430422660430655666656155582595035885523409598229589048819763510496959090095406230189688
6787609352611271280191482982224607244518602031152018027089836278807511633471447614773346488650218487
4781914504166728184769210866729556282345652697014312381759263217679102820701126235452721745136166541
0866958784817275572727657510196462715339443568132686748451621573261493065887244994586530268563218826
7848122615820842878597818776377528522727739722239344458148365804216192161248220329066456340921945417
6909259021056112148615165447151366762808371861561587765763000783887241027546595581869490985896168122
0654034816556556314687455053616940436543132594247566341442685829440430615466587339829112543825708328
4471378827957994765547809171501936197910213873031361752856419477925030262169676005598038061072783271
7403083326822102138749418744934630506292797837294466568760937530502105777468977009487203172338797969
8997850822681750235170109934874185464435069648706121286480164677466798808778429064801916994373247755
8424823110750323177927427086176492215197302458856122883805620187943322625345851670939761811344948680
1285632575456027526079759734180641284675800892144974893377706317584329597500233003977502881658058574
0054467438118654879082457790482660974300551429031715290140085028276411834771160528774099584639658905
5083560861655544322613492175014509013240159788140360274629204779467028886624131339588187721169441968
2836764634698479915891777243170212816850625689975834431432784467978848113672987146902549892726150349
4215181181280712105164318407461023396245553888112510171167322738388648011798899271179503121666527350
8884673520500815065462116207063857834539804332483499660005946399365038424957839768664172457370053733
7881813120736276007683180114503771074926261035483834892830039245934745932724836235229794324519796759
1852575056341558967436499116508731327433594354837989573873254085712924184448616368369926597051014066
0233172466406791382922542343012875882918679936997302445677313901713308564226218945508574196544563616
5212576203395757741527279455717716939542371863560312762618754068260253688708491228554911664155736161
1691977473957446628596094162098772426355378800225762678050873439170410596476082606223481997873911425
0101772350211902245270155434673516168363080934315776715518313865653481915427030455186583130068744027
3988492234674286088139214357949725371836230596509530370734664744571965845693105556695373577383286258
8204632748782110016022603191734073933400444003722447802958674678214664548608161146368920960843430347
5645318078625109898287133321330675925374179836315136860720313554830994013019859925314759581407940226
5964265213457313249515962353774533277530583884570381862248529223309385414691134187100643398143571631
7686706428388433671114268959969575718238951526192102790619907826434573408476836130735130093974533201
8782891299899937700493447458427398511247512958291005975003956312852199603444530222105567482798747687
0904614395080602562819359578616001872258337945055738703060452756967833067710850764458182108856683286
8315636850097314597262159472905380248635158623947579681644775050744224860603449387115063868002642281
4746252690839365213059417711960819835131343583555799570389456316191049316274991248457671968137708684
9773861928852239333532420260508939581139533422800648965335224547455781802469847428937581622909431700
5398410770606506897650483992205151727716909265282232757726418545139146782650730358862391578576939285
8423694613361065031169660755389118325001774481415149975452003246106250915021687117728446723158264115
0364680812682479833786544850072701676335724668101191963595798006052952119333236244615067617325824910
3177783208871834708488223630375101213277430037268442732597612207327817982920486285017674513048381071
3303664548070494250798066006403473376490634705159354406504247804799842492372441364346433304845880193
8277141960096305288267589580861306477339013858464323310228579429554239572332238031651857992230013250
3009876375719655499340418833200196548175083667938925698200430681553520406108423576169396938779803938
5856409778980609240019819092435031766322552379846888467142642009029177426721574738315777306510166918
7287792895823660488906566790341524748794545377242796566196237665234851595032476547072642930846021499
4025577664713787598656993725541337329912416123024056907500012505410217038806332437816775164661107021
5253411953024448299140331165206706188988535577478702716487802959055987469739754466852478952739007399
0702895962381034936282308549392383320322185863406260564767660902078611429064276441932170095729247525
0132137749541724465951197643500454392751039565894654309390980918976522839359002541013829926024596653
8530941933343775695699577157157606241622156176570839926817208184150418985969227848143560285490993033
0417429408260528923538118844322494764983793323669743043513566387218366239788494076258602704601246574
0560424831098328388218096618714907105686798284178748179342946369624304745593626514734144727439270045
4140748106083348629713797859483627660358508826699531703670850220944128819262316453980789830175992412
5921171146386423369318067303189002183567806816319871838238809892264162215449419489772059276658765062
4588985328979352965284875976856842144060813891364594152048221656410463200426414854370518051086880317
8763464474213181613614897409461914790392806992133850720269048711350800031913520163700197520340843066
8940707941639553570085990918959142912928429301204637189711773940783611312900947161977267321857423771
2441465967018110615506843142287664463414365988569772083075742767184649395335020839695884012696523467
4594626069490137326967011037208145723653062928476580822205768366838578727921223766315558556563073901
4996565677718103307503704857326308063682362462886137204117516112547436019545026233426945505154223258
6680583245825494867536997347556766703886471400390594379058442454810673384894381738109163057923568551
Out #7:
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
In #8:
100
9750856422446929491981408057561575213351522297602520335580829438053199782584309485174977253238098257
1640967164892615790489957339849851278706093835280881532096109760496534451614199330037317101770688701
4744593305762993900356356901821086582268221738139274792881450262564800363901844049151625587813269245
5895211422938213861346763203807342944116960579400782145231734221781255475007903175008226742179686101
2554868348091152825632701128557199748259541162719733355418376277463874452989893834661824154455161708
5246024790502219670902482209867084257808576359343645611961576155200308771881079628104369793654926936
7544155952640311234054320425666494384822503972257306763027672060856619226572155517727281938101059262
0630811108893925335395350810433177133806464913871553848289416560571712003753046442580003065699871537
9386091143324240877676394801186407157027185024761750750623714296288357615510204876952751850309122986
5783478832435630602039455655458014753473294097089735987271916295709338347735395337209901648424713177
4699298570582804726766618894505938808669143364789165824308504270882877296787575793178086407305011587
8673250560913807135732009130467174672164771472428665393440801966563410086067547158274028130884458656
3113929592868307211682120961087902578083551258611274575392907546491876332566419717053313226023953362
4897880860276772490140079655400407039304502131282138365211192067915734972322587741541003511530289673
8961731785074366930034204493661109125167539441018528967315520803756645482354436168525573035451756074
4768949143696380955258009934511282204542975182678524471100318785827500082740877110709633049755881820
9948356321670225124824602812200563769608654065260310028813851682842583220584135743088876483333791209
2017631457605190453551545746243557362383223345906864148663838880933479650792819243518813115660582672
1429997589990072141065033394328063524911761910317396067638266832423050039346555608029825331566401790
9768763043210010754210126860534615849748287060914889138549560495766273831515776143239993256518981094
3881151416531679122725764271068378318272931458111623617842697460588202609610053978583951566008479610
9723522402157643326649690783848080451176670405680055727979784302728637978030416385025160917368318295
7142640562155603442187935808398339970162750594331387493414034861020321167828660064339265054974032023
9503887127108689149998558209091128903784565612059300306987193476523519612035589850470481151739203951
4565764966852951343470674096838133177555078438042464097394830811054535028162683430032033147577163028
3488725410786585371361637317883910299708001136937760950444399708865052055486678568890090226822201703
1592129916868055387162526088690833230025796108122383027097600041954044236113095414566873434650375704
7611927085362728038720859362399475381650825186054557782886138947683202402495351500005136643309446464
2713758185426740653279374227755721786660660459546050210995369831709518293623219162805751305277207601
3126553734798179175367725801158387310765112066721553752698091787456189664785481774971873738114913903
0411231905417948443097345486170413803689214764991653502017416450186910100987345786699707756100041905
7110498384985647694099740095517173498312490049298060405006755429898683981394946940922851307676669842
9847733901886778677387879253663353696776581398083846795724885718208389588361067835282456099041646986
9661445517980047019327363359184238537047515606576045786411240463297914478223177841713199212287731952
0212266407965585263804033545256008676410993394638349857448214492398207516764052875726847166788831164
8992188824372946355168622307383620714483376952248979936808949746211135967318921138050450371720491419
4268081949459692117776358756337713835920510567665477764309675904235086520618764046453786813018624225
2560192600095954631897284948327365601254755693974163592802713667066141186941238037747169553186470655
3649361069955776972215678442144174190555172198596029380216178492211530723623992667587838512638923932
1389951246507470464676531582724629313484997971369675734369639816693929670512894288719259252722917932
2497649672979166387215558102792004782403145028839767170460192995457815264437996395220466451087263957
4480908310113599601266303340776515278689301297930632088009661332562793471560139948236956717292116747
6460075502153476273597048417283431282828294823416992932221615637627251821539739547335168763174722523
3423543804608641534053356166707989524674852318456252816825244401696087042873313519180071705248474105
7930894666642712563409531214838905759159834920714818940398299509714835193098720418687977530406358195
8114700352360495171161201215914401276479490775732418409401872256553395934640438211938564071471743796
2126759158572688084581980695879396398418896581388956844213339350029097771937835229895201043682003147
9835101508556531572440268916060357762016323547860129372787341309549657587864890989924925025722833240
5914852507413441695006037958124970258133710034828968943157633409044340089863098372676176026644430265
2483631467121301143088034351092335614056616375701576595985089024863073180972741480239164008357497239
1168857628326757912615601704436548554820490794738475549232565950783822432733321287046928908288858011
0447943364344687359196521941222142565810816129032811647525043067547970868864815363564222625689439749
9112058824802667264534223062491247705828602889950302197591830721444349592281339270782058289455216776
7129082102939338698993433786981501821598231180773854821364599311818393720264917856412605862909814543
3266496593150902148193823667209621117197266898637694840502495433803434489684066082039003664235055165
6884061278958349947430590954037360145190261861229526275783912762923585573211961226809717780398459034
9698469431845069408312240457453467495827744366140551412855628785160974199312678478581164096975678546
0091936939010207037336428157957573391333822599348352879673603063448075477045718489843812688688468305
5145787047480219711250100617368825292040671001790241667314692086238058421595146112546699385259032629
0929914021221957847535335730993728735477918465170928048725627010398991833060062619900936958543720891
8253423558593478225563643121723607578129761188584958900434714779468578853780847943260419469479826678
7446669399666208946074962572223981942953750328422067648181583293656388964861403212693401879638226272
0406534054817977412720469002613469754675754343237444581299454110871151239922446249897660217909090190
2725865655289654606804648437178898092108538805416240537805921247642732004797823995589747237550071635
3815232698252940069707654518778367062543028214385625262422005143978067468432372016823225770598484741
3133446794462075572374384693479980629507995550440768208085237724101775609186601447535910904086802313
1896968419431863617294247495133181059945480154720984950613674522626559915548731632359511207866402714
7303380733664678006430481712232749188946213711514365254887564115833077511460400503220345910133495706
9093446489478439708056365527185742159565502126843661654379670740648523338718813363949181514029017030
7223812380302716044662017808737333321258398719584835491589227650559482021476321914477632701404635250
0490248013314864995873316141406727205800548610636305773167014443774464077870052154515677243814931679
5229554359589838984922071270336689315597235844520199016629221634273597750522966518956987395991297405
7528879422816298911122666392921955138698576925549489432674665802475256280446516394074112182937902256
3485978954646938483194401727716066870658256444296013741912225046608901276185112645209153721207287954
5855359034800607293830234065554788675208621659534607387098369042202845597340462671718895493358415630
3556590918331670235523938038742361040378157909271649376371853507149331694614831933938205654201442641
8822078918474636980414108270398718487638868168336585048209252224871616529631171994987835460151155049
5958232835001598956905701880632738323949703208182514076322950450450946247398598646694317817076809496
1712251515132447816554244091401746183761497306136145790900557517557208315574267867642647760841232089
9500550404007522041376727715423696065364931598037343961795063127953288009418193973288524910855395419
4932053224355339443090588365889568279087111335144906602980198580292223009191819060888231829554276809
9896065898728115767733287671473185899631530985037899343548816379745190385451076205729743623601151511
2683559667223587909122780980109670058879075663245259868969139381098077519732298631519844504601579028
4007367883641154068610156966551149035219481615371279152155244898905541362002598004168053555011621347
6041616420623240073824050271386398130647628649799921229388411211837753818136020000324391520808586337
2012508452400275461872350671771390411527276910355138808004832798124708157136828184446391258475176832
5286754356139669878383650187201895182137817803079013248034473024897603759989166795472446633318605782
6467223667143289528434979564405983705764204815648364839418025292788657273229336837930451079743926448
0434970433915259350496547825382550348342581548138360262509219354978323721927602065201714208659636776
5616414619449936871355064972600411136772353811251347874795121437475022427833928438208416897638014163
3199162169253388564862453984841918130155817136623296303510278904217972208873451125249591339279833213
0226469788810389889006876850983079332955912600192920409130222613615665965049136776779462499834941132
4687215058589644736162586424096200791067958287247059285930771344204201789760284474620106238898590570
4572760249105041771274020684915963569887444025615073025742171429024430642004461121139294981341786456
8035030211334053058618904454249821558084183911024288274993556638095157560512531658226177356716933285
0218974772302446023460771706757074565889379542992996349497450450999744606363824633946027504281184568
7494553194374722747642043583635607590562776779668713481640495121950993867413819459111926546517034852
5366656909096245471912528055150890392682492773709230632064906867150545038815081392401187243107274924
2540389013184273004324139675628581759131133954419976449444429571147741386743668596728510046130099747
0127836973282151670898200755570857741711462930576461701749713555739577667788045605694235383386826276
Out #8:
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
In #9:
100
2180349723449560473954836593698148986654971986734827759776510278258997753123326403989855973783474455
4344743795499279601160752185653548932010294231131575923882736460117023812730360867673251401444353795
6294546830403549425225482210746925612490704073531466626124553091361355194087078222949060268521267231
9690600218037144555642854468835529658119689824064701932761578716161315618758563734743180265689196470
3856567886544550280302084140797525613738458697532710844880220937442522013886826639264662382437605418
3057464228987080325699741681350988352028377920629944482723790330087678190610764113564360414299000020
5202593842653690764983200134899432975603127566581438463817627927870798535094600823342797800384650009
7517895495167930097090220079058170762868259969299072458588912006678574625252103150817819863207072633
8697507220552761487958216192629857822669579054958989786043592756325231794704408091936478605332102455
8617904499246856030489015581165992964086891602633896073828715272040575637673121310327919867372147170
3581875115498360186483564139724906939817333545841953652801948604042279883039657868655594888475979222
0516016441107993028643488716954607168869199898315809350647599161733447942068209025887406150864067355
2106220390697371198911398305228607986624301026853132781964902487223448624242230701843009818457856943
5203345687810990252205840302759425928570645366868272428499535999918930835423260428016861582312547857
3239357519532190262632250720691304330253786223244097712948882305373609152585501811957703932334442204
3405046584143991411242494244446873555634306452013721609953125666920987013598491627835174974756293845
5983638644714402491059030860209557943080335631317386589368719340230561462905726306943430498345191629
6674248941487877773872653019200307247607442085829195398517747719230900121046307713881244522636077224
5561603325983617716775186124198847645704901864105110670390011871340954810705077753344601689259476679
3144875177933473513324984583995590913110538811223842149616603995512615378907233681761428903782723893
8983052701716574067332025815727425889225626092990498902397004425084893351759803369558822291707743393
3429146952474867692741154784124995990931766071206190109284403984121134319666780729885852310910841329
9898998179199304559355611955581084635038110243014410511011599725127811447763908985473731313450490842
9206392490594283852357540784907207616558243264796737635344706192486929541474699849402840280454677794
8811047523340594867404138656521350576906075195435542581852952233158449349729228852581864657284782226
3273922043768792199382027189082349965408060565853187502457759599703469788135565606470440670827937506
0087797988668700800731690712010615681671303320004028079219398498940162819235852014783840076849854811
0277447267311325243059075426911694925530681118895710840727404131741785330558410941939439895123012550
4485024304069584214274703450854673244391874372992904556020354310440873910518260030381481931423743814
7090411031814743152567201319182328621816491587536921220446494500621395064372970514085446701121911122
9192889455637046676560407962122899374027612114565554684472104747028019964088707972378414249850742712
3735828864318263637327242584342124601513697342045959669982031591376330019424272570224796686080362189
9239935831814545424183629654944357748294722286510693053932270296320949719709574126058228423972265602
5201109131148769058256845061109513712932081223169723665686262861062563467745426352717374756667197482
4805286030069643442547708195408972033380950095085814693434847776940401116091078322735300535149009210
1810678605428598133026523247555149647264885418228272239045204199945355354486480610421726995862845988
0920376284818583325017099718594238495863584368028299455236395663382915193068619292838516695206586039
5403501682952473799785644923718976110903463075401744988892312324597688832031499840746868361916793223
2904405730886521581819812126454624801635075017602969353068083806258304395459755753886720796882940572
1006991817892223618404064537259894806584995572170521960030896050846891697313639384385647791661080879
7547163217594489262262270556389123727766843273728236606175919063858614304409263284903704542247402701
1189930270521518657377101492906623499542754790281649806147841956669905584959353193201729821136105698
2676601590525165167282595174977240505432713512610844090012024880393152267661303054670561587382499864
2395764171555099384952505131374247247809184300202579749897471201748078848432565455593427626719531446
3252615449325462244831191796167667349708920102972588042333715326496922473276858289415708951013402609
3124241712465070238215635244550302031170940139353519878736809440795022226190075461744208521280821193
4200096272445344811132145161256496473445326914991203061657714929906567258689240637848751672741542616
9045142807060401307471276141045023762277594356591950856342404715971796357578331948411208492312634643
2954620647790829620981227500351219278823572117713574337314864612285733012898977442190109958163667238
9901127338130579914737169701738735142198591891095208767452042230330359026172281409623238094778881987
2892781826934217708486521856914290224662342693348370532788589992118533491091330027373740005174442772
9681416384990488802767441341209761628763363259722239739989113413369388908896988024279266806156058068
2786266187800358751638720141204580030028703014707059538045677608317927323289873670650820420476943530
8743008862087332222571136968277081167459419519979923381927520653855966802034792033741919449382273139
9610967155482213744508320314782989510767964413333661340107732055378951148881079758548393501325440270
1803875978649443393099435447599705675064003086582253637378562133206277235799607872912797014922224539
0229455807362428508243765846892788139592368648096211909528671164370316637738707589744056866813696728
8266003347661118909388571321577967162576394849605126583674128522906313629356585397499594788072751566
0622205584593281102213640807223694841934334872252706962735632273505206900637687824288534200899152385
8581954959808703346097808559114036812079872245370607262151486066475185758280043285490079940330953070
9730946304503161163736931749674853167450108691925516592649709638237046331571282462211946703283136941
0871559328628435819882615955376175326467236150387977614285333647076943728153797427771144244473237933
7266534090632011395890902304923613200139512358889616953405899317243273385285703064972216084812791681
8219159220560339295527581348326652841568601904677646058244924491605295447725410218418934951210839131
5785395432662083739166964830285851337563957850009544678653570362772793651702405952075756674779868883
4903856588058882515774785948685870124716000023344517053327462501626283254165421065918553292214689587
2361082795375884982496184682566274697972877012976289764667949104759960652239433804453092973010138848
9027124612951648309084728616416697068882636618990406503947365860473152906639823433117700143394330307
0212202887186922438851402777596455530520644856667226867113551964275286644522526772182445458068461223
5999228112196388378374929057074578210982574175858653665900625849960805178932247295889119842710553589
0810043627439613030400082383651984747248191714329438693951860369824430196731931826578366339377348139
6949616957889963831325833558713028038998097259580370865430393289546616351345281813654677338479165062
3222690146396896412740748020579217366681926378287232911757629433482035525505395097714154763852598724
7012096484053656829824499198237267888425250990464043962235494481422807743038140619619051535382889557
2893807719284411640793957882990881535145151057003297211252599571668318536843764381314278551799158657
2723402125735325708111920947047294588108443844109860802836038627644315549276811380228593066920541562
3428525873718083560131933630937086692721422731121172181633101367439925516461712208243640301416737982
5437906762775291903927176653468003361086993400738484247625337047586226398025420084067359596322533798
4436015534197887032638351188196509782529094758998684475429260661504441857732482792206911527513153100
8508485366472223325265278468306975516199340311479686169863325524198050564063414882148760076791951537
0379533872469270502600929870973673085865601042739441791274120181714834649564978144849060744807448608
3161230807192487093423773345699418360879540812166577439801561189658612415942749420648005140933829097
1121575031564869371651227027853901645935009931053042841521942947257428532455021045045178863233381894
8706268634352856073665923088787151652110216432215036260767851174713744059910266642050070012862058449
2013088434951555485130298700445204185568464512924090381446687558446845055897145518421753633843073495
8692657355915252905587867506593818021785678693102913070772581198715344742835658152474178543584202815
9150737740382673354527302588498527379543191770071103572872043884822942471353989276656197532594647649
7459008754762107694205746298082541189217536904406382597374696004235513708178998906050315848328734187
0349421572445332090154931690846470581475263776059121887233947825405772437173493982609896920609869715
2591419987937465629083088281652525900374968775345283485909463014969573334874647036112104822619580057
6272316297502618611194310763188433775860238019594431795952711644094394870213287142946879988036502211
3913901965271009072866207303963997231631320717717060649578846780941044222881113650549669693156537734
2728774566536115134038789074263279623193275293651173843322718745723203277642855742298930286947339149
3539334606464355594353072591900883738018836824933218352651789503382992692059048663777663534017132619
7868217065540734159099557811182324577090259314205015104636530441989709660739105405332522528492688455
7784696713290067074699359553919310967483182160908192852023476946222496297808943883860633442612528335
2304385310496980024531942132987768475961589965021735370443915514651258097620810209106371702340855844
1805213002582887082388596614674244452610439290144925603734560786995531131394855567025288009651420351
1276545323571598981578500525683763574850510524466851690751201115450928584893327709567388861258731604
1107387481398648001694722951602378612765557141967807018625625843655918768763647180855086282142688634
Out #9:
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
In #10:
100
1180667049280739612544171377279328091459853537562822904044820264191649108011261378334574527231314790
3348429994126655977845260618218398366603386745978619970414447954858245757994778132700673024879401340
5774955390580317838020639595688212352876543168269345084802238216172264882974882171434359442494624620
3878802065228358350081478280958828254968359982197823295478485095542546261588369187484663234484634961
8726414371348254651353991648553325070940108153864705616412820386215438741527599603832780687125830328
8266902870782717279154575360057512939338157865048416839142907581527531074685342150239706720336465654
9385753330837047007338901238772315506994199702610350247683097715190452590035044515138673228332378151
6595413199704427136611207551400132683052772020918752857684692962330344817424329876712508313714689399
8289382710403130908141419747724874008857245991582892020948862606489451452831310795015127989806707611
6532077218178721307999981859854774563666553530262929415036561758408377955736885663761538157000047860
9017416135630219451377659745758759003218802689631042410730412312331722504669781227732975287502959073
6798359401269729691257029481189577908950138802518664132538323465990305368621185980566348286949350399
1526163297429091475122016912079333558423041342311079953788397152485240342278163396151817716167882029
6695507455469508678772685619473867029802839214367047252233468688598523380293871526610093554429885921
4316169248317319980370482513239742697073206081508806329906240762573607442388383196262085884390485476
2967194873754079384464200652913358655387101454954843261876391689518412869550295723138376946534701215
1617281691689797997072105431374927476381089791197495774516001178057651889714015983065755267196077603
9158291361530429126466873881164388152401726735375327639846948734025330579415569306555653378386070501
2412396500935585157729899070003422821469341807316284684860469330589381756877851907139693941822809657
1060902671925727994381685645373466358303936900516486538147835044745551494517826364480824882269758296
0215499054295520377503150677180071804571420653378259628321269856020009935751122333113447475782835391
7284604893017407798488138607118387189692894202190160065730318286173277067271827225175441910644288017
0546904238015038775520123265142358953951105552787952045617410659274456580269875764575513050461984729
2981875323602543707306452834756714166939407650823561899165109351008032086325336716606237920128632614
9981112088134420457355194661708537542472248853035871801521547245700818231423717280584312020529963054
2730266294066201023005014395781886989811516286736180980760418625807566998585202554427593469562960385
1792402728355125174716390295113181200612911338082982239151389204745363759902373143997927580287030354
1893567733896300664951308070897278120572190803785293064971445207188178149923780462619349613248573133
9861690397646815775996366072242480346236544612518954933376816200953068378733375559540137581866146149
0941784676258346398146730968489053903496157755522547893363385438533569684614009539040801465481368891
9358725532823763497523774904746287180996215373162079968470386185773963893690354803081591013905984040
3814299023642398958697909372941867362121682762777029286103102761119114715977021909182843554836190247
2298704286030497546746792198381104358397695479389691171179444726164125995594776100464845341352823982
3414381736182587672208106598172098891181361969089388481220900433329582874802603280243804189503849810
2583942759557459551435404883403538574241369813698335406185283113000075277664202948014231077867809427
8438753964408931126764333935340873407998417620529854841235778876902361350960299088704870473612395302
0165945084407687319794026114304061811513601800801164265239820357224632348871627410326533681342827520
5169640842338296925861185522367910994899827629505995131070790373313210636422191686266683295842185371
7585719512619677885067269560838556150000675862501870496143286652437832289988665376696142752726616448
5367817562282654179871224103319821771199019924352611675715822305456376927108519770991918959764577556
2078220512456173481828837449399761512230155741923568105804242623504500535296693330172952969297924780
6753192522038312030063718208340234013574500038851957576161848138986612395980845886622238260763294658
9697896045245208394227853920254530896757715807276629258571171658253092613794399980752398254092140735
3489425928411368637603902519007205680611211073203598265269805965213825133398492954495006039650472522
1868004865195435773965398729473495729627348355375498459604154937764630613668229612470614908608269921
6437151141805935064528814201759632964668545119856462382428051555012027212448370148936632203197220713
6621116819927245183650978570304409775483834703416994716321060708634355364328551773466737038855922946
3286284293308417214816715479215548027319659131383520796854759142578676284592813415690867618277323666
6586320348602437452156475612795820976440169400633191815929047854140617350630956783654266685108768089
3954422324812282127311584995188935639870540132124197786597989479187490191218498410162032913008611439
7797303979331123998661617202952578476801028974939704654523951731473934103045149203575497366291468634
4236432769525185387837967656658901804248867622868477200224120958690396456361929856489646431640832466
8135805609242231570217598097566505523430401697940521352034133092519261597792674141806901159460859763
8703238270047912017317777020275145799639730712545460827803832038493256799126041497678985483736935504
8878349905287689128757619561585842228081849933923345663672275625373847610330949582155276990312379511
3182287579850028831477316491188495320065329418213184944896507371644407213124006067139049293428982472
4547964432326710984967092994773829246722067669713637590484488832047604521354686788850300487477091074
2684857014180519378072598455998766537833976506529013944250323367141321842483178990655257697946673481
0318042610200740148557170668139414489737874390454947614851487969423441255253496728336289228020682838
9068967822542106031094332147504731232632120338610540788522243016762914137029073835482243811766153570
8422769241095256788707300351196494204055729963590306801088279028650456000855619010414534671111879630
3646148654926896186728963474296049462217002306716339450791477227424831523349175135324992432553720553
0701981904481091462866830529025890251016787004130439510730956425652751445859228142125614380181791647
3770000493666916890662272115467496994675322633998982298403658129555788034467749898232717464431888239
5901929651610413522673649709832635326182860350029750148889179534164246574761717978616573042149151165
8820581955595504824570025330916909246206787950969561791777963252615550411446186756215268566090562081
5888855414426550318154459077814300569215399508691685494936215580345448107039737815994104587814730990
2788427907127388619970311867733559424658391899482843091795426273922861642828716906326265408465076544
3255321159230765157503827178660431674916213469837013063760245570605472930670457841262043881672621446
4657238269851711190950720737153288463213554777779422124991720759192195503020617231762632858835023883
2029831597609064423856778293044279174644475176195151204814604630934433245779521554859547453615068388
3860208896733393668971329752991386423553094458723357683300700788801924831872356310811171028676692703
0793245513128858279760738206220557330990168283126222828253321148649254269896248214886843067840758235
9972705811939042036093345524529826006796622946788035396982373621060325330485628209432814427889879300
4632932655058692541506098369879375817384530374301293475284853467368995529614733496865102418671286789
7355131403616411361654271901225887797454862769330169330296223628949096257196600225075512909648472129
5372339199391794968632709226789571354224187157558022300006125597537480719134334104578495969628389124
5108760259338428059669963910153226207877039383613384577168072614797890757579728270678456854687070698
7634470378184545196517743094365006421245675402830198716377912882804529556671317680041026647392616529
3245749655461410304449412879329091317161878024714675194125867182417563886709402724112563337762013696
7964617310506869950836774518062109744089387065394174025632624695735222565197812719752424627032188033
4792720124652215113006187435519069060578088295239777786679124905357980705294483724708897938739414963
4763618013784618515849328683357841127779080544810797351803193105842876744835017510478399970961650076
4821518222537349626773482273503888605568205000032831034151493174994327764863943836642981732375577712
4403439089270804377586714698148576448809816434329653387809689006593350827548597414270665304387919465
3179755285750114202335075032997769682708246644930449261806526495615164047149447283992288611049055116
8759923981202929900301038154375928042723472877750247557156356619977843162702457190720922307524679005
3494393911928874393195445104737795813949168375789633938842465560340491856215091746642761586503899554
5462092076328439668225108522131565921864056718790387356801313410008270580514584012928272297279429721
6931988229030701524818740051669305954038877125956064792737400288124120352698980467107013876038424096
9065015122427520617800898848369490701863961574005423309576147920025805445326612099577103688237636399
5364871606924747867896271081460545021509136019218857093376836552132742243723693575411883063728924708
0164002015469116033859440127429010297326620919627844256543781171846222171262752890888662206475795335
4979697877878541126002784737711747073450904933983432427405066537002463143041576584782710997425692299
9781531449128238117135505730186034369690209823183478069938956061046188366872690257804921101838088655
1789351179146885403119833521148189759233904289288361862765987211843579845524909043820709874785935899
1490365660034895653235204266142616295944942744742021574507552779913346147067097660262035600159021178
9330645688825825408325156008334004579416922296172614288580056539078825111334928386708037361042901359
1753176657257695083825660258734986429656867827840057930019226963232521508123377024822466548269533571
7936748864523864786623643028626224227928419655486018632510908490625086526212109487101434257038153578
Out #10:
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
711111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
7111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
71111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111

*/