#include "Header.h"
struct PointerInfo {
    const char* name;
    int segment;
    int offset;
    int size;
};

// ������� ��� ��������� ������ � ������ ���������� � ���������
void* allocateMemory(PointerInfo* pInfo, size_t size) {
    std::cout << "��������� " << size << " ���� ������ ��� ��������� " << pInfo->name << " � �������� " << pInfo->segment << std::endl;
    return new char[size];
}


int main() {
    int N;  
    double A, B;  
    int count = 0;  
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    cout << "������� ���������� ��������� �������: ";
    cin >> N;
    try {
        int* arr = new int[N]; // ��������� ������ ��� ���������




        for (int i = 0; i < N; i++) {
            WritePointer(arr + i, rand() % 51);
            ReadPointer(arr + i);

        }

        cout << "������� ������� ������ ��������� (A): ";
        cin >> A;
        cout << "������� ������� ����� ��������� (B):";
        cin >> B;

        for (int i = 0; i < N; i++) {
            if (*(arr + i) >= A && *(arr + i) <= B) {
                count++;
            }
        }


        cout << "���������� ��������� �������, ������� � ��������� �� A �� B: " << count << endl;
        PointerInfo leakedPointer = { "LeakedPtr", 1, 0, 100 };
        void* leakedMemory = allocateMemory(&leakedPointer, 100);
        FreePointer(arr);
    }
     catch (bad_alloc&) {
         cout << "������ ��������� ������.";
         return 0;
     }
    return 0;
}
