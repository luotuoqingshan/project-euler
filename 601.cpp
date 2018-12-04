#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
	return b == 0 ? a : gcd(b,a % b);
}

ll lcm[40];
ll p4[40];

void init(){
	lcm[1] = 1;
	for(ll i = 2;i <= 32;i++){
		ll g = gcd(lcm[i - 1],i);
		lcm[i] = lcm[i - 1] / g * i;
	}
	p4[0] = 1;
	for(ll i = 1;i <= 31;i++){
		p4[i] = p4[i - 1] * 4LL;
	}
}


int main(){
	init();	
	long long ans = 0;
	for(int i = 1;i <= 31;i++){
		ans += (p4[i] - 2) / lcm[i] - (p4[i] - 2) / lcm[i + 1];
	}
	cout << ans << endl;
	return 0;
}
