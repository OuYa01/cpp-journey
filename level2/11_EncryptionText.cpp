#include <iostream>
#include <string>
using namespace std;

/**
 * Readstring - this function just to read a textfrom user
 * 
 * Return : the text that get from user
 */
string Readstring()
{
    string str;

    cout << "Entre a Text : ";
    getline(cin, str);

    return (str);
}

/**
 * EncryptText - its encrypt text using Encryption Key
 * @str: the text to be encrypt
 * @EncryptionKey: the key that will be added to the ASCII of each character to make it encrypted
 * 
 * Return : the encrypted text
 */
string EncryptText(string str, short EncryptionKey)
{
    int i;

    for (i = 0; i <= str.length(); i++)
    {
        str[i] = str[i] + EncryptionKey;
    }

    return (str);
}

/**
 * DecryptText - its decrypt text using Encryption Key
 * @str: the text to be decrypt
 * @EncryptionKey: the key that will be subtracted from the ASCII of each character to make it decrypted
 * 
 * Return : the decrypted text
 */
string DecryptText(string str, short EncryptionKey)
{
    int i;

    for (i = 0; i <= str.length(); i++)
    {
        str[i] = str[i] - EncryptionKey;
    }

    return (str);
}

/**
 * main - the Entry point of the program
 * 
 * Return : 0 if the program run correctly
 */
int main(void)
{
    const short EncryptionKey = 30;
    string a = EncryptText(Readstring(), EncryptionKey);
    cout << a << endl;
    cout << DecryptText(a, EncryptionKey);

    return (0);
}