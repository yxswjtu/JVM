#ifndef __MEMORY_MANAGER_HPP_
#define __MEMORY_MANAGER_HPP_

#include "../heap/object.hpp"
#include "space.hpp"
#include <vector>

class Memory{

private:
	Space* _from_space;
	Space* _to_space;

	void swap_spaces();
	Object* evacuate(Object* obj);
	void copy(char* to, Object* from, size_t size);
public:
	Memory(char* bottom, char* end);

	char* allocate(size_t size);
	void collect();
	void process_reference(Object** slot);
};

#endif