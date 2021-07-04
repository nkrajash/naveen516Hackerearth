/*Best Submissions:
C:
#include <stdio.h>
#include <string.h>
typedef struct
{
    long long int coeficiente;
    char name[100];
}fan;
void sort(fan fans[1000], int num_fans);
int main()
{
    fan fans[1000];
    int i,j,T,num_fans,com_let;
    long long int aux;
    char aux_name[1000];
    scanf("%d",&num_fans);
    scanf("%d",&T);
    for(i = 0; i < num_fans; i++)
    {
        scanf("%s ",fans[i].name);
        scanf("%lld\n",&fans[i].coeficiente);
    }
    sort(fans,num_fans);
    for(i = 0; i < T; i++)
    {
        printf("%s\n",fans[i].name);
    }
    return 0;
}
void sort(fan fans[1000], int num_fans)
{
    int i , j, com_let_1, com_let_2, rompe = 0;
    long long int aux;
    char aux_name[1000];
    for(i = 0; i < num_fans - 1; i++)
    {
        for(j = 0; j < num_fans - i - 1; j++)
        {
            if(fans[j].coeficiente < fans[j + 1].coeficiente)
            {
                aux = fans[j].coeficiente;
                strcpy (aux_name,fans[j].name);
                fans[j].coeficiente = fans[j + 1].coeficiente;
                strcpy(fans[j].name , fans[j + 1].name);
                fans[j + 1].coeficiente = aux;
                strcpy(fans[j + 1].name , aux_name);
            }
            else
            {
                if(fans[j].coeficiente == fans[j + 1].coeficiente)
                {
                    com_let_1 = 0;
                    com_let_2 = 0;
                    rompe = 0;
                    while((fans[j].name[com_let_1] != '\0' || fans[j + 1].name[com_let_2] != '\0') && rompe == 0)
                    {
                        if(fans[j].name[com_let_1] != fans[j + 1].name[com_let_2])
                        {
                            if(fans[j].name[com_let_1] > fans[j + 1].name[com_let_2])
                            {
                                //printf("%s %s\n",fans[j].name,fans[j + 1].name);
                                aux = fans[j].coeficiente;
                                strcpy (aux_name,fans[j].name);
                                fans[j].coeficiente = fans[j + 1].coeficiente;
                                strcpy(fans[j].name , fans[j + 1].name);
                                fans[j + 1].coeficiente = aux;
                                strcpy(fans[j + 1].name , aux_name);
                                
                                //printf("%s %s\n",fans[j].name,fans[j + 1].name);
                            }
                            rompe = 1;
                        }
                        if(fans[j].name[com_let_1] != '\0')
                        {
                            com_let_1++;
                        }
                        if(fans[j + 1].name[com_let_2] != '\0')
                        {
                            com_let_2++;
                        }
                    }
                }
            }
        }
    }
}
C++:
#include <bits/stdc++.h>
using namespace std;
 
bool cmp(pair<string,int> a,pair<string,int> b)
{
    if(a.second>b.second)
    return true;
    else if(a.second==b.second)
    {
        if(a.first<b.first)
        return true;
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    pair<string,int> p[n];
    for(int i=0;i<n;i++)
    {
        string s;
        int a;
        cin>>s>>a;
        p[i]=make_pair(s,a);
    }
    sort(p,p+n,cmp);
     for(int i=0;i<m;i++)
     cout<<p[i].first<<endl;
}
C++14:
#include<iostream>
using namespace std;
int main(){
int n,t,i,j;
cin>>n>>t;
string name[n];
string temp;
long int fan[n];
long int tmp;
for(i=0;i<n;i++){
cin>>name[i]>>fan[i];
}
for(i=0;i<n-1;i++){
for(j=i+1;j<n;j++){
if(fan[i]<fan[j]){
tmp=fan[i];
fan[i]=fan[j];
fan[j]=tmp;
temp=name[i];
name[i]=name[j];
name[j]=temp;
}
else if(fan[i]==fan[j] && name[i]>name[j]){
temp=name[i];
name[i]=name[j];
name[j]=temp;
}
}
}
for(i=0;i<t;i++){
cout<<name[i]<<endl;
}
return 0;
}


C#:
using System;
class MyClass
{
    static void Main(string[] args)
    {
        string[] line1 = System.Console.ReadLine().Trim().Split(' ');
        var N = Int32.Parse(line1[0]);
        var T = Int32.Parse(line1[1]);
        fan[] f = new fan[N];
        for (int i = 0; i < N; i++)
        {
            string[] fandetails = System.Console.ReadLine().Trim().Split(' ');
            f[i] = new fan();
            f[i].name = fandetails[0];
            f[i].devotion = Int32.Parse(fandetails[1]);
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N - 1; j++)
            {
                if (f[j].devotion < f[i].devotion)
                {
                    fan temp = f[j];
                    f[j] = f[i];
                    f[i] = temp;
                }
                else if (f[j].devotion == f[i].devotion)
                {
                    if (string.Compare(f[j].name, f[i].name) > 0)
                    {
                        fan temp = f[j];
                        f[j] = f[i];
                        f[i] = temp;
                    }
                }
            }
        }
        for (int i = 0; i < T; i++)
        {
            Console.WriteLine(f[i].name);
        }
    }
}
 
public class fan
{
    public string name { get; set; }
    public int devotion { get; set; }
}

Python:
from sys import stdin
n,k = map(int,stdin.readline().split())
a = []
for _ in xrange(n):
	x,y = stdin.readline().strip().split()
	y = int(y)
	a.append((-y,x))
a.sort()
for i in xrange(k):
	print a[i][1]

Python 3:
n,m = map(int,input().split())
s={}
for i in range(n):
    k,v=input().split()
    v=int(v)
    if v not in s:
        s[v]=[k]
    else:
        s[v].append(k)
        s[v].sort()
list1=[x for x in s.keys()]
list1.sort(reverse=True)
c=0
for i in list1:
    if len(s[i])>0:
        for j in s[i]:
            print (j)
            c=c+1
            if c == m:
                break
    if c==m:
        break

Java:
import java.io.*;
import java.util.*;
 
 class Fan
{
	String name;
	int quotient;
	public Fan(String name1, int quotient1) {
		name=name1;
		quotient=quotient1;
		
	}
	
}
 
class sortFan implements Comparator<Fan>
{
 
	@Override
	public int compare(Fan f1, Fan f2) {
		if(f1.quotient>f2.quotient)
			return -1;
		if(f1.quotient==f2.quotient)
		{
			return f1.name.compareTo(f2.name);
		}
		else 
			return 1;
			
	}
	
}
 
 
 class Bubble_Sort {
	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] t=br.readLine().split(" ");
		int size=Integer.parseInt(t[0]);
		int test=Integer.parseInt(t[1]);
		ArrayList<Fan> flist=new ArrayList<Fan>();
		for(int i=0;i<size;i++)
		{
			String[] temp=br.readLine().split(" ");
			flist.add(new Fan(temp[0],Integer.parseInt(temp[1])));
		}
		 // for (int i=0; i<flist.size(); i++)
	       //     System.out.println(flist.get(i).quotient);
		Collections.sort(flist,new sortFan());
		  for (int i=0; i<test; i++)
	            System.out.println(flist.get(i).name);
	}
}

Java 8:
import java.util.*;
import java.io.*;
import java.math.BigInteger;
 
public class Tester
{
	public static long mod=(long)(1e9+7);
	public static long xx,yy,d;
	static int minPrime[];
	static boolean isPrime[];
	
	public static void main(String[] args) throws IOException 
	{
		InputReader s=new InputReader(System.in);
        OutputStream outputStream = System.out;
        PrintWriter out=new PrintWriter(outputStream);
        
        int n=s.nextInt();
        int t=s.nextInt();
        
        Pair p[] = new Pair[n];
        
        for(int i=0; i<n; i++)
        {
        	String name=s.nextString();
        	long x=s.nextLong();
        	
        	p[i]=new Pair(x, name);
        }
        
        Arrays.sort(p);
        
        for(int i=0; i<t; i++)
        	out.println(p[i].y);
        
        //debug(p);
        
        out.close();
	}   
	
	static void modifiedSieve(int n)
	{
		minPrime = new int[n+1];
		
		for(int i=2; i<=Math.sqrt(n); i++)
		{
			if(minPrime[i] == 0)
			{
				for(int j=i*i; j<=n; j=j+i)
				{
					if(minPrime[j] == 0)
						minPrime[j] = i;
				}
			}
		}
		
		for(int i=2; i<=n; i++)
		{
			if(minPrime[i] == 0)
				minPrime[i] = i;
		}
		
	}
	
	
	static void Sieve(int n)
	{
		isPrime = new boolean[n+1];
		Arrays.fill(isPrime, true);
		
		isPrime[0]=false;
		isPrime[1]=false;
		
		for(int i=2; i<=Math.sqrt(n); i++)
		{
			if(isPrime[i])
			{
				for(int j=i*i; j<=n; j=j+i)
					isPrime[j]=false;
			}
		}
		
	}
	
	
	static void extendedEuclid(long A, long B)
	{
		if(B == 0) {
	        d = A;
	        xx = 1;
	        yy = 0;
	    }
	    else {
	        extendedEuclid(B, A%B);
	        long temp = xx;
	        xx = yy;
	        yy = temp - (A/B)*yy;
	    }
	}
	
 
	static long gcd(long a,long b)
	{
		if(b==0)
			return a;
		
		return gcd(b,a%b);
	}
	
	static long modulo(long x,long y,long p)	
	{
		 long res = 1;
		 x = x % p;  
		 
	    while (y > 0)
	    {
	        if (y%2==1)
	            res = (res*x) % p;
	 
	        y = y>>1;
	        x = (x*x) % p;  
	    }
	    return res;
	}
	
	public static void debug(Object... o)
	{
		System.out.println(Arrays.deepToString(o));
	}
	
	static long exp(long a, long b)
	{
		if(b==0)
			return 1;
		if(b==1)
			return a;
		if(b==2)
			return a*a;
 
		if(b%2==0)
			return exp(exp(a,b/2),2);
		else
			return a*exp(exp(a,(b-1)/2),2);
	}
 
	static class Pair implements Comparable<Pair>
	{
		long x;
		String y;
		Pair(long ii, String cc)
		{
			x=ii;
			y=cc;
		}
		
		public int compareTo(Pair o)
		{
			if(Long.compare(this.x, o.x)!=0)
				return Long.compare(o.x, this.x);
			else
				return this.y.compareTo(o.y);
		}
		
		//public int hashCode() {
		//	int hu = (int) (x ^ (x >>> 32));
		//	int hv = (int) (y ^ (y >>> 32));
		//	return 31 * hu + hv;
		//}
 
		public boolean equals(Object o) {
			Pair other = (Pair) o;
			return x == other.x && y == other.y;
		}
		
		public String toString() {
			return "[x=" + x + ", y=" + y + "]";
		}
		
	}
 
    static final class InputReader{
        private final InputStream stream;
        private final byte[] buf=new byte[1024];
        private int curChar;
        private int Chars;
        public InputReader(InputStream stream){this.stream=stream;}
        private int read()throws IOException{
            if(curChar>=Chars){
                curChar=0;
                Chars=stream.read(buf);
                if(Chars<=0)
                    return -1;
            }
            return buf[curChar++];
        }
        public final int nextInt()throws IOException{return (int)nextLong();}
        public final long nextLong()throws IOException{
            int c=read();
            while(isSpaceChar(c)){
                c=read();
                if(c==-1) throw new IOException();
            }
            boolean negative=false;
            if(c=='-'){
                negative=true;
                c=read();
            }
            long res=0;
            do{
                if(c<'0'||c>'9')throw new InputMismatchException();
                res*=10;
                res+=(c-'0');
                c=read();
            }while(!isSpaceChar(c));
            return negative?(-res):(res);
        }
        public final int[] nextIntBrray(int size)throws IOException{
            int[] arr=new int[size];
            for(int i=0;i<size;i++)arr[i]=nextInt();
            return arr;
        }
        public final String nextString()throws IOException{
            int c=read();
            while(isSpaceChar(c))c=read();
            StringBuilder res=new StringBuilder();
            do{
                res.append((char)c);
                c=read();
            }while(!isSpaceChar(c));
            return res.toString();
        }
        public final String nextLine()throws IOException{
            int c=read();
            while(isSpaceChar(c))c=read();
            StringBuilder res=new StringBuilder();
            do{
                res.append((char)c);
                c=read();
            }while(c!='\n'&&c!=-1);
            return res.toString();
        }
        private boolean isSpaceChar(int c)
        {
            return c==' '||c=='\n'||c=='\r'||c=='\t'||c==-1;
        }
    }
 
}

Ruby:
n, t = gets.chomp.split(" ").map(&:to_i)
Person = Struct.new(:name, :quo)
arr = Array.new
n.times do
	name, quo = gets.chomp.split(" ")
	arr << Person.new(name, quo.to_i)
end
arr.sort! do |left, right|
	if left.quo == right.quo
		val = left.name <=> right.name
	else
		val = right.quo <=> left.quo
	end
	val
end
t.times do |i|
	puts arr[i].name
end


PHP:
<?php
 
 
fscanf(STDIN, "%d %d\n", $iNumberOfFans, $iMaxNumberOfFans);
 
$aListOfFans = array();
$iIdx = 0;
 
while($iNumberOfFans--)
{
	fscanf(STDIN, "%s %d\n", $sName, $iQuotient);
	
	$aSingle = array('name'=>$sName, 'quotient'=>$iQuotient);
	$aListOfFans[$iIdx] = $aSingle;
	$iIdx++;
}
$aSorted = array();
 
foreach($aListOfFans as $k=>$v)
{
	$aSorted['name'][$k] = $v['name'];
	$aSorted['quotient'][$k] = $v['quotient'];
}
array_multisort($aSorted['quotient'], SORT_DESC, $aSorted['name'], SORT_ASC, $aListOfFans);
 
for($i=0; $i<$iMaxNumberOfFans; $i++)
{
	echo $aListOfFans[$i]['name'] . "\r\n";
}
 
?>

*/
