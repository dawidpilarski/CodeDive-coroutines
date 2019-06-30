#include <iostream>
#include <milli/repeat.hpp>

#include <experimental/coroutine> // potrzebne dla coroutine_handle


template <typename T>
class generator {
public:
  T next();
  ~generator();

  struct promise_type;
private:
  using coro_handle_t = std::coroutine_handle<promise_type>;
  coro_handle_t coro_handle_;
  generator(coro_handle_t handle);
};

template <typename T>
struct generator<T>::promise_type {
  std::optional<T> recent_value;

  generator<T> get_return_object() {
    return generator<T>::coro_handle_t::from_promise(*this);
  }

  std::suspend_always initial_suspend() { return {}; }
  std::suspend_always final_suspend() { return {}; }

  void return_void() {}

  std::suspend_always yield_value(T value) {
    recent_value.emplace(value);
    return {};
  }

  void unhandled_exception() {
    throw;
  }
};

generator<unsigned int> positives_no_zero() {
  unsigned int current = 0;
  while (true) {
    co_yield++ current;
  }
}

int main() {
  auto generator = positives_no_zero();
  milli::repeat(10, [&]() { std::cout << generator.next() << std::endl; });
}