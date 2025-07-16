FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && apt install -y \
  build-essential cmake git wget curl \
  libyaml-cpp-dev libsqlite3-dev libboost-all-dev \
  libonnxruntime-dev protobuf-compiler \
  python3-pip tcpdump iproute2 strace net-tools

WORKDIR /neuroran
COPY . .

CMD ["/bin/bash"]
