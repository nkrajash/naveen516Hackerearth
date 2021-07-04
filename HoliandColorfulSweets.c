/*All Tracks --> Basic Programming --> Implementation --> Basics of Implementation --> Problem -->

Tag(s): Basic Programming, Basics of Implementation, Easy, Implementation
This Holi, Monk wants to distribute sweets to the houses of his colony. 
The houses of the colony are present in a circular order (i.e. house 1 and house N are adjacent to each other).

Kids love to play with colors but currently there is a supply of only 2 types of colors (Red represented by R and Green represented by G). 
Due to festive season each of the kids have colored their houses with either green or red color.

"HAPPY HOLI"

Monk is given a task of distributing sweets Q number of times. Every time he is asked to travel from xth house to yth house to distribute the sweets.
The distribution strategy is that he starts from xth house and he has to give 1 sweet to a house only when he travels from green house to a red house or vice-versa. 
Monk can travel from xth house to yth house either in clockwise direction or in anti-clockwise direction.
Monk wants your help to find the minimum number of sweets he should carry to complete his journey.

Input Format:
First line contains an integer T denoting the number of test cases.
Each test case contains an integer N and Q.
Next line contains a string S (representing the house colors) of length N.
Then Q lines follow, each containing 2 integers x and y.

Output Format:
For each test case print Q lines containing the minimum number of sweets he must carry with himself.

Input Constraints:
1<=T<=100
1<=N<=Q<=1000
1<x<=y<=N
S consists of only letters 'G' and 'R'

SAMPLE INPUT 
2
5 2
RRRGG
1 5
3 2
5 2
GGRGG
2 5
3 1
SAMPLE OUTPUT 
1
0
0
1
Explanation:
Case 1:
For 1st query, if we travel in the direction 1->2->3->4->5, we need only one sweet . 
If we travel in the direction 1->5, we need only one sweet. So he has to carry only 1 sweet.
For 2nd query, if we travel in the direction 3->4->5->1->2, we need two sweets. 
If we travel in the direction 3->2, we need no sweets. So he has to carry 0 sweets.

Case 2:
For 1st query house, 2 and 5 can be travelled using path 2->1->5 without any change of colors so he has to carry 0 sweets.
For 2nd query house 3 and 1 can be travelled using path 3->2->1 with a change of color so he has to carry 1 sweet.

//My C Solution:
#include <stdio.h>
#define LEN 1001
#define MIN(a,b) ((a<b)?(a):(b))

int main()
{
    int t,N,Q,i,j,sweets,clockwise_sweets,anti_clockwise_sweets,changes[LEN],left,right;
	char house[LEN];
    scanf("%d",&t);
    while(t--){
		    scanf("%d%d",&N,&Q);
			scanf("%s",house);
			changes[0] = 0;
			for(i = 1; i < N; i++)
				changes[i] = changes[i-1] + (house[i] != house[i - 1]);
			while(Q--)
			{
				scanf("%d%d",&left,&right);
				if(left > right) {
					j=left;
					left=right;
					right=j;
				}

				clockwise_sweets = changes[right-1] - changes[left-1];

				anti_clockwise_sweets = (changes[N-1] - changes[right-1])
										+  (changes[left-1] - changes[0])
										+  (house[N-1] != house[0]);

				sweets = MIN(clockwise_sweets, anti_clockwise_sweets);
				printf("%d\n",sweets);
			}
	}
    return 0;
}

//My C++ Solution:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int length, no_of_queries;
    cin >> length >> no_of_queries;

    char house[length + 1]; cin >> (house + 1);

    vector <int> no_of_changes_till(length + 1, 0);
    for(int i = 2; i <= length; i++)
    {
        no_of_changes_till[i] = no_of_changes_till[i - 1] + (house[i] != house[i - 1]);
    }

    while(no_of_queries--)
    {
        int left, right;
        cin >> left >> right;

        if(left > right) swap(left, right);

        int clockwise_answer = no_of_changes_till[right] - no_of_changes_till[left];

        int anti_clockwise_answer = (no_of_changes_till[length] - no_of_changes_till[right])
                                +  (no_of_changes_till[left] - no_of_changes_till[1])
                                +  (house[length] != house[1]);

        int answer = min(clockwise_answer, anti_clockwise_answer);
         cout << answer << "\n";
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
*/

