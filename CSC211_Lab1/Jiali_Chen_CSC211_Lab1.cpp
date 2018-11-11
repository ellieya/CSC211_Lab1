/*
CSC 211 Lab #1
Jiali Chen
A modular-designed program created to calculate and assign students' grade point average and letter grade based on scores read-in from an external file.
*/

#include <iostream>
#include <fstream>

using namespace std;

//Declare struct
struct record {
	int ID;
	int quiz1, quiz2;
	int exam1, exam2;
	double gradeNum;
	char gradeChar;
};

//Declare prototypes
void dataIn(int, ifstream&, record[]);
double gradeCalc(int, int, int, int);
void gradeAssign(int, record[]);
void printData(int, record[]);

int main() {
	ifstream infile;
	record curStudent[5];
	int i = 0;

	//Open the class data .txt file
	infile.open("class1.txt");

	//Check to see if the file has opened properly
	if (infile.fail()) {
		cout << "The file has failed to open!" << endl;
		exit(1);
	}

	//Input data from external file to array
	dataIn(i, infile, curStudent);

	//Calculate numerical grade average, and assign corresponding letter grade
	gradeAssign(i, curStudent);

	//Close class data .txt file
	infile.close();

	//Print all data
	printData(i, curStudent);

}


void dataIn(int i, ifstream& infile, record curStudent[]) {
	while (!infile.eof()) {
		//Input file's data into the structure array
		infile >> curStudent[i].ID
			>> curStudent[i].quiz1
			>> curStudent[i].quiz2
			>> curStudent[i].exam1
			>> curStudent[i].exam2;
		//Increment i in order to store data into the array
		i++;
	}
}

double gradeCalc(int exam1, int exam2, int quiz1, int quiz2) {
	//Calculate numerical average using provided values
	return exam1 * 0.25 + exam2 * 0.5 + ((quiz1 + quiz2) / 20.0 * 100) * 0.25;
}

void gradeAssign(int i, record curStudent[]) {
	for (i = 0; i < 5; i++) {
		//Calculate numerical average using gradeCalc function
		curStudent[i].gradeNum = gradeCalc(curStudent[i].exam1, curStudent[i].exam2, curStudent[i].quiz1, curStudent[i].quiz2);

		//Assign grade letter to student based on numerical average
		if (curStudent[i].gradeNum >= 90) {
			curStudent[i].gradeChar = 'A';
		}
		else if (curStudent[i].gradeNum >= 80) {
			curStudent[i].gradeChar = 'B';
		}
		else if (curStudent[i].gradeNum >= 70) {
			curStudent[i].gradeChar = 'C';
		}
		else if (curStudent[i].gradeNum >= 60) {
			curStudent[i].gradeChar = 'D';
		}
		else {
			curStudent[i].gradeChar = 'F';
		}
	}
}

void printData(int i, record curStudent[]) {
	for (i = 0; i < 5; i++) {
		//Print all student data
		cout << "STUDENT ID - " << curStudent[i].ID
			<< "\nQuiz #1 Score [12.5%]: " << curStudent[i].quiz1
			<< "\nQuiz #2 Score [12.5%]: " << curStudent[i].quiz2
			<< "\nExam #1 Score [25%]: " << curStudent[i].exam1
			<< "\nExam #2 Score [50%]: " << curStudent[i].exam2
			<< "\n\nNUMERIC AVERAGE - " << curStudent[i].gradeNum
			<< "\nLETTER GRADE - " << curStudent[i].gradeChar
			<< "\n\n--\n" << endl;
	}
}

/*
Output:

STUDENT ID - 1
Quiz #1 Score [12.5%]: 9
Quiz #2 Score [12.5%]: 9
Exam #1 Score [25%]: 90
Exam #2 Score [50%]: 90

NUMERIC AVERAGE - 90
LETTER GRADE - A

--

STUDENT ID - 2
Quiz #1 Score [12.5%]: 8
Quiz #2 Score [12.5%]: 8
Exam #1 Score [25%]: 80
Exam #2 Score [50%]: 80

NUMERIC AVERAGE - 80
LETTER GRADE - B

--

STUDENT ID - 3
Quiz #1 Score [12.5%]: 7
Quiz #2 Score [12.5%]: 7
Exam #1 Score [25%]: 70
Exam #2 Score [50%]: 70

NUMERIC AVERAGE - 70
LETTER GRADE - C

--

STUDENT ID - 4
Quiz #1 Score [12.5%]: 6
Quiz #2 Score [12.5%]: 6
Exam #1 Score [25%]: 60
Exam #2 Score [50%]: 60

NUMERIC AVERAGE - 60
LETTER GRADE - D

--

STUDENT ID - 5
Quiz #1 Score [12.5%]: 5
Quiz #2 Score [12.5%]: 5
Exam #1 Score [25%]: 50
Exam #2 Score [50%]: 50

NUMERIC AVERAGE - 50
LETTER GRADE - F

--

Press any key to continue . . .

*/