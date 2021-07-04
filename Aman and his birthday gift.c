/*All Tracks --> Basic Programming --> Implementation  --> Basics of Implementation --> Problem -->
Aman and his birthday gift
Tag(s): Easy-Medium

Problem Statement:

Today is Aman's birthday but I forgot to bring a gift for him. He is very angry with me. I have an idea for a gift. He likes coding very much. Why not give him a problem to solve 
as his gift? Aman likes everything infinite. Now he is studying the properties of a sequence s, such that its first element is equal to a (s1?=?a), and the difference
between any two neighbouring elements is equal to c (si?-?si?-?1?=?c). In particular, Aman wonders if his favourite integer b appears in this sequence, that is, there exists a positive integer i, such that si?=?b. Of course, you are the person he asks for a help.

Input
The first line of the input contain three integers a, b and c (?-?10^9?=?a,?b,?c?=?10^9) — the first element of the sequence, Aman's favorite number and the 
difference between any two neighbouring elements of the sequence, respectively.

Output
If b appears in the sequence s print "YES" (without quotes), otherwise print "NO" (without quotes).

SAMPLE INPUT 
1 7 3
SAMPLE OUTPUT 
YES

Explanation:
In the first sample, the sequence starts from integers 1, 4, 7, so 7 is its element.

My C Solution:
#include <stdio.h>

int main()
{
    int a,n=-1,c,Sn,b;
    scanf("%d%d%d",&a,&b,&c);
    if(c)
        n=((b-a)/c)+1;
    Sn= a+(n-1)*c;
    if(n<0 || Sn != b)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}

My C++ Solution:
#include <iostream>
using namespace std;

int main()
{ 
    int a,b,c,n=-1,Sn;
    cin>>a>>b>>c;
    if(c)
       n=((b-a)/c)+1;
    Sn=a+(n-1)*c;
    if(n<0||Sn!=b)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}

*/


/* Editorial:

#include <iostream>
using namespace std;


int main()
{
    long long int a,b,c;
    cin>>a>>b>>c;
    if(b==a)
        cout<<"YES";
        else if(a>b&&c>0||a<b&&c<0)
            cout<<"NO";
        else if(c==0)
        {
            if(a==b)
                cout<<"YES";
            else
                cout<<"NO";
        }

    else
    {
        long long int u=b-a;
        if(u%c==0)
             cout<<"YES";
        else
            cout<<"NO";
    }
    return 0;
}

*/



/*
Best Submissions:
C:
#include <stdio.h>
 
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(((b-a)/c)>0&&(((b-a)/c)%1)==0)
    printf("YES");
    else
    printf("NO");
    return 0;
}

C++:
#include<bits/stdc++.h>
 
using namespace std;
int main()
 {
     double a , b , c;
     
     
     cin>>a>>b>>c;
    double a1 = b-a;
    double  a2 = a1/c + 1 ;
    
      int a3 = (b-a)/c+1;
     
     
     if(a2-a3!=0)
     cout<<"NO"<<endl;
     else
     {
         if(b>0)
         cout<<"YES"<<endl;
         else
         cout<<"NO"<<endl;}
     
     return 0;
 }

C++14:
#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define mp make_pair
typedef long long int lli ;
typedef long long ll;
using namespace std;
 
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
ll a,b,c;
cin>>a>>b>>c;
ll k=(b-a)%c;
 
if(k==0 && (b-a)/c >-1)
cout<<"YES\n";
else
cout<<"NO\n";
 
return 0;
}

C#:
/* ============================== *\
 *    All code by stupid_chris    *
 *      ©(Christophe Savard)      *
 * Concordia University, Montreal *
 *              2017              *
\* ============================== */
 
#pragma warning disable IDE0018
//#define TESTCASES
 
using System;
using System.Collections.Generic;
using System.Diagnostics;
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
        private const long mod = 1000000007L;
 
        /// <summary>
        /// Fast Console IO helper
        /// </summary>
        private static ConsoleHelper Console { get; }
 
        /// <summary>
        /// Pre processing setup
        /// </summary>
        static Program()
        {
            Console = new ConsoleHelper();
        }
 
        /// <summary>
        /// Main method - Launches solver
        /// </summary>
        private static void Main()
        {
#if DEBUG
            Stopwatch timer = Stopwatch.StartNew();
#endif
            using (Console)
            {
#if TESTCASES
                TestCases();
#else // !TESTCASES
                Solve();
#endif
            }
#if DEBUG
            timer.Stop();
            System.Console.SetOut(File.AppendText(@"..\..\output.txt"));
            System.Console.Write($"\r\n\r\nTotal run time: {timer.Elapsed.TotalSeconds:0.000}s");
            System.Console.Out.Close();
#endif
        }
 
