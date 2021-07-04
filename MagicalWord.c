/* All Tracks --> Basic Programming--> Input/Output--> Basics of Input/Output--> 
Magical Word
Tag(s): Easy-Medium
Dhananjay has recently learned about ASCII values.He is very fond of experimenting. With his knowledge of 
ASCII values and character he has developed a special word and named it Dhananjay's Magical word.

A word which consist of alphabets whose ASCII values is a prime number is an Dhananjay's Magical word. 
An alphabet is Dhananjay's Magical alphabet if its ASCII value is prime.

Dhananjay's nature is to boast about the things he know or have learnt about. So just to defame his friends he gives few string to his friends 
and ask them to convert it to Dhananjay's Magical word. None of his friends would like to get insulted. Help them to convert the given strings to Dhananjay's Magical Word.

Rules for converting:
1.Each character should be replaced by the nearest Dhananjay's Magical alphabet.
2.If the character is equidistant with 2 Magical alphabets. The one with lower ASCII value will be considered as its replacement.

Input format:
First line of input contains an integer T number of test cases. Each test case contains an integer N (denoting the length of the string) and a string S.

Output Format:
For each test case, print Dhananjay's Magical Word in a new line.

Constraints:
1 <= T <= 100
1 <= |S| <= 500

SAMPLE INPUT 
1
6
AFREEN

SAMPLE OUTPUT 
CGSCCO

Explanation:
ASCII values of alphabets in AFREEN are 65, 70, 82, 69 ,69 and 78 respectively which are converted to CGSCCO with ASCII values 67, 71, 83, 67, 67, 79 respectively. 
All such ASCII values are prime numbers.

// My C Submission: Dhananjay's Magical Word
#include <stdio.h>
#define LEN 501

int nprimes=0;
int parr[LEN];

char Dhananjay_MagWord(char s,int parr[]);

int main(){
    char s[LEN];
    int i,t,j,k,l,m,len,isprime=0;
	//primelookup[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127}
    for (l=2; l<=127; l++)
    {
        isprime=1;
        for (m=2; m*m<=l; m++)
        {
            if (l % m == 0) 
            {
                isprime=0;
                break;    
            }
        }
        if(isprime)
            parr[nprimes++]=l;
    }

    scanf("%d",&t);
    for(j=0;j<t;j++){
        scanf("%d",&len);
        scanf("%s",s);
        for(i=0;i<len;i++){
            k = s[i];
            s[i]=Dhananjay_MagWord(s[i],parr);
        }
	    printf("%s\n",s);
    }
    return 0;
}

char Dhananjay_MagWord(char s,int parr[]){
	char c = s;
	int val = c,prev,next;
	int i=0;
	if((c >= 'A' && c <= 'Z')|| (c >= 'a' && c <= 'z')){
	    while(val>parr[i]){
	        prev = parr[i];
		    i++;
	    }
	    next = parr[i];
	    if(parr[i]==val)
		    ;
	    else{
	        if(next == 127){     // next = DEL , prev = 'q'
	            prev = 113;
	            c= prev - ' ' + 32;
	        }
	        else{
		        if(next-val >= val-prev)
		            c= prev - ' ' + 32; // Above 32 ==> ' ' are all printable chars
		        else{
			        c= next - ' ' + 32;
		        }
	        }
	    }
	}
	else{
	    if(c < 'A' && c >= ' ')
	        c='C';
	    else if(c > 'Z' && c < 'a'){
	        prev = 'Y';
	        next = 'a';
		    if(next-val >= val-prev)
		            c= prev - ' ' + 32;
		    else
			        c= next - ' ' + 32;
	    }
	    else               // c > 'z' , next = DEL, prev = 'q'
	        c='q';
	}
	return c;
}


/* Editorial
import java.util.*;

class TestCase

{

    public static void main(String args[])

    {

        Scanner ob=new Scanner(System.in);

        int t=ob.nextInt();

        for(int i=1;i<=t;i++)

        {

            int n=ob.nextInt();

            String s=ob.next();

            String w=magic(s);

            System.out.println(w);

        }

    }

    static String magic(String s)

    {

        int l=s.length();

        String w="";char c;

        for(int i=0;i<s.length();i++)

        {

            c=magic_letter(s.charAt(i));

            w+=c;

        }

        return w;

    }

    static char magic_letter(char c)

    {

        int x=c;

        int diff=255;

        int p=67;

        int a[]={67,71,73,79,83,89,97,101, 103, 107, 109, 113};

        for(int i=0;i<a.length;i++)

        {

            if(Math.abs(a[i]-c)<diff)

            {

                diff=(int)(Math.abs(a[i]-c));

                p=a[i];

            }

        }

        return (char)(p);

    }

}
EXPLANATION:
As the problem statement state that the output will be a word consisting of alphabets whose ASCII value is prime. 
So we know that the characters to be present in the output will only be the character whose ASCII value is that of a 
Magical Alphabet (defined in the question)- {67,71,73,79,83,89,97,101, 103, 107, 109, 113}.
Now what we need to do is to convert each character to nearest Magical alphabet. This part of the code does that-

if(Math.abs(a[i]-c)<diff)
{
                diff=(int)(Math.abs(a[i]-c));
                p=a[i];
}
And then we replace each character of the string with the magical alphabet and print the formed word.
Note: The main part of doubt in the question was in the last two testcases. It is mentioned in the question that the output will be words only 
consisting of alphabets but no such constraints are mentioned for the input. It was just mentioned that the input will be a string.
Hope you get the trick now.
*/

