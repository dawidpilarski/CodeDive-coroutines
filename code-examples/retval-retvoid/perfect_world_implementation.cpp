template <typename T>
struct task<T>::promise_type{
  // ... 
  void return_void() 
    requires std::is_same<T, void>{}

  template <typename U>
  void return_value(U&& val) 
    requires not std::is_same<T, void>{}
}