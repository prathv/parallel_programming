#include<stdio.h>
#include<omp.h>

//#define NUM 1000
#define NUMTRIES 5

int main()
{

float *a = new float[NUM];
float *b = new float[NUM];
float *c = new float[NUM];

int i;
int j;
double multsum = 0.0;
double multsum2 = 0.0;
double totaltimetaken1 = 0.0;
double totaltimetaken2 = 0.0;
//double time = omp_get_wtime();
double maxtime = 0.0;
double maxtime2 = 0.0;
double sum = 0.0;

for(j=0; j<NUMTRIES; j++)
{	
	double time1 = omp_get_wtime();
	
	for(i=0; i<NUM; i++)
	{
		c[i] = a[i] * b[i];
	}	
	double time2 = omp_get_wtime();
	double timetaken = time2 - time1;
	totaltimetaken1 += timetaken;
	double mult = (double) NUM/timetaken/1000000.;
//	printf("performance is %lf\n",mult);
	multsum += mult;
	//printf(" time taken is %lf\n", time2 - time1);
	if(maxtime < mult)
	{
		maxtime = mult;
	}
	
	double time3 = omp_get_wtime();
	for(i = 0; i < NUM; i++)
	{
		sum += a[i] * b[i];
	} 
	double time4 = omp_get_wtime();
	
	double timetaken2 = time4 - time3;
	totaltimetaken2 += timetaken2;
	double mult2 = (double) NUM/timetaken2/1000000.;
	multsum2 += mult2;

	if(maxtime2 < mult2)
	{
		maxtime2 = mult2;
	}

}

//printf("%lf \t",(double) multsum/NUMTRIES); 
//printf("%lf", maxtime);
//printf("%lf\n", multsum2/NUMTRIES);
//printf("Peak performance for reduction is %lf\n\n", maxtime2);
printf("Time taken for NonSimdMul is %lf microseconds \n",totaltimetaken1*1000000);
printf("Time taken for NonSimdMulReduce is %lf microseconds \n\n",totaltimetaken2*1000000);
}