#if TESTCASES
 
        /// <summary>
        /// Solves the problem for multiple test cases
        /// </summary>
        private static void TestCases()
        {
            int t = Console.NextInt();
            Console.SkipNextLine();
 
            for (; t > 0; t--)
            {
                Solve();
            }
        }
 
#endif
        #endregion
 
        #region Solution
        private static void Solve()
        {
            int a = Console.NextInt(), b = Console.NextInt(), c = Console.NextInt(), r;
 
            int d = Math.DivRem(b - a, c, out r);
            Console.Write(d > 0 && r == 0 ? "YES" : "NO");
        }
        #endregion
    }
 
    #region Tools
    // Solution does not extend beyond this point, those are merely tools to help along
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
 
        /// <summary>
        /// Checks to see if there is still readable data within the stream
        /// </summary>
        /// <returns>True if there is still data to read, false otherwise</returns>
        public bool HasData => Peek() != 0;
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
            // Open the input/output streams
#if DEBUG
            // Test mode
            this.inStream = new BufferedStream(File.OpenRead(@"..\..\input.txt"), bufferSize);
            this.outStream = new StreamWriter(File.Create(@"..\..\output.txt", bufferSize), Encoding.ASCII, bufferSize);
#else // !DEBUG
// Submission mode
            this.inStream = new BufferedStream(Console.OpenStandardInput(bufferSize), bufferSize); // Submission stream
            this.outStream = new StreamWriter(Console.OpenStandardOutput(bufferSize), Encoding.ASCII, bufferSize);
#endif
 
            // Set fields
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
    /// Useful extensions
    /// </summary>
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
 
        /// <summary>
        /// Sums all the digits of the integer n
        /// </summary>
        /// <param name="n">Integer to sum the digits of</param>
        /// <returns>Sum of all the digits of n</returns>
        public static int SumDigits(this int n)
        {
            int total = 0;
            while (n > 0)
            {
                total += n % 10;
                n /= 10;
            }
            return total;
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
    #endregion
}

Java:
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class App {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer input = new StringTokenizer(reader.readLine());
        long a = Long.parseLong(input.nextToken());
        long b = Long.parseLong(input.nextToken());
        long c = Long.parseLong(input.nextToken());
        long n = Math.abs((b - a) / c);
        long answer = a + (n * c);
        if (b == answer) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}

Java 8:
import java.util.*;
class test
{
    public static void main(String args[]) throws Exception
    {
        int f=0;
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        int c=sc.nextInt();
        if((Math.abs(b-a)%(Math.abs(c)))==0 && ((a<b && c>0)||(a>b && c<0)))
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}

Javascript(Node.js):
import java.util.*;
class test
{
    public static void main(String args[]) throws Exception
    {
        int f=0;
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        int c=sc.nextInt();
        if((Math.abs(b-a)%(Math.abs(c)))==0 && ((a<b && c>0)||(a>b && c<0)))
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}

Python:
a, f ,b= raw_input().split(" ")
a = int(a)
f = int(f)
b = int(b)
i=a
if(b>0):
    while(1):
        i=i+b
        if(i==f):
            print"YES"
            exit(0)
print"NO"


Python 3:
import sys
a,b,c = map(int,sys.stdin.readline().split())
sta = False
if a<0 and b>=0 and c<0:
    print("NO")
elif abs(b-a)%abs(c) == 0:
    print("YES")
else:
    print("NO")   


Ruby:
=begin
# Read input from stdin and provide input before running code
 
print "Please enter your name: "
name = gets.chomp
print "Hi #{name}\n"
=end
 
input = gets.chomp.split(' ')
first_number = input[0].to_i
fav_number = input[1].to_i
difference = input[2].to_i
 
result = 'NO'
 
if first_number < fav_number && difference > 0
    while(fav_number >= first_number)
        if fav_number == first_number
            result = 'YES'
            break
        end
        fav_number -= difference
    end
end
 
puts result


PHP:
<?php
/*
// Sample code to perform I/O:
 
fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
echo "Hi, ".$name.".\n";                // Writing output to STDOUT
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
 
// Write your code here
$lineinput = readline();
$lineinput = explode (' ', $lineinput);
$a = $lineinput[0];
$b = $lineinput[1];
$c = $lineinput[2];
 
if(($b-$a)%abs($c) == 0 && (($a>$b && $c<0)||($a<$b && $c>0))){
    echo "YES";
}
else{
    echo "NO";
}
 
 
?>

*/


/*
I/O:
In #1:
-245436499 416383245 992
Out #1:
YES

In #2:
-198350539 963391024 68337739
Out #2:
YES

In #3:
-2 0 -1
Out #3:
NO

In #4:
-1 -2 -2
Out #4:
NO

*/

/*
Analytics:
Submission Graph
Submission Summary
Language Analytics
Multilingual Users
*/

