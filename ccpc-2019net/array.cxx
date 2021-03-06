/**
 *     ____              _    
 *    / __ \____ _____  (_)___
 *   / /_/ / __ `/ __ \/ /_  /
 *  / _, _/ /_/ / /_/ / / / /_
 * /_/ |_|\__,_/ .___/_/ /___/
 *            /_/             
 *           code@rapiz.me
*          Fri, 23 Aug 2019 13:23:11 +0800
 */
#include <bits/stdc++.h>
#define xxx(x) cerr<<(#x)<<": "<<x<<endl;
#define lch (o<<1)
#define rch ((o<<1)|1)
typedef long long ll;
using namespace std;
namespace IStream{
    const int L=1<<15;
    char buffer[L],*S,*T;
    inline char Get_Char()
    {
        if(S==T)
        {
            T=(S=buffer)+fread(buffer,1,L,stdin);
            if(S==T) return EOF;
        }
        return *S++;
    }
    inline int gi()
    {
        char c;
        int re=0;
        for(c=Get_Char();c<'0'||c>'9';c=Get_Char());
        while(c>='0'&&c<='9')
            re=(re<<1)+(re<<3)+(c-'0'),c=Get_Char();
        return re;
    }
}
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
using IO::gi;
const int N = 1e5 + 10, SEG=N<<2;
const int ADD = 10000000;
int n, m, a[N], lastAns;
int mx[SEG];
void up(int o) {
  mx[o] = max(mx[lch], mx[rch]);
}
void put(int o, int l, int r, int pos, int idx) {
  if (l == r) {
    mx[o] = idx;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid) put(lch, l, mid, pos, idx);
  else put(rch, mid+1, r, pos, idx);
  up(o);
}
int query(int o, int l, int r, int q, int k) {
//  printf("o:%d l:%d r:%d q:%d k:%d mx:%d\n", o, l, r, q, k, mx[o]);
  if (l == r) {
    return mx[o] > q ? l : 0;
  }
  int mid = (l+r)>>1;
  int ret = 0;
  if (k<= mid && mx[lch] > q) {
    ret = query(lch, l, mid, q, k);
  }
  if (!ret && k <= r && mx[rch] > q) {
    ret = query(rch, mid+1, r, q, k);
  }
  return ret;
}
void solve() {
  memset(mx+1, 0, sizeof(int)*(n<<2));
  lastAns = 0;
  n = gi();
  m = gi();
  for (int i = 1; i <= n; i++) {
    a[i] = gi();
    put(1, 1, n+1, a[i], i);
  }
  put(1, 1, n+1, n+1, n+1);
  while (m--) {
    int op = gi();
    if (op == 1) {
      int t1 = gi()^lastAns;
      put(1, 1, n+1, a[t1], n+1);
    }
    else {
      int t2 = gi()^lastAns, t3 = gi()^lastAns;
      lastAns = query(1, 1, n+1, t2, t3);
      cout << lastAns << endl;
    }
  }
}
int main() {
  int ks = gi();
  while (ks--) {
    solve();
  }
}

