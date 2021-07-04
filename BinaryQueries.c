/*All Tracks -->  Data Structures --> Arrays --> 1-D --> Problem -->
Binary Queries
Tag(s): Very-Easy
Some problems appear hard though they are very easy. Today Aakash is stuck in a range query problem. He has been given an array with only numbers 0 and 1. 
There are two types of queries -
0 L R : Check whether the number formed from the array elements L to R is even or odd and print EVEN or ODD respectively. 
Number formation is the binary number from the bits status in the array L to R
1 X : Flip the Xth bit in the array

Indexing is 1 based

Input
First line contains a number N and Q as input. Next line contains N space separated 0 or 1. Next Q lines contain description of each query

Output
Output for only query type 0 L R whether the number in range L to R is "EVEN" or "ODD" (without quotes).

Constraints
1<= N <= 10^6
1<= L <= R <= 10^6
1<= Q <= 10^6
1<= X <= N

SAMPLE INPUT 
5 2
1 0 1 1 0
1 2
0 1 4

SAMPLE OUTPUT 
ODD

Explanation
Our first query is 1 2 that means that we have to flip the 2nd bit in the given array so now our array becomes 1 1 1 1 0
2nd query is 0 1 4 which means that if i pick the subarray 1 to 4 i.e 1 1 1 1 then the number formed by decimal representation of this binary number is of what kind ?. 
Here the number formed is 15 so its odd and ODD is the output

// My C Solution:
#include <stdio.h>
#define LEN 1000001
#define FLIP 1
#define PARITY 0

int main(){
    int Q,Qtype,n,L,R,i,pos,num[LEN];
    scanf("%d%d",&n,&Q);

    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    while(Q--){
        scanf("%d",&Qtype);
        if(Qtype == FLIP){
            scanf("%d",&pos);  
            num[(pos-1)]^=1; //Flip bit at pos using XOR mask(1)
        }
        else if(Qtype == PARITY){
            scanf("%d%d",&L,&R);
            printf(num[(R-1)] == 1 ? "ODD\n" : "EVEN\n");
        }
    }
    return 0;
}

*/

