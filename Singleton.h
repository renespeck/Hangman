#ifndef Singleton_I2abdb221m12355049952mm400b_H
#define Singleton_I2abdb221m12355049952mm400b_H
//!  a singleton pattern 
template <class T>
class Singleton{

public:
	virtual ~Singleton(){ 	}
	inline static T* instance(){
		if (!t)
			t = new T;
		return t;
	}	
	static void deleteInstance(){
		delete t;
		t = 0;
	}

protected:
    Singleton() { }

private:
	static T *t;
};
template <class T>
T *Singleton<T>::t = 0;
#endif //Singleton_I2abdb221m12355049952mm400b_H
