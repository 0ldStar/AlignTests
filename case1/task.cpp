#include <iostream>
#include <vector>

#include "task.h"

using namespace std;

void task() {
    int n, m, count;
    cin >> n >> m;

    vector<vector<int>> polygon;
    vector<vector<int>> pointsArr;
    polygon.resize(2 * n);
    pointsArr.resize(m);
    input(polygon);
    input(pointsArr);
    pointInPolygonCalc(polygon, pointsArr, count);
    cout << count;

}

void input(vector<vector<int>> &arr) {
    int x, y;
    for (auto &i : arr) {
        cin >> x >> y;
        i.push_back(x);
        i.push_back(y);
    }
}

double polygonSquare(vector<vector<int>> &arr) {
    double square = 0;
    for (int i = 3; i <= arr.size() - 1; i += 2) {
        square += arr[i - 2][0] * arr[i][1] - arr[i - 2][1] * arr[i][0];
    }
    square = abs(square) / 2;
    return square;
}

double triangleSquare(int x1, int y1, int x2, int y2, int x3, int y3) {
    double square = 0;
    square += x1 * y2 - y1 * x2;
    square += x2 * y3 - y2 * x3;
    square += x3 * y1 - y3 * x1;
    square = abs(square) / 2;
    return square;
}

double trianglesSquare(vector<vector<int>> &polygon, vector<int> &pointsArr) {
    double square = 0;
    for (int i = 1; i <= polygon.size() - 2; i += 2) {
        square += triangleSquare(polygon[i][0], polygon[i][1], polygon[i + 2][0], polygon[i + 2][1], pointsArr[0],
                                 pointsArr[1]);
    }
    return square;
}

void pointInPolygonCalc(vector<vector<int>> &polygon, vector<vector<int>> &pointsArr, int &count) {
    count = 0;
    polygon.resize(polygon.size() + 2);
    polygon[polygon.size() - 1].push_back(polygon[1][0]);
    polygon[polygon.size() - 1].push_back(polygon[1][1]);
    for (auto & i : pointsArr) {
        if (abs(polygonSquare(polygon) - trianglesSquare(polygon, i)) < 10e-7) count++;
    }
}