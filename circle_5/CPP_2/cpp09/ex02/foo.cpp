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


void PmergeMe::insertion(int jnum) {
	std::cout << "Sorting status >> ";
	printResult();
	std::cout << std::endl;
	std::cout << "jnum:\t\t" << jnum << std::endl;

	static int originalJnum = -1;
	// static int increasedIndex;

	std::cout << "originalJnum:\t" << originalJnum << std::endl;

	// 제약: b의 숫자가 0보다 작을 경우 / 이전 jnum과 같을 경우 / b의 숫자가 pairs 인덱스를 넘어갈 경우
	if (jnum == 1 && originalJnum == -1) { // 초기 상태, b1을 맨 앞에 붙이기
		std::cout << "[[[\ttoInsert: " << pairs[0].second << "\t]]]" << std::endl;
		sortedVector.insert(sortedVector.begin(), pairs[0].second);
		// increasedIndex++;
		std::cout << std::endl;
	} else if (jnum > 1) { // 초기 상태가 아닌 경우, 삽입정렬 수행
		// toInsert값은 b(jnum)의 값
		int toInsert = pairs[jnum - 1].second;
		std::cout << "[[[\ttoInsert: " << toInsert << "\t]]]" << std::endl;

		std::vector<int>::iterator at = std::find(sortedVector.begin(), sortedVector.end(), pairs[jnum - 1].first);
		std::vector<int>::iterator it = sortedVector.begin();
		while (it != at && *it < toInsert) ++it;
		sortedVector.insert(it, toInsert);
		std::cout << std::endl;
	}
	// 재귀 들어가는 조건 : jnum - 1이 originalJnum보다 커야 하고, 0이상일 경우
	if (originalJnum != -1 && jnum - 1 >= 0 && jnum - 1 > originalJnum)
		insertion(jnum - 1);
	originalJnum = jnum; // 재귀가 풀리면서(돌아오면서) originalJnum도 줄어들음, 이부분 해결필요
	std::cout << "--------stop---------" << std::endl;
	// Jnum 업데이트 조건 : 업데이트된 Jnum이 pair사이즈보다 크면 jnum대신 pair사이즈로 업데이트해서 재귀
	// insertion(JacobsthalNumber());
}
