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