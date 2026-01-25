#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>  
#include <ctime>    
#include<fstream>
using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

const int GREEN = 10;
const int CYAN = 11;
const int YELLOW = 14;
const int RED = 12;
const int WHITE = 15;
const int LIGHT_GREEN = 10;
const int BRIGHT_YELLOW = 14;
const int BRIGHT_CYAN = 11;

void printMenuHeader(string mainMenu, string subMenu);
void printMenu();
int printAdminOption();
int printPlayerOption();
int printCoachOption();
int printOption1();
void viewDetails(string a, string b, int c, int d, int e, double f);
void status(string a, string b);
void clearManager();
void clearPlayer();
void clearCoach();
void distributeBonuses();
void displaySplashScreen();
void displayStyledMenu();
void showLoading();

string name[30], position[30], fund[30], matchAgainst = " ", matchDate, tournament = " ";
int i = 0, age[30], kit[30], match[30], goals[30];
double salary[30], bonus[30];
string opponent[20];
int matchGoals[20][30];
int totalMatches = 0;


void save()
{
    fstream file;
    file.open("players_count.txt",ios::out);
    if(!file.is_open())
    {
        cout<<"Error opening file!"<<endl;
        return;
    }
    file<<i<<endl;
    

}
void read_i()
{
    fstream file;
    file.open("players_count.txt",ios::in);
    if(!file.is_open())
    {
        cout<<"Error opening file!"<<endl;
        return;
    }
    file>>i;
}
void save_players(string playerName, string playerPosition,
                  int playerAge, int playerKit,
                  string fundStatus, double playerSalary, int playerGoals,int match)
{
    fstream file;
    file.open("player_details.txt", ios::app);

    if (!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return;
    }

    file << playerName << endl;
    file << playerPosition << endl;
    file << playerAge << endl;
    file << playerKit << endl;
    file << fundStatus << endl;
    file << playerSalary << endl;
    file << playerGoals << endl;
    file << match<<endl;

    file.close();
}

void load_players()
{
    fstream file("player_details.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Error opening file!" << endl;
        return;
    }

    i = 0;   

    while (getline(file, name[i]))
    {
        getline(file, position[i]);
        file >> age[i];
        file >> kit[i];
        file >> fund[i];
        file >> salary[i];
        file >> goals[i];
        file >> match[i];
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        i++;
    }

    file.close();
    save();  
}

