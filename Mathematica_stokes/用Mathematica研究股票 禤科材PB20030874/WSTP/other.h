#include<math.h>
#include <stdio.h>

double zuidazhi(double a[250]){
	double zuida=0,x;
	int i;
	for(i=0;i<=249;i++){
		if(zuida<=a[i]){
			zuida=a[i];
		}
	}
	for(i=0;i<=249;i++){
		if(zuida==a[i]){
			x=i*0.01;return(x);
		}
		
	}
return(0);
}
double STDEVP(double a,double b,double c,double d,double e){
	double evp,ave;
	ave=(a+b+c+d+e)/5.0;
	evp=0;
	evp=evp+(a-ave)*(a-ave)+(b-ave)*(b-ave)+(c-ave)*(c-ave)
	+(d-ave)*(d-ave)+(e-ave)*(e-ave);
	evp=evp*0.2;
	evp=sqrt(evp);
	
	return(evp);
}