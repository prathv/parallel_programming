#!/bin/csh
foreach t (1 2 4 6 8 )
	echo NUMT = $t
	g++ -DNUMT=$t paraproj2.cpp -o prog -lm -fopenmp
	./prog
end	
