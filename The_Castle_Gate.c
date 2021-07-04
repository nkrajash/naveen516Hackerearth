/* All Tracks --> Basic Programming --> Bit Manipulation -->  Basics of Bit Manipulation --> The Castle Gate
Tag(s): Bit manipulation, Very-Easy
Gudi, a fun loving girl from the city of Dun, travels to Azkahar - a strange land beyond the mountains. She arrives at the gates of Castle Grey, 
owned by Puchi,the lord of Azkahar to claim the treasure that it guards. However, destiny has other plans for her as she has to move through floors, 
crossing obstacles on her way to reach the treasure.The gates of the castle are closed. An integer N is engraved on the gates. A writing on the wall says
Tap the gates as many times as there are unordered pairs of distinct integers from 1 to N whose bit-wise XOR does not exceed N.
Help her find the number of the times she has to tap.

Input:
First line contains an integer T, T testcases follow.
Each testcase consists of an integer N.

Output:
Print the answer to each testcase in a newline.

Constraints:
1<=T<=100
2<=N<=2000

SAMPLE INPUT:
3
4
6
8
SAMPLE OUTPUT:
3
12
21

Explanation:
For N=4, pairs are (1,2) , (1,3) and (2,3)

#include <stdio.h>

int main()
{
    int x,y,t=0,tc,n,cnt=0;
    
    scanf("%d",&tc);
    for(;t<tc;t++){
        scanf("%d",&n);
        for(x=1;x<n;x++){
            for(y=x+1;y<=n;y++){
                if((x^y)<=n)
                    cnt++;
            }
        }
        printf("%d\n",cnt);
        cnt=0;
    }

    return 0;
}

*/


/* Editorial:
This was meant to be the easiest problem in the round. The solution is to write a double loop and check which pairs satisfy the conditions stated. 
Some care is needed to make sure that we only count distinct unordered pairs. Look at the C++ code from the setter for a straightforward example on how to do this. 
It is also possible to solve this in python using only one line

Author Solution by Pulkit Mendiratta
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define elif else if
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
int main()
{
  // freopen("in.txt","r",stdin);
  // freopen("out","w",stdout);
  ios_base::sync_with_stdio(0);
  int t;
  cin>>t;
  assert(1<=t && t<=100);
  while(t--)
  {
    int n,i,j,ans=0;
    cin>>n;
    assert(2<=n && n<=2000);
    for(i=1 ; i<=n ; i++)
    {
      for( j=i+1; j<=n; j++ )
      {
        if( (i^j) <= n)
        {
          ans++;
        }
      }
    }
    cout<<ans;
    if(t>0)
      cout<<endl;
  }
 return 0;
}

Tester Solution by Lewin Gan
from itertools import product
print "\n".join([(lambda n: str(len([1 for i,j in product(range(n),repeat=2) if i<j and (i+1)^(j+1) <= n])))(int(raw_input())) for _ in xrange(int(raw_input()))])


*/

