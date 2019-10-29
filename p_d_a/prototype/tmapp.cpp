#include <iostream>
#include <stdlib.h>

using namespace std;

enum Commands { DELE, EXIT, HELP, INSE, LIST, RUN, SET, SHOW, TRUN, VIEW, QUIT, INVALID };
Commands work = INVALID;
enum State { NOT_RUN, BUSY, COMPLETE};
State tmState = NOT_RUN;

void checkValid(char exp);
void deleteHelper();
void exitHelper();
void helpHelper();
void insertHelper();
void listHelper();
void runHelper();
void setHelper();
void showHelper();
void truncateHelper();
void viewHelper();
void quitHelper();


int main(int argc, char* argv[])
{
	char input;
	if (argc < 1)
		cout << argv[1] << " successfully loaded" << endl;
	else
		cout << "TM successfully loaded" << endl;
	while (work != EXIT)
	{
		cout << "Command: ";
		cin >> input;
		checkValid(input);
		switch (work)
		{
		case DELE:
			cout << endl;
			deleteHelper();
			break;
		case EXIT:
			cout << endl;
			exitHelper();
			break;
		case HELP:
			cout << endl;
			helpHelper();
			break;
		case INSE:
			cout << endl;
			insertHelper();
			break;
		case LIST:
			cout << endl;
			listHelper();
			break;
		case RUN:
			cout << endl;
			runHelper();
			break;
		case SET:
			cout << endl;
			setHelper();
			break;
		case SHOW:
			cout << endl;
			showHelper();
			break;
		case TRUN:
			cout << endl;
			truncateHelper();
			break;
		case VIEW:
			cout << endl;
			viewHelper();
			break;
		case QUIT:
			cout << endl;
			quitHelper();
			break;
		case INVALID: //add blank lines
			cout << input << " is not a valid command try (h) to see list of valid commands" << endl;
			break;
		default:
			cout << "Error";
			break;
		}
	}
	return 0;
}

void checkValid(char exp)
{
	tolower(exp);
	if (exp == 'd')
		work = DELE;
	else if (exp == 'x')
		work = EXIT;
	else if (exp == 'h')
		work = HELP;
	else if (exp == 'i')
		work = INSE;
	else if (exp == 'l')
		work = LIST;
	else if (exp == 'r')
		work = RUN;
	else if (exp == 'e')
		work = SET;
	else if (exp == 'w')
		work = SHOW;
	else if (exp == 't')
		work = TRUN;
	else if (exp == 'v')
		work = VIEW;
	else if (exp == 'q')
		work = QUIT;
	else
		work = INVALID;
}

void deleteHelper()  //indeicate string number
{
	cout << "indicate which string to delete: 2" << endl;
	cout << "string 2: ab was deleted" << endl << endl;
}

void exitHelper()  //add which file was written to
{
	cout << "new list written to file" << endl;
}

void helpHelper()
{
	cout << "(d)elete	deletes input string from list" << endl;
	cout << "e(x)it		exit application" << endl;
	cout << "(h)elp		help user" << endl;
	cout << "(i)nsert	insert new input string into list" << endl;
	cout << "(l)ist		list input strings" << endl;
	cout << "(r)un		run turing machine on input string" << endl;
	cout << "s(e)t		set maximum number of transitions to preform" << endl;
	cout << "sho(w)		show status of application" << endl;
	cout << "(t)runcate	truncate instantaneous descricptions" << endl;
	cout << "(v)iew		view turing machine" << endl;
	cout << "(q)uit		quit operation of the turing machine on input string" << endl << endl;
}

void insertHelper()
{
	cout << "enter new string: aaabbb" << endl;
	cout << "string added 11 : aaabbb" << endl << endl;
}

void listHelper() //. instead :
{
	cout << " 1: a" << endl;
	cout << " 2: ab" << endl;
	cout << " 3: \\" << endl;
	cout << " 4: aaabb" << endl;
	cout << " 5: aaaaaaaaaabbbbbbbbbb" << endl;
	cout << " 6: aabb" << endl;
	cout << " 7: aaaaaabbbbbbb" << endl;
	cout << " 8: ba" << endl;
	cout << " 9: aba" << endl;
	cout << "10: bb" << endl << endl;
}

