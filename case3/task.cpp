//
// Created by 777 on 23.09.2021.
//
#include <iostream>
#include <list>
#include "task.h"

using namespace std;

void task() {
    list<int> arr;
    input(arr);
    cout << minCountCalc(arr, 0);
}

void input(list<int> &arr) {
    char c = ' ';
    int x;
    while (c != '\n') {
        scanf("%d", &x);
        arr.push_back(x);
        scanf("%c", &c);
    }
}

// Функция поиска минимума и удаления его из списка(разжимаем звенья)
int findMin(list<int> &arr) {
    auto j = arr.begin();
    int min = INT_MAX;
    for (auto x:arr) {
        if (x < min) min = x;
    }
    while (j != arr.end()) {
        if (*j == min) {
            j = arr.erase(j);
            break;
        } else {
            j++;
        }
    }
    return min;
}

// Рекурсивная функция подсчета количества звеньев для разжатия
int minCountCalc(list<int> &arr, int value) {
    int minElement;
    if (arr.empty()) return 0;
    minElement = findMin(arr);
    if (minElement + value <= arr.size() - 1) {  // Если хватит звеньев минимального фрагмента и тех, что уже разжали
        minElement += value;
        if (minElement == arr.size() - 1)
            return minElement; // если минимального фрагмента и уже разжатых ровно столько, сколько нужно
        else {
            return minCountCalc(arr, minElement);
        }
    } else return arr.size() + value; // Если минимальный фрагмент слишком большой
}