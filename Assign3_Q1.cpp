#include<iostream>
using namespace std;

class Cylinder
{
    double radius;
    double height;
    static double PI;

    public:

    Cylinder(void):radius(10),height(10)
    { }

    Cylinder(double radius,double height):radius(radius),height(height)
    { }

    double getRadius(void)
    {
      return radius;
    }

    void setRadius(double)
    {
        this->radius = radius;
    }

    double getHeight(void)
    {
        return height;

    }

    void setHeight(double)
    {
        this->height=height;
    }

    double calculateVolume(void)
    {
        return PI * radius * radius * radius;

    }

};
double Cylinder::PI=3.14;


int main()
{
    Cylinder c1;
    cout<<"Default volume of Cylinder :"<<c1.calculateVolume()<<endl;

    Cylinder c2(15,20);
    cout<<"Volume of cylinder : "<<c2.calculateVolume()<<endl;

    return 0;

}