#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Person{
public:
    virtual void getdata()=0;
    virtual void putdata()=0;
protected:
    string name;
    int age;
};

class Professor : public Person{
    private: 
    int cur_id;
    int static tot_num_prof;
    int publicaitons;
public:
    Professor (): cur_id(tot_num_prof++){};
    void getdata(){
        cin>>name >> age>>publicaitons;
        cur_id++;
    }

    void putdata()override{
        cout<< name<<" "<<age<<" "<<publicaitons<<" "<<cur_id<<endl;
    }

};

class Student : public Person{
public:
    Student():cur_id(tot_num_std++){}
    void getdata() override{
        int exam;
        cur_id++;
        cin>>name >> age;
        for(int i=0; i<6; i++){
            cin>>exam;
            marks.emplace_back(exam);
        }
    }

    void putdata()override{
        int sum{0};
        for(int i:marks){sum+=i;}
        cout<< name<<" "<<age <<" "<<sum<<" "<<cur_id<<endl;
    }
private:
    int cur_id;
    int static tot_num_std;
    vector <int> marks;

};

int Student::tot_num_std = 0;
int Professor::tot_num_prof = 0;
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }
    cout<<endl<<"The output: "<<endl;
    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}