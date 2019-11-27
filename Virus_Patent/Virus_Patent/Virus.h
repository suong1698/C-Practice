#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>


using namespace std;
class Virus
{
private:
	char* m_dna;
	int m_resistance;
public:
	Virus();
	Virus(const Virus& virus);
	virtual ~Virus();//virtual
	void SetDNA(const char* m_dna);
	char* GetDNA();
	void SetResistance(int m_resistance);
	int GetResistance();
	void LoadADNInformation();
	bool ReduceResistace(int medicine_Resistance);
	virtual void DoBorn() = 0;
	virtual std::list<Virus*> DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;
	
};
//fluvirus

class Flu :
	public Virus
{
private:
	int m_color;
public:
	Flu();
	Flu(const Flu& v);
	~Flu();
	void DoBorn();
	list<Virus*>DoClone();
	void DoDie();
	void InitResistance();
};

//Dengue
class Dengue :
	public Virus
{
protected:
	char* m_protein;
public:
	Dengue();
	~Dengue();
	Dengue(const Dengue& v);
	void SetProtein(const char* protein);
	char* GetProtein();
	void DoBorn();
	list<Virus*> DoClone();
	void DoDie();
	void InitResistance();
	
};

