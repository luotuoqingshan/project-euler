#include "PE.h"

const int maxn = 1e8 + 5;

bool vis[maxn];

void init(){
	vis[1] = true;
	for(int i = 2;i < maxn;i++){
		if(!vis[i]){
			for(int j = 2 * i;j < maxn; j += i){
				vis[j] = true;
			}
		}
	}
}
bool p(int x){
	if(x > 1e8) return false;
	return !vis[x];
}

int check(vector<int> a){
	int cnt = 0;
	for(auto x : a){
		if(p(x)) cnt++;
	}	
	return cnt;
}
int a[15];
int ans;
set<vector<int> > s;
void dfs(int n,vector<int> now){
	if(n == 10){
		if(check(now) == now.size()){
			sort(now.begin(),now.end());
			s.insert(now);
		}
		return;
	}
	if(check(now) != now.size()) return;
	int temp = 0;
	for(int j = n;j <= 9;j++){
		temp = temp * 10 + a[j];
		vector<int> b = now;
		b.push_back(temp);
		dfs(j + 1,b);
	}
}

int main(){
	init();
	for(int i = 1;i <= 9;i++)
		a[i] = i;
	do{
		dfs(1,vector<int>());
	}while(next_permutation(a + 1,a + 1 + 9));
	cout << s.size() << endl;
	return 0;
}
