#include "PE.h"

const int maxn = 5e7 + 5;

vector<int> p = get_primes(8000);

set<int> s;

int main(){
	for(int i = 0;i < p.size();i++){
		long long b1 = 1LL * p[i] * p[i] * p[i] * p[i];
		if(b1 >= 5e7) break;
		for(int j = 0;j < p.size();j++){
			long long b2 = p[j] * p[j] * p[j];
			if(b1 + b2 >= 5e7) break;
			for(int k = 0;k < p.size();k++){
				long long b3 = p[k] * p[k];
				if(b1 + b2 + b3 >= 5e7)
					break;
				else s.insert(b1 + b2 + b3);
			}
		}
	}
	cout << s.size() << endl;
	return 0;
}
