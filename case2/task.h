//
// Created by 777 on 23.09.2021.
//

#ifndef ALIGN_2_TASK_H
#define ALIGN_2_TASK_H

#include <vector>

using namespace std;

void task();

void arrayInit(vector<vector<int>> &arr, int N);

void arraySort(vector<vector<int>> &inArr, vector<vector<int>> &outArr);

void output(vector<vector<int>> &arr);

void bubbleSort(vector<vector<int>> &arr);

double lenCalc(vector<int> arr);

double angleCalc(vector<int> arr);

#endif //ALIGN_2_TASK_H
