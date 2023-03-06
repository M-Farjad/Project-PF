#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

// funtions decleration

void logo();
const int constantSize = 100;
string userNames[100];
string passwords[100];
string roles[100];
string cars[constantSize];
short int prices[constantSize];
string companies[constantSize];
int userCount = 0;
int carCount = 0;
string signIn(string userName, string password);
bool isValidUsername(string userName);
void signUpArray(string userName, string password, string role);
void storeInFile(string userName, string password, string role);
int takeChoice();
void viewUsers();
void readDataFromFile();
void adminMenu();
void costumerMenu();
void costumerMenu();

// void chechcar(string car, string company, int price);

void storeCars();
void readCarDataFromFile();
// Global variables
int option2;
int option3;
main()
{
    logo();
    readDataFromFile();
    readCarDataFromFile();
    bool decision;
    string userRole;
    string userName;
    string password;
    string role;
    int choice = 4;
    while (choice != 0)
    {
        choice = takeChoice();
        if (choice == 1)
        {
            system("Cls");
            cout << "Enter your username: ";
            cin >> userName;
            cout << "Enter your password: ";
            cin >> password;
            cout << "Enter your Role: ";
            cin >> role;
            decision = isValidUsername(userName);
            if (decision == true)
            {
                signUpArray(userName, password, role);
                storeInFile(userName, password, role);

                cout << "User Created Successfully" << endl;
                getch();
            }
            else
            {
                cout << "Username already exists" << endl;
                getch();
            }
        }
        else if (choice == 2)
        {
            system("Cls");
            cout << "Enter your username: ";
            cin >> userName;
            cout << "Enter your password: ";
            cin >> password;

            userRole = signIn(userName, password);
            if (userRole != "")
            {
                cout << "Login Successful" << endl;
                cout << "PRESS ANY KEY TO CONTINUE!!" << endl;
                getch();
                system("Cls");
                if (userRole == "admin" || userRole == "Admin" || userRole == "ADMIN")
                {
                    // cout << "MyUserCame";
                    system("Cls");
                    adminMenu();
                    getch();
                }
                else if (userRole == "costumer" || userRole == "Costumer" || userRole == "COSTUMER")
                {
                    costumerMenu();
                    getch();
                }
            }
            else
            {
                system("Color 04");
                cout << "Invalid Credentials" << endl;
            }
        }
        else if (choice == 3)
        {
            viewUsers();
        }
    }
}
string signIn(string userName, string password)
{
    string userRole = "";
    for (int idx = 0; idx < userCount; idx++)
    {
        if (userNames[idx] == userName && passwords[idx] == password)
        {
            // cout << "AnotherArray";
            // cout << "Press ANY KEY TO PROCEED!! " << endl;
            // getch();
            userRole = roles[idx];
            break;
        }
    }
    return userRole;
}
bool isValidUsername(string userName)
{
    bool flag = true;
    for (int idx = 0; idx < userCount; idx++)
    {
        if (userNames[idx] == userName)
        {
            cout << "came";
            flag = false;
            break;
        }
    }
    return flag;
}
void signUpArray(string userName, string password, string role)
{
    userNames[userCount] = userName;
    passwords[userCount] = password;
    roles[userCount] = role;
    userCount++;
}
void storeInFile(string userName, string password, string role)
{
    fstream file;
    file.open("users.txt", ios::app);
    file << userName << endl;
    file << password << endl;
    file << role << endl;
    file.close();
}
int takeChoice()
{
    int choice;
    cout << "01. SignUp User" << endl;
    cout << "02. SignIn User" << endl;
    cout << "03. View Users" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice >  ";
    cin >> choice;
    return choice;
}
void viewUsers()
{
    cout << "Usernames"

         << "\t\t"
         << "Passwords" << endl;
    cout << "_____________"
         << "\t\t"
         << "_______________"
         << endl;
    for (int idx = 0; idx < userCount; idx++)
    {
        cout << userNames[idx] << "\t\t\t" << passwords[idx] << endl;
    }
    cout << endl;
}
void readDataFromFile()
{
    string username;
    string password;
    string role;
    fstream file;
    file.open("users.txt", ios::in);
    while (getline(file, username) && getline(file, password) && getline(file, role))
    {
        userNames[userCount] = username;
        passwords[userCount] = password;
        roles[userCount] = role;
        userCount++;
    }
    file.close();
}
void readCarDataFromFile()
{
    string fCar;
    string fCompany;
    short int fPrice;
    fstream file;
    file.open("cars.txt", ios::in);
    while (getline(file, fCar) && getline(file, fCompany) && (file, fPrice))
    {
        // cout << fCar;
        // cout << fCompany;
        // cout << fPrice << endl;
        cars[carCount] = fCar;
        companies[carCount] = fCompany;
        prices[carCount] = fPrice;
        carCount++;
    }
    file.close();
}
void logo()

