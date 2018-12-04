#include "PE.h"

using namespace std;

vector<int> p = get_primes(5000);
vector<pair<int,int> > c;

typedef long long LL;

const LL N = 1e18;
const LL M = 1e9;

LL qpow(LL a,LL n,int p){
	LL ret = 1;
	while(n > 0){
		if(n & 1) ret = ret * a % p;
		a = a * a % p;
		n >>= 1;
	}
	return ret;
}

LL fac[5005];
LL inv[5005];
int a[10],b[10];

int C(int n,int m,int p){
	if(m > n) return 0;
	return fac[n] * inv[m] % p * inv[n - m] % p;
}

int cal(LL n,LL m,int p){
	fac[0] = 1;	
	for(int i = 1;i < p;i++){
		fac[i] = fac[i - 1] * i % p;
	}
	inv[p - 1] = qpow(fac[p - 1],p - 2,p);
	for(int i = p - 2;i >= 0;i--){
		inv[i] = inv[i + 1] * (i + 1) % p;
	}
	LL tmp = n;
	for(int i = 0;i < 10;i++){
		a[i] = tmp % p;
		tmp /= p;
	}
	tmp = m;
	for(int i = 0;i < 10;i++){
		b[i] = tmp % p;
		tmp /= p;
	}
	int ans = 1;
	for(int i = 0;i < 10;i++){
		ans = ans * C(a[i],b[i],p) % p;
	}
	return ans;
}

LL sum(int i,int j,int k){
	LL all = 1LL * c[i].first * c[j].first * c[k].first;
	LL ret = 0;
	LL Inv = qpow(all / c[i].first,c[i].first - 2,c[i].first);
	ret += c[i].second * Inv * all / c[i].first; 
	Inv = qpow(all / c[j].first,c[j].first - 2,c[j].first);
	ret += c[j].second * Inv * all / c[j].first; 
	Inv = qpow(all / c[k].first,c[k].first - 2,c[k].first);
	ret += c[k].second * Inv * all / c[k].first; 
	return ret % all;
}

void init(){
	for(int i = 0;i < p.size();i++){
		if(p[i] > 1000){
			c.push_back(make_pair(p[i],cal(N,M,p[i])));
		}
	}
	long long ans = 0;
	cout << c.size() << endl;
	for(int i = 0;i < c.size();i++){
		for(int j = i + 1;j < c.size();j++){
			for(int k = j + 1;k < c.size();k++){
				ans += sum(i,j,k);
			}
		}
	}
	cout << ans << endl;
}

int main(){
	init();
	return 0;
}
