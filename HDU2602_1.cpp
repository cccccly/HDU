#include <bits/stdc++.h>

using namespace std;
#define MAXN_N 1001
#define MAXN_V 1001
int dp[MAXN_N][MAXN_V];  //���仯����
int N[MAXN_N],V[MAXN_V]; //N��¼��i����Ʒ��������V��¼��i����Ʒ�ļ�ֵ 
// ʱ�临�Ӷ�O(nW) ����Ϊë���Ǳȵݹ�죿 
int main()
{
	int T;
	scanf("%d",&T);
	int n,v;
	while(T--){
		scanf("%d %d",&n,&v);
		memset(dp,0,sizeof(dp));
		for(int i = 0;i < n;i++)
			scanf("%d",&V[i]);
		for(int i = 0;i < n;i++)
			scanf("%d",&N[i]);
		/*�ӵ�i����Ʒ��ʼ��ѡ������С��jʱ���ܼ�ֵ���*/
		for(int i = n-1;i >= 0;i--){   //�������   
			for(int j = 0;j <= v;j++){
				if(j < N[i])
					dp[i][j] = dp[i+1][j];
				else{
					dp[i][j] = max(dp[i+1][j],dp[i+1][j-N[i]] + V[i]);
				}
			}
		}
		printf("%d\n",dp[0][v]);
		
		
		/* dp[i+1][j]��0��i��i+1����Ʒ��ѡ��������������j����Ʒʱ�ܼ�ֵ�����ֵ  */ 
		
		for(int i = 0;i <= n-1;i++){
			for(int j = 0;j <= v;j++){
				if(j < N[i]){     //��i���ò��� 
					dp[i+1][j] = dp[i][j];
				}
				else{
					dp[i+1][j] = max(dp[i][j],dp[i][j - N[i]] + V[i]);
				}
			}
		} 
		printf("%d\n",dp[n][v]);
	}
	return 0;
}
