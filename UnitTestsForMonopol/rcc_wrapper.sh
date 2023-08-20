#!/bin/bash
DYLD_IMAGE_SUFFIX=_debug
export DYLD_IMAGE_SUFFIX
exec /Users/milena/Qt/6.4.3/macos/libexec/rcc "$@"
