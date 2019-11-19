#include <iostream>
#include <vector>
#if 0
int partition(std::vector<int> &vec, int p, int r) {
        int x = vec[r];
        int i = p - 1;
        // next i is alway geater than x
        // i to j is geater number,p to i is less number
        // j to r - 1 is uncompared number
        for (int j = p; j < r; j++) {
                if (vec[j] < x) {
                        i++;
                        std::swap(vec[i], vec[j]);

                }
        }
	std::swap(vec[i + 1], vec[j]);
        return i + 1;
}
#endif

int partition(std::vector<int> &vec, int p, int r) {
	int x = vec[r];
	int i = p - 1;
	// next i is alway geater than x
	// i to j is geater number,p to i is less number
	// j to r - 1 is uncompared number
	for (int j = p; j <= r; j++) {
		if (vec[j] <= x) {
			i++;
			std::swap(vec[i], vec[j]);

		}
	}
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



