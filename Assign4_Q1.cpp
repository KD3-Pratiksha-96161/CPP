#include<iostream>
using namespace std;

class Time
{
private:
    int h;
    int m;
    int s;

public:
    Time(void):h(0),m(0),s(0)
    { }

    Time(int h, int m, int s):h(h),m(m),s(s)
    { }
    
    void setHour(int h)
    {
        this->h = h;
    }

    void setMinute(int m)
    {
        this->m = m;
    }

    void setSeconds(int s)
    {
        this->s = s;
    }

    int getHour(void)
    {
        return h;
    }

    int getMinute(void)
    {
        return m;
    }

    int getSecond(void)
    {
        return s;
    }

    void printTime()
    {
        cout<<h<<":"<<m<<":"<<s<<endl;
    }
};

int menulist()
{
    int choice;

    cout<<"0. EXIT"<<endl;
    cout<<"1. Add Time"<<endl;
    cout<<"2. Display All Time"<<endl;
    cout<<"3. Display only hrs of all time objects"<<endl;
    cout<<"Enter the choice : ";

    cin>>choice;

    return choice;
}

int main()
{
    int n;
    cout<<"Enter number of Time objects : ";
    cin>>n;

    Time *t = new Time[n];

    int choice;

    while((choice = menulist()) != 0)
    {
        if (choice == 1)
        {
            for (int i = 0; i < n; i++)
            {
                int h, m, s;
                cout << "Enter hour minute second for object " << i + 1 << ": ";
                cin >> h >> m >> s;

                t[i].setHour(h);
                t[i].setMinute(m);
                t[i].setSeconds(s);
            }
        }
        else if (choice == 2)
        {
            cout << "\nAll Time Objects:\n";
            for (int i = 0; i < n; i++)
            {
                t[i].printTime();
            }
        }
        else if (choice == 3)
        {
            cout << "\nHours of all Time Objects:\n";
            for (int i = 0; i < n; i++)
            {
                cout << t[i].getHour() << endl;
            }
        }
        else
        {
            cout << "Invalid Choice\n";
        }
    }

    delete[] t;

    return 0;
}


     
