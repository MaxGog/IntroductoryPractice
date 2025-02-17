#include "Mask.h"
#include <stdlib.h>

void cMask::CalcMask(int mask)
{
	int nNumber;
	for (int i = 0; i < 20; i++)
	{
		nNumber = rand();
		if ((nNumber & mask) == mask)
		{
			resultMask[mcount] = nNumber;
			mcount++;
		}
	}
}