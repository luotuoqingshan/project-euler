#include "PE.h"
#include <unordered_map>

const int maxn = 5e7 + 5;
const int N = 5e7;
int cnt[maxn];

int main(){
	for(int i = 1;i <= N;i++){
		for(int j = i;j <= N;j += i){
			if(cnt[j] > 1) continue;
			int x = i,y = j / i;
			if((x + y) % 4) continue;
			int d = (x + y) / 4;
			int a = y - d;
			if(a <= 0) continue;
			cnt[j]++;
		}
	}
	int ans = 0;
	for(int i = 1;i <= N;i++){
		if(cnt[i] == 1)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
