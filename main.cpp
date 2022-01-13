//---------------------------------------------------------------------------

#include <fmx.h>
#include <queue>
#include <string>
#pragma hdrstop

#include "quiz_game_project.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

// Question class
class Question{
	public:
		char* text;
		char* answer1;
		char* answer2;
		char* answer3;
		char* answer4;
		int correctAnswer;

		Question(){};

		// constructor
		Question(char* txt, char* ans1, char* ans2, char* ans3, char* ans4, int corrAns){
			text = txt;
			answer1 = ans1;
			answer2 = ans2;
			answer3 = ans3;
			answer4 = ans4;
			correctAnswer = corrAns;
		}

};

// Questions
std::queue<Question> loadQuestions(){
	Question question1 = Question("What does HTML stand for?", "Hyper Trainer Marking Language", "Hyper Text Marketing Language",
	"Hyper Text Markup Leveler", "Hyper Text Markup Language", 4);
	Question question2 = Question("Which of the following is the correct way to use the standard namespace in C++?", "Using namespace std;",
	"Using namespace standard;", "Using standard namespace;", "Standard namespace used;", 1);
	Question question3 = Question("Which of these is NOT a programming language?", "Python", "Ruby", "Banana", "Java", 3);
	Question question4 = Question("Which of these is a programming language?", "Gnaw", "Scratch", "Bite", "Itch", 2);
	Question question5 = Question("Java can run on any computer platform that has a/an?", "Java compiler", "Linux OS",
	"Intel Pentium", "Java Virtual Machine", 4);
	Question question6 = Question("Which aggregate SQL function will return the number of rows in a database table?",
	"COUNT(column_name) or COUNT(*)", "MAX(column_name)", "SUM(column_name)", "NUM(column_name)", 1);
	Question question7 = Question("What function is automatically called at the beginning of a C++ program?", "srand()",
	"getline()", "main()", "abs()", 3);
	Question question8 = Question("What was the original name for Java?", "C++", "Ada", "Lisp", "Oak", 4);
	Question question9 = Question("When using tags in HTML code, they always appear how?", "Inside of angled brackets",
	"Only on the top of a document", "Always singularly", "In document footers and end notes only", 1);
	Question question10 = Question("What organization sets the standards that are used across the internet?", "Google",
	"The World Wide Web Consortium", "Microsoft", "Apple", 2);
	Question question11 = Question("How does one indicate that certain text is to be treated as a \"comment\" in the classic C language?",
	"Place the text between '#' and '#'.", "Place '#' before the text.", "Place the text between /* */ .", "Place 'COMMENT:' before the text.", 3);
	Question question12 = Question("What form of punctuation must end all C++ statements?", ".", ";", "!", "#", 2);
	Question question13 = Question("Antivirus, disk formatting and file managing software are examples of which kinds of software?",
	"Utility software", "Primary software", "Productivity software", "All kinds of doohickeys", 1);
	Question question14 = Question("What is the name of the inventor (or father) of Java?", "James Gosling",
	"Bjarne Stroustroup", "Bill Gates", "Dennis Ritchie", 1);
	Question question15 = Question("What does the \"Q\" in QBasic stand for?", "quit", "quote", "quick", "quite", 3);
	Question question16 = Question("What statement executes one set of statements when true and another when false?",
	"The if statement", "The switch statement", "The if/else if statement", "The if/else statement", 4);
	Question question17 = Question("Which of these is NOT a programming language?", "Perl", "BNF", "ALGOL", "Ada", 2);
	Question question18 = Question("If x = 13 and y = 5, then which of the following expressions produce a false result?",
	"x+7 != y*4", " x+7 == y*4", "x+2 <= y*3", "x+2 > y*2", 1);
	Question question19 = Question("Which of the following data types produces an output of true/false ?",
	"float", "string", "int", "bool", 4);
	Question question20 = Question("Why was the language called \"Python\"?", "The inventor's best friend suggested him the name.",
	"As a kid, the inventor liked to play the snake-and-ladder game.", "The inventorwas once attacked by a python in the Amazons.",
	"The inventor is a fan of \"Monty Python's Flying Circus\".", 4);
	Question question21 = Question("The following is NOT considered as an advantage of the Python programming language?",
	"Ideally suited for fast and memory intensive tasks like number crunching.", "Well suited for the novice as well as the expert.",
	"Object oriented, easily extendable and highly scalable.", "Allows for rapid development reducing software production lifecycles.", 1);
	Question question22 = Question("Which of these languages has Python NOT borrowed its features from?", "Java",
	"CLISP (Common Lisp)", "Fortran", "C++", 3);
	Question question23 = Question("What is the Java implementation of Python popularly known as?", "PyJava",
	"JavaPython", "Jython", "Javathon", 3);
	Question question24 = Question("When was the world wide we invented?", "1974", "1982", "1991", "1999", 3);
	Question question25 = Question("What does GUI stand for?", "Graphical User Interim", "Geographical User Interruption",
	"Gain Upper Intensity", "Graphical User Interface", 4);

	// pushing questions to the queue
	std::queue<Question> questions;
	questions.push(question1);
	questions.push(question2);
	questions.push(question3);
	questions.push(question4);
	questions.push(question5);
	questions.push(question6);
	questions.push(question7);
	questions.push(question8);
	questions.push(question9);
	questions.push(question10);
	questions.push(question11);
	questions.push(question12);
	questions.push(question13);
	questions.push(question14);
	questions.push(question15);
	questions.push(question16);
	questions.push(question17);
	questions.push(question18);
	questions.push(question19);
	questions.push(question20);
	questions.push(question21);
	questions.push(question22);
	questions.push(question23);
	questions.push(question24);
	questions.push(question25);

	return questions;
}
// initializing variables
std::queue<Question> questions;
Question currQuestion;
int selectedAnswer;
int correctGuesses = 0;
int wrongGuesses = 0;
float percentage = 0;


