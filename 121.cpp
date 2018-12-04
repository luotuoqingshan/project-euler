#include "PE.h"

int n;

const int maxn = 1e8 + 5;

int cnt[maxn];
bool vis[maxn];

int main(){
	int n;
	cin >> n;
	vis[1] = 1;
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		for(int j = 2 * i;j <= n;j += i){
			vis[j] = 1;
		}
	}
	for(int i = 2;i <= n;i++){
		if(vis[i]) continue;
		for(int j = i;j <= n;j += i){
			if(j / i >= i){
				if(!vis[j / i]) cnt[j]++;
			}
		}
	}
	int ans = 0;
	for(int i = 1;i < n;i++){
		if(cnt[i] == 1){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
