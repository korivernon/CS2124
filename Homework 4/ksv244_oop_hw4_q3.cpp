#include<iostream>
#include<vector>
using namespace std;
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

void sortMe(int*& arr, const int& size){
    int temp, i, j;
    for(i=0; i < size; i++){		
		for(j = i + 1; j < size; j++){
			if(arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void sortInsert(int*& arr, int& size, const int& val){
    resize(arr,size,size+1); // resize for one new element
    // cout << "Size: " << size << endl;
    arr[size-1] = val; //set the size-1 = to the value
    // printArr(arr,size);
    sortMe(arr,size); // sort the list after placing
}
//get grades function
void getGrades(vector<int>& grades){
    int score;
    do { 
        cout << "Enter in a test score: ";
        cin >> score;
        if (score == -1) break;
        else if (score < 0){
            while (score < -1){
                if (score == -1) break; // user can still enter in a negative score and it will continue thru code
                else {
                    cout << "Enter in a test score: "; //continue to prompt user to enter test score
                    cin >> score;
                }
            }
        }
        grades.push_back(score);
    } while (true);
}
/*
void printHistogram(const vector<int>& grades){
    int size = 0;
    int * arr = new int[size];
    for (int val : grades){ //sort the grades so we can go through and output
        sortInsert(arr,size,val);
    } 
    // printArr(arr,size);
    // int total = 0;
    if (size > 0){
        int total = 1;
        for (int i = 1; i < grades.size(); i++){
            // cout << arr[i] << " iteration " << endl; 
            if (i == size-1){ //stop case
                if (arr[i] == arr[i-1]) // if the last element is not the last instance of it occuring
                    cout << "Number of " << arr[i-1] << "'s: " << ++total << endl;
                else {  if the last element is the only instance of it occuring
                    cout << "Number of " << arr[i-1] << "'s: " << total << endl;
                    cout << "Number of " << arr[i] << "'s: " << 1 << endl;
                }
            } else if (arr[i]==arr[i-1]){
                // cout << "adding to " << arr[i] << endl;
                total++;
            } else if (i == 0){ // this line is redundant 
                total = 1;
            } else if (arr[i]!=arr[i-1]) {
                cout << "Number of "<< arr[i-1] << "'s: " << total << endl;
                total = 1; //start over at the beginning
            }
        }
    } else {cout << "No grades entered. " << endl;}
    // printArr(arr,size);
    delete [] arr;
}
*/
// realizing that i did the problem incorrectly

void printMyHistogram(const int * arr, const int size){ // function to print my histogram
    for (int i = 0; i < size; i++){
        if (arr[i] > 0)
            cout << "Number of " << i << "'s: " << arr[i] << endl;
    }
}
void makeHistogram(vector<int>& grades){
    // cout << "here" << endl;
    int max = 0; //set the max to 0
    for (int i = 0; i < grades.size(); i++){
        if (grades[i] > max){
            max = grades[i]; //determine the max
        }
    }
    // cout << "Max: " << max << endl;
    int * arr = new int[max+1]; //create an array with the max set the the max+1 to account for the max val
    int total = 0; // set the total to 0
    for (int i = 0; i < max+1; i++){ // continue throught the max numbers
        for (int j = 0; j < grades.size(); j++){
            if (i == grades[j]){ // check to see if at any point the grades match up
                // cout << "adding to " << i << " at " << j << endl; // if they match up then increment
                total++;
            } else {
                continue; // otherwise continue
            }
        }
        // cout << i  << ": " << total<< endl; 
        arr[i] = total; // set the array to hold the total number count at that index in the array
        total = 0; // reset the total to 0 to continue throughout the rest of the loop
    }
   // printArr(arr,max+1);
   printMyHistogram(arr, max+1); // pass to function to print
}
int main() {
   // int size = 0;
   // int * arr = new int[size];
    // printArr(arr,0);
    cout << "begin" << endl;
    vector<int> grades;
    getGrades(grades);
    /*
    grades.push_back(20);
    grades.push_back(30);
    grades.push_back(4);
    grades.push_back(20);
    grades.push_back(30);
    grades.push_back(30);
    grades.push_back(50);
    */
    /* output vector
    for (int i : grades){
        cout << i << endl;
    }*/
    // printHistogram(grades);
    makeHistogram(grades);
    cout <<"here"<< endl;
}
