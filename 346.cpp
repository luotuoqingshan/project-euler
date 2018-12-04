#include "PE.h"

LL n;
unordered_map<LL,LL> mp;

int main(){
	cin >> n;
	LL ans = 0;
	mp[1] += 2;
	for(int i = 2;1LL * i * i < n;i++){
		LL temp = 1LL * i * i + i + 1;
		while( temp < n){
			mp[temp]++;
			temp = temp * i + 1;
		}
	}	
	for(auto x : mp){
		if(x.second > 0){
			ans += x.first;
		}
	}
	cout << ans << endl;
	return 0;
}
