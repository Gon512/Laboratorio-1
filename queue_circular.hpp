#ifndef QUEUECIRCULAR
#define QUEUECIRCULAR

#include <cstddef>
#include <stdexcept>
#include <utility>

template<typename T>
class QueueCircular {
private:
  T *data_ = nullptr;
  std::size_t head_ = 0;
  std::size_t size_ = 0;
  std::size_t capacity_ = 0;
  std::size_t moves_ = 0;

  void grow();
  std::size_t physical_index(std::size_t logical) const noexcept;

public:
  QueueCircular() = default;
  QueueCircular(const QueueCircular &other);
  QueueCircular(QueueCircular &&other) noexcept;
  QueueCircular &operator=(const QueueCircular &other);
  QueueCircular &operator=(QueueCircular &&other) noexcept;
  ~QueueCircular();

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
// pop() NO debe desplazar los elementos restantes.

template<typename T>
std::size_t QueueCircular<T>::physical_index(std::size_t logical) const noexcept {
  return capacity_ == 0 ? 0 : (head_ + logical) % capacity_;
}

template<typename T>
void QueueCircular<T>::grow() {
size_t new_capacity_;
	if(capacity_==0)
		new_capacity_=1;
	else new_capacity=capacity_*2;
	T* new_data=new T[new_capacity_];
	for(size_t i=0;i<size_;i++){
		new_data[i]=data_[physical_index(i)];
		moves_++;}
	delete[] data_;
	data_=new_data;
	capacity_=new_capacity_;
	head_=0;}
}

template<typename T>
QueueCircular<T>::QueueCircular(const QueueCircular &other):data_(nullptr),head_(0),size_(other.size_),capacity_(other.capacity_),moves_(0){
if(capacity_>0){
	data_=new T[capacity_];
	for(size_t i=0;i<size_;i++)
		data_[i]=other.data_[physical_index(i)];}
}

template<typename T>
QueueCircular<T>::QueueCircular(QueueCircular &&other) noexcept:data_(other.data_),head_(other.head_) size_(other.size_), capacity_(other.capacity_), moves_(other.moves_)i{
	other.data_=nullptr;
	other.head_=0;
	other.size_=0;
	other.capacity_=0;
	other.moves_=0;
}


template<typename T>
QueueCircular<T> &QueueCircular<T>::operator=(const QueueCircular &) {
   if(this!=&other){
	T* new_data_=nullptr;
	if(other.capacity_>0){
		new_data_=new T[other.capacity_];
		for(size_t i=0;i<other.size_;i++)
			new_data_[i]=other.data_[other.physical_index(i)];
			}
	delete[] data_;
	
	data_=new_data_;
	head_=0;
	size_=other.size_;
	capacity_=other.capacity_;
   	moves_=0;}
        return *this;
}

template<typename T>
QueueCircular<T> &QueueCircular<T>::operator=(QueueCircular &&) noexcept {
      if(this!=&other){
	delete[] data_;
          this->data_=other.data_;
	  this->head_=other.head_;
          this->size_=other.size_;
          this->capacity_=other.capacity_;
	  this->moves_=other.moves_;
  other.data_=nullptr;
  other.head=0;
  other.size_=0;
  other.capacity_=0;
  other.moves_=0;}
	return *this;
}


template<typename T>
QueueCircular<T>::~QueueCircular() {
  delete[] data_;
}

template<typename T>
void QueueCircular<T>::push(const T &x) {
if(size_==capacity_)
	grow();
data_[physical_index(size_)]=x;
size_++;
}

template<typename T>
void QueueCircular<T>::push(T &&x) {
	if(size_==capacity_)
		grow();
	data_[physical_index(size_)]=x;
	size_++;
}

template<typename T>
void QueueCircular<T>::pop() {
if(size_==0)
	throw out_of_range("Queue vacia");
head_=(head_+1)%capacity_;
head--;
}

template<typename T>
T &QueueCircular<T>::front() {
if(size_==0)
	throw out_of_range("Queue vacia");
return data_[head_];
}

template<typename T>
const T &QueueCircular<T>::front() const {
if(size_==0)
	throw out_of_range("Queue vacia");
return data_[head_];
}
#endif
