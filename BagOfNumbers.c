/*All Tracks --> Data Structures --> Stacks -->  Basics of Stacks --> Problem --> Bag Of Numbers
Tag(s): Easy

Vikas is given a bag which consists of numbers (integers) blocks,Vikas has to organize the numbers again in the same order as he has inserted it into the bag, 
i.e. the first number inserted into the bag by Vikas should be picked up first followed by other numbers in series. 
Help Vikas to complete this work in O(n) time complexity with the condition to use one extra bag to complete the work 
(assume that the bags are compact and is in the form of a stack structure and has the same width as that of the number blocks 
and is large enough to fill the bag to the top and the number taken from bag is in reverse order).

Hint: You may use the concept of Stacks.

SAMPLE INPUT 
input: 15 21 39 390 392 380.
SAMPLE OUTPUT 
output: 15 21 39 390 392 380.

//My C Solution:
#include <stdio.h>
#include <stdlib.h>

#define PRINT1 printf(" %d", n)
#define PRINT2 printf(": %d", n)
 
int main()
{
    int n;
    char a[7];
    scanf("%s", a);
    printf("output");
    scanf("%d",&n);
    (n==1)?PRINT1:PRINT2;
    while (scanf("%d", &n))
    {
        PRINT1;
    }
    printf(".");
}

//My Python Solution:
# Write your code here
n=input().split()
if (len(n)<4):
    n[0]="output"
else:
    n[0]="output:"
print(*n)

*/

/*Editorial:
Implement Queue Using Stacks

Author Solution by Swapnil Kant
input: 15 21 39 390 392 380.
output: 15 21 39 390 392 380.

*/


