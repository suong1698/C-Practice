
#include "Patent.h"
Patent::Patent()
{
	DoStart();
	InitResistance();
}

Patent::Patent(int m_resistance, int m_state, list<Virus*> m_virusList)
{
	this->m_resistance = m_resistance;
	this->m_virusList = m_virusList;
	this->m_state = m_state;
}

Patent::~Patent()
{
	DoDie();

}
int Patent::GetState()
{
	return this->m_state;
}

void Patent::InitResistance()
{

	this->m_resistance = (rand() % 8001 + 1000);
}

void Patent::DoStart()
{
	this->m_state = 1;
	int numVirus = (rand() % 11 + 10);
	for (int i = 0; i < numVirus; i++)
	{
		int tVirus = rand() % 2;
		if (tVirus == 1)
		{
			Virus* dengue = new Dengue();
			this->m_virusList.push_back(dengue);
			dengue = NULL;
			//delete dengue;
		}
		else
		{
			Virus* flu = new Flu();
			this->m_virusList.push_back(flu);
			flu = NULL;
			delete flu;
		}
	}
}

void Patent::TakeMedicine(int medicine_resistance)
{
	cout << "Viruses :" << this->m_virusList.size() << endl;
	list<Virus*>::iterator it;
	for (it= m_virusList.begin(); it != m_virusList.end();)
	{
		if ((*it)->ReduceResistace(medicine_resistance)) 
		{
			
			list<Virus*>::iterator temp=it;
			it++;
			(*temp)->DoDie();
			delete* temp;
			this->m_virusList.remove(*temp);
			
		}
		else
		{
			list<Virus*> newViruses = (*it)->DoClone();
			int t = newViruses.size();
			while (t > 0)
			{
				m_virusList.push_back(newViruses.back());
				newViruses.pop_back();
				t -= 1;
			}
			this->m_resistance -= (*it)->GetResistance();
			it++;
			delete* it;
		}
		if (this->m_resistance <= 0)
		{
			cout << "Die";
			this->DoDie();
			break;
		}
	}
	cout << "Viruses :" << this->m_virusList.size() << endl;
}

void Patent::DoDie()
{
	this->m_state = 0;	
	list <Virus*> ::iterator it;
	for (it = this->m_virusList.begin(); it != this->m_virusList.end();)
	{
		
		delete* it;
		this->m_virusList.remove(*it);
	}
}

