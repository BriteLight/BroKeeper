#!/usr/bin/tcsh -f
   
# Factorial illustrated as calulated from the a given interger down to the lower integers, e.g. 1!(0!). 
# Escape from loop is a true end pint without extra checks on n=1 or n=0 for that matter. Division by (0!) is a ok.
#
# Demostration is meant to be useful, intructive, and more intuitave that merely printing out the final results. 
# For starters, this is a division operation showing that n! / (0!) is equivalent to determining what n! is.
# General purpose is showing intermediate numbers for calculating n(n-1)(n-2)...(m+1) for n! / m!.
# When case is such that m > n, final result is shown as an inverted fraction 1/[n(n-1)(n-2)(n-3)...(m+1)].
# Additional future features will have an option for (n!)*(m!), shown as n(n-1)(n-2)...(m+1)*(m!)^2 for n > m.
# Partial account for Gamma Function outcomes only for half-integers, negative half-integers, and large integers.
#  

set n=1
if ( $# == 2 ) then
	set n=$1
	set m=$2
else if ( $# == 1 ) then
	set n=$1
	set m=0
else 
	echo "\
     Factorial illustrated as calulated from the a given interger down to the lower integers, e.g. 1!(0!). \
     Escape from loop is a true end pint without extra checks on n=1 or n=0 for that matter. Division by (0!) is a ok. \
	                                                                                                               \
     Demostration is meant to be useful, intructive, and more intuitave that merely printing out the final results. \
     For starters, this is a division operation showing that n! / (0!) is equivalent to determining what n! is. \
     General purpose is for showing intermediate numbers for calculating n(n-1)(n-2)...(m+1) for n! / m! . \
     When case is such that m > n, final result is shown as an inverted fraction 1/[n(n-1)(n-2)(n-3)...(m+1)]. \
     Additional future features will have an option for (n!)*(m!), shown as n(n-1)(n-2)...(m+1)*(m!)^2 for n > m. \
     Partial account for Gamma Function outcomes only for half-integers, negative half-integers, and large integers. \
	                                                                                                               \
	                    Take it easy on number size. Only a limited demo.                                           \
     "
	echo -n "enter n: "
	set n=$<
	echo -n "enter 0 for denominator(0!) if you're done. enter m: "
	set m=$<
endif
endif
echo "$n!"
echo "$m!"



if ( $n < $m ) then
	set invert = 1
	set number = $m
	set lesser = $n
else
	set number = $n
	set lesser = $m
endif

set endn = `expr $lesser + 1`
set drop = `expr $number - 1`
set fact = `expr $number \* $drop`

echo $number

while ( $drop != $endn )
	echo $fact
	set number = $drop
	set drop = `expr $number - 1`
	set fact = `expr $fact \* $drop`
end

echo $fact
echo "For $n! / $m!"

if( $?invert ) then
	echo "Result:  1 / ( $fact )"
endif
