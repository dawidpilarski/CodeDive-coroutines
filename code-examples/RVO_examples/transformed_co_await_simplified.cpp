{
  auto&& awaiter = transform(event);
  <coroutine suspend>
  awaiter.await_suspend();
  <coroutine resume>;
}