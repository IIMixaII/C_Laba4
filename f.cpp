#include "Header.h"

void WritePointer(int* ptrA, int pp) {
    *ptrA = pp;
}
void ReadPointer(int* ptr) {

    cout << *ptr << endl;
}
int* FreePointer(int* p) {
    p = NULL;
    delete p;
    return p;
}
