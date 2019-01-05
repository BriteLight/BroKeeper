#!/usr/bin/env python3
print('''
             Factorial calulated from the a given larger interger down to the lower integers, e.g. n!/m!. 
             Simplified approach in this script. Not asserting any esceptions. Larger number must come first.
                                                                                                                       
                            Take it easy on number size. Only a limited demo.        Division by (0!) is a ok.                          
                            ''')
n=1
for r in range(int(input()),int(input()),-1):
    n*=r
    print(n)

