/* Tag(s):Stacks

SuperProfs Hiring Challenge: The Football Fest

The very famous football club Manchester United decided to popularize football in India by organizing a football fest. The fest had many events for different sections of people.
For the awesome coders of Hacker Earth, there was an event called PASS and BACK. In this event, the coders were given N passes and players having ids between 1 and 1000000.
Initially some player with a given id had the ball in his possession. The coders had to make a program to display the id of the player who possessed the ball after exactly N passes.

Description of the passes:
There were two kinds of passes:
1.P ID
2.B

Explanation :
for the first kind of pass, the player in possession of the ball passes the ball to player with id=ID while for the second kind of a pass, 
the player in possession of the ball passes the ball back to the player who had passed the ball to him.

NOTE:
It is guaranteed that the given order of all the passes will be a valid order .

INPUT :
The first line of the input contains the number of test cases. For each test case, two space separated integers N and ID ( of the player possessing the ball in the very beginning). 
N lines follow describing the passes. ( for description of the passes, refer the statement above. )

OUTPUT :
Output to each test case should be a single line containing the "Player" ID (quotes for clarity) of the player who possesses the ball after N passes.

Constraints
1<=T<=100
1<=N<=10^5
1<=ID<=10^6

SAMPLE INPUT 
1
10 23
P 86
P 63
P 60
B
P 47
B
P 99
P 9
B
B
SAMPLE OUTPUT 
Player 9

Explanation
Initially, Player having id=23 posses ball. 
After pass 1, Player having id=86 posses ball. 
After pass 2, Player having id=63 posses ball. 
After pass 3, Player having id=60 posses ball. 
After pass 4, Player having id=63 posses ball. 
After pass 5, Player having id=47 posses ball. 
After pass 6, Player having id=63 posses ball. 
After pass 7, Player having id=99 posses ball. 
After pass 8, Player having id=9 posses ball. 
After pass 9, Player having id=99 posses ball. 
After pass 10, Player having id=9 posses ball.



#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 100
#define N 100000
 
int main()
{
    int passes=0,t=0,j=0,pid=0,tc=0,s=0,passarr[N];
    char line[MAXLINE];
    scanf("%d",&tc);
    for(;s<tc;s++){
        scanf("%d",&passes);
        scanf("%d",&pid);
        t=0;
        passarr[t]=pid;
        while(passes>=0){
            if(fgets(line,MAXLINE,stdin)!=NULL){
                j=0;
                if(line[j]=='P'){
                    j+=2;
                    passarr[++t]=atoi(line+j);
                }
                else if(line[j]=='B'){
                    pid=passarr[t-1];
                    passarr[++t]=pid;
                }
            }
            passes=passes-1;
        }
        printf("Player %d\n",passarr[t]);
    }
    return 0;
}
*/


/*My Cpp solution:

#include <iostream>
using namespace std;
#include <cstdlib>
#define MAXLINE 100
#define N 100000
 
int main()
{
    int passes=0,t=0,j=0,pid=0,tc=0,s=0,passarr[N];
    char line[MAXLINE];
    cin>>tc;
    for(;s<tc;s++){
        cin>>passes;
        cin>>pid;
        t=0;
        passarr[t]=pid;
        while(passes>=0){
            if(fgets(line,MAXLINE,stdin)!=NULL){
                j=0;
                if(line[j]=='P'){
                    j+=2;
                    passarr[++t]=atoi(line+j);
                }
                else if(line[j]=='B'){
                    pid=passarr[t-1];
                    passarr[++t]=pid;
                }
            }
            passes=passes-1;
        }
        cout<<"Player "<<passarr[t]<<endl;
    }
    return 0;
}

*/


