#include "PE.h"

const int maxn = 1e8 + 5;
bool vis[maxn];

LL n;
vector<int> primes;

int gcd(int a,int b){
	return b == 0 ? a : gcd(b,a % b);
}

int main(){
	cin >> n;
	vis[1] = 1;

	for(int i = 2;i < maxn;i++){
		if(!vis[i]){
			primes.push_back(i);
			for(int j = 2 * i;j < maxn;j += i){
				vis[j] = 1;
			}
		}
	}
	LL ans = 0;
	for(int i = 1;i < n;i++){
		for(int j = 1;j < n;j++){
			LL a = 1LL * i * j * j - 1;
			if(a >= n)
				break;
			if(vis[a]) continue;
			for(int k = j + 1;k < n;k++){
				if(gcd(j,k) != 1)
					continue;
				LL b = 1LL * i * j * k - 1;
				LL c = 1LL * i * k * k - 1;
				if(c >= n)
					break;
				if(!vis[b] && !vis[c]){
					ans += (a + b + c);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
