#include "Encryption.h"

static const int sizeArr = 128;
char baseArr[sizeArr] = "!Apagando las luces! Пропаганда не работает";
char encArr[128] = {};
int indent = 1;
encmode cModel = c_mode_Caesar;

std::string GetPhrase() { return baseArr; }
std::string GetEncPhrase() { return encArr; }
void SetIndent(int newIndent) { indent = newIndent; }
int GetIndent() { return indent; }

static unsigned char EncChar(UChar pCh, UChar pBc, UChar pEc, UChar pIndEnt) { return pBc + (pCh + pIndEnt - pBc) % (pEc - pBc + 1); }
static unsigned char UnEncChar(UChar pCh, UChar pBc, UChar pEc, UChar pIndEnt) { return (((pCh - pIndEnt) < pBc) ? pEc - (pBc - (pCh - pIndEnt)) + 1 : pCh - pIndEnt); }

void SetPhrase(std::string phrase)
{
	strcpy(baseArr, phrase.c_str());
}

std::string GetEncModel()
{
	if (cModel == c_mode_Caesar)
		return "Цезарь";
	else if (cModel == c_mode_CaesarDynamic)
		return "динамический Цезарь";
	else if (cModel == c_mode_Shift || cModel == c_mode_Shift_Left || cModel == c_mode_Shift_Right)
		return "побитовый сдвиг";
	return "неизвестный метод";
}

void EncryptCaeser()
{
	cModel = c_mode_Caesar;
	strcpy_s(encArr, baseArr);
	for (int i = 0; i < strlen(encArr); i++)
	{
		char ch = encArr[i];
		if (('А' <= ch) && (ch <= 'я')) ch = EncChar(ch, 'А', 'я', indent);
		else if (ch == 'ё') ch = 'Ё';
		else if (ch == 'Ё') ch = 'ё';
		else if ('A' <= ch && ch <= 'z') ch = EncChar(ch, 'A', 'z', indent);
		else if (32 <= ch && ch <= 64) ch = EncChar(ch, 32, 64, indent);
		encArr[i] = ch;
	}
}

void EncryptDynamicCaeser()
{
	cModel = c_mode_CaesarDynamic;
	strcpy_s(encArr, baseArr);
	int indent = 0;
	for (int i = 0; i < strlen(encArr); i++)
	{
		char ch = encArr[i];
		indent = i % 10;
		if (('А' <= ch) && (ch <= 'я')) ch = EncChar(ch, 'А', 'я', indent);
		else if (ch == 'Ё') ch = 'ё';
		else if (ch == 'ё') ch = 'Ё';
		else if ('A' <= ch && ch <= 'z') ch = EncChar(ch, 'A', 'z', indent);
		else if (32 <= ch && ch <= 64) ch = EncChar(ch, 32, 64, indent);
		encArr[i] = ch;
	}
}

void Create_bit_encryption(encmode pmodel, int pnBit = 1)
{
	int n_last = 0;
	UChar cbit, cbit2;

	n_last = strlen(encArr) - 1;

	switch (pmodel)
	{
	case c_mode_Shift_Left:
		cbit = encArr[0] & ((char)0x80 >> (pnBit - 1));
		cbit >>= 8 - pnBit;
		for (int i = 0; i < n_last; i++)
		{
			encArr[i] <<= pnBit;
			cbit2 = encArr[i + 1] & ((char)0x80 >> (pnBit - 1));
			cbit2 >>= 8 - pnBit;
			encArr[i] |= cbit2;
		}
		encArr[n_last] <<= pnBit;
		encArr[n_last] |= cbit;
		break;
	case c_mode_Shift_Right:

		cbit = encArr[n_last] & ((UChar)0xFF >> (8 - pnBit));
		cbit <<= (8 - pnBit);
		for (int i = n_last; i > 0; i--)
		{
			encArr[i] = (UChar)encArr[i] >> pnBit;
			cbit2 = encArr[i - 1] & ((UChar)0xFF >> (8 - pnBit));
			cbit2 <<= 8 - pnBit;
			encArr[i] |= cbit2;
		}
		encArr[0] = ((UChar)encArr[0] >> pnBit) | cbit;
		break;
	}
}

void EncryptBitShift(bool leftMode, int pnindent)
{
	indent = pnindent;
	indent %= 8;
	strcpy_s(encArr, baseArr);
	switch (leftMode)
	{
	case true:
		cModel = c_mode_Shift_Left;
		Create_bit_encryption(cModel, indent);
		break;
	case false:
		cModel = c_mode_Shift_Right;
		Create_bit_encryption(cModel, indent);
		break;
	}
}

void Decoding()
{
	int ind = 0;

	switch (cModel)
	{
	case c_mode_Caesar:
		for (int i = 0; i < strlen(encArr); i++)
		{
			char ch = encArr[i];
			if (('А' <= ch) && (ch <= 'я')) ch = UnEncChar(ch, 'А', 'я', indent);
			else if (ch == 'ё') ch = 'Ё';
			else if (ch == 'Ё') ch = 'ё';
			else if ('A' <= ch && ch <= 'z') ch = UnEncChar(ch, 'A', 'z', indent);
			else if (32 <= ch && ch <= 64) ch = UnEncChar(ch, 32, 64, indent);
			encArr[i] = ch;
		}
		break;
	case c_mode_CaesarDynamic:
		for (int i = 0; i < strlen(encArr); i++)
		{
			char ch = encArr[i];
			ind = i % 10;
			if (('А' <= ch) && (ch <= 'я')) ch = UnEncChar(ch, 'А', 'я', ind);
			else if (ch == 'Ё') ch = 'ё';
			else if (ch == 'ё') ch = 'Ё';
			else if ('A' <= ch && ch <= 'z') ch = UnEncChar(ch, 'A', 'z', ind);
			else if (32 <= ch && ch <= 64) ch = UnEncChar(ch, 32, 64, ind);
			encArr[i] = ch;
		}
		break;
	case c_mode_Shift_Right:
		Create_bit_encryption(c_mode_Shift_Left, indent);
		break;
	case c_mode_Shift_Left:
		Create_bit_encryption(c_mode_Shift_Right, indent);
		break;
	}
}
