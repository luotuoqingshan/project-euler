#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;
const LL mod = (LL)1e10;

void add(LL &a,LL b){
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

LL mul(LL a,LL b){
	LL ret = 0;
	while(b > 0){
		if(b & 1) add(ret,a);
		add(a,a);
		b >>= 1;
	}
	return ret;
}

LL qpow(LL a,LL b){
	LL ret = 1;
	while(b > 0){
		if(b & 1) ret = mul(ret,a);
		a = mul(a,a);
		b >>= 1;
	}
	return ret;
}

int main(){
	LL ans = 0;
	for(int i = 1;i <= 1000;i++){
		add(ans,qpow(i,i));
	}
	cout << ans << endl;
	return 0;
}