/*Python code 
T=int(input())
primes = [67,71,73,79,83,89,97,101,103,107,109,113]
final = []

#---------------------------------------------------------------------

def convert(arg):
	output=""
	for i in arg:
		i1=ord(i) ; 
		i2=ord(i) ; 
		j=ord(i)
	if j in primes:
		output+=i
	else:
		while i1 not in primes and i1>67: 
			i1-=1 # i1>67 so that final i1 exists in primes
		while i2 not in primes and i2<113: 
			i2+=1 # i2<113 so that final i2 exists in primes
		if j>113: 
			output+='q' # chr(113) --> 'q'
		elif j-i1 > i2-j or j<67: 
			output+=chr(i2)
		else: output+=chr(i1)
	return output

#-----------------------------------------------

	while T!=0:
		wordLength=input()
		word=str(input())
		final.append(convert(word))
		T-=1
#------------------------------------------

	for i in final:
	print(i)

*/

/* C# Code:
using System; 
using System.Numerics;
using System.Collections.Generic;
class MyClass {
static void Main(string[] args) {

var input=Console.ReadLine().Trim();
int T=Int32.Parse(input);

// char [] val=new char[500];
for(int i=0;i<T;i++)
{
var input2=Console.ReadLine().Trim();
int charL=Int32.Parse(input2);
string myinput=Console.ReadLine().Trim();
magicword(myinput);
Console.WriteLine();
}
}

public static void magicword(string input)
{
List<int> list=new List<int>();
char [] val=input.ToCharArray();


for(int i=65;i<=122;i++)
{
if(prime(i)==true)
{list.Add(i);}
}

for(int j=0;j<val.Length;j++)
{
int n=(int)Convert.ToChar(val[j]);
for (int k = 0; k < list.Count - 1; k++)

{ // Console.WriteLine("n={0} ", n);
if (n <= 67)
{ Console.Write("{0}", Convert.ToChar(67).ToString()); break; }
else if (n >= 113)
{ Console.Write("{0}", Convert.ToChar(113).ToString()); break; }
else if (n >= list[k] && n <= list[k + 1])
{
if (n - list[k] == list[k + 1] - n)
{ Console.Write("{0}", Convert.ToChar(list[k]).ToString()); break; }
else if (n - list[k] < list[k + 1] - n)
{ Console.Write("{0}", Convert.ToChar(list[k]).ToString()); break; }
else { Console.Write("{0}", Convert.ToChar(list[k + 1]).ToString()); break; }
}

}
}
}

public static bool prime(int i)
{ int count=0;
for(int j=1;j<=i;j++)
{
if(i%j==0)
{count++;}
}
if(count==2)
{
return true;
}
else {return false;}
}

}
*/


