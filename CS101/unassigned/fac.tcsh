#!/usr/bin/tcsh -f


if ( $1 == 2 ) then
	@ fac = 2 * `$0 1` 
	echo $fac
else if ( $1 >= 3 ) then
	@ nex = $1 - 1
	@ fac = $1 * `$0 $nex`
	echo $fac
endif
endif

if ( $1 == 1 ) then
	echo 1
endif
