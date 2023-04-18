#include<iostream>
#include <limits.h>
#include<math.h>

using namespace std;

int doCal(int cap, int n, int profit[], int weight[]) {

	//dp array
	int dp[cap + 1];
	for (int i = 0; i <= cap; i++) {
		dp[i] = 0;
	}

	for (int i = 1; i < n + 1; i++) {
		for (int w = cap; w >= 0; w--) {
			if (weight[i - 1] <= w) {
				dp[w] = max(dp[w], dp[w - weight[i - 1]] + profit[i - 1]);
			}
		}
	}
	return dp[cap];
}

int main() {
	int profit[] = {60, 100, 120};
	int weight[] = {10, 20, 30};
	int n = 3;
	int cap = 50;
	cout << "Answer is : " << doCal(cap, n, profit, weight);

	return 0;
}