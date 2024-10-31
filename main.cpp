#include <iostream>
#include<vector>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void decom(vector<vector<double> > &A, vector<vector<double> > &L, vector<vector<double> > &U) {
	int n = A.size();
	for(int k=0;k<n;k++) {
		L[k][k] = 1;
		U[k][k] = A[k][k];
		for(int i=k+1;i<n;i++) {
			L[i][k] = A[i][k]/U[k][k];
			U[k][i] = A[k][i];
		}
		for(int i=k+1;i<n;i++) {
			for(int j=k+1;j<n;j++) {
				A[i][j] = A[i][j] - L[i][k]*U[k][j];
			}
		}
	}
}

void solve(vector<vector<double> > &L, vector<vector<double> >&U, vector<double> &b, vector<double> &x) {
	int n = L.size();
	vector<double> y(n,0);
	for(int i=0;i<n;i++) {
		double lySum = 0;
		for(int j=0;j<=i-1;j++) {
			lySum += L[i][j]*y[j];
		} 
		y[i] = b[i] - lySum;
	}
	cout<<"y vector: "<<endl;
	for(int m=0;m<n;m++) {
		cout<<y[m]<<" ";
	}
	for(int i= n-1;i>=0;i--) {
		double uxSum = 0;
		for(int j=i+1;j<n;j++) {
			uxSum += U[i][j] * x[j];
		}
		x[i] = (y[i]-uxSum)/U[i][i];
	}
	cout<<endl;
}

int main(int argc, char** argv) {
	int n = 0;
	cout<<"Enter the dimension of matrix:";
	cin>>n;
	vector<vector<double> > A(n,vector<double>(n,0)); 
	vector<double> b(n,0);
	vector<vector<double> > L(n,vector<double>(n,0));
	vector<vector<double> > U(n,vector<double>(n,0));
	vector<double> x(n,0);
	cout<<"Enter A matrix elements: ";
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>A[i][j];
		}
	}
	cout<<"Enter b vector elements: ";
	for(int i=0;i<n;i++) {
		cin>>b[i];
	}
	decom(A,L,U);
	cout<<"Lower unit triangular matrix (L):"<<endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<L[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Upper triangular matrix (L):"<<endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<U[i][j]<<" ";
		}
		cout<<endl;
	}
	solve(L,U,b,x);
	cout<<"Solution vector(x):"<<endl;
	for(int i=0;i<n;i++) {
		cout<<x[i]<<" ";
	}
	return 0;
}
//2 3 1 5
//6 13 5 19
//2 19 10 23
//4 10 11 31







