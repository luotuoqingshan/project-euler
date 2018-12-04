#include "PE.h"

vector<int> p = get_primes(100);

set<long long> s;

void dfs(long long n,int id){
	s.insert(n);
	for(int i = id;i < p.size();i++){
		long long to = n * p[i];
		if(to > 1000000000) break;
		dfs(to,i);
	}
}

int main(){

	dfs(1,0);
	cout << s.size() << endl;
	return 0;
}
