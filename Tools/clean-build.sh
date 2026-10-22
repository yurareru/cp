#!/usr/bin/env bash

find . -type d -name '.build' -print
find . -type d -name '.build' -prune -exec rm -rf {} +
