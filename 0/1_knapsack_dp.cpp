#include <bits/stdc++.h>
using namespace std;

// Function to solve the 0/1 knapsack problem
int knapSack(int W, vector<int> wt, vector<int> val, int n) {
  // Create a 2D vector to store the maximum value for each subproblem
  vector<vector<int>> K(n + 1, vector<int>(W + 1));

  // Build table K[][] in bottom up manner
  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
      if (i == 0 || w == 0)
        K[i][w] = 0;
      else if (wt[i - 1] <= w)
        K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
      else
        K[i][w] = K[i - 1][w];
    }
  }

  // Return the result
  return K[n][W];
}

// Driver code
int main() {
  vector<int> val = {60, 100, 120};
  vector<int> wt = {10, 20, 30};
  int W = 50;
  int n = val.size();
  cout << knapSack(W, wt, val, n);
  return 0;
}
