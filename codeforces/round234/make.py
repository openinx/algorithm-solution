#!/usr/bin/python

with open('d.txt','w') as fd:
    fd.write("100000 99654 500\n")
    s = "13231 4423 16039 46334 15947 2047 207 29 623 405 107 25 13 55 15 13 3 1 1 1 1 1 1 1 1 2 1 1 1 1 1 1 1 1 1 1 1 1 1"
    #print s.split(' ')
    print len(s.split(' ')) - 1
    sm = sum( [int(i) for i in s.split(" ")[:-1]] )
    print sm
    fd.write(s)
    for i in range(500 - len(s.split(' '))  + 1):
        fd.write(" 1")
    fd.write("\n")
    for i in range(99654):
        fd.write('1 1 0\n')
