#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

const int maxn = 25000000;
const int N = 7322400;
vector<int> g[N];
map<pair<int,pair<int,int> > ,int> mp;
int main(){
	for(int i = 1;i < N;i++){
		for(int j = i;j < N;j += i){
			g[j].push_back(i);
		}
	}	
	long long ans = 0;
	for(int a = 1;a < N;a++){
		if(a == 1){
			ans += (maxn - 1) / 2;
		}else if(a & 1){
			vector<int> tmp1 = g[(a - 1) / 2];
			vector<int> tmp2 = g[(a + 1) / 2];
			for(int i = 0;i < tmp1.size();i++){
				for(int j = 0;j < tmp2.size();j++){
					long long div = 1LL * tmp1[i] * tmp2[j];
					long long div1 = 1LL * (a - 1) * (a + 1) / 4 / div;
					long long c = div1 + div;
					long long b = div1 - div;
					if(a <= b && b <= c && a + b + c <= maxn) mp[make_pair(a,make_pair(b,c))]++;	
				}
			}
		}else{
			vector<int> tmp1 = g[a - 1];
			vector<int> tmp2 = g[a + 1];
			for(int i = 0;i < tmp1.size();i++){
				for(int j = 0;j < tmp2.size();j++){
					long long div = 1LL * tmp1[i] * tmp2[j];
					long long div1 = 1LL * (a - 1) * (a + 1) / div;
					long long c = (div + div1) / 2;
					long long b = (div - div1) / 2;
					if(a <= b && b <= c && a + b + c <= maxn) mp[make_pair(a,make_pair(b,c))]++;
				}
			}
		}
	}
	cout << ans + mp.size() << endl;
	return 0;
}
