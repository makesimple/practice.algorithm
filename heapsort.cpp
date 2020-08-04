void max_heapify(std::vector<int> &A, int i) {
	int left = i << 1;
	int right = (i << 1) + 1;
	int biggest = i;
	if (left < A[0] && A[i] < A[left])
		biggest = left;
	if (right < A[0] && A[right] > A[biggest])
		biggest = right;
	if (i != biggest) {
		std::swap(A[biggest], A[i]);
		max_heapify(A, biggest);
	}
};

void build_max_heap(std::vector<int> &A) {
	int size = A.size() / 2;
	for (int i = size; i >= 1; i--) {
		max_heapify(A, i);
	}
}

void heapsort(std::vector<int> &A) {
	build_max_heap(A);
	int size = A.size() - 1;
	for (int i = size; i >= 2; i--) {
		std::swap(A[i], A[1]);
		A[0]--;
		max_heapify(A, 1);
	}
};


int main()
{
	std::vector<int> arr = { 0,1,3,5,0,113,2,7,11 };
	arr[0] = arr.size();
	heapsort(arr);
	return 0;
}
