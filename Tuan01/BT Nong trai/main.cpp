#include "Farm.h"

int main(void) {
    std::FILE *fi = std::fopen("NongTrai.in", "r");
    Farm f;
    inputAFarm(f, fi);
    std::fclose(fi);
    int *number = nullptr;
    std::FILE *fo = std::fopen("NongTrai.out", "w");
    eachTypeNumber(f, number, fo);
    std::fprintf(fo, "%lf\n%lf\n", minPerimeter(f), minPipesLength(f));
    std::fclose(fo);
    return 0;
}