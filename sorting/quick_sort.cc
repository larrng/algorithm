#include "sorting_util.h"

namespace algorithm {
namespace sorting {

template <class T, size_t N>
int Partition(T (&array)[N], int lo, int hi) {
  auto pivot = array[hi];
  int i = lo - 1;
  for (auto j = lo; j < hi; j++) {
    if (array[j] < pivot) {
      std::swap(array[++i], array[j]);
    }
  }
  std::swap(array[i + 1], array[hi]);
  return i + 1;
}

template <class T, size_t N>
int HoarePartition(T (&array)[N], int lo, int hi) {
  auto pivot = array[lo];
  int i = lo, j = hi;
  while (true) {
    while (array[i] < pivot) {
      i++;
    }
    while (array[j] > pivot) {
      j--;
    }
    if (i < j) {
      std::swap(array[i], array[j]);
    } else {
      return j;
    }
  }
}

template <class T, size_t N>
void QuickSort(T (&array)[N], int lo, int hi) {
  if (lo < hi) {
    int separator = Partition(array, lo, hi);
    QuickSort(array, lo, separator - 1);
    QuickSort(array, separator + 1, hi);
  }
}

}  // namespace sorting
}  // namespace algorithm

int main() {
  int integers[11] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
  std::string strings[7] = {"c",  "java",  "cpp",        "python",
                            "go", "swift", "objective-c"};
  float floats[8] = {5.2f, 4.4f, 6.8f, 9.5f, 0.7f, 1.2f, 3.2f, 5.9f};

  algorithm::sorting::QuickSort(integers, 0,
                                sizeof(integers) / sizeof(*integers) - 1);
  std::cout << "Sorted integer array: ";
  algorithm::sorting::PrintArray(integers);  // 2 3 5 6 8 9 10 22 26 32 40

  algorithm::sorting::QuickSort(strings, 0,
                                sizeof(strings) / sizeof(*strings) - 1);
  std::cout << "Sorted string array: ";
  algorithm::sorting::PrintArray(
      strings);  // c cpp go java objective-c python swift

  algorithm::sorting::QuickSort(floats, 0,
                                sizeof(floats) / sizeof(*floats) - 1);
  std::cout << "Sorted float array: ";
  algorithm::sorting::PrintArray(floats);  // 0.7 1.2 3.2 4.4 5.2 5.9 6.8 9.5

  return 0;
}