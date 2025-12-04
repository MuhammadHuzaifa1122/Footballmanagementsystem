#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
void printMenuHeader(string mainMenu, string subMenu);
void printMenu();
int printAdminOption();
int printPlayerOption();
int printOption1();
void viewDetails(string a, int b, int c, int d);
void status(string a, string b);
void clearManager();
void clearPlayer();
string name[15], fund[15], matchAgainst = " ", matchDate, tournament = " ";
int i = 0, age[15], kit[15], match[15];
int main()
{
    for (int x = 0; x < 15; x++)
    {
        name[x] = " ";
        fund[x] = " ";
    }
    while (true)
    {
        printMenu();
        printMenuHeader("Main Menu", "");
        int option = printOption1();
        system("cls");
        if (option == 1)
        {
            printMenu();
            printMenuHeader("Main Menu", "Manager");
            while (true)
            {
                int option1;
                option1 = printAdminOption();
                if (option1 == 1)
                {
                    clearManager();
                    cin.ignore();
                    cout << "Enter Player name: ";
                    getline(cin, name[i]);

                    cout << "Enter Player kit number: ";
                    cin >> kit[i];
                    cout << "Enter Player Age: ";
                    cin >> age[i];
                    cout << "Enter Number of matches  Player played: ";
                    cin >> match[i];
                    cin.ignore();
                    cout << "Player fund status(paid/notpaid): ";
                    getline(cin, fund[i]);
                    i += 1;
                }
                else if (option1 == 2)
                {
                    clearManager();
                    cin.ignore();
                    cout << "Next Match against: ";
                    getline(cin, matchAgainst);
                    cin.ignore();
                    cout << "Match Date: ";
                    getline(cin, matchDate);
                }
                else if (option1 == 3)
                {
                    clearManager();
                    cin.ignore();
                    cout << "Upcoming Tournament: ";
                    getline(cin, tournament);
                }
                else if (option1 == 4)
                {
                    clearManager();
                    cout << left << setw(20) << "Player Name" << setw(15) << "Number " << setw(10) << "Age" << setw(15) << " Matches played" << endl;
                    for (int j = 0; j < 15; j++)
                    {
                        if (name[j] != " ")
                        {
                            viewDetails(name[j], kit[j], age[j], match[j]);
                        }
                    }
                }
                else if (option1 == 5)
                {
                    clearManager();
                    cout << left << setw(20) << "Name" << setw(20) << "status" << endl;
                    for (int k = 0; k < 15; k++)
                    {
                        if (name[k] != " ")
                            status(name[k], fund[k]);
                    }
                }
                else if (option1 == 6)
                {
                    clearManager();
                    string searchName;
                    cout << "Enter Player Name to Update Jersey Number: " << endl;
                    cin.ignore();
                    getline(cin, searchName);

                    bool found = false;
                    for (int i = 0; i < 15; i++)
                    {
                        if (name[i] == searchName)
                        {
                            cout << "Enter new Jersey Number: " << endl;
                            cin >> kit[i];
                            cout << "Jersey Number updated successfully!" << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        cout << "Player not found!" << endl;
                }
                else if (option1 == 7)
                {
                    clearManager();
                    string searchName;
                    cout << "Enter Player Name to Search: " << endl;
                    cin.ignore();
                    getline(cin, searchName);
                    bool found = false;
                    for (int i = 0; i < 15; i++)
                    {
                        if (name[i] == searchName)
                        {
                            cout << "Player name: " << name[i] << endl;
                            cout << "Kit Number: " << kit[i] << endl;
                            cout << "Player AGE: " << age[i] << endl;
                            cout << "Number of matches player played: " << match[i] << endl;
                            cout << "Fund status: " << fund[i] << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        cout << "Player not found!" << endl;
                }
                else if (option1 == 8)
                {
                    clearManager();
                    string searchName;
                    cout << "Enter Player Name to Delete: " << endl;
                    cin.ignore();
                    getline(cin, searchName);
                    bool found = false;
                    for (int i = 0; i < 15; i++)
                    {
                        if (name[i] == searchName)
                        {
                            for (int j = i; j < 14; j++)
                            {
                                name[j] = name[j + 1];
                                age[j] = age[j + 1];
                                kit[j] = kit[j + 1];
                            }

                            cout << "Player deleted successfully!" << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        cout << "Player not found!" << endl;
                }

                else if (option1 == 9)
                {
                    cout << "Press any key to continue" << endl;
                    getch();
                    system("cls");
                    break;
                }
                else
                {
                    cout << "Invalid option! Try again." << endl;
                }

                cout << "Press any key to continue" << endl;
                getch();
                system("cls");
                printMenu();
                printMenuHeader("Main Menu", "");
            }
        }
        else if (option == 2)
        {
            while (true)
            {
                system("cls");
                printMenu();
                printMenuHeader("Main Menu", "Player");
                int option2 = printPlayerOption();
                if (option2 == 1)
                {
                    clearPlayer();
                    string searchName;
                    cout << "Enter your name to view personal details: " << endl;
                    cin.ignore();
                    getline(cin, searchName);

                    bool found = false;
                    for (int i = 0; i < 15; i++)
                    {
                        if (name[i] == searchName)
                        {
                            cout << left << setw(20) << "Player Name" << setw(15) << "Number " << setw(10) << "Age" << setw(15) << " Matches played" << endl;
                            viewDetails(name[i], kit[i], age[i], match[i]);
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        cout << "Player not found!" << endl;
                }
                else if (option2 == 2)
                {
                    clearPlayer();
                    if (matchAgainst != " ")
                    {
                        cout << "Match against " << matchAgainst << " on " << matchDate << endl;
                    }
                    else
                    {
                        cout << "No details yet!" << endl;
                    }
                }
                else if (option2 == 3)
                {
                    clearPlayer();
                    if (tournament != " ")
                    {
                        cout << "Upcoming Tournament: " << tournament << endl;
                    }
                    else
                        cout << "No Upcoming tournament" << endl;
                }
                else if (option2 == 4)
                {
                    clearPlayer();
                    string searchName;
                    cout << "Enter your name to view personal details: " << endl;
                    cin.ignore();
                    getline(cin, searchName);

                    bool found = false;
                    for (int i = 0; i < 15; i++)
                    {
                        if (name[i] == searchName)
                        {
                            cout << left << setw(20) << "Name" << setw(20) << "status" << endl;
                            status(name[i], fund[i]);
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        cout << "Player not found!" << endl;
                }
                else if (option2 == 5)
                {
                    clearPlayer();
                    for (int i = 0; i < 15; i++)
                    {
                        if (name[i] != " ")
                        {
                            if (match[i] > 30)
                            {
                                cout << name[i] << ": Senior Player" << endl;
                            }
                            else if (match[i] > 15)
                            {
                                cout << name[i] << ": Intermidiate Player" << endl;
                            }
                            else
                                cout << name[i] << ": New Player" << endl;
                        }
                    }
                }
                else if (option2 == 6)
                {
                    for (int i = 0; i < 15; i++)
                    {
                        if (name[i]!=" ")
                        {
                            cout<<i+1<<". Player"<<" Name: "<<" "<<name[i]<<"      Kit Number: "<<kit[i]<<endl;
                        }
                        
                    }
                    
                }
                
                else if (option2 == 7)
                {
                    clearPlayer();
                    cout << "Press any key to continue" << endl;
                    getch();
                    system("cls");
                    break;
                }
                else
                    cout << "invalid option!" << endl;
                cout << "Press any key to continue" << endl;
                getch();
                system("cls");
            }
        }
        else if (option == 3)
        {
            return 0;
        }
        else
            cout << "Invalid Option" << endl;
    }
}
void printMenu()
{
    cout << "=================================================" << endl;
    cout << "----------Football Management System------------=" << endl;
    cout << "=================================================" << endl;
}
void printMenuHeader(string mainMenu, string subMenu)
{
    string msg = mainMenu + " > " + subMenu;
    cout << msg << endl;
    cout << "------------------------------" << endl;
}
int printOption1()
{
    int option;
    cout << "Select any of the following option number" << endl;
    cout << "1. Manager " << endl;
    cout << "2. Player" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter Option: ";
    cin >> option;
    return option;
}
int printAdminOption()
{
    int option;
    cout << "Select any of the following option number" << endl;
    cout << "1. ADD  player " << endl;
    cout << "2. ADD Match details " << endl;
    cout << "3. ADD upcoming tournament " << endl;
    cout << "4. View player details " << endl;
    cout << "5. View fund details " << endl;
    cout << "6. Update Player Jersey Number " << endl;
    cout << "7. Search Player by Name" << endl;
    cout << "8. Delete Player by Name" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter Option: ";
    cin >> option;
    return option;
}
void viewDetails(string a, int b, int c, int d)
{
    cout << left << setw(20) << a << setw(15) << b << setw(10) << c << setw(15) << d << endl;
}
void status(string a, string b)
{
    cout << left << setw(20) << a << setw(20) << b << endl;
}
int printPlayerOption()
{
    int option;
    cout << "Select any of the following option number" << endl;
    cout << "1. View Personal details" << endl;
    cout << "2. Upcoming Match details" << endl;
    cout << "3. Upcoming tournament" << endl;
    cout << "4. View fund details" << endl;
    cout << "5. Performance Report" << endl;
    cout << "6. View Team Details" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter Option: ";
    cin >> option;
    return option;
}
void clearManager()
{
    system("cls");
    printMenu();
    printMenuHeader("Main Menu", "Manager");
}
void clearPlayer()
{
    system("cls");
    printMenu();
    printMenuHeader("Main Menu", "Player");
}
}
