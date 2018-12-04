#include "PE.h"

vector<int> p = get_primes(20000000);

int a[11] = {6,2,5,5,4,5,6,4,7,6,0};
int b[11][11];

#include <bitset>

bitset<7> c[10];

int tran(int a1[10],int b1[10]){
	int ret = 0;
	for(int i = 0;i < 10;i++){
		ret += a[a1[i]] + a[b1[i]];
		ret -= b[a1[i]][b1[i]];
	}	
	return ret;
}

long long solve(int n){
	int a[10],tot = 0;
	int b[10];
	long long ans = 0;
	int m = 0;
	for(int i = 0;i < 10;i++)
		b[i] = 10;
	while(n != m){
		tot = 0;
		for(int i = 0;i < 10;i++)
			a[i] = 10;
		int temp = n;
		m = 0;
		while(temp > 0){
			a[tot++] = temp % 10;
			m += temp % 10;
			temp /= 10;
		}	
		ans += tran(b,a);
		swap(a,b);
		swap(n,m);
	}
	return ans;
}

int main(){
	for(int i = 0;i < 10;i++){
		c[i].reset();
	}
	c[0].set(0);c[0].set(2);c[0].set(3);c[0].set(4);c[0].set(5);c[0].set(6);
	c[1].set(5);c[1].set(6);
	c[2].set(0);c[2].set(1);c[2].set(2);c[2].set(4);c[2].set(5);
	c[3].set(0);c[3].set(1);c[3].set(2);c[3].set(5);c[3].set(6);
	c[4].set(1);c[4].set(3);c[4].set(5);c[4].set(6);
	c[5].set(0);c[5].set(1);c[5].set(2);c[5].set(3);c[5].set(6);
	c[6].set(0);c[6].set(1);c[6].set(2);c[6].set(3);c[6].set(4);c[6].set(6);
	c[7].set(0);c[7].set(5);c[7].set(6);c[7].set(3);
	c[8].set(0);c[8].set(1);c[8].set(2);c[8].set(3);c[8].set(4);c[8].set(5);c[8].set(6);
	c[9].set(0);c[9].set(1);c[9].set(2);c[9].set(3);c[9].set(5);c[9].set(6);
	for(int i = 0;i < 11;i++){
		for(int j = 0;j < 11;j++){
			if(i == 10){
				b[i][j] = a[j];
				continue;
			}
			if(j == 10){
				b[i][j] = a[i];
				continue;
			}
			b[i][j] = (c[i] ^ c[j]).count();
		}
	}
	b[10][10] = 0;
	long long ans = 0;
	for(int i = 0;i < p.size();i++){
		if(p[i] > 10000000){
			ans += solve(p[i]);
		}else if(p[i] < 100){
			cout << p[i] << " " << solve(p[i]) << endl;
		}
	}
	cout << ans << endl;
	return 0;
}
