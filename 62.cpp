#include "PE.h"

map<long long,long long> mp;
map<long long,long long> cnt;

long long cal(long long n){
	int a[25],tot = 0;
	while(n > 0){
		a[++tot] = n % 10;
		n /= 10;
	}
	sort(a + 1,a + 1 + tot);
	long long tmp = 0;
	for(int i = tot;i >= 1;i--){
		tmp = tmp * 10 + a[i];
	}
	return tmp;
}

int main(){
	for(long long i = 1;i <= 100000;i++){
		long long a = cal(1LL * i * i * i);
		if(!mp.count(a)){
			mp[a] = 1LL * i * i * i;
			cnt[a]++;
		}
		else{
			cnt[a]++;
			if(cnt[a] == 5){
				cout << mp[a] << endl;
				break;
			}
		}
	}
	return 0;
}
