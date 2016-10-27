#include<stdio.h>
#include<omp.h>

#ifndef NUMT 
#define NUMT 1
#define NUM 2
#endif



#define NUMTRIES 5
struct s
{
	float value;
	int pad[NUM];
} Array[4];

double cos(double num){
return num;
}
int main()
{

	omp_set_num_threads( NUMT );

	unsigned int someBigNumber = 1000000000;	// if > 4B, use "long unsigned int"
	double maxperf = 0.;
	double perfsum = 0.;
	double time = omp_get_wtime();
	//#pragma omp parallel for
	#pragma omp parallel for 
	for( int i = 0; i < 4; i++ )
	{	float temp = Array[i].value;
		for( unsigned int j = 0; j < someBigNumber; j++ )
		{	temp = temp+cos((double)i);
			//Array[ i ].value = Array[ i ].value + cos((double)i);
		}
		Array[i].value = temp;
	}
	
	
	double time1 = omp_get_wtime();
	double timetaken = time1 - time;
	printf("total time taken is %lf\n", timetaken);
	printf("Performance is %lf\n\n", 4*someBigNumber/timetaken/1000000);
}
