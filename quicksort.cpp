#include <iostream>
#include <vector>
int partition(std::vector<int> &vec, int p, int r) {
        int pivot = vec[r];
        int i = p;
	// [i, j - 1] is greater set,the left of the set is the less number, 
	// the right of the set is unordered number,the last one is the pivot number
	// at last, swap (the left border of the set vec[i], privot number)
	// and return the i
        for (int j = p; j < r; j++) {
                if (vec[j] < x) {
                    std::swap(vec[i], vec[j]);
		    i++;
                }
        }
	std::swap(vec[i], vec[r]);
        return i;
}

void quicksort(std::vector<int> &vec, int p, int r) {
	if (p < r) {
		int q = partition(vec, p, r);
		quicksort(vec, p, q - 1);
		quicksort(vec, q + 1, r);
	}
}

int main() {
std::vector<int> vec {1, 0};
quicksort(vec, 0, vec.size() - 1);
for (auto i : vec)
	std::cout<<i<<std::endl;
return 0;
}



