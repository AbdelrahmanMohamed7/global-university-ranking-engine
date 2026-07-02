#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include<string>
using std::string;

class University
{
	string name;
	string location;
	double ar;
	double er;
	double fsr;
	double cpf;
	double ifr;
	double isr;
	double irn;
	double ger;
public:
	University();
	University(string name, string location, double ar, double er, double fsr, double cpf, double ifr, double isr, double irn, double ger);
	
	string getName() const;
	string getLocation() const;
	double getAR() const;
	double getER() const;
	double getFSR() const;
	double getCPF() const;
	double getIFR() const;
	double getISR() const;
	double getIRN() const;
	double getGER() const;

	void setName(string name);
	void setLocation(string location);
	void setAR(double ar);
	void setER(double er);
	void setFSR(double fsr);
	void setCPF(double cpf);
	void setIFR(double ifr);
	void setISR(double isr);
	void setIRN(double irn);
	void setGER(double ger);

	/*we want to sort universities data based on name in 1.2, So I am going to overload less than operator which
	helps me in sorting universities data by name*/
	bool operator < (const University& other) const;
	/*we want to sort universities data based on reputaion score, fuculty/student ratio and employer reputation score
	in 2.2, So I am going to overload greater than operator which
	helps me in sorting universities data by reputaion score, fuculty/student ratio and employer reputation score*/
	bool operator > (const University& other) const;
	void display();
};
#endif // !UNIVERSITY_H


