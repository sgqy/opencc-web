FROM gcc:10-bullseye as build

RUN apt update
RUN apt install -y cmake doxygen

RUN git clone --depth 1 https://github.com/BYVoid/OpenCC /src
WORKDIR /src
RUN make -j
RUN make install
RUN rm -rf /usr/share/opencc/doc

###

FROM mcr.microsoft.com/devcontainers/java:11-bullseye

RUN \
  --mount=type=bind,from=build,source=/,target=/mnt \
  cp -r /mnt/usr/lib/libopencc.* /usr/lib/ && \
  cp -r /mnt/usr/share/opencc /usr/share/ && \
  cp -r /mnt/usr/include/opencc /usr/include/ && \
  ldconfig
