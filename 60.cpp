#include "PE.h"

vector<int> p = get_primes(50000);

const int maxn = 1e8 + 5;
int prime[maxn];
int tot = 0;
bool vis[maxn];

void init(){
	vis[1] = 1;
	for(int i = 2;i < maxn;i++){
		if(vis[i] == 0){
			prime[++tot] = i;
		}
		for(int j = 1;j <= tot && i * prime[j] < maxn;j++){
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0)
				break;
		}
	}
}

bool isprime(long long a){
	for(int i = 0;i < p.size() && 1LL * p[i] * p[i]	<= a;i++){
		if(a % p[i] == 0)
			return 0;
	}
	return 1;
}

bool check(int a,int b){
	int temp[20];
	int k = 0;
	while(a > 0){
		temp[k++] = a % 10;
		a /= 10;
	}
	while(b > 0){
		temp[k++] = b % 10;
		b /= 10;
	}
	long long now = 0;
	for(int i = k - 1;i >= 0;i--){
		now = now * 10 + temp[i];
	}
	if(k > 8) return isprime(now);
	else return !vis[now];
}

vector<int> g[50005];

void init1(){
	for(int i = 0;i < p.size();i++){
		for(int j = i + 1;j < p.size();j++){
			if(check(p[i],p[j]) && check(p[j],p[i])) g[i].push_back(j);
		}
	}
}

int main(){
	init();
	init1();
	int n = p.size();
	for(int i = 0;i < n;i++){
		for(auto j : g[i]){
			for(auto k : g[j]){
				if(check(p[i],p[k]) == 0 || check(p[k],p[i]) == 0) break;
				for(auto l : g[k]){
					if(check(p[l],p[j]) == 0 || check(p[j],p[l]) == 0) break;
					if(check(p[l],p[i]) == 0 || check(p[i],p[l]) == 0) break;
					for(auto m : g[l]){
						if(check(p[m],p[j]) == 0 || check(p[j],p[m]) == 0) break;
						if(check(p[k],p[m]) == 0 || check(p[m],p[k]) == 0) break;
						if(check(p[m],p[i]) == 0 || check(p[i],p[m]) == 0) break;
						int sum = p[i] + p[j] + p[k] + p[l] + p[m];
						cout << sum << endl;
					}
				}
			}
		}
	}

	return 0;
}
