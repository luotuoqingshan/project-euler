#include <cstdio>
#include <iostream>

using namespace std;

bool vis[40];
int a[40];
long long ans = 0;
int n;
void dfs(int len,int i,int sum ){
	if(i > len){
		for(int j = len - n + 2;j <= len;j++){
			int ret = 0;
			for(int k = j + n - 1;k >= j;k--){
				int dig;
				if(k <= len) dig = a[k];
				else dig = a[k - len];
				ret = ret * 2 + dig;
			}
			if(vis[ret]) return;
		}	
		long long tmp = 0;
		for(int i = 1;i <= len;i++){
			tmp = tmp * 2 + a[i];
		}
		ans += tmp;
		return;
	}	
	int sum1 = sum >> 1;
	sum1 += (1 << (n - 1));
	a[i] = 1;
	if(!vis[sum1]){
		vis[sum1] = 1;
		dfs(len,i + 1,sum1);
		vis[sum1] = 0;
	}
	int sum2 = sum >> 1;
	a[i] = 0;
	if(!vis[sum2]){
		vis[sum2] = 1;
		dfs(len,i + 1,sum2);
		vis[sum2] = 0;
	}
}	

int main(){
	cin >> n;	
	for(int i = 1;i <= n;i++){
		a[i] = 0;
	}
	vis[0] = 1;
	dfs((1 << n),n + 1,0);
	cout << ans << endl;
	return 0;
}
