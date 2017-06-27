#ifndef ARIELSLIB_SELECTION_SORT_H
#define ARIELSLIB_SELECTION_SORT_H

namespace edb1 {
	template<typename T>
	int lowest(T *v, int n, int tmp) {
		T m = v[tmp];
		int pos = tmp;

		for (int i = tmp; i < n; ++i) {
			if(v[i] < m) {
				m = v[i];
				pos = i;
			}
		}
		return pos;
	}

	template<typename T>
	void selectionSort(T *v, int n) {
		int lo = 0;
		T tmp;

		for (int i = 0; i < n; ++i) {
			lo = lowest(v, n, i);

			tmp = v[i];
			v[i] = v[lo];
			v[lo] = tmp;
		}
	}
}

#endif