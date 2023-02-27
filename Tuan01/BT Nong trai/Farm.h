#include <cstdio>

struct Point {
    double x;
    double y;
};

struct Farm {
    int n; // number of trees
    Point *coordinates;
    int *treeTypes;
};


double min(const double &a, const double &b);

double max(const double &a, const double &b);

void inputAFarm(Farm &f, std::FILE *fi);

void eachTypeNumber(Farm &f, int*& number, FILE *fo);

double minPerimeter(Farm &f);

double minPipesLength(Farm &f);

double getDistanceSum(Point p, Point *pArr, int n);

