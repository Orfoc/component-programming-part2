# Tell GDB where to look for separate debugging files.
set debug-file-directory ~/.guix-profile/lib/debug

# Authorize extensions found in the store, such as the
# pretty-printers of libstdc++.
set auto-load safe-path /gnu/store/*/lib
