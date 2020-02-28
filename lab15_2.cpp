#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findColSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,result,N,M); 
	showData(result,1,M);
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
void findColSum(const double *a,double *b,int N,int M){
	double sum=0;
	for(int i=0;i<N*M;i++){
		sum+=*a;
		if(i%M==M-1){
			*b=sum;
			sum=0;
			b++;
			*(a-=41);
		}else{
			*(a+=M);
		}
	}
}

