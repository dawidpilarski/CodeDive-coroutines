task<std::vector<char>> 
read_file(const path& file_path){

  auto opened_file = co_await async_open(path);
  auto content = co_await async_read(opened_file);
  co_await async_close(opened_file);

  co_return content;
}