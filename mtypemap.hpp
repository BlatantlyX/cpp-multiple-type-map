#ifndef MTYPEMAP_HPP
#define MTYPEMAP_HPP

#include <unordered_map>

namespace bx{
	template<class VarType> void delfunct(void* p){
		delete reinterpret_cast<VarType*>(p);
	}

	template<class KeyType> class mtypemap{ //modified unsorted map
		private:
		struct voidndel{//void ptr and delete function
			void* ptr;
			void (*del)(void*);
			~voidndel(){
				del(ptr);
				ptr = 0;
				del = 0;
			}
		};
		std::unordered_map<KeyType, voidndel> data;

		public:

		template<class VarType> void set(KeyType key, VarType variable){
			auto foundIter = data.find(key); //returns data.end() if not found, else returns iterator to element
			if(foundIter != data.end()){ //variable exists
				*reinterpret_cast<VarType*>(data.at(key).ptr) = variable;

			} else {
				VarType* stored = new VarType;
				*stored = variable;
				data[key].ptr = reinterpret_cast<void*>(stored);
				data[key].del = &delfunct<VarType>;
			}
		}

		template<class VarType> VarType& get(KeyType key){
			return  *reinterpret_cast<VarType*>(data.at(key).ptr); //data.at() throws if key doesnt exist
		}

		bool is_set(KeyType key){
			auto foundIter = data.find(key);
			if(foundIter != data.end()){
				return true;
			} else {
				return false;
			}
		}

		void remove(KeyType key){
			auto foundIter = data.find(key);
			if(foundIter != data.end()){
				data.erase(key);
			}
		}
	};
}

#endif
