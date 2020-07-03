//lecture 14
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<fstream>
#include<list>
#include<set>
#include<map>
#include<ctime>
#include<algorithm>

using namespace std;

void func(const vector<int>& v){
    for (vector<int>::const_iterator i = v.begin(); i != v.end(); i++){
        cout << *i << endl;
    }
}
class Person {
    string name;
    int age;
public:
    Person(string newname="", int newage = 0) : name(newname), age(newage) {}
    string getName() const {return name;}
    int getAge() const {return age;}
    friend ostream& operator<<(ostream& outs, const Person& p);
};

ostream& operator<<(ostream& outs, const Person& p){
    outs << "Name: " << p.name << "\tName: " << p.age << endl;
    return outs;
}
class CompOnName {
public:
    bool operator()(const Person& p1, const Person& p2){return p1.getName() < p2.getName();}
};
class CompOnAge{
public:
    bool operator()(const Person& p1, const Person& p2){return p1.getAge() < p2.getAge();}
};

int main(){
    vector<Person> p; Person k("Kori",19); p.push_back(k);
    Person l("Joey",20); p.push_back(l); 
    Person d("Daniel",40); p.push_back(d);
    string names[] = {"Jimbo","Huncho","Quavo","Velicia","Alkebulan"};
    srand(time(NULL));
    for (int i = 0; i < 5;i++){
        p.push_back(Person(names[i],rand()%100));
        cout << p[i] << endl;
    }
    set<Person,CompOnAge> pset;
    for (int i = 0; i < p.size();i++){
        pset.insert(p[i]);
    }
    cout << "Sorted" << endl;
    sort(p.begin(),p.end(),CompOnAge());
    for (int i = 0; i < 8; i++)
        cout << p[i] << endl;

    vector<int> v;
    cout << "=====================================" << endl; 
    for (int i = 0; i < 10; i++){
        v.push_back(rand()%100);
    }
    for (int i: v)
        cout << i << endl;
    cout << "sorted :" <<endl;
    sort(v.begin(),v.end());
    for (int i: v)
        cout << i << endl;


    vector<int>::iterator j = v.begin();
    cout << "j[1]: " << j[1] << endl;
    j++;
    cout << "j[1]: " << j[1] << endl;
    
    for (vector<int>::iterator i = v.begin(); i!= v.end(); i++){
        cout << *i << endl;
    }

    for (vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); i++){
        cout << *i << endl;
    } 
    
    cout << "Working With Lists=====================================" << endl; 
    list<int> ls;
    for(int i = 0; i < 10; i ++){
        ls.push_back(i*10);
    }
    for (list<int>::iterator i = ls.begin(); i != ls.end(); i++){
        cout << *i << endl;
    }
    
    list<int>::iterator start = ls.begin();
    start++;

    list<int>::iterator end = ls.end();
    end--;
    ls.erase(start,end);
    for (int i: ls)
        cout << i << endl;

    cout << "Working With Sets=====================================" << endl; 
    //AVL Tree maintains the height property
    //Red Black Tree maintains the color property
    //Red Black Trees performance are better 
    //set<int> s;
    multiset<int> s;
    srand(time(NULL));
    //sets contain no duplicates
    for(int i = 0; i < 10; i++)
        s.insert(rand()%20+1); //insert for sets
    for(int i: s)
        cout << i << endl;
    cout << "Set Iterator" << endl;
    for(multiset<int>::iterator i = s.begin(); i != s.end(); i++){
        cout << *i << endl;
    }
    for(set<Person,CompOnAge>::iterator i = pset.begin(); i != pset.end(); i++){
        cout << *i << endl;
    }
    cout << "AUTO================================" << endl;
    //int x,y; x = 100;y = 20;
    //auto Demo1 = [x,y]()->int return {x/y}
    //auto lessThanOnAge = [] (const Person& p1, const Person& p2) -> bool {return p1.getAge() < p2.getAge();};
    //sort(p.begin(),p.end(),lessThanOnAge);

    cout << "Map================================" << endl;
    // key    value
    map<string, int> m1;
    m1["Daniel"] = 100;
    m1["Betty"] = 90;
    m1["Daniel"] = 99;
    cout << m1["Daniel"] << endl;

    cout << m1["Hiandie"] << endl; //when you access something that doesn't exist, it adds it to the map
    if(m1.find("kori")!= m1.end())
        cout << m1["kori"] << endl;
    // the iterator goes through based on the keys
    
    pair<string, int> p1;
    p1.first = "Daniel";
    p1.second = 100;
    pair<pair<string,int>, pair<double,char> > confusing;

    confusing.first.first = "Daniel";
    confusing.first.second = 100;
    confusing.second.first = 5.5;
    confusing.second.second = 'D';
    for (pair<string,int> p: m1){
        cout << "Name: " << p.first << "\tAge: " <<  p.second << endl;
    }

}