/* Best Submissions:
C:
// Write your code here
#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    int i;
    for(i = 0; i < t; i++){
        int n, p;
        scanf("%d%d", &n, &p);
        int j;
        int arr[n];
        arr[0] = p;
        int curr = arr[0];
        getchar();
        for(j = 0; j < n; j++){
            char c = getchar();
            if(c=='B'){
                arr[j+1] = arr[j-1];
            }
            else if(c=='P'){
                int a;
                getchar();
                scanf("%d", &a);
                arr[j+1] = a;
            }
            curr = arr[j+1];
            getchar();
            //printf("%c\n", c);
        }
        printf("Player %d\n",curr);
    }
}
Alt C Solution:
#include<stdio.h>
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
   {
        int n,k,f,f2,b=0;
        scanf("%d%d",&n,&k);
        getchar();
        while(n--)
        {
           char c=getchar();
           if(c=='P')
             {
                 getchar();
                 f2=f;
                 scanf("%d",&f);
                 b=0;
             }
            if(c=='B')
              {
                  b++;
                      int temp=f;
                       f=f2;
                       f2=temp;
                   
              }
         getchar();      
        }
         printf("Player %d\n",f);
   }    
}


C++:
#include <bits/stdc++.h>
 
using namespace std;
 
stack < int > s;
 
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);          // Decrease Time of cin, cout.
 
    int n , t, d, id;
    char c;
 
    cin >> t;
 
    while(t--){
 
        cin >> n >> d;
 
        while(!s.empty()) s.pop();      // clear the stack in each test case
 
        s.push(d);
 
        for(int i = 0; i < n; i++){
 
            cin >> c;
 
            if(c == 'B'){
 
                int second = s.top();   // pop 2 elements
                s.pop();
 
                int first = s.top();
                s.pop();
 
                s.push(second);     // push the 2 elements in reverse order
                s.push(first);
                continue;
            }
 
            cin >> id;
            s.push(id);         // normal pushing in the stack 
        }
 
        cout << "Player " << s.top() << "\n";
    }
 
    return 0;
}

C++14:
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n, curr;
        cin>>n>>curr;
        int prev = 0;
        while(n--)
        {
            char c;
            cin>>c;
            if(c=='P')
            {
                prev = curr;
                cin>>curr;
            }
            else
            {
                swap(curr, prev);
            }
        }
        cout<<"Player "<<curr<<"\n";
    }
}


C#:
/* ============================== *\
 *    All code by stupid_chris    *
 *      ©(Christophe Savard)      *
 * Concordia University, Montreal *
 *              2017              *
\* ============================== */
 
