#include "PmergeMe.hpp"

// 이해하기 쉽게 주석 빼고 정리 후 옮기는 노트

// PmergeMe.cpp:114
		// for (; at != sortedVector.begin(); --at) { // at는 a(jnum)의 위치
		// 	std::cout << "at : " << *at << std::endl;
		// 	if (*at < toInsert) {
		// 		sortedVector.insert(at + 1, toInsert);
		// 		// increasedIndex++;
		// 		break ;
		// 	}
		// }
		// if (at == sortedVector.begin()) {
		// 	std::cout << "point!" << std::endl;
		// 	if (*at < toInsert)
		// 		sortedVector.insert(sortedVector.begin() + 1, toInsert);
		// 	else
		// 		sortedVector.insert(sortedVector.begin(), toInsert);
		// 	// increasedIndex++;
		// }


// void PmergeMe::insertion(int jnum) {
// 	std::cout << "Sorting status >> ";
// 	printResult();
// 	std::cout << std::endl;
// 	std::cout << "jnum:\t\t" << jnum << std::endl;

// 	static int originalJnum = -1;
// 	// static int increasedIndex;

// 	std::cout << "originalJnum:\t" << originalJnum << std::endl;

// 	// 제약: b의 숫자가 0보다 작을 경우 / 이전 jnum과 같을 경우 / b의 숫자가 pairs 인덱스를 넘어갈 경우
// 	if (jnum == 1 && originalJnum == -1) { // 초기 상태, b1을 맨 앞에 붙이기
// 		std::cout << "[[[\ttoInsert: " << pairs[0].second << "\t]]]" << std::endl;
// 		sortedVector.insert(sortedVector.begin(), pairs[0].second);
// 		// increasedIndex++;
// 		std::cout << std::endl;
// 	} else if (jnum > 1) { // 초기 상태가 아닌 경우, 삽입정렬 수행
// 		// toInsert값은 b(jnum)의 값
// 		int toInsert = pairs[jnum - 1].second;
// 		std::cout << "[[[\ttoInsert: " << toInsert << "\t]]]" << std::endl;

// 		std::vector<int>::iterator at = std::find(sortedVector.begin(), sortedVector.end(), pairs[jnum - 1].first);
// 		std::vector<int>::iterator it = sortedVector.begin();
// 		while (it != at && *it < toInsert) ++it;
// 		sortedVector.insert(it, toInsert);
// 		std::cout << std::endl;
// 	}
// 	// 재귀 들어가는 조건 : jnum - 1이 originalJnum보다 커야 하고, 0이상일 경우
// 	if (originalJnum != -1 && jnum - 1 >= 0 && jnum - 1 > originalJnum)
// 		insertion(jnum - 1);
// 	originalJnum = jnum; // 재귀가 풀리면서(돌아오면서) originalJnum도 줄어들음, 이부분 해결필요
// 	std::cout << "--------stop---------" << std::endl;
// 	// Jnum 업데이트 조건 : 업데이트된 Jnum이 pair사이즈보다 크면 jnum대신 pair사이즈로 업데이트해서 재귀
// 	// insertion(JacobsthalNumber());
// }

void PmergeMe::insertionSortVector(int jnum) {
	static int originalJnum = -1;

	if (jnum == 1 && originalJnum == -1) {
		sortedVector.insert(sortedVector.begin(), pairsVector[0].second);
	} else if (jnum > 1) {
		int toInsert = pairsVector[jnum - 1].second;

		std::vector<int>::iterator at = std::find(sortedVector.begin(), sortedVector.end(), pairsVector[jnum - 1].first);
		std::vector<int>::iterator it = sortedVector.begin();
		while (it != at && *it < toInsert) ++it;
		sortedVector.insert(it, toInsert);
	}
	if (jnum - 1 > 1 && jnum - 1 > originalJnum)
		insertionSortVector(jnum - 1);
	originalJnum = jnum;
}

int PmergeMe::JacobsthalNumber(int containerType) {
	if (containerType == VEC) {
		static int v1;
		static int v2 = 1;
		int v3 = v2 + v1 * 2;
		v1 = v2;
		v2 = v3;
		return v3;
	} else if (containerType == DEQ) {
		static int d1;
		static int d2 = 1;
		int d3 = d2 + d1 * 2;
		d1 = d2;
		d2 = d3;
		return d3;
	} else throw std::runtime_error("Jacobsthal Number error: container type not specified");
}

