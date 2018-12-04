#include "PE.h"

const int maxn = 1e8 + 5;

int s[maxn];
bool vis[maxn];
int prime[maxn],tot = 0;
int lst[maxn];
void init(int n){
	vis[1] = 1;
	for(int i = 2;i < n + 1;i++){
		if(!vis[i]){
			prime[++tot] = i;
		}
		for(int j = 1;j <= tot && i * prime[j] < n + 1;j++){
			vis[i * prime[j]] = 1;
			lst[i * prime[j]] = prime[j];
			if(i % prime[j] == 0)
				break;
		}
	}		
}

long long cal(int n){
	init(n);
	s[1] = 1;
	long long ans = 0;
	for(int i = 2;i <= n;i++){
		if(!vis[i]){
			s[i] = i;
		}else{
			s[i] = s[i / lst[i]];
			int cnt = 0;
			int tmp = i;
			while(tmp % lst[i] == 0){
				tmp /= lst[i];
				cnt++;
			}
			long long cnt1 = 0;
			for(long long j = lst[i];j <= s[i];j *= lst[i]){
				cnt1 += s[i] / j;
			}
			if(cnt1 < cnt){
				s[i]++;
				while(s[i] % lst[i]) s[i]++;
			}
		}
		ans += s[i];
	}
	return ans;
}

int main(){
	cout << cal(100000000) << endl;

	return 0;
}
