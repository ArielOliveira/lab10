#ifndef ARIELSLIB_QUICK_SORT_H
#define ARIELSLIB_QUICK_SORT_H

#include <iostream>

namespace edb1 {

	template <typename T> 
	void quickSort(T *v, int left, int right) {
		int left1 = left, right1 = right;
		T tmp;	
		T pivot = v[(left + right) / 2];
		while(left1 <= right1) {
			while(v[left1] < pivot) left1++;
			while(v[right1] > pivot) right1--;
			if(left1 <= right1){
				tmp = v[left1];
				v[left1] = v[right1];
				v[right1] = tmp;
				left1++;
				right1--;
			}
		}
		if (left < right1) quickSort(v,left,right1);
		if (left1 < right) quickSort(v,left1,right);
	}		
}
	
#endif