{

    cout << "  ###     #####  #####       #####    ######    ##     ###   ########" << endl;
    cout << " #   #    #   #  #  #        #  #     #         ##     #       ###" << endl;
    cout << " #        #####  # #         # #      ######    #  #   #        #" << endl;
    cout << " #   #    #   #  #  #        #  #     #         #    # #        #" << endl;
    cout << "  ###     #   #  #   #       #   #    ######  ###     ##        #" << endl;
}
void adminMenu()
{

    cout << "**********************************" << endl;
    cout << "*                                *" << endl;
    cout << "*           ADMIN MENU           *" << endl;
    cout << "*                                *" << endl;
    cout << "**********************************" << endl
         << endl;
    cout << "1. Add cars" << endl;
    cout << "2. View Cars" << endl;
    cout << "3. Check availability " << endl;
    cout << "4. MODIFY CAR" << endl;
    cout << "5. Check Documents" << endl;
    cout << "6. Returning A Car" << endl;
    cout << "7. EXIT" << endl
         << endl;
    cout << "Select any option:";
    cin >> option2;

    // int carArraySize = 100;

    // // car variables
    // string car[carArraySize];
    // string company[carArraySize];
    // int price[carArraySize];

    // fstream file;
    // for (int i = 0; i < carArraySize; i++)
    // {
    //     while (getline(file, car[i]) && getline(file, company[i]))
    //     {
    //         file.open("cars.txt", ios::in);
    //         file << car[i] << endl;
    //         file << company[i] << endl;
    //         file << price[i] << endl;
    //     }
    // }
    // file.close();

    if (option2 == 1)
    {

        char choice;
        cout << "*****************ADD CARS********************" << endl
             << endl;
        // readCarData(company, price, car);
        bool choice2 = true;

        while (choice2 == true)
        {

            int i = 0;
            string car;
            string companys;
            int price;
            cout << "Enter the Name of Car You Want TO Enter: ";
            cin >> car;
            cout << "Enter the Company of the Car: ";
            cin >> companys;
            cout << "Enter the PRICE of Rent for 1 day: ";
            cin >> price;

            int check = 0;
            for (int x = 0; x <= i; x++)
            {
                if (car == cars[x])
                {
                    check++;
                    break;
                }
            }
            if (check == 0)
            {
                cars[i] = car;
                companies[i] = companys;
                prices[i] = price;
                cout << "Car entered sucessfully!!" << endl;
                fstream file;
                file.open("cars.txt", ios::app);
                file << cars[i] << endl;
                file << companies[i] << endl;
                file << prices[i] << endl;
                file.close();
                i = i + 1;
            }
            else if (check == 1)
            {
                cout << endl;
                cout << "CAR ALREADY EXISTS!!" << endl;
                cout << "press any key to continue...>>" << endl;
                getch();
                system("Cls");
                adminMenu();
            }

            cout << "DO YOU WANT TO CONTINUE ENTERING CARS ??        (y/n) ";
            cin >> choice;

            system("Cls");
            if (choice == 'y')
            {
                choice2 = true;
            }
            if (choice == 'n')
            {
                choice2 = false;
            }
        }
    }

    if (option2 == 2)
    {
        system("Cls");
        cout << "************VIEW CARS**************" << endl
             << endl;
        // string car;
        // string companys;
        // int price;
        // fstream file;
        // int i = 0;
        // file.open("cars.txt", ios::in);
        for (int i = 0; i < carCount; i++)
        {
            cout << "car: " << cars[i] << endl;

            cout << "company: " << companies[i] << endl;

            cout << "price: " << prices[i] << endl
                 << endl;
        }
        // file.close();
        cout << "PRESS ANY KEY TO CONTINUE: " << endl;
        getch();

        adminMenu();
    }

    if (option2 == 3)
    {
        system("Cls");
        cout << "****************CHECK AVAILABILITY****************" << endl;

        string copycar;
        cout << "ENTER the CAR: ";
        cin >> copycar;
        bool flag2 = false;
        for (int i = 0; i < constantSize; i++)
        {
            if (copycar == cars[i]) // copycar == kia
            {
                cout << "****************************" << endl;
                cout << "______CAR IS AVAILABLE_____" << endl;
                cout << "****************************" << endl;
                cout << endl
                     << endl;
                cout << "CAR YOU WANT TO FIND IS: " << cars[i] << endl
                     << endl;
                cout << "THE PRICE OF CAR  for 1 day of rent IS : " << prices[i] << endl
                     << endl
                     << endl;
                cout << "PRESS ANY KEY TO CONTINUE:";
                getch();
                system("Cls");
                adminMenu();

                flag2 = true;
                break;
            }
            else
            {
                continue;
            }
        }
        if (flag2 == false)
        {
            cout << "THE CAR YOU ENTER IS NOT AVAILABLE!!" << endl
                 << endl;
            cout << "PRESS ANY KEY TO CONTINUE:" << endl;
            getch();
            adminMenu();
        }
    }
    if (option2 == 4)
    {
        string car2;

        system("Cls");
        cout << "****************MODIFY CAR******************" << endl
             << endl
             << endl;
        float priceModification;
        cout << "ENTER CAR FOR MODIFICATION :";
        cin >> car2;
        for (int i = 0; i < constantSize; i++)
        {
            if (car2 == cars[i])
            {
                cout << "PRICE of  " << cars[i] << "  is: " << prices[i];
            }
        }
        cout << endl;
        cout << "PRESS ANY KEY TO CONTINUE: " << endl;
        getch();
        system("Cls");
        adminMenu();
    }
    if (option2 == 5)
    {
        system("Cls");
        cout << "******************CHECK DOCUMENTS********************" << endl;

        char age;
        char license;
        char cnic;
        cout << "Is the COSTUMER above 18??   (y/n)" << endl;
        cin >> age;
        cout << "Does the COSTUMER possess a License??    (y/n)" << endl;
        cin >> license;
        cout << " Does the Costumer have A CNIC CARD ??  (y/n)" << endl;
        cin >> cnic;
        if ((age == 'y' || age == 'Y') && (license == 'y' || license == 'Y') && (cnic == 'y' || cnic == 'Y'))
        {
            // system("Color 0A");
            cout << "______________________" << endl;
            cout << "COSTUMER is ELEGIBLE !!" << endl;
            cout << "______________________" << endl;
            cout << "Press Any Key To Continue: "
                 << endl;
            getch();
            system("Cls");
            adminMenu();
        }
        else
        {
            // system("Color E4");
            cout << "___________________________" << endl;
            cout << "COSTUMER IS NOT ELIGIBLE !!" << endl;
            cout << "___________________________" << endl;

            cout << "Press Any Key To Continue: "
                 << endl;
            getch();
            system("Cls");
            adminMenu();
        }
    }
    if (option2 == 6)
    {
        system("Cls");
        char returnc;
        char record;
        cout << "Has the Costumer returned the Car??      (y/n)" << endl;
        cin >> returnc;
        cout << " Has The costumer POSESS any Previous Charges       (y/n)";
        cin >> record;

        if (returnc == 'y' && record == 'y')
        {
            cout << "COSTUMER IS CLEARED!!" << endl;
            cout << "Press Any Key To Continue: "
                 << endl;
            getch();
            adminMenu();
        }
        if (returnc == 'n' && record == 'n')
        {
            cout << "COSTUMER IS NOT CLEARED!!" << endl;
            cout << "Press Any Key To Continue: "
                 << endl;
            getch();
            adminMenu();
        }
        if (returnc != 'n' && returnc != 'y')
        {
            cout << "INVALID OPTION TRY AGAIN!! " << endl;
            cout << "Press Any Key To Continue: "
                 << endl;
            getch();
            adminMenu();
        }
    }
}

