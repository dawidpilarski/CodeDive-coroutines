void foo(std::vector<int>* ptr){
  new(ptr) std::vector<int>
           {1,2,3,4,5};
}