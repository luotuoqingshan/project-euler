#include "PE.h"

unordered_map<int,bool> vis;

vector<int> p = get_primes(1000000);

int d[10],tot;

bool check(int num){
	tot = 0;
	while(num > 0){
		d[tot++] = num % 10;
		num /= 10;
	}
	bool flag = true;
	for(int i = tot - 1;i >= 0;i--){
		int now = 0;
		for(int j = 0;j < tot;j++){
			now = now * 10 + d[(i - j + tot) % tot];
		}
		if(vis.count(now) == 0) flag = false;
	}
	return flag;
}

int main(){
	for(int i = 0;i < p.size();i++){
		vis[p[i]] = 1;
	}
	int ans = 0;
	for(int i = 0;i < p.size();i++){
		ans += check(p[i]);	
	}
	cout << ans << endl;
	return 0;
}
