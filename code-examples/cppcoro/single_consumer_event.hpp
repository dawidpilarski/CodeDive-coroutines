class single_consumer_event{
  void set(){
    is_set_ = true;
    if(coro_handle_) coro_handle_.resume();
  }

  void reset(){
    is_set_=false;
    coro_handle_=nullptr;
  }

  operator co_await(){
    return awaiter{*this};
  }

private:
    bool is_set_=false;
    std::coroutine_handle<void> coro_handle_;
    struct awaiter;
};

struct single_consumer_evern::awaiter{
  single_consumer_event& parent;
  bool await_ready(){
    return parent.is_set_;
  }

  void await_suspend(std::coroutine_handle<void> new_handle){
    parent.coro_handle_ = new_handle;
  }

  void await_resume(){};
};