/*Best Submissions:
C:
#include <stdio.h>
 
typedef long int lint;
 
lint get_lint() { //Positive
	lint n =0;
	register int c = getchar_unlocked();
	while(c<'0' || c>'9') c = getchar_unlocked();
	while(c>='0' && c<='9') {
		n = n * 10 + c-'0';  c = getchar_unlocked();
    }
	return n;
}
void put_lint (lint li, char lc) {//Negative
	if (0 == li) {
		putchar_unlocked((int)'0');
		putchar_unlocked((int)lc);
		return;
	}
	char s[24];
	auto idx =0;
	for (; li; idx++) {
		s[idx] = '0' + li % 10;
		li /= 10;
	}
	for (auto jdx=idx-1; jdx>=0; jdx--)
		putchar_unlocked((int)s[jdx]);
	if(lc) putchar_unlocked((int)lc);
	return;
}
lint get_str(char *s, int l) { // ISLOWER
	register int c = getchar_unlocked();
	lint idx=0;
	while(isupper(c) && idx<l) {
		s[idx++] = (char)c;
		c = getchar_unlocked();
	}
	s[idx] = '\0';
	return idx;
}
 
int main () {
	lint T = get_lint();
	while(T--) {
        char str[1001];
        int safc [1001] = {0};
        lint SL = get_lint();
        lint Q = get_lint();
        lint sl = get_str(str, sizeof(str));
        
        safc[0] =0;
        for (auto ci=1; ci<sl; ci++) {
            safc[ci] = safc[ci-1];
            if (str[ci]!=str[ci-1]) safc[ci] ++;
        }
        safc [sl] = safc[sl-1];
        if (str[0]!=str[sl-1]) safc[sl] ++;
        
        while (Q--) {
            lint L = get_lint() -1;
            lint R = get_lint() -1;
            if (L>R) L^=R^=L^=R; //swap
            lint aLen = safc[R] - safc[L];
            lint zLen = safc[L] - safc[0] + safc[sl] - safc[R];
            put_lint((aLen<=zLen)?aLen:zLen, '\n');
        }
	}
	return 0;
}

C++:
#include <bits/stdc++.h>
using namespace std;
 
string S;
 
int main()
{
    int T;
    scanf("%d", &T);
    
    while(T--)
    {
        int N, Q;
        scanf("%d %d", &N, &Q);
        
        cin >> S;
        
        while(Q--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            x--, y--;
            
            if(x > y)
                swap(x, y);
            
            int ans1 = 0, ans2 = (S[0] != S[N-1]);
            
            for(int i=x+1; i<=y; i++)
                ans1 += (S[i] != S[i-1]);
            
            for(int i=1; i<=x; i++)
                ans2 += (S[i] != S[i-1]);
            for(int i=y+1; i<N; i++)
                ans2 += (S[i] != S[i-1]);
            
            printf("%d\n", min(ans1, ans2));
        }
    }
    
    return 0;
}

C++14:
// Write your code here
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector <int> v(n);
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1])
                v[i] = 0;
            else
                v[i] = 1;
        }
        if (s.back() == s.front())
            v[n - 1] = 0;
        else
            v[n - 1] = 1;
        
        int sum = 0;
        for (int  i : v)
            sum += i;
        int ans;
        while(q--) {
            int a, b;
            cin >> a >> b;
            int cnt = 0;
            if (a <= b)
            {
                for (int i = a - 1; i < b - 1; i++)
                    cnt += v[i];
            }
            else
            {
                for (int  i = a - 2; i >= b - 1; i--)
                    cnt += v[i];
            }
            int ans = min(cnt, sum - cnt);
                cout << ans << "\n";
        }
    }
    return 0;
}

C#:
#define TESTCASES
 
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
 
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
            #region Constants
            /// <summary>
            /// Modulo operator used in a lot of questions
            /// </summary>
            private const long mod = 1000000007L;
            #endregion
 
            #region Constructors
            /// <summary>
            /// Any one time initializations should be done here
            /// </summary>
            public Solution()
            {
                
            }
            #endregion
 
            #region Methods
            /// <summary>
            /// Solution
            /// </summary>
            public void Solve()
            {
                int n = Console.NextInt(), t = Console.NextInt();
                Console.SkipNextLine();
                
                bool[] houses = new bool[2 * n];
                for (int i = 0; i < n; i++)
                {
                    houses[i] = houses[i + n] = Console.NextChar() == 'G';
                }
                Console.SkipNextLine();
 
                for (; t > 0; t--)
                {
                    int x = Console.NextInt() - 1, y = Console.NextInt() - 1;
                    Console.SkipNextLine();
                    if (x == y) { Console.WriteLine('0'); continue; }
 
                    if (x > y) { Swap(ref x, ref y); }
 
                    int t1 = 0;
                    bool current = houses[x];
                    for (int i = x + 1; i <= y; i++)
                    {
                        bool h = houses[i];
                        if (current != h)
                        {
                            t1++;
                            current = h;
                        }
                    }
 
                    int t2 = 0;
                    current = houses[x];
                    for (int i = x + n - 1; i >= y; i--)
                    {
                        bool h = houses[i];
                        if (current != h)
                        {
                            t2++;
                            current = h;
                        }
                    }
 
                    Console.WriteLine(Math.Min(t1, t2));
                }
            }
 
            public static void Swap(ref int a, ref int b)
            {
                int t = a;
                a = b;
                b = t;
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
 
    // Solution does not extend beyond this point, those are merely tools to help along
    #region Tools
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
    #endregion
}

Java:
import java.util.*;
import java.text.*;
import java.io.*;
import java.math.*;
public class code5 {
	InputStream is;
	PrintWriter out;
	static long mod=pow(10,9)+7;
	static int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
	ArrayList<Integer> al[];
	boolean edge[][];
	void solve() throws IOException
	{
		int t=ni();
		while(t--!=0)
		{
			int n=ni();
			int q=ni();
			String s=ns();
			int prefix[]=new int[n];
			for(int i=1;i<n;i++)
			{
				if(s.charAt(i)!=s.charAt(i-1))
					prefix[i]+=1;
				prefix[i]+=prefix[i-1];
			}
			while(q--!=0)
			{
				int x=ni()-1;
				int y=ni()-1;
				if(x>y)
				{
					x=x^y;
					y=x^y;
					x=x^y;
				}
				if(n==1)
				{
					out.println(0);
					continue;
				}
				int t1=prefix[y]-prefix[x];
				int t2=prefix[x]+prefix[n-1]-prefix[y]+(s.charAt(0)==s.charAt(n-1)?0:1);
				out.println(Math.min(t1,t2));
			}
		}
	}
	long ncr[][];
	int small[];
	void pre(int n)
	{
		small=new int[n+1];
		for(int i=2;i*i<=n;i++)
			
		{
			for(int j=i;j*i<=n;j++)
			{
				if(small[i*j]==0)
					small[i*j]=i;
			}
		}
		for(int i=0;i<=n;i++)
		{
			if(small[i]==0)
				small[i]=i;
		}
	}
	int sum(int i)
	{
		int sum=0;
		while(i!=0)
		{
			if((i%10)%2==1)
				sum+=i%10;
			i/=10;
		}
		return sum;
	}
	//ArrayList<Integer> al[]
 	//void take(int n,int m)
 	//{
 	//	al=new ArrayList[n];
 	//	for(int i=0;i<n;i++)
 	//		al[i]=new ArrayList<Integer>();
 	//	for(int i=0;i<m;i++)
 	//	{
 	//		int x=ni()-1;
 	//		int y=ni()-1;
 	//		al[x].add(y);
 	//		al[y].add(x);
 	//	}
 	//}
 	int check(long n)
 	{
 		int count=0;
 		while(n!=0)
 		{
 			if(n%10!=0)
 				break;
 			n/=10;
 			count++;
 		}
 		return count;
 	}
	public static int count(int x)
	{
		int num=0;
		while(x!=0)
		{
			x=x&(x-1);
			num++;
		}
		return num;
	}
	static long d, x, y;
	void extendedEuclid(long A, long B) {
	    if(B == 0) {
	        d = A;
	        x = 1;
	        y = 0;
	    }
	    else {
	        extendedEuclid(B, A%B);
	        long temp = x;
	        x = y;
	        y = temp - (A/B)*y;
	    }
	}
	long modInverse(long A,long M) //A and M are coprime
	{
	    extendedEuclid(A,M);
	    return (x%M+M)%M;    //x may be negative
	}
	public static void mergeSort(int[] arr, int l ,int r){
		if((r-l)>=1){
			int mid = (l+r)/2;
			mergeSort(arr,l,mid);
			mergeSort(arr,mid+1,r);
			merge(arr,l,r,mid);
		}
	}
	public static void merge(int arr[], int l, int r, int mid){
		int n1 = (mid-l+1), n2 = (r-mid);
		int left[] = new int[n1];
		int right[] = new int[n2];
		for(int i =0 ;i<n1;i++) left[i] = arr[l+i];
		for(int i =0 ;i<n2;i++) right[i] = arr[mid+1+i];
		int i =0, j =0, k = l;
		while(i<n1 && j<n2){
			if(left[i]>right[j]){
				arr[k++] = right[j++];
			}
			else{
				arr[k++] = left[i++];
			}
		}
		while(i<n1) arr[k++] = left[i++];
		while(j<n2) arr[k++] = right[j++];
	}
	public static void mergeSort(long[] arr, int l ,int r){
		if((r-l)>=1){
			int mid = (l+r)/2;
			mergeSort(arr,l,mid);
			mergeSort(arr,mid+1,r);
			merge(arr,l,r,mid);
		}
	}
	public static void merge(long arr[], int l, int r, int mid){
		int n1 = (mid-l+1), n2 = (r-mid);
		long left[] = new long[n1];
		long right[] = new long[n2];
		for(int i =0 ;i<n1;i++) left[i] = arr[l+i];
		for(int i =0 ;i<n2;i++) right[i] = arr[mid+1+i];
		int i =0, j =0, k = l;
		while(i<n1 && j<n2){
			if(left[i]>right[j]){
				arr[k++] = right[j++];
			}
			else{
				arr[k++] = left[i++];
			}
		}
		while(i<n1) arr[k++] = left[i++];
		while(j<n2) arr[k++] = right[j++];
	}
	 static class Pair implements Comparable<Pair>{
		 
	       int x,y,k;
	       int i,dir;
	       long val;
	       double pos;
		Pair (int x,int y){
			this.x=x;
			this.y=y;
		}   
		public int compareTo(Pair o) {
			return Double.compare(this.pos,o.pos);
		}
	 
		public String toString(){
			return x+" "+y+" "+k+" "+i+" "+val;}
		public boolean equals(Object o) {
			if (o instanceof Pair) {
				Pair p = (Pair)o;
				return p.x == x && p.y == y;
			}
			return false;
		}
		public int hashCode() {
			return new Long(x).hashCode()*31 + new Long(y).hashCode() ;
		}
	} 
	    
	    public static boolean isPal(String s){
	        for(int i=0, j=s.length()-1;i<=j;i++,j--){
	                if(s.charAt(i)!=s.charAt(j)) return false;
	        }
	        return true;
	    }
	    public static String rev(String s){
			StringBuilder sb=new StringBuilder(s);
			sb.reverse();
			return sb.toString();
	    }
	    
	    public static long gcd(long x,long y){
		if(y==0)
			return x;
		else
			return gcd(y,x%y);
	    }
	    
	    public static int gcd(int x,int y){
	    	if(y==0) 
	    		return x; 
	    	return gcd(y,x%y);
	    }
	    
	    public static long gcdExtended(long a,long b,long[] x){
	        
	        if(a==0){
	            x[0]=0;
	            x[1]=1;
	            return b;
	        }
	        long[] y=new long[2];
	        long gcd=gcdExtended(b%a, a, y);
	        
	        x[0]=y[1]-(b/a)*y[0];
	        x[1]=y[0];
	        
	        return gcd;
	    }
	    
	    public static int abs(int a,int b){
		return (int)Math.abs(a-b);
	    }
	 
	    public static long abs(long a,long b){
		return (long)Math.abs(a-b);
	    }
	    
	    public static int max(int a,int b){
		if(a>b)
			return a;
		else
			return b;
	    }
	 
	    public static int min(int a,int b){
		if(a>b)
			return b;
		else 
			return a;
	    }
	    
	    public static long max(long a,long b){
		if(a>b)
			return a;
		else
			return b;
	    }
	 
	    public static long min(long a,long b){
		if(a>b)
			return b;
		else 
			return a;
	    }
	 
	    public static long pow(long n,long p,long m){
		 long  result = 1;
		  if(p==0)
		    return 1;
		if (p==1)
		    return n;
		while(p!=0)
		{
		    if(p%2==1)
		        result *= n;
		    if(result>=m)
		    result%=m;
		    p >>=1;
		    n*=n;
		    if(n>=m)
		    n%=m;
		}
		return result;
	    }
	    
	    public static long pow(long n,long p){
		long  result = 1;
		  if(p==0)
		    return 1;
		if (p==1)
		    return n;
		while(p!=0)
		{
		    if(p%2==1)
		        result *= n;	    
		    p >>=1;
		    n*=n;	    
		}
		return result;
	    }
	    public static void debug(Object... o) {
			System.out.println(Arrays.deepToString(o));
		}
	    void run() throws Exception {
			is = System.in;
			out = new PrintWriter(System.out);
			solve();
			out.flush();
		}
	   
	    public static void main(String[] args) throws Exception {
			new Thread(null, new Runnable() {
				public void run() {
					try {
						new code5().run();
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
			}, "1", 1 << 26).start();
			
	    	//new code5().run();
		}
	    private byte[] inbuf = new byte[1024];
		public int lenbuf = 0, ptrbuf = 0;
	 
		private int readByte() {
			if (lenbuf == -1)
				throw new InputMismatchException();
			if (ptrbuf >= lenbuf) {
				ptrbuf = 0;
				try {
					lenbuf = is.read(inbuf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return -1;
			}
			return inbuf[ptrbuf++];
		}
	 
		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}
	 
		private int skip() {
			int b;
			while ((b = readByte()) != -1 && isSpaceChar(b));
			return b;
		}
	 
		private double nd() {
			return Double.parseDouble(ns());
		}
	 
		private char nc() {
			return (char) skip();
		}
	 
		private String ns() {
			int b = skip();
			StringBuilder sb = new StringBuilder();
			while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
	 
		private char[] ns(int n) {
			char[] buf = new char[n];
			int b = skip(), p = 0;
			while (p < n && !(isSpaceChar(b))) {
				buf[p++] = (char) b;
				b = readByte();
			}
			return n == p ? buf : Arrays.copyOf(buf, p);
		}
	 
		private char[][] nm(int n, int m) {
			char[][] map = new char[n][];
			for (int i = 0; i < n; i++)
				map[i] = ns(m);
			return map;
		}
	 
		private int[] na(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = ni();
			return a;
		}
		private long[] nl(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nl();
			return a;
		}
	 
		private int ni() {
			int num = 0, b;
			boolean minus = false;
			while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
				;
			if (b == '-') {
				minus = true;
				b = readByte();
			}
	 
			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = readByte();
			}
		}
	 
		private long nl() {
			long num = 0;
			int b;
			boolean minus = false;
			while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
				;
			if (b == '-') {
				minus = true;
				b = readByte();
			}
	 
			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = readByte();
			}
		}
	 
}

Java 8:
import java.io.*;
import java.math.*;
import java.security.Key;
import java.security.KeyStore.Entry;
import java.util.*;


			
class Code
 
{
	
	private InputStream is;
	private  PrintWriter out;
	
	
	
	void solve() throws IOException
	{
	 int t=ni();
	  
	  while(t-->0)
	  {
		  int n=ni();
		  
		  int q=ni();
		  
		  char c=nc();
		  
		  char c1=c;
		  
		  int a[]=new int[n+1];
		  
		  a[1]=0;
		  
		  char rl=c;
								  
		  for(int i=2;i<=n;i++)
		  {
			  
			   rl=nc();
			  
			  if(rl!=c)
			  {
				  a[i]++;
				  c=rl;
			  }
			  a[i]+=a[i-1];
					  
					  
			  
		  }
		  
		//for(int i=1;i<=n;i++)
		// out.print(a[i]+" ");
		  
		 // out.println();
		  //
		  
		  int f=0;
		  
		  if(c1!=rl)
		   f=1;
	
		
		  while(q-->0)
		  {
			  int l=ni();
			  
			  int r=ni();

				 if(l>r)
				 {
				   int t1=l;
				   l=r;
				   r=t1;
				  }
			
				  int a1=a[r]-a[l];
				  
				  int a2=a[l];
				  
				  a2+=f;
				  
				  a2+=(a[n]-a[r]);
				  
			
				  out.println(Math.min(a1, a2));
			  
		   }
		  
		  
		  
	  }
	
		
	}
	
		
  
	void run() throws Exception {
			is = System.in;
			out = new PrintWriter(System.out);
			solve();
			out.flush();
		
	}
	 
	public static void main(String[] args) throws Exception {
			new Thread(null, new Runnable() {
				public void run() {
					try {
						new Code().run();
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
			}, "1", 1 << 26).start();
}

// To Get Input
// Some Buffer Methods
private byte[] inbuf = new byte[1024];
public int lenbuf = 0, ptrbuf = 0;

private int readByte() {
if (lenbuf == -1)
	throw new InputMismatchException();
if (ptrbuf >= lenbuf) {
	ptrbuf = 0;
	try {
		lenbuf = is.read(inbuf);
	} catch (IOException e) {
		throw new InputMismatchException();
	}
	if (lenbuf <= 0)
		return -1;
}
return inbuf[ptrbuf++];
}

private boolean isSpaceChar(int c) {
return !(c >= 33 && c <= 126);
}

private int skip() {
int b;
while ((b = readByte()) != -1 && isSpaceChar(b))
	;
return b;
}

private double nd() {
return Double.parseDouble(ns());
}

private char nc() {
return (char) skip();
}

private String ns() {
int b = skip();
StringBuilder sb = new StringBuilder();
while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != '
							// ')
	sb.appendCodePoint(b);
	b = readByte();
}
return sb.toString();
}

private char[] ns(int n) {
char[] buf = new char[n];
int b = skip(), p = 0;
while (p < n && !(isSpaceChar(b))) {
	buf[p++] = (char) b;
	b = readByte();
}
return n == p ? buf : Arrays.copyOf(buf, p);
}



private int[] na(int n) {
int[] a = new int[n];

for (int i = 0; i < n; i++)
	{
	  a[i] = ni();
	  
	  
	}


return a;
}

private void pa(int[] a) {
int i=0;

while(i<a.length)
{
   System.out.print(a[i++]+" ");
}




}


private int ni() {
int num = 0, b;
boolean minus = false;
while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
	;
if (b == '-') {
	minus = true;
	b = readByte();
}

while (true) {
	if (b >= '0' && b <= '9') {
		num = num * 10 + (b - '0');
	} else {
		return minus ? -num : num;
	}
	b = readByte();
}
}

private long nl() {
long num = 0;
int b;
boolean minus = false;
while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
	;
if (b == '-') {
	minus = true;
	b = readByte();
}

while (true) {
	if (b >= '0' && b <= '9') {
		num = num * 10 + (b - '0');
		} else {
			return minus ? -num : num;
		}
		b = readByte();
	}
}


} 

		
JavaScript(Node.js)
// Sample code to perform I/O:
 
process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
 
process.stdin.on("data", function (input) {
    stdin_input += input;                               // Reading input from STDIN
});
 
process.stdin.on("end", function () {
  main(stdin_input.split('\n'));
});
let inp = [], i = 0;
function readLine(){
    // let ss = inp[i];
    // i++;
    return inp[i++];
}
function operate(num, clock, limit){
    num = num + clock;
    if(num == -1){
        num = limit - 1;
    }
    else if(num == limit){
        num = 0;
    }
    return num;
}
 
function check(arr, clock, st, fin){
    let count = 0;
    // console.log(`fin is ${fin}`);
    while(st != fin){
        // console.log(`st is ${st}`);
        if(arr[st] != arr[operate(st, clock, arr.length)]){
            count++;
        }
        st = operate(st, clock, arr.length);
    }
    return count;
}
 
function main(input) {
    // console.log(input);
    inp = input;
    let num = parseInt(readLine());
    // console.log(num);
    for(t = 0; t < num; t++){
        let str = readLine().split(' ');
        let n = parseInt(str[0]), q = parseInt(str[1]);
        // console.log(`n = ${n} and q = ${q}`)
        let arr = readLine().split('');
        // console.log(arr);
        for(let i = 0; i < q; i++){
            let str2 = readLine().split(' ');
            // console.log(str2);
            let start = parseInt(str2[0]) - 1, finish = parseInt(str2[1]) - 1;
            let f = check(arr, 1, start, finish), b = check(arr, -1, start, finish);
            console.log(Math.min(f, b));
        }
    }
    // process.stdout.write("Hi, " + input + ".\n");       // Writing output to STDOUT
}
 
Python:
for _ in range(int(raw_input())):
    n,q = [int(i) for i in raw_input().split()]
    s = raw_input()
    p = []
    k = 0
    for i in range(len(s)):
        if s[i] != s[i-1]:
            k += 1
        p.append(k)
    # print p
    for _ in range(q):
        l = [int(i) for i in raw_input().split()]
        l.sort()
        # print p[l[1]]
        # print p[l[0]]
        # print p[n-1]
        # print p[l[0]-1]
        # print p[l[1]-1]-p[l[0]-1]
        # print p[n-1]-p[l[1]-1]+p[l[0]-1]
        print min(p[l[1]-1]-p[l[0]-1],p[n-1]-p[l[1]-1]+p[l[0]-1])
        # c = 0
        # for i in range(l[0],l[1]):
        #     if s[i] != s[i-1]:
        #         c += 1
        # c1 = 0
        # k = l[0]+(n-l[1])
        # m =1
        # while k>0:
        #     if s[l[0]-m] != s[l[0]-(m+1)]:
        #         c1 += 1
        #     k -= 1
        #     m += 1
        
        # # print c,c1 
        # print min(c,c1)
 
Python 3:
import sys,math
t = int(sys.stdin.readline())
 
for _ in range(t):	
	n,q=list(map(int,sys.stdin.readline().strip().split()))
	arr=[]
	while(len(arr)<n):
		arr+=list(sys.stdin.readline().strip())
	a=[0 for i in range(3*n)]
	for i in range(1,3*n):		
		a[i]= a[i-1]+(arr[i%n]!=arr[(i-1)%n])
 
	for _ in range(q):
		x1,x2=list(map(int,sys.stdin.readline().strip().split()))
		x1-=1
		x2-=1
		if x1>x2:
			[x1,x2]=[x2,x1]
 
		v1=a[x2+n]-a[x1+n]
		x1+=n
		v2=a[x1+n]-a[x2+n]
		print(min(v1,v2))


*/

