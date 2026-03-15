#include<iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date():day(0),month(0),year(0){}

    Date(int day,int month,int year):day(day),month(month),year(year){}

    void acceptDate()
    {
        cout<<"Day : ";
        cin>>day;
        cout<<"Month : ";
        cin>>month;
        cout<<"Year : ";
        cin>>year;
    }

    void displayDate()
    {
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }
};

class Person
{
private:
    string name;
    string address;
    Date birthDate;

public:
    Person():name(""),address(""){}

    Person(string name,string address,Date birthDate)
        :name(name),address(address),birthDate(birthDate){}

    void acceptPerson()
    {
        cout<<"Name : ";
        cin>>name;

        cout<<"Address : ";
        cin>>address;

        cout<<"Birth Date"<<endl;
        birthDate.acceptDate();
    }

    void displayPerson()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Address : "<<address<<endl;

        cout<<"Birth Date : ";
        birthDate.displayDate();
    }
};

class Student
{
private:
    int id;
    float marks;
    string course;
    Date joinDate;
    Date endDate;

public:
    Student():id(0),marks(0.0),course(""){}

    Student(int id,float marks,string course,Date joinDate,Date endDate)
        :id(id),marks(marks),course(course),joinDate(joinDate),endDate(endDate){}

    void acceptStudent()
    {
        cout<<"Id : ";
        cin>>id;

        cout<<"Marks : ";
        cin>>marks;

        cout<<"Course : ";
        cin>>course;

        cout<<"Join Date"<<endl;
        joinDate.acceptDate();

        cout<<"End Date"<<endl;
        endDate.acceptDate();
    }

    void displayStudent()
    {
        cout<<"Id : "<<id<<endl;
        cout<<"Marks : "<<marks<<endl;
        cout<<"Course : "<<course<<endl;

        cout<<"Join Date : ";
        joinDate.displayDate();

        cout<<"End Date : ";
        endDate.displayDate();
    }
};

int main()
{
    Person p;
    Student s;

    cout<<"Enter Person Details"<<endl;
    p.acceptPerson();

    cout<<"\nEnter Student Details"<<endl;
    s.acceptStudent();

    cout<<"\nPerson Details"<<endl;
    p.displayPerson();

    cout<<"\nStudent Details"<<endl;
    s.displayStudent();

    return 0;
}