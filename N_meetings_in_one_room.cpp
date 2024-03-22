/*
There is one meeting room in a firm. There are N meetings in the form of
(start[i], end[i]) where start[i] is start time of meeting i and end[i] is
finish time of meeting i. What is the maximum number of meetings that can be
accommodated in the meeting room when only one meeting can be held in the
meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the
other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output:
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
Example 2:

Input:
N = 3
start[] = {10, 12, 20}
end[] = {20, 25, 30}
Output:
1
Explanation:
Only one meetings can be held
with given start and end timings.

Your Task :
You don't need to read inputs or print anything. Complete the function
maxMeetings() that takes two arrays start[] and end[] along with their size N as
input parameters and returns the maximum number of meetings that can be held in
the meeting room.


Expected Time Complexity : O(N*LogN)
Expected Auxilliary Space : O(N)


Constraints:
1 ≤ N ≤ 105
0 ≤ start[i] < end[i] ≤ 105

*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Function to find the maximum number of activities that can be performed by a
// single person
int maxActivities(
    vector<int> start, vector<int> end,
    int n) { // Create a vector of pairs where each pair is a meeting
  // The first element of the pair is the end time and the second element is the
  // start time
  vector<pair<int, int>> activity(n);
  for (int i = 0; i < n; i++) {
    activity[i] = {end[i], start[i]};
  }

  // Sort the meetings by their end times
  sort(activity.begin(), activity.end());
  // The first meeting is always selected
  int count = 1;
  int end_time = activity[0].first;

  // For each remaining meeting, if its start time is greater than the end time
  // of the last selected meeting, select it
  for (int i = 1; i < n; i++) {
    if (activity[i].second > end_time) {
      count++;
      end_time = activity[i].first;
    }
  }
  return count;
}

int main() {
  int n;
  cin >> n;
  vector<int> start(n);
  vector<int> end(n);
  for (int i = 0; i < n; i++) {
    cin >> start[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> end[i];
  }
  // std::vector<int> start = {86, 32, 31, 98, 37, 65, 98, 71, 99, 58, 59, 32,
  // 52, 69, 15, 75, 4, 86, 57, 36, 83, 18, 58, 50, 43, 29, 98, 53, 80, 5, 89,
  // 73, 8, 97, 17, 100, 9, 21, 55, 55, 32, 74, 60, 32, 87, 72};
  // std::vector<int> end = {54, 126, 112, 134, 138, 89, 118, 107, 124, 126, 83,
  // 133, 64, 124, 109, 108, 132, 111, 95, 82, 106, 86, 118, 82, 78, 92, 55,
  // 128, 121, 118, 95, 94, 110, 111, 146, 124, 148, 95, 146, 109, 61, 93, 126,
  // 74, 76, 110, 78, 91};
  int x = maxActivities(start, end, n);
  std::cout << x << std::endl;
  return 0;
}
