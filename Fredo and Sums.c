/*All Tracks -->Algorithms -->Sorting -->Merge Sort -->Problem
Fredo and Sums
Tag(s): Algorithms, Arrays, Easy-Medium, Greedy, Sorting
Fredo has an array A consisting of N elements. He wants to divide the array into N/2  pairs where each array element comes in exactly one pair. 
Say that pair i has elements  Xi and  Yi, he defines S as :
    N/2
	 __
S = \   abs(Xi – Yi)
	/__
    i=1
	
He asks you to find the minimum and maximum value of S.
Input Format:
First line consists of an integer T denoting the number of test cases.
Each test case:
First line consists of an integer N denoting the number of elements in the array.
Second line consists of N space separated integers denoting the array elements.
Output Format:
For each test case, print the minimum and maximum sum (space separated). Answer for each test case should come in a new line.

Input Constraints:
1<=T<=10
1<=N<=10^5
-10^9 <=A[i] <=10^9
N is even

SAMPLE INPUT 
1
4
10 20 -10 0
SAMPLE OUTPUT 
20 40

Explanation
For minimum sum, we take pairs (10,20)  and (-10,0) .
For maximum sum, we take pairs  (20,0)  and (10,-10) .

My c solution:
#include <stdio.h>
#include <stdlib.h>
#define N 100000

long cmpfunc(const void *a,const void *b){
    return (  *(long *)a - *(long *)b );
}

int main()
{
    int i,j,k,l,t,n;
    long A[N],min=0,max=0,minsum,maxsum;
    
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        minsum=maxsum=0;
        for(j=0;j<n;j++)
            scanf("%ld",&A[j]);
        qsort(A,n,sizeof(long),cmpfunc);
        for(k=0;k<n-1;k+=2)
            minsum+=abs(A[k+1]-A[k]);
        for(k=0;k<(n/2);k+=1)
            maxsum+=abs(A[n-k-1]-A[k]);
        max=maxsum;
        min=minsum;
        printf("%ld %ld\n",min,max);
    }
    return 0;
}
*/

