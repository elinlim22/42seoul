#include <iostream>
#include <string>

class Date {
	private :
		int year_;
		int month_;
		int day_;

	public :
		void SetDate(int year, int month, int date) {
			year_ = year;
			month_ = month;
			day_ = date;
		};
		void AddYear(int inc) {
			year_ += inc;
		};
		void AddMonth(int inc) {
			if (12 - month_ >= inc) {
				month_ += inc;
			} else {
				month_ += (inc - 12);
				year_++;
			}
		};
		void AddDay(int inc) {
			int max = 31;
			if (month_ == 2) {
				max = 28;
			} else if (month_ % 2) {
				max = 30;
			}
			if (max - day_ >= inc) {
				day_ += inc;
			} else {
				day_ += (inc - max);
				month_++;
			}
		};

		void ShowDate() {
			std::cout << "Year : " << year_ << std::endl;
			std::cout << "Month : " << month_ << std::endl;
			std::cout << "Date : " << day_ << std::endl;
		};
};

int main() {
	class Date date;

	date.SetDate(2023, 4, 4);
	date.AddYear(3);
	date.AddMonth(9);
	date.AddDay(30);

	date.ShowDate();
	return 0;
}
