#include "clase_member.hpp"
#include "clase.hpp"


using namespace jvm::rtda::heap;

void ClaseMember::copyMemberInfo(jvm::classfile::MemberInfo* memberinfo){
	access_flags_ = memberinfo->getAccessFlags();
	name_ = memberinfo->getName();
	descriptor_ = memberinfo->getDescriptor();
}

bool ClaseMember::IsPublic(){
	return (0 != (access_flags_ &  ACC_PUBLIC));
}

bool ClaseMember::IsPrivate(){
	return (0 != (access_flags_ &  ACC_PRIVATE));
}

bool ClaseMember::IsProtected(){
	return (0 != (access_flags_ &  ACC_PROTECTED));
}

bool ClaseMember::IsStatic(){
	return (0 != (access_flags_ &  ACC_STATIC));
}

bool ClaseMember::IsFinal(){
	return (0 != (access_flags_ &  ACC_FINAL));
}

bool  ClaseMember::IsSynthetic(){
	return (0 != (access_flags_ &  ACC_SYNTHETIC));
}

std::string ClaseMember::getName(){
	return name_;
}
std::string ClaseMember::getDescriptor(){
	return descriptor_;
}

Clase* ClaseMember::getClase(){
	return clase_;
}

uint16 ClaseMember::getAccessFlags(){
	return access_flags_;
}

void ClaseMember::setClase(Clase* clase){
	clase_ = clase;
}


bool ClaseMember::isAccessibleTo(Clase* d){
	if (d->IsPublic()){
		return true;
	}

	Clase* c = clase_;
	if (IsProtected()){
		if ((c == d) || (d->IsSubClassOf(c)) ||(c->getPackageName() == d->getPackageName())){
			return true;
		}
	}

	if (!IsPrivate()){
		return c->getPackageName() == d->getPackageName();
	}

	return d == c;
}