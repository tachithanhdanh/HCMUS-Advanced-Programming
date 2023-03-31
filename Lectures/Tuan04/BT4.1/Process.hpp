#ifndef BT41_PROCESS_HPP_
#define BT41_PROCESS_HPP_

void InsertCharToString(char *&s, int &n, const char c);
void InsertWordToWordArray(char **&s, int &n, char *&word);
void process(const char *inputString, const int inputLen, char **&stringArray, int &arrayLen, int &countWords);
void deleteStringArray(char **&stringArray, int &arrayLen);
void deleteDynamicString(char *&str);
void normalize(char *s, int n);

#endif