for(const auto& line : lines("myfile.txt")){
  if(starts_with(line, "string I am looking for"))
    break;
}