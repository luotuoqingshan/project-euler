#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 2e8 + 5;

bool vis[maxn];
int prime[maxn],tot;
bool ok[maxn];
void init(){
	vis[1] = 1;
	for(int i = 2;i <= 200000000;i++){
		if(!vis[i]){
			prime[++tot] = i;
		}
		for(int j = 1;j <= tot && i * prime[j] <= 200000000;j++){
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	for(int i = 1;i <= 100000000;i++){
		for(int j = i;j <= 100000000; j += i){
			if(vis[i + j / i]) ok[j] = 1;	
		}
	}
	long long ans = 0;
	for(int i = 1;i <= 100000000;i++){
		if(!ok[i]) ans += i;
	}
	cout << ans << endl;
}


int main(){
	init();
	return 0;
}
