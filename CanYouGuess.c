/* All Tracks -->  Math -->  Number Theory --> Basic Number Theory-1  --> Problem
Can you Guess ?
Tag(s): Very-Easy, Very-Easy

No problem statement.
Find the logic from the given sample input/output.
And answer Q queries.

Constraints :
1 <= Value <= 100000
1<=nunber of query<=10000

SAMPLE INPUT 
8
10
30
45
9
69
77
127
150

SAMPLE OUTPUT 
8
42
33
4
27
19
1
222

#include <stdio.h>

void printSumofDivisors(int n)
{           // Function to print the divisors
    int i=1;
    long sum = 0;
    // Note that this loop runs till square root
    for (; i<=sqrt(n)+1; i++)
    {
        if (n%i==0)
        {
            if (((n/i) == i) || ((n/i) == n))
                sum+=i;// If divisors are equal, print only one
            else 
                if((n/i)<i)
                    continue; // If divisors are already printed, continue
                else
                    sum+=(n/i)+i;// Otherwise print both
        }
    }
    if(n==1)
        sum=0;
    printf("%ld\n",sum);
}
 
int main()
{  
	// Driver program to test above function
    int Q,i,n;
    scanf("%d",&Q);
    for(i=0;i<Q;i++){
        scanf("%d",&n);
        printSumofDivisors(n);
    }
    return 0;
}

Another C++ Solution:
#include <bits/stdc++.h>

void printSumofDivisors(int n)
{
    int i=1;
    long sum = 0;
    for (; i<=sqrt(n)+1; i++)
    {
        if (n%i==0)
        {
            if (((n/i) == i) || ((n/i) == n))
                sum+=i;
            else 
                if((n/i)<i)
                    continue; 
                else
                    sum+=(n/i)+i;
        }
    }
    if(n==1)
        sum=0;
    printf("%ld\n",sum);
}
 
int main()
{
    int Q,i,n;
    scanf("%d",&Q);
    for(i=0;i<Q;i++){
        scanf("%d",&n);
        printSumofDivisors(n);
    }
    return 0;
}

*/

