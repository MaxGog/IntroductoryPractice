#include "MyConvector.h"

void StringToChar(String^ s, std::string& os)
{
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}

String^ CharToString(char* str)
{
	IntPtr dptr = Marshal::AllocHGlobal(strlen(str) + 1);
	char* sdes = (char*)dptr.ToPointer();
	for (int i = 0; i < strlen(str); i++)
	{
		sdes[i] = str[i];
	}
	return Marshal::PtrToStringAnsi((IntPtr)str);
}

std::pair<std::string, std::string> GetKeyValue(std::string ptext)
{
	std::pair<std::string, std::string> out;
	out.first = "";
	out.second = "";
	if (ptext.empty()) return out;

	char* skey{}, * svalue{};
	int npos = ptext.find('=');
	if (npos)
	{
		skey = new char[npos + 1] {};
		svalue = new char[ptext.length()] {};
		ptext.copy(skey, npos);
		ptext.copy(svalue, ptext.length() - npos, npos + 1);
		out.first = skey;
		out.second = svalue;
		delete[] skey;
		delete[] svalue;
		return out;
	}
	else
		return out;
}