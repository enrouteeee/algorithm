//연산자 끼워넣기
#include<stdio.h>

int A[105];
int O[4];
int n;
int max = -9876543210;
int min = 9976543210;
void dfs(int h, int result) {
	int temp = result;
	if (h >= n) {
		if (max < result) max = result;
		if (min > result) min = result;
	}

	else {
		for (int i = 0; i < 4; i++) {
			if (O[i] > 0) {
				O[i]--;
				if (i == 0) {
					result += A[h];
				}
				else if (i == 1) {
					result -= A[h];
				}
				else if (i == 2) {
					result *= A[h];
				}
				else{
					result /= A[h];
				}
				dfs(h + 1, result);
				result = temp;
				O[i]++;
			}
		}
	}
}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}


	for (int i = 0; i < 4; i++) {
		scanf("%d", &O[i]);
	}

	dfs(1, A[0]);

	printf("%d\n%d", max, min);

	return 0;
}