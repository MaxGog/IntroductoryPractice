#include "Sorting.h"

using namespace std;

const int sizeArray = 20;

string baseArray[20]{ "Пропаганда", "Человек", "Фон", "Планшет", "Арт", "Рисовать", "Творчесво",
	"Музыка", "Работа", "Код", "Доккер", "Винда", "Слово", "Ручка", "Микрофон",
	"Стилус", "Кровать", "Энергетик", "Кола", "Студия" };

bool orient = false;

LARGE_INTEGER time_s{}, time_f{};

string sortingArray[20]{ "Пропаганда", "Человек", "Фон", "Планшет", "Арт", "Рисовать", "Творчесво",
	"Музыка", "Работа", "Код", "Доккер", "Винда", "Слово", "Ручка", "Микрофон",
	"Стилус", "Кровать", "Энергетик", "Кола", "Студия" };

int GetSizeArray() { return sizeArray; }
bool GetOrient() { return orient; }
void SetOrient(bool set) { orient = set; }
long long GetTime() { return time_f.QuadPart - time_s.QuadPart; }
void SetElementSortingArray(std::string dataElement, int id) { sortingArray[id] = dataElement; }
string GetElementSortingArray(int id) { return sortingArray[id]; }

void SetSortingArray(std::string* newArray[])
{
	for (int i = 0; i < sizeArray; i++)
	{
		sortingArray[i] = *newArray[i];
	}
}

void ResetData()
{
	for (int i = 0; i < sizeArray; i++)
	{
		sortingArray[i] = baseArray[i];
	}
}

void SortingSelection()
{
	QueryPerformanceCounter(&time_s);
	for (int i = 0; i < sizeArray - 1; i++)
	{
		for (int j = i; j < sizeArray; j++)
		{
			if ((sortingArray[i] > sortingArray[j]) ^ orient)
			{
				std::string temp = sortingArray[i];
				sortingArray[i] = sortingArray[j];
				sortingArray[j] = temp;
			}
		}
	}
	QueryPerformanceCounter(&time_f);
}

void SortingBubble()
{
	QueryPerformanceCounter(&time_s);

	bool przn = false;
	do {
		przn = false;
		for (int i = 0; i < sizeArray - 1; i++)
			if ((sortingArray[i] > sortingArray[i + 1]) ^ orient) {
				sortingArray[i].swap(sortingArray[i + 1]);
				przn = true;
			}
	} while (przn);

	QueryPerformanceCounter(&time_f);
}

void QuickS(std::string* sarr, int n_first, int n_last, int reverse)
{
	std::string smid = sarr[(n_first + n_last) / 2];
	int i = n_first, j = n_last;
	int nreverse = 0;
	if (reverse == false)
		nreverse = -1;
	else
		nreverse = 1;
	do {
		while (sarr[i].compare(smid) * nreverse > 0) i++;
		while (sarr[j].compare(smid) * nreverse < 0) j--;
		if (i < j) sarr[i].swap(sarr[j]);
		if (i <= j) i++;
		if (i <= j) j--;
	} while (i <= j);
	if (n_first < j) QuickS(sarr, n_first, j, reverse);
	if (i < n_last) QuickS(sarr, i, n_last, reverse);
}

void SortingQuick()
{
	QueryPerformanceCounter(&time_s);

	QuickS(sortingArray, 0, sizeArray - 1, orient);

	QueryPerformanceCounter(&time_f);
}
