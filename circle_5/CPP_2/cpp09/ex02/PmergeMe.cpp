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
	// 홀수인 경우 빼두기
	int tmp = -1;
	if (originalVector.size() % 2 != 0) {
		tmp = originalVector[originalVector.size() - 1];
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

	// 빼둔 끝수가 있는 경우 끝수만 삽입정렬
	if (tmp != -1) {
		std::vector<int>::iterator it = sortedVector.begin();

		while (it != sortedVector.end() && *it < tmp) ++it;
		sortedVector.insert(it, tmp);
	}
}

void PmergeMe::insertion(int jnum) {
	static int originalJnum = -1;

	if (jnum == 1 && originalJnum == -1) { // 초기 상태, b1을 맨 앞에 붙이기
		sortedVector.insert(sortedVector.begin(), pairs[0].second);
	} else if (jnum > 1) {
		int toInsert = pairs[jnum - 1].second;

		std::vector<int>::iterator at = std::find(sortedVector.begin(), sortedVector.end(), pairs[jnum - 1].first);
		std::vector<int>::iterator it = sortedVector.begin();
		while (it != at && *it < toInsert) ++it;
		sortedVector.insert(it, toInsert);
	}
	if (jnum - 1 >= 0 && jnum - 1 > originalJnum)
		insertion(jnum - 1);
	originalJnum = jnum;
}

int PmergeMe::JacobsthalNumber() {
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
		for (int i = JacobsthalNumber(); static_cast<size_t>(i) <= pairs.size(); i = JacobsthalNumber()) {
			insertion(i);
		}
		if (originalVector.size() != sortedVector.size()) {
			insertion(pairs.size());
		}
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

/////////////////////////////////Tester: ./PmergeMe 3 12 2 10 6 11 8 0 1 7 9 4 5 14 13
