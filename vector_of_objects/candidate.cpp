#include "candidate.h"

candidate::candidate()
{
	username="n/a";
	password = "n/a";
	id = "n/a";
	name = "n/a";
	aadhar_no = "n/a";
	address = "n/a";
	qualifications = "n/a";
}

void candidate::candidate_login_validation(vector<candidate>& obj)
{
	string username, password;
	int i = 0;

	cout << "\nEnter the username :: ";
	getline(cin, username);
	getline(cin, username);

	cout << "\nEnter the Password :: ";
	getline(cin, password);

	int flag = 0;
	for (unsigned int i = 0; i < obj.size(); i++)
	{
		if (obj[i].getusername() == username && obj[i].getpass() == password)
		{
			flag = 1;
			break;
		}
		else
			flag = 0;
	}
	if (flag == 1)
		cout << "\n\nLOGGED IN !!!!!!!\n\n";
	else
		cout << "\n\nWRONG USERNAME/PASSWORD\n\n";
}

void candidate::modify(vector<candidate>& obj)
{

}

void candidate::register_candidate(string filename, vector<vector<string>>& Filedata)
{
	vector<string> vec;

	fstream fout;

	fout.open(filename, ios::app);

	string username, password, candidate_name, address, qualifications, candidate_id, aadhar;

	cout << "\n\n--------------------------------------\n\n";

	cout << "\nEnter the username (Format= For 'John Doe'; Username= 'jdoe'):: ";
	getline(cin, username);
	vec.push_back(username);

	cout << "\nEnter the Password (Alpha Numeric of atleast 7 characters):: ";
	getline(cin, password);
	vec.push_back(password);

	cout << "\nCandidate ID :: ";
	getline(cin, candidate_id);
	vec.push_back(candidate_id);

	cout << "\nEnter Candidate Name:: ";
	getline(cin, candidate_name);
	vec.push_back(candidate_name);

	cout << "\nEnter your Aadhar Card No:: ";
	getline(cin, aadhar);
	vec.push_back(aadhar);

	cout << "\nEnter your address:: ";
	getline(cin, address);
	vec.push_back(address);

	cout << "\nEnter Qualification:: ";
	getline(cin, qualifications);
	vec.push_back(qualifications);

	fout << username << "," << password << "," << candidate_id << "," << candidate_name << "," << aadhar << "," << address << "," << qualifications << "\n";
	Filedata.push_back(vec);

	//call the create_array_of objects after this function returns
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

string candidate::getusername()
{
	return username;
}
string candidate::getpass()
{
	return password;
}
string candidate::getcid()
{
	return id;
}
string candidate::getcname()
{
	return name;
}
string candidate::getaadhar()
{
	return aadhar_no;
}
string candidate::getaddress()
{
	return address;
}
string candidate::getqual()
{
	return qualifications;
}

void candidate::display()
{
	cout << endl << "\t" << username << "\t" << password << "\t" << id << "\t" << name << "\t" << aadhar_no << "\t" << address << "\t" << qualifications;
}


bool Read(string filename, vector<vector<string>>& Filedata)
{
	vector<string> vec;

	fstream file;

	file.open(filename, ios::in);

	if (!file)
	{
		return 0;
	}

	string line;

	while (!file.eof())
	{
		getline(file, line);
		stringstream   linestream(line);
		string         value;

		while (getline(linestream, value, ','))
		{
			vec.push_back(value);
		}
		Filedata.push_back(vec);
		vec.clear();
	}
	file.close();

	return 1;
}

void display_vector(vector<vector<string>>& Filedata)
{
	for (unsigned int i = 0; i < Filedata.size(); i++)
	{
		for (unsigned int j = 0; j < Filedata[i].size(); j++)
		{
			cout << Filedata[i][j] << " ";
		}
		cout << endl;
	}
}

void Read_Check(bool c, vector<vector<string>>& Filedata)
{
	if (1 == c)
	{
		display_vector(Filedata);
	}
	else
	{
		cout << "\nFile not read";
	}
}

void write(string filename, vector<vector<string>>& Filedata)
{
	vector<string> vec;

	fstream fout;

	fout.open(filename, ios::app);

	string username, password, candidate_name, address, qualifications, candidate_id, aadhar;

	cout << "\n\n--------------------------------------\n\n";

	cout << "\nEnter the username (Format= For 'John Doe'; Username= 'jdoe'):: ";
	getline(cin, username);
	vec.push_back(username);

	cout << "\nEnter the Password (Alpha Numeric of atleast 7 characters):: ";
	getline(cin, password);
	vec.push_back(password);

	cout << "\nCandidate ID :: ";
	getline(cin, candidate_id);
	vec.push_back(candidate_id);

	cout << "\nEnter Candidate Name:: ";
	getline(cin, candidate_name);
	vec.push_back(candidate_name);

	cout << "\nEnter your Aadhar Card No:: ";
	getline(cin, aadhar);
	vec.push_back(aadhar);

	cout << "\nEnter your address:: ";
	getline(cin, address);
	vec.push_back(address);

	cout << "\nEnter Qualification:: ";
	getline(cin, qualifications);
	vec.push_back(qualifications);

	fout << username << "," << password << "," << candidate_id << "," << candidate_name << "," << aadhar << "," << address << "," << qualifications << "\n";
	Filedata.push_back(vec);

	fout.close();
	//call the create_array_of objects after this function returns
}

void Create_array_of_objects(vector<candidate>& obj, vector<vector<string>>& Filedata)
{
	candidate tt;

	unsigned int i = 0;
	int j = 0;

	//***************************
		fstream file;

		int n = 0;

		file.open("candidates.txt", ios::in);
		string line;

		while (!file.eof())
		{
			getline(file, line);
			n++;
		}

		file.seekg(0, ios::beg);

		file.close();

	//********************************

	Filedata.resize(n);

	while (i < Filedata.size())
	{

		tt.setusername(Filedata[j][0]);

		tt.setpass(Filedata[j][1]);

		tt.setcid(Filedata[j][2]);

		tt.setcname(Filedata[j][3]);

		tt.setaadhar(Filedata[j][4]);

		tt.setaddress(Filedata[j][5]);

		tt.setqual(Filedata[j][6]);

		obj.push_back(tt);
		j++;
		i++;
	}

}

void display_obj(vector<candidate>& obj)
{
	for (unsigned int i = 0; i < obj.size(); i++)
	{
		obj[i].display();
	}
}

void write_back_to_file(string filename,vector<candidate>& obj)
{
	fstream fout;

	fout.open(filename, ios::out);

	for (unsigned int i = 0; i < obj.size(); i++)
	{
		fout << obj[i].getusername() << "," << obj[i].getpass() << "," << obj[i].getcid() << "," << obj[i].getcname() << "," << obj[i].getaadhar() << "," << obj[i].getaddress() << "," << obj[i].getqual() << "\n";
	}
	fout.close();
}