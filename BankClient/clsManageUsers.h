#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUsers :protected clsScreen
{
private:
    enum enManageUsersOptions
    {
        eListUser = 1, eAddNewUsers = 2,
        eDeleteUser = 3, eUpdateUser = 4,
        eFindUser = 5, eMainMenue = 6
    };
    static short _ReadManageUsersMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }
    static void _GoBackToManageUsersMenu()
    {
        cout << "\n\nPress any key to go back to Manage Users Menu...\n";

        system("pause>0");
        ShowManageUsersScreen();
    }
    static void _ShowListUsersScreen()
    {
        //cout << "\n List Users Screen will be here.\n";
        clsListUsersScreen::ShowUsersList();
    }
    static void _ShowAddNewUsersScreen()
    {
        //cout << "\n Add New User Screen will be here.\n";
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }
    static void _ShowDeleteUsersScreen()
    {
        //cout << "\n Delete User Screen will be here.\n";
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }
    static void _ShowUpdateUserScreen()
    {
        //cout << "\n Update User Screen will be here.\n";
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }
    static void _ShowFindUserScreen()
    {
        //cout << "\n Find User Screen will be here.\n";
        clsFindUserScreen::ShowFindUserScreen();
    }
    static void _PerformManageUsersMenuOption(enManageUsersOptions ManageUserMenuOption)
    {
        switch (ManageUserMenuOption)
        {
        case enManageUsersOptions::eListUser:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case enManageUsersOptions::eAddNewUsers:
        {
            system("cls");
            _ShowAddNewUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case enManageUsersOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case enManageUsersOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case enManageUsersOptions::eFindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case enManageUsersOptions::eMainMenue:
        {

        }
        }
    }

public:
    static void ShowManageUsersScreen()
    {
        if (!CheckAccessRight(clsUser::pManageUsers))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t  Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformManageUsersMenuOption((enManageUsersOptions)_ReadManageUsersMenuOption());
    }
};

