#!/bin/bash

OSS=(darwin freebsd linux)
ARCHS=(386 amd64)

mkdir -p bin
rm -f bin/*

for os in "${OSS[@]}"; do
    for arch in "${ARCHS[@]}"; do
    	echo "Building for $os($arch)"
        GOOS=$os GOARCH=$arch go build -ldflags "-s -w"
        mv IsrafilCLI bin/IsrafilCLI-$os-$arch
    done
done

OSS=(windows)
ARCHS=(386 amd64)

for os in "${OSS[@]}"; do
    for arch in "${ARCHS[@]}"; do
    	echo "Building for $os($arch)"
        GOOS=$os GOARCH=$arch go build -ldflags "-s -w"
        mv IsrafilCLI.exe bin/IsrafilCLI-$os-$arch.exe
    done
done
