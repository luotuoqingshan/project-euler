#include "PE.h"

const int maxn = 1e4 + 5;

int sg[maxn];

int cnt[maxn];

int n;

const LL mod = 1e18;

map<pair<int,int>, LL> mp;
LL dfs(int n,int m){
	LL ans = 0;
	if(mp.count(make_pair(n,m))) return mp[make_pair(n,m)];
	if(m == -1)
		return 1;
	if(n <= 2){
		if(n == 2 && m == 0){
			return 1;
		}
		return 0;
	}
		ans += dfs(n - 2,((sg[n - 1] + 1) ^ m) - 1); 	
		ans += dfs(n - 1,((sg[n - 2] + 1) ^ m) - 1); 	
	mp[make_pair(n,m)] = ans;
	return ans;
}

int main(){
	sg[1] = 0;
	sg[2] = 1;
	int mx = 0;	
	for(int i = 3;i <= 10000;i++){
		sg[i] = (sg[i - 1] + 1) ^ (sg[i - 2] + 1);
	}	
	return 0;
}
