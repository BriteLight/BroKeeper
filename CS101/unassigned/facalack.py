#!/usr/bin/env python3
from sys import argv

n=1

if len(argv) == 3:
    n, m = int(argv[1]), int(argv[2])
else:
    if len(argv) == 2:
        n, m = int(argv[1]), 0
    else:
        print('''
             Factorial illustrated as calulated from the a given interger down to the lower integers, e.g. 1!(0!). 
     Escape from loop is a true end pint without extra checks on n=1 or n=0 for that matter. Division by (0!) is a ok. 
                                                                                                                       
     Demostration is meant to be useful, intructive, and more intuitave that merely printing out the final results. 
     For starters, this is a division operation showing that n! / (0!) is equivalent to determining what n! is. 
     General purpose is for showing intermediate numbers for calculating n(n-1)(n-2)...(m+1) for n! / m! . 
     When case is such that m > n, final result is shown as an inverted fraction 1/[n(n-1)(n-2)(n-3)...(m+1)]. 
     Additional future features will have an option for (n!)*(m!), shown as n(n-1)(n-2)...(m+1)*(m!)^2 for n > m. 
     Partial account for Gamma Function outcomes only for half-integers, negative half-integers, and large integers. 
                                                                                                                       
                            Take it easy on number size. Only a limited demo.                                           
                            ''')
        print("enter n: ", end=' ')
        n=input()
        print("enter m: ", end=' ')
        m=input()

assert(n>=0 and m>=0),"Unable to process request. Requires integer argument. One <int> minimum. Two <int> max"


print(n,'!',sep='')
print(m,'!',sep='')


if n < m:
    number=m
    lesser=n
else:
    number=n
    lesser=m

endn=lesser+1
drop=number-1
fact=number*drop

print(number)

while drop != endn:
    print(fact)
    number=drop
    drop=number-1
    fact=fact*drop


print(fact)
print("For  ",n,"!/",m,"!",sep='')

if n<m:
    print("Result:   1/",fact,sep='')

