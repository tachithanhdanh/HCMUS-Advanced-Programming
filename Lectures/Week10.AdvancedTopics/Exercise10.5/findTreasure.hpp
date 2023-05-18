#ifndef FIND_TREASURE_HPP_
#define FIND_TREASURE_HPP_

void findTreasure();
void inputRooms(int**& rooms, int& M, int& N);
void findMaxTreasure(int**& rooms, int**& maxTreasure, int**& trace, int M, int N);
void findPathToMaxTreasure(int**& rooms, int**& maxTreasure, int**& trace, int M, int N);
void initMatrix(int**& a, int m, int n);
void deleteMatrix(int**& a, int m);

#endif