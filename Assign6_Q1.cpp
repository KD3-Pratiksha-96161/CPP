#include<iostream>
using namespace std;

class Product
{
protected:
    int id;
    string title;
    float price;

public:
    Product(void):id(0),title(""),price(0)
    { }
    Product(int id,string title,float price): id(id), title(title), price(price) 
    { }

    virtual void accept()
    {
        cout<<"Enter ID: ";
        cin>>id;

        cout<<"Enter Title: ";
        cin>>title;

        cout<<"Enter Price: ";
        cin>>price;
    }

    virtual float calculatePrice()=0;

    virtual void display()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"Title: "<<title<<endl;
    }

    virtual ~Product(){}
};

class Book : public Product
{
    string author;

public:
    Book():Product(),author("")
    { }

    void accept()
    {
        Product::accept();
        cout<<"Enter Author: ";
        cin>>author;
    }

    float calculatePrice()
    {
        return price - price*0.10;
    }

    void display()
    {
        Product::display();
        cout<<"Author: "<<author<<endl;
        cout<<"Final Price: "<<calculatePrice()<<endl;
    }
};

class Tape : public Product
{
    string artist;

public:
    Tape():Product(),artist("")
    { }

    void accept()
    {
        Product::accept();
        cout<<"Enter Artist: ";
        cin>>artist;
    }

    float calculatePrice()
    {
        return price - price*0.05;
    }

    void display()
    {
        Product::display();
        cout<<"Artist: "<<artist<<endl;
        cout<<"Final Price: "<<calculatePrice()<<endl;
    }
};

int menuList()
{
    int choice;

    cout<<" MENU "<<endl;
    cout<<"1. Add Book"<<endl;
    cout<<"2. Add Tape"<<endl;
    cout<<"3. Display Bill"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;

    return choice;
}

int main()
{
    Product* arr[3];
    int choice;
    int index=0;
    float total=0;

    while((choice=menuList())!=4)
    {
        switch(choice)
        {
            case 1:
                if(index<3)
                {
                    arr[index]=new Book();
                    arr[index]->accept();
                    index++;
                }
                else
                    cout<<"Only 3 products allowed"<<endl;
                break;

            case 2:
                if(index<3)
                {
                    arr[index]=new Tape();
                    arr[index]->accept();
                    index++;
                }
                else
                    cout<<"Only 3 products allowed"<<endl;
                break;

            case 3:
                cout<<"BILL : ";

                for(int i=0;i<index;i++)
                {
                    arr[i]->display();
                    total += arr[i]->calculatePrice();
                }

                cout<<"Total Bill = "<<total<<endl;
                break;
        }
    }

    for(int i=0;i<index;i++)
        delete arr[i];

    return 0;
}