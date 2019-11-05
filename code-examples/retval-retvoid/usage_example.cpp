task<int> foo(){
  co_return 42;
}

task<void> start(){
  std::cout << (co_await foo()) << std::endl;
  // implicit co_return;
}