/* I/O:
In #1:
10
9
11
7
14
13
11
12
8
3
13
Out #1:
24
39
21
84
66
39
51
21
3
66

In #2:
100
81
223
42
27
5
161
376
250
206
238
393
397
365
204
467
6
366
450
462
150
86
337
146
92
327
248
330
245
107
37
298
363
403
455
88
461
445
65
338
17
40
70
485
484
401
180
410
46
463
214
332
259
244
406
207
352
431
171
45
241
222
283
22
331
488
129
103
382
69
454
264
253
404
295
276
457
325
50
23
29
102
450
308
152
147
78
213
230
275
251
324
292
498
333
168
257
122
450
296
257
Out #2:
2412
21681
630
303
6
9684
54165
30510
17244
26316
60744
62418
50370
16779
99483
12
50700
89130
96348
8760
2712
42348
8514
3171
40053
29781
40710
28710
4791
510
35094
49719
65019
92085
2853
95730
86250
1956
42594
108
573
2016
111390
110703
64140
12135
68190
780
96969
19224
41163
32403
28359
66360
17481
46353
78585
10839
738
27324
21396
33519
168
40935
113469
8004
4293
56388
1998
91488
32493
31626
65463
34725
33015
93288
39630
978
189
378
4176
89130
36519
8901
8571
2268
18966
23760
32955
30879
39423
34383
120594
41394
10461
32388
7086
89130
34845
32388

In #3:
100
138
947
922
667
959
472
397
393
625
564
127
141
149
540
83
44
879
343
376
326
449
792
239
275
364
41
687
900
13
418
325
968
136
891
858
512
901
933
544
731
381
728
166
825
915
189
872
266
252
832
471
884
59
419
547
83
368
258
9
445
174
672
328
853
992
419
722
712
38
537
274
336
219
926
715
281
330
389
228
475
156
638
242
451
20
299
275
569
523
432
596
161
547
10
516
295
90
303
822
782
Out #3:
8166
414795
383070
166575
430689
102693
62418
60744
149628
134439
8001
8274
8694
131523
2523
699
332889
43869
54165
39840
88548
248325
26649
32955
50043
600
176505
356703
66
71994
39630
442893
8109
346335
310398
130305
357870
396798
131889
202575
56010
200613
10224
277728
374523
13674
325245
32550
31251
284385
102045
338439
1599
72483
132195
2523
51369
32394
24
86250
11244
168945
40269
305238
476625
72483
196770
190605
528
131280
32898
42105
20559
388020
192423
33360
40710
59118
23151
104655
9219
154308
27666
89715
135
35223
32955
135264
130503
79113
141015
9684
132195
30
130335
34725
3006
35769
274920
240060

In #4:
100
756
835
622
670
756
814
841
700
618
740
777
998
642
688
772
815
724
734
893
734
968
660
968
1000
852
604
701
602
883
913
786
938
800
904
629
893
638
863
941
761
625
736
931
668
726
823
730
834
729
940
943
917
878
703
838
953
910
952
943
758
830
707
761
843
868
619
699
603
640
751
987
741
745
600
852
737
970
617
676
984
897
761
761
841
824
679
623
796
681
690
982
662
682
988
917
656
660
943
622
902
Out #4:
219975
287283
148620
167988
219975
267564
293160
183603
147318
208623
236040
485328
155850
177033
232095
268473
198039
204564
348618
204564
442893
163383
442893
488253
304215
143139
184170
142590
337323
372108
243330
403158
255153
361389
151014
348618
154308
315633
407010
223680
149628
205905
394275
167043
199320
275853
201918
286314
201264
405723
409593
376950
331788
185313
290208
422688
368508
421365
409593
221448
282468
187635
223680
295143
320943
147639
183039
142863
155073
216345
469455
209310
212088
142053
304215
206580
445638
147000
170895
465189
353220
223680
223680
293160
276789
172389
148953
251715
173400
178098
462360
164280
173910
470883
376950
161625
163383
409593
148620
359040

In #5:
100
953
997
969
970
987
961
972
967
971
969
950
985
984
974
973
992
959
974
999
992
951
967
954
969
996
974
989
975
972
960
981
976
956
968
972
985
959
971
988
985
963
996
967
990
963
969
990
988
976
976
968
962
979
952
970
970
958
991
960
989
982
995
952
998
957
991
997
976
955
995
966
957
962
983
987
970
990
974
985
950
964
978
952
976
984
956
988
957
965
975
975
983
963
961
969
978
991
996
959
975
Out #5:
422688
483870
444264
445638
469455
433380
448395
441525
447015
444264
418728
466608
465189
451164
449778
476625
430689
451164
486789
476625
420045
441525
424014
444264
482415
451164
472314
452553
448395
432033
460950
453945
426675
442893
448395
466608
430689
447015
470883
466608
436083
482415
441525
473748
436083
444264
473748
470883
453945
453945
442893
434730
458139
421365
445638
445638
429348
475185
432033
472314
462360
480963
421365
485328
428010
475185
483870
453945
425343
480963
440160
428010
434730
463773
469455
445638
473748
451164
466608
418728
437439
456738
421365
453945
465189
426675
470883
428010
438798
452553
452553
463773
436083
433380
444264
456738
475185
482415
430689
452553

In #6:
100
1000
999
1000
999
999
999
999
999
999
999
999
1000
1000
999
1000
999
999
1000
1000
1000
1000
999
999
1000
999
1000
999
1000
999
1000
999
1000
999
999
1000
1000
999
1000
999
1000
999
999
999
1000
1000
1000
1000
999
1000
1000
1000
999
1000
1000
999
1000
999
999
999
999
1000
1000
1000
999
1000
999
1000
1000
999
1000
1000
1000
999
999
999
1000
1000
999
1000
1000
999
1000
1000
1000
999
1000
999
1000
1000
999
1000
1000
999
1000
1000
999
999
1000
1000
999

Out #6:
488253
486789
488253
486789
486789
486789
486789
486789
486789
486789
486789
488253
488253
486789
488253
486789
486789
488253
488253
488253
488253
486789
486789
488253
486789
488253
486789
488253
486789
488253
486789
488253
486789
486789
488253
488253
486789
488253
486789
488253
486789
486789
486789
488253
488253
488253
488253
486789
488253
488253
488253
486789
488253
488253
486789
488253
486789
486789
486789
486789
488253
488253
488253
486789
488253
486789
488253
488253
486789
488253
488253
488253
486789
486789
486789
488253
488253
486789
488253
488253
486789
488253
488253
488253
486789
488253
486789
488253
488253
486789
488253
488253
486789
488253
488253
486789
486789
488253
488253
486789

In #7:
100
1000
987
997
989
984
998
998
1000
994
984
989
994
983
982
987
997
992
980
999
988
997
996
988
991
992
986
997
984
986
988
1000
985
989
980
993
1000
981
997
994
984
984
995
997
1000
980
996
998
990
983
986
996
989
993
988
997
989
997
997
997
998
989
999
986
984
998
987
990
985
990
983
982
981
996
988
990
980
987
984
995
983
990
990
982
991
985
980
998
982
990
995
986
992
1000
993
983
993
981
985
991
996

Out #7:
488253
469455
483870
472314
465189
485328
485328
488253
479514
465189
472314
479514
463773
462360
469455
483870
476625
459543
486789
470883
483870
482415
470883
475185
476625
468030
483870
465189
468030
470883
488253
466608
472314
459543
478068
488253
460950
483870
479514
465189
465189
480963
483870
488253
459543
482415
485328
473748
463773
468030
482415
472314
478068
470883
483870
472314
483870
483870
483870
485328
472314
486789
468030
465189
485328
469455
473748
466608
473748
463773
462360
460950
482415
470883
473748
459543
469455
465189
480963
463773
473748
473748
462360
475185
466608
459543
485328
462360
473748
480963
468030
476625
488253
478068
463773
478068
460950
466608
475185
482415

*/

