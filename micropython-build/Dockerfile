FROM debian:stable-slim

# Moving on...
RUN apt-get update && apt-get -y dist-upgrade
RUN apt-get install -y git build-essential make unrar-free autoconf \
	automake libtool gcc g++ gperf flex bison texinfo gawk ncurses-dev \
	libexpat-dev python-dev python python-serial sed unzip bash help2man \
	wget bzip2 libtool-bin
RUN useradd build
RUN mkdir -p /data ; chown -R build /data
RUN su - build -c "cd /data ; git clone --recursive https://github.com/pfalcon/esp-open-sdk"
RUN su - build -c "cd /data/esp-open-sdk ; make"
RUN su - build -c "git clone --recursive https://github.com/micropython/micropython /data/micropython/"
RUN su - build -c "cd /data/micropython ; \
                   export PATH=/data/esp-open-sdk/xtensa-lx106-elf/bin:$PATH ; \
                   git submodule update --init"
RUN su - build -c "export PATH=/data/esp-open-sdk/xtensa-lx106-elf/bin:$PATH ; \
                   cd /data/micropython/ ; make -C mpy-cross"
RUN su - build -c "export PATH=/data/esp-open-sdk/xtensa-lx106-elf/bin:$PATH ; \
                   cd /data/micropython/ports/esp8266 ; make axtls && make "
