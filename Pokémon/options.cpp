/***********************************************************
* Project Name: Pokémon
* File Name: options.cpp
* Started on: 2020-08-15
************************************************************
* Author: Jimmy Béland-Bédard (NoxGamingQC)
* Last update author: Jimmy Béland-Bédard (NoxGamingQC)
* Last update: 2020-08-17
************************************************************
* Description:
************************************************************/

#include "options.h"

using namespace std;

int checkSettingsFile() {
    string line;
    ifstream readSettingFile("settings.txt");
    if (readSettingFile.is_open()) {
        cout << "Setting file opened" << endl;
        while (getline(readSettingFile, line))
        {
            string currentSettingName = "";
            string currentSettingValue = "";
            for (int i = 0; i < line.find(':'); i++) {
                currentSettingName += line[i];
            }
            cout << currentSettingName;
            cout << ": ";
            for (int i = line.find(':') + 2; i < line.length(); i++) {
                currentSettingValue += line[i];
            }
            cout << currentSettingValue << endl;
            if (currentSettingName == "language") {
                string language;
                language = currentSettingValue;
            }
            cout << endl;
        }
        readSettingFile.close();
        cout << "Setting file closed." << endl;
    } else {
        readSettingFile.close();
        ofstream createSettingFile("settings.txt");
        cout << "Create and write in the setting file..." << endl;
        createSettingFile << "Resolution: 800x600" << endl;
        createSettingFile << "Text Speed: Normal" << endl;
        createSettingFile << "Frame_Color: #ff0000" << endl;
        createSettingFile << "Language: fr_ca" << endl;
        cout << "Saved." << endl; 

        createSettingFile.close();
        cout << "Setting file closed." << endl;
    }

    return 0;
}