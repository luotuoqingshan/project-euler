#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

const int N = 1e8 + 5;
const int mod = 1e9;
typedef long long LL;
int prime[N],tot;
bool vis[N];
int mu[N];
int miu[N];
int sz[N],sum[N],pr[N];
int mul(LL a,LL b){
	if(a & 1) b /= 2;
	else a /= 2;
	a %= mod;b %= mod;
	return 1LL * a * b % mod;
}

inline void upd(int &a,int b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

void init(){
	vis[1] = 1;
	mu[1] = 1;
	sum[1] = 1;
	sz[1] = 1;
	miu[1] = 1;
	pr[1] = 1;
	for(int i = 2;i < N;i++){
		if(!vis[i]){
			prime[++tot] = i;
			mu[i] = -1;
			sum[i] = 1 + i;
			pr[i] = 1 + i;
			sz[i] = i;
		}
		for(int j = 1;j <= tot && i * prime[j] < N;j++){
			vis[i * prime[j]] = 1;
			if(i % prime[j]){
				mu[i * prime[j]] = -mu[i];
				sz[i * prime[j]] = prime[j];
				pr[i * prime[j]] = 1 + prime[j];
				sum[i * prime[j]] = 1LL * sum[i] * (1 + prime[j]) % mod;
			}else{
				mu[i * prime[j]] = 0;
				sz[i * prime[j]] = sz[i] * prime[j];
				pr[i * prime[j]] = (1LL * pr[i] * prime[j] + 1) % mod; 
				sum[i * prime[j]] = sum[i * prime[j] / sz[i * prime[j]]] * 1LL * pr[i * prime[j]] % mod;
				break;
			}
		}
		miu[i] = i * mu[i];
	}
	for(int i = 2;i < N;i++){
		upd(miu[i],miu[i - 1]);
		upd(sum[i],sum[i - 1]);
	}
}

map<LL,int> u;

int Miu(long long n){
	if(n < N) return miu[n];
	if(u.count(n)) return u[n];

	int ret = 1;
	for(LL i = 2,j;i <= n;i = j + 1){
		j = min(n,n / (n / i));
		upd(ret,-1LL * mul(i + j,j - i + 1) * Miu(n / i) % mod);
	}
	u[n] = ret;
	return ret;
}


map<LL,int> sigma;

int Sigma(long long n){
	if(n < N) return sum[n];
	if(sigma.count(n) == 1) return sigma[n];

	int ret = 0;
	for(LL i = 1,j;i <= n;i = j + 1){
		j = min(n,n / (n / i));
		upd(ret,1LL * mul(i + j,j - i + 1) * ((n / i)%mod) % mod);
	}
	sigma[n] = ret;
	return ret;
}


int solve(LL M){
	int ans = 0;
	for(LL i = 1,j;i <= M;i = j + 1){
		j = min(M,M / (M / i));
		int tmp = 0;
		upd(tmp,Miu(j));upd(tmp,-Miu(i - 1));
		int ss = Sigma(M / i);
		ss = 1LL * ss * ss % mod;
		tmp = 1LL * tmp * ss % mod;
		upd(ans,tmp);
	}	
	return ans;
}


int main(){
	init();
	cout << solve((LL)1e11) << endl;
	return 0;
}
