source /mnt/tbbusers/tbbtest/tools/linux/oneapi_compiler/nightly/setvars.sh
source /mnt/tbbusers/tbbtest/tools/linux/intel-compute-runtime/latest/vars.sh
source /mnt/tbbusers/andreyfe/work/repos/GITHUB/oneDPL/env/onedplvars.sh
#source /mnt/tbbusers/tbbtest/tools/linux/onetbb/latest/env/vars.sh
#clinfo
#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/mnt/tbbusers/tbbtest/tools/linux/intel-compute-runtime/20.09.15980/usr/local/lib 
#lscl
#clinfo
#echo $LD_LIBRARY_PATH
#cmake -DCMAKE_CXX_COMPILER=dpcpp ..
cmake -DCMAKE_CXX_FLAGS=-DBUILD_FOR_HOST ..
# -DCMAKE_CXX_FLAGS="-Wall -Wformat-security -Werror=format-security -Wno-unused-lambda-capture"
# -DCMAKE_CXX_FLAGS="-fiopenmp -fopenmp-targets=spir64 -fsycl"
make VERBOSE=1
make run
make clean
