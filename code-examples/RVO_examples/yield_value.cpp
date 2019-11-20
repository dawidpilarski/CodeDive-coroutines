template <typename T> class task<T>::promise_type{
// ....

  template <typename U> requires ConstructibleFrom<T, U>
  void return_value(U&& value){
    handle.set_value<T>(std::forward<U>(value));
  }	

  template <typename... Args> 
            requires ConstructibleFrom<T, Args...>
  void return_value(std::in_place_construct<Args&&...> 
  	          ctor_args){
    handle.set_value_from<T>(ctor_args);
  }

};