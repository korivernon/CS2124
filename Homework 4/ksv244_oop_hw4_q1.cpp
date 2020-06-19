#include<iostream>
using namespace std;

// this uses size of, but only works for max 8 ch
// THIS DOES NOT WORK. PLEASE IGNOAR
/*
void reversecstr(char *& cstr){
    char * temp = new char[sizeof(cstr)];
    size_t j = sizeof(cstr)-1;
    cout << "Size: " << j+1 << endl;
    for(int i = 0; i < sizeof(cstr)/2; i++){
        temp[i] = cstr[j];
        temp[j] = cstr[i];
        j--;
    }
    if (sizeof(cstr)%2 != 0){
        temp[(sizeof(cstr)/2)+1] = cstr[(sizeof(cstr)/2)+1];
    }
    //  delete [] cstr;
    cstr = temp;
}
*/
void reverseCstr(char* cstr){
    int size = strlen(cstr); // get the size of str
    // cout << "Size: " << size << endl; 
    char *begn, *end; // declare begin and end poitner
    begn = end = cstr; // set the beginning and end equal to the beginning 
    for(int i = 0; i < size-1; i++){
        end++; //move the end pointer to the last element in the array
    }
    for (int i = 0; i < size/2; i++){
        *begn = (*end+*begn)-(*end=*begn); // inline swap
        begn++; // increment the beginning
        end--; // decrement the end
    }
}
// not really needed bc we can use printf... 
void printcstr(const char * cstr){
    for (size_t i = 0; i < sizeof(cstr); i++){
        cout << cstr[i];
    }
    cout << endl;
}

//katz function
void reverseIt(char* cstr){
    char* front = cstr;
    char* rear;
    for(rear = cstr; *(rear+1) != '\0'; rear++); // this searches for the lenght

    for (; front < rear; front++,rear--){
        *rear = (*front+*rear) - (*front=*rear);
    }
}
int main() {
    char str[100] = "strng\0";
    cout << "Before: ";
    printf("Before: %s\n",str);
    cout << "After: ";
    reverseCstr(str);
    printf("Reverse: %s\n",str);
    char cstr[100] = "h my name is kori\0";
    reverseCstr(cstr);
    reverseIt(cstr);
    printf("Reverse: %s\n",cstr);
}
