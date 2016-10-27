#!/bin/csh

foreach l (8 16 32 64 128 256 512)
	foreach t (1024 4096 8192 32768 65536 131072 262144 524288 1048576 2097152 3145728 4194304 5242880 6291456 7340032 8388608)   
		/nfs/guille/a2/rh80apps/intel/studio.2013-sp1/composer_xe_2015.0.090/bin/intel64/icpc -o first first.cpp  -no-vec /scratch/cuda-7.0/lib64/libOpenCL.so -lm -openmp -DNMB=$t -DLOCAL_SIZE=$l 
		./first
	end
end 
