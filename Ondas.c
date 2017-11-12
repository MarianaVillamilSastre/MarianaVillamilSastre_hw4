#include <stdio.h>
#include <math.h>
#include <stdlib.h>



void Fijos(void){
float c=250.0;
int nx=129.0;
int t=100000.0;
int nt;
double*x=malloc(nx*sizeof(double));
double*y=malloc(nx*sizeof(double));

FILE*datos=fopen("cond_ini_cuerda.dat", "r");
int i;
for (i=0;i<nx;i++){
	fscanf(datos,"%lf %lf\n", &x[i],&y[i]);
	printf("%lf\n",x[i]);

}

fclose(datos);


FILE*myfile=fopen("datos.dat","w");

double * u=malloc(nx*sizeof(double));
double * u_inicial=malloc(nx*sizeof(double));
double * u_siguiente=malloc(nx*sizeof(double));

for(i=0;i<nx;i++){
		u_inicial[i]=y[i];}

int j;
double dx=0.005;
double dt=(0.1*dx)/c;
double r=c*dt/dx;
for (i=1;i<nx-1;i++){
	u[i]=u_inicial[i] + pow(r,2)*0.5*(u_inicial[i+1]-2*u_inicial[i]+u_inicial[i-1]);}

for(j=1;j<t;j++)
{
	
	for (i=1;i<nx-1;i++){

		u_siguiente[i]=2*(1-pow(r,2))*u[i] - u_inicial[i] + pow(r,2)*(u[i+1]+ u[i-1]);}
		
	int m;
	for(m=1;m<nx;m++){
		u_inicial[m]=u[m];
		u[m]=u_siguiente[m];
				
}

	if(j==t/2 | j==t/4 | j==t/8)
	{
		
		for(i=0;i<nx;i++)
		{	
			fprintf(myfile,"%f ",u_siguiente[i]);
		} 

		fprintf(myfile,"\n");}
	}


}









void perturbado(void){
float c=250.0;
int nx=129.0;
int t=100000.0;
int nt;
double*x=malloc(nt*sizeof(double));
double*y=malloc(nt*sizeof(double));




FILE*myfile=fopen("sen.dat","w");

double * u=malloc(nx*sizeof(double));
double * u_inicial=malloc(nx*sizeof(double));
double * u_siguiente=malloc(nx*sizeof(double));

int i;
for(i=0;i<nx;i++){
		u_inicial[i]=0;
		u[i]=0;}

int j;
double dx=0.005;
double dt=(0.1*dx)/c;
double r=c*dt/dx;
for (i=1;i<nx-1;i++){
	u[i]=u_inicial[i] + pow(r,2)*0.5*(u_inicial[i+1]-2*u_inicial[i]+u_inicial[i-1]);}

for(j=1;j<t;j++)
{
	
	for (i=1;i<nx-1;i++){

		u_siguiente[i]=2*(1-pow(r,2))*u[i] - u_inicial[i] + pow(r,2)*(u[i+1]+ u[i-1]);
		
		}

		u_siguiente[nx-1]=sin((2*3.1415*c/0.64)*(j*dt));
		
	int m;
	for(m=1;m<nx;m++){
		u_inicial[m]=u[m];
		u[m]=u_siguiente[m];
				
}

	if(j==t/2 | j==t/4 | j==t/8)
	{
		
		for(i=0;i<nx;i++)
		{	
			fprintf(myfile,"%f ",u_siguiente[i]);
		} 

		fprintf(myfile,"\n");}
	}


}





void Audios(void){
float c=250.0;
int nx=129.0;
int t=100000.0;
int nt;
double*x=malloc(nx*sizeof(double));
double*y=malloc(nx*sizeof(double));

FILE*datos=fopen("cond_ini_cuerda.dat", "r");
int i;
for (i=0;i<nx;i++){
	fscanf(datos,"%lf %lf\n", &x[i],&y[i]);
	printf("%lf\n",x[i]);

}

fclose(datos);


FILE*myfile1=fopen("audios.dat","w");

double * u=malloc(nx*sizeof(double));
double * u_inicial=malloc(nx*sizeof(double));
double * u_siguiente=malloc(nx*sizeof(double));

for(i=0;i<nx;i++){
		u_inicial[i]=y[i];}

int j;
double dx=0.005;
double dt=(0.1*dx)/c;
double r=c*dt/dx;
for (i=1;i<nx-1;i++){
	u[i]=u_inicial[i] + pow(r,2)*0.5*(u_inicial[i+1]-2*u_inicial[i]+u_inicial[i-1]);}

for(j=1;j<t;j++)
{
	
	for (i=1;i<nx-1;i++){

		u_siguiente[i]=2*(1-pow(r,2))*u[i] - u_inicial[i] + pow(r,2)*(u[i+1]+ u[i-1]);}
		
	int m;
	for(m=1;m<nx;m++){
		u_inicial[m]=u[m];
		u[m]=u_siguiente[m];
				
}

	if(j%100==0)
	{
		
		fprintf(myfile1,"%f ",u_siguiente[nx/2]);}



	}
	
	
}



int main(void){
	Fijos();
	perturbado();
	Audios();
	return 0;

}










