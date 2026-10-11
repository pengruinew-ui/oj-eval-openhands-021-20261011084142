#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y, idx;
    bool operator<(const Point& other) const {
        return x < other.x;
    }
};

vector<Point> points;
vector<int> y_coords;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    points.resize(n);
    y_coords.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        y_coords[i] = points[i].y;
    }
    
    // Sort and compress y-coordinates
    sort(y_coords.begin(), y_coords.end());
    y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());
    
    for (int i = 0; i < n; i++) {
        points[i].y = lower_bound(y_coords.begin(), y_coords.end(), points[i].y) - y_coords.begin();
        points[i].idx = i;
    }
    
    // Sort points by x-coordinate
    sort(points.begin(), points.end());
    
    long long answer = 0;
    
    // For each point as potential bottom-left corner
    for (int i = 0; i < n; i++) {
        int min_y = points[i].y;
        
        // Look for points to the right that can be top-right corners
        for (int j = i + 1; j < n; j++) {
            if (points[j].y > min_y) {
                bool valid = true;
                
                // Check if there are any points between i and j that interfere
                for (int k = i + 1; k < j; k++) {
                    if (points[k].y >= min_y && points[k].y <= points[j].y) {
                        valid = false;
                        break;
                    }
                }
                
                if (valid) {
                    answer++;
                }
            }
        }
    }
    
    cout << answer << endl;
    
    return 0;
}