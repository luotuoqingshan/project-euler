#include "PE.h"

const int maxn = 1e6 + 5;

vector<int> d[maxn];

int l[maxn];
int cnt[maxn];
int main(){
	for(int i = 1;i <= 1000000;i++){
		for(int j = i;j <= 1000000;j += i){
			d[j].push_back(i);
		}
	}
	for(int i = 1;i <= 1000000;i++){
		for(auto x : d[i]){
			int y = i / x;
			if(y <= x) continue;
			if(x & 1) continue;
			if(y & 1) continue;
			l[i]++;
		}
		cnt[l[i]]++;
	}
	LL sum = 0;
	for(int i = 1;i <= 10;i++){
		sum += cnt[i];
	}
	cout << sum << endl;
	return 0;
}
