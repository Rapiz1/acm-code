/** ����˷� 
* a �� m*p �ľ���b �� p*n �ľ��� ��c �� m*n �ľ��� 
*/
#include<iostream>
using namespace std;
const int MAXN=1000+10;
int a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN],m,p,n;
int main(){
	cin>>m>>p>>n;
	for(int i=1;i<=m;i++) for(int j=1;j<=p;j++) cin>>a[i][j];
	for(int i=1;i<=p;i++) for(int j=1;j<=n;j++) cin>>b[i][j];
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) for(int k=1;k<=p;k++)
		c[i][j]+=a[i][k]*b[k][j];
	for(int i=1;i<=m;i++,cout<<endl) for(int j=1;j<=n;j++) cout<<c[i][j]<<' ';
}
