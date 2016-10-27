#include <stdio.h>
#include <omp.h>
#include "simd.p5.h"
//#define NUM 

#define NUMTRIES 5

int main()
{


float *a = new float[NUM];
float *b = new float[NUM];
float *c = new float[NUM];
int i;

//double time = omp_get_wtime();
double totaltimetaken1 = 0.0;
double totaltimetaken2 = 0.0;
double maxtime = 0.;
double maxtime2 = 0.;

double multsum = 0.0;
double multsum2 = 0.0;
//printf("SIMD MULT performance \t");
//printf("SIMD MULTREDUCE performance \n");
for( i=0; i < NUMTRIES; i++)

	{	
		double time = omp_get_wtime();
		SimdMul(a,b,c,NUM);
		
		double time1 = omp_get_wtime();
		double timetaken = time1 - time;
		totaltimetaken1 += timetaken;
		double mult = (double) NUM/ timetaken/1000000;
//		printf("performance is %lf\n",mult);
		
		multsum += mult;
		
		if(maxtime < mult)
		{ 
			maxtime = mult;
			
		}	
		//printf("Maxtime is %lf\n",maxtime);
		double time2 = omp_get_wtime();
		
		SimdMulSum(a,b,NUM);
		
		double time3 = omp_get_wtime();
		
		double timetaken2 = time3 - time2;
		totaltimetaken2 += timetaken2;
		//printf("Time taken for reduction is %lf\n",timetaken2);
		double mult2 = (double) NUM/timetaken2/1000000.;
//		printf("performance for reduction is %lf\n",mult2);
		multsum2 += mult2;
		if(maxtime2 < mult2)
		{
			maxtime2 = mult2;	
		}
//		printf("max performance is %lf\n",maxtime2);
	}




//printf("total time is %lf\n",multsum);
//printf(" Average performance for SimdMul is %lf Megamultiplies \t",(double) multsum/NUMTRIES);
//printf("Peak performance is %lf MegaMultiplies per second\n",maxtime);
//printf(" Average perforamnce for SimdMulred%lf \t\n", (double) multsum2/NUMTRIES);
//printf("Peak performance for reduction is %lf \n\n", maxtime2);
printf(" Time taken for SimdMUL is %lf microseconds\n",totaltimetaken1*1000000);
printf("Time taken for SimdMUlRed is %lf microseconds \n\n",totaltimetaken2*1000000); 
return 0;


}
