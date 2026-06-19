#include "main.h"



/**
 * userRecorde : Admin#//#1111#//#-1
 */
stUsers convertUserRecordeToUser(string UserRecorde)
{
    vector<string> temp = SplitStringIntoVector(UserRecorde, "#//#");
    stUsers user;

    if (temp.size() < 3)
    {
        cout << "Error: Record line does not contain enough fields!" << endl;
        return stUsers{}; // Return an empty users structure
    }
    user.UserName = temp[0];
    user.PassWord = temp[1];
    user.Permission = stoi(temp[2]);

    return (user);
}

void LoadAllUsersDataFromFile(vector<stUsers>& AllUsersData)
{
    ifstream UsersData;
    UsersData.open(UsersFileName, ios::in); // Open file for reading (get inputs from the file)
    
    if (!UsersData.is_open())
    {
        std::cerr << "Error file not opened";
        return;
    }
    string line;
    stUsers user;

    while(getline(UsersData, line))
    {
        user = convertUserRecordeToUser(line);
        AllUsersData.push_back(user);
    }

    UsersData.close();
}   

bool CheckIfUserExist(stUsers& user, vector<stUsers>& AllUsersData)
{
    for (stUsers tempuser : AllUsersData)
    {
        if (user.UserName == tempuser.UserName) 
        {
            if (user.PassWord == tempuser.PassWord)
            {
                user.Permission = tempuser.Permission;
                return true;
            }
            else
                return false;
        }
    }

    return false;
}

void ShowLoginScreen()
{
    cout << "-------------------------------------------\n";
    cout << "\t\t Login Screen\n";
    cout << "-------------------------------------------\n";
}

void GetUserInfos(stUsers& user)
{
    cout << "Enter Username? ";
    cin >> user.UserName;
    cout << "Enter PassWord? ";
    cin >> user.PassWord;
}


void showUsersMenueScreen()
{
    cout << "===============================================\n";
    cout << "\t\tUsers Menue Screen\n";
    cout << "===============================================\n";
    cout << "\t[1] List Users.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delet User.\n";
    cout << "\t[4] Update User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Main Menue.\n";
    cout << "===============================================\n";
    cout << "Choose what do you want to do? [1 to 6]?  ";
}


void PrintUserCard(stUsers& user)
{
    cout << "| " << left << setw(15) << user.UserName;
    cout << "| " << left << setw(12) << user.PassWord;
    cout << "| " << left << setw(40) << user.Permission;
    cout << "\n";
}

void ShowUsersList(vector<stUsers>& AllUsersList)
{
    cout << "\tUsers List ("<< AllUsersList.size() << ") User(s)\n\n";
    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(12) << "PassWord";
    cout << "| " << left << setw(40) << "Permissions";


    cout << "\n";
    for (stUsers& user : AllUsersList)
    {
         PrintUserCard(user);
    }
}

bool UserFound(vector<stUsers>& AllUserData, string& TargetUserName, stUsers& User)
{
    int i;

    for (i = 0; i < AllUserData.size(); i++)
    {
        if (TargetUserName == AllUserData[i].UserName)
        {
            User = AllUserData[i];
            return true;
        }
            
    }
    return (false);
}
string ConverUserToRecordeLine(stUsers User, string separateur)
{
    return (User.UserName + separateur + User.PassWord + separateur + to_string(User.Permission) + '\n');
}




void SetPermissionToUser(stUsers& User)
{
    char confirm;
    cout << "Do you want to give full access? (y/n)?  ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y')
    {
        User.Permission = Permissions::FullAccess;
        return;
    }

    User.Permission = 0;

    cout << "Do you want to give access to: \n\n";
    cout << "Show client List? y/n? ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y')
        User.Permission |= Permissions::Client_List_p;
    
    cout << "Add client? y/n? ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y')
        User.Permission |= Permissions::Add_Client_P;

    cout << "Delete client? y/n? ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y')
        User.Permission |= Permissions::Delete_Client_p;

    cout << "Update client? y/n? ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y')
        User.Permission |= Permissions::Update_Client_p;

    cout << "Find client? y/n? ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y')
        User.Permission |= Permissions::Find_Client_p;

    cout << "Transactions? y/n? ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y')
        User.Permission |= Permissions::Transactions_p
        ;
    cout << "Manage Users? y/n? ";
    cin >> confirm; 
    if (confirm == 'y' || confirm == 'Y')
        User.Permission |= Permissions::ManageUsers_P;
}


void AddNewUser(vector<stUsers>& AllUsersData)
{
    stUsers User;
    ofstream UserDataFile(UsersFileName, ios::app);
    char Again;

    cout << "______________________________________________________________________________________________________________________\n";
    cout << "Adding New User\n";
    cout << "______________________________________________________________________________________________________________________\n";
    
    do
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entre User Name: ";
        getline(cin, User.UserName);

        if (UserFound(AllUsersData, User.UserName, User))
        {
            cout << "\nUser Found !\nEntre Another one? (Y/n)? ";
            cin >> Again;
            if (Again == 'y' || Again == 'Y')
                continue;
            else
                return ;
        }

        cout << "Entre Password : ";
        getline(cin, User.PassWord);
        
        SetPermissionToUser(User);

        if (UserDataFile.is_open())
        {
            AllUsersData.push_back(User);
            UserDataFile << ConverUserToRecordeLine(User);
        }
        else
        cout << "error file not opening\n";

        cout << "User Add Successfully, Do you want to add More Users (Y/n)? ";
        cin >> Again;

    }while(Again == 'Y' || Again == 'y');
    UserDataFile.close();
}

void ManageUsersMenueSwitch(vector<stUsers>& AllUsersData, vector<stClient>& AllClientData, stUsers& RootUser)
{
    int YourChoice;


    do
    {
        system("clear");
        showUsersMenueScreen();
        cin >> YourChoice;
        switch (YourChoice)
        {
            case 1:
                system("clear");
                ShowUsersList(AllUsersData);
                BackToMenu();
                break;
            case 2:
                system("clear");
                AddNewUser(AllUsersData);
                BackToMenu();
                break;
            case 3:
                system("clear");
                /* code */
                BackToMenu();
                break;
            case 4:
                system("clear");
                /* code */
                BackToMenu();
                break;
            case 5:
                system("clear");
                /* code */
                BackToMenu();
                break;
            case 6:
                MainMenueSwitch(AllClientData, AllUsersData, RootUser);
                break;
            default:
                cout << "Choice Not Found, Try Again";
                BackToMenu();
                break;
        }
    } while (YourChoice != 6);

   
}

bool CheckAccessPermession(stUsers& RootUser, int PermessionToCheck)
{
    if (RootUser.Permission & PermessionToCheck)
        return (true);
    return (false);
}

void PrintAccessDenied()
{
    cout << "-----------------------------------\n";
    cout << "\t Access Denied,\nYou Don't Have Permission To Do This,\nPlease contact your admin.\n";
    cout << "-----------------------------------\n";
}

void Login()
{
    vector<stUsers> AllUsersData;
    LoadAllUsersDataFromFile(AllUsersData);
    ShowLoginScreen();
    stUsers RootUser;
start:    
    GetUserInfos(RootUser);

    if (CheckIfUserExist(RootUser, AllUsersData))
    {
        vector<stClient> AllClientsData;
        LoadAllClientsDataFromFile(AllClientsData);
        MainMenueSwitch(AllClientsData, AllUsersData, RootUser);
    }
    else
    {
        cout << "Invalide UserName/Password!\n";
        goto start;
    }
}



