#!/usr/bin/env sh
dir="$(dirname $(realpath "$0"))"

cmake -S "${dir}" -B "${dir}/build" \
	-DCMAKE_EXPORT_COMPILE_COMMANDS=1
#	-DCMAKE_BUILD_TYPE:STRING=Release \

cmake --build "${dir}/build"

mv -f "${dir}/build/compile_commands.json" "${dir}/compile_commands.json"
