#/usr/bin/python

import random

with open('2945.in', 'w') as fd:
    n  = 20000 
    m = 20
    fd.write("%s %s\n" % (n , m))
    for i in xrange(n):
        s = ''.join([random.choice('ACGT') for i in xrange(m)])
        fd.write(s + '\n')
