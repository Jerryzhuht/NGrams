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
#include "random.h"

using namespace std;
Map<Queue<string>,Vector<string>> readFile();
Queue<string> wordGen(int n, Map<Queue<string>,Vector<string>> &dictionary);


int main() {
    // Print the welcoming text
    cout << "Welcome to CS 106B/X Random Writer ('N-Grams')!" << endl;
    cout << "This program generates random text based on a document." << endl;
    cout << "Give me an input file and an 'N' value for groups" << endl;
    cout << "of words, and I'll create random text for you." << endl;
    cout << endl;

    Map<Queue<string>,Vector<string>> dictionary = readFile();
    while(true){
        int n = getInteger("# of random words to generate (0 to quit):");
        if (n == 0){
            break;
        }
        Queue<string> sentence = wordGen(n,dictionary);
        while (!sentence.isEmpty()){
            string word = sentence.dequeue();
            cout << word << "";
            cout << endl;
        }
    }

    cout << "Exiting." << endl;
    return 0;
}



Map<Queue<string>,Vector<string>> readFile(){
    ifstream infile;
    promptUserForFile(infile, "Input file name");

    int Ngram = getInteger("Value of N?");

    Map<Queue<string>,Vector<string>> dictionary;

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
    for (int i=0; i<wordCount;i++){
        for (int j=1; j<Ngram; j++){
            string keyWord = passage.dequeue();
            window.enqueue(keyWord);
            passage.enqueue(keyWord);
        }
        string valueWord = passage.dequeue();
        // from window to key queue
        Queue<string> keyQueue = window;
//        Vector<string> keyVec;
//        while (!getWord.isEmpty()){
//            keyVec.add(getWord.dequeue());
//        }
//        Vector<string> valueVec;
        // check if key exist
        Vector<string> valueVec;
        if (dictionary.containsKey(keyQueue)){
            valueVec = dictionary[keyQueue];
        }

        valueVec.add(valueWord);
        // put one set in map
        dictionary.put(keyQueue,valueVec);
        // move window backward one word
        window.dequeue();
        window.enqueue(valueWord);
      }

    infile.close();
    return dictionary;
}


Queue<string> wordGen(int n, Map<Queue<string>,Vector<string>> &dictionary){
    Queue<string> sentence;
    // all the keys in dictionary
    Vector<Queue<string>> availableKeys = dictionary.keys();
    int rand1 = randomInteger(0, availableKeys.size()-1);
    // first N words
    Queue<string> startQueue = availableKeys[rand1];

    // init windows
    Queue<string> windows;
    windows = startQueue;
    sentence = startQueue;
//    while (!startQueue.isEmpty()){
//        windows.enqueue(startVec[i]);
//        sentence.enqueue(startVec[i]);
//    }

    while(sentence.size() < n ){
        // vector for next word
        Vector<string> nextVec = dictionary[startQueue];
        int rand2 = randomInteger(0, nextVec.size()-1);
        string nextWord = nextVec[rand2];
        // add into sentence
        sentence.enqueue(nextWord);
        // adjust windows
        windows.enqueue(nextWord);
        windows.dequeue();
        // adjust startQueue
        startQueue.dequeue();
    }
    return sentence;
}


























