cmake_minimum_required(VERSION 3.20)

project(lessionfive)

set(PostgreSQL_ADDITIONAL_VERSIONS "17")

add_executable(lessionfive lessionfive.cpp)

add_subdirectory(C:/libpqxx-7.10.1 libpqxx-build)

target_compile_features(lessionfive PRIVATE cxx_std_17)

target_link_libraries(lessionfive pqxx)