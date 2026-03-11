#include <iostream>
using namespace std;

class TollBooth
{
private:
    int totalCars;
    int payingCars;
    int nonPayingCars;
    double totalMoney;

public:
    TollBooth()
    {
        totalCars = 0;
        payingCars = 0;
        nonPayingCars = 0;
        totalMoney = 0;
    }

    void payingCar()
    {
        totalCars++;
        payingCars++;
        totalMoney += 0.50;
    }

    void nopayCar()
    {
        totalCars++;
        nonPayingCars++;
    }

    void printOnConsole()
    {
        cout << "Total Cars = " << totalCars << endl;
        cout << "Paying Cars = " << payingCars << endl;
        cout << "Non Paying Cars = " << nonPayingCars << endl;
        cout << "Total Money Collected = $" << totalMoney << endl;
    }
};

int menuList()
{
    int choice;

    cout << "\n0. Exit" << endl;
    cout << "1. Paying Car" << endl;
    cout << "2. Non Paying Car" << endl;
    cout << "3. Display" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    TollBooth t;
    int choice;

    while((choice = menuList()) != 0)
    {
        switch(choice)
        {
            case 1:
                t.payingCar();
                break;

            case 2:
                t.nopayCar();
                break;

            case 3:
                t.printOnConsole();
                break;

            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}