#ifndef DATA_HPP
#define DATA_HPP

class Data {
	private:
		int data;
	public:
		Data();
		Data(const Data& a);
		Data& operator= (const Data& a);
		virtual ~Data();
		int getData() const;
};

#endif