/*
In #1:
1000
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
189
190
191
192
193
194
195
196
197
198
199
200
201
202
203
204
205
206
207
208
209
210
211
212
213
214
215
216
217
218
219
220
221
222
223
224
225
226
227
228
229
230
231
232
233
234
235
236
237
238
239
240
241
242
243
244
245
246
247
248
249
250
251
252
253
254
255
256
257
258
259
260
261
262
263
264
265
266
267
268
269
270
271
272
273
274
275
276
277
278
279
280
281
282
283
284
285
286
287
288
289
290
291
292
293
294
295
296
297
298
299
300
301
302
303
304
305
306
307
308
309
310
311
312
313
314
315
316
317
318
319
320
321
322
323
324
325
326
327
328
329
330
331
332
333
334
335
336
337
338
339
340
341
342
343
344
345
346
347
348
349
350
351
352
353
354
355
356
357
358
359
360
361
362
363
364
365
366
367
368
369
370
371
372
373
374
375
376
377
378
379
380
381
382
383
384
385
386
387
388
389
390
391
392
393
394
395
396
397
398
399
400
401
402
403
404
405
406
407
408
409
410
411
412
413
414
415
416
417
418
419
420
421
422
423
424
425
426
427
428
429
430
431
432
433
434
435
436
437
438
439
440
441
442
443
444
445
446
447
448
449
450
451
452
453
454
455
456
457
458
459
460
461
462
463
464
465
466
467
468
469
470
471
472
473
474
475
476
477
478
479
480
481
482
483
484
485
486
487
488
489
490
491
492
493
494
495
496
497
498
499
500
501
502
503
504
505
506
507
508
509
510
511
512
513
514
515
516
517
518
519
520
521
522
523
524
525
526
527
528
529
530
531
532
533
534
535
536
537
538
539
540
541
542
543
544
545
546
547
548
549
550
551
552
553
554
555
556
557
558
559
560
561
562
563
564
565
566
567
568
569
570
571
572
573
574
575
576
577
578
579
580
581
582
583
584
585
586
587
588
589
590
591
592
593
594
595
596
597
598
599
600
601
602
603
604
605
606
607
608
609
610
611
612
613
614
615
616
617
618
619
620
621
622
623
624
625
626
627
628
629
630
631
632
633
634
635
636
637
638
639
640
641
642
643
644
645
646
647
648
649
650
651
652
653
654
655
656
657
658
659
660
661
662
663
664
665
666
667
668
669
670
671
672
673
674
675
676
677
678
679
680
681
682
683
684
685
686
687
688
689
690
691
692
693
694
695
696
697
698
699
700
701
702
703
704
705
706
707
708
709
710
711
712
713
714
715
716
717
718
719
720
721
722
723
724
725
726
727
728
729
730
731
732
733
734
735
736
737
738
739
740
741
742
743
744
745
746
747
748
749
750
751
752
753
754
755
756
757
758
759
760
761
762
763
764
765
766
767
768
769
770
771
772
773
774
775
776
777
778
779
780
781
782
783
784
785
786
787
788
789
790
791
792
793
794
795
796
797
798
799
800
801
802
803
804
805
806
807
808
809
810
811
812
813
814
815
816
817
818
819
820
821
822
823
824
825
826
827
828
829
830
831
832
833
834
835
836
837
838
839
840
841
842
843
844
845
846
847
848
849
850
851
852
853
854
855
856
857
858
859
860
861
862
863
864
865
866
867
868
869
870
871
872
873
874
875
876
877
878
879
880
881
882
883
884
885
886
887
888
889
890
891
892
893
894
895
896
897
898
899
900
901
902
903
904
905
906
907
908
909
910
911
912
913
914
915
916
917
918
919
920
921
922
923
924
925
926
927
928
929
930
931
932
933
934
935
936
937
938
939
940
941
942
943
944
945
946
947
948
949
950
951
952
953
954
955
956
957
958
959
960
961
962
963
964
965
966
967
968
969
970
971
972
973
974
975
976
977
978
979
980
981
982
983
984
985
986
987
988
989
990
991
992
993
994
995
996
997
998
999
1000
Out #1:
0
1
1
3
1
6
1
7
4
8
1
16
1
10
9
15
1
21
1
22
11
14
1
36
6
16
13
28
1
42
1
31
15
20
13
55
1
22
17
50
1
54
1
40
33
26
1
76
8
43
21
46
1
66
17
64
23
32
1
108
1
34
41
63
19
78
1
58
27
74
1
123
1
40
49
64
19
90
1
106
40
44
1
140
23
46
33
92
1
144
21
76
35
50
25
156
1
73
57
117
1
114
1
106
87
56
1
172
1
106
41
136
1
126
29
94
65
62
25
240
12
64
45
100
31
186
1
127
47
122
1
204
27
70
105
134
1
150
1
196
51
74
25
259
35
76
81
118
1
222
1
148
81
134
37
236
1
82
57
218
31
201
1
130
123
86
1
312
14
154
89
136
1
186
73
196
63
92
1
366
1
154
65
176
43
198
29
148
131
170
1
316
1
100
141
203
1
270
1
265
71
104
37
300
47
106
105
226
31
366
1
166
75
110
49
384
39
112
77
284
31
234
1
280
178
116
1
332
1
202
153
218
1
312
53
184
83
194
1
504
1
157
121
190
97
258
33
232
87
218
1
476
35
130
177
255
1
270
45
328
129
134
1
456
59
214
93
208
1
450
1
286
175
140
97
396
1
142
137
440
1
294
1
220
195
218
49
531
18
250
101
226
1
390
65
274
183
152
37
568
51
154
105
316
67
396
1
364
107
266
1
528
1
160
309
244
1
330
41
442
111
254
37
523
109
166
113
302
55
534
1
256
161
170
73
656
1
211
117
416
43
438
57
316
231
176
1
492
1
394
209
404
1
366
77
274
219
182
1
810
20
184
169
420
79
378
1
376
177
314
61
524
1
274
249
344
43
582
1
460
131
194
1
636
191
196
185
298
1
618
41
463
135
200
85
696
1
202
241
561
1
414
45
310
321
314
49
672
1
346
141
316
67
522
89
466
143
302
1
924
1
214
201
386
133
438
69
328
243
362
1
808
1
334
285
334
43
450
1
640
300
314
1
620
95
226
153
568
1
759
53
346
155
230
217
744
1
232
261
548
1
690
1
466
303
236
1
806
75
394
161
428
55
486
145
532
225
242
1
1032
51
244
285
447
103
606
1
442
167
536
1
684
47
346
441
496
79
510
1
592
171
254
1
1056
107
358
225
388
1
786
81
511
287
260
109
716
59
394
177
740
1
648
1
400
467
266
49
960
24
442
249
588
55
546
113
484
183
272
145
1140
1
274
185
590
115
798
1
418
257
566
49
888
87
280
357
424
1
690
57
928
303
284
1
780
119
286
401
512
1
870
1
604
195
434
169
1075
1
343
197
680
91
594
65
526
507
296
1
1008
51
490
201
586
1
846
269
454
203
410
1
1260
1
454
281
460
193
618
1
652
351
506
61
1026
1
310
393
824
1
630
1
724
339
314
97
1112
156
316
333
478
55
1242
1
568
215
320
133
876
161
442
297
890
1
654
1
700
411
434
1
1167
71
652
373
496
1
666
137
646
305
494
1
1356
1
334
345
596
295
816
53
508
227
554
73
1344
1
340
565
605
1
690
105
940
231
470
1
1136
143
514
233
676
67
1038
1
526
555
350
145
1104
59
352
237
1036
1
978
57
820
447
356
109
972
1
586
329
638
55
1014
293
544
243
362
1
1698
111
421
245
550
205
870
1
952
364
602
61
1004
1
370
633
776
79
900
1
856
379
554
1
1176
155
376
345
764
115
1122
1
736
255
506
157
1484
1
382
393
1040
1
774
117
580
639
386
73
1276
1
958
261
586
1
942
217
694
439
392
61
1572
83
514
417
983
163
798
1
598
267
650
121
1548
75
400
501
604
1
1122
65
1153
369
404
85
1100
347
538
273
722
1
1368
1
868
275
554
169
1416
63
412
637
944
1
834
1
736
663
614
1
1356
1
682
281
946
193
846
173
844
443
422
1
2040
30
424
285
640
253
1026
217
826
287
824
61
1164
1
634
705
764
1
1158
1
988
483
434
1
1656
179
436
361
924
91
1290
81
778
401
566
373
1196
1
442
297
1352
1
1341
1
880
555
446
1
1392
135
730
561
676
67
906
185
1144
447
452
61
1921
71
610
505
806
187
918
1
688
417
1106
1
1568
95
460
573
694
139
1242
1
1240
311
464
85
1764
253
466
425
962
1
1374
209
706
315
470
361
1794
1
694
317
1076
1
954
65
916
975
638
1
1292
87
910
321
1208
1
1152
197
724
483
482
145
2088
32
634
441
730
199
1338
1
1027
471
794
1
1576
147
490
761
946
1
990
101
1414
449
494
1
1536
203
634
549
972
67
1818
1
1024
335
734
205
1356
1
502
521
1340
*/


