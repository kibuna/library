template <typename T>
void array_shuffle(vector<T> &arr) {
    srand((unsigned int)(time(nullptr)));
    int size = arr.size();
    for (int i = size; i >= 1; --i) {
        swap(arr[i - 1], arr[rand() % i]);
    }
}