#include "PE.h"

int check(vector<int> a){
	int sum[5005];
	int n = a.size();
	for(int i = 0;i < (1 << n);i++){
		int temp = 0;
		for(int j = 0;j < n;j++){
			if(i & (1 << j)){
				temp += a[j];
			}
		}
		sum[i] = temp;
	}
	bool flag = true;
	for(int j = 0;j < (1 << n);j++){
		int k = ((1 << n) - 1) ^ j;
		for(int i = k;i;i = (i - 1) & k){
			if(sum[j] == sum[i]) flag = false;
			int cnt1 = __builtin_popcount(j);
			int cnt2 = __builtin_popcount(i);
			if(cnt1 > cnt2){
				if(sum[j] <= sum[i]) flag = false;
			}else if(cnt1 < cnt2){
				if(sum[j] >= sum[i]) flag = false;
			}
		}
	}
	if(flag) return sum[(1 << n) - 1];
	else return 0;
}

char s[1005];

int main(){
	LL ans = 0;
	while(gets(s)){
		if(s[0] == ',') break;
		vector<int> v;
		int n = strlen(s);
		s[n] = ',';
		for(int i = 0;i <= n;i++){
			int j = i;
			while(j + 1 <= n && s[j + 1] != ','){
				j++;
			}
			int temp = 0;
			for(int k = i;k <= j;k++){
				temp = temp * 10 + s[k] - '0';
			}
			i = j + 1;
			v.push_back(temp);
		}
		int ret = check(v);
		cout << ret << endl;
		ans += ret;
	}	
	cout << ans << endl;
	return 0;
}
