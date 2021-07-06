#!/bin/bash

MAYBE_NOCACHE="--no-cache"

pushd runtime_dlopened
docker build . -t jeffdaily/dlopen_sandbox:dlopened ${MAYBE_NOCACHE}
popd

pushd runtime_disjoint
docker build . -t jeffdaily/dlopen_sandbox:auditwheel_one ${MAYBE_NOCACHE}
popd

pushd runtime_disjoint
docker build . -t jeffdaily/dlopen_sandbox:auditwheel_two -f Dockerfile.both ${MAYBE_NOCACHE}
popd
