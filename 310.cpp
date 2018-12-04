#include "PE.h"

const int maxn = 1e6 + 6;
int sg[maxn];
LL cnt[maxn];
int main(){
	sg[0] = 0;
	for(int i = 1;i <= 100000;i++){
		bool vis[5005] = {0};
		for(int j = 1;j * j <= i;j++){
			vis[sg[i - j * j]] = true;
		}	
		for(int j = 0;j < 5000;j++){
			if(!vis[j]){
				sg[i] = j;
				break;
			}
		}
	}
	int ans = 0;
	for(int a = 0;a <= 29;a++){
		for(int b = a;b <= 29;b++){
			for(int c = b;c <= 29;c++){
				if(sg[a] ^ sg[b] ^ sg[c] == 0){
					ans++;
				}
			}	
		}
	}
	cout << ans << endl;
	return 0;
}