void PmergeMe::MIsort(std::string& input) {
	try {
		initData(input);
		std::cout << "Vector input size:\t" << originalVector.size() << std::endl;
		std::cout << "Deque input size:\t" << originalDeque.size() << std::endl;
		std::cout << "pairsVector size:\t" << pairsVector.size() << std::endl;
		std::cout << "pairsDeque size:\t" << pairsDeque.size() << std::endl;
		// Vector sorting
		for (int i = JacobsthalNumber(VEC); static_cast<size_t>(i) <= pairsVector.size(); i = JacobsthalNumber(VEC)) {
			insertionSortVector(i);
		}
		if (originalVector.size() != sortedVector.size()) {
			insertionSortVector(pairsVector.size());
		}
		// Deque sorting
		for (int i = JacobsthalNumber(DEQ); static_cast<size_t>(i) <= pairsDeque.size(); i = JacobsthalNumber(DEQ)) {
			insertionSortDeque(i);
		}
		if (originalDeque.size() != sortedDeque.size()) {
			insertionSortDeque(pairsDeque.size());
		}
		std::cout << std::endl;
		printResult();
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}


/* Error case
./PmergeMe 79 13 38 42 39 22 94 33 80 6 94 27 84 8 35 32 65 3 51 74 96 55 29
79 13 38 42 39 22 94 33 80 6 94 27 84 8 35 32 65 3 51 74 96 55 29
Vector pairs:   [35, 32] [39, 22] [42, 38] [65, 3] [74, 51] [79, 13] [80, 6] [84, 8] [94, 27] [94, 33] [96, 55]
After Vector pairing:
        29 35 39 42 65 74 79 80 84 94 94 96
Deque pairs:    [35, 32] [39, 22] [42, 38] [65, 3] [74, 51] [79, 13] [80, 6] [84, 8] [94, 27] [94, 33] [96, 55]
After Deque pairing:
        29 35 39 42 65 74 79 80 84 94 94 96
Vector input size:      23
Deque input size:       23
pairsVector size:       11
pairsDeque size:        11
Sorting status >> 29 35 39 42 65 74 79 80 84 94 94 96

jnum:           1
originalJnum:   -1
[[[     toInsert: 32    ]]]

--------stop---------
Sorting status >> 32 29 35 39 42 65 74 79 80 84 94 94 96

jnum:           3
originalJnum:   1
[[[     toInsert: 38    ]]]
Sorting status >> 32 29 35 38 39 42 65 74 79 80 84 94 94 96

jnum:           2
originalJnum:   1
[[[     toInsert: 22    ]]]
--------stop---------
--------stop---------
Sorting status >> 22 32 29 35 38 39 42 65 74 79 80 84 94 94 96

jnum:           5
originalJnum:   3
[[[     toInsert: 51    ]]]
Sorting status >> 22 32 29 35 38 39 42 51 65 74 79 80 84 94 94 96

jnum:           4
originalJnum:   3
[[[     toInsert: 3     ]]]
--------stop---------
--------stop---------
Sorting status >> 3 22 32 29 35 38 39 42 51 65 74 79 80 84 94 94 96

jnum:           11
originalJnum:   5
[[[     toInsert: 55    ]]]
Sorting status >> 3 22 32 29 35 38 39 42 51 55 65 74 79 80 84 94 94 96

jnum:           10
originalJnum:   5
[[[     toInsert: 33    ]]]
Sorting status >> 3 22 32 29 33 35 38 39 42 51 55 65 74 79 80 84 94 94 96

jnum:           9
originalJnum:   5
[[[     toInsert: 27    ]]]
Sorting status >> 3 22 27 32 29 33 35 38 39 42 51 55 65 74 79 80 84 94 94 96

jnum:           8
originalJnum:   5
[[[     toInsert: 8     ]]]
Sorting status >> 3 8 22 27 32 29 33 35 38 39 42 51 55 65 74 79 80 84 94 94 96

jnum:           7
originalJnum:   5
[[[     toInsert: 6     ]]]
Sorting status >> 3 6 8 22 27 32 29 33 35 38 39 42 51 55 65 74 79 80 84 94 94 96

jnum:           6
originalJnum:   5
[[[     toInsert: 13    ]]]
--------stop---------
--------stop---------
--------stop---------
--------stop---------
--------stop---------
--------stop---------

Vector result>
3 6 8 13 22 27 32 29 33 35 38 39 42 51 55 65 74 79 80 84 94 94 96
Deque result>
3 6 8 13 22 27 32 29 33 35 38 39 42 51 55 65 74 79 80 84 94 94 96
Error: Sorting error: failed to sort
*/

/*
출력결과 형식
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
*/