/* Best Submissions:
C:
#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,s=0;
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            if(n%i==0)
            s+=i;
        }
        printf("%d\n",s);
    }
}

C++:
// Sample code to perform I/O:
 
#include <iostream>
 
using namespace std;
 
int main() {
	int num;
	cin >> num;										
	for(int i=0;i<num;i++){
	    int input,output=0;
	    cin >> input;
	    for(int i=1;i*i<=input;i++){
	        if(input%i==0){
	            output += i;
	            output += (input/i);
	        }
	        if(i*i==input){
	            output-=i;
	        }
	    }
	    output -= input;
	    cout << output <<endl;
	}
}

C++14:
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        long long n;
        cin >> n;
        long long sum = 0;
        for(long long j=1; j<n; j++){
            if(n % j == 0){
                sum += j;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}

C#:
using System;
using System.Collections.Generic;
 
class MyClass {
     static void Main(string[] args)
        {
            int numberOfTestCase = Convert.ToInt32(Console.ReadLine());
            List<int> getAll = new List<int>();
            
            int[] sum = new int[numberOfTestCase];
            for (int i = 0; i < numberOfTestCase;i++ )
            {
                int sumTotal = 0;
                int numVal = Convert.ToInt32(Console.ReadLine());
                getAll = Factor(numVal);
                foreach(int val in getAll)
                {
                    sumTotal = sumTotal + val;
                }
                sum[i] = sumTotal;
            }
 
         foreach (int i in  sum)
            Console.WriteLine(i);
 
              
            Console.ReadKey();
        }
 
      
        public static  List<int> Factor(int number)
        {
            List<int> factors = new List<int>();
            int max = (int)Math.Sqrt(number);  //round down
            for (int factor = 1; factor <= max; ++factor)
            { //test from 1 to the square root, or the int below it, inclusive.
                if (number % factor == 0)
                {
                    factors.Add(factor);
                    if (factor != number / factor)
                    { // Don't add the square root twice!  Thanks Jon
                        factors.Add(number / factor);
                    }
                }
            }
             factors.Remove(number);
 
             return factors;
        }
 
    }
 
Java:
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.PrintWriter;
 
public class CanUGuess {
 
	public static void main(String[] args) {
		InputReader s = new InputReader(System.in);
		PrintWriter o = new PrintWriter(System.out);
			int t=s.nextInt();
			while(t-- >0){
				int n=s.nextInt();
				long sum=0;
				for (int i=1; i<=Math.sqrt(n); i++)
			    {
			        if (n%i==0)
			        {
			            // If divisors are equal, print only one
			            if (n/i == i)
			                sum=sum+i;
			 
			            else // Otherwise print both
			               sum=sum + i +n/i; 
			        }
			    }
				sum=sum-n;
				o.println(sum);
			}
		o.close();
	}
 
	static long GCD, Xinv, Yinv;
 
	static void gcd(long a, long b) {
		if (b == 0) {
			GCD = a;
			Xinv = 1;
			Yinv = 0;
		} else {
			gcd(b, a % b);
			long temp = Xinv;
			Xinv = Yinv;
			Yinv = temp - (a / b) * Yinv;
		}
	}
 
	static long modInverse(long a, long m) {
		gcd(a, m);
		return (Xinv % m + m) % m;
	}
 
	static long m = 1000000007;
 
	static long modularExpnentiation(long x, long y) {
		if (y == 0)
			return 1;
		if (y % 2 == 0)
			return modularExpnentiation((x * x) % m, y / 2);
		else
			return (x * modularExpnentiation(x, y - 1)) % m;
	}
 
	public static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
 
		public InputReader(InputStream inputstream) {
			reader = new BufferedReader(new InputStreamReader(inputstream));
			tokenizer = null;
		}
 
		public String nextLine() {
			String fullLine = null;
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					fullLine = reader.readLine();
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
				return fullLine;
			}
			return fullLine;
		}
 
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
 
		public long nextLong() {
			return Long.parseLong(next());
		}
 
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}

Java8:
//imports for BufferedReader
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
//import for Scanner and other utility classes
import java.util.*;
 
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        // Sample code to perform I/O:
        // Use either of these methods for input
 
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String name = br.readLine();                // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
 
        //Scanner
        //Scanner s = new Scanner(System.in);
        //String name = s.nextLine();                 // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT

 
        // Write your code here
        BufferedReader bufread = new BufferedReader(new InputStreamReader(System.in));
        Integer testCases = Integer.parseInt(bufread.readLine()) ;
        for(int i = 0 ; i < testCases ;i++){
            Integer number = Integer.parseInt(bufread.readLine()) ;
            int sum =0 ;
            for(int j =1 ;j < number ;j++){
                if(number%j==0)
                sum+=j ;
            }
            System.out.println(sum);
        }
 
    }
}

Pascal:
var
  t,n,i:longint;
  u:int64;
BEGIN
  readln(t);
  while (t>0) do begin
    dec(t);
    readln(n);
    u := 0;
    for i:=1 to (n div 2) do if (n mod i = 0) then u := u + i;
    writeln(u);
  end;
END.

Python:
n=int(input())
while n!=0:
    m=int(input())
    temp=0
    for i in range(1,m):
       if m%i==0:
        temp=temp+i
    print temp
    n-=1


Python 3:
n = int(input())
for i in range(n):
    q = int(input())
    s = 0
    for j in range(1, q):
        if (q%j==0):
            s += j
    print (s)


PHP:
<?php

// Sample code to perform I/O:
//fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
//echo "Hi, ".$name.".\n";                // Writing output to STDOUT
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
// Write your code here
fscanf(STDIN, "%d\n", $n);

for($i = 1; $i <= $n; $i++)
{
    fscanf(STDIN, "%d\n", $number);
    if($number == 1){
        $sum = 0;
    }else{
        $sum = 1;
    }
    for($j = 2; $j <= $number/2; $j++)
    {
        if($number % $j == 0){
            $sum = $sum + $j;
        }
    }
    echo $sum . PHP_EOL;
}
?>


Ruby:
gets.to_i.times {
    n = gets.to_i
    div = 0
    if n > 1 then
        div = 1
        i = 2
        while (i*i <= n) do
            div += i if n % i == 0
            div += n/i if i*i != n and n % (n/i) == 0
            i += 1
        end
    end
    puts div
}

VB:
gets.to_i.times {
    n = gets.to_i
    div = 0
    if n > 1 then
        div = 1
        i = 2
        while (i*i <= n) do
            div += i if n % i == 0
            div += n/i if i*i != n and n % (n/i) == 0
            i += 1
        end
    end
    puts div
}

*/
