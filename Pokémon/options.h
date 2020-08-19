#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <SDL.h>

using namespace std;

int checkSettingsFile(int language);
int getLanguage(const char *languageCode[], const int languageCount);