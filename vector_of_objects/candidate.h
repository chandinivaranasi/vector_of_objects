#pragma once
#include<iostream>
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
};

