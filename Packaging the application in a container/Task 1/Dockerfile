FROM ubuntu:16.04
RUN apt update && apt install -y g++ mc
WORKDIR  /app
COPY main.cpp .
RUN g++ main.cpp -o hello_world
CMD [ "./hello_world"]