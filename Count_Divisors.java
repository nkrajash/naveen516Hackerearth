/*Editorial:

There are multiple ways to solve this problem. The easiest one is to iterate over the entire range and check each number. 
This gives us a time complexity of O(N) where N is the size of the range. However, this problem can also be solved in O(1) time which might be helpful for larger constraints. 
The number of numbers divisible by a certain number k in the range from 1 to r is r/k.  Thus we can first find the number of numbers divisible by k in the range from 1 to r 
and then subtract from it the numbers divisible by k in the range from 1 to l-1 to obtain the answer.

Answer : (r/k) - ((l-1/k))

import java.io.*;
import java.util.*;
class example_2
{
    static Scanner sc=new Scanner(System.in);

    public static void main(String args[]) throws Exception
    {
        int l=sc.nextInt(),r=sc.nextInt(),k=sc.nextInt();
        System.out.println((r/k)-((l-1)/k));
    }
}
*/


/* I/O:
In #1:
200 300 2
Out #1:
51

In #2:
567 943 3
Out #2:
126

In #3:
347 1000 432
Out #3:
2

In #4:
1000 1000 999
Out #4:
0

*/