#include "PE.h"

const int maxn = 1e7 + 5;

int cnt[maxn];

int main(){
	for(int i = 1;i < maxn;i++){
		for(int j = i;j < maxn;j += i){
			cnt[j]++;
		}
	}
	int ans = 0;
	for(int i = 2;i < 1e7;i++){
		if(cnt[i] == cnt[i + 1]) ans++;
	}
	cout << ans << endl;
	return 0;
}
