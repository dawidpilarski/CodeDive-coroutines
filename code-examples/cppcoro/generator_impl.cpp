template <typename T>
generator<T>::generator(coro_handle_t handle) : coro_handle_(handle){}

template <typename T>
generator<T>::~generator(){
	coro_handle_.destroy();
}

template <typename T>
T generator<T>::next(){
  if(coro_handle_.done())
    throw "nothing to resume";
  
  coro_handle_.resume();
  return *coro_handle_.promise().value_;
};

