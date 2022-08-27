#!/bin/bash
set -euo pipefail
IFS=$'\n\t'

source sh_menu.sh

if [[ ${BASE} == "exit" ]]; then exit 0; fi

make clean
make run
