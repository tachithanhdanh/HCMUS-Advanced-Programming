#include "Farm.h"

void inputAFarm(Farm &f, std::FILE *fi) {
    int n;
    fscanf(fi, "%d\n", &n);
    f.n = n;
    f.coordinates = new Point[n];
    f.treeTypes = new int[n];
    for (int i = 0; i < f.n; ++i) {
        fscanf(fi, "%lf %lf %d", &f.coordinates[i].x, &f.coordinates[i].y, &f.treeTypes[i]);
    }
    return;
}

void eachTypeNumber(Farm &f, int*& number, FILE *fo) {
    number = new int[3]{};
    for (int i = 0; i < f.n; ++i) {
        ++number[f.treeTypes[i]];
    }
    fprintf(fo, "%d %d %d\n", number[0], number[1], number[2]);
    number = nullptr;
    return;
}

double minPerimeter(Farm &f) {
    double minX, minY, maxX, maxY;
    minX = maxX = f.coordinates[0].x, minY = maxY = f.coordinates[1].y;
    for (int i = 0; i < f.n; ++i) {
        double X = f.coordinates[i].x, Y = f.coordinates[i].y;
        minX = min(minX, X);
        minY = min(minY, Y);
        maxX = max(maxX, X);
        maxY = max(maxY, Y);
    }
    double res = ((maxX - minX) + (maxX - minY)) * 2;
    return res;
}

double min(const double &a, const double &b) {
    return (a < b ? a : b);
}

double max(const double &a, const double &b) {
    return (a > b ? a : b);
}

double minPipesLength(Farm &f) {
    const Point dPoint[] = {{1.0, 0.0}, {-1.0, 0.0}, {0.0, 1.0}, {0.0, -1.0}};
    const double epsilon = 1E-4;
    Point *pArr = f.coordinates;
    int n = f.n;
    Point pCurrent = {0.0, 0.0};
    for (int i = 0; i < n; ++i) {
        pCurrent.x += pArr[i].x;
        pCurrent.y += pArr[i].y;
    }
    // let pCurrent be the center of gravity 
    pCurrent.x /= static_cast<double>(n);
    pCurrent.y /= static_cast<double>(n);
    double minDistance = getDistanceSum(pCurrent, pArr, n);
    double testDistance = 1000.0;
    bool flag;
    while (testDistance > epsilon) {
        flag = false;
        for (int i = 0; i < 4; ++i) {
            Point pNew;
            pNew.x = pCurrent.x + dPoint[i].x;
            pNew.y = pCurrent.x + dPoint[i].y;
            double newDist = getDistanceSum(pNew, pArr, n);
            if (newDist < minDistance) {
                flag = true;
                minDistance = newDist;
                pCurrent = pNew;
            }
        }
        if (flag == false) {
            testDistance /= 2;
        }
    }
    return minDistance;
}

double getDistanceSum(Point p, Point *pArr, int n) {
    double res = 0.0;
    for (int i = 0; i < n; ++i) {
        double dx = p.x - pArr[i].x;
        double dy = p.y - pArr[i].y;
        res += dx * dx + dy * dy;
    }
    return res;
}