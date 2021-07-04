/* All Tracks  --> Data Structures -->   Arrays -->  Multi-dimensional -->  Problem --> 
Monk and Operations

Monk is fond of matrices. Today, he created a matrix A of size NxM. He defines four types of operations on the matrix as follows:
1.Add v1 to all elements of a row.
2.Update the value of all elements of a row to v2, i.e., all elements of that row become equal to v2.
3.Add v3 to all elements of a column.
4.Update the value of all elements of a column to v4, i.e., all elements of that column become equal to v4.

He defines a function F(x) as
		 
	 i=N _  j=M  _
F(x) = 	\   	\  abs(A[i][j])
		/_  	/_
	  i=1   j=1
where (A[i][j]) refers to the jth cell in the ith  row of matrix A, and abs(x) refers to absolute value of any integer x.

Now, he has defined some restrictions:
On any cell of the matrix, at most one operation can be performed. This operation can be of any type.
Any type of operation can be used any number of times.
You need to maximize the value of F(x) following these restrictions.

Input Format:
The first line consists of two integers N and M, denoting the number of rows and number of columns in matrix A respectively.
Each of the following N lines consist of M space-separated integers, where the  jth integer in the ith line denotes A[i][j].
The last line of input consists of four space-separated integers denoting the values of v1,v2,v3 and v4 respectively.

Output Format:
The only line of output should consist of the maximum value of F(x).

Input Constraints:
1<=N<=1000
1<=M<=1000
-10^9<=A[i][j]<=10^9
-10^9<=v1,v2,v3,v4<=10^9

SAMPLE INPUT 
2 2
-5 8
6 -9
-2 5 -1 6
SAMPLE OUTPUT 
29
Explanation
-5 8
6 -9

We use third type of operation on column 2 (or we can leave column 2 as it is) and fourth type of operation on column 1.
F(x) = abs(6) + abs(8-1) + abs(6) + abs(-9-1) = 6+7+6+10 = 29

#include <stdio.h>
#include <stdlib.h>
#define ll long long int
#define max(a,b) ((a)>(b))?(a):(b)

int main()
{
    ll row[1001][2];
    ll col[1001][2];
    ll a[1001][1001];    
    ll n,m,i,j,v1,v2,v3,v4;
    ll r,c;
    scanf("%lld%lld",&n,&m);
    for(i=0;i<1000;i++){
        for(j=0;j<2;j++){
            row[i][j]=0;
            col[i][j]=0;
        }
    }
    for(i =0;i<n;i++)
    {
        for(j =0;j<m;j++)
        {
            scanf("%lld",&a[i][j]);
        }
    }
    scanf("%lld%lld%lld%lld",&v1,&v2,&v3,&v4);
    for(i =0;i<n;i++)
    {
        for(j =0;j<m;j++)
        {
            col[j][0]+=(labs(a[i][j]));
            row[i][0]+=(labs(a[i][j]));
            col[j][1]+=(labs(a[i][j]+v3));
            row[i][1]+=(labs(a[i][j]+v1));
        }
        r+=max(m*labs(v2),max(row[i][0],row[i][1]));
    }
    for(i =0;i<m;i++)
    {
        c+=max(n*labs(v4),max(col[i][0],col[i][1]));
    }
    printf("%lld\n",max(r,c));
    return 0;
}

*/

/*Editorial:
Author: Shubham Gupta
Tester: Anand Jaisingh
Hint : Operations have to be performed over rows only/ columns only.

Detailed Editorial :
The first observation to make in this problem is that we cannot perform an operation on a row as well as a column. Suppose we perform an operation on row i and column j. 
By doing so, we perform an opeartion on cell (i,j) twice. 
This violates the constraints, and thus can never be done.

So, operations can be performed either on rows only, or columns only. The answer will be the maximum of the two.
For each row/column, there are 3 distinct possibilities, i.e.

1.Perform an operation of type 1
2.Perform an operation of type 2.
3.Do not perform any operation.

We need to check these 3 possibilities for each row/column, and then print the maximum of the two.

Time/Space Complexity :
O(N x M)

Author Solution by Shubham Gupta
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	assert(n>=1 && n<=1000);
	assert(m>=1 && m<=1000);
	ll mat[1005][1005],val[10];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>mat[i][j];
			assert(mat[i][j]>=-1e9 && mat[i][j]<=1e9);
		}
	for(int i=0;i<4;i++)
	{
		cin>>val[i];
		assert(val[i]>=-1e9 && val[i]<=1e9);
	}
	ll rsum=0,rusum=0,risum=0,csum=0,cisum=0,cusum=0,matrsum=0,matcsum=0;
	for(int i=0;i<n;i++)
	{
		rsum=risum=rusum=0;
		for(int j=0;j<m;j++)
		{
			rsum+=abs(mat[i][j]);
			risum+=abs(mat[i][j]+val[0]);
			rusum+=abs(val[1]);
		}
		matrsum+=max(rsum,max(risum,rusum));
	}
	for(int j=0;j<m;j++)
	{
		csum=cisum=cusum=0;
		for(int i=0;i<n;i++)
		{
			csum+=abs(mat[i][j]);
			cisum+=abs(mat[i][j]+val[2]);
			cusum+=abs(val[3]);
		}
		matcsum+=max(csum,max(cisum,cusum));
	}
	//cout<<matrsum<<" "<<matcsum<<"\n";
	cout<<max(matrsum,matcsum)<<"\n";
	return 0;
}

Tester Solution by Anand Jaisingh
import java.io.*;
import java.util.*;
public final class fredo_and_ops
{
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static FastScanner sc=new FastScanner(br);
    static PrintWriter out=new PrintWriter(System.out);
	static Random rnd=new Random();
	
    public static void main(String args[]) throws Exception
    {
		int n=sc.nextInt(),m=sc.nextInt();long[][] a=new long[n][m];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				a[i][j]=sc.nextLong();
			}
		}
		long v1=sc.nextLong(),v2=Math.abs(sc.nextLong()),v3=sc.nextLong(),v4=Math.abs(sc.nextLong()),max1=0,max2=0;
		for(int i=0;i<n;i++)
		{
			long sum1=0,sum2=0;
			for(int j=0;j<m;j++)
			{
				long curr=a[i][j]+v1;sum1=sum1+Math.abs(curr);sum2+=Math.abs(a[i][j]);
			}
			max1+=Math.max(sum1,Math.max(sum2,v2*m));
		}
		for(int i=0;i<m;i++)
		{
			long sum1=0,sum2=0;
			for(int j=0;j<n;j++)
			{
				long curr=Math.abs(a[j][i]+v3);sum1+=curr;sum2+=Math.abs(a[j][i]);
			}
			max2+=Math.max(sum1,Math.max(sum2,v4*n));
		}
		out.println(Math.max(max1,max2));out.close();
    }
}
class FastScanner
{
    BufferedReader in;
    StringTokenizer st;
    public FastScanner(BufferedReader in) {
        this.in = in;
    }
	
    public String nextToken() throws Exception {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }
	
	public String next() throws Exception {
		return nextToken().toString();
	}
	
    public int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }
    public long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }
    public double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }
}

*/

