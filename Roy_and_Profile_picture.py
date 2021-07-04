//Author Solution by Ravi Ojha 
    def roy_and_profile_pic():
        L = input()
        N = input()
        for t in xrange(N):
            W,H = map(int,raw_input().split())
            if W < L or H < L:
                print 'UPLOAD ANOTHER'
            else:
                if W == H:
                    print 'ACCEPTED'
                else:
                    print 'CROP IT'
    roy_and_profile_pic()

//Tester Solution by Lalit Kundu

    l=input()
    n=input()
    for i in range(n):
    	x=raw_input()
    	y=x.split()
    	w=int(y[0])
    	h=int(y[1])
    	if w<l or h<l: print "UPLOAD ANOTHER"
    	elif w==h: print "ACCEPTED"
    	else: print "CROP IT" 

		
