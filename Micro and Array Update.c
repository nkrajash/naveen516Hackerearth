/* All Tracks --> Data Structures -->  Arrays -->   1-D -->  
Micro and Array Update
Tag(s): Ad-Hoc, Data Structures, Very-Easy
Micro purchased an array A having N integer values. After playing it for a while, he got bored of it and decided to update value of its element. 
In one second he can increase value of each array element by 1. He wants each array element's value to become greater than or equal to K. 
Please help Micro to find out the minimum amount of time it will take, for him to do so.

Input: 
First line consists of a single integer, T, denoting the number of test cases. 
First line of each test case consists of two space separated integers denoting N and K. 
Second line of each test case consists of N space separated integers denoting the array A.

Output:
For each test case, print the minimum time in which all array elements will become greater than or equal to K. Print a new line after each test case.

Constraints: 
1<=T<=5
1<=N<=10^5
1<=A[i],K<=10^6
 

SAMPLE INPUT 
2
3 4
1 2 5
3 2
2 5 5
SAMPLE OUTPUT 
3
0


Explanation:
For first test case,
After 1 second, array will be {2,3,6}.
After 2 second, array will be {3,4,7}.
After 3 second, array will be {4,5,8}.

So it will take 3 second for all array elements to become greater than or equal to 4.

#include <stdio.h>
#define N 1000000
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int i,j,t,K,A[N],sec,n;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        scanf("%d",&K);
        sec=0;
        for(j=0;j<n;j++)
            scanf("%d",&A[j]);
        qsort(A, n, sizeof(int), cmpfunc);
        if(A[0]<K){
            while(A[0]!=K){
                A[0]=A[0]+1;
                sec++;
            }
        }
        printf("%d\n",sec);
    }
    return 0;
}

#include <iostream>
#include <cstdlib>
using namespace std;
#define N 1000000

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int i,j,t,K,A[N],sec,n;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        cin>>K;
        sec=0;
        for(j=0;j<n;j++)
            cin>>A[j];
        qsort(A, n, sizeof(int), cmpfunc);
        if(A[0]<K){
            while(A[0]!=K){
                A[0]=A[0]+1;
                sec++;
            }
        }
        cout<<sec<<endl;
    }
    return 0;
}

Author: Vaibhav_Jaimini
Tester: usaxena95
Editorialist: r3gz3n
Brief Description: Given an array A of N elements and an integer K. You can increase value of each array element by 1. 
Find minimum number of step you need such that all the values will be greater than or equal to K.
Prerequisite: None
Difficulty: CakeWalk
Detailed Explanation: 
Since we can only increase all the elements by 1, the minimum element will take most step to reach K. 
So we have to find the minimum element in array A and answer will difference between K and minimum element.
One corner case is if K is less than minimum element in the array A.
Time Complexity: O(N)
Space Complexity: O(1)

Author Solution by Vaibhav Jaimini
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n, k;cin>>n>>k;
		int ans = k;
		for(int i=1; i<=n; i++){
			int temp;cin>>temp;
			ans = min(ans, temp);
		}
		cout<<k-ans<<endl;
	}
	return 0;
}

*/

/*Best Submissions:
C:
#include <stdio.h>
 
int main()
{
    int t,n,i,c=0,k,max=0;
    scanf("%d",&t);
    while(t--)
    {
       	k=0;n=0;max=0; 
        scanf("%d%d",&n,&k);
        int a[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<k)
            {
                c=k-a[i];
                if(c>=max)
                    max=c;
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
 
C++:
#include <bits/stdc++.h>
using namespace std;
int mn=1e9,n,m,k,t,x;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        mn=1e9;
        for(int i=0; i<n; i++){
            scanf("%d",&x);
            mn=min(mn,x);
        }
        printf("%d\n",max(0,k-mn));
    }
    
    return 0;
}


C++14:

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,i;
        scanf("%d %d",&n,&k);
        int a[n];
        int mn = INT_MAX;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            mn = min(mn, a[i]);
        }
        int res = k-mn;
        if(res>=0)
            printf("%d\n",res);
        else
            printf("0\n");
    }
}

C#:
/* ============================== *\
 *    All code by stupid_chris    *
 *      ©(Christophe Savard)      *
 * Concordia University, Montreal *
 *              2017              *
\* ============================== */
 
