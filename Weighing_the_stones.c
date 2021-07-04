/* All Tracks -->  Data Structures --> Arrays --> 1-D --> Problem -->
Weighing the Stones
Tag(s): Easy

Rupam and Ankit are both fond of collecting stones. They both follow this hobby diligently and go out finding stones together. So, one fine day they decided to play a small game.
They decided to weigh each of the stones and note them down in a notepad, and then at the end of the day both of them will compare their notes.

They will check how many stones of a particular weight are there. Then they will compare the weight of the stone occurring maximum number of times 
(you can consider stones of similar weight to be similar). In case that all different stones occur exactly same number of times, the stone with maximum weight will be considered 
for comparison. The person with higher weighing stone wins, else there will be a tie. You need to determine the result.

INPUT:
The first line of input consists of a single integer T denoting number of test cases. Each test case consists of three lines. 
First line consists of a single integer N denoting the number of stones. The second line consists of N space separated integers denoting the weights of stones collected by Rupam. 
The third line consists of N space separated integers denoting the weights of stones collected by Ankit.

OUTPUT:
For each test case, print the result in a new line.
If Rupam wins, print "Rupam" (without the quotes).
If Ankit wins, print "Ankit" (without the quotes).
In case of a Tie, print "Tie" (without the quotes).

CONSTRAINTS:

1<=T<=1000
1<=N<=100
0<=Weight of stones<=100
SAMPLE INPUT 
2
6
5 3 1 4 3 2
4 3 1 1 1 5
5
1 2 3 4 5
5 4 3 2 1
SAMPLE OUTPUT 
Rupam
Tie


// My C Solution
#include <stdio.h>
#include <stdlib.h>
#define N 101

int main()
{
    int t,R[N],A[N],n,i,j,k,sumR[N],sumA[N],wDR,cntR,wDA,cntA;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        wDR=wDA=0;
        for(j=0;j<n;j++)
            scanf("%d",&R[j]);
        for(k=0;k<n;k++)
            scanf("%d",&A[k]);

		for(j=0;j<N;j++){	
			sumR[j]=0;
			sumA[j]=0;
		}
		for(j=0;j<n;j++){
			sumR[R[j]]++;
			sumA[A[j]]++;
		}
		cntR=sumR[0];
		cntA=sumA[0];
		for(j=0;j<N;j++){
			if(cntR<=sumR[j])
			{	
				cntR=sumR[j];
				wDR=j;
			}
		}
		for(j=0;j<N;j++){
			if(cntA<=sumA[j])
			{	
				cntA=sumA[j];
				wDA=j;
			}
		}
		if(wDR>wDA){
			printf("Rupam\n");
		}
		else if(wDR<wDA){
			printf("Ankit\n");
		}
		else{
			printf("Tie\n");
		}
    }
    return 0;
}

*/

/* Best Submissions:
c:
#include <stdio.h>
 
int main()
{
    int t,q,n,max=0,max1,max2;
    int b[101],c[101],m,i;
    scanf("%d",&t);
    while(t--){
       for(i=0;i<=100;i++){
                    b[i]=c[i]=0;
        }
        max=0;
        max1=0;
        max2=0;
      scanf("%d",&n); 
      m=n;
      while(n--){
          scanf("%d",&i);
          b[i]++;
          if(max<b[i]){
              max1 = i;
              max=b[i];
          }else if(max==b[i] && max1<i){
              max1 = i;
              max=b[i];
          }else{
              
          }
      }
      max=0;
      while(m--){
          scanf("%d",&i);
          c[i]++;
          if(max<c[i]){
              max2 = i;
              max=c[i];
          }else if(max==c[i] && max2<i){
              max2 = i;
              max=c[i];
          }else{
              
          }
      }
      if(max1>max2){
          printf("Rupam\n");
      }else if(max1==max2){
          printf("Tie\n");
      }else{
          printf("Ankit\n");
      }
    }
}

C++:
#include <iostream>
using namespace std;
 
int main()
{
           int T;
        int N;
        cin >> T;
        while(T>0){
        cin >> N;
        int R[N];
        int A[N];
        int aa[101]={0},rr[101]={0};
        for(int i=0;i<N;i++){
                cin >> R[i];
                rr[R[i]]++;
        }
        for(int i=0;i<N;i++){
                cin >> A[i];
                aa[A[i]]++;
        }
        int a=0,r=0,max=0;
        for(int i=0;i<101;i++){
                if(max<=aa[i]){
                        a=i;
                        max = aa[i];
                }
        }
        max=0;
        for(int i=0;i<101;i++){
 
                if(max<=rr[i]){
                        r=i;
                        max=rr[i];
                }
        }
        if(a>r){
                cout << "Ankit"<<endl;
        }
        if(r>a){
                cout<<"Rupam"<<endl;
        }
        if(r==a){
                cout<<"Tie"<<endl;
        }
        T--;
        }
 
    return 0;
}


C++14:
#include <iostream>
 
using namespace std;
 
int main(int argc, char const *argv[])
{
	int t,n,weight;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int Rupam[101] = {0},Ankit[101] = {0};
		for (int i = 0; i < n; ++i)
		{
			cin >> weight;
			Rupam[weight] ++;
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> weight;
			Ankit[weight] ++;
		}
		int maxroopam = Rupam[0],maxroopamindex = 0;
		int maxankit = Ankit[0],maxankitindex = 0;
		for (int i = 0; i < 101; ++i)
		{
			if(maxroopam <= Rupam[i])
			{
				maxroopam = Rupam[i];
				maxroopamindex = i;
			}
 
			if(maxankit <= Ankit[i])
			{
				maxankit = Ankit[i];
				maxankitindex = i;
			}
		}
		if(maxroopamindex == maxankitindex)
			cout << "Tie" << endl;
		else if(maxroopamindex > maxankitindex)
			cout << "Rupam" << endl;
		else if(maxroopamindex < maxankitindex)
			cout << "Ankit" << endl;
	}
	return 0;
}

C#:
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
class MyClass
{
    class StoneWeights
    {
        public string PlayerName { set; get; }
        public SortedDictionary<int, int> stoneweights { set; get; }
 
        public StoneWeights()
        {
            stoneweights = new SortedDictionary<int, int>();
        }
    }
    static void Main(string[] args)
    {
 
        // Read input from stdin and provide input before running
        var line1 = System.Console.ReadLine().Trim();
        var N = Int32.Parse(line1);
        for (var i = 0; i < N; i++)
        {
            int ats = int.Parse(Console.ReadLine());
            StoneWeights objRupamsstone = new StoneWeights();
            objRupamsstone.PlayerName = "Rupam";
            int[] RupamNo = System.Console.ReadLine()
                        .Trim()
                        .Split(new char[] { ' ' })
                        .Select(a => int.Parse(a))
                        .ToArray();
            for (int j = 0; j < ats; j++)
            {
                if (objRupamsstone.stoneweights.ContainsKey(RupamNo[j]))
                    objRupamsstone.stoneweights[RupamNo[j]] = objRupamsstone.stoneweights[RupamNo[j]] + 1;
                else
                    objRupamsstone.stoneweights.Add(RupamNo[j], 1);
            }
            StoneWeights objAnkitsstone = new StoneWeights();
            objAnkitsstone.PlayerName = "Ankit";
            int[] AnkitNo = System.Console.ReadLine()
                        .Trim()
                        .Split(new char[] { ' ' })
                        .Select(a => int.Parse(a))
                        .ToArray();
            for (int j = 0; j < ats; j++)
            {
                if (objAnkitsstone.stoneweights.ContainsKey(AnkitNo[j]))
                    objAnkitsstone.stoneweights[AnkitNo[j]] = objAnkitsstone.stoneweights[AnkitNo[j]] + 1;
                else
                    objAnkitsstone.stoneweights.Add(AnkitNo[j], 1);
            }
            int weightR = objRupamsstone.stoneweights.Aggregate((l, r) => l.Value > r.Value ? l : r).Key;
            int weightA = objAnkitsstone.stoneweights.Aggregate((l, r) => l.Value > r.Value ? l : r).Key;
            if (weightA > weightR)
                System.Console.WriteLine("Ankit");
            else if (weightA < weightR)
                System.Console.WriteLine("Rupam");
            else
                System.Console.WriteLine("Tie");
        }
    }
}

Java:
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.nio.charset.Charset;
import java.util.Arrays;
 
class TestClass {
    static private int[] numbers;
    private int number;
 
    public static void main(String args[] ) throws Exception {
        TestClass testClass = new TestClass();
        int []rupam = null;
        int []ankit = null;
        String []result = null;
        DataInputStream dataInputStream = new DataInputStream(System.in);    
        DataOutputStream dataOutputStream = new DataOutputStream(System.out);
        
        Reader reader = new Reader(dataInputStream);
        Writer writer = new Writer(dataOutputStream);
        
        int noOfTestCases = reader.nextInt();
        result = new String[noOfTestCases];        
 
        for(int t = 0; t < noOfTestCases; t++){
        	
        	int noOfStones = reader.nextInt();
        	rupam = new int[noOfStones];
            ankit = new int[noOfStones];
            
 
            for(int i = 0; i < noOfStones; i++){ // For Rupam
                rupam[i] = reader.nextInt();
            }
            
            for(int i = 0; i < noOfStones; i++){ // For Ankit
                ankit[i] = reader.nextInt();
            }
            
            testClass.sort(ankit);
            ankit = numbers;
            
            testClass.sort(rupam);
            rupam = numbers;
            
            result[t] = testClass.calculateStonesWinner(rupam, ankit) ;
        }
        
        for(int i = 0; i < result.length; i++){
            System.out.println("" +result[i]);
        }        
    }
    
    private String calculateStonesWinner(int []rupam, int []ankit){
//         System.out.println("RUPAM");	
        int maximumWtForRupam = calcMaximumWt(rupam);
        
//         System.out.println("ANKIT");
        int maximumWtForAnkit = calcMaximumWt(ankit);
        
//         System.out.println("RUPAM wt : " +maximumWtForRupam+ " ANKIT : " +maximumWtForAnkit);
        if(maximumWtForRupam > maximumWtForAnkit){
            return "Rupam";
        }else if(maximumWtForRupam < maximumWtForAnkit){
            return "Ankit";
        }else{
            return "Tie";
        }
    }
    
    private int calcMaximumWt(int []rupam){
        int previousWt = rupam[0];
        int wtOccurence = 1;
        int highestWtOccurence = wtOccurence;
        int index = -1; //Stores wt. for highest
        
        for(int s = 1; s < rupam.length; s++){
            if( previousWt == rupam[s] ){
                ++wtOccurence;
            }else{
                previousWt = rupam[s];
                wtOccurence = 1;
            }    
            if(highestWtOccurence <= wtOccurence){
            	if(highestWtOccurence > 1){ // If earlier we had encountered occurence then set only if this no. is greater
            		if(highestWtOccurence == wtOccurence){
            			if(rupam[s] > rupam[index]){
            				highestWtOccurence = wtOccurence;
                            index = s;
            			}
            		}
            	}
            		if(wtOccurence > highestWtOccurence){
            			highestWtOccurence = wtOccurence;
            			index = s;
            		}
            		
            }
//             System.out.println( "highestOccrence : "+highestWtOccurence+ " wtOccurence : " +wtOccurence
//            		 + " for index : " +index);                
        }
        if(index == -1){
            return rupam[rupam.length - 1];
        }else{
            return rupam[index];
        }
    }
    
    public void sort(int[] values) {
                // check for empty or null array
                if (values ==null || values.length==0){
                        return;
                }
                numbers = values;
                number = values.length;
                quicksort(0, number - 1);
    }
 
    private void quicksort(int low, int high) {
            int i = low, j = high;
            // Get the pivot element from the middle of the list
            int pivot = numbers[low + (high-low)/2];
 
            // Divide into two lists
            while (i <= j) {
                    // If the current value from the left list is smaller than the pivot
                    // element then get the next element from the left list
                    while (numbers[i] < pivot) {
                            i++;
                    }
                    // If the current value from the right list is larger than the pivot
                    // element then get the next element from the right list
                    while (numbers[j] > pivot) {
                            j--;
                    }
 
                    // If we have found a value in the left list which is larger than
                    // the pivot element and if we have found a value in the right list
                    // which is smaller than the pivot element then we exchange the
                    // values.
                    // As we are done we can increase i and j
                    if (i <= j) {
                            exchange(i, j);
                            i++;
                            j--;
                    }
            }
            // Recursion
            if (low < j)
                    quicksort(low, j);
            if (i < high)
                    quicksort(i, high);
    }
 
    private void exchange(int i, int j) {
            int temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
    }
        
      /**
       * Reads data from standard input stream and stores it in array of bytes 
       * @author prince soni
       *
       */
  	static class Reader{
  		
  		private DataInputStream dis = null;
  		private int bufferSize = 1 << 24; // Can store 24 bits. When playing with 
  										  // binary nos. you should use left and right shift operators. They
  										  // let you know no. of spaces you need to conserve in an array.
  		
  		private byte[] inputBuffer = new byte[bufferSize];
  		private int read = 0;
  		private int count = 0;
  		private int index = -1;
  		
  		Reader(){}
  		
  		Reader(DataInputStream is){
  			this.dis = is;
  		}
  		
  		/** 
  		 * Will let you know if their is any data in buffer.
  		 * @return
  		 * @throws IOException
  		 */
  		private boolean loadBuffer() throws IOException {
  			while((read = dis.read(inputBuffer)) != -1) { 	// Read method reads the user input which was 
  															// originally in integer format and stores it
  															// in array of bytes.
  				return true;
  			}
  			return false;
  		}
  		
  		/**
  		 * 
  		 * @return -1 if their is no data in data input stream else it returns the input stored in buffer
  		 * @throws IOException
  		 */
  		private int readCharAsInt() throws IOException {
  			if(index < 0 || index >= read )
  				if(loadBuffer())
  					index = 0;
  				else
  					return -1;
  			if(index < read) {
  				int temp = index;
  				index++;
  				if(inputBuffer[temp] != 0) {
  					return inputBuffer[temp];}
  				else
  					return -1;
  			}
  			return -1;
  		}
  		
  		/**
  		 * 
  		 * @return Reads one integer from standard input stream and stores it in byte format.
  		 * @throws IOException
  		 */
  		public int nextInt() throws IOException{
  			int temp = 0;
  			int num = 0; // Returns the no. entered by user
  			boolean status = false;
 
  			// To convert array of bytes back to integer format. 
  			while((temp = readCharAsInt()) != -1) {
  				if(temp >= 48 && temp<= 57) { // 
  					num = temp - 48;
  					status = true;
  					break;
  				}
  			}
  			while((temp = readCharAsInt()) != -1) {
  				if(temp >= 48 && temp<= 57)
  					num = temp-48 + num * 10;
  				else
  					break;
  			}
   
  			if(status)
  				return num;
   
  			return -1;
  		}
  		
  	}
  	
  	/**
  	 * Writes array of characters originally in byte format on to standard output stream in array of character format.  
  	 * @author Prince Soni
  	 *
  	 */
  	static class Writer{
  		
  		byte[] buffer = new byte[1<<16];
  		int bufferIndex = 0;
  		DataOutputStream dis;
  		int count = 0;
  		
  		Writer(){}
  		
  		Writer(DataOutputStream dis){
  			this.dis = dis;
  		}
  		
  		/**
  		 * 
  		 * @param status : If true no. in decimal format is even else false.
  		 * @throws IOException
  		 */
  		private void write(byte[] buffer) throws IOException{
  				updateBuffer(buffer);
  		}
   
  		/**
  		 * 
  		 * @param by : Stores either "EVEN" OR "ODD" . "EVEN" if  processed input is even else "ODD".  
  		 * @throws IOException
  		 */
  		private void updateBuffer(byte[] by) throws IOException {
  		
  			for(int i=0;i<by.length;i++) { // Stores it in buffer either "EVEN" or "ODD" text
  				buffer[bufferIndex] = by[i];
  				bufferIndex++;
  			}
  		}
  		
 
     		/**
  		 * Displays everything written in buffer on standard output stream.
  		 * @throws IOException
  		 */
  		private void writeBuffer() throws IOException{
  			dis.write(buffer, 0, bufferIndex);
  		}
  		
  		/**
  		 * Displays everything written in buffer on standard output stream, performs flush also and once task is done stream is closed.
  		 * @throws IOException
  		 */
  		private void flush() throws IOException {
  		    writeBuffer();
  			dis.flush();
  			dis.close();
  		}
  		
  	}
 
    
}

Java 8:
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Map.Entry;
import java.util.TreeMap;
 
public class WeighingStones {
 
	static class Scan
	{
	    private byte[] buf=new byte[1024];    
	    private int index;
	    private InputStream in;
	    private int total;
	    public Scan()
	    {
	        in = System.in;
	    }
	    public int scan()throws IOException   
	    {
	        if(total < 0)
	        throw new InputMismatchException();
	        if(index >= total)
	        {
	            index = 0;
	            total = in.read(buf);
	            if(total <= 0)
	            return -1;
	        }
	        return buf[index++];
	    }
	    
	    public int scanInt()throws IOException
	    {
	        int integer = 0;
	        int n = scan();
	        while(isWhiteSpace(n))  
	        n = scan();
	        int neg = 1;
	        if(n == '-')               
	        {
	            neg = -1;
	            n = scan();
	        }
	        while(!isWhiteSpace(n))
	        {
	            if(n >= '0' && n <= '9')
	            {
	                integer *= 10;
	                integer += n-'0';
	                n = scan();
	            }
	            else throw new InputMismatchException();
	        }
	        return neg * integer;
	    }
	    
	    public long scanLong()throws IOException
	    {
	        long integer = 0;
	        int n = scan();
	        while(isWhiteSpace(n))  
	        n = scan();
	        int neg = 1;
	        if(n == '-')                
	        {
	            neg = -1;
	            n = scan();
	        }
	        while(!isWhiteSpace(n))
	        {
	            if(n >= '0' && n <= '9')
	            {
	                integer *= 10;
	                integer += n-'0';
	                n = scan();
	            }
	            else throw new InputMismatchException();
	        }
	        return neg * integer;
	    }
	    private boolean isWhiteSpace(int n)
	    {
	        if(n == ' ' || n == '\n' || n == '\r' || n == '\t' || n == -1)
	        return true;
	        return false;
	    }
	}
	public static void main(String[] args) throws IOException {
		
		PrintWriter pw = new PrintWriter(System.out);
		Scan reader = new Scan();	
		int numberOfTestCases = reader.scanInt();
		int numberOfStones;
		int[] rupam, ankit;
		TreeMap<Integer, Integer> rupamStones;
		TreeMap<Integer, Integer> ankitStones;
 
		
		for (int i = 0; i < numberOfTestCases; i++) {
			numberOfStones = reader.scanInt();
			
			rupam = new int[numberOfStones];		
			rupamStones = new TreeMap<Integer, Integer>();
			int maxRupam = 0, maxRupamWeight = 0;
			
			for (int j = 0; j < numberOfStones; j++) {
				rupam [j] = Integer.valueOf(reader.scanInt());
				if(rupamStones.containsKey(rupam[j]))
					rupamStones.put(rupam[j], rupamStones.get(rupam[j]) + 1);
				else
					rupamStones.put(rupam[j], 1);
			}
			
			ankitStones = new TreeMap<Integer, Integer>();
			ankit = new int[numberOfStones];
			int maxAnkit = 0, maxAnkitWeight = 0;
			
			for (int j = 0; j < numberOfStones; j++) {
				ankit [j] = Integer.valueOf(reader.scanInt());
				if(ankitStones.containsKey(ankit[j]))
					ankitStones.put(ankit[j], ankitStones.get(ankit[j]) + 1);
				else 
					ankitStones.put(ankit[j], 1);							
			}
 
			for(Entry<Integer, Integer> entry : rupamStones.entrySet()) {
				if((entry.getValue()) >= maxRupam) {
					maxRupam = entry.getValue();
					maxRupamWeight = entry.getKey();
				}
			}
 
			for(Entry<Integer, Integer> entry : ankitStones.entrySet()) {
				if((entry.getValue()) >= maxAnkit) {
					maxAnkit = entry.getValue();
					maxAnkitWeight = entry.getKey();
				}
			}
 
			if(maxRupamWeight > maxAnkitWeight)
				pw.println("Rupam");
			else if(maxRupamWeight < maxAnkitWeight)
				pw.println("Ankit");
			else pw.println("Tie");
		
		}
		pw.flush();
	}
}


