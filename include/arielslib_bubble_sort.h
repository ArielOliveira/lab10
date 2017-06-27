#ifndef ARIELSLIB_BUBBLE_SORT_H
#define ARIELSLIB_BUBBLE_SORT_H

namespace {

    template<typename T>
    void bubbleSort(T *v, int n) {
    	int k = n;
    	int j;
    	bool swap;
    	T tmp;
 		j = k - 2;

    	do {
    		swap = false;
    		for(int i = 0; i <= j; ++i)	{
	    		if(v[i] > v[i + 1]) {
	    			tmp = v[i];
	    			v[i] = v[i + 1];
	    			v[i + 1] = tmp;

	    			swap = true;
	    		}
	    	}
    		j--;
    	} while(swap);
    }
}

#endif