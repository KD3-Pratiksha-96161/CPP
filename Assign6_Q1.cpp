#include<iostream>
using namespace std;

class Product
{
protected:
    int id;
    string title;
    float price;

public:
    virtual void accept()
    {
        cout<<"Enter ID: ";
        cin>>id;

        cout<<"Enter Title: ";
        cin>>title;

        cout<<"Enter Price: ";
        cin>>price;
    }

    virtual void display()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
    }

    virtual float calculatePrice() = 0;

    virtual ~Product() {}  
};

class Book : public Product
{
    string author;

public:

    void accept()
    {
        Product::accept();
        cout<<"Enter Author: ";
        cin>>author;
    }

    void display()
    {
        Product::display();
        cout<<"Author: "<<author<<endl;
    }

    float calculatePrice()
    {
        return price - (price * 0.10); 
    }
};

class Tape : public Product
{
    string artist;

public:

    void accept()
    {
        Product::accept();
        cout<<"Enter Artist: ";
        cin>>artist;
    }

    void display()
    {
        Product::display();
        cout<<"Artist: "<<artist<<endl;
    }

    float calculatePrice()
    {
        return price - (price * 0.05);
    }
};

int main()
{
    Product* arr[3];
    int choice;

    for(int i=0;i<3;i++)
    {
        cout<<"\n1. Book\n2. Tape\n";
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
            arr[i] = new Book();
        else
            arr[i] = new Tape();

        arr[i]->accept();
    }

    float totalBill = 0;

    cout<<"\nProduct Details\n";

    for(int i=0;i<3;i++)
    {
        arr[i]->display();
        float finalPrice = arr[i]->calculatePrice();

        cout<<"Final Price after discount: "<<finalPrice<<endl;
        cout<<"   "<<endl;

        totalBill += finalPrice;
    }

    cout<<"\nTotal Bill = "<<totalBill<<endl;

    
    for(int i=0;i<3;i++)
        delete arr[i];

    return 0;
}