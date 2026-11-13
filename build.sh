#!/usr/bin/env bash
# Build script for Conway's Game of Life.
# The GitHub Actions workflow calls this, but it works on any Debian/Ubuntu
# machine (a VM, a Docker container, a lab PC...).
set -euo pipefail

# Use sudo only if we're not already root (e.g. inside a Docker container)
if [ "$(id -u)" -eq 0 ]; then SUDO=""; else SUDO="sudo"; fi

export DEBIAN_FRONTEND=noninteractive

echo "==> Updating system packages"
$SUDO apt-get update
$SUDO apt-get dist-upgrade -y

echo "==> Installing build tools"
$SUDO apt-get install -y build-essential git

echo "==> Building with make"
make clean
make

echo "==> Copying executable to dist/"
mkdir -p dist
cp conway dist/

echo "==> Build finished: dist/conway"
