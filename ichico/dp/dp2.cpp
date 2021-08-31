//정수삼각형
#include <stdio.h>

int dp[501][501];
int row[501];

int main(){
	int i, j;
	int n;
	int max;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		for (j = 0; j < i; j++){
			scanf("%d", &row[j]);
			if (j == 0) dp[i][j] = row[j] + dp[i - 1][j];
			if (j == i - 1) dp[i][j] = row[j] + dp[i - 1][j - 1];
			else
				dp[i][j] = row[j] + ((dp[i - 1][j - 1] >= dp[i - 1][j]) ? dp[i - 1][j - 1] : dp[i - 1][j]);
		}
	}
	max = 0;
	for (int k = 0; k < n; k++){
		if (max < dp[n][k]) max = dp[n][k];
	}
	printf("%d", max);

	return 0;
}