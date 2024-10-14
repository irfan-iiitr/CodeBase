#include <bits/stdc++.h> 
#define MOD 1000000007
#define ll long long 

void multiply(ll m[2][2], ll temp[2][2]){
	ll a= (m[0][0]*temp[0][0]+ m[0][1]*temp[1][0])%MOD;
	ll b= (m[0][0]*temp[0][1]+ m[0][1]*temp[1][1])%MOD;
	ll c= (m[1][0]*temp[0][0]+ m[1][1]*temp[1][0])%MOD;
	ll d= (m[1][0]*temp[0][1]+ m[1][1]*temp[1][1])%MOD;

	m[0][0]=a;
	m[0][1]=b;
	m[1][0]=c;
	m[1][1]=d;
}

void power(ll m[2][2],ll n){
	if(n==0 or n==1) return ;

	ll temp[2][2]= {{1,1},{1,0}};

	power(m,n/2);
	multiply(m,m);

	if(n%2==1){
		multiply(m,temp);
	}


}

ll fib(ll n){
	if(n==0) return 0;

	ll m[2][2]= {{1,1},{1,0}};
	power(m,n-1);
	return m[0][0];
}

long long fibSum(ll n){
	return (fib(n+2)-1  +MOD)%MOD;
}
int fiboSum(int n , int m)
{
	// Write your code here

	long long sumn=n==0? 0: fibSum(n-1);
	long long summ=fibSum(m);
	return (summ-sumn +MOD)%MOD;
}
