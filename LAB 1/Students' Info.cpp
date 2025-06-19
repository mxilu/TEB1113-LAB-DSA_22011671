#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
    int id;
    string name;
    string email;
    string phone;
    
    void dataInput(){
        cout<<"Enter the student ID: ";cin>>id;
        cout<<"Enter the student name: ";cin>>name;
        cout<<"Enter the student email: ";cin>>email;
        cout<<"Enter the student phone number: ";cin>>phone;
    }
};

int main(){
    int i;
    cout<<"How many students?: ";cin>>i;
    vector<Student> students (i);
    
    for (int j = 0; j < i; j++){
        students[j].dataInput();
    }

    cout << "\nStudent Profiles:\n";
    for (Student s: students){
        cout<<"ID: "<< s.id<<"\nName: "<<s.name<<"\nEmail: "<<s.email<<"\nPhone Number: "<<s.phone<<'\n';
    }    
}