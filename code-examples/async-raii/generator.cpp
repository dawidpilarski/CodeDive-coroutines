generator<std::string> lines(const path& file_path) {
  ifstream stream(file_path.string());
  std::string line;
  while(getline(stream, line)){
    co_yield line;
  }
  // stream closes file
}