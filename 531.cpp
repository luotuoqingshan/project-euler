#include "PE.h"

int gcd(int a,int b){
	return b == 0 ? a : gcd(b,a % b);
}


int qpow(int a,int n,int mod){
	int ret = 1;
	while(n > 0){
		if(n & 1)
			ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
		n >>= 1;
	}
	return ret;
}
vector<int> phi = get_phi(1005005);
void extgcd(LL a,LL b,LL& d,LL& x,LL& y){  
    if(!b){ d=a; x=1; y=0;}  
    else{ extgcd(b,a%b,d,y,x); y-=x*(a/b); }  
}  
LL inverse(LL a,LL n){  
    LL d,x,y;  
    extgcd(a,n,d,x,y);  
    return d==1?(x+n)%n:-1;  
}  


long long g(int a,int n,int b,int m){
	int G = gcd(n,m);
	if((a - b) % G) return 0;
	int nn = n / G,mm = m / G;
	int c = b - a;
	c /= G;
	LL inv = inverse(nn,mm);
	long long N = 1LL * n * m / G;
	return ((1LL * n * c % N * inv % N + a) % N + N) % N;
}

int main(){
	long long sum = 0;
	for(int n = 1000000;n < 1005000;n++){
		for(int m = n + 1;m < 1005000;m++){
			sum += g(phi[n],n,phi[m],m);
		}
	}
	cout << sum << endl;
	return 0;
}
