#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;

int gcd(int a,int b){
	return b == 0 ? a : gcd(b,a % b);
}

LL gcd(LL a,LL b){
	return b == 0 ? a : gcd(b,a % b);
}

bool is_prime(int x){
	if(x == 1) return 0;
	for(int i = 2;i * i <= x;i++){
		if(x % i == 0) return 0;
	}	
	return 1;
}

bool is_prime(long long x){
	if(x == 1) return 0;
	for(int i = 2;i * i <= x;i++){
		if(x % i == 0) return 0;
	}
	return 1;
}

vector<int> get_primes(int n){
	vector<int> vis(n + 1);
	vis[0] = 1;
	vis[1] = 1;
	vector<int> primes;
	for(int i = 2;i <= n;i++){
		if(!vis[i]){
			primes.push_back(i);
		}
		for(int j = 0;j < primes.size() && 1LL * i * primes[j] <= n;j++){
			vis[i * primes[j]] = 1;
			if(i % primes[j] == 0)
				break;
		}
	}
	return primes;
}

vector<int> get_phi(int n){
	vector<int> vis(n + 1,0);
	vector<int> phi(n + 1);
	for(int i = 2;i <= n;i++)
		phi[i] = i;
	for(int i = 2;i <= n;i++){
		if(!vis[i]){
			phi[i] = phi[i] / i * (i - 1);
			for(int j = 2 * i;j <= n;j += i){
				vis[j] = 1;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
	return phi;
}

LL MUL(LL x,LL y,LL m){
	LL c,s = 0;
	for(c = x % m;y;c = (c + c) % m,y >>= 1){
		if(y & 1) s = (s + c) % m;
	}
	return s;
}

LL POW(LL x,LL y,LL m){
	LL c,s = 1;
	for(c = x % m;y;c = MUL(c,c,m),y >>= 1)
		if(y & 1) s = MUL(s,c,m);
	return s;
}

vector<vector<LL> > Fac(LL n, LL mod){
	vector<vector<LL> > ret;
	vector<LL> fac(n + 1), inv(n + 1);
	fac[0] = 1;
	for(int i = 1;i <= n;i++){
		fac[i] = fac[i - 1] * i % mod;
	}
	inv[n] = POW(fac[n], mod - 2, mod);
	for(int i = n - 1;i >= 0;i--){
		inv[i] = inv[i + 1] * (i + 1) % mod;
	}
	ret.push_back(fac);
	ret.push_back(inv);
	return ret;
}

bool miller_rabin(LL num){
	if(num <= 1) return false;
	if(num <= 3) return true;
	if(~num & 1) return false;
	const int u[] = {2,3,5,7,11,13,17,19,23,29,0};
	LL e = num - 1,a,c = 0;
	while(~e&1) e/=2,c++;
	for(int i = 0;u[i];i++){
		if(num <= u[i]) return true;
		a = POW(u[i],e,num);
		if(a == 1) continue;
		for(int j = 1;a != num - 1;j++){
			if(j == c) return false;
			a = MUL(a,a,num);
		}
	}
	return true;
}


void extgcd(LL a,LL b,LL& d,LL& x,LL& y){  
    if(!b){ d=a; x=1; y=0;}  
    else{ extgcd(b,a%b,d,y,x); y-=x*(a/b); }  
}  

LL inverse(LL a,LL n){  
    LL d,x,y;  
    extgcd(a,n,d,x,y);  
    return d==1?(x+n)%n:-1;  
}  


long long CRT(int a,int n,int b,int m){
	int G = gcd(n,m);
	if((a - b) % G) return -1; 
	int nn = n / G,mm = m / G;
	int c = b - a;
	c /= G;
	LL inv = inverse(nn,mm);
	long long N = 1LL * n * m / G;
	return ((1LL * n * c % N * inv % N + a) % N + N) % N;
}
