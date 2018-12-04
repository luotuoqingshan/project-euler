#include <cmath>
#include <iostream>
#include <unordered_set>

using namespace std;
typedef long long LL;
unordered_set<LL> s;

LL cal(LL n){
	for(int i = 1;1LL * i * i + 1LL * (i + 1) * (i + 1) <= n;i++){
		for(int j = i + 1;1LL * i * i + 1LL * j * j <= n;j++){
			LL tmp = 1LL * i * i + 1LL * j * j;
			if(s.count(tmp)) s.erase(tmp);
			else s.insert(tmp);
		}
	}
	return s.size();
}

int main(){
	freopen("611.txt","w",stdout);
	cout << cal(100) << endl;
	cout << cal(1e12) << endl;
	return 0;
}
