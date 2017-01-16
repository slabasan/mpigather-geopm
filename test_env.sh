#!/bin/bash

export GEOPM_PREFIX=$HOME/ex-mpigather-geopm/geopm/build
export GEOPM_LIBDIR=$GEOPM_PREFIX/lib
export GEOPM_INCLUDEDIR=$GEOPM_PREFIX/include
export GEOPM_CFLAGS="-I$GEOPM_INCLUDEDIR"
export GEOPM_LDFLAGS="-L$GEOPM_LIBDIR -lgeopm"

LD_PRELOAD=$GEOPM_LIBDIR/libgeopm.so \
LD_DYNAMIC_WEAK=true \
GEOPM_PMPI_CTL=process \
GEOPM_REPORT=test_report \
GEOPM_TRACE=test_trace \
./prog

#
