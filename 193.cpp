#include "PE.h"


const int maxn = (1 << 25) + 5;

int mu[maxn];
int prime[maxn],tot;
bool vis[maxn];

void init(){
	tot = 0;
	vis[1] = 0;
	mu[1] = 1;
	for(int i = 2;i < maxn;i++){
		if(!vis[i]){
			prime[tot++] = i;
			mu[i] = -1;
		}
		for(int j = 0;j < tot && 1LL * i * prime[j] < maxn;j++){
			vis[prime[j] * i] = 1;
			if(i % prime[j]){
				mu[i * prime[j]] = -mu[i];
			}else{
				mu[i * prime[j]] = 0;
				break;
			}
		}
	}
}

int main(){
	init();
	long long ans = 0;
	long long n = (1LL << 50);
	for(int i = 1;i < maxn;i++){
		ans += mu[i] * (n / (1LL * i * i));
	}
	cout << ans << endl;
	return 0;
}
