#include<iostream>
using namespace std;

int findOccurrences(char* cstr, char toFind){
    if (strlen(cstr)==0) return 0; // this is kind of redundant to the line below... go figure
    if(cstr[0]=='\0') return 0;//we're looking for the end element
    if(cstr[0]!= toFind)return findOccurrences(cstr+1, toFind); //increment through the array if toFind is not detected

    return findOccurrences(cstr+1,toFind)+1; //add to the occurrences because we have found it, and return it so that it can continue through the recursion
}

int main(){
    char cstr[] = "I like cheese";
    cout << "Occurrences: " << findOccurrences(cstr, 'a') << endl;
}
