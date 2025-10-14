FROM ubuntu:16.04
RUN apt update && apt install -y g++ clang nano
WORKDIR  /app
COPY Task2.cpp .
RUN g++ Task2.cpp -o test
CMD ["./test"]