/*Best Submissions:
C:
#include <stdio.h>
     
    void scnaf_leave_int(int *n)
    {
        register int c = getchar_unlocked();
        for( ; (c<48 || c>57); c = getchar_unlocked() );
        for( ; (c>47 && c<58); c = getchar_unlocked() );
    }
     
    void scnaf_int(int *n){
        register int c = getchar_unlocked();
        *n = 0;
        for( ; (c<48 || c>57); c = getchar_unlocked() );
        for( ; (c>47 && c<58); c = getchar_unlocked() ){
            *n = (*n<<1) + (*n<<3) +c -48;
        }
    }
     //getchar_unlocked() is a function which scans input much faster than scanf. It reads input as char. And it is converted to int by shift operations and "- 48".

    int main()
    {
    	int i,n,q,a;
    	scnaf_int(&n);
    	scnaf_int(&q);
        int arr[n+1];
        for(i=1; i<=n; i++)
        	scnaf_int(&arr[i]);
    	
    	while(q--){
    		scnaf_int(&a);
    		if(a==1){
    			int x;
    			scnaf_int(&x);
    				arr[x] = !arr[x]; 
    		}
    		else if(a==0){
    			int l,r;
    			scnaf_leave_int(&l);
    			scnaf_int(&r);
    			if(arr[r]==1)
    				printf("ODD\n");
    			else
    				printf("EVEN\n");
    		}
    	}
        return 0;
    }

C++:
 #include <iostream>
    using namespace std;
    int scan(){
    	register int c = getchar_unlocked();
        int n = 0;
        for( ; (c<48 || c>57); c = getchar_unlocked() );
        for( ; (c>47 && c<58); c = getchar_unlocked() ){
            n = (n<<1) + (n<<3) +c -48;
        }
        return n;
    }
    void scan1(){
    	register int c = getchar_unlocked();
        for( ; (c<48 || c>57); c = getchar_unlocked() );
        for( ; (c>47 && c<58); c = getchar_unlocked() );
    }
    int main()
    {
        int n,q;
        n=scan();
        q=scan();
      //cin>>n>>q;
        int a[n];
        int i,j;
        int x,l,r;
        for(i=0;i<n;i++) a[i]=scan();
        while(q){
        	x=scan();
        	if(x==1){
        		l=scan();
        		//cin>>l;
        		a[l-1]=(a[l-1]+1)%2;
        	}
        	else {
        		scan1();
        		r=scan();
        		//cin>>l>>r;
        		if(a[r-1]==1) printf("ODD\n");
        		else if(a[r-1]==0) printf("EVEN\n");
        	}
        	q--;
        }
        return 0;
    }

C++14:
#include <iostream>
#include <cstdio>
using namespace std;
int bit_arr[1000002]={0};
int scan(){ // not thread safe
    	register int c = getchar_unlocked();
        register int n = 0;
        for( ; (c<48 || c>57); c = getchar_unlocked() ); // not thread safe
        for( ; (c>47 && c<58); c = getchar_unlocked() ){
            n = (n<<1) + (n<<3) +c -48;
        }
        return n;
}
int main(){
    int N,Q;
    scanf("%d %d", &N, &Q);
    int L, R, q;
    // for(int i=1;i<=N;++i) scanf("%d ", &bit_arr[i]);
    for(int i=1;i<=N;++i) bit_arr[i] = scan();
    for(int i=0;i<Q;++i){
        // scanf("%d ", &q);
        q = scan();
        if(q==0){
            // scanf("%d %d", &L, &R);
            L = scan();
            R = scan();
            if(bit_arr[R]==0) printf("EVEN\n");
            else printf("ODD\n");
            
        }else{
            // scanf("%d ", &q);
            q = scan();
            bit_arr[q] = 1 - bit_arr[q];
        }
    }
    return 0;
}

C#:
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
                //TestCases();
                Solve();
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
            console.SkipNextLine();
 
            bool[] bits = new bool[n + 1];
            for (int i = 1; i <= n; i++)
            {
                bits[i] = console.Read() == 49;
                console.Skip();
            }
            console.Skip();
 
            for (int i = 0; i < m; i++)
            {
                if (console.Read() == 49)
                {
                    bits[console.NextInt()] ^= true; //Flips the bool
                }
                else
                {
                    console.SkipNext();
                    console.WriteLine(bits[console.NextInt()] ? "ODD" : "EVEN");
                }
                console.SkipNextLine();
            }
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
            this.inStream = new BufferedStream(Console.OpenStandardInput(bufferSize), bufferSize);  //Submission stream
            //this.inStream = new BufferedStream(File.OpenRead(@"..\..\test.txt"), bufferSize);     //Test stream
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

Java:
import java.lang.System;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.io.OutputStreamWriter;
 
import javax.imageio.stream.FileImageInputStream;
 
public class StaticReaderTesing {
	
	public static void main(String[] args) throws IOException {
		DataInputStream dis = new DataInputStream(System.in);
		DataOutputStream ois = new DataOutputStream(System.out);
		Reader r = new Reader(dis);
		Writer1 w = new Writer1(ois);
		
		int arraySize = r.nextInt();
		int[] input = new int[arraySize];
		int totolInputs = r.nextInt();
		
		for(int i=0;i<arraySize;i++) {
			input[i] = r.nextInt();
		}
		
		int x;
    	for(int i=0;i<totolInputs;i++) {
			x = r.nextInt();
			if(x == 0) {
				r.nextInt();
				if(input[r.nextInt()-1] == 0) {
					w.write(true);
				}
				else {
					w.write(false);
				}
			}else {
				int token = r.nextInt();
				input[token-1] = input[token-1] ^ 1;
			}
		}
		w.flush();
	}
	
	static class Reader{
		
		private DataInputStream dis = null;
		private int bufferSize = 1 << 24;
		private byte[] by = new byte[bufferSize];
		private int read = 0;
		private int count = 0;
		private int index = -1;
		
		Reader(){}
		
		Reader(DataInputStream is){
			this.dis = is;
		}
		
		private boolean loadBuffer() throws IOException {
			while((read = dis.read(by)) != -1) {
				return true;
			}
			return false;
		}
		
		private int readCharAsInt() throws IOException {
			if(index < 0 || index >= read )
				if(loadBuffer())
					index = 0;
				else
					return -1;
			if(index < read) {
				int temp = index;
				index++;
				if(by[temp] != 0) {
					return by[temp];}
				else
					return -1;
			}
			return -1;
		}
		
		public int nextInt() throws IOException{
			int temp = 0;
			int num = 0;
			boolean status = false;
			
			while((temp = readCharAsInt()) != -1) {
				if(temp >= 48 && temp<= 57) {
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
	
	static class Writer1{
		
		byte[] buffer = new byte[1<<16];
		int bufferIndex = 0;
		DataOutputStream dis;
		int count = 0;
		byte[] evenBytes = ("EVEN"+System.lineSeparator()).getBytes(Charset.forName("UTF-8"));
		byte[] oddBytes = ("ODD"+System.lineSeparator()).getBytes(Charset.forName("UTF-8"));
		
		Writer1(){}
		
		Writer1(DataOutputStream dis){
			this.dis = dis;
		}
		
		private void write(boolean status) throws IOException{
			if(status)
				updateBuffer(evenBytes);
			else
				updateBuffer(oddBytes);
		}
 
		private void updateBuffer(byte[] by) throws IOException {
			if(bufferIndex >= buffer.length - 5) {
				writeBuffer();
				bufferIndex = 0;
			}
			for(int i=0;i<by.length;i++) {
				buffer[bufferIndex] = by[i];
				bufferIndex++;
			}
		}
 
		private void writeBuffer() throws IOException{
			dis.write(buffer, 0, bufferIndex);
		}
		
		private void flush() throws IOException {
			writeBuffer();
			dis.flush();
			dis.close();
		}
		
	}
}

Java 8:
import java.lang.System;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.io.OutputStreamWriter;
 
import javax.imageio.stream.FileImageInputStream;
 
public class StaticReaderTesing {
	
	public static void main(String[] args) throws IOException {
		DataInputStream dis = new DataInputStream(System.in);
		DataOutputStream ois = new DataOutputStream(System.out);
		Reader r = new Reader(dis);
		Writer1 w = new Writer1(ois);
		
		int arraySize = r.nextInt();
		int[] input = new int[arraySize];
		int totolInputs = r.nextInt();
		
		for(int i=0;i<arraySize;i++) {
			input[i] = r.nextInt();
		}
		
		int x;
    	for(int i=0;i<totolInputs;i++) {
			x = r.nextInt();
			if(x == 0) {
				r.nextInt();
				if(input[r.nextInt()-1] == 0) {
					w.write(true);
				}
				else {
					w.write(false);
				}
			}else {
				int token = r.nextInt();
				input[token-1] = input[token-1] ^ 1;
			}
		}
		w.flush();
	}
	
	static class Reader{
		
		private DataInputStream dis = null;
		private int bufferSize = 1 << 24;
		private byte[] by = new byte[bufferSize];
		private int read = 0;
		private int count = 0;
		private int index = -1;
		
		Reader(){}
		
		Reader(DataInputStream is){
			this.dis = is;
		}
		
		private boolean loadBuffer() throws IOException {
			while((read = dis.read(by)) != -1) {
				return true;
			}
			return false;
		}
		
		private int readCharAsInt() throws IOException {
			if(index < 0 || index >= read )
				if(loadBuffer())
					index = 0;
				else
					return -1;
			if(index < read) {
				int temp = index;
				index++;
				if(by[temp] != 0) {
					return by[temp];}
				else
					return -1;
			}
			return -1;
		}
		
		public int nextInt() throws IOException{
			int temp = 0;
			int num = 0;
			boolean status = false;
			
			while((temp = readCharAsInt()) != -1) {
				if(temp >= 48 && temp<= 57) {
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
	
	static class Writer1{
		
		byte[] buffer = new byte[1<<16];
		int bufferIndex = 0;
		DataOutputStream dis;
		int count = 0;
		byte[] evenBytes = ("EVEN"+System.lineSeparator()).getBytes(Charset.forName("UTF-8"));
		byte[] oddBytes = ("ODD"+System.lineSeparator()).getBytes(Charset.forName("UTF-8"));
		
		Writer1(){}
		
		Writer1(DataOutputStream dis){
			this.dis = dis;
		}
		
		private void write(boolean status) throws IOException{
			if(status)
				updateBuffer(evenBytes);
			else
				updateBuffer(oddBytes);
		}
 
		private void updateBuffer(byte[] by) throws IOException {
			if(bufferIndex >= buffer.length - 5) {
				writeBuffer();
				bufferIndex = 0;
			}
			for(int i=0;i<by.length;i++) {
				buffer[bufferIndex] = by[i];
				bufferIndex++;
			}
		}
 
		private void writeBuffer() throws IOException{
			dis.write(buffer, 0, bufferIndex);
		}
		
		private void flush() throws IOException {
			writeBuffer();
			dis.flush();
			dis.close();
		}
		
	}
}

JavaScript(Rhino)
importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new Scanner(System['in']);					// Reading input from STDIN
 
 
var N = sc.nextInt();
var Q = sc.nextInt();
var arr = [];
var Qid;
var L,R,X;
 
for(var i=0; i<N; i++){
    arr.push(sc.nextInt());
}
 
for(var j=0; j<Q;j++){
    Qid = sc.nextInt();
    if(Qid === 0){
        L = sc.nextInt();;
        R = sc.nextInt();
        
        if(arr[R-1] === 1){
            System.out.println("ODD");
        }else{
            System.out.println("EVEN");
        }
    }else{
        X =  sc.nextInt();
        X--;
        arr[X] = 1 - arr[X]
    }
}
 
JavaScript(Node.js) 
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
 
    input = input.split('\n');
    let loop = input[0].split(' ')[1];
    let ele = input[1].split(' ');
    let final = "";
    for(let i = 0; i < loop; i++) {
        let val = input[i+2].split(' ');
        if(val.length === 2) {
            let fl = parseInt(val[1]);
            ele[fl-1] = (ele[fl-1] ===  '0' ?  '1' : '0');
        } else {
            final += (ele[parseInt(val[2])-1] === '0' ? "EVEN\n" : "ODD\n");
        }
        
    }
    console.log(final);
    
    // process.stdout.write("Hi, " + input + ".\n");       // Writing output to STDOUT
}
 
Pascal:
Program HiHere;
VAR n,q,i,j,t,e,er:int64; numb:array[1..1000001] of integer;
Begin
Readln(n,q);
for i:=1 to n do
Begin
Read(numb[i]);
end;
Readln;
for i:=1 to q do
Begin
Read(t);
if (t = 1) then
Begin
Readln(e);
if (numb[e] = 0) then numb[e]:=1 else numb[e]:=0;
end else
Begin
Readln(e,er);
if (numb[er] = 0) then Writeln('EVEN') else Writeln('ODD');
end;
end;
Readln;
END.

Perl:
use strict;
use warnings;
 
my @line1 = split(" ",<STDIN>);
my $N = $line1[0];
my $Q = $line1[1];
 
my @arr = split(" ",<STDIN>);
for(my $i=1;$i<=$Q;$i++)
{
    my @line= split(" ",<STDIN>);
    if($line[0]==1)
    {
        $arr[$line[1]-1] = ($arr[$line[1]-1]==0) ? 1 : 0;
    }
    elsif($line[0]==0)
    {
        my $val = ($arr[$line[2]-1]==1) ? "ODD" : "EVEN";
        print "$val\n";
    }
}

PHP:
<?php

// Sample code to perform I/O:
//fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
//echo "Hi, ".$name.".\n";                // Writing output to STDOUT
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
// Write your code here

list(,$q) = explode(' ',trim(fgets(STDIN)));
$arr = explode(' ',trim(fgets(STDIN)));
 
while($q > 0){
    $ln  = explode(' ',trim(fgets(STDIN)));
    if($ln[0] == 0){
            echo ($arr[$ln[2] - 1] == 1) ? 'ODD'.PHP_EOL:'EVEN'.PHP_EOL;
    }else{
        $arr[$ln[1] - 1] = !($arr[$ln[1] - 1]);     
    }
    $q--;
}
?>

Python:
def f():
    b = raw_input().split()
    q = int(b[1])
    a = raw_input().split()
    for i in range(q):
        b = raw_input().split()
        if b[0] == '0':
            if a[int(b[2]) - 1] == '0':
                print "EVEN"
            else:
                print "ODD"
        else:
            t = int(b[1]) - 1
            if a[t] == '0':
                a[t] = '1'
            else:                
                a[t] = '0'
f()

Python 3:
from sys import stdin, stdout
 
# import time
 
var = stdin.readline().strip().split()
inp = stdin.readline().strip().split()
out = {'1': '0', '0': '1'}
out2 = {'1': 'ODD\n', '0': 'EVEN\n'}
for _ in range(int(var[1])):
    # s = time.time()
    each = stdin.readline().split()
    # print("0", time.time() - s)
    pos = int(each[-1])-1
    if each[0] is '1':
        # s = time.time()
        inp[pos] = out[inp[pos]]
        # print("1", time.time() - s)
    else:
        # s = time.time()
        # ex = inp[int(each[1]) - 1:int(each[2]) - 1]
        stdout.write(out2[inp[pos]])
        # print("2", time.time() - s)


Ruby:
NQ = gets.chomp.split
N = NQ[0].to_i
Q = NQ[1].to_i
arr = gets.chomp.split.map(&:to_i)
 
Q.times do
	qq = gets.chomp.split
 
	if qq[0].to_i == 1
		q1 = qq[1].to_i - 1
		arr[q1] = arr[q1] == 1 ? 0 : 1
	elsif arr[qq[2].to_i - 1] == 1 
		puts("ODD")
	else
		puts("EVEN")
	end
end	

*/


