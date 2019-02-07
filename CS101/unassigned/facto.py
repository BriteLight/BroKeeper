#!/usr/bin/env python

class MatterOfac(object):
  def __init__(self, n=1):
      self.n = n
  def testit(self):
      print(self.n)


MFacFive = MatterOfac(n=5)
MFacFive.testit()
MFac = MatterOfac()
MFac.testit()
