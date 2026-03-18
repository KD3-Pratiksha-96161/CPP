#include<iostream>
using namespace std;

class Distance
{
private:
    int feet;
    int inches;

    // to normalize inches (12 inches = 1 foot)
    void normalize()
    {
        if(inches >= 12)
        {
            feet += inches / 12;
            inches = inches % 12;
        }
        else if(inches < 0)
        {
            int borrow = (abs(inches) + 11) / 12;
            feet -= borrow;
            inches += borrow * 12;
        }
    }

public:
    Distance(int f=0, int i=0) : feet(f), inches(i)
    {
        normalize();
    }

    
    Distance operator+(const Distance &d)
    {
        Distance temp(feet + d.feet, inches + d.inches);
        temp.normalize();
        return temp;
    }

    
    Distance operator++()
    {
        ++inches;
        normalize();
        return *this;
    }

    // declare friend -- operator
    friend Distance operator--(Distance &d);

    // >> operator (input)
    friend istream& operator>>(istream &in, Distance &d)
    {
        cout << "Enter feet: ";
        in >> d.feet;
        cout << "Enter inches: ";
        in >> d.inches;
        d.normalize();
        return in;
    }

    // << operator (output)
    friend ostream& operator<<(ostream &out, const Distance &d)
    {
        out << d.feet << " feet " << d.inches << " inches";
        return out;
    }
};

// -- operator (friend function)
Distance operator--(Distance &d)
{
    --d.inches;
    d.normalize();
    return d;
}

int main()
{
    Distance d1, d2, d3;

    cout << "Enter Distance 1:" << endl;
    cin >> d1;

    cout << "Enter Distance 2:" << endl;
    cin >> d2;

    // +
    d3 = d1 + d2;
    cout << "Addition: " << d3 << endl;

    // ++
    ++d1;
    cout << "After ++d1: " << d1 << endl;

    // --
    --d2;
    cout << "After --d2: " << d2 << endl;

    return 0;
}