std::vector<int> foo(){
  return {1,2,3,4,5};
}

// ...

// no copy or move construction
// invoked
auto _ = foo(); 