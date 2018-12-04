#include "PE.h"

const int maxn = 1234567 + 5;

set<int> bit[maxn];

vector<int> p = get_primes(maxn);

vector<int> divisor[maxn];

int R[maxn];
int cal(int l,int r){
	for(int i = l;i <= r;i++){
		int tmp = i;
		for(int j = 0;j < divisor[i].size();j++){
			int divi = divisor[i][j];
			int cnt = 0;
			while(tmp % divi == 0){
				cnt++;
				tmp /= divi;
			}
			if(cnt & 1) bit[i].insert(divi);
		}		
	}
	int ans = 0;
	for(int i = l;i <= r;i++){
		while(bit[i].size() > 0){
			int now = *bit[i].begin();
			if(R[now] == 0){
				R[now] = i;
				break;
			}else{
				for(auto x: bit[R[now]]){
					if(bit[i].count(x)){
						bit[i].erase(x);
					}else{
						bit[i].insert(x);
					}
				}
			}
		}
		if(bit[i].size() == 0) ans++;
	}
	return ans;
}

const int mod = 1e9 + 7;

int qpow(int a,int n){
	int ret = 1;
	while(n > 0){
		if(n & 1){
			ret = 1LL * ret * a % mod;
		}
		a = 1LL * a * a % mod;
		n >>= 1;
	}
	return ret;
}

int main(){
	for(int i = 0;i < p.size();i++){
		int d = p[i];
		for(int j = d;j < maxn;j += d){
			divisor[j].push_back(d);
		}	
	}	
	//cout << cal(5,10) << endl;
	int n = cal(1000000,1234567);
	int ans = (qpow(2,n) + mod - 1) % mod;
	cout << ans << endl;
	return 0;
}
