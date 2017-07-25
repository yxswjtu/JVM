#ifndef __SPACE_HPP_
#define __SPACE_HPP_


class Space {
	char* bottom_;
	char* top_;
	char* end_;

public:
	Space(char* bottom, char* end);

	char* bottom() { return bottom_; }
	char* top()    { return top_; }
	char* end()    { return end_; }

	bool contains(char* obj);
	char* allocate(size_t size);
	void reset();
};


#endif