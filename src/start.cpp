#include "start.h"
#include "admin.h"
#include "user.h"

void start() {

    int choice;
    
    do {
        
        system("cls");

        cout << "W e l c o m e   t o   T h e   S y s t e m " << endl << endl;

        cout << "1. Login as Admin" << endl;
        cout << "2. Enter as User" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                {
                    Admin admin;
                    admin.login();
                    break;
                }
            case 2:
                {
                    User user;
                    user.menu();
                    break;
                }

            default:
                cout << "Exit" << endl;
                exit(0); // finish program here
        }
    
    } while (choice != 0);
}
