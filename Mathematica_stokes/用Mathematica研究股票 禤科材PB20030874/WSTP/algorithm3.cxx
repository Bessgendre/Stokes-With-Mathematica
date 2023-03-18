#include "wstp.h"
#include "other.h"

void algorithm3(double *b, long blen, double *h, long hlen, double *l, long llen, double *e, long elen, double *huan, long huanlen,int time, double ratio1,double ratio2,double ratio3,double ratio4)
{
	int i=0,n=0,A=2,k=0,n1=0,n2=0,day=0,kx=0;
	double Account=100000,shizhi=0,di=0,gao=0,di1=0,gao1=0,chazhi=0;
	double huanjun[300],i1=0,i2=0;
	double k1=1.17,k2=0,k3=0,a[250],a1[250];

	for(day=249;day>=6;day=day-1)
	{
		for(k1=0;k1<=2.0;k1=k1+0.01)
		{
			i=day+1;shizhi=300000;Account=100000;
			n=0;n1=0;n2=0;A=2;

			while(i>day-time) //这个5
	        {
				i=i-1;
				di1=0.04;gao1=0.04;
	        	if(i<=245)
				{
	        		huanjun[i]=huan[i+1]*ratio1+huan[i+2]*ratio2+huan[i+3]*ratio3+huan[i+4]*ratio4;   
					/*加权比*/

					di1=double(int(k1*huanjun[i]*50)/100.0)+ 
					int(k1*k1*STDEVP(b[i],h[i+1],l[i+1],b[i+1],e[i+1])*10)/100.0;    
					/*50和10*/

					gao1=double(int(k1*huanjun[i]*50)/100.0)+
					int(k1*k1*STDEVP(b[i],h[i+1],l[i+1],b[i+1],e[i+1])*10)/100.0+
					int(k1*k1*(b[i]-0.4*e[i+1]-0.3*b[i+1]-0.2*e[i+2]-0.1*b[i+2])*15)/100.0;   
					/*50、10、15*/
				
					if(huanjun[i]<=0.11){continue;}
					if(huanjun[i]>=0.25){di1=di1+0.02;gao1=gao1+0.02;}
		        }   /*0.11、0.25、0.02、0.02*/

		   		di=b[i]-di1;gao=b[i]+gao1;
				if(A==2 && l[i]<=di)
				{
					n=int(Account/2.0/di/100.0);
					Account=Account-n*di*100.0;
					A=A-1;
					continue;
				}
				if(A==0&&h[i]>=gao)
				{
		    		Account=Account+int(n/2)*gao*100.0*0.995;
		    		n=n-int(n/2);
					A=A+1;
					continue;
				}
				if(A==1)
				{
					if(h[i]>=gao&&l[i]<=di)
					{//half sell and buy
						n2=n;
						n1=int(Account/di/100.0);
						n=n1;
						Account=Account+n2*gao*100.0*0.995-n1*di*100;
						A=A	;	
		    		} 
		    		if(h[i]>=gao&&l[i]>di)
					{//half sell
		    			Account=Account+n*gao*100*0.995;
		    			n=0;
		    			A=A+1;	
		    		} 
		    		if(h[i]<gao&&l[i]<=di)
					{//half buy
		    			n=n+int(Account/di/100.0);
		    			Account=Account-int(Account/di/100.0)*di*100;
		    			A=A-1;		
		    		} 
					continue;
				}
			
	        } 
	       shizhi = Account + n*e[i]*100.0;
	       a1[int(100*k1)]=shizhi;
		}
		a[day-(time+1)]=zuidazhi(a1);
	}



	// WSPutReal64List(stdlink,a,250);
	
	
	
	
	
	
	i=200;shizhi=100000;Account=100000;n=0;n1=0;n2=0;A=2;

	while(i>=5)
	{
		i=i-1;di1=0.04;gao1=0.04;k1=a[i];
		if(i<=245)
		{
			if(((i+2)/5.0-double(int((i+2)/5)))==0)
			{
				continue;
			}
			huanjun[i]=(huan[i+1]*ratio1+huan[i+2]*ratio2+huan[i+3]*ratio3+huan[i+4]*ratio4);
			di1=double(int(k1*huanjun[i]*50)/100.0)+ 
			int(k1*k1*STDEVP(b[i],h[i+1],l[i+1],b[i+1],e[i+1])*10)/100.0;
			gao1=double(int(k1*huanjun[i]*50)/100.0)+
			int(k1*k1*STDEVP(b[i],h[i+1],l[i+1],b[i+1],e[i+1])*10)/100.0+
			int(k1*k1*(b[i]-0.4*e[i+1]-0.3*b[i+1]-0.2*e[i+2]-0.1*b[i+2])*20)/100.0;
			if(huanjun[i]<=0.11){continue;}
			if(huanjun[i]>=0.25){di1=di1+0.03;gao1=gao1+0.06;}
		}
		di=b[i]-di1;gao=b[i]+gao1;
		if(A==2&&l[i]<=di)
		{ 
			n=int(Account/2.0/di/100.0);
			Account=Account-n*di*100.0;
			A=A-1;
			shizhi=Account+n*e[i]*100.0;
			// printf("%lf    %lf    %lf    %lf   %d %d  %lf  %lf   %lf\n",b[i],h[i],l[i],e[i],A,i,(h[i]-gao),(di-l[i]),shizhi);
			continue;
		}
		if(A==0&&h[i]>=gao)
		{ 
			Account=Account+int(n/2)*gao*100.0*0.9985;
			n=n-int(n/2);
			A=A+1;
			shizhi=Account+n*e[i]*100.0;
			// printf("%lf    %lf    %lf    %lf   %d %d  %lf  %lf   %lf\n",b[i],h[i],l[i],e[i],A,i,(h[i]-gao),(di-l[i]),shizhi);
			continue;
		}
		if(A==1)
		{
			if(h[i]>=gao&&l[i]<=di)
			{//half sell and buy
				n2=n;
				n1=int(Account/di/100.0);
				n=n1;
				Account=Account+n2*gao*100.0*0.9985-n1*di*100;
				A=A	;	
			} 
			if(h[i]>=gao&&l[i]>di)
			{//half sell
				Account=Account+n*gao*100*0.9985;
				n=0;
				A=A+1;	
			} 
			if(h[i]<gao&&l[i]<=di)
			{//half buy
				n=n+int(Account/di/100.0);
				Account=Account-int(Account/di/100.0)*di*100;
				A=A-1;		
			} 
			shizhi=Account+n*e[i]*100.0;
			// printf("%lf    %lf    %lf    %lf   %d %d  %lf  %lf   %lf\n",b[i],h[i],l[i],e[i],A,i,(h[i]-gao),(di-l[i]),shizhi);
			continue;
		}
		shizhi=Account+n*e[i]*100.0;
		// printf("%lf    %lf    %lf    %lf   %d %d  %lf  %lf   %lf\n",b[i],h[i],l[i],e[i],A,i,(h[i]-gao),(di-l[i]),shizhi);
	}

	shizhi=Account+n*e[i]*100.0;
	       
    WSPutReal64(stdlink, shizhi);
	return;
}

int main(int argc, char **argv)
{
	return WSMain(argc, argv);
}
