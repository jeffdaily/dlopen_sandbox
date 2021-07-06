FROM quay.io/pypa/manylinux2014_x86_64

WORKDIR /root

RUN yum install -y --nogpgcheck autoconf automake libtool vim less zip unzip wget sed make

RUN python3.6 -m pip install auditwheel pybind11

ENV LD_LIBRARY_PATH $LD_LIBRARY_PATH:/usr/local/lib

RUN git clone https://github.com/jeffdaily/dlopen_sandbox 

RUN cd dlopen_sandbox/runtime_dlopened/driver && autoreconf -fi && mkdir build && cd build && ../configure && make && make check && make install

RUN cd dlopen_sandbox/runtime_dlopened/runtime && autoreconf -fi && mkdir build && cd build && ../configure && make && make check && make install

RUN cd dlopen_sandbox/runtime_dlopened/py_one && python3.6 setup.py bdist_wheel && python3.6 -m auditwheel repair dist/*.whl && python3.6 -m pip install wheelhouse/*.whl

RUN cd dlopen_sandbox/runtime_dlopened/py_two && python3.6 setup.py bdist_wheel && python3.6 -m auditwheel repair dist/*.whl && python3.6 -m pip install wheelhouse/*.whl

RUN cd dlopen_sandbox/runtime_dlopened && python3.6 ./run_complete_test.py
