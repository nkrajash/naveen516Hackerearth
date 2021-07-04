/* All Tracks -->  Basic Programming --> Input/Output --> Basics of Input/Output --> Problem -->
Life, the Universe, and Everything
Tag(s): Ad-Hoc, Basic Programming, Easy
Your program is to use the brute-force approach in order to find the Answer to Life, the Universe, and Everything. 
More precisely... rewrite small numbers from input to output. Stop processing input after reading in the number 42. 
All numbers at input are integers of one or two digits.
SAMPLE INPUT 
1
2
88
42
99
SAMPLE OUTPUT 
1
2
88


#include <stdio.h>

int main()
{
    int nums;
    
    while(1){
        scanf("%d",&nums);
        if(nums!=42)
            printf("%d\n",nums);
        else
            break;
    }
    return 0;
}
*/


/*
Editorialist: Ganesh Sawhney

Prerequisites: Basic Programming (If-Else , Loops)

Problem: We are given unknown length of numbers. We need to print all the numbers until we reach a number which is equal to 42

Solution:

We run an infinite loop and break it only when a 42 is recieved

C Solution by Ganesh Sawhney
#include <stdio.h> 
int main()
{
    int input;
    while(1)
    {
        scanf("%d",&input);
        if(input!=42)
        printf("%d\n",input);
        else
        break;
    }
}
C++ Solution by Ganesh Sawhney
#include <iostream>
using namespace std; 
int main()
{
    int n;
    while(1)
    {
        cin>>n;
        if(n==42)
        break;

        cout<<n<<endl;
    }
    return 0;
}
Python Solution by Ganesh Sawhney
while(True):
    no = int(raw_input())
    if no == 42:
        break
    else :
        print no
Java Solution by Ganesh Sawhney
import java.util.*;
class TestClass {

public static void main(String args[]){
Scanner in = new Scanner(System.in);
 while(true){
  int t = in.nextInt();
  if(t != 42){
    System.out.println(t);
  }else{
   break;
  }
 }
    }
}

*/

/*Best Submissions:
Bash:
declare -i num
while true;
do
    read num
    if [[ $num -eq 42 ]]
        then
            break
    else
        echo $num
    fi
done;

C:
#include <stdio.h>
 
int main()
{
    int no;
    while(1)
    {
    	scanf("%d", &no);
    	if(no==42)
    		break;
    	else
    	printf("%d\n",no);
    }
    
    return 0;
}

C++:
#include <iostream>
using namespace std;
 
int main()
{
	int n,a[10001],i=0,j;
	while(1)
	{
		cin>>n;
		if(n==42)
		break;
		else
		a[i++]=n;
	}
	for(j=0;j<i;j++)
	cout<<a[j]<<endl;
    return 0;
}


C++14:
#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    int n;
    vector<int> myset;
    bool finished=false;
    while (!finished){
        cin>>n;
        if (n==42){
            finished=true;
            break;
        }
        myset.push_back(n);
    }
    vector<int>::iterator i;
    for (i=myset.begin(); i!=myset.end();++i)
        cout<<*i<<endl;
    return 0;
}

C#:
using System; 
using System.Numerics;
class MyClass {
    static void Main(string[] args) {
        for(int n;(n = int.Parse(Console.ReadLine().Trim())) != 42;)
      Console.WriteLine(n);
    }
}

Java:
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
 
class LifeTheUniverseAndEverything {
 
    boolean submit = !false;
 
    public LifeTheUniverseAndEverything() throws IOException {
        InputReader in;
        if(submit == false) {
            in = new InputReader(new FileInputStream("/home/karthickmj/NetBeansProjects/input.txt"));
        } else {
            in = new InputReader(System.in);
        }
        PrintWriter out = new PrintWriter(System.out);
 
        int T = 1;
        for(int caseNo = 1; caseNo <= T; caseNo++) {
            solve(caseNo, in, out);
        }
 
        out.close();
    }
 
    private void solve(int caseNo, InputReader in, PrintWriter out) throws IOException {
        while (true) {
            int n = in.nextInt();
            if (n == 42) {
                return;
            }
            out.println(n);
        }
    }
 
    static class InputReader {
 
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;
 
        public InputReader(InputStream stream) {
            this.stream = stream;
        }
 
        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                        numChars = stream.read(buf);
                } catch (IOException e) {
                        throw new InputMismatchException();
                }
                if (numChars <= 0) {
                        return -1;
                }
            }
            return buf[curChar++];
        }
 
 
 
        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }
 
        public interface SpaceCharFilter {
 
            public boolean isSpaceChar(int ch);
        }
 
        public String next() {
            return nextString();
        }
 
        public String nextString() {
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
 
        public Long nextLong() {
            return Long.parseLong(nextString());
        }
 
        public Double nextDouble() {
            return Double.parseDouble(nextString());
        }
    }
 
    private void debug(Object... o) {
        if(!submit) {
            System.out.println(Arrays.deepToString(o));
        }
    }
 
    public static void main(String args[]) throws IOException {
        new LifeTheUniverseAndEverything();
    }
}
 

Java8:
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
 
 
class TestClass {
    public static void main(String args[] ) throws Exception {
 
        //BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while(true){
        String line = br.readLine();
        if(!line.equals("42")){
            sb.append(line+"\n");
        }else{
            break;
        }
        }
 
 
        System.out.println(sb);
    }
}

Pascal:
program ideone;
var a:integer;
f:text;
begin
	while not eof(INPUT) do
	begin
		readln(a);	
		if a=42 then break;
		writeln(a);
	end;
end.

Perl:
#!/usr/bin/perl
use strict;
use strict;
use warnings;
 
 
while(my $fred = <STDIN>) {
	if ($fred != 42){
    	print $fred;
	}
    else{
    	last;
    }
}

Python:
'''
# Read input from stdin and provide input before running code
 
name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
n=int(raw_input())
while(n!=42):
	print n
	n=int(raw_input())


Python 3:
import sys
 
lines = sys.stdin.read().splitlines()
 
lines = [int(i) for i in lines]
 
for line in lines:
    if (line == 42):
        break;
    print (line)


PHP:
<?php
fscanf(STDIN, "%d\n", $name);
do
{
	echo $name."\n";
	fscanf(STDIN, "%d\n", $name);
}while($name!=42);
?>

R:
line <- readLines('stdin', warn=FALSE)
t=scan(text =line , what = "")
K <- which(t==42)[1]-1
write(t[1:K],"")

Ruby:
=begin
# Read input from stdin and provide input before running code
 
print "Please enter your name: "
name = gets.chomp
print "Hi #{name}\n"
=end
 
while i = gets.chomp.to_i
  if i != 42
    puts i
  else
    break
  end
end

VB:
Module Main
 
    Sub Main()
        Dim stIn As String = ""
        stIn = Console.ReadLine()
      While (stIn IsNot Nothing) And (stIn <> 42)
        Console.WriteLine("{0}", stIn)
        stIn = Console.ReadLine()
        If stIn = 42 Then Exit Sub
      End While
    End Sub
 
End Module



*/


