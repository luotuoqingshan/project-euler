#include "PE.h"

const int maxn = 1e7 + 5;
const int N = 1e7;
vector<int> primes = get_primes(maxn);
vector<int> divisor[maxn];

map<pair<int,int>,int> mp;

void init(){
	for(int i = 0;i < primes.size();i++){
		int d = primes[i];
		for(int j = d;j < maxn;j += d){
			divisor[j].push_back(d);
		}
	}
	long long sum = 0;
	for(int i = 1;i <= N;i++){
		if(divisor[i].size() == 2){
			pair<int,int> p = make_pair(divisor[i][0],divisor[i][1]); 
			mp[p] = max(mp[p],i);
		}
	}
	for(auto x : mp){
		sum += x.second;
	}
	cout << sum << endl;
}


int main(){
	init();	

	return 0;
}
