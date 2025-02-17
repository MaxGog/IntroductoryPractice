#pragma once
#include <string>

#include "Header.h"

void Create_bit_encryption(encmode pmodel, int pnBit);
void SetPhrase(std::string phrase);
std::string GetPhrase();
std::string GetEncPhrase();
void SetIndent(int newIndent);
int GetIndent();
std::string GetEncModel();

void EncryptCaeser();
void EncryptDynamicCaeser();
void EncryptBitShift(bool leftMode, int pnindent);
void Decoding();