void rewrite_players_file()
{
    fstream file("player_details.txt", ios::out);

    for (int k = 0; k < i; k++)
    {
        file << name[k] << endl;
        file << position[k] << endl;
        file << age[k] << endl;
        file << kit[k] << endl;
        file << fund[k] << endl;
        file << salary[k] << endl;
        file << goals[k] << endl;
        file << match[k] << endl;
    }
    file.close();
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    for (int j = 0; j < 30; j++)
{
    name[j] = " ";
    position[j] = " ";
    fund[j] = " ";
    age[j] = kit[j] = match[j] = goals[j] = 0;
    salary[j] = bonus[j] = 0;
}

    load_players();

    displaySplashScreen();

   
    

    while (true)
    {
        system("cls");
        displayStyledMenu();
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
                    setColor(YELLOW);
                    cout << "Enter Player name: ";
                    setColor(WHITE);
                    getline(cin, name[i]);
                    

                    setColor(YELLOW);
                    cout << "Enter Player position (GK/DEF/MID/ATK): ";
                    setColor(WHITE);
                    getline(cin, position[i]);

                    int newKit;
                    bool kitTaken = false;
                    do
                    {
                        kitTaken = false;
                        setColor(YELLOW);
                        cout << "Enter Player kit number: ";
                        setColor(WHITE);
                        cin >> newKit;

                        for (int j = 0; j < 30; j++)
                        {
                            if (name[j] != " " && kit[j] == newKit)
                            {
                                setColor(RED);
                                cout << "Jersey number " << newKit << " is already taken by " << name[j] << "!" << endl;
                                setColor(WHITE);
                                kitTaken = true;
                                break;
                            }
                        }
                    } while (kitTaken);

                    kit[i] = newKit;
                    setColor(YELLOW);
                    cout << "Enter Player Age: ";
                    setColor(WHITE);
                    cin >> age[i];
                    setColor(YELLOW);
                    cout << "Enter Number of matches Player played: ";
                    setColor(WHITE);
                    cin >> match[i];
                    setColor(YELLOW);
                    cout << "Enter Total Goals Scored: ";
                    setColor(WHITE);
                    cin >> goals[i];
                    setColor(YELLOW);
                    cout << "Enter Player Salary: ";
                    setColor(WHITE);
                    cin >> salary[i];
                    cin.ignore();
                    setColor(YELLOW);
                    cout << "Player fund status(paid/notpaid): ";
                    setColor(WHITE);
                    getline(cin, fund[i]);
                    save_players(name[i],position[i],age[i],kit[i],fund[i],salary[i],goals[i],match[i]);
                    i += 1;
                    save();
                }
                else if (option1 == 2)
                {
                    clearManager();
                    cin.ignore();

                    setColor(YELLOW);
                    cout << "Next Match against: ";
                    setColor(WHITE);
                    getline(cin, opponent[totalMatches]);
                    matchAgainst = opponent[totalMatches];
                    setColor(YELLOW);
                    cout << "Match Date: ";
                    setColor(WHITE);
                    getline(cin, matchDate);

                    for (int p = 0; p < 30; p++)
                        matchGoals[totalMatches][p] = 0;
                    totalMatches++;
                }
                else if (option1 == 3)
                {
                    clearManager();
                    cin.ignore();
                    setColor(YELLOW);
                    cout << "Upcoming Tournament: ";
                    setColor(WHITE);
                    getline(cin, tournament);
                }
                else if (option1 == 4)
                {   
                    clearManager();
                    setColor(GREEN);
                    cout << left << setw(20) << "Player Name" << setw(10) << "Position" << setw(10) << "Age" << setw(12) << "Matches" << setw(15) << "Salary" << endl;
                    cout << "---------------------------------------------------------------" << endl;
                    setColor(WHITE);
                    for (int j = 0; j < i; j++)
                    {
                        if (name[j] != " ")
                        {
                            viewDetails(name[j], position[j], kit[j], age[j], match[j], salary[j]);
                        }
                    }
                }
                else if (option1 == 5)
                {
                    clearManager();
                    setColor(GREEN);
                    cout << left << setw(20) << "Name" << setw(20) << "Status" << endl;
                    setColor(WHITE);
                    for (int k = 0; k < 30; k++)
                    {
                        if (name[k] != " ")
                            status(name[k], fund[k]);
                    }
                }
                else if (option1 == 6)
                {
                    clearManager();
                    string searchName;
                    setColor(YELLOW);
                    cout << "Enter Player Name to Update Jersey Number: " << endl;
                    setColor(WHITE);
                    cin.ignore();
                    getline(cin, searchName);

                    bool found = false;
                    for (int i = 0; i < 30; i++)
                    {
                        if (name[i] == searchName)
                        {
                            int newKit;
                            bool kitTaken = false;
                            do
                            {
                                kitTaken = false;
                                setColor(YELLOW);
                                cout << "Enter new Jersey Number: " << endl;
                                setColor(WHITE);
                                cin >> newKit;

                                for (int j = 0; j < 30; j++)
                                {
                                    if (j != i && name[j] != " " && kit[j] == newKit)
                                    {
                                        setColor(RED);
                                        cout << "Jersey number " << newKit << " is already taken by " << name[j] << "!" << endl;
                                        setColor(WHITE);
                                        kitTaken = true;
                                        break;
                                    }
                                }
                            } while (kitTaken);

                            kit[i] = newKit;
                            setColor(LIGHT_GREEN);
                            cout << "Jersey Number updated successfully!" << endl;
                            rewrite_players_file();
                            setColor(WHITE);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        setColor(RED);
                        cout << "Player not found!" << endl;
                        setColor(WHITE);
                    }
                }
                else if (option1 == 7)
                {
                    clearManager();
                    string searchName;
                    setColor(YELLOW);
                    cout << "Enter Player Name to Search: " << endl;
                    setColor(WHITE);
                    cin.ignore();
                    getline(cin, searchName);
                    bool found = false;
                    for (int i = 0; i < 30; i++)
                    {
                        if (name[i] == searchName)
                        {
                            setColor(CYAN);
                            cout << "Player name: " << name[i] << endl;
                            cout << "Position: " << position[i] << endl;
                            cout << "Kit Number: " << kit[i] << endl;
                            cout << "Player AGE: " << age[i] << endl;
                            cout << "Number of matches player played: " << match[i] << endl;
                            cout << "Total Goals Scored: " << goals[i] << endl;
                            cout << "Salary: $" << salary[i] << endl;
                            cout << "Fund status: " << fund[i] << endl;
                            setColor(WHITE);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        setColor(RED);
                        cout << "Player not found!" << endl;
                        setColor(WHITE);
                    }
                }
                else if (option1 == 8)
                {
                    clearManager();
                    string searchName;
                    setColor(YELLOW);
                    cout << "Enter Player Name to Delete: " << endl;
                    setColor(WHITE);
                    cin.ignore();
                    getline(cin, searchName);
                    bool found = false;
                    for (int k = 0; k < 30; k++)
                    {
                        if (name[k] == searchName)
                        {
                            for (int j = k; j < 29; j++)
                            {
                                name[j] = name[j + 1];
                                position[j] = position[j + 1];
                                age[j] = age[j + 1];
                                kit[j] = kit[j + 1];
                                match[j] = match[j + 1];
                                goals[j] = goals[j + 1];
                                salary[j] = salary[j + 1];
                                fund[j] = fund[j + 1];
                                bonus[j] = bonus[j + 1];
                            }

                            setColor(LIGHT_GREEN);
                            i--;
                            save();
                            rewrite_players_file();
                            cout << "Player deleted successfully!" << endl;
                            setColor(WHITE);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        setColor(RED);
                        cout << "Player not found!" << endl;
                        setColor(WHITE);
                    }
                }

                else if (option1 == 9)
                {
                    clearManager();

                    int currentMatch = totalMatches;

                    if (matchAgainst == " ")
                    {
                        setColor(YELLOW);
                        cout << "Enter opponent team for this match: ";
                        setColor(WHITE);
                        cin.ignore();
                        getline(cin, opponent[currentMatch]);
                    }

                    for (int j = 0; j < i; j++)
                    {
                        if (name[j] != " ")
                        {
                            int g;
                            setColor(YELLOW);
                            cout << "Goals scored by " << name[j] << ": ";
                            setColor(WHITE);
                            cin >> g;
                            matchGoals[currentMatch][j] = g;
                            goals[j] += g;
                            match[j]++;
                        }
                    }

                    totalMatches++;

                    clearManager();
                    setColor(YELLOW);
                    cout << "=== AUTOMATIC BONUS DISTRIBUTION ===" << endl;
                    cout << "Bonus criteria (based on this match goals):" << endl;
                    cout << "- 2+ Goals: 1000 Bonus" << endl;
                    cout << "- 4+ Goals: 2000 Bonus\n" << endl;
                    setColor(WHITE);

                    setColor(GREEN);
                    cout << left << setw(25) << "Player Name" << setw(10) << "Position" << setw(10) << "Match Goals" << setw(15) << "Bonus" << endl;
                    cout << "==================================================================\n";
                    setColor(WHITE);

                    for (int j = 0; j < 30; j++)
                    {
                        if (name[j] != " " && (position[j] == "MID" || position[j] == "ATK"))
                        {
                            int matchGoalsScored = matchGoals[currentMatch][j];
                            double newBonus = 0;

                            if (matchGoalsScored >= 4)
                            {
                                newBonus = 2000;
                            }
                            else if (matchGoalsScored >= 2)
                            {
                                newBonus = 1000;
                            }

                            if (newBonus > 0)
                            {
                                bonus[j] += newBonus;
                                salary[j] += newBonus;
                                setColor(CYAN);
                                cout << left << setw(25) << name[j] << setw(10) << position[j] << setw(10) << matchGoalsScored
                                     << setw(15) << "$" << fixed << setprecision(0) << newBonus << endl;
                                     
                                setColor(WHITE);
                            }
                        }
                    }
                    setColor(LIGHT_GREEN);
                    rewrite_players_file();
                    cout << "\n=== Bonuses awarded automatically ===" << endl;
                    setColor(WHITE);
                }

                else if (option1 == 10)
                {
                    clearManager();
                    setColor(YELLOW);
                    cout << "=== TOP SCORERS ===" << endl;
                    setColor(WHITE);

                    string tempNames[30];
                    int tempGoals[30];
                    int tempKits[30];
                    int count = 0;

                    for (int j = 0; j < 30; j++)
                    {
                        if (name[j] != " ")
                        {
                            tempNames[count] = name[j];
                            tempGoals[count] = goals[j];
                            tempKits[count] = kit[j];
                            count++;
                        }
                    }

                    for (int i = 0; i < count - 1; i++)
                    {
                        int maxIndex = i;

                        for (int j = i + 1; j < count; j++)
                        {
                            if (tempGoals[j] > tempGoals[maxIndex])
                            {
                                maxIndex = j;
                            }
                        }

                        int tGoal = tempGoals[i];
                        tempGoals[i] = tempGoals[maxIndex];
                        tempGoals[maxIndex] = tGoal;

                        string tName = tempNames[i];
                        tempNames[i] = tempNames[maxIndex];
                        tempNames[maxIndex] = tName;

                        int tKit = tempKits[i];
                        tempKits[i] = tempKits[maxIndex];
                        tempKits[maxIndex] = tKit;
                    }

                    setColor(GREEN);
                    cout << left << setw(5) << "Rank" << setw(25) << "Player Name"
                         << setw(10) << "Kit #" << setw(10) << "Goals" << endl;
                    cout << "-------------------------------------------------------" << endl;
                    setColor(WHITE);
                    for (int j = 0; j < count; j++)
                    {
                        setColor(CYAN);
                        cout << left << setw(5) << j + 1 << setw(25) << tempNames[j]
                             << setw(10) << tempKits[j] << setw(10) << tempGoals[j] << endl;
                        setColor(WHITE);
                    }
                }

                else if (option1 == 11)
                {
                    setColor(YELLOW);
                    cout << "Press any key to continue" << endl;
                    setColor(WHITE);
                    getch();
                    system("cls");
                    break;
                }
                
                else
                {
                    setColor(RED);
                    cout << "Invalid option! Try again." << endl;
                    setColor(WHITE);
                }

                setColor(YELLOW);
                cout << "Press any key to continue" << endl;
                setColor(WHITE);
                getch();
                system("cls");
                printMenu();
                printMenuHeader("Main Menu", "Manager");
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
                    setColor(YELLOW);
                    cout << "Enter your name to view personal details: " << endl;
                    setColor(WHITE);
                    cin.ignore();
                    getline(cin, searchName);

                    bool found = false;
                    for (int i = 0; i < 30; i++)
                    {
                        if (name[i] == searchName)
                        {
                            setColor(GREEN);
                            cout << left << setw(20) << "Player Name" << setw(10) << "Position" << setw(10) << "Age" << setw(12) << "Matches" << setw(15) << "Salary" << endl;
                            setColor(WHITE);
                            viewDetails(name[i], position[i], kit[i], age[i], match[i], salary[i]);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        setColor(RED);
                        cout << "Player not found!" << endl;
                        setColor(WHITE);
                    }
                }
                else if (option2 == 2)
                {
                    clearPlayer();
                    if (matchAgainst != " ")
                    {
                        setColor(CYAN);
                        cout << "Match against " << matchAgainst << " on " << matchDate << endl;
                        setColor(WHITE);
                    }
                    else
                    {
                        setColor(YELLOW);
                        cout << "No details yet!" << endl;
                        setColor(WHITE);
                    }
                }
                else if (option2 == 3)
                {
                    clearPlayer();
                    if (tournament != " ")
                    {
                        setColor(CYAN);
                        cout << "Upcoming Tournament: " << tournament << endl;
                        setColor(WHITE);
                    }
                    else {
                        setColor(YELLOW);
                        cout << "No Upcoming tournament" << endl;
                        setColor(WHITE);
                    }
                }
                else if (option2 == 4)
                {
                    clearPlayer();
                    string searchName;
                    setColor(YELLOW);
                    cout << "Enter your name to view fund details: " << endl;
                    setColor(WHITE);
                    cin.ignore();
                    getline(cin, searchName);

                    bool found = false;
                    for (int i = 0; i < 30; i++)
                    {
                        if (name[i] == searchName)
                        {
                            setColor(GREEN);
                            cout << left << setw(20) << "Name" << setw(20) << "Status" << endl;
                            setColor(WHITE);
                            status(name[i], fund[i]);
                            
                            if (bonus[i] > 0)
                            {
                                setColor(YELLOW);
                                cout << "\n=== BONUS DETAILS ===" << endl;
                                cout << "Total Bonuses Earned: $" << fixed << setprecision(0) << bonus[i] << endl;
                                cout << "Total Salary (with bonuses): $" << salary[i] << endl;
                                setColor(WHITE);
                            }
                            else
                            {
                                setColor(YELLOW);
                                cout << "\nNo bonuses earned yet!" << endl;
                                setColor(WHITE);
                            }
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        setColor(RED);
                        cout << "Player not found!" << endl;
                        setColor(WHITE);
                    }
                }
                else if (option2 == 5)
                {
                    clearPlayer();
                    for (int i = 0; i < 30; i++)
                    {
                        if (name[i] != " ")
                        {
                            if (match[i] > 30)
                            {
                                setColor(CYAN);
                                cout << name[i] << ": Senior Player" << endl;
                                setColor(WHITE);
                            }
                            else if (match[i] > 15)
                            {
                                setColor(CYAN);
                                cout << name[i] << ": Intermediate Player" << endl;
                                setColor(WHITE);
                            }
                            else {
                                setColor(CYAN);
                                cout << name[i] << ": New Player" << endl;
                                setColor(WHITE);
                            }
                        }
                    }
                }
                else if (option2 == 6)
                {
                    clearPlayer();
                    setColor(GREEN);
                    cout << "Team Roster:" << endl;
                    cout << "----------------------------------------" << endl;
                    setColor(WHITE);
                    for (int i = 0; i < 30; i++)
                    {
                        if (name[i] != " ")
                        {
                            setColor(CYAN);
                            cout << i + 1 << ". " << name[i] << " (" << position[i] << ") - Kit: " << kit[i] << endl;
                            setColor(WHITE);
                        }
                    }
                }

                else if (option2 == 7)
                {
                    clearPlayer();
                    setColor(YELLOW);
                    cout << "=== TOP SCORERS ===" << endl;
                    setColor(WHITE);

                    string tempNames[30];
                    int tempGoals[30];
                    int tempKits[30];
                    int count = 0;

                    for (int j = 0; j < 30; j++)
                    {
                        if (name[j] != " ")
                        {
                            tempNames[count] = name[j];
                            tempGoals[count] = goals[j];
                            tempKits[count] = kit[j];
                            count++;
                        }
                    }

                    for (int j = 0; j < count - 1; j++)
                    {
                        for (int k = 0; k < count - j - 1; k++)
                        {
                            if (tempGoals[k] < tempGoals[k + 1])
                            {
                                int tGoal = tempGoals[k];
                                tempGoals[k] = tempGoals[k + 1];
                                tempGoals[k + 1] = tGoal;

                                string tName = tempNames[k];
                                tempNames[k] = tempNames[k + 1];
                                tempNames[k + 1] = tName;

                                int tKit = tempKits[k];
                                tempKits[k] = tempKits[k + 1];
                                tempKits[k + 1] = tKit;
                            }
                        }
                    }

                    setColor(GREEN);
                    cout << left << setw(5) << "Rank" << setw(25) << "Player Name"
                         << setw(10) << "Kit #" << setw(10) << "Goals" << endl;
                    cout << "-------------------------------------------------------" << endl;
                    setColor(WHITE);
                    for (int j = 0; j < count; j++)
                    {
                        setColor(CYAN);
                        cout << left << setw(5) << j + 1 << setw(25) << tempNames[j]
                             << setw(10) << tempKits[j] << setw(10) << tempGoals[j] << endl;
                        setColor(WHITE);
                    }
                }
                else if (option2 == 8)
                {
                    clearPlayer();
                    string searchName;
                    setColor(YELLOW);
                    cout << "Enter your name to view goals: " << endl;
                    setColor(WHITE);
                    cin.ignore();
                    getline(cin, searchName);

                    bool found = false;
                    for (int i = 0; i < 30; i++)
                    {
                        if (name[i] == searchName)
                        {
                            setColor(CYAN);
                            cout << "\n=== Goal Statistics for " << name[i] << " ===" << endl;
                            cout << "Total Goals Scored: " << goals[i] << endl;
                            cout << "Total Matches Played: " << match[i] << endl;
                            if (match[i] > 0)
                            {
                                double avg = (double)goals[i] / match[i];
                                cout << "Average Goals per Match: " << fixed << setprecision(2) << avg << endl;
                            }
                            setColor(WHITE);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        setColor(RED);
                        cout << "Player not found!" << endl;
                        setColor(WHITE);
                    }
                }
                else if (option2 == 9)
                {
                    clearPlayer();
                    string searchName;
                    setColor(YELLOW);
                    cout << "Enter your name: ";
                    setColor(WHITE);
                    cin.ignore();
                    getline(cin, searchName);

                    int pIndex = -1;
                    for (int i = 0; i < 30; i++)
                        if (name[i] == searchName)
                            pIndex = i;

                    if (pIndex == -1)
                    {
                        setColor(RED);
                        cout << "Player not found!" << endl;
                        setColor(WHITE);
                    }
                    else
                    {
                        setColor(CYAN);
                        cout << "\nGoals Match-wise:\n";
                        for (int m = 0; m < totalMatches; m++)
                        {
                            cout << "vs " << opponent[m]
                                 << " : " << matchGoals[m][pIndex]
                                 << " goals" << endl;
                        }
                        setColor(WHITE);
                    }
                }

                else if (option2 == 10)
                {
                    clearPlayer();
                    setColor(YELLOW);
                    cout << "Press any key to continue" << endl;
                    setColor(WHITE);
                    getch();
                    system("cls");
                    break;
                }
                else {
                    setColor(RED);
                    cout << "invalid option!" << endl;
                    setColor(WHITE);
                }
                setColor(YELLOW);
                cout << "Press any key to continue" << endl;
                setColor(WHITE);
                getch();
                system("cls");
            }
        }
        else if (option == 3)
        {
            printMenu();
            printMenuHeader("Main Menu", "Coach");
            while (true)
            {
                int option3 = printCoachOption();
                if (option3 == 1)
                {
                    clearCoach();
                    setColor(YELLOW);
                    cout << "=== AUTOMATIC TEAM SELECTION ===" << endl;
                    cout << "Formation: 1GK - 4DEF - 3MID - 3ATK" << endl;
                    cout << "Selection Criteria:" << endl;
                    cout << "- GK: Best overall (included)" << endl;
                    cout << "- DEF: Top 4 by matches played" << endl;
                    cout << "- MID: Top 3 by goals scored" << endl;
                    cout << "- ATK: Top 3 by goals scored" << endl;
                    cout << "\n=== SELECTED TEAM ===" << endl;
                    setColor(WHITE);

                    string gkNames[5], defNames[20], midNames[20], atkNames[20];
                    int gkIndices[5], defIndices[20], midIndices[20], atkIndices[20];
                    int gkCount = 0, defCount = 0, midCount = 0, atkCount = 0;

                    for (int j = 0; j < 30; j++)
                    {
                        if (name[j] != " ")
                        {
                            if (position[j] == "GK")
                            {
                                gkNames[gkCount] = name[j];
                                gkIndices[gkCount] = j;
                                gkCount++;
                            }
                            else if (position[j] == "DEF")
                            {
                                defNames[defCount] = name[j];
                                defIndices[defCount] = j;
                                defCount++;
                            }
                            else if (position[j] == "MID")
                            {
                                midNames[midCount] = name[j];
                                midIndices[midCount] = j;
                                midCount++;
                            }
                            else if (position[j] == "ATK")
                            {
                                atkNames[atkCount] = name[j];
                                atkIndices[atkCount] = j;
                                atkCount++;
                            }
                        }
                    }

                    setColor(LIGHT_GREEN);
                    cout << "\n--- GOALKEEPERS (1) ---" << endl;
                    setColor(WHITE);
                    if (gkCount > 0)
                    {
                        setColor(CYAN);
                        cout << gkNames[0] << " (GK) - Kit: " << kit[gkIndices[0]] << endl;
                        setColor(WHITE);
                    }

                    setColor(LIGHT_GREEN);
                    cout << "\n--- DEFENDERS (4) ---" << endl;
                    setColor(WHITE);
                    int defToSelect = (defCount < 4) ? defCount : 4;
                    for (int i = 0; i < defCount - 1; i++)
                    {
                        int maxIndex = i;
                        for (int j = i + 1; j < defCount; j++)
                        {
                            if (match[defIndices[j]] > match[defIndices[maxIndex]])
                            {
                                maxIndex = j;
                            }
                        }
                        swap(defIndices[i], defIndices[maxIndex]);
                        swap(defNames[i], defNames[maxIndex]);
                    }
                    for (int i = 0; i < defToSelect; i++)
                    {
                        setColor(CYAN);
                        cout << defNames[i] << " (DEF) - Kit: " << kit[defIndices[i]] << " - Matches: " << match[defIndices[i]] << endl;
                        setColor(WHITE);
                    }

                    setColor(LIGHT_GREEN);
                    cout << "\n--- MIDFIELDERS (3) ---" << endl;
                    setColor(WHITE);
                    int midToSelect = (midCount < 3) ? midCount : 3;
                    for (int i = 0; i < midCount - 1; i++)
                    {
                        int maxIndex = i;
                        for (int j = i + 1; j < midCount; j++)
                        {
                            if (goals[midIndices[j]] > goals[midIndices[maxIndex]])
                            {
                                maxIndex = j;
                            }
                        }
                        swap(midIndices[i], midIndices[maxIndex]);
                        swap(midNames[i], midNames[maxIndex]);
                    }
                    for (int i = 0; i < midToSelect; i++)
                    {
                        setColor(CYAN);
                        cout << midNames[i] << " (MID) - Kit: " << kit[midIndices[i]] << " - Goals: " << goals[midIndices[i]] << endl;
                        setColor(WHITE);
                    }

                    setColor(LIGHT_GREEN);
                    cout << "\n--- ATTACKERS (3) ---" << endl;
                    setColor(WHITE);
                    int atkToSelect = (atkCount < 3) ? atkCount : 3;
                    for (int i = 0; i < atkCount - 1; i++)
                    {
                        int maxIndex = i;
                        for (int j = i + 1; j < atkCount; j++)
                        {
                            if (goals[atkIndices[j]] > goals[atkIndices[maxIndex]])
                            {
                                maxIndex = j;
                            }
                        }
                        swap(atkIndices[i], atkIndices[maxIndex]);
                        swap(atkNames[i], atkNames[maxIndex]);
                    }
                    for (int i = 0; i < atkToSelect; i++)
                    {
                        setColor(CYAN);
                        cout << atkNames[i] << " (ATK) - Kit: " << kit[atkIndices[i]] << " - Goals: " << goals[atkIndices[i]] << endl;
                        setColor(WHITE);
                    }

                    setColor(YELLOW);
                    cout << "\n=== TOTAL PLAYERS SELECTED: " << (1 + defToSelect + midToSelect + atkToSelect) << " ===" << endl;
                    setColor(WHITE);
                }
                else if (option3 == 2)
                {
                    clearCoach();
                    setColor(YELLOW);
                    cout << "Press any key to continue" << endl;
                    setColor(WHITE);
                    getch();
                    system("cls");
                    break;
                }
                else
                {
                    setColor(RED);
                    cout << "Invalid option! Try again." << endl;
                    setColor(WHITE);
                }

                setColor(YELLOW);
                cout << "Press any key to continue" << endl;
                setColor(WHITE);
                getch();
                system("cls");
                printMenu();
                printMenuHeader("Main Menu", "Coach");
            }
        }
        else if (option == 4)
        {
            return 0;
        }
        else {
            setColor(RED);
            cout << "Invalid Option" << endl;
            setColor(WHITE);
        }
    }
    return 0;
}

void printMenu()
{
    setColor(GREEN);
    cout << "=================================================" << endl;
    cout << "=---------Football Management System------------=" << endl;
    cout << "=================================================" << endl;
    setColor(WHITE);
}

void printMenuHeader(string mainMenu, string subMenu)
{
    string msg = mainMenu + " > " + subMenu;
    setColor(GREEN);
    cout << msg << endl;
    cout << "------------------------------" << endl;
    setColor(WHITE);
}

int printOption1()
{
    int option;
    setColor(YELLOW);
    cout << "Select any of the following option number" << endl;
    setColor(CYAN);
    cout << "1. Manager " << endl;
    cout << "2. Player" << endl;
    cout << "3. Coach" << endl;
    cout << "4. Exit" << endl;
    setColor(YELLOW);
    cout << "Enter Option: ";
    setColor(WHITE);
    cin >> option;
    return option;
}

int printAdminOption()
{
    int option;
    setColor(YELLOW);
    cout << "Select any of the following option number" << endl;
    setColor(CYAN);
    cout << "1. ADD player " << endl;
    cout << "2. ADD Match details " << endl;
    cout << "3. ADD upcoming tournament " << endl;
    cout << "4. View player details " << endl;
    cout << "5. View fund details " << endl;
    cout << "6. Update Player Jersey Number " << endl;
    cout << "7. Search Player by Name" << endl;
    cout << "8. Delete Player by Name" << endl;
    cout << "9. Add Goals After Match" << endl;
    cout << "10. View Top Scorers" << endl;
    cout << "11. Exit" << endl;
    setColor(YELLOW);
    cout << "Enter Option: ";
    setColor(WHITE);
    cin >> option;
    return option;
}

int printCoachOption()
{
    int option;
    setColor(YELLOW);
    cout << "Select any of the following option number" << endl;
    setColor(CYAN);
    cout << "1. Generate Automatic Team Selection (11 Players)" << endl;
    cout << "2. Exit" << endl;
    setColor(YELLOW);
    cout << "Enter Option: ";
    setColor(WHITE);
    cin >> option;
    return option;
}

void viewDetails(string a, string b, int c, int d, int e, double f)
{
    setColor(CYAN);
    cout << left << setw(20) << a << setw(10) << b << setw(10) << d << setw(12) << e << setw(15) << fixed << setprecision(2) << f << endl;
    setColor(WHITE);
}

void status(string a, string b)
{
    setColor(CYAN);
    cout << left << setw(20) << a << setw(20) << b << endl;
    setColor(WHITE);
}

int printPlayerOption()
{
    int option;
    setColor(YELLOW);
    cout << "Select any of the following option number" << endl;
    setColor(CYAN);
    cout << "1. View Personal details" << endl;
    cout << "2. Upcoming Match details" << endl;
    cout << "3. Upcoming tournament" << endl;
    cout << "4. View fund details" << endl;
    cout << "5. Performance Report" << endl;
    cout << "6. View Team Details" << endl;
    cout << "7. View Top Scorers" << endl;
    cout << "8. View My Goals" << endl;
    cout << "9. View Goals Match-wise" << endl;
    cout << "10. Exit" << endl;
    setColor(YELLOW);
    cout << "Enter Option: ";
    setColor(WHITE);
    cin >> option;
    return option;
}

void displaySplashScreen()
{
    system("cls");
    setColor(YELLOW);
    cout << "    ╔═════════════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "    ║                                                                                         ║\n";
    setColor(CYAN);
    cout << "    ║             __        __   _                            _                               ║\n";
    cout << "    ║             \\ \\      / /__| | ___ ___  _ __ ___   ___  | |_ ___                         ║\n";
    cout << "    ║              \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\                        ║\n";
    cout << "    ║               \\ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) |                       ║\n";
    cout << "    ║                \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/                        ║\n";

    setColor(YELLOW);
    cout << "    ║                                                                                         ║\n";
    cout << "    ║                        *** UET TITANS FOOTBALL CLUB ***                                 ║\n";
    cout << "    ║                                                                                         ║\n";
    cout << "    ║                                                                                         ║\n";
    cout << "    ║                                                                                         ║\n";
    cout << "    ║                       Elite Training • Champions Mindset                                ║\n";
    cout << "    ║                                                                                         ║\n";
    cout << "    ╚═════════════════════════════════════════════════════════════════════════════════════════╝\n";
    showLoading();
     cout << "    Program is now starting...\n";
    Sleep(600);
    system("cls");
}
void showLoading() {
    setColor(CYAN); 
    srand(time(0));
    cout << "\n                                 Loading";
    for (int i = 0; i < 10; i++) {
        int color = rand() % 15 + 1;
        setColor(color);
        cout << ".";
        Sleep(300); 
    }
    cout << "\n\n";
    setColor(WHITE); 
}
void displayStyledMenu()
{
    setColor(BRIGHT_CYAN);
    cout << "\n";
    cout << "  ╔════════════════════════════════════════════════════════════════════╗\n";
    cout << "  ║                                                                    ║\n";
    cout << "  ║                  FOOTBALL MANAGEMENT SYSTEM                        ║\n";
    cout << "  ║                                                                    ║\n";
    cout << "  ║                    UET TITANS FOOTBALL CLUB                        ║\n";
    cout << "  ║                                                                    ║\n";
    cout << "  ╠════════════════════════════════════════════════════════════════════╣\n";
    cout << "  ║                                                                    ║\n";
    cout << "  ║                      SELECT YOUR ROLE                              ║\n";
    cout << "  ║                                                                    ║\n";
    cout << "  ║   ┌─────────────────────────────────────────────────────────────┐  ║\n";
    cout << "  ║   │                                                             │  ║\n";
    setColor(BRIGHT_YELLOW);
    cout << "  ║   │    1.    MANAGER - Manage Players, Matches & Tournament     │  ║\n";
    setColor(BRIGHT_CYAN);
    cout << "  ║   │                                                             │  ║\n";
    cout << "  ║   │    ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄       │  ║\n";
    cout << "  ║   │                                                             │  ║\n";
    setColor(BRIGHT_YELLOW);
    cout << "  ║   │    2.   PLAYER - View Profile, Stats & Performance          │  ║\n";
    setColor(BRIGHT_CYAN);
    cout << "  ║   │                                                             │  ║\n";
    cout << "  ║   │    ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄       │  ║\n";
    cout << "  ║   │                                                             │  ║\n";
    setColor(BRIGHT_YELLOW);
    cout << "  ║   │    3.    COACH - Generate Team Selection and Formation      │  ║\n";
    setColor(BRIGHT_CYAN);
    cout << "  ║   │                                                             │  ║\n";
    cout << "  ║   │    ┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄       │  ║\n";
    cout << "  ║   │                                                             │  ║\n";
    setColor(BRIGHT_YELLOW);
    cout << "  ║   │    4.    EXIT - Quit the Application                        │  ║\n";
    setColor(BRIGHT_CYAN);
    cout << "  ║   │                                                             │  ║\n";
    cout << "  ║   └─────────────────────────────────────────────────────────────┘  ║\n";
    cout << "  ║                                                                    ║\n";
    cout << "  ╠════════════════════════════════════════════════════════════════════╣\n";
    cout << "  ║                                                                    ║\n";
    setColor(BRIGHT_YELLOW);
    cout << "  ║         Enter Your Choice (1-4):                                   ║\n";
    setColor(BRIGHT_CYAN);
    cout << "  ║                                                                    ║\n";
    cout << "  ╚════════════════════════════════════════════════════════════════════╝\n";
    cout << "\n";
    setColor(WHITE);
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

void clearCoach()
{
    system("cls");
    printMenu();
    printMenuHeader("Main Menu", "Coach");
}

void distributeBonuses()
{
    setColor(YELLOW);
    cout << "=== BONUS SUMMARY ===" << endl;
    cout << "Criteria:" << endl;
    cout << "- 2+ Goals (per match): 1000 Bonus" << endl;
    cout << "- 4+ Goals (per match): 2000 Bonus" << endl;
    cout << "\nNote: Only Midfielders and Attackers are eligible for bonuses\n" << endl;
    setColor(WHITE);

    double totalBonusGiven = 0;
    int playersWithBonus = 0;

    setColor(GREEN);
    cout << left << setw(25) << "Player Name" << setw(10) << "Position" << setw(15) << "Total Bonus" << setw(20) << "Current Salary" << endl;
    cout << "====================================================================================\n";
    setColor(WHITE);

    for (int i = 0; i < 30; i++)
    {
        if (name[i] != " " && (position[i] == "MID" || position[i] == "ATK"))
        {
            if (bonus[i] > 0)
            {
                totalBonusGiven += bonus[i];
                playersWithBonus++;

                setColor(CYAN);
                cout << left << setw(25) << name[i] << setw(10) << position[i] << setw(15) << "$" << fixed << setprecision(0) << bonus[i]
                     << setw(20) << "$" << salary[i] << endl;
                setColor(WHITE);
            }
        }
    }

    setColor(GREEN);
    cout << "\n====================================================================================\n";
    setColor(YELLOW);
    cout << "Total Players with Bonuses: " << playersWithBonus << endl;
    cout << "Total Bonus Distributed: $" << fixed << setprecision(0) << totalBonusGiven << endl;
    setColor(WHITE);
}
