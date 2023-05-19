# build components

FROM openjdk:11-jdk-slim AS build
RUN apt update
RUN apt install -y git build-essential cmake doxygen python3

RUN git clone --depth 1 https://github.com/BYVoid/OpenCC /z
WORKDIR /z
RUN make -j
RUN make install
RUN strip /usr/lib/libopencc.so
RUN rm -rf /usr/share/opencc/doc

WORKDIR /s
COPY . .
RUN make clean
RUN make -j all

# release image

FROM openjdk:11-jre-slim
RUN \
  --mount=type=bind,from=build,source=/,target=/mnt \
  cp -r /mnt/usr/lib/libopencc.* /usr/lib/ && \
  cp -r /mnt/usr/share/opencc /usr/share/ && \
  cp -r /mnt/usr/include/opencc /usr/include/ && \
  cp -r /mnt/s/target/main/cpp/*.so /usr/lib/ && \
  ldconfig