using System;
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
        /// Fast Console IO helper
        /// </summary>
        private static readonly ConsoleHelper console = new ConsoleHelper();
 
        /// <summary>
        /// Main method - Launches solver
        /// </summary>
        private static void Main()
        {
            //Depending on problem
            using (console)
            {
                TestCases();
                //Solve();
            }
        }
 
        /// <summary>
        /// Solves the problem for multiple test cases
        /// </summary>
        private static void TestCases()
        {
            int n = console.NextInt();
            console.NextLine();
 
            for (int i = 0; i < n; i++)
            {
                Solve();
            }
        }
        #endregion
 
        #region Solution
        /// <summary>
        /// Solution
        /// </summary>
        private static void Solve()
        {
            int n = console.NextInt(), m = console.NextInt();
            console.NextLine();
 
            console.WriteLine(-Math.Min(0, console.EnumerateInts(n).Min() - m));
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
        private readonly BufferedStream inStream; //Buffered console input stream
        private readonly BufferedStream outStream; //Buffered console output stream
        private readonly byte[] inBuffer; //Input buffer 
        private readonly byte[] outBuffer; //Output buffer
 
        private int inputIndex; //Input buffer current index
        private int outputIndex; //Output buffer current index
        private int bufferEnd; //Input buffer ending index
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
            //Open the input stream
            this.inStream = new BufferedStream(Console.OpenStandardInput(bufferSize), bufferSize);
            this.inBuffer = new byte[bufferSize];
 
            //Open the output stream
            this.outStream = new BufferedStream(Console.OpenStandardOutput(bufferSize), bufferSize);
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
 
            NextLine();
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
 
                NextLine();
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
 
            NextLine();
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
                if ((i & -i) == i) { continue; }
 
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
        #endregion
    }
}

JAVA:
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;
 
public class MicroArray {
	static int[] ar;
	public static void main(String[] args) throws IOException {
		//Scanner sc=new Scanner(System.in);
		Reader sc=new Reader();
		int n=sc.nextInt();
		
		int min;
		while(n-->0)
		{
			int l=sc.nextInt();
			ar=new int[l];
			int lvl=sc.nextInt();
			//System.out.println(" "+ l +" "+ lvl +"\n");
			min=initArr(sc,ar,l);
			//System.out.println(Arrays.toString(ar));
//			min=findMin(ar);
			//System.out.println(Arrays.toString(ar));
			int ans=lvl-min;
			if(ans<0) ans=0;
			System.out.println(ans);
			
		}
	}
	
	static int initArr(Reader sc,int[] ar,int l) throws IOException
	{int min=2100000000;
		for(int i=0;i<l; i++)
	{ar[i]=sc.nextInt();
		if(ar[i]<min) min=ar[i];
	}
	return min;
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
	
//	static int findMin(int[] a)
//	{int min=a[0];
//	if(a.length==1)
//		return a[0];
//	for(int i=0; i<a.length; i++)
//	{if(a[i]<min)
//	min=a[i];}
//	return min;}
}

Java 8:
import java.io.*;
import java.util.*;
 
class Solution{
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
 
