#include "candidate.h"

void candidate::candidate_login_validation()
{
}

void candidate::modify()
{
}

void candidate::register_candidate()
{
}

void candidate::delete_candidate()
{
}

void candidate::setusername(string un)
{
	this->username = un;
}
void candidate::setpass(string pass)
{
	this->password = pass;
}
void candidate::setcid(string cid)
{
	this->id = cid;
}
void candidate::setcname(string cname)
{
	this->name = cname;
}
void candidate::setaadhar(string aa)
{
	this->aadhar_no = aa;
}
void candidate::setaddress(string add)
{
	this->address = add;
}
void candidate::setqual(string q)
{
	this->qualifications = q;
}

void candidate::display()
{
	cout << endl << "\t" << username << "\t" << password << "\t" << id << "\t" << name << "\t" << aadhar_no << "\t" << address << "\t" << qualifications;
}

