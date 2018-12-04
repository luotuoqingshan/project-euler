#include "PE.h"

const int maxn = 1e6 + 5;

int divisorSum[maxn];

map<int,bool> mp;

int main(){
	for(int i = 1;i < maxn;i++){
		for(int j = 2 * i;j < maxn;j += i){
			divisorSum[j] += i;
		}
	}
	int ans = 1e9;
	for(int i = 1;i <= 1000000;i++){
		mp.clear();
		int now = i;
		int mx = 1e9;
		while(now > 0 && now <= 1000000 && !mp.count(now)){
			mp[now] = true;
			mx = min(mx,now);
			now = divisorSum[now];
		}
		if(now == i){
			if(mp.size() == 28){
				ans = min(ans,mx);
			}	
		}
	}	
	cout << ans << endl;
	return 0;
}
