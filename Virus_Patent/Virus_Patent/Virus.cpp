#include "Virus.h"
using namespace std;

Virus::Virus(const Virus& virus)
{
	this->SetDNA(virus.m_dna);
	this->m_resistance = virus.m_resistance;
}
Virus::Virus()
{
	this->m_dna = new char[100]{ "" };
	this->m_resistance = 10;
}

Virus::~Virus()
{
	delete[] this->m_dna;

}
void Virus::SetDNA(const char* m_dna)
{

	this->m_dna = new char[100];
	int i = 0;
	while (m_dna[i] != NULL) {
		this->m_dna[i] = m_dna[i];
		
	}
}

char* Virus::GetDNA()
{
	return this->m_dna;
}

void Virus::SetResistance(int m_resistance)
{
	this->m_resistance = m_resistance;
}

int Virus::GetResistance()
{
	return this->m_resistance;
}

void Virus::LoadADNInformation()
{
	fstream f;
	f.open("ATGX.bin");
	string nu;
	getline(f, nu);
	for (int i = 0; i < nu.length() + 1; i++)
	{
		this->m_dna[i] = nu[i];
	}
}

bool Virus::ReduceResistace(int medicine_Resistance)
{
	return (this->m_resistance - medicine_Resistance) <= 0;
}


//fluvirus
Flu::Flu()
{
	DoBorn();
	InitResistance();
}

Flu::Flu(const Flu& v) : Virus(v)
{
	this->m_color = v.m_color;
}

void Flu::DoBorn()
{
	this->LoadADNInformation();
	int color[2] = { 0x0000ff, 0xff0000 };
	this->m_color = color[rand() % 2];
}

list<Virus*> Flu::DoClone()
{
	list<Virus*> listVirus;
	Flu *fl = new Flu(*this);
	listVirus.push_back(fl);
	/*fl=NULL;
	delete fl;*/
	return listVirus;
}

void Flu::DoDie()
{
	this->m_color = NULL;
	this->SetResistance(NULL);
}

void Flu::InitResistance()
{
	if (this->m_color == 0x0000ff)
	{
		this->SetResistance( rand() % 6 + 10);
	}
	else
	{
		this->SetResistance( rand() % 11 + 10);
	}
}

Flu::~Flu()
{
	this->DoDie();
	
}
//dueguevirus
Dengue::Dengue()
{
	DoBorn();
	InitResistance();
}

Dengue::~Dengue()
{
	DoDie();
	delete[] m_protein;
}

Dengue::Dengue(const Dengue& vdengue) :Virus(vdengue)
{
	this->SetProtein(vdengue.m_protein);
}

void Dengue::SetProtein(const char* protein)
{
	this->m_protein = new char[100];
	int i = 0;
	while (protein[i] != NULL) {
		this->m_protein[i] = protein[i];
		i++;
	}
}

char* Dengue::GetProtein()
{
	return this->m_protein;
}

void Dengue::DoBorn()
{
	this->LoadADNInformation();
	//this->m_protein = new char[4];
	int pr = rand() % 2 + 1;
	if (pr == 0) {
		SetProtein("NS3");
		//this->m_protein[0] ='N';
		//this->m_protein[1] = 'S';
		//this->m_protein[2] = '3';

	}
	else if (pr == 1) {
		SetProtein("NS5");
		//this->m_protein[0] = 'N';
		/*this->m_protein[1] = 'S';
		this->m_protein[2] = '5';*/
	}
	else
	{
		SetProtein("VTE");
		/*this->m_protein[0] = 'V';
		this->m_protein[1] = 'T';
		this->m_protein[2] = 'E';*/
	}

}

list<Virus*> Dengue::DoClone()
{
	list<Virus*> listVirus;
	Dengue *den = new Dengue(*this);
	listVirus.push_back(den);
	den = NULL;
	delete den;
	den = new Dengue(*this);
	listVirus.push_back(den);
	den = NULL;
	delete den;
	return listVirus;
}

void Dengue::DoDie()
{
	this->SetResistance(NULL);
	//delete[] m_protein;
}

void Dengue::InitResistance()
{
	if (this->m_protein[2]=='3')
	{
		this->SetResistance(rand() % 10 + 1);
	}
	else if (this->m_protein[2] == '5')
	{
		this->SetResistance(rand() % 21 + 10);
	}
	else
	{
		this->SetResistance(rand() % 31 + 20);
	}
}
