#pragma once
#include <string>
#include <Windows.h>

int GetSizeArray();

bool GetOrient();
void SetOrient(bool set);

//İÒÀ ÔÓÍÊÖÈß ÍÓÆÍÀ ÅÙ¨ ÄËß ÂÇßÒÈß ÂÑÅÃÎ ÌÀÑÑÈÂÀ

long long GetTime();

void SetElementSortingArray(std::string dataElement, int id);
std::string GetElementSortingArray(int id);

void SetSortingArray(std::string* newArray[]);
void ResetData();

void SortingSelection();
void SortingBubble();
void SortingQuick();