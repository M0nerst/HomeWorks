FROM ubuntu:16.04
RUN apt update && apt install -y g++
WORKDIR  /app
COPY . .
RUN g++ main.cpp -o macros
CMD ["./macros"]