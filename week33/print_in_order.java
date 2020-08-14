class Foo {
    final Lock lk;
    final Condition first;
    final Condition second;
    int count = 0;
    public Foo() {
        lk = new ReentrantLock();
        first = lk.newCondition();
        second = lk.newCondition();
    }

    public void first(Runnable printFirst) throws InterruptedException {
        lk.lock();
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        count++;
        first.signal();
        lk.unlock();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        lk.lock();
        while (count != 1) first.await();
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        count++;
        second.signal();
        lk.unlock();
    }

    public void third(Runnable printThird) throws InterruptedException {
        lk.lock();
        while (count != 2) second.await();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
        lk.unlock();
    }
}