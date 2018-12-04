#include "PE.h"

const int maxn = 10000005;

bool vis[maxn];
long long prime[maxn],tot;
typedef long long LL;
const LL mod = 1000000000;
LL mul(LL a,LL b){
	return 1LL * a * b % mod;
}
void upd(LL &a,LL b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}
LL p3(LL x){
	return mul(mul(x,x),x);
}
LL pre[maxn];
void init(){
	tot = 0;
	vis[1] = 1;
	for(int i = 2;i < maxn;i++){
		if(!vis[i]){
			prime[++tot] = i;
		}
		for(int j = 1;j <= tot && i * prime[j] < maxn;j++){
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0)
				break;
		}
	}
	pre[0] = 0;
	pre[1] = 0;
	for(int i = 2;i < maxn;i++){
		pre[i] = pre[i - 1];
		if(!vis[i]){
			//pre[i] += 1LL * i * i * i;
			upd(pre[i],p3(i));
			//upd(pre[i],1);
		}
	}
}
LL p2(LL a,LL b){
	if(a % 2 == 0) a /= 2;
	else b /= 2;
	a %= mod;
	b %= mod;
	return 1LL * a * b % mod;
}
LL sqr(LL a){
	return 1LL * a * a % mod;
}
#include <unordered_map>
typedef long long LL;
LL arr[maxn];
vector<LL> vr;
unordered_map<LL,LL> mp;
LL cal(LL n){
	if(n < maxn) return pre[n];
	LL r = sqrt(n);
	vr.clear();
	mp.clear();
	for(LL i = 1;i <= r;i++){
		vr.push_back(n / i);
	}
	for(LL i = vr.back() - 1;i > 0;--i){
		vr.push_back(i);
	}
	int len = vr.size();
	for(int i = 0;i < len;i++){
		arr[i] = vr[i];
		mp[vr[i]] = (sqr(p2(vr[i],vr[i] + 1)) + mod - 1) % mod;
	}
	LL sp;
	LL p2;
	for(LL i = 2;i <= r;i++){
		if(!vis[i]){
			sp = mp[i - 1];
			p2 = 1LL * i * i;
			for(int v = 0;v < len;++v){
				if(arr[v] < p2) break;
				upd(mp[arr[v]],-mul(p3(i),(mp[arr[v] / i] - sp + mod) % mod));
			}
		}
	}
	return mp[n];
}



LL solve(LL n){
	LL ans = 0;
	for(int i = 1;i <= tot && 1LL * prime[i] * prime[i] <= n;i++){
		LL tmp = p3(prime[i]);
		tmp = mul(tmp,(cal(n / prime[i]) - cal(prime[i]) + mod) % mod);	
		upd(ans,tmp);
	}
	return ans;
}

int main(){
	init();
	double st = clock();
	cout << solve(1e2) << endl;
	cout << solve(1e4) << endl;
	cout << solve(1e12) << endl;
	double ed = clock();
	cout << (ed - st) / CLOCKS_PER_SEC << endl;
	return 0;
}



