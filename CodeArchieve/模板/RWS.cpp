#include<cstdio> 
#include<cstdlib>
#include<ctime>
const int N=20;
const int T=1000;
int RWS(){//��1...n�Ȳ������ʲ��ó����
	double unit=2/double(N*N+N),now=0,r=(double)(rand()%1000)/1000,m=0;
	for(int i=N;i>=1;i--){
		m=m+(now+=unit);
		if(r<=m) return i;
	}
	return N;
}
int main(){
	freopen("rws.out","w",stdout);
	for(int i=1;i<=T;i++) printf("%d ",RWS());
}
