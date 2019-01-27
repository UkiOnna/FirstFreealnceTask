#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void countLetter() {
	string sentence;
	char letter;
	try {		//use try/catch for catching errors
		cout << "Please enter a sentence: ";
		getline(cin, sentence);//Get the user's sentence

		cout << "Please enter a letter: ";
		cin >> letter;//Get the user's letter



		letter = tolower(letter); //Convert letter to lowercase
		transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower); //Convert whole sentence to lowercase

		int counter = 0;
		for (size_t i = 0; i < sentence.size(); i++) {
			if (sentence[i] == letter) {	//Checking for repeating in sentence 
				counter++;//count every repeat
			}
		}

		cout << "The letter \"" << letter << "\" is repeated " << counter << " times in your sentence" << endl;
	}

	catch (...) {	//Get here if get errors
		cout << "You entered incorrect values" << endl;
	}
}
void convertPhonetic() {
	string alpha[] = { "Alfa", "Bravo", "Charlie", "Delta","Echo","Foxtrot","Golf","Htoel","India","Juliett","Kilo","Lima",
		"Mike","November","Oscar","Papa","Quebec","Romeo","Sierra", "Tango","Uniform","Victor", "Whiskey", "X-ray", "Yankee","Zulu" };//massiv of NATO alphabet

	string word;

	cout << "Please enter a word: ";
	cin >> word;

	for (size_t i = 0; i < word.size(); i++) {
		int index = toupper(word[i]) - 'A';
		cout << alpha[index] << " ";
	}

	cout << endl;
}
int computeFactorial(int number) {
	return number > 1 ? computeFactorial(number - 1) * number : 1;
}
void factorial() {
	int number;

	cout << "Please enter a number: ";
	cin >> number;

	cout << "The factorial of \"" << number << "\" is \"" << computeFactorial(number) << "\"";
}
int computeEnchancedFactorial(int number) {
	const int lastPreCalculatedFactorial = 720;
	const int lastPreCalculatedFactorialNumber = 6;

	return number > lastPreCalculatedFactorialNumber ? computeEnchancedFactorial(number - 1) * number : lastPreCalculatedFactorial;
}
void enchancedFactorial() {
	const int preCalculatedFactorials[] = { 1, 2, 6, 24, 120, 720 };
	int number;

	cout << "Please enter a number: ";
	cin >> number;


	int result;
	if (number >= 1 && number <= 6) {
		result = preCalculatedFactorials[number - 1];
	}
	else {
		result = computeEnchancedFactorial(number);
	}

	cout << "The factorial of \"" << number << "\" is \"" << result << "\"";
}

int main(void) {
	countLetter();
	convertPhonetic();
	factorial();
	enchancedFactorial();
	cin.get(); cin.get();
	return 0;
}