// Kori Vernon
// Quiz 3
#include<iostream>
#include<string>

using namespace std;

void sortMe(int*& arr, const int size){
    // declare a temporary array
    int * tempa = new int[size];
    int temp, i, j;
    for(i=0; i < size; i++){		
		for(j = i + 1; j < size; j++){
			if(arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
       
		}
        tempa[j] = arr[i];
	}
    delete [] arr;
    arr = tempa;
}

int main(){
    int * arr = new int[10];
    for (int i=0; i < 10; i++){
        arr[i] = -(i*i);
    }
    cout << "BEFORE: "; 
    for (int i = 0; i < 10; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;

    sortMe(arr, 10);
    cout << "AFTER: ";
    for (int i = 0; i < 10; i++ ){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
