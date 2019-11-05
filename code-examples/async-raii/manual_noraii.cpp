async_generator<std::string> lines(const path& file_path) {
  auto opened_file = co_await async_open(file_path);
  while(getline(stream, line)){
    // remember to resume coroutine before destroy!
    auto cancellation_token = 
         co_yield co_await async_read_line(opened_file); 
    if(cancellation_token){
      goto clean_up;
    }
  }
  
  clean_up:
  co_await async_close(opened_file);
}