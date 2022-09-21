#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

typedef struct STUDENT_DATA {
	string firstName;
	string lastName;

	string printStudent() {
		string fullName = lastName + "," + firstName;
		return fullName;
	}
}STUDENTDATA;


//#define PRE_RELEASE;

int main() {

	string tempDataStorage;
	vector<STUDENTDATA>studentList;

	ifstream StudentDataFile("..\\StudentData.txt");

	while (getline(StudentDataFile, tempDataStorage)) {
		int totalStringLength = tempDataStorage.length();
		STUDENTDATA newStudent;

		newStudent.lastName = tempDataStorage.substr(0, tempDataStorage.find(','));
		newStudent.firstName = tempDataStorage.substr(tempDataStorage.find(',') + 1, totalStringLength);

		studentList.push_back(newStudent);
	}
	StudentDataFile.close();

	#ifdef _DEBUG
		cout << "DEBUG - Standard Version" << endl;
		for (int i = 0; i < studentList.size(); i++)
			cout << studentList.at(i).printStudent() << endl;
	#endif

	#ifdef PRE_RELEASE
		cout << "Pre Release Version" << endl;
		ifstream StudentDataFile("..\\StudentData_Emails.txt");
		while (getline(StudentDataFile, tempDataStorage)) 
		{
			cout << tempDataStorage << endl;
		}
	#endif

	
	return 1;
}