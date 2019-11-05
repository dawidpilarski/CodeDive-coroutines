task<int> bar(){
  co_return 42;
}

task<int> foo(){
  co_return co_await bar();
}
