#include <bits/stdc++.h> 
using namespace std;

// This is a comparator function that will be used to sort the vector of pairs.
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
  double ratio1 =
      (double)a.first / a.second; // Calculate the ratio of the first element of
                                  // the pair to the second for the first pair.
  double ratio2 =
      (double)b.first / b.second; // Calculate the ratio of the first element of
                                  // the pair to the second for the second pair.
  if (ratio1 == ratio2) {         // If the ratios are equal...
    return a.second < b.second; // ...then sort the pairs by the second element
                                // (weight) in ascending order.
  }
  return ratio1 > ratio2; // If the ratios are not equal, sort the pairs by
                          // ratio in descending order.
}

int main() {
  vector<pair<int, int>> w = {
      {10, 12},
      {15, 10},
      {25, 8},
      {30, 5},
      {2, 2}}; // Initialize a vector of pairs with given values.

  sort(w.begin(), w.end(),
       compare); // Sort the vector using the "compare" function defined above.

  cout << "Weights: "; // Print the string "Weights: " to the console.
  for (int i = 0; i < w.size(); i++) { // For each pair in the vector...
    cout << "(" << w[i].first << ", " << w[i].second
         << ") "; // ...print the pair to the console.
  }
  return 0; // Indicate that the program has run successfully.
}