void runHelper()  //change : to .
{
	switch (tmState)
	{
		case NOT_RUN:
			cout << "please enter an input string number: 1" << endl << endl;
			cout << "0: [s0]ab" << endl;
			cout << "1:  X[s1]b" << endl;
			tmState = BUSY;
			break;
		case BUSY:
			cout << "2: X[s2]Y" << endl; //show last instantaneous description
			cout << "5: YX-[s4]" << endl;
			cout << "accepted" << endl; // add number of transitions and string number
			tmState = COMPLETE;
			break;
		case COMPLETE:
			cout << "please enter an input string number: 1" << endl << endl;
			cout << "0: [s0]ab" << endl;
			cout << "1:  X[s1]b" << endl;
			tmState = NOT_RUN;
			break;
	}
	cout << endl;
}

void setHelper() //remove brackets
{
	cout << "set maximum number of transitions [1] : 10" << endl;
	cout << "maximum set to [10]" << endl << endl;
}

void showHelper() //add blank line isolate information add operations of BUSY RUNNING and 
{
	cout << "CPTS350, SEM: 2, YEAR: 2019, INST: NEIL CORRIGAN, AUTH: TREVOR SURFACE" << endl;
	cout << "V. PROTOTYPE" << endl;
	cout << "Maximum transitions set [1]" << endl;
	cout << "truncate value set [32]" << endl << endl;
	cout << "TM::tm" << endl;
	switch (tmState)
	{
		case NOT_RUN:
			cout << "not operating" << endl;
			break;
		case BUSY:
			cout << "input string: ab" << endl;
			cout << "transitions: 1" << endl;
			break;
		case COMPLETE:
			cout << "input string: ab" << endl;
			cout << "transitions: 5" << endl;
			cout << "string was accepted" << endl;
			break;
	}
	cout << endl;
}

void truncateHelper()  //change to truncation value message
{
	cout << "maximum instantaneous description [32]: 64" << endl;
	cout << "maximum instantaneous description set to [64]" << endl << endl;
}

void viewHelper() //fix unicode 
{
	cout << "This Turing machine accepts the language of one or more a's followed by the" << endl;
	cout << "same number of b's" << endl << endl;
	cout << "Q: {s0, s1, s2, s3, s4}" << endl << endl;
	cout << "\u03A3: {a, b}" << endl << endl;
	cout << "\u0393: {a, b, X, Y, -}" << endl << endl;
	cout << "transition functions:" << endl; //remove this line
	cout << "\u03B4(s0, a) = (s1, X, R)" << endl;
	cout << "\u03B4(s0, Y) = (s3, Y, R)" << endl;
	cout << "\u03B4(s1, a) = (s1, a, R)" << endl;
	cout << "\u03B4(s1, b) = (s2, Y, L)" << endl;
	cout << "\u03B4(s1, Y) = (s1, Y, R)" << endl;
	cout << "\u03B4(s2, a) = (s2, a, L)" << endl;
	cout << "\u03B4(s2, X) = (s0, X, R)" << endl;
	cout << "\u03B4(s2, Y) = (s2, Y, L)" << endl;
	cout << "\u03B4(s3, Y) = (s3, Y, R)" << endl;
	cout << "\u03B4(s3, -) = (s4, -, R)" << endl;
	cout << endl;
	cout << "q0: s0" << endl << endl; //remove {}
	cout << "B: -" << endl << endl; //remove {}
	cout << "F: {s4}" << endl << endl;
}

void quitHelper()
{
	switch (tmState)
	{
	case NOT_RUN:
		cout << "tm is not running" << endl;
		break;
	case BUSY:
		cout << "string: ab has not been accepted or rejected" << endl;
		cout << "in 2 transitions" << endl;
		break;
	case COMPLETE:
		cout << "tm is not running" << endl;
		break;
	}
	cout << endl;
}
