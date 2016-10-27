#!/bin/csh
echo "NonSimdMult perf  NonSimdReduce perf"
foreach n (1000 10000 1000000 2000000 3000000 4000000 5000000 10000000 20000000 30000000)
	g++ -o arraymult -DNUM=$n arraymultnsimd.cpp simd.p5.o -fopenmp -lm
	./arraymult
end
