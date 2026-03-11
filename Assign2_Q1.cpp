
#include<iostream>
using namespace std;
class Box
{
    private:
    int length;
    int width;
    int height;
    

    public:
    Box(void)
    {
        length=10;
        width=10;
        height=10;
    }
    Box(int a)
    {
       length = a;
       width = a;
       height = a;

    }
    Box(int l, int w, int h)
    {
        length=l;
        width=w;
        height=h;
        
    }
    int calculateVolume()
    {
        
       return length*width*height;
       
    }
  

};
 int menuList(void)
    {
        int choice;
        cout<<"0.Exit."<<endl;
        cout<<"1.Calculate Volume with default values."<<endl;
        cout<<"2.Calculate Volume with length,breadth and height with same value"<<endl;
        cout<<"3.Calculate Volume with different length,breadth and height values."<<endl;

        cout<<"Enter choice";
        cin>>choice;
        return choice;

    }
int main()
{

    int choice;
    while((choice = menuList()) != 0)
    {
        switch(choice)
        {
            case 1: 
            {
            Box b1;
            cout<<"Volume = "<<b1.calculateVolume()<<endl;
            break;
            }

            case 2:
            {
            int value;     
            cout<<"Enter a value : ";
            cin>>value;
            Box b2(value);
            cout<<"Volume  = "<<b2.calculateVolume()<<endl;
            break;
            }

            case 3: 
            {
            int length,width,height;
            cout<<"Enter length,width,height : ";
            cin>>length>>width>>height;
            Box b3(length,width,height);
            cout<<"Volume  = "<<b3.calculateVolume()<<endl;
            break;
            }

        }
    }
    return 0;

}