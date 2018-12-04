#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
typedef long long LL;
map<pair<LL,LL>,bool> mp;

int main(){
	mp[make_pair(1,1)] = true;
	queue<pair<LL,LL> > Q;
	Q.push(make_pair(1,1));
	LL r = 3,s = 1,D = 8;
	while(!Q.empty()){
		if(mp.size() > 50) break;
		pair<LL,LL> now = Q.front();
		Q.pop();
		LL p = now.first,q = now.second;	
		LL pp = abs(p * r - D * q * s);
		LL qq = abs(p * s - q * r);
		if(!mp.count(make_pair(pp,qq))){
			mp[make_pair(pp,qq)] = true;
			Q.push(make_pair(pp,qq));
		}
		pp = abs(p * r + D * q * s);
		qq = abs(p * s + q * r);
		if(!mp.count(make_pair(pp,qq))){
			mp[make_pair(pp,qq)] = true;
			Q.push(make_pair(pp,qq));
		}
	}	
	int cnt = 0;
	LL sum = 0;
	for(auto x : mp){
		LL val = x.first.second - 1;
		if(val > 0){
			cnt++;
			if(cnt <= 40){
				sum += val;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
