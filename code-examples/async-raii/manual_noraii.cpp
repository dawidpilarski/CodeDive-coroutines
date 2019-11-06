async_generator<std::string> lines(const path& file_path) {
  auto opened_file = co_await async_open(file_path);
  std::optional<std::string> opt_line;
  while(opt_line = co_await 
                   async_read_line(opened_file)){
    // remember to resume the coroutine before destroying
    auto cancellation_token = co_yield *opt_line;
    if(cancellation_token) break;
  }
  
  co_await async_close(opened_file);
}