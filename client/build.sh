#!/usr/bin/env bash

source /etc/os-release

if [ "$ID" == "ubuntu" ]; then
    sudo apt-get install libfreetype6 x11-xserver-utils libflac-dev libogg-dev libvorbis-dev libopenal-dev
    echo "Dependencies on Ubuntu for SFML installed"
elif [ "$ID" == "fedora" ]; then
    sudo dnf install freetype-devel libX11-devel libXrandr-devel libudev-devel xorg-x11-server-Xorg mesa-libGL-devel flac-devel libogg-devel libvorbis-devel openal-soft-devel
    echo "Dependencies on Fedora for SFML installed"
else
    echo "This is a different Linux distribution"
fi

rm -rf lib/
rm -rf build/
mkdir build
cd build
cmake ..

if [ $? -ne 0 ]; then
    echo "cmake failed"
    exit 1
fi

make

if [ $? -ne 0 ]; then
    echo "make failed"
    exit 1
fi

make package

if [ $? -ne 0 ]; then
    echo "make package failed"
    exit 1
fi

cd ..
