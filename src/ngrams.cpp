// This is the CPP file you will edit and turn in. (TODO: Remove this comment!)

#include <iostream>
#include "console.h"
#include <string>
#include "lexicon.h"
#include "strlib.h"
#include "simpio.h"
#include "vector.h"
#include "queue.h"
#include "filelib.h"
using namespace std;

// when reading a file, it has to be When reading the input file, the idea is to keep a window of N-1 words at all times, and as you read each word from the file, discard the first word from your window and append the new word.
// The matter matters ('are you' is different from 'you are')
//
//Prototypes
void welcome();
void readFile(Vector<string> grams_map, Vector<string> grams_window, ifstream&infile, int N);


int main() {
    // Print the welcoming text
    welcome();
    // Open the file and reprompt the user if the file is invalid
    ifstream stream;
    string prompt = "Input file name?";
    string reprompt = "Unable to open that file. Try again!";
    promptUserForFile(stream, prompt, reprompt);
    // How can i store the file, what ADT should I use @@
    //read the input file
    // Assign the literature to a variable called work
    Lexicon lex(filename);
    //work = Set<string>stream;

    // Prompt the user for integer input "N"
    int N = stringToInteger(getLine("Value of N? "));
    int Num = stringToInteger(getLine("# of random words to generate (0 to quit)."));
    //Call the readFile function@@




    cout << "Exiting." << endl;
    return 0;
}


void welcome (){
    cout << "Welcome to CS 106B/X Random Writer ('N-Grams')!" << endl;
    cout << "This program generates random text based on a document." << endl;
    cout << "Give me an input file and an 'N' value for groups" << endl;
    cout << "of words, and I'll create random text for you." << endl;
    cout << endl;

}

//void readFile(Vector<string> grams_map, Vector<string> grams_window, ifstream&infile, int N){
//    // Keep a window of N-1 words at all time

//    string filename = getLine("Filename");

//    promptUserForFile(infile, "ladygaga.txt");

//    grams_window = Vector<string>;
//    //grams_map = Map<Queue<Stack<string>>, queue<stack>>;
//    grams_map = Map<Vector<string>, Vector<string>>;
//    Queue<
//    //How should I call the literature here@@
//    //string (line);

//    //while@@

//    // keep a counter of the random words generated
//    <int>sum_words = 0
//    //iterating through all the lines


}
Map<Vector<string>,Vector<string>> readFile(){
    ifstream infile;
    promptUserForFile(infile, "Input file name");

    int Ngram = getInteger("Value of B?");

    Map<Vector<string>,Vector<string>> dictionary;

    cout<< endl;
    //@@How can I know the position of N and n in the programming
    //Create an empty map to store the key and value
    //Map<Vector<string>, Vector<string>> map;
    Queue<string> passage;

    string word;
    while(infile >> word){
        passage.enqueue(word);
    }
    int wordCount = passage.size();
    Queue<string> window;
    // from passage to window
    for (i=wordCount; i>0;i--){
        for (j=Ngram; j>1; j--){
            string keyWord = passage.dequeue();
            window.enqueue(keyWord);
            passage.enqueue(keyWord);
        }
        string valueWord = passage.dequeue();
        // from window to key vector
        Queue<string> getWord = keyWord;
        Vector<string> keyVec;
        while (!getWord.isEmpty()){
            keyVec.add(getWord.dequeue());
        }
        Vector<string> valueVec;
        // check if key exist
        if (dictionary.containsKey(keyVec)){
            valueVec = dictionary[keyVec]
        }

        valueVec.add(valueWord);
        // put one set in map
        dictionary.put(keyVec,valueVec);
        // move window backward one word
        window.dequeue();
        window.enqueue(valueWord);
      }
    infile.close();
    return dictionary;
}