/*Editorial:
The problem statement says that you need to travel from the xth house to the yth house and distribute minimum number of sweets.
You can travel clockwise or anticlockwise.
When to distribute a sweet? 
When you are in a red house and you move to a green house or vice-versa.
So you just need to process every query in O(n) by taking the minimum of the number of sweets you would require in clockwise movement and anti-clockwise movement.
While calculating the number of sweets required in either movement just store the current color of your house and check if the next color is same as current.
If yes then do nothing else change the current color to the color of the next house and increment your answer by 1.

Complexity: O(TNQ).

Author Solution by Aashray Agarwal
#include<bits/stdc++.h>
using namespace std;
#define ll int
int main()
{
    freopen("samp.txt","r",stdin);
    freopen("sout.txt","w",stdout);
    ll t,n,q,x,y,i,j,cur,ans,val,val1;
    string s;
    cin>>t;
    assert(t>=1&&t<=100);
    while(t--)
    {
        cin>>n>>q;
        assert(n>=1&&n<=1000);
        assert(q>=1&&q<=1000);
        cin>>s;
        s=s+s;
        s=" "+s;
        while(q--)
        {
            val=val1=0;
            cin>>x>>y;
            if(x>y)
            swap(x,y);
            cur=s[x];
            for(i=x;i<=y;i++)
            {
                if(s[i]!=cur)
                {
                    cur=s[i];
                    val++;
                }
            }
            x+=n;
            cur=s[y];
            for(i=y;i<=x;i++)
            {
                if(s[i]!=cur)
                {
                    cur=s[i];
                    val1++;
                }
            }
            ans=min(val,val1);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
Tester Solution by Shubham
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	assert(t>=1 && t<=1e2);
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		assert(n>=1 && n<=1e3);
		assert(q>=1 && q<=1e3);
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++)assert(s[i]=='G' || s[i]=='R');
		assert(s.size()==n);
		while(q--)
		{
			int x,y,a1=0,a2=0,ans;
			cin>>x>>y;x--;y--;
			if(x>y){swap(x,y);}
			for(int i=x+1;i<=y;i++)
				a1+=(s[i]!=s[i-1]);
			for(int i=y+1;i<=n-1;i++)
				a2+=(s[i]!=s[i-1]);
			a2+=(s[0]!=s[n-1]);
			for(int i=1;i<=x;i++)
				a2+=(s[i]!=s[i-1]);
			//cout<<a1<<" "<<a2<<"\n";
			cout<<min(a1,a2)<<"\n";
		}
	}
	return 0;
}

*/
