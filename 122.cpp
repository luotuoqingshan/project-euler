#include "PE.h"

const int maxn = 205;
int dp[maxn];

vector<vector<int> > G[maxn];

int main(){
	memset(dp,0x3f,sizeof(dp));
	dp[1] = 0;
	vector<int> i(1,1);
	G[1].push_back(i);
	for(int i = 1;i <= 200;i++){
		for(int j = 0;j < G[i].size();j++){
			for(auto x:G[i][j]){
				if(i + x <= 200){
					if(dp[i + x] > dp[i] + 1){
						dp[i + x] = dp[i] + 1;
						vector<int> temp = G[i][j];
						temp.push_back(i + x);
						G[i + x].clear();
						G[i + x].push_back(temp);
					}else if(dp[i + x] == dp[i] + 1){
						dp[i + x] = dp[i] + 1;
						vector<int> temp = G[i][j];
						temp.push_back(i + x);
						G[i + x].push_back(temp);
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= 200;i++){
		ans += dp[i];
	}
	cout << ans << endl;
	return 0;
}
