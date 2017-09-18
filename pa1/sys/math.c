#include <stdio.h>
#include <math.h>


double log(double x);
double pow(double x, int y);

double expdev(double lambda){

	double dummy;
	do{
 	    dummy = (double) rand()  / RAND_MAX;
	}while(dummy==0.0);
	return -log(dummy)/lambda;
}

double log(double x){
	int i;
	double ans=0.0;
	for(i = 1;i<=20;i++){
	    ans = ans + (pow(x-1,i))*(pow(-1,i+1))/i;
	}
	return ans;
}

double pow(double x, int y){
	double sol = 1.0;
	while(y!=0){
	    if((y&1)==1){
	        sol *=x;
	    }
	    y>>=1;
	    x*=x;
	}
	return sol;
}

