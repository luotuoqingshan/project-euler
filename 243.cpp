#include "PE.h"
const int maxn = 1e8 + 5;
int phi[maxn];
void phi_table(int n){
	for(int i = 2;i <- n;i++) phi[i] = 0;
	phi[1] = 1;
	for(int i = 2;i <= n;i++) if(!phi[i])
		for(int j = i;j <= n;j += i){
			if(!phi[j]) phi[j] = j;
			phi[j] = phi[j] / i * (i - 1);
		}
}

int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a % b);
}
int a[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int main(){
	long long d = 1,n = 1;
	for(int i = 0;i < 15;i++){
		
	}
	return 0;
}
