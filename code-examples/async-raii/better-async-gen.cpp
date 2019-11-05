async_generator<std::string> lines(const path& file_path) {
  auto opened_file = co_await async_open(file_path);
  while(getline(stream, line)){
    co_yield co_await async_read_line(opened_file);
  }
  
  //async close happens as a part of cleanup
}