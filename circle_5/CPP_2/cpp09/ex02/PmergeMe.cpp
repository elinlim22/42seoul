#include "PmergeMe.hpp"

/* -------------------------------------------------------------------------- */
/*                                    OCCF                                    */
/* -------------------------------------------------------------------------- */
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& a) {
	*this = a;
}

PmergeMe& PmergeMe::operator= (const PmergeMe& a) {
	if (this != &a) {
		originalVector = a.originalVector;
		sortedVector = a.sortedVector;
		originalDeque = a.originalDeque;
		sortedDeque = a.sortedDeque;
	} return *this;
}

PmergeMe::~PmergeMe() {
	// delete 있을수도
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
void PmergeMe::initData(std::string& input) {
	std::istringstream iss(input);
	std::string token;
	while (std::getline(iss, token, ' ')) {
		try {
			int i = std::stoi(token);
			if (i >= 0) {
				originalVector.push_back(i);
				originalDeque.push_back(i);
			} else {
				throw std::runtime_error("Parsing error: Negative integer value found");
			}
		} catch (const std::invalid_argument& e) {
			throw std::runtime_error("Parsing error: Non-integer value found");
		}
	}
	doubling();
}

void PmergeMe::doubling() {
	// 홀수인 경우 -1추가 -> 나중에 제거 필요
	if (originalVector.size() % 2 != 0 && originalDeque.size() % 2 != 0) {
		originalVector.push_back(-1);
	}

	// pair로 묶음
	// std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < originalVector.size() - 1; i += 2) {
		pairs.push_back(std::make_pair(originalVector[i], originalVector[i + 1]));
	}

	// 앞쪽에 큰 값으로 정렬(내부)
	for (size_t i = 0; i < originalVector.size(); ++i) {
		if (pairs[i].first < pairs[i].second) {
			std::swap(pairs[i].first, pairs[i].second);
		}
	}

	// 앞을 기준으로 정렬(외부)
	std::sort(pairs.begin(), pairs.end()); // std::sort 말고 merge sort 만들어서 사용

	// 출력 및 sortedvector에 그대로 넣기
	for (size_t i = 0; i < pairs.size(); i++) {
		std::cout << "[" << pairs[i].first << ", " << pairs[i].second << "] ";
		sortedVector.push_back(pairs[i].first);
		// sortedVector.push_back(pairs[i].second);
	} std::cout << std::endl;

	// sortedVector 출력
	// for (size_t i = 0; i < sortedVector.size(); i++) {
	// 	std::cout << sortedVector[i] << " ";
	// } std::cout << std::endl;
}

// void PmergeMe::insertion(int prevJnum) {
// 	std::cout << "prevJnum: " << prevJnum << std::endl;
// 	static int increasedIndex; //?
// 	int startJnumIndex = prevJnum * 2 - 1 + increasedIndex; // jnum = 1, 3, 5, 11, 21, 43, 85, 171 ...
// 	// int endJnum = prevJnum * 2 - 1;
// 	static int originalJnum;
// 	std::cout << originalJnum << std::endl;
// 	std::cout << "start index: " << startJnumIndex << std::endl;
// 	if (startJnumIndex < 0 || prevJnum == originalJnum || static_cast<size_t>(startJnumIndex) >= sortedVector.size()) return ;

// 	// 여기서부터 삽입정렬, jnum(*2-1)인덱스의 원소를 찾아 맨앞까지 돌며(i+=2?) 값 비교 (재귀, prevjnum에 넘겨주기)

// 	// if (originalJnum == prevJnum) return ;
// 	std::vector<int>::iterator it = sortedVector.begin() + startJnumIndex;
// 	sortedVector.erase(it);

// 	for (int i = startJnumIndex; i > 0; i--) {
// 		std::cout << "checking... " << "sortedVector[" << i - 1 << "], " << it - sortedVector.begin() + 1 << std::endl;
// 		if (sortedVector[i - 1] > *it) { // Swap
// 			std::swap(sortedVector[i - 1], *it);
// 		}
// 	}
// 	std::cout << "----------------" << std::endl;
// 	insertion(prevJnum - 1);
// 	std::cout << "----------------\n----------------" << std::endl;
// 	originalJnum = prevJnum;
// 	std::cout << originalJnum << std::endl;
// 	int j = JacobsthalNumber();
// 	std::cout << "jacob: " << j << std::endl;
// 	insertion(j);
// }

void PmergeMe::insertion(int jnum) {
	std::cout << "Sorting status >> ";
	printResult();
	std::cout << std::endl;
	std::cout << "jnum:\t\t" << jnum << std::endl;

	static int originalJnum = -1;
	static int increasedIndex;

	std::cout << "originalJnum:\t" << originalJnum << std::endl;

	// 제약: b의 숫자가 0보다 작을 경우 / 이전 jnum과 같을 경우 / b의 숫자가 pairs 인덱스를 넘어갈 경우
	if (jnum < 0 || jnum == originalJnum || static_cast<size_t>(jnum) > pairs.size()) return ;
	if (jnum == 1) { // 초기 상태, b1을 맨 앞에 붙이기
		sortedVector.insert(sortedVector.begin(), pairs[0].second);
		increasedIndex++;
		std::cout << "---------------------" << std::endl;
	} else {

		// toInsert값은 b(jnum)의 값
		int toInsert = pairs[jnum - 1].second;
		std::cout << "[[[\ttoInsert: " << toInsert << "\t]]]" << std::endl;

		std::vector<int>::iterator at = std::find(sortedVector.begin(), sortedVector.end(), pairs[jnum - 1].first);
		for (; at != sortedVector.begin(); --at) { // at는 a(jnum)의 위치
			if (*at >= toInsert) {
				sortedVector.insert(at, toInsert);
				break ;
			}
		}
		if (*at < toInsert) {
			sortedVector.insert(sortedVector.begin() + jnum + increasedIndex, toInsert);
			increasedIndex++;
		}
		std::cout << "---------------------" << std::endl;
	}
	if (!(jnum - 1 < 0 || jnum - 1 == originalJnum || static_cast<size_t>(jnum - 1) > pairs.size()))
		insertion(jnum - 1);
	originalJnum = jnum + 1; // Jnum이 업데이트가 안된다... 왜?
	std::cout << "---------------------" << std::endl;
	std::cout << "---------------------" << std::endl;
	insertion(JacobsthalNumber());
}

/////////////////////////////////Tester: ./PmergeMe 3 2 6 8 0 1 7 9 4 5

int PmergeMe::JacobsthalNumber() { // 한번 1 뽑아내고나서 3부터 사용해야 함..
	static int i1;
	static int i2 = 1;
	int i3 = i2 + i1 * 2;
	i1 = i2;
	i2 = i3;
	return i3;
}

void PmergeMe::MIsort(std::string& input) {
	try {
		initData(input);
		std::cout << "pairs.size() :\t" << pairs.size() << std::endl << std::endl;
		insertion(JacobsthalNumber());
		std::cout << "\n\n\n";
		printResult();
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void PmergeMe::printResult() {
	for (size_t i = 0; i < sortedVector.size(); i++) {
		std::cout << sortedVector[i] << " ";
	} std::cout << std::endl;
}
