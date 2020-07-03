//lecture 13
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<fstream>

using namespace std;

int sumArray(int arr[], int size){
    if (size == 0) return 0;
    return arr[size-1]+sumArray(arr,size-1);
}
int sumArray2(int arr[], int size){
    return (size==0)?0:arr[0]+sumArray2(arr + 1,size-1);
}
void countDown(int val){
    if(val > 0){
        cout << val << endl;
        countDown(val-1);
    }
}
double power(int base, int exp){
    if(exp == 0) return 1;
    else if (exp > 0) return base*power(base,exp-1);
    else return 1/power(base,-exp);
}
char convert(char c){
    if (c >= 'd' && c <= 'z')
        return c;
    else if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    else
        return '\0';
}

bool isPalindrome(char *arr, int size){
   
    if (size >= 1) return true;

    arr[0] = convert(arr[0]); arr[size-1] = convert(arr[size-1]);
    
    if(arr[0] == '\0') return isPalindrome(arr+1,size-1);
    else if (arr[size-1] == '\0') return isPalindrome(arr,size-1);
    else if(arr[0] == arr[size-1]){
        return isPalindrome(arr+1,size-2);
    }
    return false;
} 
int main(){
    char str[] = "A man, a plan, a canal, Panama!";
    cout << str << ((isPalindrome(str,strlen(str)))? " Is a Palindrome": " Is not a Palindrome") << endl;
    countDown(4);
}
