#include "PE.h"

using namespace std;

vector<int> d;
vector<int> p = get_primes(1e6);
vector<int> r;
const int mod = 2017;

int qpow(int a,int n){
	a %= mod;
	int ret = 1;
	while(n > 0){
		if(n & 1) ret = ret * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}
void init(){
	for(int i = 1;i <= 2016;i++){
		if(2016 % i == 0){
			d.push_back(i);
		}
	}
	for(int i = 0;i < p.size();i++){
		if(p[i] != 2017){
			for(int j = 0;j < d.size();j++){
				if(qpow(p[i],d[j]) == 1){
					r.push_back(d[j]);
				}
			}
		}else{
			r.push_back(-1);
		}
		if(r[i] >= 0 && r[i] <= 5){
			cout << p[i] << " " << r[i] << endl;
		}
	}
}

int main(){
	init();
	return 0;
}
