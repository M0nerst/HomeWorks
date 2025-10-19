#include <iostream>
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"

// Узел двусвязного списка
struct ListNode
{
public:
   
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;          
    ListNode* prev;     
    ListNode* next;     
};


class List
{
public:
    
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    
    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    // Проверка, пуст ли список
    bool Empty() { return m_size == 0; }

    // Возвращает текущий размер списка
    unsigned long Size() { return m_size; }

    // Добавляет элемент в начало списка
    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    // Добавляет элемент в конец списка
    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    // Удаляет и возвращает первый элемент списка
    // Бросает исключение, если список пуст
    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    // Удаляет и возвращает последний элемент списка
    // Бросает исключение, если список пуст
    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    // Очищает весь список, удаляя все элементы
    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    // Вспомогательная функция для извлечения узла перед заданным
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;           // Фиктивный головной узел
    ListNode* m_tail;           // Фиктивный хвостовой узел
    unsigned long m_size;       // Текущий размер списка
};


// ============ ТЕСТЫ ============

TEST_CASE("TEST_LIST", "[TEST_LIST]")
{
    List L1;

    SECTION("Проверка пустой список или нет CHECK_FALSE Empty()")
    {
        INFO("Проверка пустой список или нет CHECK_FALSE Empty()");

        // Пустой
        CHECK_FALSE(!L1.Empty());

        L1.PushBack(55);

        // Не пустой
        CHECK_FALSE(L1.Empty());

        L1.PopBack();

        // Пустой
        CHECK_FALSE(!L1.Empty());
    };

    SECTION("Проверка размера списка CHECK Size()")
    {
        INFO("Проверка размера списка");

        // Пустой
        CHECK(L1.Size() == 0);

        L1.PushBack(55);

        // Не пустой
        CHECK(L1.Size() == 1);

        L1.PushBack(55);
        L1.PushBack(56);
        L1.PushBack(57);

        // Не пустой
        CHECK(L1.Size() == 4);

        L1.PopBack();

        // Не пустой
        CHECK(L1.Size() == 3);

        L1.PopBack();
        L1.PopBack();
        L1.PopBack();

        // Пустой
        CHECK(L1.Size() == 0);
    };

    SECTION("Проверка очистки списка CHECK Clear()")
    {
        INFO("Проверка очистки списка CHECK Clear()");

        L1.Clear();

        // Пустой
        CHECK(L1.Size() == 0);

        L1.PushBack(57);
        // Не Пустой
        CHECK(L1.Size() == 1);

        L1.PopBack();

        // Пустой
        CHECK(L1.Size() == 0);
    };
};


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "RU");

    // Пример использования списка
    List L1;

    std::cout << "Empty() " << L1.Empty() << std::endl;
    std::cout << "L1.Size() " << L1.Size() << std::endl;

    // Добавляем элементы
    L1.PushBack(55);
    L1.PushBack(56);
    L1.PushBack(57);

    std::cout << "L1.Size() " << L1.Size() << std::endl;

    L1.PushFront(58);

    std::cout << "L1.Size() " << L1.Size() << std::endl;
    std::cout << "Empty() " << L1.Empty() << std::endl;
    std::cout << "L1.PopFront() 58 - " << L1.PopFront() << std::endl;
    std::cout << "L1.Size() " << L1.Size() << std::endl;

    // Удаляем оставшиеся элементы (их сейчас 3: 55, 56, 57)
    std::cout << "L1.PopFront() 55 - " << L1.PopFront() << std::endl;
    std::cout << "L1.PopFront() 56 - " << L1.PopFront() << std::endl;
    std::cout << "L1.PopFront() 57 - " << L1.PopFront() << std::endl;

    // Теперь список пуст
    std::cout << "L1.Size() " << L1.Size() << std::endl;

    std::cout << "\n\nКонец вывода\n\n";

    // Запуск тестов Catch2
    return Catch::Session().run(argc, argv);
}
