#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WORD 30
#define MAX_LINES 250
#define LINE 256

int getLine(char s[LINE]) {
    int count = 0;
    char c = getchar();
    while (count < LINE - 1 && c != '\n' && c != '\r') {
        s[count++] = c;  
        c = getchar();
    }
    s[count] = '\0';
    return count;
}

/*Function gets string from the standard input and saves it
  in the argument. Function returns the number of char that was gotten*/
int getWord(char w[WORD]) {
    int count = 0;
    char c = getchar();
    while(count < WORD - 1 && c != '\n' && c != '\t' && c != ' ') {
        w[count++] = c;
        c = getchar();
    }
    w[count] = '\0'; 
    return count;
}

  int similar(char* string1, char* string2, int max_deletions) {
  int m = strlen(string1);
  int n = strlen(string2);

  // If the length of string2 is more than the length of string1, then
  // string2 cannot be obtained from string1 by deleting at most max_deletions
  // characters.
  if (n > m) {
    return 0;
  }

  int i = 0;
  int j = 0;

  // Loop through both strings, comparing characters at each position.
  while (i < m && j < n) {
    // If the characters match, increment both i and j.
    if (string1[i] == string2[j]) {
      i++;
      j++;
    }
    else {
      // If the characters don't match, increment i and decrement max_deletions.
      i++;
      max_deletions--;
    }
  }

  // If all characters in string2 were found in string1 (j == n), and max_deletions
  // is non-negative, then string2 is a substring of string1 with at most max_deletions
  // deletions.
  return (j == n && max_deletions >= 0 && i == m);
}


// int substring(const char* str1, const char* str2) {
//   return strstr(str2, str1) != NULL;
// }


/*Function gets two strings and returns if str2 is in str1 */
int substring(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if(len2 > len1)
        return 0;
    
    int count = 0;
    while (*(str1)) {
        
        while (*(str2 + count) != '\0' && *(str1) == *(str2 + count)) {
            count++;
            str1++;
        }
        
        if(count == len2)// found substring
            return 1;
        
        count = 0;
        str1++; 
    }
    return 0;// wasnt found
}

void print_lines(char* str) {
    char line[LINE] = "0";
    int count = 0;
    while (count < LINE - 1) {
        count = getLine(line);
        if(substring(line, str))
            printf("%s\n", line);
    }  
}

/*Function gets string to search in the text if
  there are words that look similar to the string*/
void print_similar_words(char* str) {
    char word[WORD] = "0";
    int count = 0;
    while(count < WORD - 1) {
        count = getWord(word);
        if(similar(word, str, 1))
            printf("%s\n", word);
    }
}

void print(char *arr)
{
    char *pointer = arr;
    while (*pointer)
    {
        printf("%c", *pointer);
        pointer++;
    }
    printf("\n");
}

int main()
{ 
  char theWord[WORD] = {};
  getWord(theWord);

  char AorB;
  AorB = getchar();

  if (AorB == 'a')
  {
    print_lines(theWord);
  }
  else if (AorB == 'b')
  {
    print_similar_words(theWord);
  }
}