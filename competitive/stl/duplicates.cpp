vector<int> removedupli(vector<int> input){
  //set<int> s;
  std::vector<int> result;
  /*for(int i=0;i<input.size();i++){
    if(s.find(input[i])==s.end()){
      s.insert(input[i]);
      result.push_back(input[i]);
    }
  } */
  // by sort ;
  sort(input.begin(),input.end());
  result.push_back(input[0]);
  for(int i=1;i<input.size;i++){
    if(input[i]!=input[i-1]){
      result.push_back(input[i]);
    }
  }
  return result;
}
