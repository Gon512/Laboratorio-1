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
	else{new_capacity=capacity_*2;}
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
QueueShift<T>::QueueShift(QueueShift &&other) noexcept:data_(other.data_), size_(other.size_), capacity_(other.capacity_), moves_(other.moves_)i{
	other.data_=nullptr;
	other.size_=0;
	other.capacity_=0;
	other.moves_=0;
}

template<typename T>
QueueShift<T> &QueueShift<T>::operator=(const QueueShift &) {
  throw std::logic_error("TODO QueueShift copy assignment");
}

template<typename T>
QueueShift<T> &QueueShift<T>::operator=(QueueShift &&) noexcept {
  // TODO: liberar el recurso actual, transferir ownership y vaciar el origen.
  return *this;
}

template<typename T>
QueueShift<T>::~QueueShift() {
  delete[] data_;
}

template<typename T>
void QueueShift<T>::push(const T &) {
  throw std::logic_error("TODO QueueShift::push(const T&)");
}

template<typename T>
void QueueShift<T>::push(T &&) {
  throw std::logic_error("TODO QueueShift::push(T&&)");
}

template<typename T>
void QueueShift<T>::pop() {
  throw std::logic_error("TODO QueueShift::pop");
}

template<typename T>
T &QueueShift<T>::front() {
  throw std::logic_error("TODO QueueShift::front");
}

template<typename T>
const T &QueueShift<T>::front() const {
  throw std::logic_error("TODO QueueShift::front const");
}
#endif
