#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;


const int maxn = 1e8 + 5;

int prime[maxn],tot = 0;
bool vis[maxn];
int sum[maxn];
void init(){
	vis[1] = 1;
	for(int i = 2;i < maxn;i++){
		if(!vis[i]){
			prime[++tot] = i;
		}
		for(int j = 1;j <= tot && prime[j] * i < maxn;j++){
			vis[prime[j] * i] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	sum[0] = 0;
	for(int i = 1;i < maxn;i++){
		sum[i] = sum[i - 1] + (vis[i] == 0);
	}
}

typedef long long LL;
LL arr[maxn];
vector<LL> vr;
unordered_map<LL,LL> mp;
LL Sum(LL n){
	if(n < maxn) return sum[n];
	LL r = sqrt(n);
	vr.clear();
	mp.clear();
	for(int i = 1;i <= r;i++){
		vr.push_back(n / i);
	}
	for(int i = vr.back() - 1;i > 0;--i){
		vr.push_back(i);
	}
	int len = vr.size();
	for(int i = 0;i < len;i++){
		arr[i] = vr[i];
		mp[vr[i]] = vr[i] - 1;
	}
	LL sp;
	LL p2;
	for(int i = 2;i <= r;i++){
		if(mp[i] > mp[i - 1]){
			sp = mp[i - 1];
			p2 = 1LL * i * i;
			for(int v = 0;v < len;++v){
				if(arr[v] < p2) break;
				mp[arr[v]] -= (mp[arr[v] / i] - sp);
			}
		}
	}
	return mp[n];
}
LL cal(LL n){
	LL ans = 0;
	int l = 0,r = 30;
	while(l < r){
		int mid = (l + r + 1) / 2;
		LL now = 1;
		for(int i = 1;i <= 7;i++){
			now *= prime[mid]; 
		}
		if(now <= n) l = mid;
		else r = mid - 1;
	}
	ans = r;
	for(int i = 1;i <= tot && 1LL * prime[i] * prime[i] * prime[i] <= n;i++){
		ans += Sum(n / (1LL * prime[i] * prime[i] * prime[i]));	
		if(1LL * prime[i] * prime[i] * prime[i] * prime[i] <= n) ans--;
	}
	for(int i = 1;i <= tot && 1LL * prime[i] * prime[i] * prime[i] <= n;i++){
		for(int j = i + 1;j <= tot && 1LL * prime[i] * prime[j] * prime[j] <= n;j++){
			ans += Sum(n / (1LL * prime[i] * prime[j])) - Sum(prime[j]);
		}
	}
	return ans;
}

int main(){
	double st = clock();
	init();
	cout << Sum(1e12) << endl;
	double en = clock();
	cout << (en - st) / CLOCKS_PER_SEC << endl;
	return 0;
}
