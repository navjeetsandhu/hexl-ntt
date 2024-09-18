[![Test](https://github.com/virtualsecureplatform/TFHEpp/actions/workflows/test.yml/badge.svg)](https://github.com/virtualsecureplatform/TFHEpp/actions/workflows/test.yml)
# hexl-ntt


## HEXL

[HEXL](https://github.com/intel/hexl.git) is the NTT library optimized for AVX512. 

# Speed Test

Following Code measure how many time homomorphic NAND takes on your computer with TFHEpp. 
```
git clonehttps://github.com/navjeetsandhu/hexl-ntt
cd hexl-ntt
mkdir build
cd build
cmake .. -DENABLE_TEST=ON
make
ulimit -s unlimited
./test/nand 
```