/* c++ Solution

// Write your code here
//Dhananjay's Magical Word 

#include <iostream>
using namespace std;

#define LEN 501

int nprimes=0;
int parr[LEN];

char Dhananjay_MagWord(char s,int parr[]);

int main(){
    char s[LEN];
    int i,t,j,k,l,m,len,isprime=0;
	//primelookup[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127}
    for (l=2; l<=127; l++)
    {
        isprime=1;
        for (m=2; m*m<=l; m++)
        {
            if (l % m == 0) 
            {
                isprime=0;
                break;    
            }
        }
        if(isprime)
            parr[nprimes++]=l;
    }

    cin>>t;
    for(j=0;j<t;j++){
        cin>>len;
        cin>>s;
        for(i=0;i<len;i++){
            k = s[i];
            s[i]=Dhananjay_MagWord(s[i],parr);
        }
	    cout<<s<<endl;
    }
    return 0;
}

char Dhananjay_MagWord(char s,int parr[]){
	char c = s;
	int val = c,prev,next;
	int i=0;
	if((c >= 'A' && c <= 'Z')|| (c >= 'a' && c <= 'z')){
	    while(val>parr[i]){
	        prev = parr[i];
		    i++;
	    }
	    next = parr[i];
	    if(parr[i]==val)
		    ;
	    else{
	        if(next == 127){     // next = DEL , prev = 'q'
	            prev = 113;
	            c= prev - ' ' + 32;
	        }
	        else{
		        if(next-val >= val-prev)
		            c= prev - ' ' + 32; // Above 32 ==> ' ' are all printable chars
		        else{
			        c= next - ' ' + 32;
		        }
	        }
	    }
	}
	else{
	    if(c < 'A' && c >= ' ')
	        c='C';
	    else if(c > 'Z' && c < 'a'){
	        prev = 'Y';
	        next = 'a';
		    if(next-val >= val-prev)
		            c= prev - ' ' + 32;
		    else
			        c= next - ' ' + 32;
	    }
	    else               // c > 'z' , next = DEL, prev = 'q'
	        c='q';
	}
	return c;
}

*/

/*
Another C++ code

#include <iostream>
#include<string>
using namespace std;

int isprime(int n)
{
int i;
if(n%2!=0 && n!=2)
{
if(n%3!=0 && n!=3)
{
for(i=4;i<n;i++)
{
if(n%i==0)
return 0;
}
return 1;
}
else
return 0;
} 
else
return 0;

}
int main()
{
int i=0,n=0,prime[12],temp1=0,temp2=0,j=0,temp=0,k=0;
cin>>n;
int len1[n];
string str[n],ans[n];
j=0;
for(i=65;i<123;i++)
{
if(isprime(i))
{
prime[j]=i;
j++;
}
}

for(i=0;i<n;i++)
{
cin>>len1[i];
cin>>str[i];
for (j=0;j<len1[i];j++)
{
temp=int(str[i][j]);
for(k=0;k<12;k++)
{
if(temp==prime[k])
{
ans[i]+=str[i][j];
break;
}
else if(temp<prime[k] && k!=0)
{ 

temp1=temp-prime[k-1];

temp2=prime[k]-temp;

if(abs(temp1)<abs(temp2) || abs(temp1)==abs(temp2))
{
ans[i]+=char(prime[k-1]);
break;
}
else
{
ans[i]+=char(prime[k]);
break;
}
}
else if(temp<prime[k] && k==0)
{

ans[i]+=char(prime[k]);
break;
}
else if(temp>prime[k] && k==11)
{
ans[i]+=char(prime[k]);
break;
}
}
}
cout<<ans[i]<<endl;

}
return 0;
}

*/

