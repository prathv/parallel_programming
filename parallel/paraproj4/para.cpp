#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<math.h>

int	NowYear;		// 2016 - 2021
int	NowMonth;		// 0 - 11
int 	NowMonster;

float	NowPrecip;		// inches of rain per month
float	NowTemp;		// temperature this month
float	NowHeight;		// grain height in inches
int	NowNumDeer;


float currHeight;

const float GRAIN_GROWS_PER_MONTH =		8.0;
const float ONE_DEER_EATS_PER_MONTH =		0.5;

const float AVG_PRECIP_PER_MONTH =		6.0;
const float AMP_PRECIP_PER_MONTH =		6.0;
const float RANDOM_PRECIP =			2.0;

const float AVG_TEMP =				50.0;
const float AMP_TEMP =				20.0;
const float RANDOM_TEMP =			10.0;

const float MIDT = 	40.;
const float MIDP =	10.;


float Ranf(float, float);
int RanInt( int ilow, int ihigh );
void temppre();


void GrainDeer()
{
int currdeer;
int currtemp;

while( NowYear <= 2021 )
{	
	currdeer = NowNumDeer;
	currtemp = NowTemp;

	if(NowHeight > currdeer)
	{
			currdeer += 1;
	}
	
	else if( NowHeight < currdeer )
	{
			currdeer -= 1;
		
		if(currdeer < 0)
		{
			currdeer = 0;
		}
	
	}   
	else
	{
	
	}
	
	if(NowMonster > 3)
	{
		currdeer -= 1;
	}
	
	// DoneComputing barrier:
	#pragma omp barrier
	NowNumDeer = currdeer;
	
	// DoneAssigning barrier:
	#pragma omp barrier
	

	// DonePrinting barrier:
	#pragma omp barrier
	
}
}

void Grain()
{
float tempFactor;
float precipFactor;
while( NowYear <= 2021 )
{	

	// compute a temporary next-value for this quantity based on the current state of the simulation:
	currHeight = NowHeight; 
	tempFactor= exp ((-1) * pow( ((float) (NowTemp- MIDT)/10), 2));
         precipFactor= exp ((-1) * pow( ((float) (NowPrecip- MIDP)/10), 2));
	
	
	// DoneComputing barrier:
	#pragma omp barrier
	
 	NowHeight += tempFactor * precipFactor * GRAIN_GROWS_PER_MONTH;
 	NowHeight -= (float)NowNumDeer * ONE_DEER_EATS_PER_MONTH;	
	
	if(NowHeight < 0)
	{
		NowHeight = 0;
	}

	// DoneAssigning barrier:
	#pragma omp barrier
	

	// DonePrinting barrier:
	#pragma omp barrier
	
}

}

void Watcher()
{
float celc;
int currmonth ;
while( NowYear <= 2021 )
{

	// compute a temporary next-value for this quantity based on the current state of the simulation:
	currmonth = NowMonth;
	celc = (5./9.) * (NowTemp - 32); 	
	
	// DoneComputing barrier:
	#pragma omp barrier
	
	// DoneAssigning barrier:
	#pragma omp barrier
	
	printf("%d\t %d\t  %d\t %f\t  %f\t %lf\t  %f\t  %d \n",NowYear,NowMonth, NowNumDeer, NowPrecip, NowHeight, celc, currHeight, NowMonster);
	
	currmonth += 1;
	
	if(currmonth > 11)
	{
		NowYear += 1;
		NowMonth = 0;	
	}
	
	else
	{
		NowMonth += 1;
	}
	
	temppre();	
	// DonePrinting barrier:
	#pragma omp barrier	
}

}

void Monster()
{
	int currMonster;
	while(NowYear <= 2021)
	{

	currMonster = NowMonster;

	#pragma omp barrier
	//Monsters increase if temp below certain temp in Farhenheit and Number of Deer greater than some threshold value
	if((NowTemp < 30) && (NowNumDeer > 2))
		{
			currMonster += 1;
		} 
	//Monsters decrease if less number of deers
	else if((NowNumDeer < 2))
		{
			currMonster -= 1;
			if (currMonster < 1)
				currMonster = 0;
		}
	else
		{
		}
	
	#pragma omp barrier
	
	NowMonster = currMonster;
	
	#pragma omp barrier
	}
}

void temppre()
{

    float ang = (30.*(float)NowMonth + 15.  ) * ( M_PI / 180. );

    float temp = AVG_TEMP - AMP_TEMP * cos( ang );
    NowTemp = temp + Ranf( -RANDOM_TEMP, RANDOM_TEMP );

    float precip = AVG_PRECIP_PER_MONTH + AMP_PRECIP_PER_MONTH * sin( ang );
    NowPrecip = precip + Ranf( -RANDOM_PRECIP, RANDOM_PRECIP );
    if( NowPrecip < 0. )
        NowPrecip = 0.;

}

int RanInt( int ilow, int ihigh )
{
	float low = (float)ilow;
	float high = (float)ihigh + 0.9999f;

	return (int)(  Ranf(low,high) );
}

float Ranf( float low, float high )
{
	float r = (float) rand();		// 0 - RAND_MAX

	return(   low  +  r * ( high - low ) / (float)RAND_MAX );
}




int main()
{

NowMonth =    0;
NowYear  = 2016;
NowMonster = 0;
NowNumDeer = 1;
NowHeight =  1.;

#ifndef _OPENMP
fprintf(stderr,"OPENMP does not exist\n");
return 1;
#endif

omp_set_num_threads( 4 );
printf("Year\t Month\t NumDeer\t NumPrecip\t NewHeight\t Temperature\t CurrHeight\t NumMonster\n");  
#pragma omp parallel sections

{
	#pragma omp section
	{	GrainDeer();
		
	}

	#pragma omp section
	{
		Grain();
			
	}


	#pragma omp section
	{
		Watcher( );
	}

	#pragma omp section
	{
		Monster();

	}

}
return 0;  
}

