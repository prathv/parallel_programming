#include<stdio.h>
#include<omp.h>

struct s
{
	float value;
	int pad[NUM];
} Array[4];

double cos( double i){
return i;
}

int main()
{

	omp_set_num_threads( NUMT );

	unsigned int someBigNumber = 1000000000;	// if > 4B, use "long unsigned int"
	double time = omp_get_wtime();
	#pragma omp parallel for 
	for( int i = 0; i < 4; i++ )
	{	
		for( unsigned int j = 0; j < someBigNumber; j++ )
		{	
		Array[ i ].value = Array[ i ].value + cos((double)i);
		}
	
	}
	
	
	double time1 = omp_get_wtime();
	double timetaken = time1 - time;
	printf("total time taken is %8.2lf\n", timetaken);
	printf("Performance is %10.21lf\n\n", (double)4*someBigNumber/timetaken/1000000.);
}