/* Best Submissions:
C:
#include <stdio.h>
int next(int n)
{
    int i,ans;
    int d1,d2;
    int k[12]={67,71,73,79,83,89,97,101,103,107,109,113};
    if(n<=67)
    {
        ans=67;
    }
    else if(n>=113)
    {
        ans=113;
    }
    else
    {
        for(i=0;i<12;i++)
        {
            if(k[i]>n)
            {
               d1=k[i]-n ;
               d2=n-k[i-1];
               if(d1<d2)
               {
                   ans=k[i];
                   break;
               }
               else
               {
                   ans=k[i-1];
                   break;
               }
            }
        }
    }
    return ans;
}
int main()
{
    int t,i,n;
    int temp,ne;
    char ch[500];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",ch);
        for(i=0;i<n;i++)
        {
            temp=ch[i];
            ne=next(temp);
            ch[i]=ne;
            
        }
        printf("%s\n",ch);
    }
    return 0;
}
C++14:

#include<iostream>
using namespace std ;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, t ;
    int prime[12] = {67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113} ;
    string s;
    cin>>t ;
    while(t--){
        cin>>n ;
        cin>>s ;
        for(int i=0; i<n; i++){
            int ascii = int(s[i]) ;
            for(int k=0; k<12; k++){
                if(prime[k]<ascii && ascii<prime[k+1]){
                    if( (prime[k+1]-ascii)>(ascii - prime[k]) || (prime[k+1]-ascii)==(ascii - prime[k])){
                        s[i] = prime[k] ;
                        break ;
                    }
                    else {
                        s[i] = prime[k+1] ;
                        break ;
                    }
                }
            }
            if(ascii<prime[0]) {
                s[i] = prime[0] ;
            }
            if(ascii>prime[11]) {
                s[i] = prime[11] ;
            }
        }
        cout<<s<<"\n" ;
    }
}

C++:
#include<iostream>
using namespace std;
int fun(int f)
{
	int i,j=0,k=0;
	static int f1=0;
	if(j==0)
	{
	if(f>=121)
	{
		cout<<"q";f1=0;
		return 0;
	}
	j++;
	}
	for(i=2;i<f;i++)
	{
		if(f%i==0)
		{
			k=1;
			if(f1%2==0)
			{
				f1++;
				return fun(f-f1);
			}
			else if(f1%2!=0)
			{
				f1++;   
				return fun(f+f1);
			}
			break;
		}
	}
	if(k==0)
	cout<<(char)f;
	f1=0;
	return 0;
}
main()
{
	int t,n,s;
	cin>>t;
	char a[10000];
	int i,j=0,k,f;
	for(i=0;i<t;i++)
	{
		cin>>n;                     // ABCD
		j=0;
		while(j<n)
		{
			cin>>a[j];
			f=a[j];
			if(f<65)
			{
				if(f>93 && f<97)
				{
					s=f-97;
					f-=s;
					goto g;
				}
				s=65-f;
				f+=s;	
			}
			g:fun(f);
			j++;
		}
		cout<<endl;
	}
}

Java 8:

import java.io.BufferedReader;
import java.io.InputStreamReader;
 
class TestClass {
	public static void main(String args[]) throws Exception {
 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		int N = 0;
		String string = null, result = null;
		for (int i = 1; i <= T; i++) {
			N = Integer.parseInt(br.readLine());
			string = br.readLine();
			result = getResultantString(string, N);
			System.out.println(result);
		}
 
	}
 
	private static String getResultantString(String string, int n) {
 
		int temp = 0, next = 0, prev = 0;
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
 
			if (Character.isDigit(string.charAt(i))) {
 
				sb.append("C");
			} else {
				temp = string.codePointAt(i);
				next = temp;
				prev = temp;
				if (next >= 122) {
					next = 113;
				}
				if (prev <=65) {
					prev = 67;
				}
				while (!isPrime(next) && !isPrime(prev)) {
					next = next + 1;
					prev = prev - 1;
					if (next >= 122) {
						next = 113;
					}
					if (prev <=65) {
						prev = 67;
					}
				}
 
				if (isPrime(next) && isPrime(prev)) {
					sb.append((char) prev);
				} else if (isPrime(next)) {
					sb.append((char) next);
				} else if (isPrime(prev)) {
					sb.append((char) prev);
				}
			}
 
		}
		return sb.toString();
	}
 
	private static boolean isPrime(int num) {
 
		int flag = 0;
		int sqrt = (int) Math.sqrt(num);
		for (int i = 2; i <= sqrt; i++) {
			if (num % i == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			return true;
		else
			return false;
	}
}

Java:
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;

//Created by Ashwin Shirva on 12-01-2017.
public class MagicalWord {
    static class Print {
        private final BufferedWriter bw;
 
        public Print() {
            this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }
 
        public void print(Object object) throws IOException {
            bw.append("" + object);
        }
 
        public void println(Object object) throws IOException {
            print(object);
            bw.append("\n");
        }
 
        public void close() throws IOException {
            bw.close();
        }
    }
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
 
        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public String readLine() throws IOException {
            byte[] buf = new byte[100000]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }
 
        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
 
            if (neg)
                return -ret;
            return ret;
        }
 
        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
 
        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
 
        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }
 
    public static void main(String[] args) throws Exception{
        Print pr = new Print();
        Reader rd = new Reader();
 
 
        Map<Character,Character> map = new HashMap<>();
        map.put('A','C');
        map.put('B','C');
        map.put('C','C');
        map.put('D','C');
        map.put('E','C');
        map.put('F','G');
        map.put('G','G');
        map.put('H','G');
        map.put('I','I');
        map.put('J','I');
        map.put('K','I');
        map.put('L','I');
        map.put('M','O');
        map.put('N','O');
        map.put('O','O');
        map.put('P','O');
        map.put('Q','O');
        map.put('R','S');
        map.put('S','S');
        map.put('T','S');
        map.put('U','S');
        map.put('V','S');
        map.put('W','Y');
        map.put('X','Y');
        map.put('Y','Y');
        map.put('Z','Y');
        map.put('a','a');
        map.put('b','a');
        map.put('c','a');
        map.put('d','e');
        map.put('e','e');
        map.put('f','e');
        map.put('g','g');
        map.put('h','g');
        map.put('i','g');
        map.put('j','k');
        map.put('k','k');
        map.put('l','k');
        map.put('m','m');
        map.put('n','m');
        map.put('o','m');
        map.put('p','q');
        map.put('q','q');
        map.put('r','q');
        map.put('s','q');
        map.put('t','q');
        map.put('u','q');
        map.put('v','q');
        map.put('w','q');
        map.put('x','q');
        map.put('y','q');
        map.put('z','q');
 
        map.put('\0','C');
        map.put('!','C');
        map.put('"','C');
        map.put('#','C');
        map.put('$','C');
        map.put('%','C');
        map.put('&','C');
        map.put('\'','C');
        map.put('(','C');
        map.put(')','C');
        map.put('*','C');
        map.put('+','C');
        map.put(',','C');
        map.put('-','C');
        map.put('.','C');
        map.put('/','C');
        map.put(':','C');
        map.put(';','C');
        map.put('<','C');
        map.put('=','C');
        map.put('>','C');
        map.put('?','C');
        map.put('@','C');
        map.put('[','Y');
        map.put('\\','Y');
        map.put(']','Y');
        map.put('^','a');
        map.put('_','a');
        map.put('`','a');
        map.put('{','q');
        map.put('|','q');
        map.put('}','q');
        map.put('~','q');
 
        map.put('0','C');
        map.put('1','C');
        map.put('2','C');
        map.put('3','C');
        map.put('4','C');
        map.put('5','C');
        map.put('6','C');
        map.put('7','C');
        map.put('8','C');
        map.put('9','C');
 
        int t = rd.nextInt();
        while(t-->0){
            int len = rd.nextInt();
            StringBuilder ip= new StringBuilder(rd.readLine());
            char op[] = new char[len];
            for(int i=0;i<len;i++){
                op[i] = map.get(ip.charAt(i));
            }
            pr.println(String.valueOf(op));
        }
        pr.close();
    }
 
}


Python:
def findKeyPosition(A, key):
    # Find i such that A[i] <= key, in the sorted array A
    # Return -1 if key < A[0]
    low = 0
    high = len(A) - 1
    while low <= high:
        if A[low] > key:
            return low-1
        elif A[high] < key:
            return high
            
        mid = (low + high)/2
        if A[mid] == key:
            return mid
        elif A[mid] < key:
            low = mid + 1
        else:
            high = mid - 1
    
    return -1
 
 
P = [
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
    53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 
    109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 
    173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
    233, 239, 241, 251, 257
]
 
for _ in xrange(input()):
    N = input()
    S = raw_input().strip()
    T = ['']*N
    for k, c in enumerate(S):
        i = findKeyPosition(P, ord(c))
        t = c
        if P[i] != ord(c) or P[i] < 65 or P[i] > 122:
            if P[i] < 65:
                t = chr(67)
            elif ord(c)-P[i] <= P[i+1]-ord(c) or P[i+1] > 122:
                t = chr(P[i])
            else:
                t = chr(P[i+1])
        T[k] = t
    print ''.join(T)


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
 
chomp(my $t = <>);
my @magic_nos = (67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113);
for(1..$t) {
    chomp(my $l = <>);
    my @str = split(//, <>);
    for(my $i = 0; $i < $l; $i++) {
        my $min = 1000;
        my $rep = "C";
        foreach (@magic_nos) {
            if (abs(ord($str[$i]) - $_) < $min) {
                $min = abs(ord($str[$i]) - $_);
                $rep = chr($_);
            }
        }
        $str[$i] = $rep;
    }
    print join("", @str);
}


C#:
using System; 
using System.Numerics;
class MyClass {
    static void Main(string[] args) {
        int t = Int32.Parse(Console.ReadLine());
        int n;
        String s;
        char letter = 'a';
        int ascci;
        bool prim = true;
        
        for(int i = 0; i < t;i++){
            n = Int32.Parse(Console.ReadLine());
            s = Console.ReadLine();
                foreach( char c in s)
                {
                    ascci = System.Convert.ToInt32(c);
                    bool klein = false;
                    int durchlauf = 0;
                    if(ascci <= 113 && ascci > 66){
                        for(int j = ascci;prim == true;){
                            prim = false;
                            for(int q = 1;q < j;q++)
                            {
                                if(j % q == 0&&q != 1){
                                    prim = true;
                                    
                                }
                            }
                            if(prim == false){
                                letter = Convert.ToChar(j);
                            }
                            if(klein == true){
                                j = j + durchlauf;
                                j++;
                                durchlauf++;
                                
                            }else{
                                j = j - durchlauf;
                                j--;
                                durchlauf++;
                            }
                            klein = !klein;
                    }
                    prim = true;
                    Console.Write(letter);
                        
                    }
                    
                    else if(ascci > 113){
                         letter = 'q';
                         Console.Write(letter);
                    }
                    else{
                        letter = 'C';
                         Console.Write(letter);
                    }
                    
                    
                    
                }
                Console.WriteLine();
        }
   //string asciichar = (Convert.ToChar(65)).ToString();
    }
}

R:
input = file("stdin", "r")
n = as.numeric(readLines(input, n=1))
 
asc <- function(x) { strtoi(charToRaw(x),16L) }
chr <- function(n) { rawToChar(as.raw(n)) }
 
Dword = c(67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113)
Dword = matrix(c(rep(1,length(Dword)), Dword), nrow=2, byrow=T)
  
for (i in 1:n) {
  ni = as.numeric(readLines(input, n=1))
  s = readLines(input, n=1)
  s = asc(s)
  s = matrix(c(s, rep(-1,length(s))), ncol=2, byrow=F)
  ans = abs(s %*% Dword)
  ans = apply(ans, 1, which.min)
  ans = chr(Dword[2, ans])
  write(ans, "")
}


PHP:
<?php
 
function isPrime($num) {
    if($num == 2)
        return true;
	if($num % 2 == 0) {
        return false;
    }
	if($num == 1)
        return false;
    
$ceil = ceil(sqrt($num));
    for($i = 3; $i <= $ceil; $i = $i + 2) {
        if($num % $i == 0)
            return false;
    }
 
    return true;
}
//Normal alphabet characters to dhananjay's corresponding ones 
function elect($alphabet,$num) {
	$ecart=array('k'=>'-','e'=>1000);
	foreach($alphabet as $key=>$value) {
		$e=abs(($num-$key));
		if($e<$ecart['e']) $ecart=array('k'=>$key,'e'=>$e);
		elseif($e==$ecart['e'] && $key<$ecart['k']) $ecart=array('k'=>$key,'e'=>$e);
	}
	return $ecart['k'];
}
//Validate that characters are string
//function validateString($s){
//	$r='';
//	foreach(str_split($s) as $c){
//		if((ord($c)>=65&&ord($c)<=90)||(ord($c)>=97&&ord($c)<=122)) $r.=$c;
//	}
//	return $r;
//}
 
//Make dhananjay's alphabet
$alphabet=array();
for($i=65;$i<=90;$i++) {
	if(isPrime($i)){
		$alphabet[$i]=$i;
	}
	if(isPrime(($i+32))){
		$alphabet[($i+32)]=chr(($i+32));
	}
}
//for($i=48;$i<=57;$i++) {
//	if(isPrime($i)){
//		$alphabet[$i]=$i;
//	}
//}

//Normal alphabet to dhananjay's one 
$dhananjays=array();
for($i=32;$i<=126;$i++) {
	$dhananjays[$i]=elect($alphabet,$i);
	//$dhananjays[($i+32)]=elect($alphabet,($i+32));
}
//for($i=48;$i<=57;$i++) {
//	$dhananjays[$i]=elect($alphabet,$i);
//}
 
//die(var_dump($dhananjays));
fscanf(STDIN, "%d", $nbTests);
while($nbTests) {
	//$str=validateString($s);
	//if(''!=$str){
		fscanf(STDIN, "%d", $str_len);
		fscanf(STDIN, "%s", $str);
		foreach(str_split($str) as $c) echo chr($dhananjays[ord($c)]);
		echo "\n";
		$nbTests--;
	//}
}



*/



