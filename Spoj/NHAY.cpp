#include <iostream>
#include <vector>
using namespace std;

#define uint unsigned int

//#define MAX_N 100010
//char T[MAX_N], P[MAX_N];                                    // T = text, P = pattern
//int b[MAX_N], n, m;             // b = back table, n = length of T, m = length of P

void kmpPreprocess(string &text, string &pattern, vector<int> &backTable, uint &textSize, uint &patternSize) {     // call this before calling kmpSearch()
  int i = 0, j = -1; backTable[0] = -1;                                 // starting values
  while (i < patternSize) {                             // pre-process the pattern string P
    while (j >= 0 && pattern[i] != pattern[j]) 
      j = backTable[j];                                   // different, reset j using b
    i++; j++;                                 // if same, advance both pointers
    backTable[i] = j; // observe i = 8, 9, 10, 11, 12, 13 with j = 0, 1, 2, 3, 4, 5
  }                                 // in the example of P = "SEVENTY SEVEN" above
}

void kmpSearch(string &text, string &pattern, vector<int> &backTable, uint &textSize, uint &patternSize, vector<uint> &foundAt) {                   // this is similar as kmpPreprocess(), but on string T
  int i = 0, j = 0;                                   // starting values
  while (i < textSize) {                            // search through string T
    while (j >= 0 && text[i] != pattern[j]) 
      j = backTable[j];                         // different, reset j using b
    i++; j++;                                   // if same, advance both pointers
    if (j == patternSize) {                       // a match found when j == m
      foundAt.push_back(i-j); 
      //printf("P is found at index %d in T\n", i - j);
      j = backTable[j];                       // prepare j for the next possible match
    } 
  } 
}

int main()
{
  ios_base :: sync_with_stdio(false);
  
  string text, pattern;
  vector <int> backTable;
  
  uint textSize, patternSize;
  
  vector <uint> foundAt;
  uint foundAtSize;
  
  //input
  while(cin >> patternSize)
  {
    cin >> pattern >> text;
    
    patternSize = pattern.size();
    backTable.resize(patternSize+1);
    textSize = text.size();
    
    if(textSize < patternSize)
      cout << "\n";
    else{
      kmpPreprocess(text, pattern, backTable, textSize, patternSize);
      kmpSearch(text, pattern, backTable, textSize, patternSize, foundAt);
      
      foundAtSize = foundAt.size();
      for(int i=0; i<foundAtSize; i++)
        cout << foundAt[i] << "\n";
    }
    backTable.clear();
    foundAt.clear();
  }
  return 0;