#define TESTCASES
 
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
            using (Console)
            {
#if TESTCASES
                TestCases();
                #else
                Solve();
#endif
            }
        }
 
        #if TESTCASES
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
        #endif
        #endregion
 
        #region Solution
        /// <summary>
        /// Solution
        /// </summary>
        private static void Solve()
        {
            int n = Console.NextInt(), current = Console.NextInt();
            Console.SkipNextLine();
            
            int last;
            for (int i = 0; i < n; i++)
            {
                if (Console.NextChar() == 'P')
                {
                    last = current;
                    current = Console.NextInt();
                }
                else unsafe { Swap(&last, &current); }
                Console.SkipNextLine();
            }
            Console.WriteLine("Player " + current);
        }
        
        private static unsafe void Swap(int* a, int* b)
        {
            int t = *a;
            *a = *b;
            *b = t;
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
            //Open the input/output streams
#if DEBUG
            //Test mode
            this.inStream = new BufferedStream(File.OpenRead(@"..\..\input.txt"), bufferSize);
            this.outStream = new BufferedStream(File.Create(@"..\..\output.txt", bufferSize), bufferSize);
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
        /// Writes the contents of the StringBuilder to the console output
        /// </summary>
        /// <param name="sb">StringBuilder to write to the output</param>
        public void Write(StringBuilder sb)
        {
            char[] buffer = new char[sb.Length];
            sb.CopyTo(0, buffer, 0, sb.Length);
            Write(buffer);
        }
 
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
        public void Write<T>(IEnumerable<T> e, string separator = "") => Write(new StringBuilder().AppendJoin(e, separator));
 
        /// <summary>
        /// Writes a sequence to the console output with the given string separator
        /// </summary>
        /// <typeparam name="T">Type of elements in the sequence</typeparam>
        /// <param name="e">Sequence to print</param>
        /// <param name="separator">Character separator between each element</param>
        public void Write<T>(IEnumerable<T> e, char separator) => Write(new StringBuilder().AppendJoin(e, separator));
 
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
        /// Writes the contents of the StringBuilder to the console output, followed by a linefeed
        /// </summary>
        /// <param name="sb">StringBuilder to write to the output</param>
        public void WriteLine(StringBuilder sb)
        {
            Write(sb);
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
        /// Writes a sequence to the console output with the given string separator, follows by a linefeed
        /// </summary>
        /// <typeparam name="T">Type of elements in the sequence</typeparam>
        /// <param name="e">Sequence to print</param>
        /// <param name="separator">Character separator between each element</param>
        public void WriteLine<T>(IEnumerable<T> e, char separator)
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
        /// Joins all the elements of the enumerable into a string
        /// </summary>
        /// <typeparam name="T">Type of elements in the Enumerable</typeparam>
        /// <param name="e">Enumerable to loop through</param>
        /// <param name="separator">Separator character</param>
        public static string Join<T>(this IEnumerable<T> e, char separator) => new StringBuilder().AppendJoin(e, separator).ToString();
 
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
Soln1:
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.io.IOException;
class TestClass {
    public static void main(String args[] ) throws Exception {
        FastReader sc = new FastReader();
        int T= sc.nextInt();
        for(int t = 0 ; t  <T ; t++){
            int n = sc.nextInt();
            //Stack<Integer> st = new Stack<>();
            int curr_id = sc.nextInt();
            int prev_id = -1;
            //st.push(sc.nextInt());
            for(int i = 0 ; i < n ;i++){
                String s = sc.next();
                if(s.equals("P")){
                    prev_id = curr_id;
                    curr_id = sc.nextInt();
                   // st.push(sc.nextInt());
                }else {
                    int temp = curr_id;
                    curr_id = prev_id;
                    prev_id = temp;
                    
                    //int temp = st.pop();
                    //int p = st.pop();
                    //st.push(p);
                    //st.push(temp);
                    //st.push(p);
                }
            }
            System.out.println("Player "+curr_id);
            
        }
 
    }
    public static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while(st==null || !st.hasMoreElements()){
                try {
                    st = new StringTokenizer(br.readLine());
                }catch (IOException e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt(){
            return Integer.parseInt(next());
        }
    }
    
}

Soln2(Efficient):
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.io.IOException;
class TestClass {
    public static void main(String args[] ) throws Exception {
        Reader sc = new Reader();
        int T= sc.nextInt();
        for(int t = 0 ; t  <T ; t++){
            int n = sc.nextInt();
            int curr_id = sc.nextInt();
            int prev_id = -1;
            for(int i = 0 ; i < n ;i++){
                char s = sc.nextChar();
                if(s=='P'){
                    prev_id = curr_id;
                    curr_id = sc.nextInt();
                }else {
                    int temp = curr_id;
                    curr_id = prev_id;
                    prev_id = temp;
                }
            }
            System.out.println("Player "+curr_id);
            
        }
        sc.close();
 
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
        public char nextChar() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
 
            return (char) c;
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

Java 8:
Soln(Efficient)
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.io.*;
 
//
//Created by mahantys on 25/12/16.
//
 
public class FootballFest {
 
    static BufferedReader br;
    static Reader reader;
 
    public static int findPlayerAfterLastPass(int n, int startId) throws IOException {
        int curr = startId;
        int prev = -1;
        if (n == 1) {
            return startId;
        }
 
        for (int i = 0; i < n; i++) {
            // String line = br.readLine();
            int element = prev;
            char op = reader.nextChar();
            if (op == 'P') {
                element = reader.nextInt();
            }
            //System.out.println("OP: " + op + "   value: " + element);
            prev = curr;
            curr = element;
        }
 
        return curr;
    }
 
    public static int parseInt(final String s) {
        final int len = s.length();
        final char ch = s.charAt(0);
        int num = '0' - ch;
        int i = 1;
 
        while (i < len)
            num = num * 10 + '0' - s.charAt(i++);
 
        return num * -1;
    }
 
    public static void main(String[] args) throws IOException {
        reader = new Reader();
        //br = new BufferedReader(new FileReader("testdata/footballfest"));
        int c = reader.nextInt();
        //long startTime = System.currentTimeMillis();
        for (int i = 0; i < c; i++) {
            //String[] tokens = br.readLine().split(" ");
            int n = reader.nextInt();
            int startId = reader.nextInt();
            //System.out.println(" N: " + n + "  startId: " + startId);
            int result = findPlayerAfterLastPass(n, startId);
            System.out.println("Player " + result);
        }
        //long endTime = System.currentTimeMillis();
        //System.out.println("Time: " + ((double) (endTime - startTime) / 1000) + " second(s)");
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
 
        public char nextChar() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
 
            return (char) c;
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
            }
            while ((c = read()) >= '0' && c <= '9');
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
            }
            while ((c = read()) >= '0' && c <= '9');
 
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
}

Soln2:
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.File;
import java.util.*;
import java.util.stream.*;
 
class TestClass {
 
    private static Integer[] passStack;
 
    public static void main(String args[] ) throws Exception {
        Integer testCases = 0;
        Scanner s = new Scanner(System.in);
        testCases = Integer.valueOf(s.nextLine());
 
        int testCase = 1;
        do {
            String initial[] = s.nextLine().split(" ");
            int totalPasses = Integer.valueOf(initial[0]);
            // Add the first player
            passStack = new Integer[totalPasses];
            passStack[0] = Integer.valueOf(initial[1]);
            
            Integer player = passStack[0];
            Integer previousPlayer = -1;
            Integer nextPlayer = -1;
            int pass = 1;
            do {
                String input[] = s.nextLine().split(" ");
                if (input[0].equalsIgnoreCase("P")) {
                    nextPlayer = Integer.valueOf(input[1]);
                } else if (input[0].equalsIgnoreCase("B")) {
                    nextPlayer = previousPlayer;
                } else continue;
 
                previousPlayer = player;
                player = nextPlayer;
 
                passStack[pass - 1] = player;
                pass++;
            } while (pass <= totalPasses);
            System.out.println("Player " + player);
            testCase++;
        } while (testCase <= testCases);
    }
}

Java(Node.js):
function main(input) {
    lc = -1;
    lines = input.split('\n');
    T = +lines[++lc];
    for(t=0;t<T;t++){
        ND = lines[++lc].split(' ');
        N = +ND[0];
        s=[];
        s.push(ND[1]);
        for(i=0;i<N;i++){
            val=lines[++lc].split(' ');
            if(val[0]=='P'){
                s.push(val[1]);
            }
            else
            {
                s.push(s[s.length-2]);
            }
        }
     process.stdout.write('Player '+s.pop()+"\n");
    }
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
 
Pascal:
Soln1:
var 
num,n,i,pre,id,ntest,itest:int64;
str:ansistring;
 
procedure swap(var x,y:int64);
var tmp:longint;
begin
    tmp:=x;
    x:=y;
    y:=tmp;
end;
 
function change(s:ansistring):int64;
var i,tmp:longint;
begin
    tmp:=0;
    for i:=1 to length(s) do
    tmp:=tmp*10+ord(s[i])-48;
    change:=tmp;
end;
 
procedure solve;
begin
    pre:=0;
    id:=0;
    readln(n,id);
    for i:=1 to n do
    begin
        readln(str);
        if str[1]='P' then
        begin
            str:=copy(str,3,length(str)-2);
            num:=change(str);
            pre:=id;
            id:=num;
        end
        else
        begin
            swap(pre,id);
        end;
    end;
        writeln('Player ',id);
end;
 
begin
    readln(ntest);
    for itest:=1 to ntest do
    solve;
end.

Soln2:
uses crt;
var a,b,d,e,f,g,i,j,k,n,m,count,t:longint;
type d2a=array[1..1000,1..1000] of longint;
var gr:d2a;
var s,bf,cr,c:string;
var ed,ar:array[1..1000000] of longint;
begin
        readln(t);
        for i:=1 to t do
        begin
                bf:='';
                cr:='';
                readln(n,m);
                for j:=1 to n do
                begin
                        readln(s);
                        if(s[1]='P') then
                        begin
                                bf:=cr;
                                cr:='';
                                for k:=1 to length(s)-2 do
                                begin
 
                                        cr:=cr+s[k+2]
                                end;
                                continue;
                        end;
                        if(bf='') then continue;
                        c:=bf;
                        bf:=cr;
                        cr:=c;
                end;
                writeln('Player ',cr);
        end;
 
 
end.
 
PHP:

<?php
    //define('STDINPUT',fopen("testcase.txt","r"));
    $lastPlayerId = 0;
    fscanf(STDIN, "%d", $testcase);
 
    for($i = 0;$i < $testcase;$i++)
    {
        fscanf(STDIN, "%d %d", $noOfPasses,$playerId);
        for($k = 0;$k < $noOfPasses;$k++)
        {
            fscanf(STDIN, "%s %d", $passType, $nextPlayerId); 
            if($passType == 'P')
            {
                $lastPlayerId = $playerId;
                $playerId = $nextPlayerId;
            }
            else
            {
                $temp = $lastPlayerId;
                $lastPlayerId = $playerId;
                $playerId =$temp;
            }
        }
        echo "Player ".$playerId ;
        echo PHP_EOL;
    }
?>

Python:

import sys
t=input()
for i in xrange(t):
    nPas,current=sys.stdin.readline().split()
    nPas=int(nPas)
    ar=list()
    ar.append(current)
    for j in xrange(nPas):
        inp=sys.stdin.readline()
        if("P" in inp):
            ar.append(inp[2:])
        else:
            ar.append(ar[len(ar)-2])
    print "Player %s" % ar[len(ar)-1]

Python 3:

num=int(input())
for i in range(num):
    k=list(map(int,input().split(" ")))
    
    past=None
    present=k[1]
    for j in range(k[0]):
        tem=list(map(str,input().split(" ")))
        if(tem[0]=="P"):
            past=present
            present=tem[1]
            
        if(tem[0]=="B"):
            present,past=past,present
            
    print("Player",present)        

Ruby:
tc = gets.strip.to_i
(1..tc).each do |t|
	n, id = gets.strip.split(" ").map(&:to_i)
	prev, next1, result = 0, id, id
	(1..n).each do |p|
		c, pass_to = gets.strip.split(" ")
		if c == 'P'
			prev = next1
			next1 = pass_to
		else
			prev, next1 = next1, prev
		end
		result = next1
	end
	puts "Player "+result
end


*/
