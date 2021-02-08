/* Tiffany Cai
 Given a document your program should output all of the misspelled words.
 For each misspelled word you should also provide a list of candidate corrections
 from the dictionary that can be formed by applying one of the following rules to the misspelled word:
 a) Adding one character in each possible position
 b) Removing one character from the word
 c) Swapping adjacent characters in the word
 */

#include "quadratic_probing.h"
#include "linear_probing.h"
#include "double_probing.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void SpellCheck(const string &dictionary_filename, const string &document_filename)
{
    HashTable<string> HashWordsTable; //create a hashtable to store dictionary words
    
    //open dictionary
    ifstream dictionaryFile;
    dictionaryFile.open(dictionary_filename);
    if (dictionaryFile.fail())
    {
        cerr << "Error, try again." << endl;
    }
    string dictWord;
    while (dictionaryFile >> dictWord){
        HashWordsTable.Insert(dictWord);    //add dictionary words to hashtable
    }
    dictionaryFile.close();
    
    //open documentfile
    ifstream documentFile;
    documentFile.open(document_filename);
    if (documentFile.fail())

    {
        cerr << "Error, try again." << endl;
    }
    string docWord;
    while (documentFile >> docWord){
        for (int i = 0; i < docWord.size(); i++)
        {
            docWord[0] = tolower(docWord[0]);      //this makes everything lowercase
            if (ispunct(docWord[0])){               //if first char is punctuation
                docWord = docWord.substr(1);        //remove
            }
            if (ispunct(docWord[docWord.size() - 1]))
            {                               //if last is punct, remove
                docWord.pop_back();
                if (ispunct(docWord[docWord.size() - 1]))
                {                           //if there are two punctuations
                    docWord.pop_back();     //remove
                }
            }
        }
        
        //CASE A
        //Adding one character in each possible position
        if(!HashWordsTable.Contains(docWord)){
            string misspelledWord = docWord;
            for (int i = 0; i < docWord.size(); i++){
                for (char c = 'a'; c <= 'z'; c++){  //inserts char c at location i
                    docWord.insert(i, 1, c);
                    if (HashWordsTable.Contains(docWord)){  //check dictionary for docWord
                        cout << misspelledWord << " -> " << docWord << " (case a)" << endl;
                    }
                    docWord = misspelledWord;   //reset word to loop
                }
            }
            
            //CASE B
            //Removing one character from the word
            for (int i = 0; i < docWord.size(); ++i){
                docWord.erase(i, 1);    //go through the word, and erase each character
                if (HashWordsTable.Contains(docWord)){  //check dictionary for docword
                    cout << misspelledWord << " -> " << docWord << " (case b)" << endl;
                }
                docWord = misspelledWord;   //reset
            }
            
            //CASE C
            //Swapping adjacent characters in the word
            for (int i = 0; i < docWord.size(); i++){
                swap(docWord[i], docWord[i + 1]); //swap character i with the next character
                if (HashWordsTable.Contains(docWord)){  //check dictionary for docword
                    cout<< misspelledWord << " -> " << docWord << " (case c)" << endl;
                }
                swap(docWord[i], docWord[i + 1]);   //reset
            }
        }
    }
    documentFile.close();
}


// Sample main for program spell_check
int main(int argc, char **argv) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <document-file> <dictionary-file>" << endl;
        return 0;
    }
    
    const string document_filename(argv[1]);
    const string dictionary_filename(argv[2]);
    
    cout << "Input document filename is " << document_filename << endl;
    cout << "Input dictionary filename is " << dictionary_filename << endl;
    
    // Call functions implementing the assignment requirements.
    SpellCheck(dictionary_filename, document_filename);
    
    return 0;
}
