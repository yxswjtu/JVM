#include "space.hpp"
#include <stdio.h>

Space::Space(char* bottom, char* end) {
	bottom_ = bottom;
	top_ = bottom;
	end_ = end;
}

bool Space::contains(char* obj) {
	return bottom_ <= obj && obj < top_;
}

char* Space::allocate(size_t size) {

	char* obj = NULL;

	if (top_ + size <= end_) {
		obj = top_;
		top_ += size;
	}	

	return obj;	
}

void Space::reset() {
	top_ = bottom_;
}