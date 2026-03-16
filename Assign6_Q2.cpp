#include<iostream>
using namespace std;

class Employee
{
protected:
    int id;
    float salary;

public:
    void accept()
    {
        cout<<"Enter ID: ";
        cin>>id;

        cout<<"Enter Salary: ";
        cin>>salary;
    }

    void display()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};

class Manager : public Employee
{
    float bonus;

public:
    void acceptManager()
    {
        accept();
        cout<<"Enter Bonus: ";
        cin>>bonus;
    }

    void displayManager()
    {
        display();
        cout<<"Bonus: "<<bonus<<endl;
    }
};

class Salesman : public Employee
{
    float commission;

public:
    void acceptSalesman()
    {
        accept();
        cout<<"Enter Commission: ";
        cin>>commission;
    }

    void displaySalesman()
    {
        display();
        cout<<"Commission: "<<commission<<endl;
    }
};

int main()
{
    Manager m;
    Salesman s;

    cout<<"Enter Manager Details"<<endl;
    m.acceptManager();

    cout<<"\nEnter Salesman Details"<<endl;
    s.acceptSalesman();

    cout<<"\nManager Details"<<endl;;
    m.displayManager();

    cout<<"\nSalesman Details"<<endl;
    s.displaySalesman();

    return 0;
}