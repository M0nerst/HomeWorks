cmake_minimum_required(VERSION 3.10)
#Название проекта
project(task_1) 

add_subdirectory(catch2)

#Включение экспорта всех символов для создания динамической библиотеки
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

#добавляем цель - приложение, у которого исходник с единственным приложением
add_executable(${PROJECT_NAME} 01.cpp)

#Линковка программы с библиотекой catch2 
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)