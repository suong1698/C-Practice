
#include <ctime>
#include "Virus.h"
#include "Patent.h"
#include"vld.h"
using namespace std;
int main()
{
	srand((int)time(0));
	Patent p;
	char medicine = 0;
	if (p.GetState() == 1)
	{
		cout << "Take Medicine (0 = NO, 1 = YES)";
		cin >> medicine;
		if (medicine == '1')
		{
			int min = 1;
			int max = 60;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			p.TakeMedicine(medicine_resistance);
			
		}
	}
	return 0;
}
