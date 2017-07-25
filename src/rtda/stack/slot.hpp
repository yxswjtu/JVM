#ifndef __SLOT_HPP_
#define __SLOT_HPP_

#include "../../common/global.hpp"
#include <vector>

namespace jvm{
	namespace rtda{		
			namespace heap{	
			class Object;
			typedef union slot{
				int32 num;
				float32 fnum;
				Object* ref;
			}slot;

			typedef union Long{
				int64 lnum;
				float64    dnum;
			}Long;
			
			class Slot{

			private:
				std::vector<slot> local_vars_;
			public:
				//in bytes
				Slot(int32 size);

				void SetInt(int32 index, int32 val);
				int32 GetInt(int32 index);

				void  SetFloat(int32 index, float32 val);
				float32 GetFloat(int32 index);

				void  SetLong(int32 index, int64 val);
				int64 GetLong(int32 index);

				void  SetDouble(int32 index, float64 val);
				float64 GetDouble(int32 index);

				void SetRef(int32 index, Object* ref);
				Object* GetRef(int32 index);

				void SetSlot(int32 index, slot lot);
				slot GetSlot(int32 index);
			};

		}
	}
}


#endif