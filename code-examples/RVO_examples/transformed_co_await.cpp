{
  auto&& awaiter = transform(task);
  if(!awaiter.await_ready()){
    <coroutine suspend>
    awaiter.await_suspend();
    <coroutine resume>;
  }
  awaiter.await_resume();
}