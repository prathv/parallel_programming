#include<iostream>
#include<omp.h>
#include<stdio.h>
#define NUMS 4
#define NUMT 10
 
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


float Height( int, int );

int main( int argc, char *argv[ ] )
{
	

#ifndef _OPENMP
        fprintf( stderr, "OpenMP is not supported here -- sorry.\n" );
        return 1;
#endif
	
	float volume = 0.0; 

	// the area of a single full-sized tile:

	float fullTileArea = (  ( (XMAX-XMIN)/(float)(NUMS-1) )  *  ( ( YMAX - YMIN )/(float)(NUMS-1) )  );
//	float halfTileArea = fullTileArea/2;
//	float quarterTileArea = fullTileArea/4;

	// sum up the weighted heights into the variable "volume"
	// using an OpenMP for loop and a reduction:

	omp_set_num_threads(NUMT);
	
//#pragma omp parallel for default(none),shared(fullTileArea),reduction(+ : volume)
for( int i = 0; i < NUMS*NUMS; i++)
{//	printf("Hello with i:%d from thread :%d\n",i,omp_get_thread_num());
        
		int iu = i % NUMS;
		int iv = i / NUMS;

		float addThis =  fullTileArea * Height(iu, iv);//TODO get the sum added here?????
		if(iu == 0 || iu == NUMS -1){
			if(iv == 0 || iv == NUMS -1){
				addThis *= 0.25;
			}else{
				addThis *= 0.5;
			}
		}else if(iv == 0 || iv == NUMS - 1){
			addThis *= 0.5;
		}
		volume += addThis;
}
printf("The total weighted volume is %d\n", volume);
}
