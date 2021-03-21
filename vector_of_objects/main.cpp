#include "candidate.h"

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

    cout << "\n\t\t1.modify candidate";
    cout << "\n\t\t2.Login Candidate";
    cout << "\n\t\t3.Register ";

    candidate n;

    int choice = 1;
    cout << "\n\tEnter the Choices:: ";
    cin >> choice;

    switch (choice)
    {
    case 1: 
    {
        n.modify(obj);
        write_back_to_file("candidates.txt", obj);
        Filedata.clear();
        bool check = Read("candidates.txt", Filedata);
        //Read_Check(check, Filedata);
        obj.clear();
        Create_array_of_objects(obj, Filedata);
        display_obj(obj);
        break; 
    }
    case 2:n.candidate_login_validation(obj);
        break;
    case 3:
        n.register_candidate("candidates.txt",Filedata);
        Create_array_of_objects(obj, Filedata);
        break;
    default:cout << "\n\n----------WRONG INPUT-------------\n\n";
        break;
    }

	return 0;
}