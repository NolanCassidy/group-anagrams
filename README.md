# group-anagrams
Finds all anagrams in a dictionary.

The program does the following:<br />
Open a file specified on the command line or read from stdin.<br />
*Read each line as a word and remove the ‘\n’ from it.<br />
*Add the word to an existing anagram family or create a new one.<br />
*Enumerate the anagram families, printing to a specified file or stdout:<br />
    *print the sorted set followed by ‘:’<br />
    *print the number of anagrams followed by ‘\n’<br />
    *print a tab ‘\t’ before each anagram, then anagram, followed by ‘\n’<br />
*Do not print out anagram families whose size is 1.<br />
*Clean up all memory data structures and close all files, Detect and handle erroneous command line input.<br />

Here is an example of expected output in a file:<br />
a a b e i r : 3<br />
A b e r i a<br />
B a e r i a<br />
B a i e r a<br />
<br />
a b e t : 5<br />
a b e t<br />
b a t e<br />
b e a t<br />
B e t a<br />
b e t a<br />
