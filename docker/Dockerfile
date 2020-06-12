FROM ubuntu:18.04
# Grab our dependencies, there aren't many for this
RUN DEBIAN_FRONTEND="noninteractive" apt-get update
RUN DEBIAN_FRONTEND="noninteractive" apt-get -y install build-essential binwalk git vim tmux elfutils emacs make python python3 
# Install 32bit libraries
RUN DEBIAN_FRONTEND="noninteractive" dpkg --add-architecture i386
RUN DEBIAN_FRONTEND="noninteractive" apt-get update && apt-get -y install  libc6:i386 libncurses5:i386 libstdc++6:i386 multiarch-support

RUN mkdir /home/hackaday/
WORKDIR /home/hackaday
RUN git clone https://github.com/wrongbaud/hackaday-u.git
