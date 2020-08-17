/***********************************************************
* Project Name: Pok�mon
* File Name: options.cpp
* Started on: 2020-08-15
************************************************************
* Author: Jimmy B�land-B�dard (NoxGamingQC)
* Last update author: Jimmy B�land-B�dard (NoxGamingQC)
* Last update: 2020-08-17
************************************************************
* Description:
************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int openOptionsFile() {
    string line;
    fstream optionFile("settings.opt");
    if (optionFile.is_open()) {
        while (getline(optionFile, line))
        {
            cout << line << '\n';
        }
        optionFile.close();
    } else {
        optionFile << line << '\n';
    }
    return 0;
}