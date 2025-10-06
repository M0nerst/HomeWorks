
#include <iostream>
#include <mutex>
#include <thread>
#include <Windows.h>


class Data {
private:
    int data_; 
public:
    // Конструктор инициализирует данные
    Data(int data) :data_(data) {};

    // Геттер для получения значения
    int get() { return data_; }

    // Сеттер для установки значения
    void set(int data) { data_ = data; }

    // Мьютекс для синхронизации доступа к данным
    std::mutex mutex_;


    void swap_Lock(Data& d2)
    {
        // Одновременная блокировка двух мьютексов без риска deadlock
        std::lock(this->mutex_, d2.mutex_);

        // Обмен значениями между двумя объектами Data
        int tmp = this->get();
        this->set(d2.get());
        d2.set(tmp);

        std::cout << "=========Lock=========" << std::endl;
        this->print();
        d2.print();

        this->mutex_.unlock();
        d2.mutex_.unlock();
    }


    void swap_ScopedLock(Data& d2)
    {
        std::scoped_lock lock(this->mutex_, d2.mutex_);

        // Обмен значениями
        int tmp = this->get();
        this->set(d2.get());
        d2.set(tmp);

        std::cout << "=========ScopedLock=========" << std::endl;
        this->print();
        d2.print();

 
    }


    void swap_UniqueLock(Data& d2)
    {
        // Создаем unique_lock с отложенной блокировкой (std::defer_lock)
        std::unique_lock<std::mutex> lock1(this->mutex_, std::defer_lock);
        std::unique_lock<std::mutex> lock2(d2.mutex_, std::defer_lock);

        // Явная блокировка мьютексов
        lock1.lock();
        lock2.lock();

        // Обмен значениями
        int tmp = this->get();
        this->set(d2.get());
        d2.set(tmp);

        std::cout << "=========UniqueLock=========" << std::endl;
        this->print();
        d2.print();


        lock1.unlock();
        lock2.unlock();
    }

    // Вспомогательный метод для вывода значения
    void print() {
        std::cout << "data_ = " << data_ << ";" << std::endl;
    }
};


int main()
{

    Data d1(12);
    Data d2(124);


    d1.print();
    d2.print();



    // Поток 1: использует std::lock
    std::thread t1([&]() {
        d1.swap_Lock(d2);
        });

    // Поток 2: использует std::scoped_lock (рекомендуемый подход в C++17+)
    std::thread t2([&]() {
        d1.swap_ScopedLock(d2);
        });

    // Поток 3: использует std::unique_lock (для более гибкого управления)
    std::thread t3([&]() {
        d1.swap_UniqueLock(d2);
        });

    // Ожидаем завершения всех потоков перед выходом из программы
    t1.join();
    t2.join();
    t3.join();
}
