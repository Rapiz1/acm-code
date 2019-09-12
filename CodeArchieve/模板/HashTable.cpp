/** �ַ�����ϣ�� 
* ��������ͻ 
* �����ַ������� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef unsigned long long ULL;
struct HT{
	//ģ��MOD���ַ�����󳤶�LEN���ַ����������MAXN 
	static const ULL MOD=1e6+3,LEN=20+10,MAXN=1e5+1,SEED=171;
	int head[MOD],nxt[MAXN],cnt[MAXN],sz;
	char st[MAXN][LEN];
	ULL hash(char*s){
		ULL hv=0;
		while(*s) hv=hv*SEED+*(s++),hv%=MOD;
		return hv;
	}
	HT(){memset(this,0,sizeof(this));}
	void insert(char*s){
		int hv=hash(s),idx=head[hv];
		while(idx&&strcmp(st[idx],s)) idx=nxt[idx];
		if(!idx) {
			nxt[idx=++sz]=head[hv];
			head[hv]=sz;
			strcpy(st[sz],s);
		}
		cnt[idx]++;
	}
	int count(char*s){
		int hv=hash(s),idx=head[hv];
		while(idx&&strcmp(st[idx],s)) idx=nxt[idx];
		return cnt[idx];
	}
}ht;
int main(){
	char buf[20+10];
	//n���ַ����� m��ѯ�� 
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>buf,ht.insert(buf);
	cin>>m;
	for(int i=1;i<=m;i++) cin>>buf,cout<<ht.count(buf)<<endl;
}
