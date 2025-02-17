#pragma once
#include <string>

using namespace System::Runtime::InteropServices;
using namespace System;

void StringToChar(String^ s, std::string& os);
String^ CharToString(char* str);
std::pair<std::string, std::string> GetKeyValue(std::string ptext);