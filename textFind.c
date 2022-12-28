#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WORD 30
#define MAX_LINES 250
#define LINE 256

int getLine(char s[LINE]) {
    int counter = 0;
    char ch = getchar();
    while (counter < LINE - 1 && ch != '\n' && ch != '\r') {
        s[counter] = ch;
        counter++;  
        ch = getchar();
    }
    s[counter] = 0;
    return counter;
}

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

  if (n > m)
  {
    return 0;
  }

  int i = 0;
  int j = 0;

  while (i < m && j < n) {
    if (string1[i] == string2[j])
    {
      i++;
      j++;
    }
    else
    {
      i++;
      max_deletions--;
    }
  }
  return (j == n && max_deletions >= 0 && (i == m || i == m - max_deletions));
}

int substring(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    
    if(n > m)
        return 0;
    
    int counter = 0;

    while (*(str1)) {
        
        while (str2[counter] != '\0' && *(str1) == str2[counter]) {  
            str1++;
            counter++;
        }
        
        if(n == counter)
        {
          return 1;
        }
        
        str1++;
        counter = 0; 
    }
    return 0;
}

void print_lines(char* str) {
    char arr[LINE] = {};
    int count = 0;
    while (count < LINE - 1) {
        count = getLine(arr);
        if(substring(arr, str))
        {
          printf("%s\n", arr);
        }
    }  
}

void print_similar_words(char* str) {
    char arr[WORD] = {};
    int count = 0;
    while(count < WORD - 1) {
        count = getWord(arr);
        if(similar(arr, str, 1))
        {
          printf("%s\n", arr);
        }
    }
}

void print(char *arr)
{
    char *pArr = arr;
    while (*pArr)
    {
        printf("%c", *pArr);
        pArr++;
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