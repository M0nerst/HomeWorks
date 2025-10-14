FROM ubuntu:16.04
RUN apt update && apt install -y g++ nano
WORKDIR  /app
COPY main.cpp .
RUN g++ main.cpp -o hi
CMD [ "./hi"]