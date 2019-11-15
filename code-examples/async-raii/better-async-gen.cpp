async_generator<std::string> lines(const path& file_path) {
  auto opened_file = co_await async_open(file_path);
  std::optional<std::string> opt_line;
  while(opt_line = co_await 
                   async_read_line(opened_file)){
    co_yield *opt_line;
  }
  
  // async_close happens as a part of clean-up
}