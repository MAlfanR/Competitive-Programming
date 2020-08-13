#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n";
		}

};

class Student :  public Person{
	private:
		vector<int> testScores;
	public:
        Student(string firstName, string lastName, int id, vector<int> testScores1)
             :Person(firstName,lastName,id){
                 this->testScores = testScores1;
             }



        /*
        *   Class Constructor
        *
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here

        /*
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here

        char calculate(){
            int sum =0;
            for(int i=0 ;i<testScores.size(); i++){
                sum+=testScores[i];
            }
            sum = sum/testScores.size();
            if(sum>=90){
                return 'O';
            }else if(sum>=80){
                return 'E';
            }else if(sum>=70){
                return 'A';
            }else if(sum>=55){
                return 'P';
            }else if(sum>=40){
                return 'D';
            }else{
                return 'T';
            }
        }
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}