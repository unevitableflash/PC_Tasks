#include <bits/stdc++.h>
using namespace std;

pair<int, int> normalize(int dx, int dy) {
    int g = gcd(abs(dx), abs(dy));
    dx /= g;
    dy /= g;

    // Ensure a consistent representation for slope direction
    // TO ENSURE A CONSISTEN REPRESENTATION FOR SLOPE DIRECTION
    if (dy < 0 || (dy == 0 && dx < 0)) {
        dx = -dx;
        dy = -dy;
    }

    return {dx, dy};
}

// A STRUCTURE USED TO REPRESENT LINE USING ITS SLOPE AND THE BASE POINT
struct Line {
    pair<int, int> slope;
    pair<int, int> base;

    bool operator<(const Line& other) const {
    if (slope.first != other.slope.first)
        return slope.first < other.slope.first;
    if (slope.second != other.slope.second)
        return slope.second < other.slope.second;
    if (base.first != other.base.first)
        return base.first < other.base.first;
    return base.second < other.base.second;
}
};
 
int count(const vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<pair<int, int>> points;  // TO STORE COORDINATES HAVING VALUES 1

    // IN THIS BASICALLY I AM TRYING TO FIND ALL THE 1'S AND STORE THEIR COORDINATES
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                points.emplace_back(i, j);
            }
        }
    }

    set<Line> uniqueLines;

    // EACH POINT IS COMPARED TO EVERY OTHER POINT
    for (int i = 0; i < points.size(); ++i) {
        map<      pair<int, int>    ,    vector<pair<int, int>>     > slopeMap;

        for (int j = 0; j < points.size(); ++j) {
            if (i == j) continue;
            int dx = points[j].first - points[i].first;
            int dy = points[j].second - points[i].second;
            auto slope = normalize(dx, dy);
            slopeMap[slope].push_back(points[j]);
        }

        for (auto it = slopeMap.begin(); it != slopeMap.end(); ++it) 
        {
            pair<int, int> slope = it->first;
            vector<pair<int, int>>& vec = it->second;
            vec.push_back(points[i]);  // INCLUDING THE BASE POINT ALSO
            if (vec.size() >= 3) {      // COLINEAR LINES ARE LINES HAVING 3 OR MORE THAN 3 COMMON POINTS
                sort(vec.begin(), vec.end());
                uniqueLines.insert({slope, vec[0]}); // USING THE SMALLEST POINT AS THE BASE
            }
        }
    }
     
    return uniqueLines.size();

}




int main() {
    int m, n;
    cin >> m >> n;
vector<vector<int>> matrix(m, vector<int>(n));
 
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
           {cin >> matrix[i][j];} 
    }

    cout << count(matrix)<< endl;
     return 0;
}







 