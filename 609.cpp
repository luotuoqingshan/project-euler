#include "PE.h"

const int maxn = 1e8 + 5;

int prime[maxn],tot;
int vis[maxn];
int sum[maxn];
int len[maxn];
int dp[maxn];
int inv[maxn];
const int mod = 1e9 + 7;

void init(){
	inv[1] = 1;
	for(int i = 2;i < maxn;i++)
		inv[i] = (mod - mod / i) * 1LL * inv[mod % i] % mod;	
	vis[1] = 1;
	tot = 0;
	for(int i = 2;i < maxn;i++){
		if(!vis[i]){
			prime[++tot] = i;
		}
		for(int j = 1;j <= tot && i * prime[j] < maxn;j++){
			vis[i * prime[j]] = 1;
			
			if(i % prime[j] == 0) break;
		}
	}
	sum[0] = 0;
	for(int i = 1;i < maxn;i++){
		sum[i] = sum[i - 1] + (!vis[i]);
	}
/*	len[0] = 0;
	for(int i = 1;i < maxn;i++){
		len[i] = len[sum[i]] + 1;
	}*/
}

typedef long long LL;


long long cal(int x){
	long long ans = 1;
	for(int i = 1;i <= x;i++){
		int tmp = i;
		int now = vis[tmp];
		while(tmp > 0){
			tmp = sum[tmp];
			if(tmp == 0) break;
			if(vis[tmp]) now++;
			dp[now]++;
		}		
	}
	for(int i = 0;i <= x;i++){
		if(dp[i] > 0) ans = (ans * dp[i]) % mod;
	}
	return ans;
}

int main(){
	init();
	cout << cal(100000000) << endl;
	return 0;
}
