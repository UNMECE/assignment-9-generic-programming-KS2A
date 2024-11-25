#include <stdio.h>

template <typename T = int>

class xArray {
protected:
	int xsize;
	T* xarray;
public:
	xArray() : xsize(0), xarray(nullptr) {}

	~xArray() {
		delete[] xarray;
	}

	void addElement(T ex) {
		T* sizet = new T[xsize + 1];
		for (int i = 0; i < xsize; i++) {
			sizet[i] = xarray[i];
		}
		sizet[xsize] = ex;
		delete[] xarray;
		xarray = sizet;
		xsize++;
	}

	T at(int a) {
		return xarray[a];
	}

	int size() {
		return xsize;
	}

	T sum() {
        T xsum = 0;
        for (int i = 0; i < xsize; i++) {
            xsum += xarray[i];
        }
        return xsum;
	}

	T max() {
        T max = xarray[0];
        for (int i = 0; i < xsize; i++) {
            if (xarray[i] > max) {
                max = xarray[i];
            }
        }
        return max;
	}

	T min() {
        T min = xarray[0];
        for (int i = 0; i < xsize; i++) {
            if (xarray[i] < min) {
                min = xarray[i];
            }
        }
        return min;
	}

	xArray<T>* slice(int begin, int end) {
	    int ssize = end - begin;
	    xArray<T>* xarrslice = new xArray<T>();
	    xarrslice->xsize = ssize;
	    xarrslice->xarray = new T[ssize];
	    for (int i = 0; i < ssize; i++) {
	        xarrslice->xarray[i] = xarray[begin + i];
	    }
	    return xarrslice;
	}
};

int main() {
    xArray <int> arr;
    arr.addElement(2);
    arr.addElement(4);
    arr.addElement(6);
    arr.addElement(8);
    
    printf("Size: %d\n", arr.size());
    printf("Sum: %d\n", arr.sum());
    printf("Max: %d\n", arr.max());
    printf("Min: %d\n", arr.min());
    
    xArray<int>* arrslice = arr.slice(1, 3);
    printf("Sliced: ");
    for (int i = 0; i < arrslice->size(); i++) {
        printf("%d ", arrslice->at(i));
    }
    delete arrslice;

	return 0;
}
