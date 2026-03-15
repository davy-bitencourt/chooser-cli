#!/usr/bin/env bash
set -e

BUILD_PATH="build"
TARGET="chooser"

read -p "Limpar o build? (Y/n) " CHOICE
if [[ "$CHOICE" == "Y" || "$CHOICE" == "y" ]]; then
    echo "\n[ REMOVENDO CACHE ]"
    rm -rfv "$BUILD_PATH"
fi

echo -e "\n[ CONFIGURANDO BUILD ]"
cmake -S . -B "$BUILD_PATH"

echo -e "\n[ BUILDANDO PROGRAMA ]"
cmake --build "$BUILD_PATH"

echo -e "\n[ EXECUTANDO PROGRAMA ]"
./"$BUILD_PATH/$TARGET" teste.md
./"$BUILD_PATH/$TARGET" -h
./"$BUILD_PATH/$TARGET" -hs
./"$BUILD_PATH/$TARGET" sla