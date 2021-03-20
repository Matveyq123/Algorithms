template<typename FirstIt, typename SecondIt, typename OutIt>
OutIt Merge(FirstIt first_begin, FirstIt first_end, SecondIt second_begin, SecondIt second_end, OutIt out_begin, int64_t& counter) {
    while (first_begin != first_end && second_begin != second_end) {
        if (*second_begin < *first_begin) {
            int size = first_end - first_begin;
            *out_begin = *second_begin;
            ++second_begin;
            counter += size;
        }
        else {
            *out_begin = *first_begin;
            ++first_begin;
        }
        ++out_begin;
    }
    return std::copy(second_begin, second_end, std::copy(first_begin, first_end, out_begin));
}
template<typename RandomIt>
int MergeSort(RandomIt range_begin, RandomIt range_end, int64_t& counter) {
    int range_length = range_end - range_begin;
    if (range_length < 2) {
        return 0;
    }
    std::vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto mid = elements.begin() + range_length / 2;

    MergeSort(elements.begin(), mid, counter);
    MergeSort(mid, elements.end(), counter);

    Merge(elements.begin(), mid, mid, elements.end(), range_begin, counter);
    return counter;
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int64_t>arr(n);
    for (int64_t& i : arr) {
        std::cin >> i;
    }
    int64_t counter = 0;
    int answer = MergeSort(arr.begin(), arr.end(), counter);
    std::cout <<"Number of invertions: " << counter << std::endl;
     for (const int& i : arr) {
         std::cout << i<< " ";
     }
    return 0;
}
