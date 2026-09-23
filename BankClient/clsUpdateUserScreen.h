#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"
using namespace std;
class clsUpdateUserScreen : protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";
    }
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permissions: ";
        User.Permissions = _ReadPermissionsToSet();
    }
    static int _ReadPermissionsToSet()
    {
        int Permission = 0;
        char Answer = 'n';
        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
            return clsUser::enPermissions::eAll;
        cout << "\nDo you want to give access to :\n";
        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
            Permission += clsUser::enPermissions::pListClient;

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
            Permission += clsUser::enPermissions::pAddNewClient;

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
            Permission += clsUser::enPermissions::pDeleteClient;

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
            Permission += clsUser::enPermissions::pUpdateClient;

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
            Permission += clsUser::enPermissions::pFindClient;

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
            Permission += clsUser::enPermissions::pTransactions;

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
            Permission += clsUser::enPermissions::pManageUsers;

        cout << "\nShow Login Register? y/n? ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
            Permission += clsUser::enPermissions::pShowLogInRegister;
        return Permission;
    }
public:

    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("\tUpdate User Screen");

        string UserName = "";

        cout << "\nPlease Enter User Name: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);

        _PrintUser(User1);

        cout << "\nAre you sure you want to update this user y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";

            _ReadUserInfo(User1);

            clsUser::enSaveResults SaveResult;

            SaveResult = User1.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nUser Updated Successfully :-)\n";

                _PrintUser(User1);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError user was not saved because it's Empty";
                break;

            }

            }

        }

    }
};