/*Best Submissions:
C:
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
long long int rmax,cmax,a[1000][1000],v1,v2,v3,v4;
int N,M;
 
 
long int absolute(long long int a)
{
    if(a<0)
        return 0-a;
    else
        return a;
}
 
long long int the_rows(){
    long long int max=0,max1,max2,max3;
    for(int i=0;i<N;i++){
        max1=0;
        max2=0;
        max3=0;
        for(int j=0;j<M;j++){
            max1+=absolute(a[i][j]+v1);
            max2+=absolute(v2);
            max3+=absolute(a[i][j]);
        }
        if(max1>=max2 && max1>=max3)max+=max1;
        else if (max2>=max1 && max2>=max3)max+=max2;
        else max+=max3;
    }
    return max;
}
long long int the_columns(){
    long long int max=0,max1,max2,max3;
    for(int i=0;i<M;i++){
        max1=0;
        max2=0;
        max3=0;
        for(int j=0;j<N;j++){
            max1+=absolute(a[j][i]+v3);
            max2+=absolute(v4);
            max3+=absolute(a[j][i]);
        }
        if(max1>=max2 && max1>=max3)max+=max1;
        else if (max2>=max1 && max2>=max3)max+=max2;
        else max+=max3;
    }
    return max;
}
 
int main()
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            long long int temp;
            scanf("%lli",&temp);
            a[i][j]=temp;
        }
    }
    scanf("%lli %lli %lli %lli",&v1,&v2,&v3,&v4);
    rmax=the_rows();
    cmax=the_columns();
    if(rmax>cmax){
        printf("%lli",rmax);
    }else printf("%lli",cmax);
    return 0;
}

C++:
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[1100][1100] , row[1100] , col[1100];
int main()
{
    long long n,m;
    cin>>n>>m;
    long long maxirow = 0 , maxicol = 0;
    for(int i = 0 ; i<n ; i++)
    for(int j = 0 ; j<m ; j++)
      {
          scanf("%lld" , &a[i][j]);
          row[i]+=abs(a[i][j]);
          col[j]+=abs(a[i][j]);
      }
    long long d1,d2,d3,d4;
    cin>>d1>>d2>>d3>>d4;
    for(int i = 0 ; i<n ; i++)
    {
        long long sum = 0;
        for(int j = 0 ; j<m ; j++)
        {
            sum+= abs(a[i][j] + d1);
        }
        maxirow += max(row[i] , max(sum , abs(m*d2)));
    }
   for(int i = 0 ; i<m ; i++)
    {
        long long sum = 0;
        for(int j = 0 ; j<n ; j++)
        {
            sum+= abs(a[j][i] + d3);
        }
        maxicol += max(col[i] , max(sum , abs(n*d4)));
    }
    cout<<max(maxirow , maxicol)<<endl;
    return 0;
}

C++14:
#include<bits/stdc++.h>
using namespace std;
 
#define pi 3.141592654
#define hell 1000000007
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fix(n) cout << fixed << setprecision(n)
#define input1(n) int n;cin>>n
#define input2(a, b) int a,b;cin>>a>>b
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (__typeof((b)) i=(a);i<(b);i++)
#define ren(i,a,b) for(__typeof((a)) i=(a);i>=(b);i--)
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int,int>
#define piii pair<pair<int,int>,int>
#define all(v) (v).begin(), (v).end()
#define sz(x) (int)x.size()
#define set(a,n) memset(a,n,sizeof(a))
 
void solve(){
    input2(n,m);
    int a[n][m];
    ll row[n] = {0}, col[m] = {0};
    rep(i, 0, n){
        rep(j, 0, m){
            cin>>a[i][j];
            row[i]+=abs(a[i][j]);
            col[j]+=abs(a[i][j]);
        }
    }
    ll v1, v2, v3, v4;
    cin>>v1>>v2>>v3>>v4;
    ll ans = 0, ans2 = 0, ans3 = 0;
    
    ll sum1 = 0, sum2 = 0;
    rep(i, 0, n)
        sum1+=row[i];
    rep(i, 0, m)
        sum2+=col[i];
    ans = Max(sum1, sum2);
    
    rep(i, 0, n){
        ll sum = 0;
        rep(j, 0, m)
            sum += abs(a[i][j] + v1);
        ll temp_sum1 = Max(sum, row[i]);
        ll temp_sum2 = Max(temp_sum1, abs(v2*m));
        ans2 += temp_sum2;
    }
    
    rep(j, 0, m){
        ll sum = 0;
        rep(i, 0, n)
            sum += abs(a[i][j] + v3);
        ll temp_sum1 = Max(sum, col[j]);
        ll temp_sum2 = Max(temp_sum1, v4*n);
        ans3 += temp_sum2;
    }
    
    ans = Max(ans, Max(ans2, ans3));
    cout<<ans<<endl;
}
int main(){
    io;
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}

C#:
System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
 
namespace HackerEarth
{
    /// <summary>
    /// Solution class
    /// </summary>
    internal static class Program
    {
        #region Main
        /// <summary>
        /// Modulo operator used in a lot of questions
        /// </summary>
        private const long mod = 1000000007;
        /// <summary>
        /// Fast Console IO helper
        /// </summary>
        private static ConsoleHelper Console { get; } = new ConsoleHelper();
 
        /// <summary>
        /// Main method - Launches solver
        /// </summary>
        private static void Main()
        {
            //Depending on problem
            using (Console)
            {
                //TestCases();
                Solve();
            }
        }
 
        /// <summary>
        /// Solves the problem for multiple test cases
        /// </summary>
        private static void TestCases()
        {
            int t = Console.NextInt();
            Console.SkipNextLine();
 
            while (t-- > 0)
            {
                Solve();
            }
        }
        #endregion
 
        #region Solution
        private class Matrix
        {
            private readonly long[,] matrix;
            private readonly int n, m;
            private readonly long v1, v2, v3, v4;
 
            public Matrix(int n, int m)
            {
                this.n = n;
                this.m = m;
                this.matrix = new long[n, m];
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        this.matrix[i, j] = Console.NextInt();
                    }
                    Console.SkipNextLine();
                }
 
                this.v1 = Console.NextInt();
                this.v2 = Console.NextInt();
                this.v3 = Console.NextInt();
                this.v4 = Console.NextInt();
            }
 
            public long AddRow(int i)
            {
                long result = 0L;
                for (int j = 0; j < this.m; j++)
                {
                    result += Math.Abs(this.matrix[i, j] + this.v1);
                }
                return result;
            }
 
            public long SetRow(int i) => Math.Abs(this.v2 * this.m);
 
            public long SumRow(int i)
            {
                long result = 0L;
                for (int j = 0; j < this.m; j++)
                {
                    result += Math.Abs(this.matrix[i, j]);
                }
                return result;
            }
 
            public long AddColumn(int j)
            {
                long result = 0L;
                for (int i = 0; i < this.n; i++)
                {
                    result += Math.Abs(this.matrix[i, j] + this.v3);
                }
                return result;
            }
 
            public long SetColumn(int j) => Math.Abs(this.v4 * this.n);
 
            public long SumColumn(int j)
            {
                long result = 0L;
                for (int i = 0; i < this.n; i++)
                {
                    result += Math.Abs(this.matrix[i, j]);
                }
                return result;
            }
        }
 
        /// <summary>
        /// Solution
        /// </summary>
        private static void Solve()
        {
            int n = Console.NextInt(), m = Console.NextInt();
            Console.SkipNextLine();
            
            Matrix matrix = new Matrix(n, m);
 
            long rowMax = 0L;
            for (int i = 0; i < n; i++)
            {
                rowMax += Math.Max(matrix.SumRow(i), Math.Max(matrix.AddRow(i), matrix.SetRow(i)));
            }
 
            long columnMax = 0L;
            for (int j = 0; j < m; j++)
            {
                columnMax += Math.Max(matrix.SumColumn(j), Math.Max(matrix.AddColumn(j), matrix.SetColumn(j)));
            }
 
            Console.Write(Math.Max(rowMax, columnMax));
        }
        #endregion
    }
 
    /// <summary>
    /// Fast Console IO helper
    /// </summary>
    internal sealed class ConsoleHelper : IDisposable
    {
        #region Constants
        /// <summary>
        /// The standard input and output buffers size (2^20, 1Mb)
        /// </summary>
        private const int baseSize = 1048576;
        #endregion
 
        #region Fields
        private readonly BufferedStream inStream;  //Buffered console input stream
        private readonly BufferedStream outStream; //Buffered console output stream
        private readonly byte[] inBuffer;  //Input buffer 
        private readonly byte[] outBuffer; //Output buffer
 
        private int inputIndex;  //Input buffer current index
        private int outputIndex; //Output buffer current index
        private int bufferEnd;   //Input buffer ending index
        #endregion
 
        #region Properties
        /// <summary>
        /// The buffer size, in bytes
        /// </summary>
        public int BufferSize { get; }
 
        /// <summary>
        /// If this memory stream is open and available to read/write
        /// </summary>
        public bool Open { get; private set; }
        #endregion
 
        #region Constructors
        /// <summary>
        /// Creates a new console IO helper reading from the standard Console input and output
        /// </summary>
        public ConsoleHelper() : this(baseSize) { }
 
        /// <summary>
        /// Creates a new console IO helper reading from the standard Console input and output with the specified buffer size
        /// <param name="bufferSize">Size of the buffer to use in bytes</param>
        /// </summary>
        public ConsoleHelper(int bufferSize)
        {
            //Open the input/output streams
            #if DEBUG
            //Test mode
            this.inStream = new BufferedStream(File.OpenRead(@"..\..\input.txt"), bufferSize);
            this.outStream = new BufferedStream(File.OpenWrite(@"..\..\output.txt"), bufferSize);
            #else //DEBUG
            //Submission mode
            this.inStream = new BufferedStream(Console.OpenStandardInput(bufferSize), bufferSize); //Submission stream
            this.outStream = new BufferedStream(Console.OpenStandardOutput(bufferSize), bufferSize);
            #endif
 
            //Setup input/output buffers
            this.inBuffer = new byte[bufferSize];
            this.outBuffer = new byte[bufferSize];
 
            //Set fields
            this.inputIndex = this.outputIndex = this.bufferEnd = 0;
            this.BufferSize = bufferSize;
            this.Open = true;
        }
        #endregion
 
        #region Static methods
        /// <summary>
        /// Verifies that the passed character is a non-special ASCII character
        /// </summary>
        /// <param name="i">Character to validate</param>
        /// <returns>True if the character is not a special character</returns>
        public static bool ValidateChar(int i) => i >= ' ';
 
        /// <summary>
        /// Verifies that the passed character is a non-special ASCII character or a whitespace
        /// </summary>
        /// <param name="i">Character to validate</param>
        /// <returns>True if the character is not a whitespace or a special character</returns>
        public static bool ValidateCharNoSpace(int i) => i > ' ';
 
        /// <summary>
        /// Verifies that the passed character is a numerical character (0-9)
        /// </summary>
        /// <param name="i">Character to validate</param>
        /// <returns>True if the character is a numerical character, false otherwise</returns>
        public static bool ValidateNumber(int i) => i >= '0' && i <= '9';
 
        /// <summary>
        /// Verifies if a character is an Endline character
        /// </summary>
        /// <param name="i">Character to check</param>
        /// <returns>True if it is an Endline character, false otherwise</returns>
        public static bool IsEndline(int i) => i == '\n' || i == '\0';
        #endregion
 
        #region Methods
        /// <summary>
        /// Returns the next byte data in the console input stream
        /// </summary>
        /// <returns>Next data byte from the console</returns>
        public byte Read()
        {
            CheckBuffer();
            return this.inBuffer[this.inputIndex++];
        }
 
        /// <summary>
        /// Returns the next byte data in the console input stream without consuming it
        /// </summary>
        /// <returns>Next data byte from the console</returns>
        public byte Peek()
        {
            CheckBuffer();
            return this.inBuffer[this.inputIndex];
        }
 
        /// <summary>
        /// Skips a number of characters in the input stream
        /// </summary>
        /// <param name="n">Amount of chars to skip, defaults to 1</param>
        public void Skip(int n = 1) => this.inputIndex += n;
 
        /// <summary>
        /// Assures we have data available in the input buffer
        /// </summary>
        private void CheckBuffer()
        {
            //If we reach the end of the buffer, load more data
            if (this.inputIndex >= this.bufferEnd)
            {
                this.inputIndex = this.inputIndex - this.bufferEnd;
                this.bufferEnd = this.inStream.Read(this.inBuffer, 0, this.BufferSize);
 
                //If nothing was added, add a null char at the start
                if (this.bufferEnd < 1) { this.inBuffer[this.bufferEnd++] = 0; }
            }
        }
 
        /// <summary>
        /// Returns the next character in the console input stream
        /// </summary>
        /// <returns>Next character in the input stream</returns>
        public char NextChar() => (char)Read();
 
        /// <summary>
        /// Returns the next string token from the console input
        /// </summary>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <returns>Parsed string, separated by spaces or special characters such as line feeds</returns>
        public string Next()
        {
            byte b = SkipInvalid();
            ValidateEndline(b);
 
            //Append all characters
            StringBuilder sb = new StringBuilder().Append((char)b);
            b = Peek();
            while (ValidateCharNoSpace(b))
            {
                //Peek to not consume terminator
                sb.Append((char)b);
                Skip();
                b = Peek();
            }
 
            return sb.ToString();
        }
 
        /// <summary>
        /// Returns the next int value in the console input, this is a fast parse
        /// </summary>
        /// <exception cref="FormatException">If the text is not a valid integer</exception>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <exception cref="OverflowException">If the value is too large for integer</exception>
        /// <returns>Parsed int value from the input</returns>
        public int NextInt()
        {
            //Skip invalids
            byte b = SkipInvalid();
            ValidateEndline(b);
 
            //Verify for negative
            bool neg = false;
            if (b == '-')
            {
                neg = true;
                b = Read();
            }
 
            //Get first digit
            if (!ValidateNumber(b)) { throw new FormatException("Integer parsing has failed because the string contained invalid characters"); }
 
            int n = b - '0';
            b = Peek();
            while (ValidateNumber(b))
            {
                //Peek to not consume terminator, and check for overflow
                n = checked((n << 3) + (n << 1) + (b - '0'));
                Skip();
                b = Peek();
            }
            //If the character causing the exit is a valid ASCII character, the integer isn't correct formatted
            if (ValidateCharNoSpace(b)) { throw new FormatException("Integer parsing has failed because the string contained invalid characters"); }
 
            return neg ? -n : n;
        }
 
        /// <summary>
        /// Returns the next long value in the console input, this is a fast parse
        /// </summary>
        /// <exception cref="FormatException">If the text is not a valid long</exception>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <exception cref="OverflowException">If the value is too large for long</exception>
        /// <returns>Parsed long value from the input</returns>
        public long NextLong()
        {
            byte b = SkipInvalid();
            ValidateEndline(b);
 
            //Verify negative
            bool neg = false;
            if (b == '-')
            {
                neg = true;
                b = Read();
            }
 
            //Get first digit
            if (!ValidateNumber(b)) { throw new FormatException("Integer parsing has failed because the string contained invalid characters"); }
 
            long n = b - '0';
            b = Peek();
            while (ValidateNumber(b))
            {
                //Peek to not consume terminator, and check for overflow
                n = checked((n << 3) + (n << 1) + (b - '0'));
                Skip();
                b = Peek();
            }
            //If the character causing the exit is a valid ASCII character, the long isn't correct formatted
            if (ValidateCharNoSpace(b)) { throw new FormatException("Long parsing has failed because the string contained invalid characters"); }
 
            return neg ? -n : n;
        }
 
        /// <summary>
        /// Returns the next double value in the console input
        /// Note: fast double parsing is slightly harder, I'll implement it if I need to
        /// </summary>
        /// <exception cref="FormatException">If the text is not a valid double</exception>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <exception cref="OverflowException">If the value is too large for double</exception>
        /// <returns>Parsed double value from the input</returns>
        public double NextDouble() => double.Parse(Next());
 
        /// <summary>
        /// Returns the next n int values on the same line in an array
        /// </summary>
        /// <param name="n">Number of values to seek</param>
        /// <exception cref="FormatException">If the text is not a valid integer</exception>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <exception cref="OverflowException">If the value is too large for integer</exception>
        /// <exception cref="OutOfMemoryException">If the created array is too large for the system memory</exception>
        /// <returns>The n integer values in an array</returns>
        public int[] NextInts(int n)
        {
            int[] array = new int[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = NextInt();
            }
 
            SkipNextLine();
            return array;
        }
 
        /// <summary>
        /// Returns the next n int values on the next m lines in the output stream under the form of an NxM matrix
        /// </summary>
        /// <param name="n">Number of rows to the matrix</param>
        /// <param name="m">Number of columns to the matrix</param>
        /// <exception cref="FormatException">If the text is not a valid integer</exception>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        /// <exception cref="OverflowException">If the value is too large for integer</exception>
        /// <exception cref="OutOfMemoryException">If the created 2D array is too large for the system memory</exception>
        /// <returns>The NxM matrix of integers</returns>
        public int[,] NextMatrix(int n, int m)
        {
            int[,] matrix = new int[n, m];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[i, j] = NextInt();
                }
 
                SkipNextLine();
            }
 
            return matrix;
        }
 
        /// <summary>
        /// Returns the next line of text in the console
        /// </summary>
        /// <returns>Next string line from the console</returns>
        public string NextLine()
        {
            byte b = SkipInvalid();
            if (b == 0)
            {
                //Consume newline and return empty string
                Skip();
                return string.Empty;
            }
 
            //Read all the characters until the next linefeed
            StringBuilder sb = new StringBuilder().Append((char)b);
            b = Read();
            while (!IsEndline(b))
            {
                //Don't append special characters, but don't exit
                if (ValidateChar(b))
                {
                    sb.Append((char)b);
                }
                b = Read();
            }
 
            return sb.ToString();
        }
 
        /// <summary>
        /// Skips the next token in input
        /// </summary>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        public void SkipNext()
        {
            byte b = SkipInvalid();
            ValidateEndline(b);
 
            for (b = Peek(); ValidateCharNoSpace(b); b = Peek())
            {
                Skip();
            }
        }
 
        /// <summary>
        /// Skips all the text on the current line and jump to the next
        /// </summary>
        public void SkipNextLine()
        {
            for (byte b = Read(); !IsEndline(b); b = Read()) { }
        }
 
        /// <summary>
        /// Enumerates the given number of integers on the current line
        /// </summary>
        /// <param name="n">Number of integers on the current line</param>
        /// <returns>Enumerable of the integers</returns>
        public IEnumerable<int> EnumerateInts(int n)
        {
            while (n-- > 0)
            {
                yield return NextInt();
            }
 
            SkipNextLine();
        }
 
        /// <summary>
        /// Enumerates all the characters in the next line until the feed is exhausted or an endline character is met
        /// </summary>
        /// <returns>Enumerable of all the characters in the current line</returns>
        public IEnumerable<char> EnumerateLine()
        {
            for (char c = NextChar(); !IsEndline(c); c = NextChar())
            {
                if (ValidateChar(c))
                {
                    yield return c;
                }
            }
        }
 
        /// <summary>
        /// Assures we are not trying to read more data on the line that there exists
        /// </summary>
        /// <param name="b">Byte data to verify</param>
        /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
        private void ValidateEndline(byte b)
        {
            //If empty char
            if (b == 0)
            {
                //Go back a char and throw
                this.inputIndex--;
                throw new InvalidOperationException("No values left on line");
            }
        }
 
        /// <summary>
        /// Skips all invalid character bytes then returns the first valid byte found, spaces are considered invalid
        /// </summary>
        /// <returns>The next valid character byte, cannot be a whitespace</returns>
        private byte SkipInvalid()
        {
            byte b = Peek();
            if (IsEndline(b)) { return 0; }
 
            while (!ValidateCharNoSpace(b))
            {
                Skip();
                b = Peek();
                //Return empty char if we meet an linefeed or empty char
                if (IsEndline(b)) { return 0; }
            }
 
            return Read();
        }
 
        /// <summary>
        /// Writes the given char to the console output
        /// </summary>
        /// <param name="c">Character to write</param>
        public void Write(char c) => WriteByte((byte)c);
 
        /// <summary>
        /// Writes the given char buffer to the console output
        /// </summary>
        /// <param name="buffer">Char buffer to write</param>
        public void Write(char[] buffer) => buffer.ForEach(c => WriteByte((byte)c));
 
        /// <summary>
        /// Writes the given string to the console output
        /// </summary>
        /// <param name="s">String to write</param>
        public void Write(string s) => Write(s.ToCharArray());
 
        /// <summary>
        /// Writes the given integer to the console output
        /// </summary>
        /// <param name="n">Integer to write</param>
        public void Write(int n) => Write(n.ToString().ToCharArray());
 
        /// <summary>
        /// Writes the given long to the console output
        /// </summary>
        /// <param name="n">Long to write</param>
        public void Write(long n) => Write(n.ToString().ToCharArray());
 
        /// <summary>
        /// Writes the given object to the console output using the object's ToString method
        /// </summary>
        /// <param name="o">Object to write</param>
        public void Write(object o) => Write(o.ToString().ToCharArray());
 
        /// <summary>
        /// Writes a sequence to the console output with the given string separator
        /// </summary>
        /// <typeparam name="T">Type of elements in the sequence</typeparam>
        /// <param name="e">Sequence to print</param>
        /// <param name="separator">String separator between each element, defaults to the empty string</param>
        public void Write<T>(IEnumerable<T> e, string separator = "") => Write(e.Join(separator).ToCharArray());
 
        /// <summary>
        /// Writes a linefeed to the console output
        /// </summary>
        public void WriteLine() => WriteByte(10);
 
        /// <summary>
        /// Writes the given char to the console output, followed by a linefeed
        /// </summary>
        /// <param name="c">Character to write</param>
        public void WriteLine(char c)
        {
            WriteByte((byte)c);
            WriteByte(10);
        }
 
        /// <summary>
        /// Writes the given char buffer to the console output, followed by a linefeed
        /// </summary>
        /// <param name="buffer">Char buffer to write to the output</param>
        public void WriteLine(char[] buffer)
        {
            Write(buffer);
            WriteByte(10);
        }
 
        /// <summary>
        /// Writes the given string to the console output, followed by a linefeed
        /// </summary>
        /// <param name="s">String to write</param>
        public void WriteLine(string s)
        {
            Write(s.ToCharArray());
            WriteByte(10);
        }
 
        /// <summary>
        /// Writes the given integer to the console output, followed by a linefeed
        /// </summary>
        /// <param name="n">Integer to write</param>
        public void WriteLine(int n)
        {
            Write(n.ToString().ToCharArray());
            WriteByte(10);
        }
 
        /// <summary>
        /// Writes the given long to the console output, followed by a linefeed
        /// </summary>
        /// <param name="n">Long to write</param>
        public void WriteLine(long n)
        {
            Write(n.ToString().ToCharArray());
            WriteByte(10);
        }
 
        /// <summary>
        /// Writes a sequence to the console output with the given string separator, follows by a linefeed
        /// </summary>
        /// <typeparam name="T">Type of elements in the sequence</typeparam>
        /// <param name="e">Sequence to print</param>
        /// <param name="separator">String separator between each element, defaults to the empty string</param>
        public void WriteLine<T>(IEnumerable<T> e, string separator = "")
        {
            Write(e, separator);
            WriteByte(10);
        }
 
        /// <summary>
        /// Writes the given object to the console output using the object's ToString method, followed by a linefeed
        /// </summary>
        /// <param name="o">Object to write</param>
        public void WriteLine(object o)
        {
            Write(o.ToString().ToCharArray());
            WriteByte(10);
        }
 
        /// <summary>
        /// Writes the given data byte to the console output, this does NOT write the actual number
        /// </summary>
        /// <param name="b">Data byte to write</param>
        public void WriteByte(byte b)
        {
            Flush();
            this.outBuffer[this.outputIndex++] = b;
        }
 
        /// <summary>
        /// Flushes the output buffer to the console if the buffer is full, or if it's being forced
        /// </summary>
        /// <param name="force">If the buffer must be forced to flush even if it isn't full</param>
        public void Flush(bool force = false)
        {
            if (this.outputIndex == this.BufferSize || force)
            {
                this.outStream.Write(this.outBuffer, 0, this.outputIndex);
                this.outStream.Flush();
                this.outputIndex = 0;
            }
        }
 
        /// <summary>
        /// Disposes of the resources of this ConsoleHelper, closing all the associated streams
        /// </summary>
        public void Dispose()
        {
            if (this.Open)
            {
                Flush(true);
                this.inStream.Dispose();
                this.outStream.Dispose();
                this.Open = false;
            }
        }
        #endregion
    }
 
    /// <summary>
    /// Useful extensions
    /// </summary>
    internal static class Extensions
    {
        #region Enumerable extensions
        /// <summary>
        /// Applies an action on each member of the enumerable
        /// </summary>
        /// <typeparam name="T">Type of elements in the Enumerable</typeparam>
        /// <param name="e">Enumerable to loop through</param>
        /// <param name="action">Action to apply to each parameter</param>
        public static void ForEach<T>(this IEnumerable<T> e, Action<T> action)
        {
            foreach (T t in e)
            {
                action(t);
            }
        }
 
        /// <summary>
        /// Tests whether or not the given collection of items is empty
        /// </summary>
        /// <param name="c">Collection to test</param>
        /// <returns>True if the collection is empty, false otherwise</returns>
        public static bool IsEmpty(this System.Collections.ICollection c) => c.Count == 0;
 
        /// <summary>
        /// Joins all the elements of the enumerable into a string
        /// </summary>
        /// <typeparam name="T">Type of elements in the Enumerable</typeparam>
        /// <param name="e">Enumerable to loop through</param>
        /// <param name="separator">Separator string, defaults to the empty string</param>
        public static string Join<T>(this IEnumerable<T> e, string separator = "") => new StringBuilder().AppendJoin(e, separator).ToString();
 
        /// <summary>
        /// Finds the object with the maximum value in the enumerable
        /// </summary>
        /// <typeparam name="T">Type of objects in the Enumerable</typeparam>
        /// <typeparam name="TU">Comparing type, must implement IComparable(T)</typeparam>
        /// <param name="e">Enumerable to loop through</param>
        /// <param name="selector">Function calculating the value that we want the max from</param>
        /// <returns>The object with the maximum value in the enumerable</returns>
        public static T MaxValue<T, TU>(this IEnumerable<T> e, Func<T, TU> selector) where TU : IComparable<TU>
        {
            using (IEnumerator<T> enumerator = e.GetEnumerator())
            {
                if (!enumerator.MoveNext()) { throw new InvalidOperationException("No elements in sequence"); }
 
                T max = enumerator.Current;
                TU value = selector(max);
                while (enumerator.MoveNext())
                {
                    TU v = selector(enumerator.Current);
                    if (value.CompareTo(v) < 0)
                    {
                        max = enumerator.Current;
                        value = v;
                    }
                }
 
                return max;
            }
        }
 
        /// <summary>
        /// Finds the object with the minimum value in the enumerable
        /// </summary>
        /// <typeparam name="T">Type of objects in the Enumerable</typeparam>
        /// <typeparam name="TU">Comparing type, must implement IComparable(T)</typeparam>
        /// <param name="e">Enumerable to loop through</param>
        /// <param name="selector">Function calculating the value that we want the min from</param>
        /// <returns>The object with the minimum value in the enumerable</returns>
        public static T MinValue<T, TU>(this IEnumerable<T> e, Func<T, TU> selector) where TU : IComparable<TU>
        {
            using (IEnumerator<T> enumerator = e.GetEnumerator())
            {
                if (!enumerator.MoveNext()) { throw new InvalidOperationException("No elements in sequence"); }
 
                T min = enumerator.Current;
                TU value = selector(min);
                while (enumerator.MoveNext())
                {
                    TU v = selector(enumerator.Current);
                    if (value.CompareTo(v) > 0)
                    {
                        min = enumerator.Current;
                        value = v;
                    }
                }
 
                return min;
            }
        }
        #endregion
 
        #region String extensions
        /// <summary>
        /// Appends multiple objects to a StringBuilder, separated by the given string
        /// </summary>
        /// <typeparam name="T">Type of elements in the Enumerable</typeparam>
        /// <param name="sb">StringBuilder to append to</param>
        /// <param name="e">Enumerable to loop through</param>
        /// <param name="separator">Separator string</param>
        /// <returns>The StringBuilder instance after the appending is done</returns>
        public static StringBuilder AppendJoin<T>(this StringBuilder sb, IEnumerable<T> e, string separator = "")
        {
            using (IEnumerator<T> enumerator = e.GetEnumerator())
            {
                if (enumerator.MoveNext())
                {
                    sb.Append(enumerator.Current);
                    while (enumerator.MoveNext())
                    {
                        sb.Append(separator).Append(enumerator.Current);
                    }
                }
 
                return sb;
            }
        }
 
        /// <summary>
        /// Returns true if the string is null, or the empty string ""
        /// Note: this will never throw a NullRef exception given that it is an extension method calling a static method
        /// </summary>
        /// <param name="s">String to test</param>
        /// <returns>True if the string is null or empty, false otherwise</returns>
        public static bool IsEmpty(this string s) => string.IsNullOrEmpty(s);
 
        /// <summary>
        /// Creates a substring from a starting and ending index
        /// </summary>
        /// <param name="s">String to substring</param>
        /// <param name="start">Starting index</param>
        /// <param name="end">Ending index</param>
        /// <returns>The resulting substring</returns>
        public static string SubStr(this string s, int start, int end) => s.Substring(start, (end - start) + 1);
        #endregion
 
        #region Number extensions
        /// <summary>
        /// Tests if the given number is pair or not
        /// </summary>
        /// <param name="n">Number to test</param>
        /// <returns>True if the number is pair, false otherwise</returns>
        public static bool IsPair(this int n) => (n & 1) == 0;
 
        /// <summary>
        /// Tests if the given number is pair or not
        /// </summary>
        /// <param name="n">Number to test</param>
        /// <returns>True if the number is pair, false otherwise</returns>
        public static bool IsPair(this long n) => (n & 1L) == 0;
 
        /// <summary>
        /// Real Modulus function over the integer, not a remainder function like the normal C# mod
        /// </summary>
        /// <param name="n">Left operand of the mod</param>
        /// <param name="m">Right operand of the mod</param>
        /// <returns>The Modulus of n and m, within [0, m - 1]</returns>
        public static int Mod(this int n, int m) => ((n % m) + m) % m;
 
        /// <summary>
        /// Real Modulus function over the integer, not a remainder function like the normal C# mod
        /// </summary>
        /// <param name="n">Left operand of the mod</param>
        /// <param name="m">Right operand of the mod</param>
        /// <returns>The Modulus of n and m, within [0, m - 1]</returns>
        public static long Mod(this long n, long m) => ((n % m) + m) % m;
 
        /// <summary>
        /// Returns the triangle number of the current number
        /// </summary>
        /// <param name="n">Integer to get the triangle number from</param>
        /// <returns>The resulting triangle number</returns>
        public static int Triangle(this int n) => (n * (n + 1)) / 2;
 
        /// <summary>
        /// Returns the triangle number of the current number
        /// </summary>
        /// <param name="n">Long to get the triangle number from</param>
        /// <returns>The resulting triangle number</returns>
        public static long Triangle(this long n) => (n * (n + 1L)) / 2L;
 
        /// <summary>
        /// Counts the amount of set bits (1s in the binary representation) of a given integer
        /// </summary>
        /// <param name="n">Integer to get the set bits from</param>
        /// <returns>Amount of set bits of the integer</returns>
        public static int SetBits(this int n)
        {
            n = n - ((n >> 1) & 0x55555555);
            n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
            return (((n + (n >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
        }
 
        /// <summary>
        /// Counts the amount of set bits (1s in the binary representation) of a given long
        /// </summary>
        /// <param name="n">Long to get the set bits from</param>
        /// <returns>Amount of set bits of the long</returns>
        public static long SetBits(this long n)
        {
            n = n - ((n >> 1) & 0x5555555555555555);
            n = (n & 0x3333333333333333) + ((n >> 2) & 0x3333333333333333);
            return (((n + (n >> 4)) & 0xF0F0F0F0F0F0F0F) * 0x101010101010101) >> 56;
        }
        #endregion
 
        #region Array extensions
        /// <summary>
        /// Does a binary search through the sorted array to find the requested value
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="value">Value to find</param>
        /// <returns>The index of the found element, or -1 if it wasn't found</returns>
        public static int BinarySearch<T>(this T[] array, T value) => Array.BinarySearch(array, value);
 
        /// <summary>
        /// Clears the array of all elements
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to clear</param>
        public static void Clear<T>(this T[] array) => Array.Clear(array, 0, array.Length);
 
        /// <summary>
        /// Determines if the array contains the given value
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="value">Value to find</param>
        /// <returns>True if the value was found, false otherwise</returns>
        public static bool Contains<T>(this T[] array, T value) => Array.IndexOf(array, value) != -1;
 
        /// <summary>
        /// Enumerates the contents of an ArraySegment
        /// </summary>
        /// <typeparam name="T">Type contained within the ArraySegment</typeparam>
        /// <param name="segment">Segment to enumerate</param>
        /// <returns>Enumerable of all the values contained in the ArraySegment</returns>
        public static IEnumerable<T> Enumerate<T>(this ArraySegment<T> segment)
        {
            int max = segment.Offset + segment.Count;
            for (int i = segment.Offset; i < max; i++)
            {
                yield return segment.Array[i];
            }
        }
 
        /// <summary>
        /// Sees if an elements matching the specified condition exists in the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="match">Matching function to apply</param>
        /// <returns>True if a matching element exists, false otherwise</returns>
        public static bool Exists<T>(this T[] array, Predicate<T> match) => Array.Exists(array, match);
 
        /// <summary>
        /// Finds the first element matching the given condition in the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="match">Matching function to apply</param>
        /// <returns>The first found element that satisfied the match, or default(T) if none did</returns>
        public static T Find<T>(this T[] array, Predicate<T> match) => Array.Find(array, match);
 
        /// <summary>
        /// Finds the last element matching the given condition in the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="match">Matching function to apply</param>
        /// <returns>The last found element that satisfied the match, or default(T) if none did</returns>
        public static T FindLast<T>(this T[] array, Predicate<T> match) => Array.FindLast(array, match);
 
        /// <summary>
        /// Applies an action to every member of the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to loop through</param>
        /// <param name="action">Action to apply on each member</param>
        public static void ForEach<T>(this T[] array, Action<T> action) => Array.ForEach(array, action);
 
        /// <summary>
        /// Generates all the subsets of the given array of a size greater than 1
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to get the subsets from</param>
        /// <returns>All the subsets of size 1 or greater from the array</returns>
        public static IEnumerable<List<T>> GetSubsets<T>(this T[] array)
        {
            int max = 1 << array.Length, l = array.Length - 1;
            for (int i = 1; i < max; i++)
            {
                if ((i & -i) == i) { continue; } //Exclude subsets of length 1
 
                List<T> subset = new List<T>(array.Length);
                subset.AddRange(array.Where((t, j) => (i & (1 << (l - j))) != 0));
                yield return subset;
            }
        }
 
        /// <summary>
        /// Finds the first index of the given value in the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="value">Value to find</param>
        /// <returns>The index of the value in the array, or -1 if it wasn't found</returns>
        public static int IndexOf<T>(this T[] array, T value) => Array.IndexOf(array, value);
 
        /// <summary>
        /// Finds the last index of the given value in the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to search into</param>
        /// <param name="value">Value to find</param>
        /// <returns>The last index of the value in the array, or -1 if it wasn't found</returns>
        public static int LastIndexOf<T>(this T[] array, T value) => Array.LastIndexOf(array, value);
 
        /// <summary>
        /// Reverses the array
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to reverse</param>
        /// <returns>The reversed array</returns>
        public static T[] Reverse<T>(this T[] array)
        {
            Array.Reverse(array);
            return array;
        }
 
        /// <summary>
        /// Sorts the array with the default comparer of T
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to sort</param>
        public static void Sort<T>(this T[] array) => Array.Sort(array);
 
        /// <summary>
        /// Sorts an array with the given comparison method
        /// </summary>
        /// <typeparam name="T">Type of elements in the array</typeparam>
        /// <param name="array">Array to sort</param>
        /// <param name="comparison">Comparison method to sort the array with</param>
        public static void Sort<T>(this T[] array, Comparison<T> comparison) => Array.Sort(array, comparison);
 
        /// <summary>
        /// Swap two elements in an array
        /// </summary>
        /// <typeparam name="T">Type of the array</typeparam>
        /// <param name="array">Aray to swap elements in</param>
        /// <param name="i">Index of the first element</param>
        /// <param name="j">Index of the second element</param>
        public static void Swap<T>(this T[] array, int i, int j)
        {
            T t = array[i];
            array[i] = array[j];
            array[j] = t;
        }
        #endregion
    }
}

Java:
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
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
        //Reader s=new Reader();
		// 	BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));
		// 	Writer w = new Writer(wr);
		//java.io.BufferedReader br = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
		 	int row = s.nextInt();
		 	int col = s.nextInt();
		 	int[][] mat = new int[row][col];
		 	int[] sol = new int[4];
		 	for(int i=0;i<row;i++)
		 	{
		 		for(int j=0;j<col;j++)
		 		{
		 			mat[i][j] = s.nextInt();
		 		}
		 	}
		 	for(int i=0;i<4;i++)
		 	{
		 		sol[i] = s.nextInt();
		 	}
		 	long modSumWithRowImpl = rowMax(sol[0],sol[1],mat,row,col,w);
		 	//w.writeLong(modSumWithRowImpl);
		 	long modSumWithColImpl = colMax(sol[2],sol[3],mat,row,col);
		 	//w.writeLong(modSumWithColImpl);
		 	w.writeLong(Math.max(modSumWithRowImpl, modSumWithColImpl));
		 	s.close();
		 	wr.close();
 
    }
    
     static long rowMax(int v1,int v2,int[][] mat,int row,int col,Writer w) throws IOException
	  {
		long finalMax=0;
		//BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));
		//Writer w = new Writer(wr);
	    //w.writeString("Playing with rows");
		for(int i=0;i<row;i++)
		{
			long maxSumWithV1=0,maxSumWithV2=0,maxSumNormal=0;
			for(int j=0;j<col;j++)
			{
			    maxSumWithV1=maxSumWithV1+Math.abs((mat[i][j]+v1));
				maxSumWithV2=maxSumWithV2+Math.abs(v2);
				maxSumNormal=maxSumNormal+Math.abs(mat[i][j]);
			}
			//w.writeLong(maxSumWithV1);
			//w.writeLong(maxSumWithV2);
			//w.writeLong(maxSumNormal);
			finalMax = finalMax + findMaxOfThree(maxSumWithV1,maxSumWithV2,maxSumNormal);
		}
		return finalMax;
		  
	  }
	  
	  static long colMax(int v3,int v4,int[][] mat,int row,int col)
	  {
		long finalMax=0;
		for(int j=0;j<col;j++)
		{
			long maxSumWithV3=0,maxSumWithV4=0,maxSumNormal=0;
			for(int i=0;i<row;i++)
			{
				maxSumWithV3= maxSumWithV3+Math.abs((mat[i][j]+v3));
				maxSumWithV4=maxSumWithV4+Math.abs(v4);
				maxSumNormal=maxSumNormal+Math.abs(mat[i][j]);
			}
			finalMax = finalMax + findMaxOfThree(maxSumWithV3,maxSumWithV4,maxSumNormal);
		}
		return finalMax;
	  }
	  static long findMaxOfThree(long max1,long max2,long max3)
	  {
		  return Math.max(Math.max(max1, max2), max3);
	  }
	  static class Reader
	    {
	        final private int BUFFER_SIZE = 1 << 16;
	        private DataInputStream din;
	        private byte[] buffer;
	        private int bufferPointer, bytesRead;
	 
	        public Reader()
	        {
	            din = new DataInputStream(System.in);
	            buffer = new byte[BUFFER_SIZE];
	            bufferPointer = bytesRead = 0;
	        }
	 
	        public Reader(String file_name) throws IOException
	        {
	            din = new DataInputStream(new FileInputStream(file_name));
	            buffer = new byte[BUFFER_SIZE];
	            bufferPointer = bytesRead = 0;
	        }
	 
	        public String readLine() throws IOException
	        {
	            byte[] buf = new byte[64]; // line length
	            int cnt = 0, c;
	            while ((c = read()) != -1)
	            {
	                if (c == '\n')
	                    break;
	                buf[cnt++] = (byte) c;
	            }
	            return new String(buf, 0, cnt);
	        }
	 
	        public int nextInt() throws IOException
	        {
	            int ret = 0;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	            do
	            {
	                ret = ret * 10 + c - '0';
	            }  while ((c = read()) >= '0' && c <= '9');
	 
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        public long nextLong() throws IOException
	        {
	            long ret = 0;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	            do {
	                ret = ret * 10 + c - '0';
	            }
	            while ((c = read()) >= '0' && c <= '9');
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        public double nextDouble() throws IOException
	        {
	            double ret = 0, div = 1;
	            byte c = read();
	            while (c <= ' ')
	                c = read();
	            boolean neg = (c == '-');
	            if (neg)
	                c = read();
	 
	            do {
	                ret = ret * 10 + c - '0';
	            }
	            while ((c = read()) >= '0' && c <= '9');
	 
	            if (c == '.')
	            {
	                while ((c = read()) >= '0' && c <= '9')
	                {
	                    ret += (c - '0') / (div *= 10);
	                }
	            }
	 
	            if (neg)
	                return -ret;
	            return ret;
	        }
	 
	        private void fillBuffer() throws IOException
	        {
	            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
	            if (bytesRead == -1)
	                buffer[0] = -1;
	        }
	 
	        private byte read() throws IOException
	        {
	            if (bufferPointer == bytesRead)
	                fillBuffer();
	            return buffer[bufferPointer++];
	        }
	 
	        public void close() throws IOException
	        {
	            if (din == null)
	                return;
	            din.close();
	        }
	    }
	 
	 	static class Writer{
			
			BufferedWriter wr =  null;
			
			Writer(){}
			
			public Writer(BufferedWriter wr) {
				this.wr = wr;
			}
	 
			public void writeInt(int value) throws IOException {
				wr.write(value + "\n");
			}
			
			public void writeString(String value) throws IOException {
				wr.write(value + "\n");
			}
			
			public void writeLong(Long value) throws IOException {
				wr.write(value + "\n");
			}
			
			public void flush() throws IOException {
				wr.flush();
				wr.close();
			}
		}
}

Java 8:
import java.util.Scanner;
import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.Math.*;
 
 class Main
{	public static void main(String args[]) throws Exception
	{
		InputReader sc=new InputReader(System.in);		
		PrintWriter out=new PrintWriter(System.out);
		//HashMap<Integer,Integer> h=new HashMap<Integer,Integer>();
		int n=sc.nextInt();
		int m=sc.nextInt();
		long[][] ar=new long[n][m];
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			ar[i][j]=sc.nextLong();
		long v1=sc.nextLong();long v2=sc.nextLong();long v3=sc.nextLong();long v4=sc.nextLong();
		long max1=0;
		for(int i=0;i<n;i++){
			long sum1=0,sum2=0;
			for(int j=0;j<m;j++){
				sum1+=Math.abs(ar[i][j]);
				sum2+=Math.abs(ar[i][j]+v1);
			}
			max1+=Math.max(sum2,Math.max(sum1,v2*m));
		}
		long max2=0;
		for(int i=0;i<m;i++){
			long sum1=0,sum2=0;
			for(int j=0;j<n;j++){
				sum1+=Math.abs(ar[j][i]);
				sum2+=Math.abs(ar[j][i]+v3);
			}
			max2+=Math.max(sum2,Math.max(sum1,v4*n));
		}
		out.println(Math.max(max1,max2));
		out.close();
	}
	 
        
    
   static long mul(long a,long b){
	   return a*b;
   }
    
 
   public static int lower_bound_binary(int[] a,int x){
				int low = 0;
        		int end = a.length ;
        
       
        		while (low < end) {
        		  int mid = (low + end) >> 1;
            	  if (x <a[mid]) 
			
                	end = mid;
        		  
        		  else 
                		low = mid+1;
				}
				return low;
				
 
}
public static int upper_bound_binary(int[] a,int x){
				int low=0;
				int end=a.length;
				while(low<end){
					int mid=(low+end)>>1;
					if(x>a[mid])
						low=mid+1;
					else
						end=mid;
				}
			return low;
 
}
  
 
 
	static int visit[];
	static Stack<Integer> temp1;
	static Stack<Long> temp2;
	static class InputReader
	{
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;
		
		public InputReader(InputStream stream)
		{
			this.stream = stream;
		}
		
		public int read()
		{
			if (numChars==-1) 
				throw new InputMismatchException();
			
			if (curChar >= numChars)
			{
				curChar = 0;
				try 
				{
					numChars = stream.read(buf);
				}
				catch (IOException e)
				{
					throw new InputMismatchException();
				}
				
				if(numChars <= 0)				
					return -1;
			}
			return buf[curChar++];
		}
	 
		public String nextLine()
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
		}
		public int nextInt()
		{
			int c = read();
			
			while(isSpaceChar(c)) 
				c = read();
			
			int sgn = 1;
			
			if (c == '-') 
			{
				sgn = -1;
				c = read();
			}
			
			int res = 0;
			do 
			{
				if(c<'0'||c>'9') 
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			while (!isSpaceChar(c)); 
			
			return res * sgn;
		}
		
		public long nextLong() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') 
			{
				sgn = -1;
				c = read();
			}
			long res = 0;
			
			do 
			{
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			while (!isSpaceChar(c));
				return res * sgn;
		}
		
		public double nextDouble() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') 
			{
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') 
			{
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, nextInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') 
			{
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) 
				{
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, nextInt());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}
		
		public String readString() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do 
			{
				res.appendCodePoint(c);
				c = read();
			} 
			while (!isSpaceChar(c));
			
			return res.toString();
		}
	 
		public boolean isSpaceChar(int c) 
		{
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
	 
		public String next() 
		{
			return readString();
		}
		
		public interface SpaceCharFilter 
		{
			public boolean isSpaceChar(int ch);
		}
		
 
		
 
	
	}
	static class OutputWriter {
		private final PrintWriter writer;
 
		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}
 
		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}
 
		public void print(Object...objects) {
			for (int i = 0; i < objects.length; i++) {
				if (i != 0)
					writer.print(' ');
				writer.print(objects[i]);
			}
		}
 
		public void println(Object...objects) {
			print(objects);
			writer.println();
		}
 
		public void close() {
			writer.close();
		}
 
		public void flush() {
			writer.flush();
		}
 
		}
	 static	class myarray {
 
		public static int[] intarray(InputReader sc, int size) {
			int[] array = new int[size];
			for (int i = 0; i < size; i++)
				array[i] = sc.nextInt();
			return array;
		}
		public static long[] longarray(InputReader sc, int size) {
			long[] array = new long[size];
			for (int i = 0; i < size; i++)
				array[i] = sc.nextLong();
			return array;
		}
 
	}
 
	  ////////////////////////////////////////////////////////////////////
    //      Number Theory
    
    long pow(long a,long b,long mod){
		if(b == 0)	return 1;
		long t = pow(a,b>>1,mod);
		t = (t * t) % mod;
		if((b & 1) == 1)	t = (t * a);
		if(t >= mod)	t %= mod;
		return t;
	}
    
    int divisor(long x,long[] a){
        long limit = x;
        int numberOfDivisors = 0;
 
        for (int i=1; i < limit; ++i) {
            if (x % i == 0) {
                limit = x / i;
                if (limit != i) {
                    numberOfDivisors++;
                }
                numberOfDivisors++;
            }
        }
        return numberOfDivisors;
    }
    
    void findSubsets(int array[]){
        long numOfSubsets = 1 << array.length; 
        for(int i = 0; i < numOfSubsets; i++){    
            @SuppressWarnings("unused")
			int pos = array.length - 1;
            int bitmask = i;
            while(bitmask > 0){     
                if((bitmask & 1) == 1)
//                    ww.print(array[pos]+" ");
                bitmask >>= 1;
                pos--;
            }
//            ww.println();
        }
    }
    
    
    public static long gcd(long a, long b){
        return b == 0 ? a : gcd(b,a%b);
    }
    
  
    public static long lcm(int a,int b, int c){
        return lcm(lcm(a,b),c);
    }
    
    public static long lcm(long a, long b){
        return (a*b/gcd(a,b));
    }
    
    public static long invl(long a, long mod) {
        long b = mod;
        long p = 1, q = 0;
        while (b > 0) {
            long c = a / b;
            long d;
            d = a;
            a = b;
            b = d % b;
            d = p;
            p = q;
            q = d - c * q;
        }
        return p < 0 ? p + mod : p;
    }
    static  boolean[]  sieve(int n) {
        boolean prime[] = new boolean[n+1];
        for(int i=0;i<n;i++)
            prime[i] = true;
         
        for(int p = 2; p*p <=n; p++)
        {
            // If prime[p] is not changed, then it is a prime
            if(prime[p] == true)
            {
                // Update all multiples of p
                for(int i = p*2; i <= n; i += p)
                    prime[i] = false;
            }
        }
         
        return prime;
    }
     
    ////////////////////////////////////////////////////////////////////

 
}

Javascript(Node.js):
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
     var n = input[0].split(' ')[0];
     var m = input[0].split(' ')[1];
 
     var array = [];
     for(var t = 0;t<n;t++){
         array[t] = input[t+1].split(' ').map(Number);
     }
     var v = input[Number(n)+1].split(' ').map(Number);
 
     var sum, msum;
     var rsum = 0;
     for(var i = 0; i < n; i++  ){
          sum = 0;
          msum = 0;
         for(var j = 0; j < m; j++){
             sum += Math.abs(array[i][j]);
             msum += Math.abs(array[i][j]+v[0]);
         }
         rsum += Math.max(Math.abs(v[1]) * m, sum, msum);
     }
     var csum = 0;
     for (var i = 0; i < m; i++){
          sum =0;
          msum = 0;
         for(var j =0; j < n;j++){
             //console.log(i);
             sum += Math.abs(array[j][i]);
             msum += Math.abs(array[j][i]+v[2]);
         }
         csum += Math.max(Math.abs(v[3])*n , sum,msum);
     }
      //console.log(csum);
     console.log(Math.max(csum,rsum));
     
}

Pascal:
Program HiHere;
VAR n,m,i,j,s1,s2,v1,v2,v3,v4,s,max,sf:int64; a:array[1..1001,1..1001] of int64;
Begin
Readln(n,m);
for i:=1 to n do
Begin
for j:=1 to m do
Begin
Read(a[i,j]);
end;
Readln;
end;
Readln(v1,v2,v3,v4);
 
for i:=1 to n do
Begin
s:=0;
sf:=0;
for j:=1 to m do
Begin
s:=s + abs(a[i,j]);
sf:=sf + abs(a[i,j] + v1);
end;
if (s > sf) then max:=s else max:=sf;
if (abs(m*v2) > max) then max:=abs(m*v2);
s1:=s1 + max;
//Writeln(max);
end;
 
for i:=1 to m do
Begin
s:=0;
sf:=0;
for j:=1 to n do
Begin
s:=s + abs(a[j,i]);
sf:=sf + abs(a[j,i] + v3);
end;
if (s > sf) then max:=s else max:=sf;
if (abs(n*v4) > max) then max:=abs(n*v4);
s2:=s2 + max;
//Writeln(max);
end;
 
if (s1 > s2) then Writeln(s1) else Writeln(s2);
Readln;
END.

PHP:
<?php

// Sample code to perform I/O:
//fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
//echo "Hi, ".$name.".\n";                // Writing output to STDOUT
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

 
// Write your code here
 
$maxRows = $maxCols = 0;
fscanf(STDIN, "%d %d", $rowNum,$colNum);
$nums = $v = array();
for($i=0;$i<$rowNum;$i++){
    array_push($nums,explode(' ',trim(fgets(STDIN))));
}
$colsArray = $nums;
$v = explode(' ',trim(fgets(STDIN)));
for($i=0;$i<$rowNum;$i++){
    $rowSum = 0;
    $rowSum1 = 0;
    for($j=0;$j<$colNum;$j++){
        $rowSum1 = $rowSum1 + abs($nums[$i][$j]);
        $rowSum  = $rowSum  + abs($nums[$i][$j] + $v[0]);
    }
    if($rowSum >= abs($colNum * $v[1]) && $rowSum > $rowSum1){
        for($j=0;$j<$colNum;$j++){
            $nums[$i][$j] = abs($nums[$i][$j] + $v[0]);
        }
    }
    else{ if (abs($colNum * $v[1]) > $rowSum && abs($colNum * $v[1]) > $rowSum1){
        for($j=0;$j<$colNum;$j++){
            $nums[$i][$j] = abs($v[1]);
        }
    }else{
    for($j=0;$j<$colNum;$j++){
        $nums[$i][$j] = abs($nums[$i][$j]);
    }
    }
    }
}
for($i=0;$i<$colNum;$i++){
    $colSum  = 0;
    $colSum1 = 0;
    for($j=0;$j<$rowNum;$j++){
        $colSum1 = $colSum1 + abs($colsArray[$j][$i]);
        $colSum = $colSum + abs($colsArray[$j][$i] + $v[2]);
    }
    if($colSum >= abs($rowNum * $v[3]) && $colSum > $colSum1){
        for($j=0;$j<$rowNum;$j++){
            $colsArray[$j][$i] = abs($colsArray[$j][$i] + $v[2]);
            
        }
    }else{ if (abs($rowNum * $v[3]) > $colSum && abs($rowNum * $v[3]) > $colSum1){
        for($j=0;$j<$rowNum;$j++){
            $colsArray[$j][$i] = abs($v[3]);
            
        }
    }else{
        for($j=0;$j<$rowNum;$j++){
            $colsArray[$j][$i] = abs($colsArray[$j][$i]);
            
        }
    }
    }
}
for($i=0;$i<$rowNum;$i++){
    for($j=0;$j<$colNum;$j++){
        $maxRows += $nums[$i][$j];
        $maxCols += $colsArray[$i][$j];
    }
}
echo ($maxRows > $maxCols)?$maxRows:$maxCols;
 
?>

Python:
RI = lambda: map(int, raw_input().split())
 
def calc(t, x, y):
    s1, s2, s3 = 0, 0, abs(y) * len(t)
    for z in t:
        s1 += abs(z)
        s2 += abs(z + x)
    return max(s1, s2, s3)
 
n, m = RI()
a = [RI() for _ in range(n)]
v1, v2, v3, v4 = RI()
ans1 = 0
for t in a:
    ans1 += calc(t, v1, v2)
a = zip(*a)
ans2 = 0
for t in a:
    ans2 += calc(t, v3, v4)
print max(ans1, ans2)

Python 3:
import numpy as np
 
# Write your code here
M=[]
score=0
n,p=list(map(int,input().split()))
for i in range(n):
    M.append(list(map(int,input().split())))
v1,v2,v3,v4 = list(map(int,input().split()))
M=np.array(M)
# print(M)
 
M1=M.copy()
 
for i in range(n):
    row=M[i,:]
    upd_score=np.abs(v2*p)
    add_score=np.sum(np.abs(row+v1))
    sorted_score=sorted([upd_score,add_score,np.sum(np.abs(row))])
    if sorted_score[-1]==upd_score:
        M[i,:]=v2
    elif sorted_score[-1] == add_score:
        M[i,:]=row+v1
# print(M)
 
for j in range(p):
    col=M1[:,j]
    upd_score=np.abs(v4*n)
    add_score=np.sum(np.abs(col+v3))
    sorted_score=sorted([upd_score,add_score,np.sum(np.abs(col))])
    if sorted_score[-1]==upd_score:
        M1[:,j]=v4        
    elif sorted_score[-1] == add_score:
        M1[:,j]=col+v3
 
# print(M1)
 
F=np.sum(np.abs(M))
F1=np.sum(np.abs(M1))
 
print(F if F > F1 else F1)
 
# print(F,F1)

Ruby:
n, m = gets.split(' ').map(&:to_i)
 
arr = Array.new(n)
 
n.times do |i|
    arr[i] = gets.split(' ').map(&:to_i)
end
v1,v2,v3,v4 = gets.split(' ').map(&:to_i)
sum_v2 =  v2.abs*m
sum_v4 = v4.abs*n
 
sum_rows = 0
(0..n-1).each do |i|
   sum_plain = arr[i].map(&:abs).inject(:+)
   sum_v1 = arr[i].map{|e| (e+v1).abs }.inject(:+)
   #puts "sum_rows = #{sum_rows}, sum_plain = #{sum_plain}, sum_v1 = #{sum_v1}, sum_v2 = #{sum_v2}"
   sum_rows += [sum_plain,sum_v1,sum_v2].max
end
 
sum_cols = 0
(0..m-1).each do |i|
   sum_plain = arr.map{|e| e[i].abs}.inject(:+)
   sum_v3 = arr.map{|e| (e[i]+v3).abs }.inject(:+)
   #puts "sum_cols = #{sum_cols}, sum_plain = #{sum_plain}, sum_v3 = #{sum_v3}, sum_v4 = #{sum_v4}"
   sum_cols += [sum_plain,sum_v3,sum_v4].max
end
 
puts [sum_rows,sum_cols].max


*/

