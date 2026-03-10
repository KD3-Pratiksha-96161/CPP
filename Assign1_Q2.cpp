#include <iostream>
using namespace std;

struct Date {
    int day, month, year;

    void initDate() {
        day = 1; 
        month = 1; 
        year = 2000;
        cout << "Date initialized to default.\n";
    }

    void printDateOnConsole() {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }

    void acceptDateFromConsole() {
        cout << "day : ";
        cin >> day;
        cout << "month : ";
        cin>> month; 
        cout << "year : ";
        cin>> year;
    }

    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

int menuList() {
    int choice;
    cout << "\n0. Exit\n1. Init\n2. Print\n3. Accept\n4. Check Leap Year\nChoice: ";
    cin >> choice;
    return choice;
}

int main() 
{
    Date dt;
    int choice;
    while ((choice = menuList()) != 0) 
    {
        switch (choice) 
        {
            case 1: dt.initDate(); 
            break;
            case 2: dt.printDateOnConsole(); 
            break;
            case 3: dt.acceptDateFromConsole();
            break;
            case 4: 
                if (dt.isLeapYear()) cout << "Leap Year!\n";
                else cout << "Not a Leap Year.\n";
            break;
        }
    }
    return 0;
}
