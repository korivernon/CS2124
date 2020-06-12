#include<iostream>

using namespace std;

void resize(int*& arr, int & old, int news){
    int* temp = new int[news];
    if (old > news){
        for (int i = 0; i < news; i++ ){
            temp[i] = arr[i];
        }
    } else {
        for (int i = 0; i < old; i++){
            temp[i] = arr[i];
        }
    }
    delete [] arr;
    arr = temp;
    old = news;
}

void fill(int* arr, const int stop){
    // we are passing the pointer in because we are changing the values
    for (int i = 0; i < stop; i++){
        arr[i] = i;
    }
}
int main() {
    int cap = 10;
    int * arr = new int[cap];

    delete [] arr;
}
