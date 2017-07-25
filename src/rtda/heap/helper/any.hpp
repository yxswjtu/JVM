#ifndef __ANY_HPP_
#define __ANY_HPP_

#include <stdio.h>

namespace jvm{
	namespace rtda{
		namespace heap{
			class PlaceHolder{
			public:
				virtual ~PlaceHolder(){}
				virtual PlaceHolder* clone(){ return NULL; }
			};

			template<typename ValueType>
			class Holder :public PlaceHolder{
			public:
				Holder(const ValueType& value) :holder_(value){}
				PlaceHolder* clone(){
					return new Holder(holder_);
				}
				ValueType holder_;
			};

			class Any{
			private:
				PlaceHolder* content_;
			public:
				template<typename ValueType>
				Any(const ValueType& value){
					content_ = new Holder<ValueType>(value);
				}

				Any() :content_(NULL) {}

				Any(const Any& other){
					if (other.content_){
						content_ = other.content_->clone();
					}
					else{
						content_ = NULL;
					}
				}

				template<typename ValueType>
				ValueType any_cast(){
					if (content_ == NULL){
						return NULL;
					}
					return static_cast<Holder<ValueType> *>(content_)->holder_;
				}

				~Any(){
					delete content_;
				}
			};
		}
	}
}

#endif