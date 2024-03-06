#include <bits/stdc++.h>
using namespace std;

int minimumDays (int s, int n, int m){
    int sundays = s / 7;
    int shop_open_days = s - sundays;
    int needed_days = s*m / n;
    if (s*m % n != 0){
        needed_days++;
    }
    if(shop_open_days < needed_days){
        return -1;
    }
    return needed_days;
}

int main (){
    int s, n, m;
    cin >> s >> n >> m;
    if (minimumDays (s, n, m) == -1){
        cout << "No"<< endl;
}else
{
    cout << "Yes "<<minimumDays (s, n, m) << endl;
}
    return 0;
}
