#ifndef STACKRAW
#define STACKRAW

#include <cstddef>
#include <stdexcept>
#include <utility>
using namespace std;
template<typename T>
class StackRaw {
private:
  T *data_ = nullptr;
  std::size_t size_ = 0;
  std::size_t capacity_ = 0;

  void grow();

public:
  StackRaw() = default;
  StackRaw(const StackRaw &other);
  StackRaw(StackRaw &&other) noexcept;
  StackRaw &operator=(const StackRaw &other);
  StackRaw &operator=(StackRaw &&other) noexcept;
  ~StackRaw();

  void push(const T &x);
  void push(T &&x);
  void pop();

  T &top();
  const T &top() const;

  bool empty() const noexcept { return size_ == 0; }
  std::size_t size() const noexcept { return size_; }
  std::size_t capacity() const noexcept { return capacity_; }
};

// Restricción didáctica: T debe ser construible por defecto y asignable.
// No se permite usar std::vector dentro de esta clase.

template<typename T>
void StackRaw<T>::grow() {
	size_t new_capacity=0;
	if (capacity_==0)
		new_capacity=1;
	else{new_capacity=capacity_*2};
	T* new_data=new T[new_capacity];
	for(size_t i=0;i<size_;i++)
		new_data[i]=data_[i];
	delete[] data_;
	data_=new_data;
	capacity_=new_capacity;}
	
}

template<typename T>
StackRaw<T>::StackRaw(const StackRaw &other):data_(nullptr),size_(other.size_),capacity_(other.capacity_) {
if(capacity_>0){
	data_=new T[capacity_];
	for(size_t i=0;i<capacity_;i++){
		data_[i]=other.data_[i];}
}}

template<typename T>
StackRaw<T>::StackRaw(StackRaw &&other) noexcept: data_(other.data_),size_(other.size_),capacity_(other.capacity_){
other.data_=nullptr;
other.size_=0;
other.capacity_=0;}

template<typename T>
StackRaw<T> &StackRaw<T>::operator=(const StackRaw &other) {
    if(this!=&other){
	T* new_data_=nullptr;
	if(other.capacity_>0){
		new_data_=new T[other.capacity_];
		for(size_t i=0;i<other.size_;i++)
			new_data_[i]=other.data_[i];
	delete[] data_;
	}
	data_=new_data_;
	size_=other.size_;
	capacity_=other.capacity_;}


        return *this;
}

template<typename T>
StackRaw<T> &StackRaw<T>::operator=(StackRaw &&other) noexcept {
  if(this!=&other){
          this.data_=move(other.data_);
          this.size_=move(other.size_);
          this.capacity_=move(other.capacity);}
  return *this; 
	
}

template<typename T>
StackRaw<T>::~StackRaw() {
  delete[] data_;
}

template<typename T>
void StackRaw<T>::push(const T &) {
  throw std::logic_error("TODO StackRaw::push(const T&)");
}

template<typename T>
void StackRaw<T>::push(T &&) {
  throw std::logic_error("TODO StackRaw::push(T&&)");
}

template<typename T>
void StackRaw<T>::pop() {
  throw std::logic_error("TODO StackRaw::pop");
}

template<typename T>
T &StackRaw<T>::top() {
  throw std::logic_error("TODO StackRaw::top");
}

template<typename T>
const T &StackRaw<T>::top() const {
  throw std::logic_error("TODO StackRaw::top const");
}
#endif
