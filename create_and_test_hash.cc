// Tiffany Cai
//
//

#include "quadratic_probing.h"
#include "linear_probing.h"
#include "double_probing.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) {
  cout << "TestFunctionForHashTables..." << endl;
  cout << "Words filename: " << words_filename << endl;
  cout << "Query filename: " << query_filename << endl;
    cout << endl;
    
  hash_table.MakeEmpty();  
  //..Insert your own code

    hash_table.reset_numCollisions();   //have to reset collisions each time
    
    //open files
    ifstream inputFile;
    inputFile.open(words_filename.c_str());
    if (inputFile.fail())
    {
        cerr << "Error, try again." << endl;
    }
    
    string line_input;
    if (inputFile.is_open())
    {
        cout << "Inserting words into Hash Table..." << endl;
        while(getline(inputFile, line_input))   //while file is open, add elements to table
        {
            hash_table.Insert(line_input);
        }           //collide until a position is found in the table
    }
    inputFile.close();

    //Testing part A
    cout << endl;
    cout << "Statistics for this Hash Table: " << endl;
    cout << "Collisions: " << hash_table.numCollisions() << endl;
    cout << "Number of items: " << hash_table.numElements() << endl;
    cout << "Size of hash table: " << hash_table.arraySize() << endl;
    cout << "Load factor: " << (hash_table.numElements() / (float)hash_table.arraySize()) << endl;
    cout << "Avg. number of collisions: " << (hash_table.numCollisions() / (float)hash_table.numElements()) << endl;
    cout <<endl;
    
    ifstream queryFile;
    queryFile.open(query_filename.c_str());
    if (queryFile.fail())
    {
        cerr << "Error, try again." << endl;
    }

    //Testing Part B
    string line_query;
    cout << "Beginning searching for query words:" << endl;
    while(getline(queryFile, line_query))
    {
        hash_table.reset_numCollisions();   //reset collisions after each probe
        //collide until a position is found in the table
        if(hash_table.Contains(line_query))
        {
            cout << line_query << ": Found in " << hash_table.numCollisions() + 1 << " probes " << endl;
        }   //number of probs is the numcollisions plus 1
        else
        {
            cout << line_query << ": Not Found in " << hash_table.numCollisions() + 1 << " probes " << endl;
        }
    }
    queryFile.close();
}

// Sample main for program create_and_test_hash
int
main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << " <wordsfilename> <queryfilename> <flag>" << endl;
    return 0;
  }
  
  const string words_filename(argv[1]);
  const string query_filename(argv[2]);
  const string param_flag(argv[3]);

  if (param_flag == "linear") {
    HashTableLinear<string> linear_probing_table;
    TestFunctionForHashTable(linear_probing_table, words_filename, query_filename);
  }
  else if (param_flag == "quadratic") {
    HashTable<string> quadratic_probing_table;
    TestFunctionForHashTable(quadratic_probing_table, words_filename, query_filename);
  }
  else if (param_flag == "double") {
    HashTableDouble<string> double_probing_table;
    TestFunctionForHashTable(double_probing_table, words_filename, query_filename);
  }
  else
  {
    cout << "Uknown tree type " << param_flag << " (User should provide linear, quadratic, or double)" << endl;
  }
  return 0;
}
