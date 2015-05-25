#ifndef MTYPEMAP_HPP
#define MTYPEMAP_HPP

#include <string>
#include <unordered_map>

	template<class T> void delfunct(void* p){
		delete (T*)p;
	}

	class randomDataStore{ //modified unsorted map
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
		std::unordered_map<std::string, voidndel> data;

		public:

		template<class T> void set(std::string key, T variable){ //careful, setting a differet type may be harmful!
			auto foundIter = data.find(key); //returns data.end() if not found, else returns iterator to element
			if(foundIter != data.end()){ //variable exists
				*((T*)data.at(key).ptr) = variable;

			} else {
				T* stored = new T;
				*stored = variable;
				data[key].ptr = (void*) stored;
				data[key].del = &delfunct<T>;
			}
		}

		template<class T> T& get(std::string key){
			return  *(T*)(data.at(key).ptr); //data.at() throws if key doesnt exist
		}

		bool is_set(std::string key){
			auto foundIter = data.find(key);
			if(foundIter != data.end()){
				return true;
			} else {
				return false;
			}
		}

		void remove(std::string key){
			auto foundIter = data.find(key);
			if(foundIter != data.end()){
				data.erase(key);
			}
		}
	};

}

#endif
