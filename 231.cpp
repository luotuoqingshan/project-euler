#include "PE.h"

vector<int> p = get_primes(20000000);
typedef long long LL;
LL cal(LL l,LL r,LL p){
	return r / p - (l - 1) / p;
}

LL solve(LL n,LL m){
	LL ans = 0;
	for(int i = 0;i < p.size() && p[i] <= n;i++){
		LL v = p[i];
		for(;;v *= p[i]){
			LL cnt1 = cal(n - m + 1,n,v);
			LL cnt2 = cal(1,m,v);
			if(cnt1 > cnt2){
				ans += p[i];
			}else{
				if(cnt1 == 0) break;
			}
		}	
	}
	return ans;
}

int main(){
	cout << solve(20000000,15000000) << endl;
	return 0;
}
