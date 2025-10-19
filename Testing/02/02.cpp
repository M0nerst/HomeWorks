#include <iostream>
#include <exception>
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>


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

    // Проверяет, пуст ли список
    // Возвращает true, если размер списка равен нулю
    bool Empty() { return m_size == 0; }

    // Возвращает текущий размер списка (количество элементов)
    unsigned long Size() { return m_size; }

    // Добавляет элемент в начало списка
    // value - значение добавляемого элемента
    void PushFront(int value)
    {
        // Создаем новый узел между head и первым реальным узлом
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    // Добавляет элемент в конец списка
    // value - значение добавляемого элемента
    void PushBack(int value)
    {
        // Создаем новый узел перед tail
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    // Удаляет и возвращает первый элемент списка
    // Выбрасывает исключение, если список пуст
    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        // Извлекаем первый реальный узел
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    // Удаляет и возвращает последний элемент списка
    // Выбрасывает исключение, если список пуст
    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        // Извлекаем последний реальный узел
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    // Очищает список, удаляя все элементы
    void Clear()
    {
        auto current = m_head->next;
        // Проходим по всем узлам от head до tail
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
        ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;      
    ListNode* m_tail;    
    unsigned long m_size;  
};

//==============Тесты======================

TEST_CASE("TEST_LIST", "[LIST]")
{
    List L1;

    SECTION("Проверка добавления элемента в конец списка PushBack(int value)")
    {
        INFO("Проверка добавления элемента в конец списка PushBack(int value)");

        // Проверяем, что список изначально пуст
        CHECK_FALSE(!L1.Empty());

        L1.PushBack(55);

        // После добавления одного элемента размер должен быть 1
        CHECK(L1.Size() == 1);

        L1.PopBack();
        // После удаления список снова пуст
        CHECK_FALSE(!L1.Empty());
        CHECK(L1.Size() == 0);

        // Добавляем несколько элементов
        L1.PushBack(55);
        L1.PushFront(55);
        L1.PushFront(55);

        CHECK(L1.Size() == 3);

        L1.PopBack();
        CHECK(L1.Size() == 2);

        L1.PopBack();
        L1.PopBack();

        // Проверяем, что попытка удаления из пустого списка вызывает исключение
        CHECK_THROWS(L1.PopBack());
        CHECK_THROWS(L1.PopFront());

        CHECK(L1.Size() == 0);
    };
};



int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "RU");

    List L1;

    // Демонстрация работы со списком
    std::cout << "Empty() " << L1.Empty() << std::endl;

    std::cout << "L1.Size() " << L1.Size() << std::endl;

    // Добавляем элементы в конец списка
    L1.PushBack(55);
    L1.PushBack(56);
    L1.PushBack(57);

    std::cout << "L1.Size() " << L1.Size() << std::endl;

    // Добавляем элемент в начало списка
    L1.PushFront(58);

    std::cout << "L1.Size() " << L1.Size() << std::endl;
    std::cout << "Empty() " << L1.Empty() << std::endl;

    // Удаляем первый элемент (должен быть 58)
    std::cout << "L1.PopFront() 58 - " << L1.PopFront() << std::endl;

    std::cout << "L1.Size() " << L1.Size() << std::endl;

    // Очищаем список
    L1.Clear();

    // Снова добавляем элементы для демонстрации
    L1.PushBack(55);
    L1.PushBack(56);
    L1.PushBack(57);

    // Удаляем элементы с начала списка
    std::cout << "L1.PopFront() 55 - " << L1.PopFront() << std::endl;
    std::cout << "L1.PopFront() 56 - " << L1.PopFront() << std::endl;
    std::cout << "L1.PopFront() 57 - " << L1.PopFront() << std::endl;

    std::cout << "\n\nВывод закончен. Запущены тесты.\n\n";

    // Запускаем unit-тесты Catch2
    return Catch::Session().run(argc, argv);
}
