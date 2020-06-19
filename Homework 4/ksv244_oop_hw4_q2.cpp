#include<iostream>
using namespace std;
//just to help with output

void printArr(const int * arr, const int& size){
    cout << "{";
    for (int i = 0; i < size; i++){
        if (i!= size-1)
            cout << arr[i] << ",";
        else
            cout << arr[i];
    }
    cout << "}" << endl;
}
// resize function to easily resize
void resize(int*& arr, int& oldsize, const int& newsize){
    int * temp = new int[newsize];
    if (oldsize > newsize){
        for (int i = 0; i < newsize; i++){
            temp[i] = arr[i];
        }
    } else {
        for (int i = 0; i < oldsize; i++){
            temp[i] = arr[i];
        }
    }
    delete [] arr;
    arr = temp;
    oldsize = newsize;
}
// this sorts the array
void sortMe(int* arr, const int& size){
    for(int i=0; i < size; i++){		
		for(int j = i + 1; j < size; j++){
			if(arr[i] > arr[j]){
                arr[j] = (arr[i]+arr[j])-(arr[i]=arr[j]); //in line swap
			}
		}
	}
}
//this combines everything
void sortInsert(int*& arr, int& size, const int& val){
    // cout << "Before: ";
    // printArr(arr, size);
    resize(arr,size,size+1); // resize for one new element
    arr[size-1] = val; //set the size-1 = to the value
    // cout << "Middle: "; 
    // printArr(arr, size);
    sortMe(arr,size); // sort the list after placing
    // cout << "After: ";
    // printArr(arr, size);
}

void addToSorted(int*& arr, int& size, int newE){
    int* temp = new int[size+1];
    int tempPtr = 0;
    bool adv = false;
    for (int i = 0; i < size; i++){
        if(adv == false && newE < arr[i]){
            arr[tempPtr++] = newE;
            adv = true;
        }
        temp[tempPtr++] = i;
    }
    if (adv == false)
        temp[tempPtr++] = newE;
    size++;
    delete [] arr;
    arr = temp;
}

int main() {
    cout << "Filling Array 1-10: ";
    int * arr = new int[10];
    for(int i = 0; i < 10; i++){
        arr[i] = i+1;
    }
    int size = 10;
    printArr(arr, size);
    cout << "Inserting -2: ";
    sortInsert(arr,size,-2);
    printArr(arr,size);
    // cout << "Bye" << endl;
    delete [] arr;
}
