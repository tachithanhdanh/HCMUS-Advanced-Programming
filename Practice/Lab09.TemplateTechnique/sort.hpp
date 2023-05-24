#ifndef SORT_HPP_
#define SORT_HPP_

template<typename T>
using cmpFcnPtr = bool(*)(const T&, const T&);

template<typename T>
void sort(T* arr, int n, cmpFcnPtr<T> cmpFcn) {
    merge_sort(arr, 0, n - 1, cmpFcn);
}

template<typename T>
void merge_sort(T* arr, int left, int right, cmpFcnPtr<T> cmpFcn) {
    if (left == right) {
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid, cmpFcn);
    merge_sort(arr, mid + 1, right, cmpFcn);
    merge(arr, left, mid, right, cmpFcn);
}

template<typename T>
void merge(T* arr, int left, int mid, int right, cmpFcnPtr<T> cmpFcn) {
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;
    T* leftArr = new T[sizeLeft]{};
    T* rightArr = new T[sizeRight]{};

    int indexLeft = 0;
    int indexRight = 0;
    int indexArr = left;

    while (indexLeft < sizeLeft && indexRight < sizeRight) {
        if (cmpFcn(leftArr[indexLeft], rightArr[indexRight])) {
            arr[indexArr++] = leftArr[indexLeft++];
        } else {
            arr[indexArr++] = rightArr[indexRight++];
        }
    }

    while (indexLeft < sizeLeft) {
        arr[indexArr++] = leftArr[indexLeft++];
    }

    while (indexRight < sizeRight) {
        arr[indexRight++] = rightArr[indexRight++];
    }

    delete[] leftArr;
    delete[] rightArr;
}

#endif