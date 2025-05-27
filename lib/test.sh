target_dir=$(dirname "$0")
flags="-g -Wall -Wextra -std=c23"

clang $flags -o "$target_dir/test/d_array_list_test" "$target_dir/test/d_array_list.test.c" "$target_dir/d_array_list.c"

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi
echo "Compilation successful!"
echo "Running tests..."
echo -e "-------------------------\n"

"$target_dir/test/d_array_list_test"