#ifndef QUEUESHIFT
#define QUEUESHIFT

#include <cstddef>
#include <stdexcept>
#include <utility>

template<typename T>
class QueueShift {
private:
  T *data_ = nullptr;
  std::size_t size_ = 0;
  std::size_t capacity_ = 0;
  std::size_t moves_ = 0;

  void grow();

public:
  QueueShift() = default;
  QueueShift(const QueueShift &other);
  QueueShift(QueueShift &&other) noexcept;
  QueueShift &operator=(const QueueShift &other);
  QueueShift &operator=(QueueShift &&other) noexcept;
  ~QueueShift();

  void push(const T &x);
  void push(T &&x);
  void pop();

  T &front();
  const T &front() const;

  bool empty() const noexcept { return size_ == 0; }
  std::size_t size() const noexcept { return size_; }
  std::size_t capacity() const noexcept { return capacity_; }

  std::size_t moves() const noexcept { return moves_; }
  void reset_counters() noexcept { moves_ = 0; }
};

// Restricción didáctica: T debe ser construible por defecto y asignable.
// moves_ cuenta transferencias debidas a redimensionamiento o desplazamiento,
// no la asignación normal del elemento que se inserta.

template<typename T>
void QueueShift<T>::grow() {
size_t new_capacity_;
	if(capacity_==0)
		new_capacity_=1;
	else{new_capacity_=capacity_*2;}
	T* new_data=new T[new_capacity_];
	for(size_t i=0;i<size_;i++){
		new_data[i]=data_[i];
		moves_++;}
	delete[] data_;
	data_=new_data;
	capacity_=new_capacity_;}

template<typename T>
QueueShift<T>::QueueShift(const QueueShift &other):data_(nullptr),size_(other.size_),capacity_(other.capacity_),moves_(0){
if(capacity_>0){
	data_=new T[capacity_];
	for(size_t i=0;i<size_;i++)
		data_[i]=other.data_[i];}
}


template<typename T>
QueueShift<T>::QueueShift(QueueShift &&other) noexcept:data_(other.data_), size_(other.size_), capacity_(other.capacity_), moves_(other.moves_){
	other.data_=nullptr;
	other.size_=0;
	other.capacity_=0;
	other.moves_=0;
}

template<typename T>
QueueShift<T> &QueueShift<T>::operator=(const QueueShift &other) {
   if(this!=&other){
	T* new_data_=nullptr;
	if(other.capacity_>0){
		new_data_=new T[other.capacity_];
		for(size_t i=0;i<other.size_;i++)
			new_data_[i]=other.data_[i];
			}
	delete[] data_;
	
	data_=new_data_;
	size_=other.size_;
	capacity_=other.capacity_;
   	moves_=0;}


        return *this;
}


template<typename T>
QueueShift<T> &QueueShift<T>::operator=(QueueShift &&other) noexcept {
    if(this!=&other){
	delete[] data_;
          this->data_=other.data_;
          this->size_=other.size_;
          this->capacity_=other.capacity_;
	  this->moves_=other.moves_;
  other.data_=nullptr;
  other.size_=0;
  other.capacity_=0;
  other.moves_=0;}
	return *this;
}

template<typename T>
QueueShift<T>::~QueueShift() {
  delete[] data_;
}

template<typename T>
void QueueShift<T>::push(const T &x) {
if(size_==capacity_)
	grow();
data_[size_]=x;
size_++;
}

template<typename T>
void QueueShift<T>::push(T &&x) {
	if(size_==capacity_)
		grow();
	data_[size_]=x;
	size_++;
}

template<typename T>
void QueueShift<T>::pop() {
if(size_==0)
	throw out_of_range("Queue vacia");
for(size_t i=0;i<size_-1;i++){
	data_[i]=data_[i+1];
	moves_++;
}
size_-=1;
}

template<typename T>
T &QueueShift<T>::front() {
if(size_==0)
	throw out_of_range("Queue vacia");
return data_[0];
}

template<typename T>
const T &QueueShift<T>::front() const {
if(size_==0)
        throw out_of_range("Queue vacia");
return data_[0];
}
#endif
