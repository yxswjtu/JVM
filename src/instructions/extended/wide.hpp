#ifndef __WIDE_HPP_
#define __WIDE_HPP_

#include "../loads/aload.hpp"
#include "../loads/fload.hpp"
#include "../loads/iload.hpp"
#include "../loads/dload.hpp"
#include "../loads/lload.hpp"
#include "../stores/astore.hpp"
#include "../stores/istore.hpp"
#include "../stores/dstore.hpp"
#include "../stores/fstore.hpp"
#include "../stores/lstore.hpp"
#include "../math/iinc.hpp"

#include <iostream>

namespace jvm{
	namespace instruction{
		class WIDE :public Instruction{
		private:
			Instruction * inst_;
		public:
			void FetchOperands(BytecodeReader* reader){
				uint8 opcode = reader->ReadUint8();

				switch (opcode){
				case 0x15:{
							  ILOAD* ins1 = new ILOAD();
							  ins1->setIndex(reader->ReadUint16());
							  inst_ = (Instruction *)ins1;
							  break;
				}
				case 0x16:{
							  LLOAD* ins2 = new LLOAD();
							  ins2->setIndex(reader->ReadUint16());
							  inst_ = ins2;
							  break;
				}
				case 0x17:{
							  FLOAD* ins3 = new FLOAD();
							  ins3->setIndex(reader->ReadUint16());
							  inst_ = ins3;
							  break;
				}

				case 0x18:{
							  DLOAD* ins4 = new DLOAD();
							  ins4->setIndex(reader->ReadUint16());
							  inst_ = ins4;
							  break;
				}

				case 0x19:{
							  ALOAD* ins5 = new ALOAD();
							  ins5->setIndex(reader->ReadUint16());
							  inst_ = ins5;
							  break;
				}

				case 0x36:{
							  ISTORE* ins6 = new ISTORE();
							  ins6->setIndex(reader->ReadUint16());
							  inst_ = ins6;
							  break;
				}

				case 0x37:{
							  LSTORE* ins7 = new LSTORE();
							  ins7->setIndex(reader->ReadUint16());
							  inst_ = ins7;
							  break;
				}

				case 0x38:{
							  FSTORE* ins8 = new FSTORE();
							  ins8->setIndex(reader->ReadUint16());
							  inst_ = ins8;
							  break;
				}

				case 0x39:{
							  DSTORE* ins9 = new DSTORE();
							  ins9->setIndex(reader->ReadUint16());
							  inst_ = ins9;
							  break;
				}

				case 0x3a:{
							  ASTORE* ins_10 = new ASTORE();
							  ins_10->setIndex(reader->ReadUint16());
							  inst_ = ins_10;
							  break;
				}

				case 0x84:{
							  IINC* ins_11 = new IINC();
							  ins_11->setIndex(reader->ReadUint16());
							  ins_11->setConst(reader->ReadInt16());
							  inst_ = ins_11;
							  break;
				}

				case 0xa9:
					std::cout << "Unsupported opcode: 0xa9!" << std::endl;
					break;
				}
			}

			void Execute(Frame* frame){
				inst_->Execute(frame);
			}
		};

	}
}


#endif