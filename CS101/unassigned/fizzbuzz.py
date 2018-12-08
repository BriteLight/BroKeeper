#!/usr/bin/env python3
from sys import argv

"""

this is a program that prints a list of integers from 1 to some endning number , r.
But for multiples of one number, s, print "Fizz" instead of the number and for the multiples of another number, t, print "Buzz".
For numbers which are multiples of both s and t print "FizzBuzz".

"""
def fizzout(r,s,t):
    for i in range(1,(r+1)):
        if (i %s == 0 and i %t == 0):
            yield "fizzbuzz"
        elif i %s == 0:
            yield "fizz"
        elif i %t == 0:
            yield "Buzz"
        else:
            yield i

if len(argv) != 4:
    raise Exception("usage: takes three integers, <int> <int> <int>")
try:
    r, s, t = int(argv[1]), int(argv[2]), int(argv[3])
except ValueError:
  raise Exception("Enter 3 integers: One for a range of numbers, and two other integers where multiples of which are to be replaced by Fizz or Buzz.")

for num in fizzout(r,s,t):
  print(num)

