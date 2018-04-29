#include <bits/stdc++.h>

using namespace std;
#define MAXN_N 10001
#define MAXN_M 10001
double dp[MAXN_M][MAXN_N] ;
int ai[MAXN_N];
double bi[MAXN_N];

int main()
{
	int n,m;
	while(cin>>n>>m){
		for(int i = 0;i <= m;i++){
			cin>>ai[i]>>bi[i];
			bi[i] = 1.0-bi[i];
		}
		for(int i = 0;i <m;i++)
			cout<<bi[i]<<endl;
		memset(dp,0,sizeof(dp));
		for(int i = 0;i < m;i++){
			for(int j = 0;j <=n;j++){
				if(j < ai[i])
					dp[i+1][j] = dp[i][j];
				else{
					if(dp[i][j] > dp[i][j - ai[i]]*bi[i]){
						if(dp[i][j - ai[i]] == 0)
							dp[i+1][j] = bi[i];
						else
							dp[i+1][j] = dp[i][j - ai[i]]*bi[i];
					}
					else{
						dp[i+1][j] = dp[i][j];
					}
				}	
			}
		}
		for(int i = 0;i <= m;i++){
			for(int j = 0;j <= n;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		double ans = (1.0 - dp[m][n]) *100;
		printf("%.1f%%\n",ans);
	}
	return 0;
 } 
