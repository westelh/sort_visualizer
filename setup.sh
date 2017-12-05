mkdir build
git clone --branch master --depth 1 https://github.com/liballeg/allegro5.git build/allegro
cd build/allegro
cmake -Wno-dev -DCMAKE_INSTALL_PREFIX="./install" .
make install -j5
cd ../..
