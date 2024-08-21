#include "Header.h"
struct PointerInfo {
    const char* name;
    int segment;
    int offset;
    int size;
};

// Функция для выделения памяти с учетом информации о указателе
void* allocateMemory(PointerInfo* pInfo, size_t size) {
    std::cout << "Выделение " << size << " байт памяти для указателя " << pInfo->name << " в сегменте " << pInfo->segment << std::endl;
    return new char[size];
}


int main() {
    int N;  
    double A, B;  
    int count = 0;  
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    cout << "Введите количество элементов массива: ";
    cin >> N;
    try {
        int* arr = new int[N]; // Выделение памяти для указателя




        for (int i = 0; i < N; i++) {
            WritePointer(arr + i, rand() % 51);
            ReadPointer(arr + i);

        }

        cout << "Введите границу начала диапазона (A): ";
        cin >> A;
        cout << "Введите границу конца диапазона (B):";
        cin >> B;

        for (int i = 0; i < N; i++) {
            if (*(arr + i) >= A && *(arr + i) <= B) {
                count++;
            }
        }


        cout << "Количество элементов массива, лежащих в диапазоне от A до B: " << count << endl;
        PointerInfo leakedPointer = { "LeakedPtr", 1, 0, 100 };
        void* leakedMemory = allocateMemory(&leakedPointer, 100);
        FreePointer(arr);
    }
     catch (bad_alloc&) {
         cout << "Ошибка выделения памяти.";
         return 0;
     }
    return 0;
}
