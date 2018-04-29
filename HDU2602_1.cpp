#include <bits/stdc++.h>

using namespace std;
#define MAXN_N 1001
#define MAXN_V 1001
int dp[MAXN_N][MAXN_V];  //记忆化数组
int N[MAXN_N],V[MAXN_V]; //N记录第i个物品的重量，V记录第i个物品的价值 
// 时间复杂度O(nW) 但是为毛就是比递归快？ 
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
		/*从第i个物品开始挑选总重量小于j时，总价值最大*/
		for(int i = n-1;i >= 0;i--){   //逆向求解   
			for(int j = 0;j <= v;j++){
				if(j < N[i])
					dp[i][j] = dp[i+1][j];
				else{
					dp[i][j] = max(dp[i+1][j],dp[i+1][j-N[i]] + V[i]);
				}
			}
		}
		printf("%d\n",dp[0][v]);
		
		
		/* dp[i+1][j]从0到i这i+1个物品中选出总重量不超过j的物品时总价值的最大值  */ 
		
		for(int i = 0;i <= n-1;i++){
			for(int j = 0;j <= v;j++){
				if(j < N[i]){     //第i个拿不了 
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
