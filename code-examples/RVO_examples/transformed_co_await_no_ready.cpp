{
  auto&& awaiter = transform(event);
  if(!awaiter.await_ready()){
    <coroutine suspend>
    awaiter.await_suspend();
  }
  <coroutine resume>;
}