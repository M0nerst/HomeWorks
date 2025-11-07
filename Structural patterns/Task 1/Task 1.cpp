
#include <string>
#include <iostream>
#include <algorithm>  

// Предоставляет виртуальный метод render для отображения текста
class Text 
{
public:
    virtual ~Text() = default;  // Добавлен виртуальный деструктор
    virtual void render(const std::string& data) const 
    {
        std::cout << data;
    }
};


// Реализует паттерн "Декоратор" (Decorator pattern)
class DecoratedText : public Text 
{
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    virtual ~DecoratedText() { delete text_; }  // Добавлен деструктор для освобождения памяти
    Text* text_;
};

// Декоратор для отображения текста курсивом
// Оборачивает текст в HTML-теги <i></i>
class ItalicText : public DecoratedText 
{
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const override 
    {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

// Декоратор для отображения жирного текста
// Оборачивает текст в HTML-теги <b></b>
class BoldText : public DecoratedText 
{
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const override 
    {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

// Декоратор для создания параграфа
// Оборачивает текст в HTML-теги <p></p>
class Paragraph : public DecoratedText 
{
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const override 
    {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

// Декоратор для отображения текста в обратном порядке
// Переворачивает строку перед отображением
class Reversed : public DecoratedText 
{
public:
    explicit Reversed(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const override 
    {
        std::string ReversedData = data;
        std::reverse(ReversedData.begin(), ReversedData.end());
        text_->render(ReversedData);
    }
};

// Декоратор для создания гиперссылки
// Оборачивает текст в HTML-тег <a href="..."></a>
class Link : public DecoratedText 
{
public:
    explicit Link(Text* text) : DecoratedText(text) {}
    void render(const std::string& link, const std::string& data) const 
    {
        std::cout << "<a href=";
        text_->render(link);
        std::cout << ">";
        text_->render(data);
        std::cout << "</a>";
    }
};

int main() 
{
    // Пример 1: Создание жирного курсивного текста
    // Комбинация декораторов ItalicText и BoldText
    auto Bold_Italic_block = new ItalicText(new BoldText(new Text()));
    Bold_Italic_block->render("Hello world");
    std::cout << std::endl;
    delete Bold_Italic_block;  // Освобождение памяти

    // Пример 2: Создание параграфа
    auto Paragraph_block = new Paragraph(new Text());
    Paragraph_block->render("Hello world");
    std::cout << std::endl;
    delete Paragraph_block;  // Освобождение памяти

    // Пример 3: Отображение текста в обратном порядке
    auto Reversed_block = new Reversed(new Text());
    Reversed_block->render("Hello world");
    std::cout << std::endl;
    delete Reversed_block;  // Освобождение памяти

    // Пример 4: Создание гиперссылки
    auto Link_block = new Link(new Text());
    Link_block->render("netology.ru", "Hello world");
    std::cout << std::endl;
    delete Link_block;  // Освобождение памяти

    return 0;
}