void costumerMenu()
{
    cout << "**********************************" << endl;
    cout << "*                                *" << endl;
    cout << "*         COSTUMER MENU          *" << endl;
    cout << "*                                *" << endl;
    cout << "**********************************" << endl
         << endl;

    cout << "1. Rent A Car" << endl;
    cout << "2. Check Availability" << endl;
    cout << "3. Check Price" << endl;
    cout << "4. View Cars " << endl;
    cout << "5. Compare Price" << endl;
    cout << "6. EXIT" << endl
         << endl;
    cout << "Select any option:";
    cin >> option3;
    if (option3 == 1)
    {
        string rentcar;
        int pricerent;
        int days;
        cout << "****************RENT A CAR***************" << endl
             << endl;
        cout << "WHICH CAR YOU WANT TO TAKE FOR RENT??";
        cin >> rentcar;
        cout << "FOR HOW MANY DAYS YOU WANT TO KEEP IT??";
        cin >> days;
        bool blag = false;
        for (int i = 0; i < 12; i++)
        {
            if (rentcar == cars[i])
            {
                cout << "PRICE FOR ONE DAY OF RENT OF  " << cars[i] << "  is" << prices[i] << endl
                     << endl;
                pricerent = days * prices[i];
                cout << "THE PRICE FOR  " << days << "  is :" << pricerent << endl
                     << endl;
                blag = true;
                break;
            }
        }
        if (blag == true)
        {
            cout << "PRESS ANY KEY TO CONTINUE:" << endl;
            getch();
            costumerMenu();
        }
        if (blag == false)
        {
            cout << "CAR NOT FOUND !! " << endl;
            cout << "PRESS ANY KEY TO CONTINUE:" << endl;
            getch();
            costumerMenu();
        }
    }
    if (option3 == 2)
    {
        cout << "***************CHECK AVAILABILITY*******************" << endl
             << endl;
        string copycar;
        cout << "ENTER the CAR: ";
        cin >> copycar;
        bool flag2 = false;
        for (int i = 0; i < constantSize; i++)
        {
            if (copycar == cars[i]) 
            {
                cout << "****************************" << endl;
                cout << "______CAR IS AVAILABLE_____" << endl;
                cout << "****************************" << endl;
                cout << endl
                     << endl;
                cout << "CAR YOU WANT TO FIND IS: " << cars[i] << endl
                     << endl;
                cout << "THE PRICE OF CAR  for 1 day of rent IS : " << prices[i] << endl
                     << endl
                     << endl;
                cout << "PRESS ANY KEY TO CONTINUE:";
                getch();
                system("Cls");
                costumerMenu();

                flag2 = true;
                break;
            }
            else
            {
                continue;
            }
        }
        if (flag2 == false)
        {
            cout << "THE CAR YOU ENTER IS NOT AVAILABLE!!" << endl
                 << endl;
            cout << "PRESS ANY KEY TO CONTINUE:" << endl;
            getch();
            costumerMenu();
        }
    }

    if (option3 == 3)
    {
        string cargo;
        cout << "***************CHECK PRICE******************" << endl
             << endl;

        cout << endl;
        cout << "ENTER CAR : ";
        cin >> cargo;
        for (int i = 0; i < 12; i++)
        {
            if (cargo == cars[i])
                cout << "price for " << cars[i] << " is " << prices[i] << endl;
            break;
        }

        cout << "PRESS ANY KEY TO CONTINUE : " << endl;
        getch();
        system("CLS");
        costumerMenu();
    }
    if (option3 == 4)
    {
        cout << "****************VIEW CARS*******************" << endl
             << endl;

        for (int i = 0; i < carCount; i++)
        {
            cout << "car: " << cars[i] << endl;

            cout << "company: " << companies[i] << endl;
            cout << "price: " << prices[i] << endl
                 << endl;
        }
        // file.close();
        cout << "PRESS ANY KEY TO CONTINUE: " << endl;
        getch();

        costumerMenu();
    }

    if (option3 == 5)
    {
        cout << "*******************COMPARE PRICE*********************" << endl;
    }
}
// void readCarData(string car, string company, int price)
// {
//     fstream file;

//     file.open("cars.txt", ios::in);
//     int i = 0;
//     while (getline(file, car) && getline(file, company))
//     {

//         car[i] == cars;

//         company[i] = company;
//         // price[i] = price;
//         i++;
//     }
//     file.close();
// }
