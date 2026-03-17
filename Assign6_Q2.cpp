#include<iostream>
using namespace std;

class Employee
{
    protected:
    int id;
    float salary;

    public:
    Employee(void):id(0),salary(0)
    { }
    Employee(int id,float salary) : id(id), salary(salary) 
    { }

    void accept()
    {
        cout<<"Enter Employee ID: "<<endl;
        cin>>id;

        cout<<"Enter Salary: "<<endl;
        cin>>salary;
    }

    void display()
    {
        cout<<"Employee ID: "<<id<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};

class Manager : virtual public Employee
{
protected:
    float bonus;

public:
    Manager():Employee(),bonus(0)
    { }

    void acceptManager()
    {
        cout<<"Enter Bonus: "<<endl;
        cin>>bonus;
    }

    void displayManager()
    {
        cout<<"Bonus: "<<bonus<<endl;
    }
};

class Salesman : virtual public Employee
{
protected:
    float commission;

public:
    Salesman():Employee(),commission(0)
    { }

    void acceptSalesman()
    {
        cout<<"Enter Commission: "<<endl;
        cin>>commission;
    }

    void displaySalesman()
    {
        cout<<"Commission: "<<commission<<endl;
    }
};

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager():Employee(),Manager(),Salesman(){}

    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }

    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};

int menuList()
{
    int choice;

    cout<<" MENU "<<endl;
    cout<<"1. Manager"<<endl;
    cout<<"2. Salesman"<<endl;
    cout<<"3. Sales Manager"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;

    return choice;
}

int main()
{
    int choice;

    while((choice=menuList())!=4)
    {
        switch(choice)
        {
            case 1:
            {
                Manager m;
                m.accept();
                m.acceptManager();
                m.display();
                m.displayManager();
                break;
            }

            case 2:
            {
                Salesman s;
                s.accept();
                s.acceptSalesman();
                s.display();
                s.displaySalesman();
                break;
            }

            case 3:
            {
                SalesManager sm;
                sm.accept();
                sm.display();
                break;
            }

            default:
                cout<<"Invalid choice"<<endl;
        }
    }

    return 0;
}