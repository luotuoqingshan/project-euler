#include "PE.h"

typedef long long LL;

#include <unordered_map>	

unordered_map<LL,int> mp;

int cal(int x,int type){
	int a[10],tot = 0;
	while(x > 0){
		a[++tot] = x % 10;
		x /= 10;
	}
	reverse(a + 1,a + 1 + tot);
	if(type == 1){
		for(int i = tot + 1;i <= 2 * tot - 1;i++){
			a[i] = a[2 * tot - i];
		}
		tot = 2 * tot - 1;
	}else{
		for(int i = tot + 1;i <= 2 * tot;i++){
			a[i] = a[2 * tot + 1 - i];
		}
		tot = 2 * tot;
	}
	int ret = 0;
	for(int i = 1;i <= tot;i++){
		ret = ret * 10 + a[i];
	}	
	return ret;
}
int main(){
	for(int i = 1;i <= 10000;i++){
		LL pre = 1LL * i * (i + 1) * (2 * i + 1) / 6;
		mp[pre] = i;
	}
	long long ans = 0;
	for(int i = 1;i < 10000;i++){
		int now = cal(i,1);
		bool flag = false;
		for(int j = 0;1LL * j * j <= now;j++){
			LL x = 1LL * j * (j + 1) * (2 * j + 1) / 6;
			if(mp.count(x + now) && mp[x + now] > j + 1){
				flag = true;
			}
		}
		if(flag) ans += now;
	}
	for(int i = 1;i < 10000;i++){
		int now = cal(i,2);
		bool flag = false;
		for(int j = 0;1LL * j * j <= now;j++){
			LL x = 1LL * j * (j + 1) * (2 * j + 1) / 6;
			if(mp.count(x + now) && mp[x + now] > j + 1){
				flag = true;
			}
		}
		if(flag) ans += now;
	}
	cout << ans << endl;
	return 0;
}