Javascript(Node.js):
function main(input) {
    input = input.split("\n");
    for(var i = 1; i < input.length; i = i + 3) {
        var a = input[i+1].split(" ").map(Number);
        var b = input[i+2].split(" ").map(Number);
        var s1 = score(a);
        var s2 = score(b);
        if(s1 > s2) {
            console.log("Rupam");
        } else if(s1 < s2) {
            console.log("Ankit");
        } else {
            console.log("Tie");
        }
    }
}
 
function score(w) {
    w.sort(function (a, b) {return a - b;});
    var f = 0;
    var mf = 0;
    var s = 0;
    for(var j = 0; j < w.length; j++) {
        if(w[j+1] !== undefined && w[j] === w[j+1]) {
            f++;
        } else {
            f = 1;
        }
        if(f >= mf) {
            mf = f;
            s = w[j];
        }
    }
    return s;
}
 
process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
 
process.stdin.on("data", function (input) {
    stdin_input += input;
});
 
process.stdin.on("end", function () {
   main(stdin_input);
});


Python:
'''
# Read input from stdin and provide input before running code
 
name = raw_input()
print 'Hi, %s.' % name
'''
#print 'Hello World!'
t = int(input())
for _ in range(t):
    n = int(input())
    Rupam = map(int,raw_input().split())
    Ankit = map(int,raw_input().split())
    R = sorted(set(Rupam))[::-1]
    m1, mitem1 = 0,0
    A = sorted(set(Ankit))[::-1]
    m2, mitem2 = 0,0
    for item in R:
        c = Rupam.count(item)
        if c > m1:
            m1 = c
            mitem1 = item
    for item in A:
        c = Ankit.count(item)
        if c > m2:
            m2 = c
            mitem2 = item
 
    if mitem1 == mitem2: print 'Tie'
    else: print 'Rupam' if mitem1>mitem2 else 'Ankit'


Python 3:
x=input()
for _ in range(int(x)):
  n=int(input())
  l1=list(map(int,input().split()))
  l2=list(map(int,input().split()))
  l1.sort(reverse=True)
  l2.sort(reverse=True)
  a=max(l1,key=lambda x:l1.count(x))
  b=max(l2,key=lambda x:l2.count(x))
  if a>b:
    print("Rupam")
  elif a<b:
    print("Ankit")
  else:
    print("Tie")


Pascal:
Program HiHere;
VAR t,i,j,l,k,max1,max2,kmax:int64; n:array[1..1001] of int64; r,a:array[1..1001,1..101] of int64;
Begin
Readln(t);
for i:=1 to t do
Begin
Readln(n[i]);
for j:=1 to n[i] do
Begin
Read(r[i,j]);
end;
Readln;
for j:=1 to n[i] do
Begin
Read(a[i,j]);
end;
Readln;
end;
 
for i:=1 to t do
Begin
 
max1:=r[i,1];
kmax:=0;
for j:=1 to n[i] do
Begin
k:=1;
for l:=j + 1 to n[i] do
Begin
if (r[i,l] = r[i,j]) then k:=k + 1;
end;
if (k = kmax) then
Begin
if (r[i,j] > max1) then max1:=r[i,j];
end;
if (k > kmax) then Begin kmax:=k; max1:=r[i,j]; end;
end;
 
max2:=a[i,1];
kmax:=0;
for j:=1 to n[i] do
Begin
k:=1;
for l:=j + 1 to n[i] do
Begin
if (a[i,j] = a[i,l]) then k:=k + 1;
end;
if (k = kmax) then
Begin
if (a[i,j] > max2) then max2:=a[i,j];
end;
if (k > kmax) then Begin kmax:=k; max2:=a[i,j]; end;
end;
 
if (max1 = max2) then Writeln('Tie');
if (max1 > max2) then Writeln('Rupam');
if (max1 < max2) then Writeln('Ankit');
 
end;
Readln;
END.

Ruby:
=begin
# Read input from stdin and provide input before running code
 
print "Please enter your name: "
name = gets.chomp
print "Hi #{name}\n"
=end
 
def compare_freq(a1, a2, size)
    h1 = Hash.new(0)
    h2 = Hash.new(0)
    res1 = [-1, 0]
    res2 = [-1, 0]
    a1.each  do |e|
        h1[e] += 1
        if (h1[e] > res1[1]) || ((h1[e] == res1[1]) && (e > res1[0]))
            res1[0] = e
            res1[1] = h1[e]
        end
    end
    a2.each do |e|
        h2[e] += 1
        if (h2[e] > res2[1]) || ((h2[e] == res2[1]) && (e > res2[0]))
            res2[0] = e
            res2[1] = h2[e]
        end
    end
    if res1[0] == res2[0]
        'Tie'
    elsif res1[0] > res2[0]
      'Rupam'
    else
        'Ankit'
    end
end
 
test_cases = gets.chomp.to_i
test_cases.times do 
    a = gets.chomp.to_i
    a1 = gets.chomp.split(' ').map(&:to_i)
    a2 = gets.chomp.split(' ').map(&:to_i)
    puts compare_freq(a1,a2, a)
end

*/

