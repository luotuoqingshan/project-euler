
typedef long long LL;
LL arr[maxn];
vector<LL> vr;
unordered_map<LL,LL> mp;
LL Sum(LL n){
	if(n < maxn) return sum[n];
	LL r = sqrt(n);
	vr.clear();
	mp.clear();
	for(int i = 1;i <= r;i++){
		vr.push_back(n / i);
	}
	for(int i = vr.back() - 1;i > 0;--i){
		vr.push_back(i);
	}
	int len = vr.size();
	for(int i = 0;i < len;i++){
		arr[i] = vr[i];
		mp[vr[i]] = vr[i] - 1;
	}
	LL sp;
	LL p2;
	for(int i = 2;i <= r;i++){
		if(mp[i] > mp[i - 1]){
			sp = mp[i - 1];
			p2 = 1LL * i * i;
			for(int v = 0;v < len;++v){
				if(arr[v] < p2) break;
				mp[arr[v]] -= 1LL * i * (mp[arr[v] / i] - sp);
			}
		}
	}
	return mp[n];
}
