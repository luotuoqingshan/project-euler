#include "PE.h"


typedef pair<LL,pair<LL,vector<pair<LL,LL> > > > P;

priority_queue<P> Q;

int n;

vector<int> primes = get_primes(1e8);

void bfs(){
	P a = make_pair(1LL,make_pair(0,vector<pair<LL,LL> >(0)));	
	Q.push(a);
	while(!Q.empty()){
		P u = Q.top();Q.pop();
		LL val = u.first;
		LL times = u.second.first;
		vector<pair<LL,LL> > div = u.second.second;
		if(times == n){
			cout << val << endl;
			break;
		}
		for(int i = 0;i < div.size();i++){

		}
	}
}

int main(){
	cin >> n;	

	return 0;
}
