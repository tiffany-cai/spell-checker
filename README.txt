//Tiffany Cai


The goal of this assignment is to test three hashing implementations.  The three implementations are linear, double, and quadratic probing. Then these hashing implementations are used to create a spell checker.  

Each hashing implementation is able to read all words from a given text file, words.txt, and insert them into a hash table.  After the table is created print out the total number of elements in the table (N), the size of table, the load factor, the total number of collisions, and the average number of collisions.  It also checks whether each word is in another given file, query_words.txt, is in the hash table or not.  If it is found, the word is printed along with the string "Found" and the number of probes used to find it.  If it is not found, the word is printed along with "Not Found" and the number of probes used.

The spell checker is implemented using quadratic probing.  It inputs all dictionary words into a hash table.  Then it reads a given document file to find misspelled words.  The spell checker makes all the words in the document lowercase and removes any punctuation to compare the words to the words in the hash table. It compares the words using three cases: adding characters, removing characters, and swapping characters.  Then it outputs any misspelled words with its correct spelling. 

One issue I had was figuring out how to convert everything to lowercase and remove punctuation.  I found that that tolower and ispunct is built in to c++ and used that.

To compile and run the program in terminal:

Compile everything by typing 

make clean
make all

To run create_and_test_hash:
./create_and_test_hash <words file name> <query words file name> <flag>
Examples:
	./create_and_test_hash words.txt query_words.txt quadratic
	./create_and_test_hash words.txt query_words.txt linear
	./create_and_test_hash words.txt query_words.txt double

To run spell_check:
./spell_check <document file> <dictionary file>
Examples:
	./spell_check document1_short.txt wordsEn.txt
	./spell_check document1.txt wordsEn.txt

Input files:
	document1_short.txt
	document1.txt
	query_words.txt
	words.txt
	wordsEn.txt

Output file:
	expected_output.txt