/*Editorial:
For update query just set A[x] = 1 - A[x] and for each query of type L,R just check if A[R] is 1 then print ODD or print EVEN. 
A binary number is ODD if its 0th bit is 1

Fast I/O mechanism should be used for this problem. 
import java.io.BufferedReader; 
import java.io.InputStreamReader;

class TestClass { 
	public static void main(String args[]) 
		throws Exception { 
			try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) 
			{ 
				StringBuilder output = new StringBuilder();
				String[] nq = br.readLine().split("\\s");
				int N = Integer.parseInt(nq[0]);
				int Q = Integer.parseInt(nq[1]);

				String arr = br.readLine();
				int[] A = new int[N];
				int len = arr.length();
				int i=0;
				for (int n = 0; n < len; n += 2)
				{
					A[i++] = arr.charAt(n) == '0' ? 0 : 1;
				}

				for (int q = 0; q < Q; q++)
				{
					String[] qry = br.readLine().split("\\s");
					int t = Integer.parseInt(qry[0]);
					if (t == 0)
					{
						int R = Integer.parseInt(qry[2]);
						if (A[R - 1] == 0)
						{
							output.append("EVEN");
						}
						else
						{
							output.append("ODD");
						}
						output.append('\n');
					}
					else
					{
						int x = Integer.parseInt(qry[1]);
						A[x - 1] = 1 - A[x - 1];
					}
				}

				System.out.println(output);
			}
	}
}

// solution in c language //contributor : Ruhul Amin Choudhury
include
int main() {

int N , Q , i , j , L , R;

scanf("%d%d",&N,&Q);
int a[N] , b[Q] , bit , value;

for( i = 1 ; i <= N ; i++)
   scanf("%d",&a[i]);

while(Q--)
{
 scanf("%d",&value);
if( value == 1)
    {
        scanf("%d",&bit);
            if(a[bit] == 0)
                a[bit] = 1;
            else
                a[bit] = 0 ;
    }
else
    {
        // value is 0
        scanf("%d%d",&L,&R); /// if last bit  in array is 1 i.e suppose 1 1 0 1 in array i.e last number will be odd..see the last bit of array  
        if(a[R] == 1)
            printf("ODD\n");
        else
            printf("EVEN\n");
    }
}
return 0;
}

*/