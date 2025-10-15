FROM ubuntu:16.04
COPY . /usr/src/DockerTest
WORKDIR /usr/src/DockerTest
RUN apt update && apt install -y g++ clang nano
RUN g++ Task2.cpp -o Test_gcc
RUN clang++ Task2.cpp -o Test_clang
# CMD ["./Test_gcc", "./Test_clang"]
