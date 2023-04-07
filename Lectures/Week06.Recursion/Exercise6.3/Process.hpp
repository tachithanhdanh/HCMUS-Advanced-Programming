#ifndef BT63_PROCESS_HPP_
#define BT63_PROCESS_HPP_

void generate_permutations(char *s, int k, int n);
void generate_permutations_of_size_k(char *src, char *dest, int k, int n);
void generate_combinations(char *src, char *dest, int offset, int k, int pos, int n, bool flag = false);
void sort(char *s, int len);
void swap(char &a, char &b);

#endif