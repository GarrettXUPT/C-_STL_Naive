#define _CRT_SECURE_NO_WARNINGS

// 对char类型和int类型的数组进行排序
#include<iostream>
#include<stdlib.h>

using namespace std;

template<class T>
void printArr(T* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<class T>
void mySort(T* arr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] < arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4, 5};
    char b[] = {'A', 'B', 'C', 'D', 'E'};
    int len = sizeof(b) / sizeof(b[0]);
    cout << "sort before" << endl;
    printArr(b, len);
    mySort(b, len);
    cout << "sort after" << endl;
    printArr(b, len);
    system("pause");
    return 0;
}
