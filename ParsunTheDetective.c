/* All Tracks -->  Data Structures -->  Arrays -->  1-D -->  Problem --> Prasun the detective
Attempted by: 1114/Accuracy: 91%/Maximum Score: 30/
Tag(s): Medium
Prasun, a wanna be detective, has been assigned a case after his continuous failure at solving any. This is the murder 
of Snehashis who was killed last night. Prasun has already made some guesses on who could be the murderer and it seems that 
the two murderers are communicating via some strange arrangement of words. As prasun has been involved at solving cases of 
such fashion, he is making some guesses on what the message could probably be. Though he is pretty smart (:P), you have to 
help him by checking whether his guess is actually a possible one from the messages received.

Constraints:
Length of both message is less than 50 character.

Line 1: Message Received.
Line 2: Prasun's Guess.

SAMPLE INPUT 
jogod #! siara.
raja is good!
SAMPLE OUTPUT 
YES

//My Python Solution:
import re
p = input().lower() 
q = input().lower()
p = re.sub(r'\s+','',p)  # or we can write --> p = p.replace(" ","")  i.e. Matches any whitespace character; this is equivalent to the set [\t\n\r\f\v].
q = re.sub(r'\s+','',q)  # or we can write --> q = q.replace(" ","") 
p = re.sub('[^a-z0-9]','',p)
q= re.sub('[^a-z0-9]','',q) 
if sorted(p)==sorted(q):
	print('YES') 
else:
    print('NO')

*/
	
/* Editorial:
replace all non-alphabetical characters with an empty string,
then compare the lengths of the strings
(enough for passing all the test cases)
*/

