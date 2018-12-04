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

void dfs(int n,vector<int> a){
	if(n == 7){
		if(check(a) != 0){
			int sum = 0;
			for(auto x : a){
				cout << x  << " ";
				sum += x;
			}
			cout << endl;
			cout << sum << endl;
		}
		return;
	}
	int pre;
	if(n > 0 && check(a) == 0) return;
	if(n == 0) pre = 10;
	else pre = a[n - 1] + 1;	
	for(int i = pre;i <= 50;i++){
		vector<int> temp = a;
		temp.push_back(i);
		dfs(n + 1,temp);
	}
}

int main(){
	dfs(0,vector<int>());
	return 0;
}
