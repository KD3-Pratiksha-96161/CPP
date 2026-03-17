#include<iostream>
using namespace std;

class Employee
{
protected:
    int id;
    double salary;

public:

    Employee():id(0),salary(0)
    {}

    
    Employee(int id,double salary):id(id),salary(salary)
    {}

    virtual void accept()
    {
        cout<<"Enter ID: "<<endl;
        cin>>id;

        cout<<"Enter Salary: "<<endl;
        cin>>salary;
    }

    virtual void display()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};

class Manager : virtual public Employee
{
protected:
    double bonus;

public:
    Manager():Employee(),bonus(0){}

    Manager(int id,double salary,double bonus)
        :Employee(id,salary),bonus(bonus){}

    void acceptManager()
    {
        Employee::accept();
        cout<<"Enter Bonus: "<<endl;
        cin>>bonus;
    }

    void displayManager()
    {
        Employee::display();
        cout<<"Bonus: "<<bonus<<endl;
    }
};

class Salesman : virtual public Employee
{
protected:
    double commission;

public:
    Salesman():Employee(),commission(0){}

    Salesman(int id,double salary,double commission)
        :Employee(id,salary),commission(commission){}

    void acceptSalesman()
    {
        Employee::accept();
        cout<<"Enter Commission: "<<endl;
        cin>>commission;
    }

    void displaySalesman()
    {
        Employee::display();
        cout<<"Commission: "<<commission<<endl;
    }
};

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager():Employee(),Manager(),Salesman(){}

    SalesManager(int id,double salary,double bonus,double commission)
        :Employee(id,salary),Manager(id,salary,bonus),Salesman(id,salary,commission){}

    void acceptSalesManager()
    {
        Employee::accept();
        cout<<"Enter Bonus: "<<endl;
        cin>>bonus;
        cout<<"Enter Commission: "<<endl;
        cin>>commission;
    }

    void displaySalesManager()
    {
        Employee::display();
        cout<<"Bonus: "<<bonus<<endl;
        cout<<"Commission: "<<commission<<endl;
    }
};

int menuList()
{
    int choice;

    cout<<endl;
    cout<<"1. Add Manager"<<endl;
    cout<<"2. Add Salesman"<<endl;
    cout<<"3. Add SalesManager"<<endl;
    cout<<"4. Display Count"<<endl;
    cout<<"5. Display All Managers"<<endl;
    cout<<"6. Display All Salesman"<<endl;
    cout<<"7. Display All SalesManagers"<<endl;
    cout<<"8. Exit"<<endl;

    cout<<"Enter choice: ";
    cin>>choice;

    return choice;
}

int main()
{
    Manager m[10];
    Salesman s[10];
    SalesManager sm[10];

    int mCount=0;
    int sCount=0;
    int smCount=0;

    int choice;

    while((choice=menuList())!=8)
    {
        switch(choice)
        {
            case 1:
                m[mCount].acceptManager();
                mCount++;
                break;

            case 2:
                s[sCount].acceptSalesman();
                sCount++;
                break;

            case 3:
                sm[smCount].acceptSalesManager();
                smCount++;
                break;

            case 4:
                cout<<"Managers: "<<mCount<<endl;
                cout<<"Salesman: "<<sCount<<endl;
                cout<<"SalesManagers: "<<smCount<<endl;
                break;

            case 5:
                for(int i=0;i<mCount;i++)
                {
                    cout<<endl;
                    m[i].displayManager();
                }
                break;

            case 6:
                for(int i=0;i<sCount;i++)
                {
                    cout<<endl;
                    s[i].displaySalesman();
                }
                break;

            case 7:
                for(int i=0;i<smCount;i++)
                {
                    cout<<endl;
                    sm[i].displaySalesManager();
                }
                break;
        }
    }

    return 0;
}