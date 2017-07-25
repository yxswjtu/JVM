#include "memory.hpp"


// Initialize the heap. Assuming contiguous address space
Memory::Memory(char* bottom, char* end) {
	size_t space_size = (end - bottom) / 2;
	char* boundary = bottom + space_size;
	_from_space = new Space(bottom, boundary);
	_to_space = new Space(boundary, end);
}

void Memory::swap_spaces() {
	// std:swap(_from_space, _to_space);
	Space* temp = _from_space;
	_from_space = _to_space;
	_to_space = temp;
	// After swapping, the to-space is assumed to be empty.
	// Reset its allocation pointer.
	_to_space->reset();
}

char*  Memory::allocate(size_t size) {
	return _from_space->allocate(size);
}

void Memory::copy(char* to, Object* from, size_t size){

}

Object* Memory::evacuate(Object* obj) {
	size_t size = obj->size();

	// allocate space in to_space and copy object to there
	char* new_addr = _to_space->allocate(size);
	copy(/* to */ new_addr, /* from */ obj, size);

	// set forwarding pointer in old object
	Object* new_obj = (Object*)new_addr;
	obj->forward_to(new_obj);

	return new_obj;
}
