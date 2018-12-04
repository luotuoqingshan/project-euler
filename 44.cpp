#include "PE.h"

int cal(int n){
	return n * (3 * n  - 1) / 2;
}

int P[10000];
map<int,bool> mp;

int main(){
	for(int i = 1;i < 10000;i++){
		P[i] = cal(i);
		mp[P[i]] = 1;
	}
	int ans = 1e9;
	for(int i = 1;i < 10000;i++){
		for(int j = i + 1;j < 10000;j++){
			int d = P[j] - P[i];
			int sum = P[j] + P[i];
			if(mp.count(d) && mp.count(sum)){
				ans = min(ans,d);
			}
		}
	}	
	cout << ans << endl;
	return 0;
}
