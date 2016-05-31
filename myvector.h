#ifndef MYVECTOR_H
#define MYVECTOR_H

typedef int Rank;

#define DEFAULT_CAPACITY 3

template <typename T> class myvector{
private:
    T* _elem;
    int _size;
    int _capacity;

protected:
    int copyFrom(const T* V, int lo, int hi);
    //expand and shrank
    void expand();
public:

    //constructor
    myvector(unsigned int c = DEFAULT_CAPACITY, int s = 0, const T& e = 0);
    myvector(myvector<T> const &v, Rank lo, Rank hi);
    myvector(myvector<T> const &v);

    //destructor
    ~myvector();


    //insertion
    Rank insert(Rank r, const T& e);
    Rank push_back(const T& e);

    //remove
    T remove(Rank r);
    int remove(Rank lo, Rank hi);

    //visit
    T& operator[](Rank r) const;

    //get size and capacity
    int size(){return _size;};
    int capacity(){return _capacity;};
};


template <typename T>
int myvector<T>::copyFrom(const T* V, int lo, int hi){
    _elem = new T[_capacity = (hi - lo)*2];
    _size = 0;
    while(lo < hi)
        _elem[_size++] = V[lo];
}

template <typename T>
myvector<T>::myvector(unsigned int c, int s, const T& e){
    _elem = new T[ _capacity = c];
    _size = 0;
    while(_size < s) _elem[_size++] = e;
}

template <typename T>
myvector<T>::myvector(myvector<T> const& V){
    copyFrom(V._elem, 0, V._size);
}

template <typename T>
myvector<T>::myvector(myvector<T> const& V, Rank lo, Rank hi){
    copyFrom(V._elem, lo, hi);
}


//destructor
template <typename T>
myvector<T>::~myvector(){
     delete _elem;
}
template <typename T>
Rank myvector<T>::insert(Rank r, const T& e){
    expand();
    Rank i;
    for(i = _size; i > r; i--) _elem[i] = _elem[i - 1];
    _elem[i] = e;
    _size++;
    return i;
}

template <typename T>
Rank myvector<T>::push_back(const T& e){
    insert(_size, e);
}


template <typename T>
int myvector<T>::remove(Rank lo, Rank hi){
    if(lo > hi)  return 0;
    if(hi > _size) hi = _size;
    while(hi < _size) _elem[lo++] = _elem[hi++];
    _size -= (hi -lo);
    return hi-lo;
}

template <typename T>
T myvector<T>::remove(Rank r){
    T temp = _elem[r];
    remove(r,r+1);
}


template <typename T>
void myvector<T>::expand(){
    if(_size < _capacity) return;
    T* temp_elem = _elem;
    _capacity*=2;
    _elem =  new T[_capacity];
    for(int i=0; i<_size; i++)
        _elem[i] =  temp_elem[i];
    delete temp_elem;
}


template <typename T>
T& myvector<T>::operator[](Rank r) const{
     return _elem[r];
}

#endif
