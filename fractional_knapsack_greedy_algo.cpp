/*
The weights and values of n items are given. The items are such that you can
take a whole item or some fraction of it (divisible). You have a knapsack to
carry those items, whose weight capacity is W. Due to the capacity limit of the
knapsack, it might not be possible to carry all the items at once. In that case,
pick items such that the profit (total values of the taken items) is maximized.
Write a program that takes the weights and values of n items, and the capacity W
of the knapsack from the user and then finds the items which would maximize the
profit using a greedy algorithm.
sample input
n
weight, value
…
W

4
4 20
3 9
2 12
1 7
5

sample output
item 4: 1.0 kg 7.0 taka
item 3: 2.0 kg 12.0 taka
item 1: 2.0 kg 10.0 taka
profit: 29 taka
Possible greedy strategies:
● Pick the lightest item first, then pick the next lightest item and so on.
● Pick the costliest (per-unit value wise) item first, then pick the next
costliest item and so on. (optimal answer) ● Pick the costliest (total value
wise) item first, then pick the next costliest item and so on.
*/

#include <bits/stdc++.h>
using namespace std;

//! This is to pair and print only the total value
bool comp(pair<int, int> a, pair<int, int> b) {
  double ratio1 = (double)a.second / a.first;
  double ratio2 = (double)b.second / b.first;
  return ratio1 > ratio2;
}

void fractional_knapsack(vector<pair<int, int>> &product, int weight) {
  sort(product.begin(), product.end(), comp);

  double total_value = 0.0;
  for (int i = 0; i < product.size(); i++) {
    if (product[i].first <= weight) {
      total_value += product[i].second;
      weight -= product[i].first;
    } else {
      total_value += (double)product[i].second * weight / product[i].first;
      break;
    }
  }
  cout << fixed << setprecision(2) << total_value << endl;
}

/*
//! This is to double pair and print with items numbers
bool comp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
  double ratio1 = (double)a.second.second / a.second.first;
  double ratio2 = (double)b.second.second / b.second.first;
  return ratio1 > ratio2;
}
// Function to solve the fractional knapsack problem
void fractional_knapsack(vector<pair<int, int>> &product, int weight) {
  // Create a new vector to store the items with their original indices
  vector<pair<int, pair<int, int>>> items;
  for (int i = 0; i < product.size(); i++) {
    // Add each item to the new vector with its original index
    items.push_back(make_pair(i + 1, product[i]));
  }

  // Sort the items based on the ratio of value to weight
  sort(items.begin(), items.end(), comp); // Time complexity: O(n log n)

  // Initialize the total value of items in the knapsack to 0
  double total_value = 0.0;

  // Iterate over each item
  for (int i = 0; i < items.size(); i++) {
    // If the item can be added to the knapsack without exceeding the maximum
    // weight
    if (items[i].second.first <= weight) {
      // Print the item's index, weight, and value
      cout << "item " << items[i].first << ": " << items[i].second.first
           << " kg " << items[i].second.second << " taka" << endl;
      // Add the item's value to the total value
      total_value += items[i].second.second;
      // Subtract the item's weight from the remaining weight
      weight -= items[i].second.first;
    } else {
      // If the item can't be added to the knapsack without exceeding the
      // maximum weight Calculate the fraction of the item that can be added
      double fraction = (double)weight / items[i].second.first;
      // Print the item's index, the fraction of its weight that is added, and
      // the fraction of its value that is added
      cout << "item " << items[i].first << ": " << weight << " kg "
           << items[i].second.second * fraction << " taka" << endl;
      // Add the fraction of the item's value to the total value
      total_value += items[i].second.second * fraction;
      // Break the loop since the knapsack is now full
      break;
    }
  }

  // Print the total value of items in the knapsack
  cout << "profit: " << total_value << " taka" << endl;
}
*/
int main() {
  vector<pair<int, int>> product;
  int n, weight, value;

  cin >> n; // Input the number of items
  for (int i = 0; i < n; i++) {
    cin >> weight >> value;
    product.push_back(make_pair(weight, value));
  }

  int max_weight;
  cin >> max_weight;
  fractional_knapsack(product, max_weight);
}
