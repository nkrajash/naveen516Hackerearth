/* All Tracks --> Data Structures  -->  Arrays -->  1-D -->  Problem --> Maximize the Earning
Tag(s): Easy

Napoleon choosed a city for Advertising his company's product. There are S streets in that city. Each day he travels one street. 
There are N buildings in a street which are located at points 1,2,3..N(respectively). Each building has some height(Say h meters). Napoleon stands at point 0. 
His height is 0.5m. Now Napoleon starts communicating with the people of each building. 
He can communicate with people of a particular building only if he can see that building. 
If he succeed to communicate with any particular building then his boss gives him R rupees. 
i.e. if he communicates with K buildings in a day, then he will earn K*R rupees. 
Now Napoleon wants to know his maximum Earning for each day.

Note: All the points are on Strainght Line and Napoleon is always standing at point 0.

Input:
First line of input contains an integer S , denoting no of streets in the city.
Details for each street is described in next two lines.
First line contains two integers N  and R,  denoting no of buildings in the Street and earning on communicating with a building.
Second line contains N integers, denoting height of  building.

Output:
Print S Lines, each containing maximum earning in ith street.
    
Constraints:
1<=N<=10^4
1<=h<=10^9
1<=S<=100
1<=R<=10^4


SAMPLE INPUT 
2
6 3
8 2 3 11 11 10
5 12
12 20 39 45 89

SAMPLE OUTPUT 
6
60

Explanation:
There are two streets in the city.
The first street has 6 buildings and the earning of Napoleon for communicating with each building is 3 rupees .
Height of buildings are 8,2,3,11,11,10  respectively.
As Chef is standing at point 0, he will be able to see only 1st and 4th building.
So his total earning will be 3*2 =6 rupees in that street
Similarly for 2nd street his earning will be 60 rupees.

My solution:

#include <stdio.h>
#define N 100001

int main(){
	int n,S,R,i,j,K=0;
	long h[N],temp=0;
	scanf("%d",&S);
	for(i=0;i<S;i++){
	    scanf("%d%d",&n,&R);
	    for(j=0;j<n;j++){
	        scanf("%d",&h[j]);
            if(h[j]>temp){
                temp = h[j];
                K++;
            }
	    }
	    printf("%ld\n",K*R);
	    K=temp=0;
	}
	return 0;
}

/* Editorial:
Author : Vikram Kumar
Editorialist : Gaurang Bansal
Expected Difficulty : Easy
Editorial :
Since we want to maximise the earnings of Napolean, we have to find out how many buildings napolean will able to see.
And once we get the count of buildings we will multiply that by  k, so the total earnings will be count*k.
Initially, initialise count to 0.
Now, we will use a stack in this problem.We will push the first height in the stack irrespective of it's length and increment count by 1.
Now only those heights will be inserted into the stack whose magnitude is strictly greater than height of building at the top of the stack and count will be incremented by 1.
 
We can then print the answer for each test case on a new line.

Sample c++ code :
        for(long long i=0;i<n;i++){
            cin>>x;
            if(i==0){
               s.push(x);//pushing first element to stack
               count++;
            }
            //check if next one is greater than top element of stack
            if(i>0){
                if(x>s.top()){
                    s.push(x);
                    count++;
                }
            }
            
        }
        cout<<count*k<<endl;
 

The time complexity of each test is O(N) resulting in an overall complexity of  O(N*S) where S is the number of test cases.

Editorialist's Code :

#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int a=0;a<t;a++){
        long long n,k;
        cin>>n;
        cin>>k;
        stack<long long> s;
        long long x;
        long long count=0;//count initialise to 0.
        for(long long i=0;i<n;i++){
            cin>>x;
            if(i==0){
               s.push(x);//pushing first element to stack
               count++; 
            }
            //check if next one is greater than top element of stack
            if(i>0){
                if(x>s.top()){
                    s.push(x);
                    count++;
                }
            }
            
        }
        cout<<count*k<<endl;
        
    }
}



#include <iostream>

using namespace std;

int main() {

int s;
cin>>s;
while(s>0)
{
s--;
int n,r;
cin>>n>>r;
int *a=new int[n];
for(int i=0;i<n;i++)
cin>>a[i];

int count=1;
int temp=a[0];
for(int i=1;i<n;i++)
{

if(a[i]>temp)
{ count++;
temp=a[i];
}


}

int res=r*count;
cout<<res<<endl;


delete []a;

}


}

*/

