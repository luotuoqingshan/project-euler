#include "PE.h"

queue<int> q;
vector<int> ans;

bool check(long long x){
	long long tmp = x;
	while(tmp > 0){
		if(is_prime(tmp) == 0) return false;
		tmp /= 10;
	}
	long long id = 1;
	tmp = x;
	while(id <= tmp) id *= 10;
	if(x == 3937) cout << id << endl;
	while(id > 1){

		if(is_prime(tmp % id) == 0) return false;
		id /= 10;
	}
	return true;
}

int main(){
	for(int i = 10;i <= 1000000;i++){
		if(check(i)){
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	long long sum = 0;
	for(int i = 0;i < ans.size();i++){
		sum += ans[i];
	}
	cout << sum << endl;
	return 0;
}
