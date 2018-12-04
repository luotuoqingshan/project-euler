#include "PE.h"

const int maxn = 6e7 + 5;

int d[maxn];
LL dT[maxn];
const LL mod = 1e18;
LL qmul(LL a,LL b){
	LL ret = 0;
	while(b > 0){
		if(b & 1)
			ret = (ret + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return ret;
}

int c[maxn];

void add(int p,int d){
	for(int i = p;i < maxn;i += i & -i){
		c[i] += d;
	}
}
int sum(int p){
	int ret = 0;
	for(int i = p;i > 0;i -= i & -i){
		ret += c[i];
	}
	return ret;
}
pair<LL,int> p[maxn];
int ans1[maxn],ans2[maxn];
int main(){
	for(int i = 1;i < maxn;i++){
		for(int j = i;j < maxn;j += i){
			d[j]++;
		}
	}
	int n;
	for(int i = 1;i <= 60000000;i++){
		if(i & 1){
			dT[i] = d[(i + 1) / 2] * d[i];
		}else{
			dT[i] = d[i / 2] * d[i + 1];
		}
	}	
	cin >> n;
	/*for(int i = 1;i <= n;i++){
		p[i] = make_pair(-dT[i],-i);
	}
	sort(p + 1,p + 1 + n);
	memset(c,0,sizeof(c));*/
	/*for(int i = 1;i <= n;i++){
		ans1[i] = sum(-p[i].second);
		add(-p[i].second,1);
	}
	for(int i = 1;i <= n;i++){
		p[i] = make_pair(dT[i],i);
	}*/
	/*sort(p + 1,p + 1 + n);
	memset(c,0,sizeof(c));
	for(int i = 1;i <= n;i++){
		ans2[i] = (i - 1) - sum(p[i].second);
		add(p[i].second,1);
	}
	*/LL val = 0;
	for(int i = 1;i <= n;i++){
		val = (val + ans1[i] * ans2[i]) % mod;
	}
	cout << val << endl;
	return 0;
}
