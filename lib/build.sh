
target_dir=$(dirname "$0")

build() {

    clang -fPIC -shared -o "$target_dir/liblib.so" "$target_dir/lib.c"
}

build