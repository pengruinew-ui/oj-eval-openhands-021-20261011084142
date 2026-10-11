#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& other) const {
        return x < other.x;
    }
};

vector<Point> points;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    points.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    // Sort points by x-coordinate
    sort(points.begin(), points.end());
    
    long long answer = 0;
    
    // For each pair of points (i, j) where i < j
    // Check if point i can be bottom-left and point j can be top-right
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if points[i] can be bottom-left and points[j] can be top-right
            if (points[i].x < points[j].x && points[i].y < points[j].y) {
                bool valid = true;
                
                // Check if there are any points inside the rectangle
                // Only need to check points between i and j in x-order
                for (int k = i + 1; k < j; k++) {
                    // Check if point k is inside or on the boundary of the rectangle
                    if (points[k].y >= points[i].y && points[k].y <= points[j].y) {
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