#include <bits/stdc++.h>

using namespace std;
#define MAXN_N 1001
#define MAXN_V 1001
int dp[MAXN_N][MAXN_V];  //记忆化数组
int N[MAXN_N],V[MAXN_V]; //N记录第i个物品的重量，V记录第i个物品的价值 


//递归 时间复杂度O(nW) 
int rec(int i, int j,int n){   //从第i个物品开始挑选总重小于j的部分 ,总共n件物品，从0开始存 
	if(dp[i][j] >= 0){
		//如果计算过直接用 
		return dp[i][j];
	}
	int res;
	if(i == n)   //没有剩余物品了 
		res = 0;
	else if(j < N[i]){  //取不了 
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
