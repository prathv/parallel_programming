#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define XMIN	 0.
#define XMAX	 3.
#define YMIN	 0.
#define YMAX	 3.

#define Z00	0.
#define Z10	1.
#define Z20	0.
#define Z30	0.

#define Z01	1.
#define Z11	6.
#define Z21	1.
#define Z31	0.

#define Z02	0.
#define Z12	1.
#define Z22	0.
#define Z32	4.

#define Z03	3.
#define Z13	2.
#define Z23	3.
#define Z33	3.

#define NUMS 30
#define NUMT 2
#define NUMTRIES 10


float Height( int iu, int iv )	// iu,iv = 0 .. NUMS-1
{
	float u = (float)iu / (float)(NUMS-1);
	float v = (float)iv / (float)(NUMS-1);

	// the basis functions:

	float bu0 = (1.-u) * (1.-u) * (1.-u);
	float bu1 = 3. * u * (1.-u) * (1.-u);
	float bu2 = 3. * u * u * (1.-u);
	float bu3 = u * u * u;

	float bv0 = (1.-v) * (1.-v) * (1.-v);
	float bv1 = 3. * v * (1.-v) * (1.-v);
	float bv2 = 3. * v * v * (1.-v);
	float bv3 = v * v * v;

	// finally, we get to compute something:

	float height = 	  bu0 * ( bv0*Z00 + bv1*Z01 + bv2*Z02 + bv3*Z03 )
			+ bu1 * ( bv0*Z10 + bv1*Z11 + bv2*Z12 + bv3*Z13 )
			+ bu2 * ( bv0*Z20 + bv1*Z21 + bv2*Z22 + bv3*Z23 )
			+ bu3 * ( bv0*Z30 + bv1*Z31 + bv2*Z32 + bv3*Z33 );

	return height;
}

int main( int argc, char *argv[ ] )
{	
	
	omp_set_num_threads(NUMT);
	printf("With values Nums:%d and Numt:%d\n",NUMS,NUMT);
 
	// start the timings. . .
	//double time0 = omp_get_wtime();
    	float volume = 0.;

	// the area of a single full-sized tile: 
	float fullTileArea = (  ( (XMAX-XMIN)/(float)(NUMS-1) )  *  ( ( YMAX - YMIN )/(float)(NUMS-1) )  );

	// sum up the weighted heights into the variable "volume"
	//starts out with nothing

	double sumheight = 0.;
	double maxheight = 0.;
	// using an OpenMP for loop and an addition reduction:
for(int j = 0 ; j < 100 ; j++)
{

volume = 0.;
double time1 = omp_get_wtime();

#pragma omp parallel for default(none), reduction(+:volume), shared(fullTileArea)
for( int i = 0; i < NUMS*NUMS; i++ )
	{
	 	
    
	int iu = i % NUMS;
	int iv = i / NUMS;
	
	int max = NUMS - 1;
	int min = 0;

	if((iu == max && iv == min )||(iv == max && iu == min)|| (iv == min && iu == min) || (iu == max && iv == max))
	{

	volume += (fullTileArea * Height(iu,iv))/4;
	}

	else if (iu == min || iv == max || iu == max || iv == min){	
	volume += (fullTileArea * Height(iu,iv))/2;
	}
	
	else{

	volume += fullTileArea * Height(iu,iv);

	}

}

double time2 = omp_get_wtime();

double heightmult = (double)(NUMS * NUMS)/(time2 - time1)/1000000.;

//printf("Height per thread is %d\n", heightmult);
sumheight += heightmult;

if(heightmult > maxheight)
	maxheight = heightmult; 

}

//printf("Time difference for thread is %d", dtime1-dtime);

//totaltime += dtime1 - dtime;
		
printf("Peak performance is %d", maxheight);

printf("Average Performance is %d", sumheight);


//	double time1 = omp_get_wtime();

//	double timeUsed = time1 - time0;

//	printf("Total time taken is:%lf\n",timeUsed);

	printf("Volume found to be %f\n",volume);

//printf("With time precision %g\n\n\n", omp_get_wtick());

return 0;
}