/*Best Submissions:
C:
#include <stdio.h>
#define ll long long
ll scan() 
{
    register int c; 
    ll number = 0;
    c = getchar_unlocked(); 
    for (; (c>47 && c<58); c=getchar_unlocked()) 
        number = number *10 + c - 48; 
    return number;
} 
int main()
{
    int t;      t=scan();
    while(t--)
    {
        int n, r;    ll arr[100001], m = 0, max = 0;
        n=scan();    r=scan();
        for(int i=0; i<n; i++)
        {
            arr[i] = scan();
            if(arr[i] > max)
            {
                max = arr[i];
                m++;
            }
        }
        printf("%lld\n",r*m);
    }
}

C++:
#include <stdio.h>
#define ll long long
ll scan() 
{
    register int c; 
    ll number = 0;
    c = getchar_unlocked(); 
    for (; (c>47 && c<58); c=getchar_unlocked()) 
        number = number *10 + c - 48; 
    return number;
} 
int main()
{
    int t;      t=scan();
    while(t--)
    {
        int n, r;    ll arr[100001], m = 0, max = 0;
        n=scan();    r=scan();
        for(int i=0; i<n; i++)
        {
            arr[i] = scan();
            if(arr[i] > max)
            {
                max = arr[i];
                m++;
            }
        }
        printf("%lld\n",r*m);
    }
}


C++14:
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define fast ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL)
using namespace std;
ll scan() 
{
    register int c; 
    ll number = 0;
    c = getchar_unlocked(); 
    for (; (c>47 && c<58); c=getchar_unlocked()) 
        number = number *10 + c - 48; 
    return number;
} 
int main()
{
    int t;      t=scan();
    while(t--)
    {
        int n, r;    ll arr[100001], m = 0, max = 0;
        n=scan();    r=scan();
        for(int i=0; i<n; i++)
        {
            arr[i] = scan();
            if(arr[i] > max)
            {
                max = arr[i];
                m++;
            }
        }
        cout<<m*r<<endl;
    }
}

C#:
//Comment/uncomment this if there are one/multiple test cases
#define TESTCASES
 
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using HackerEarth.Utils;
using static HackerEarth.Utils.Utils;
 
namespace HackerEarth
{
    /// <summary>
    /// Main class
    /// </summary>
    public static class Program
    {
        /// <summary>
        /// Solution class
        /// </summary>
        public class Solution
        {
            #region Constructors
            /// <summary>
            /// Creates a new Solution
            /// </summary>
            public Solution()
            {
                //Any initialization should be done here
            }
            #endregion
 
            #region Solution
            /// <summary>
            /// Solution
            /// </summary>
            public void Solve()
            {
                int n = Console.NextInt(), r = Console.NextInt();
                Console.SkipNextLine();
 
                int highest = Console.NextInt(), profit = r;
                foreach (int building in Console.EnumerateInts(n - 1))
                {
                    if (building > highest)
                    {
                        highest = building;
                        profit += r;
                    }
                }
 
                Console.WriteLine(profit);
            }
            #endregion
        }
        
        #region Constants
        /// <summary>
        /// Fast Console IO helper
        /// </summary>
        private static ConsoleHelper Console { get; } = new ConsoleHelper();
        #endregion
 
        #region Main
        /// <summary>
        /// Main method - Launches solver
        /// </summary>
        private static void Main()
        {
#if DEBUG
            Stopwatch timer = Stopwatch.StartNew();
#endif //DEBUG
            using (Console)
            {
                Solution solution = new Solution();
#if TESTCASES
                TestCases(solution);
#else //TESTCASES
                solution.Solve();
#endif //TESTCASES
            }
#if DEBUG
            timer.Stop();
            using (StreamWriter file = File.AppendText(@"..\..\output.txt"))
            {
                file.WriteLine($"\r\n\r\nTotal run time: {timer.Elapsed.TotalSeconds:0.000}s");
            }
#endif //DEBUG
        }
 
#if TESTCASES
        /// <summary>
        /// Solves the problem for multiple test cases
        /// </summary>
        private static void TestCases(Solution solution)
        {
            int t = Console.NextInt();
            Console.SkipNextLine();
 
            for (; t > 0; t--)
            {
                solution.Solve();
            }
        }
#endif //TESTCASES
        #endregion
    }
 
    namespace Utils
    {
        /// <inheritdoc />
        /// <summary>
        /// Fast Console IO helper
        /// </summary>
        [DebuggerStepThrough]
        internal sealed class ConsoleHelper : IDisposable
        {
            #region Constants
            /// <summary>
            /// The standard input and output buffers size (2^20, 1Mb)
            /// </summary>
            private const int baseSize = 1048576;
            /// <summary>
            /// Integer out string conversion buffer
            /// </summary>
            private static readonly char[] numBuffer = new char[20];
            #endregion
 
            #region Fields
            private readonly BufferedStream inStream; // Buffered console input stream
            private readonly StreamWriter outStream; // Buffered console output stream
 
            private readonly byte[] inBuffer; // Input buffer 
            private int inputIndex; // Input buffer current index
            private int bufferEnd; // Input buffer ending index
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
            /// <inheritdoc />
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
                //On disk test mode
                this.inStream = new BufferedStream(File.OpenRead(@"..\..\input.txt"), bufferSize);
                this.outStream = new StreamWriter(File.Create(@"..\..\output.txt", bufferSize), Encoding.ASCII, bufferSize);
#else //DEBUG
            //Submission mode
            this.inStream = new BufferedStream(Console.OpenStandardInput(bufferSize), bufferSize); // Submission stream
            this.outStream = new StreamWriter(Console.OpenStandardOutput(bufferSize), Encoding.ASCII, bufferSize);
#endif //DEBUG
 
                //Set fields
                this.inBuffer = new byte[bufferSize];
                this.inputIndex = this.bufferEnd = 0;
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
 
            /// <summary>
            /// Takes a signed int value and copies it's characters at the end of the integer char buffer
            /// </summary>
            /// <param name="n">Int to write to the buffer</param>
            /// <returns>Head index at which the buffer's writing starts</returns>
            private static int GetIntBuffer(int n)
            {
                int head = 20;
                bool neg;
                if (n < 0)
                {
                    neg = true;
                    n = -n;
                }
                else { neg = false; }
 
                do
                {
                    numBuffer[--head] = (char)((n % 10) + 48);
                    n /= 10;
                }
                while (n > 0);
 
                if (neg) { numBuffer[--head] = '-'; }
                return head;
            }
 
            /// <summary>
            /// Takes a signed long value and copies it's characters at the end of the integer char buffer
            /// </summary>
            /// <param name="n">Long to write to the buffer</param>
            /// <returns>Head index at which the buffer's writing starts</returns>
            private static int GetLongBuffer(long n)
            {
                int head = 20;
                bool neg;
                if (n < 0L)
                {
                    neg = true;
                    n = -n;
                }
                else { neg = false; }
 
                do
                {
                    numBuffer[--head] = (char)((n % 10L) + 48L);
                    n /= 10L;
                }
                while (n > 0L);
 
                if (neg) { numBuffer[--head] = '-'; }
                return head;
            }
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
                // If we reach the end of the buffer, load more data
                if (this.inputIndex >= this.bufferEnd)
                {
                    this.inputIndex = this.inputIndex - this.bufferEnd;
                    this.bufferEnd = this.inStream.Read(this.inBuffer, 0, this.BufferSize);
 
                    // If nothing was added, add a null char at the start
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
 
                // Append all characters
                StringBuilder sb = new StringBuilder().Append((char)b);
                b = Peek();
                while (ValidateCharNoSpace(b))
                {
                    // Peek to not consume terminator
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
                // Skip invalids
                byte b = SkipInvalid();
                ValidateEndline(b);
 
                // Verify for negative
                bool neg = false;
                if (b == '-')
                {
                    neg = true;
                    b = Read();
                }
 
                // Get first digit
                if (!ValidateNumber(b)) { throw new FormatException("Integer parsing has failed because the string contained invalid characters"); }
 
                int n = b - '0';
                b = Peek();
                while (ValidateNumber(b))
                {
                    // Peek to not consume terminator, and check for overflow
                    n = checked((n << 3) + (n << 1) + (b - '0'));
                    Skip();
                    b = Peek();
                }
                // If the character causing the exit is a valid ASCII character, the integer isn't correct formatted
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
 
                // Verify negative
                bool neg = false;
                if (b == '-')
                {
                    neg = true;
                    b = Read();
                }
 
                // Get first digit
                if (!ValidateNumber(b)) { throw new FormatException("Integer parsing has failed because the string contained invalid characters"); }
 
                long n = b - '0';
                b = Peek();
                while (ValidateNumber(b))
                {
                    // Peek to not consume terminator, and check for overflow
                    n = checked((n << 3) + (n << 1) + (b - '0'));
                    Skip();
                    b = Peek();
                }
                // If the character causing the exit is a valid ASCII character, the long isn't correct formatted
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
            /// Returns the next n long values on the same line in an array
            /// </summary>
            /// <param name="n">Number of values to seek</param>
            /// <exception cref="FormatException">If the text is not a valid long</exception>
            /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
            /// <exception cref="OverflowException">If the value is too large for long</exception>
            /// <exception cref="OutOfMemoryException">If the created array is too large for the system memory</exception>
            /// <returns>The n long values in an array</returns>
            public long[] NextLongs(int n)
            {
                long[] array = new long[n];
                for (int i = 0; i < n; i++)
                {
                    array[i] = NextLong();
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
                    // Consume newline and return empty string
                    Skip();
                    return string.Empty;
                }
 
                // Read all the characters until the next linefeed
                StringBuilder sb = new StringBuilder().Append((char)b);
                b = Read();
                while (!IsEndline(b))
                {
                    // Don't append special characters, but don't exit
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
            /// Enumerates all the special character separated tokens on the current line
            /// </summary>
            /// <returns>An enumerable of all the tokens on the current line</returns>
            public IEnumerable<string> EnumerateTokens()
            {
                StringBuilder sb = new StringBuilder();
                for (char c = NextChar(); !IsEndline(c); c = NextChar())
                {
                    if (ValidateCharNoSpace(c)) { sb.Append(c); }
                    else if (sb.Length > 0)
                    {
                        yield return sb.ToString();
                        sb.Clear();
                    }
                }
 
                if (sb.Length > 0)
                {
                    yield return sb.ToString();
                }
            }
 
            /// <summary>
            /// Assures we are not trying to read more data on the line that there exists
            /// </summary>
            /// <param name="b">Byte data to verify</param>
            /// <exception cref="InvalidOperationException">If there is no more data on the line being read</exception>
            private void ValidateEndline(byte b)
            {
                // If empty char
                if (b == 0)
                {
                    // Go back a char and throw
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
                    // Return empty char if we meet an linefeed or empty char
                    if (IsEndline(b)) { return 0; }
                }
 
                return Read();
            }
 
            /// <summary>
            /// Writes the given char to the console output
            /// </summary>
            /// <param name="c">Character to write</param>
            public void Write(char c) => this.outStream.Write(c);
 
            /// <summary>
            /// Writes the given char buffer to the console output
            /// </summary>
            /// <param name="buffer">Char buffer to write</param>
            public void Write(char[] buffer) => this.outStream.Write(buffer);
 
            /// <summary>
            /// Writes the given string to the console output
            /// </summary>
            /// <param name="s">String to write</param>
            public void Write(string s) => this.outStream.Write(s);
 
            /// <summary>
            /// Writes the given integer to the console output
            /// </summary>
            /// <param name="n">Integer to write</param>
            public void Write(int n)
            {
                int head = GetIntBuffer(n);
                this.outStream.Write(numBuffer, head, 20 - head);
            }
 
            /// <summary>
            /// Writes the given long to the console output
            /// </summary>
            /// <param name="n">Long to write</param>
            public void Write(long n)
            {
                int head = GetLongBuffer(n);
                this.outStream.Write(numBuffer, head, 20 - head);
            }
 
            /// <summary>
            /// Writes the contents of the StringBuilder to the console output
            /// </summary>
            /// <param name="sb">StringBuilder to write to the output</param>
            public void Write(StringBuilder sb) => this.outStream.Write(sb.ToCharArray());
 
            /// <summary>
            /// Writes the given object to the console output using the object's ToString method
            /// </summary>
            /// <param name="o">Object to write</param>
            public void Write(object o) => this.outStream.Write(o);
 
            /// <summary>
            /// Writes a sequence to the console output with the given string separator
            /// </summary>
            /// <typeparam name="T">Type of elements in the sequence</typeparam>
            /// <param name="e">Sequence to print</param>
            /// <param name="separator">String separator between each element, defaults to the empty string</param>
            public void Write<T>(IEnumerable<T> e, string separator = "") => this.outStream.Write(new StringBuilder().AppendJoin(e, separator).ToCharArray());
 
            /// <summary>
            /// Writes a sequence to the console output with the given string separator
            /// </summary>
            /// <typeparam name="T">Type of elements in the sequence</typeparam>
            /// <param name="e">Sequence to print</param>
            /// <param name="separator">Character separator between each element</param>
            public void Write<T>(IEnumerable<T> e, char separator) => this.outStream.Write(new StringBuilder().AppendJoin(e, separator).ToCharArray());
 
            /// <summary>
            /// Writes a linefeed to the console output
            /// </summary>
            public void WriteLine() => this.outStream.WriteLine();
 
            /// <summary>
            /// Writes the given char to the console output, followed by a linefeed
            /// </summary>
            /// <param name="c">Character to write</param>
            public void WriteLine(char c) => this.outStream.WriteLine(c);
 
            /// <summary>
            /// Writes the given char buffer to the console output, followed by a linefeed
            /// </summary>
            /// <param name="buffer">Char buffer to write to the output</param>
            public void WriteLine(char[] buffer) => this.outStream.WriteLine(buffer);
 
            /// <summary>
            /// Writes the given string to the console output, followed by a linefeed
            /// </summary>
            /// <param name="s">String to write</param>
            public void WriteLine(string s) => this.outStream.WriteLine(s);
 
            /// <summary>
            /// Writes the given integer to the console output, followed by a linefeed
            /// </summary>
            /// <param name="n">Integer to write</param>
            public void WriteLine(int n)
            {
                int head = GetIntBuffer(n);
                this.outStream.WriteLine(numBuffer, head, 20 - head);
            }
 
            /// <summary>
            /// Writes the given long to the console output, followed by a linefeed
            /// </summary>
            /// <param name="n">Long to write</param>
            public void WriteLine(long n)
            {
                int head = GetLongBuffer(n);
                this.outStream.WriteLine(numBuffer, head, 20 - head);
            }
 
            /// <summary>
            /// Writes the contents of the StringBuilder to the console output, followed by a linefeed
            /// </summary>
            /// <param name="sb">StringBuilder to write to the output</param>
            public void WriteLine(StringBuilder sb) => this.outStream.WriteLine(sb.ToCharArray());
 
            /// <summary>
            /// Writes a sequence to the console output with the given string separator, follows by a linefeed
            /// </summary>
            /// <typeparam name="T">Type of elements in the sequence</typeparam>
            /// <param name="e">Sequence to print</param>
            /// <param name="separator">String separator between each element, defaults to the empty string</param>
            public void WriteLine<T>(IEnumerable<T> e, string separator = "") => this.outStream.WriteLine(new StringBuilder().AppendJoin(e, separator).ToCharArray());
 
            /// <summary>
            /// Writes a sequence to the console output with the given string separator, follows by a linefeed
            /// </summary>
            /// <typeparam name="T">Type of elements in the sequence</typeparam>
            /// <param name="e">Sequence to print</param>
            /// <param name="separator">Character separator between each element</param>
            public void WriteLine<T>(IEnumerable<T> e, char separator) => this.outStream.WriteLine(new StringBuilder().AppendJoin(e, separator).ToCharArray());
 
            /// <summary>
            /// Writes the given object to the console output using the object's ToString method, followed by a linefeed
            /// </summary>
            /// <param name="o">Object to write</param>
            public void WriteLine(object o) => this.outStream.WriteLine(o);
 
            /// <summary>
            /// Flushes the output buffer to the console if the buffer is full, or if it's being forced
            /// </summary>
            public void Flush() => this.outStream.Flush();
 
            /// <inheritdoc />
            /// <summary>
            /// Disposes of the resources of this ConsoleHelper, closing all the associated streams
            /// </summary>
            public void Dispose()
            {
                if (this.Open)
                {
                    Flush();
                    this.inStream.Dispose();
                    this.outStream.Dispose();
                    this.Open = false;
                }
            }
            #endregion
        }
 
        /// <summary>
        /// Utils static methods class
        /// </summary>
        [DebuggerStepThrough]
        internal static class Utils
        {
            #region Constants
            /// <summary>
            /// Modulo operator used in a lot of questions
            /// </summary>
            private const long mod = 1000000007L;
            /// <summary>
            /// Log2 lookup table
            /// </summary>
            private static readonly int[] lookup =
            {
                0,  58, 1,  59, 47, 53, 2,  60,
                39, 48, 27, 54, 33, 42, 3,  61,
                51, 37, 40, 49, 18, 28, 20, 55,
                30, 34, 11, 43, 14, 22, 4,  62,
                57, 46, 52, 38, 26, 32, 41, 50,
                36, 17, 19, 29, 10, 13, 21, 56,
                45, 25, 31, 35, 16, 9,  12, 44,
                24, 15, 8,  23, 7,  6,  5,  63
            };
            #endregion
 
            #region Static methods
            /// <summary>
            /// Fast long int Log2 operation
            /// </summary>
            /// <param name="n">Value to get the Log2 for</param>
            /// <returns>The log2 of n</returns>
            public static int Log2(ulong n)
            {
                n |= n >> 1;
                n |= n >> 2;
                n |= n >> 4;
                n |= n >> 8;
                n |= n >> 16;
                n |= n >> 32;
                return lookup[unchecked((n * 0x03F6EAF2CD271461) >> 58)];
            }
            #endregion
        }
 
        /// <summary>
        /// Useful extensions
        /// </summary>
        [DebuggerStepThrough]
        internal static class Extensions
        {
            #region Enumerable extensions
            /// <summary>
            /// Finds out if the amount of objects in the enumerable is equal to the given number
            /// </summary>
            /// <typeparam name="T">Type of element in the Enumerable</typeparam>
            /// <param name="e">Enumerable to iterate through</param>
            /// <param name="count">Number of items that the enumerable should be equal to</param>
            /// <returns>True if the amount of objects is equal to count, false otherwise</returns>
            public static bool EqualTo<T>(this IEnumerable<T> e, int count)
            {
                if (count < 0) { return false; }
 
                int total = 0;
                return !e.Any(t => ++total > count) && total == count;
            }
 
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
            /// Finds out if the amount of objects in the enumerable is greater than the given number
            /// </summary>
            /// <typeparam name="T">Type of element in the Enumerable</typeparam>
            /// <param name="e">Enumerable to iterate through</param>
            /// <param name="count">Number of items that the enumerable should be greater than</param>
            /// <returns>True if the amount of objects is greater than count, false otherwise</returns>
            public static bool GreaterThan<T>(this IEnumerable<T> e, int count)
            {
                if (count < 0) { return true; }
 
                int total = 0;
                return e.Any(t => ++total > count);
            }
 
            /// <summary>
            /// Joins all the elements of the enumerable into a string
            /// </summary>
            /// <typeparam name="T">Type of elements in the Enumerable</typeparam>
            /// <param name="e">Enumerable to loop through</param>
            /// <param name="separator">Separator string, defaults to the empty string</param>
            public static string Join<T>(this IEnumerable<T> e, string separator = "") => new StringBuilder().AppendJoin(e, separator).ToString();
 
            /// <summary>
            /// Joins all the elements of the enumerable into a string
            /// </summary>
            /// <typeparam name="T">Type of elements in the Enumerable</typeparam>
            /// <param name="e">Enumerable to loop through</param>
            /// <param name="separator">Separator character</param>
            public static string Join<T>(this IEnumerable<T> e, char separator) => new StringBuilder().AppendJoin(e, separator).ToString();
 
            /// <summary>
            /// Gets the last element of a given List
            /// </summary>
            /// <typeparam name="T">Type of object in the list</typeparam>
            /// <param name="c">List to check in</param>
            /// <returns>The last element of the list</returns>
            public static T Last<T>(this IList<T> c) => c[c.Count - 1];
 
            /// <summary>
            /// Finds out if the amount of objects in the enumerable is less than the given number
            /// </summary>
            /// <typeparam name="T">Type of element in the Enumerable</typeparam>
            /// <param name="e">Enumerable to iterate through</param>
            /// <param name="count">Number of items that the enumerable should be less than</param>
            /// <returns>True if the amount of objects is less than count, false otherwise</returns>
            public static bool LessThan<T>(this IEnumerable<T> e, int count)
            {
                if (count <= 0) { return false; }
 
                int total = 0;
                return !e.Any(t => ++total >= count);
            }
 
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
            /// <param name="source">Enumerable to loop through</param>
            /// <param name="separator">Separator string, defaults to the empty string</param>
            /// <returns>The StringBuilder instance after the appending is done</returns>
            public static StringBuilder AppendJoin<T>(this StringBuilder sb, IEnumerable<T> source, string separator = "")
            {
                using (IEnumerator<T> e = source.GetEnumerator())
                {
                    if (e.MoveNext())
                    {
                        sb.Append(e.Current);
                        while (e.MoveNext())
                        {
                            sb.Append(separator).Append(e.Current);
                        }
                    }
                }
 
                return sb;
            }
 
            /// <summary>
            /// Appends multiple objects to a StringBuilder, separated by the given string
            /// </summary>
            /// <typeparam name="T">Type of elements in the Enumerable</typeparam>
            /// <param name="sb">StringBuilder to append to</param>
            /// <param name="source">Enumerable to loop through</param>
            /// <param name="separator">Separator character</param>
            /// <returns>The StringBuilder instance after the appending is done</returns>
            public static StringBuilder AppendJoin<T>(this StringBuilder sb, IEnumerable<T> source, char separator)
            {
                using (IEnumerator<T> e = source.GetEnumerator())
                {
                    if (e.MoveNext())
                    {
                        sb.Append(e.Current);
                        while (e.MoveNext())
                        {
                            sb.Append(separator).Append(e.Current);
                        }
                    }
                }
 
                return sb;
            }
 
            /// <summary>
            /// Gets the frequency array of a lowercase alphabet string
            /// </summary>
            /// <param name="s">Lowercase, alphabet characters only string to get the frequency array from</param>
            /// <returns>A 26 length integer array representing the frequency of each character</returns>
            public static int[] GetFrequency(this string s)
            {
                int[] results = new int[26];
                foreach (char c in s)
                {
                    results[c - 'a']++;
                }
 
                return results;
            }
 
            /// <summary>
            /// Returns true if the string is null, or the empty string ""
            /// Note: this will never throw a NullRef exception given that it is an extension method calling a static method
            /// </summary>
            /// <param name="s">String to test</param>
            /// <returns>True if the string is null or empty, false otherwise</returns>
            public static bool IsEmpty(this string s) => string.IsNullOrEmpty(s);
 
            /// <summary>
            /// Returns true if the given string is a palindrome (reads the same forwards and backwards)
            /// </summary>
            /// <param name="s">String to test</param>
            /// <returns>True if the string is a palindrome, false otherwise</returns>
            public static bool IsPalindrome(this string s)
            {
                int l = s.Length / 2, n = s.Length - 1;
                for (int i = 0; i <= l; i++)
                {
                    if (s[i] != s[n - i]) { return false; }
                }
 
                return true;
            }
 
            /// <summary>
            /// Reverses the given string
            /// </summary>
            /// <param name="s">String to reverse</param>
            /// <returns>The reversed equivalent of a string</returns>
            public static string Reverse(this string s)
            {
                int n = s.Length - 1;
                char[] rev = new char[s.Length];
                for (int i = 0; i < s.Length; i++)
                {
                    rev[n - i] = s[i];
                }
 
                return new string(rev);
            }
 
            /// <summary>
            /// Creates a substring from a starting and ending index
            /// </summary>
            /// <param name="s">String to substring</param>
            /// <param name="start">Starting index</param>
            /// <param name="end">Ending index</param>
            /// <returns>The resulting substring</returns>
            public static string SubStr(this string s, int start, int end) => s.Substring(start, (end - start) + 1);
 
            /// <summary>
            /// Copies the contents of a StringBuilder instance to an array
            /// </summary>
            /// <param name="sb">StringBuilder to copy</param>
            /// <returns>Contents array of the StringBuilder</returns>
            public static char[] ToCharArray(this StringBuilder sb)
            {
                char[] buffer = new char[sb.Length];
                sb.CopyTo(0, buffer, 0, sb.Length);
                return buffer;
            }
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
            /// Converts the number to it's binary string equivalent
            /// </summary>
            /// <param name="n">Number to convert</param>
            /// <returns>Binary representation of the number</returns>
            public static string ToBinary(this int n) => Convert.ToString(n, 2);
 
            /// <summary>
            /// Converts the number to it's binary string equivalent
            /// </summary>
            /// <param name="n">Number to convert</param>
            /// <returns>Binary representation of the number</returns>
            public static string ToBinary(this long n) => Convert.ToString(n, 2);
 
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
                n = n - ((n >> 1) & 0x5555555555555555L);
                n = (n & 0x3333333333333333L) + ((n >> 2) & 0x3333333333333333L);
                return (((n + (n >> 4)) & 0xF0F0F0F0F0F0F0FL) * 0x101010101010101L) >> 56;
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
            /// Creates a new instance shallow copy of the array
            /// </summary>
            /// <typeparam name="T">Type of the array</typeparam>
            /// <param name="array">Array to copy</param>
            /// <returns>The new copy of the array</returns>
            public static T[] Copy<T>(this T[] array)
            {
                T[] copy = new T[array.Length];
                Array.Copy(array, copy, array.Length);
                return copy;
            }
 
            /// <summary>
            /// Enumerates the contents of an ArraySegment
            /// </summary>
            /// <typeparam name="T">Type contained within the array</typeparam>
            /// <param name="array">Array to iterate through</param>
            /// <param name="offset">Index offset to start the iteration at, defaults to 0</param>
            /// <param name="count">Amount of values to return, default to the whole array</param>
            /// <returns>Enumerable of all the values contained in the ArraySegment</returns>
            public static IEnumerable<T> Enumerate<T>(this T[] array, int offset = 0, int count = 0)
            {
                if (count == 0) { count = array.Length - offset; }
 
                int max = offset + count;
                for (int i = offset; i < max; i++)
                {
                    yield return array[i];
                }
            }
 
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
                    if ((i & -i) == i) { continue; } // Exclude subsets of length 1
 
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
            /// <param name="array">Array to swap elements in</param>
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
 
        /// <summary>
        /// Better implementation of ArraySegment from the .NET 4.0 libraries
        /// </summary>
        /// <typeparam name="T">Type of element in the array</typeparam>
        /// <inheritdoc cref="IEnumerable{T}"/>
        [DebuggerStepThrough]
        public struct ArraySegment<T> : IEnumerable<T>, IEquatable<ArraySegment<T>>, IEquatable<T[]>, IEquatable<IEnumerable<T>>
        {
            #region Fields
            /// <summary>
            /// Array reference
            /// </summary>
            private readonly T[] array;
 
            /// <summary>
            /// Segment member equality comparer
            /// </summary>
            private readonly IEqualityComparer<T> comparer;
            #endregion
 
            #region Properties
            /// <summary>
            /// Offset from the start of the internal array
            /// </summary>
            public int Offset { get; }
 
            /// <summary>
            /// Length of the segment
            /// </summary>
            public int Length { get; }
            #endregion
 
            #region Indexers
            /// <summary>
            /// Gets or sets the element at the i index in the segment
            /// </summary>
            /// <param name="i">Index to get or set the parameter at</param>
            /// <returns>The value in the segment at the given index</returns>
            public T this[int i]
            {
                get { return this.array[this.Offset + i]; }
                set { this.array[this.Offset + i] = value; }
            }
            #endregion
 
            #region Constructors
            /// <summary>
            /// Creates a new ArraySegment spanning the entire array
            /// </summary>
            /// <param name="array">Array to create the segment on</param>
            /// <exception cref="ArgumentNullException">If the array is null</exception>
            /// <exception cref="ArgumentException">If the array is of size 0</exception>
            public ArraySegment(T[] array)
            {
                if (array == null) { throw new ArgumentNullException(nameof(array), "Array cannot be null"); }
                if (array.Length == 0) { throw new ArgumentException("Cannot take segment of array of size 0", nameof(array)); }
 
                this.array = array;
                this.Offset = 0;
                this.Length = array.Length;
                this.comparer = EqualityComparer<T>.Default;
            }
 
            /// <summary>
            /// Creates a new ArraySegment spanning the given array with the specified offset and length
            /// </summary>
            /// <param name="array">Array to create the segment on</param>
            /// <param name="offset">Offset from the start of the array</param>
            /// <param name="length">Length of the segment</param>
            /// <exception cref="ArgumentNullException">If the array is null</exception>
            /// <exception cref="ArgumentException">If the array is of size 0, or the offset or length is invalid</exception>
            public ArraySegment(T[] array, int offset, int length)
            {
                if (array == null) { throw new ArgumentNullException(nameof(array), "Array cannot be null"); }
                if (array.Length == 0) { throw new ArgumentException("Cannot take segment of array of size 0", nameof(array)); }
                if (offset < 0 || offset >= array.Length) { throw new ArgumentException("Offset must be between 0 and the segment's size", nameof(offset)); }
                if (length <= 0 || offset + length > array.Length) { throw new ArgumentException("Length must be greater than zero and stay within the target array", nameof(length)); }
 
                this.array = array;
                this.Offset = offset;
                this.Length = length;
                this.comparer = EqualityComparer<T>.Default;
            }
 
            /// <summary>
            /// Creates a new ArraySegment spanning the entire given existing segment
            /// </summary>
            /// <param name="array">Segment to create the new segment from</param>
            public ArraySegment(ArraySegment<T> array)
            {
                this.array = array.array;
                this.Offset = array.Offset;
                this.Length = array.Length;
                this.comparer = EqualityComparer<T>.Default;
            }
 
            /// <summary>
            /// Creates a new ArraySegment from a given segment with an offset within this segment
            /// </summary>
            /// <param name="array">ArraySegment to create the segment from</param>
            /// <param name="offset">Offset from the start of the segment</param>
            /// <param name="length">Length of the segment</param>
            /// <exception cref="ArgumentException">If the offset or lengths are invalid</exception>
            public ArraySegment(ArraySegment<T> array, int offset, int length)
            {
                if (offset < 0 || offset >= array.Length) { throw new ArgumentException("Offset must be between 0 and the array's size", nameof(offset)); }
                if (length <= 0 || offset + length > array.Length) { throw new ArgumentException("Length must be greater than zero and stay within the target array", nameof(length)); }
 
                this.array = array.array;
                this.Offset = array.Offset + offset;
                this.Length = length;
                this.comparer = EqualityComparer<T>.Default;
            }
            #endregion
 
            #region Methods
            /// <summary>
            /// Enumerates through the whole segment
            /// </summary>
            /// <returns>Sequence containing the elements of the segment</returns>
            /// <inheritdoc/>
            public IEnumerator<T> GetEnumerator()
            {
                for (int i = 0; i < this.Length; i++)
                {
                    yield return this[i];
                }
            }
 
            /// <summary>
            /// Enumerates through the whole segment
            /// </summary>
            /// <returns>Sequence containing the elements of the segment</returns>
            /// <inheritdoc/>
            System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator() => GetEnumerator();
 
            /// <summary>
            /// Gets the hashcode of this instance
            /// </summary>
            /// <returns></returns>
            public override int GetHashCode() => unchecked((((this.array.GetHashCode() * 397) ^ this.Offset) * 397) ^ this.Length);
 
            /// <summary>
            /// Tests if a given object is equal to this ArraySegment. This can be another ArraySegment or an actual array
            /// </summary>
            /// <param name="obj">Object to compare to</param>
            /// <returns>True if both objects are equivalent, false otherwise.</returns>
            public override bool Equals(object obj)
            {
                return (obj is ArraySegment<T> && Equals((ArraySegment<T>)obj))
                    || (obj is T[] && Equals((T[])obj))
                    || (obj is IEnumerable<T> && Equals((IEnumerable<T>)obj));
            }
 
            /// <summary>
            /// Tests if another given ArraySegment is equal to this instance
            /// </summary>
            /// <param name="other">ArraySegment to compare to</param>
            /// <returns>True if both instances are equivalent, false otherwise</returns>
            /// <inheritdoc/>
            public bool Equals(ArraySegment<T> other) => other.array == this.array && other.Length == this.Length && other.Offset == this.Offset;
 
            /// <summary>
            /// Tests if another given array is equal to this instance. This compares the full parameter array to the segment covered
            /// </summary>
            /// <param name="other">Array to compare to</param>
            /// <returns>True if both instances are equivalent, false otherwise</returns>
            /// <inheritdoc/>
            public bool Equals(T[] other)
            {
                if (other?.Length != this.Length) { return false; }
 
                for (int i = 0; i < other.Length; i++)
                {
                    if (!this.comparer.Equals(this[i], other[i])) { return false; }
                }
 
                return true;
            }
 
            /// <summary>
            /// Tests if another given IEnumerable is equal to this instance, by checking all members of the sequence and sequence length
            /// </summary>
            /// <param name="other">IEnumerable to compare to</param>
            /// <returns>True if both instances are equivalent, false otherwise</returns>
            /// <inheritdoc/>
            public bool Equals(IEnumerable<T> other)
            {
                if (other == null) { return false; }
                int i = 0;
                foreach (T t in other)
                {
                    if (i == this.Length || this.comparer.Equals(this[i++], t)) { return false; }
                }
 
                return i == this.Length;
            }
            #endregion
        }
 
        /// <summary>
        /// Sieve of Eratosthenes implementation
        /// </summary>
        /// <inheritdoc cref="IEnumerable{T}"/>
        [DebuggerStepThrough]
        public struct Sieve : IEnumerable<int>
        {
            #region Fields
            /// <summary>
            /// Sieve storage array
            /// </summary>
            private readonly bool[] sieve;
            /// <summary>
            /// List of primes, in ascending order
            /// </summary>
            private readonly List<int> primes;
            #endregion
 
            #region Properties
            /// <summary>
            /// Size of the Sieve
            /// </summary>
            public int Size { get; }
            #endregion
 
            #region Indexers
            /// <summary>
            /// Gets if a specific number is prime
            /// </summary>
            /// <param name="i">Number to test</param>
            /// <returns>True if the number is a prime, false otherwise</returns>
            public bool this[int i]
            {
                get
                {
                    if (i < 0 || i > this.Size) { throw new ArgumentOutOfRangeException(nameof(i), i, "Prime value must be between 0 and the size of the Sieve"); }
                    return this.sieve[i];
                }
            }
            #endregion
 
            #region Constructors
            /// <summary>
            /// Creates a new Sieve of the given size
            /// </summary>
            /// <param name="size">Size of the sieve - number up until which primes are loaded</param>
            public Sieve(int size)
            {
                this.Size = size;
                this.sieve = new bool[size + 1];
                this.primes = new List<int>(size / 10) { 2 };
 
                //Two is the first prime
                this.sieve[2] = true;
 
                //Set all odd numbers above 2 as potential primes
                for (int i = 3; i <= size; i += 2)
                {
                    this.sieve[i] = true;
                }
 
                //Starting at three, cross out multiples
                for (int i = 3; i <= size; i += 2)
                {
                    if (this.sieve[i])
                    {
                        this.primes.Add(i);
                        for (int j = i + i; j <= size; j += i)
                        {
                            this.sieve[j] = false;
                        }
                    }
                }
            }
            #endregion
 
            #region Methods
            /// <summary>
            /// Enumerates the primes stored in the Sieve
            /// </summary>
            /// <returns>Sequence of all the primes in the sieve, ordered</returns>
            /// <inheritdoc/>
            public IEnumerator<int> GetEnumerator() => this.primes.GetEnumerator();
 
            /// <summary>
            /// Enumerates the primes stored in the Sieve
            /// </summary>
            /// <returns>Sequence of all the primes in the sieve, ordered</returns>
            /// <inheritdoc/>
            System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator() => this.primes.GetEnumerator();
            #endregion
        }
 
        /// <summary>
        /// Descending integer comparer
        /// </summary>
        /// <inheritdoc/>
        [DebuggerStepThrough]
        public class DescendingComparer : IComparer<int>
        {
            #region Static properties
            /// <summary>
            /// Comparer instance
            /// </summary>
            public static DescendingComparer Comparer { get; } = new DescendingComparer();
            #endregion
 
            #region Methods
            /// <summary>
            /// Compares to integers in decreasing order
            /// </summary>
            /// <param name="a">First integer to compare</param>
            /// <param name="b">Second integer to comparer</param>
            /// <returns>1 if the first integer is smaller than the second, -1 if it is larger, and 0 if they are equal</returns>
            /// <inheritdoc/>
            public int Compare(int a, int b) => b.CompareTo(a);
            #endregion
        }
    }
}

// IMPORTANT: Multiple classes and nested static classes are supported
 
//uncomment this if you want to read input.
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
//import for Scanner and other utility classes
import java.util.*;

 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
class TestClass {
    public static void main(String args[] ) throws Exception {
        //Sample code to perform I/O:
        // Use either of these methods for input
        //
        ////BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String name = br.readLine();                // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
        //
        ////Scanner
        //Scanner s = new Scanner(System.in);
        //String name = s.nextLine();                 // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
        //
        //
 
        // Write your code here
        Reader s=new Reader();
		 	BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));
		 	Writer w = new Writer(wr);
		 	int testCases = s.nextInt();
		 	while(testCases-- > 0)
		 	{
		 		int noOfBuilding = s.nextInt();
		 		int earning = s.nextInt();
		 		int maxHeight = 0;
		 		int visibleBuilding = 0;
		 		for(int i = 0;i < noOfBuilding;i++)
		 		{
		 			int height = s.nextInt();
		 			if(height > maxHeight)
		 			{
		 				maxHeight =height;
		 				visibleBuilding++;
		 			}
		 		}
		 		w.writeInt(visibleBuilding * earning);
		 	}	
	        w.flush();
	        s.close();
 
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
			
			public void flush() throws IOException {
				wr.flush();
				wr.close();
			}
		}
}

Java 8:
//import java.util.Scanner
import java.io.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
        int a,max =0,N,R,sum=0;
        Reader scan =  new Reader();
        //Scanner scan = new Scanner(System.in);
        int S = scan.readInt();
        while(S!=0)
        {
             N = scan.readInt();
             R = scan.readInt();
            a = scan.readInt();
            max = a;
            sum = sum + R;
            for(int i =1;i<N;i++)
            {
                a= scan.readInt();
                if(a>max)
                {
                    max = a;
                    sum = sum + R;
                }
            
                    
            }
            System.out.println(sum);
            sum =0;
            S--;
        }
 
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
 
        public int readInt() throws IOException
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
 
        public long readLong() throws IOException
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
 
        public double readDouble() throws IOException
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
}
 
Javascript(Rhino):
// Below is a sample code to process input from STDIN.
// Equivalent in effect to the Java declaration import java.io.*;
//importPackage(java.io);
//importPackage(java.lang);
//importPackage(java.math);
//importPackage(java.util);
// 
//var sc = new Scanner(System['in']);					// Reading input from STDIN
// 
//var my_name = sc.nextLine();
//System.out.println("Hi, " + my_name + ".");			// Writing output to STDOUT
// End of input processing code.
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

 
// Write your code here
 
importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new Scanner(System['in']);	
 
var street = sc.nextLine();
 
while(street > 0){
    var details = sc.nextLine().split(" ");
    var numberOfBuilding = parseInt(details[0]);
    var rupees = parseInt(details[1]);
    
    var buildings = sc.nextLine().split(" ");
    
    var i=0; 
    var count =1;
    var height =parseInt(buildings[0]);
    for(i=1;i<buildings.length;i++){
        if(parseInt(buildings[i]) > height){
          height =parseInt(buildings[i]);
          count++;
        }
    }
    
    System.out.println(count* rupees+"");
    street--;
}
 

Javascript(Node.js):
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
    var token = input.split('\n');
    var s = Number(token[0]);
    for(var i=0; i<s; i++) {
        iterate(token, i);
    }
}
 
function iterate(token, i) {
    var row = token[2*i+1].split(' ');
    var n = Number(row[0]);
    var r = Number(row[1]);
    var a = token[2*i+2].split(' ');
    var max = Number(a[0]);
    var count = 1;
    for(var j=1; j<n; j++) {
        var elem = Number(a[j]);
        if(elem > max) {
            count++;
            max = elem;
        }
    }
    console.log(count*r);
}

Python 2:
for _ in xrange(int(raw_input())):
    t = 0
    n, r = map(int,raw_input().split())
    l = map(float,raw_input().split())
    # l.insert(0,.5)
    k = .5
    c = 0
    for i in l:
        if i > k:
            k = i
            c += 1    
    t += r*c
    
    print t

Python 3:
'''
# Sample code to perform I/O:
 
name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''
 
# Write your code here
def maximize(r, n, heights):
    total, big = 0, 0
    for i in heights:
        if i > big:
            total += 1
            big = i
    return (total * r)
 
s = int(input())
for _ in range(s):
    n, r = map(int,input().split())
    heights = list(map(int,input().split()))
    print(maximize(r, n, heights))


Ruby:
=begin
# Sample code to perform I/O:
 
name = gets.chomp                # Reading input from STDIN
print "Hi, #{name}.\n"           # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
=end
 
# Write your code here
def process_query(ar, r,n)
  tot = 1
  ar = ar.split(" ").map(&:to_i)
  prev_max = ar[0]
  ar[1..n.to_i-1].each do |a1|
      if(a1>prev_max)
         tot+=1 
         prev_max = a1
      end
  end
  return tot * r.to_i
end
 
 
full =  STDIN.read.split("\n")
no_of_inputs = full[0].to_i
 
number=1
while(!full[number].nil?)
  n, r = full[number].split(" ")
  number+=1
  ar = full[number]
  number+=1
  puts process_query(ar,r,n)
end

Scala:
// Sample code to perform I/O:
//val name = scala.io.StdIn.readLine()        // Reading input from STDIN
//println("Hi, " + name + ".")                // Writing output to STDOUT
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
// Write your code here

object MaximizeTheEarnings {
  def main(args: Array[String]){
    var S = readInt()
    var R = new java.lang.StringBuffer()
    while(S>0){
      var NE = readLine().split(' ').map(_.toInt)
      var A = readLine().split(' ').map(_.toInt)
      var c=1
      var max= A(0)
      for(i<- 1 until NE(0)){
        if(A(i)>max){ max=A(i); c =c +1}
      }
     R.append(c*NE(1)+"\n")
     S = S-1
    }
    println(R)
  }
}


*/
