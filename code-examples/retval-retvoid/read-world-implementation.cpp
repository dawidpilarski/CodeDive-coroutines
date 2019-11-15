template <typename T>
struct task<T>::promise_type{
  //...
  template <typename T>
  void return_value(T&&){
    //...
  }
};