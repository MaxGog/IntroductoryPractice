#pragma once

class cMask
{
private:
	int resultMask[20];
	int mcount;
public:
	cMask(): mcount(0) {};

	void CalcMask(int mask);
	int GetCount() { return mcount; }
	__declspec(property(get = GetCount)) int count;

	int GetResultNum(int i) { return resultMask[i]; }

	~cMask()
	{
		//delete[] resultMask;
	}
};

