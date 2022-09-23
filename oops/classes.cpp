#include<iostream>
using namespace std;
class Student{
    public:
        int rollno;
        int age;
    
    void display(){
        cout<<rollno<<' ';
        cout<<age<<" ";
    }
    Student(int age=0,int rollno=0){
        this->age=age;
        this->rollno=rollno;
    }

};
int main(){
    Student *s1=new Student(10,20);
    Student s2(*s1);
    s1->display();
    s2.display();

}