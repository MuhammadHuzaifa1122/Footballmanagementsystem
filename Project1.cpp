#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
void printMenu();
int printAdminOption();
int printPlayerOption();
int printOption1();
void viewDetails(string a, int b, int c, int d);
void status(string a, string b);
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
        int option = printOption1();
        if (option == 1)
        {
            while (true)
            {
                int option1;
                option1 = printAdminOption();
                if (option1 == 1)
                {
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
                    cin.ignore();
                    cout << "Next Match against: ";
                    getline(cin,matchAgainst);
                    cin.ignore();
                    cout << "Match Date: ";
                    getline(cin,matchDate);
                }
                else if (option1 == 3)
                {
                    cin.ignore();
                    cout << "Upcoming Tournament: ";
                    getline(cin,tournament);
                }
                else if (option1 == 4)
                {
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
                    cout<<left<<setw(20) << "Name"<<setw(20)<<"status" << endl;
                    for (int k = 0; k < 15; k++)
                    {
                        if (name[k] != " ")
                            status(name[k], fund[k]);
                    }
                   
                }
                else if (option1 == 6)
                {
                    break;
                }
                else
                {
                    cout << "Invalid option! Try again." << endl;
                }
               
                 cout << "Press any key to continue" << endl;
                    getch();
                     system("cls");
            }
        }
        else if (option == 2)
        {
            while (true)
            {
                system("cls");
                int option2 = printPlayerOption();
                if (option2 == 1)
                {
                    int checkKit;
                    cout << "Enter your kit Number ";
                    cin >> checkKit;
                    bool found = false;
                    for (int i = 0; i < 15; i++)
                    {
                        if (kit[i] == checkKit)
                        {
                             cout << left << setw(20) << "Player Name" << setw(15) << "Number " << setw(10) << "Age" << setw(15) << " Matches played" << endl;
                            viewDetails(name[i], kit[i], age[i], match[i]);
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        cout << "Invalid kit Number!" << endl;
                    }
                    
                }
                else if (option2 == 2)
                {
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
                    if (tournament != " ")
                    {
                        cout << "Upcoming Tournament: " << tournament << endl;
                    }
                    else
                        cout << "No Upcoming tournament" << endl;
                    
                }
                else if (option2 == 4)
                {
                    int checkKit;
                    cout << "Enter your kit Number ";
                    cin >> checkKit;
                    bool found = false;
                    for (int i = 0; i < 15; i++)
                    {
                        if (kit[i] == checkKit)
                        {
                            cout<<left<<setw(20) << "Name"<<setw(20)<<"status" << endl;
                            status(name[i], fund[i]);
                            found=true;
                            break;
                        }
                       
                        
                    }
                     if (!found)
                        {
                              cout << "Invalid kit Number!" << endl;
                        }
                }

                else if (option2 == 5)
                {
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
    cout << "=         Football Management System            =" << endl;
    cout << "=================================================" << endl;
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
    cout << "6. Exit" << endl;
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
    cout <<left<<setw(20)<< a << setw(20) << b << endl;
}
int printPlayerOption()
{
    int option;
    cout << "Select any of the following option number" << endl;
    cout << "1. View Personal details" << endl;
    cout << "2. Upcoming Match details" << endl;
    cout << "3. Upcoming tournament" << endl;
    cout << "4. View fund details" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter Option: ";
    cin >> option;
    return option;
}