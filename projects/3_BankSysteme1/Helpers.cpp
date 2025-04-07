#include "main.h"




/**
 * LoadAllDataFromVecToFile - Load All Data from Vector to file, bcs when we update a data in our programme
 *                            We Update it just in the vectore so we need to make it back to our file
 * @AllClientData : This is a referance to a vector of structure 'stClient' to Update Data in it and send it back to file
 * 
 * Return : Nothing
 */
void LoadAllDataFromVecToFile(vector<stClient>& AllClientsData)
{
    ofstream ClientDataFile(FileName);

    for (stClient& Client : AllClientsData)
    {
        ClientDataFile << ConverClientToRecordeLine(Client);
    }
}


/**
 * LoadAllClientsDataFromFile - Load All Clients Data From File To vector, This Function will help us,
 *                              bcs When programme ends data will stay always in File, But vectore will
 *                              Forget all the data, so we need always when start the programme To load
 *                              This data from file to Vector
 * 
 * @AllClientData : This is a referance to a vector of structure 'stClient' to Update Data in it and send it back to file
 * 
 * Return : Nothing
 *                              
 */
void LoadAllClientsDataFromFile(vector<stClient>& AllDataClients)
{
    ifstream ClienData;

    ClienData.open(FileName, ios::in); //open file (Read Mode)
    if (!ClienData)
    {
        std::cerr << "Error Openning the file";
        return ;
    }

    string line;
    stClient Client;

    while (getline(ClienData, line))
    {
        Client = convertClientRecordeToClient(line);
        AllDataClients.push_back(Client);
    }

    ClienData.close();  
}



/**
 * BackToMenu - When a function end in this systeme its shows this to u can see the output,
 *              Then if you want u can back to main menue by Press any key
 * 
 */
void BackToMenu()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nPress any key to go back to main menue... ";
    cin.get();
}


/**
 * SplitStringIntoVector - This will split A string into a Vector using separateur.
 * 
 * @RecordeLine : This is the line will be look smtg like that : "B01#//#0000#//#Oussama#//#+212608095577#//#20000".
 * @separateur : the delimiter that separte data in this line.
 * 
 * Return : Vector of strings that has each data from this line
 */
vector<string> SplitStringIntoVector(string RecordeLine, string separateur)
{
    int pos;
    vector<string> vec;

    while ((pos = RecordeLine.find(separateur)) != std::string::npos)
    {
        vec.push_back(RecordeLine.substr(0, pos));
        RecordeLine = RecordeLine.substr(pos + separateur.length());
    }
    vec.push_back(RecordeLine);

    return (vec);
}

/**
 * ConverClientToRecordeLine - This Function will Convert Data of client in a struct to one line,
 *                             Bcs It will help us a lot in our file to can get data from it again
 * 
 * @client - its a Structure That Hold All client Data.
 * @separateur - That a separateur that we will Separte data with it in this line. Will look smtg like that
 *               "B01#//#0000#//#Oussama#//#+212608095577#//#20000"
 * 
 * Return : The line That has all data
 */
string ConverClientToRecordeLine(stClient client, string separateur)
{
    return (client.AccountNumber + separateur + client.PinCode + separateur + client.Name + separateur + client.PhoneNumber + separateur + to_string(client.accountBalance) + '\n');
}


/**
 * convertClientRecordeToClient - Convert Client Recorde(Bcs in our File, Data looks Like one line) to Client structure
 * 
 * @RecordeLine : The line of data ~ its smtg like that "B01#//#0000#//#Oussama#//#+212608095577#//#20000"
 * 
 * Return : Client data 
 */
stClient convertClientRecordeToClient(string RecordeLine)
{
    vector<string> vec = SplitStringIntoVector(RecordeLine);
    stClient Client;

    if (vec.size() < 5) {
        cout << "Error: Record line does not contain enough fields!" << endl;
        return stClient{}; // Return an empty client structure
    }

    Client.AccountNumber = vec[0];
    Client.PinCode = vec[1];
    Client.Name = vec[2];
    Client.PhoneNumber = vec[3];
    Client.accountBalance = stod(vec[4]);

    return Client;
}