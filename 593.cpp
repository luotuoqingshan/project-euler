#include "PE.h"

vector<int> primes = get_primes(200000000);

const int maxn = 1e7 + 5;

int s[maxn];
int s2[maxn];
const int mod = 1e4 + 7;
int qpow(int a,int n){
	int ret = 1;
	while(n > 0){
		if(n & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}

const int N = 30000;
int v[N << 2];

#define lson o * 2,l,mid
#define rson o * 2 + 1,mid + 1,r

void pushup(int o){
	v[o] = v[o * 2] + v[o * 2 + 1];
}

void build(int o,int l,int r){
	v[o] = 0;
	if(l == r){
		return;
	}
	int mid = (l + r) / 2;
	build(lson);
	build(rson);
}

int query(int o,int l,int r,int k){
	if(l == r){
		return l;
	}
	int mid = (l + r) / 2;
	if(v[o * 2] >= k)
		return query(lson,k);
	else
		return query(rson,k - v[o * 2]);
}

void update(int o,int l,int r,int p,int k){
	if(l == r){
		v[o] += k;
		return;
	}
	int mid = (l + r) / 2;
	if(p <= mid) update(lson,p,k);
	else update(rson,p,k);
	pushup(o);
}


int main(){
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		s[i] = qpow(primes[i - 1] % mod,i);
	}
	for(int i = 1;i <= n;i++){
		s2[i] = s[i] + s[(i / 10000) + 1];
	}
	build(1,1,10007 * 2);
	double sum = 0;
	for(int i = 1;i<= n;i++){
		update(1,1,10007 * 2,s2[i] + 1,1);
		if(i - k >= 1){
			update(1,1,10007 * 2,s2[i - k] + 1,-1);
		}
		if(i >= k){
			if(k & 1){
				int val = query(1,1,10007 * 2,k / 2 + 1) - 1; 
				sum += val;
			}else{
				int val1,val2;
				val1 = query(1,1,10007 * 2,k / 2) - 1;
			   	val2 = query(1,1,10007 * 2,k / 2 + 1) - 1;
				sum += (val1 + val2) / 2.0;
			}
		}
	}
	printf("%.1lf\n",sum);
	return 0;
}
