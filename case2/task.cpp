#include "task.h"
#include <iostream>
#include <vector>
#include <cmath>

#define X0 0
#define Y0 0
#define RADIUS 80
#define RANGE 10

using namespace std;

void task() {
    int N;
    vector<vector<int>> inArr;
    vector<vector<int>> outArr;

    cin >> N;

    arrayInit(inArr, N);
    arraySort(inArr, outArr);
    output(outArr);
}

void arraySort(vector<vector<int>> &inArr, vector<vector<int>> &outArr) {
    double length;
    for (int i = 0; i < inArr.size(); ++i) {
        length = lenCalc(inArr[i]);
        if (length < RANGE) {
            outArr.resize(outArr.size() + 1);
            outArr[outArr.size() - 1].push_back(inArr[i][0]);
            outArr[outArr.size() - 1].push_back(inArr[i][1]);
        }
    }
    bubbleSort(outArr);
}

void arrayInit(vector<vector<int>> &arr, int N) {
    arr.resize(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2; ++j) {
            arr[i].push_back(rand() % 200 - 100);
        }
    }
}

void output(vector<vector<int>> &arr) {
    for (vector<int> &x:arr) {
        cout << x[0] << "," << x[1] << endl;
    }
}

double angleCalc(vector<int> arr) {
    double cathetusA = arr[0] - X0;
    double cathetusB = arr[1] - Y0;
    return atan(cathetusA / cathetusB);
}

double lenCalc(vector<int> arr) {
    double length = sqrt(pow(arr[0] - X0, 2) + pow(arr[1] - Y0, 2));
    if (length > RADIUS) length -= RADIUS;
    if (length < RADIUS) length = RADIUS - length;
    return length;
}

void bubbleSort(vector<vector<int>> &arr) {
    int i, j;
    unsigned int n;

    n = arr.size();
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (angleCalc(arr[j]) > angleCalc(arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


