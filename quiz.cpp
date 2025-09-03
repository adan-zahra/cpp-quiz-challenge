//Quiz
#include<iostream>
#include<string>
#include<fstream>
#include<limits>
using namespace std;

//structure to hold quiz question, options, and their correct answer
struct question {
    string que; //question text
    string opt[3]; //array to hold three options
    int ans; //index of the correct answer from opt (1-3)
}; 

//function to enter user name
void enterName(string &name) {
    cout << "                Enter your Name. max (15 characters): ";
    getline(cin,name); // Read the entire line for the name
    
    while(name.length()>25){
    	cout<<"         Name too long.Please enter a valid name. max (25 characters):";
    	getline(cin,name);
	}
}

void enterId(string &id){
	    cout<< "               Enter your Reg-Id. max (8 characters): ";
	    getline(cin,id);
		
	while(id.length()>8){
		cout<<"       Reg-Id too long.Please enter a valid id. max (8 characters):";
		getline(cin,id);
	}
}

//function to initialize all quiz questions
void initializeQuestions(question quiz[10]) {
    //struct=each question is initialized with the question text, options, and the correct answer index
    quiz[0] = {"\ni)-Who is the developer of C++?", {"1. Bjarne Stroustrup", "2. Guido van Rossum", "3. Dennis Ritchie"}, 1};
    quiz[1] = {"\nii)-An instance of class is called____?", {"1. Object", "2. Method", "3. Variable"}, 1};
    quiz[2] = {"\niii)-Which of the following cannot be declared as virtual in C++?", {"1. Member function", "2. Constructor", "3. Destructor"}, 2};
    quiz[3] = {"\niv)-Select an Input Device?", {"1. Keyboard", "2. Monitor", "3. Headphone"}, 1};
    quiz[4] = {"\nv)-Integers reserves _____ bytes in memory:", {"1. 2", "2. 4", "3. 8"}, 2};
    quiz[5] = {"\nvi)-An identifier cannot consist more than _____ characters?", {"1. 34", "2. 32", "3. 31"}, 3};
    quiz[6] = {"\nvii)-_____ error is detected by compiler:", {"1. Runtime", "2. Logical", "3. Syntax"}, 3};
    quiz[7] = {"\nviii)-Evaluate!(1&&!(0||1))?", {"1. True", "2. False", "3. Unevaluatable"}, 1};
    quiz[8] = {"\nix)-Which of the following is not a correct variable type?", {"1. int", "2. real", "3. float"}, 2};
    quiz[9] = {"\nx)-A short cut key for center is__?", {"1. Ctrl+C", "2. Ctrl+M", "3. Ctrl+E"}, 3};
}

void saveScoreToFile(const string& name, const string& id, int score) {
    ofstream outFile("quiz_scores.txt", ios::app); //open file in append mode
    if(outFile.is_open()) {//if file is open then
        outFile<< "Name: " << name << ", Reg-Id: " << id << ", Score: " << score <<endl;
        outFile.close(); //close the file
    } else {
        cout<<"Unable to open file to save score."<<endl;
    }
}
//main function
int main() {    
    string name;//var to store user name
    string id;
    cout<<"                    ***********************************           "<<endl;
    cout<<"                       Welcome to the Quiz Challenge!             "<<endl;
    cout<<"                       ******************************             "<<endl;
    enterName(name);  
    enterId(id);
    cout<<"                     --------------------------------            "<<endl;
    
    question quiz[10]; //an array to hold 10 quiz questions
    initializeQuestions(quiz); 
    
    int score = 0; //variable to track the user score
    int userans; //variable to store answer given by a user
    for (int i = 0; i < 10; i++) { //loop
        cout << quiz[i].que << endl; //display question
        for (int j = 0; j < 3; j++) { //loop through options
            cout << quiz[i].opt[j] << endl; //display every option
        }
        cout<<" Choose the correct numbering of your answer (1-3): ";
        //using try,catch,throw
        while (true) { //loop until valid input
            try {
                cin >> userans; //reading user's answer
                if (userans < 1 || userans > 3) { // Check for valid range
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    throw invalid_argument(" Invalid input. Please enter a number between 1 and 3.");
                }
                break; //break the loop if input is valid
            } catch (const invalid_argument &e) { //catching invalid input
                cout<< e.what() <<endl; //Display an error message
                cout<<" Choose the correct numbering of your answer from option (1-3): ";
            }
        }
        //now check if the user entered ans is correct
        if (userans == quiz[i].ans) {
            score++; 
            cout<<" Correct!\n"<<endl;
        } else {
            cout<<" Incorrect!.\n"<<endl;
        }
    }
    
    cout<<"                   ______________________________________        "<<endl;
    cout<<"                  |                                      |"<<endl;
    cout<<"                  |   Your final score is: " << score << " out of 10.  |"<<endl;
    cout<<"                  |______________________________________|       "<<endl;
    
    cout<<"                 ******************************************        "<<endl;
    cout<<"                       Thanks For Attempting This Quiz!              "<<endl;
    cout<<"                     ***********************************             "<<endl;
    saveScoreToFile(name, id, score); 
    return 0;//End of the program 
}