/* Best Submissions:
C:
#include<stdio.h>
void quicksort(int arr[],int low,int high);
int partition(int arr[],int low,int high);
void swap(int *a,int *b);
void quicksort(int arr[],int low,int high)
{
if(low<high)
{
int piv=partition(arr,low,high);
quicksort(arr,low,piv-1);
quicksort(arr,piv+1,high);
}
}
int partition(int arr[],int low,int high)
{
int i=low-1;
int j;
for(j=low;j<=high-1;j++)
{
if(arr[j]<arr[high])
{
i++;
swap(&arr[j],&arr[i]);
}
}
swap(&arr[i+1],&arr[high]);
return i+1;
}
void swap(int *a,int *b)
{
int t=*a;
*a=*b;
*b=t;
}
int main()
{
int t,i,n,j,q,temp,a[100000];
scanf("%d",&t);
for(i=0;i<=t-1;i++)
{
scanf("%d",&n);
for(j=0;j<=n-1;j++)
{
scanf("%d",&a[j]);
}
quicksort(a,0,n-1);
long long int sum1=0,sum2=0;
for(j=0;j<=n-1;j=j+2)
{
sum1=sum1+(a[j]-a[j+1]);
}
for(j=0;j<=(n/2)-1;j++)
{
sum2=sum2+(a[j]-a[n-j-1]);
}
printf("%lld %lld\n",-sum1,-sum2);
}
return 0;
}

C++:
#include<bits/stdc++.h>
#define ll long long
#define sll(x) int x = scanLong();
#define fori0(i,n) for(int i=0;i<n;i++)
using namespace std;
inline int scanInt() { int n = 0; char ch = getchar_unlocked();	int sign = 1;
	while(ch < '0' || ch > '9') {if(ch == '-')	sign = -1;ch = getchar_unlocked();}
	while(ch >= '0' && ch <= '9') {n = (n<<1)+(n<<3)+(int)(ch-'0');	ch = getchar_unlocked();}
	return n*sign;
}
 
inline ll scanLong() {ll n = 0;	char ch = getchar_unlocked();ll sign = 1;
	while(ch < '0' || ch > '9') {if(ch == '-')	sign = -1;ch = getchar_unlocked();}
	while(ch >= '0' && ch <= '9') {n = (n<<1)+(n<<3)+(ll)(ch-'0');ch = getchar_unlocked();}
	return n*sign;
}
int main()
{
//fast I/O
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
#endif
sll(t);
while(t--)
{
   sll(n);
    ll a[n];
    fori0(i,n) a[i]=scanLong();
    sort(a,a+n);
    ll mi=0,ma=0;
    for(int i=0;i<n/2;i++)
        ma+=a[n-i-1]-a[i];
    for(int i=0;i<n;i+=2)
        mi+=a[i+1]-a[i];
    cout<<mi<<" "<<ma<<endl;
}
    return 0;
}

C++14:
#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ull unsigned long long int
#define mod 1000000007  //1000000009
#define stop return 0;
using namespace std;
int sI(){
        register int c = getchar_unlocked();
        bool flag = true;
        if(c=='-'){
            flag =false;
            c = getchar_unlocked();
        }
        int n = 0;
        for( ; (c<48 || c>57); c = getchar_unlocked() );
        for( ; (c>47 && c<58); c = getchar_unlocked() ){
            n = (n<<1) + (n<<3) +c -48;
        }
        if(flag){
            return n;
        }
        else{
            return n*-1;
        }
}
int main()
{
    fast;
    ll t;
    t=sI();
    while(t--){
        ll n,i,j,mx,mn,k;
        n=sI();
        ll arr[n];
        for(i=0;i<n;++i)
            arr[i]=sI();
        sort(arr,arr+n);
        j=mn=mx=0;
        for(i=0;i<n;i+=2){
            mx+=abs(arr[j]-arr[n-1-j]);
            mn+=abs(arr[i]-arr[i+1]);
            ++j;
        }
        cout<<mn<<" "<<mx<<endl;
    }
    stop;
}

C#:
#pragma warning disable IDE0018
#define TESTCASES
//Tools and default solution template belongs to https://www.hackerearth.com/@christophe_savard
//Solution to the problem belongs to me
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
 
namespace CpForCompetitiveProgrammingHRFrudoAndSum
{
    public static class HRFrudoAndSum
    {
        #region Main
 
        private const long Mod = 1000000007L;
        private const long MaxArrySize = 100000000L;
        private static ConsoleHelper Console { get; set; }
 
        static HRFrudoAndSum()
        {
            Console = new ConsoleHelper();
        }
 
        //public static void Main_Solver(string[] args)
        public static void Main(string[] args)
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
            System.Console.SetOut(File.AppendText(@"../../output.txt"));
            System.Console.Write($"\r\n\r\nTotal run time: {timer.Elapsed.TotalSeconds:0.000}s at {DateTime.Now}");
            System.Console.Out.Dispose();
#endif
        }
 
 
 
        #endregion
 
        #region Solution
 
#if TESTCASES
 
        private static void TestCases()
        {
            int tc = Console.NextInt(true);
 
            for (int i = 0; i < tc; i++)
            {
                var n = Console.NextInt(true);
                var array = Console.NextInts(n);
                Solve(array.OrderBy(e => e).ToArray());
            }
        }
 
#endif
        public static void Solve(int[] orderedArray)
        {
            long minSum = 0, maxSum = 0;
           
            int j = orderedArray.Length - 1;
            int k = orderedArray.Length - 1;
 
            for (int i = 0; i < orderedArray.Length / 2; i++)
            {
                long x = orderedArray[j];
                long y = orderedArray[i];
                var d = Math.Abs(x - y);
                maxSum += d;
 
                long dm = Math.Abs(orderedArray[k] - orderedArray[k - 1]);
                minSum += dm;
 
                --j;
                k -= 2;
            }
 
            Console.WriteLine(minSum + " " + maxSum);
        }
 
        #endregion
    }
 
 
    //Tools belongs to https://www.hackerearth.com/@christophe_savard
    #region Tools
    [DebuggerStepThrough]
    public sealed class ConsoleHelper : IDisposable
    {
        #region Constants
        private const int BaseSize = 1048576;
        private static readonly char[] NumBuffer = new char[20];
        #endregion
 
        #region Fields
        private readonly BufferedStream _inStream;
        private readonly StreamWriter _outStream;
 
        private readonly byte[] _inBuffer;
        private int _inputIndex;
        private int _bufferEnd;
        #endregion
 
        #region Properties
        public int BufferSize { get; set; }
 
        public bool Open { get; private set; }
        #endregion
 
        #region Constructors
 
        public ConsoleHelper() : this(BaseSize) { }
 
 
        public ConsoleHelper(int bufferSize)
        {
            // Open the input/output streams
#if DEBUG
            // Test mode
            this._inStream = new BufferedStream(File.OpenRead(@"../../input.txt"), bufferSize);
            this._outStream = new StreamWriter(File.Create(@"../../output.txt", bufferSize), Encoding.ASCII, bufferSize);
#else // !DEBUG
            // Submission mode
            this._inStream = new BufferedStream(Console.OpenStandardInput(bufferSize), bufferSize); // Submission stream
            this._outStream = new StreamWriter(Console.OpenStandardOutput(bufferSize), Encoding.ASCII, bufferSize);
#endif
 
            // Set fields
            this._inBuffer = new byte[bufferSize];
            this._inputIndex = this._bufferEnd = 0;
            this.BufferSize = bufferSize;
            this.Open = true;
        }
        #endregion
 
        #region Static methods
 
        public static bool ValidateChar(int i)
        {
            return i >= ' ';
        }
 
 
        public static bool ValidateCharNoSpace(int i)
        {
            return i > ' ';
        }
 
 
        public static bool ValidateNumber(int i)
        {
            return i >= '0' && i <= '9';
        }
 
 
        public static bool IsEndline(int i)
        {
            return i == '\n' || i == '\0';
        }
 
 
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
                NumBuffer[--head] = (char)((n % 10) + 48);
                n /= 10;
            }
            while (n > 0);
 
            if (neg) { NumBuffer[--head] = '-'; }
            return head;
        }
 
 
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
                NumBuffer[--head] = (char)((n % 10L) + 48L);
                n /= 10L;
            }
            while (n > 0L);
 
            if (neg) { NumBuffer[--head] = '-'; }
            return head;
        }
        #endregion
 
        #region Methods
 
        public byte Read()
        {
            CheckBuffer();
            return this._inBuffer[this._inputIndex++];
        }
 
 
        public byte Peek()
        {
            CheckBuffer();
            return this._inBuffer[this._inputIndex];
        }
 
 
        public void Skip(int n = 1)
        {
            this._inputIndex += n;
        }
 
 
        private void CheckBuffer()
        {
            // If we reach the end of the buffer, load more data
            if (this._inputIndex >= this._bufferEnd)
            {
                this._inputIndex = this._inputIndex - this._bufferEnd;
                this._bufferEnd = this._inStream.Read(this._inBuffer, 0, this.BufferSize);
 
                // If nothing was added, add a null char at the start
                if (this._bufferEnd < 1) { this._inBuffer[this._bufferEnd++] = 0; }
            }
        }
 
 
        public char NextChar()
        {
            return (char)Read();
        }
 
 
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
 
 
        public int NextInt(bool moveToNextLine = false)
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
 
            if (moveToNextLine)
            {
                SkipToNextLine();
            }
 
            return neg ? -n : n;
        }
 
 
        public long NextLong(bool moveToNextLine = false)
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
 
            if (moveToNextLine)
            {
                SkipToNextLine();
            }
 
            return neg ? -n : n;
        }
 
 
        public double NextDouble()
        {
            return double.Parse(Next());
        }
 
 
        public int[] NextInts(int n)
        {
            int[] array = new int[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = NextInt();
            }
 
            SkipToNextLine();
            return array;
        }
 
 
        public long[] NextLongs(int n)
        {
            long[] array = new long[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = NextLong();
            }
 
            SkipToNextLine();
            return array;
        }
 
 
        public int[,] NextMatrix(int n, int m)
        {
            int[,] matrix = new int[n, m];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[i, j] = NextInt();
                }
 
                SkipToNextLine();
            }
 
            return matrix;
        }
 
 
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
 
 
        public void SkipNext()
        {
            byte b = SkipInvalid();
            ValidateEndline(b);
 
            for (b = Peek(); ValidateCharNoSpace(b); b = Peek())
            {
                Skip();
            }
        }
 
 
        public void SkipToNextLine()
        {
            for (byte b = Read(); !IsEndline(b); b = Read()) { }
        }
 
 
        public IEnumerable<int> EnumerateInts(int n)
        {
            while (n-- > 0)
            {
                yield return NextInt();
            }
 
            SkipToNextLine();
        }
 
 
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
 
 
        private void ValidateEndline(byte b)
        {
            // If empty char
            if (b == 0)
            {
                // Go back a char and throw
                this._inputIndex--;
                throw new InvalidOperationException("No values left on line");
            }
        }
 
 
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
 
 
        public void Write(char c)
        {
            this._outStream.Write(c);
        }
 
 
        public void Write(char[] buffer)
        {
            this._outStream.Write(buffer);
        }
 
 
        public void Write(string s)
        {
            this._outStream.Write(s);
        }
 
 
        public void Write(int n)
        {
            int head = GetIntBuffer(n);
            this._outStream.Write(NumBuffer, head, 20 - head);
        }
 
 
        public void Write(long n)
        {
            int head = GetLongBuffer(n);
            this._outStream.Write(NumBuffer, head, 20 - head);
        }
 
 
        public void Write(StringBuilder sb)
        {
            this._outStream.Write(sb.ToCharArray());
        }
 
 
        public void Write(object o)
        {
            this._outStream.Write(o);
        }
 
 
        public void Write<T>(IEnumerable<T> e, string separator = "")
        {
            this._outStream.Write(new StringBuilder().AppendJoin(e, separator).ToCharArray());
        }
 
 
        public void Write<T>(IEnumerable<T> e, char separator)
        {
            this._outStream.Write(new StringBuilder().AppendJoin(e, separator).ToCharArray());
        }
 
 
        public void WriteLine()
        {
            this._outStream.WriteLine();
        }
 
 
        public void WriteLine(char c)
        {
            this._outStream.WriteLine(c);
        }
 
 
        public void WriteLine(char[] buffer)
        {
            this._outStream.WriteLine(buffer);
        }
 
 
        public void WriteLine(string s)
        {
            this._outStream.WriteLine(s);
        }
 
        public void WriteLine(int n)
        {
            int head = GetIntBuffer(n);
            this._outStream.WriteLine(NumBuffer, head, 20 - head);
        }
 
 
        public void WriteLine(long n)
        {
            int head = GetLongBuffer(n);
            this._outStream.WriteLine(NumBuffer, head, 20 - head);
        }
 
 
        public void WriteLine(StringBuilder sb)
        {
            this._outStream.WriteLine(sb.ToCharArray());
        }
 
 
        public void WriteLine<T>(IEnumerable<T> e, string separator = "")
        {
            this._outStream.WriteLine(new StringBuilder().AppendJoin(e, separator).ToCharArray());
        }
 
 
        public void WriteLine<T>(IEnumerable<T> e, char separator)
        {
            this._outStream.WriteLine(new StringBuilder().AppendJoin(e, separator).ToCharArray());
        }
 
 
        public void WriteLine(object o)
        {
            this._outStream.WriteLine(o);
        }
 
 
        public void Flush()
        {
            this._outStream.Flush();
        }
 
 
        public void Dispose()
        {
            if (this.Open)
            {
                Flush();
                this._inStream.Dispose();
                this._outStream.Dispose();
                this.Open = false;
            }
        }
        #endregion
    }
 
    public static class Extensions
    {
        #region Enumerable extensions
 
        public static bool EqualTo<T>(this IEnumerable<T> e, int count)
        {
            if (count < 0) { return false; }
 
            int total = 0;
            return !e.Any(t => ++total > count) && total == count;
        }
 
        public static void ForEach<T>(this IEnumerable<T> e, Action<T> action)
        {
            foreach (T t in e)
            {
                action(t);
            }
        }
 
        public static bool IsEmpty(this ICollection c)
        {
            return c.Count == 0;
        }
 
        public static bool GreaterThan<T>(this IEnumerable<T> e, int count)
        {
            if (count < 0) { return true; }
 
            int total = 0;
            return e.Any(t => ++total > count);
        }
 
        public static string Join<T>(this IEnumerable<T> e, string separator = "")
        {
            return new StringBuilder().AppendJoin(e, separator).ToString();
        }
 
        public static string Join<T>(this IEnumerable<T> e, char separator)
        {
            return new StringBuilder().AppendJoin(e, separator).ToString();
        }
 
        public static bool LessThan<T>(this IEnumerable<T> e, int count)
        {
            if (count <= 0) { return false; }
 
            int total = 0;
            return !e.Any(t => ++total >= count);
        }
 
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
 
        public static List<List<T>> DeepClone<T>(this IEnumerable<IEnumerable<T>> e)
        {
            var newList = new List<List<T>>();
 
            foreach (var item in e)
            {
                List<T> newItem = new List<T>();
 
                foreach (var inner in item)
                {
                    newItem.Add(inner);
                }
 
                newList.Add(newItem);
            }
 
            return newList;
        }
 
        public static int StringDiff(this string s, string other)
        {
            int diff = 0;
 
            for (int i = 0; i < s.Length; i++)
            {
                if (i == other.Length)
                {
                    break;
                }
 
                if (s[i] != other[i])
                {
                    ++diff;
                }
            }
 
            return diff;
        }
 
        public static bool ForAllPermutation<T>(this IEnumerable<T> collection, Func<T[], bool> funcExecuteAndTellIfShouldStop)
        {
            var items = collection.ToArray();
            int countOfItem = items.Length;
 
            if (countOfItem <= 1)
            {
                return funcExecuteAndTellIfShouldStop(items);
            }
 
            var indexes = new int[countOfItem];
            for (int i = 0; i < countOfItem; i++)
            {
                indexes[i] = 0;
            }
 
            if (funcExecuteAndTellIfShouldStop(items))
            {
                return true;
            }
 
            for (int i = 1; i < countOfItem;)
            {
                if (indexes[i] < i)
                {
                    if ((i & 1) == 1)
                    {
                        Swap(ref items[i], ref items[indexes[i]]);
                    }
                    else
                    {
                        Swap(ref items[i], ref items[0]);
                    }
 
                    if (funcExecuteAndTellIfShouldStop(items))
                    {
                        return true;
                    }
 
                    indexes[i]++;
                    i = 1;
                }
                else
                {
                    indexes[i++] = 0;
                }
            }
 
            return false;
        }
 
        static void Swap<T>(ref T a, ref T b)
        {
            T temp = a;
            a = b;
            b = temp;
        }
 
        #endregion
 
        #region String extensions
 
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
 
 
        public static bool IsEmpty(this string s)
        {
            return String.IsNullOrEmpty(s);
        }
 
 
        public static string SubStr(this string s, int start, int end)
        {
            return s.Substring(start, (end - start) + 1);
        }
 
 
        public static char[] ToCharArray(this StringBuilder sb)
        {
            char[] buffer = new char[sb.Length];
            sb.CopyTo(0, buffer, 0, sb.Length);
            return buffer;
        }
        #endregion
 
        #region Number extensions
 
        public static bool IsPair(this int n)
        {
            return (n & 1) == 0;
        }
 
 
        public static bool IsPair(this long n)
        {
            return (n & 1L) == 0;
        }
 
 
        public static int Mod(this int n, int m)
        {
            return ((n % m) + m) % m;
        }
 
 
        public static long Mod(this long n, long m)
        {
            return ((n % m) + m) % m;
        }
 
 
        public static int Triangle(this int n)
        {
            return (n * (n + 1)) / 2;
        }
 
 
        public static long Triangle(this long n)
        {
            return (n * (n + 1L)) / 2L;
        }
 
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
 
        private static void Swap(long[] arr, int i, int j)
        {
            var t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
 
        private static int Partition(long[] arr, int l, int h, bool asc)
        {
            var x = arr[h];
            int i = (l - 1);
 
            for (int j = l; j <= h - 1; j++)
            {
                if (arr[j] <= x)
                {
                    i++;
 
                    if (asc)
                    {
                        Swap(arr, i, j);
                    }
                    else
                    {
                        Swap(arr, j, i);
                    }
 
                }
            }
 
            if (asc)
            {
                Swap(arr, i + 1, h);
            }
            else
            {
                Swap(arr, h, i + 1);
            }
 
            return (i + 1);
        }
 
        public static void QuickSort(this long[] arr, bool asc)
        {
            int l = 0;
            int h = arr.Length - 1;
 
            // create auxiliary stack
            int[] stack = new int[h - l + 1];
 
            // initialize top of stack
            int top = -1;
 
            // push initial values in the stack
            stack[++top] = l;
            stack[++top] = h;
 
            // keep popping elements until stack is not empty
            while (top >= 0)
            {
                // pop h and l
                h = stack[top--];
                l = stack[top--];
 
                // set pivot element at it's proper position
                int p = Partition(arr, l, h, asc);
 
                // If there are elements on left side of pivot,
                // then push left side to stack
                if (p - 1 > l)
                {
                    stack[++top] = l;
                    stack[++top] = p - 1;
                }
 
                // If there are elements on right side of pivot,
                // then push right side to stack
                if (p + 1 < h)
                {
                    stack[++top] = p + 1;
                    stack[++top] = h;
                }
            }
        }
 
        public static int BinarySearch(long[] a, long key)
        {
            int low = 0, high = a.Length - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (a[mid] == key)
                {
                    high = mid;
                    break;
                }
                else if (a[mid] < key)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
 
            if (high == a.Length - 1)
                return high;
            while ((high + 1 < a.Length) && a[high + 1] == key)
                high++;
            return high;
 
        }
    }
 
    #endregion
 
 
}

Java:
import java.util.*;
import java.io.*;
class TestClass {
    
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
    
    public static void main(String args[] ) throws Exception {

        //Read input from stdin and provide input before running
        //Use either of these methods for input
 
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String line = br.readLine();
        //int N = Integer.parseInt(line);
 
        //Scanner
        Reader s = new Reader();
        int N = s.nextInt();
 
        for (int i = 0; i < N; i++) {
            int n = s.nextInt();
            int a[] = new int[n];
            for(int j=0; j<n; j++){
                a[j] = s.nextInt();
            }
            Arrays.sort(a);
            long min = 0;
            long max = 0;
            for(int j=0; j<n-1; j+=2){
                min += Math.abs(a[j+1]-a[j]);
            }
            for(int j=0; j<n/2; j++){
                max += Math.abs(a[j]-a[n-j-1]);
            }
            System.out.println(min+" "+max);
            //System.out.println(max);
        }
    }
}


Java8:
// IMPORTANT: Multiple classes and nested static classes are supported
//uncomment this if you want to read input.
//imports for BufferedReader
//import java.io.BufferedReader;
//import java.io.InputStreamReader;
 
//import for Scanner and other utility classes
//import java.util.*;

 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
import java.io.*;
import java.util.*;
import java.lang.*;
class TestClass {
    static long count=0;
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
    public static void main(String args[] ) throws Exception {
        //Sample code to perform I/O:
        //Use either of these methods for input
 
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String name = br.readLine();                // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        //Scanner
        //Scanner s = new Scanner(System.in);
        //String name = s.nextLine();                 // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        // Write your code here
        Reader in = new Reader();
        //Scanner in = new Scanner(System.in);
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        PrintWriter out = new PrintWriter(System.out, true);
        int t= in.nextInt();
        while(t-->0){
            int n = in.nextInt();
            long min_sum=0,max_sum=0;
            int[]a= new int[n];
            for(int i=0;i<n;i++){
                a[i]=in.nextInt();
            }
            Arrays.sort(a);
            for(int i=0;i<n;i=i+2){
                min_sum+= (long)(a[i+1]-a[i]);
            }
            for(int i=0;i<n/2;i++){
                max_sum+=(long)(a[n-1-i]-a[i]);
            }
            sb.append(min_sum+" "+max_sum+"\n");
        }
        out.println(sb);
        in.close();
 
    }
}

Python:
for _ in range(int(raw_input())):
    n = int(raw_input())
    a = sorted(map(int, raw_input().split()))
    print sum(a[1::2]) - sum(a[0::2]), sum(a[n/2:]) - sum(a[:n/2])


Python 3:
for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    a.sort()
    s = sum(a[1::2])-sum(a[::2])
    t = sum(a[n//2:]) - sum(a[:n//2])
    print(s,end=' ')
    print(t)


PHP:
<?php
 
//Read input from stdin and provide input before running code
//fscanf(STDIN, "%s\n", $name);
//echo "Hi, ".$name;
 
$_fp = fopen("php://stdin","r");
 
$T = trim(fgets($_fp));
 
// echo $T;
while($T--){
    // echo "here";
    $N = trim(fgets($_fp));
    $posCount = 0;
    $negCount = 0;
    $minSum = 0;
    $maxSum = 0;
    
    $arr = explode(" ", trim(fgets($_fp)));
    
    for ($j = 0; $j < $N; $j++) {
        if($arr[$j] < 0){
            $negCount++;
        }
        else{
            $posCount++;
        }
    }
            
            // mergeSort(arr, 0, N-1);
    sort($arr);
            
    $minPos = 0;
    if($posCount >= $negCount){
        $lastIndex = $N-1;
        
        for ($j = 0; $j < $negCount; $j++) {
            $maxSum += $arr[$lastIndex] + $arr[$j]*-1;
            $lastIndex--;
            $minSum += abs($arr[$minPos] - $arr[$minPos+1]);
            $minPos += 2;
            // System.out.print(maxSum+"-----");
        }
        
        $last = $lastIndex;
        
        for($j = $negCount; $j <= ($negCount+$lastIndex)/2; $j++){
            $maxSum += abs($arr[$j] - $arr[$last]);
            // System.out.print(maxSum+"-----");
            $last--;
            $minSum += abs($arr[$minPos] - $arr[$minPos+1]);
            $minPos += 2;
        }
    }else{
        $lastIndex = $N-1;
        for ($j = 0; $j < $posCount; $j++) {
            $maxSum += $arr[$lastIndex] + $arr[$j]*-1;
            $lastIndex--;
            $minSum += abs($arr[$minPos] - $arr[$minPos+1]);
            $minPos += 2;
        }
        
        $last = $lastIndex;
        
        for($j = $posCount; $j <= ($posCount+$lastIndex)/2; $j++){
            $maxSum += abs($arr[$j] - $arr[$last]);
            $last--;
            $minSum += abs($arr[$minPos] - $arr[$minPos+1]);
            $minPos += 2;
        }
    }
    
    echo $minSum." ".$maxSum."\n";
}
 
 
?>

Ruby:
def calc(arr, n)
    min = 0
    max = 0
    it = n/2
    it.times do |i|
        max += (arr[i] - arr[it + i]).abs
        min += (arr[2*i] - arr[2*i+1]).abs
    end
    return min.to_s + " " + max.to_s
end
t = gets.chomp.to_i
t.times do 
    n = gets.chomp.to_i
    arr = gets.chomp.split(" ").map(&:to_i)
    puts calc(arr.sort, n)
end

*/