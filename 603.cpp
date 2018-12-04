#include "PE.h" 

typedef long long LL;
const LL mod = 1e9 + 7;


LL qpow(LL a,LL n){
	LL ret = 1;
	while(n > 0){
		if(n & 1) ret = ret * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}

LL i9 = qpow(9LL,mod - 2);
LL i10 = qpow(10LL,mod - 2);

vector<int> p = get_primes(20000000);

int s[10000005];
int tot = 0;

void solve(LL n,LL m){
	tot = 0;
	for(int i = 0;i < n;i++){
		int tmp = p[i];
		int now = tot;
		while(tmp > 0){
			s[++tot] = tmp % 10;
			tmp /= 10;
		}
		reverse(s + now + 1,s + tot + 1);
	}
	/*for(int i = 1;i <= m;i++){
		for(int j = 1;j <= tot;j++){
			s[(i - 1) * tot + j] = s[j];
		}
	}*/
	//cout << tot << endl;
	LL ans = 0;
	LL x = m,y = (m - 1);
	if(x & 1) y /= 2;
	else x /= 2;
	x %= mod,y %= mod;
	LL val = x * y % mod;
	for(int i = 1;i <= tot;i++){
		LL power = (m  % (mod - 1) * tot % (mod - 1)- i + 1 + (mod - 1)) % (mod - 1);
		LL v1 = qpow(10LL,power);
		v1 = v1 * s[i] % mod;
		LL v2 = v1 * i % mod;
		LL a = qpow(i10,tot);
		LL b = qpow(a,m);
		LL v3 = (b + mod - 1) % mod;
		v3 = v3 * qpow((a - 1 + mod) % mod,mod - 2) % mod;
		v3 = v2 * v3 % mod;
		LL v4 = (m - 1) % mod * tot % mod * qpow(i10,m % (mod - 1) * tot) % mod;
		v4 = (v4 - tot % mod * ((qpow(i10,m % (mod - 1) * tot) - qpow(i10,tot) + mod) % mod) % mod * qpow((qpow(i10,tot) + mod - 1) % mod,mod - 2) % mod + mod) % mod;
		v4 = v4 * qpow((qpow(i10,tot) + mod - 1) % mod,mod - 2) % mod;
		v4 = v1 * v4 % mod;
		LL v5 = 1LL * s[i] * i % mod * (m % mod) % mod;
		LL v6 = val % mod * tot % mod * s[i] % mod;
		ans = (ans + v3 + v4 - v5 - v6 + 2 * mod) % mod;
	}
	ans = ans * i9 % mod;
	cout << ans << endl;
	//cout << ans << endl;
/*	LL ret = 0;
	for(int i = 1;i <= tot * m;i++){
		LL tmp = 0;
		for(int j = i;j <= tot * m;j++){
			tmp = (tmp * 10LL + s[j]) % mod;	
			ret = (ret + tmp) % mod;
		}
	}
	//cout << ret << endl;
	if(ans != ret){
		cout << n << " " << m << endl;
		cout << ans << " " << ret << endl;	
	}*/	
}



int main(){
	//cout << p.size() << endl;
	//solve(1,2);
/*	for(int i = 1;i <= 30;i++){
		for(int j = 1;j <= 30;j++){
			solve(i,j);
		}
	}*/
	solve(1e6,1e12);
	return 0;
}
