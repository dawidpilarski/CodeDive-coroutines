

#include <cppcoro/single_consumer_event.hpp>
#include <cppcoro/task.hpp>
#include <cppcoro/sync_wait.hpp>
#include <cppcoro/when_all_ready.hpp>
#include <thread>
#include <experimental/coroutine>
#include <iostream>
#include <chrono>

using namespace cppcoro;
using namespace std;
using namespace std::literals;

struct scheduler {
  struct promise_type;
  using this_coro_t = std::experimental::coroutine_handle<promise_type>;

  scheduler(this_coro_t this_coro) : coro(this_coro) {}

  scheduler(const scheduler& rhs) = default;

  struct promise_type {
    scheduler get_return_object() { return this_coro_t::from_promise(*this); }

    std::experimental::suspend_never initial_suspend() { return {}; }

    std::experimental::suspend_always final_suspend() { return {}; }

    void unhandled_exception() { throw; }

    void return_void() {}
  };

  this_coro_t coro;
};

scheduler start_task(task<> task) {
  co_await task;
}

void sched(task<> task1, task<> task2) {
  start_task(std::move(task1));
  start_task(std::move(task2));
}

void test() {
  single_consumer_event event;
  sched(
      [&]() -> cppcoro::task<> {
        while (true) {
          co_await event;
          event.reset();
          std::cout << "pong" << std::endl;
          std::this_thread::sleep_for(1000ms);
        }
      }(),
      [&]() -> cppcoro::task<> {
        while (true) {
          std::cout << "ping" << std::endl;
          event.set();
        }
        co_return;
      }());
}


int main() {
  test();
}

