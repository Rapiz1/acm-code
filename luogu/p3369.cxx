/*
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
 *          Sun, 25 Aug 2019 21:43:11 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define fastread ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;
namespace IO{
	char buf[1<<15],*fs,*ft;
	inline char gc(){return (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),fs==ft))?0:*fs++;}
	inline int gi(){
		int x=0,rev=0,ch=gc();
		while(ch<'0'||ch>'9'){if(ch=='-')rev=1;ch=gc();}
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=gc();}
		return rev?-x:x;
	}
}
using namespace std;
const int N = 5e5 + 10, T = 20;
int n, m, s, fa[N][T], dep[N], t;
vector<int> to[N];
void dfs(int u) {
  for (int i = 1; i <= t; i++) {
    fa[u][i] = fa[fa[u][i-1]][i-1];
  }
  for (auto v: to[u]) {
    if (v != fa[u][0]) {
      dep[v] = dep[u]+1;
      fa[v][0] = u;
      dfs(v);
    }
  }
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for(int x = dep[u] - dep[v], i = 0;x; x>>=1, i++) {
    if (x&1) u = fa[u][i];
  }
  if (u == v) return v;
  for (int i = t; i>=0; i--) {
    if (fa[u][i] != fa[v][i]) {
      u = fa[u][i];
      v = fa[v][i];
    }
  }
  return fa[u][0];
}
int main() {
  using IO::gi;
  n = gi(), m = gi(), s = gi();
  t = ceil(log2(n));
  for (int i = 1; i < n; i++) {
    int u, v;
    u = gi(), v = gi();
    to[u].push_back(v);
    to[v].push_back(u);
  }
  dfs(s);
  for (int i = 1; i <= m; i++) {
    int u,  v;
    u = gi(), v = gi();
    cout << lca(u, v) << endl;
  }
}