TForm1 *Form1;
//---------------------------------------------------------------------------
// on start
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	questions = loadQuestions();
	currQuestion = questions.front();

	// connecting labels and buttons to questions
	questionLabel -> Text = currQuestion.text;
	answer1Button -> Text = currQuestion.answer1;
	answer2Button -> Text = currQuestion.answer2;
	answer3Button -> Text = currQuestion.answer3;
	answer4Button -> Text = currQuestion.answer4;

	questions.pop();  // removes answered question from the queue
	goodGuesses -> Text = correctGuesses;
	badGuesses -> Text = wrongGuesses;
	// not visible until game ends
	guessPercentage -> Visible = false;
	percentageLabel -> Visible = false;
}
// answer 1 event handler
void __fastcall TForm1::answer1ButtonChange(TObject *Sender)
{
	selectedAnswer = 1;
}
// answer 2 event handler
void __fastcall TForm1::answer2ButtonChange(TObject *Sender)
{
	selectedAnswer = 2;
}
// answer 3 event handler
void __fastcall TForm1::answer3ButtonChange(TObject *Sender)
{
	selectedAnswer = 3;
}
// answer 4 event handler
void __fastcall TForm1::answer4ButtonChange(TObject *Sender)
{
	selectedAnswer = 4;
}
// submit button event handler
void __fastcall TForm1::submitButtonClick(TObject *Sender)
{
	if (selectedAnswer == currQuestion.correctAnswer) {
		correctGuesses++;
		goodGuesses -> Text = correctGuesses;
	} else {
		wrongGuesses++;
		badGuesses -> Text = wrongGuesses;
	}

	// if there are still questions remaining
	if (!questions.empty()) {
		currQuestion = questions.front();

        questionLabel -> Text = currQuestion.text;
		answer1Button -> Text = currQuestion.answer1;
		answer2Button -> Text = currQuestion.answer2;
		answer3Button -> Text = currQuestion.answer3;
		answer4Button -> Text = currQuestion.answer4;

		questions.pop();
		answer1Button -> IsChecked = false;
		answer2Button -> IsChecked = false;
		answer3Button -> IsChecked = false;
		answer4Button -> IsChecked = false;
	}
	// if there are no more questions (game ends)
	else {
		submitButton -> Enabled = false;
		submitButton -> Text = "Game Over!";
		guessPercentage -> Visible = true;
        percentageLabel -> Visible = true;
		float percentageOfGuesses = float(correctGuesses) / float((correctGuesses + wrongGuesses));
		percentageOfGuesses = ceil(percentageOfGuesses * 100);
		percentage -> Text = percentageOfGuesses;
		if (percentageOfGuesses == 100) {
			endText -> Text = "You know everything, congratulations!";
		} else if (percentageOfGuesses >= 75) {
			endText -> Text = "Good job, close to perfect!";
		} else if (percentageOfGuesses >= 50) {
			endText -> Text = "Not great, not terrible.";
		} else if (percentageOfGuesses > 0) {
			endText -> Text = "You definitely lack some knowledge.";
		} else {
			endText -> Text = "That was sad to watch, honestly.";
		}
	}
}

