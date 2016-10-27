#!/bin/csh
foreach t (1 2 4 )
	foreach n ( 0 2 8 15 )
		echo NUMT = $t
		echo NUM = $n
		g++ -DNUMT=$t -DNUM=$n parallelproj3-fix2.cpp -o prog -lm -fopenmp
		./prog
	end
end	
