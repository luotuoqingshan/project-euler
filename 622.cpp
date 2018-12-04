#include "PE.h"


long long gcd(long long a,long long b){
	if(b == 0) return a;
	return gcd(b,a % b);
}


long long a[100];


int main(){
	long long power = 1;
	for(int i = 1;i <= 60;i++){
		power = power * 2;
		a[i] = power - 1;
	}
	vector<long long> div;
	long long temp = a[60];
	for(int i = 1;1LL * i * i <= temp;i += 2){
		if(temp % i == 0){
			div.push_back(i);
			if(temp / i != 1LLi)	div.push_back(temp / i);
		}
	}
	long long ans = 0;
	for(auto x:div){
		bool flag = false;
		for(int i = 1;i <= 59;i++){
			if(a[i] % x == 0){
				flag = true;
			}
		}
		if(!flag) {ans += (x + 1);}
	}
	cout << ans << endl;
	return 0;
}