/* I/O:
In #1:
10
7
5 9 3 0 1 5 2 
2 2 4 0 6 1 8 
2
3 9 
7 0 
7
6 2 2 6 4 3 9 
2 9 7 7 0 1 1 
4
9 4 9 0 
8 4 0 5 
8
4 5 5 0 5 6 7 3 
0 4 6 0 2 2 8 4 
7
9 9 8 0 1 5 1 
4 7 2 5 1 2 1 
8
1 0 8 5 3 0 9 2 
2 9 0 8 8 7 1 5 
5
4 7 3 5 0 
5 6 8 5 2 
5
5 3 0 8 8 
7 2 0 6 9 
2
2 5 
6 9 
Out #1:
Rupam
Rupam
Ankit
Rupam
Rupam
Rupam
Ankit
Rupam
Ankit
Ankit
In #2:
10
4
4 1 5 6 
2 2 0 6 
4
9 5 3 1 
3 2 2 0 
3
3 9 9 
8 1 1 
8
1 6 1 5 8 9 8 2 
9 0 4 7 1 1 0 2 
2
6 7 
2 6 
7
2 1 1 1 1 5 7 
6 5 0 4 5 0 6 
3
9 6 0 
6 3 7 
3
4 8 3 
4 2 8 
8
2 6 0 2 3 8 0 2 
7 8 1 7 6 8 4 8 
1
7 
2 
Out #2:
Rupam
Rupam
Rupam
Rupam
Rupam
Ankit
Rupam
Tie
Ankit
Rupam
In #3:
Tie
Rupam
Ankit
Tie
Ankit
Rupam
Ankit
Ankit
Rupam
Rupam
In #4:
10
36
8 16 6 4 6 18 10 9 14 10 19 0 2 18 9 13 0 9 0 17 1 4 13 2 13 16 2 8 9 14 16 2 11 6 12 1 
7 12 5 5 1 1 18 2 9 14 6 15 11 5 5 19 5 9 4 6 3 15 12 8 9 16 14 5 18 14 15 13 12 18 0 0 
26
1 12 17 0 1 19 14 4 19 7 1 1 5 0 2 19 2 10 9 6 8 11 18 15 0 15 
15 2 11 19 13 5 4 5 1 6 17 14 9 6 12 0 0 18 5 3 16 10 5 11 13 13 
45
11 2 14 13 8 2 1 2 11 17 10 14 18 14 0 7 4 8 18 6 3 6 11 6 14 4 8 11 5 5 7 18 14 3 18 13 12 12 9 10 13 8 2 16 16 
2 18 13 5 8 1 11 1 6 13 19 5 0 2 17 4 13 7 1 17 10 7 10 13 4 17 19 10 9 17 0 4 3 19 0 9 18 19 14 0 4 10 7 17 2 
49
1 5 10 0 5 13 12 7 14 11 19 6 16 17 0 12 4 1 11 2 1 10 2 17 18 12 3 7 0 2 9 2 8 18 10 9 2 3 11 7 5 0 10 18 13 13 9 19 16 
12 11 17 6 0 18 5 9 2 13 7 17 7 14 8 17 0 10 8 15 14 7 13 4 6 12 3 12 16 0 15 16 4 19 12 2 18 17 18 7 14 8 19 17 7 0 11 9 8 
6
15 5 11 3 13 16 
2 16 6 13 3 2 
1
19 
8 
22
13 16 19 0 3 4 17 17 12 17 13 6 0 17 0 15 15 8 2 16 6 7 
11 13 15 14 3 9 15 11 11 4 19 2 3 2 9 7 7 11 3 8 9 11 
44
15 0 7 4 2 14 9 14 11 10 10 12 18 14 8 19 11 2 13 4 10 19 14 11 13 11 8 16 8 12 9 1 15 18 12 8 15 3 8 18 11 14 14 16 
17 14 18 2 10 1 1 8 18 2 7 19 1 9 10 4 8 10 19 11 0 9 10 8 4 17 14 8 14 8 17 5 5 9 15 5 11 3 0 19 2 4 2 0 
11
14 10 15 12 9 13 15 10 10 13 19 
6 13 11 11 19 5 14 2 9 17 4 
21
3 14 13 14 0 3 11 4 19 16 4 1 4 15 16 3 15 12 12 6 12 
15 8 11 15 12 15 2 12 10 4 4 2 2 3 9 0 16 6 18 0 15 
Out #4:
Rupam
Ankit
Ankit
Ankit
Rupam
Rupam
Rupam
Rupam
Ankit
Ankit
In #5:
40
46
16 1 6 7 4 17 8 16 6 13 19 11 18 16 0 12 12 12 3 17 2 15 3 4 11 13 6 11 16 3 13 1 12 9 13 1 5 19 9 7 8 2 0 15 6 19 
10 18 18 15 12 2 1 15 15 1 4 17 4 9 4 10 12 18 4 14 8 13 1 18 8 4 11 8 18 15 14 4 12 17 3 18 0 5 8 12 14 1 19 2 8 18 
49
2 1 5 9 6 13 5 2 5 16 8 19 4 14 10 15 5 17 16 6 7 7 19 6 5 9 11 11 9 19 9 7 18 1 3 4 18 6 8 7 12 9 5 16 9 9 19 1 13 
12 8 11 7 11 11 3 6 17 10 10 8 0 8 18 4 7 16 16 12 12 12 3 5 3 11 11 11 18 8 10 8 13 5 1 6 12 0 7 13 12 14 9 14 7 4 10 7 6 
29
3 6 8 4 17 12 1 7 19 18 6 10 18 10 7 1 11 6 0 4 0 11 15 18 17 15 2 11 7 
5 5 19 6 7 12 10 13 0 8 11 12 0 0 16 1 9 1 13 15 0 16 6 19 18 16 8 13 0 
49
0 5 19 11 1 6 4 18 15 19 15 3 18 19 4 11 17 16 8 15 7 17 18 1 9 13 2 14 3 18 17 8 16 14 15 3 5 6 17 8 19 1 5 19 8 18 2 15 18 
1 1 19 2 2 18 18 17 1 12 8 17 13 16 5 14 19 19 17 2 15 12 9 4 4 19 3 6 16 14 10 0 17 2 6 10 0 8 19 6 17 3 0 8 4 3 13 10 16 
3
14 6 19 
11 10 5 
28
15 0 4 5 19 10 6 3 10 2 17 18 1 10 7 6 12 11 14 2 10 19 19 12 18 13 4 19 
10 12 0 3 11 15 15 13 11 12 9 10 3 5 15 5 6 4 5 19 8 10 11 19 6 3 13 17 
14
6 8 15 18 5 9 6 3 16 13 0 4 16 9 
17 16 1 18 11 12 4 14 7 12 9 8 17 7 
20
0 2 5 9 9 15 9 6 7 14 18 12 3 18 4 11 2 4 16 0 
12 18 4 10 5 1 19 17 9 16 15 10 4 8 6 9 9 11 11 5 
16
15 1 13 5 4 14 1 10 6 6 2 13 9 10 9 3 
4 9 13 16 6 16 9 12 5 9 4 17 4 16 18 1 
28
12 8 17 15 15 10 15 16 9 15 18 12 8 16 17 12 1 13 5 18 5 14 10 3 11 7 6 11 
8 15 10 17 13 8 16 2 1 8 1 2 9 13 9 3 12 11 19 8 17 14 11 11 4 19 2 16 
19
2 7 12 16 13 2 16 16 3 2 7 9 1 11 1 17 12 19 14 
19 5 12 4 15 3 2 7 17 5 1 18 7 5 17 13 6 13 0 
16
5 13 0 2 6 19 12 15 14 12 13 10 7 9 9 1 
14 0 14 8 3 5 18 10 18 2 7 19 14 6 7 5 
16
18 11 15 13 18 2 4 3 10 17 6 12 18 1 12 18 
10 4 2 2 6 0 0 11 19 17 0 7 12 17 19 11 
41
8 6 0 2 9 15 3 15 12 9 5 14 17 0 15 13 9 4 15 11 12 13 16 11 19 13 19 13 16 1 15 2 14 15 18 17 1 6 5 0 13 
5 16 3 18 7 1 6 13 13 4 9 18 10 16 12 5 5 14 5 11 7 15 14 15 15 0 14 16 5 15 14 10 9 5 1 18 14 12 16 5 11 
10
16 6 11 4 0 7 17 6 15 11 
5 4 13 14 18 14 19 12 12 0 
30
4 8 3 3 3 0 12 4 14 11 16 5 2 0 16 14 15 1 1 4 4 17 19 0 14 7 17 4 1 4 
12 4 7 15 10 6 9 5 1 17 0 10 18 3 14 0 18 0 5 8 15 19 19 8 7 12 0 19 9 15 
1
7 
16 
28
7 4 0 6 10 19 12 17 4 13 8 7 11 5 6 19 17 2 8 6 11 14 2 10 6 13 19 0 
14 13 7 3 12 17 4 4 13 0 17 14 5 3 5 18 12 19 18 10 12 16 14 18 14 16 6 12 
37
2 12 14 11 19 16 14 1 10 7 9 19 19 6 0 6 2 14 9 13 7 17 2 3 7 4 11 4 18 4 16 14 13 3 5 10 13 
2 17 0 3 11 9 2 7 9 0 5 2 10 12 8 7 12 5 13 4 8 0 16 8 13 15 7 0 6 10 10 9 18 5 7 14 15 
29
3 19 19 3 11 5 19 3 0 6 1 10 10 4 13 16 7 11 8 1 18 15 1 18 5 12 4 18 13 
7 16 5 19 18 13 11 10 0 15 9 5 9 16 14 0 17 2 17 8 13 5 17 19 4 0 10 6 0 
16
14 12 5 16 12 6 0 17 3 0 17 6 14 2 16 6 
4 2 7 13 3 19 2 15 14 18 4 5 0 14 0 1 
11
5 19 13 6 14 14 11 19 4 0 13 
10 5 4 0 19 9 3 2 9 5 13 
1
5 
14 
36
9 7 12 16 3 15 0 4 17 0 19 10 19 13 15 10 17 11 7 16 10 2 6 18 8 19 19 10 11 0 7 5 15 13 0 0 
6 16 1 12 15 1 17 9 5 10 1 3 8 13 15 5 2 11 19 4 13 15 0 0 17 17 13 17 0 9 17 18 7 15 5 15 
24
7 1 18 11 1 9 18 19 15 12 10 15 5 3 12 18 7 16 5 12 16 14 19 15 
8 17 2 10 13 13 0 16 0 7 12 0 15 15 7 15 12 9 0 14 18 2 14 14 
45
16 6 7 18 19 5 6 13 9 6 15 1 12 2 17 11 7 1 17 15 1 14 0 9 16 17 19 6 18 18 4 18 18 11 3 15 10 11 16 14 4 10 3 12 5 
14 0 1 3 9 9 2 15 19 6 17 11 10 3 17 7 5 8 2 18 17 15 12 5 15 3 0 4 14 15 6 14 2 0 17 19 1 9 9 5 1 17 16 7 17 
32
1 12 11 5 16 1 1 5 8 1 14 16 5 4 13 17 19 5 0 16 1 6 18 2 1 14 15 13 16 5 1 1 
15 11 3 6 12 0 5 19 1 6 19 10 9 8 7 11 7 4 6 7 8 9 10 0 12 1 10 8 9 15 0 17 
29
12 6 4 11 14 10 14 0 10 4 18 6 4 14 5 2 8 9 9 1 1 6 12 9 17 5 15 14 11 
17 19 12 9 7 3 8 3 9 11 7 5 10 14 11 8 16 17 12 14 2 8 5 8 12 16 18 9 7 
17
19 2 13 9 19 5 18 11 2 2 8 5 19 12 15 10 5 
3 16 8 11 4 0 15 5 0 5 0 3 14 0 2 9 18 
1
19 
15 
19
4 2 0 16 9 15 6 1 19 10 0 19 7 10 0 15 18 16 7 
2 5 15 10 14 15 13 6 6 18 6 8 3 11 13 5 0 2 19 
32
17 19 1 2 14 0 13 7 16 3 15 1 16 5 13 10 15 18 5 3 18 6 17 16 18 4 4 1 7 6 11 7 
14 3 2 6 8 14 18 4 16 18 13 19 3 18 0 1 12 16 10 19 17 15 15 2 2 3 13 17 14 14 11 15 
16
12 13 10 3 14 15 12 9 10 6 15 18 6 19 16 14 
13 16 16 19 14 14 8 10 14 13 18 3 1 2 2 1 
3
3 2 18 
17 18 10 
1
10 
2 
5
15 17 6 8 14 
9 13 18 13 13 
9
6 11 16 6 11 1 14 7 5 
14 11 17 8 7 1 19 13 7 
26
5 14 0 11 3 17 14 10 13 16 10 5 17 15 2 0 5 10 8 19 3 3 0 7 17 6 
11 19 5 16 16 1 18 7 15 13 14 3 19 11 1 1 15 10 2 15 13 11 18 6 2 3 
45
3 3 1 10 17 8 11 13 13 10 15 1 1 10 17 4 0 9 14 6 3 10 3 1 11 4 17 11 16 11 15 18 8 4 15 15 10 16 13 9 10 3 1 16 19 
1 4 3 1 6 4 4 16 11 3 16 11 16 8 8 5 13 1 12 12 16 9 19 12 1 6 0 9 4 13 1 13 19 5 16 14 15 14 15 2 18 19 6 6 13 
49
7 12 2 0 13 1 10 9 7 3 5 15 8 5 15 8 12 16 3 18 4 16 8 3 11 16 15 16 11 4 11 11 19 1 15 1 6 9 2 0 7 15 11 17 2 5 17 5 4 
2 18 4 11 12 16 12 6 7 5 5 5 11 5 2 6 7 1 16 8 12 0 16 12 7 15 19 18 5 0 6 3 4 8 16 19 1 15 8 16 2 17 11 10 12 5 1 7 13 
Out #5:
Ankit
Ankit
Rupam
Ankit
Rupam
Rupam
Ankit
Tie
Ankit
Rupam
Rupam
Ankit
Rupam
Rupam
Ankit
Rupam
Ankit
Ankit
Rupam
Rupam
Ankit
Rupam
Ankit
Ankit
Rupam
Rupam
Ankit
Rupam
Rupam
Rupam
Ankit
Rupam
Rupam
Tie
Rupam
Rupam
Rupam
Rupam
Ankit
Rupam
In #6:
40
1
0 
11 
3
15 6 5 
8 16 5 
37
1 11 13 9 1 5 5 10 2 8 4 4 9 8 5 15 3 0 11 15 14 13 3 18 13 19 12 19 15 9 11 11 6 19 0 12 9 
2 13 6 0 4 7 3 2 0 16 11 5 8 8 2 7 1 18 0 0 10 14 10 8 15 11 0 3 10 0 13 10 19 11 8 14 3 
11
10 14 3 1 6 18 7 19 2 14 17 
13 16 15 2 4 15 0 11 7 13 1 
42
10 2 7 9 2 7 16 10 10 3 2 18 12 1 6 7 3 11 11 10 1 11 1 12 12 1 5 7 17 7 3 6 12 12 13 13 13 0 15 8 7 16 
16 8 9 9 16 16 3 3 13 18 16 2 8 4 4 6 14 18 8 5 6 10 18 1 2 14 10 12 0 7 4 2 12 8 1 13 17 12 0 8 14 12 
14
6 7 8 19 19 16 2 2 12 17 2 10 7 14 
8 8 13 8 18 16 14 0 19 5 9 6 1 18 
16
16 1 19 16 18 9 2 12 7 15 14 12 12 13 15 0 
12 16 10 1 6 15 9 9 13 7 10 15 10 7 16 15 
26
7 12 4 4 18 19 10 19 7 2 8 6 12 12 18 8 4 4 19 0 19 17 5 18 14 9 
9 18 12 3 6 9 17 8 12 10 8 16 9 11 4 18 17 6 13 16 6 12 19 17 4 0 
29
11 3 16 10 10 0 2 0 6 17 12 14 5 6 17 9 15 2 15 4 19 4 1 6 5 3 2 0 18 
15 1 9 4 3 7 4 8 0 9 16 13 10 7 1 19 0 17 10 16 5 2 1 4 5 17 16 7 14 
39
13 12 19 18 3 1 15 9 19 13 1 2 8 17 1 7 17 11 7 19 10 1 9 19 9 8 6 15 14 2 7 12 7 9 10 13 17 6 1 
9 2 14 18 3 5 4 9 7 8 3 15 7 15 4 4 0 1 1 16 13 2 10 12 6 8 12 8 16 11 4 17 17 8 19 5 4 16 15 
16
12 5 19 19 15 9 19 6 14 11 12 10 13 6 15 18 
4 4 5 1 15 5 3 11 19 3 8 7 0 12 14 2 
49
12 7 0 18 1 14 18 5 16 8 8 14 9 17 8 19 1 3 7 13 14 7 3 16 13 17 6 6 16 15 5 12 14 15 13 4 13 18 14 14 0 17 14 9 19 12 9 3 12 
0 17 11 13 12 15 11 7 19 18 5 13 16 0 12 18 9 8 13 7 13 14 0 5 19 11 10 14 16 8 19 0 7 1 12 7 12 11 5 19 10 16 17 7 14 10 3 9 4 
3
10 7 15 
16 5 4 
37
17 19 1 12 18 1 1 15 13 9 7 11 19 3 4 9 15 17 0 15 18 17 4 9 11 4 10 13 10 19 9 11 8 17 14 8 19 
18 3 14 15 10 13 4 7 8 17 12 12 15 8 13 3 4 15 10 17 13 8 5 7 19 17 17 15 17 10 18 0 5 12 13 7 10 
18
2 4 3 2 15 2 16 3 3 12 1 3 4 18 15 10 8 19 
9 1 17 16 12 17 0 1 16 18 13 8 19 13 1 4 4 12 
29
19 18 7 19 10 15 14 13 19 16 14 11 17 13 14 9 0 4 17 9 5 8 11 19 10 3 10 3 11 
19 12 10 15 4 11 18 5 5 4 8 0 12 8 14 15 18 8 10 11 9 3 0 8 18 15 9 15 19 
13
19 7 2 14 10 13 19 9 14 6 11 8 19 
4 0 2 0 8 19 2 18 1 6 16 7 4 
39
2 12 5 8 1 0 3 4 14 15 1 4 8 17 16 10 18 19 13 9 7 15 3 18 6 8 18 19 4 0 9 15 6 14 14 17 0 6 8 
13 0 3 18 6 6 2 19 3 16 6 1 7 8 3 13 19 1 11 11 7 13 2 15 8 9 3 2 9 4 1 9 17 3 4 19 11 17 10 
23
13 13 18 0 19 12 12 8 8 19 16 3 3 13 4 18 1 17 16 11 11 12 2 
18 18 14 8 12 13 16 4 15 5 1 14 15 4 1 4 6 0 17 15 16 4 5 
28
1 15 1 7 2 13 2 2 1 13 6 13 17 2 2 9 17 7 18 12 4 11 3 13 1 5 16 0 
6 3 19 1 13 1 8 13 9 13 18 5 4 13 9 3 12 15 11 18 1 12 0 8 4 16 2 15 
8
13 16 13 6 19 18 12 10 
12 7 10 4 1 1 17 8 
3
5 3 2 
18 14 7 
26
6 14 16 7 10 11 4 19 3 5 18 1 4 16 14 0 12 0 0 19 6 0 17 0 0 1 
13 13 16 3 7 1 8 2 6 6 6 10 19 5 1 3 17 5 14 4 14 17 19 16 8 8 
14
17 12 8 16 15 17 5 11 7 16 0 4 14 11 
12 1 9 1 9 9 15 13 6 10 4 11 3 9 
37
16 16 1 8 10 18 8 15 0 1 19 10 13 11 10 12 4 9 2 2 0 4 3 14 6 1 18 9 14 16 13 8 6 18 19 14 14 
15 7 16 9 17 11 15 2 19 15 11 13 13 1 16 13 14 4 3 8 12 19 8 14 2 15 19 2 4 6 8 4 5 12 0 7 3 
39
8 10 11 5 19 0 7 1 5 6 16 15 5 11 12 8 19 11 2 12 5 18 18 9 4 19 16 1 4 6 3 7 17 6 1 16 16 10 15 
8 19 11 10 1 18 16 3 1 0 14 6 17 14 9 3 14 5 6 17 16 7 16 2 2 3 15 5 5 3 2 9 8 3 2 11 15 6 5 
27
5 8 12 19 13 4 9 15 0 4 6 1 4 4 7 6 8 17 10 0 18 7 7 7 18 16 9 
16 16 0 16 16 7 1 2 10 6 3 1 8 8 12 12 15 4 11 5 16 9 13 11 9 14 6 
28
13 10 10 12 15 8 15 4 5 0 14 3 19 3 6 6 13 14 10 4 16 11 15 16 1 9 19 11 
13 3 18 2 18 11 0 7 6 16 18 15 5 13 13 3 10 13 15 3 5 4 14 15 1 11 12 6 
19
9 10 6 14 16 16 7 5 3 9 4 12 9 0 5 19 5 13 10 
2 14 10 12 8 17 18 6 4 17 13 2 7 12 15 15 13 9 9 
48
16 5 2 14 15 13 6 1 17 19 0 17 11 10 13 0 3 2 3 15 13 17 7 0 10 15 2 10 8 11 17 2 10 7 17 7 4 7 3 10 4 10 6 19 5 7 13 1 
0 3 7 16 2 3 6 8 13 8 4 16 16 0 18 0 3 2 4 14 7 10 0 11 1 4 12 4 16 2 7 16 17 3 18 13 19 15 13 5 17 9 19 0 17 12 10 13 
5
13 12 16 17 17 
15 0 16 4 1 
38
15 6 10 11 11 6 6 5 14 5 19 16 15 2 11 8 7 15 5 9 14 8 10 1 19 13 13 9 3 5 14 14 12 7 4 8 17 5 
18 18 6 0 15 3 2 13 14 8 19 10 10 7 9 12 15 19 12 7 11 14 0 0 16 19 8 12 15 15 14 1 10 14 9 9 16 11 
48
10 1 18 11 14 8 18 7 12 1 11 16 9 6 17 14 19 7 0 2 18 14 6 17 11 7 15 10 6 12 3 6 11 13 10 4 2 4 9 8 5 13 10 19 6 13 9 9 
12 19 6 19 7 14 10 4 18 3 3 16 15 13 18 1 11 1 19 1 2 12 6 0 14 6 5 9 7 16 8 7 3 7 7 14 3 18 16 14 17 18 14 10 8 12 13 18 
32
4 0 4 14 17 19 11 12 11 10 0 10 13 3 19 7 19 5 13 13 19 2 1 4 0 1 11 15 16 17 12 4 
0 12 10 16 12 18 14 4 5 1 18 8 4 1 16 0 6 4 12 15 13 14 15 3 17 4 7 16 1 10 6 5 
14
19 13 3 14 8 0 1 5 10 1 14 10 14 9 
8 8 5 0 19 11 0 19 17 6 7 12 8 15 
13
2 3 15 11 12 0 13 7 3 14 8 12 17 
7 14 16 15 10 18 12 12 14 8 19 16 2 
25
12 16 5 3 5 6 9 6 4 17 5 18 11 0 17 5 18 7 11 12 10 8 7 3 13 
18 9 13 4 18 10 19 17 9 13 6 12 15 0 12 14 7 5 3 11 2 1 1 1 7 
18
18 17 13 17 17 7 11 4 12 19 18 2 14 4 1 0 12 17 
13 1 12 6 3 6 1 6 5 16 6 5 7 18 15 13 13 5 
33
4 13 4 15 19 10 4 9 13 19 3 2 10 0 17 18 2 15 4 13 1 13 0 8 5 9 9 11 5 8 19 19 5 
9 15 5 18 11 19 6 16 18 16 1 16 6 11 3 8 8 2 13 10 4 17 9 17 3 13 6 19 18 16 14 4 15 
16
2 10 9 17 15 13 7 10 5 6 9 2 8 15 6 16 
3 14 10 19 6 6 9 4 9 7 8 5 6 17 3 12 
Out #6:
Ankit
Ankit
Rupam
Ankit
Ankit
Ankit
Ankit
Rupam
Ankit
Ankit
Rupam
Rupam
Ankit
Rupam
Rupam
Rupam
Rupam
Rupam
Rupam
Ankit
Rupam
Ankit
Ankit
Rupam
Ankit
Rupam
Ankit
Rupam
Ankit
Ankit
Rupam
Ankit
Ankit
Rupam
Rupam
Ankit
Rupam
Rupam
Rupam
Rupam
In #7:
40
8
16 19 18 17 17 8 17 16 
10 15 15 10 15 17 2 19 
39
6 7 13 7 17 19 16 19 6 5 3 5 14 16 19 0 3 12 11 4 8 4 14 18 3 17 17 13 4 2 7 10 14 8 12 7 19 10 7 
10 19 7 14 2 16 10 17 2 9 4 10 11 3 10 10 15 6 19 1 6 5 5 2 16 18 14 19 2 8 8 6 14 8 0 15 14 5 10 
9
16 15 13 8 16 16 13 14 13 
9 7 3 8 9 14 7 9 9 
26
10 3 10 4 9 16 17 18 11 8 10 5 14 12 17 19 7 16 2 16 16 18 12 15 15 11 
0 15 16 18 15 3 15 0 3 19 4 0 17 11 15 9 18 11 11 18 18 5 4 0 8 11 
50
10 10 7 16 16 6 2 7 4 2 12 1 2 16 16 17 15 8 1 18 11 16 0 16 2 2 11 14 7 6 19 1 11 16 5 1 5 10 15 17 18 4 9 0 6 6 19 6 3 4 
2 19 13 5 5 11 13 12 4 19 9 9 4 18 8 8 2 12 9 7 7 19 5 3 2 19 5 11 19 5 4 9 13 6 11 1 6 1 17 12 2 13 11 12 18 3 13 2 3 17 
53
11 9 16 18 1 19 19 1 12 12 6 7 4 10 0 15 3 5 17 10 6 0 5 19 13 5 12 1 14 5 5 4 9 10 4 17 1 13 6 16 8 2 19 14 8 4 11 5 10 2 12 12 8 
8 12 12 7 4 4 3 1 19 16 5 12 0 6 12 17 3 10 18 11 12 3 9 11 1 0 17 15 5 7 14 19 9 15 15 9 12 11 12 0 19 10 0 0 1 1 17 14 9 1 18 5 19 
92
13 8 14 9 1 15 3 16 16 17 6 1 11 12 11 17 11 7 15 19 3 0 5 17 17 6 7 16 6 9 11 6 18 4 14 7 15 3 18 7 18 16 8 14 1 1 11 15 18 7 3 3 4 15 19 14 7 18 13 0 19 13 10 3 16 2 13 9 15 2 8 10 16 14 2 13 3 12 8 1 5 6 7 17 19 15 11 0 11 3 10 11 
4 18 6 10 15 10 1 15 6 8 0 7 1 6 1 16 13 12 18 1 3 8 10 12 11 3 12 5 17 1 15 18 5 18 5 15 9 8 14 13 9 10 9 5 5 8 4 3 12 10 16 0 2 13 9 6 19 18 15 3 12 6 0 16 4 7 9 8 1 19 3 12 3 14 13 14 8 8 18 8 14 0 7 10 5 12 13 16 14 16 17 1 
81
19 4 16 3 14 10 16 16 1 18 15 0 5 19 7 10 5 0 12 4 17 2 13 6 13 5 4 7 6 10 12 9 12 17 1 13 3 19 5 3 0 1 17 19 10 16 10 3 7 17 12 9 12 4 12 5 7 1 19 16 17 19 14 10 9 9 4 5 17 6 19 1 19 11 15 6 16 14 13 0 1 
6 6 13 11 7 3 16 15 8 19 0 17 5 19 2 16 4 6 17 14 16 18 4 8 9 6 1 6 6 4 16 14 11 11 19 2 4 14 11 3 1 9 16 14 3 17 9 4 5 10 14 3 3 1 17 14 3 19 7 5 4 17 13 6 3 13 7 8 17 5 13 11 0 10 18 18 4 4 8 7 5 
19
8 5 18 11 0 3 16 12 13 17 13 5 1 9 10 7 15 19 7 
2 5 14 0 4 15 11 18 10 5 8 11 0 19 11 6 6 2 17 
37
5 3 5 6 14 7 4 8 14 12 2 1 0 0 16 13 0 19 16 19 8 15 6 10 17 9 6 18 10 9 8 11 4 6 6 19 8 
13 3 15 17 13 6 3 9 17 4 11 4 19 3 0 15 16 2 14 8 14 4 9 15 8 2 3 6 2 8 12 15 11 7 4 2 17 
80
19 12 1 19 0 9 7 1 4 15 6 15 5 14 7 7 5 12 18 13 1 19 8 18 6 13 0 11 18 14 7 3 9 16 15 15 7 2 19 10 15 12 0 13 13 1 3 9 5 16 17 12 4 16 1 16 4 14 4 19 4 16 10 13 15 7 18 2 7 18 16 18 16 7 18 14 3 11 2 3 
18 4 12 17 18 3 15 14 17 3 12 13 5 14 2 3 1 19 19 12 5 16 1 3 8 16 9 10 8 2 4 16 2 2 10 11 3 6 15 10 6 17 19 8 5 18 3 12 5 13 9 6 19 11 3 11 16 1 11 9 0 5 15 6 19 19 18 2 13 10 1 17 7 7 3 17 10 12 6 16 
51
5 1 17 19 12 10 14 10 4 3 19 13 17 11 16 5 7 16 1 7 13 12 15 5 7 19 6 1 6 8 15 13 10 13 9 9 12 11 10 9 14 0 11 1 1 18 15 9 10 18 4 
9 18 4 11 4 6 1 7 6 13 5 1 18 2 15 11 10 14 3 16 8 1 13 0 14 18 5 15 9 3 9 12 15 1 15 13 6 9 4 18 15 5 4 5 16 18 7 7 8 11 14 
49
1 1 16 2 9 12 6 6 13 9 12 1 7 2 10 18 9 4 12 18 1 11 11 7 2 8 15 19 4 8 18 4 9 13 1 8 14 3 9 1 2 19 8 1 12 16 2 8 2 
5 3 18 0 5 10 6 2 1 6 10 6 4 9 17 2 12 6 1 12 12 8 18 19 18 14 13 1 19 1 12 0 3 3 9 4 18 18 1 17 19 2 16 17 16 18 17 7 8 
34
11 7 12 11 11 15 14 9 6 15 15 4 9 1 7 16 19 1 5 5 1 8 14 5 12 4 10 2 6 17 16 17 13 14 
15 8 14 10 8 13 17 9 6 1 13 16 9 0 1 15 0 5 2 10 6 13 8 18 7 2 10 11 4 0 15 9 11 10 
22
2 14 19 19 7 6 4 3 4 4 10 17 10 19 7 0 1 15 9 9 6 4 
16 11 11 18 13 3 5 16 17 18 11 5 1 10 10 0 5 14 18 18 12 3 
53
0 11 15 7 16 5 12 18 4 4 0 0 15 0 14 8 10 6 10 4 18 0 19 13 16 3 7 9 9 17 0 16 17 9 13 11 4 18 3 9 18 19 11 2 13 13 3 9 16 11 11 7 7 
7 18 6 11 12 6 19 16 18 8 18 12 0 0 12 12 14 11 9 17 15 6 12 17 3 3 15 12 6 3 3 14 4 3 7 17 8 7 15 8 9 0 0 15 13 7 9 12 4 11 18 3 0 
5
11 16 14 10 12 
14 14 15 9 19 
93
13 3 10 13 8 14 0 1 18 15 7 3 19 13 2 11 1 0 1 5 4 15 11 9 7 3 0 2 11 18 18 8 18 7 0 15 0 11 18 15 17 17 10 19 12 7 8 18 16 16 4 7 14 2 14 0 8 4 10 13 9 19 17 10 17 19 12 10 12 8 17 9 0 6 12 6 11 14 5 3 16 2 9 16 6 4 1 6 4 18 15 5 19 
7 1 19 1 13 16 13 1 14 1 13 3 2 8 18 14 2 6 3 9 11 6 1 11 1 8 7 11 7 19 16 0 16 14 1 19 3 11 10 4 8 19 1 10 3 6 14 12 9 13 3 2 5 13 12 14 9 3 6 18 13 10 7 13 15 9 0 10 3 6 4 17 8 11 9 2 12 11 5 3 0 5 2 5 10 17 7 19 9 18 7 0 4 
96
16 15 14 17 14 0 2 12 15 7 7 7 10 11 12 11 11 13 16 10 15 12 17 15 2 15 16 14 18 5 16 14 0 8 18 6 2 1 9 4 17 9 18 16 0 0 11 11 14 12 2 4 8 12 7 3 11 6 4 6 2 15 8 16 10 13 7 9 0 0 2 6 2 12 15 15 3 18 12 0 7 17 12 8 10 14 12 18 8 12 15 9 12 0 7 19 
3 14 16 3 2 14 10 4 14 15 16 18 10 10 16 0 14 2 14 19 19 12 15 19 6 14 9 7 6 17 11 19 16 5 15 7 6 8 10 6 11 18 13 8 19 16 11 12 11 1 15 11 19 9 9 6 2 19 2 0 7 11 16 17 10 18 6 17 4 11 6 5 16 2 19 16 3 15 15 7 14 2 10 3 2 2 0 14 16 2 4 8 1 16 19 10 
28
5 7 1 4 7 2 3 1 17 0 1 12 4 8 14 6 12 5 0 2 12 1 5 8 4 2 2 8 
7 0 6 1 13 1 18 17 8 1 7 5 10 1 13 18 6 17 14 16 18 2 16 10 4 18 16 19 
3
19 1 11 
0 19 5 
34
3 18 7 7 19 0 17 11 10 16 7 5 10 14 11 8 1 1 16 2 4 16 2 7 14 2 7 18 8 18 11 7 16 10 
10 4 4 8 9 4 10 10 4 5 12 8 6 3 16 2 5 13 15 8 19 14 4 12 1 12 8 2 16 15 17 19 14 13 
29
0 6 1 7 18 7 18 8 15 13 0 8 17 10 12 14 6 10 16 17 14 1 9 2 6 14 2 8 2 
6 5 3 15 17 12 17 9 0 10 1 16 14 17 8 5 2 9 18 18 5 7 15 1 13 9 4 4 19 
32
19 18 14 14 14 10 10 18 2 0 16 7 6 0 13 11 6 15 19 12 14 10 14 14 14 19 18 11 0 19 18 10 
10 13 0 9 18 1 18 4 7 3 17 16 10 7 15 9 5 14 5 8 8 19 12 7 1 9 4 6 16 5 9 13 
20
6 1 17 12 17 1 1 13 15 4 2 3 19 15 10 3 16 13 8 1 
4 18 16 5 18 16 14 14 11 15 19 12 7 19 2 16 2 3 16 14 
32
13 8 0 9 0 9 16 10 16 18 12 9 0 4 5 14 2 8 8 1 10 10 11 11 4 0 1 17 3 16 0 8 
11 19 17 15 6 12 17 3 15 0 13 7 5 19 8 8 0 13 2 2 6 13 5 1 0 17 9 2 5 12 12 2 
55
6 10 6 10 11 11 10 7 4 5 8 18 0 6 3 14 17 15 4 2 2 18 3 17 0 12 12 14 15 15 6 15 8 5 5 7 2 5 7 1 12 6 7 5 7 12 8 7 12 2 3 5 11 16 2 
19 0 7 17 0 19 10 4 8 12 18 2 14 14 10 11 15 6 12 19 16 17 3 9 1 4 19 12 7 7 3 14 15 15 12 9 12 4 5 11 3 2 14 9 13 8 16 12 9 10 19 8 19 3 0 
26
18 13 17 4 15 15 12 7 1 4 5 3 3 4 8 3 0 17 14 4 2 4 8 4 2 10 
7 15 10 14 12 9 5 3 0 6 2 3 16 2 13 17 6 3 8 7 6 9 8 0 18 1 
97
16 19 18 1 16 10 11 1 13 15 4 4 5 10 17 9 2 15 5 3 8 7 15 5 14 6 19 3 9 10 5 0 18 10 5 16 0 3 16 15 3 10 11 7 12 4 18 16 14 5 8 14 13 19 18 9 9 14 13 7 19 16 6 1 2 10 4 17 4 6 0 6 8 13 14 7 1 12 16 1 5 4 1 3 1 12 11 1 9 8 17 9 17 11 18 8 9 
1 14 16 8 14 4 9 3 9 14 6 15 16 12 6 1 2 9 17 13 12 6 10 0 0 16 10 0 11 16 12 7 7 11 11 10 11 10 4 0 17 14 8 5 12 1 3 11 5 0 19 7 15 5 8 16 13 0 1 2 14 17 12 7 13 12 15 12 16 17 16 14 6 6 9 17 2 2 2 5 3 1 1 15 14 0 6 3 14 19 7 10 10 15 7 12 19 
61
17 1 6 14 4 9 12 17 3 10 16 8 14 19 10 6 8 16 0 8 3 19 0 9 4 10 15 12 13 7 12 2 9 12 10 1 11 5 12 2 3 11 0 5 7 8 0 12 1 0 10 16 15 15 18 17 19 18 2 18 10 
17 10 4 0 1 7 3 3 11 11 0 10 15 6 1 17 11 3 16 16 1 0 6 9 6 13 1 15 19 8 3 8 8 2 13 16 11 6 17 11 17 0 3 17 3 5 16 15 8 15 11 0 18 9 0 18 19 7 3 15 5 
79
1 8 13 3 11 1 10 15 8 6 8 14 0 13 6 3 17 6 14 7 1 0 8 16 1 15 14 4 7 1 2 3 14 2 5 11 9 18 16 16 1 13 13 16 18 3 3 18 18 13 18 15 9 0 9 15 5 7 4 17 6 17 16 9 10 7 2 6 19 8 13 2 2 1 4 8 6 12 7 
10 9 16 7 6 14 8 7 9 19 7 5 19 0 9 17 6 7 0 6 4 9 10 10 15 19 16 10 12 5 2 12 11 15 1 10 13 17 8 4 10 9 4 7 13 9 11 19 13 17 10 15 2 5 12 1 8 11 4 17 2 5 12 0 7 15 15 18 18 12 9 12 11 2 18 13 10 19 19 
88
17 5 12 6 19 10 10 9 6 10 11 2 11 9 13 10 9 3 4 2 11 13 4 19 11 12 4 16 17 9 17 12 1 7 2 8 16 18 1 16 17 2 2 6 3 7 18 10 2 18 19 0 9 7 1 16 6 9 14 19 6 16 2 5 0 4 15 12 17 4 6 3 19 0 15 2 16 0 17 9 2 11 2 0 4 9 18 3 
19 12 10 9 9 8 13 4 18 3 8 16 12 1 1 3 3 17 5 15 16 3 9 5 17 9 1 1 1 3 4 10 4 0 15 16 10 15 5 11 4 16 2 4 5 18 12 5 0 11 1 19 13 8 5 5 8 1 6 15 9 8 9 1 19 9 2 18 6 9 12 8 3 18 0 8 4 16 8 0 16 12 18 19 13 0 7 15 
78
16 14 1 3 17 7 18 1 5 8 19 12 4 9 17 10 17 4 2 9 5 10 8 11 13 11 7 9 4 6 11 18 9 4 3 12 18 4 1 19 15 14 12 0 14 10 18 10 1 2 5 1 19 6 9 16 13 4 3 4 10 16 17 3 13 10 14 4 16 5 2 15 19 8 19 5 14 7 
19 1 11 5 6 0 18 16 18 3 17 10 9 2 14 7 11 4 5 2 18 6 6 7 1 17 17 12 5 6 9 9 15 2 5 4 13 19 6 10 13 16 16 5 18 8 12 13 2 4 5 9 5 19 14 7 18 5 9 1 0 6 12 17 6 4 14 11 12 15 16 2 3 6 5 4 12 19 
15
5 14 18 11 18 11 15 19 13 9 1 3 9 7 5 
0 11 3 8 19 0 2 1 10 1 13 14 5 13 14 
1
8 
5 
7
6 7 7 5 5 11 5 
19 2 18 4 5 2 19 
63
0 11 10 12 15 13 14 0 4 0 19 10 6 11 13 3 6 3 18 2 18 0 2 6 5 2 1 0 17 10 3 4 13 4 2 15 5 5 0 15 6 12 12 15 11 4 7 11 1 0 4 6 7 5 3 3 15 3 18 12 12 8 8 
2 2 5 18 1 8 2 10 11 10 19 11 15 14 3 3 3 12 15 11 7 10 10 15 8 6 9 18 9 14 1 19 9 9 8 4 0 2 14 17 2 10 10 9 3 11 3 14 9 4 18 9 19 16 15 13 8 19 14 0 19 13 10 
36
5 2 1 1 7 0 19 11 12 7 8 16 12 10 0 6 15 14 9 2 0 8 13 13 9 19 19 9 19 15 3 0 7 4 10 18 
5 12 0 6 3 13 11 1 19 13 1 10 8 7 12 16 15 17 5 12 14 18 17 1 16 0 14 11 14 3 11 14 3 3 11 17 
27
3 8 3 0 4 7 0 7 3 4 5 19 0 0 19 0 7 7 1 2 18 7 19 3 3 7 5 
7 7 8 15 16 3 14 18 11 5 16 12 2 13 1 4 15 11 16 10 6 16 10 7 17 13 15 
76
18 3 1 16 17 3 10 9 0 7 13 11 9 1 8 18 16 0 3 0 14 11 18 2 10 9 17 9 2 10 15 11 7 19 0 12 3 12 15 13 12 3 2 1 9 10 6 18 12 17 12 18 15 5 1 1 14 11 9 17 19 1 14 18 3 5 3 7 8 15 18 15 3 6 16 18 
13 5 17 16 5 1 0 17 19 10 12 16 17 18 11 0 15 10 19 1 8 11 3 19 16 10 5 11 3 11 15 14 18 11 19 7 18 5 2 8 15 19 5 5 18 2 0 9 11 1 1 11 11 6 7 7 0 1 0 4 14 10 13 17 5 15 18 8 16 13 7 6 6 13 11 17 
Out #7:
Rupam
Ankit
Rupam
Ankit
Ankit
Ankit
Rupam
Rupam
Rupam
Ankit
Rupam
Ankit
Ankit
Rupam
Ankit
Ankit
Rupam
Rupam
Ankit
Ankit
Tie
Rupam
Ankit
Rupam
Ankit
Ankit
Ankit
Ankit
Ankit
Rupam
Ankit
Ankit
Ankit
Rupam
Rupam
Ankit
Ankit
Rupam
Ankit
Rupam
In #8:
40
84
8 10 0 5 13 2 3 1 6 2 13 8 14 15 3 1 0 19 16 13 19 4 6 13 0 6 19 13 6 19 14 9 9 10 5 0 5 11 1 3 16 12 1 0 18 11 4 6 0 9 19 3 7 4 8 8 9 2 12 7 6 6 12 1 11 12 3 4 16 8 18 5 13 12 17 14 0 6 8 8 7 1 6 5 
3 6 14 13 7 12 10 15 0 0 10 14 19 19 15 16 18 17 11 9 14 12 8 15 0 3 16 6 7 13 9 0 14 2 5 16 5 11 5 14 11 16 4 1 11 10 2 19 1 3 16 0 2 15 8 4 16 19 10 6 11 12 9 12 9 1 17 7 4 6 19 10 14 4 10 16 10 10 8 14 11 7 16 5 
81
5 14 19 6 0 1 0 6 4 7 1 9 2 11 18 6 7 9 1 16 13 17 12 11 0 14 1 11 15 4 15 14 14 14 3 12 18 3 13 4 16 3 0 0 4 6 12 3 1 4 12 9 3 14 15 14 11 8 12 6 17 4 4 6 14 3 16 6 14 1 2 4 4 9 15 0 2 5 0 14 19 
2 4 18 14 1 7 16 10 18 2 0 1 4 6 2 1 14 11 13 19 18 4 15 12 11 15 4 5 19 3 16 5 6 3 14 2 18 4 5 14 11 14 14 2 17 17 5 5 0 19 4 16 15 16 10 10 8 11 8 8 19 11 1 12 12 9 9 11 1 18 7 13 6 1 1 17 16 5 2 14 16 
45
7 10 15 14 14 8 13 12 9 17 10 9 16 9 13 10 3 17 15 8 11 17 15 17 12 15 14 8 2 19 11 18 13 9 16 3 9 13 16 12 13 4 1 0 3 
6 8 18 7 5 2 19 18 17 6 14 17 11 12 13 15 3 16 19 10 0 7 10 17 18 0 15 7 18 12 6 3 5 3 8 11 12 19 2 10 17 2 18 16 13 
40
12 3 7 10 13 5 14 4 2 1 15 13 8 4 15 7 9 1 6 1 8 14 11 7 3 1 11 9 11 10 17 15 17 3 11 13 19 18 15 17 
3 13 18 3 9 6 18 13 15 17 7 0 6 9 0 12 2 6 13 4 16 5 2 12 3 13 12 2 5 4 0 7 9 18 19 12 4 0 0 3 
57
17 14 6 6 10 14 11 7 3 19 13 5 10 9 8 19 15 7 18 4 16 12 17 12 12 15 19 18 7 16 3 0 11 6 1 0 4 1 4 13 0 17 12 14 2 6 5 3 19 15 19 10 9 0 0 6 1 
15 4 15 9 16 10 18 15 11 0 3 9 5 17 6 0 17 9 5 2 17 18 19 2 7 10 18 14 15 18 2 19 11 5 8 1 11 18 13 8 0 11 19 0 17 1 17 19 1 0 11 10 6 10 16 6 8 
17
17 12 1 0 3 8 1 2 1 9 14 13 15 12 6 3 1 
1 13 11 17 5 14 17 10 9 7 7 13 9 1 0 5 15 
83
16 17 17 1 7 6 6 4 12 14 1 14 9 2 14 12 4 5 11 1 7 9 0 13 9 8 19 10 9 17 15 5 11 14 13 16 10 4 6 19 2 8 6 4 19 1 6 9 19 1 17 10 19 18 4 8 2 13 14 13 18 1 18 8 4 14 8 3 15 18 5 12 7 1 16 5 5 2 9 11 3 12 12 
14 5 11 19 13 13 15 1 5 13 10 10 0 6 14 3 0 6 12 5 7 7 0 16 12 12 7 8 0 12 19 9 8 17 10 7 14 2 10 3 7 8 3 10 3 17 5 17 3 6 18 0 2 10 10 4 2 15 4 6 1 8 0 8 1 17 7 10 11 17 18 12 10 12 5 5 0 17 4 4 3 1 2 
7
16 9 18 8 11 2 15 
13 12 11 10 15 5 4 
79
8 5 17 7 15 11 15 8 12 0 12 1 15 10 6 19 1 19 0 19 6 15 6 5 5 13 6 3 1 0 12 16 7 16 17 17 19 15 8 5 19 11 9 19 4 10 6 5 3 18 16 12 0 14 1 3 19 4 9 2 17 9 14 19 18 18 15 0 16 17 2 10 7 6 13 18 4 13 15 
10 17 9 15 19 2 3 5 3 0 0 9 9 6 14 1 3 7 11 2 14 1 2 3 4 14 16 11 1 17 12 2 2 3 17 5 10 16 18 9 19 10 14 2 2 11 12 17 6 6 1 3 4 17 17 10 0 6 17 7 13 4 15 11 1 14 1 17 6 2 9 13 4 6 0 8 19 14 14 
92
1 19 18 3 2 17 12 6 9 8 3 14 17 5 11 15 13 9 5 3 0 13 9 8 8 3 9 10 12 16 16 17 6 16 3 9 6 8 18 2 10 6 18 7 10 12 18 10 0 5 9 4 14 0 14 10 14 18 5 16 10 14 3 17 14 1 4 17 6 19 18 7 10 2 5 17 7 1 9 17 16 4 16 12 18 17 0 6 19 19 7 10 
9 7 18 12 0 12 8 0 5 9 7 9 5 11 18 12 11 6 4 15 2 18 16 16 12 16 12 0 17 10 12 11 15 5 14 4 2 8 18 17 3 5 13 16 19 3 5 8 5 8 11 12 9 19 2 0 7 12 17 19 15 19 17 11 9 19 6 19 10 8 3 4 6 11 19 7 7 2 4 2 14 11 13 4 10 9 12 3 2 11 4 12 
14
8 1 16 1 5 0 5 14 19 5 3 16 4 9 
4 19 7 18 17 15 15 0 2 9 19 13 19 12 
78
10 19 8 2 12 1 15 12 5 1 2 8 13 2 14 11 17 7 16 15 7 0 18 14 15 11 13 17 2 15 19 10 6 17 6 6 6 0 5 2 8 15 16 3 2 0 0 1 8 14 15 2 10 7 17 8 12 14 11 6 3 12 16 18 13 18 8 19 11 6 0 8 19 1 8 18 7 19 
13 16 3 11 5 11 12 16 12 12 8 6 15 18 8 5 15 0 10 12 11 8 14 10 1 14 13 18 1 7 3 9 0 19 7 13 11 5 15 19 10 12 8 15 0 19 3 3 14 17 16 15 13 12 7 5 13 18 14 8 4 17 19 13 17 11 8 7 4 5 17 15 5 3 12 19 17 17 
15
6 12 13 0 5 6 18 3 15 1 19 11 11 11 17 
6 18 7 18 16 2 12 13 7 11 13 16 2 15 16 
53
19 6 12 3 10 8 12 14 9 2 3 5 4 3 19 2 17 14 13 11 4 8 8 7 17 13 8 1 13 16 15 10 6 9 1 5 1 9 9 12 9 2 14 8 13 13 15 17 12 12 1 8 13 
5 12 5 12 0 0 12 0 3 8 0 12 15 3 2 5 10 17 5 8 9 14 17 4 1 9 9 1 7 12 3 11 10 7 12 12 11 0 19 4 3 4 7 5 8 6 17 9 15 3 19 18 4 
41
13 2 14 17 4 11 4 5 9 13 11 2 1 6 3 6 6 9 5 8 15 8 2 12 11 5 8 18 18 7 9 1 18 16 14 11 11 8 4 14 6 
11 12 9 8 8 19 15 5 7 0 19 10 19 11 5 15 8 2 5 12 1 3 5 12 4 9 18 8 17 2 8 19 13 16 4 8 11 4 14 17 5 
22
16 19 19 1 14 2 6 4 16 8 10 10 19 19 3 3 8 0 14 7 10 9 
10 12 18 6 4 14 10 10 0 0 3 4 0 6 12 0 0 13 3 5 4 12 
67
13 12 19 16 16 8 13 6 6 9 16 19 19 16 19 14 0 12 8 16 8 19 7 13 0 3 1 15 15 4 16 14 14 13 14 9 19 19 16 18 12 5 8 9 0 13 12 10 17 15 7 12 3 3 12 8 18 2 12 8 0 3 18 16 5 8 11 
5 15 5 19 1 11 1 9 17 13 9 12 0 14 4 5 11 18 16 11 2 1 7 4 0 0 8 11 19 8 8 4 10 18 9 15 0 4 12 17 18 3 15 4 16 18 2 5 2 9 3 6 5 15 2 12 11 14 18 8 17 2 8 15 4 4 11 
67
4 1 19 13 11 13 11 17 6 11 10 4 7 4 12 3 8 8 0 1 8 5 9 12 15 9 10 11 7 14 10 14 12 12 4 5 8 15 13 14 1 14 9 15 6 5 9 17 10 5 5 8 5 1 16 0 18 12 10 2 3 5 1 17 9 6 12 
2 4 0 17 9 4 18 17 2 12 4 7 13 4 2 13 1 4 6 18 12 7 0 5 10 5 4 9 2 1 10 3 17 13 12 14 16 19 19 15 3 19 4 17 7 12 18 8 9 19 10 17 16 4 4 11 16 1 8 4 5 0 0 0 19 9 17 
89
15 5 0 6 2 9 0 16 17 15 0 1 2 17 12 2 16 18 0 9 7 14 11 4 0 4 1 6 10 19 10 3 4 15 14 9 2 11 1 16 16 5 5 2 13 4 7 12 4 15 8 18 12 17 10 2 10 4 19 1 9 11 19 9 4 9 18 8 6 15 13 9 15 12 9 0 2 13 11 13 10 8 6 15 0 14 7 9 17 
1 4 10 9 16 16 17 10 17 12 14 19 0 2 15 17 13 6 1 13 12 14 13 18 3 19 3 11 19 5 8 6 14 0 19 7 10 0 6 0 13 18 13 17 8 4 15 18 18 6 3 6 1 3 15 1 18 7 15 16 9 8 2 17 3 1 7 8 8 19 10 15 7 19 1 8 4 17 5 17 8 17 0 16 13 18 17 10 19 
9
18 11 19 8 6 3 1 10 10 
10 15 11 8 10 14 6 0 5 
19
12 16 6 10 7 8 11 7 0 14 17 1 18 13 15 17 17 6 2 
16 13 9 17 5 16 17 7 9 5 19 16 5 15 9 5 15 11 12 
82
0 18 4 19 4 14 5 11 0 12 11 19 16 17 14 10 16 6 13 10 2 16 15 0 0 18 7 8 12 16 9 12 7 2 0 13 6 11 10 7 3 7 4 0 13 4 17 8 4 15 11 9 13 13 9 2 18 17 18 0 12 0 9 0 9 12 14 14 4 2 13 7 2 0 12 16 18 14 13 4 7 15 
14 10 0 6 12 11 4 18 10 9 12 8 1 15 1 4 17 18 9 0 19 12 14 19 6 12 2 2 17 11 9 12 12 1 7 16 13 2 6 2 18 3 19 0 16 5 4 7 18 19 6 4 7 15 15 16 6 8 3 16 6 13 9 9 12 10 2 1 12 12 4 2 10 2 3 9 14 19 10 12 2 11 
25
4 0 1 2 18 13 3 13 9 7 3 3 19 15 0 14 9 4 18 17 6 15 8 5 17 
13 13 11 15 14 4 6 13 9 9 17 18 5 13 16 3 2 19 5 4 12 19 12 2 0 
36
6 15 3 19 10 4 1 17 10 0 15 17 4 8 8 12 12 13 17 15 4 0 4 8 13 13 19 5 7 7 0 16 14 0 17 8 
4 12 14 14 5 11 8 14 4 16 9 19 19 17 8 13 7 7 13 14 4 14 0 16 11 8 5 12 10 19 19 0 5 5 19 0 
80
2 12 0 10 5 15 11 12 10 9 12 7 19 3 10 10 2 17 0 3 14 6 1 3 16 17 18 0 14 9 2 0 19 12 13 7 10 16 2 15 16 2 6 8 7 2 0 10 13 11 1 3 12 11 14 17 10 10 7 9 10 8 14 3 10 2 9 7 8 13 10 1 17 6 15 6 6 4 13 16 
11 15 17 0 12 11 5 8 15 5 2 14 11 3 4 18 6 19 11 4 17 1 14 15 2 5 19 12 2 12 1 0 19 12 8 16 15 12 11 8 16 18 10 18 11 14 7 9 7 15 19 13 9 12 8 2 10 15 0 14 17 7 19 5 9 13 9 14 18 6 13 18 19 3 19 11 8 19 10 6 
85
11 3 8 0 5 17 17 14 4 15 17 12 14 14 1 7 6 6 14 9 10 4 1 7 5 0 5 12 14 6 4 16 8 5 7 16 0 11 17 11 8 0 15 16 10 9 5 10 12 0 14 17 6 10 1 5 11 2 8 14 17 12 4 18 6 5 15 17 0 0 5 0 18 18 8 3 10 4 6 4 1 11 10 15 1 
0 13 3 9 2 11 10 0 17 17 15 3 17 9 3 17 0 8 13 2 1 9 13 13 16 12 19 11 9 17 19 15 3 10 8 2 14 7 12 18 11 19 11 11 1 7 13 8 10 17 12 19 16 4 13 18 18 4 16 16 7 1 0 12 9 10 2 19 11 15 10 5 2 5 10 10 5 1 19 14 12 19 6 16 2 
31
1 0 4 10 14 11 10 1 3 3 5 19 11 2 15 2 13 12 2 18 14 13 3 5 0 11 10 7 15 14 2 
2 4 10 4 2 17 19 0 9 5 14 4 7 16 7 8 14 17 10 0 3 7 4 6 17 9 19 11 7 14 4 
85
8 6 13 11 16 4 8 17 16 9 8 15 14 15 10 17 11 15 5 5 16 11 19 2 9 9 12 4 6 16 3 14 2 0 19 19 17 15 3 15 6 9 9 0 13 3 3 7 14 11 17 17 7 2 16 6 6 6 5 14 17 14 0 16 14 6 4 10 7 18 14 2 16 5 6 9 18 11 16 17 11 1 14 0 12 
5 6 0 6 3 1 10 5 18 9 14 2 14 1 6 5 15 12 1 14 19 1 7 0 11 19 17 13 5 8 18 14 8 13 12 16 11 13 15 3 1 9 12 9 13 4 19 14 13 8 18 19 5 7 19 0 11 1 9 7 8 2 8 14 12 17 9 18 1 4 17 14 0 9 19 14 11 4 19 14 8 8 14 12 9 
1
19 
17 
22
7 18 1 4 0 7 14 5 1 15 8 14 18 5 8 14 13 4 11 3 4 2 
8 5 17 0 3 7 4 16 19 19 4 12 0 6 4 19 19 15 8 10 1 16 
18
7 14 5 19 10 1 19 1 9 2 2 8 9 14 11 9 10 6 
3 17 11 5 15 10 0 6 4 7 13 12 18 3 3 18 6 9 
10
17 11 2 16 2 0 10 18 11 8 
18 11 12 4 5 1 17 18 2 7 
93
10 3 11 11 5 17 11 6 4 12 13 6 3 2 17 9 15 15 19 4 14 8 7 13 19 14 15 15 2 14 10 14 6 17 19 10 17 11 7 14 18 19 9 8 12 14 4 1 1 6 3 19 8 2 13 2 7 19 11 11 10 16 3 12 3 1 19 11 16 3 2 6 12 12 3 18 8 16 11 11 1 4 18 8 16 9 6 2 4 5 17 9 7 
13 18 2 19 12 8 3 5 10 0 10 16 18 0 6 12 15 5 15 4 2 9 2 0 17 13 15 14 9 2 7 10 11 3 8 16 10 2 2 9 12 7 10 17 10 16 1 15 17 17 6 16 16 3 8 2 19 4 6 6 10 3 8 18 1 0 7 14 11 13 3 0 4 5 10 3 16 0 11 0 12 14 9 8 9 12 10 3 7 3 10 15 11 
59
14 12 6 8 16 9 17 14 14 11 1 0 15 2 4 17 5 13 14 17 10 12 3 12 4 17 14 1 6 11 7 14 4 11 9 5 10 8 12 11 5 17 8 5 2 3 10 0 12 5 18 8 15 13 5 0 9 6 15 
0 5 6 19 15 11 13 0 16 2 10 5 9 10 19 3 9 7 6 8 4 9 1 17 9 11 6 14 9 17 14 1 17 18 4 12 17 6 9 11 15 10 8 3 17 12 9 18 9 10 15 12 2 3 6 13 18 12 12 
60
7 17 13 14 18 12 0 4 13 13 6 12 10 6 19 8 18 4 13 18 19 0 3 2 0 14 6 8 16 11 15 7 6 10 12 19 17 4 5 11 5 1 15 5 0 6 15 9 4 7 7 8 8 19 9 13 10 11 16 15 
7 4 8 9 3 14 0 19 12 4 11 5 12 9 12 6 16 15 3 14 10 8 10 14 8 6 13 16 1 0 16 14 11 18 14 13 2 5 2 3 12 17 12 11 5 9 4 14 3 0 9 9 1 12 7 17 5 12 16 7 
31
7 9 5 9 3 7 4 8 12 3 19 9 14 5 14 6 10 1 15 3 17 14 12 10 19 6 0 18 17 17 14 
10 6 17 9 18 18 12 0 16 11 2 16 10 3 17 8 0 7 17 3 13 18 17 10 2 4 16 4 7 7 9 
12
12 10 2 3 2 10 3 19 2 11 19 13 
1 13 1 9 16 2 5 13 11 12 13 11 
56
1 9 6 13 17 19 14 0 6 2 0 11 11 15 18 0 12 11 10 17 16 13 16 7 13 1 7 6 8 11 9 3 10 4 10 19 5 11 14 0 10 3 2 19 1 16 3 19 13 14 5 8 3 7 4 6 
5 2 8 7 14 2 0 0 10 9 4 18 11 9 11 9 2 12 1 5 6 12 6 8 12 10 0 4 19 18 19 12 17 11 4 1 13 15 1 17 10 7 14 19 15 7 10 16 5 6 19 18 4 13 19 10 
75
6 13 1 14 2 11 16 2 7 4 12 11 18 0 2 18 11 17 14 8 4 1 8 14 13 16 12 17 7 6 6 3 0 3 9 11 1 13 16 13 6 15 3 2 7 6 14 0 8 0 18 3 5 19 4 4 5 12 3 12 15 8 8 5 1 10 16 4 15 19 9 11 16 3 1 
4 11 18 8 14 12 13 19 7 12 8 4 7 10 12 4 9 12 13 10 4 19 16 19 18 16 11 13 16 18 11 8 3 5 18 19 1 7 13 14 7 3 14 1 3 4 14 11 11 17 9 10 18 18 5 14 19 4 14 14 13 0 17 9 16 0 14 1 16 12 11 12 16 17 14 
54
9 5 6 17 4 11 19 13 6 8 2 4 7 16 0 7 12 13 11 16 11 15 15 15 18 14 7 2 3 15 17 12 6 14 6 17 18 11 2 2 12 18 1 4 8 18 15 4 18 18 3 3 7 15 
1 13 8 14 19 11 12 1 9 4 18 4 7 1 9 1 1 7 2 10 16 12 16 17 3 2 12 18 0 10 10 4 13 2 17 4 11 5 18 0 2 2 16 19 11 7 2 13 18 15 7 3 2 12 
Out #8:
Ankit
Tie
Ankit
Rupam
Rupam
Ankit
Ankit
Rupam
Rupam
Rupam
Ankit
Ankit
Ankit
Rupam
Rupam
Rupam
Rupam
Rupam
Ankit
Tie
Rupam
Ankit
Ankit
Ankit
Ankit
Ankit
Ankit
Rupam
Rupam
Ankit
Rupam
Ankit
Rupam
Rupam
Rupam
Ankit
Ankit
Ankit
Ankit
Rupam
In #9:
50
37
3 23 25 17 22 22 20 11 3 34 19 36 28 43 20 14 27 39 14 43 14 38 10 45 24 1 11 3 1 2 3 7 33 38 4 35 48 
24 13 0 33 49 49 41 24 49 11 22 44 26 11 0 26 45 48 27 34 33 8 16 40 48 47 9 11 4 44 33 41 46 29 39 12 5 
87
16 41 2 37 20 39 6 7 28 37 44 45 43 24 24 10 34 16 35 44 5 3 36 38 10 4 4 42 20 11 7 43 40 27 8 26 18 41 31 15 17 40 47 1 40 10 3 32 30 3 18 11 21 27 15 38 22 47 15 45 39 43 13 23 39 49 19 2 26 17 46 6 46 35 5 29 3 49 37 6 11 35 33 15 27 39 45 
21 37 30 3 23 3 26 39 45 46 12 47 10 13 19 17 43 26 39 49 33 11 43 30 8 44 46 44 49 16 29 12 23 37 47 23 49 27 14 43 32 1 24 46 29 14 21 47 19 49 43 6 45 8 47 36 24 45 35 4 8 10 18 12 12 4 37 38 38 14 44 36 43 30 41 40 25 9 9 13 16 33 19 23 31 4 39 
5
13 43 43 49 14 
17 36 45 38 15 
44
1 39 39 46 7 3 17 8 22 41 13 29 7 40 6 30 17 27 30 7 25 28 31 41 35 7 11 8 14 1 20 21 4 8 47 33 17 30 19 11 32 6 5 15 
13 1 30 5 46 44 38 21 9 41 21 1 8 21 15 4 27 28 16 45 42 23 33 7 21 41 39 19 18 46 37 9 44 5 14 26 36 32 24 36 11 40 16 43 
66
35 39 40 2 9 38 2 39 41 10 35 23 39 7 44 20 2 47 48 3 47 10 29 20 39 45 7 19 9 13 33 11 14 45 43 13 42 3 17 43 2 46 30 39 49 18 35 42 19 32 33 47 39 2 24 11 1 0 20 20 43 46 17 41 26 16 
45 20 32 0 26 24 44 8 3 6 30 24 35 2 32 22 10 20 45 14 26 15 20 7 21 10 46 27 0 47 11 8 37 17 25 6 20 1 1 2 44 7 34 2 32 0 15 10 36 47 21 31 3 34 2 28 5 30 19 15 14 9 47 39 41 45 
21
31 4 35 11 6 5 8 28 20 26 20 36 3 31 12 28 14 7 8 16 8 
16 11 18 16 35 35 1 4 24 20 13 29 48 18 29 48 29 19 37 8 0 
38
46 19 32 34 49 5 32 20 30 33 42 28 20 34 36 48 5 21 41 5 24 21 9 36 2 5 49 5 12 21 33 2 27 45 11 23 13 34 
32 41 17 0 26 9 31 24 18 12 42 30 22 34 15 48 14 16 34 43 0 22 12 30 25 12 32 21 31 24 33 32 19 10 43 22 5 43 
55
12 14 8 41 45 16 49 48 36 2 10 35 17 29 23 40 33 11 8 32 33 13 29 2 41 24 48 38 0 35 6 36 37 9 35 28 19 24 19 12 45 48 46 28 41 31 45 44 30 3 30 28 41 43 5 
2 33 19 4 45 9 40 13 46 40 44 34 27 40 16 31 22 34 14 2 47 41 12 23 2 18 33 34 8 18 11 39 24 19 41 38 5 3 0 17 39 5 2 31 15 23 33 17 11 48 42 44 17 45 49 
77
46 44 15 20 29 38 2 2 23 41 39 48 28 5 31 15 12 20 1 29 31 22 18 5 14 37 12 15 41 44 21 8 29 43 21 48 19 22 13 38 10 36 19 9 41 46 22 46 22 4 1 36 34 41 7 39 40 18 5 41 14 40 14 38 3 21 28 24 30 47 36 48 18 20 42 9 17 
46 7 4 3 1 10 8 35 7 22 26 29 27 47 15 38 14 25 20 20 10 15 10 21 32 17 29 37 38 37 25 36 28 25 1 37 48 43 13 47 48 44 43 11 11 26 33 23 36 13 21 33 44 28 17 3 48 2 0 24 49 29 45 17 15 21 39 3 46 15 36 11 49 31 32 17 41 
36
20 30 26 16 25 27 32 44 17 37 24 35 35 15 17 2 6 32 49 12 43 15 6 46 24 14 31 2 16 20 16 36 7 43 21 47 
47 32 6 23 21 45 47 41 47 27 38 8 39 12 21 45 29 36 36 44 18 44 24 3 26 26 22 1 47 14 29 9 17 2 35 33 
53
24 8 49 41 38 10 45 44 8 17 22 30 0 2 19 32 37 40 44 34 31 13 29 19 30 12 44 40 0 49 32 46 36 24 15 9 49 44 36 29 46 25 47 47 37 21 11 36 5 15 42 13 45 
40 22 46 3 19 3 38 9 2 15 21 36 8 44 23 2 43 38 44 3 3 17 8 39 34 3 47 23 8 21 5 42 31 8 21 11 9 11 37 24 0 16 35 22 49 45 6 17 35 17 35 22 13 
21
20 38 13 34 6 18 45 22 37 14 33 26 27 35 8 11 6 38 4 34 43 
49 47 13 5 24 41 13 15 37 49 34 6 31 3 42 40 26 11 18 35 18 
54
26 25 7 25 6 35 30 36 21 4 46 28 49 2 6 41 15 19 44 5 28 22 1 16 22 23 1 45 46 37 17 24 26 31 9 4 12 18 17 27 9 7 26 44 1 32 43 8 12 21 40 2 5 23 
37 12 43 34 25 4 17 34 0 10 8 45 38 2 22 39 26 11 11 0 12 29 20 13 28 4 9 26 34 0 41 40 32 21 36 29 16 2 30 21 45 40 13 20 39 29 27 48 37 12 16 43 30 20 
20
13 26 4 14 37 49 44 30 11 38 20 23 37 46 23 40 3 22 1 34 
31 42 0 9 16 15 35 26 48 11 0 29 26 48 24 28 26 14 49 23 
55
27 36 39 48 19 15 49 27 40 16 9 26 22 11 21 27 30 12 8 17 41 31 22 29 5 10 46 30 13 0 16 6 46 26 17 18 24 15 44 26 9 37 46 12 11 2 16 16 32 39 6 34 3 13 4 
21 35 25 20 16 33 6 34 27 12 46 19 18 0 43 3 38 26 30 7 10 15 41 12 22 23 24 37 20 19 19 39 6 46 28 39 36 4 36 15 34 9 46 3 41 8 25 14 16 5 15 38 21 27 26 
24
31 38 41 9 32 41 22 46 3 43 28 25 46 20 7 25 21 24 8 16 37 47 32 47 
31 28 16 30 4 14 45 5 23 10 44 12 3 29 34 48 18 8 34 6 13 17 43 36 
6
33 30 7 46 14 19 
3 33 5 3 4 16 
82
20 4 2 12 29 1 22 6 32 5 35 36 6 23 28 1 37 22 38 29 43 41 31 43 46 30 39 1 41 23 10 11 30 2 7 42 1 11 5 24 26 9 14 20 28 9 10 12 25 26 37 34 37 5 48 44 47 46 3 38 30 13 49 28 1 40 13 7 23 11 15 24 37 38 18 19 41 4 3 0 5 24 
38 34 16 24 1 15 16 2 35 40 33 44 15 14 21 24 38 15 5 49 36 38 5 13 18 42 36 1 43 21 25 25 21 6 43 0 16 12 35 26 14 28 36 3 13 49 15 29 33 13 0 36 13 17 37 48 20 47 29 31 46 1 1 20 35 6 22 6 42 23 45 12 0 40 20 40 1 38 31 8 36 4 
7
27 29 12 15 45 21 8 
7 31 14 38 36 18 9 
98
13 0 17 41 13 8 16 49 35 40 27 19 44 43 44 21 20 25 38 9 40 38 9 44 18 31 39 22 17 43 15 22 15 23 45 35 14 32 8 44 22 30 1 19 41 9 18 11 11 9 9 0 43 18 48 28 29 6 0 5 44 16 24 37 8 13 8 42 23 31 38 47 5 28 49 34 12 14 28 9 23 38 35 17 28 15 48 17 1 42 48 34 11 43 21 23 31 49 
36 43 2 42 33 6 43 45 44 34 37 34 13 33 36 46 1 6 48 49 5 31 48 18 22 22 32 37 1 49 30 10 5 24 1 47 43 27 28 30 41 1 13 20 1 48 9 49 32 44 26 23 14 45 2 21 18 40 41 32 30 17 22 47 1 18 18 33 29 40 26 25 36 1 2 31 10 31 48 35 25 21 42 41 15 45 21 16 45 0 21 46 6 25 2 32 39 32 
24
19 10 21 18 14 4 43 13 18 16 5 25 46 11 49 34 10 46 37 37 47 48 24 21 
16 40 20 37 41 5 21 33 9 2 48 49 48 37 14 24 40 0 2 48 46 26 46 48 
63
1 21 23 12 31 18 0 0 16 49 8 30 38 44 49 38 32 43 2 6 46 33 20 16 15 13 47 30 9 29 37 28 41 6 7 20 42 5 27 27 18 25 1 3 33 17 35 31 40 26 40 23 42 13 30 13 47 18 16 29 25 4 43 
36 21 15 9 13 17 47 12 2 14 8 16 2 2 10 16 10 10 45 46 36 38 29 12 14 37 36 45 16 22 36 26 8 30 29 15 32 28 4 12 19 32 0 36 32 22 25 42 15 8 24 20 28 22 31 5 27 7 25 9 18 15 40 
44
0 26 4 28 0 31 25 3 30 43 41 8 9 43 32 3 18 37 2 14 21 29 49 20 30 18 1 46 28 48 3 4 33 12 12 23 24 27 18 40 1 8 25 35 
2 36 29 8 4 38 38 46 21 29 1 11 18 41 10 38 35 8 47 41 0 8 14 23 39 28 4 40 48 32 31 11 32 38 45 20 1 45 8 24 25 9 48 2 
85
44 11 15 43 44 39 16 20 11 31 13 35 29 28 28 28 0 44 6 31 2 20 8 20 28 35 18 5 24 21 29 0 42 39 26 2 16 35 1 30 36 45 27 20 26 11 31 25 0 30 5 47 15 48 33 28 33 20 41 40 49 47 20 9 31 37 9 8 12 28 15 23 35 3 49 19 4 12 37 47 3 16 26 37 22 
9 6 49 9 12 6 6 1 37 15 9 16 6 4 34 20 45 32 28 41 43 24 36 5 17 1 26 21 18 10 31 22 42 19 46 22 8 46 25 49 43 33 27 28 19 5 41 34 25 47 37 36 10 48 20 46 40 34 39 40 38 37 24 16 45 23 23 35 44 16 30 2 44 4 36 43 20 11 24 42 43 15 5 38 35 
48
17 4 21 47 23 28 36 49 10 46 48 24 49 40 16 47 26 11 35 13 30 20 46 46 19 16 39 27 49 34 17 3 1 9 20 34 26 21 10 17 34 34 13 16 44 12 27 34 
47 27 40 18 21 46 43 42 15 47 43 35 8 42 0 43 4 43 11 39 26 15 36 48 43 41 13 24 13 39 24 34 33 46 9 43 36 28 0 10 2 36 0 47 0 9 14 10 
67
30 10 32 17 45 25 49 21 23 37 14 24 0 48 24 43 0 49 30 32 2 47 30 10 6 47 31 49 27 11 48 43 21 26 2 24 46 37 4 33 25 42 14 31 21 36 38 37 1 33 49 34 0 46 37 22 40 47 40 23 16 22 14 17 16 33 23 
2 0 9 46 1 45 11 20 0 39 30 30 2 31 5 49 1 14 42 42 28 12 5 35 4 44 20 33 25 14 15 38 36 30 38 47 38 13 10 40 39 12 13 4 2 35 40 17 45 30 45 11 21 5 30 37 28 40 25 17 12 39 18 36 34 30 8 
71
7 33 12 17 20 30 21 11 32 46 48 37 36 25 41 36 1 2 39 35 46 13 2 34 26 33 24 40 12 19 49 8 25 41 42 5 5 40 16 32 36 35 15 36 28 48 17 2 14 25 1 23 26 32 13 24 49 19 4 33 21 13 13 34 8 6 22 25 18 15 38 
46 21 37 31 16 17 41 13 24 12 41 6 15 28 14 13 3 33 31 21 4 37 37 30 38 44 4 5 6 43 49 37 44 47 46 12 49 21 15 34 21 47 26 31 2 49 48 43 30 27 2 35 19 14 39 23 39 30 34 2 30 34 3 21 5 40 31 1 20 7 23 
53
9 20 8 0 39 9 21 27 41 44 25 12 45 47 13 49 9 5 24 29 45 45 49 6 36 25 35 29 4 6 22 43 5 26 28 2 9 6 20 41 44 7 0 9 28 24 31 26 46 38 26 17 25 
46 0 5 30 23 14 29 9 27 28 38 47 16 3 49 29 40 27 37 12 17 18 46 23 16 10 21 11 8 14 31 34 18 33 14 22 5 19 47 42 36 39 26 7 6 12 7 46 10 40 3 36 4 
11
8 49 44 13 1 7 20 10 34 22 44 
18 28 49 6 20 7 14 39 39 11 18 
33
43 23 44 33 38 40 42 45 21 45 27 0 35 20 21 24 23 11 19 31 25 40 13 6 41 34 19 28 11 16 7 38 46 
25 49 35 31 18 25 21 16 2 45 27 43 25 20 6 40 34 30 2 47 3 32 9 45 21 32 27 34 15 47 37 16 37 
29
13 12 19 38 5 4 22 39 41 27 23 17 13 35 33 0 26 18 12 21 28 39 33 17 20 36 17 11 43 
29 31 15 48 26 44 33 31 47 18 3 38 31 2 35 23 42 11 17 12 25 28 13 13 23 34 28 21 40 
75
33 32 4 9 48 49 46 45 47 24 46 0 20 21 34 8 32 20 25 43 37 25 14 4 0 13 14 18 25 7 4 15 42 29 13 6 13 26 17 5 28 28 34 28 37 9 30 6 35 16 46 37 43 43 40 41 45 45 35 1 41 3 26 11 29 28 33 30 47 7 13 19 27 5 44 
2 8 23 33 47 44 26 2 42 13 28 32 10 7 7 0 39 48 47 27 4 27 16 40 16 43 49 28 17 46 19 2 15 20 30 6 6 27 17 47 11 34 33 47 11 36 30 23 27 0 10 13 0 30 2 21 12 49 36 1 39 26 39 14 10 42 40 11 46 47 49 5 3 19 5 
56
49 40 16 11 3 38 37 1 26 26 20 24 7 12 36 31 38 34 11 28 28 40 9 7 35 15 25 13 0 10 35 27 4 12 15 42 45 44 48 40 28 6 5 22 4 34 18 24 34 22 28 28 2 35 10 3 
49 7 26 20 40 44 31 38 3 16 44 39 4 6 12 36 28 28 40 12 42 48 22 17 17 12 46 13 7 19 15 34 27 1 3 5 1 7 5 11 24 29 36 3 38 24 26 9 31 3 12 43 39 33 3 24 
94
38 24 33 18 45 40 8 6 47 35 39 12 15 8 8 29 27 34 34 43 13 12 42 45 3 14 7 37 18 34 18 35 7 21 27 4 24 24 37 24 34 38 40 27 41 4 11 9 17 18 2 46 37 17 3 38 9 41 14 40 18 20 6 30 44 31 47 5 22 11 22 37 18 38 29 4 29 21 5 48 34 6 46 46 9 37 4 40 43 17 16 38 39 29 
43 38 39 38 3 23 31 7 14 20 39 0 3 20 16 28 40 36 23 48 39 34 34 6 31 17 39 21 2 41 47 16 12 15 3 41 8 3 1 12 39 38 27 37 12 18 42 5 31 36 47 44 28 5 5 29 29 38 1 47 31 1 42 49 46 4 22 19 27 18 33 32 30 48 35 14 5 18 7 1 30 9 36 24 23 2 28 6 44 37 16 31 16 42 
64
19 20 31 16 25 42 14 0 12 20 20 33 35 18 46 14 12 16 0 49 2 31 31 20 15 23 42 7 18 20 44 35 32 9 41 33 45 24 35 4 32 46 38 43 26 12 15 49 44 3 28 20 25 33 25 37 46 11 49 0 49 44 4 37 
49 30 37 30 4 23 10 47 11 18 8 34 47 17 34 17 12 7 40 39 19 42 35 1 23 1 17 38 22 19 42 44 29 45 21 23 48 25 41 12 3 48 44 35 38 7 22 28 25 41 13 48 5 38 48 35 33 45 15 27 49 23 46 9 
15
1 8 46 40 17 16 11 28 29 17 35 1 35 3 26 
18 14 1 28 21 44 11 40 22 31 29 8 20 31 33 
41
23 7 6 30 48 36 7 49 21 42 21 25 48 40 40 8 34 24 47 33 19 16 34 3 38 4 42 25 49 35 13 34 25 41 29 35 32 6 5 34 36 
43 45 32 35 5 5 22 13 18 20 18 38 3 22 14 33 21 13 10 48 41 13 24 23 28 45 0 40 25 17 44 15 21 36 8 13 12 28 2 10 30 
77
28 23 8 10 14 8 40 21 44 31 29 28 10 25 30 1 7 10 26 45 25 46 29 27 25 35 26 24 23 2 41 39 31 17 38 44 21 40 35 3 41 26 9 39 20 33 31 16 48 11 38 0 14 33 18 21 9 27 10 46 0 36 9 13 28 29 17 8 46 18 46 37 40 35 24 26 17 
33 48 10 43 27 41 4 37 34 20 28 37 34 9 24 12 15 0 47 43 16 27 11 8 9 27 46 27 47 34 23 17 28 0 3 46 11 25 1 26 31 7 33 19 24 22 42 14 46 39 3 26 29 12 37 27 29 49 32 43 46 24 40 10 23 6 1 33 11 7 41 31 24 35 40 32 48 
81
19 32 23 14 0 27 26 35 43 44 44 35 35 20 25 22 27 16 48 31 45 10 15 47 49 33 8 45 44 30 41 33 7 2 49 33 39 18 41 8 34 32 48 7 33 12 36 10 18 48 7 37 27 19 40 10 0 31 43 9 33 21 9 3 20 28 8 15 48 49 12 38 22 9 34 6 37 45 28 6 14 
8 12 20 18 32 1 47 18 35 2 46 0 48 6 0 28 46 39 28 12 48 24 12 14 25 19 1 40 31 22 43 7 34 13 27 14 30 3 23 48 38 34 6 47 45 2 45 36 5 36 2 15 20 12 47 45 9 42 38 19 36 15 23 32 32 22 38 44 8 9 4 41 1 10 14 13 27 28 4 35 38 
79
5 29 40 48 32 23 36 5 34 49 31 44 19 7 15 14 40 31 37 5 13 27 10 34 21 41 25 1 2 44 36 27 1 20 49 27 39 28 25 45 23 41 29 16 37 23 14 32 46 46 49 22 2 18 3 31 30 47 26 43 11 20 15 31 39 15 46 46 32 22 37 42 31 38 23 44 47 5 46 
33 18 23 24 29 20 36 47 34 18 19 29 29 7 44 19 4 17 31 42 25 12 5 47 33 22 10 31 14 4 9 23 18 49 0 48 23 36 16 30 1 2 46 42 49 48 22 21 8 32 33 21 46 6 32 6 38 36 24 30 36 17 17 26 43 15 24 26 43 34 40 1 26 24 24 9 29 47 41 
29
46 0 14 20 4 14 7 35 16 18 42 0 4 13 27 3 15 39 24 1 0 41 37 10 35 2 43 1 0 
25 6 1 16 21 42 23 4 23 46 26 34 2 23 1 11 34 33 31 12 13 6 27 38 24 46 49 7 46 
54
32 46 17 49 12 11 20 28 40 0 36 42 23 48 49 32 5 16 46 45 23 9 41 5 8 17 21 7 12 0 20 44 21 14 2 0 47 24 18 24 45 46 38 14 6 28 7 39 32 18 37 25 5 49 
47 25 21 16 40 18 34 36 38 13 36 49 16 3 40 30 24 15 40 37 1 5 27 24 46 22 49 22 8 1 29 15 31 0 41 27 43 26 47 16 11 41 3 46 1 4 29 21 43 43 16 29 12 8 
10
3 43 14 11 23 1 17 45 2 2 
7 16 21 4 30 27 18 47 6 18 
26
20 26 35 37 34 11 2 27 34 4 49 10 0 21 46 36 45 19 49 37 21 32 43 38 22 29 
7 27 36 2 9 12 21 35 30 48 45 11 20 14 0 41 15 11 9 34 8 0 31 16 17 24 
44
26 46 39 27 3 2 28 22 46 40 29 41 22 33 6 25 15 11 35 29 4 38 43 25 40 8 44 42 35 37 17 30 7 11 29 43 11 28 30 49 36 46 27 26 
7 7 32 17 41 22 31 29 47 9 32 49 10 5 43 48 29 42 45 37 4 26 39 37 32 30 18 40 23 48 9 0 23 13 44 12 49 19 21 32 27 25 11 23 
2
31 27 
4 40 
56
40 12 8 32 27 19 8 12 2 9 6 47 29 20 0 27 1 7 35 46 42 40 49 18 19 6 43 49 20 22 33 25 33 44 45 20 30 41 1 7 32 41 28 34 1 32 44 12 14 14 5 38 3 14 1 43 
8 17 12 22 31 26 30 37 18 15 36 5 14 7 0 8 46 11 37 49 1 37 37 28 30 11 48 14 16 21 47 45 5 5 2 21 7 21 1 13 24 0 0 43 26 27 14 22 24 24 21 3 25 46 38 7 
37
44 24 18 8 41 28 31 31 48 36 48 15 6 15 5 38 27 8 8 9 28 3 22 18 14 16 12 48 15 0 38 41 34 30 0 49 12 
42 43 39 27 31 41 24 42 42 45 46 45 27 45 8 39 31 32 41 36 13 27 3 7 7 19 31 6 44 28 47 2 8 43 37 28 13 
65
23 21 2 30 49 40 28 13 37 23 42 41 34 1 48 44 25 40 19 36 41 49 36 25 45 31 22 3 6 29 26 37 38 23 25 49 35 28 5 11 24 5 14 48 28 27 34 27 44 41 1 14 24 26 10 5 9 15 26 15 44 37 10 19 5 
38 28 6 22 14 41 5 41 30 9 19 34 20 37 37 29 11 33 15 36 36 2 30 3 12 47 21 35 40 10 43 48 0 36 33 39 14 43 47 16 27 7 42 33 29 11 20 17 2 37 16 17 9 7 43 24 37 12 36 6 30 0 22 13 34 
50
18 33 2 35 21 4 7 12 41 16 27 23 28 9 36 8 37 38 32 46 30 12 47 49 20 18 10 8 44 9 25 36 12 35 16 28 1 47 12 34 32 9 48 37 39 21 41 32 8 48 
34 33 43 25 21 25 20 24 37 39 47 13 32 46 40 8 6 45 49 44 22 5 35 47 2 40 23 40 33 43 9 46 39 22 21 7 38 11 16 13 41 3 45 6 5 11 29 8 34 23 
Out #9:
Ankit
Ankit
Ankit
Ankit
Rupam
Ankit
Ankit
Rupam
Rupam
Ankit
Rupam
Ankit
Ankit
Rupam
Ankit
Rupam
Rupam
Ankit
Rupam
Rupam
Ankit
Ankit
Ankit
Ankit
Ankit
Rupam
Rupam
Ankit
Rupam
Rupam
Ankit
Ankit
Rupam
Ankit
Ankit
Rupam
Rupam
Rupam
Ankit
Rupam
Ankit
Rupam
Ankit
Rupam
Rupam
Ankit
Ankit
Rupam
Ankit
Ankit
In #10:
100
55
49 36 43 48 12 13 47 47 7 20 26 16 49 3 32 13 43 1 28 17 41 24 33 38 46 35 16 23 17 40 4 10 29 41 28 22 41 39 26 21 39 22 43 49 13 9 13 4 25 44 31 27 35 7 24 
46 46 42 39 13 9 44 43 22 21 11 38 1 4 0 25 0 18 16 42 30 44 20 4 9 38 11 23 14 1 46 4 27 40 1 31 8 5 48 27 47 16 30 40 3 13 32 18 28 30 41 8 49 22 40 
19
30 47 25 15 30 3 32 8 13 19 33 36 46 31 44 10 47 27 37 
49 19 14 34 19 26 3 32 30 17 48 36 35 37 17 7 10 13 43 
3
42 8 15 
28 30 15 
65
14 31 33 3 39 23 11 28 8 0 16 39 16 30 1 7 14 13 6 12 4 8 18 5 48 40 32 24 23 15 15 36 48 16 21 34 35 30 33 46 35 8 40 3 11 38 38 47 41 0 30 2 19 12 41 4 35 14 49 33 28 24 26 18 19 
26 7 2 31 41 46 47 31 49 0 9 41 43 38 5 46 20 7 26 9 48 44 7 31 43 31 42 18 13 21 14 45 22 25 14 22 33 11 2 23 19 16 39 8 16 2 18 7 47 28 45 20 31 8 46 20 34 5 32 22 15 3 26 9 4 
19
14 0 9 29 43 29 38 45 34 40 28 25 46 41 10 9 40 21 43 
8 22 2 49 31 43 13 27 29 33 25 38 15 43 42 31 36 46 42 
36
46 45 9 47 10 6 29 46 17 45 44 42 2 6 13 7 40 11 42 18 2 31 28 2 42 20 33 27 4 14 33 16 26 22 31 6 
13 12 8 24 21 35 45 8 34 34 4 39 28 36 12 7 23 41 4 30 36 24 42 9 34 38 47 15 18 37 23 13 36 47 37 33 
40
32 4 27 37 12 25 23 46 0 11 21 1 0 4 31 25 18 42 30 35 4 5 35 3 6 34 1 3 39 18 16 5 29 37 29 35 40 30 41 6 
35 43 14 2 11 40 29 7 26 12 26 43 49 20 17 36 4 13 9 40 48 22 40 49 38 36 41 11 27 36 38 22 21 36 10 37 25 24 38 8 
96
47 14 3 10 15 33 49 12 19 24 26 14 44 4 40 17 40 47 27 47 14 32 41 11 43 0 28 24 20 9 26 31 5 35 34 43 2 13 47 15 36 46 47 38 3 26 14 7 30 25 49 7 48 43 18 38 27 9 21 37 35 3 27 19 4 22 32 32 30 5 14 9 9 47 49 20 44 42 4 33 16 1 14 18 26 30 25 35 32 24 22 33 27 10 9 25 
29 14 40 39 30 29 13 15 28 27 6 21 14 32 19 31 7 13 1 21 8 37 44 32 14 38 30 33 33 26 26 26 1 0 32 11 1 45 38 38 27 16 31 28 27 0 7 17 12 36 28 42 32 26 31 46 33 38 27 35 22 37 28 24 12 44 19 5 3 27 34 6 27 28 11 23 49 47 42 30 34 15 15 24 25 29 19 10 16 30 4 5 43 41 29 10 
4
37 20 6 36 
49 40 3 36 
94
24 37 21 13 23 0 6 6 25 4 8 34 23 47 35 32 47 20 40 41 35 3 10 42 11 0 19 14 10 35 29 37 10 1 36 22 15 25 43 31 46 44 5 28 22 12 15 12 2 19 14 18 9 41 25 45 32 5 34 9 32 32 39 26 17 29 12 8 44 16 42 8 31 23 2 31 34 27 28 46 46 5 49 0 45 15 41 46 4 26 12 9 7 25 
42 3 13 25 8 15 13 32 15 29 25 39 45 37 31 7 3 49 22 26 3 24 22 26 1 41 47 33 21 18 48 27 45 29 20 1 40 3 23 25 41 29 29 48 19 40 32 24 39 4 16 12 39 36 15 21 25 41 30 3 48 21 10 16 29 29 7 17 7 33 16 22 46 41 23 24 19 25 38 15 37 44 30 22 24 42 44 47 1 0 37 43 21 3 
86
44 23 41 19 15 29 23 20 16 44 7 7 43 6 44 5 41 33 46 24 37 8 3 36 29 43 34 46 6 17 17 21 32 19 3 21 29 38 28 28 26 19 15 28 9 47 38 17 25 21 38 22 10 27 13 41 30 9 24 45 15 28 10 30 3 47 19 19 25 31 43 45 47 34 5 7 36 12 28 2 4 27 12 48 10 47 
33 40 41 10 1 49 17 49 29 2 34 2 0 43 8 26 44 22 27 41 16 37 43 33 36 16 42 30 16 6 43 4 14 42 32 23 6 24 14 5 24 44 5 22 18 37 10 39 44 11 7 11 48 7 14 41 6 13 9 17 7 39 22 7 10 40 25 9 37 33 28 44 45 38 20 6 32 5 38 6 4 5 7 43 6 7 
42
26 11 32 18 48 13 11 43 39 43 8 2 4 30 39 14 5 29 23 7 23 42 5 22 2 21 39 48 17 34 33 48 5 36 48 17 9 9 39 33 12 43 
10 42 15 17 12 44 27 45 11 7 13 36 3 34 5 47 9 38 36 38 3 33 45 7 9 46 48 37 7 2 44 4 42 21 30 22 40 39 35 9 30 47 
44
39 35 16 27 45 19 17 31 22 35 33 48 12 9 29 18 14 14 34 21 44 18 10 16 34 35 24 40 13 36 33 38 13 34 36 14 2 38 8 44 21 33 0 49 
39 22 40 49 23 3 39 33 12 41 45 47 49 18 7 40 15 1 26 39 18 8 32 16 13 37 10 29 9 11 42 39 48 33 42 11 7 27 14 42 25 10 43 6 
28
35 4 20 37 5 22 7 0 35 42 35 42 45 16 32 16 17 9 18 49 34 19 34 10 1 18 18 25 
35 8 13 39 48 39 3 37 15 13 39 44 12 7 5 4 29 0 4 39 45 24 7 12 14 33 46 36 
34
13 10 11 3 29 34 30 48 8 30 33 37 19 8 29 9 16 33 28 44 7 8 12 3 38 22 36 6 14 3 6 37 21 18 
37 17 30 3 31 17 43 32 37 49 27 42 3 23 20 23 16 27 7 11 27 48 25 23 35 22 13 49 47 4 40 2 18 17 
57
20 24 25 22 30 5 20 39 44 45 44 28 8 41 28 24 20 41 39 37 3 13 10 5 38 35 0 31 12 9 3 37 14 42 45 1 0 21 19 15 25 38 31 23 29 19 0 19 8 33 16 43 0 43 9 10 26 
13 14 4 23 37 49 29 19 22 1 43 40 18 44 46 25 14 12 43 23 46 24 48 24 38 16 12 49 3 28 29 23 37 11 0 2 45 39 33 48 19 6 34 45 41 13 36 14 47 47 42 3 27 1 25 15 40 
95
3 16 29 47 25 7 44 10 32 6 2 42 47 43 42 21 10 32 46 16 9 34 36 9 7 19 22 41 17 2 30 38 47 19 18 40 5 25 27 40 29 39 36 2 49 29 19 36 2 9 27 49 17 1 27 30 16 38 42 37 21 44 6 13 24 9 45 28 8 35 35 32 42 6 23 39 47 34 2 42 0 22 26 36 11 36 24 19 9 18 4 30 34 42 48 
10 14 44 20 9 13 29 39 26 18 38 25 21 38 40 12 24 13 9 27 20 5 40 29 45 13 11 16 37 32 1 31 36 6 20 1 13 23 16 12 18 10 2 39 14 22 33 16 13 46 20 17 7 0 21 49 4 1 37 21 24 36 35 30 35 25 35 34 25 42 8 46 11 42 5 44 15 23 6 19 19 45 5 0 1 12 21 1 34 42 8 3 49 47 7 
17
13 40 34 16 7 16 19 4 16 22 30 5 34 9 49 3 21 
34 35 28 24 16 48 41 36 28 16 42 28 14 20 49 5 20 
47
0 35 9 9 0 48 8 42 31 33 13 21 31 49 1 24 31 20 19 34 2 36 7 43 26 41 38 48 31 35 12 24 18 18 14 26 0 34 47 46 21 1 29 38 4 7 8 
28 29 1 21 11 1 31 12 21 48 23 39 39 40 11 22 40 47 43 0 5 8 18 32 11 40 34 16 25 39 48 44 21 45 44 21 15 47 1 15 44 30 42 28 39 28 15 
34
33 9 25 10 34 49 38 47 12 38 47 47 3 22 36 2 14 17 37 1 13 18 24 33 42 3 13 21 45 1 15 29 36 43 
46 49 6 33 41 32 25 25 4 8 40 41 11 33 45 47 32 39 4 43 2 47 40 33 6 34 45 45 47 11 33 14 18 2 
59
19 27 7 42 36 29 35 41 19 46 36 2 14 14 12 16 25 11 20 15 32 4 47 43 45 36 37 39 37 33 14 43 21 31 0 9 45 12 25 31 9 33 24 17 29 1 0 14 17 7 26 14 37 0 46 27 28 4 21 
45 40 14 18 12 19 42 8 45 11 13 2 45 45 36 34 3 1 33 17 42 34 12 8 24 33 37 6 14 28 2 49 8 13 13 12 25 13 36 48 43 28 17 39 6 47 27 1 28 45 36 3 38 7 10 9 28 6 19 
61
16 38 25 19 36 2 11 3 47 37 5 49 4 6 46 49 49 45 31 6 44 18 42 8 31 23 45 38 9 46 10 14 15 8 9 26 16 23 39 13 31 12 15 16 0 22 6 32 36 39 20 28 40 37 5 13 2 41 48 22 18 
10 47 27 16 48 16 8 40 2 15 9 25 24 4 13 4 21 11 22 35 10 46 21 48 28 21 6 39 16 21 35 30 38 20 18 9 38 11 37 47 19 36 4 34 29 35 29 37 26 49 3 45 32 25 48 32 20 18 42 22 23 
28
3 32 39 26 33 9 5 40 25 27 47 36 43 18 27 3 47 45 19 44 36 33 36 38 45 5 38 44 
43 15 21 43 34 34 33 7 8 12 48 16 3 46 31 27 43 20 37 49 39 3 36 15 37 22 1 12 
45
3 1 40 10 40 4 29 37 10 13 1 32 38 36 11 48 12 19 11 13 40 10 10 32 2 34 26 19 13 12 23 27 36 27 27 27 24 30 3 49 42 45 32 46 46 
0 27 34 21 30 19 24 23 25 32 11 12 5 43 22 17 12 17 6 8 23 16 46 29 13 46 34 10 27 38 25 16 17 29 16 2 29 14 24 34 22 4 9 33 48 
31
3 22 2 30 36 22 15 2 7 10 12 14 30 3 28 11 3 15 40 38 6 36 39 19 19 4 10 9 25 32 16 
17 44 47 6 9 38 49 20 22 3 9 0 34 2 22 42 46 36 29 45 12 48 22 27 4 40 38 38 17 11 35 
33
3 9 31 42 27 47 3 32 41 48 37 26 21 48 21 15 24 18 43 46 33 45 37 20 35 39 4 36 0 43 8 21 13 
18 38 42 30 19 0 26 16 38 43 10 16 30 29 45 27 26 8 42 46 19 11 2 35 4 48 34 18 12 42 31 40 19 
19
45 32 40 9 3 8 24 9 26 44 20 25 25 28 4 48 9 12 29 
16 48 20 0 28 19 35 7 29 14 40 12 32 1 38 42 41 5 45 
89
47 20 20 10 46 46 42 33 8 27 9 47 21 35 4 32 24 13 43 37 23 13 29 25 42 22 47 23 31 24 33 6 8 49 27 25 7 22 43 34 15 35 22 10 33 11 21 41 49 7 12 26 48 28 21 5 5 27 43 49 45 2 29 36 29 33 2 40 21 36 48 4 21 41 39 35 30 44 7 33 41 26 42 32 24 11 22 46 27 
39 45 40 14 26 4 21 28 1 32 30 8 4 48 28 9 4 17 36 21 49 41 2 39 22 14 6 28 28 48 45 47 11 24 34 24 29 10 3 44 38 31 27 36 44 49 10 38 13 0 15 31 49 20 29 11 13 22 21 10 43 40 16 25 43 10 42 38 26 44 2 43 24 46 15 24 49 25 43 46 12 17 43 13 17 42 44 28 9 
62
11 38 30 41 4 27 30 13 20 41 18 42 8 6 9 4 23 26 4 15 7 16 32 44 24 24 17 20 9 30 31 18 29 45 9 22 8 23 43 5 18 41 1 28 4 47 32 5 45 49 33 43 21 42 20 22 21 24 24 39 30 46 
18 9 36 12 10 3 18 9 40 46 31 10 25 42 33 29 12 46 32 0 20 19 36 35 32 6 1 2 0 30 18 7 41 18 25 22 43 22 31 21 41 24 3 8 9 0 40 18 6 26 6 26 4 40 7 31 0 37 38 36 6 40 
51
14 34 48 45 40 10 35 46 5 12 14 46 7 1 40 31 1 35 30 33 22 14 48 27 33 40 29 8 9 22 12 8 36 15 4 31 38 18 24 8 32 8 10 4 8 20 42 19 11 7 48 
10 36 33 3 30 2 5 21 4 22 19 13 27 47 21 46 32 25 44 43 5 30 20 32 39 10 44 18 34 8 19 27 45 31 1 49 40 48 22 33 32 12 27 28 30 29 30 29 47 40 12 
80
48 30 49 14 27 44 5 6 29 19 11 45 22 26 1 21 46 7 23 38 24 40 42 30 33 49 24 1 11 8 17 43 1 13 15 8 35 35 46 11 2 24 12 31 9 2 7 32 21 23 43 9 18 49 48 2 46 22 45 21 40 11 42 20 32 29 15 32 41 29 41 10 4 29 29 29 35 38 40 24 
8 46 25 15 37 2 0 13 29 48 17 14 21 14 5 3 47 47 22 15 34 17 17 44 49 40 45 19 6 7 8 42 38 17 12 34 32 27 46 41 49 47 15 24 26 8 19 2 42 28 1 48 32 5 5 20 16 12 8 15 39 38 0 44 9 10 44 38 16 4 44 47 21 38 8 21 3 47 5 23 
5
30 0 42 15 46 
48 26 36 25 31 
6
26 39 45 0 6 1 
27 3 21 3 20 25 
75
48 43 43 26 32 30 7 17 10 15 45 11 27 30 38 42 12 12 19 32 5 47 35 28 23 25 29 43 7 26 14 7 8 41 14 3 27 49 37 47 40 27 7 3 2 11 14 46 42 6 43 45 47 46 1 36 29 19 16 15 40 42 31 2 19 35 16 42 28 41 16 0 37 19 45 
10 42 15 30 31 12 12 28 26 45 26 27 21 30 25 26 18 25 29 9 6 46 30 43 27 4 48 22 5 32 1 4 5 35 29 25 6 40 47 21 42 43 35 36 8 31 8 11 38 32 39 28 10 10 49 4 31 21 24 14 39 44 27 44 5 6 47 41 15 2 6 19 26 28 18 
39
43 41 31 30 33 29 26 49 36 31 33 26 11 9 47 10 26 12 48 9 10 10 34 40 6 15 19 16 35 22 39 21 6 37 36 29 1 29 36 
17 46 5 42 12 7 18 28 6 13 9 16 39 38 32 39 46 24 5 19 2 0 0 42 32 10 0 2 30 27 0 5 8 8 17 31 36 29 42 
12
46 20 20 28 13 44 2 4 2 6 41 12 
3 24 12 48 45 0 5 18 23 10 33 2 
23
6 6 21 38 41 38 0 9 36 45 22 29 29 40 32 40 20 34 12 41 36 29 27 
9 4 4 46 35 16 24 32 9 1 25 34 45 35 6 6 5 22 27 47 34 21 4 
6
16 3 8 23 1 0 
46 26 38 36 15 20 
42
20 35 25 29 0 6 2 48 5 36 15 18 16 1 44 29 5 39 46 17 49 46 47 34 48 41 32 39 34 19 43 34 35 43 0 38 20 36 18 23 44 48 
39 25 18 0 31 46 42 41 5 20 32 0 10 41 5 39 33 31 48 16 31 13 46 26 4 26 25 29 42 34 16 4 17 0 11 13 22 28 26 10 24 46 
97
25 6 29 5 45 19 36 4 12 46 28 1 45 2 11 22 25 11 46 7 30 32 38 12 34 37 12 25 18 47 38 42 34 36 11 38 24 35 18 48 38 8 42 19 13 11 26 14 23 11 20 8 18 35 8 49 10 47 38 13 30 24 48 11 36 48 3 13 38 3 3 49 24 27 48 44 0 26 42 44 44 21 20 0 36 22 49 36 19 33 39 19 49 48 16 31 13 
48 33 12 22 38 25 40 48 49 24 27 28 33 44 48 29 46 29 31 9 32 10 48 44 36 8 12 41 0 25 16 9 42 36 3 22 43 40 29 48 2 49 27 27 23 42 28 49 28 24 0 48 48 45 5 26 37 18 48 29 9 13 7 9 13 26 8 11 41 16 21 39 36 47 42 10 22 33 17 40 14 46 32 30 46 32 28 16 20 46 5 19 33 33 11 9 38 
76
40 1 36 8 19 25 17 45 19 10 30 25 41 7 31 21 16 19 42 27 2 30 45 23 14 31 12 14 10 48 43 28 21 16 8 26 6 7 49 36 46 24 34 36 45 27 20 28 1 42 0 12 11 41 8 20 21 8 23 10 19 22 41 47 25 39 33 21 34 0 44 40 45 18 5 8 
6 43 10 8 48 43 43 48 43 0 5 35 24 20 22 47 45 25 18 24 8 1 8 20 12 25 44 5 41 25 19 14 38 36 28 23 35 7 20 35 41 24 42 12 37 4 26 31 23 0 8 42 2 42 45 42 16 38 16 49 47 26 28 23 22 44 43 2 44 3 22 19 14 14 13 22 
71
13 27 9 32 30 8 39 30 10 12 9 31 47 37 27 43 36 6 29 49 15 8 48 17 20 1 2 6 45 31 10 47 21 43 13 14 24 10 43 0 15 23 26 43 5 3 39 47 36 3 3 10 14 16 38 44 22 22 19 37 9 8 3 30 10 38 45 25 29 11 6 
36 26 15 44 15 4 6 48 29 41 40 44 31 1 22 22 43 0 16 11 36 23 31 47 42 7 9 15 15 6 10 46 32 27 34 27 27 26 49 21 30 9 40 29 10 5 13 35 3 9 7 0 26 38 34 19 12 14 14 0 26 30 39 8 32 21 18 33 4 29 40 
35
10 15 42 14 4 49 46 23 49 48 26 34 40 36 35 0 40 7 29 15 22 4 3 37 21 0 23 24 46 0 32 48 0 48 38 
6 31 41 7 22 14 45 44 12 9 20 42 35 40 30 29 39 41 45 48 23 16 21 4 45 40 43 21 34 45 5 38 11 48 5 
17
8 20 29 1 26 0 5 24 5 21 15 6 9 2 9 37 34 
39 1 1 19 19 21 42 35 12 22 38 40 2 6 4 28 17 
63
15 37 4 19 40 31 33 6 43 39 19 27 14 22 44 40 12 10 49 34 36 31 27 48 1 22 16 27 6 48 21 31 38 32 43 29 36 49 33 16 10 28 49 47 0 48 49 24 20 26 28 45 43 35 17 0 21 16 34 10 45 16 17 
37 14 3 18 3 11 31 34 24 8 7 45 43 9 9 11 12 47 33 11 43 32 34 9 28 24 20 25 34 34 47 43 10 15 17 22 2 2 37 11 27 21 1 9 11 11 12 9 10 18 18 39 33 34 45 46 17 2 3 15 15 19 47 
74
14 19 44 39 45 30 41 28 19 28 35 14 22 31 14 33 41 44 34 49 24 36 19 21 39 34 26 13 35 30 17 10 25 1 44 21 42 5 1 39 10 9 0 45 34 45 20 4 36 26 8 12 4 45 20 32 44 37 37 31 45 8 0 10 33 16 3 13 14 48 22 3 0 37 
11 0 44 42 26 36 9 46 22 10 24 15 4 23 18 40 6 3 30 27 4 8 41 30 44 19 19 3 30 43 46 32 15 30 48 26 19 38 36 24 28 27 19 5 9 17 43 8 41 32 33 15 42 36 15 33 16 23 47 6 40 16 48 23 47 41 30 30 45 5 21 36 44 34 
33
9 37 35 34 11 34 30 37 10 20 42 37 42 11 10 7 10 15 41 31 48 2 36 44 17 44 0 36 45 13 32 42 25 
42 14 4 28 18 9 29 5 44 18 17 27 41 40 36 47 24 14 22 18 26 45 29 45 6 8 5 14 39 38 30 39 25 
9
48 9 44 15 26 41 19 43 42 
38 43 36 49 47 45 32 25 13 
61
12 8 14 43 30 33 25 33 16 16 20 12 11 20 47 21 6 11 23 48 25 25 38 18 7 49 34 29 11 27 14 49 47 28 2 21 16 36 14 44 31 38 19 19 7 45 10 15 18 43 18 37 19 25 16 29 28 32 40 7 23 
21 33 36 43 26 45 24 17 32 2 36 17 12 16 34 8 9 19 31 20 3 28 5 21 23 2 32 13 9 22 46 10 49 15 1 8 31 32 18 28 25 9 33 24 0 24 38 9 29 42 23 48 6 46 1 34 42 3 10 35 16 
73
42 9 16 20 30 24 42 28 15 20 21 5 28 35 20 1 16 0 48 6 43 38 7 23 20 13 17 37 5 38 43 8 31 30 38 20 45 11 44 34 6 17 40 39 49 43 12 22 31 1 2 18 35 37 14 26 16 24 34 30 10 40 9 25 16 39 3 46 17 20 7 24 20 
27 15 25 10 40 24 4 27 35 15 40 10 4 42 27 23 24 5 38 23 48 42 25 37 15 43 26 18 21 45 46 17 23 34 34 32 6 5 13 49 31 39 2 27 17 6 25 30 9 36 2 35 13 46 20 35 28 24 47 41 32 40 25 41 4 11 25 33 14 11 11 47 7 
20
32 30 3 45 41 18 19 0 29 14 14 5 26 17 9 44 3 16 15 34 
45 15 43 24 13 11 21 28 32 42 13 39 10 12 23 26 38 27 9 0 
23
19 23 45 27 33 23 6 40 3 18 23 20 25 41 24 6 34 29 18 24 26 14 41 
47 7 6 35 39 30 42 37 27 24 12 42 14 35 12 12 48 15 13 1 22 42 18 
62
13 0 47 26 44 34 20 24 30 4 16 18 30 5 34 19 20 24 41 46 26 48 24 12 47 3 14 28 20 14 21 39 5 29 35 13 24 20 21 29 34 24 4 5 20 4 25 30 25 44 39 26 26 20 2 38 27 16 46 47 23 39 
10 34 15 30 36 17 22 8 7 29 3 27 4 1 13 33 32 0 6 6 19 17 10 0 17 22 4 8 30 42 20 18 41 23 35 24 24 19 45 15 41 48 1 6 41 15 41 42 15 38 6 45 15 23 37 5 18 33 45 18 21 25 
27
13 43 31 13 32 12 16 41 40 27 21 32 49 43 11 29 4 21 27 22 30 34 19 24 38 36 10 
1 29 40 0 46 22 16 25 24 20 33 34 30 27 22 4 45 6 49 3 8 18 40 10 11 7 30 
27
40 7 35 19 38 32 31 8 36 2 15 29 2 32 36 18 27 16 25 38 2 28 45 7 28 43 9 
49 21 41 20 30 43 25 32 23 34 45 26 41 45 26 16 30 44 5 38 0 48 43 21 8 35 41 
38
32 46 18 40 43 17 30 21 49 5 42 44 7 48 31 15 22 5 16 25 12 12 32 23 14 46 21 38 33 30 12 16 10 41 43 38 30 43 
44 23 20 23 41 4 48 45 25 24 0 19 15 7 8 18 45 48 36 2 13 39 19 44 18 49 41 22 6 44 24 0 34 37 22 17 23 47 
28
9 33 48 25 46 41 41 1 23 47 30 36 16 26 4 11 19 5 15 40 8 23 33 47 47 14 31 16 
30 17 14 33 14 28 7 20 41 30 6 45 41 2 16 42 43 3 17 36 21 22 13 33 5 25 1 38 
9
10 9 36 19 1 21 47 2 17 
12 9 4 36 38 29 7 0 48 
54
44 25 26 34 21 8 34 20 39 32 0 16 3 43 40 44 23 34 41 31 41 47 22 19 46 48 26 32 36 45 43 41 46 3 46 16 46 38 9 31 6 11 41 44 15 48 14 14 31 24 16 13 17 24 
48 48 47 40 23 48 32 2 5 14 35 32 28 32 25 3 9 20 36 17 7 5 43 6 28 24 32 30 32 9 43 48 27 14 4 23 0 34 1 32 44 37 14 36 35 2 27 47 6 34 36 49 23 6 
53
6 9 7 48 12 12 37 25 6 22 46 12 13 47 37 42 30 49 27 45 7 4 14 16 43 19 36 41 41 42 25 36 0 7 26 17 32 17 12 7 30 7 29 1 37 39 34 4 1 25 45 26 33 
44 31 40 30 27 36 22 49 23 33 30 1 25 8 10 4 16 25 28 4 41 23 22 41 49 36 43 27 18 12 30 41 19 43 31 11 33 11 12 18 9 2 28 15 46 22 9 48 2 28 44 29 30 
26
2 32 36 4 34 22 3 41 32 41 13 9 40 16 42 34 13 44 40 25 5 4 26 45 7 15 
4 15 3 39 29 4 18 31 32 33 43 12 17 21 27 10 41 19 18 1 19 32 44 35 30 2 
59
26 12 25 38 44 25 43 38 21 12 9 6 8 46 27 5 47 19 12 5 47 42 21 18 20 25 14 1 12 4 10 7 19 22 36 2 29 34 30 35 24 24 6 28 32 23 48 13 7 34 23 46 16 20 49 45 26 36 33 
15 3 46 2 43 49 45 4 43 30 24 41 7 9 27 21 12 17 14 16 48 41 12 21 39 15 28 32 43 15 49 37 33 10 34 0 34 17 4 28 23 43 47 37 9 41 4 5 10 3 44 11 30 11 16 37 14 25 19 
2
26 5 
23 47 
25
37 24 17 29 47 38 15 12 15 33 34 22 3 38 10 44 19 37 16 37 24 4 40 31 2 
11 13 18 15 37 13 43 46 41 24 33 17 23 20 8 16 42 22 14 35 29 14 0 3 43 
75
37 11 25 46 31 15 1 40 19 43 43 19 28 38 49 44 37 5 6 10 6 42 41 12 47 12 47 29 15 39 22 40 41 49 8 30 3 4 12 16 38 10 27 32 30 9 20 11 49 39 17 12 41 21 37 5 35 4 1 8 2 2 22 10 46 37 32 25 49 9 13 7 20 32 10 
38 4 38 17 18 32 25 20 44 3 44 9 17 35 44 5 30 33 23 7 12 6 1 3 22 14 8 11 43 18 35 28 32 10 44 17 30 16 8 17 26 8 7 2 41 3 5 8 21 5 25 4 44 6 24 48 17 27 13 37 26 43 3 13 8 22 20 45 20 33 16 29 11 42 3 
82
10 46 26 42 25 28 47 15 40 45 14 30 37 15 26 37 27 29 43 0 8 9 19 17 23 33 23 7 6 35 46 46 29 45 35 41 45 0 40 18 5 41 22 4 11 37 48 43 36 17 34 42 27 48 25 45 12 36 8 19 9 20 30 10 42 29 5 0 4 48 25 10 6 11 6 27 23 49 16 29 37 29 
27 28 31 41 32 4 49 48 22 16 24 16 2 38 17 8 40 37 26 0 26 38 15 36 29 42 30 0 18 1 5 1 27 33 27 25 32 0 16 22 24 18 5 43 0 21 41 42 13 45 27 6 32 2 28 10 9 3 17 18 7 34 12 44 14 29 45 12 27 35 45 41 25 46 43 11 17 24 29 43 23 47 
41
26 24 1 32 15 31 6 49 41 42 49 28 1 7 6 42 28 19 25 36 22 31 46 41 28 33 40 22 42 12 30 14 31 17 42 41 9 31 4 19 20 
39 36 48 23 35 47 17 30 23 38 42 16 16 46 36 21 28 34 45 1 12 5 35 1 4 39 28 16 4 17 48 16 13 46 13 38 30 14 14 16 28 
63
25 24 28 46 41 7 20 4 8 7 47 10 26 46 41 16 28 46 13 49 20 17 6 27 2 22 20 44 9 11 36 12 19 12 5 49 29 8 27 28 42 3 17 14 37 35 7 23 31 31 7 22 10 25 22 12 30 37 37 11 23 28 28 
42 19 14 35 28 17 30 25 17 22 45 20 25 42 29 1 19 14 9 8 24 2 45 6 2 26 5 37 41 44 12 49 48 18 36 20 11 9 43 34 26 25 35 11 6 32 41 30 8 34 16 5 13 10 2 22 22 49 26 33 24 32 10 
11
0 15 8 39 13 31 34 39 0 44 31 
45 26 33 2 5 32 32 46 7 11 4 
96
7 43 12 33 4 47 0 39 39 14 43 28 36 28 43 39 28 31 17 38 4 29 15 33 6 10 35 29 5 0 32 26 46 25 23 28 30 31 23 30 5 3 45 14 34 33 43 0 42 15 31 29 10 26 18 0 11 37 48 40 7 39 4 34 46 42 47 23 31 20 24 3 27 48 27 14 3 4 2 26 21 34 37 41 47 4 13 28 7 7 22 29 33 6 18 9 
28 7 18 0 1 32 26 27 32 33 38 49 27 49 9 14 35 49 9 28 14 14 2 37 36 46 45 28 45 42 22 33 4 15 17 1 6 39 24 25 44 42 2 8 1 21 30 8 0 31 18 26 39 8 27 41 9 25 28 37 1 48 11 8 6 9 27 11 37 1 32 8 25 40 34 49 8 6 24 27 30 32 25 35 44 48 19 4 13 15 47 34 13 8 36 17 
57
5 31 5 45 38 1 38 9 20 21 32 19 2 40 43 25 32 45 38 30 17 5 29 30 13 42 16 18 7 31 16 23 3 8 17 26 4 45 49 40 15 25 3 4 11 48 40 6 39 1 4 0 46 10 46 35 22 
33 5 22 14 42 34 39 20 6 20 34 0 1 16 7 47 9 34 47 27 23 33 36 38 5 28 32 25 5 26 32 31 37 18 13 47 22 4 17 20 37 49 34 22 23 35 20 49 2 23 42 35 13 32 16 26 5 
61
20 20 43 8 45 48 40 17 6 2 32 19 15 10 42 4 26 11 6 46 13 38 1 16 32 1 16 39 18 21 24 18 43 37 2 17 6 11 30 9 29 7 44 1 40 11 9 24 32 33 24 18 32 42 40 15 47 40 35 32 12 
13 6 3 12 14 19 17 28 15 45 6 31 23 24 2 21 3 22 0 7 40 3 46 40 19 36 24 9 5 37 0 10 32 9 47 2 1 34 38 33 20 18 40 3 25 31 25 31 47 48 2 0 14 49 36 8 38 34 4 28 9 
71
18 21 14 45 36 43 49 34 20 38 12 40 24 17 17 43 36 35 3 25 27 21 9 39 42 7 45 24 7 29 3 47 20 45 6 15 44 49 22 2 39 49 19 20 47 8 12 33 11 37 24 44 26 15 14 2 16 28 3 10 23 19 24 29 9 43 6 1 44 40 44 
33 35 28 27 25 27 14 20 33 34 31 46 41 10 35 0 38 27 47 30 38 23 17 18 3 14 41 45 35 10 30 48 35 34 13 1 35 45 23 25 10 14 10 47 22 5 40 29 20 39 34 19 1 21 11 29 22 24 21 17 34 29 29 20 15 13 15 40 44 44 47 
92
8 41 17 5 0 16 23 29 46 18 33 33 8 0 9 38 21 30 47 9 0 28 35 20 33 3 12 25 21 13 0 33 18 48 0 9 28 13 19 25 30 20 18 46 18 40 30 31 34 1 12 43 37 4 17 49 0 36 38 26 7 42 2 10 28 47 23 16 19 10 17 38 23 5 14 1 26 6 28 15 7 31 41 30 10 41 14 25 4 21 0 38 
27 31 46 26 44 6 25 10 11 47 36 16 17 5 32 49 45 46 39 19 41 16 43 34 25 6 23 29 32 23 39 42 25 40 34 36 12 45 43 12 11 4 48 13 17 3 9 29 23 5 6 19 44 26 28 37 12 44 9 7 28 9 16 49 23 36 29 13 28 31 35 11 22 36 36 17 23 15 38 9 5 49 11 47 27 26 40 34 34 37 48 39 
4
17 27 9 49 
32 40 37 12 
97
18 16 30 15 9 36 6 26 42 0 15 4 5 5 9 17 45 0 16 10 2 36 9 6 19 32 28 19 38 34 21 20 47 43 23 33 7 10 23 25 8 2 39 35 31 28 22 48 12 44 28 27 1 5 39 25 12 10 20 31 19 14 49 38 18 29 11 37 15 21 44 3 25 9 25 3 4 40 25 45 43 26 32 27 1 49 44 6 16 49 18 42 44 41 7 32 46 
45 42 28 41 5 3 15 48 30 33 31 28 18 39 36 8 9 49 44 22 5 9 28 2 43 0 11 30 23 13 49 24 24 32 42 41 26 26 16 30 32 43 46 25 17 32 19 4 13 7 4 18 38 1 37 3 35 23 3 21 31 44 25 41 7 0 32 29 37 30 46 31 32 10 9 43 15 32 27 5 17 4 44 0 37 22 24 28 14 3 45 13 7 3 35 1 38 
74
29 0 31 45 22 37 10 41 13 31 24 32 22 45 26 23 36 21 43 11 2 4 22 22 20 34 34 37 22 0 15 47 9 2 47 14 23 28 28 46 16 49 48 38 25 12 26 40 16 41 0 3 32 28 42 7 11 4 45 1 26 25 0 45 5 33 7 44 27 3 23 8 33 12 
28 45 34 48 23 17 13 35 3 33 48 35 27 21 1 18 13 8 48 9 1 45 33 45 35 19 1 36 32 24 9 15 9 40 1 32 27 24 14 21 23 27 4 2 43 21 41 32 2 30 8 44 6 41 12 33 35 19 11 48 2 47 32 49 4 19 21 44 6 27 32 37 37 6 
53
22 35 28 48 17 42 24 37 39 32 9 28 14 35 44 12 23 6 33 46 18 33 26 7 19 35 13 29 27 4 21 45 14 4 31 29 0 41 13 12 17 48 0 34 44 41 32 41 33 5 34 26 40 
43 35 4 3 24 37 26 8 47 0 21 19 31 1 15 23 4 0 19 10 11 43 41 23 4 9 49 11 42 7 33 9 31 2 2 37 42 1 35 27 21 15 15 24 40 19 8 16 36 24 36 10 26 
55
1 47 37 49 48 34 2 15 9 0 48 37 7 44 38 48 17 49 35 37 32 34 20 42 8 1 17 32 29 20 29 40 15 22 43 24 47 7 12 12 23 42 23 25 20 21 1 48 48 21 29 20 35 28 16 
1 9 41 35 7 43 18 26 40 40 2 9 28 44 38 39 33 2 46 38 16 2 47 49 13 6 42 27 11 23 14 32 30 44 46 14 16 29 44 11 25 31 5 23 48 31 49 23 28 20 19 29 17 34 28 
10
33 24 6 3 47 32 7 2 7 33 
38 45 6 37 42 36 41 2 33 7 
25
14 46 16 49 27 4 16 38 22 4 0 19 25 5 45 41 32 45 45 49 9 18 36 0 37 
45 41 14 44 1 28 45 16 29 35 18 25 18 9 19 6 3 28 21 22 26 48 12 34 23 
67
10 18 6 19 18 17 38 24 3 0 11 49 5 30 34 29 19 39 22 4 34 13 43 5 40 30 29 44 2 18 3 25 26 46 46 0 10 36 23 7 10 2 7 16 35 46 27 32 33 42 2 21 22 34 33 8 22 21 34 47 1 38 36 43 2 41 19 
2 4 8 34 49 28 24 3 14 39 17 8 5 11 14 37 13 36 29 32 19 16 30 30 30 32 20 15 49 48 26 5 10 22 19 44 32 24 17 49 31 46 44 39 44 14 24 18 46 17 4 12 32 3 5 32 23 3 31 25 31 7 17 30 49 11 2 
43
42 47 31 35 3 46 12 30 48 45 15 14 37 21 4 3 31 14 41 8 37 48 48 21 23 26 42 3 42 30 11 8 8 29 16 28 36 27 19 22 12 39 19 
2 3 35 45 37 17 27 20 22 10 37 22 7 10 33 13 13 1 4 7 27 4 49 41 30 30 29 29 10 29 19 2 4 13 32 38 24 19 42 8 26 26 5 
19
24 32 20 14 18 17 20 13 13 16 27 17 16 33 3 33 11 18 26 
46 46 25 5 47 5 43 0 12 12 8 45 32 13 30 25 4 16 22 
89
1 47 40 31 37 16 3 8 30 33 12 5 20 43 1 4 25 22 17 11 40 6 42 14 18 44 24 33 1 31 0 9 38 8 28 49 33 19 37 22 2 4 23 10 38 7 19 44 44 45 31 13 32 47 45 33 9 49 6 1 2 48 38 31 21 42 32 33 29 26 35 49 18 42 2 16 32 7 4 4 12 0 32 26 6 23 20 10 20 
10 20 33 47 37 42 7 28 37 14 38 32 48 40 17 30 6 17 11 13 49 10 25 6 8 29 28 19 38 5 9 6 10 10 4 10 16 19 23 48 24 27 14 32 14 7 35 17 45 28 47 2 14 24 19 12 4 19 15 49 29 10 14 33 43 41 15 29 12 3 17 47 23 11 2 41 14 41 47 31 31 2 8 43 27 14 14 44 5 
61
3 6 15 48 36 29 15 35 4 42 30 38 33 18 16 38 38 45 28 17 19 41 15 10 44 18 3 2 16 3 18 15 32 36 43 27 49 19 8 1 30 16 34 9 29 34 28 14 40 24 16 7 40 16 5 35 30 35 1 1 23 
26 45 38 24 8 31 44 35 42 23 43 18 27 43 48 14 43 25 32 17 18 49 14 37 49 43 46 36 18 21 29 47 12 16 20 5 0 14 37 35 47 42 32 28 41 9 46 28 22 20 38 32 39 31 20 15 39 4 27 44 15 
4
38 8 35 0 
17 41 0 39 
98
41 47 48 38 42 38 13 11 39 37 14 29 11 10 40 41 8 10 9 16 49 48 16 30 18 27 39 43 12 40 23 41 9 15 42 6 38 49 11 45 18 23 44 6 32 42 25 7 6 11 1 40 43 33 31 22 29 48 31 6 15 17 8 38 48 13 31 2 29 45 9 14 40 48 15 29 11 37 21 13 3 18 49 34 39 47 3 34 26 20 4 13 6 37 2 1 28 49 
10 10 10 5 6 48 41 46 7 0 5 44 46 32 38 10 17 8 28 22 8 32 19 39 0 2 1 37 7 36 32 43 35 13 27 40 17 28 19 17 9 38 46 23 17 16 4 8 18 5 26 44 22 8 9 19 43 7 1 3 6 27 8 1 8 38 11 12 34 30 46 4 43 37 14 0 45 48 3 18 40 31 9 24 28 47 37 30 39 26 9 40 46 35 37 46 27 19 
61
18 7 7 22 8 45 22 35 4 7 35 6 30 43 17 1 5 2 6 1 32 42 36 40 22 26 8 42 30 14 16 11 37 43 9 0 14 24 31 32 13 19 22 36 42 45 17 46 15 15 28 47 20 35 5 29 32 13 31 29 7 
9 29 49 49 39 13 30 31 1 16 42 4 24 43 42 20 43 44 13 2 27 8 25 25 34 6 49 15 27 41 46 20 10 43 45 24 41 32 27 19 27 19 42 29 39 30 40 6 28 5 3 32 19 14 16 19 18 41 10 18 18 
64
34 14 35 6 22 29 7 26 26 10 11 20 33 34 1 37 7 27 7 12 32 2 24 33 26 8 45 27 48 15 11 21 1 24 36 40 42 23 32 20 48 0 22 39 13 2 27 42 7 6 10 42 17 43 25 5 32 0 35 39 15 7 41 5 
46 3 45 18 46 39 49 32 36 40 6 3 34 40 3 34 29 18 38 26 36 13 37 5 14 31 46 35 37 16 30 13 35 7 13 8 28 22 6 40 3 32 46 29 6 32 48 0 27 44 4 15 1 38 23 25 15 25 25 10 26 29 17 26 
32
34 37 6 34 9 11 36 35 35 18 39 11 30 34 17 28 43 9 26 31 48 8 22 3 48 41 25 9 46 49 9 17 
25 43 34 39 43 24 46 43 5 18 28 40 33 3 14 46 34 24 16 0 44 9 19 36 36 15 45 45 37 49 5 43 
17
35 46 49 15 35 22 37 8 10 7 16 48 33 44 22 13 6 
2 29 32 31 8 46 3 20 14 20 17 37 30 4 9 49 5 
69
26 27 47 20 28 29 3 25 47 40 30 13 0 9 35 12 23 8 10 16 48 49 7 14 47 10 15 8 45 36 47 27 6 23 9 6 3 33 18 11 3 39 13 44 22 29 18 17 40 38 10 27 5 42 40 12 32 5 33 39 2 34 35 44 8 14 3 18 36 
1 13 30 26 35 12 23 8 26 13 46 2 48 38 25 17 13 20 37 34 36 46 25 39 2 19 27 8 28 41 21 6 8 47 39 48 18 39 42 17 15 30 36 45 48 28 32 1 35 37 36 47 42 22 22 20 49 36 18 4 8 27 19 49 9 19 39 34 0 
12
14 15 38 40 37 22 40 32 21 15 6 30 
41 1 15 13 10 42 6 22 46 39 9 11 
41
39 46 0 37 3 18 13 40 8 40 36 49 39 0 45 9 11 35 7 14 1 45 47 44 8 47 32 22 21 47 20 30 20 32 27 20 6 5 43 28 35 
6 24 42 32 25 43 35 10 37 28 24 7 44 7 39 17 46 43 23 3 1 40 5 15 20 44 1 30 17 3 17 24 40 39 46 1 34 29 48 33 38 
57
14 43 41 0 35 31 27 0 1 25 13 21 45 11 6 44 46 2 4 47 36 44 9 5 6 18 34 44 46 21 1 7 19 17 31 25 6 18 16 35 49 49 1 0 11 4 34 39 27 21 19 31 13 5 37 7 44 
38 36 25 27 35 37 26 30 45 13 32 15 39 13 34 4 12 10 44 45 34 27 17 48 36 36 31 32 40 30 16 12 21 19 33 2 24 1 39 44 37 23 45 12 44 46 46 32 43 20 17 43 12 36 40 8 35 
21
9 35 47 49 34 10 48 26 20 47 3 43 49 13 34 5 9 44 43 14 26 
10 38 28 38 30 21 39 0 4 34 1 14 16 0 3 42 5 31 26 10 12 
4
11 7 19 28 
15 19 25 36 
17
21 31 1 49 33 44 9 33 9 26 45 21 7 32 2 25 6 
16 44 5 41 27 44 21 36 15 33 9 12 32 21 28 41 1 
14
22 23 39 14 5 41 0 24 10 29 41 9 22 23 
39 7 0 12 33 33 11 38 16 42 20 26 21 30 
Out #10:
Ankit
Rupam
Rupam
Rupam
Tie
Rupam
Ankit
Rupam
Ankit
Rupam
Rupam
Rupam
Ankit
Ankit
Ankit
Ankit
Rupam
Ankit
Ankit
Rupam
Ankit
Rupam
Ankit
Ankit
Ankit
Ankit
Ankit
Ankit
Rupam
Ankit
Ankit
Ankit
Rupam
Rupam
Rupam
Ankit
Rupam
Ankit
Rupam
Ankit
Ankit
Ankit
Ankit
Ankit
Rupam
Rupam
Rupam
Ankit
Rupam
Ankit
Rupam
Ankit
Rupam
Rupam
Ankit
Ankit
Rupam
Ankit
Rupam
Ankit
Rupam
Ankit
Ankit
Ankit
Rupam
Rupam
Rupam
Rupam
Rupam
Rupam
Rupam
Rupam
Rupam
Ankit
Rupam
Ankit
Ankit
Rupam
Rupam
Ankit
Tie
Rupam
Rupam
Ankit
Rupam
Ankit
Ankit
Rupam
Ankit
Ankit
Ankit
Rupam
Rupam
Ankit
Rupam
Rupam
Rupam
Ankit
Ankit
Rupam

*/

