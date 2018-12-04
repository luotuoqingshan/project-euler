#include "PE.h"

#include <unordered_set>

unordered_set<LL> s,p;
LL n;
void init(){
	queue<LL> q;
	q.push(1);
	s.insert(1);
	while(!q.empty()){
		LL u = q.front();q.pop();
		if(2LL * u <= n){
			if(s.find(2LL * u) == s.end()){
				s.insert(2LL * u);
				q.push(2LL * u);
			}
		}
		if(5LL * u <= n){
			if(s.find(5LL * u) == s.end()){
				s.insert(5LL * u);
				q.push(5LL * u);
			}
		}
		if(3LL * u <= n){
			if(s.find(3LL * u) == s.end()){
				s.insert(3LL * u);
				q.push(3LL * u);
			}
		}
	}
	for(auto x:s){
		if((x + 1) <= n && miller_rabin(x + 1)){
			p.insert(x + 1);
		}
	}
}

vector<LL> v;
vector<LL> v1;
unordered_map<LL,bool> mp;
void dfs(int N,LL val){
	if(!mp.count(val))
		v1.push_back(val);
	if(N == v.size()) return;
	dfs(N + 1,val);
	if(val * v[N] <= n)dfs(N + 1,val * v[N]);
}	

int main(){
	cin >> n;
	init();
	p.insert(2);
	p.insert(3);
	p.insert(5);
	cout << p.size() << endl;
	for(auto x: p){
		v.push_back(x);
	}
	dfs(0,1);
	return 0;
}
