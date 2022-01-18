#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void randData(double *q, int N, int M)
{
	for(int i=0; i < N*M; i++)
	{
		q[i] = (rand()%101)/100.00;
	}
}
void showData(double *w,int N,int M)
{
	cout << fixed << setprecision(2);
	for(int i=0; i < N*M; i++)
	{
		cout << w[i];
		if((i+1)%M == 0)
		cout << endl;
		else cout << " ";
	}
}
void findRowSum(const double *a,double *b,int N,int M){
	double sum1 = 0.00;
	for(int i=0; i<N ; i++){
		for(int j=0; j<M ; j++){
			sum1 = sum1 + *(a+j+i*M);
		}
		*(b+i)=sum1;
		sum1=0;
	}
}
void findColSum(const double *Z,double *X,int C,int V)
{
	if(C == 1)
	{
		for(int i=0; i<V; i++)
		{
			X[i] = Z[i]; 
		}
	}else
	{
		for(int j = 0; j<C*V; j++)
		{
			X[j % V] = X[j % V] + Z[j];
		}
		for(int k = 0; k<V; k++)
		{
			X[k] = 0;
		}
		for(int m = 0; m<C*V; m++)
		{
			X[m%V] = X[m%V] + Z[m];
		}
	}
}