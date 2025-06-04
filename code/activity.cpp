//code for activity selection problem in C++
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

struct Activity {
    int start, finish;
};


bool activityCompare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(Activity activities[], int n) {
    // Sort activities by finish time
    sort(activities, activities + n, activityCompare);

    cout << "Selected activities (0-based index): ";
    int last = 0;
    cout << last << " ";
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= activities[last].finish) {
            cout << i << " ";
            last = i;
        }
    }
    cout << endl;
}

int main() {
    int n;
    Activity activities[MAX];
    cout << "Enter number of activities: ";
    cin >> n;
    cout << "Enter start and finish times of activities:\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish;
    }
    activitySelection(activities, n);
    return 0;
}