#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[N] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,result,N,M);
	showData(result,N,1);
}

void randData(double *a,int N,int M){
	for(int i=0;i<N*M;i++){
		*a=(rand()%100)/100.0;
		*a++;
	}
}
void showData(double *a,int N,int M){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout << *a << " ";
			*a++;
		}
		cout << endl;
	}	
} 
void findRowSum(const double *a,double *b,int N,int M){
	double sum=0;
	for(int i=0;i<N;i++){
		sum=0;
		for(int j=0;j<M;j++){
			sum+= *a;
			a++;
			*b=sum;
		}
		b++;
	}
}
