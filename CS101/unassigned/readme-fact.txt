Some ongoing checks on how a factorial algorithm can be done in various way and various lanuages and shell scripts.

Just a not on a clear limitation in the example, "Copy_of_Java-example.SimpleFactorial.java", which is shown in comments.
Two TCSH scripts were done, one with comparable results illustrating the same limitation and the other goes way beyond.

There are other obvious limits accross each one of course. But more modifications can slightly enhance the better of the 3.
One good note is that the python (pending) version may prove to be the one to go forward with more enhancements than ever.

####
# fac.tcsh - Recursive calls to the script itself, spawning interations of itself until n=1 then calculating !n from low end.
# 
# factorial.tcsh - Intentially run in reverse order, from a given n calculating larger number first down to a lower m! or 0!.
####
