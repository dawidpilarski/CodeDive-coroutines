task<void> display_text(string text){
  // ...
  co_return;
}

task<void> display_file(path file){
  auto content = co_await read_file(file);
  co_return display_text(content);
}