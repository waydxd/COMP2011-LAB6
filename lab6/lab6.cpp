/* 
 * File: lab6_skeleton.cpp
 *
 * Lab 6: Recursion - Alien Word Parsing
 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_LEN = 256; 
bool isAlphabet(char c)
{
   return (c >= 'a' && c <= 'z');
}
bool correct_word(char word[], int start, int end)
{
   // Task 1: Base case with only a single character
   if (start == end && isAlphabet(word[start])) {
      return 1;
   }

   // Task 2: Recursive case with suffix characters '@', or '#'
   if (word[end] == '@' || word[end] == '#') {
      return correct_word(word, start, end - 1);
   }

   // Task 3: Recursive case with concatenation characters '|' at suffix position.
   if (word[end] == '|') {
      for(int i = start; i < end-1; i++) {
         if(correct_word(word, start, i) && correct_word(word, i+1, end-1)){
            return 1;
         }
      }
   }

   // Task 4: Recursive case with concatenation characters '#' at prefix position.
   if (word[start] == '#') {
      for(int i = start+1; i < end; i++){
         if(correct_word(word, start+1 ,i) &&correct_word(word, i+1,end)){
            return 1;
         }
      }
   }

   // All remaining cases are wrong
   return 0;
}


int main()
{
   char word[MAX_LEN];
   char c;
   
   do{
      cout << "Enter a word: ";
      cin >> word;
      if (correct_word(word, 0, strlen(word) - 1))
         cout << "The word is CORRECT!\n";
      else
         cout << "The word is INCORRECT!\n";
      cout << "Do you want to enter a new word ('Y'/'y' for Yes, 'N'/'n' for No)? ";
      cin >> c;
   } while (c == 'Y' || c=='y');

   return 0;
}

