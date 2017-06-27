#ifndef ARIELSLIB_INSERTION_SORT_H
#define ARIELSLIB_INSERTION_SORT_H

namespace edb1 {
	
	template<typename T>
	void insertionSort(T *v, int n) {
      int i, j;
      T tmp;
      for (i = 1; i < n; i++) {
            j = i;
            while (j > 0 && v[j - 1] > v[j]) {
                  tmp = v[j];
                  v[j] = v[j - 1];
                  v[j - 1] = tmp;
                  j--;
            }
      	}
    }
}

#endif