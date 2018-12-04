#include "PE.h"

const int maxn = 64000000 + 5;

long long d[maxn];

int main(){
	for(int i = 1;i < maxn;i++){
		for(int j = i;j < maxn;j += i){
			d[j] += 1LL * i * i; 
		}
	}
	long long ans = 0;
	for(int i = 1;i < 64000000LL;i++){
		long long x = (long long)sqrt(d[i]);
		if(1LL * x * x == d[i]){
			ans += i;
		}
	}
	cout << ans << endl;
	return 0;
}
