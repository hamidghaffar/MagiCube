#include "stdafx.h"
#include <iostream>

using namespace std;

class magicube{
public:
	magicube( int a =5){
		n=5;
		m = new int*[n];
		for(int s=0 ; s<n ; s++)
			m[s] = new int[n];
		for(int ii=0; ii<n ;ii++)
			for (int jj=0 ; jj<n ; jj++)
				m[ii][jj]=0;
		intialize();
		fill();
	};
	void intialize();
	void fill();
	void print();
private:
	void cellfill(int& , int& , int);
	int n;
	int** m ;
};

void magicube::intialize(){
	if(n%2==1){
		m[0][n/2+1]=1;
	}
}

void magicube::fill(){
	int i=0;
	int j=n/2+1;
	for ( int c=2; c<=n*n ; c++){
		cellfill(i,j,c);
	}
}

void magicube::cellfill(int& i , int &j , int c){
	int ii=i;
	int jj=j;
	ii==0 ?	ii=n-1:ii=ii-1;
	jj==0 ?	jj=n-1:jj=jj-1;
	if(m[ii][jj]==0){
		m[ii][jj] = c;
		i=ii;
		j=jj;
	}else{
		i==n-1 ? i=0 : i=i+1 ;
		m[i][j] = c;
	}
}

void magicube::print(){
	for(int ii=0; ii<n ;ii++){
		for (int jj=0 ; jj<n ; jj++){
			if(m[ii][jj]>9) cout<<m[ii][jj]<<"  ";
			else cout<<'0'<<m[ii][jj]<<"  ";
		}
		cout<<endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i;
	cout<<"n = ";
	cin>>i;
	magicube m(i);
	m.print();
	return 0;
}
