#include <iostream>
using namespace std;
class school{
	int numberofstudents;
	string name;
public :
	school (string name = "",int numberofstudents = 0){
		this -> name = name;
		this -> numberofstudents = numberofstudents;
		}
	virtual  avergscore(int allscore) = 0;
}; 
class mathclass: public school {
	int numberofstudents;
public:
	mathclass (int numberofstudents = 0){
		this -> numberofstudents = numberofstudents;
	}	
	virtual avergscore(int allscore){
		int averg;
		averg = allscore / numberofstudents;
		return averg;
	}
};
class biologyclass: public school {
	int numberofstudents;
public:
	biologyclass (int numberofstudents = 0){
		this -> numberofstudents = numberofstudents;
	}	
	virtual avergscore(int allscore){
		int averg;
		averg = allscore / numberofstudents;
		return averg;
	}
	int input(void){
		cout << "Enter all student score in biology class : "<< endl ;
		int allscore = 0;
		int score;
		for( int i = 0 ; i < numberofstudents ; i++){
			cout << "student number " << i+1 << ":" <<endl ; 
			cin >> score ;
			allscore += score;
		}
		return allscore;
	} 
};
class student : public biologyclass , public  mathclass {
	string name ;
	int studentnumber;
public :
	student (string name = "",int studentnumber = 0){
		this -> name = name;
		this -> studentnumber = studentnumber;
		}
	virtual avergscore (int score){
		int averg;
		averg = score / 2 ;
		return averg;
	}
	int inputscore (void) {
		int score1,score2; 
		cout << "Enter stduent score in math : " << endl ;
	    cin >> score1;
	    cout << "Enter stduent score in biology : " << endl ;
	    cin >> score2;
	    return score1+score2;
	}  
};
int main(int argc, char **argv)
{ 
	biologyclass biology(4);
	student s1("ali",98211);
	int biologyallscore = biology.input();
	cout << "averg score of students in biology is : " << biology.avergscore(biologyallscore) << endl ;
	school * school1 = &biology;
	cout << school1 -> avergscore(biologyallscore) <<endl;
	int studentscore = s1.inputscore();
	cout << "averg score of student is : " << s1.avergscore(studentscore) << endl ;
	mathclass* math = &s1;
	cout << math -> avergscore(studentscore) << endl ;  
	return 0;
}

