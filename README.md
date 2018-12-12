# group-anagrams
 The goal is to find all anagrams in the dictionary.  Everyword that can be spelled using the same set of letters will be grouped together.

The program does the following:
•Open a file specified on the command line or read from stdin.
•Read each line as a word and remove the ‘\n’ from it.
•Add the word to an existing anagram family or create a new one.
•Enumerate the anagram families, printing to a specified file or stdout:
    print the sorted set followed by ‘:’
    print the number of anagrams followed by ‘\n’
    print a tab ‘\t’ before each anagram, then anagram, followed by ‘\n’
•Do not print out anagram families whose size is 1.
•Clean up all memory data structures and close all files, Detect and handle erroneous command line input.

Here is an example of expected output in a file:
a a b e i r : 3
A b e r i a
B a e r i a
B a i e r a

a b e t : 5
a b e t
b a t e
b e a t
B e t a
b e t a
