# Clang SA
sudo apt install clang

# Clang tidy
sudo apt install clang-tidy

# cppcheck
sudo apt install cppcheck

# flawfinder
sudo apt install flawfinder

# frama-c
sudo apt install opam
opam init
eval $(opam env)
opam install alt-ergo z3 why3 frama-c

# infer
sudo curl -sSL "https://github.com/facebook/infer/releases/download/v1.2.0/infer-linux-x86_64-v1.2.0.tar.xz" | sudo tar -C /opt -xJ
sudo ln -s "/opt/infer-linux-x86_64-v1.2.0/bin/infer" /usr/local/bin/infer

# rats
git clone https://github.com/andrew-d/rough-auditing-tool-for-security.git
cd rough-auditing-tool-for-security/
./configure
make
make install

# sparse
sudo apt install sparse

# splint
sudo apt install splint

# IKOS 
sudo apt install ikos

# ESBMC
sudo apt-get install -y clang-14 llvm-14 clang-tidy-14 python-is-python3 python3 git ccache unzip wget curl bison flex g++-multilib linux-libc-dev libboost-all-dev libz3-dev libclang-14-dev libclang-cpp-dev cmake
git clone https://github.com/esbmc/esbmc.git
cd esbmc
mkdir build && cd build
cmake .. -DENABLE_Z3=1
make -j4
sudo make install