/*Best Submissions:
C:
#include <stdio.h>
 
int lower_xor_numbers(int N);
 
int main(int argc, char const *argv[]){
	int T,N;
	scanf("%d\n",&T);
	for (int i = 0; i < T; ++i){
		scanf("%d\n",&N);
		printf("%d\n",lower_xor_numbers(N));
	}
	return 0;
}
 
int lower_xor_numbers(int N){
	int count = 0;
	for (int i = 2; i <= N; i++){
		for (int j = 1; j < i; j++){
			if ((i^j)<=N){
				count++;
			}
		}
	}
	return count;
}


C++:
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        int counter=0;
        for(int j=1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if((int)(j^k) <= n){
                    counter++;
                }
            }
        }
        cout << counter << endl;
    }
    return 0;
}


C++14:
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >>t;
    while(t--){
        cin >>n;
        int count = 0;
        for(int i=1; i<n; i++){
            for(int j=i+1; j<=n; j++){
                if((i^j) <= n)
                    count++;
            }
        }
        cout <<count <<endl;
    }
    return 0;
}


C#:
using System; 
using System.Numerics;
class MyClass {
    static void Main(string[] args) {
        int t=int.Parse(Console.ReadLine());
        for(int i=0;i<t;i++)
        {
        	int n=int.Parse(Console.ReadLine());
        	int count=0;
        	for(int j=1;j<=n;j++)
        	{
        	   for(int k=1;k<=n;k++)
        	   {
        	   	if((j^k)<=n&&j!=k)
        	   	{
        	   		count++;
        	   	}
        	   }
        	}
        	Console.WriteLine(count/2);
        }
    }
}

Java:
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.PrintWriter;
 
public class AuxOrBit {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
 
    public static void main(String[] args) {
        int t = 0, N = 0, count = 0;
        try {
            t = Integer.parseInt(br.readLine());
        } catch(IOException ex){
        }
 
        while(t-- > 0) {
            try {
               N = Integer.parseInt(br.readLine());
            } catch(IOException ex) {
            }
            count = 0;
            for(int i = 1; i <= N; i++) {
                for(int j = i+1; j <= N; j++) {
                    if((i ^ j) <= N)
                    count++;
                }
            }
            out.println(count);
        }
 
        out.flush();
        br = null;
        out = null;
        System.gc();
    }
}


Java 8:
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
 
class Main
{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
	public static void main(String args[])
	{
	    int t = 1;
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try{
            t = Integer.parseInt(br.readLine());    
        }catch (IOException e){
            e.printStackTrace();
        }
	    int n = 1;
	    int temp = 1;
		while(t-- > 0)
		{
			int count = 0;
			try{
			    n = Integer.parseInt(br.readLine());    
			}catch(IOException e){
                e.printStackTrace();
            }
            
		
			for(int i = 1; i < n; i ++)
			{
				for(int j = i + 1; j <= n ; j ++)
				{
					if((i^j) <= n)
						count ++;
				}
			}
			
			out.println(count);
		}
		out.flush();
	}
}

Java(Rhino):

importPackage(java.util);
importPackage(java.lang);
 
	var inp=new Scanner(System.in);
		var t=inp.nextInt();
		for(;t>0;t--)
		{
			var n=inp.nextInt(),ctr=0;
			for(var i=1;i<=n;i++)
			{
				for(var j=i;j<=n;j++)
					if((i^j)<=n&&i!=j)
						ctr++;
			}
			print(ctr);
		}

Java(Node.js):
function main(input) {
    //Enter your code here
    
    var arr = input.split("\n");
    for (var x = 1;x<arr.length;x++){
    	var num = parseInt(arr[x]);
    	var count = 0;
    	for (var y =1 ;y<=num;y++)
    	{
    		for(var z = y+1; z<=num;z++)
    		{
    			var result = y ^ z;
    			if(result<=num){count++;}
    		}
    		
    	}
    	console.log(count);
    	}
 //   process.stdout.write("Hello World!");
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



PHP:
<?php
 
//Read input from stdin and provide input before running code
 
//fscanf(STDIN, "%s\n", $name);
//echo "Hi, ".$name;
 

fscanf(STDIN, "%d\n", $T);
for($i=1; $i<=$T; $i++)
{
	fscanf(STDIN, "%d\n", $N);
	if($N>=2 && $N<=2000)
	pairr($N);
}
function pairr($N)
{
	//int i, j, xorval=0, count=0;
	//echo "n is $N\n";
	$count=0;
	for($i=1; $i<=$N; $i++)
	{
		//count=0;
		for($j=$i+1; $j<=$N; $j++)
		{
			if($i!=$j)
			{
				//echo "i is $i, j is $j\n";
				$xorval=$i^$j;
				if($xorval<=$N)
				{
					$count++;
				}
				$xorval=0;
			}
		}
	}
	echo $count."\n";
	$count=0;
}
?>

Perl:
$t=<>;
@v = grep {$_} map {split/\s+/,<>} 1 .. $t;
 
for my $v (@v){
    my $res = 0;    
    for(my $i=1;$i<$v;$i++){
        for(my $j=$i+1;$j<=$v;$j++){
            $res++ if ($i ^ $j) <= $v;
            #print "$v: $i $j => ".($i ^ $j)."\n" if ($i ^ $j) <= $v;
        }    
    }
    print "$res\n";
}

Python:
#Modification on existing sol by Ketan Sharma
import sys
N = int(sys.stdin.readline())
for cases in xrange(N):
    n = int(sys.stdin.readline())
    tot = n*(n-1)/2
    length = len(bin(n))-2
    lower = 2**(length-1)
    print tot - (n - lower + 1)*(lower*2 - 1 - n)

Python 3:
def ans():
    for _ in range(int(input())):
        n = int(input())
        if n < 3:
            yield 0
        else:
            m = 1 << (n.bit_length() - 1)
            yield ((m - 1) * (m - 2) + 3 * (n - m + 1) * (n - m)) // 2
print(*ans(), sep="\n")

R(Rscript):
input = file("stdin", "r")
n = as.numeric(readLines(input, n=1))
 
for (i in 1:n) {
  t = as.numeric(readLines(input, n=1))
  ans = 0
  for (j in 1:(t-1)) {
    temp = sum(bitwXor(j, (j+1):t)<=t)
    ans = ans + temp
  }
  write(ans, "")
}

Ruby:
t = gets.chomp.to_i
t.times do
   num = gets.chomp.to_i
   sum = ((num*(num-1))/2)
   bin = num.to_s(2)
   #puts "num = #{num}, bin = #{bin}"
   
   pivot = (2**(bin.length-1))
   #puts pivot
   #sum -= (pivot-1)*(pivot-2)/2
   
   max = (pivot*2)-1
   sum -= (max-num)*(num-pivot+1)
   #puts "max = #{max}, sum = #{sum}"
   puts sum
 
end

*/