/*Best Submissions:
C:
#include <stdio.h>
#include<math.h>
void main()
{
    char a[100],b[100];
    gets(a);
    gets(b);
    int c=strlen(a);
    int d=strlen(b);
    int e=0;
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<d;j++)
        {
            if(b[j]==a[i])
            {
                e++;
                j=d;
            }
        }
    }
    if(e<=d)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}

C++:
#include<iostream>
using namespace std;
int main()
{
    char a[50],b[50];
    gets(a);
    gets(b);
    int i,j;
    for(i=0;b[i]!='\0';i++)
    {
        for(j=0;a[j]!='\0';j++)
        {
            if(b[i]==' ')
            break;;
            if(b[i]==a[j]||b[i]==a[j]+32||b[i]==a[j]-32)
            {
                b[i]='$';
                a[j]='$';
                break;
            }
        }
        if(a[j]=='\0')
        break;
    }
    if(b[i]!='\0')
    cout<<"NO";
    else
    cout<<"YES";
    return 0;
}


C++14:
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long i,j,n,t;
    string a;
    string b;
    int c[26]={0};
    getline (cin, a);
    getline (cin, b);
    // cout<<a<<"\n"<<b;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]>64 && a[i]<91)
        {
            a[i]=a[i]+32;
        }
        if(a[i]>96 && a[i]<123)
        {
            c[a[i]-'a']++;
        }
    }
    for(i=0;b[i]!='\0';i++)
    {
        if(b[i]>64 && b[i]<91)
        {
            b[i]=b[i]+32;
        }
        if(b[i]>96 && b[i]<123)
        {
            c[b[i]-'a']--;
        }
    }
    //cout<<a<<endl<<b;
    for(i=0;i<26;i++)
    {
        if(c[i]!=0)
        {
            cout<<"NO";
            return 0;
        }
        //cout<<c[i]<<" ";
    }
    cout<<"YES";
    return 0;
}


C#:
using System;
public class Program
{
    public static void Main(string[] a)
    {
        string code=Console.ReadLine();
        string guess=Console.ReadLine();
        int flag=1;
        int j=0;
        char c='a';
        code=code.Replace(" ",string.Empty).ToLower();
        guess=guess.Replace(" ",string.Empty).ToLower();
		for(int i=0;i<guess.Length;i++)
        {
             c=guess[i];
             j=code.IndexOf(c);
            
            if(j!=-1)
            {
              code=code.Remove(j,1);  
            }
            else
            {
                flag=-1;
            }
        }
        if(flag==-1)
         Console.WriteLine("NO");
        else
        {
            flag=0;
            code=code.ToLower();
            for(int i=0;i<code.Length;i++)
            {
                
                if(((int)code[i]>=97&&(int)code[i]<=122))
                {
                    flag=-1;
                    break;
                }
                
            }
            if(flag==0)
            {
               Console.WriteLine("YES"); 
            }
            else
            {
                Console.WriteLine("NO"); 
            }
        }
    }
}


Java:
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
public class PrasunTheDetective {
 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String msz = br.readLine();
		String guess = br.readLine();
 
		boolean[] mszval = new boolean[26];
		
		for (int i = 0; i < msz.length(); i++) {
			if (msz.charAt(i) >= 'a' && msz.charAt(i) <= 'z' && !mszval[msz.charAt(i) - 'a']) {
				mszval[msz.charAt(i) - 'a'] = true;
			}
		}
		
		System.out.println((isGuessCorrect(mszval, guess, guess.length(), msz.length())) ? "YES" : "NO");
 
	}
 
	private static boolean isGuessCorrect(boolean[] mszVal, String guess, int guessLen, int mszLen) {
		boolean res = true;
		
			for (int i = 0; i < guessLen; i++) {
				if (guess.charAt(i)>='a' && guess.charAt(i)<='z' && !mszVal[guess.charAt(i) - 'a']) {
					res = false;
					break;
				}
			}
 
		return res;
	}
}


Java 8:
import java.util.*;
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        //Sample code to perform I/O:
        //Use either of these methods for input
        //
        ////BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String name = br.readLine();                // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
        //
        ////Scanner
        //
        //String name = s.nextLine();                 // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
        //
        //
 
        // Write your code here
        Scanner s = new Scanner(System.in);
        String s1=s.nextLine();
        String s2=s.nextLine();
        char s1arr[]=s1.replaceAll(" ","").replaceAll("[^a-zA-Z]", "").toLowerCase().toCharArray();
        char s2arr[]=s2.replaceAll(" ","").replaceAll("[^a-zA-Z]", "").toLowerCase().toCharArray();
        Arrays.sort(s1arr);
        Arrays.sort(s2arr);
        if(s1arr.length!=s2arr.length)
            System.out.println("NO");
        else
        {
            int flag=0;
            for(int i=0;i<s1arr.length;i++)
            {
                if(s1arr[i]!=s2arr[i])
                {    
                    flag=1;
                    break;
                }
                
            }
            if(flag==0)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}

Java(Node.js):
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
    var data = input.split('\n');
    var str1 = data[0].replace(/\s/g,'').toLowerCase();
    var str2 = data[1].replace(/\s/g,'').toLowerCase();
    var res='';
    if(str2.length > str1.length) {
        process.stdout.write("NO");
        return;
    }
    var map = new Map();
    for(let i=0; i<str1.length; i++) {
        let count = map.has(str1.charAt(i)) ? (map.get(str1.charAt(i)) + 1) : 1;
        map.set(str1.charAt(i), count);
    }
    
    for(let j=0; j<str2.length; j++) {
        if(!map.has(str2.charAt(j))) {
            process.stdout.write("NO");
            return;
        } else {
            var count = map.get(str2.charAt(j)) - 1;
            if(count == 0) map.delete(str2.charAt(j));
            else map.set(str2.charAt(j), count);
        }
    }
 
    process.stdout.write("YES");
}

Python:
s1 = raw_input().lower()
s2 = raw_input().lower()
 
_ord_a = ord('a')
_ord_z = ord('z')
dict1 = {}
dict2 = {}
for i in xrange(_ord_a, _ord_z):
    dict1[i] = 0
    dict2[i] = 0
 
for s in s1:
    ss = ord(s)
    if ss >= _ord_a and ss <= _ord_z:
        dict1[ss] += 1
for s in s2:
    ss = ord(s)
    if ss >= _ord_a and ss <= _ord_z:
        dict2[ss] += 1
match = True
for i in xrange(_ord_a, _ord_z):
    match = (dict1[i] == dict2[i])
    if not match: break
print 'YES' if match else 'NO'


Python 3:
raw =list(input().lower())
mes =list(input().lower())
 
for i in range(len(mes)):
    if mes[i] in raw:
        raw.remove(mes[i])
    elif mes[i]==" ":
        pass
    else:
        print('NO')
        break
else:
    print("YES")


*/


/*I/O:
In #1:
scut, dellwellhoro@@.
hello world, let us c.
Out #1:
YES

In #2:
taergerasd mary ip.
pyramids are great.
Out #2:
YES

In #3:
kabhi kabhi lagta hai apun hi bhagwan hai.
my name is lakkhan.
Out #3:
NO

In #4:
cherry@@@ is love, pondi!!!!.
Pondicherry is love.
Out #4:
YES

In #5:
jogod #! siara.
raja is good!
Out #5:
YES


*/
