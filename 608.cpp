#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;


const int N = 1e8 + 5;
const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;
typedef long long LL;
int num[N];
int prime[N],tot;
bool vis[N];
int sz[N];
int size[N];
void upd(int &a,int b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}
int qpow(int a,int n){
	int ret = 1;
	while(n > 0){
		if(n & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
		n >>= 1;
	}
	return ret;
}
void init(){
	vis[1] = 1;num[1] = 1;size[1] = 1;
	for(int i = 2;i < N;i++){
		if(!vis[i]){
			prime[++tot] = i;
			sz[i] = 1;
			num[i] = 2;
		}
		for(int j = 1;j <= tot;j++){
			if(1LL * i * prime[j] >= N) break;
			vis[i * prime[j]] = 1;
			if(i % prime[j]){
				sz[i * prime[j]] = 1;
				num[i * prime[j]] = num[i] * 2;	
			}else{
				sz[i * prime[j]] = sz[i] + 1;
				num[i * prime[j]] = num[i] / sz[i * prime[j]] * (sz[i * prime[j]] + 1);	
				break;
			}
		}
		
	}

	for(int i = 1;i < N;i++){
		size[i] = num[i];
		upd(num[i],num[i - 1]);
	}
}

int times[205];
int res;

int mul2(int a,int b){
	return 1LL * a * b % mod * inv2 % mod;
}
const int jj = 200;

void caltimes(){
	for(int i = 1;i <= jj;i++){
		if(vis[i]) continue;
		for(int j = i;j <= jj;j *= i){
			times[i] += jj / j;
		}	
		times[i] %= mod;
	}
	res = 1;
	for(int i = 1;i <= jj;i++){
		if(vis[i]) continue;
		res = 1LL * res * mul2(times[i] + 1,times[i] + 2) % mod;
	}	
}
map<LL,int> sigma;

int Sigma(long long x){
	if(x < N) return num[x];
	if(sigma.count(x) == 1) return sigma[x];
	int ret = 0;
	for(long long i = 1,j;i <= x;i = j + 1){
		j = min(x,x / (x / i));
		upd(ret,1LL * (j - i + 1) % mod * ((x / i) % mod) % mod);
	}	
	sigma[x] = ret;
	return ret;
}

int ans;

long long now = 1000000000000LL;
void dfs(int n,long long mul,int num,long long sub){
	if(mul > now) return;
	if(n > 46){
		long long tmp = 1;
		if(num & 1) tmp = -1;
		tmp = (tmp * Sigma(now / mul) % mod + mod) % mod;
		tmp = tmp * res % mod * sub % mod;
		upd(ans,tmp);
		return;
	}	
	dfs(n + 1,mul,num,sub);
	dfs(n + 1,mul * prime[n],num + 1,sub * mul2(times[prime[n]],times[prime[n]] + 1) % mod * qpow(mul2(times[prime[n]] + 1,times[prime[n]] + 2),mod - 2) % mod);
}

int duipai(){
	int x = 1;
	for(int i = 1;i <= jj;i++){
		x *= i;
	}
	cout << x << endl;
	int ret = 0;	
	for(int i = 1;i <= x;i++){
		if(x % i != 0) continue;
		for(int j = 1;j <= now;j++){
			upd(ret,size[i * j]);
		}
	}
	return ret;
}

int main(){
	init();
	caltimes();
	//cout << duipai() << endl;
	ans = 0;
	dfs(1,1LL,0,1);
	cout << ans << endl;
	return 0;
}
