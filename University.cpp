#include "University.h"
#include<iostream>
using namespace std;


string University::getName() const
{
	return name;
}
string University::getLocation() const
{
	return location;
}
double University:: getAR() const
{
	return ar;
}
double University:: getER() const
{
	return er;
}
double University:: getFSR() const
{
	return fsr;
}
double University:: getCPF() const
{
	return cpf;
}
double University:: getIFR() const
{
	return ifr;
}
double University:: getISR() const
{
	return isr;
}
double University:: getIRN() const
{
	return irn;
}
double University:: getGER() const
{
	return ger;
}
void University::setName(string name)
{
	this->name = name;
}
void University::setLocation(string location)
{
	this->location = location;
}
void University::setAR(double ar)
{
	this->ar = ar;
}
void University::setER(double er)
{
	this->er = er;
}
void University::setFSR(double fsr)
{
	this->fsr = fsr;
}
void University::setCPF(double cpf)
{
	this->cpf = cpf;
}
void University::setIFR(double ifr)
{
	this->ifr = ifr;
}
void University::setISR(double isr)
{
	this->isr = isr;
}
void University::setIRN(double irn)
{
	this->irn = irn;
}
void University::setGER(double ger)
{
	this->ger = ger;
}
bool University:: operator < (const University& other) const
{
	return this->name < other.name;
}
bool University:: operator > (const University& other) const
{
	if (this->ar == other.ar)
	{
		if (this->fsr == other.fsr)
			return this->er > other.er;
		return this->fsr > other.fsr;
	}
	return this->ar > other.ar;
}
University::University()
{

}
University::University(string name, string location, double ar, double er, double fsr, double cpf, double ifr, double isr, double irn, double ger)
{
	this->name = name;
	this->location = location;
	this->ar = ar;
	this->er = er;
	this->fsr =fsr;
	this->cpf = cpf;
	this->ifr = ifr;
	this->isr = isr;
	this->irn = irn;
	this->ger = ger;
}
void University:: display()
{
	cout << "\n----------------------University Indormation-------------------------\n";
	cout << "Name: " << name << '\n';
	cout << "Location: " << location << '\n';
	cout << "Acedemic reputation: " << ar << '\n';
	cout << "Employer reputation: " << er << '\n';
	cout << "Faculty by Student ratio: " << fsr << '\n';
	cout << "Citations per faculty: " << cpf << '\n';
	cout << "International faculty ratio: " << ifr << '\n';
	cout << "International student ratio: " << isr << '\n';
	cout << "International research network: " << irn << '\n';
	cout << "Employment outcome: " << ger << '\n';
	cout << "----------------------------------------------------\n";
}