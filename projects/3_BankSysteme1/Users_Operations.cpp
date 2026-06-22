#include "Headers/users.h"



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

void LoadAllUsersDataFromVecToFile(vector<stUsers>& AllUsersData)
{
    ofstream UserDataFile(UsersFileName);

    for (stUsers& User : AllUsersData)
    {
        UserDataFile << ConverUserToRecordeLine(User);
    }
}

bool CheckIfUserExist(vector<stUsers>& AllUsersData)
{
    for (stUsers tempuser : AllUsersData)
    {
        if (RootUser.UserName == tempuser.UserName) 
        {
            if (RootUser.PassWord == tempuser.PassWord)
            {
                RootUser.Permission = tempuser.Permission;
                return true;
            }
            else
                return false;
        }
    }

    return false;
}


void GetUserInfos()
{
    cout << "Enter Username? ";
    cin >> RootUser.UserName;
    cout << "Enter PassWord? ";
    cin >> RootUser.PassWord;
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


void DeletUser(vector<stUsers>& AllUsersData, string& TargetUsername)
{
    int i;

    for (i = 0; i < AllUsersData.size(); i++)
    {
        if (AllUsersData[i].UserName == TargetUsername)
        {
            AllUsersData.erase(AllUsersData.begin() + i);
            break;
        }
    }

}

void DeletUserByUserName(vector<stUsers>& AllUsersData)
{
    stUsers User;
    string TargetUsername;
    char Del;

    cout << "______________________________________________________________________________________________________________________\n\n";
    cout << "\tDelet User\n";
    cout << "\n\n______________________________________________________________________________________________________________________\n\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entre Username: ";
    getline(cin, TargetUsername);
    
    if (TargetUsername == "Admin")
    {
        cout << "You can't Delet Admin from the systeme\n";
        return;
    }

    if (UserFound(AllUsersData, TargetUsername, User))
    {
        PrintUserCard(User);
        cout << "\nAre you sure You Want To delet this User ? (Y/N)";
        cin >> Del;
        if (Del == 'Y' || Del == 'y')
        {
            DeletUser(AllUsersData, TargetUsername);
            LoadAllUsersDataFromVecToFile(AllUsersData);
            cout << "\nUser Deleted Succ\n";
        }
        return ;
    }
    cout << "User Not Found!!\n";

}


void UpdateUser(vector<stUsers>& AllUsersData, string& TargetUsername)
{

    for (stUsers& User : AllUsersData)
    {
        if (User.UserName == TargetUsername)
        {
            User.UserName = TargetUsername;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entre New UserName : ";
            getline(cin, User.UserName);
            cout << "Entre New PassWord: ";
            getline(cin ,User.PassWord);
            cout << "Change Permissions: \n";
            SetPermissionToUser(User);
  
            break;
        }
    }

}

void UpateUserDataByUserName(vector<stUsers>& AllUsersData)
{
    stUsers User;
    string TargetUserName;
    char Update;

    cout << "______________________________________________________________________________________________________________________\n\n";
    cout << "\t\tUpdate User\n";
    cout << "\n\n______________________________________________________________________________________________________________________\n\n";
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entre Username: ";
    getline(cin, TargetUserName);

    if (TargetUserName == "Admin")
    {
        cout << "You can't Update Admin Infos\n";
        return;
    }
    if (UserFound(AllUsersData, TargetUserName, User))
    {
        PrintUserCard(User);
        cout << "\nAre you sure You Want To Upate this User ? (Y/N)";
        cin >> Update;
        if (Update == 'Y' || Update == 'y')
        {
            UpdateUser(AllUsersData, TargetUserName);
            LoadAllUsersDataFromVecToFile(AllUsersData);
            cout << "\nUser Updated succ!!\n";
        }
        return ;
    }
    
    cout << "\nUser Not Found!!\n";
}


void FindUser(vector<stUsers>& AllUsersData)
{
    string TargetUsername;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entre Username: ";
    getline(cin, TargetUsername);
    if (TargetUsername == "Admin")
    {
        cout << "Admin found, But You can't See his Informations.\n";
        return;
    }
    int i;

    for (i = 0; i < AllUsersData.size(); i++)
    {
        if (TargetUsername == AllUsersData[i].UserName)
        {
            cout << "THe follwoing are User details: \n";
            cout << "------------------------------------------------f-------\n";
            PrintUserCard(AllUsersData[i]);
            cout << "-------------------------------------------------------\n";
            return ;
        }
    }

    cout << "User with UserName : " << TargetUsername << " is not found!\n";
}


void ManageUsersMenueSwitch(vector<stUsers>& AllUsersData, vector<stClient>& AllClientData)
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
                DeletUserByUserName(AllUsersData);
                BackToMenu();
                break;
            case 4:
                system("clear");
                UpateUserDataByUserName(AllUsersData);
                BackToMenu();
                break;
            case 5:
                system("clear");
                FindUser(AllUsersData);
                BackToMenu();
                break;
            case 6:
                MainMenueSwitch(AllClientData, AllUsersData);
                break;
            default:
                cout << "Choice Not Found, Try Again";
                BackToMenu();
                break;
        }
    } while (YourChoice != 6);

   
}

bool CheckAccessPermession(int PermessionToCheck)
{
    if (RootUser.Permission & PermessionToCheck)
        return (true);
    return (false);
}

