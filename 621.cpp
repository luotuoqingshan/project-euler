#include "PE.h"

typedef long long LL;
unordered_map<LL,int> mp;

int main(){
	LL n = 1000000000LL;
	for(int b = 0;1LL * b * (b + 1) / 2 <= n;b++){
		for(int c = 0;1LL * b * (b + 1) / 2 + 1LL * c * (c + 1) / 2 <= n;c++){
			LL ans = 1LL * b * (b + 1) / 2 + 1LL * c * (c + 1) / 2;
			mp[ans]++;
		}
	}	
	cout << mp.size() << endl;
	return 0;
}
