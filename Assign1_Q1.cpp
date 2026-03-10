#include<stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrDate) {
    ptrDate->day = 1;      
    ptrDate->month = 1;
    ptrDate->year = 2000;
    printf("Date initialized to default.\n");
}

void printDateOnConsole(struct Date *ptrDate) {

    printf("Date : %d/%d/%d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

void acceptDateFromConsole(struct Date *ptrDate) {
    printf("day: ");
    scanf("%d", &ptrDate->day);
    printf("month: ");
    scanf("%d", &ptrDate->month);
    printf("year: ");
    scanf("%d", &ptrDate->year);
}

int menuList(void) 
{
    int choice;

    printf("1. Init Date\n");
    printf("2. Print Date\n");
    printf("3. Accept Date\n");
    printf("Enter the choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    struct Date dt ;
    int choice;

    while ((choice = menuList()) != 0) {
        switch (choice) {
            case 1: 
                initDate(&dt); 
                break;
            case 2: 
                printDateOnConsole(&dt); 
                break; 
            case 3:
                acceptDateFromConsole(&dt);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

