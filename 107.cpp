#include "PE.h"

int a[40][40];

char s[1000000];

bool vis[40];

int main(){
	freopen("p107_network.txt","r",stdin);
	for(int i = 0;i < 40;i++){
		scanf("%s",s);
		int n = strlen(s);
		s[n] = ',';
		int now = 0;
		int cnt = 0;
		for(int j = 0;j <= n;j++){
			if(s[j] == '-'){
				now = 1e9; 
			}else if(s[j] == ','){
				a[i][cnt++] = now;
				now = 0;
			}else{
				now = now * 10 + (s[j] - '0');
			}	
		}	
	}
	long long sum1 = 0;
	for(int i = 0;i < 40;i++){
		for(int j = i;j < 40;j++){
			if(a[i][j] != 1e9)
				sum1 += a[i][j];
		}
	}
	vis[0] = 1;
	long long sum = 0;
	while(true){
		bool flag = false;
		int ans = 1e9,id = -1;
		for(int i = 0;i < 40;i++){
			if(vis[i]){
				for(int j = 0;j < 40;j++){
					if(!vis[j]){
						if(a[i][j] != 1e9){
							if(a[i][j] < ans){
								id = j;
								ans = a[i][j];
								flag = true;
							}
						}	
					}
				}
			}
		}
		if(!flag) break;
		vis[id] = true;
		sum += ans;
		cout << ans << endl;
	}
	cout << sum1 - sum << endl;
	return 0;
}
