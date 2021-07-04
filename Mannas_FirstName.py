for i in range(int(raw_input())):
    name = raw_input()
    suvo = name.count('SUVO')
    suvojit = name.count('SUVOJIT')
    print "SUVO = %d, SUVOJIT = %d"%(suvo-suvojit,suvojit)