#include "candidate.h"

#include<fstream>
#include<sstream>
#include<vector>


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

void write(string filename)
{
	fstream fout;

	fout.open(filename, ios::app);

	string username, password, candidate_name, address, qualifications, candidate_id, aadhar;

	cout << "\n\n--------------------------------------\n\n";

	cout << "\nEnter the username (Format= For 'John Doe'; Username= 'jdoe'):: ";
	getline(cin, username);


	cout << "\nEnter the Password (Alpha Numeric of atleast 7 characters):: ";
	getline(cin, password);


	cout << "\nCandidate ID :: ";
	getline(cin, candidate_id);


	cout << "\nEnter Candidate Name:: ";
	getline(cin, candidate_name);


	cout << "\nEnter your Aadhar Card No:: ";
	getline(cin, aadhar);


	cout << "\nEnter your address:: ";
	getline(cin, address);


	cout << "\nEnter Qualification:: ";
	getline(cin, qualifications);

	fout << username << "," << password << "," << candidate_id << "," << candidate_name << "," << aadhar << "," << address << "," << qualifications << "\n";

}

void Create_array_of_objects(vector<candidate>& obj, vector<vector<string>>& Filedata)
{
	candidate tt;

	unsigned int i = 0;
	int j = 0;
	while(i<Filedata.size())
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

int main()
{
	vector<vector <string>> Filedata;

	bool check = Read("candidates.txt", Filedata);

	//Read_Check(check, Filedata);

	//Filedata.clear();

	vector<candidate> obj;

	Create_array_of_objects(obj, Filedata);

	//displaying array of objects
	display_obj(obj);

	return 0;
}