    public static void main(String args[]) throws IOException{
    	Reader r = new Reader();
        int min;
        int t = r.nextInt();
        while (t-- > 0){
            min = Integer.MAX_VALUE;
            int n = r.nextInt();
            int k = r.nextInt();
            for (int i = 0 ; i < n ; ++i)
            {
                int temp = r.nextInt();
                if (temp < min)
                    min = temp;
            }
            min = k - min;
            if (min < 0)
                min = 0;
            System.out.println(min);
        }
    }
}

JavaScript(Rhino):
/*
// Below is a sample code to process input from STDIN.
// Equivalent in effect to the Java declaration import java.io.*;
importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new Scanner(System['in']);					// Reading input from STDIN
 
var my_name = sc.nextLine();
System.out.println("Hi, " + my_name + ".");			// Writing output to STDOUT
// End of input processing code.
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
 
// Write your code here
importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new Scanner(System['in']);					// Reading input from STDIN
 
var testCases = sc.nextLine();
while(testCases > 0){
    var time = 0;
    var line1 = sc.nextLine().split(" ");
    var size = parseInt(line1[0]);
    var finalVal = parseInt(line1[1]);
    var arr = sc.nextLine().split(" ");
 
    for(var j=0;j<arr.length;j++){
        var val = parseInt(arr[j]);
        if(val < finalVal && time<(finalVal - val)){
           time = finalVal - val;
        }
    }
    testCases = testCases -1;
    System.out.println(time+"");
}
 
JavaScript(Node.js):
 function computeTime(list, k){
    var diff;
    diff = k - Math.min.apply(Math,list);
    process.stdout.write(Math.max(0,diff)+'\n');
}
 
function main(irows) {
    var i,len=irows.length;
    for(i=1;i<len;i=i+2){
        computeTime(irows[i+1].split(' '), irows[i].split(' ')[1]);
    }
}
 
process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
 
process.stdin.on("data", function (input) {
    stdin_input += input;
});
 
process.stdin.on("end", function () {
   main(stdin_input.split("\n"));
});

Pascal:
var min,r,i,n,k,test,t : longint;
    a:array[1..100000] of longint;
begin
readln(test);
for r:= 1 to test do 
 begin
  readln(n,k);
  min:= 0;
   for i:= 1 to n do
   begin
   
    read(a[i]);
    if i=1 then min:=a[i] else
    if min>a[i] then min:=a[i];
   end;
    t:= k - min ;
    if t<0 then t:=0;
writeln(t);
  end;
end.

Perl:
use Math::BigInt;
use List::Util qw( min max );
$a=<STDIN>;
chomp($a);
while($a!=0){
 $b=<STDIN>;
 chomp($b);
 @arr_b=split(/ /,$b);
 $c=<STDIN>;
 chomp($c);
 @arr_c=split(/ /,$c);
 
 #@arr_c=sort(@arr_c);
 #$min=$arr_c[0];
 $min=min @arr_c;
 #print("Arry is @arr_c\n");
 #print("minimin is $min\n");
 $time=$arr_b[1]-$min;
 
 if($time<0){
  $time = 0;
 }
 print("$time\n");
 $a=$a-1;
}

Python:
t=input()
for i in range(0,t):
    n,k=map(int,raw_input().split())
    a=[]
    a=map(int,raw_input().split())
    x=min(a)
    if x<k:
        print k-x
    else:
        print "0"

Python 3:
for _ in range(int(input())):
    n, k = map(int, input().split(' '))
    l = min(map(int, input().split(' ')))
    #sm = min(n_list)
    if l < k: print(k - l)
    else: print(0)



PHP:
<?php
 
// Sample code to perform I/O:
$min;$next=0;
while($name=fgets(STDIN)){
    $name =explode(" ",$name);
    //var_dump($name);
    if(count($name)==2){$min=$name[1];
        $next=1;continue;
    }
    if($next==1){$next=0;
    //var_dump($name);
    $minnum=100000000;
    foreach($name as $num){if((int)$num<$minnum){$minnum=$num;}}
   // echo $minnum."a\n";
    $result=$min-$minnum;
    if($result>0){echo $result . "\n";}else{echo "0 \n";}
    
};         
}// Reading input from STDIN
//cho "Hi, ".$name.".\n";                // Writing output to STDOUT
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
 
// Write your code here*/
 
?>

Ruby:
t = gets.to_i
t.times do
	array = gets.split
	n = array[0].to_i
	k = array[1].to_i
	array2 = gets.split
	while array2.length != n
		puts "make sure that you put #{n} numbers"
		array2 = gets.split
	end
	min = 10000000000000000000000000000000000000000000000
	b = 0
	while b < n
		if min > array2[b].to_i
			min = array2[b].to_i
		end
		b += 1
	end
	output = k - min
	if output < 0
		puts 0
	else
		puts output
	end
end





*/


