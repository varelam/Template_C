#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1

Code="$(pwd)/src"
Deps="$(pwd)/deps"
Build="$(pwd)/build"

if [[ $# -ge 1 && ${1::1} == '/' ]]; then shift 1; fi
{ [[ "${1:-}" == *'t'* ]]; BuildTests="$((1-$?))"; } || :
{ [[ "${1:-}" == *'d'* ]]; BuildDeps="$((1-$?))"; } || :

# ====================================================================================================
Common_F0=(
    -march=native

    -ggdb3
    # -fkeep-inline-functions
    # -fkeep-static-functions

    -fno-strict-overflow
    -fno-strict-aliasing
    -fno-delete-null-pointer-checks

    -fno-trapping-math
    -fno-math-errno
    -fno-signed-zeros

    -fno-exceptions
    -fno-rtti

    -Wall -Wextra
    -Wshadow

    -Wconversion
    -Wfloat-conversion
    -Wno-sign-conversion

    -Wno-missing-braces
    -Wno-missing-field-initializers
    -Wno-unused-const-variable
    -Wno-unused-function
    -Wno-write-strings

    -lm -lrt
    -pthread
)

Common_F1=(
    -O1
    -DDEBUG=1
    -DINTERNAL=1

    -std=c++14
)
# ====================================================================================================
# Lets get building!
gcc()
{
    local Cmd=("${FUNCNAME[0]}" "$1" -o "$2"); shift 2;
    local Args=("$@")
    for Arg in "${Args[@]}"
    do
        if [[ "${Arg:0:1}" == '-' ]]
        then
            Cmd+=("$Arg")
        else
            local Name0="${Arg}_F0[@]"; local Name1="${Arg}_F1[@]";
            if [[ -v "$Name0" ]]; then Cmd+=("${!Name0}"); fi
            if [[ -v "$Name1" ]]; then Cmd+=("${!Name1}"); fi
        fi
    done
    echo "${Cmd[@]}"
    command "${Cmd[@]}"
}

# ====================================================================================================
# Build

mkdir -p "$Build"
if [[ "$BuildDeps" == 1 ]]
then
  # Build dependencies
  echo "=== Building dependencies ==============================="
fi

echo "=== Building programs ============================"
gcc "$Code"/mycode.cpp  "$Build"/myprog
if [[ "$BuildTests" == 1 ]]
then
    mkdir -p "$Build"/tests
    echo "=== Building tests ==============================="
    gcc  "$Code"/tests/mytest.cpp -I"$Code" Common
fi
