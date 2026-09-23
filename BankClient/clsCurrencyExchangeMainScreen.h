#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeMainScreen : protected clsScreen
{
private:
    enum enCurrencyExchange
    {
        eListCurrencies = 1, eFindCurrency = 2,
        eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenu = 5
    };
    static short _ReadCurrencyExchangeMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }
    static void _ShowListCurrenciesScreen()
    {
        clsListCurrenciesScreen::ShowCurrenciesList();
    }
    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateRateScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }
    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }
   
    static void _GoBackToCurrencyExchangeMenu()
    {
        cout << "\n\nPress any key to go back to Currencies Menu...\n";

        system("pause>0");
        ShowCurrencyScreen();
    }
    static  void _PerformCurrencyExchangeMenuOption(enCurrencyExchange CurrencyExchangeMenuOption)
    {
        switch (CurrencyExchangeMenuOption)
        {
        case enCurrencyExchange::eListCurrencies:
        {
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }
        case enCurrencyExchange::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }
        case enCurrencyExchange::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }
        case enCurrencyExchange::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }
        case enCurrencyExchange::eMainMenu:
        {

        }
        }
    }
public:

    static void ShowCurrencyScreen()
    {
       

        system("cls");
        _DrawScreenHeader("Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformCurrencyExchangeMenuOption((enCurrencyExchange)_ReadCurrencyExchangeMenuOption());
    }

};


