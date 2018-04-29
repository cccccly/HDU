#include <bits/stdc++.h>

using namespace std;
#define MAXN_N 1001
#define MAXN_V 1001
int dp[MAXN_N][MAXN_V];  //���仯����
int N[MAXN_N],V[MAXN_V]; //N��¼��i����Ʒ��������V��¼��i����Ʒ�ļ�ֵ 


//�ݹ� ʱ�临�Ӷ�O(nW) 
int rec(int i, int j,int n){   //�ӵ�i����Ʒ��ʼ��ѡ����С��j�Ĳ��� ,�ܹ�n����Ʒ����0��ʼ�� 
	if(dp[i][j] >= 0){
		//��������ֱ���� 
		return dp[i][j];
	}
	int res;
	if(i == n)   //û��ʣ����Ʒ�� 
		res = 0;
	else if(j < N[i]){  //ȡ���� 
		res = rec(i + 1,j,n);
	}
	else{
		res = max(rec(i + 1,j,n),rec(i+1,j-N[i],n)+V[i]);
	}
	return dp[i][j] = res;
}

int main()
{
	int T;
	scanf("%d",&T);
	int n,v;
	while(T--){
		scanf("%d %d",&n,&v);
		memset(dp,-1,sizeof(dp));
		for(int i = 0;i < n;i++)
			scanf("%d",&V[i]);
		for(int i = 0;i < n;i++)
			scanf("%d",&N[i]);
		printf("%d\n",rec(0,v,n));
	}
	return 0;
}
