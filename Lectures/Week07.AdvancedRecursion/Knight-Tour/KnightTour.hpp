#ifndef WEEK07_KNIGHT_TOUR_HPP_
#define WEEK07_KNIGHT_TOUR_HPP_

bool isValid(int x, int y, int n, int **position);
void knightTour(int k, int n, int x, int y, int **position, const int dx[8], const int dy[8]);

#endif