#!/usr/bin/env bash
set -e

BUILD_PATH="build"
TARGET="chooser"

read -p "Limpar o build? (Y/n) " CHOICE
if [[ "$CHOICE" == "Y" || "$CHOICE" == "y" ]]; then
    echo "[ REMOVENDO CACHE ]"
    rm -rfv "$BUILD_PATH"
fi

echo "[ CONFIGURANDO BUILD ]"
cmake -S . -B "$BUILD_PATH"

echo "[ BUILDANDO PROGRAMA ]"
cmake --build "$BUILD_PATH"

echo "[ EXECUTANDO PROGRAMA ]"
./"$BUILD_PATH/$TARGET"