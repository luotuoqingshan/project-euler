#include "PE.h"

#include <map>
typedef long long LL;

LL gcd(LL a,LL b){
	if(b == 0) return a;
	return gcd(b,a % b);
}

LL cal(LL n){
		map<vector<LL>,int> mp;
		LL x = sqrt(n);
		if(x * x == n) return 0;
		LL a = n,b = x,c = 1;
		for(LL j = 1;;j++){
			LL tmp = a - b * b;
			LL g = gcd(tmp,c);
			tmp /= g;
			c /= g;
			LL ret = (1.0 * sqrt(a) + b) * c / tmp;
			vector<LL> v(0);
			v.push_back(a);
			v.push_back(b);
			v.push_back(c);
			v.push_back(tmp);
			v.push_back(ret);
			if(mp.count(v)) return j - 1;
			else mp[v] = j;
			a = a * c * c;
			b = tmp * ret - b * c;
			c = tmp;	
		}
		return 0;
}

int main(){
	int cnt = 0;
	for(int i = 1;i <= 10000;i++){
		cnt += (cal(i) & 1);
	}
	cout << cnt << endl;
	return 0;
}
