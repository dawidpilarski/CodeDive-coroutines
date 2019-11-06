template <>
struct task<void>::promise_type{
  //...
  
  void return_void(){}

  void return_value(task<void>&&){
    // ...
  }
};