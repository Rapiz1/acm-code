/** KMP aģʽ�� bԭ�� 
* ���ƥ��λ�� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=10000+10;
char a[MAXN],b[MAXN];//1...len
int nxt[MAXN],len1,len2;
int main(){
	scanf("%s",a+1);
	len1=strlen(a+1);
	scanf("%s",b+1);
	len2=strlen(b+1);
	//����nxt[] 
	for(int i=2;i<=len1;i++){
		int p=nxt[i-1];
		while(p&&a[p+1]!=a[i]) p=nxt[p];
		if(a[p+1]==a[i]) p++;
		nxt[i]=p;
	}
	int p=0;
	for(int i=1;i<=len2;i++) {
		while(p&&a[p+1]!=b[i]) p=nxt[p];//ʧ�� 
		if(a[p+1]==b[i]) p++;//ƥ�� 
		if(p==len1) printf("%d\n",i-p+1),p=nxt[p];//ƥ��λ�� 
	}
}
