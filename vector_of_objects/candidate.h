#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>

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
	candidate();
	void candidate_login_validation(vector<candidate>&);
	void modify(vector<candidate>&);

	//registering of a new candidate
	void register_candidate(string, vector<vector<string>>& );

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

	string getusername();
	string getpass();
	string getcid();
	string getcname();
	string getaadhar();
	string getaddress();
	string getqual();


	void display();
	
};

bool Read(string, vector<vector<string>>&);
void display_vector(vector<vector<string>>&);
void Read_Check(bool, vector<vector<string>>&);
void write(string, vector<vector<string>>&);
void Create_array_of_objects(vector<candidate>&, vector<vector<string>>&);
void display_obj(vector<candidate>&);
void write_back_to_file(string,vector<candidate>&);
