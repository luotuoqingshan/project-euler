#include "PE.h"

int id[15] = {0,1,2,3,2,4,5,4,6,7,6,8,9,8,1};

long long ans = 0;
void dfs(int n,int *a,bool *vis){
	if(n == 10){
		int x = a[0] + a[1] + a[2];
		if(a[2] + a[3] + a[4] != x) return;
		if(a[4] + a[5] + a[6] != x) return;
		if(a[6] + a[7] + a[8] != x) return;
		if(a[9] + a[8] + a[1] != x) return;
		if(a[0] > a[3]) return;
		if(a[0] > a[5]) return;
		if(a[0] > a[7]) return;
		if(a[0] > a[9]) return;
		int temp[25];
		int k = 0;
		for(int i = 14;i >= 0;i--){
			int tmp = a[id[i]];
			while(tmp > 0){
				temp[k++] = tmp % 10;
				tmp /= 10;
			}
		}
		long long tmp = 0;
		for(int i = k - 1;i >= 0;i--){
			tmp = tmp * 10 + temp[i];
		}
		if(k == 16) ans = max(ans,tmp);
		return;
	}
	for(int i = 1;i <= 10;i++){
		if(vis[i] == 0){
			vis[i] = 1;
			a[n] = i;
			dfs(n + 1,a,vis);
			vis[i] = 0;
		}
	}
}

int a[15];
bool v[15];

int main(){
	dfs(0,a,v);
	cout << ans << endl;	
	return 0;
}
