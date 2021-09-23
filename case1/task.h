//
// Created by 777 on 23.09.2021.
//

#ifndef ALIGN_1_TASK_H
#define ALIGN_1_TASK_H

#include <vector>

using namespace std;

void task();

void input(vector<vector<int>> &arr);

double polygonSquare(vector<vector<int>> &arr);

double triangleSquare(int x1, int y1, int x2, int y2, int x3, int y3);

double trianglesSquare(vector<vector<int>> &polygon, vector<int> &pointsArr);

void pointInPolygonCalc(vector<vector<int>> &polygon, vector<vector<int>> &pointsArr, int &count);

#endif //ALIGN_1_TASK_H