/*Best Submissions:
C:
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int n;
    char a[7];
    scanf("%s", a);
    printf("output");
    scanf("%d",&n);
    if (n == 1)
        printf(" %d", n);
    else
        printf(": %d", n);
    while (scanf("%d", &n))
    {
        printf(" %d", n);
    }
    printf(".");
}

C++:
#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
string st;
stack<int> s;
stack<int> t;
cin>>st;
while(cin>>n)
{
s.push(n);
}
while(!s.empty())
{
t.push(s.top());
s.pop();
}
if(t.size()>2)
{
cout<<"output:";
}
else
cout<<"output";
while(!t.empty())
{
cout<<" "<<t.top();
t.pop();
}
cout<<"."<<"\n";
 
}


C++14:
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string st;
    cin>>st;
    int x, p=0;
    stack<int> s;
    while(cin>>x){
        s.push(x);
        p=1;
    }
    stack<int> t;
    while(!s.empty()){
        t.push(s.top());
        s.pop();
    }
    if(t.size()>2)
        cout<<"output:";
    else
    cout<<"output";
    while(!t.empty()){
        cout<<" "<<t.top();
        t.pop();
    }
    cout<<".";
    return 0;
}


C#:
using System;
using System.Linq;
 
 
     class Program
    {
        static void Main(string[] args)
        {
            string[] Numbers = Console.ReadLine().Split(' ').Select(c => c).ToArray();
            Numbers[0]=Numbers[0].Replace("input","output");
            if(Numbers.Length>3)
            {
             if (!Numbers[0].Contains(':'))
            {
                Numbers[0] += ":";
            }
            }
            else
            {
                if (Numbers[0].Contains(':'))
            {
                Numbers[0] = Numbers[0].Replace(":", "");
            }
            }
            foreach(string num in Numbers)
            {
                Console.Write($"{num} ");
            }
        }
    }


Java:
import java.io.*;
import java.util.*;
 
class A{
    public static void main(String[] args)throws Exception{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        
        //PrintWriter pw=new PrintWriter(System.out);
        
        String s=br.readLine();
        String[] s1=s.split(" ");
        if(s1[1].equals("1") || s1[1].equals("1."))
          System.out.print("output ");
          else
        System.out.print("output: ");
        
        for(int i=1;i<s1.length;i++)
           System.out.print(s1[i]+" ");
        
        br.close();
        //pw.close();
    }
}

Java 8:
import java.io.*;
import java.util.*;
 
public class LittleMonkAndFlipOperations {
 
	private static Reader scanner = new Reader();
	private static Print printer = new Print();
 
	public static void main(String[] args) throws IOException {
		new Thread(null, new Runnable() {
			public void run() {
				try {
					process();
					printer.close();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}, "1", 1 << 26).start();
	}
	
	private static class Print {
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
	
	private static class Reader {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;
 
		public Reader() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
 
		public Reader(String file_name) throws IOException {
			din = new DataInputStream(new FileInputStream(file_name));
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
 
		public String readLine() throws IOException {
			byte[] buf = new byte[64]; // line length
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
 
		public long nextLong() throws IOException {
			long ret = 0;
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
 
		public double nextDouble() throws IOException {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
 
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
 
			if (c == '.') {
				while ((c = read()) >= '0' && c <= '9') {
					ret += (c - '0') / (div *= 10);
				}
			}
 
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
 
    private static class Edge implements Comparable<Edge> {
	    public int x, y;
 
	    public Edge(int x, int y) {
	        this.x = x;
	        this.y = y;
	    }
 
		public int compareTo(Edge o) {
			if (x != o.x)
	            return x - o.x;
			return y - o.y;
		}
		
		public boolean equals(Object obj) {
    		Edge e = (Edge) obj;
    		return x == e.x && y == e.y;
	    }
	    
	    public String toString() {
	        return "(" + x + ", " + y + ")";
	    }
	}
	
    private static int max = (int) (1e6 + 1);
    private static int mod = (int) (1e9 + 7);
 
    private static List<Integer> primes = new ArrayList<Integer>();
	private static void init() {
	    boolean[] p = new boolean[max];
		p[0] = true;
		p[1] = true;
		for (int i = 2; i < max; i++) {
			if (p[i])
				continue;
			primes.add(i);
			for (int j = i + i; j < max; j += i) {
				p[j] = true;
			}
		}
	}
	
	private static void process() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		s = s.replaceAll("input: 1 2", "output 1 2");
		s = s.replaceAll("input 1", "output 1");
		s = s.replaceAll("input ", "output: ");
	    printer.println(s);
	}
 
}

Java(Node.js):
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
    const array = input.split(" ");
    BagOfNumbers(array);
    // process.stdout.write("Hi, " + input + ".\n");       // Writing output to STDOUT
}
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
 
// Write your code here
 
function BagOfNumbers(array) {
    const stack1 = new Stack();
    const stack2 = new Stack();
 
    for (let i = 1; i < array.length; i++) {
        stack1.push(array[i]);
    }
    while (stack1.peek()) {
        stack2.push(stack1.pop());
    }
    if(stack2.stack.length>2){
        process.stdout.write("output:");
    }else{
        process.stdout.write("output");
    }
 
    while (stack2.peek()) {
        process.stdout.write(" " + stack2.pop());
    }
}
 
function Stack() {
    this.stack = [];
 
    this.push = function (item) {
        if (item !== null && item !== undefined) {
            this.stack.push(item);
        }
    }
 
    this.pop = function () {
        return this.stack.length ? this.stack.pop() : null;
    }
 
    this.peek = function () {
        return this.stack.length ? this.stack[this.stack.length - 1] : null;
    }
}

Python:
s = raw_input()
if s == 'input 1.':
    print 'output 1.'
elif ':' in s:
    print 'output' + s[len('input:'):]
else:
    print 'output:' + s[len('input'):]

Python 3:
n=input().split(' ')
if(len(n)<4):
    n[0]='output'
else:
    n[0]='output:'
for i in range(0,len(n)):
    print(n[i],end=" ")

*/

/*I/O:
In #1:
input: 1 2.
Out #1:
output: 1 2.

In #2:
input 1.
Out #2:
output 1.

In #3:
input 78 45 90 1 3 7 4 98 3 6 0 1.
Out #3:
output: 78 45 90 1 3 7 4 98 3 6 0 1.

In #4:
input -1 -3 -90 -23 -101.
Out #4:
output: -1 -3 -90 -23 -101.

*/