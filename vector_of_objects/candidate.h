#pragma once
#include<iostream>
#include<vector>
using namespace std;

//used for logging in of candidate and registering of the candidate
//candidates.txt

class candidate
{
	string username;
	string password;
	string id;
	string name;
	string aadhar_no;
	string address;
	string qualifications;

public:
	void candidate_login_validation();
	void modify();

	//registering of a new candidate
	void register_candidate();

	//in admin's power only
	//Only candidate for whom interview is not scheduled can be deleted.
	void delete_candidate();

	void setusername(string);
	void setpass(string);
	void setcid(string);
	void setcname(string);
	void setaadhar(string);
	void setaddress(string);
	void setqual(string);

	void display();
	
};

