FROM ubuntu:18.04
# Grab our dependencies, there aren't many for this
RUN DEBIAN_FRONTEND="noninteractive" apt-get update
RUN DEBIAN_FRONTEND="noninteractive" apt-get -y install build-essential binwalk git vim tmux elfutils emacs make python python3 
RUN mkdir /home/hackaday/
WORKDIR /home/hackaday
RUN git clone https://github.com/wrongbaud/hackaday-u.git
