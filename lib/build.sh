
target_dir=$(dirname "$0")

build() {

    echo "Building library..."
    clang -fPIC -shared -o "$target_dir/liblib.so" "$target_dir/lib.c"
    echo -e "Library build completed!\n"
}

build