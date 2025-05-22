
target_dir=$(dirname "$0")

build() {

    clang -fPIC -shared -o "$target_dir/libd_array_list.so" "$target_dir/d_array_list.c"
}

build