#include "PE.h"

int a[14] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43};
typedef long long LL;
LL N = 13082761331670030LL;
vector<int> g[14];
long long ans;

LL qpow(LL a,LL n,LL mod){
	a %= mod;
	LL ret = 1;
	while(n > 0){
		if(n & 1) ret = ret * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}
vector<LL> answers;
int cnt = 0;
void dfs(int n,vector<int> G){
	if(n == 14){
		LL ret = 0;
		for(int i = 0;i < G.size();i++){
			LL A = N / a[i];
			ret += (A * qpow(A,a[i] - 2,a[i])) * G[i] % N;
			ret %= N;
		}		
		cout << ret << endl;
		return;
	}
	for(int i = 0;i < g[n].size();i++){
		vector<int> tmp = G;
		tmp.push_back(g[n][i]);
		dfs(n + 1,tmp);
	}
}

int main(){
	freopen("271.txt","w",stdout);
	ans = 0;
	for(int i = 0;i < 14;i++){
		for(int j = 1;j < a[i];j++){
			if(j * j * j % a[i] == 1){
				g[i].push_back(j);
			}
		}
	}
	vector<int> g(0);
	dfs(0,g);
	return 0;
}
