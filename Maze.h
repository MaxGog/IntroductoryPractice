#include <Windows.h>
#include "Header.h"

void ResetMaze();
MyAction MazeDraw(System::Drawing::Graphics^ graph);
void MazeKeys(int pkey);
int Moving(char pnRow, char pnCol, System::Drawing::Graphics^ graph, const BOOL pKey);
int StartMoving(System::Drawing::Graphics^ graph);